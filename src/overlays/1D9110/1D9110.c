#include "common.h"

f32 cosf(f32); /* extern */
f32 sinf(f32); /* extern */
extern struct ObjSpawnInfo D_80113A78;
extern struct ObjSpawnInfo D_80113A84;
extern struct ObjSpawnInfo D_80113DCC;
extern struct ObjSpawnInfo D_80113DD8;
extern struct ObjSpawnInfo D_80113F04;
extern struct ObjSpawnInfo D_80113F40;
extern struct ObjSpawnInfo D_80113FA0;
extern struct ObjSpawnInfo D_80113FB8;
extern struct ObjSpawnInfo D_8011403C;
extern struct ObjSpawnInfo D_80114174;
extern struct ObjSpawnInfo D_80114180;
extern struct ObjSpawnInfo D_801141D4;
extern struct ObjSpawnInfo D_80114264;
extern struct ObjSpawnInfo D_80114624;
extern struct ObjSpawnInfo D_80114630;
extern struct ObjSpawnInfo D_8011463C;
extern struct ObjSpawnInfo D_80114660;
extern struct ObjSpawnInfo D_8011466C;
extern u32 D_8011731C;
extern struct UnkStruct8016C298_1 D_80117368;
extern struct UnkStruct8016C298_1 D_80117384;
extern struct UnkStruct8016C298_1 D_801173A0;
extern struct UnkStruct8016C298_1 D_801173BC;
extern u32 D_801173D8;
extern u32 D_801173E0;
extern u32 D_80117874;
extern u32 D_80118108;
extern struct UnkStruct8016C298_1 D_80118138;
extern u32 D_801182C4;
extern u32 D_80118A64;
extern u32 D_80118A6C;
extern u32 D_80118A74;
extern u32 D_80118DA0;
extern s8 D_8016E3B0;
extern s8 D_8016E3B8;

void func_80330000_unk_bin_38(void) {
    s32 sp24;
    s32 sp20;

    sp24 = func_80027464(2, &D_80113FA0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        sp20 = gObjects[sp24].unkE8[0];
        gObjects[sp24].Scale.x = 1.5f;
        gObjects[sp24].Scale.y = 1.5f;
        gObjects[sp24].Scale.z = 1.5f;
        gObjects[sp20].Scale.x = 1.5f;
        gObjects[sp20].Scale.y = 1.5f;
        gObjects[sp20].Scale.z = 1.5f;
        func_80019448(sp24, 2, 0, 1);
        func_80019448(sp20, 2, 0, 1);
    }
}

void func_803301E8_unk_bin_38(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 4;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
    if (D_80177A64 == 2) {
        gObjects[gCurrentParsedObject].actionState = 4;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_803302C8_unk_bin_38(void) {
    struct ObjectStruct* sp2C;
    s32 pad[2];
    s32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    sp20 = gObjects[gCurrentParsedObject].unkE8[0];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unkA6 = 0;
        sp2C->unkA8 *= 0x64;
        sp2C->unkAA = 0;
        sp2C->unkB6 = (s16) (s32) sp2C->Pos.y;
        sp2C->moveAngle = (f32) (((Math_Random(0xA) & 1) * 0xB4) + 0x5A);
        sp2C->moveSpeed = 4.0f;
        sp2C->unk40 = 90.0f;
        sp2C->unk48 = 30.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x61, &D_80118A6C);
        func_8001C0EC(sp20, 0, 0, 0x62, &D_80118A74);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp2C->unkA8 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    sp2C->unkA6 = (s16) (s32) Math_WrapAngle((f32) sp2C->unkA6, 10.0f);
    sp2C->unk48 = ((sinf((f32) ((f64) sp2C->unkA6 * DEG_TO_RAD)) * 30.0f) + (f32) sp2C->unkB6) - sp2C->Pos.y;
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->unkA8 = 0;
    }
    if ((sp2C->unkA8 == 0) && (sp2C->unkAA == 0)) {
        if (sp2C->moveAngle == 90.0f) {
            sp2C->moveAngle = 270.0f;
        } else {
            sp2C->moveAngle = 90.0f;
        }
        sp2C->unkAA = 0xA;
        sp2C->unkA8 = (Math_Random(0xA) & 1) + 1;
        sp2C->unkA8 *= 0x64;
    }
    if (sp2C->unkA8 != 0) {
        sp2C->unkA8 -= 1;
    }
    if (sp2C->unkAA != 0) {
        sp2C->unkAA -= 1;
    }
    gObjects[sp20].Vel.x = sp2C->Vel.x;
    gObjects[sp20].Vel.y = sp2C->Vel.y;
    gObjects[sp20].Vel.z = sp2C->Vel.z;
    if ((sp2C->Pos.z < gPlayerObject->Pos.z) && (func_8002A1FC(gCurrentParsedObject, 1500.0f) != 0)) {
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
    }
}

void func_803307B0_unk_bin_38(void) {
    struct ObjectStruct* sp44;
    s32 sp40;
    s32 sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;
    f32 sp2C;

    sp44 = &gObjects[gCurrentParsedObject];
    sp3C = gObjects[gCurrentParsedObject].unkE8[0];
    if (sp44->unk132 == 0) {
        sp44->unk132 = 1;
        sp44->moveSpeed = 20.0f;
        sp44->moveAngle = sp44->Rot.y;
        sp44->unk40 = 0.0f;
    }
    sp40 = 0;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp40 = 1;
    }
    sp2C = Math_CalcAngleRotated(gPlayerObject->Pos.x - sp44->Pos.x, (gPlayerObject->Pos.z - 360.0f) - sp44->Pos.z);
    sp30 = func_800157EC(sp44->moveAngle, sp2C, 2.0f);
    sp44->moveAngle = Math_WrapAngle(sp44->moveAngle, (f32) ((f64) sp30 * 0.5));
    sp2C = Math_CalcAngleSimple(gPlayerObject->Pos.x - sp44->Pos.x, gPlayerObject->Pos.y - sp44->Pos.y);
    sp2C = Math_NormalizeAngle(sp2C);
    sp30 = func_800157EC(sp44->unk40, sp2C, 2.0f);
    sp44->unk40 = Math_WrapAngle(sp44->unk40, (f32) sp30);
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp34, &sp38, 0.0f, -30.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp34, &sp38, 0.0f, 30.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    if (func_8002A1FC(gCurrentParsedObject, 1700.0f) == 0) {
        sp40 = 1;
    }
    if ((gPlayerObject->Pos.z - sp44->Pos.z) < 360.0f) {
        sp40 = 1;
    }
    if (sp40 != 0) {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->actionState = 4;
        sp44->unk132 = 0;
    }
    gObjects[sp3C].moveAngle = sp44->moveAngle;
    gObjects[sp3C].Rot.y = sp44->Rot.y;
    gObjects[sp3C].Rot.z = sp44->Rot.z;
    gObjects[sp3C].Vel.x = sp44->Vel.x;
    gObjects[sp3C].Vel.y = sp44->Vel.y;
    gObjects[sp3C].Vel.z = sp44->Vel.z;
}

void func_80330C34_unk_bin_38(void) {
}

void func_80330C44_unk_bin_38(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    sp20 = gObjects[gCurrentParsedObject].unkE8[0];
    if (gObjects[gCurrentParsedObject].unkE8[0] != -1) {
        func_800281A4(gCurrentParsedObject, 0);
        func_8002B114(sp20);
    }
    func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
    func_8007EDF4(sp24->Pos.x, sp24->Pos.y + 120.0f, sp24->Pos.z, 1.8f);
    func_8002B114(gCurrentParsedObject);
}

void func_80330D64_unk_bin_38(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_803302C8_unk_bin_38();
            break;
        case 2:
            func_803307B0_unk_bin_38();
            break;
        case 3:
            func_80330C34_unk_bin_38();
            break;
        case 4:
            func_80330C44_unk_bin_38();
            break;
        default:
            break;
    }
}

void func_80330E30_unk_bin_38(void) {
    s32 sp4;

    if ((D_80177A64 == 2) && (gObjects[gCurrentParsedObject].unkE6[0] != -1)) {
        sp4 = gObjects[gCurrentParsedObject].unkE6[0];
        gObjects[sp4].actionState = 2;
        gObjects[sp4].unk132 = 0;
    }
}

void func_80330F08_unk_bin_38(void) {
}

void func_80330F18_unk_bin_38(void) {
    s32 sp24;
    s32 sp20;

    sp24 = func_80027464(2, &D_80113FB8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        sp20 = gObjects[sp24].unkE8[0];
        gObjects[sp24].Scale.x = 1.5f;
        gObjects[sp24].Scale.y = 1.5f;
        gObjects[sp24].Scale.z = 1.5f;
        gObjects[sp20].Scale.x = 1.5f;
        gObjects[sp20].Scale.y = 1.5f;
        gObjects[sp20].Scale.z = 1.5f;
    }
}

void func_803310D8_unk_bin_38(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 4;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
    if (D_80177A64 == 2) {
        gObjects[gCurrentParsedObject].actionState = 4;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_803311B8_unk_bin_38(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    sp20 = gObjects[gCurrentParsedObject].unkE8[0];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unkA6 = 0;
        sp24->unkA8 = 0xA;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x61, &D_80118A6C);
        func_8001C0EC(sp20, 0, 0, 0x62, &D_80118A74);
    }
    if (sp24->unkA6 == 0) {
        sp24->Pos.y -= 2.0f;
        sp24->unkA8 -= 1;
        if (sp24->unkA8 == 0) {
            sp24->unkA6 = 1;
            sp24->unkA8 = 0x14;
        }
    } else {
        sp24->Pos.y += 2.0f;
        sp24->unkA8 -= 1;
        if (sp24->unkA8 == 0) {
            sp24->unkA6 = 0;
            sp24->unkA8 = 0x14;
        }
    }
    gObjects[sp20].Pos.y = sp24->Pos.y;
    if (func_8002A1FC(gCurrentParsedObject, 1200.0f) != 0) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
    }
}

void func_803313F8_unk_bin_38(void) {
    struct ObjectStruct* sp14;
    s32 pad[2];
    s32 sp8;

    sp14 = &gObjects[gCurrentParsedObject];
    sp8 = gObjects[gCurrentParsedObject].unkE8[0];
    if (sp14->unk132 == 0) {
        sp14->unk132 = 1;
        sp14->unkA6 = 0x14;
        sp14->Vel.z = 0.0f;
        sp14->Vel.x = sp14->Vel.y = sp14->Vel.z;
        gObjects[sp8].Vel.x = gObjects[sp8].Vel.y = gObjects[sp8].Vel.z = 0.0f;
    }
    if (sp14->unkA6 == 0) {
        sp14->actionState = 3;
        sp14->unk132 = 0;
    } else {
        sp14->unkA6 -= 1;
        sp14->Scale.x = (f32) ((f64) sp14->Scale.x + 0.12);
        sp14->Scale.y = (f32) ((f64) sp14->Scale.y + 0.12);
        sp14->Scale.z = (f32) ((f64) sp14->Scale.z + 0.12);
        gObjects[sp8].Scale.x = (f32) ((f64) gObjects[sp8].Scale.x + 0.12);
        gObjects[sp8].Scale.y = (f32) ((f64) gObjects[sp8].Scale.y + 0.12);
        gObjects[sp8].Scale.z = (f32) ((f64) gObjects[sp8].Scale.z + 0.12);
    }
}

void func_803316C4_unk_bin_38(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    UNUSED s32 pad[3];

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = gObjects[gCurrentParsedObject].unkE8[0];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unkA6 = 0x5A;
    }
    if (sp2C->unkA6 == 0) {
        sp2C->unk132 = 0;
        sp2C->actionState = 4;
    } else {
        sp2C->unkA6 -= 1;
        sp2C->Rot.y = Math_WrapAngle(sp2C->Rot.y, 12.0f);
        gObjects[sp28].Rot.y = sp2C->Rot.y;
    }
}

void func_8033180C_unk_bin_38(void) {
    struct ObjectStruct* sp3C;
    UNUSED s32 pad[2];
    s32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    sp30 = gObjects[gCurrentParsedObject].unkE8[0];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unkA6 = 0x14;
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z;
        gObjects[sp30].Vel.x = gObjects[sp30].Vel.y = gObjects[sp30].Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x61, &D_80118A6C);
        sp3C->damageState = 0;
        gObjects[sp30].damageState = 0;
    }
    if (sp3C->unkA6 == 0) {
        sp3C->actionState = 5;
        sp3C->unk132 = 0;
    } else {
        sp3C->unkA6 -= 1;
    }
}

void func_80331A18_unk_bin_38(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    sp20 = gObjects[gCurrentParsedObject].unkE8[0];
    if (gObjects[gCurrentParsedObject].unkE8[0] != -1) {
        func_800281A4(gCurrentParsedObject, 0);
        func_8002B114(sp20);
    }
    func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
    func_8007EDF4(sp24->Pos.x, sp24->Pos.y + 360.0f, sp24->Pos.z, 2.5f);
    func_8002B114(gCurrentParsedObject);
}

void func_80331B34_unk_bin_38(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_803311B8_unk_bin_38();
            break;
        case 2:
            func_803313F8_unk_bin_38();
            break;
        case 3:
            func_803316C4_unk_bin_38();
            break;
        case 4:
            func_8033180C_unk_bin_38();
            break;
        case 5:
            func_80331A18_unk_bin_38();
            break;
        default:
            break;
    }
}

void func_80331C04_unk_bin_38(void) {
    s32 sp4;

    if ((D_80177A64 == 2) && (gObjects[gCurrentParsedObject].unkE6[0] != -1)) {
        sp4 = (s32) gObjects[gCurrentParsedObject].unkE6[0];
        if (gObjects[sp4].actionState == 3) {
            gObjects[sp4].actionState = 4;
            gObjects[sp4].unk132 = 0;
        }
    }
}

void func_80331D0C_unk_bin_38(void) {
}

void func_80331D1C_unk_bin_38(void) {
    func_80027464(1, &D_80114174, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_80331D94_unk_bin_38(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 4;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_80331E0C_unk_bin_38(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xA8, &D_80118868);
        func_8001BB34(gCurrentParsedObject, 1);
    }
    if (func_8002A2EC(gCurrentParsedObject, 1200.0f) != 0) {
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
    }
}

void func_80331F28_unk_bin_38(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;
    s32 sp2C;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unkA6 = 0x1E;
        sp3C->unkA8 = 0x3C;
        sp3C->unkE0 = 3.0f;
        sp3C->unkAC = 0;
        sp3C->unkAE = Math_Random(0xA) & 1;
        sp3C->moveAngle = (f32) ((sp3C->unkAE * 0xB4) + 0x5A);
        sp3C->moveSpeed = 12.0f;
        sp3C->Scale.z = 0.1f;
        sp3C->Scale.x = sp3C->Scale.y = sp3C->Scale.z;
        func_8001BB34(gCurrentParsedObject, 0);
    }
    if (sp3C->unkA8 != 0) {
        sp3C->Scale.x = (f32) ((f64) sp3C->Scale.x + 0.015);
        sp3C->Scale.y = (f32) ((f64) sp3C->Scale.y + 0.015);
        sp3C->Scale.z = (f32) ((f64) sp3C->Scale.z + 0.015);
        sp3C->unkA8 -= 1;
        if (sp3C->unkA8 == 0x1E) {
            sp3C->damageState = 1;
        }
    }
    sp3C->unkA6 -= 1;
    if (sp3C->unkA6 == 0) {
        if (sp3C->moveAngle == 90.0f) {
            sp3C->moveAngle = 270.0f;
        } else {
            sp3C->moveAngle = 90.0f;
        }
        sp3C->unkA6 = 0x3C;
    }
    if (sp3C->moveAngle == 90.0f) {
        sp3C->Rot.z = Math_WrapAngle(sp3C->Rot.z, 0.2f);
    } else {
        sp3C->Rot.z = Math_WrapAngle(sp3C->Rot.z, -0.2f);
    }
    sp3C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 2U, 180.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = sp3C->Vel.z;
    }
    if (sp3C->unkAC == 0) {
        sp3C->unkE0 = (f32) ((f64) sp3C->unkE0 - 0.2);
        sp3C->moveSpeed = (f32) ((f64) sp3C->moveSpeed - 0.4);
        if (sp3C->unkE0 <= -2.0f) {
            sp3C->unkAA = -2;
            sp3C->unkAC = 1;
        }
    } else {
        sp3C->unkE0 = (f32) ((f64) sp3C->unkE0 + 0.2);
        sp3C->moveSpeed = (f32) ((f64) sp3C->moveSpeed + 0.4);
        if (sp3C->unkE0 >= 4.0f) {
            sp3C->unkAA = 4;
            sp3C->unkAC = 0;
        }
    }
    sp3C->Pos.y -= sp3C->unkE0;
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) {
        sp30 = (s32) sp34;
    } else {
        sp30 = (s32) sp38;
    }
    sp2C = (s32) (sp3C->Pos.y - 60.0f);
    if ((sp2C - sp30) <= 0) {
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z;
        sp3C->actionState = 3;
        sp3C->unk132 = 0;
    }
}

void func_8033252C_unk_bin_38(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkA6 = Math_Random(0xA) & 1;
        sp2C->moveSpeed = 5.0f;
    }
    sp2C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 180.0f, 0.0f, 0.0f, 0.0f) != 0) {
        if (sp2C->moveAngle == 90.0f) {
            sp2C->moveAngle = 270.0f;
        } else {
            sp2C->moveAngle = 90.0f;
        }
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 60.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp24;
    } else {
        sp2C->Pos.y = sp28;
    }
    sp2C->Pos.y += 60.0f;
}

void func_803326DC_unk_bin_38(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_8033270C_unk_bin_38(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_80331E0C_unk_bin_38();
            break;
        case 2:
            func_80331F28_unk_bin_38();
            break;
        case 3:
            func_8033252C_unk_bin_38();
            break;
        case 4:
            func_803326DC_unk_bin_38();
            break;
        default:
            break;
    }
}

void func_803327D8_unk_bin_38(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011403C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].Scale.x = 1.5f;
        gObjects[sp24].Scale.y = 1.5f;
        gObjects[sp24].Scale.z = 1.5f;
    }
}

void func_803328E8_unk_bin_38(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk132 = 0;
        sp4->actionState = 4;
    } else if ((D_80177A64 == 1) && (sp4->damageState == 1)) {
        sp4->damageState = 0x32;
    }
}

void func_80332990_unk_bin_38(void) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->moveSpeed = 4.0f;
        sp34->moveAngle = 0.0f;
        sp34->unkA6 = 0;
        sp34->unkA8 = 0;
        sp34->unkAA = 0;
        sp34->unkB0 = 0;
        sp34->unkB2 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x89, &D_801182C4);
    }
    if (sp34->damageState == 1) {
        sp34->moveSpeed = 4.0f;
        func_8001BBDC(gCurrentParsedObject, 0);
    } else {
        func_8001BB34(gCurrentParsedObject, !((sp34->damageState + 1) & 1));
        sp34->moveSpeed = 0.0f;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if ((sp34->unkA6 == 0) && (sp34->moveAngle == 0.0f)) {

    } else {
        if (sp34->unkAA == 0) {
            sp34->Rot.y = Math_WrapAngle(sp34->Rot.y, (f32) (sp34->unkA8 * 2));
            sp34->moveAngle = sp34->Rot.y;
        }
        sp30 = (s32) ((f32) sp34->unkA6 - sp34->moveAngle);
        if ((sp30 < 3) && (sp30 >= -2)) {
            if (sp34->unkA6 != 0) {
                sp34->unkB6 = (s16) (s32) sp34->moveAngle;
                sp34->unkB8 = (s16) (s32) sp34->Vel.x;
                sp34->unkBA = (s16) (s32) sp34->Vel.z;
                sp34->moveAngle = 0.0f;
                func_80029C40(gCurrentParsedObject);
                if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
                    sp34->unkAA = 1;
                } else {
                    sp34->unkA6 = 0;
                    sp34->unkAA = 0;
                    if (sp34->unkA8 == 1) {
                        sp34->unkA8 = -1;
                    } else {
                        sp34->unkA8 = 1;
                    }
                }
                sp34->moveAngle = (f32) sp34->unkB6;
                sp34->Vel.x = (f32) sp34->unkB8;
                sp34->Vel.z = (f32) sp34->unkBA;
            } else {
                sp34->unkA8 = 0;
                sp34->Rot.y = 0.0f;
                sp34->moveAngle = sp34->Rot.y;
            }
        }
    }
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        if (D_801651A0 & 0x80) {
            sp34->Vel.z = 0.0f;
            sp34->Vel.x = sp34->Vel.z;
            sp34->unkB0 = 1;
        } else if ((sp34->unkA6 == 0) && (sp34->moveAngle == 0.0f)) {
            sp30 = (s32) Get_AngleToPlayer(gCurrentParsedObject);
            if ((sp30 >= 0) && (sp30 < 0xB4)) {
                sp34->unkA6 = 0x5A;
                sp34->unkA8 = 1;
            }
        } else {
            sp34->unkA6 = 0x10E;
            sp34->unkA8 = -1;
        }
    }
    if ((((gPlayerObject->Pos.z - sp34->Pos.z) < 1600.0f) || (sp34->unkB0 != 0)) && (sp34->unkA6 == 0) &&
        (sp34->moveAngle == 0.0f) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp34->actionState = 2;
        sp34->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
}

void func_80333020_unk_bin_38(void) {
    struct ObjectStruct* sp34;
    s32 pad[2];

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkA6 = 0;
        sp34->unkA8 = 0;
        sp34->unkAE = 0;
        sp34->unkD4 = 0.0f;
        sp34->unkD8 = 0.0f;
        sp34->unk40 = 0.0f;
        sp34->unk48 = 0.0f;
        sp34->moveSpeed = 0.0f;
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    if (sp34->damageState == 1) {
        if (sp34->unkA8 != 0) {
            sp34->unkA8 -= 1;
            if (sp34->unkA8 < 0xA) {
                sp34->unkD4 = (f32) ((f64) sp34->unkD4 - 0.5);
            } else if (sp34->unkD4 < 5.0f) {
                sp34->unkD4 += 1.0f;
            }
            sp34->Rot.x += sp34->unkD8;
        }
        sp34->unk48 = sp34->unkD4;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001BB34(gCurrentParsedObject, 0);
    } else {
        sp34->unk48 = 0.0f;
        func_8001BB34(gCurrentParsedObject, !((sp34->damageState + 1) & 1));
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        if (D_801651A0 & 0x80) {
            sp34->unkA6 = 2;
            sp34->Vel.z = 0.0f;
            sp34->Vel.x = sp34->Vel.z;
        } else {
            func_80029A9C(gCurrentParsedObject, func_800297DC());
        }
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 60.0f) {
        sp34->unk40 = 90.0f;
        sp34->unkD4 = 1.0f;
        sp34->unkD8 = 1.0f;
        sp34->unkA8 = 0x3C;
    } else if (func_8001B62C(gCurrentParsedObject, 0) == 0.0f) {
        sp34->unk40 = 270.0f;
        sp34->unkD4 = 1.0f;
        sp34->unkD8 = -1.0f;
        sp34->unkA8 = 0x3C;
    }
    if (sp34->unkB0 == 0) {
        if ((sp34->unkA6 == 0)) {
            if ((gPlayerObject->Pos.z - sp34->Pos.z) > 1700.0f) {
                sp34->unkA6 = 1;
            }
        }
        if ((sp34->unkA6 == 1) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
            sp34->actionState = 1;
            sp34->unk132 = 0;
        }
    }
}

void func_803334E4_unk_bin_38(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80333514_unk_bin_38(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80333544_unk_bin_38(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_80332990_unk_bin_38();
            break;
        case 2:
            func_80333020_unk_bin_38();
            break;
        case 3:
            func_803334E4_unk_bin_38();
            break;
        case 4:
            func_80333514_unk_bin_38();
            break;
        default:
            break;
    }
}

void func_80333610_unk_bin_38(void) {
    s32 sp34;
    s32 sp30;
    s16 sp2E;
    s16 temp_t4;

    sp34 = func_80027464(7, &D_80114180, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp34 != -1) {
        for (sp2E = 0; sp2E < 6; sp2E++) {
            sp30 = gObjects[sp34].unkE8[sp2E];
            gObjects[sp30].unkA6 = sp2E * 0x3C;
            gObjects[sp30].Pos.x = (240.0f * sinf(((f64) gObjects[sp30].unkA6 * DEG_TO_RAD))) + gObjects[sp34].Pos.x;
            gObjects[sp30].Pos.y = (240.0f * cosf(((f64) gObjects[sp30].unkA6 * DEG_TO_RAD))) + gObjects[sp34].Pos.y;
        }
    }
}

void func_80333880_unk_bin_38(void) {
}

void func_80333890_unk_bin_38(void) {
    struct ObjectStruct* sp24;
    s32 sp20;
    s16 sp1E;
    s16 temp_t4;
    s16 temp_t8;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkA8 = 0xF0;
        sp24->unkAA = 0;
        func_8001BB34(gCurrentParsedObject, 1);
    }
    for (sp1E = 0; sp1E < 6; sp1E++) {
        sp20 = (s32) gObjects[gCurrentParsedObject].unkE8[sp1E];
        gObjects[sp20].unkA6 = (s16) (s32) Math_WrapAngle(gObjects[sp20].unkA6, 3.0f);
        gObjects[sp20].Pos.x = sp24->Pos.x + (sinf(((f64) gObjects[sp20].unkA6 * DEG_TO_RAD))) * sp24->unkA8;
        gObjects[sp20].Pos.y = sp24->Pos.y + (cosf(((f64) gObjects[sp20].unkA6 * DEG_TO_RAD))) * sp24->unkA8;
        gObjects[sp20].Pos.z = sp24->Pos.z;
    }
    if (sp24->unkAA == 0) {
        sp24->unkA8 -= 1;
        if (sp24->unkA8 == 0x78) {
            sp24->unkAA = 1;
        }
    } else {
        sp24->unkA8 += 1;
        if (sp24->unkA8 == 0xF0) {
            sp24->unkAA = 0;
        }
    }
}

void func_80333BE0_unk_bin_38(void) {
    if (gObjects[gCurrentParsedObject].actionState == 1) {
        if (FALSE) {}
        func_80333890_unk_bin_38();
    } else {
        if (FALSE)
            ;
    }
}

void func_80333C54_unk_bin_38(void) {
    s32 sp34;
    s32 sp30;
    s16 sp2E;
    s16 temp_t4;

    sp34 = func_80027464(7, &D_801141D4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp34 != -1) {
        for (sp2E = 0; sp2E < 6; sp2E++) {
            sp30 = gObjects[sp34].unkE8[sp2E];
            gObjects[sp30].unkA6 = sp2E * 0x3C;
            gObjects[sp30].Pos.x = 
                                   (240.0f * sinf((f32) ((f64) gObjects[sp30].unkA6 * DEG_TO_RAD))) + gObjects[sp34].Pos.x ; 
            gObjects[sp30].Pos.y = 
                                   (240.0f * cosf((f32) ((f64) gObjects[sp30].unkA6 * DEG_TO_RAD))) + gObjects[sp34].Pos.y;
        }
    }
}

void func_80333EC4_unk_bin_38(void) {
}

void func_80333ED4_unk_bin_38(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    s32 pad;
    s16 sp22;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkA8 = 0xF0;
        sp2C->unkAA = 0;
        sp2C->unkAC = 0x3C;
        sp2C->moveSpeed = 2.0f;
        sp2C->moveAngle = 90.0f;
        func_8001BB34(gCurrentParsedObject, 1);
    }
    sp2C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.z;
    }
    sp2C->unkAC -= 1;
    if (sp2C->unkAC == 0) {
        sp2C->unkAC = 0x78;
        if (sp2C->moveAngle == 90.0f) {
            sp2C->moveAngle = 270.0f;
        } else {
            sp2C->moveAngle = 90.0f;
        }
    }
    for (sp22 = 0; sp22 < 6; sp22++) {
        sp28 = (s32) gObjects[gCurrentParsedObject].unkE8[sp22];
        gObjects[sp28].unkA6 = (s16) (s32) Math_WrapAngle((f32) gObjects[sp28].unkA6, 3.0f);
        gObjects[sp28].Pos.x =
            (sinf((f32) ((f64) gObjects[sp28].unkA6 * DEG_TO_RAD)) * (f32) sp2C->unkA8) + sp2C->Pos.x;
        gObjects[sp28].Pos.y =
            (cosf((f32) ((f64) gObjects[sp28].unkA6 * DEG_TO_RAD)) * (f32) sp2C->unkA8) + sp2C->Pos.y;
        gObjects[sp28].Pos.z = sp2C->Pos.z;
    }
    if (sp2C->unkAA == 0) {
        sp2C->unkA8 -= 1;
        if (sp2C->unkA8 == 0x78) {
            sp2C->unkAA = 1;
        }
    } else {
        sp2C->unkA8 += 1;
        if (sp2C->unkA8 == 0xF0) {
            sp2C->unkAA = 0;
        }
    }
}

void func_80334354_unk_bin_38(void) {
    if (gObjects[gCurrentParsedObject].actionState == 1) {
        if (FALSE) {}
        func_80333ED4_unk_bin_38();
    } else {
        if (FALSE) {}
    }
}

void func_803343C8_unk_bin_38(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114264, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkB8 = 0;
        func_80019448(sp24, 2, 0, 1);
    }
}

void func_8033448C_unk_bin_38(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].damageState = 0;
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 3;
    }
}

void func_8033452C_unk_bin_38(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unkA6 = 0;
        sp2C->unkA8 *= 0x64;
        sp2C->unkAA = 0;
        sp2C->unkB6 = (s16) (s32) sp2C->Pos.y;
        sp2C->moveAngle = (f32) (((Math_Random(0xA) & 1) * 0xB4) + 0x5A);
        sp2C->moveSpeed = 2.0f;
        sp2C->unk40 = 90.0f;
        sp2C->unk48 = 30.0f;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x173, &D_80118A64);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp2C->unkA8 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    sp2C->unkA6 = (s16) (s32) Math_WrapAngle((f32) sp2C->unkA6, 10.0f);
    func_800294F0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f);
    sp2C->unk48 =
        ((sinf((f32) ((f64) sp2C->unkA6 * DEG_TO_RAD)) * 20.0f) + (f32) sp2C->unkB6) - sp2C->Pos.y;
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->unkA8 = 0;
    }
    if ((sp2C->unkA8 == 0) && (sp2C->unkAA == 0)) {
        if (sp2C->moveAngle == 90.0f) {
            sp2C->moveAngle = 270.0f;
        } else {
            sp2C->moveAngle = 90.0f;
        }
        sp2C->unkAA = 0xA;
        sp2C->unkA8 = (Math_Random(0xA) & 1) + 1;
        sp2C->unkA8 *= 0x64;
    }
    if (sp2C->unkA8 != 0) {
        sp2C->unkA8 -= 1;
    }
    if (sp2C->unkAA != 0) {
        sp2C->unkAA -= 1;
    }
    if (sp2C->unkB8 == 0) {
        if ((sp2C->Pos.z < gPlayerObject->Pos.z) && (func_8002A1FC(gCurrentParsedObject, 1500.0f) != 0)) {
            sp2C->actionState = 2;
            sp2C->unk132 = 0;
        }
    } else if (func_8002A1FC(gCurrentParsedObject, 1700.0f) == 0) {
        sp2C->unkB8 = 0;
    }
}

void func_803349B0_unk_bin_38(void) {
    struct ObjectStruct* sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    s32 sp34;
    f32 sp30;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = 1;
        sp44->moveSpeed = 20.0f;
        sp44->moveAngle = sp44->Rot.y;
        sp44->unk40 = 0.0f;
    }
    sp40 = 0;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp40 = 1;
    }
    sp30 = Math_CalcAngleRotated(gPlayerObject->Pos.x - sp44->Pos.x, gPlayerObject->Pos.z - sp44->Pos.z);
    sp34 = func_800157EC(sp44->moveAngle, sp30, 2.0f);
    sp44->moveAngle = Math_WrapAngle(sp44->moveAngle, (f32) ((f64) sp34 * 0.5));
    sp30 = Math_CalcAngleSimple(gPlayerObject->Pos.x - sp44->Pos.x, gPlayerObject->Pos.y - sp44->Pos.y);
    sp30 = Math_NormalizeAngle(sp30);
    sp34 = func_800157EC(sp44->unk40, sp30, 2.0f);
    sp44->unk40 = Math_WrapAngle(sp44->unk40, (f32) sp34);
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp3C, 0.0f, -30.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp3C, 0.0f, 30.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    if (func_8002A1FC(gCurrentParsedObject, 1700.0f) == 0) {
        sp40 = 1;
    }
    if (sp40 != 0) {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->unkB8 = 1;
        sp44->actionState = 1;
        sp44->unk132 = 0;
    }
}

void func_80334CC4_unk_bin_38(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80334CF4_unk_bin_38(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_8033452C_unk_bin_38();
            break;
        case 2:
            func_803349B0_unk_bin_38();
            break;
        case 3:
            func_80334CC4_unk_bin_38();
            break;
        default: 
            break;
    }
}

void func_80334DA4_unk_bin_38(void) {
    func_80027464(1, &D_80113F04, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void stub_80334E28(void)  {

}

void func_80334E2C_unk_bin_38(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138);
    }
    if ((gObjects->Pos.y < (sp2C->Pos.y - 90.0f)) && (func_8002A2EC(gCurrentParsedObject, 420.0f) != 0)) {
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
    }
}

void func_80334F84_unk_bin_38(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        sp2C->unkA6 = 0x1E;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138 + 1);
    }
    if (sp2C->unkA6 == 0) {
        sp2C->actionState = 3;
        sp2C->unk132 = 0;
    } else {
        sp2C->unkA6 -= 1;
    }
}

void func_803350D4_unk_bin_38(void) {
    struct ObjectStruct* sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->moveSpeed = 8.0f;
        sp24->moveAngle = Get_AngleToPlayer(gCurrentParsedObject);
        func_80029EF8(gCurrentParsedObject, 10.0f, 1.0f);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x55, &D_80118108);
    }
    sp20 = sp24->Vel.y;
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 2U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    sp24->Vel.y = sp20;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -107.0f, 60.0f) == 1) {
        func_800175F0(gCurrentParsedObject, 0, 0x3E, -1, 0);
        sp24->actionState = 4;
        sp24->unk132 = 0;
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
}

void func_803352D8_unk_bin_38(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->moveSpeed = 0.0f;
        func_80029EF8(gCurrentParsedObject, 10.0f, 1.0f);
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -107.0f, 60.0f) == 1) {
        sp24->actionState = 5;
        sp24->unk132 = 0;
    }
}

void func_803353C0_unk_bin_38(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->Vel.x = 0.0f;
        sp1C->Vel.y = 0.0f;
        sp1C->Vel.z = 0.0f;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138);
    }
}

void func_80335470_unk_bin_38(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_80334E2C_unk_bin_38();
            break;
        case 2:
            func_80334F84_unk_bin_38();
            break;
        case 3:
            func_803350D4_unk_bin_38();
            break;
        case 4:
            func_803352D8_unk_bin_38();
            break;
        case 5:
            func_803353C0_unk_bin_38();
            break;
        default:
            break;
    }
}

void func_80335540_unk_bin_38(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113F40, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkB6 = D_80165100->unkA;
        gObjects[sp24].unkB8 = 0;
    }
}

void stub_8033562C(void) {
    
}

void func_80335630_unk_bin_38(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138);
    }
    if (func_8002A2EC(gCurrentParsedObject, 1200.0f) != 0) {
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
    }
}

void func_80335758_unk_bin_38(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;
    f32 sp34;
    f32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = sp3C->Vel.y =  sp3C->Vel.z;
        sp3C->unkA6 = 0;
        sp3C->unkA8 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138 + 1);
    }
    sp38 = 0;
    sp3C->Rot.y = Math_WrapAngle(sp3C->Rot.y, 8.0f);
    if (sp3C->unkB6 == 0) {
        sp3C->unkA8 += 1;
        if (sp3C->unkA8 >= 0xA) {
            sp3C->unkA8 = 0xA;
        }
        sp3C->Vel.y = (f32) sp3C->unkA8;
    } else {
        sp3C->unkA8 -= 1;
        if (sp3C->unkA8 < -9) {
            sp3C->unkA8 = -0xA;
        }
        sp3C->Vel.y = (f32) sp3C->unkA8;
    }
    if ((sp3C->unkB6 == 0) && (func_800295C0(gCurrentParsedObject, &sp34, &sp30, 0.0f, 100.0f, 0.0f) != 0)) {
        sp38 = 1;
    }
    if ((sp3C->unkB6 == 1) && (func_800295C0(gCurrentParsedObject, &sp34, &sp30, 0.0f, -100.0f, 0.0f) != 0)) {
        sp38 = 1;
    }
    if (sp38 == 1) {
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z;
        sp3C->actionState = 3;
        sp3C->unk132 = 0;
    }
}

void func_80335A70_unk_bin_38(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkA6 = 0x1E;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138);
        if (sp24->unkB6 == 0) {
            func_8002AE38(sp24->Pos.x, sp24->Pos.y + 100.0f, sp24->Pos.z, 2.0f, 0x10);
        } else {
            func_8002AE38(sp24->Pos.x, sp24->Pos.y - 100.0f, sp24->Pos.z, 2.0f, 0x10);
        }
        func_800175F0(gCurrentParsedObject, 0, 0x3E, -1, 0);
    }
    if (sp24->unkA6 == 0) {
        if (sp24->unkB6 == 0) {
            sp24->unkB6 = 1;
        } else {
            sp24->unkB6 = 0;
        }
        sp24->actionState = 1;
        sp24->unk132 = 0;
    } else {
        sp24->unkA6 -= 1;
    }
}

void func_80335C48_unk_bin_38(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_80335630_unk_bin_38();
            break;
        case 2:
            func_80335758_unk_bin_38();
            break;
        case 3:
            func_80335A70_unk_bin_38();
            break;
        default:
            break;
    }
}

void func_80335CF8_unk_bin_38(void) {
    s8 sp27;

    sp27 = func_80027464(1, &D_80113A78, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp27 != -1) {
        gObjects[sp27].Rot.y = (f32) D_80165100->unk8;
        gObjects[sp27].damageState = 0;
        gObjects[sp27].unk100 = -1;
        gObjects[sp27].unk102 = 0;
        gObjects[sp27].unk103 = 1;
        gObjects[sp27].actionState = 2;
        gObjects[sp27].unk132 = 0;
        gObjects[sp27].moveAngle = (f32) Math_Random(0x168);
        func_8001C0EC((s32) sp27, 0, 0, 0xEF, &D_8011731C);
        func_8001ABF4((s32) sp27, 0, 0, &D_80117368);
        func_8001ABF4((s32) sp27, 1, 0, &D_80117384);
    }
}

void func_80335F24_unk_bin_38(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->actionState = 7;
        sp4->unk132 = 0;
    }
}

void func_80335F90_unk_bin_38(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->moveSpeed = 6.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0x258;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xEF, &D_8011731C);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->actionState = 4;
        sp24->unk132 = 0;
        return;
    }
    sp24->Rot.y = sp24->moveAngle;
    sp24->unkA6 -= 6;
    if (func_8002A1FC(gCurrentParsedObject, 180.0f) != 0) {
        sp24->actionState = 3;
        sp24->unk132 = 0;
    }
    if (sp24->unkA6 <= 0) {
        sp24->actionState = 3;
        sp24->unk132 = 0;
    }
}

void func_80336188_unk_bin_38(void) {
    struct ObjectStruct* sp24;
    s8 sp23;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->moveSpeed = 8.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA8 = (s16) (s32) Math_WrapAngle(sp24->moveAngle, 180.0f);
        sp24->unkD4 = 10.0f;
    }
    sp23 = func_800BFF20(sp24, (f32) sp24->unkA8, sp24->unkD4);
    if (sp23 == 0) {
        sp24->actionState = 5;
        sp24->unk132 = 0;
    }
    if (sp23 != 0) {
        sp24->unkD4 = (f32) sp23 * 10.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_80029018(gCurrentParsedObject, 4U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->actionState = 4;
        sp24->unk132 = 0;
        return;
    }
    sp24->Rot.y = sp24->moveAngle;
}

void func_803363A4_unk_bin_38(void) {
    struct ObjectStruct* sp34;
    s8 sp33;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->moveSpeed = 8.0f;
        sp34->unk48 = 0.0f;
        sp34->unkA6 = 0x78;
        sp34->unkA8 = (s16) (s32) Math_WrapAngle(sp34->moveAngle, (f32) Math_Random(-0xB4));
        sp34->unkD4 = 30.0f;
        sp33 = func_800BFF20(sp34, (f32) sp34->unkA8, sp34->unkD4);
        if (sp33 != 0) {
            sp34->unkD4 = (f32) sp33 * 10.0f;
        }
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xEF, &D_8011731C);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_80029018(gCurrentParsedObject, 4U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->actionState = 4;
        sp34->unk132 = 0;
        return;
    }
    if (sp34->unk132 == 1) {
        sp34->unkA6 -= 8;
        if (sp34->unkA6 <= 0) {
            sp34->moveSpeed = 6.0f;
            sp34->unk132 = 2;
        }
    }
    if (sp33 != 0) {
        sp33 = func_800BFF20(sp34, (f32) sp34->unkA8, sp34->unkD4);
    }
    sp34->Rot.y = sp34->moveAngle;
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) == 0) {
        sp34->actionState = 2;
        sp34->unk132 = 0;
    }
}

void func_803366A8_unk_bin_38(void) {
    struct ObjectStruct* sp34;
    s8 sp33;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->moveSpeed = 4.0f;
        sp34->unk48 = 0.0f;
        sp34->unkA8 = (s16) (s32) Math_WrapAngle(sp34->moveAngle, 180.0f);
        sp34->unkA8 = (s16) (s32) Math_WrapAngle((f32) sp34->unkA8, (f32) (func_800297DC() * 0x2D));
        sp34->unkA8 = (s16) (s32) Math_WrapAngle((f32) sp34->unkA8, (f32) Math_Random(-0x2D));
        sp34->unkD4 = 30.0f;
    }
    sp33 = func_800BFF20(sp34, (f32) sp34->unkA8, sp34->unkD4);
    if (sp33 == 0) {
        sp34->actionState = 5;
        sp34->unk132 = 0;
        sp34->Rot.y = sp34->moveAngle;
    }
    if (sp33 != 0) {
        sp34->unkD4 = (f32) sp33 * 30.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_80029018(gCurrentParsedObject, 4U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->unkA8 = (s16) (s32) Math_WrapAngle(sp34->moveAngle, 180.0f);
        sp34->unkA8 = (s16) (s32) Math_WrapAngle((f32) sp34->unkA8, (f32) Math_Random(-0xB4));
    }
}

void func_80336A00_unk_bin_38(void) {
    func_8001BB34(gCurrentParsedObject, 0);
    func_8002B0E4(gCurrentParsedObject);
}

void func_80336A40_unk_bin_38(void) {
}

void func_80336A50_unk_bin_38(void) {
}

void func_80336A60_unk_bin_38(void) {
    s32 sp1C;

    sp1C = (s32) gObjects[gCurrentParsedObject].actionState;
    switch (sp1C) {
        case 2:
            func_80335F90_unk_bin_38();
            break;
        case 5:
            func_803363A4_unk_bin_38();
            break;
        case 3:
            func_80336188_unk_bin_38();
            break;
        case 4:
            func_803366A8_unk_bin_38();
            break;
        case 6:
            func_80336A40_unk_bin_38();
            break;
        case 7:
            func_80336A00_unk_bin_38();
            break;
        case 8:
            func_80336A50_unk_bin_38();
            break;
        default:
            break;
    }
}

void func_80336B5C_unk_bin_38(void) {
    s8 sp27;

    sp27 = func_80027464(1, &D_80113A84, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp27 != -1) {
        gObjects[sp27].Rot.y = (f32) D_80165100->unk8;
        gObjects[sp27].damageState = 0;
        gObjects[sp27].unk100 = -1;
        gObjects[sp27].unk102 = 0;
        gObjects[sp27].unk103 = 1;
        gObjects[sp27].actionState = 2;
        gObjects[sp27].unk132 = 0;
        gObjects[sp27].moveAngle = (f32) Math_Random(0x168);
        func_8001C0EC((s32) sp27, 0, 0, 0xEF, &D_8011731C);
        func_8001ABF4((s32) sp27, 0, 0, &D_801173A0);
        func_8001ABF4((s32) sp27, 1, 0, &D_801173BC);
    }
}

s16 func_80336D88_unk_bin_38(struct ObjectStruct* arg0, s16 arg1, s16 arg2) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp32 = func_80027464(1, &D_80113DD8, arg0->Pos.x, arg0->Pos.y, arg0->Pos.z, arg0->moveAngle);
    if (sp32 != -1) {
        func_80026F10((s32) arg1, (s32) sp32);
        sp34 = &gObjects[sp32];
        sp34->Pos.x = (arg0->Pos.x + (f32) (arg2 * 0x50)) - 40.0f;
        sp34->Pos.y = arg0->Pos.y + 20.0f;
        sp34->Pos.z = arg0->Pos.z + 10.0f;
        /*
        temp_t2 = (arg2 * 0x3C) + 0x14A;
        if (temp_t2 >= 0xB5) {
            if (temp_t2 >= 0x168) {
                var_s0 = (arg2 * 0x3C) - 0x1E;
            } else {
                var_s0 = (arg2 * 0x3C) + 0x14A;
            }
            sp34->moveAngle = (f32) var_s0;
        } else {
            if (((arg2 * 0x3C) + 0x14A) < 0) {
                var_s1 = (arg2 * 0x3C) + 0x2B2;
            } else {
                var_s1 = (arg2 * 0x3C) + 0x14A;
            }
            sp34->moveAngle = (f32) var_s1;
        }
        */
        #define DUMMY(x) x + 0x14A >= 0xB5 ? (x + 0x14A) >= 0x168 ? x - 0x1E : x + 0x14A : x + 0x14A < 0 ? x + 0x2B2 : x + 0x14A
        sp34->moveAngle =  DUMMY(0x3C * arg2);
        sp34->unk40 = arg0->unk40;
        sp34->actionState = 1;
        sp34->unkA8 = 0;
        sp34->unkB2 = 0x8C;
        sp34->unk132 = 0;
        sp34->damageState = 1;
        func_8001C0EC((s32) sp32, 0, 0, 0x121, &D_801173E0);
        func_8001BBDC((s32) sp32, 1);
        func_80029C40((s32) sp32);
        func_80029D04((s32) sp32);
        arg0->damageState = 1;
    }
    return sp32;
}

void func_80337010_unk_bin_38(void) {
    s16 sp26;

    sp26 = func_80027464(1, &D_80113DCC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].actionState = 1;
        gObjects[sp26].unkA8 = -1;
        gObjects[sp26].unk132 = 0;
        func_8001BBDC((s32) sp26, 1);
        if (D_80165100->unkA != 0) {}
    }
}

void func_80337138_unk_bin_38(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 6;
    } else if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].actionState = 7;
    } else {
        return;
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_80337200_unk_bin_38(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->moveSpeed = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->damageState = -1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x120, &D_801173D8);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if ((func_8002A2EC(gCurrentParsedObject, 1320.0f) != 0) && (func_8002A3A8(gCurrentParsedObject, 1440.0f) != 0)) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
    }
}

void func_80337318_unk_bin_38(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->moveSpeed = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->damageState = -1;
        func_80336D88_unk_bin_38(sp1C, (s16) gCurrentParsedObject, 0);
        func_80336D88_unk_bin_38(sp1C, (s16) gCurrentParsedObject, 1);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->actionState = 4;
    sp1C->unk132 = 0;
    sp1C->damageState = 1;
}

void func_80337430_unk_bin_38(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->moveSpeed = 0.0f;
        sp1C->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((sp1C->unk132 == 1) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        func_8001BBDC(gCurrentParsedObject, 1);
        sp1C->unkA6 = 0;
        sp1C->unk132 = 2;
    }
    if (sp1C->unk132 == 2) {
        sp1C->unkA6 += 1;
        if (sp1C->unkA6 >= 0x1E) {
            sp1C->actionState = 5;
            sp1C->unk132 = 0;
        }
    }
}

void func_8033759C_unk_bin_38(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->moveSpeed = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->damageState = -1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x120, &D_801173D8);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 3;
        sp24->unk132 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x120, &D_801173D8);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
}

void func_803376F0_unk_bin_38(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->moveSpeed = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkA6 += 1;
    if (sp1C->unkA6 >= 0x46) {
        sp1C->actionState = 2;
        sp1C->unk132 = 0;
    }
}

void func_803377F8_unk_bin_38(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->moveSpeed = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->damageState = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_8001BBDC(gCurrentParsedObject, 0);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp1C->unkA8 != 0) {}
    func_8002B0E4(gCurrentParsedObject);
}

void func_803378FC_unk_bin_38(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->moveSpeed = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk132 = 1;
        sp24->damageState = 0x3C;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    func_8001BB34(gCurrentParsedObject, !(sp24->damageState & 1));
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->damageState == 1) {
        sp24->actionState = 5;
        sp24->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

void func_80337A44_unk_bin_38(void) {
}

void func_80337A54_unk_bin_38(void) {
    s32 sp1C;

    sp1C = (s32) gObjects[gCurrentParsedObject].actionState;
    switch (sp1C) {
        case 1:
            func_80337200_unk_bin_38();
            break;
        case 2:
            func_80337318_unk_bin_38();
            break;
        case 3:
            func_803376F0_unk_bin_38();
            break;
        case 4:
            func_80337430_unk_bin_38();
            break;
        case 5:
            func_8033759C_unk_bin_38();
            break;
        case 7:
            func_803378FC_unk_bin_38();
            break;
        case 6:
            func_803377F8_unk_bin_38();
            break;
        default:
            break;
    }
}


void stub_80337B5C(void) {
    
}

void func_80337B60_unk_bin_38(void) {
    gObjects[gCurrentParsedObject].actionState = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_80337BC4_unk_bin_38(void) {
    struct ObjectStruct* sp3C;
    struct ObjectStruct* sp38;
    f32 sp34;
    f32 sp30;
    s32 sp2C;
    f32 sp28;
    u8 sp27;

    sp38 = gObjects;
    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = 1;
        sp3C->unk40 = 25.0f;
        sp3C->moveSpeed = 0.0f;
        sp3C->unk48 = 0.0f;
        sp3C->unkA6 = 0;
        sp3C->damageState = 1;
        func_800272E8(gCurrentParsedObject);
        func_80019448(gCurrentParsedObject, 2, 0, 1);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    sp3C->unkA6 += 1;
    if (sp3C->unkA6 >= 0x25) {
        sp27 = (u8) ((s16) sp3C->unkA6 / 25);
        sp3C->moveSpeed = (f32) (sp27 + 0x14);
    }
    if (sp3C->unkA6 == 0x14) {
        sp3C->moveSpeed = 20.0f;
        sp3C->unk48 = 14.0f;
    }
    if (sp3C->unkA6 >= 0x15) {
        sp28 = Math_CalcAngleRotated(sp38->Pos.x - sp3C->Pos.x, sp38->Pos.z - sp3C->Pos.z);
        sp2C = func_800157EC(sp3C->moveAngle, sp28, 8.0f);
        sp3C->moveAngle = Math_WrapAngle(sp3C->moveAngle, (f32) sp2C);
        sp28 = Math_CalcAngleSimple(sp38->Pos.x - sp3C->Pos.x, sp38->Pos.y - sp3C->Pos.y);
        sp28 = Math_NormalizeAngle(sp28);
        sp2C = func_800157EC(sp3C->unk40, sp28, 8.0f);
        sp3C->unk40 = Math_WrapAngle(sp3C->unk40, (f32) sp2C);
        sp3C->Rot.y = sp3C->moveAngle;
        sp3C->Rot.x = Math_WrapAngle(360.0f, -sp3C->unk40);
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp30, &sp34, 0.0f, -10.0f, 0.0f) != 0) {
        sp3C->actionState = 2;
        sp3C->unk132 = 0;
    }
    sp3C->unkB2 -= 1;
    if (sp3C->unkB2 <= 0) {
        sp3C->actionState = 2;
        sp3C->unk132 = 0;
    }
}

void func_80337F44_unk_bin_38(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->moveSpeed = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->damageState = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8002B0E4(gCurrentParsedObject);
}

void func_80338010_unk_bin_38(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
            case 1:
                func_80337BC4_unk_bin_38();
                break;
            case 2:
                func_80337F44_unk_bin_38();
                break;
            default: 
                break;
        }
    }
}

void func_803380D8_unk_bin_38(void) {
    s16 sp2E;

    sp2E = func_80027464(1, &D_80114624, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].actionState = 1;
        gObjects[sp2E].actionState = 6;
        gObjects[sp2E].unk132 = 0;
        gObjects[sp2E].Scale.x = 1.0f;
        gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.x;
        func_80019448(gCurrentParsedObject, 2, 0, 1);
        func_8001C0EC((s32) sp2E, 0, 0, 0x99, &D_80117874);
    }
}

void func_8033829C_unk_bin_38(void) {
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        return;
    }
    gObjects[gCurrentParsedObject].actionState = 3;
    gObjects[gCurrentParsedObject].damageState = 0;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_80338350_unk_bin_38(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->moveAngle = 0.0f;
        sp2C->moveSpeed = 4.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0;
    }
    sp2C->unkA6 = (s16) (s32) Math_WrapAngle((f32) sp2C->unkA6, 8.0f);
    sp2C->Rot.y = sp2C->moveAngle;
    sp2C->Rot.z = sinf((f32) ((f64) sp2C->unkA6 * DEG_TO_RAD)) * 16.0f;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
}

void func_80338508_unk_bin_38(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    s8 sp2F;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->moveSpeed = 4.0f;
        sp34->unk48 = 0.0f;
        sp34->unkA6 = 0;
        sp34->unkD4 = Math_WrapAngle((f32) Math_Random(0x168), 0.0f);
        sp34->unkD8 = 2.0f;
    }
    sp2F = func_800BFFCC(sp34, 0, sp34->unkD4, sp34->unkD8);
    if (sp2F == 0) {
        sp34->unkD4 = Math_WrapAngle((f32) Math_Random(0x168), 0.0f);
    }
    if (sp2F != 0) {
        sp34->unkD8 = (f32) sp2F * 2.0f;
    }
    sp34->Rot.y = sp34->moveAngle;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp30 = sp34->moveAngle;
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp34->unkD4 = sp34->moveAngle;
        sp34->moveAngle = sp30;
    }
    if (func_8002A1FC(gCurrentParsedObject, 720.0f) != 0) {
        sp34->actionState = 2;
        sp34->unk132 = 0;
    }
}

void func_80338754_unk_bin_38(void) {
    struct ObjectStruct* sp44;
    struct ObjectStruct* sp40;
    f32 sp3C;
    f32 sp38;
    s32 pad;
    f32 sp30;
    s8 sp2F;

    sp44 = &gObjects[gCurrentParsedObject];
    sp40 = gObjects;
    if (sp44->unk132 == 0) {
        sp44->unk132 = 1;
        sp44->moveSpeed = 4.0f;
        sp44->unk48 = 0.0f;
        sp44->unkA6 = 0x258;
        sp44->unkD4 = sp44->moveAngle;
        sp44->unkD8 = 2.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (sp44->unk132 == 1) {
        func_8002A8B4(gCurrentParsedObject, 1.0f);
        func_8002A9A4(gCurrentParsedObject, 12.0f);
        if (func_8002A560(gCurrentParsedObject, 8.0f) == 0) {
            sp44->unk132 = 2;
        }
    } else {
        if (sp44->unk132 == 3) {
            sp2F = func_800BFFCC(sp44, 0, sp44->unkD4, sp44->unkD8);
            if (sp2F == 0) {
                sp44->unk132 = 2;
            }
            if (sp2F != 0) {
                sp44->unkD8 = (f32) sp2F * 2.0f;
            }
        }
        if (sp44->moveSpeed < 16.0f) {
            sp44->moveSpeed += 1.0f;
        }
        if (sp44->unk48 < 12.0f) {
            sp44->unk48 += 1.0f;
        }
        sp44->unkA6 -= 0x10;
    }
    sp44->Rot.y = sp44->moveAngle;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp3C, 0.0f, -80.0f, 0.0f) != 0) {
        sp44->Vel.y = 0.0f;
        sp44->Rot.x = 0.0f;
    }
    if (func_80029018(gCurrentParsedObject, 4U, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp30 = sp44->moveAngle;
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp44->unk132 = 3;
        sp44->unkD4 = sp44->moveAngle;
        sp44->moveAngle = sp30;
    }
    if (sp44->unkA6 < 0) {
        sp44->actionState = 1;
        sp44->unk132 = 0;
    }
}

void func_80338B18_unk_bin_38(void) {
    func_8001BB34(gCurrentParsedObject, 0);
    func_8002B0E4(gCurrentParsedObject);
}

void func_80338B58_unk_bin_38(void) {
}

void func_80338B68_unk_bin_38(void) {
}

void func_80338B78_unk_bin_38(void) {
    s32 sp1C;

    sp1C = (s32) gObjects[gCurrentParsedObject].actionState;
    switch (sp1C) {
        case 1:
            func_80338508_unk_bin_38();
            break;
        case 2:
            func_80338754_unk_bin_38();
            break;
        case 3:
            func_80338B18_unk_bin_38();
            break;
        case 4:
            func_80338B58_unk_bin_38();
            break;
        case 5:
            func_80338B68_unk_bin_38();
            break;
        case 6:
            func_80338350_unk_bin_38();
            break;
        default:
            break;
    }
}

void func_80338C64_unk_bin_38(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114630, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA;
        gObjects[sp24].unkA8 = D_80165100->unkC;
    }
}

void func_80338D50_unk_bin_38(void) {
    if ((D_80177A64 == 0) && (gObjects[gCurrentParsedObject].actionState == 1)) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 2;
        gObjects[gCurrentParsedObject].damageState = 0;
    }
}

void func_80338E24_unk_bin_38(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1;
    }
}

void func_80338E88_unk_bin_38(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x18E, &D_80118DA0);
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8002AE38(sp24->Pos.x, sp24->Pos.y + 120.0f, sp24->Pos.z, 4.0f, 0x10);
        if (sp24->unkA6 != 0) {
            func_800941C4((s32) sp24->unkA8, sp24->Pos.x, sp24->Pos.y + 240.0f, sp24->Pos.z);
        }
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_80338FD0_unk_bin_38(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_80338E24_unk_bin_38();
            break;
        case 2:
            func_80338E88_unk_bin_38();
            break;
        default: 
            break;
    }
}

void func_80339064_unk_bin_38(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s16 temp_t4;

    sp2C = func_80027464(3, &D_8011463C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2C != -1) {
        sp28 = (s32) gObjects[sp2C].unkE8[0];
        sp24 = (s32) gObjects[sp2C].unkE8[1];
        gObjects[sp2C].Scale.x = 5.0f;
        gObjects[sp2C].Scale.y = 5.0f;
        gObjects[sp2C].Scale.z = 5.0f;
        gObjects[sp28].Scale.x = 1.5f;
        gObjects[sp28].Scale.y = 1.5f;
        gObjects[sp28].Scale.z = 1.5f;
        gObjects[sp24].Scale.x = 1.5f;
        gObjects[sp24].Scale.y = 1.5f;
        gObjects[sp24].Scale.z = 1.5f;
    }
}

void func_803392D4_unk_bin_38(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk132 = 0;
        sp4->actionState = 2;
    } else if ((D_80177A64 == 1) && (sp4->damageState == 1)) {
        sp4->damageState = 0x32;
        sp4->unkB6 = (s16) (s32) sp4->Rot.z;
        sp4->unkB8 = 0;
        sp4->unkBA = 6;
    }
}

void func_803393C4_unk_bin_38(void) {
    struct ObjectStruct* sp5C;
    s32 pad[2];
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    f32 sp40;

    sp5C = &gObjects[gCurrentParsedObject];
    sp48 = gObjects[gCurrentParsedObject].unkE8[0];
    sp44 = (s32) gObjects[gCurrentParsedObject].unkE8[1];
    if (sp5C->unk132 == 0) {
        sp5C->unk132 += 1;
        sp5C->unkA6 = 0;
        sp5C->unkA8 = 0;
        sp5C->unkAC = 0;
        sp5C->unkAE = 0;
        sp5C->unkBC = 0xC8;
        sp5C->unkD4 = 0.0f;
        sp5C->unkD8 = 0.0f;
        sp5C->unk40 = 0.0f;
        sp5C->unk48 = 0.0f;
        sp5C->moveSpeed = 0.0f;
        sp5C->Rot.x = gObjects[sp48].Rot.x = gObjects[sp44].Rot.x = 340.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x89, &D_801182C4);
        func_8001C0EC(sp48, 0, 0, 0x99, &D_80117874);
        func_8001C0EC(sp44, 0, 0, 0x99, &D_80117874);
        func_8001BBDC(sp48, 1);
        func_8001BBDC(sp44, 1);
        func_80019448(gCurrentParsedObject, 2, 0, 1);
        func_80019448(sp48, 2, 0, 1);
        func_80019448(sp44, 2, 0, 1);
    }
    if (sp5C->damageState == 1) {
        sp4C = func_8002A640(gCurrentParsedObject, 1.0f);
        sp5C->Rot.y = Math_WrapAngle(sp5C->Rot.y, (f32) sp4C);
        sp5C->moveAngle = sp5C->Rot.y;
        if (sp5C->unkA8 != 0) {
            sp5C->unkA8 -= 1;
            if (sp5C->unkA8 < 0xA) {
                sp5C->unkD4 -= 1.0f;
            } else if (sp5C->unkD4 < 5.0f) {
                sp5C->unkD4 += 1.0f;
            }
            sp5C->Rot.x = Math_WrapAngle(sp5C->Rot.x, sp5C->unkD8 * 1.0f);
        }
        sp5C->unk48 = sp5C->unkD4;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001BB34(gCurrentParsedObject, 0);
        if (sp5C->unkAC != 0) {
            sp5C->unkAC -= 1;
            sp40 = gPlayerObject->Pos.z - sp5C->Pos.z;
            if ((sp40 < 1700.0f) && (sp40 > 60.0f)) {
                func_800175F0(gCurrentParsedObject, 0, 0x38, -1, 0);
                sp50 = func_80027464(1, &D_8011466C, (f32) Math_Random(-0x168) + sp5C->Pos.x,
                                     (f32) Math_Random(-0xB4) + sp5C->Pos.y, sp5C->Pos.z + 180.0f, sp5C->Rot.y);
                if (sp50 != -1) {
                    gObjects[sp50].Scale.x = gObjects[sp50].Scale.y = gObjects[sp50].Scale.z = 3.0f;
                    gObjects[sp50].moveAngle = Math_WrapAngle(sp5C->Rot.y, (f32) Math_Random(-0xA));
                    gObjects[sp50].unk40 = Math_WrapAngle(0.0f, (f32) Math_Random(-0xA));
                }
                if (gPlayerObject->Pos.z > (sp5C->Pos.z + 30.0f)) {
                    D_8016E3B0 = 2;
                    D_8016E3B8 = 0x1E;
                }
            }
        }
    } else {
        sp5C->unk48 = 0.0f;
        func_8001BBDC(gCurrentParsedObject, 1);
        if (sp5C->unkB8 == 0) {
            sp5C->Rot.z = Math_WrapAngle(sp5C->Rot.z, (f32) sp5C->unkBA);
        } else {
            sp5C->Rot.z = Math_WrapAngle(sp5C->Rot.z, (f32) -sp5C->unkBA);
        }
        sp5C->unkB8 += 1;
        if (sp5C->unkB8 == 2) {
            sp5C->unkB8 = 0;
        }
        sp5C->unkBA = 0xC;
        if (sp5C->damageState == 2) {
            sp5C->Rot.z = (f32) sp5C->unkB6;
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029A9C(gCurrentParsedObject, func_800297DC());
    }
    if (gObjects[gCurrentParsedObject].unkE8[0] != -1) {
        gObjects[sp48].moveAngle = sp5C->moveAngle;
        gObjects[sp48].Rot.x = sp5C->Rot.x;
        gObjects[sp48].Rot.y = sp5C->Rot.y;
        gObjects[sp48].Pos.x = sp5C->Pos.x + 120.0f;
        gObjects[sp48].Pos.y = sp5C->Pos.y;
        gObjects[sp48].Pos.z = sp5C->Pos.z + 180.0f;
    }
    if (gObjects[gCurrentParsedObject].unkE8[1] != -1) {
        gObjects[sp44].moveAngle = sp5C->moveAngle;
        gObjects[sp44].Rot.x = sp5C->Rot.x;
        gObjects[sp44].Rot.y = sp5C->Rot.y;
        gObjects[sp44].Pos.x = sp5C->Pos.x - 120.0f;
        gObjects[sp44].Pos.y = sp5C->Pos.y;
        gObjects[sp44].Pos.z = sp5C->Pos.z + 180.0f;
    }
    if (sp5C->unkBC != 0) {
        sp5C->unkBC -= 1;
        if (sp5C->unkBC == 0x64) {
            func_800281A4(gCurrentParsedObject, 0);
        } else if (sp5C->unkBC == 0) {
            func_800281A4(gCurrentParsedObject, 1);
        }
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 60.0f) {
        sp5C->unk40 = 90.0f;
        sp5C->unkD4 = 1.0f;
        sp5C->unkD8 = 1.0f;
        sp5C->unkA8 = 0x3C;
        sp5C->unkAC = 0xC;
    } else if (func_8001B62C(gCurrentParsedObject, 0) == 0.0f) {
        sp5C->unk40 = 270.0f;
        sp5C->unkD4 = 1.0f;
        sp5C->unkD8 = -1.0f;
        sp5C->unkA8 = 0x3C;
    }
}

void func_8033A010_unk_bin_38(void) {
    func_8002B0E4(gCurrentParsedObject);
    func_800175F0(gCurrentParsedObject, 0, 0x67, -1, 0);
}

void func_8033A05C_unk_bin_38(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_803393C4_unk_bin_38();
            break;
        case 2:
            func_8033A010_unk_bin_38();
            break;
        default:
            break;
    }
}

void func_8033A0F0_unk_bin_38(void) {
}

void func_8033A100_unk_bin_38(void) {
    struct ObjectStruct* sp34;
    s32 pad[2];

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->moveSpeed = 14.0f;
        sp34->unk48 = 5.0f;
        sp34->unkB6 = Math_Random(0xA) + 0x28;
    }
    sp34->Scale.x = (f32) ((f64) sp34->Scale.x + 0.05);
    sp34->Scale.y = (f32) ((f64) sp34->Scale.y + 0.05);
    sp34->Scale.z = (f32) ((f64) sp34->Scale.z + 0.05);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
        sp34->actionState = 2;
        sp34->unk132 = 0;
    } else if (sp34->unkB6 == 0) {
        sp34->actionState = 2;
        sp34->unk132 = 0;
    } else {
        sp34->unkB6 -= 1;
    }
}

void func_8033A310_unk_bin_38(void) {
    func_8002B114(gCurrentParsedObject);
}

void func_8033A340_unk_bin_38(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
            case 1:
                func_8033A100_unk_bin_38();
                break;
            case 2:
                func_8033A310_unk_bin_38();
                break;
            default:
                break;
        }
    }
}

void func_8033A408_unk_bin_38(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 1) {
        sp4->actionState = 2;
        sp4->unk132 = 0;
    }
    if (D_80177A64 == 2) {
        sp4->actionState = 2;
        sp4->unk132 = 0;
    }
}

void func_8033A4A0_unk_bin_38(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp24;
    f32 sp20;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->moveSpeed = 12.0f;
        sp34->moveAngle = sp34->Rot.y;
        sp34->unkA8 = 0xF;
        func_80019448(gCurrentParsedObject, 2, 0, 1);
    }
    sp30 = 0;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp30 = 1;
    }
    if (sp34->unkA8 == 0) {
        sp20 = Math_CalcAngleRotated(gPlayerObject->Pos.x - sp34->Pos.x, gPlayerObject->Pos.z - sp34->Pos.z);
        sp24 = func_800157EC(sp34->moveAngle, sp20, 2.0f);
        sp34->moveAngle = Math_WrapAngle(sp34->moveAngle, (f32) ((f64) sp24 * 0.5));
        sp20 = Math_CalcAngleSimple(gPlayerObject->Pos.x - sp34->Pos.x, gPlayerObject->Pos.y - sp34->Pos.y);
        sp20 = Math_NormalizeAngle(sp20);
        sp24 = func_800157EC(sp34->unk40, sp20, 2.0f);
        sp34->unk40 = Math_WrapAngle(sp34->unk40, (f32) sp24);
    } else {
        sp34->unkA8 -= 1;
    }
    sp34->Rot.y = sp34->moveAngle;
    sp34->Rot.x = Math_WrapAngle(360.0f, -sp34->unk40);
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp30 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp2C, 0.0f, -30.0f, 0.0f) != 0) {
        sp30 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp2C, 0.0f, 30.0f, 0.0f) != 0) {
        sp30 = 1;
    }
    if (sp30 != 0) {
        sp34->actionState = 2;
        sp34->unk132 = 0;
    }
}

void func_8033A7C4_unk_bin_38(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_8033A7F4_unk_bin_38(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
            case 1:
                func_8033A4A0_unk_bin_38();
                break;
            case 2:
                func_8033A7C4_unk_bin_38();
                break;
            default:
                break;
        }
    }
}

void func_8033A8BC_unk_bin_38(void) {
    func_80027464(1, &D_80114660, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_8033A934_unk_bin_38(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 0x64;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_8033A9AC_unk_bin_38(struct ObjectStruct* arg0) {
    s32 sp34;
    f32 sp30;
    f32 sp2C;

    if (arg0->unk132 == 0) {
        arg0->unk132 += 1;
        arg0->moveSpeed = 5.0f;
    }
    sp34 = 0;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp34 = 1;
    }
    arg0->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 45.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp34 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp30, &sp2C, 0.0f, 0.0f, 0.0f) != 0) {
        arg0->Pos.y = sp2C;
    } else {
        arg0->Pos.y = sp30;
    }
    if (sp34 != 0) {
        arg0->actionState = 2;
        arg0->unk132 = 0;
        return;
    }
    arg0->Rot.y = arg0->moveAngle;
}

void func_8033AB54_unk_bin_38(struct ObjectStruct* arg0) {
    s32 sp24;

    if (arg0->unk132 == 0) {
        arg0->unk132 += 1;
        arg0->Vel.z = 0.0f;
        arg0->Vel.x = arg0->Vel.y = arg0->Vel.z;
    }
    sp24 = func_8002A800(arg0->Rot.y, arg0->moveAngle, 2.0f);
    if (sp24 == 0) {
        arg0->Rot.y = arg0->moveAngle;
        arg0->actionState = 1;
        arg0->unk132 = 0;
        return;
    } else {
        arg0->Rot.y = Math_WrapAngle(arg0->Rot.y, (f32) (sp24 * 2));
    }
}

void func_8033AC74_unk_bin_38(struct ObjectStruct* arg0) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_8033ACA8_unk_bin_38(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->actionState) { /* irregular */
        case 0x1:
            func_8033A9AC_unk_bin_38(sp24);
            break;
        case 0x2:
            func_8033AB54_unk_bin_38(sp24);
            break;
        case 0x64:
            func_8033AC74_unk_bin_38(sp24);
            break;
    }
}
