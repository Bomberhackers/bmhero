#include <ultra64.h>

void func_8033849C_unk_bin_51(s16 arg0);            /* static */
s16 func_8033882C_unk_bin_51(s16 arg0);             /* static */
s16 func_8033908C_unk_bin_51(void);                     /* static */
void func_80339150_unk_bin_51(void);                    /* static */

extern struct UnkStruct_80027C00 D_80113B20;
extern struct UnkStruct_80027C00 D_80113B5C;

void func_80338000_unk_bin_51(void) {
    s16 sp2E;

    sp2E = func_80027464(5, &D_80113B20, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].actionState = ACTION_IDLE;
        gObjects[sp2E].unkA6 = 0x348;
        gObjects[sp2E].unkA8 = 1;
        gObjects[sp2E].unkAA = 0xC8;
        gObjects[sp2E].unkAC = 0x2000;
        gObjects[sp2E].Rot.y = 90.0f;
        gObjects[sp2E].damageState = OBJ_DEATH;
        gObjects[sp2E].unk132 = 0;
        gObjects[sp2E].Rot.y = 0.0f;
        gObjects[sp2E].moveAngle = (f32) (gObjects[sp2E].unkA8 * 0x5A);
        gObjects[sp2E].Scale.x = 2.0f;
        gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.x;
        func_8033849C_unk_bin_51(sp2E);
    }
}

void func_803382E0_unk_bin_51(s16 arg0, s16 arg1) {
    gObjects[arg0].actionState = ACTION_IDLE;
    gObjects[arg0].unkA8 = arg1;
    gObjects[arg0].unkAC = 0;
    gObjects[arg0].unkB2 = 0;
    gObjects[arg0].unk132 = 0;
    gObjects[arg0].Rot.y = 0.0f;
    gObjects[arg0].damageState = 1;
    gObjects[arg0].unk103 = 1;
    gObjects[arg0].Scale.x = 1.6f;
    gObjects[arg0].Scale.z = gObjects[arg0].Scale.y = gObjects[arg0].Scale.x;
}

void func_8033849C_unk_bin_51(s16 arg0) {
    s16 sp1E;
    s16 sp1C;

    for (sp1C = 0; sp1C < 4; sp1C++) {
        sp1E = gObjects[arg0].unkE8[sp1C];
        func_803382E0_unk_bin_51(sp1E, sp1C);
    } 
}

void func_8033852C_unk_bin_51(s32 arg0, s32 arg1, struct ObjectStruct* arg2) {
    s16 sp2E;

    sp2E = func_80027C00(arg0, arg1, &D_80113B5C, arg2->Pos.x, arg2->Pos.y, arg2->Pos.z, 0.0f);
    if (sp2E != -1) {
        func_803382E0_unk_bin_51(sp2E, (s16) arg1);
    }
}

void func_803385B0_unk_bin_51(void) {
    s16 sp1E;
    s16 sp1C;

    func_8001BB34(gCurrentParsedObject, 0);
    sp1C = gObjects[gCurrentParsedObject].damageState;
                
    gObjects[gCurrentParsedObject].damageState  = 0;
    
    for (sp1E = 0; sp1E < 4; sp1E++) {
        func_8033882C_unk_bin_51(sp1E);
    } 
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        gObjects[gCurrentParsedObject].damageState = sp1C;
        return;
    }
    if ((gObjects[gCurrentParsedObject].interactingObjID == 0xF) || (gObjects[gCurrentParsedObject].interactingObjID == 8)) {
        if (D_80177A64 == 0) {
            gObjects[gCurrentParsedObject].actionState = 6;
            gObjects[gCurrentParsedObject].unk132 = 0;
            gObjects[gCurrentParsedObject].damageState  = 0;
            return;
        }
        if (D_80177A64 == 1) {
            gObjects[gCurrentParsedObject].actionState = 5;
            gObjects[gCurrentParsedObject].unk132 = 0;
            gObjects[gCurrentParsedObject].damageState  = 0;
            return;
        }
    }
}
s16 func_8033882C_unk_bin_51(s16 arg0) {
    struct ObjectStruct* spC;
    struct ObjectStruct* sp8;
    s16 sp6;

    spC = &gObjects[gCurrentParsedObject];
    sp6 = spC->unkE8[arg0];
    if (sp6 != -1) {
        sp8 = &gObjects[sp6];
        if (((sp8->interactingObjIdx != -1)) || (sp8->unk100 == 0)) {
            sp8->Scale.y = 5.8f;
            sp8->Scale.x = sp8->Scale.z =  sp8->Scale.y;
            sp8->unkA6 = 0x28;
        }
    }
    return sp6;
}

void func_80338938_unk_bin_51(void) {
    struct ObjectStruct* sp2C;
    UNUSED s32 pad;
    union {
        s16 ret;
    } fake;
    

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->moveSpeed = 4.0f;
        sp2C->unk40 = 90.0f;
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp2C->unkD4 = Math_WrapAngle(sp2C->unkD4, 8.0f);
    sp2C->unkB2 = (s16) (s32) Math_WrapAngle((f32) sp2C->unkB2, 14.0f);
    sp2C->unk48 = sinf((f32) ((f64) sp2C->unkB2 * DEG_TO_RAD)) * 16.0f;
    if (sp2C->unkAA == ((sp2C->unkAC * 0x28) + 0x50)) {
        if ((sp2C->unk100 > sp2C->unkAC) && (sp2C->unkAC < 4)) {
            if ((sp2C->unkE8[sp2C->unkAC] == -1)) {
                func_8033852C_unk_bin_51(gCurrentParsedObject, (s32) sp2C->unkAC, sp2C);
            }
        }
        sp2C->unkAC += 1;
    }
    sp2C->unkAA++;
    fake.ret = func_8033908C_unk_bin_51();
    if (fake.ret == 0) {
        func_8001BB34(gCurrentParsedObject, 0);
        sp2C->damageState = 1;
        sp2C->unkAC = 0;
    } else {
        if (!(sp2C->unkAA & 3)) {
            func_8001BB34(gCurrentParsedObject, 1);
        } else {
            func_8001BB34(gCurrentParsedObject, 0);
        }
        sp2C->damageState = 0;
        sp2C->Rot.y = 0.0f;
    }
    if (sp2C->unkAA >= 0xC8) {
        func_80339150_unk_bin_51();
        sp2C->unkAA = 0;
    }
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->unkA6 = 0x348;
        sp2C->unkA8 = (s16) ((s32) (sp2C->unkA8 + 2) % 4);
        sp2C->unk132 = 0;
        sp2C->moveAngle = (f32) (sp2C->unkA8 * 0x5A);
        return;
    }
    sp2C->unkA6 -= 4;
    if (sp2C->unkA6 <= 0) {
        sp2C->actionState = 1;
        sp2C->unk132 = 0;
        sp2C->unkA6 = 0x348;
        sp2C->unkA8 = (s16) ((s32) (sp2C->unkA8 + 2) % 4);
        sp2C->moveAngle = (f32) (sp2C->unkA8 * 0x5A);
        return;
    }
}

s16 func_80338DBC_unk_bin_51(s16 arg0) {
    struct ObjectStruct* sp24;
    struct ObjectStruct* sp20;
    s16 sp1E;
    s16 sp1C;

    sp1C = 0;
    sp24 = &gObjects[gCurrentParsedObject];
    sp1E = sp24->unkE8[arg0];
    if (sp1E != -1) {
        sp20 = &gObjects[sp1E];
        sp20->moveAngle = Math_WrapAngle(sp24->unkD4, (f32) (sp20->unkA8 * 0x50));
        sp20->Vel.x = sinf((f32) ((f64) sp20->moveAngle * DEG_TO_RAD)) * 200.0f;
        sp20->Vel.z = cosf((f32) ((f64) sp20->moveAngle * DEG_TO_RAD)) * 200.0f;
        sp20->unk40 = Math_WrapAngle(sp20->unk40, 8.0f);
        sp20->Vel.y = cosf((f32) ((f64) sp20->unk40 * DEG_TO_RAD)) * 20.0f;
        sp20->Pos.x = sp24->Pos.x + sp20->Vel.x;
        sp20->Pos.z = sp24->Pos.z + sp20->Vel.z;
        sp20->Pos.y = sp24->Pos.y + sp20->Vel.y;
        sp20->Rot.y = sp24->Rot.y;
        sp20->moveSpeed = 0.0f;
        sp20->unk48 = 0.0f;
        sp20->damageState = -1;
        sp1C = 1;
        func_80029C40((s32) sp1E);
        func_80029D04((s32) sp1E);
        if (sp20->unkAC > 0) {
            sp20->unkAC -= 1;
            if (sp20->unkAC == 0) {
                sp20->unkB2 = 0x3C;
                func_800281A4(gCurrentParsedObject, (s32) arg0);
            }
        }
    }
    return sp1C;
}

s16 func_8033908C_unk_bin_51(void) {
    struct ObjectStruct* sp2C;
    s16 sp2A;
    s16 sp28;

    sp2C = &gObjects[gCurrentParsedObject];
    sp2A = 0;
    for (sp28 = 0; sp28 < sp2C->unk100; sp28++) {
        sp2A += func_80338DBC_unk_bin_51(sp28);
    }
    return sp2A;
}

void func_80339150_unk_bin_51(void) {
    struct ObjectStruct* sp4;
    s16 sp2;
    s16 sp0;

    sp4 = &gObjects[gCurrentParsedObject];
    for (sp0 = 0; sp0 < sp4->unk100; sp0++) {
        sp2 = sp4->unkE8[sp0];
        if (sp2 != -1) {
            gObjects[sp2].unkAC = (sp0 * 0x1E) + 1;
        }
    }
}

void func_80339234_unk_bin_51(void) {
    struct ObjectStruct* sp1C;
    s16 sp1A;
    s16 sp18;

    sp1C = &gObjects[gCurrentParsedObject];
    func_8001BB34(gCurrentParsedObject, 0);
    for (sp18 = 0; sp18 < 4; sp18++) {
        sp1A = sp1C->unkE8[sp18];
        if (sp1A != -1) {
            func_800281A4(gCurrentParsedObject, (s32) sp18);
            func_8002B0E4((s32) sp1A);
        }
    } 
    func_8002B0E4(gCurrentParsedObject);
}

void func_80339310_unk_bin_51(void) {
    struct ObjectStruct* sp34;
    UNUSED char pad[0x8];

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->damageState = 0x50;
    }
    func_8001BB34(gCurrentParsedObject, !(sp34->damageState & 1));
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp34->unkD4 = Math_WrapAngle(sp34->unkD4, 8.0f);
    sp34->unkB2 = (s16) (s32) Math_WrapAngle((f32) sp34->unkB2, 14.0f);
    sp34->unk48 = sinf((f32) ((f64) sp34->unkB2 * DEG_TO_RAD)) * 16.0f;
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->unkA8 = (s16) ((s32) (sp34->unkA8 + 2) % 4);
        sp34->moveAngle = (f32) (sp34->unkA8 * 0x5A);
        sp34->unkA6 = 0x348;
    }
    sp34->unkA6 -= 4;
    if (sp34->unkA6 <= 0) {
        sp34->unkA8 = (s16) ((s32) (sp34->unkA8 + 2) % 4);
        sp34->moveAngle = (f32) (sp34->unkA8 * 0x5A);
        sp34->unkA6 = 0x348;
    }
    if (sp34->damageState == 1) {
        sp34->damageState = 0;
        sp34->moveSpeed = 4.0f;
        sp34->actionState = 1;
        sp34->unkAC = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

void func_80339628_unk_bin_51(void) {
    s32 sp24;

    sp24 = (s32) gObjects[gCurrentParsedObject].actionState;
    if (gObjects[gCurrentParsedObject].unk100 <= 0) {
        func_80339234_unk_bin_51();
        return;
    }
    switch (sp24) {                                 /* irregular */
    case 1:
        func_80338938_unk_bin_51();
        break;
    case 5:
        func_80339310_unk_bin_51();
        break;
    default:
        func_80339234_unk_bin_51();
        break;
    }
}

void func_80339714_unk_bin_51(void) {
}

static void stub_unk_bin_51(void) { 
}

void func_80339734_unk_bin_51(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->moveSpeed = 16.0f;
        sp34->unk48 = 12.0f;
        sp34->unk40 = 270.0f;
        sp34->unkA6 = 0;
        sp34->damageState = 1;
        func_800272E8(gCurrentParsedObject);
    }
    func_8002A8B4(gCurrentParsedObject, 8.0f);
    sp34->unkA6 = (s16) (s32) Math_WrapAngle((f32) sp34->unkA6, 10.0f);
    sp34->Scale.x = (f32) ((f64) (FABS(sinf((f32) sp34->unkA6)) * 2.1f) + 0.1);
    sp34->Scale.z = sp34->Scale.y = sp34->Scale.x;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp2C, &sp30, 0.0f, -30.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    sp34->unkB2 -= 1;
    if (sp34->unkB2 <= 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_803399E4_unk_bin_51(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unkE6[0] == -1) {
        func_80339734_unk_bin_51();
    } else if (sp24->unkA6 > 0) {
        if (sp24->Scale.x > 1.6f) {
            sp24->Scale.x -= 0.8f;
            sp24->Scale.y = sp24->Scale.z = sp24->Scale.x;
        }
        sp24->unkA6 -= 1;
    }
}
