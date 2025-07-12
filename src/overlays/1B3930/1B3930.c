#include "common.h"

void func_803316CC_unk_bin_23(); /* static */
extern u32 D_8011A210;
extern struct UnkStruct8016C298_1 D_8011A298;
extern u32 D_8011BCF0;
extern u32 D_8011BCFC;
static struct ObjSpawnInfo D_80333270_unk_bin_23 = { 0, OBJ_BOLB_AW, 0x163, 1, -1, 0, 0, 0 };
static struct ObjSpawnInfo D_8033327C_unk_bin_23 = { 0, OBJ_BOLB_MS, 0x165, 1, 1, 1, 1, 0 };
static struct ObjSpawnInfo D_80333288_unk_bin_23[1] = { 0, OBJ_BOLB_AM, 0x162, 1, 1, 1, 1, 0 };
static struct ObjSpawnInfo D_80333294_unk_bin_23[2] = { { 0, OBJ_BOLB_BD2, 0xD3, 0xA, 8, 1, 1, 0 },
                                                        { 0, OBJ_BOLB_HB, 0x164, 1, -1, -1, 1, 1 } };

void func_80330000_unk_bin_23(void) {
    s32 sp24;

    sp24 = func_80027464(2, D_80333294_unk_bin_23, (f32) D_80165100->unk2, (f32) D_80165100->unk4,
                         (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_8011A298);
    gObjects[sp24].unkA6 = 8;
    gObjects[sp24].unkAA = 3;
}

void func_803300E4_unk_bin_23(void) {
    struct ObjectStruct* sp1C;
    struct ObjectStruct* temp_t8;

    sp1C = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp1C->damageState = 0;
        func_80069E60(0, 1, 0x12C);
        gObjects[sp1C->unkE8[0]].damageState = 0;
        sp1C->actionState = 7;
        sp1C->unk132 = 0;
        sp1C->Vel.z = 0.0f;
        sp1C->Vel.x = sp1C->Vel.z;
        sp1C->moveSpeed = 0.0f;
        gObjects[sp1C->unkE8[0]].Vel.x = gObjects[sp1C->unkE8[0]].Vel.z = 0.0f;
        gObjects[sp1C->unkE8[0]].moveSpeed = 0.0f;
        func_8001BBDC(gCurrentParsedObject, 1);
    } else if (D_80177A64 == 1) {
        sp1C->damageState = 0x78;
    }
}

void func_8033029C_unk_bin_23(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x12, 0xD3, &D_8011A210);
        if (sp24->unk100 >= 7) {
            sp24->unkA8 = 3;
        } else {
            sp24->unkA8 = 1;
        }
    }
    func_803316CC_unk_bin_23();
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp24->unkA8 == 0) {
            if (sp24->unkAA == 0) {
                sp24->actionState = 4;
                sp24->unk132 = 0;
                if (sp24->unk100 >= 7) {
                    sp24->unkAA = 3;
                } else {
                    sp24->unkAA = 1;
                }
            } else {
                sp24->unkAA -= 1;
                sp24->actionState = 2;
                sp24->unk132 = 0;
            }
        } else {
            sp24->unkA8 -= 1;
        }
    }
}

void func_80330480_unk_bin_23(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0xD3, &D_8011A210);
        if (sp24->unkB6 == 0) {
            sp24->unkB6 = 3;
        }
    }
    func_803316CC_unk_bin_23();
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 3;
        sp24->unk132 = 0;
    }
}

void func_80330590_unk_bin_23(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0xD3, &D_8011A210);
        sp28 = sp34->Pos.y + 350.0f;
        sp20 = Math_WrapAngle(sp34->Rot.y, 18.0f);
        sp2C = (sinf((f32) ((f64) sp20 * 0.017453292519943295)) * 402.0f) + sp34->Pos.x;
        sp24 = (cosf((f32) ((f64) sp20 * 0.017453292519943295)) * 402.0f) + sp34->Pos.z;
        sp30 = func_80027464(1, &D_8033327C_unk_bin_23, sp2C, sp28, sp24, sp20);
        func_80019448(sp30, 2, 0, 1);
        gObjects[sp30].unkC2 = (s16) gCurrentParsedObject;
        func_80026F10(gCurrentParsedObject, sp30);
        sp20 = Math_WrapAngle(sp34->Rot.y, -18.0f);
        sp2C = (sinf((f32) ((f64) sp20 * 0.017453292519943295)) * 420.0f) + sp34->Pos.x;
        sp24 = (cosf((f32) ((f64) sp20 * 0.017453292519943295)) * 420.0f) + sp34->Pos.z;
        sp30 = func_80027464(1, &D_8033327C_unk_bin_23, sp2C, sp28, sp24, sp20);
        func_80019448(sp30, 2, 0, 1);
        gObjects[sp30].unkC2 = (s16) gCurrentParsedObject;
        func_80026F10(gCurrentParsedObject, sp30);
        func_800175F0(sp30, 0, 0x42, -1, 0);
    }
    func_803316CC_unk_bin_23();
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp34->unkB6 < 2) {
            sp34->unkB6 = 0;
            sp34->actionState = 1;
            sp34->unk132 = 0;
        } else {
            sp34->unkB6 -= 1;
            sp34->actionState = 2;
            sp34->unk132 = 0;
        }
    }
}

void func_80330940_unk_bin_23(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xA, 0xD3, &D_8011A210);
    }
    func_803316CC_unk_bin_23();
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 5;
        sp24->unk132 = 0;
    }
}

void func_80330A2C_unk_bin_23(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;
    s32 pad34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    UNUSED s32 pad[2];

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unkB2 = sp3C->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0xD3, &D_8011A210);
        if (sp3C->unk100 >= 4) {
            sp30 = sp3C->Pos.x;
            sp2C = sp3C->Pos.y + 420.0f;
            sp28 = sp3C->Pos.z + 300.0f;
            sp38 = func_80027464(1, D_80333288_unk_bin_23, sp30, sp2C, sp28, 0.0f);
            gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
            gObjects[sp38].unkC0 = 1;
            sp30 = sp3C->Pos.x + 120.0f;
            sp2C = sp3C->Pos.y + 120.0f;
            sp28 = sp3C->Pos.z + 300.0f;
            sp38 = func_80027464(1, D_80333288_unk_bin_23, sp30, sp2C, sp28, 0.0f);
            gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
            gObjects[sp38].unkC0 = 2;
            sp30 = sp3C->Pos.x - 120.0f;
            sp2C = sp3C->Pos.y + 120.0f;
            sp28 = sp3C->Pos.z + 300.0f;
            sp38 = func_80027464(1, D_80333288_unk_bin_23, sp30, sp2C, sp28, 0.0f);
            gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
            gObjects[sp38].unkC0 = 3;
        } else {
            sp30 = sp3C->Pos.x;
            sp2C = sp3C->Pos.y + 420.0f;
            sp28 = sp3C->Pos.z;
            sp38 = func_80027464(1, D_80333288_unk_bin_23, sp30, sp2C, sp28, 0.0f);
            gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
            gObjects[sp38].unkC0 = 1;
            sp30 = sp3C->Pos.x + 120.0f;
            sp2C = sp3C->Pos.y + 120.0f;
            sp28 = sp3C->Pos.z + 300.0f;
            sp38 = func_80027464(1, D_80333288_unk_bin_23, sp30, sp2C, sp28, 0.0f);
            gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
            gObjects[sp38].unkC0 = 2;
            sp30 = sp3C->Pos.x - 120.0f;
            sp2C = sp3C->Pos.y + 120.0f;
            sp28 = sp3C->Pos.z + 300.0f;
            sp38 = func_80027464(1, D_80333288_unk_bin_23, sp30, sp2C, sp28, 0.0f);
            gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
            gObjects[sp38].unkC0 = 3;
            sp30 = sp3C->Pos.x + 180.0f;
            sp2C = sp3C->Pos.y + 270.0f;
            sp28 = sp3C->Pos.z + 240.0f;
            sp38 = func_80027464(1, D_80333288_unk_bin_23, sp30, sp2C, sp28, 0.0f);
            gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
            gObjects[sp38].unkC0 = 4;
            sp30 = sp3C->Pos.x - 180.0f;
            sp2C = sp3C->Pos.y + 270.0f;
            sp28 = sp3C->Pos.z + 240.0f;
            sp38 = func_80027464(1, D_80333288_unk_bin_23, sp30, sp2C, sp28, 0.0f);
            gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
            gObjects[sp38].unkC0 = 5;
            sp30 = sp3C->Pos.x;
            sp2C = sp3C->Pos.y + 270.0f;
            sp28 = sp3C->Pos.z + 300.0f;
            sp38 = func_80027464(1, D_80333288_unk_bin_23, sp30, sp2C, sp28, 0.0f);
            gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
            gObjects[sp38].unkC0 = 6;
        }
        func_800175F0(gCurrentParsedObject, 0, 0x1D, -1, 0);
    }
    func_803316CC_unk_bin_23();
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp3C->actionState = 6;
        sp3C->unk132 = 0;
    }
}

void func_803312A8_unk_bin_23(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xC, 0xD3, &D_8011A210);
    }
    func_803316CC_unk_bin_23();
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 1;
        sp24->unk132 = 0;
    }
}

void func_80331394_unk_bin_23(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        sp24->unkA6 = 0x3C;
        func_80069E60(0, 1, 0x82);
    }
    if (sp24->unkA6 == 0x1E) {
        sp24->unkA6 -= 1;
        func_8007F070(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 5.0f);
    } else if (sp24->unkA6 == 0) {
        func_8001BB34(gCurrentParsedObject, 1);
        func_8001BB34((s32) sp24->unkE8[0], 1);
        if (sp24->unk132 == 1) {
            func_800175F0(gCurrentParsedObject, 0, 0x67, -1, 0);
            sp24->unk132 += 1;
        }
    } else {
        sp24->unkA6 -= 1;
    }
}

void func_8033153C_unk_bin_23(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->damageState == 0) {
        func_8001BB34(gCurrentParsedObject, 0);
    } else {
        func_8001BB34(gCurrentParsedObject, !(sp24->damageState & 1));
        if (sp24->damageState == 1) {
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011A298);
        }
    }
    switch (sp24->actionState) {
        case 1:
            func_8033029C_unk_bin_23();
            break;
        case 2:
            func_80330480_unk_bin_23();
            break;
        case 3:
            func_80330590_unk_bin_23();
            break;
        case 4:
            func_80330940_unk_bin_23();
            break;
        case 5:
            func_80330A2C_unk_bin_23();
            break;
        case 6:
            func_803312A8_unk_bin_23();
            break;
        case 7:
            func_80331394_unk_bin_23();
            break;
        default:
            break;
    }
}

void func_803316CC_unk_bin_23(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->Pos.z <= -4800.0f) {
        if ((gPlayerObject->Pos.z - sp24->Pos.z) < 780.0f) {
            sp24->unkA8 = 0;
            sp24->moveSpeed = 0.0f;
        } else if ((gPlayerObject->Pos.z - sp24->Pos.z) < 900.0f) {
            if ((f64) sp24->moveSpeed < -0.5) {
                sp24->moveSpeed = (f32) ((f64) sp24->moveSpeed + 0.5);
            } else if ((f64) sp24->moveSpeed > 0.5) {
                sp24->moveSpeed = (f32) ((f64) sp24->moveSpeed - 0.5);
            } else {
                sp24->moveSpeed = 0.0f;
            }
        } else if (sp24->moveSpeed >= 10.0f) {
            sp24->moveSpeed = 10.0f;
        } else {
            sp24->moveSpeed = (f32) ((f64) sp24->moveSpeed + 0.5);
        }
    } else if ((gPlayerObject->Pos.z - sp24->Pos.z) < 780.0f) {
        if (sp24->unkA6 == 0) {
            sp20 =
                func_80027464(1, &D_80333270_unk_bin_23, sp24->Pos.x + 50.0f, sp24->Pos.y + 10.0f, sp24->Pos.z, 0.0f);
            sp20 = func_80027464(1, &D_80333270_unk_bin_23, sp24->Pos.x - 35.0f, sp24->Pos.y - 10.0f,
                                 sp24->Pos.z + 10.0f, 0.0f);
            sp24->unkA6 = 0x10;
        } else if (sp24->unkA6 == 8) {
            sp20 =
                func_80027464(1, &D_80333270_unk_bin_23, sp24->Pos.x - 50.0f, sp24->Pos.y + 10.0f, sp24->Pos.z, 0.0f);
            sp20 = func_80027464(1, &D_80333270_unk_bin_23, sp24->Pos.x + 35.0f, sp24->Pos.y - 10.0f,
                                 sp24->Pos.z + 10.0f, 0.0f);
            sp24->unkA6 -= 1;
        } else {
            sp24->unkA6 -= 1;
        }
        if (sp24->moveSpeed <= -10.0f) {
            sp24->moveSpeed = -10.0f;
        } else {
            sp24->moveSpeed = (f32) ((f64) sp24->moveSpeed - 0.5);
        }
    } else if ((gPlayerObject->Pos.z - sp24->Pos.z) < 900.0f) {
        if ((f64) sp24->moveSpeed < -0.5) {
            sp24->moveSpeed = (f32) ((f64) sp24->moveSpeed + 0.5);
        } else if ((f64) sp24->moveSpeed > 0.5) {
            sp24->moveSpeed = (f32) ((f64) sp24->moveSpeed - 0.5);
        } else {
            sp24->moveSpeed = 0.0f;
        }
    } else if (sp24->moveSpeed >= 10.0f) {
        sp24->moveSpeed = 10.0f;
    } else {
        sp24->moveSpeed = (f32) ((f64) sp24->moveSpeed + 0.5);
    }
    func_80029C40(gCurrentParsedObject);
    gObjects[sp24->unkE8[0]].Vel.x = sp24->Vel.x;
    gObjects[sp24->unkE8[0]].Vel.y = sp24->Vel.y;
    gObjects[sp24->unkE8[0]].Vel.z = sp24->Vel.z;
}

void func_80331D04_unk_bin_23(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x163, &D_8011BCFC);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_80331DE0_unk_bin_23(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80331E10_unk_bin_23(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        sp34->Rot.y = gObjects[sp34->unkC2].Rot.y;
        sp34->moveAngle = sp34->Rot.y;
        if (gObjects[sp34->unkC2].moveSpeed >= 0.0f) {
            sp34->moveSpeed = 20.0f;
            sp34->unkA6 = Math_Random(5) + 3;
        } else {
            sp34->moveSpeed = 6.0f;
            sp34->unkA6 = 0;
        }
        sp34->unk40 = 12.0f;
        sp34->unkB4 = 0x3C;
    }
    if ((gObjects[sp34->unkC2].moveSpeed < 0.0f)) {
        if (((sp34->Pos.z - gPlayerObject->Pos.z) > 60.0f)) {
            sp34->moveSpeed = 15.0f;
        }
    }
    if (sp34->unkA6 == 0) {
        sp30 = Math_CalcAngleSimple(gPlayerObject->Pos.x - sp34->Pos.x, gPlayerObject->Pos.y - sp34->Pos.y);
        sp30 = Math_NormalizeAngle(sp30);
        sp2C = (f32) func_8002A800(sp34->unk40, sp30, 2.0f);
        if (sp2C != 0.0f) {
            sp34->unk40 = Math_WrapAngle(sp34->unk40, 4.0f * sp2C);
        }
        sp34->Rot.y = sp34->moveAngle;
        sp34->Rot.x = 360.0f - sp34->unk40;
        if (sp34->Rot.x >= 360.0f) {
            sp34->Rot.x -= 360.0f;
        }
        if (gObjects[sp34->unkC2].moveSpeed >= 0.0f) {
            func_8002A8B4(gCurrentParsedObject, 3.0f);
        } else {
            func_8002A8B4(gCurrentParsedObject, 6.0f);
        }
        sp34->Rot.y = sp34->moveAngle;
    } else {
        sp34->unkA6 -= 1;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_8007EDF4(sp34->Pos.x, sp34->Pos.y, sp34->Pos.z, 1.0f);
        func_8002B114(gCurrentParsedObject);
        return;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, -30.0f, 0.0f) != 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp34->Pos.x, sp34->Pos.y, sp34->Pos.z, 1.0f);
        func_8002B114(gCurrentParsedObject);
        return;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, 30.0f, 0.0f) != 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp34->Pos.x, sp34->Pos.y, sp34->Pos.z, 1.0f);
        func_8002B114(gCurrentParsedObject);
        return;
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp34->Pos.x, sp34->Pos.y, sp34->Pos.z, 1.0f);
        func_8002B114(gCurrentParsedObject);
        return;
    }
    if (sp34->unkB4 == 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp34->Pos.x, sp34->Pos.y, sp34->Pos.z, 1.0f);
        func_8002B114(gCurrentParsedObject);
        return;
    } else {
        sp34->unkB4 -= 1;
    }
}

void func_80332448_unk_bin_23(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->actionState == 1) {
        if (FALSE)
            ;
        func_80331E10_unk_bin_23();
    } else {
        if (FALSE)
            ;
    }
}

void func_803324CC_unk_bin_23(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_803324FC_unk_bin_23(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x162, &D_8011BCF0);
        sp2C->moveSpeed = 24.0f;
        sp2C->unkA6 = 0xC;
        switch (sp2C->unkC0) {
            case 5:
                sp2C->moveAngle = 300.0f;
                break;
            case 4:
                sp2C->moveAngle = 60.0f;
                break;
            case 3:
                sp2C->moveAngle = 330.0f;
                break;
            case 2:
                sp2C->moveAngle = 30.0f;
                break;
            case 1:
                sp2C->moveAngle = 0.0f;
                break;
            default:
                sp2C->moveAngle = 0.0f;
                break;
        }
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, -30.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, 30.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (sp2C->unkA6 == 0) {
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
        sp2C->moveSpeed = 0.0f;
    } else {
        sp2C->moveSpeed -= 2.0f;
        sp2C->unkA6 -= 1;
    }
}

void func_80332810_unk_bin_23(void) {
    struct ObjectStruct* sp34;
    s16 sp32;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        sp34->unkA6 = 2;
    }
    sp24 = Math_CalcAngleSimple(gPlayerObject->Pos.x - sp34->Pos.x, gPlayerObject->Pos.y - sp34->Pos.y);
    sp24 = Math_NormalizeAngle(sp24);
    sp20 = (f32) func_8002A800(sp34->unk40, sp24, 3.0f);
    if (sp20 != 0.0f) {
        sp34->unk40 = Math_WrapAngle(sp34->unk40, 1.0f * sp20);
    }
    func_8002A8B4(gCurrentParsedObject, 2.0f);
    sp34->Rot.y = sp34->moveAngle;
    sp32 = Math_Random(-0xA);
    sp34->moveSpeed = (f32) (sp32 + 0x14) / 10.0f;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp2C, 0.0f, -30.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp2C, 0.0f, 30.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp34->unkA6 == 0) {
            sp34->actionState = 3;
            sp34->unk132 = 0;
        } else {
            sp34->unkA6 -= 1;
        }
    }
}

void func_80332B20_unk_bin_23(void) {
    struct ObjectStruct* sp34;
    s16 sp32;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x162, &D_8011BCF0);
        sp34->unkA6 = 2;
    }
    sp24 = Math_CalcAngleSimple(gPlayerObject->Pos.x - sp34->Pos.x, gPlayerObject->Pos.y - sp34->Pos.y);
    sp24 = Math_NormalizeAngle(sp24);
    sp20 = (f32) func_8002A800(sp34->unk40, sp24, 3.0f);
    if (sp20 != 0.0f) {
        sp34->unk40 = Math_WrapAngle(sp34->unk40, 1.0f * sp20);
    }
    func_8002A8B4(gCurrentParsedObject, 2.0f);
    sp34->Rot.y = sp34->moveAngle;
    sp32 = Math_Random(-0xA);
    sp34->moveSpeed = (f32) (sp32 + 0x14) / 10.0f;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp2C, 0.0f, -30.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp2C, 0.0f, 30.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp34->unkA6 == 0) {
            sp34->actionState = 4;
            sp34->unk132 = 0;
        } else {
            sp34->unkA6 -= 1;
        }
    }
}

void func_80332E54_unk_bin_23(void) {
    struct ObjectStruct* sp34;
    s16 sp32;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x162, &D_8011BCF0);
        sp34->unkA6 = 2;
    }
    sp24 = Math_CalcAngleSimple(gPlayerObject->Pos.x - sp34->Pos.x, gPlayerObject->Pos.y - sp34->Pos.y);
    sp24 = Math_NormalizeAngle(sp24);
    sp20 = (f32) func_8002A800(sp34->unk40, sp24, 3.0f);
    if (sp20 != 0.0f) {
        sp34->unk40 = Math_WrapAngle(sp34->unk40, 1.0f * sp20);
    }
    func_8002A8B4(gCurrentParsedObject, 2.0f);
    sp34->Rot.y = sp34->moveAngle;
    sp32 = Math_Random(-0xA);
    sp34->moveSpeed = (f32) (sp32 + 0x14) / 10.0f;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp2C, 0.0f, -30.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp2C, 0.0f, 30.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp34->unkA6 == 0) {
            func_8002B0E4(gCurrentParsedObject);
        } else {
            sp34->unkA6 -= 1;
        }
    }
}

void func_80333188_unk_bin_23(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->actionState) { /* irregular */
        case 1:
            func_803324FC_unk_bin_23();
            break;
        case 2:
            func_80332810_unk_bin_23();
            break;
        case 3:
            func_80332B20_unk_bin_23();
            break;
        case 4:
            func_80332E54_unk_bin_23();
            break;
        default:
            break;
    }
}
