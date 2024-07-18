#include "common.h"
#include "variables.h"

//LEVEL LOADING RELATED FILE
//F6220 is rodata

void func_80069AD8(s32, s32);                          /* extern */
void func_8001A928(s32);                               /* extern */
void func_800650F0();                                  /* extern */
void func_80065C20();                                  /* extern */
void func_800669E0();                                  /* extern */
void func_80066AE8();                                  /* extern */
void func_800675DC();                                  /* extern */
void func_80067674();                                  /* extern */

extern s8 D_801776E0;
extern s8 D_80134801;
extern s8 D_80134802;
extern s8 D_80134803;
extern u8 D_80134808[];
extern s8 D_8016E3CC;
extern struct UnkStructSTCG* D_8017753C;
extern s8 D_8013488C;

extern s16 D_80177788;
extern s16 D_80177798;
extern s16 D_801777A8;

extern u8 D_80106DA0[]; //THIS MIGHT BE INCORRECT!!! unless for some reason there's two ways of accessing the same array??
extern u8 D_80106DA1[];

extern s32 D_801778F4;
extern s32 D_801778FC;
extern s32 D_80177904;

extern s16 D_80177608;
extern u8 D_801779E0;

extern s8 D_8016E3CD;
extern s8 D_8016E3D4;
extern s16 D_8016E432;

extern s8 D_8016E3CD;
extern s16 D_801775F6;
extern s16 D_801775FA;
extern s16 D_80177608;
extern s8 D_80177628;

extern s8 D_80177640;
extern s32 D_80177778;

extern f64 D_80104F90;

extern struct LevelInfo* gLevelInfo[];

void func_800250A0(s8);

//find free slot
s32 func_800642E0(void) {
    s32 sp4;
    
    for(sp4 = 0xE; sp4 < 0x4E; sp4++)
    {
        if(gPlayerData[sp4].unkA4 == 0)
        {
            return sp4;
        }
    }
    return -1;
}

s32 func_80064358(s32 arg0) {

    while(arg0 < 0x4E)
    {
        if (gPlayerData[arg0].unkA4 == 0)
        {
            return arg0;
        }
        arg0++;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800643C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800650F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800654AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800657E8.s")

struct UnkStruct80177778* func_80065ACC(void) {
    return D_801776F0.Unk88;
}

void func_80065AEC(f32 arg0, f32 arg1, f32 arg2, s32* arg3, s32* arg4, s32* arg5) {
    *arg3 = (s32) (((arg0 - (f32) D_801776F0.unk98) / 60.0f) / 16.0f);
    *arg4 = (s32) (((arg1 - (f32) D_801776F0.unkA8) / 60.0f) / 16.0f);
    *arg5 = (s32) (((arg2 - (f32) D_801776F0.unkB8) / 60.0f) / 16.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80065C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80065D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800660DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800663EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800669E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80066AE8.s")

void func_8006707C(void) {
    s32 sp1C;

    func_80066AE8();
    for(sp1C = 0x4E; sp1C < 0x8E; sp1C++)
    {
        func_8001A928(sp1C);
    }
    func_80065C20();
    func_800669E0();
    func_800650F0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800670E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80067238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800673D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800675DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80067674.s")

void func_8006770C(void) {
    func_800675DC();
    func_80067674();
    D_801776E0 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80067748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006828C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800682E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80068CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800695A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800697F0.s")

s32 func_800699B0(void) {
    u8 sp1F;
    s32 sp18;

    if(func_800254E8(D_8013488C) != 0)
    {
        sp18 = 0;
        for(sp1F = 0; sp1F < 5; sp1F++)
        {
            if (func_800697F0(sp1F) == 0) {
                sp18 += 1;
            }
        }
        if (sp18 >= 5) {
            return 1;
        }
    }

    return 0;
}

s32 func_80069A54(s8 arg0, s8 arg1) {
    if (D_8016E3CC != 0) {
        return 0;
    }
    D_8016E3CC = arg0;
    D_8016E3CD = arg1;
    return 1;
}

void func_80069AA8(s8 arg0, s8 arg1) {
    D_8016E3CC = arg0;
    D_8016E3CD = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069AD8.s")

void func_80069D04(s32 arg0, s32 arg1) {
    if (D_8016E3CC != 0) {
        return;
    }
    if (D_8017753C->Unk108 == 0) {
        return;
    }
    func_80069AD8(arg0, arg1);
    D_8016E3CC = 2;
}


void func_80069D88(s32 arg0, s32 arg1) {
    if (D_8016E3CC != 0) {
        return;
    }
    if (D_8017753C->Unk108 == 0) {
        return;
    }
    func_80069AD8(arg0, arg1);
}

void func_80069E00(s32 arg0, s32 arg1) {
    func_80069AD8(arg0, arg1);
}

void func_80069E38(void) {
    D_801778F4 = 0;
    D_801778FC = 0;
    D_80177904 = 0;
}

void func_80069E60(s32 arg0, s32 arg1, s32 arg2) {
    D_801778F4 = arg2;
    D_801778FC = arg0;
    D_80177904 = arg1;
}

void func_80069E88(void) {
    if (D_801778F4 == 0) {
        return;
    }
    D_801778F4 -= 1;
    if (D_801778F4 != 0) {
        return;
    }
    func_80069D88(D_801778FC, D_80177904);
}

//looks like this is handling level loading in some way
void func_80069F0C(s32 arg0) {
    if(arg0 != 0)
    {
        gCurrentLevel = D_80106DA1[D_80134801 * 0x2A + D_80134802 * 0xE + D_80134803 * 2];
    }
    else
    {
        gCurrentLevel = D_80106DA0[D_80134801 * 0x2A + D_80134802 * 0xE + D_80134803 * 2];
    }
}

void func_80069FD8(void) {
    struct LevelInfo* sp4;

    sp4 = gLevelInfo[gCurrentLevel];
    D_80134801 = sp4->Stage - 1;
    D_80134802 = sp4->Area - 1;
    D_80134803 = sp4->Map - 1;
}

s32 func_8006A054(void) {
    u8 sp7;

    sp7 = D_80134808[(D_80134801 * 0x15) + (D_80134802 * 7) + D_80134803] & 0xF;
    if ((sp7 == 0) || (sp7 == 6)) {
        return 0;
    }
    return 1;
}

s32 func_8006A0E4(void) {
    u8 sp7;

    sp7 = D_80134808[D_80134801 * 0x15 + D_80134802 * 7 + D_80134803] & 0xF;
    if (sp7 == 0) {
        return 0;
    }

    return 1;
}

void func_8006A168(void) {
    s32 sp1C;

    if (D_8016E3D4 == 0) {
        gCurrentLevel = (s32) D_8016E432;
    } else {
        sp1C = gCurrentLevel;
        gCurrentLevel = (s32) D_8016E432;
        func_80069FD8();
        if (func_8006A054() != 0) {
            gCurrentLevel = sp1C;
        }
    }
}

u32 func_8006A1F4(u32 arg0) {

    if(gLevelInfo[arg0]->Clear != 0)
    {
        arg0 = D_8016E432;
    }
    else
    {
        while(1) {
            arg0 = *gLevelInfo[arg0]->Unk8;
            if (gLevelInfo[arg0]->Clear != 0)
                break;
        } 
        arg0 = *gLevelInfo[arg0]->Unk8;
    }

    return arg0;
}

void func_8006A2BC(void) {
    u8 sp1F;

    sp1F = D_80134808[(D_80134801 * 0x15) + (D_80134802 * 7) + D_80134803] & 0xF0;
    D_80134808[(D_80134801 * 0x15) + (D_80134802 * 7) + D_80134803] = sp1F | 6;
    func_800250A0(D_8013488C);
}

void func_8006A388(void) {
    u8 sp1F;

    sp1F = D_80134808[0x69];
    if (!(sp1F & 0xF)) {
        sp1F &= 0xF0;
        D_80134808[0x69] = (u8) (sp1F | 6);
        func_800250A0(D_8013488C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006A404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006A898.s")

void func_8006A95C(void) {
    if (D_80177628 == 0) {
        return;
    }
    if ((D_80177608 == 0) || (D_801775FA == D_801775F6)) {
        D_8016E3CC = 3;
        D_8016E3CD = 1;
        if (D_80177608 == 0) {
            func_80070664(2);
        } else {
            func_80070664(3);
        }
    }
}

void func_8006AA0C(void) {
    D_80177640 = 0;
}

s32 func_8006AA24(s32 arg0) {
    if (D_80177640 == 0) {
        D_80177640 = arg0;
        return 1;
    }
    return 0;
}

//rodata will go brr here
void func_8006AA60(s32* arg0, s32* arg1, s32* arg2) {
    *arg0 = (s16) D_80177608 / 1800;
    *arg1 = (s32) ((s16) D_80177608 % 1800) / 30;
    *arg2 = (s32) ((f64) ((s16) D_80177608 % 30) * D_80104F90);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006AB14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006AD28.s")

void func_8006AF18(s16 arg0) {
    if (D_801779E0 != 0) {
        return;
    }
    D_80177608 += arg0;
    if (D_80177608 <= 0) {
        D_80177608 = 0;
    }
    else if (D_80177608 >= 0x270F) {
        D_80177608 = 0x270F;
    }
}
