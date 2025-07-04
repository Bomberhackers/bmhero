#include "common.h"

void func_80063200(s32, s32, s32, s32, s32); /* extern */
void func_80063BE8(s32, s32, s32);           /* extern */
void func_80063C58(s32, s32, s32, void*);    /* extern */
void func_80060278(void);                    /* extern */
void func_80332EA4_unk_bin_2(int);           /* extern */
void func_80335960_unk_bin_2();              /* extern */
void func_80335B44_unk_bin_2();              /* extern */

struct UnkStruct_801039D5 {
    s32 unk0;
    char pad[0xD4];
};

struct UnkStruct_801039D5_1 {
    char unk0[0x4];
};

extern struct UnkStruct_801039D5_1 D_801039D5[];
extern struct UnkStruct_801039D5 D_80324184[];
extern s32 D_80336134_unk_bin_2[];
extern s32 D_80336140_unk_bin_2[];
extern s32 D_80336158_unk_bin_2[];
extern f32 D_803362DC_unk_bin_2;
extern f32 D_803362E0_unk_bin_2;
extern f32 D_803362E4_unk_bin_2;
extern f32 D_803362E8_unk_bin_2;
extern f32 D_803362EC_unk_bin_2;
extern f32 D_803362F0_unk_bin_2;
extern f32 D_803362F4_unk_bin_2;
extern f32 D_803362F8_unk_bin_2;
extern f32 D_803362FC_unk_bin_2;
extern f32 D_80336300_unk_bin_2;
extern f32 D_80336304_unk_bin_2;
extern s32 D_803363C0;
extern s8 D_803363C4;
extern UNK_TYPE D_803361BC_unk_bin_2;
extern s8 D_803363C4;
extern f32 D_803361F0_unk_bin_2;
extern f64 D_803361F8_unk_bin_2;
extern f64 D_80336200_unk_bin_2;
extern f64 D_80336208_unk_bin_2;
extern f64 D_80336210_unk_bin_2;
extern f64 D_80336218_unk_bin_2;
extern f64 D_80336220_unk_bin_2;
extern f32 D_80336364;
extern f32 D_80336368;
extern f32 D_8033636C;
extern f32 D_80336370;
extern s16 D_80324992;
extern f64 D_80336228_unk_bin_2;
extern f64 D_80336230_unk_bin_2;
extern f64 D_80336238_unk_bin_2;
extern f64 D_80336240_unk_bin_2;
extern f64 D_80336248_unk_bin_2;
extern f64 D_80336250_unk_bin_2;
extern f64 D_80336258_unk_bin_2;
extern f64 D_80336280_unk_bin_2;
extern f32 D_80336288_unk_bin_2;
extern f32 D_8033628C_unk_bin_2;
extern f64 D_80336290_unk_bin_2;
extern f32 D_80336298_unk_bin_2;
extern f32 D_8033629C_unk_bin_2;
extern f32 D_803362A0_unk_bin_2;
extern f32 D_803362A4_unk_bin_2;
extern f32 D_803362A8_unk_bin_2;
extern f32 D_80336364;
extern f32 D_80336368;
extern f32 D_8033636C;
extern f32 D_80336370;
extern s32 D_80323738;
extern UNK_TYPE D_80323DDC;
extern f32 D_80336350_unk_bin_2;
extern s32 D_803363BC;
extern s8 D_803363C4;

void func_80330000_unk_bin_2(void) {
    D_803363C0 = 1;
}

s32 func_8033001C_unk_bin_2(s32 arg0) {
    if (*gContButtonPressed & CONT_A) {
        if (D_803363C0 == 0) {
            func_800178D4(-1, 0, 0x40, -1, 0);
            D_803363C4 = 0;
            return 1;
        } else {
            func_800178D4(-1, 0, 0x41, -1, 0);
            D_803363C4 = 0;
            return 2;
        }
    } else if (*gContButtonPressed & CONT_B) {
        func_800178D4(-1, 0, 0x41, -1, 0);
        D_803363C4 = 0;
        return 2;
    } else if ((arg0 == 1) || (arg0 == -1)) {
        D_803363C0 ^= 1;
        func_800178D4(-1, 0, 0x3F, -1, 0);
    }
    D_803363C4 = D_803363C0 + 1;
    return 0;
}

void func_80330180_unk_bin_2(void) {
    switch (D_803363C4) { /* irregular */
        case 1:
            func_80063200(0x44, 0x5C, 0xFC, 0x84, 0xC8);
            func_8006357C();
            func_80063C58(0, 0x78, 0x60, &D_803361BC_unk_bin_2);
            func_80063C58(1, 0x5C, 0x70, &D_803361BC_unk_bin_2);
            func_80063BE8(0x48, 0x6C, 0x70);
            break;
        case 2:
            func_80063200(0x44, 0x5C, 0xFC, 0x84, 0xC8);
            func_8006357C();
            func_80063C58(0, 0x78, 0x60, &D_803361BC_unk_bin_2);
            func_80063C58(1, 0x5C, 0x70, &D_803361BC_unk_bin_2);
            func_80063BE8(0x48, 0xAC, 0x70);
            break;
    }
}

void func_803302A4_unk_bin_2(s32 arg0) {
    D_803363C4 = arg0;
}

void func_803302BC_unk_bin_2(void) {
    D_803363C4 = 0;
}

void func_800604A8(s32); /* extern */
extern s32 D_80336080_unk_bin_2[];
extern s8 D_80336360;

void func_803302D4_unk_bin_2(void) {
    s16 sp1E;

    for (sp1E = 0; sp1E < D_80336360; sp1E++) {
        if (sp1E == D_80134801) {
        } else {
            func_800604A8(D_80336080_unk_bin_2[sp1E]);
        }
    }
    if (D_80134801 != 1) {
        func_800604A8(0xC);
    }
    if (D_80134801 != 3) {
        func_800604A8(0xF);
    }
    if (D_80134801 != 4) {
        func_800604A8(0x11);
    }
}

void func_80060E40(s32, s32); /* extern */

void func_803303BC_unk_bin_2(void) {
    s16 sp4E;
    f32 sp48;
    f64 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 sp28;

    sp28 = 0x17;
    func_8001A928(sp28);
    func_80060E40(D_80134801 + 0x18, sp28);
    gObjects[sp28].Pos.x = 32.0f;
    gObjects[sp28].Pos.y = 16.0f;
    gObjects[sp28].Pos.z = D_803361F0_unk_bin_2;
    sp3C = -((cosf((f32) ((f64) D_8033636C * D_803361F8_unk_bin_2)) * -D_80336364) + D_80336364);
    sp38 = sinf((f32) ((f64) D_8033636C * D_80336200_unk_bin_2)) * -D_80336364;
    sp40 = -20.0;
    sp48 = D_8033636C;

    for (sp4E = D_80134801; sp4E < D_80336360; sp4E++) {
        sp34 = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.x =
            -((cosf((sp48 * D_80336208_unk_bin_2)) * -D_80336364) + D_80336364) - sp3C;
        sp2C = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.z = (sinf((sp48 * D_80336210_unk_bin_2)) * -D_80336364) - sp38;
        sp30 = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.y = sp40;

        sp40 += (f64) D_80336370;
        sp48 += D_80336368;
    }
    sp40 = (f64) -D_80336370 + -20.0;
    sp48 = D_8033636C - D_80336368;

    for (sp4E = D_80134801 - 1; sp4E >= 0; sp4E--) {
        sp34 = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.x =
            -((cosf((f32) ((f64) sp48 * D_80336218_unk_bin_2)) * -D_80336364) + D_80336364) - sp3C;
        sp2C = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.z =
            (sinf((f32) ((f64) sp48 * D_80336220_unk_bin_2)) * -D_80336364) - sp38;
        sp30 = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.y = sp40;
        sp40 -= (f64) D_80336370;
        sp48 -= D_80336368;
    }
}

void func_803308C4_unk_bin_2(s32 arg0) {
    s16 sp4E;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    sp28 = 16.0f;
    sp2C = (f32) (D_80336228_unk_bin_2 / (f64) sp28);
    sp48 = -((cosf((f32) ((f64) D_8033636C * D_80336230_unk_bin_2)) * -D_80336364) + D_80336364);
    sp44 = sinf((f32) ((f64) D_8033636C * D_80336238_unk_bin_2)) * -D_80336364;
    arg0 = -arg0;
    sp30 = (D_80336370 / sp28) * arg0;
    sp40 = ((D_80336368 / sp28) * (sp28 - D_80324992) * arg0) + D_8033636C;

    for (sp4E = (s16) D_80134801; sp4E < D_80336360; sp4E++) {
        sp3C = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.x =
            -((cosf((f32) ((f64) sp40 * D_80336240_unk_bin_2)) * -D_80336364) + D_80336364) - sp48;
        sp34 = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.z =
            (sinf((f32) ((f64) sp40 * D_80336248_unk_bin_2)) * -D_80336364) - sp44;
        gObjects[D_80336080_unk_bin_2[sp4E]].Pos.y += sp30, sp38 = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.y;
        sp40 += D_80336368;
    }

    sp40 = (((D_80336368 / sp28) * (sp28 - (f32) D_80324992) * (f32) arg0) - D_80336368) + D_8033636C;

    for (sp4E = D_80134801 - 1; sp4E >= 0; sp4E--) {
        sp3C = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.x =
            -((cosf((f32) ((f64) sp40 * D_80336250_unk_bin_2)) * -D_80336364) + D_80336364) - sp48;
        sp34 = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.z =
            (sinf((f32) ((f64) sp40 * D_80336258_unk_bin_2)) * -D_80336364) - sp44;
        gObjects[D_80336080_unk_bin_2[sp4E]].Pos.y += sp30, sp38 = gObjects[D_80336080_unk_bin_2[sp4E]].Pos.y;
        sp40 -= D_80336368;
    }
}

extern f32 D_80336260_unk_bin_2;
extern f32 D_80336264_unk_bin_2;
extern f32 D_80336268_unk_bin_2;
extern f32 D_8033626C_unk_bin_2;

void func_80330E04_unk_bin_2(void) {
    gObjects[0xA].Rot.y = Math_WrapAngle(gObjects[0xA].Rot.y, D_80336260_unk_bin_2);
    gObjects[0xB].Rot.y = Math_WrapAngle(gObjects[0xB].Rot.y, D_80336264_unk_bin_2);
    gObjects[0xD].Rot.y = Math_WrapAngle(gObjects[0xD].Rot.y, D_80336268_unk_bin_2);
    gObjects[0xE].Rot.y = Math_WrapAngle(gObjects[0xE].Rot.y, D_8033626C_unk_bin_2);
    gObjects[0xC].Pos.x = gObjects[0xB].Pos.x;
    gObjects[0xC].Pos.y = gObjects[0xB].Pos.y;
    gObjects[0xC].Pos.z = gObjects[0xB].Pos.z;
    gObjects[0xC].Rot.z = 45.0f;
    gObjects[0xC].Rot.x = 10.0f;
    gObjects[0xF].Pos.x = gObjects[0xE].Pos.x;
    gObjects[0xF].Pos.y = gObjects[0xE].Pos.y;
    gObjects[0xF].Pos.z = gObjects[0xE].Pos.z;
    gObjects[0x11].Pos.x = gObjects[0x10].Pos.x;
    gObjects[0x11].Pos.y = gObjects[0x10].Pos.y;
    gObjects[0x11].Pos.z = gObjects[0x10].Pos.z;
}

//? func_800252AC(s8, s8 *, ? *, ? *, ? *);           /* extern */

void func_80330FA0_unk_bin_2(void) {
    s8 sp27;
    u8 sp26;
    u8 sp25;
    u8 sp24;

    gObjects[0x15].Pos.x = gObjects[0x14].Pos.x;
    gObjects[0x15].Pos.y = gObjects[0x14].Pos.y;
    gObjects[0x15].Pos.z = gObjects[0x14].Pos.z;
    gObjects[0x15].Rot.x = gObjects[0x14].Rot.x;
    gObjects[0x15].Rot.y = gObjects[0x14].Rot.y;
    gObjects[0x15].Rot.z = gObjects[0x14].Rot.z;
    gObjects[0x15].Scale.x = gObjects[0x14].Scale.x;
    gObjects[0x15].Scale.y = gObjects[0x14].Scale.y;
    gObjects[0x15].Scale.z = gObjects[0x14].Scale.z;
    gObjects[0x16].Pos.x = gObjects[0x14].Pos.x;
    gObjects[0x16].Pos.y = gObjects[0x14].Pos.y;
    gObjects[0x16].Pos.z = gObjects[0x14].Pos.z;
    gObjects[0x16].Rot.x = gObjects[0x14].Rot.x;
    gObjects[0x16].Rot.y = gObjects[0x14].Rot.y;
    gObjects[0x16].Rot.z = gObjects[0x14].Rot.z;
    gObjects[0x16].Scale.x = gObjects[0x14].Scale.x;
    gObjects[0x16].Scale.y = gObjects[0x14].Scale.y;
    gObjects[0x16].Scale.z = gObjects[0x14].Scale.z;
    func_8001BB34(0x16, 1);
    if (D_80177630 == 0) {
        if ((D_80134808[D_80134801 * 0x15] == 0) || (D_80134808[D_80134801 * 0x15] == 6)) {
            if ((D_80134801 > 0) && (D_80134801 < 4)) {
                func_8001BB34(0x16, 0);
            }
        } else {
            func_800252AC(D_8013488C, &sp27, &sp26, &sp25, &sp24);
            if (((D_80134808[sp27 * 0x15] == 0) || (D_80134808[sp27 * 0x15] == 6)) && (sp27 > 0) && (sp27 < 4)) {
                func_8001BB34(0x16, 0);
            }
        }
    }
}

void func_80331238_unk_bin_2(f32 arg0, f32 arg1) {
    if (arg0 != 0.0f) {
        gObjects[D_80336080_unk_bin_2[D_80134801]].Scale.x += arg1 * arg0;
        gObjects[D_80336080_unk_bin_2[D_80134801]].Scale.y += arg1 * arg0;
        gObjects[D_80336080_unk_bin_2[D_80134801]].Scale.z += arg1 * arg0;
        if (D_80134801 == 1) {
            gObjects[0xC].Scale.x += arg1 * arg0;
            gObjects[0xC].Scale.y += arg1 * arg0;
            gObjects[0xC].Scale.z += arg1 * arg0;
        } else if (D_80134801 == 3) {
            gObjects[0xF].Scale.x += arg1 * arg0;
            gObjects[0xF].Scale.y += arg1 * arg0;
            gObjects[0xF].Scale.z += arg1 * arg0;
        } else if (D_80134801 == 4) {
            gObjects[0x11].Scale.x += arg1 * arg0;
            gObjects[0x11].Scale.y += arg1 * arg0;
            gObjects[0x11].Scale.z += arg1 * arg0;
        }
    } else {

        gObjects[D_80336080_unk_bin_2[D_80134801]].Scale.x = gObjects[D_80336080_unk_bin_2[D_80134801]].Scale.y =
            gObjects[D_80336080_unk_bin_2[D_80134801]].Scale.z = arg1;

        if (D_80134801 == 1) {
            gObjects[0xC].Scale.x = gObjects[0xC].Scale.y = gObjects[0xC].Scale.z = arg1;
        } else if (D_80134801 == 3) {
            gObjects[0xF].Scale.x = gObjects[0xF].Scale.y = gObjects[0xF].Scale.z = arg1;
        } else if (D_80134801 == 4) {
            gObjects[0x11].Scale.x = gObjects[0x11].Scale.y = gObjects[0x11].Scale.z = arg1;
        }
    }
}

void func_800608B8(void*); /* extern */
extern UNK_TYPE D_803240F4;
extern UNK_TYPE D_8032491C;

void func_8033161C_unk_bin_2(void) {
    func_800608B8(&D_803240F4);
    func_8001ABF4(0x15, 0, 0, &D_8032491C + 14);
    func_8001ABF4(0x15, 1, 0, &D_8032491C + 21);
    gObjects[0x14].Pos.x = 200.0f;
    gObjects[0x14].Pos.y = -200.0f;
    gObjects[0x14].Pos.z = 800.0f;
    gObjects[0x14].Rot.y = 180.0f;
    gObjects[0x14].Rot.z = 310.0f;
    gObjects[0x14].Scale.x = gObjects[0x14].Scale.y = gObjects[0x14].Scale.z = 2.5f;
    func_80330FA0_unk_bin_2();
}

extern f64 D_80336270_unk_bin_2;
extern f64 D_80336278_unk_bin_2;
extern s8 D_80336361;

void func_80331728_unk_bin_2(void) {
    f32 sp24;
    func_800608B8(&D_803240F4);
    func_8001ABF4(0x15, 0, 0, &D_8032491C + 14);
    func_8001ABF4(0x15, 1, 0, &D_8032491C + 21);
    gObjects[0x14].Pos.x = gObjects[D_80336080_unk_bin_2[D_80336361]].Pos.x;
    gObjects[0x14].Pos.y = gObjects[D_80336080_unk_bin_2[D_80336361]].Pos.y;
    gObjects[0x14].Pos.z = gObjects[D_80336080_unk_bin_2[D_80336361]].Pos.z;
    gObjects[0x14].Rot.y = 0.0f;
    gObjects[0x14].Rot.z = 0.0f;
    sp24 =
        (f32) (((f64) gObjects[D_80336080_unk_bin_2[D_80336361]].Pos.z * D_80336270_unk_bin_2) + D_80336278_unk_bin_2);
    gObjects[0x14].Scale.x = gObjects[0x14].Scale.y = gObjects[0x14].Scale.z = sp24;
    func_80330FA0_unk_bin_2();
}

void func_80331920_unk_bin_2(void) {
    f32 sp2C;

    if ((f64) D_80324992 == D_80336280_unk_bin_2) {
        func_8033161C_unk_bin_2();
        func_800178D4(-1, 0, 0x2C, -1, 0);
    }
    if ((f64) D_80324992 <= 10.0) {
        if ((f64) D_80324992 == 10.0) {
            func_803302D4_unk_bin_2();
        }
        func_80331238_unk_bin_2(1.0f, D_80336288_unk_bin_2);
    } else {
        sp2C = D_8033628C_unk_bin_2;
        gObjects[0x14].Scale.x -= sp2C;
        gObjects[0x14].Scale.y -= sp2C;
        gObjects[0x14].Scale.z -= sp2C;
        if ((f64) gObjects[0x14].Scale.x < D_80336290_unk_bin_2) {
            gObjects[0x14].Scale.x = gObjects[0x14].Scale.y = gObjects[0x14].Scale.z = D_80336298_unk_bin_2;
        }
        sp2C = D_8033629C_unk_bin_2;
        gObjects[0x14].Pos.x -= sp2C;
        sp2C = D_803362A0_unk_bin_2;
        gObjects[0x14].Pos.y -= sp2C;
        sp2C = D_803362A4_unk_bin_2;
        gObjects[0x14].Pos.z -= sp2C;
        sp2C = D_803362A8_unk_bin_2;
        gObjects[0x14].Rot.z += sp2C;
        func_80330FA0_unk_bin_2();
    }
}

extern f64 D_803362B0_unk_bin_2;
extern f64 D_803362B8_unk_bin_2;
extern f64 D_803362C0_unk_bin_2;
extern f64 D_803362C8_unk_bin_2;
extern f64 D_803362D0_unk_bin_2;
extern f32 D_803362D8_unk_bin_2;

void func_80331B9C_unk_bin_2(void) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    if ((f64) D_80324992 == 40.0) {
        func_80331728_unk_bin_2();
    }
    sp20 =
        (f32) (((f64) gObjects[D_80336080_unk_bin_2[D_80336361]].Pos.z * D_803362B0_unk_bin_2) + D_803362B8_unk_bin_2);
    sp1C =
        (f32) (((f64) gObjects[D_80336080_unk_bin_2[D_80336361]].Pos.z * D_803362C0_unk_bin_2) + D_803362C8_unk_bin_2);
    sp24 = (f32) ((f64) (sp1C - sp20) / D_803362D0_unk_bin_2);
    gObjects[0x14].Scale.x += sp24;
    gObjects[0x14].Scale.y += sp24;
    gObjects[0x14].Scale.z += sp24;
    sp24 = D_803362D8_unk_bin_2;
    gObjects[0x14].Pos.y += sp24;
    func_80330FA0_unk_bin_2();
}

s32 func_800253EC(s8);       /* extern */
s32 func_800600B8(s32, s32); /* extern */
extern u32 D_80116F3C;
extern u32 D_80116F40;
extern u32 D_80116F44;
extern u32 D_80116F48;
extern UNK_TYPE D_80116F7C;
extern UNK_TYPE D_80116FE0;
extern UNK_TYPE D_80323F44;
extern s16 D_80324990;

void func_80331D78_unk_bin_2(s32 arg0) {
    UNUSED char pad[0x4];

    D_80324990 = 0;
    D_80324992 = 0;

    func_800608B8(&D_80323F44);
    if ((func_800253EC(D_8013488C) & 2) && (func_800600B8(0, 4) != 0)) {
        D_80336360 = 6;
    } else {
        func_800604A8(0x12);
        D_80336360 = 5;
    }
    func_80331238_unk_bin_2(0.0f, 1.0f);
    if (D_80336361 != 1) {
        func_8001C0EC(0xB, 0, 0, 4, &D_80116F3C);
    }
    if (D_80336361 != 3) {
        func_8001C0EC(0xE, 0, 0, 7, &D_80116F40);
    }
    if (D_80336361 != 2) {
        func_8001C0EC(0xD, 0, 0, 6, &D_80116F44);
        func_8001ABF4(0xD, 0, 0, &D_80116F7C);
    }
    if (D_80336361 != 4) {
        if (func_800600B8(0, 4) != 0) {
            func_8001C0EC(0x10, 0, 2, 9, &D_80116F48);
            func_8001B754(0x10, 0);
        } else {
            func_8001C0EC(0x10, 0, 0, 9, &D_80116F48);
        }
    }
    if (D_80336361 != 3) {
        func_8001ABF4(0xF, 0, 3, &D_80116FE0);
    }
    func_803303BC_unk_bin_2();
    func_80330E04_unk_bin_2();
}

extern s32 D_80336128_unk_bin_2[];
extern s32 D_8033614C_unk_bin_2[];

void func_80331F8C_unk_bin_2(s16 arg0) {
    gObjects[D_8033614C_unk_bin_2[arg0]].Pos.z = gObjects[D_80336128_unk_bin_2[arg0]].Pos.z + 1.0f;
}

void func_80332010_unk_bin_2(s16 arg0) {
    gObjects[D_8033614C_unk_bin_2[arg0]].Pos.z = gObjects[D_80336128_unk_bin_2[arg0]].Pos.z - 1.0f;
}

void func_80332094_unk_bin_2(s32 arg0) {
    s16 sp1E;

    func_800604A8(0x14);
    func_800604A8(0x15);
    D_80336361 = D_80134801;
    func_803302D4_unk_bin_2();
    func_80331238_unk_bin_2(0.0f, D_803362DC_unk_bin_2);
    D_80324990 = 0;
    D_80324992 = 0;
    for (sp1E = 0; sp1E < D_801039D4[D_80134801].Unk01; sp1E++) {
        D_80324184[sp1E].unk0 = D_801039D5[D_80134801].unk0[sp1E];
        func_800608B8(&D_80324184[sp1E]);

        gObjects[D_80336140_unk_bin_2[sp1E]].Pos.x =
            (f32) ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Pos.x -
                   ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Scale.x * 16.0));
        gObjects[D_80336140_unk_bin_2[sp1E]].Pos.y =
            (f32) ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Pos.y -
                   ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Scale.y * 42.0));

        gObjects[D_80336140_unk_bin_2[sp1E]].Scale.x = D_803362E0_unk_bin_2;
        gObjects[D_80336140_unk_bin_2[sp1E]].Scale.y = D_803362E4_unk_bin_2;

        gObjects[D_80336158_unk_bin_2[sp1E]].Pos.x =
            (f32) ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Pos.x -
                   ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Scale.x * 46.0));
        gObjects[D_80336158_unk_bin_2[sp1E]].Pos.y =
            (f32) ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Pos.y -
                   ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Scale.y * 42.0));

        gObjects[D_80336158_unk_bin_2[sp1E]].Scale.x = D_803362E8_unk_bin_2;
        gObjects[D_80336158_unk_bin_2[sp1E]].Scale.y = D_803362EC_unk_bin_2;

        gObjects[D_8033614C_unk_bin_2[sp1E]].Pos.x =
            (f32) ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Pos.x -
                   ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Scale.x * -58.0));
        gObjects[D_8033614C_unk_bin_2[sp1E]].Pos.y =
            (f32) ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Pos.y -
                   ((f64) gObjects[D_80336128_unk_bin_2[sp1E]].Scale.y * -36.0));

        gObjects[D_8033614C_unk_bin_2[sp1E]].Scale.x = D_803362F0_unk_bin_2;
        gObjects[D_8033614C_unk_bin_2[sp1E]].Scale.y = D_803362F4_unk_bin_2;
        gObjects[D_80336128_unk_bin_2[sp1E]].Scale.x = D_803362F8_unk_bin_2;
        gObjects[D_80336128_unk_bin_2[sp1E]].Scale.y = D_803362FC_unk_bin_2;

        gObjects[D_80336128_unk_bin_2[sp1E]].unkA6 = gObjects[D_80336128_unk_bin_2[sp1E]].Pos.x;
        gObjects[D_80336128_unk_bin_2[sp1E]].unkA8 = gObjects[D_80336128_unk_bin_2[sp1E]].Pos.y;

        gObjects[D_80336134_unk_bin_2[sp1E]].Scale.x = D_80336300_unk_bin_2;
        gObjects[D_80336134_unk_bin_2[sp1E]].Scale.y = D_80336304_unk_bin_2;
        if (sp1E == D_80134802) {
            func_8001BC84(D_80336128_unk_bin_2[sp1E], 0, 0);
        } else {
            func_8001BC84(D_80336128_unk_bin_2[sp1E], 0, 1);
        }
        if (func_800600B8(1, (s32) sp1E) != 0) {
            func_80331F8C_unk_bin_2(sp1E);
        } else {
            func_80332010_unk_bin_2(sp1E);
        }
    }
}

extern f64 D_80336308_unk_bin_2;
extern f64 D_80336310_unk_bin_2;
extern f32 D_80336374;
extern f32 D_80336378;

extern f32 D_80336098_unk_bin_2[0x12][3][2];
extern u8 D_80103B3C[][3][8];

void func_80332918_unk_bin_2(void) {
    f32 sp4;
    sp4 = D_80336098_unk_bin_2[D_80134801][D_80134802][0] + D_80336308_unk_bin_2;
    sp4 -= (f32) (((s32) sp4 / 360) * 0x168);
    sp4 -= gObjects[D_80336080_unk_bin_2[D_80134801]].Rot.x;
    D_80336374 = sp4 - (f32) (((s32) sp4 / 180) * 0x168);
    sp4 = D_80336098_unk_bin_2[D_80134801][D_80134802][1] + D_80336310_unk_bin_2;
    sp4 -= (f32) (((s32) sp4 / 360) * 0x168);
    sp4 -= gObjects[D_80336080_unk_bin_2[D_80134801]].Rot.y;
    D_80336378 = sp4 - (f32) (((s32) sp4 / 180) * 0x168);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/14C540/14C540/func_80332BCC_unk_bin_2.s")

f32 func_80332E10_unk_bin_2(s32 arg0) {
    s32 sp4;
    f32 sp0;

    sp4 = D_80103B3C[D_80134801][D_80134802][0];
    sp0 = (f32) ((120.0 / (f64) (f32) (sp4 - 1)) * (f64) arg0);
    return sp0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/14C540/14C540/func_80332EA4_unk_bin_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/14C540/14C540/func_80333E18_unk_bin_2.s")

s32 func_80062EAC(); /* extern */
extern s8 D_80134800;

void func_80334BE0_unk_bin_2(void) {
    UNUSED char pad[0x4];

    s32 sp30;
    sp30 = func_80062EAC();
    if ((D_80324990 == 0) && (D_80324992 == 0)) {
        if ((sp30 == -2) || (sp30 == -1)) {
            D_80324990 = -1;
        } else if ((sp30 == 2) || (sp30 == 1)) {
            D_80324990 = 1;
        } else if (*gContButtonPressed & 0x8000) {
            if (D_80336361 == D_80134801) {
                D_80324990 = 2;
                D_80324992 = 0xA;
            } else if (D_80336361 > D_80134801) {
                D_80324990 = 3;
                D_80324992 = 0x28;
            } else {
                D_80324990 = 2;
                D_80324992 = 0x46;
            }
        } else if (*gContButtonPressed & 0x4000) {
            func_80330000_unk_bin_2();
            D_80134800 = 3;
            func_800178D4(-1, 0, 0x41, -1, 0);
        }
        if (((D_80324990 == 1) || (D_80324990 == -1)) && (D_80324992 == 0)) {
            if (((D_80134801 + D_80324990) < 0) || ((D_80134801 + D_80324990) >= D_80336360) ||
                ((func_800600B8(0, (s32) D_80134801) == 0) && (D_80324990 == 1))) {
                D_80324990 = 0;
            } else {
                D_80324992 = 0xF;
                func_800178D4(-1, 0, 0x6F, -1, 0);
            }
        }
    }
    if (D_80324992 != 0) {
        switch (D_80324990) { /* irregular */
            case -1:
            case 1:
                func_803308C4_unk_bin_2((s32) D_80324990);
                D_80324992 -= 1;
                if (D_80324992 == 0) {
                    D_80134801 += D_80324990;
                    D_80324990 = 0;
                    func_803303BC_unk_bin_2();
                }
                break;
            case 2:
                func_80331920_unk_bin_2();
                D_80324992 -= 1;
                if (D_80324992 == 0) {
                    D_80324990 = 0;
                    D_80134800 += 1;
                    D_80134802 = 0;
                    func_80332094_unk_bin_2(-1);
                    return;
                }
                break;
            case 3:
                func_80331B9C_unk_bin_2();
                D_80324992 -= 1;
                if (D_80324992 == 0) {
                    D_80324990 = 2;
                    D_80324992 = 0x46;
                }
                break;
        }
    }
    func_80330E04_unk_bin_2();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/14C540/14C540/func_80334FD0_unk_bin_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/14C540/14C540/func_80335548_unk_bin_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/14C540/14C540/func_803358C8_unk_bin_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/14C540/14C540/func_80335960_unk_bin_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/14C540/14C540/func_80335B44_unk_bin_2.s")

s32 func_80335DE4_unk_bin_2(void) {
    s16 sp2E;

    func_8001ECB8();
    gDebugRoutine1 = func_80335B44_unk_bin_2;
    gDebugRoutine2 = func_80335960_unk_bin_2;
    D_8016E134 = 0;
    gView.at.x = 0.0f;
    gView.at.y = 0.0f;
    gView.at.z = 0.0f;
    gView.rot.x = 0.0f;
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 700.0f;
    func_80019C84();
    func_80019D2C();
    func_8001A258();
    func_803302BC_unk_bin_2();
    D_80324994 = &D_80323738;
    func_80060278();
    func_800608B8(&D_80323DDC);
    D_803363BC = 0;
    D_80336361 = -1;
    D_80336364 = D_80336350_unk_bin_2;
    D_80336368 = 5.0f;
    D_8033636C = 0.0f;
    D_80336370 = 500.0f;

    for (sp2E = 0; sp2E <= D_80134800; sp2E++) {
        switch (sp2E) { /* irregular */
            case 0:
                func_80331D78_unk_bin_2(D_80134800 == 2 ? 0 : -1);
                break;
            case 1:
                func_80332094_unk_bin_2(D_80134800 == 2 ? 0 : -1);
                break;
            case 2:
                func_80332EA4_unk_bin_2(D_80134800 == 2 ? 0 : -1);
                break;
        }
    }
    Set_BgColor(-1, -1, -1, 0x10);
    func_8001D284();
    func_80000964();
    return D_803363BC;
}
