#include <ultra64.h>
#include "../boot/2BF00.h"
#include "7B0A0.h"
#include "71AA0.h"

void func_8007F580(void) {
    s32 sp1C;

    sp1C = 0x8F;
    do {
        func_8001A928(sp1C);
    } while (++sp1C < 0xCF);
}

void func_8007F5CC(void) {
    gObjects[gCurrentParsedObject].objID = 700;
    gObjects[gCurrentParsedObject].unkBE = 2;
    gObjects[gCurrentParsedObject].unkC0 = 0;
    gObjects[gCurrentParsedObject].unkC2 = 0x1E;
}

void func_8007F688(void) {
    struct ObjectStruct* sp34;

    sp34 = &gObjects[gCurrentParsedObject];
    sp34->unkA6 += 1;
    sp34->Scale.x = sp34->Scale.y = sp34->Scale.z = ((f32) sp34->unkA6 / 10.0f) + 1.0f;
    if (sp34->unkA6 >= 0x15) {
        func_8001A928(gCurrentParsedObject);
    }
}

void func_8007F778(void) {
    gObjects[gCurrentParsedObject].objID = 0x2BD;
    gObjects[gCurrentParsedObject].unkBE = 2;
    gObjects[gCurrentParsedObject].unkC0 = 0;
    gObjects[gCurrentParsedObject].unkC2 = 0x1F;
}

void func_8007F834(void) {
    struct ObjectStruct* sp34;

    sp34 = &gObjects[gCurrentParsedObject];
    if (!(sp34->unkA6 & 3)) {
        sp34->unkC0 = (s16) ((s16) sp34->unkA6 / 4);
    }
    sp34->Scale.x = sp34->Scale.y = sp34->Scale.z = ((f32) sp34->unkA6 / 16.0f) + 1.0f;
    sp34->unkA6 += 1;
    if (sp34->unkA6 >= 0x20) {
        func_8001A928(gCurrentParsedObject);
    }
}

void func_8007F964(void) {
    gObjects[gCurrentParsedObject].objID = 0x2C5;
    gObjects[gCurrentParsedObject].unkBE = 2;
    gObjects[gCurrentParsedObject].unkC0 = 0;
    gObjects[gCurrentParsedObject].unkC2 = 0x25;
}

void func_8007FA20(void) {
    struct ObjectStruct* sp34;

    sp34 = &gObjects[gCurrentParsedObject];
    sp34->unkC0 = (s16) ((s16) sp34->unkA6 / 2);
    sp34->Scale.x = sp34->Scale.y = sp34->Scale.z = ((f32) sp34->unkA6 / 16.0f) + 1.0f;
    sp34->unkA6 += 1;
    if (sp34->unkA6 >= 0x10) {
        func_8001A928(gCurrentParsedObject);
    }
}

void func_8007FB34(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    sp4->objID = 0x2BE;
    sp4->unkBE = 3;
    sp4->unkC0 = 0;
    sp4->unkC2 = 0x20;
}

void func_8007FBA4(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unkA8 == 0) {
        if (sp1C->unkA6 == 9) {
            func_8001A928(gCurrentParsedObject);
            return;
        } else {
            sp1C->unkC0 = sp1C->unkA6;
            sp1C->unkA6 += 1;
            sp1C->unkA8 = 1;
        }
    } else {
        sp1C->unkA8 -= 1;
    }
}

void func_8007FC98(struct ObjectStruct* arg0) {

    arg0->Vel.y = (f32) Math_Random(-7);
    arg0->Vel.z = (f32) Math_Random(-7);
    arg0->Scale.z = 1.0f;
    arg0->Scale.x = arg0->Scale.y = arg0->Scale.z;
    arg0->unkA6 = 0x32;
    arg0->unkBE = 2;
    arg0->unkC0 = 0;
    arg0->unkC2 = 0x21;
}

void func_8007FD5C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->objID = 0x2BF;
    sp1C->Vel.x = (f32) (Math_Random(3) + 0xF);
    func_8007FC98(sp1C);
}

void func_8007FDDC(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->objID = 0x2C0;
    sp1C->Vel.x = (f32) (Math_Random(-3) - 0xF);
    func_8007FC98(sp1C);
}

void func_8007FE5C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->Pos.x += sp1C->Vel.x;
    sp1C->Pos.y += sp1C->Vel.y;
    sp1C->Pos.z += sp1C->Vel.z;
    if (sp1C->unkA6 == 0) {
        func_8001A928(gCurrentParsedObject);
    } else {
        sp1C->unkA6 -= 1;
    }
}

void func_8007FF44(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    sp24->objID = 0x2C1;
    sp24->Scale.z = D_8010CB10;
    sp24->Scale.x = sp24->Scale.y = sp24->Scale.z;
    sp24->unkA6 = Math_Random(5) + 8;
    sp24->unkBE = 2;
    sp24->unkC0 = 0;
    sp24->unkC2 = 0x21;
}

void func_80080014(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->Pos.y -= (f32) sp1C->unkA6;
    sp1C->Pos.x = (f32) Math_Random(-3) + sp1C->Pos.x;
    if ((sp1C->Pos.y < (gView.at.y - 320.0f)) || (sp1C->Pos.y > (gView.at.y + 960.0f)) ||
        (sp1C->Pos.x < (gView.at.x - 960.0f)) || (sp1C->Pos.x > (gView.at.x + 960.0f)) ||
        (sp1C->Pos.z < (gView.at.z - 960.0f)) || (sp1C->Pos.z) > (gView.at.z + 960.0f)) {
        func_8001A928(gCurrentParsedObject);
    }
}

void func_80080198(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->objID = 0x2C2;
    sp1C->unkA6 = Math_Random(5) + 8;
    sp1C->unkBE = 3;
    sp1C->unkC0 = 0;
    sp1C->unkC2 = 0x22;
}

void func_80080228(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->Pos.y -= (f32) sp1C->unkA6;
    if ((sp1C->Pos.y < (gView.at.y - 320.0f)) || (sp1C->Pos.y > (gView.at.y + 960.0f)) ||
        ((sp1C->Pos.x < (gView.at.x - 960.0f))) || (sp1C->Pos.x > (gView.at.x + 960.0f)) ||
        ((sp1C->Pos.z < (gView.at.z - 960.0f))) || (sp1C->Pos.z) > (gView.at.z + 960.0f)) {
        func_8001A928(gCurrentParsedObject);
    }
}

void func_80080388(void) {
    gObjects[gCurrentParsedObject].objID = 707;
    gObjects[gCurrentParsedObject].Scale.x = gObjects[gCurrentParsedObject].Scale.y =
        gObjects[gCurrentParsedObject].Scale.z = 3.0f;
    gObjects[gCurrentParsedObject].unkBE = 2;
    gObjects[gCurrentParsedObject].unkC0 = 0;
    gObjects[gCurrentParsedObject].unkC2 = 0x23;
}

void func_800804D0(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->unkC0 = sp1C->unkA6;
    sp1C->unkA6 += 1;
    if (sp1C->unkC0 >= 8) {
        func_8001A928(gCurrentParsedObject);
        return;
    }
}

void func_8008057C(void) {
    gObjects[gCurrentParsedObject].objID = 0x2C4;
    gObjects[gCurrentParsedObject].unkBE = 2;
    gObjects[gCurrentParsedObject].unkC0 = 0;
    gObjects[gCurrentParsedObject].unkC2 = 0x24;
}

void func_80080638(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->unkC0 = sp1C->unkA6;
    sp1C->unkA6 += 1;
    if (sp1C->unkC0 >= 8) {
        func_8001A928(gCurrentParsedObject);
    }
}

void func_800806DC(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    sp4->objID = 0x2C6;
    sp4->unkBE = 2;
    sp4->unkC0 = 0;
    sp4->unkC2 = 0x26;
    sp4->Scale.z = 2.0f;
    sp4->Scale.x = sp4->Scale.y = sp4->Scale.z;
}

void func_80080780(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->unkC0 = (s16) ((s16) sp1C->unkA6 / 2);
    sp1C->unkA6 += 1;
    if (sp1C->unkC0 >= 8) {
        func_8001A928(gCurrentParsedObject);
    }
}

void func_80080834(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    sp24->objID = 0x2C7;
    sp24->Scale.z = D_8010CB14;
    sp24->Scale.x = sp24->Scale.y = sp24->Scale.z;
    sp24->Pos.y += 300.0f;
    sp24->unkA6 = Math_Random(5) + 8;
    sp24->Vel.x = (f32) Math_Random(-0xC);
    sp24->Vel.y = (f32) (Math_Random(5) + 0x14);
    sp24->Vel.z = (f32) Math_Random(-0xC);
    sp24->unkBE = 2;
    sp24->unkC0 = 0;
    sp24->unkC2 = 0x21;
    sp24->unk132 = 0;
}

void func_80080978(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->Pos.x += sp1C->Vel.x;
    sp1C->Pos.z += sp1C->Vel.z;
    sp1C->Pos.y += sp1C->Vel.y;
    sp1C->Vel.y = (f32) ((f64) sp1C->Vel.y - D_8010CB18);
    if (sp1C->Scale.x <= 1.0f) {
        sp1C->Scale.x = (f32) ((f64) sp1C->Scale.x + D_8010CB20);
        sp1C->Scale.y = (f32) ((f64) sp1C->Scale.y + D_8010CB28);
        sp1C->Scale.z = (f32) ((f64) sp1C->Scale.z + D_8010CB30);
    }
    if (sp1C->Pos.y <= 0.0f) {
        func_8001A928(gCurrentParsedObject);
    }
}

void func_80080AFC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    sp24->objID = 0x2C8;
    sp24->unkBE = 2;
    sp24->unkC0 = Math_Random(8);
    sp24->unkC2 = 0x27;
    sp24->Vel.x = (f32) Math_Random(-0xC);
    sp24->Vel.y = (f32) (Math_Random(8) + 8);
    sp24->Vel.z = (f32) Math_Random(-0xC);
    sp24->Scale.z = 3.0f;
    sp24->Scale.x = sp24->Scale.y = sp24->Scale.z;
}

extern f64 D_8010CB38;

void func_80080C0C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->Pos.x += sp1C->Vel.x;
    sp1C->Pos.z += sp1C->Vel.z;
    sp1C->Pos.y += sp1C->Vel.y;
    sp1C->Vel.y = (f32) ((f64) sp1C->Vel.y - D_8010CB38);
    if (sp1C->Vel.y < 0.0f) {
        func_8001A928(gCurrentParsedObject);
    }
}

void func_80080D00(void) {
    gObjects[gCurrentParsedObject].objID = 0x2C9;
    gObjects[gCurrentParsedObject].Scale.x = gObjects[gCurrentParsedObject].Scale.y =
        gObjects[gCurrentParsedObject].Scale.z = 3.0f;
    gObjects[gCurrentParsedObject].unkBE = 2;
    gObjects[gCurrentParsedObject].unkC0 = 0;
    gObjects[gCurrentParsedObject].unkC2 = 0x28;
}

void func_80080E48(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->unkC0 = sp1C->unkA6;
    sp1C->unkA6 += 1;
    if (sp1C->unkC0 >= 8) {
        func_8001A928(gCurrentParsedObject);
        return;
    }
}

void func_80080EF4(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    func_8001BD44(gCurrentParsedObject, 0, 1, (s32) gFileArray[0x29].ptr);
    sp1C->objID = 0x2CA;
}

void func_80080F6C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    func_8001BD44(gCurrentParsedObject, 0, 1, (s32) gFileArray[0x29].ptr);
    sp24->objID = 0x2CB;
    sp24->Scale.x = sp24->Scale.y = sp24->Scale.z = 2.0f;
}

void func_80081024(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x29, &D_80116EDC);
        func_800175F0(gCurrentParsedObject, 0, 0x6A, -1, 0);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001A928(gCurrentParsedObject);
        return;
    }
    func_8001CD20(gCurrentParsedObject);
}

void func_80081120(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    func_8001BD44(gCurrentParsedObject, 0, 1, (s32) gFileArray[0x2A].ptr);
    sp24->objID = 0x2CC;
    sp24->Scale.x = sp24->Scale.y = sp24->Scale.z = 2.0f;
}

void func_800811D8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x2A, &D_80116EE0);
        func_800175F0(gCurrentParsedObject, 0, 0x6A, -1, 0);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001A928(gCurrentParsedObject);
        return;
    }
    func_8001CD20(gCurrentParsedObject);
}

void func_800812D4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    sp24->objID = 0x2CD;
    sp24->Scale.x = sp24->Scale.y = sp24->Scale.z = 3.0f;
    sp24->unkA6 = 0xC8;
    sp24->Vel.y = (f32) (Math_Random(5) + 2);
    sp24->unkBE = 2;
    sp24->unkC0 = 0;
    sp24->unkC2 = 0x1E;
}

void func_800813B8(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unkA6 == 0) {
        func_8001A928(gCurrentParsedObject);
    } else {
        sp1C->unkA6 -= 1;
        sp1C->Pos.y += sp1C->Vel.y;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_80081468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/71AA0/func_800816FC.s")

void func_800818CC(void) {
    struct ObjectStruct* sp1C;
    s32 sp18;

    func_8001838C();
    
    for (sp18 = 0x8F, sp1C = &gObjects[0x8F]; sp18 < 0xCF; sp18++, sp1C++) {
        if (sp1C->actionState != 0) {
            if ((sp1C->objID == 714) || (sp1C->objID == 715) || (sp1C->objID == 716)) {
                if (func_8001C1A8(sp18, 0) != 0) {
                    func_8001838C();
                    func_8001B014(sp18, 0);
                    func_8001C384(sp18, 0);
                }
            } else {
                func_8001CDF4(sp18, sp1C->unkC0, sp1C->unkBE, gFileArray[sp1C->unkC2].ptr);
            }
        }
    } 
}

void func_800819E0(void) {
    s32 i;

    // clear file array.
    for (i = 0; i < 700; i++) {
        gFileArray[i].ptr = NULL;
    }

    Set_DecompressHeap((s32*) 0x8024C000);
    LoadFile(0, unk_bin_0_2_ROM_START, code_extra_0_ROM_START);
    DecompressFile(0x1A, (u32) &_64C3C0_ROM_START, (u32) &_64C3C0_ROM_END);
    DecompressFile(0xD, (u32) &_641EC0_ROM_START, (u32) &_641EC0_ROM_END);
    DecompressFile(0xE, (u32) &_643690_ROM_START, (u32) &_643690_ROM_END);
    DecompressFile(0xF, (u32) &_644550_ROM_START, (u32) &_644550_ROM_END);
    DecompressFile(0x10, (u32) &_645370_ROM_START, (u32) &_645370_ROM_END);
    DecompressFile(0x11, (u32) &_6469E0_ROM_START, (u32) &_6469E0_ROM_END);
    DecompressFile(0x1E, (u32) &_647D30_ROM_START, (u32) &_647D30_ROM_END);
    DecompressFile(0x1F, (u32) &_647ED0_ROM_START, (u32) &_647ED0_ROM_END);
    DecompressFile(0x24, (u32) &_649670_ROM_START, (u32) &_649670_ROM_END);
    DecompressFile(0x25, (u32) &_649DD0_ROM_START, (u32) &_649DD0_ROM_END);
    DecompressFile(0x26, (u32) &_64A3E0_ROM_START, (u32) &_64A3E0_ROM_END);
    DecompressFile(0x23, (u32) &_649020_ROM_START, (u32) &_649020_ROM_END);
    DecompressFile(0x27, (u32) &_64A9E0_ROM_START, (u32) &_64A9E0_ROM_END);
    DecompressFile(0x28, (u32) &_64AF80_ROM_START, (u32) &_64AF80_ROM_END);
    DecompressFile(0x2A, (u32) &_64BE10_ROM_START, (u32) &_64BE10_ROM_END);
    DecompressFile(0x29, (u32) &_64B870_ROM_START, (u32) &_64B870_ROM_END);

    if ((gCurrentLevel == MAP_JUN_FALLS) || (gCurrentLevel == MAP_EVIL_BOMBER)) {
        DecompressFile(0x22, (u32) &_648B30_ROM_START, (u32) &_648B30_ROM_END);
    }
    if (gCurrentLevel == MAP_STORM_VALLEY) {
        DecompressFile(0x21, (u32) &_6489B0_ROM_START, (u32) &_6489B0_ROM_END);
    }
    DecompressFile(0x19, (u32) &_64EC60_ROM_START, (u32) &_64EC60_ROM_END);
}

void func_80081C50(void) {
    D_8016E430 = 0;
    D_8016E432 = (s16) gCurrentLevel;
    D_8016E434 = (s16) gCurrentLevel;
    D_8016E438 = (f32) *D_80108238[gCurrentLevel]->unk0;
    D_8016E43C = (f32) * (D_80108238[gCurrentLevel]->unk0 + 0x1);
    D_8016E440 = (f32) * (D_80108238[gCurrentLevel]->unk0 + 0x2);
    D_8016E444 = (f32) * (D_80108238[gCurrentLevel]->unk0 + 0x3);
}

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
    Set_DecompressHeap((s32*) 0x802D0000);
    sp20 = D_80108238[gCurrentLevel];
    if (D_8016E3DC == 0) {
        DecompressFile(0x1C, sp20->unk4, sp20->unk8);
    } else {
        LoadFile(0x1C, (u32) &unk_bin_0_ROM_START, (u32) &unk_bin_0_ROM_END);
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
        if (gCutsceneLength != -1) {
            gCameraType = 0;
        }
    }
    if (gCutsceneLength == -1) {
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
    Set_BgColor(-1, -1, -1, 0x10);
    func_8001D284();
}

void func_800821E0(void) {
    u16 sp3E;
    s32 temp_t8;
    Gfx* sp34;
    Gfx* sp30;

    func_8001D4D0();
    if (D_80177A20 < 2) {
        if (D_8017792E == 0) {
            Debug_SetBg(1, (s32) D_80177932, (s32) D_80177934, (s32) D_80177938);
        } else {
            Debug_SetBg(0, 0, 0, 0);
            func_8006D6F4();
        }
    } else {
        Debug_SetBg(1, 0, 0, 0);
    }
    guPerspective(D_8016E104->unk00, &sp3E, 50.0f, 1.3333334f, 100.0f, D_801779C8.raw, 1.0f);
    sp34 = gMasterDisplayList++;
    sp34->words.w0 = 0xBC00000E;
    sp34->words.w1 = (u32) sp3E;
    guLookAt(&D_8016E104->unk00[2], gView.eye.x, gView.eye.y, gView.eye.z, gView.at.x, gView.at.y, gView.at.z,
             gView.up.x, gView.up.y, gView.up.z);
    sp30 = gMasterDisplayList++;
    sp30->words.w0 = 0x01030040;
    sp30->words.w1 = (u32) D_8016E104;
    D_8016E3A4 = 0;
    if (D_80177A20 < 2) {
        func_80087C58();
        func_8007E678();
        func_8001C464();
        func_8001C70C();
        func_8001C96C();
        func_8006E7CC();
        func_80087D70();
        func_8001C5B8();
        func_8007F3F0();
        func_800657E8();
        func_800818CC();
        func_80077528();
        Cutscene_HandlePrintText();
    } else {
        func_80087C58();
        func_80087D70();
    }
    func_80070B1C();
    func_80071240();
    func_8007070C();
    func_8006F780();
    func_80064120();
    func_800FF7B4();
    if (gDebugShowTimerBar != 0) {
        Debug_DrawProfiler(0x2E, 0xD0);
    }
}

void func_800824A8(void) {
    func_8001ECB8();
    gDebugRoutine1 = &func_800821E0;
    gDebugRoutine2 = &func_80024744;
    func_80081D78();
    func_80000964();
}

void func_80082500(void) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    s16 temp;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;

    sp18 = D_8016E430;
    sp1A = D_8016E432;
    sp1C = D_8016E434;
    sp20 = D_8016E438;
    sp24 = D_8016E43C;
    sp28 = D_8016E440;
    sp2C = D_8016E444;
    if (D_80134801 == 0) {
        gCurrentLevel = 0x61;
    } else if (D_80134801 == 1) {
        gCurrentLevel = 0x62;
    } else if (D_80134801 == 2) {
        gCurrentLevel = 0x63;
    } else {
        gCurrentLevel = 0x64;
    }
    func_80081C50();
    D_80177628 = 1;
    func_800824A8();
    D_8016E430 = sp18;
    D_8016E432 = sp1A;
    D_8016E434 = sp1C;
    D_8016E438 = sp20;
    D_8016E43C = sp24;
    D_8016E440 = sp28;
    D_8016E444 = sp2C;
}

void func_80082678(void) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s16 temp;
    s16 sp24;
    s16 sp22;
    s16 sp20;
    s32 sp1C;

    sp20 = D_8016E430;
    sp22 = D_8016E432;
    sp24 = D_8016E434;
    sp28 = D_8016E438;
    sp2C = D_8016E43C;
    sp30 = D_8016E440;
    sp34 = D_8016E444;
    sp1C = gCurrentLevel;
    gCurrentLevel = 0xAB;
    func_80081C50();
    D_80177628 = 0;
    func_800824A8();
    gCurrentLevel = sp1C;
    D_8016E430 = sp20;
    D_8016E432 = sp22;
    D_8016E434 = sp24;
    D_8016E438 = sp28;
    D_8016E43C = sp2C;
    D_8016E440 = sp30;
    D_8016E444 = sp34;
}

void func_8008279C(void) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    s16 temp;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;

    sp18 = D_8016E430;
    sp1A = D_8016E432;
    sp1C = D_8016E434;
    sp20 = D_8016E438;
    sp24 = D_8016E43C;
    sp28 = D_8016E440;
    sp2C = D_8016E444;
    gCurrentLevel = 0xAA;
    func_80081C50();
    D_80177628 = 0;
    func_800824A8();
    D_8016E430 = sp18;
    D_8016E432 = sp1A;
    D_8016E434 = sp1C;
    D_8016E438 = sp20;
    D_8016E43C = sp24;
    D_8016E440 = sp28;
    D_8016E444 = sp2C;
}

void func_800828A4(void) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    s16 temp;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;

    sp18 = D_8016E430;
    sp1A = D_8016E432;
    sp1C = D_8016E434;
    sp20 = D_8016E438;
    sp24 = D_8016E43C;
    sp28 = D_8016E440;
    sp2C = D_8016E444;
    gCurrentLevel = 0xBA;
    func_80081C50();
    D_80177628 = 0;
    func_800824A8();
    D_8016E430 = sp18;
    D_8016E432 = sp1A;
    D_8016E434 = sp1C;
    D_8016E438 = sp20;
    D_8016E43C = sp24;
    D_8016E440 = sp28;
    D_8016E444 = sp2C;
}

void func_800829AC(void) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    s16 temp;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;

    sp18 = D_8016E430;
    sp1A = D_8016E432;
    sp1C = D_8016E434;
    sp20 = D_8016E438;
    sp24 = D_8016E43C;
    sp28 = D_8016E440;
    sp2C = D_8016E444;
    gCurrentLevel = 0xAF;
    func_80081C50();
    D_80177628 = 0;
    func_800824A8();
    D_8016E430 = sp18;
    D_8016E432 = sp1A;
    D_8016E434 = sp1C;
    D_8016E438 = sp20;
    D_8016E43C = sp24;
    D_8016E440 = sp28;
    D_8016E444 = sp2C;
}

void func_80082AB4(void) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    s16 temp;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;

    sp18 = D_8016E430;
    sp1A = D_8016E432;
    sp1C = D_8016E434;
    sp20 = D_8016E438;
    sp24 = D_8016E43C;
    sp28 = D_8016E440;
    sp2C = D_8016E444;
    gCurrentLevel = 0xB0;
    func_80081C50();
    D_80177628 = 0;
    func_800824A8();
    D_8016E430 = sp18;
    D_8016E432 = sp1A;
    D_8016E434 = sp1C;
    D_8016E438 = sp20;
    D_8016E43C = sp24;
    D_8016E440 = sp28;
    D_8016E444 = sp2C;
}

void func_80082BBC(void) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    s16 temp;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;

    sp18 = D_8016E430;
    sp1A = D_8016E432;
    sp1C = D_8016E434;
    sp20 = D_8016E438;
    sp24 = D_8016E43C;
    sp28 = D_8016E440;
    sp2C = D_8016E444;
    gCurrentLevel = 0xBB;
    func_80081C50();
    D_80177628 = 0;
    func_800824A8();
    D_8016E430 = sp18;
    D_8016E432 = sp1A;
    D_8016E434 = sp1C;
    D_8016E438 = sp20;
    D_8016E43C = sp24;
    D_8016E440 = sp28;
    D_8016E444 = sp2C;
}

void func_80082CC4(void) {
    s32 sp1C;
    s32 sp18;

    sp18 = gCurrentLevel;
    sp1C = MAP_BOMBER_BASE_ENTRANCE;
    if (sp18 == MAP_HOLE_LAKE) {
        sp1C = 7;
    } else if ((sp18 == MAP_ERARS_LAKE_1) || (sp18 == MAP_AQUAWAY) || (sp18 == MAP_CUTSCENE_POST_AQUA_TANK) ||
               (sp18 == MAP_FREEZE_LAKE)) {
        sp1C = 3;
    } else {
        if (sp18 == MAP_BIG_CANNON) {
            sp1C = 6;
        } else if ((sp18 == MAP_MILLIAN_ROAD) || (sp18 == MAP_HEAVEN_SKY) || (sp18 == MAP_OUTER_ROAD)) {
            sp1C = 2;
        } else if (sp18 == MAP_KILLER_GATE) {
            sp1C = 8;
        } else if ((sp18 == MAP_BARUDA) || (sp18 == MAP_HADES_CRATER)) {
            sp1C = 4;
        } else if (sp18 == MAP_EMERALD_TUBE) {
            sp1C = 9;
        } else if (sp18 == MAP_SNOW_CIRCUIT) {
            sp1C = 5;
        }
    }
    if (sp1C != MAP_BOMBER_BASE_ENTRANCE) {
        Demo_Start(sp1C);
    }
}

void func_80082E38(s32 arg0) {
    s8 sp27;
    s8 sp26;
    s8 sp25;
    s8 sp24;

    if (arg0 == 0) {
        return;
    }
    D_8013488C = 3;
    func_80025D4C(D_8013488C);
    func_8005FBD0();
    if (arg0 < 6) {
        sp27 = D_8010CBCD[arg0][0];
        sp26 = D_8010CBCD[arg0][1];
        sp25 = D_8010CBCD[arg0][2];
        func_8005FC98(sp27, sp26, sp25, 1);
    } else if (arg0 == 6) {
        sp27 = 6;
        sp26 = 1;
        sp25 = 3;
        func_8005FC98(sp27, sp26, sp25, 5);
        D_801347EB[((sp27 * 0x15) + (sp26 * 7) + sp25)] = 5;
        func_80025428(D_8013488C, 7);
        sp24 = 0;
        do {
            func_80025568(D_8013488C, sp24);
        } while (++sp24 < 0x18);
    } else if (arg0 == 7) {
        sp27 = 5;
        sp26 = 1;
        sp25 = 7;
        func_8005FC98(sp27, sp26, sp25, 5);
        sp24 = 0;
        do {
            func_80025568(D_8013488C, sp24);
        } while (++sp24 < 0x17);
    } else {
        sp27 = D_80134801 = gLevelInfo[gCurrentLevel]->Stage;
        sp26 = D_80134802 = gLevelInfo[gCurrentLevel]->Area;
        sp25 = D_80134803 = gLevelInfo[gCurrentLevel]->Map;
        D_80134800 = 2;
        func_8005FC98(D_80134801, D_80134802, D_80134803, 5);
    }
    func_800250A0((s32) D_8013488C);
    func_8002536C(D_8013488C, sp27 - 1, sp26 - 1, sp25 - 1, 2);
    func_800880E4();
    func_8002598C(D_8013488C);
    func_80024EF4(D_8013488C);
}

void func_80083180(s32 arg0) {
    s32 sp2C_pad;
    s8 pad2B;
    s8 pad2A;
    s8 pad29;
    s8 sp28;
    s8 sp27;
    s8 pad26;
    s8 pad25;
    s8 pad24;
    s32 sp20;

    /* Flowgraph is not reducible, falling back to gotos-only mode. */
    if (arg0 != 0) {
        func_80082E38(arg0);
        if (arg0 == 0x64) {
            D_8016E3CC = 0;
            arg0 = 0;
            D_8016E3D4 = 0;
            D_80177630 = 0;
            goto loop_67;
        }
    }
    func_80016D74(0);
    if (!(gControllerBits & 1)) {
        PlayTrack_WithVolLoop(-1, -1, 0);
        func_80000DAC();
        func_803303A4();
    }

block_5:
    PlayTrack_WithVolLoop(-1, -1, 0);
    func_80000D4C();
    func_80330440();

demo_init:
    Demo_Start(0);

block_7:
    func_80000E6C();

    if ((sp20 = func_80330594()) == 1) {
        goto demo_init;
    }

    if (gShowDebugMenu == 1) {
        gShowDebugMenu = 1;
    } else if (gShowDebugMenu == 2) {
        gShowDebugMenu = 1;
        if (arg0 == 0) {
            return;
        }
    }

    D_80134888 = 0;
    D_8013488C = 0;
block_15:
    PlayTrack_WithVolLoop(0x1C, -1, 1);
loop_16:
    func_80000CEC();
    sp20 = func_80333164();
    if (sp20 == 0) {
        goto CASE_0;
    } else if (sp20 == 1) {
        goto CASE_1;
    } else if (sp20 == 2) {
        D_8013488D = 0;
        goto loop_37;
    } else if (sp20 == 3) {
        goto CASE_3;
    } else {
        PlayTrack_WithVolLoop(-1, -1, 1);
        goto block_7;
    }
CASE_0:
    D_80177630 = 0;
    goto block_49;

CASE_1:
    sp20 = 0;

    while (TRUE) {
        func_80000ECC();
        sp20 = func_803316CC(sp20);
        if (sp20 != 6) {
            func_80000E0C();
            func_8033248C(sp20, 1);
        } else {
            break;
        }
    }

    goto loop_16;

CASE_3:
    func_8005FBD0();
    func_800880E4();
    D_8016E3D4 = 0;
    gCurrentLevel = MAP_BOMBER_STAR_HUB_CUTSCENE;
    D_80177630 = 4;
    goto block_49;

loop_37:
    func_80000F2C();
    sp20 = func_8033148C();

    if (sp20 == 0) {
        PlayTrack_WithVolLoop(-1, -1, 0);
        func_80000F2C();
        func_80332BDC();
        PlayTrack_WithVolLoop(0x1C, -1, 1);
        goto loop_37;
    } else if (sp20 == 1) {
        func_80088094();
        D_8016E3D4 = 0;
        gCurrentLevel = 0xAC;
        D_80177630 = 2;
        goto block_49;
    } else if (sp20 == 2) {
        func_800880E4();
        D_8016E3D4 = 0;
        gCurrentLevel = 0xB1;
        D_80177630 = 3;
        goto block_49;
    } else if (sp20 == 3) {
        D_80134801 = 0;
        D_80177630 = 1;
        goto block_49;
    }
    goto loop_16;
block_49:
    D_8016E3CC = 0;
    if (D_80177630 >= 2) {
        D_80177600 = 0;
        goto loop_133;
    }
block_51:
    func_800880E4();
    if (D_80134801 == -1) {
        func_80025D4C(D_8013488C);
        func_8002598C(D_8013488C);
        D_80134800 = 0;
        D_80134803 = 0;
        D_80134802 = 0;
        D_80134801 = 0;
        func_8006A2BC();
        func_800250A0((s32) D_8013488C);
        func_8002536C(D_8013488C, 0, 0, 0, 2);
        func_80024EF4(D_8013488C);
        D_80134801 = 0;
        D_80134802 = 0;
        D_80134803 = 0;
        D_80134800 = 0;
        func_8008279C();
    } else {
        func_80025978(D_8013488C);
        func_800252AC(D_8013488C, &D_80134801, &D_80134802, &D_80134803, &D_80134800);
    }
block_54:
    func_800251D4(D_8013488C);
    if (D_80177630 == 1) {
        D_80134801 = 0;
        D_80134802 = 0;
        D_80134803 = 0;
        D_80134800 = 0;
        func_800829AC();
    }

block_56:
    PlayTrack_WithVolLoop(0x1A, -1, 1);
    func_80000C2C();
    sp20 = func_80335DE4_unk_bin_2();
    if (sp20 != 0) {
        if (D_80177630 == 0) {
            goto block_15;
        } else {
            goto loop_37;
        }
    }

    if (func_800600B8(0, D_80134801) != 0 || func_800600B8(1, D_80134802) != 0 || func_8006A054() != 0) {
        D_8016E3D4 = 1;
    } else {
        D_8016E3D4 = 0;
    }

    func_80069F0C(D_8016E3D4);
    func_80082CC4();
loop_67:
    func_80081C50();
loop_68:
    sp28 = func_800253EC(D_8013488C) & 2;
    sp27 = func_80025764(D_8013488C);
    func_80025608(D_8013488C);
    func_800258A0(D_8013488C);
    func_800882C8();
    D_80177628 = 0;
    func_800824A8();
    if (D_8016E3CC == -1) {
        goto end;
    } else if (D_8016E3CC == 4) {
        func_80025674(D_8013488C);
        func_8002590C(D_8013488C);
        func_80088338();
        func_8002598C(D_8013488C);
        func_80024EF4(D_8013488C);
        goto block_56;
    } else if (D_8016E3CC == 1) {
        func_80025674(D_8013488C);
        func_8002590C(D_8013488C);

        if (gCurrentLevel == MAP_BOMBER_BASE_ENTRANCE || gCurrentLevel == MAP_AIR_ROOM_SELECT || gCurrentLevel == MAP_ZERO_G_ENTRANCE || gCurrentLevel == MAP_MIRROR_ROOM_ENTRANCE ||
            gCurrentLevel == MAP_NATIA_1_ENTRANCE) {
        } else {
            func_80069FD8();
            func_80069F0C(1);
        }

        func_80088248(-1);
        if (gLifeCount == 0) {
            func_80000C8C();
            if (func_80331154() == 0) {
                func_80088134();
                func_8002598C(D_8013488C);
                func_80024EF4(D_8013488C);
                goto block_56;
            } else {
                func_80088184();
                func_8002598C(D_8013488C);
                func_80024EF4(D_8013488C);
                if (D_80177630 == 0) {
                    PlayTrack_WithVolLoop(-1, -1, 1);
                    goto block_7;
                } else {
                    goto loop_37;
                }
            }
        } else {
            func_800881D4();
            func_8002598C(D_8013488C);
            func_80024EF4(D_8013488C);
            goto loop_67;
        }
    } else if (D_8016E3CC == 2 || D_8016E3CC == 3) {
        func_80024EF4(D_8013488C);

        if (D_8016E3CC == 3 || (D_8016E3D4 != 0 && D_80177620 != 0)) {
            if (gCurrentLevel == 0x9E) {
                gHealthCount = gMaxHealth;
                gBombCount = 3;
                gFireCount = 3;
                func_8002598C(D_8013488C);
                func_80024EF4(D_8013488C);
            }

            func_80069FD8();
            if (func_800600B8(0, D_80134801) != 0) {
                func_80000E0C();
                if (D_8016E3D4 == 0) {
                    func_8033248C((s32) D_80134801, 0);
                } else {
                    func_8033248C((s32) D_80134801, 1);
                }
            }

            if (D_80177630 == 0) {
                if (gCurrentLevel == MAP_CUTSCENE_BAGULAR_3_WIN) {

                    if (D_8016E3D4 == 0 || !(func_800253EC(D_8013488C) & 2)) {
                        Demo_Start(1);
                        func_80082BBC();
                    }

                    if (D_8016E3D4 == 0 && (func_800253EC(D_8013488C) & 2)) {
                        func_80082678();
                    }

                    D_80134803 = 0;
                    D_80134802 = 0;
                    D_80134801 = 0;
                    D_80134800 = 0;
                    goto block_5;
                } else if (gCurrentLevel == 0x55) {
                    func_800828A4();
                    D_80134803 = 0;
                    D_80134802 = 0;
                    D_80134801 = 0;
                    D_80134800 = 0;
                    goto block_5;
                }
            }

            if (((D_80177630 == 0) && func_800600B8(0, 4) && sp28 == 0 && (func_800253EC(D_8013488C) & 2))) {
                func_80082678();
            }

            if ((D_80177630 == 1 && sp27 == 0 && func_80025764(D_8013488C) != 0)) {
                func_80082AB4();
                goto loop_37;
            }

            if (!(D_8016E3D4 != 0 || D_80134801 >= 4 || func_800600B8(0, D_80134801) == 0)) {
                func_80082500();
                func_8002598C(D_8013488C);
                func_80024EF4(D_8013488C);
            }

            func_800252AC(D_8013488C, &D_80134801, &D_80134802, &D_80134803, &D_80134800);
            func_8006A168();
            func_80069FD8();
            goto block_56;
        } else {
            goto loop_68;
        }
    }

    goto block_7;
loop_133:
    func_80081C50();
loop_134:
    D_80177628 = 0;
    func_800824A8();
    if (D_8016E3CC == -1) {
        goto end;
    } else if (D_8016E3CC == 4) {
        if (D_80177630 == 2) {
            goto loop_37;
        } else if (D_80177630 == 3) {
            goto loop_37;
        } else {
            goto block_15;
        }
    } else if (D_8016E3CC == 1) {
        func_80069FD8();
        func_80069F0C(1);
        func_80088248(-1);
        if (gLifeCount == 0) {
            func_80000C8C();
            if (func_80331154() == 0) {
                if (D_80177630 == 2) {
                    func_80088094();
                } else {
                    func_80088134();
                }
                goto loop_133;
            } else if (D_80177630 == 2) {
                goto loop_37;
            } else if (D_80177630 == 3) {
                goto loop_37;
            } else {
                goto block_15;
            }
        } else {
            func_800881D4();
            goto loop_133;
        }
    } else if (D_8016E3CC == 2 || D_8016E3CC == 3) {

        if (D_80177630 == 2) {
            if (D_8016E432 == 0xAD) {
                if (D_80177640 == 1) {
                    D_8016E432 = 0xAD;
                } else if (D_80177640 == 2) {
                    D_8016E432 = 0xAE;
                } else if (D_80177640 == 3) {
                    D_8016E432 = 0xAE;
                }
            } else if (D_8016E432 == 0x7F) {
                goto loop_37;
            }
        } else if (D_80177630 == 3) {
            if (D_8016E432 == 0x7F) {
                goto loop_37;
            }
        } else if (D_8016E432 == 0x7F) {
            goto block_15;
        }
        goto loop_134;
    }
end:;
}
