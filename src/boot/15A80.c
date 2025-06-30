#include <ultra64.h>

// External functions
f32 Math_CalcAngle2D(f32, f32);
f32 func_80015634(f32 arg0, f32 arg1);

// File functions
f32 Math_Atan2f(f32 arg0, f32 arg1);
f32 Math_CalcAngle2D(f32 arg0, f32 arg1);
f32 func_80015634(f32 arg0, f32 arg1);
f32 Math_CalcAngleSimple(f32 arg0, f32 arg1);
f32 Math_NormalizeAngle(f32 arg0);
s32 func_800157EC(f32 arg0, f32 arg1, f32 arg2);
void func_800158B4(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4);
f32 Math_SolvePlaneX(f32 arg0, f32 arg1, s64 arg2, s64 arg4, s64 arg6, s64 arg8);
f32 Math_SolvePlaneY(f32 arg0, f32 arg1, s64 arg2, s64 arg3, s64 arg4, s64 arg5);
s32 Math_ComparePlanes(s64 arg0, s64 arg2, s64 arg4, s64 arg6, s64 arg8, s64 argA, s64 argC, s64 argE);
s32 func_800162F0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
s32 func_800163AC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
s32 func_80016560(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
void func_80016A80(s64 arg0, s64 arg2, s64 arg4, s64 arg5, f32* argA, f32* argB, f32* argC, f32* argD);

f32 gArctanTable[100] = {
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

s32 Math_Random(s16 range) {
    gRandSeed = (gRandSeed * 61 * 9 - 1);

    if (range == 0) {
        return gRandSeed;
    } else {
        if (range > 0) {
            return range * (u16) gRandSeed / 0x10000;
        } else {
            return ((range * gRandSeed) / 32768);
        }
    }
}

f32 Math_Atan2f(f32 y, f32 x) {
    f32 sp4;
    f32 sp0;

    if (y == x) {
        if (y == 0.0f) {
            return 0.0f;
        } else if (y > 0.0f) {
            return 45.0f;
        } else {
            return 225.0f;
        }
    } else if (y == 0.0f) {
        if (x > 0.0f) {
            return 90.0f;
        } else {
            return 270.0f;
        }
    } else if (x == 0.0f) {
        if (y > 0.0f) {
            return 0.0f;
        } else {
            return 180.0f;
        }
    } else if (SQ(y) == SQ(x)) {
        if (y > 0.0f) {
            return 315.0f;
        } else {
            return 135.0f;
        }
    } else if (y > 0.0f) {
        if (x > 0.0f) {
            if (x < y) {
                sp4 = (x / y) * 100.0f;
                return gArctanTable[(s32) sp4];
            } else {
                sp4 = (y / x) * 100.0f;
                sp0 = 90.0f - gArctanTable[(s32) sp4];
                return sp0;
            }
        } else if (SQ(y) > SQ(x)) {
            sp4 = ((-1.0f * x) / y) * 100.0f;
            sp0 = 360.0f - gArctanTable[(s32) sp4];
            return sp0;
        } else {
            sp4 = ((-1.0f * y) / x) * 100.0f;
            sp0 = gArctanTable[(s32) sp4] + 270.0f;
            return sp0;
        }
    } else if (x > 0.0f) {
        if (SQ(y) > SQ(x)) {
            sp4 = ((-1.0f * x) / y) * 100.0f;
            sp0 = 180.0f - gArctanTable[(s32) sp4];
            return sp0;
        } else {
            sp4 = ((-1.0f * y) / x) * 100.0f;
            sp0 = gArctanTable[(s32) sp4] + 90.0f;
            return sp0;
        }
    } else if (y < x) {
        sp4 = (x / y) * 100.0f;
        sp0 = gArctanTable[(s32) sp4] + 180.0f;
        return sp0;
    } else {
        sp4 = (y / x) * 100.0f;
        sp0 = 270.0f - gArctanTable[(s32) sp4];
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

/*
 *
 *  @brief: Calculates a 2D angle using Math_Atan2f and adjusts by -90°
 *  @return: normalized result to a positive range
 */
f32 Math_CalcAngle2D(f32 y, f32 x) {
    f32 angle;

    angle = Math_Atan2f(y, x) - 90.0f;
    if (angle < 0.0f) {
        angle += 360.0f;
    }
    return angle;
}

f32 func_80015634(f32 arg0, f32 arg1) {
    f32 angle;

    angle = Math_Atan2f(arg0, -arg1) + 90.0f;
    if (angle >= 360.0f) {
        angle -= 360.0f;
    }
    return angle;
}

f32 Math_CalcAngleSimple(f32 y, f32 x) {
    f32 angle;

    angle = Math_Atan2f(y, x);
    if (angle >= 360.0f) {
        angle -= 360.0f;
    }
    return angle;
}

f32 Math_NormalizeAngle(f32 angle) {
    if ((angle > 90.0f) && (angle <= 180.0f)) {
        angle = 180.0f - angle;
    } else if ((angle > 180.0f) && (angle < 270.0f)) {
        angle = 540.0f - angle;
    }
    return angle;
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

void func_800158B4(f32 x, f32 y, f32 z, f32* arg3, f32* arg4) {
    *arg4 = func_80015634(x, z);
    *arg3 = Math_CalcAngle2D(y, sqrtf(SQ(x) + SQ(z)));
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

f32 Math_SolvePlaneX(f32 x, f32 y, s64 A, s64 B, s64 C, s64 D) {
    f32 result_x;

    if (A != 0) {
        result_x = (((-(B) *x) - (C * y)) + D) / A;
    } else {
        result_x = 0.0f;
    }
    return result_x;
}

f32 Math_SolvePlaneY(f32 x, f32 y, s64 A, s64 B, s64 C, s64 D) {
    f32 result_y;

    if ((B != 0)) {
        result_y = (((-(A) *x) - (C * y)) + D) / B;
    } else {
        result_y = 0.0f;
    }
    return result_y;
}

/*
 * Solves for z in a plane equation in the form Ax + By + Cz + D = 0
 * @return Given x and y, returns z = -(Ax + By + D) / C
 */
f32 Math_SolvePlaneZ(f32 x, f32 y, s64 A, s64 B, s64 C, s64 D) {
    f32 z;

    if (C != 0) {
        z = ((-A * x) - (B * y) + D) / C;
    } else {
        z = 0.0f;
    }

    return z;
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

/*
 * @brief Compares two planes Y axis
 *
 * @return true if both Y are equal otherwise false
 */
s32 Math_ComparePlanes(s64 A, s64 B, s64 C, s64 D, s64 A2, s64 B2, s64 B3, s64 B4) {
    f32 y1;
    f32 y2;

    y1 = Math_SolvePlaneY(0.0f, 0.0f, A, B, C, D);
    y2 = Math_SolvePlaneY(0.0f, 0.0f, A2, B2, B3, B4);
    if (y1 != y2) {
        return FALSE;
    }
    y1 = Math_SolvePlaneY(100.0f, 100.0f, A, B, C, D);
    y2 = Math_SolvePlaneY(100.0f, 100.0f, A2, B2, B3, B4);
    if (y1 != y2) {
        return FALSE;
    }
    y1 = Math_SolvePlaneY(100.0f, 0.0f, A, B, C, D);
    y2 = Math_SolvePlaneY(100.0f, 0.0f, A2, B2, B3, B4);
    if (y1 != y2) {
        return FALSE;
    }
    return TRUE;
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
        *arg8 = Math_SolvePlaneX(0.0f, 0.0f, sp48, 0, sp40, sp38);
        *arg9 = 0.0f;
    } else if (sp40 != 0) {
        *arg9 = Math_SolvePlaneZ(0.0f, 0.0f, sp48, 0, sp40, sp38);
        *arg8 = 0.0f;
    } else {
        *arg8 = 0.0f;
        *arg9 = 0.0f;
    }
    if ((sp48 != 0)) {
        *argA = Math_SolvePlaneX(0.0f, 10.0f, sp48, 0, sp40, sp38);
        *argB = 10.0f;
    } else if ((sp40 != 0)) {
        *argB = Math_SolvePlaneZ(10.0f, 0.0f, sp48, 0, sp40, sp38);
        *argA = 10.0f;
    } else {
        *argA = 0.0f;
        *argB = 0.0f;
    }
}

void func_80016A80(s64 arg0, s64 arg2, s64 arg4, UNUSED s64 arg5, f32* argA, f32* argB, f32* argC, f32* argD) {
    f32 sp34;
    f32 sp30;

    *argA = 90.0f - Math_Atan2f(arg4, arg2);
    *argC = Math_Atan2f(arg0, arg2) - 90.0f;
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
