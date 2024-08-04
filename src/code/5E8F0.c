#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006C3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006C428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006CC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006D6F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006D7A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006D964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006DB7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006DDF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006DE90.s")

void func_8006E088(void) {
    s32 tableIdx;
    u32 romStart;
    u32 romEnd;

    if (D_8017792E != 0) {
        tableIdx = D_8017792E - 1;
        romStart = gUnkROMTable801051E0[tableIdx].romStart;
        romEnd = gUnkROMTable801051E0[tableIdx].romEnd;
        DecompressFile(0x18, romStart, romEnd);
        func_8006DE90(gFileArray[0x18].ptr);
    }
    D_80177A14 = 0.0f;
    D_80177A1A = 0xA;
    D_80177A1E = 4;
    D_80177A24 = D_801055B8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006E160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006E1B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006E7CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006E93C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006F570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006F664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8006F780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_80070644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_80070664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8007070C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_80070934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_80070A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_80070AC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_80070B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_800711B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_8007121C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_80071240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5E8F0/func_800713D0.s")
