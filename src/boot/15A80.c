#include <ultra64.h>

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
void func_800158B4(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4);
f32 func_80015C24(f32 arg0, f32 arg1, s64 arg2, s64 arg4, s64 arg6, s64 arg8);
f32 func_80015D2C(f32 arg0, f32 arg1, s64 arg2, s64 arg3, s64 arg4, s64 arg5);
s32 func_8001608C(s64 arg0, s64 arg2, s64 arg4, s64 arg6, s64 arg8, s64 argA, s64 argC, s64 argE);
s32 func_800162F0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
s32 func_800163AC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
s32 func_80016560(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
void func_80016A80(s64 arg0, s64 arg2, s64 arg4, s64 arg5, f32* argA, f32* argB, f32* argC, f32* argD);

// Temporal name
f32 gNumTable[100] = {
    0.0f,      0.57294f,  1.14576f,  1.71836f,  2.29061f,  2.86241f,  3.43363f,  4.00417f,  4.57392f,  5.14276f,
    5.71059f,  6.2773f,   6.84277f,  7.40691f,  7.96961f,  8.53077f,  9.09028f,  9.64805f,  10.20397f, 10.75797f,
    11.30993f, 11.85978f, 12.40742f, 12.95276f, 13.49573f, 14.03624f, 14.57422f, 15.10958f, 15.64225f, 16.17216f,
    16.69924f, 17.22344f, 17.74467f, 18.26289f, 18.77803f, 19.29005f, 19.79888f, 20.30447f, 20.80679f, 21.30578f,
    21.80141f, 22.29363f, 22.78241f, 23.2677f,  23.74949f, 24.22775f, 24.70243f, 25.17352f, 25.64101f, 26.10485f,
    26.56505f, 27.02158f, 27.47443f, 27.92359f, 28.36905f, 28.81079f, 29.24883f, 29.68314f, 30.11373f, 30.5406f,
    30.96376f, 31.38319f, 31.79891f, 32.21093f, 32.61924f, 33.02387f, 33.42481f, 33.82209f, 34.2157f,  34.60568f,
    34.99202f, 35.37475f, 35.75389f, 36.12944f, 36.50144f, 36.8699f,  37.23483f, 37.59627f, 37.95423f, 38.30874f,
    38.65981f, 39.00747f, 39.35175f, 39.69267f, 40.03026f, 40.36454f, 40.69553f, 41.02327f, 41.34778f, 41.66908f,
    41.98721f, 42.30219f, 42.61406f, 42.92283f, 43.22853f, 43.5312f,  43.83086f, 44.12754f, 44.42127f, 44.71208f,
};

s32 func_80014E80(s16 arg0) {

    D_8016E092 = (D_8016E092 * 61 * 9 - 1);

    if (!arg0) {
        return D_8016E092;
    } else {
        if (arg0 > 0) {
            return arg0 * (u16) D_8016E092 / 0x10000;
        } else {
            return ((arg0 * D_8016E092) / 32768);
        }
    }
}

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
    } else if (SQ(arg0) == SQ(arg1)) {
        if (arg0 > 0.0f) {
            return 315.0f;
        } else {
            return 135.0f;
        }
    } else if (arg0 > 0.0f) {
        if (arg1 > 0.0f) {
            if (arg1 < arg0) {
                sp4 = (arg1 / arg0) * 100.0f;
                return gNumTable[(s32) sp4];
            } else {
                sp4 = (arg0 / arg1) * 100.0f;
                sp0 = 90.0f - gNumTable[(s32) sp4];
                return sp0;
            }
        } else if (SQ(arg0) > SQ(arg1)) {
            sp4 = ((-1.0f * arg1) / arg0) * 100.0f;
            sp0 = 360.0f - gNumTable[(s32) sp4];
            return sp0;
        } else {
            sp4 = ((-1.0f * arg0) / arg1) * 100.0f;
            sp0 = gNumTable[(s32) sp4] + 270.0f;
            return sp0;
        }
    } else if (arg1 > 0.0f) {
        if (SQ(arg0) > SQ(arg1)) {
            sp4 = ((-1.0f * arg1) / arg0) * 100.0f;
            sp0 = 180.0f - gNumTable[(s32) sp4];
            return sp0;
        } else {
            sp4 = ((-1.0f * arg0) / arg1) * 100.0f;
            sp0 = gNumTable[(s32) sp4] + 90.0f;
            return sp0;
        }
    } else if (arg0 < arg1) {
        sp4 = (arg1 / arg0) * 100.0f;
        sp0 = gNumTable[(s32) sp4] + 180.0f;
        return sp0;
    } else {
        sp4 = (arg0 / arg1) * 100.0f;
        sp0 = 270.0f - gNumTable[(s32) sp4];
        return sp0;
    }
}

f32 func_80015538(f32 arg0, f32 arg1) {
    arg0 += arg1;
    if (arg0 >= 360.0f) {
        arg0 -= 360.0f;
    } else if (arg0 < 0.0f) {
        arg0 += 360.0f;
    }

    return arg0;
}

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

void func_800158B4(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4) {
    *arg4 = func_80015634(arg0, arg2);
    *arg3 = func_800155A8(arg1, sqrtf(SQ(arg0) + SQ(arg2)));
}

void func_80015944(f64 arg0, f64 arg1, f64 arg4, f64 arg5, f64 arg6, f64 arg7, f64 arg8, f64 arg9, f64 argA, s32* arg12,
                   s32* arg13, s32* arg14, s32* arg15, UNUSED f64 argB, UNUSED f64 argC, UNUSED f64 argE,
                   UNUSED f64 arg10) {

    f64 sp10;
    f64 sp8;
    f64 sp0;

    *arg12 = ((((arg7 - argA) * arg1) + (arg6 * (argA - arg4)) + (arg9 * (arg4 - arg7))) / 100.0);

    *arg13 = ((((arg5 - arg8) * arg4) + (arg7 * (arg8 - arg0)) + (argA * (arg0 - arg5))) / 100.0);

    *arg14 = ((((arg6 - arg9) * arg0) + (arg5 * (arg9 - arg1)) + (arg8 * (arg1 - arg6))) / 100.0);

    sp10 = (((arg6 * argA) - (arg7 * arg9)) * arg0) / 100.0;
    // arg6 * arg8  - arg7 * argA
    sp8 = (((arg7 * arg8) - (arg5 * argA)) * arg1) / 100.0;
    sp0 = (((arg5 * arg9) - (arg6 * arg8)) * arg4) / 100.0;
    *arg15 = (sp10 + sp8 + sp0);
}

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

f32 func_80015E34(f32 arg0, f32 arg1, s64 arg2, s64 arg4, s64 arg6, s64 arg8) {
    f32 sp3C;

    if (arg6 != 0) {
        sp3C = ((-arg2 * arg0) - (arg4 * arg1) + arg8) / arg6;
    } else {
        sp3C = 0.0f;
    }

    return sp3C;
}

s32 func_80015F3C(f32 arg0, f32 arg1, f32 arg2, s64 arg4, s64 arg6, s64 arg8, s64 argA) {
    s64 sp48;

    sp48 = (-arg4 * arg0) - (arg6 * arg1) - (arg8 * arg2) + argA;

    if (sp48 < 0) {
        return -1;
    } else if (sp48 > 0) {
        return 1;
    }

    return 0;
}

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

s32 func_800163AC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
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

s32 func_80016560(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
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

void func_80016714(s64 arg0, s64 arg1, s64 arg2, s64 arg3, s64 arg4, s64 arg5, s64 arg6, s64 arg7, f32* arg8, f32* arg9,
                   f32* argA, f32* argB) {
    s64 sp48;
    s64 sp40;
    s64 sp38;

    sp48 = (arg4 * arg1) - (arg0 * arg5);

    sp40 = (arg6 * arg1) - (arg2 * arg5);

    sp38 = -((arg5 * arg3) - (arg1 * arg7));

    if ((sp48 != 0)) {
        *arg8 = func_80015C24(0.0f, 0.0f, sp48, 0, sp40, sp38);
        *arg9 = 0.0f;
    } else if (sp40 != 0) {
        *arg9 = func_80015E34(0.0f, 0.0f, sp48, 0, sp40, sp38);
        *arg8 = 0.0f;
    } else {
        *arg8 = 0.0f;
        *arg9 = 0.0f;
    }
    if ((sp48 != 0)) {
        *argA = func_80015C24(0.0f, 10.0f, sp48, 0, sp40, sp38);
        *argB = 10.0f;
    } else if ((sp40 != 0)) {
        *argB = func_80015E34(10.0f, 0.0f, sp48, 0, sp40, sp38);
        *argA = 10.0f;
    } else {
        *argA = 0.0f;
        *argB = 0.0f;
    }
}

void func_80016A80(s64 arg0, s64 arg2, s64 arg4, UNUSED s64 arg5, f32* argA, f32* argB, f32* argC, f32* argD) {
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

void func_80016C54(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5, f32* arg6) {
    s32 sp3C;

    func_80067748(arg0, arg1, arg2);
    sp3C = D_801776E0 & 1;

    func_80016A80(D_801776F0[sp3C], D_80177700[sp3C], D_80177710[sp3C], 0, arg3, arg4, arg5, arg6);
}
