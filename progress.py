#!/usr/bin/env python3

import argparse
import json
import csv
import git
import os
import re
import math

##### SCORES ENTRIES #####

import typing as t

class TableEntry(t.NamedTuple):
    name: str
    score2req: int
    score3req: int
    score4req: int
    scoreMax: int

gMyScores: t.Sequence[TableEntry] = (
    TableEntry("Planet Bomber - Battle Room", 1500, 2500, 3500, 4500),
    TableEntry("Planet Bomber - Hyper Room", 1000, 2000, 3000, 4000),
    TableEntry("Planet Bomber - Secret Room", 1000, 2000, 3000, 3500),
    TableEntry("Planet Bomber - Heavy Room", 1500, 2500, 3500, 4500),
    TableEntry("Planet Bomber - Sky Room", 1000, 2000, 3000, 4000),
    TableEntry("Planet Bomber - Blue Cave", 1000, 2000, 2500, 3000),
    TableEntry("Planet Bomber - Hole Lake", 2500, 4000, 5500, 7000),
    TableEntry("Planet Bomber - Red Cave", 1500, 3000, 4500, 5500),
    TableEntry("Planet Bomber - Big Cannon", 2500, 4000, 5500, 7000),
    TableEntry("Planet Bomber - Dark Wood", 1000, 1500, 2000, 2500),
    TableEntry("Planet Bomber - Dragon Road", 1000, 2000, 3000, 3500),
    TableEntry("Planet Bomber - Vs. Nitros", 2500, 4000, 5500, 7000),
    TableEntry("Planet Bomber - Clown Valley", 1000, 2000, 2500, 3000),
    TableEntry("Planet Bomber - Great Rock", 1000, 2000, 3000, 3500),
    TableEntry("Planet Bomber - Fog Route", 1000, 2000, 3000, 3500),
    TableEntry("Planet Bomber - Vs. Endol", 2500, 4000, 5500, 7500),
    TableEntry("Primus Star - Groog Hills", 1500, 3000, 4500, 6000),
    TableEntry("Primus Star - Bubble Hole", 4000, 5000, 6000, 7000),
    TableEntry("Primus Star - Erars Lake", 2500, 4000, 5500, 6500),
    TableEntry("Primus Star - Waterway", 1000, 2000, 3000, 4000),
    TableEntry("Primus Star - Water Slider", 1000, 2000, 3000, 4000),
    TableEntry("Primus Star - Rock'n Road", 1000, 2000, 2500, 3000),
    TableEntry("Primus Star - Water Pool", 1500, 2500, 3500, 4500),
    TableEntry("Primus Star - Millian Road", 2000, 3000, 4000, 5000),
    TableEntry("Primus Star - Warp Room", 1000, 1500, 2000, 2500),
    TableEntry("Primus Star - Dark Prison", 1000, 2000, 2500, 3000),
    TableEntry("Primus Star - Vs. Nitros", 1500, 3000, 4500, 6500),
    TableEntry("Primus Star - Killer Gate", 1000, 2000, 3000, 4000),
    TableEntry("Primus Star - Spiral Tower", 1000, 2000, 2500, 3000),
    TableEntry("Primus Star - Snake Route", 1000, 1500, 2000, 2500),
    TableEntry("Primus Star - Vs. Baruda", 1500, 3000, 4500, 6000),
    TableEntry("Kanatia Star - Hades Crater", 1500, 2000, 2500, 3000),
    TableEntry("Kanatia Star - Magma Lake", 1500, 2500, 3500, 4500),
    TableEntry("Kanatia Star - Magma Dam", 2000, 3000, 4000, 5000),
    TableEntry("Kanatia Star - Crysta Hole", 2000, 3000, 4000, 5000),
    TableEntry("Kanatia Star - Emerald Tube", 2500, 4000, 5500, 7500),
    TableEntry("Kanatia Star - Death Temple", 1000, 2000, 2500, 3000),
    TableEntry("Kanatia Star - Death Road", 1500, 2500, 3500, 4500),
    TableEntry("Kanatia Star - Death Garden", 1000, 2000, 3000, 3500),
    TableEntry("Kanatia Star - Float Zone", 1000, 2000, 2500, 3000),
    TableEntry("Kanatia Star - Aqua Tank", 1000, 2000, 2500, 3000),
    TableEntry("Kanatia Star - Aqua Way", 4000, 6000, 8000, 9000),
    TableEntry("Kanatia Star - Vs. Nitros", 1500, 3000, 4500, 6500),
    TableEntry("Kanatia Star - Hard Coaster", 1500, 3000, 4500, 6500),
    TableEntry("Kanatia Star - Dark Maze", 1000, 2000, 3000, 3500),
    TableEntry("Kanatia Star - Mad Coaster", 1000, 2000, 3000, 4000),
    TableEntry("Kanatia Star - Move Stone", 1000, 2000, 3000, 3500),
    TableEntry("Kanatia Star - Vs. Bolban", 2500, 4000, 5500, 7000),
    TableEntry("Mazone Star - Hopper Land", 2000, 3000, 4000, 5000),
    TableEntry("Mazone Star - Junfalls", 1000, 2000, 3000, 4000),
    TableEntry("Mazone Star - Freeze Lake", 1500, 3000, 4500, 6500),
    TableEntry("Mazone Star - Cool Cave", 1500, 2500, 3500, 4500),
    TableEntry("Mazone Star - Snowland", 1500, 2500, 3500, 4500),
    TableEntry("Mazone Star - Storm Valley", 1000, 2000, 3000, 3500),
    TableEntry("Mazone Star - Snow Circuit", 1000, 2000, 3000, 4000),
    TableEntry("Mazone Star - Heaven Sky", 2500, 4000, 5500, 7500),
    TableEntry("Mazone Star - Eye Snake", 1500, 2500, 3500, 4500),
    TableEntry("Mazone Star - Vs. Nitros", 1500, 3000, 4500, 6500),
    TableEntry("Mazone Star - Air Room", 1000, 2000, 3000, 4000),
    TableEntry("Mazone Star - Zero G Room", 1000, 2000, 3000, 4000),
    TableEntry("Mazone Star - Mirror Room", 1000, 2000, 3000, 3500),
    TableEntry("Mazone Star - Vs. Natia", 2000, 3000, 4000, 5500),
    TableEntry("Garaden Star - Room 1: Endol", 2500, 4000, 5500, 7500),
    TableEntry("Garaden Star - Room 2: Baruda", 1500, 3000, 4500, 6500),
    TableEntry("Garaden Star - Room 3: Cronus", 1500, 3000, 4500, 6000),
    TableEntry("Garaden Star - Room 4: Nitros", 1500, 3000, 4500, 6000),
    TableEntry("Garaden Star - Room 5: Bolban", 2000, 3000, 4000, 5500),
    TableEntry("Garaden Star - Room 6: Natia", 2500, 4000, 5500, 7000),
    TableEntry("Garaden Star - Vs. Bagular", 400, 600, 800, 1000),
    TableEntry("Gossick Star - Outer Road", 1000, 2000, 3000, 4000),
    TableEntry("Gossick Star - Inner Road", 1000, 2000, 3000, 4000),
    TableEntry("Gossick Star - Vs. ???", 1500, 3000, 4500, 6000),
    TableEntry("Bomber Star - Stage 1", 1500, 3000, 4500, 6000),
    TableEntry("Bomber Star - Stage 2", 1500, 3000, 4500, 5500),
    TableEntry("Bomber Star - Stage 3", 1500, 3000, 4500, 6000),
)

# calculate global total score for safety. this should eval to 361500, but lets not hardcode that
total_score = 0
for entry in gMyScores:
    total_score = total_score + entry.scoreMax

##### SCORES END #####

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

# now, given our current srcPct, where are we?
current_score = math.floor((srcPct * total_score) / 100)

# Now where are we currently?
level_id = 0
for entry in gMyScores:
    if current_score <= entry.scoreMax:
        break
    else: # since we have no match, deduct the score and increment.
        current_score = current_score - entry.scoreMax
        level_id = level_id + 1

# What score do we currently have?
score_value = 1
if current_score >= gMyScores[level_id].scoreMax:
    score_value = 5
elif current_score >= gMyScores[level_id].score4req:
    score_value = 4
elif current_score >= gMyScores[level_id].score3req:
    score_value = 3
elif current_score >= gMyScores[level_id].score2req:
    score_value = 2

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
    print("-------------------------------------------------------\n")
    print("Current Level:", gMyScores[level_id].name)
    print("Current Score:", round(current_score/10)*10)
    print("Current Score Value:", score_value)
    print("") # extra newline
else:
    print("Unknown format argument: " + args.format)
