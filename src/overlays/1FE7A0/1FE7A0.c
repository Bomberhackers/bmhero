#include "common.h"


extern struct ObjSpawnInfo D_80113DE4;
extern struct ObjSpawnInfo D_80113DF0;
extern struct ObjSpawnInfo D_8011430C;
extern struct ObjSpawnInfo D_80114324;
extern struct ObjSpawnInfo D_80114330;
extern u32 D_80117F00;
extern u32 D_80117F04;
extern u32 D_80118EC8;
extern UNK_TYPE D_80118EFC;
extern u32 D_80118F34;
extern u32 D_80118F44;
extern u32 D_80118F4C;
extern UNK_TYPE D_80118FCC;

void func_80330000_unk_bin_48(void) {
    s16 sp2E;

    sp2E = func_80027464(1, &D_80113DE4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].actionState = 1;
        gObjects[sp2E].unkAA = 0xF0;
        gObjects[sp2E].unkAC = 4;
        gObjects[sp2E].unk132 = 0;
        gObjects[sp2E].Scale.x = 2.0f;
        gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.x;
        if (D_80165100->unkA == 2) {
            D_80165100->unkA = 0;
        }
        if (D_80165100->unkC != 0) {
            gObjects[sp2E].unkAA = D_80165100->unkC * 0x3C;
        }
        if (D_80165100->unkE != 0) {
            gObjects[sp2E].unkAC = (s16) ((s16) D_80165100->unkE % 48);
        }
        gObjects[sp2E].unkA8 = (s16) ((s16) D_80165100->unkA % 4);
        func_8001C0EC((s32) sp2E, 3, 0, 0x122, &D_80117F00);
    }
}

void func_803302F8_unk_bin_48(void) {
    if ((D_80177A64 != 0) && (D_80177A64 == 1)) {
        return;
    }
}

void func_80330330_unk_bin_48(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->moveSpeed = (f32) sp2C->unkAC;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = sp2C->unkAA;
        sp2C->moveAngle = (f32) (sp2C->unkA8 * 0x5A);
        func_800175F0(gCurrentParsedObject, 0, 0x37, -1, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_800C00F4(sp2C, 300.0f);
    if (func_80029018(gCurrentParsedObject, 4U, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp2C->unkA6 = (s16) (s32) ((f32) sp2C->unkA6 - sp2C->moveSpeed);
    if (sp2C->unkA6 <= 0) {
        sp2C->actionState = 1;
        sp2C->unk132 = 0;
        sp2C->unkA8 = (s16) ((s32) (sp2C->unkA8 + 2) % 4);
    }
}

static void stub0() {}
static void stub1() {}


void func_80330550_unk_bin_48(void) {
}

void func_80330580_unk_bin_48(void) {
    func_80330330_unk_bin_48();
}

void func_803305A8_unk_bin_48(void) {
    s16 sp2E;

    sp2E = func_80027464(1, &D_80113DF0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].actionState = 1;
        gObjects[sp2E].unk132 = 0;
        gObjects[sp2E].unk102 = 0;
        gObjects[sp2E].Scale.x = 2.0f;
        gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.x;
        func_8001C0EC((s32) sp2E, 3, 0, 0x199, &D_80117F04);
    }
}

void func_80330750_unk_bin_48(void) {
    if ((D_80177A64 != 0) && (D_80177A64 == 1)) {
        return;
    }
}

void func_80330788_unk_bin_48(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->moveSpeed = 2.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0x168;
        func_800175F0(gCurrentParsedObject, 0, 0x37, -1, 0);
    }
    func_80029C40(gCurrentParsedObject);
    sp24->moveAngle = Math_WrapAngle(sp24->moveAngle, 4.0f);
    func_800C00F4(sp24, 300.0f);
    if (func_80029018(gCurrentParsedObject, 4U, 180.0f, 0.0f, 0.0f, 0.0f) != 0) {

    }
    sp24->unkA6 -= 2;
    if (sp24->unkA6 <= 0) {
        sp24->actionState = 1;
        sp24->unk132 = 0;
    }
}

static void stub3() {}
static void stub4() {}
static void stub5() {}

void func_8033092C_unk_bin_48(void) {
    func_80330788_unk_bin_48();
}

void func_80330954_unk_bin_48(void) {
    s32 sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = func_80027464(2, &D_8011430C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp2C != -1) {
        gObjects[sp2C].unkC0 = D_80165100->unkA;
        if (D_80165100->unkA == 0) {
            if (func_800295C0(sp2C, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
                gObjects[sp2C].Pos.y  = sp24;
            } else {
                gObjects[sp2C].Pos.y  = sp28;
            }
            gObjects[gObjects[sp2C].unkE8[0]].Pos.y = gObjects[sp2C].Pos.y;
        } else if (D_80165100->unkA == 1) {
            if (func_800295C0(sp2C, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
                gObjects[sp2C].Pos.y  = sp24;
            } else {
                gObjects[sp2C].Pos.y  = sp28;
            }
            gObjects[gObjects[sp2C].unkE8[0]].Pos.y = gObjects[sp2C].Pos.y;
            gObjects[sp2C].actionState = 5;
        } else if (D_80165100->unkA == 2) {
            if (func_800295C0(sp2C, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
                gObjects[sp2C].Pos.y  = sp24;
            } else {
                gObjects[sp2C].Pos.y  = sp28;
            }
            //temp_t5_2 = &;
            gObjects[sp2C].Pos.y -= 60.0f;
            gObjects[gObjects[sp2C].unkE8[0]].Pos.y = gObjects[sp2C].Pos.y + 60.0f;
            gObjects[sp2C].actionState = 8;
        }
    }
}

void func_80330D5C_unk_bin_48(void) {
    struct ObjectStruct* sp1C;
    s16 sp1A;

    sp1C = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp1C->damageState = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
        sp1C->unkD4 = sp1C->Pos.y;
        if (sp1C->unkC0 != 2) {
            for (sp1A = 0; sp1A < 3; sp1A++) {
                gObjects[sp1C->unkE8[sp1A]].damageState = 0;
                func_8001BBDC((s32) sp1C->unkE8[sp1A], 1);
            }
        } else {
            gObjects[sp1C->unkE8[0]].damageState = 0;
            func_8001BBDC((s32) sp1C->unkE8[0], 1);
        }
        if (sp1C->unkC2 != 0) {
            func_8002B114((s32) sp1C->unkC2);
        }
        sp1C->actionState = 4;
        sp1C->unk132 = 0;
    } else if (D_80177A64 == 1) {
        sp1C->damageState = 0x3C;
        if (sp1C->unkC0 != 2) {
            for (sp1A = 0; sp1A < 3; sp1A++) {
                gObjects[sp1C->unkE8[sp1A]].damageState = 0x3C;
            } 
        } else {
            gObjects[sp1C->unkE8[0]].damageState = 0x3C;
        }
    }
}

void func_80330FCC_unk_bin_48(void) {
    struct ObjectStruct* sp34;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        sp34->Rot.y = Math_WrapAngle(sp34->Rot.y, 180.0f);
        sp34->moveAngle = sp34->Rot.y;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC);
        func_80027C00(gCurrentParsedObject, 1, &D_80114324, sp34->Pos.x, sp34->Pos.y + 90.0f, sp34->Pos.z, sp34->Rot.y);
        gObjects[sp34->unkE8[1]].moveAngle = gObjects[sp34->unkE8[1]].Rot.y;
        func_8001C0EC((s32) sp34->unkE8[1], 0, 0, 0x5D, &D_80118F34);
        func_80027C00(gCurrentParsedObject, 2, &D_80114324, sp34->Pos.x, sp34->Pos.y + 90.0f, sp34->Pos.z, Math_WrapAngle(sp34->Rot.y, 180.0f));
        gObjects[sp34->unkE8[2]].moveAngle = gObjects[sp34->unkE8[2]].Rot.y;
        func_8001C0EC((s32) sp34->unkE8[2], 0, 0, 0x5D, &D_80118F34);
    }
    if (func_8002A1FC(gCurrentParsedObject, 600.0f) != 0) {
        sp34->actionState = 2;
        sp34->unk132 = 0;
    }
}

void func_8033123C_unk_bin_48(void) {
    struct ObjectStruct* sp44;
    struct ObjectStruct* sp40;
    struct ObjectStruct* sp3C;
    struct ObjectStruct* sp38;
    s32 sp34;
    s16 sp32;

    sp44 = &gObjects[gCurrentParsedObject];
    sp40 = &gObjects[sp44->unkE8[0]];
    sp3C = &gObjects[sp44->unkE8[1]];
    sp38 = &gObjects[sp44->unkE8[2]];
    if (sp44->unk132 == 0) {
        sp44->unk132 += 1;
        sp44->unkB2 = sp44->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x5C, &D_80118EC8);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC);
        func_8001C0EC((s32) sp44->unkE8[0], 0, 1, 0x5E, &D_80118F44);
        for (sp32 = 1; sp32 < 3; sp32++) {
            sp34 = Math_Random(3);
            func_8001C0EC((s32) sp44->unkE8[sp32], 0, sp34 + 1, 0x5D, &D_80118F34);
        } 
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp44->Rot.y = sp44->moveAngle;
    sp40->Rot.y = sp40->moveAngle = sp44->Rot.y;
    sp3C->Rot.y = sp3C->moveAngle = sp44->Rot.y;
    sp38->Rot.y = Math_WrapAngle(sp44->Rot.y, 180.0f);
    sp38->moveAngle = sp38->Rot.y;
    if (func_8002A2EC(gCurrentParsedObject, 480.0f) != 0) {
        sp44->actionState = 3;
        sp44->unk132 = 0;
    } else if (func_8001B4AC((s32) sp44->unkE8[0], 0) != 0) {
        sp44->unk132 = 0;
    }
}

void func_8033151C_unk_bin_48(void) {
    struct ObjectStruct* sp44;
    struct ObjectStruct* sp40;
    struct ObjectStruct* sp3C;
    struct ObjectStruct* sp38;
    s32 sp34;
    s16 sp32;


    sp44 = &gObjects[gCurrentParsedObject];
    sp40 = &gObjects[sp44->unkE8[0]];
    sp3C = &gObjects[sp44->unkE8[1]];
    sp38 = &gObjects[sp44->unkE8[2]];
    if (sp44->unk132 == 0) {
        sp44->unk132 += 1;
        sp44->unkB2 = sp44->actionState;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp44->Rot.y = sp44->moveAngle;
    sp40->Rot.y = sp40->moveAngle = sp44->Rot.y;
    sp3C->Rot.y = sp3C->moveAngle = sp44->Rot.y;
    sp38->Rot.y = Math_WrapAngle(sp44->Rot.y, 180.0f);
    sp38->moveAngle = sp38->Rot.y;
    if (sp44->unkA6 == 0) {
        if ((D_801651A4 & 1) && (gPlayerObject->Vel.y > 0.0f)) {
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC + 7);
            sp44->unkA6 = 1;
            sp44->unkA8 = 0xE;
            sp44->Pos.y += 10.0f;
            for (sp32 = 1; sp32 < 3; sp32++) {
                gObjects[sp44->unkE8[sp32]].Pos.y += 10.0f;
            } 
        }
    } else if (sp44->unkA8 == 0) {
        if (sp44->unkA6 == 1) {
            sp44->Pos.y -= 10.0f;
            for (sp32 = 1; sp32 < 3; sp32++) {
                gObjects[sp44->unkE8[sp32]].Pos.y -= 10.0f;
            } 
            sp44->unkA6 = 2;
            sp44->unkA8 = 0xE;
        } else {
            sp44->unkA6 = 0;
        }
    } else {
        if (sp44->unkA6 == 1) {
            sp44->Pos.y += 10.0f;
            for (sp32 = 1; sp32 < 3; sp32++) {
                gObjects[sp44->unkE8[sp32]].Pos.y += 10.0f;
            } 
        } else if (sp44->unkA6 == 2) {
            sp44->Pos.y -= 10.0f;
            for (sp32 = 1; sp32 < 3; sp32++) {
                gObjects[sp44->unkE8[sp32]].Pos.y -= 10.0f;
            } 
        }
        sp44->unkA8 -= 1;
    }
    if ((sp44->unkA6 == 0) && (sp44->unkA8 == 0)) {
        sp44->actionState = 2;
        if (func_8001B4AC((s32) sp44->unkE8[0], 0) != 0) {
            sp44->unk132 = 0;
        }
    } else if (func_8001B4AC((s32) sp44->unkE8[0], 0) != 0) {
        for (sp32 = 1; sp32 < 3; sp32++) {
            sp34 = Math_Random(3);
            func_8001C0EC((s32) sp44->unkE8[sp32], 0, sp34 + 1, 0x5D, &D_80118F34);
        } 
    }
}

void func_80331B44_unk_bin_48(void) {
    struct ObjectStruct* sp2C;
    struct ObjectStruct* sp28;
    struct ObjectStruct* sp24;
    struct ObjectStruct* sp20;
    s32 sp1C;
    s16 sp1A;

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = &gObjects[sp2C->unkE8[0]];
    if (sp2C->unkC0 != 2) {
        sp24 = &gObjects[sp2C->unkE8[1]];
        sp20 = &gObjects[sp2C->unkE8[2]];
    }
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
    }
    sp2C->Rot.y = Math_WrapAngle(sp2C->Rot.y, 18.0f);
    sp28->Rot.y = sp2C->Rot.y;
    sp2C->Pos.y -= 4.0f;
    sp28->Pos.y -= 4.0f;
    if (sp2C->unkC0 != 2) {
        sp24->Rot.y = sp2C->Rot.y;
        sp20->Rot.y = Math_WrapAngle(sp2C->Rot.y, 180.0f);
        sp24->Pos.y -= 4.0f;
        sp20->Pos.y -= 4.0f;
    }
    if (sp2C->Pos.y < (sp2C->unkD4 - 480.0f)) {
        if (sp2C->unkC0 != 2) {
            for (sp1A = 0; sp1A < 3; sp1A++) {
                sp1C = func_800281A4(gCurrentParsedObject, (s32) sp1A);
                func_8002B114(sp1C);
            } 
        } else {
            sp1C = func_800281A4(gCurrentParsedObject, 0);
            func_8002B114(sp1C);
        }
        func_8002B114(gCurrentParsedObject);
    }
}

void func_80331E28_unk_bin_48(void) {
    struct ObjectStruct* sp34;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        sp34->Rot.y = Math_WrapAngle(sp34->Rot.y, 180.0f);
        sp34->moveAngle = sp34->Rot.y;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC);
        func_80027C00(gCurrentParsedObject, 1, &D_80114324, sp34->Pos.x, sp34->Pos.y + 90.0f, sp34->Pos.z, sp34->Rot.y);
        gObjects[sp34->unkE8[1]].moveAngle = gObjects[sp34->unkE8[1]].Rot.y;
        func_8001C0EC((s32) sp34->unkE8[1], 0, 0, 0x5D, &D_80118F34);
        func_80027C00(gCurrentParsedObject, 2, &D_80114324, sp34->Pos.x, sp34->Pos.y + 90.0f, sp34->Pos.z, Math_WrapAngle(sp34->Rot.y, 180.0f));
        gObjects[sp34->unkE8[2]].moveAngle = gObjects[sp34->unkE8[2]].Rot.y;
        func_8001C0EC((s32) sp34->unkE8[2], 0, 0, 0x5D, &D_80118F34);
    }
    if (func_8002A1FC(gCurrentParsedObject, 600.0f) != 0) {
        sp34->actionState = 6;
        sp34->unk132 = 0;
    }
}

void func_80332098_unk_bin_48(void) {
    struct ObjectStruct* sp44;
    struct ObjectStruct* sp40;
    struct ObjectStruct* sp3C;
    struct ObjectStruct* sp38;
    s32 sp34;
    s16 sp32;

    sp44 = &gObjects[gCurrentParsedObject];
    sp40 = &gObjects[sp44->unkE8[0]];
    sp3C = &gObjects[sp44->unkE8[1]];
    sp38 = &gObjects[sp44->unkE8[2]];
    if (sp44->unk132 == 0) {
        sp44->unk132 += 1;
        sp44->unkB2 = sp44->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x5C, &D_80118EC8);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC);
        func_8001C0EC((s32) sp44->unkE8[0], 0, 1, 0x5E, &D_80118F44);
        for (sp32 = 1; sp32 < 3; sp32++) {
            sp34 = Math_Random(3);
            func_8001C0EC((s32) sp44->unkE8[sp32], 0, sp34 + 1, 0x5D, &D_80118F34);
        }
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp44->Rot.y = sp44->moveAngle;
    sp40->Rot.y = sp40->moveAngle = sp44->Rot.y;
    sp3C->Rot.y = sp3C->moveAngle =  sp44->Rot.y;
    sp38->Rot.y = Math_WrapAngle(sp44->Rot.y, 180.0f);
    sp38->moveAngle = sp38->Rot.y;
    if (func_8002A2EC(gCurrentParsedObject, 480.0f) != 0) {
        sp44->actionState = 7;
        sp44->unk132 = 0;
    } else if (func_8001B4AC((s32) sp44->unkE8[0], 0) != 0) {
        sp44->unk132 = 0;
    }
}

void func_80332378_unk_bin_48(void) {
    struct ObjectStruct* sp4C;
    struct ObjectStruct* sp48;
    struct ObjectStruct* sp44;
    struct ObjectStruct* sp40;
    s32 sp3C;
    s32 sp38;
    s16 sp36;
    f32 sp30;
    f32 sp2C;

    sp4C = &gObjects[gCurrentParsedObject];
    sp48 = &gObjects[sp4C->unkE8[0]];
    sp44 = &gObjects[sp4C->unkE8[1]];
    sp40 = &gObjects[sp4C->unkE8[2]];
    if (sp4C->unk132 == 0) {
        sp4C->unk132 += 1;
        sp4C->unkB2 = sp4C->actionState;
        sp4C->unkA6 = 0x3C;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC + 7);
        sp30 = (sinf((f32) ((f64) sp4C->Rot.y * DEG_TO_RAD)) * 98.0f) + sp4C->Pos.x;
        sp2C = (cosf((f32) ((f64) sp4C->Rot.y * DEG_TO_RAD)) * 98.0f) + sp4C->Pos.z;
        sp38 = func_80027464(1, &D_80114330, sp30, sp4C->Pos.y, sp2C, sp4C->Rot.y);
        gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
        sp4C->unkC2 = (s16) sp38;
        func_8001ABF4(sp38, 0, 3, &D_80118FCC);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp4C->Rot.y = sp4C->moveAngle;
    sp48->Rot.y = sp48->moveAngle = sp4C->Rot.y;
    sp44->Rot.y = sp44->moveAngle = sp4C->Rot.y;
    sp40->Rot.y = Math_WrapAngle(sp4C->Rot.y, 180.0f);
    sp40->moveAngle = sp40->Rot.y;
    if (sp4C->unkA6 == 0) {
        sp4C->actionState = 6;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC);
    } else {
        sp4C->unkA6 -= 1;
        if (func_8001B4AC((s32) sp4C->unkE8[0], 0) != 0) {
            for (sp36 = 1; sp36 < 3; sp36++) {
                sp3C = Math_Random(3);
                func_8001C0EC((s32) sp4C->unkE8[sp36], 0, sp3C + 1, 0x5D, &D_80118F34);
            } 
        }
    }
}

void func_80332750_unk_bin_48(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        sp1C->unkB2 = sp1C->actionState;
        sp1C->Rot.y = Math_WrapAngle(sp1C->Rot.y, 180.0f);
        sp1C->moveAngle = sp1C->Rot.y;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC);
    }
    if (func_8002A1FC(gCurrentParsedObject, 300.0f) != 0) {
        sp1C->actionState = 9;
        sp1C->unk132 = 0;
    }
}

void func_80332864_unk_bin_48(void) {
    struct ObjectStruct* sp34;
    struct ObjectStruct* sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    sp30 = &gObjects[sp34->unkE8[0]];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x5C, &D_80118EC8);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC);
        func_8001C0EC((s32) sp34->unkE8[0], 0, 1, 0x5E, &D_80118F44);
        sp34->unkA6 = 0x14;
        sp34->unkA8 = 1;
    }
    if (sp34->unkA6 == 0) {
        if (sp34->unkA8 == 1) {
            sp34->unkA8 = 2;
            sp34->unkA6 = 0xE;
            sp34->Pos.y -= 10.0f;
        } else {
            sp34->unkA8 = 0;
        }
    } else if (sp34->unkA8 == 1) {
        sp34->Pos.y += 10.0f;
        sp34->unkA6 -= 1;
    } else {
        func_8002A8B4(gCurrentParsedObject, 6.0f);
        sp34->Rot.y = sp34->moveAngle;
        sp30->Rot.y = sp30->moveAngle = sp34->Rot.y;
        sp34->Pos.y -= 10.0f;
        sp34->unkA6 -= 1;
    }
    if ((sp34->unkA6 == 0) && (sp34->unkA8 == 0)) {
        sp34->actionState = 0xA;
        sp34->unk132 = 0;
        return;
    }
}

void func_80332B34_unk_bin_48(void) {
    struct ObjectStruct* sp2C;
    struct ObjectStruct* sp28;

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = &gObjects[sp2C->unkE8[0]];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp2C->Rot.y = sp2C->moveAngle;
    sp28->Rot.y = sp28->moveAngle = sp2C->Rot.y;
    if (func_8002A2EC(gCurrentParsedObject, 480.0f) != 0) {
        sp2C->actionState = 0xB;
        sp2C->unk132 = 0;
    }
}

void func_80332C8C_unk_bin_48(void) {
    struct ObjectStruct* sp44;
    struct ObjectStruct* sp40;
    UNUSED s32 sp3C;
    s32 sp38;
    UNUSED s32 pad;
    f32 sp30;
    f32 sp2C;
            

    sp44 = &gObjects[gCurrentParsedObject];
    sp40 = &gObjects[sp44->unkE8[0]];
    if (sp44->unk132 == 0) {
        sp44->unk132 += 1;
        sp44->unkB2 = sp44->actionState;
        sp44->unkA6 = 0x3C;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC + 0x7);
        sp30 = (sinf((f32) ((f64) sp44->Rot.y * DEG_TO_RAD)) * 98.0f) + sp44->Pos.x;
        sp2C = (cosf((f32) ((f64) sp44->Rot.y * DEG_TO_RAD)) * 98.0f) + sp44->Pos.z;
        sp38 = func_80027464(1, &D_80114330, sp30, sp44->Pos.y, sp2C, sp44->Rot.y);
        gObjects[sp38].unkC2 = (s16) gCurrentParsedObject;
        sp44->unkC2 = (s16) sp38;
        func_8001ABF4(sp38, 0, 3, &D_80118FCC);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp44->Rot.y = sp44->moveAngle;
    sp40->Rot.y = sp40->moveAngle = sp44->Rot.y;
    if (sp44->unkA6 == 0) {
        sp44->actionState = 0xA;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118EFC);
    } else {
        sp44->unkA6 -= 1;
    }
}

void func_80332F30_unk_bin_48(void) {
    struct ObjectStruct* sp2C;
    s16 sp2A;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->damageState == 0) {
        func_8001BB34(gCurrentParsedObject, 0);
        if (sp2C->unkC0 != 2) {
            for (sp2A = 0; sp2A < 3; sp2A++) {
                func_8001BB34((s32) sp2C->unkE8[sp2A], 0);
            }
        } else {
            func_8001BB34((s32) sp2C->unkE8[0], 0);
        }
    } else {
        func_8001BB34(gCurrentParsedObject, !(sp2C->damageState & 1));
        if (sp2C->unkC0 != 2) {
            for (sp2A = 0; sp2A < 3; sp2A++) {
                func_8001BB34((s32) sp2C->unkE8[sp2A], !(sp2C->damageState & 1));
            } 
        } else {
            func_8001BB34((s32) sp2C->unkE8[0], !(sp2C->damageState & 1));
        }
    }
    switch (sp2C->actionState) {
    case 1:
        func_80330FCC_unk_bin_48();
        break;
    case 2:
        func_8033123C_unk_bin_48();
        break;
    case 3:
        func_8033151C_unk_bin_48();
        break;
    case 4:
        func_80331B44_unk_bin_48();
        break;
    case 5:
        func_80331E28_unk_bin_48();
        break;
    case 6:
        func_80332098_unk_bin_48();
        break;
    case 7:
        func_80332378_unk_bin_48();
        break;
    case 8:
        func_80332750_unk_bin_48();
        break;
    case 9:
        func_80332864_unk_bin_48();
        break;
    case 10:
        func_80332B34_unk_bin_48();
        break;
    case 11:
        func_80332C8C_unk_bin_48();
        break;
    default:
        break;
    }
}

void func_803331DC_unk_bin_48(void) {
    struct ObjectStruct* sp24;
    struct ObjectStruct* sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    sp20 = &gObjects[sp24->unkC2];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x19A, &D_80118F4C);
        sp24->unkB6 = 0;
    }
    if (sp24->unkB6 == 0) {
        sp24->unkB6 = 8;
        func_800175F0(gCurrentParsedObject, 0, 0x44, -1, 0);
    } else {
        sp24->unkB6 -= 1;
    }
    sp24->Pos.x = (sinf((f32) ((f64) sp20->Rot.y * DEG_TO_RAD)) * 98.0f) + sp20->Pos.x;
    sp24->Pos.z = (cosf((f32) ((f64) sp20->Rot.y * DEG_TO_RAD)) * 98.0f) + sp20->Pos.z;
    sp24->Rot.y = sp20->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 3) != 0) {
        sp20->unkC2 = 0;
        func_8002B114(gCurrentParsedObject);
    }
}
