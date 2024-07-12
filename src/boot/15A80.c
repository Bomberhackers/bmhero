#include "common.h"
#include "variables.h"

// File variables
extern f32 D_8004BC10; // .rodata
extern f32 D_8004A400[]; // .rodata

// External functions
f32 func_800155A8(f32, f32);
f32 func_80015634(f32 arg0, f32 arg1);

// File functions
f32 func_80014F50(f32 arg0, f32 arg1);
f32 func_800155A8(f32 arg0, f32 arg1);
f32 func_80015634(f32 arg0, f32 arg1);
f32 func_800156C4(f32 arg0, f32 arg1);
f32 func_80015744(f32 arg0);
s32 func_800157EC(f32 arg0, f32 arg1, f32 arg2);
void func_800158B4(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4);
f32 func_80015C24(f32 arg0, f32 arg1, s64 arg2, s64 arg4, s64 arg6, s64 arg8);
f32 func_80015D2C(f32 arg0, f32 arg1, s64 arg2, s64 arg3, s64 arg4, s64 arg5);
s32 func_8001608C(s64 arg0, s64 arg2, s64 arg4, s64 arg6, s64 arg8, s64 argA, s64 argC, s64 argE);
s32 func_800162F0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
s32 func_800163AC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
s32 func_80016560(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                  f32 arg8, f32 arg9);
void func_80016A80(s64 arg0, s64 arg2, s64 arg4, f32 *arg8, f32 *arg9, f32 *argA, f32 *argB, f32 *argC,
                   f32 *argD);

#pragma GLOBAL_ASM("asm/nonmatchings/boot/15A80/func_80014E80.s")

    f32 func_80014F50(f32 arg0, f32 arg1) {
    f32 sp4;
    f32 sp0;

    if (arg0 == arg1) {
        if (arg0 == 0.0f) {
            return 0.0f;
        } else if (arg0 > 0.0f) {
            return 45.0f;
        } else {
            return 225.0f;
        }
    } else if (arg0 == 0.0f) {
        if (arg1 > 0.0f) {
            return 90.0f;
        } else {
            return 270.0f;
        }
    } else if (arg1 == 0.0f) {
        if (arg0 > 0.0f) {
            return 0.0f;
        } else {
            return 180.0f;
        }
    } else if ((arg0 * arg0) == (arg1 * arg1)) {
        if (arg0 > 0.0f) {
            return D_8004BC10;
        } else {
            return 135.0f;
        }
    } else if (arg0 > 0.0f) {
        if (arg1 > 0.0f) {
            if (arg1 < arg0) {
                sp4 = (arg1 / arg0) * 100.0f;
                return D_8004A400[(s32) sp4];
            } else {
                sp4 = (arg0 / arg1) * 100.0f;
                sp0 = 90.0f - D_8004A400[(s32) sp4];
                return sp0;
            }
        } else if (SQ(arg0) > SQ(arg1)) {
            sp4 = ((-1.0f * arg1) / arg0) * 100.0f;
            sp0 = 360.0f - D_8004A400[(s32) sp4];
            return sp0;
        } else {
            sp4 = ((-1.0f * arg0) / arg1) * 100.0f;
            sp0 = D_8004A400[(s32) sp4] + 270.0f;
            return sp0;
        }
    } else if (arg1 > 0.0f) {
        if (SQ(arg0) > SQ(arg1)) {
            sp4 = ((-1.0f * arg1) / arg0) * 100.0f;
            sp0 = 180.0f - D_8004A400[(s32) sp4];
            return sp0;
        } else {
            sp4 = ((-1.0f * arg0) / arg1) * 100.0f;
            sp0 = D_8004A400[(s32) sp4] + 90.0f;
            return sp0;
        }
    } else if (arg0 < arg1) {
        sp4 = (arg1 / arg0) * 100.0f;
        sp0 = D_8004A400[(s32) sp4] + 180.0f;
        return sp0;
    } else {
        sp4 = (arg0 / arg1) * 100.0f;
        sp0 = 270.0f - D_8004A400[(s32) sp4];
        return sp0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/15A80/func_80015538.s")

// Doesn't exists
#pragma GLOBAL_ASM("asm/nonmatchings/boot/15A80/func_80015598.s")

f32 func_800155A8(f32 arg0, f32 arg1) {
    f32 sp1C;

    sp1C = func_80014F50(arg0, arg1) - 90.0f;
    if (sp1C < 0.0f) {
        sp1C += 360.0f;
    }
    return sp1C;
}

f32 func_80015634(f32 arg0, f32 arg1) {
    f32 sp1C;

    sp1C = func_80014F50(arg0, -arg1) + 90.0f;
    if (sp1C >= 360.0f) {
        sp1C -= 360.0f;
    }
    return sp1C;
}

f32 func_800156C4(f32 arg0, f32 arg1) {
    f32 sp1C;

    sp1C = func_80014F50(arg0, arg1);
    if (sp1C >= 360.0f) {
        sp1C -= 360.0f;
    }
    return sp1C;
}

f32 func_80015744(f32 arg0) {
    if ((arg0 > 90.0f) && (arg0 <= 180.0f)) {
        arg0 = 180.0f - arg0;
    } else if ((arg0 > 180.0f) && (arg0 < 270.0f)) {
        arg0 = 540.0f - arg0;
    }
    return arg0;
}


s32 func_800157EC(f32 arg0, f32 arg1, f32 arg2) {
    f32 sp4;

    sp4 = arg1 - arg0;
    if (sp4 < 0.0f) {
        sp4 += 360.0f;
    }
    if ((sp4 < arg2) || ((360.0f - arg2) < sp4)) {
        return 0;
    }
    if (sp4 >= 180.0f) {
        return -1;
    }
    return 1;
}

void func_800158B4(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4) {
    *arg4 = func_80015634(arg0, arg2);
    *arg3 = func_800155A8(arg1, sqrtf(SQ(arg0) + SQ(arg2)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/15A80/func_80015944.s")

f32 func_80015C24(f32 arg0, f32 arg1, s64 arg2, s64 arg4, s64 arg6, s64 arg8) {
    f32 sp3C;

    if (arg2 != 0) {
        sp3C = (((-(arg4) *arg0) - (arg6 * arg1)) + arg8) / arg2;
    } else {
        sp3C = 0.0f;
    }
    return sp3C;
}

f32 func_80015D2C(f32 arg0, f32 arg1, s64 arg2, s64 arg3, s64 arg4, s64 arg5) {
    f32 sp3C;

    if ((arg3 != 0)) {
        sp3C = (((-(arg2) *arg0) - (arg4 * arg1)) + arg5) / arg3;
    } else {
        sp3C = 0.0f;
    }
    return sp3C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/15A80/func_80015E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/15A80/func_80015F3C.s")

s32 func_8001608C(s64 arg0, s64 arg2, s64 arg4, s64 arg6, s64 arg8, s64 argA, s64 argC, s64 argE) {
    f32 sp34;
    f32 sp30;

    sp34 = func_80015D2C(0.0f, 0.0f, arg0, arg2, arg4, arg6);
    sp30 = func_80015D2C(0.0f, 0.0f, arg8, argA, argC, argE);
    if (sp34 != sp30) {
        return 0;
    }
    sp34 = func_80015D2C(100.0f, 100.0f, arg0, arg2, arg4, arg6);
    sp30 = func_80015D2C(100.0f, 100.0f, arg8, argA, argC, argE);
    if (sp34 != sp30) {
        return 0;
    }
    sp34 = func_80015D2C(100.0f, 0.0f, arg0, arg2, arg4, arg6);
    sp30 = func_80015D2C(100.0f, 0.0f, arg8, argA, argC, argE);
    if (sp34 != sp30) {
        return 0;
    }
    return 1;
}

s32 func_800162F0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f64 sp0;

    sp0 = (f64) (((arg4 - arg2) * (arg1 - arg3)) - ((arg5 - arg3) * (arg0 - arg2)));
    if (sp0 > 0.0) {
        return 1;
    } else if (sp0 < 0.0) {
        return -1;
    }
    return 0;
}

s32 func_800163AC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                  f32 arg8, f32 arg9) {
    f64 sp0;

    sp0 = (f64) (((arg4 - arg2) * (arg1 - arg3)) - ((arg5 - arg3) * (arg0 - arg2)));
    if (sp0 > 0.0) {
        return 0;
    }
    sp0 = (f64) (((arg6 - arg4) * (arg1 - arg5)) - ((arg7 - arg5) * (arg0 - arg4)));
    if (sp0 > 0.0) {
        return 0;
    }
    sp0 = (f64) (((arg8 - arg6) * (arg1 - arg7)) - ((arg9 - arg7) * (arg0 - arg6)));
    if (sp0 > 0.0) {
        return 0;
    }
    sp0 = (f64) (((arg2 - arg8) * (arg1 - arg9)) - ((arg3 - arg9) * (arg0 - arg8)));
    if (sp0 > 0.0) {
        return 0;
    }
    return 1;
}

s32 func_80016560(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                  f32 arg8, f32 arg9) {
    f64 sp0;

    sp0 = (f64) (((arg4 - arg2) * (arg1 - arg3)) - ((arg5 - arg3) * (arg0 - arg2)));
    if (sp0 < 0.0) {
        return 0;
    }
    sp0 = (f64) (((arg6 - arg4) * (arg1 - arg5)) - ((arg7 - arg5) * (arg0 - arg4)));
    if (sp0 < 0.0) {
        return 0;
    }
    sp0 = (f64) (((arg8 - arg6) * (arg1 - arg7)) - ((arg9 - arg7) * (arg0 - arg6)));
    if (sp0 < 0.0) {
        return 0;
    }
    sp0 = (f64) (((arg2 - arg8) * (arg1 - arg9)) - ((arg3 - arg9) * (arg0 - arg8)));
    if (sp0 < 0.0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/15A80/func_80016714.s")

void func_80016A80(s64 arg0, s64 arg2, s64 arg4, f32 *arg8, f32 *arg9, f32 *argA, f32 *argB, f32 *argC,
                   f32 *argD) {
    f32 sp34;
    f32 sp30;

    *argA = 90.0f - func_80014F50(arg4, arg2);
    *argC = func_80014F50(arg0, arg2) - 90.0f;
    *argB = 0.0f;

    if ((sp34 = *argA) < 0.0f) {
        sp34 = -sp34;
    }

    if ((sp30 = *argB) < 0.0f) {
        sp30 = -sp30;
    }
    if (sp34 < sp30) {
        sp34 = sp30;
    }

    if ((sp30 = *argC) < 0.0f) {
        sp30 = -sp30;
    }
    if (sp34 < sp30) {
        sp34 = sp30;
    }
    *argD = sp34;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/15A80/func_80016C54.s")
