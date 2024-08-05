#include <ultra64.h>
#include "7B0A0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007F580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007F5CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007F688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007F778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007F834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007F964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007FA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007FB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007FBA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007FC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007FD5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007FDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007FE5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8007FF44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800804D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8008057C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800806DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80080F6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80081024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80081120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800811D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800812D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800813B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80081468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800816FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800818CC.s")

void func_800819E0(void) {
    s32 i;

    // clear file array.
    for(i = 0; i < 700; i++) {
        gFileArray[i].ptr = NULL;
    }

    func_8001E954((s32* )0x8024C000);
    func_8001E98C(0, unk_bin_0_2_ROM_START, code_extra_0_ROM_START);
    DecompressFile(0x1A, (u32)&_64C3C0_ROM_START, (u32)&_64C3C0_ROM_END);
    DecompressFile(0xD, (u32)&_641EC0_ROM_START, (u32)&_641EC0_ROM_END);
    DecompressFile(0xE, (u32)&_643690_ROM_START, (u32)&_643690_ROM_END);
    DecompressFile(0xF, (u32)&_644550_ROM_START, (u32)&_644550_ROM_END);
    DecompressFile(0x10, (u32)&_645370_ROM_START, (u32)&_645370_ROM_END);
    DecompressFile(0x11, (u32)&_6469E0_ROM_START, (u32)&_6469E0_ROM_END);
    DecompressFile(0x1E, (u32)&_647D30_ROM_START, (u32)&_647D30_ROM_END);
    DecompressFile(0x1F, (u32)&_647ED0_ROM_START, (u32)&_647ED0_ROM_END);
    DecompressFile(0x24, (u32)&_649670_ROM_START, (u32)&_649670_ROM_END);
    DecompressFile(0x25, (u32)&_649DD0_ROM_START, (u32)&_649DD0_ROM_END);
    DecompressFile(0x26, (u32)&_64A3E0_ROM_START, (u32)&_64A3E0_ROM_END);
    DecompressFile(0x23, (u32)&_649020_ROM_START, (u32)&_649020_ROM_END);
    DecompressFile(0x27, (u32)&_64A9E0_ROM_START, (u32)&_64A9E0_ROM_END);
    DecompressFile(0x28, (u32)&_64AF80_ROM_START, (u32)&_64AF80_ROM_END);
    DecompressFile(0x2A, (u32)&_64BE10_ROM_START, (u32)&_64BE10_ROM_END);
    DecompressFile(0x29, (u32)&_64B870_ROM_START, (u32)&_64B870_ROM_END);

    if ((gCurrentLevel == MAP_JUN_FALLS) || (gCurrentLevel == MAP_EVIL_BOMBER)) {
        DecompressFile(0x22, (u32)&_648B30_ROM_START, (u32)&_648B30_ROM_END);
    }
    if (gCurrentLevel == MAP_STORM_VALLEY) {
        DecompressFile(0x21, (u32)&_6489B0_ROM_START, (u32)&_6489B0_ROM_END);
    }
    DecompressFile(0x19, (u32)&_64EC60_ROM_START, (u32)&_64EC60_ROM_END);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80081C50.s")

void func_80081D78(void) {
    u32 pad;
    struct UnkStruct80108238* sp20;
    u8 trackID;

    D_8016E434 = gCurrentLevel;
    gCurrentLevel = D_8016E432;
    D_80177638 = 0;
    func_800819E0();
    D_80176606 = 0;
    D_8017660A = 0;
    gPlayerObject = gObjects;
    gPlayerArmWindObject = &gObjects[1];
    func_80019C84();
    func_80019D2C();
    func_8001A258();
    func_80088B80();
    if (gCurrentLevel >= MAP_FIRST_CUTSCENE_MAP) {
        func_80000F8C(gCurrentLevel - MAP_FIRST_CUTSCENE_MAP);
        func_80088EAC(gCurrentLevel - MAP_FIRST_CUTSCENE_MAP);
    }
    func_8001E954((s32* )0x802D0000);
    sp20 = D_80108238[gCurrentLevel];
    if (D_8016E3DC == 0) {
        DecompressFile(0x1C, sp20->unk4, sp20->unk8);
    } else {
        func_8001E98C(0x1C, (u32)&unk_bin_0_ROM_START, (u32)&unk_bin_0_ROM_END);
    }
    func_8001EB68(0x1B, sp20->unkC, sp20->unk10);
    func_80000FF4(gCurrentLevel);
    func_8006707C();
    func_800695A0();
    func_8006E088();
    func_8002629C();
    func_80069700();
    gLevelInfo[gCurrentLevel]->unk24();
    gLevelInfo[gCurrentLevel]->unk28();
    D_8016E134 = 0;
    if (gCameraType != 1) {
        gCameraType = D_80177921;
        if (D_80134BF2 != -1) {
            gCameraType = 0;
        }
    }
    if (D_80134BF2 == -1) {
        D_8016523E = D_80177778->unk29;
        if ((gGoldBomber != 0) && (*gContCurrButton & 0x2000)) {
            D_80177638 = 1;
            D_8016523E = 0;
        }
        if (D_80177630 == 3) {
            D_80177638 = 1;
            D_8016523E = 0;
            gCameraType = 2;
        }
        func_800883A8();
        func_80088694();
    } else {
        func_800889A8();
    }
    func_8007F580();
    func_8007957C();
    func_8007E720();
    func_8006E160();
    func_80076458();
    func_80076640();
    func_80063EE0();
    D_801775F0 = 0;
    D_801775EE = 0;
    D_80177620 = 0;
    func_8006AB14();
    func_80069E38();
    func_80070A6C();
    func_800711B4();
    func_80070644();
    if (D_80177630 < 2) {
        if (D_80177628 == 1) {
            func_80070664(1);
        }
    } else if (D_80177630 == 2) {
        func_80070664(4);
    }
    func_8006AA0C();
    D_8016E3CC = 0;
    D_8016E3CD = 0;
    trackID = gLevelInfo[gCurrentLevel]->trackID;
    if (trackID != 0xFF) {
        PlayTrack_WithVolLoop(trackID, -1, 0);
    } else {
        PlayTrack_WithVolLoop(-1, -1, 0);
    }
    func_8001D244(-1, -1, -1, 0x10);
    func_8001D284();
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800821E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800824A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80082500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80082678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_8008279C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800828A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800829AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80082AB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80082BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80082CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80082E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80083180.s")
