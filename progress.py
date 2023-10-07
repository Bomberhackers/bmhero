#!/usr/bin/env python3

import argparse
import json
import csv
import git
import os
import re

parser = argparse.ArgumentParser(description="Computes current progress throughout the whole project.")
parser.add_argument("format", nargs="?", default="text", choices=["text", "csv", "shield-json"])
parser.add_argument("-m", "--matching", dest='matching', action='store_true',
                    help="Output matching progress instead of decompilation progress")
args = parser.parse_args()

NON_MATCHING_PATTERN = r"#ifdef\s+NON_MATCHING.*?#pragma\s+GLOBAL_ASM\s*\(\s*\"(.*?)\"\s*\).*?#endif"

def GetNonMatchingFunctions(files):
    functions = []

    for file in files:
        with open(file) as f:
            functions += re.findall(NON_MATCHING_PATTERN, f.read(), re.DOTALL)

    return functions

def ReadAllLines(fileName):
    lineList = list()
    with open(fileName) as f:
        lineList = f.readlines()

    return lineList

def GetFiles(path, ext):
    files = []

    for r, d, f in os.walk(path):
        for file in f:
            if file.endswith(ext):
                files.append(os.path.join(r, file))

    return files

nonMatchingFunctions = GetNonMatchingFunctions(GetFiles("src", ".c")) if not args.matching else []

def GetNonMatchingSize(path):
    size = 0

    asmFiles = GetFiles(path, ".s")

    for asmFilePath in asmFiles:
        if asmFilePath not in nonMatchingFunctions:
            asmLines = ReadAllLines(asmFilePath)

            for asmLine in asmLines:
                if (asmLine.startswith("/*")):
                    size += 4

    return size

def IsCFile(objfile):
    srcfile = objfile.strip().replace("build/", "").replace(".o", "")
    return os.path.isfile(srcfile)

mapFile = ReadAllLines("build/bmhero.map")
curSegment = None
src = 0
code = 0
boot = 0
ovl = 0

for line in mapFile:

    if "game_VRAM" in line:
        curSegment = "code"
    elif "boot_code_VRAM" in line:
        curSegment = "boot"
    elif "game_VRAM_END" in line or "boot_code_VRAM_END" in line:
        curSegment = None

    lineSplit =  list(filter(None, line.split(" ")))

    if (len(lineSplit) == 4 and lineSplit[0].startswith(".")):
        section = lineSplit[0]
        size = int(lineSplit[2], 16)
        objFile = lineSplit[3]

        if (section == ".text" and IsCFile(objFile)):
            if (objFile.startswith("build/src")):
                src += size

            if (objFile.startswith("build/src/code") or (objFile.startswith("build/src/libultra/") and curSegment == "code")):
                code += size
            elif (objFile.startswith("build/src/boot") or (objFile.startswith("build/src/libultra/") and curSegment == "boot")):
                boot += size
            elif (objFile.startswith("build/src/overlays")):
                ovl += size

nonMatchingASM = GetNonMatchingSize("asm/nonmatchings")
nonMatchingASMBoot = GetNonMatchingSize("asm/nonmatchings/boot")
nonMatchingASMCode = GetNonMatchingSize("asm/nonmatchings/code")
nonMatchingASMOvl = GetNonMatchingSize("asm/nonmatchings/overlays")

src -= nonMatchingASM
code -= nonMatchingASMCode
boot -= nonMatchingASMBoot
ovl -= nonMatchingASMOvl

bootSize = 293648
codeSize = 674384
ovlSize = 212420 # .text sections

total = src + nonMatchingASM
srcPct = 100 * src / total
codePct = 100 * code / codeSize
bootPct = 100 * boot / bootSize
ovlPct = 100 * ovl / ovlSize

if args.format == 'csv':
    csv_version = 2
    git_object = git.Repo().head.object
    timestamp = str(git_object.committed_date)
    git_hash = git_object.hexsha
    csv_list = [str(csv_version), timestamp, git_hash, str(src), str(total), str(code), str(codeSize), str(boot), str(bootSize), str(ovl), str(ovlSize), str(nonMatchingASM), str(len(nonMatchingFunctions))]
    print(",".join(csv_list))
elif args.format == 'shield-json':
    # https://shields.io/endpoint
    print(json.dumps({
        "schemaVersion": 1,
        "label": "progress",
        "message": f"{srcPct:.3g}%",
        "color": 'yellow' if srcPct < 100 else 'brightgreen',
    }))
elif args.format == 'text':
    adjective = "decompiled" if not args.matching else "matched"

    print(str(total) + " total bytes of decompilable code\n")
    print(str(src) + " bytes " + adjective + " in src " + str(srcPct) + "%")
    print(str(boot) + "/" + str(bootSize) + " bytes " + adjective + " in boot " + str(bootPct) + "%")
    print(str(code) + "/" + str(codeSize) + " bytes " + adjective + " in game " + str(codePct) + "%")
    print(str(ovl) + "/" + str(ovlSize) + " bytes " + adjective + " in overlays " + str(ovlPct) + "%\n")
else:
    print("Unknown format argument: " + args.format)
