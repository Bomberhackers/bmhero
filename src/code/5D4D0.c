#include "common.h"

extern f32 D_8016E140;
extern f32 D_8016E144;
extern f32 D_8016E148;
extern u8 D_801776E0;
extern s8 D_801775EE;
extern s8 D_801348B2;
extern s16 D_80134C22;
extern f32 D_80134F28;
extern u16 D_80177958;

extern s32 func_80014E80(s32);                               /* extern */
extern void func_80067748(f32, f32, f32);                     /* extern */
extern void func_80081468(s32, f32, f32, f32);                  /* extern */
extern void func_80017BEC(s32, s32, s32, s32); 
extern void func_80017CFC(s32, s32, s32, s32); 

void func_8006AFB0(void) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    sp24 = (f32) func_80014E80(-0x3C0) + D_8016E140;
    sp20 = (f32) func_80014E80(0xF0) + (D_8016E144 + 540.0f);
    sp1C = (f32) func_80014E80(-0x3C0) + D_8016E148;
    func_80067748(sp24, sp20, sp1C);
    if (!(D_801776E0 & 1)) {
        func_80081468(0x2C1, sp24, sp20, sp1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006B084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006B1B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006B3BC.s")

void func_8006B5A4(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
        func_80017BEC(0, 0x35, -1, 0);
    }
}

void func_8006B5F8(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
        func_80017BEC(0, 0x35, -1, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006B64C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006B754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006B7BC.s")

void func_8006B8CC(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
        func_80017BEC(0, 0x35, -1, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006B920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006B9A0.s")

void func_8006B9F4(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
    }
    func_80017BEC(0, 0x3C, -1, 1);
    func_80017CFC(0, 0x3C, -1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006BA5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006BAC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006BBF4.s")

void func_8006BE9C(void) {
    if (D_801775EE == 0) {
        D_801775EE += 1;
        D_80177958 = 0;
    }
    if (D_80134C22 != 0) {
        if (D_80177958 == 0) {
            D_80134F28 += 2.0f;
            D_80177958 += 1;
        }
        else
        {
            D_80134F28 -= 2.0f;
            D_80177958 = 0;
        }
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006BF5C.s")

void func_8006C18C(void) {
    if ((D_80134C22 != 0) && (D_801775EE == 0)) {
        D_801775EE = 1;
        D_801348B2 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006C1DC.s")
