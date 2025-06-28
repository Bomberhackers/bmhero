#include "ultra64.h"
#include "src/boot/17930.h"
#include "src/code/76640.h"

struct Vec3f D_80281590_code_extra_3[8] = {
    { 0.0f, 0.0f, -29.0f },   { 29.0f, 0.0f, 0.0f },   { 0.0f, 0.0f, 29.0f },   { -29.0f, 0.0f, 0.0f },
    { 0.0f, 119.0f, -29.0f }, { 29.0f, 119.0f, 0.0f }, { 0.0f, 119.0f, 29.0f }, { -29.0f, 119.0f, 0.0f },
};

char D_802815F0_code_extra_3[8] = { 1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80 };

struct Vec2i D_802815F8_code_extra_3[0x10] = {
    { 0, 0 }, { 0, 1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 0 }, { -1, -1 }, { -1, 0 },
    { 1, 0 }, { 1, 1 }, { 0, 0 },  { 0, 1 },  { 1, -1 }, { 1, 0 }, { 0, -1 },  { 0, 0 },
};

f32 D_80281678_code_extra_3[0x7E] = {
    0.0f,          0.49f,          0.97f,          1.44f,          1.9f,           2.35f,          2.79f,
    3.22f,         3.64f,          4.05f,          4.45f,          4.84f,          5.22f,          5.59f,
    5.95f,         6.3f,           6.64f,          6.97f,          7.29f,          7.6f,           7.9f,
    8.19f,         8.47f,          8.74f,          9.0f,           9.25f,          9.49f,          9.72f,
    9.94f,         10.0f,          9.94f,          9.72f,          9.49f,          9.25f,          9.0f,
    8.74f,         8.47f,          8.19f,          7.9f,           7.6f,           7.29f,          6.97f,
    6.64f,         6.3f,           5.95f,          5.59f,          5.22f,          4.84f,          4.45f,
    4.05f,         3.64f,          3.22f,          2.79f,          2.35f,          1.9f,           1.44f,
    0.97f,         0.49f,          0.0f,           -0.49f,         -0.97f,         -1.44f,         -1.9f,
    -2.35f,        -2.79f,         -3.22f,         -3.64f,         -4.05f,         -4.45f,         -4.84f,
    -5.22f,        -5.59f,         -5.95f,         -6.3f,          -6.64f,         -6.97f,         -7.29f,
    -7.6f,         -7.9f,          -8.19f,         -8.47f,         -8.74f,         -9.0f,          -9.25f,
    -9.49f,        -9.72f,         -9.94f,         -10.0f,         -9.94f,         -9.72f,         -9.49f,
    -9.25f,        -9.0f,          -8.74f,         -8.47f,         -8.19f,         -7.9f,          -7.6f,
    -7.29f,        -6.97f,         -6.64f,         -6.3f,          -5.95f,         -5.59f,         -5.22f,
    -4.84f,        -4.45f,         -4.05f,         -3.64f,         -3.22f,         -2.79f,         -2.35f,
    -1.9f,         -1.44f,         -0.97f,         -0.49f,         -3.679754e-39f, -3.678958e-39f, -3.679866e-39f,
    -3.67916e-39f, -3.680084e-39f, -3.679378e-39f, -3.680174e-39f, -3.679513e-39f, 0.0f,           0.0f,
};

// This is probably fake...
extern void* (*func_80280E74_code_extra_3_1[4][2])();

//.bss
extern s32 D_8016E3F0;
extern s32 D_8016E410;
extern s32 D_8016E418;
extern f32 D_8016E408;
extern f32 D_8016E400;
extern f32 D_8016E3F8;

// unsorted externs
extern u32 D_80115F34;
extern s8 D_8016E3F6;
extern f32 D_8016E400;

void func_80280000_code_extra_3(void) {
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    s32 sp34;
    s32 sp30;
    u8 sp2F;
    u8 sp2E;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    f32 sp1C;
    f32 sp18;

    sp4C = gPlayerObject->Pos.x;
    sp48 = gPlayerObject->Pos.y;
    sp44 = gPlayerObject->Pos.z;
    sp40 = gPlayerObject->Vel.x;
    sp3C = gPlayerObject->Vel.y;
    sp38 = gPlayerObject->Vel.z;
    sp48 += sp3C;
    func_800843CC(sp4C, sp48 + 119.0f, sp44);
    if (D_801776E0 & 1) {
        sp48 = D_80177760[0] - 119.0f;
    }
    func_800843CC(sp4C, sp48, sp44);
    if (D_801776E0 & 1) {
        sp48 = D_80177760[1];
    }
    if (D_80177760[D_801776E0 & 1] == sp48) {
        sp34 = 1;
    } else {
        sp34 = 0;
    }
    sp4C += sp40;
    sp44 += sp38;
    sp20 = 8;
    sp2E = 0;

    for (sp30 = 0; sp30 < 0x1E; sp30++) {

        sp2F = 0;

        for (sp28 = 0; sp28 < 8; sp28++) {

            sp24 = func_80084430(D_80281590_code_extra_3[sp28].x + sp4C, D_80281590_code_extra_3[sp28].y + sp48,
                                 D_80281590_code_extra_3[sp28].z + sp44);

            if (sp24 == 4) {

                sp2F = sp2F | D_802815F0_code_extra_3[sp28];
            }
        }
        sp2F = (sp2F & 0xF) | ((s32) sp2F >> 4);
        if ((sp2F == 0) && ((sp30 == 0) || (sp20 == 1))) {
            break;
        }
        if (sp2F == 0) {
            sp4C = sp1C;
            sp44 = sp18;
            sp20 = sp20 / 2;
            sp2F = sp2E;
        } else if ((sp2E != sp2F) && (sp30 != 0) && ((sp20 / 2) != 0)) {
            sp2F = sp2E;
            sp20 = sp20 / 2;
            sp4C = sp1C;
            sp44 = sp18;
        }
        sp1C = sp4C;
        sp18 = sp44;
        sp2E = sp2F;
        sp4C = sp4C + D_802815F8_code_extra_3[sp2F].x * sp20;
        sp44 = sp44 + D_802815F8_code_extra_3[sp2F].y * sp20;
    }
    sp24 = func_80084430(sp4C, sp48, sp44);
    if ((sp24 < 3) && (sp34 != 0)) {
        func_800843CC(sp4C, sp48, sp44);
        if (!(D_801776E0 & 1)) {
            sp48 = D_80177760[0];
        }
    }
    gPlayerObject->Pos.x = sp4C;
    gPlayerObject->Pos.y = sp48;
    gPlayerObject->Pos.z = sp44;
}

void func_802804F8_code_extra_3(void) {
    D_8016E3F0 = 0;
    func_800843CC(gPlayerObject->Pos.x, gPlayerObject->Pos.y + 120.0f, gPlayerObject->Pos.z);
    if (D_801776E0 & 1) {
        D_8016E3F0 |= 1;
    }
    func_800843CC(gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
    if (!(D_801776E0 & 1)) {
        if (*D_80177760 == gPlayerObject->Pos.y) {
            D_8016E3F0 |= 2;
        }
    } else {
        D_8016E3F0 |= 2;
    }
}

void func_80280604_code_extra_3(void) {
    f32 sp1C;

    if ((gActiveContStickX < 10.0f) && (gActiveContStickX > -10.0f)) {
        D_8016E410 = 0;
    } else {
    }
    sp1C = sqrtf(gActiveContStickY * gActiveContStickY);
    if (sp1C < 10.0f) {
        D_8016E418 = 0;
    } else if (sp1C < 30.0f) {
        D_8016E418 = 1;
    } else if (sp1C < 50.0f) {
        D_8016E418 = 2;
    } else {
        D_8016E418 = 3;
    }
}

void func_80280724_code_extra_3(void) {
    D_8016E408 = D_80281678_code_extra_3[D_8016E3F6] * D_8016E3F8;
    D_8016E3F6 += 1;
    if (D_8016E3F6 >= 0x74) {
        D_8016E3F6 = 0;
    }
    if (D_8016E408 >= 0.0f) {
        gPlayerObject->Rot.z = D_8016E408;
    } else {
        gPlayerObject->Rot.z = D_8016E408 + 360.0f;
    }
}

void func_802807EC_code_extra_3(void) {
    f32 sp4;

    if (gActiveContStickY < -40.0f) {
        sp4 = -7.0f;
    } else if (gActiveContStickY < -10.0f) {
        sp4 = -4.0f;
    } else if (gActiveContStickY <= 10.0f) {
        sp4 = 0.0f;
    } else if (gActiveContStickY <= 30.0f) {
        sp4 = 4.0f;
    } else if (gActiveContStickY <= 50.0f) {
        sp4 = 7.0f;
    } else {
        sp4 = 10.0f;
    }
    if (gPlayerObject->unk44 <= sp4) {
        gPlayerObject->unk44 = (f32) ((f64) gPlayerObject->unk44 + 0.2);
        if (gPlayerObject->unk44 > sp4) {
            gPlayerObject->unk44 = sp4;
        }
    } else {
        gPlayerObject->unk44 = (f32) ((f64) gPlayerObject->unk44 - 0.2);
        if (gPlayerObject->unk44 < sp4) {
            gPlayerObject->unk44 = sp4;
        }
    }
    if (gPlayerObject->unk44 <= -7.0f) {
        gPlayerObject->unk44 = -7.0f;
    } else if (gPlayerObject->unk44 >= 10.0f) {
        gPlayerObject->unk44 = 10.0f;
    }
}

void func_80280A7C_code_extra_3(void) {
    if ((gActiveContStickX >= -10.0f) && (gActiveContStickX <= 10.0f)) {
        gPlayerObject->Vel.x = 0.0f;
    } else if (gActiveContStickX < 0.0f) {
        gPlayerObject->Vel.x = -8.0f;
    } else {
        gPlayerObject->Vel.x = 8.0f;
    }
}

void func_80280B30_code_extra_3(void) {
    gPlayerObject->Vel.x = sinf((f32) ((f64) gPlayerObject->unk3C * 0.017453292519943295)) * gPlayerObject->unk44;
    gPlayerObject->Vel.z = cosf((f32) ((f64) gPlayerObject->unk3C * 0.017453292519943295)) * gPlayerObject->unk44;
}

void func_80280BD8_code_extra_3(void) {
    if (D_801651A4 & 1) {
        gPlayerObject->Vel.y = (f32) ((f64) gPlayerObject->Vel.y - 2.083333);
        if (gPlayerObject->Vel.y <= -48.0f) {
            gPlayerObject->Vel.y = -48.0f;
        }
    } else {
        gPlayerObject->Vel.y = 0.0f;
    }
}

void func_80280C84_code_extra_3(void) {
    s16 sp26;
    s32 sp20;

    gPlayerObject->unkA4 = 0x12D;
    if (gPlayerObject->unk44 == 0.0f) {
        sp26 = 0;
    } else if (gPlayerObject->unk44 < -4.0f) {
        sp26 = 6;
    } else if (gPlayerObject->unk44 < 0.0f) {
        sp26 = 5;
    } else if (gPlayerObject->unk44 <= 4.0f) {
        sp26 = 1;
    } else if (gPlayerObject->unk44 <= 7.0f) {
        sp26 = 2;
    } else {
        sp26 = 3;
    }
    sp20 = func_8001B880(0, 0);
    if (sp26 != sp20) {
        func_8001C0EC(0, 0, (s32) sp26, 1, &D_80115F34);
    }
}

void func_80280DF8_code_extra_3(void) {
    s16 sp26;

    sp26 = 7;
    gPlayerObject->unkA4 = 0x12E;
    func_8001C0EC(0, 0, (s32) sp26, 1, &D_80115F34);
    func_8001B754(0, 0);
    D_801651A4 &= ~1;
}

void func_80280E74_code_extra_3(void) {
    s16 sp26;

    sp26 = 8;
    gPlayerObject->unkA4 = 0x12F;
    func_8001C0EC(0, 0, (s32) sp26, 1, &D_80115F34);
    func_8001B754(0, 0);
    D_801651A4 |= 1;
    gPlayerObject->Vel.y = 0.0f;
}

void func_80280F00_code_extra_3(void) {
    s16 sp26;

    sp26 = 9;
    gPlayerObject->unkA4 = 0x130;
    func_8001C0EC(0, 0, (s32) sp26, 1, &D_80115F34);
    D_801651A4 &= ~1;
}

void func_80280F70_code_extra_3(void) {
    if (func_80085D54() != 0) {
        return;
    }
    if (!(D_8016E3F0 & 2)) {
        func_80280E74_code_extra_3();
        return;
    }
    if (gActiveContPressed & 0x8000) {
        func_80280DF8_code_extra_3();
        return;
    }
    func_80280C84_code_extra_3();
}

void func_80281000_code_extra_3(void) {
    if (func_80085D54() != 0) {
        return;
    }
    if ((D_801651A4 & 1) && ((D_8016E3F0 & 3) || (gPlayerObject->Vel.y < 0.0f))) {
        func_80280E74_code_extra_3();
        return;
    }
}

void func_8028109C_code_extra_3(void) {
    if (func_80085D54() != 0) {
        return;
    }
    if (D_8016E3F0 & 2) {
        func_80280F00_code_extra_3();
        return;
    }
}

void func_802810FC_code_extra_3(void) {
    if (func_80085D54() != 0) {
        return;
    }
    if (!(D_8016E3F0 & 2)) {
        func_80280E74_code_extra_3();
        return;
    }
    if (gActiveContPressed & 0x8000) {
        func_80280DF8_code_extra_3();
        return;
    }
    if (func_8001B44C(0, 0) != 0) {
        func_80280C84_code_extra_3();
        return;
    }
}

void func_802811A8_code_extra_3(void) {
    func_80280724_code_extra_3();
    func_802807EC_code_extra_3();
    gPlayerObject->unk3C = 180.0f;
    func_80280B30_code_extra_3();
}

void func_802811F8_code_extra_3(void) {
    f32 sp1C;

    sp1C = func_8001B62C(0, 0);
    if (sp1C == 2.0f) {
        gPlayerObject->Vel.y = 33.333332f;
        D_801651A4 |= 1;
    }
    func_80280724_code_extra_3();
    func_802807EC_code_extra_3();
    func_80280B30_code_extra_3();
    func_80280A7C_code_extra_3();
}

void func_80281294_code_extra_3(void) {
    func_80280724_code_extra_3();
    func_802807EC_code_extra_3();
    func_80280B30_code_extra_3();
    func_80280A7C_code_extra_3();
}

void func_802812D4_code_extra_3(void) {
    func_80280724_code_extra_3();
    func_802807EC_code_extra_3();
    func_80280B30_code_extra_3();
    func_80280A7C_code_extra_3();
}

void func_80281314_code_extra_3(void) {
    func_80280604_code_extra_3();
    func_80085B34(0.0f, 0.0f);
    func_802804F8_code_extra_3();
    func_80280E74_code_extra_3_1[gPlayerObject->unkA4 + 14][0]();
    func_80280E74_code_extra_3_1[gPlayerObject->unkA4 + 13][1]();
    func_80280BD8_code_extra_3();
    func_80280000_code_extra_3();
    gPlayerObject->Rot.y = 180.0f;
    func_8001CD20(0);
    func_8001AD6C(0);
}

void func_802813E4_code_extra_3(void) {
    if (gPlayerObject->unk132 == 0) {
        gPlayerObject->unk132 += 1;
        Reset_LightSettings();
        gPlayerObject->unk108 = 1;
        gPlayerObject->Pos.x = 0.0f;
        gPlayerObject->Pos.y = 0.0f;
        gPlayerObject->Pos.z = 0.0f;
        func_8001C0EC(0, 0, 0, 1, &D_80115F34);
        func_8001BBDC(0, 0);
    }
    func_8001CD20(0);
    func_8001AD6C(0);
}

void func_802814CC_code_extra_3(void) {
    func_8001BD44(0, 0, 0x13, (s32) gFileArray[1].ptr);
    func_8001C0EC(0, 0, 0, 1, &D_80115F34);
    gPlayerObject->unkE4 = 3;
    gPlayerObject->unkA4 = 0x12D;
    gPlayerObject->Rot.y = 180.0f;
    D_8016E408 = 0.0f;
    D_8016E3F6 = 0;
    D_8016E3F8 = 1.0f;
    D_8016E400 = 0.0f;
}
