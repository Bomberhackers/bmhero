#include "common.h"

extern s8 D_80134801;
extern s8 D_80134802;
extern s8 D_80134803;
extern u8 D_80134808[];
void func_80069AD8(s32, s32);                          /* extern */
extern s8 D_8016E3CC;
extern struct UnkStructSTCG* D_8017753C;
extern s8 D_8013488C;

extern s16 D_80177788;
extern s16 D_80177798;
extern s16 D_801777A8;

void func_800250A0(s8);

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800642E0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80065ACC.s")

void func_80065AEC(f32 arg0, f32 arg1, f32 arg2, s32* arg3, s32* arg4, s32* arg5) {
    *arg3 = (s32) (((arg0 - (f32) D_80177788) / 60.0f) / 16.0f);
    *arg4 = (s32) (((arg1 - (f32) D_80177798) / 60.0f) / 16.0f);
    *arg5 = (s32) (((arg2 - (f32) D_801777A8) / 60.0f) / 16.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80065C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80065D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800660DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800663EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800669E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80066AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006707C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800670E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80067238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800673D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800675DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80067674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006770C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069AD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069D04.s")

void func_80069D88(s32 arg0, s32 arg1) {
    if (D_8016E3CC != 0) {
        return;
    }
    if (D_8017753C->Unk108 == 0) {
        return;
    }
    func_80069AD8(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069E88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069FD8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006A168.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006A1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006A2AC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006A95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006AA0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006AA24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006AA50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006AA60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006AB14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006AD28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006AF18.s")
