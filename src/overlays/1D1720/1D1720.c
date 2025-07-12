#include "common.h"

s8 func_80333FC4_unk_bin_37(s8 arg0);   /* static */
s8 func_80334534_unk_bin_37();          /* static */
s16 func_803345DC_unk_bin_37(s16 arg0); /* static */
extern struct ObjSpawnInfo D_801136C4;
extern struct ObjSpawnInfo D_80113B74;
extern struct ObjSpawnInfo D_80113BA4;
extern struct ObjSpawnInfo D_80113C28;
extern struct ObjSpawnInfo D_80113E08;
extern struct ObjSpawnInfo D_80113E20;
extern struct ObjSpawnInfo D_80113E2C;
extern struct ObjSpawnInfo D_80113E38;
extern struct ObjSpawnInfo D_80113E44;
extern struct ObjSpawnInfo D_80114048;
extern struct ObjSpawnInfo D_80114054;
extern struct ObjSpawnInfo D_80114060;
extern struct ObjSpawnInfo D_8011460C;
extern struct ObjSpawnInfo D_80114618;
extern struct UnkStruct8016C298_1 D_80117424;
extern struct UnkStruct8016C298_1 D_80117440;
extern u32 D_80117478;
extern u32 D_80117484;
extern u32 D_80117488;
extern u32 D_8011748C;
extern u32 D_801182CC;
extern u32 D_80118B54;

s8 func_80330000_unk_bin_37(s8 arg0) {
    struct ObjectStruct* sp24;
    struct ObjectStruct* sp20;
    s8 sp1F;

    sp24 = &gObjects[gCurrentParsedObject];
    sp1F = (s8) sp24->unkE8[arg0];
    if ((sp1F != -1)) {
        sp20 = &gObjects[sp1F];

        if (((sp20->interactingObjIdx != -1)) || (sp20->unk100 == 0)) {
            func_800281A4(gCurrentParsedObject, (s32) arg0);
            sp20->damageState = 0;
            sp20->actionState = 2;
            sp20->unk132 = 0;
            sp24->unkAA = -1;
        }
    }
    return sp1F;
}

void func_8033011C_unk_bin_37(void) {
    struct ObjectStruct* sp1C;
    s8 sp1B;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unkAA == -1) {
        sp1B = (s8) sp1C->unkE8[0];
        if (sp1B != -1) {
            func_8001ABF4((s32) sp1B, 0, 0, &D_80117424);
        }
        sp1B = (s8) sp1C->unkE8[1];
        if (sp1B != -1) {
            func_8001ABF4((s32) sp1B, 0, 0, &D_80117424);
        }
        sp1B = (s8) sp1C->unkE8[2];
        if (sp1B != -1) {
            func_800281A4(gCurrentParsedObject, 2);
            gObjects[sp1B].actionState = 3;
            gObjects[sp1B].unk132 = 0;
            gObjects[sp1B].damageState = 0;
        }
        sp1C->unkAA = -2;
    }
}

s8 func_803302A8_unk_bin_37(s8 arg0) {
    struct ObjectStruct* sp24;
    struct ObjectStruct* sp20;
    s8 sp1F;
    s8 sp1E;

    sp1E = 0;
    sp24 = &gObjects[gCurrentParsedObject];
    sp1F = (s8) sp24->unkE8[arg0];
    if (sp1F != -1) {
        sp20 = &gObjects[sp1F];
        sp20->Pos.x = sp24->Pos.x + (f32) sp20->unkAA;
        sp20->Pos.y = sp24->Pos.y + (f32) sp20->unkAC;
        sp20->Pos.z = sp24->Pos.z;
        sp20->moveAngle = sp24->moveAngle;
        sp20->unk40 = sp24->unk40;
        if (sp24->Rot.y == 0.0f) {
            sp20->Rot.y = (f32) sp20->unkAE;
            if (arg0 != 2) {
                sp20->Rot.x = Math_WrapAngle(sp20->Rot.x, 4.0f);
            }
        } else {
            sp20->Rot.x = (f32) sp20->unkAE;
            if (arg0 != 2) {
                sp20->Rot.z = Math_WrapAngle(sp20->Rot.z, 4.0f);
            }
        }
        sp1E = 1;
        func_80029C40((s32) sp1F);
        func_80029D04((s32) sp1F);
    }
    return sp1E;
}

s8 func_803304D0_unk_bin_37(void) {
    s8 sp27;

    sp27 = 0;
    sp27 += func_803302A8_unk_bin_37(0);
    sp27 += func_803302A8_unk_bin_37(1);
    sp27 += func_803302A8_unk_bin_37(2);
    func_8033011C_unk_bin_37();
    return sp27;
}

void func_8033056C_unk_bin_37(void) {
    s16 sp2E;
    s16 sp2C;
    s16 sp2A;
    s16 sp28;
    f32 sp24;
    f32 sp20;

    sp2E = func_80027464(4, &D_80113B74, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].actionState = 8;
        gObjects[sp2E].unkA8 = 1;
        gObjects[sp2E].unkAA = 0;
        gObjects[sp2E].Rot.y = 90.0f;
        gObjects[sp2E].damageState = 0;
        gObjects[sp2E].unk100 = -1;
        gObjects[sp2E].unk102 = 0;
        gObjects[sp2E].unk103 = 1;
        gObjects[sp2E].unk132 = 0;
        func_8001BB34((s32) sp2E, 1);
        sp2C = gObjects[sp2E].unkE8[0];
        sp2A = gObjects[sp2E].unkE8[1];
        sp28 = gObjects[sp2E].unkE8[2];
        gObjects[sp2C].actionState = 1;
        gObjects[sp2C].unk132 = 0;
        gObjects[sp2C].unkA8 = 0;
        gObjects[sp2C].damageState = 1;
        gObjects[sp2A].actionState = 1;
        gObjects[sp2A].unk132 = 0;
        gObjects[sp2A].unkA8 = 1;
        gObjects[sp2A].damageState = 1;
        gObjects[sp28].actionState = 1;
        gObjects[sp28].unk132 = 0;
        gObjects[sp28].unkA8 = 2;
        gObjects[sp28].damageState = -1;
        gObjects[sp28].unk100 = -1;
        func_8001ABF4((s32) sp2C, 0, 0, &D_80117424);
        func_8001ABF4((s32) sp2A, 0, 0, &D_80117424);
        func_8001BBDC((s32) sp28, 1);
        gObjects[sp2E].unkAC = 0x1E0;
        if (D_80165100->unkE != 0) {
            gObjects[sp2E].unkAC = D_80165100->unkE * 0x3C;
        }
        sp20 = 1.0f;
        if (D_80165100->unkC != 0) {
            sp20 = (f32) D_80165100->unkC / 10.0f;
        }
        if (D_80165100->unkA == 0) {
            gObjects[sp2E].Rot.y = 0.0f;
            gObjects[sp28].Scale.x = sp20;
            sp24 = (gObjects[sp28].Scale.x * 960.0f) / 2.0f;
            gObjects[sp2C].unkAA = (s16) (s32) ((150.0f + sp24) * -1.0f);
            gObjects[sp2C].unkAC = 0;
            gObjects[sp2C].unkAE = 0x5A;
            gObjects[sp2A].unkAA = (s16) (s32) (150.0f + sp24);
            gObjects[sp2A].unkAC = 0;
            gObjects[sp2A].unkAE = 0x10E;
            gObjects[sp28].unkAA = (s16) (s32) (gObjects[sp28].Scale.x * 120.0f);
            gObjects[sp28].unkAC = 0;
            gObjects[sp28].unkAE = 0x10E;
        } else {
            gObjects[sp2E].Rot.y = 180.0f;
            gObjects[sp28].Scale.y = sp20;
            sp24 = (gObjects[sp28].Scale.y * 960.0f) / 2.0f;
            gObjects[sp2C].unkAA = 0;
            gObjects[sp2C].unkAC = (s16) (s32) ((150.0f + sp24) * -1.0f);
            gObjects[sp2C].unkAE = 0x10E;
            gObjects[sp2A].unkAA = 0;
            gObjects[sp2A].unkAC = (s16) (s32) (150.0f + sp24);
            gObjects[sp2A].unkAE = 0x5A;
            gObjects[sp28].unkAA = 0;
            gObjects[sp28].unkAC = (s16) (s32) (gObjects[sp28].Scale.y * 120.0f);
            gObjects[sp28].unkAE = 0x5A;
        }
    }
}

void func_80331024_unk_bin_37(void) {
    s8 sp1F;

    sp1F = func_80330000_unk_bin_37(0);
    sp1F = func_80330000_unk_bin_37(1);
    func_8033011C_unk_bin_37();
}

void func_80331064_unk_bin_37(void) {
    struct ObjectStruct* sp1C;
    s8 sp1B;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->moveSpeed = 8.0f;
        sp1C->moveAngle = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8002A2EC(gCurrentParsedObject, 1800.0f) != 0) {
        sp1C->actionState = 2;
        sp1C->unk132 = 0;
    }
    sp1B = func_803304D0_unk_bin_37();
    if (sp1B == 0) {
        sp1C->actionState = 5;
        sp1C->unk132 = 0;
    }
}

void func_8033117C_unk_bin_37(void) {
    struct ObjectStruct* sp1C;
    s8 sp1B;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->moveSpeed = 8.0f;
        sp1C->moveAngle = Math_WrapAngle(360.0f, (f32) (sp1C->unkA8 * 0x5A));
        sp1C->unkA6 = 0x1E0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkA6 -= 8;
    if (sp1C->unkA6 <= 0) {
        sp1C->actionState = 1;
        sp1C->unk132 = 0;
        sp1C->unkA8 = -sp1C->unkA8;
        sp1C->actionState = 2;
        sp1C->unk132 = 0;
    }
    sp1B = func_803304D0_unk_bin_37();
    if (sp1B == 0) {
        sp1C->actionState = 5;
        sp1C->unk132 = 0;
    }
}

void func_8033131C_unk_bin_37(void) {
    struct ObjectStruct* sp24;
    struct ObjectStruct* sp20;
    s8 sp1F;

    sp24 = &gObjects[gCurrentParsedObject];
    sp1F = (s8) sp24->unkE8[0];
    if (sp1F != -1) {
        func_8001ABF4((s32) sp1F, 0, 0, &D_80117440);
    }
    sp1F = (s8) sp24->unkE8[1];
    if (sp1F != -1) {
        func_8001ABF4((s32) sp1F, 0, 0, &D_80117440);
    }
    sp1F = (s8) sp24->unkE8[2];
    if (sp1F != -1) {
        sp20 = &gObjects[sp1F];
        sp20->actionState = 2;
        sp20->unk132 = 0;
    }
    sp24->actionState = 3;
    sp24->unk132 = 0;
}

void func_8033145C_unk_bin_37(void) {
    struct ObjectStruct* sp1C;
    s8 sp1B;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unkA6 = sp1C->unkAC;
        if (sp1C->Rot.y == 0.0f) {
            sp1C->moveSpeed = 0.0f;
            sp1C->unk48 = 8.0f;
            sp1C->unk40 = Math_WrapAngle(360.0f, (f32) (sp1C->unkA8 * 0x5A));
        } else {
            sp1C->moveSpeed = 8.0f;
            sp1C->unk48 = 0.0f;
            sp1C->moveAngle = Math_WrapAngle(360.0f, (f32) (sp1C->unkA8 * 0x5A));
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkA6 -= 8;
    if (sp1C->unkA6 <= 0) {
        sp1C->actionState = 3;
        sp1C->unk132 = 0;
        sp1C->unkA8 = -sp1C->unkA8;
    }
    sp1B = func_803304D0_unk_bin_37();
    if (sp1B == 0) {
        sp1C->actionState = 5;
        sp1C->unk132 = 0;
    }
}

void func_80331684_unk_bin_37(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_803316B4_unk_bin_37(void) {
}

void func_803316C4_unk_bin_37(void) {
}

void func_803316D4_unk_bin_37(void) {
    s32 sp1C;

    sp1C = (s32) gObjects[gCurrentParsedObject].actionState;
    switch (sp1C) {
        case 8:
            func_80331064_unk_bin_37();
            break;
        case 1:
            func_8033117C_unk_bin_37();
            break;
        case 2:
            func_8033131C_unk_bin_37();
            break;
        case 3:
            func_8033145C_unk_bin_37();
            break;
        case 4:
            func_803304D0_unk_bin_37();
            break;
        case 6:
            func_803316B4_unk_bin_37();
            break;
        case 5:
            func_80331684_unk_bin_37();
            break;
        case 7:
            func_803316C4_unk_bin_37();
            break;
        default:
            break;
    }
}

void stub_80331778_unk_bin_37() {
}

void stub_8033177C_unk_bin_37() {
}

void func_80331800_unk_bin_37(void) {
    func_8001BB34(gCurrentParsedObject, 0);
    func_8002B0E4(gCurrentParsedObject);
}

void func_80331840_unk_bin_37(void) {
    if (gObjects[gCurrentParsedObject].actionState == 2) {
        func_80331800_unk_bin_37();
    }
}

void func_803318B4_unk_bin_37() {
}

void func_803318B8_unk_bin_37() {
}

void func_803318BC_unk_bin_37(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->moveSpeed = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0xA;
        func_8001C0EC(gCurrentParsedObject, 3, 2, 0x101, &D_80117478);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->unkA6 -= 1;
    if (sp24->unkA6 <= 0) {
        func_8002B114(gCurrentParsedObject);
        return;
    }
    if (func_8001B44C(gCurrentParsedObject, 3) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_80331A0C_unk_bin_37(void) {
}

void func_80331A1C_unk_bin_37(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->moveSpeed = 0.0f;
        sp24->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x101, &D_80117478);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((sp24->unk132 == 1) && (func_8001B44C(gCurrentParsedObject, 3) != 0)) {
        func_8001C0EC(gCurrentParsedObject, 3, 1, 0x101, &D_80117478);
        sp24->unk132 = 2;
    }
}

void func_80331B60_unk_bin_37(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_80331A0C_unk_bin_37();
            break;
        case 2:
            func_80331A1C_unk_bin_37();
            break;
        case 3:
            func_803318BC_unk_bin_37();
            break;
        default:
            break;
    }
}

void func_80331C10_unk_bin_37(void) {
    s16 sp26;

    sp26 = func_80027464(1, &D_80113E08, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        if (D_80165100->unkA != 0) {
            gObjects[sp26].unkAA = 0;
            gObjects[sp26].moveAngle = (f32) D_80165100->unkA;
            gObjects[sp26].Rot.y = (f32) D_80165100->unkA;
            gObjects[sp26].unk40 = 0.0f;
            gObjects[sp26].unk48 = 0.0f;
        } else {
            gObjects[sp26].unkAA = 1;
            gObjects[sp26].unk40 = (f32) D_80165100->unkC;
            gObjects[sp26].Rot.x = Math_WrapAngle(180.0f, (f32) D_80165100->unkC);
            gObjects[sp26].moveAngle = 0.0f;
            gObjects[sp26].moveSpeed = 0.0f;
        }
        if (D_80165100->unkE != 0) {
            gObjects[sp26].unkA8 = D_80165100->unkE;
        } else {
            gObjects[sp26].unkA8 = 0x18;
        }
        gObjects[sp26].actionState = 1;
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32) sp26, 0, 0, 0x12A, &D_80117484);
        func_8001BBDC((s32) sp26, 1);
    }
}
void func_80331F90_unk_bin_37() {
}

void func_80331F94_unk_bin_37(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->moveSpeed = 0.0f;
        sp1C->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8002A2EC(gCurrentParsedObject, 1800.0f) != 0) {
        sp1C->actionState = 2;
        sp1C->unk132 = 0;
    }
}

void func_80332074_unk_bin_37(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->moveSpeed = 0.0f;
        sp1C->unk48 = 0.0f;
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
        sp1C->actionState = 3;
        sp1C->unk132 = 0;
    }
}

void func_80332174_unk_bin_37(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unkA6 = 0x294;
        if (sp1C->unkAA == 1) {
            sp1C->unk48 = (f32) sp1C->unkA8;
            sp1C->unk40 = Math_WrapAngle(180.0f, sp1C->Rot.x);
        } else {
            sp1C->moveSpeed = (f32) sp1C->unkA8;
            sp1C->moveAngle = sp1C->Rot.y;
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp1C->unkAA == 1) {
        sp1C->Rot.z = Math_WrapAngle(sp1C->Rot.z, 12.0f);
    } else {
        sp1C->Rot.x = Math_WrapAngle(sp1C->Rot.x, 12.0f);
    }
    if (sp1C->unkA6 <= 0) {
        sp1C->moveSpeed = 0.0f;
        sp1C->unk48 = 0.0f;
    } else {
        sp1C->unkA6 -= sp1C->unkA8;
    }
}

void func_80332354_unk_bin_37(void) {
}

void func_80332364_unk_bin_37(void) {
}

void func_80332374_unk_bin_37(void) {
}

void func_80332384_unk_bin_37(void) {
    s32 sp1C;

    sp1C = (s32) gObjects[gCurrentParsedObject].actionState;
    switch (sp1C) {
        case 1:
            func_80331F94_unk_bin_37();
            break;
        case 2:
            func_80332074_unk_bin_37();
            break;
        case 3:
            func_80332174_unk_bin_37();
            break;
        case 5:
            func_80332364_unk_bin_37();
            break;
        case 4:
            func_80332354_unk_bin_37();
            break;
        case 6:
            func_80332374_unk_bin_37();
            break;
        default:
            break;
    }
}

s16 func_80332470_unk_bin_37(struct ObjectStruct* arg0, s16 arg1, s16 arg2, struct ObjSpawnInfo* arg3) {
    struct ObjectStruct* sp3C;
    s16 sp3A;
    f32 sp34;
    s16 sp32;

    sp3A = func_80027464(1, arg3, arg0->Pos.x, arg0->Pos.y, arg0->Pos.z, arg0->moveAngle);
    if (sp3A != -1) {
        func_80026F10((s32) arg1, (s32) sp3A);
        sp3C = &gObjects[sp3A];
        sp32 = ((arg2 / 2) * 0x28) - 0x14;
        sp34 = Math_WrapAngle(arg0->moveAngle, (f32) sp32);
        sp3C->Vel.x = sinf((f32) ((f64) sp34 * DEG_TO_RAD)) * 200.0f;
        sp3C->Vel.z = cosf((f32) ((f64) sp34 * DEG_TO_RAD)) * 200.0f;
        sp3C->Pos.x = arg0->Pos.x + sp3C->Vel.x;
        sp3C->Pos.z = arg0->Pos.z + sp3C->Vel.z;
        sp3C->Pos.y = arg0->Pos.y + 100.0f;
        sp3C->moveSpeed = 20.0f;
        sp3C->moveAngle = arg0->moveAngle;
        sp3C->unk40 = arg0->unk40;
        sp3C->Rot.y = arg0->moveAngle;
        sp3C->actionState = 1;
        sp3C->unkA8 = 1;
        sp3C->unkB2 = 0x78;
        sp3C->unk132 = 0;
        sp3C->Scale.x = 1.4f;
        sp3C->Scale.z = sp3C->Scale.y = sp3C->Scale.x;
        func_80029C40((s32) sp3A);
        func_80029D04((s32) sp3A);
    }
    return sp3A;
}

void func_803326FC_unk_bin_37(void) {
    s16 sp2E;

    sp2E = func_80027464(1, &D_80113E20, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].actionState = 1;
        gObjects[sp2E].unkA8 = 0x10;
        gObjects[sp2E].unk132 = 0;
        gObjects[sp2E].Scale.x = 1.4f;
        gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.x;
    }
}

void func_80332888_unk_bin_37(void) {
    if (D_80177A64 == 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_803328CC_unk_bin_37(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->moveSpeed = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkA6 == 1) {
        if (sp24->unkA8 >= 0x10) {
            sp24->actionState = 2;
            sp24->unk132 = 0;
            func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
        } else {
            sp24->unkA6 = 0;
        }
    }
}

void func_80332A04_unk_bin_37(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->moveSpeed = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkAA = 0;
    }
    if (sp24->unk132 == 1) {
        func_8002A8B4(gCurrentParsedObject, 6.0f);
        if (func_8002A560(gCurrentParsedObject, 5.0f) == 0) {
            sp24->unkAA = 0;
            sp24->unk132 = 2;
        }
    } else {
        sp24->unkAA += 1;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->Rot.y = sp24->moveAngle;
    if (sp24->unkAA == 4) {
        func_80332470_unk_bin_37(sp24, (s16) gCurrentParsedObject, 0, &D_80113E38);
        func_80332470_unk_bin_37(sp24, (s16) gCurrentParsedObject, 1, &D_80113E2C);
        func_800175F0(gCurrentParsedObject, 0, 0x1B, -1, 0);
    }
    if (sp24->unkAA == 0xE) {
        func_80332470_unk_bin_37(sp24, (s16) gCurrentParsedObject, 2, &D_80113E38);
        func_80332470_unk_bin_37(sp24, (s16) gCurrentParsedObject, 3, &D_80113E2C);
        func_800175F0(gCurrentParsedObject, 0, 0x1B, -1, 0);
    }
    if (sp24->unkAA == 0x12) {
        sp24->actionState = 1;
        sp24->unkA8 = 0;
        sp24->unk132 = 0;
    }
}

void func_80332C60_unk_bin_37(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80332C90_unk_bin_37(void) {
}

void func_80332CA0_unk_bin_37(void) {
}

void func_80332CB0_unk_bin_37(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    switch (sp1C->actionState) {
        case 1:
            func_803328CC_unk_bin_37();
            break;
        case 2:
            func_80332A04_unk_bin_37();
            break;
        case 4:
            func_80332C90_unk_bin_37();
            break;
        case 3:
            func_80332C60_unk_bin_37();
            break;
        case 5:
            func_80332CA0_unk_bin_37();
            break;
        default:
            break;
    }
    sp1C->unkA8 += 1;
    if (sp1C->unkA8 >= 0x2000) {
        sp1C->unkA8 = 0x2000;
    }
}

static void stub_80332DE8_unk_bin_37() {
}

static void stub_80332DEC_unk_bin_37() {
}

void func_80332DF0_unk_bin_37(void) {
    func_8002B114(gCurrentParsedObject);
}

void func_80332E20_unk_bin_37(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        if (sp24->unk132 == 0) {
            sp24->unk132 = 1;
            sp24->moveSpeed = 0.0f;
            sp24->unk48 = 0.0f;
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0x131, &D_80117488);
            func_800272E8(gCurrentParsedObject);
        }
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
        sp24->Rot.y = sp24->moveAngle;
        if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
            func_8002B114(gCurrentParsedObject);
        }
    }
}

void stub9() {
}

void func_80332F84_unk_bin_37(void) {
    gObjects[gCurrentParsedObject].actionState = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_80332FE8_unk_bin_37(void) {
    struct ObjectStruct* sp34;
    struct ObjectStruct* sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp24;
    f32 sp20;

    sp30 = gObjects;
    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk40 = 0.0f;
        sp34->moveSpeed = 28.0f;
        sp34->unk48 = 14.0f;
        sp34->unkA6 = 0;
        sp34->damageState = 1;
        func_800272E8(gCurrentParsedObject);
        func_80019448(gCurrentParsedObject, 2, 0, 1);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    sp34->unkA6 += 1;
    sp34->moveSpeed = (f32) (((s16) sp34->unkA6 / 8) + 0x1C);
    sp34->Rot.z = Math_WrapAngle(sp34->Rot.z, 16.0f);
    sp20 = Math_CalcAngleRotated(sp30->Pos.x - sp34->Pos.x, sp30->Pos.z - sp34->Pos.z);
    sp24 = func_800157EC(sp34->moveAngle, sp20, 12.0f);
    sp34->moveAngle = Math_WrapAngle(sp34->moveAngle, (f32) sp24);
    sp20 = Math_CalcAngleSimple(sp30->Pos.x - sp34->Pos.x, sp30->Pos.y - sp34->Pos.y);
    sp20 = Math_NormalizeAngle(sp20);
    sp24 = func_800157EC(sp34->unk40, sp20, 12.0f);
    sp34->unk40 = Math_WrapAngle(sp34->unk40, (f32) sp24);
    sp34->Rot.y = sp34->moveAngle;
    sp34->Rot.x = Math_WrapAngle(360.0f, -sp34->unk40);
    func_80029D8C(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp2C, 0.0f, -10.0f, 0.0f) != 0) {
        sp34->actionState = 2;
        sp34->unk132 = 0;
    }
    sp34->unkB2 -= 1;
    if (sp34->unkB2 <= 0) {
        sp34->actionState = 2;
        sp34->unk132 = 0;
    }
}

void func_80333310_unk_bin_37(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80333340_unk_bin_37(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
            case 1:
                func_80332FE8_unk_bin_37();
                break;
            case 2:
                func_80333310_unk_bin_37();
                break;
            default:
                break;
        }
    }
}

void func_80333408_unk_bin_37(void) {
    s16 sp3E;

    sp3E = func_80027464(1, &D_80113E44, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp3E != -1) {
        gObjects[sp3E].damageState = 1;
        gObjects[sp3E].unk100 = -1;
        gObjects[sp3E].unk102 = 0;
        gObjects[sp3E].unkA8 = 3;
        gObjects[sp3E].unkAA = 2;
        gObjects[sp3E].unkAC = 0;
        gObjects[sp3E].unkAE = 0;
        gObjects[sp3E].unkB0 = 0x18;
        if (D_80165100->unkA != 0) {
            gObjects[sp3E].unkB0 = D_80165100->unkA + 0x18;
        }
        if (D_80165100->unkC != 0) {
            gObjects[sp3E].unkA8 = (IABS(D_80165100->unkC) % 4);
            if (gObjects[sp3E].unkA8 == 3) {
                gObjects[sp3E].unkAC = 1;
            }
        }
        if (D_80165100->unkE != 0) {
            gObjects[sp3E].unkAA = IABS(D_80165100->unkE);
        }
        gObjects[sp3E].Scale.x = 3.0f;
        gObjects[sp3E].Scale.z = gObjects[sp3E].Scale.y = gObjects[sp3E].Scale.x;
        func_8001C0EC((s32) sp3E, 3, 0, 0x133, &D_8011748C);
    }
}

void func_80333844_unk_bin_37(void) {
    struct ObjectStruct* sp1C;
    s16 sp1A;

    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        sp1C = &gObjects[gCurrentParsedObject];
        sp1A = 0;
        if (sp1A != -1) {
            do {
                sp1A = Get_ObjIdx_ByPos(0x142, (s32) sp1A);
                if (sp1A != -1) {
                    if (sp1C->Pos.z >= gObjects[sp1A].Pos.z) {
                        sp1C->unkA6 = 0;
                        gObjects[sp1A].unkA6 = 1;
                    }
                    sp1A += 1;
                }
            } while (sp1A != -1);
        }
    }
}

static void stub_8033399C_unk_bin_37() {
}

static void stub_803339A0_unk_bin_37() {
}

static void stub_803339A4_unk_bin_37() {
}

void func_803339A8_unk_bin_37(void) {
    struct ObjectStruct* sp1C;
    f32 sp18;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->moveSpeed = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->moveAngle = Math_WrapAngle((f32) (((s16) sp1C->unkA8 % 4) * 0x5A), 0.0f);
        sp1C->unk40 = 180.0f;
        sp1C->unkA6 = 0x3C;
        func_80019448(gCurrentParsedObject, 2, 0, 1);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp1C->unkAC == 0) {
        if (sp1C->unk40 < 210.0f) {
            sp1C->unk40 = Math_WrapAngle(sp1C->unk40, (f32) sp1C->unkAA);
        } else {
            sp1C->unkAC = 1;
        }
    } else if (sp1C->unk40 > 150.0f) {
        sp1C->unk40 = Math_WrapAngle(sp1C->unk40, (f32) -sp1C->unkAA);
    } else {
        sp1C->unkAC = 0;
    }
    sp1C->unkAE = (s16) (s32) Math_WrapAngle((f32) sp1C->unkAE, 10.0f);
    sp18 = sinf((f32) ((f64) sp1C->unkAE * DEG_TO_RAD)) * (f32) sp1C->unkB0;
    sp1C->Rot.x = sp1C->unk40;
    sp1C->Rot.y = Math_WrapAngle(sp1C->moveAngle, sp18);
    sp1C->Rot.y = sp1C->moveAngle;
    sp1C->unkA6 += 1;
    if (sp1C->unkA6 >= 0x2000) {
        sp1C->unkA6 = 0;
    }
}

void func_80333CD8_unk_bin_37(void) {
    s8 sp27;

    sp27 = func_80027464(7, &D_80113C28, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp27 != -1) {
        gObjects[sp27].unkA8 = D_80165100->unkA;
        gObjects[sp27].unkAA = 1;
        gObjects[sp27].Scale.x = 0.85f;
        gObjects[sp27].Scale.y = 0.85f;
        gObjects[sp27].Scale.z = 0.85f;
        if (gObjects[sp27].unkA8 == 0) {
            gObjects[sp27].unkA8 = 1;
        }
        if (D_80165100->unkC != 0) {
            gObjects[sp27].unkAA = -1;
        }
        gObjects[sp27].unkA8 = (gObjects[sp27].unkA8 * 4) * gObjects[sp27].unkAA;
        gObjects[sp27].damageState = -1;
        gObjects[sp27].unk100 = -1;
        gObjects[sp27].actionState = 2;
        gObjects[sp27].unk132 = 0;
        func_80333FC4_unk_bin_37(sp27);
    }
}

s8 func_80333FC4_unk_bin_37(s8 arg0) {
    s8 sp1F;
    s8 sp1E;

    for (sp1E = 0; sp1E < 6; sp1E++) {
        sp1F = (s8) gObjects[arg0].unkE8[sp1E];
        gObjects[sp1F].damageState = -1;
        gObjects[sp1F].unk100 = -1;
        gObjects[sp1F].unk132 = 0;
        gObjects[sp1F].actionState = 1;
        gObjects[sp1F].unkA8 = sp1E - 3;
        gObjects[sp1F].unkAA = 0;
        gObjects[sp1F].Scale.x = 0.85f;
        gObjects[sp1F].Scale.y = 0.85f;
        gObjects[sp1F].Scale.z = 0.85f;
        if (gObjects[sp1F].unkA8 >= 0) {
            gObjects[sp1F].unkA8 += 1;
        }
        func_80019448((s32) sp1F, 2, 0, 1);
    }
    return sp1E;
}

void func_80334244_unk_bin_37() {
}

void func_80334248_unk_bin_37(s8 arg0) {
}

void func_8033425C_unk_bin_37(void) {
    struct ObjectStruct* sp24;
    s32 pad[2];

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->moveSpeed = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->moveAngle = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->moveAngle = Math_WrapAngle(sp24->moveAngle, (f32) sp24->unkA8);
    func_80334534_unk_bin_37();
}

void func_8033434C_unk_bin_37(void) {
    struct ObjectStruct* sp1C;
    s8 sp1B;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->moveSpeed = 0.0f;
        sp1C->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    for (sp1B = 0; sp1B < 6; sp1B++) {
        func_80334248_unk_bin_37(sp1B);
    }
    func_8002B0E4(gCurrentParsedObject);
}

s8 func_8033443C_unk_bin_37(s8 arg0) {
    struct ObjectStruct* spC;
    UNUSED s32 pad;
    s8 sp7;

    spC = &gObjects[gCurrentParsedObject];
    sp7 = 0;
    if (spC->unkE8[arg0] != -1) {
        sp7 = 1;
    }
    return sp7;
}

s8 func_803344B8_unk_bin_37(void) {
    s8 sp27;
    s8 sp26;

    sp27 = 0;
    for (sp26 = 0; sp26 < 6; sp26++) {
        sp27 += func_8033443C_unk_bin_37(sp26);
    }
    return sp27;
}

s8 func_80334534_unk_bin_37(void) {
    struct ObjectStruct* sp24;
    s8 sp23;
    s8 sp22;

    sp23 = 0;
    sp24 = &gObjects[gCurrentParsedObject];
    for (sp22 = 6; sp22 > 0; sp22--) {
        sp23 += func_803345DC_unk_bin_37(sp22 - 1);
    }
    return sp23;
}

s16 func_803345DC_unk_bin_37(s16 arg0) {
    struct ObjectStruct* sp34;
    struct ObjectStruct* sp30;
    f32 sp2C;
    s8 sp2B;
    s16 var_s0;
    struct ObjectStruct* temp_t4;

    sp34 = &gObjects[gCurrentParsedObject];
    sp2B = (s8) sp34->unkE8[arg0];
    if (sp2B != -1) {
        sp30 = &gObjects[sp2B];
        sp34 = &gObjects[sp30->unkE6[0]];
        sp2C = Math_WrapAngle(sp34->moveAngle, 90.0f);
        sp30->Vel.x = sinf((f32) ((f64) sp2C * DEG_TO_RAD)) * ((f32) sp30->unkA8 * (100.0f * sp30->Scale.x));
        sp30->Vel.y = cosf((f32) ((f64) sp2C * DEG_TO_RAD)) * ((f32) sp30->unkA8 * (100.0f * sp30->Scale.x));
        sp30->Pos.x = sp34->Pos.x + sp30->Vel.x;
        sp30->Pos.y = sp34->Pos.y + sp30->Vel.y;
        sp30->Pos.z = sp34->Pos.z - (35.0f * sp30->Scale.x * (f32) arg0);
        sp30->Rot.z = Math_WrapAngle(sp30->Rot.z, (f32) -sp34->unkA8);
        sp30->unk40 = sp34->unk40;
        sp30->moveSpeed = sp34->moveSpeed;
        sp30->unk48 = sp34->unk48;
    }

    return ~(sp2B != 0) ? 0 : 1;
}

void func_80334878_unk_bin_37(void) {
    s32 sp24;

    sp24 = (s32) gObjects[gCurrentParsedObject].actionState;
    switch (sp24) { /* irregular */
        case 2:
            func_8033425C_unk_bin_37();
            break;
        case 3:
            func_8033434C_unk_bin_37();
            break;
        default:
            break;
    }
}

void func_80334918_unk_bin_37(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114048, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].Scale.x = 1.5f;
        gObjects[sp24].Scale.y = 1.5f;
        gObjects[sp24].Scale.z = 1.5f;
    }
}

void func_80334A28_unk_bin_37(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 3;
    }
}

void func_80334AA0_unk_bin_37(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->moveSpeed = 2.0f;
        sp24->moveAngle = 0.0f;
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x8A, &D_801182CC);
    }
    if ((sp24->unkA6 == 0) && (sp24->moveAngle == 0.0f)) {

    } else {
        sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, (f32) (sp24->unkA8 * 2));
        sp24->moveAngle = sp24->Rot.y;
        sp20 = (s32) ((f32) sp24->unkA6 - sp24->moveAngle);
        if ((sp20 < 3) && (sp20 >= -2)) {
            if (sp24->unkA6 != 0) {
                sp24->unkA6 = 0;
                if (sp24->unkA8 == 1) {
                    sp24->unkA8 = -1;
                } else {
                    sp24->unkA8 = 1;
                }
            } else {
                sp24->unkA8 = 0;
                sp24->Rot.y = 0.0f;
                sp24->moveAngle = sp24->Rot.y;
            }
        }
    }
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        if (D_801651A0 & 0x80) {
            sp24->actionState = 2;
            sp24->unk132 = 0;
        }
        if ((sp24->unkA6 == 0) && (sp24->moveAngle == 0.0f)) {
            sp20 = (s32) Get_AngleToPlayer(gCurrentParsedObject);
            if ((sp20 >= 0) && (sp20 < 0xB4)) {
                sp24->unkA6 = 0x5A;
                sp24->unkA8 = 1;
            } else {
                sp24->unkA6 = 0x10E;
                sp24->unkA8 = -1;
            }
        }
    }
}

void func_80334E34_unk_bin_37(void) {
    func_8002B114(gCurrentParsedObject);
}

void func_80334E64_unk_bin_37(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80334E94_unk_bin_37(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_80334AA0_unk_bin_37();
            break;
        case 2:
            func_80334E34_unk_bin_37();
            break;
        case 3:
            func_80334E64_unk_bin_37();
            break;
        default:
            break;
    }
}

void func_80334F44_unk_bin_37(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114054, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].Scale.x = 1.5f;
        gObjects[sp24].Scale.y = 1.5f;
        gObjects[sp24].Scale.z = 1.5f;
    }
}

void func_80335054_unk_bin_37(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 4;
    }
}

void func_803350CC_unk_bin_37(void) {
    struct ObjectStruct* sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;
    f32 temp_f20;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = 1;
        sp44->unkA6 = 0x2D;
        sp44->unkAA = 0xC8;
        sp30 = (s32) (sp44->Pos.x - gPlayerObject->Pos.x);
        if (sp30 < 0) {
            sp44->moveAngle = 70.0f;
            sp44->unkA8 = -1;
        } else {
            sp44->moveAngle = 290.0f;
            sp44->unkA8 = 1;
        }
        sp30 = (s32) (gPlayerObject->Pos.y - sp44->Pos.y);
        sp44->Vel.y = (f32) (sp30 / 100);
        sp44->moveSpeed = 6.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x8A, &D_801182CC);
    }
    sp40 = 0;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp40 = 1;
    }
    if (sp44->unkA6 != 0) {
        sp44->unkA6 -= 1;
        if (sp44->unkA6 == 0x25) {
            func_8001BBDC(gCurrentParsedObject, 1);
        }
        sp44->Rot.z = Math_WrapAngle(sp44->Rot.z, (f32) sp44->unkA8);
    }
    sp3C = sp44->Vel.y;
    sp44->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    sp44->Vel.y = sp3C;
    if (func_800295C0(gCurrentParsedObject, &sp34, &sp38, 0.0f, 100.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp34, &sp38, 0.0f, -100.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    if ((gPlayerObject->Pos.z - sp44->Pos.z) < 60.0f) {
        sp40 = 1;
    }
    if (sp44->unkAA != 0) {
        sp44->unkAA -= 1;
        if (sp44->unkAA == 0) {
            sp40 = 1;
        }
    }
    if (sp40 != 0) {
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z = 0.0f;
        sp44->actionState = 2;
        sp44->unk132 = 0;
    }
}

void func_80335518_unk_bin_37(void) {
    struct ObjectStruct* sp34;
    f32 temp_f20;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk48 = 0.0f;
        sp34->moveSpeed = 2.0f;
        if (sp34->unkA8 == 1) {
            sp34->unkA8 = -1;
        } else {
            sp34->unkA8 = 1;
        }
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    if (sp34->Rot.z != 0.0f) {
        sp34->Rot.z = Math_WrapAngle(sp34->Rot.z, (f32) sp34->unkA8);
    } else {
        sp34->Rot.z = 0.0f;
        sp34->actionState = 3;
        sp34->unk132 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        if (D_801651A0 & 0x80) {
            sp34->actionState = 4;
            sp34->unk132 = 0;
        } else {
            sp34->Vel.x = sp34->Vel.y = sp34->Vel.z = 0.0f;
        }
    }
}

void func_80335718_unk_bin_37(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->moveSpeed = 2.0f;
        sp24->moveAngle = 0.0f;
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x8A, &D_801182CC);
    }
    if ((sp24->unkA6 == 0) && (sp24->moveAngle == 0.0f)) {

    } else {
        sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, (f32) (sp24->unkA8 * 2));
        sp24->moveAngle = sp24->Rot.y;
        sp20 = (s32) ((f32) sp24->unkA6 - sp24->moveAngle);
        if ((sp20 < 3) && (sp20 >= -2)) {
            if (sp24->unkA6 != 0) {
                sp24->unkA6 = 0;
                if (sp24->unkA8 == 1) {
                    sp24->unkA8 = -1;
                } else {
                    sp24->unkA8 = 1;
                }
            } else {
                sp24->unkA8 = 0;
                sp24->Rot.y = 0.0f;
                sp24->moveAngle = sp24->Rot.y;
            }
        }
    }
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        if (D_801651A0 & 0x80) {
            sp24->actionState = 4;
            sp24->unk132 = 0;
        }
        if ((sp24->unkA6 == 0) && (sp24->moveAngle == 0.0f)) {
            sp20 = (s32) Get_AngleToPlayer(gCurrentParsedObject);
            if ((sp20 >= 0) && (sp20 < 0xB4)) {
                sp24->unkA6 = 0x5A;
                sp24->unkA8 = 1;
            } else {
                sp24->unkA6 = 0x10E;
                sp24->unkA8 = -1;
            }
        }
    }
}

void func_80335AAC_unk_bin_37(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80335ADC_unk_bin_37(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_803350CC_unk_bin_37();
            break;
        case 2:
            func_80335518_unk_bin_37();
            break;
        case 3:
            func_80335718_unk_bin_37();
            break;
        case 4:
            func_80335AAC_unk_bin_37();
            break;
        default:
            break;
    }
}

void func_80335BA8_unk_bin_37(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114060, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].Scale.x = 1.5f;
        gObjects[sp24].Scale.y = 1.5f;
        gObjects[sp24].Scale.z = 1.5f;
    }
}

void func_80335CB8_unk_bin_37(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 2;
    }
}

void func_80335D30_unk_bin_37(void) {
    struct ObjectStruct* sp24;
    f32 sp20;
    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->moveSpeed = 2.0f;
        sp24->unkA6 = 0x32;
        sp24->unkA8 = 0;
        sp24->unkAA = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x8A, &D_801182CC);
    }
    sp20 = sp24->Vel.y;
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    sp24->Vel.y = sp20;
    if (sp24->unkA8 < 3) {
        if (sp24->unkA8 == 0) {
            if (sp24->unkA6 == 0x2B) {
                func_8001BBDC(gCurrentParsedObject, 1);
            }
            sp24->Pos.y -= 10.0f;
            sp24->Rot.x = 30.0f;
            sp24->unkA6 -= 1;
            if (sp24->unkA6 == 0) {
                sp24->unkA8 += 1;
            }
        } else if (sp24->unkA8 == 1) {
            if (sp24->Rot.x != 0.0f) {
                sp24->Rot.x = Math_WrapAngle(sp24->Rot.x, -2.0f);
            } else {
                sp24->unkA6 = 0x3C;
                sp24->unkA8 += 1;
            }
        } else {
            sp24->unkAA += 1;
            if (sp24->unkAA >= 0xA) {
                sp24->unkAA = 0xA;
            }
            sp24->Pos.y += (f32) sp24->unkAA;
            if ((sp24->Rot.x == 0.0f) || (sp24->Rot.x > 340.0f)) {
                sp24->Rot.x = Math_WrapAngle(sp24->Rot.x, -1.0f);
            }
            sp24->unkA6 -= 1;
            if (sp24->unkA6 == 0) {
                sp24->unkA8 += 1;
            }
        }
    } else {
        sp24->moveSpeed = 5.0f;
        if (sp24->Rot.x != 0.0f) {
            sp24->Rot.x = Math_WrapAngle(sp24->Rot.x, 2.0f);
        }
    }
    if ((sp24->Pos.z - gPlayerObject->Pos.z) > 360.0f) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
    }
}

void func_803361AC_unk_bin_37(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_803361DC_unk_bin_37(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_80335D30_unk_bin_37();
            break;
        case 2:
            func_803361AC_unk_bin_37();
            break;
        default:
            break;
    }
}

void func_80336270_unk_bin_37(void) {
    func_80027464(1, &D_8011460C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void stub_1D1720_803363F4() {
}

void func_803362F8_unk_bin_37(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
    }
    if (func_8002A1FC(gCurrentParsedObject, 900.0f) != 0) {
        sp1C->actionState = 2;
        sp1C->unk132 = 0;
    }
}

void func_80336398_unk_bin_37(void) {
    struct ObjectStruct* sp34;
    s32 pad[1];
    s32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
    }
    if (sp34->unkE8[0] == -1) {
        func_80027C00(gCurrentParsedObject, 0, &D_80114618, sp34->Pos.x, sp34->Pos.y, sp34->Pos.z, 0.0f);
    }
    if ((gPlayerObject->Pos.z - sp34->Pos.z) < -480.0f) {
        sp2C = (s32) sp34->unkE8[0];
        if (sp2C != -1) {
            func_800281A4(gCurrentParsedObject, 0);
            func_8002B0E4(sp2C);
        }
    }
}

void func_803364C8_unk_bin_37(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_803362F8_unk_bin_37();
            break;
        case 2:
            func_80336398_unk_bin_37();
            break;
        default:
            break;
    }
}

void func_8033655C_unk_bin_37(void) {
}

void func_8033656C_unk_bin_37(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->damageState = 0;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x17F, &D_80118B54);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    if (func_8001B44C(gCurrentParsedObject, 3) != 0) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
}

void func_8033665C_unk_bin_37(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->damageState = 1;
        func_8001C0EC(gCurrentParsedObject, 3, 1, 0x17F, &D_80118B54);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}

void func_8033670C_unk_bin_37(void) {
    s16 temp_s0;

    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_8033656C_unk_bin_37();
            break;
        case 2:
            func_8033665C_unk_bin_37();
            break;
        default:
            break;
    }
}

void func_803367A0_unk_bin_37(void) {
    s32 sp2C;

    sp2C = func_80027464(1, &D_801136C4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2C != -1) {
        gObjects[sp2C].actionState = 1;
        gObjects[sp2C].unk132 = 0;
        gObjects[sp2C].Scale.x = gObjects[sp2C].Scale.y = gObjects[sp2C].Scale.z = 1.2f;
        func_80019448(sp2C, 2, 0, 1);
        gObjects[sp2C].Rot.x = Math_WrapAngle(gObjects[sp2C].Rot.x, 270.0f);
        gObjects[sp2C].Rot.y = Math_WrapAngle(gObjects[sp2C].Rot.y, 90.0f);
        func_8001ABF4(sp2C, 0, 0, (struct UnkStruct8016C298_1*) &D_80118B38);
    }
}

void func_803369E0_unk_bin_37(void) {
    if (D_80177A64 == 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_80336A24_unk_bin_37(void) {
    struct ObjectStruct* sp2C;
    struct ObjectStruct* player;
    f32 sp24;
    UNUSED f32 pad;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk48 = 12.0f;
        sp2C->unkA6 = 0;
        sp2C->unkA8 = 0;
        func_80017664(gCurrentParsedObject, 0, 0x12, -1, 0);
    }
    sp2C->Rot.z = Math_WrapAngle(sp2C->Rot.z, 20.0f);
    sp24 = sp2C->moveAngle;
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    sp2C->unkA6 = (s16) (s32) Math_WrapAngle((f32) sp2C->unkA6, 16.0f);
    sp24 = sinf((f32) ((f64) sp2C->unkA6 * DEG_TO_RAD)) * 30.0f;
    sp2C->unk40 = Math_WrapAngle(sp24, 0.0f);
    sp2C->unkA8 = (s16) (s32) Math_WrapAngle((f32) sp2C->unkA8, 10.0f);
    if (sinf((f32) ((f64) sp2C->unkA8 * DEG_TO_RAD)) < 0.0f) {
        sp24 = -sinf((f32) ((f64) sp2C->unkA8 * DEG_TO_RAD));
    } else {
        sp24 = sinf((f32) ((f64) sp2C->unkA8 * DEG_TO_RAD));
    }
    sp2C->moveSpeed = (18.0f * sp24) + 1.0f;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->moveAngle = Get_AngleToPlayer(gCurrentParsedObject);
    }
    if ((sp2C->moveAngle > 90.0f) && (sp2C->moveAngle < 270.0f)) {
        sp2C->moveAngle = sp24;
    }

    player = &PLAYER_OBJ;
    if (player->Pos.z <= (sp2C->Pos.z - 360.0f)) {
        func_8002B0E4(gCurrentParsedObject);
        return;

        // @bug: unreachable code
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
    }
}

void func_80336DF4_unk_bin_37(void) {
    struct ObjectStruct* sp2C;
    UNUSED s32 pad;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->moveSpeed = 64.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0;
        sp2C->unkA8 = 0;
        sp2C->moveAngle = 180.0f;
    }
    sp2C->Rot.z = Math_WrapAngle(sp2C->Rot.z, 20.0f);
    sp2C->unkA8 = (s16) (s32) Math_WrapAngle((f32) sp2C->unkA8, 20.0f);
    if (sinf((f32) ((f64) sp2C->unkA8 * DEG_TO_RAD)) < 0.0f) {
        sp24 = -sinf((f32) ((f64) sp2C->unkA8 * DEG_TO_RAD));
    } else {
        sp24 = sinf((f32) ((f64) sp2C->unkA8 * DEG_TO_RAD));
    }
    if (sp2C->moveSpeed > 0.0f) {
        sp2C->moveSpeed -= sp24 / 2.0f;
    }
    sp2C->moveAngle = Math_WrapAngle(sp2C->moveAngle, 20.0f * sp24);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->moveAngle = Get_AngleToPlayer(gCurrentParsedObject);
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
    }
    if (sp2C->moveAngle <= 60.0f) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    } else if (sp2C->moveSpeed <= 0.0f) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_80337130_unk_bin_37(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->actionState) { /* irregular */
        case 1:
            func_80336A24_unk_bin_37();
            break;
        case 2:
            func_80336DF4_unk_bin_37();
            break;
    }
}

void func_803371CC_unk_bin_37(void) {
    s16 sp26;

    sp26 = func_80027464(1, &D_80113BA4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].actionState = 1;
        gObjects[sp26].unk132 = 0;
        gObjects[sp26].unkA8 = 0;
        if (D_80165100->unkA != 0) {
            gObjects[sp26].unkA8 = 1;
        }
        gObjects[sp26].damageState = 1;
        func_8001ABF4((s32) sp26, 0, 0, &D_80117424);
        func_8001BB34((s32) sp26, 0);
    }
}

void func_80337358_unk_bin_37(void) {
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        return;
    }
    func_8002B0E4(gCurrentParsedObject);
    return;
}

void func_803373B8_unk_bin_37(void) {
    struct ObjectStruct* sp3C;
    struct ObjectStruct* sp38;
    s8 sp37;
    s8 sp36;

    sp38 = gObjects;
    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = 1;
        sp3C->moveSpeed = 8.0f;
        sp3C->moveAngle = 0.0f;
        sp3C->unkAA = func_8002A560(gCurrentParsedObject, 1.0f);
        sp3C->unkD4 = Math_WrapAngle(360.0f, (f32) (sp3C->unkAA * 0x24));
        sp3C->unkAA *= 3;
        sp3C->unkD8 = sp38->Pos.x;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((sp3C->unkA8 == 1)) {
        if ((sp3C->Pos.z + 1500) > sp38->Pos.z) {

            if (sp3C->unk132 == 1) {
                sp37 = func_800BFFCC(sp3C, 0, sp3C->unkD4, (f32) sp3C->unkAA);
                if (sp37 == 0) {
                    sp3C->unk132 = 4;
                }
            }
            sp36 = func_80028FA0(gCurrentParsedObject);
            if (sp36 != 0) {
                sp3C->Vel.x = 0.0f;
            }
            if (func_80029018(gCurrentParsedObject, 3U, 180.0f, 0.0f, 0.0f, 0.0f)) {
                sp36 = 1;
                sp3C->Vel.x = 0.0f;
                sp3C->Vel.z = 4.0f;
            }
            if ((((sp3C->Pos.x - 180.0f) < sp3C->unkD8) && ((sp3C->Pos.x + 180.0f) >= sp3C->unkD8)) || (sp36 != 0)) {
                sp3C->unkA8 = 0;

                sp3C->unkAA = -((sp3C->unkAA > 0 ? 1 : !sp3C->unkAA ? 0 : -1) * 10);
                sp3C->moveSpeed = 10.0f;
                sp3C->unkD4 = 0.0f;
                sp3C->unk132 = 2;
                sp3C->moveAngle = 0.0f;
            }
        }
    }

    if (func_80029018(gCurrentParsedObject, 3U, 180, 0, 0, 0)) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (sp3C->unk132 == 2) {
        sp37 = func_800BFFCC(sp3C, 0, sp3C->unkD4, sp3C->unkAA);
        if (sp37 == 0) {
            sp3C->unk132 = 1;
        }
    }
    sp3C->Rot.z = Math_WrapAngle(sp3C->Rot.z, 12.0f);
    sp3C->Rot.y = sp3C->moveAngle;
}

void func_8033781C_unk_bin_37(void) {
}

void func_8033782C_unk_bin_37(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_8033785C_unk_bin_37(void) {
    s32 sp24;

    sp24 = (s32) gObjects[gCurrentParsedObject].actionState;
    switch (sp24) { /* irregular */
        case 1:
            func_803373B8_unk_bin_37();
            break;
        case 2:
            func_8033781C_unk_bin_37();
            break;
        default:
            func_8033782C_unk_bin_37();
            break;
    }
}
