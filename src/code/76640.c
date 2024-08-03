#include <ultra64.h>

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80084120.s")

void func_800841E8(void) {
    if ((gCurrentLevel == MAP_MAGMA_LAKE) || (gCurrentLevel == MAP_MAGMA_DAM)) {
        D_8016E110 = 2;
        D_8016E112 = 0x3C;
    } else {
        D_8016E110 = 0;
        D_8016E112 = 0;
    }
    D_8016E115 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_8008424C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_800842C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_800843CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80084430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80084BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80085424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_800857B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80085804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80085884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80085B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80085D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80086AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80086D50.s")

void func_80086E70(f32* arg0, f32* arg1, f32* arg2) {
    guMtxXFMF((f32 (*)[4]) D_80177550, *arg0, *arg1, *arg2, arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80086ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80087694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80087994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80087B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80087C58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80087D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80087E14.s")

void func_80088094(void) {
    gLifeCount = 1;
    gMaxHealth = 4;
    gHealthCount = gMaxHealth;
    gBombCount = 0;
    gFireCount = 0;
    gGemCount = 0;
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_800880E4.s")

void func_80088134(void) { //looks like the regular base stats
    gLifeCount = 3;
    gMaxHealth = 4;
    gHealthCount = gMaxHealth;
    gBombCount = 0;
    gFireCount = 0;
    gGemCount = 0;
}

void func_80088184(void) { //looks like the regular base stats
    gLifeCount = 3;
    gMaxHealth = 4;
    gHealthCount = gMaxHealth;
    gBombCount = 0;
    gFireCount = 0;
    gGemCount = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_800881D4.s")

void func_80088248(s32 arg0) {
    if (arg0 > 0) {
        gLifeCount += arg0;
        if ((s32) gLifeCount >= 99) {
            gLifeCount = 99;
        }
    }
    else if (gLifeCount != 0) {
        gLifeCount += arg0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_800882C8.s")

void func_80088338(void) {
    gLifeCount = D_80165238;
    gHealthCount = D_80165239;
    gMaxHealth = D_8016523A;
    gBombCount = D_8016523B;
    gFireCount = D_8016523C;
    gGemCount = D_8016523D;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_800883A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80088694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_8008884C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_800889A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80088A88.s")
