#include "common.h"

void func_bagular1_80330000();         /* static */
void func_bagular1_803300C8();         /* static */
void func_bagular1_803301D4();         /* static */
void func_bagular1_803303D0();         /* static */
void func_bagular1_80330844();         /* static */
void func_bagular1_80330EA4();         /* static */
void func_bagular1_80331148();         /* static */
void func_bagular1_803314BC();         /* static */
void func_bagular1_803316EC();         /* static */
void func_bagular1_80331880(s16 arg0); /* static */
s32 func_bagular1_80331A34(f32 arg0);  /* static */
s32 func_bagular1_80331B74(f32 arg0);  /* static */
void func_bagular1_80331CB4();         /* static */
void func_bagular1_80332304();         /* static */
void func_bagular1_8033249C();         /* static */
void func_bagular1_80332694();         /* static */
void func_bagular1_803328BC();         /* static */
void func_bagular1_80332AE0();         /* static */
void func_bagular1_80332BCC();         /* static */
void func_bagular1_80332C94();         /* static */
void func_bagular1_80332D5C();         /* static */
void func_bagular1_80332F3C();         /* static */

extern u32 D_8011B0A0;
extern u32 D_8011B0B4;
extern u32 D_8011B0B8;
extern u32 D_8011B0BC;
extern UNK_TYPE D_8011B104;
extern u32 D_8011B120;
extern u32 D_8011B124;
extern u32 D_8011B128;
extern UNK_TYPE D_8011B16C;

static s16 D_bagular1_80332FC0[0x12] = {
    8, 8, 9, 9, 0xA, 0xA, 0xB, 0xB, 0xC, 0xC, 0xD, 0xD, 0xE, 0xE, 0xF, 0xF, 0x10, 0x10,
};
static s16 D_bagular1_80332FE4[0x1A] = {
    0x11, 0x11, 0x12, 0x12, 0x13, 0x13, 0x14, 0x14, 0x15, 0x15, 0x16, 0x16, 0x17,
    0x17, 0x18, 0x18, 0x19, 0x19, 0x1A, 0x1A, 0x1B, 0x1B, 0x1C, 0x1C, 0x1D, 0x1D,
};
static s16 D_bagular1_80333018[0x22] = {
    0, 0, 1, 1,   2,   2,   3,   3,   4,   4,   5,   5,   6,   6,   7,   7,    8,
    8, 9, 9, 0xA, 0xA, 0xB, 0xB, 0xC, 0xC, 0xD, 0xD, 0xE, 0xE, 0xF, 0xF, 0x10, 0x10,
};
static s16 D_bagular1_8033305C[0x26] = {
    0x1E, 0x1E, 0x1F, 0x1F, 0x20, 0x20, 0x21, 0x21, 0x22, 0x22, 0x23, 0x23, 0x24, 0x24, 0x25, 0x25, 0x26, 0x26, 0x27,
    0x27, 0x28, 0x28, 0x29, 0x29, 0x2A, 0x2A, 0x2B, 0x2B, 0x2C, 0x2C, 0x2D, 0x2D, 0x2E, 0x2E, 0x2F, 0x2F, 0x30, 0x30,
};
static s16 D_bagular1_803330A8[0x30] = {
    0x2D, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x2D, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E,
    0x2D, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x2D, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E,
    0x2D, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x2D, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E,
};
static s16 D_bagular1_80333108[0x2E] = {
    0x31, 0x31, 0x32, 0x32, 0x33, 0x33, 0x34, 0x34, 0x35, 0x35, 0x36, 0x36, 0x37, 0x37, 0x38, 0x38,
    0x39, 0x39, 0x3A, 0x3A, 0x3B, 0x3B, 0x3C, 0x3C, 0x3D, 0x3D, 0x3E, 0x3E, 0x3F, 0x3F, 0x40, 0x40,
    0x41, 0x41, 0x42, 0x42, 0x43, 0x43, 0x44, 0x44, 0x45, 0x45, 0x46, 0x46, 0x47, 0x47,
};

static struct ObjSpawnInfo D_bagular1_80333164[1] = {{ 0, OBJ_BAG1_MT, 0x136, 0, -1, 0, 0, 0 }};
static struct ObjSpawnInfo D_bagular1_80333170 = { 3, OBJ_BAG1_AT1, 0x137, 4, -1, 0, 0, 0 };  /* const */
static struct ObjSpawnInfo D_bagular1_8033317C = { 3, OBJ_BAG1_AT2, 0x138, 2, -1, 0, 0, 0 };  /* const */
static struct ObjSpawnInfo D_bagular1_80333188 = { 3, OBJ_BAG1_AT3, 0x138, 2, 1, -1, 1, 0 };  /* const */
static struct ObjSpawnInfo D_bagular1_80333194 = { 3, OBJ_BAG1_WP, 0x139, 1, -1, 0, 0, 0 };  /* const */
static struct ObjSpawnInfo D_bagular1_803331A0 = { 3, OBJ_BAG1_WL, 0x13A, 4, -1, 0, 0, 0 };  /* const */
static struct ObjSpawnInfo D_bagular1_803331AC = { 3, OBJ_BAG1_AT4, 0x13B, 3, -1, 0, 0, 0 };  /* const */
static struct ObjSpawnInfo D_bagular1_803331B8 = { 0, OBJ_BAG1_ST, 0x13C, 1, -1, 0, 0, 0 };  /* const */
static struct ObjSpawnInfo D_bagular1_803331C4 = { 0, OBJ_BAG1_BD, 0x135, 0xB, 7, 1, 1, 0 }; /* const */
static struct ObjSpawnInfo D_bagular1_803331D0 = { 0, OBJ_BAG1_TV, 0x167, 1, -1, 0, 0, 0 };  /* const */

void func_bagular1_80330000(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_bagular1_803331C4, (f32) D_80165100->unk2, (f32) D_80165100->unk4,
                         (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    gObjects[sp24].unkC2 = 0;
    gObjects[sp24].unkBC = 1;
}

void func_bagular1_803300C8(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp1C->damageState = 0;
        func_80069E60(0, 1, 0x12C);
        sp1C->unkBE = 1;
        sp1C->actionState = 6;
        sp1C->unk132 = 0;
        sp1C->moveSpeed = 0.0f;
        sp1C->Vel.z = 0.0f;
        sp1C->Vel.x = sp1C->Vel.z;
        func_8001BBDC(gCurrentParsedObject, 1);
    } else if (D_80177A64 == 1) {
        sp1C->damageState = 0x78;
    }
}

void func_bagular1_803301D4(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x135, &D_8011B0A0);
    }
    func_bagular1_80331880(D_bagular1_80332FE4[(s16) (s32) (func_8001B62C(gCurrentParsedObject, 0) / 2.0f)]);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if ((func_bagular1_80331A34(480.0f) == 1) || (func_bagular1_80331B74(480.0f) == 1)) {
            sp2C->unkA6 = 2;
        } else if (func_8002A2EC(gCurrentParsedObject, 600.0f) != 0) {
            sp2C->unkA6 = 1;
        } else if (func_bagular1_80331A34(600.0f) != 0) {
            sp2C->unkA6 = 1;
        } else {
            sp2C->unkA6 = 0;
        }
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
    }
}

void func_bagular1_803303D0(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unkB2 = sp3C->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x135, &D_8011B0A0);
        sp3C->unkAC = 0;
        if ((sp3C->damageState == -1) || (sp3C->damageState == 0)) {
            sp3C->damageState = 1;
        }
        if (sp3C->unkB8 != 0) {
            sp3C->damageState = sp3C->unkB8;
            sp3C->unkB8 = 0;
        }
    }
    func_bagular1_80331880(D_bagular1_80333018[(s16) (s32) (func_8001B62C(gCurrentParsedObject, 0) / 2.0f)]);
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp3C->Rot.y = sp3C->moveAngle;
    switch (sp3C->unkA6) { /* irregular */
        case 0:
            if (func_8001B62C(gCurrentParsedObject, 0) > 30.0f) {
                sp3C->actionState = 4;
                sp3C->unk132 = 0;
            }
            break;
        case 1:
            if (func_8001B62C(gCurrentParsedObject, 0) > 30.0f) {
                sp3C->actionState = 3;
                sp3C->unk132 = 0;
            }
            break;
        case 2:
            if (func_8001B62C(gCurrentParsedObject, 0) > 14.0f) {
                if (sp3C->unkAC == 7) {
                    sp38 = func_80027464(1, &D_bagular1_803331A0, sp3C->Pos.x, sp3C->Pos.y, sp3C->Pos.z, sp3C->Rot.y);
                    sp3C->unkAC = 0;
                } else {
                    sp3C->unkAC += 1;
                }
            }
            sp3C->unkB8 = sp3C->damageState;
            sp3C->damageState = 0;
            if (func_8001B62C(gCurrentParsedObject, 0) > 30.0f) {
                sp3C->Vel.y = 0.5f;
            }
            if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
                sp3C->unkC4 = 1;
                func_8001BB34(gCurrentParsedObject, 1);
                func_8001BB34((s32) sp3C->unkC2, 1);
                sp3C->unkC0 = 1;
                sp3C->Vel.y = 0.0f;
                sp38 = func_80027464(1, &D_bagular1_80333194, sp3C->Pos.x, sp3C->Pos.y, sp3C->Pos.z, sp3C->Rot.y);
                gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
                sp3C->actionState = 5;
                sp3C->unk132 = 0;
            }
            break;
        default:
            break;
    }
}

void func_bagular1_80330844(void) {
    struct ObjectStruct* sp34;
    UNUSED s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        sp34->unkA8 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x135, &D_8011B0A0);
        sp34->unkB0 = 0;
    }
    if (sp34->unk132 == 1) {
        func_bagular1_80331880(D_bagular1_8033305C[(s16) (s32) (func_8001B62C(gCurrentParsedObject, 0) / 2.0f)]);
        func_8002A8B4(gCurrentParsedObject, 6.0f);
        sp34->Rot.y = sp34->moveAngle;
        if (func_8001B62C(gCurrentParsedObject, 0) == 56.0f) {
            sp34->unk132 += 1;
            func_8001BBDC(gCurrentParsedObject, 1);
            sp34->moveSpeed = 30.0f;
            sp34->unkAC = 0;
            func_800175F0(gCurrentParsedObject, 0, 0x37, -1, 0);
        }
    }
    if ((sp34->unk132 == 2)) {
        if ((sp34->damageState == OBJ_DAMAGE_STATE_NORMAL)) {
            sp34->damageState = OBJ_INVENCIBLE;
        }
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->moveSpeed = 0.0f;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.z;
        func_8001BBDC(gCurrentParsedObject, 0);
        sp34->unk132 = 3;
    }
    if (((sp34->Pos.x + sp34->Vel.x) > 480.0f) || ((sp34->Pos.x + sp34->Vel.x) < -480.0f) ||
        (((sp34->Pos.z + sp34->Vel.z) > 480.0f)) || ((sp34->Pos.z + sp34->Vel.z) < -480.0f)) {
        sp34->moveSpeed = 0.0f;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.z;
        func_8001BBDC(gCurrentParsedObject, 0);
        sp34->unk132 = 3;
    }
    if (sp34->unk132 == 2) {
        func_bagular1_80331880(D_bagular1_803330A8[sp34->unkA8]);
        if (sp34->unkAC == 7) {
            sp30 = func_80027464(1, &D_bagular1_803331AC, sp34->Pos.x + sp34->Vel.x, sp34->Pos.y,
                                 sp34->Pos.z + sp34->Vel.z, sp34->Rot.y);
            sp34->unkAC = 0;
        } else {
            sp34->unkAC += 1;
        }
        if (sp34->unkA8 == 0x2F) {
            sp34->unk132 += 1;
            func_8001BBDC(gCurrentParsedObject, 0);
            sp34->moveSpeed = 0.0f;
            sp34->Vel.z = 0.0f;
            sp34->Vel.x = sp34->Vel.z;
            sp34->unkA8 += 1;
        } else {
            sp34->unkA8 += 1;
        }
    }
    if (sp34->unk132 == 3) {
        func_bagular1_80331880(D_bagular1_8033305C[(s16) (s32) (func_8001B62C(gCurrentParsedObject, 0) / 2.0f)]);
        if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
            if ((func_bagular1_80331A34(480.0f) == 1) || (func_bagular1_80331B74(480.0f) == 1)) {
                sp34->unkA6 = 2;
            } else {
                if (sp34->damageState == -1) {
                    sp34->damageState = 1;
                }
                if (func_8002A2EC(gCurrentParsedObject, 600.0f) != 0) {
                    sp34->unkA6 = 1;
                } else {
                    sp34->unkA6 = 0;
                }
            }
            sp34->actionState = 2;
            sp34->unk132 = 0;
        }
    }
}

void func_bagular1_80330EA4(void) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x135, &D_8011B0A0);
        sp30 = func_80027464(1, &D_bagular1_80333170, sp34->Pos.x, sp34->Pos.y, sp34->Pos.z, sp34->Rot.y);
        gObjects[sp30].unkC2 = (s16) gCurrentParsedObject;
        sp34->unkAE += 1;
    }
    func_bagular1_80331880(D_bagular1_80333108[(s16) (s32) (func_8001B62C(gCurrentParsedObject, 0) / 2.0f)]);
    if (func_8001B62C(gCurrentParsedObject, 0) < 24.0f) {
        func_8002A8B4(gCurrentParsedObject, 6.0f);
        sp34->Rot.y = sp34->moveAngle;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp34->unkAE >= 3) {
            sp34->unkA6 = 2;
            sp34->actionState = 2;
            sp34->unk132 = 0;
            sp34->unkAE = 0;
        } else if (func_8002A2EC(gCurrentParsedObject, 600.0f) != 0) {
            sp34->unkA6 = 1;
            sp34->actionState = 2;
            sp34->unk132 = 0;
        } else {
            sp34->actionState = 1;
            sp34->unk132 = 0;
        }
    }
}

void func_bagular1_80331148(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x135, &D_8011B0A0);
        func_8001BBDC(gCurrentParsedObject, 1);
        sp34->unkB6 = 0;
        func_800175F0(gCurrentParsedObject, 0, 0x23, -1, 0);
    }
    if (sp34->damageState == 1) {
        sp34->damageState = 0;
    }
    func_bagular1_80331880(D_bagular1_80332FC0[(s16) (s32) (func_8001B62C(gCurrentParsedObject, 0) / 2.0f)]);
    if (sp34->unkB6 == 0) {
        func_8001BB34((s32) sp34->unkC2, 1);
        func_8001BB34(gCurrentParsedObject, 1);
    }
    if (sp34->unkB6 == 1) {
        func_8001BB34((s32) sp34->unkC2, 0);
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BB34((s32) sp34->unkC2, 0);
        sp34->unkC4 = 0;
        sp34->unkC0 = 0;
        sp34->Vel.y = -0.5f;
        sp34->unkB6 = 2;
    }
    if ((sp34->unkB6 == 2) && (func_8001B4AC(gCurrentParsedObject, 0) != 0)) {
        if (func_800295C0(gCurrentParsedObject, &sp30, &sp2C, 0.0f, 0.0f, 0.0f) != 0) {
            sp34->Pos.y = sp2C;
        } else {
            sp34->Pos.y = sp30;
        }
        sp34->Vel.y = 0.0f;
        if (func_8002A2EC(gCurrentParsedObject, 600.0f) != 0) {
            sp34->unkA6 = 1;
        } else if (func_bagular1_80331A34(600.0f) != 0) {
            sp34->unkA6 = 1;
        } else {
            sp34->unkA6 = 0;
        }
        sp34->actionState = 2;
        sp34->unk132 = 0;
        sp34->unkB6 = 0;
        sp34->unkAE = 0;
    }
}

void func_bagular1_803314BC(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        sp24->unkBC = 0x5A;
        sp24->unkA6 = 0x3C;
        sp24->unkAA = 0;
        func_80069E60(0, 0, 0x96);
    }
    if (sp24->unkAA == 1) {
        func_8001BB34(gCurrentParsedObject, 1);
        if (sp24->unkA6 == 0) {
            func_8002B114(gCurrentParsedObject);
        } else {
            sp24->unkA6 -= 1;
        }
    } else if (sp24->unkBC == 0) {
        func_8002B114((s32) sp24->unkC2);
        func_8001BB34(gCurrentParsedObject, 1);
        sp24->unkAA = 1;
    } else if (sp24->unkBC == 0x4B) {
        sp20 = func_80027464(1, &D_bagular1_803331B8, sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, sp24->Rot.y);
        gObjects[sp20].unkC2 = (s16) gCurrentParsedObject;
        sp24->unkBC -= 1;
    } else {
        sp24->unkBC -= 1;
    }
}

void func_bagular1_803316EC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->damageState == 0) {
        func_8001BB34(gCurrentParsedObject, !(sp24->unkBC & 1));
    } else if ((sp24->damageState != -1)) {
        if ((sp24->unkC0 == 0)) {
            func_8001BB34(gCurrentParsedObject, !(sp24->damageState & 1));
        }
    }
    switch (sp24->actionState) {
        case 1:
            func_bagular1_803301D4();
            break;
        case 2:
            func_bagular1_803303D0();
            break;
        case 3:
            func_bagular1_80330844();
            break;
        case 4:
            func_bagular1_80330EA4();
            break;
        case 5:
            func_bagular1_80331148();
            break;
        case 6:
            func_bagular1_803314BC();
            break;
        default:
            break;
    }
}

void func_bagular1_80331880(s16 arg0) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    D_bagular1_80333164[0].unk6 = (s8) arg0;
    sp30 = func_80027464(1, D_bagular1_80333164, sp34->Pos.x + sp34->Vel.x, sp34->Pos.y + sp34->Vel.y,
                         sp34->Pos.z + sp34->Vel.z, sp34->Rot.y);
    if (sp34->unkC2 != 0) {
        func_8002B114((s32) sp34->unkC2);
    }
    sp34->unkC2 = (s16) sp30;
    if (sp34->damageState == 0) {
        if (sp34->unk100 == 0) {
            func_8001BB34(sp30, 0);
        } else if (sp34->unkC4 == 1) {
            func_8001BB34(sp30, 1);
        } else {
            func_8001BB34(sp30, 0);
        }
    } else if (sp34->damageState != -1) {
        func_8001BB34(sp30, !(sp34->damageState & 1));
    }
}

s32 func_bagular1_80331A34(f32 arg0) {
    struct ObjectStruct* spC;
    f32 sp8;
    f32 sp4;
    s32 sp0;

    spC = &gObjects[gCurrentParsedObject];
    for (sp0 = 2; sp0 < 6; sp0++) {
        if (gObjects[sp0].actionState != 0) {
            sp8 = gObjects[sp0].Pos.x - spC->Pos.x;
            sp4 = gObjects[sp0].Pos.z - spC->Pos.z;
            if ((SQ(sp8) + SQ(sp4)) < SQ(arg0)) {
                return 1;
            }
        }
    }
    return 0;
}

s32 func_bagular1_80331B74(f32 arg0) {
    struct ObjectStruct* spC;
    f32 sp8;
    f32 sp4;
    s32 sp0;

    spC = &gObjects[gCurrentParsedObject];
    for (sp0 = 6; sp0 < 14; sp0++) {
        if (gObjects[sp0].actionState != 0) {
            sp8 = gObjects[sp0].Pos.x - spC->Pos.x;
            sp4 = gObjects[sp0].Pos.z - spC->Pos.z;
            if ((SQ(sp8) + SQ(sp4)) < SQ(arg0)) {
                return 1;
            }
        }
    }
    return 0;
}

void func_bagular1_80331CB4(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x137, &D_8011B0B4);
    }
    if (sp34->unk132 == 1) {
        sp34->Rot.y = gObjects[sp34->unkC2].Rot.y;
        sp34->moveAngle = gObjects[sp34->unkC2].Rot.y;
    }
    if ((sp34->unk132 == 1) && (func_8001B62C(gCurrentParsedObject, 3) > 56.0f)) {
        sp34->unk132 += 1;
        func_800175F0(gCurrentParsedObject, 0, 0x42, -1, 0);
        sp2C = sinf((f32) ((f64) sp34->moveAngle * DEG_TO_RAD)) * 60.0f;
        sp28 = cosf((f32) ((f64) sp34->moveAngle * DEG_TO_RAD)) * 60.0f;
        sp30 = func_80027464(1, &D_bagular1_8033317C, sp34->Pos.x + sp2C, sp34->Pos.y, sp34->Pos.z + sp28, sp34->Rot.y);
        gObjects[sp30].unkC2 = sp34->unkC2;
        sp30 = func_80027464(1, &D_bagular1_80333188, sp34->Pos.x + sp2C, sp34->Pos.y - 340.0f, sp34->Pos.z + sp28,
                             sp34->Rot.y);
        gObjects[sp30].unkC2 = sp34->unkC2;
        sp24 = Math_WrapAngle(sp34->Rot.y, 30.0f);
        sp2C = sinf((f32) ((f64) sp24 * DEG_TO_RAD)) * 60.0f;
        sp28 = cosf((f32) ((f64) sp24 * DEG_TO_RAD)) * 60.0f;
        sp30 = func_80027464(1, &D_bagular1_8033317C, sp34->Pos.x + sp2C, sp34->Pos.y, sp34->Pos.z + sp28, sp24);
        gObjects[sp30].unkC2 = sp34->unkC2;
        sp30 =
            func_80027464(1, &D_bagular1_80333188, sp34->Pos.x + sp2C, sp34->Pos.y - 340.0f, sp34->Pos.z + sp28, sp24);
        gObjects[sp30].unkC2 = sp34->unkC2;
        sp24 = Math_WrapAngle(sp34->Rot.y, -30.0f);
        sp2C = sinf((f32) ((f64) sp24 * DEG_TO_RAD)) * 60.0f;
        sp28 = cosf((f32) ((f64) sp24 * DEG_TO_RAD)) * 60.0f;
        sp30 = func_80027464(1, &D_bagular1_8033317C, sp34->Pos.x + sp2C, sp34->Pos.y, sp34->Pos.z + sp28, sp24);
        gObjects[sp30].unkC2 = sp34->unkC2;
        sp30 =
            func_80027464(1, &D_bagular1_80333188, sp34->Pos.x + sp2C, sp34->Pos.y - 340.0f, sp34->Pos.z + sp28, sp24);
        gObjects[sp30].unkC2 = sp34->unkC2;
    }
    if (func_8001B4AC(gCurrentParsedObject, 3) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
    if (gObjects[sp34->unkC2].unkBE == 1) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_bagular1_80332304(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x138, &D_8011B0B8);
        sp24->moveSpeed = 24.0f;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 190.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->moveSpeed = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    if (func_8001B4AC(gCurrentParsedObject, 3) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
    if (gObjects[sp24->unkC2].unkBE == 1) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_bagular1_8033249C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->moveSpeed = 24.0f;
        sp24->Vel.y = 20.0f;
        sp24->unkA6 = 0x10;
        func_8001BB34(gCurrentParsedObject, 1);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 190.0f, 0.0f, 400.0f, 0.0f) != 0) {
        sp24->moveSpeed = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    if (sp24->unkA6 == 0) {
        sp24->Vel.y = -20.0f;
    } else if (sp24->unkA6 < -0xF) {
        func_8002B114(gCurrentParsedObject);
    } else {
        sp24->unkA6 -= 1;
    }
    if (gObjects[sp24->unkC2].unkBE == 1) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_bagular1_80332694(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x139, &D_8011B0BC);
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_8011B104);
    }
    if (func_8001B4AC(gCurrentParsedObject, 3) != 0) {
        sp20 = Math_Random(-0x191);
        sp24->Pos.x = (f32) sp20;
        gObjects[sp24->unkC2].Pos.x = sp24->Pos.x;
        sp20 = Math_Random(-0x191);
        sp24->Pos.z = (f32) sp20;
        gObjects[sp24->unkC2].Pos.z = sp24->Pos.z;
        sp24->moveAngle = Get_AngleToPlayer(gCurrentParsedObject);
        sp24->Rot.y = sp24->moveAngle;
        gObjects[sp24->unkC2].Rot.y = sp24->Rot.y;
        gObjects[sp24->unkC2].moveAngle = sp24->moveAngle;
        sp24->actionState = 2;
        sp24->unk132 = 0;
    }
}

void func_bagular1_803328BC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 3, 1, 0x139, &D_8011B0BC);
    }
    if (func_8001B4AC(gCurrentParsedObject, 3) != 0) {
        if ((func_bagular1_80331A34(360.0f) == 1) || (func_bagular1_80331B74(360.0f) == 1) ||
            (func_8002A1FC(gCurrentParsedObject, 360.0f) == 1)) {
            sp24->actionState = 1;
            sp24->unk132 = 0;
        } else {
            gObjects[sp24->unkC2].Pos.x = sp24->Pos.x;
            gObjects[sp24->unkC2].Pos.y = sp24->Pos.y;
            gObjects[sp24->unkC2].Pos.z = sp24->Pos.z;
            gObjects[sp24->unkC2].Rot.y = sp24->Rot.y;
            gObjects[sp24->unkC2].unkB6 = 1;
            func_8002B114(gCurrentParsedObject);
        }
    }
}

void func_bagular1_80332AE0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->actionState) { /* irregular */
        case 1:
            func_bagular1_80332694();
            break;
        case 2:
            func_bagular1_803328BC();
            break;
        default:
            break;
    }
    if (gObjects[sp24->unkC2].unkBE == 1) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_bagular1_80332BCC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x13B, &D_8011B124);
    }
    if (func_8001B4AC(gCurrentParsedObject, 3) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_bagular1_80332C94(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x13A, &D_8011B120);
    }
    if (func_8001B4AC(gCurrentParsedObject, 3) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_bagular1_80332D5C(void) {
    struct ObjectStruct* sp24;
    UNUSED s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x13C, &D_8011B128);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B16C);
        sp24->unkA6 = 0x4B;
        sp24->unkA8 = 0x96;
        sp24->unkAC = 0;
    }
    func_8001BB34(gCurrentParsedObject, sp24->unkA6 & 1);
    if (sp24->unkAC == 0xF) {
        sp20 = func_80027464(1, &D_bagular1_803331A0, sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, sp24->Rot.y);
        sp24->unkAC = 0;
    } else {
        sp24->unkAC += 1;
    }
    if (sp24->unkA6 != 0) {
        sp24->unkA6 -= 1;
    } else {
        sp24->unkA6 = 0;
    }
    if (sp24->unkA8 == 0) {

    } else {
        sp24->unkA8 -= 1;
    }
}

void func_bagular1_80332F3C(void) {
    UNUSED s32 sp24;

    sp24 = func_80027464(1, &D_bagular1_803331D0, (f32) D_80165100->unk2, (f32) D_80165100->unk4,
                         (f32) D_80165100->unk6, (f32) D_80165100->unk8);
}
