#include "common.h"

s32 func_bagular2_80330000(f32 arg0);  /* static */
s32 func_bagular2_80330188(f32 arg0);  /* static */
void func_bagular2_803302C8();         /* static */
void func_bagular2_803303AC(f32 arg0); /* static */
void func_bagular2_803304B8(f32 arg0); /* static */
void func_bagular2_803305C0(s32 arg0); /* static */
void func_bagular2_80330894();         /* static */
void func_bagular2_80330A90();         /* static */
void func_bagular2_80330CD0();         /* static */
void func_bagular2_80330F08();         /* static */
void func_bagular2_80331064();         /* static */
void func_bagular2_803311B4();         /* static */
void func_bagular2_8033124C();         /* static */
void func_bagular2_80331438();         /* static */
void func_bagular2_803317E4();         /* static */
void func_bagular2_80331D0C();         /* static */
void func_bagular2_80331E90();         /* static */
void func_bagular2_80332718();         /* static */
void func_bagular2_803328F8();         /* static */
void func_bagular2_80332B6C();         /* static */
void func_bagular2_80332C58();         /* static */
void func_bagular2_80333074();         /* static */
void func_bagular2_80333248();         /* static */
void func_bagular2_80333370();         /* static */
void func_bagular2_80333544();         /* static */
void func_bagular2_8033382C();         /* static */
void func_bagular2_80333B20();         /* static */
void func_bagular2_80333C4C();         /* static */
void func_bagular2_80333F8C();         /* static */
void func_bagular2_803341C8();         /* static */
extern u32 D_8011B190;
extern UNK_TYPE D_8011B290;
extern u32 D_8011B338;
extern UNK_TYPE D_8011B3D4;
extern u32 D_8011B40C;
extern u32 D_8011B414;
extern u32 D_8011B418;

extern s16 D_803344D0[4];

static struct ObjSpawnInfo D_bagular2_80334410[3] = {
    { 0, OBJ_BAG2_BD2, 0x13D, 7, -1, 0, 0, 0 },
    { 3, OBJ_BAG2_NO, 0x13E, 2, -1, 0, 0, 0 },
    { 3, OBJ_BAG2_KZ, 0x13F, 2, -1, 0, 0, 0 },
};
static struct ObjSpawnInfo D_bagular2_80334434[1] = {{ 0, OBJ_BAG2_AT1, 0x142, 2, -1, 0, 0, 0 }};
static struct ObjSpawnInfo D_bagular2_80334440[1] = {{ 0, OBJ_BAG2_AT2, 0x143, 1, -1, 1, 1, 0 }};
static struct ObjSpawnInfo D_bagular2_8033444C[1] = {{ 0, OBJ_BAG2_AT3, 0x143, 1, -1, 0, 0, 0 }};

static struct ObjSpawnInfo D_bagular2_80334458[3] = {
    { 0, OBJ_BAG2_BD, 0x13D, 7, 6, 1, 1, 0 },
    { 3, OBJ_BAG2_NO, 0x13E, 2, -1, -1, 1, 1 },
    { 3, OBJ_BAG2_KZ, 0x13F, 2, -1, 0, 0, 1 },
};

s32 func_bagular2_80330000(f32 arg0) {
    struct ObjectStruct* sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 sp4;

    sp14 = &gObjects[gCurrentParsedObject];
    for (sp4 = 2; sp4 < 6; sp4++) {
        if (gObjects[sp4].actionState != 0) {
            sp10 = gObjects[sp4].Pos.x - sp14->Pos.x;
            spC = gObjects[sp4].Pos.y - (sp14->Pos.y - 170.0f);
            sp8 = gObjects[sp4].Pos.z - sp14->Pos.z;

            if ((SQ(sp10) + SQ(spC) + SQ(sp8)) < SQ(arg0)) {
                return 1;
            }
        }
    }
    return 0;
}

s32 func_bagular2_80330188(f32 arg0) {
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

void func_bagular2_803302C8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (((func_bagular2_80330000(180.0f) == 1) || (func_bagular2_80330188(180.0f) == 1)) && (sp24->unkAE <= 0)) {
        sp24->unkAE = 0x3E;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 35);
        func_800175F0(gCurrentParsedObject, 0, 0x3B, -1, 0);
    }
}

void func_bagular2_803303AC(f32 arg0) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (func_8002A2EC(gCurrentParsedObject, arg0) != 0) {
        sp20 = func_80027464(1, D_bagular2_80334434, sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, sp24->Rot.y);
        gObjects[sp20].unkC2 = (s16) gCurrentParsedObject;
        gObjects[sp20].unkC0 = 1;
        sp24->unkAC = (s16) sp20;
        sp24->unkAA = 1;
    }
}

void func_bagular2_803304B8(f32 arg0) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (func_8002A2EC(gCurrentParsedObject, arg0) != 0) {
        sp20 = func_80027464(1, D_bagular2_80334434, sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, sp24->Rot.y);
        gObjects[sp20].unkC2 = (s16) gCurrentParsedObject;
        gObjects[sp20].unkC0 = 0;
        sp24->unkAC = (s16) sp20;
        sp24->unkAA = 1;
    }
}

void func_bagular2_803305C0(s32 arg0) {
    s16 sp2E;
    s32 sp28;

    sp2E = 0;
    if (sp2E == 0) {
        do {
            sp28 = Math_Random(4);
            switch (sp28) {
                case 0:
                    if (D_803344D0[0] == 0) {
                        D_803344D0[0] = 1;
                        sp2E = 1;
                        gObjects[arg0].Pos.x = 300.0f;
                        gObjects[arg0].Pos.z = 300.0f;
                    }
                    break;
                case 1:
                    if (D_803344D0[1] == 0) {
                        D_803344D0[1] = 1;
                        sp2E = 1;
                        gObjects[arg0].Pos.x = 300.0f;
                        gObjects[arg0].Pos.z = -300.0f;
                    }
                    break;
                case 2:
                    if (D_803344D0[2] == 0) {
                        D_803344D0[2] = 1;
                        sp2E = 1;
                        gObjects[arg0].Pos.x = -300.0f;
                        gObjects[arg0].Pos.z = -300.0f;
                    }
                    break;
                case 3:
                    if (D_803344D0[3] == 0) {
                        D_803344D0[3] = 1;
                        sp2E = 1;
                        gObjects[arg0].Pos.x = -300.0f;
                        gObjects[arg0].Pos.z = 300.0f;
                    }
                    break;
            }
        } while (sp2E == 0);
    }
}

void func_bagular2_80330894(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unkE8[0] != -1) {
        gObjects[sp4->unkE8[0]].Pos.x = sp4->Pos.x + sp4->Vel.x;
        gObjects[sp4->unkE8[0]].Pos.y = sp4->Pos.y + sp4->Vel.y;
        gObjects[sp4->unkE8[0]].Pos.z = sp4->Pos.z + sp4->Vel.z;
        gObjects[sp4->unkE8[0]].Rot.x = sp4->Rot.x;
        gObjects[sp4->unkE8[0]].Rot.y = sp4->Rot.y;
        gObjects[sp4->unkE8[0]].Rot.z = sp4->Rot.z;
        gObjects[sp4->unkE8[0]].Scale.x = sp4->Scale.x;
        gObjects[sp4->unkE8[0]].Scale.y = sp4->Scale.y;
        gObjects[sp4->unkE8[0]].Scale.z = sp4->Scale.z;
    }
}

void func_bagular2_80330A90(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unkE8[1] != -1) {
        gObjects[sp2C->unkE8[1]].unkD4 += 1.0f;
        if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
            sp20 = sp24;
        } else {
            sp20 = sp28;
        }
        gObjects[sp2C->unkE8[1]].Pos.x = sp2C->Pos.x + sp2C->Vel.x;
        if ((sp20 - gObjects[sp2C->unkE8[1]].Pos.y) >= 60.0f) {
            gObjects[sp2C->unkE8[1]].unkD4 = 0.0f;
            gObjects[sp2C->unkE8[1]].Pos.y = sp20 - 60.0f;
        } else {
            gObjects[sp2C->unkE8[1]].Pos.y = sp20 - gObjects[sp2C->unkE8[1]].unkD4;
        }
        gObjects[sp2C->unkE8[1]].Pos.z = sp2C->Pos.z + sp2C->Vel.z;
    }
}

void func_bagular2_80330CD0(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unkE8[1] != -1) {
        gObjects[sp2C->unkE8[1]].unkD4 += 1.0f;
        if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
            sp20 = sp24;
        } else {
            sp20 = sp28;
        }
        gObjects[sp2C->unkE8[1]].Pos.x = sp2C->Pos.x + sp2C->Vel.x;
        if ((sp20 - gObjects[sp2C->unkE8[1]].Pos.y) <= 0.0f) {
            gObjects[sp2C->unkE8[1]].unkD4 = 0.0f;
            gObjects[sp2C->unkE8[1]].Pos.y = sp20;
        } else {
            gObjects[sp2C->unkE8[1]].Pos.y = gObjects[sp2C->unkE8[1]].unkD4 + (sp20 - 60.0f);
        }
        gObjects[sp2C->unkE8[1]].Pos.z = sp2C->Pos.z + sp2C->Vel.z;
    }
}

void func_bagular2_80330F08(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    sp2C->unkD4 = 0.0f;
    if (sp2C->unkE8[1] != -1) {
        if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
            sp20 = sp24;
        } else {
            sp20 = sp28;
        }
        gObjects[sp2C->unkE8[1]].Pos.x = sp2C->Pos.x + sp2C->Vel.x;
        gObjects[sp2C->unkE8[1]].Pos.y = sp20 - 60.0f;
        gObjects[sp2C->unkE8[1]].Pos.z = sp2C->Pos.z + sp2C->Vel.z;
    }
}

void func_bagular2_80331064(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    sp2C->unkD4 = 0.0f;
    if (sp2C->unkE8[1] != -1) {
        if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
            sp20 = sp24;
        } else {
            sp20 = sp28;
        }
        gObjects[sp2C->unkE8[1]].Pos.x = sp2C->Pos.x + sp2C->Vel.x;
        gObjects[sp2C->unkE8[1]].Pos.y = sp20;
        gObjects[sp2C->unkE8[1]].Pos.z = sp2C->Pos.z + sp2C->Vel.z;
    }
}

void func_bagular2_803311B4(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unkBC == 0) {
        sp4->Vel.y = -sp4->Vel.y;
        sp4->unkBC = 0xE;
    } else {
        sp4->unkBC -= 1;
    }
}

void func_bagular2_8033124C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unkBA == 0) {
        sp1C->unkD8 = -sp1C->unkD8;
        sp1C->Rot.z = Math_WrapAngle(sp1C->Rot.z, sp1C->unkD8);
        sp1C->unkBA = 0x10;
    } else {
        sp1C->Rot.z = Math_WrapAngle(sp1C->Rot.z, sp1C->unkD8);
        sp1C->unkBA -= 1;
    }
    if (sp1C->unkB8 == 0) {
        if (sp1C->unkDC == 0.0f) {
            sp1C->unkDC = 0.3f;
            sp1C->unkB8 = 8;
        } else {
            sp1C->unkDC = -sp1C->unkDC;
            sp1C->unkB8 = 0x10;
        }
        sp1C->Rot.x = Math_WrapAngle(sp1C->Rot.x, sp1C->unkDC);
    } else {
        if (sp1C->unkDC != 0.0f) {
            sp1C->Rot.x = Math_WrapAngle(sp1C->Rot.x, sp1C->unkDC);
        }
        sp1C->unkB8 -= 1;
    }
}

void func_bagular2_80331438(void) {
    s32 sp2C;
    f32 sp28;
    f32 sp24;
    s16 sp22;

    func_800175F0(gCurrentParsedObject, 0, 5, -1, 0);
    sp2C = func_80027464(3, D_bagular2_80334458, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    func_8001ABF4(sp2C, 1, 0, &D_8011B290);
    func_8001ABF4(sp2C, 0, 0, &D_8011B290 + 35);
    func_8001ABF4((s32) gObjects[sp2C].unkE8[0], 0, 3, &D_8011B3D4);
    func_8001C0EC(sp2C, 0, 0, 0x13D, &D_8011B190);
    func_8001C0EC((s32) gObjects[sp2C].unkE8[0], 3, 0, 0x13E, &D_8011B338);
    func_8001C0EC((s32) gObjects[sp2C].unkE8[1], 3, 0, 0x13F, &D_8011B40C);
    if (func_800295C0(sp2C, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        gObjects[sp2C].Pos.y = sp24;
    } else {
        gObjects[sp2C].Pos.y = sp28;
    }
    gObjects[sp2C].Pos.y += 420.0f;
    gObjects[sp2C].Vel.y = 1.2f;
    gObjects[sp2C].unkBC = 0xF;
    gObjects[sp2C].unkD8 = 0.3f;
    gObjects[sp2C].unkBA = 8;
    gObjects[sp2C].unkDC = 0.0f;
    gObjects[sp2C].unkB8 = 8;
    for (sp22 = 0; sp22 < 4; sp22++) {
        D_803344D0[sp22] = 0;
    }
    func_800175F0(gCurrentParsedObject, 0, 0x3B, -1, 0);
}

void func_bagular2_803317E4(void) {
    struct ObjectStruct* sp1C;
    s16 sp1A;
    UNUSED s16 temp_t9;

    sp1C = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp1C->damageState = 0;
        func_80069E60(0, 1, 0x12C);
        gObjects[sp1C->unkE8[0]].damageState = 0;
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_8011B290 + 7);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 28);
        func_8001ABF4((s32) sp1C->unkE8[0], 0, 3, &D_8011B3D4 + 7);
        sp1C->Vel.z = 0.0f;
        sp1C->Vel.x = sp1C->Vel.z;
        sp1C->moveSpeed = 0.0f;
        if (gObjects[sp1C->unkC0].actionState != 0) {
            gObjects[sp1C->unkC0].actionState = 0x63;
            gObjects[sp1C->unkC0].unk132 = 0;
        }
        if (gObjects[sp1C->unkC2].actionState != 0) {
            gObjects[sp1C->unkC2].actionState = 0x63;
            gObjects[sp1C->unkC2].unk132 = 0;
        }
        sp1C->actionState = 0x63;
        sp1C->unk132 = 0;
    } else if (D_80177A64 == 1) {
        sp1C->damageState = 0x78;
        gObjects[sp1C->unkE8[0]].damageState = 0x78;
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_8011B290 + 7);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 28);
        func_8001ABF4((s32) sp1C->unkE8[0], 0, 3, &D_8011B3D4 + 7);
        sp1C->Vel.z = 0.0f;
        sp1C->Vel.x = sp1C->Vel.z;
        sp1C->moveSpeed = 0.0f;
        sp1C->actionState = 1;
        sp1C->unk132 = 0;
        if (gObjects[sp1C->unkC0].actionState != 0) {
            gObjects[sp1C->unkC0].actionState = 0x63;
            gObjects[sp1C->unkC0].unk132 = 0;
        }
        if (gObjects[sp1C->unkC2].actionState != 0) {
            gObjects[sp1C->unkC2].actionState = 0x63;
            gObjects[sp1C->unkC2].unk132 = 0;
        }
        if (sp1C->unkAC != 0) {
            sp1C->unkAA = 0;
            func_8002B114((s32) sp1C->unkAC);
            sp1C->unkAC = 0;
        }
        for (sp1A = 0; sp1A < 4; sp1A++) {
            D_803344D0[sp1A] = 0;
        }
    }
    func_bagular2_8033124C();
    func_bagular2_803311B4();
    func_bagular2_80330894();
    func_bagular2_80331064();
}

void func_bagular2_80331D0C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        sp1C->unkB2 = sp1C->actionState;
    }
    if (sp1C->damageState == 1) {
        sp1C->damageState = -1;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp1C->Rot.y = sp1C->moveAngle;
    if (sp1C->Pos.y >= 1200.0f) {
        sp1C->Pos.y = 1200.0f;
        sp1C->Vel.y = 0.0f;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 21);
        sp1C->actionState = 2;
        sp1C->unk132 = 0;
    } else {
        sp1C->Vel.y = 8.0f;
    }
    func_bagular2_8033124C();
    func_bagular2_80330894();
    func_bagular2_80330A90();
}

void func_bagular2_80331E90(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    UNUSED s32 pad2C;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 21);
        func_8001ABF4((s32) sp34->unkE8[0], 0, 3, &D_8011B3D4);
        if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
            sp34->Pos.y = sp24;
        } else {
            sp34->Pos.y = sp28;
        }
        sp34->Pos.y += 1200.0f;
        func_bagular2_803305C0(gCurrentParsedObject);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp34->Rot.y = sp34->moveAngle;
    sp30 = func_80027464(3, D_bagular2_80334410, sp34->Pos.x, sp34->Pos.y, sp34->Pos.z, sp34->Rot.y);
    func_8001ABF4(sp30, 1, 0, &D_8011B290);
    func_8001ABF4(sp30, 0, 0, &D_8011B290 + 21);
    func_8001ABF4((s32) gObjects[sp30].unkE8[0], 0, 3, &D_8011B3D4);
    func_8001C0EC(sp30, 0, 0, 0x13D, &D_8011B190);
    func_8001C0EC((s32) gObjects[sp30].unkE8[0], 3, 0, 0x13E, &D_8011B338);
    func_8001C0EC((s32) gObjects[sp30].unkE8[1], 3, 0, 0x13F, &D_8011B40C);
    if (func_800295C0(sp30, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        gObjects[sp30].Pos.y = sp24;
    } else {
        gObjects[sp30].Pos.y = sp28;
    }
    gObjects[sp30].Pos.y += 1200.0f;
    gObjects[sp30].unkA6 = -1;
    gObjects[sp30].Vel.y = 1.2f;
    gObjects[sp30].unkBC = 0xF;
    gObjects[sp30].unkD8 = 0.3f;
    gObjects[sp30].unkBA = 8;
    gObjects[sp30].unkDC = 0.0f;
    gObjects[sp30].unkB8 = 8;
    gObjects[sp30].unkC2 = (s16) gCurrentParsedObject;
    sp34->unkC0 = (s16) sp30;
    sp34->unkC4 = 0x3C;
    func_bagular2_803305C0(sp30);
    sp30 = func_80027464(3, D_bagular2_80334410, sp34->Pos.x, sp34->Pos.y, sp34->Pos.z, sp34->Rot.y);
    func_8001ABF4(sp30, 1, 0, &D_8011B290);
    func_8001ABF4(sp30, 0, 0, &D_8011B290 + 21);
    func_8001ABF4((s32) gObjects[sp30].unkE8[0], 0, 3, &D_8011B3D4);
    func_8001C0EC(sp30, 0, 0, 0x13D, &D_8011B190);
    func_8001C0EC((s32) gObjects[sp30].unkE8[0], 3, 0, 0x13E, &D_8011B338);
    func_8001C0EC((s32) gObjects[sp30].unkE8[1], 3, 0, 0x13F, &D_8011B40C);
    if (func_800295C0(sp30, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        gObjects[sp30].Pos.y = sp24;
    } else {
        gObjects[sp30].Pos.y = sp28;
    }
    gObjects[sp30].Pos.y += 1200.0f;
    gObjects[sp30].unkA6 = -1;
    gObjects[sp30].Vel.y = 1.2f;
    gObjects[sp30].unkBC = 0xF;
    gObjects[sp30].unkD8 = 0.3f;
    gObjects[sp30].unkBA = 8;
    gObjects[sp30].unkDC = 0.0f;
    gObjects[sp30].unkB8 = 8;
    gObjects[sp30].unkC2 = (s16) gCurrentParsedObject;
    sp34->unkC2 = (s16) sp30;
    sp34->unkB4 = 0x1E;
    sp34->unkC4 = 0x3C;
    func_bagular2_803305C0(sp30);
    func_bagular2_8033124C();
    func_bagular2_803311B4();
    func_bagular2_80330894();
    func_bagular2_80330F08();
    sp34->actionState = 3;
    sp34->unk132 = 0;
}

void func_bagular2_80332718(void) {
    struct ObjectStruct* sp34;
    UNUSED s32 pad30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        sp34->damageState = 1;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 21);
        func_8001ABF4((s32) sp34->unkE8[0], 0, 3, &D_8011B3D4);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp34->Rot.y = sp34->moveAngle;
    if (func_800295C0(gCurrentParsedObject, &sp2C, &sp28, 0.0f, 0.0f, 0.0f) != 0) {
        sp24 = sp28;
    } else {
        sp24 = sp2C;
    }
    sp24 += 420.0f;
    if (sp34->Pos.y <= sp24) {
        sp34->Pos.y = sp24;
        sp34->Vel.y = 0.0f;
        sp34->actionState = 4;
        sp34->unk132 = 0;
    } else {
        sp34->Vel.y = -12.0f;
    }
    func_bagular2_8033124C();
    func_bagular2_80330894();
    func_bagular2_80330CD0();
}

void func_bagular2_803328F8(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
        sp2C->moveSpeed = 9.0f;
        sp2C->unkB6 = 0;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 21);
        func_8001ABF4((s32) sp2C->unkE8[0], 0, 3, &D_8011B3D4);
    }
    if (sp2C->unkB6 == 0) {
        sp2C->moveAngle = Math_WrapAngle(sp2C->moveAngle, (f32) Math_Random(0x168));
        sp2C->unkE0 = sp2C->moveAngle;
        sp2C->unkB6 = 0x5A;
    } else {
        sp2C->unkB6 -= 1;
    }
    sp2C->moveAngle = sp2C->Rot.y;
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp2C->Rot.y = sp2C->moveAngle;
    sp2C->moveAngle = sp2C->unkE0;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 240.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp2C->unkE0 = sp2C->moveAngle;
    }
    func_bagular2_8033124C();
    func_bagular2_803311B4();
    func_bagular2_80330894();
    func_bagular2_80331064();
    if (sp2C->unkAA == 0) {
        func_bagular2_803303AC(300.0f);
    }
}

void func_bagular2_80332B6C(void) {
    struct ObjectStruct* sp24;
    UNUSED s32 pad[2];

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = sp24->moveAngle;
    func_bagular2_8033124C();
    func_bagular2_803311B4();
    func_bagular2_80330894();
    func_bagular2_80330F08();
    sp24->actionState = 3;
    sp24->unk132 = 0;
}

void func_bagular2_80332C58(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    UNUSED f32 temp_f20;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
        sp2C->moveSpeed = 0.0f;
        sp2C->Vel.x = sp2C->Vel.z = sp2C->Vel.y = 0.0f;
        sp2C->unkA6 = 0xB4;
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_8011B290 + 7);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 28);
        func_8001ABF4((s32) sp2C->unkE8[0], 0, 3, &D_8011B3D4 + 7);
        if (sp2C->unkAC != 0) {
            sp2C->unkAA = 0;
            func_8002B114((s32) sp2C->unkAC);
            sp2C->unkAC = 0;
        }
        sp2C->Vel.z = (-1800.0f - sp2C->Pos.z) / 180.0f;
        if (sp2C->Rot.y > 180.0f) {
            sp2C->unkE0 = -3.0f;
        } else {
            sp2C->unkE0 = 3.0f;
        }
        if (sp2C->unkE8[1] != -1) {
            sp28 = func_800281A4(gCurrentParsedObject, 1);
            func_8002B114(sp28);
        }
        func_80069E60(0, 0, 0xB3);
    }
    if (sp2C->unkA6 == 0) {
        if (sp2C->unkE8[0] != -1) {
            sp28 = func_800281A4(gCurrentParsedObject, 0);
            func_8002B114(sp28);
        }
        func_8002B114(gCurrentParsedObject);
    } else {
        sp2C->Rot.y = Math_WrapAngle(sp2C->Rot.y, sp2C->unkE0);
        if (sp2C->unkE0 < 0.0f) {
            if (sp2C->Rot.y <= 180.0f) {
                sp2C->Rot.y = 180.0f;
            }
        } else if (sp2C->Rot.y >= 180.0f) {
            sp2C->Rot.y = 180.0f;
        }
        sp2C->moveAngle = sp2C->Rot.y;
        sp2C->Scale.x = (f32) ((f64) sp2C->Scale.x - 0.005);
        sp2C->Scale.y = (f32) ((f64) sp2C->Scale.y - 0.005);
        sp2C->Scale.z = (f32) ((f64) sp2C->Scale.z - 0.005);
        sp2C->unkA6 -= 1;
        func_bagular2_8033124C();
        func_bagular2_803311B4();
        func_bagular2_80330894();
    }
}

void func_bagular2_80333074(void) {
    struct ObjectStruct* sp2C;
    UNUSED s32 pad;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->damageState == 0) {
        func_8001BB34(gCurrentParsedObject, !(sp2C->unkA6 & 1));
        func_8001BB34((s32) sp2C->unkE8[0], !(sp2C->unkA6 & 1));
    } else {
        func_8001BB34(gCurrentParsedObject, !(sp2C->damageState & 1));
        func_8001BB34((s32) sp2C->unkE8[0], !(sp2C->damageState & 1));
    }
    switch (sp2C->actionState) { /* irregular */
        case 0x1:
            func_bagular2_80331D0C();
            break;
        case 0x2:
            func_bagular2_80331E90();
            break;
        case 0x3:
            func_bagular2_80332718();
            break;
        case 0x4:
            func_bagular2_803328F8();
            break;
        case 0x5:
            func_bagular2_80332B6C();
            break;
        case 0x63:
            func_bagular2_80332C58();
            break;
        default:
            break;
    }
}

void func_bagular2_80333248(void) {
    struct ObjectStruct* sp24;
    UNUSED s32 pad[2];

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 21);
        func_8001ABF4((s32) sp24->unkE8[0], 0, 3, &D_8011B3D4);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = sp24->moveAngle;
    func_bagular2_8033124C();
    func_bagular2_803311B4();
    func_bagular2_80330894();
    func_bagular2_80330F08();
    sp24->actionState = 2;
    sp24->unk132 = 0;
}

void func_bagular2_80333370(void) {
    struct ObjectStruct* sp34;
    UNUSED s32 pad30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 21);
        func_8001ABF4((s32) sp34->unkE8[0], 0, 3, &D_8011B3D4);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp34->Rot.y = sp34->moveAngle;
    if (func_800295C0(gCurrentParsedObject, &sp2C, &sp28, 0.0f, 0.0f, 0.0f) != 0) {
        sp24 = sp28;
    } else {
        sp24 = sp2C;
    }
    sp24 += 420.0f;
    if (sp34->Pos.y <= sp24) {
        sp34->Pos.y = sp24;
        sp34->Vel.y = 0.0f;
        sp34->actionState = 3;
        sp34->unk132 = 0;
    } else {
        sp34->Vel.y = -12.0f;
    }
    func_bagular2_8033124C();
    func_bagular2_80330894();
    func_bagular2_80330CD0();
}

void func_bagular2_80333544(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
        sp2C->moveSpeed = 9.0f;
        sp2C->unkB6 = 0;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 21);
        func_8001ABF4((s32) sp2C->unkE8[0], 0, 3, &D_8011B3D4);
    }
    if (sp2C->unkB6 == 0) {
        sp2C->moveAngle = Math_WrapAngle(sp2C->moveAngle, (f32) Math_Random(0x168));
        sp2C->unkE0 = sp2C->moveAngle;
        sp2C->unkB6 = 0x5A;
    } else {
        sp2C->unkB6 -= 1;
    }
    sp2C->moveAngle = sp2C->Rot.y;
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp2C->Rot.y = sp2C->moveAngle;
    sp2C->moveAngle = sp2C->unkE0;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 240.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp2C->unkE0 = sp2C->moveAngle;
    }
    func_bagular2_8033124C();
    func_bagular2_803311B4();
    func_bagular2_80330894();
    func_bagular2_80331064();
    if (sp2C->unkAA == 0) {
        func_bagular2_803304B8(300.0f);
    }
    func_bagular2_803302C8();
    if (sp2C->unkAE == 0) {
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 21);
        sp2C->unkAE -= 1;
    } else {
        sp2C->unkAE -= 1;
    }
}

void func_bagular2_8033382C(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    s16 sp26;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkA6 = 0x3D;
        if (sp2C->unkAC != 0) {
            sp2C->unkAA = 0;
            func_8002B114((s32) sp2C->unkAC);
            sp2C->unkAC = 0;
        }
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z = 0.0f;
        sp2C->moveSpeed = 0.0f;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011B290 + 21);
        func_8001ABF4((s32) sp2C->unkE8[0], 0, 3, &D_8011B3D4);
    }
    if (sp2C->unkA6 == 0) {
        for (sp26 = 0; sp26 < 2; sp26++) {
            if (sp2C->unkE8[sp26] != -1) {
                sp28 = func_800281A4(gCurrentParsedObject, (s32) sp26);
                func_8002B114(sp28);
            }
        }
        if (gObjects[sp2C->unkC2].unkC0 == gCurrentParsedObject) {
            gObjects[sp2C->unkC2].unkC0 = 0;
        }
        if (gObjects[sp2C->unkC2].unkC2 == gCurrentParsedObject) {
            gObjects[sp2C->unkC2].unkC2 = 0;
        }
        func_8002B114(gCurrentParsedObject);
    } else {
        sp2C->unkA6 -= 1;
        func_bagular2_8033124C();
        func_bagular2_803311B4();
        func_bagular2_80330894();
        func_bagular2_80331064();
    }
}

void func_bagular2_80333B20(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    func_8001BB34(gCurrentParsedObject, !(sp24->unkA6 & 1));
    func_8001BB34((s32) sp24->unkE8[0], !(sp24->unkA6 & 1));
    switch (sp24->actionState) { /* irregular */
        case 0x1:
            func_bagular2_80333248();
            break;
        case 0x2:
            func_bagular2_80333370();
            break;
        case 0x3:
            func_bagular2_80333544();
            break;
        case 0x63:
            func_bagular2_8033382C();
            break;
        default:
            break;
    }
}

void func_bagular2_80333C4C(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x142, &D_8011B414);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp24->unkC0 != 0) {
            sp20 =
                func_80027464(1, D_bagular2_80334440, gObjects[sp24->unkC2].Pos.x + gObjects[sp24->unkC2].Vel.x,
                              gObjects[sp24->unkC2].Pos.y + gObjects[sp24->unkC2].Vel.y,
                              gObjects[sp24->unkC2].Pos.z + gObjects[sp24->unkC2].Vel.z, gObjects[sp24->unkC2].Rot.y);

        } else {
            sp20 =
                func_80027464(1, D_bagular2_8033444C, gObjects[sp24->unkC2].Pos.x + gObjects[sp24->unkC2].Vel.x,
                              gObjects[sp24->unkC2].Pos.y + gObjects[sp24->unkC2].Vel.y,
                              gObjects[sp24->unkC2].Pos.z + gObjects[sp24->unkC2].Vel.z, gObjects[sp24->unkC2].Rot.y);
        }
        gObjects[sp24->unkC2].unkAC = (s16) sp20;
        gObjects[sp20].unkC2 = sp24->unkC2;
        func_8002B114(gCurrentParsedObject);
    } else {
        sp24->Pos.x = gObjects[sp24->unkC2].Pos.x + gObjects[sp24->unkC2].Vel.x;
        sp24->Pos.z = gObjects[sp24->unkC2].Pos.z + gObjects[sp24->unkC2].Vel.z;
        sp24->Rot.x = gObjects[sp24->unkC2].Rot.x;
        sp24->Rot.y = gObjects[sp24->unkC2].Rot.y;
        sp24->Rot.z = gObjects[sp24->unkC2].Rot.z;
    }
}

void func_bagular2_80333F8C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x143, &D_8011B418);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        gObjects[sp24->unkC2].unkAA = 0;
        gObjects[sp24->unkC2].unkAC = 0;
        func_8002B114(gCurrentParsedObject);
    } else {
        sp24->Pos.x = gObjects[sp24->unkC2].Pos.x + gObjects[sp24->unkC2].Vel.x;
        sp24->Pos.z = gObjects[sp24->unkC2].Pos.z + gObjects[sp24->unkC2].Vel.z;
        sp24->Rot.x = gObjects[sp24->unkC2].Rot.x;
        sp24->Rot.y = gObjects[sp24->unkC2].Rot.y;
        sp24->Rot.z = gObjects[sp24->unkC2].Rot.z;
    }
}

void func_bagular2_803341C8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x143, &D_8011B418);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        gObjects[sp24->unkC2].unkAA = 0;
        gObjects[sp24->unkC2].unkAC = 0;
        func_8002B114(gCurrentParsedObject);
    } else {
        sp24->Pos.x = gObjects[sp24->unkC2].Pos.x + gObjects[sp24->unkC2].Vel.x;
        sp24->Pos.z = gObjects[sp24->unkC2].Pos.z + gObjects[sp24->unkC2].Vel.z;
        sp24->Rot.x = gObjects[sp24->unkC2].Rot.x;
        sp24->Rot.y = gObjects[sp24->unkC2].Rot.y;
        sp24->Rot.z = gObjects[sp24->unkC2].Rot.z;
    }
}
