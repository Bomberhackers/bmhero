#include <ultra64.h>

void func_800FACF0(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801136D0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].Scale.x = 0.10f;
        gObjects[sp24].Scale.y = 0.10f;
        gObjects[sp24].Scale.z = 0.10f;
    }
}

void func_800FAE00(void) {
}

void func_800FAE10(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x19E, D_80116EC4);
        func_8001BB34(gCurrentParsedObject, 1);
    }
    if (func_8002A1FC(gCurrentParsedObject, 660.0f) != 0) {
        func_8002AE38(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 1.0f, 0x10);
        sp24->actionState = 2;
        sp24->unk132 = 0;
    }
}

void func_800FAF10(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkA6 = 0x1E;
        func_8001BB34(gCurrentParsedObject, 0);
    }
    if (obj->unkA6 == 0) {
        obj->actionState = 3;
        obj->unk132 = 0;
    } else {
        obj->unkA6 -= 1;
        obj->Scale.x = (f32) ((f64) obj->Scale.x + 0.0299999999999999989);
        obj->Scale.y = (f32) ((f64) obj->Scale.y + 0.0299999999999999989);
        obj->Scale.z = (f32) ((f64) obj->Scale.z + 0.0299999999999999989);
    }
}

void func_800FB05C(void) {
    s32 spCC;
    s32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    Mtx_t sp7C;
    Mtx_t sp3C;
    struct ObjectStruct* obj; // sp38

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132++;
        func_8001C0EC(gCurrentParsedObject, 3, 1, 0x19E, &D_80116EC4);
        func_8001BBDC(gCurrentParsedObject, 0);
    }

    spCC = func_8002A640(gCurrentParsedObject, 10.0f);
    obj->Rot.y = Math_WrapAngle(obj->Rot.y, (f32) (spCC * 0xA));
    obj->moveAngle = obj->Rot.y;

    if (func_8001B62C(gCurrentParsedObject, 3) == 30.0f) {
        guRotateF((f32(*)[4]) sp7C[0], obj->Rot.y, 0.0f, 1.0f, 0.0f);
        guTranslateF((f32(*)[4]) & sp3C[0], obj->Pos.x, obj->Pos.y, obj->Pos.z);
        guMtxCatF((f32(*)[4]) & sp7C[0], (f32(*)[4]) & sp3C[0], (f32(*)[4]) & sp7C[0]);
        guMtxXFMF((f32(*)[4]) & sp7C[0], -30.0f, 0.0f, 30.0f, &spC4, &spC0, &spBC);

        spC8 = func_80027464(1, &D_801136DC, spC4, spC0, spBC, obj->Rot.y);
        if (spC8 != -1) {
            gObjects[spC8].moveAngle = obj->moveAngle;
            gObjects[spC8].Scale.x = gObjects[spC8].Scale.y = gObjects[spC8].Scale.z = 0.1000000015f;
        }
    }
    if (func_8001B44C(gCurrentParsedObject, 3) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
        obj->actionState = 4;
        obj->unk132 = 0;
    }
}

void func_800FB344(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        sp1C->unkA6 = 0x1C;
        sp1C->unkB6 = 7;
        sp1C->unkB8 = (s16) (s32) sp1C->Pos.y;
    }
    if (sp1C->unkB6 < 0xE) {
        sp1C->Pos.y = (f32) ((f64) sp1C->Pos.y + 1.5);
    } else {
        sp1C->Pos.y = (f32) ((f64) sp1C->Pos.y - 1.5);
    }
    sp1C->unkB6 += 1;
    if (sp1C->unkB6 == 0x1C) {
        sp1C->unkB6 = 0;
    }
    if (sp1C->unkA6 == 0) {
        sp1C->actionState = 3;
        sp1C->unk132 = 0;
        sp1C->Pos.y = (f32) sp1C->unkB8;
    } else {
        sp1C->unkA6 -= 1;
    }
    if (func_8002A1FC(gCurrentParsedObject, 700.0f) == 0) {
        sp1C->actionState = 5;
        sp1C->unk132 = 0;
    }
}

void func_800FB548(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        sp1C->unkA6 = 0x1E;
    }
    if (sp1C->unkA6 == 0) {
        func_8001BB34(gCurrentParsedObject, 1);
        sp1C->actionState = 1;
        sp1C->unk132 = 0;
    } else {
        sp1C->unkA6 -= 1;
        sp1C->Scale.x = (f32) ((f64) sp1C->Scale.x - 0.0299999999999999989);
        sp1C->Scale.y = (f32) ((f64) sp1C->Scale.y - 0.0299999999999999989);
        sp1C->Scale.z = (f32) ((f64) sp1C->Scale.z - 0.0299999999999999989);
    }
}

void func_800FB694(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800FAE10();
            break;
        case 2:
            func_800FAF10();
            break;
        case 3:
            func_800FB05C();
            break;
        case 4:
            func_800FB344();
            break;
        case 5:
            func_800FB548();
            break;
        default:
            break;
    }
}

void func_800FB764(void) {
    if (D_80177A64 == 2) {
        gObjects[gCurrentParsedObject].unkA6 = 0;
        gObjects[gCurrentParsedObject].actionState = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800FB804(void) {
    struct ObjectStruct* obj;
    f32 sp20;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unk44 = 8.0f;
        obj->unkA6 = 0x14;
        func_80029EF8(gCurrentParsedObject, 2.0f, 0.5f);
    }
    if (obj->unkA6 != 0) {
        obj->unkA6 -= 1;
        obj->Scale.x = (f32) ((f64) obj->Scale.x + 0.0449999999999999983);
        obj->Scale.y = (f32) ((f64) obj->Scale.y + 0.0449999999999999983);
        obj->Scale.z = (f32) ((f64) obj->Scale.z + 0.0449999999999999983);
    }
    sp20 = obj->Vel.y;
    obj->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 15.0f, 0.0f, 0.0f, 0.0f) != 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
    }
    obj->Vel.y = sp20;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -15.0f, 15.0f) == 1) {
        obj->actionState = 2;
        obj->unk132 = 0;
    }
}

void func_800FBA24(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
    func_8007EDF4(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 1.0f);
    func_8002B114(gCurrentParsedObject);
}

void func_800FBAB8(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800FB804();
            break;
        case 2:
            func_800FBA24();
            break;
        default:
            break;
    }
}

void func_800FBB4C(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113694, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].actionState = 0x64;
        gObjects[sp24].Scale.x = -1.0f;
        func_800193CC(sp24, 1, 2, 0);
    }
}

void func_800FBC40(void) {
    if (D_80177A64 == 0) {

    } else if (D_80177A64 == 1) {

    } else {
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800FBCB0(void) {
    struct ObjectStruct* sp2C;
    UNUSED s32 sp28;
    s32 sp24;
    f32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 1, &D_80115808);
    }
    sp24 = func_8001B880(0, 0);
    sp20 = func_8001B62C(0, 0);
    func_8001C0EC(gCurrentParsedObject, 0, sp24, 1, &D_80115808);
    func_8001B6BC(gCurrentParsedObject, 0, sp20);
    sp2C->Pos.x = gPlayerObject->Pos.x;
    sp2C->Pos.y = gPlayerObject->Pos.y;
    sp2C->Pos.z = -1860.0f - gPlayerObject->Pos.z;
    sp2C->Rot.y = 180.0f - gPlayerObject->Rot.y;
    if (sp2C->Rot.y < 0.0f) {
        sp2C->Rot.y += 360.0f;
    }
}

void func_800FBE54(void) {
    if (gPlayerObject->Pos.z < -930.0f) {
        func_8001BB34(gCurrentParsedObject, 1);
    } else {
        func_8001BB34(gCurrentParsedObject, 0);
    }
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 0x64:
            func_800FBCB0();
            break;
    }
}

void func_800FBF10(void) {
    s16 sp26;

    sp26 = func_80027464(1, &D_80113EBC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].actionState = 1;
        gObjects[sp26].unkAA = 1;
        gObjects[sp26].unkA6 = 0x258;
        gObjects[sp26].unkB2 = 0x3C;
        gObjects[sp26].unkAC = 0;

        if (D_80165100->unkA == 2) {
            D_80165100->unkA = 0;
        }
        gObjects[sp26].unkA8 = D_80165100->unkA % 4;
        gObjects[sp26].Rot.y = gObjects[sp26].unkA8 * 0x5A;
        gObjects[sp26].unk132 = 0;
        gObjects[sp26].damageState = 1;
        func_8001C0EC(sp26, 0, 0, 0x1A7, &D_80117504);
        func_80019448(sp26, 2, 0, 1);
        func_8001ABF4(sp26, 0, 0, &D_8011758C);
        func_8001ABF4(sp26, 1, 0, &D_80117554);
    }
}

void func_800FC1D8(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        return;
    }
    if (D_80177A64 == 0) {
        D_80165242 += 1;
        func_80081468(0x2CB, sp1C->Pos.x, sp1C->Pos.y + 120.0f, sp1C->Pos.z);
        sp1C->damageState = 0;
        sp1C->actionState = 3;
        sp1C->unk132 = 0;
    } else {
        sp1C->damageState = 0;
        sp1C->actionState = 4;
        sp1C->unk132 = 0;
    }
}

void func_800FC2E4(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk44 = 3.0f;
        obj->unk48 = 0.0f;
        obj->moveAngle = (f32) (obj->unkA8 * 0x5A);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    if ((obj->unkAC == 0)) {
        if (obj->unkAA != -1) {
            obj->unkAA = -1;
            obj->actionState = 6;
            obj->unk132 = 0;
            obj->unkAC = 1;
        }
    }

    if ((func_8002A1FC(gCurrentParsedObject, 600.0f) != 0)) {
        if ((obj->unkAA != -1)) {
            obj->unkAA = -1;
            obj->actionState = 2;
            obj->unk132 = 0;
            obj->unkAC = 1;
        }
    }

    obj->unkA6 = (s16) (s32) ((f32) obj->unkA6 - obj->unk44);
    if (obj->unk54 - 50.0f > obj->Pos.y + obj->Vel.y) {
        obj->Pos.y = obj->unk54 - 50.0f;
        obj->Vel.y = 0.0f;
        obj->unk132 = 2;
    }

    if ((obj->unk54 + 20.0f) < (obj->Pos.y + obj->Vel.y)) {
        obj->Pos.y = obj->unk54 + 20.0f;
        obj->Vel.y = 0.0f;
        obj->unk132 = 2;
    }

    if (obj->unkA6 <= 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
        obj->unkA6 = 0x258;
        obj->unkAC = 0;
        obj->unkA8 = (s16) ((s32) (obj->unkA8 + 2) % 4);

        if (func_8002A1FC(gCurrentParsedObject, 600.0f) == 0) {
            obj->unkAA = obj->unkAA < 0 ? -obj->unkAA : obj->unkAA;
        } else if (obj->unkAA != -1) {
            obj->unkAA = -1;
        } else {
            obj->actionState = 1;
            obj->unk132 = 0;
        }
    }
}

void func_800FC6BC(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk44 = 0.0f;
        obj->unk48 = (f32) (obj->unkAA * 2);
        obj->unk40 = 90.0f;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_800175F0(gCurrentParsedObject, 0, 0x36, -1, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((obj->unk54 - 50.0f) > (obj->Pos.y + obj->Vel.y)) {
        obj->Pos.y = obj->unk54 - 50.0f;
        obj->Vel.y = 0.0f;
        obj->unk132 = 2;
    }
    if ((obj->unk54 + 20.0f) < (obj->Pos.y + obj->Vel.y)) {
        obj->Pos.y = obj->unk54 + 20.0f;
        obj->Vel.y = 0.0f;
        obj->unk132 = 2;
    }
    if (obj->unk132 == 2) {
        obj->actionState = 1;
        obj->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}

void func_800FC8D0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkB0 = 0x44;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801175A8);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117570);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkB0 == 0x20) {
        func_800175F0(gCurrentParsedObject, 0, 0x80, -1, 0);
        func_800FD04C((s16) gCurrentParsedObject, 0, 1);
    }
    sp24->unkB0 -= 1;
    if (sp24->unkB0 <= 0) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011758C);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117554);
    }
}

void func_800FCA8C(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk44 = 0.0f;
        obj->unk48 = 0.0f;
        obj->unkB2 = 0x3C;
        obj->damageState = 0;
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
        func_8001BB34(gCurrentParsedObject, 0);
        func_80029EF8(gCurrentParsedObject, 0.0f, 0.5f);
    }
    obj->Rot.x = Math_WrapAngle(obj->Rot.x, -2.0f);
    obj->Rot.z = Math_WrapAngle(obj->Rot.z, -0.400000006f);
    if (obj->Rot.x < 180.0f) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    obj->unkB2 -= 1;
    if (obj->unkB2 <= 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_800FCC98() {
    struct ObjectStruct* sp2C;
    f32 sp28;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->damageState = 0x3C;
        sp2C->unkB0 = 0;
    }
    func_8001BB34(gCurrentParsedObject, !(sp2C->damageState & 1));
    sp2C->unkB0 = (s16) (s32) Math_WrapAngle((f32) sp2C->unkB0, 16.0f);
    sp28 = sinf((f32) ((f64) sp2C->moveAngle * DEG_TO_RAD)) * 20.0f;
    sp2C->Rot.z = Math_WrapAngle(0.0f, sp28);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((sp2C->unk54 - 50.0f) > (sp2C->Pos.y + sp2C->Vel.y)) {
        sp2C->Pos.y = sp2C->unk54 - 50.0f;
        sp2C->Vel.y = 0.0f;
        sp2C->unk132 = 2;
    }
    if ((sp2C->unk54 + 20.0f) < (sp2C->Pos.y + sp2C->Vel.y)) {
        sp2C->Pos.y = sp2C->unk54 + 20.0f;
        sp2C->Vel.y = 0.0f;
        sp2C->unk132 = 2;
    }
    if (sp2C->damageState == 1) {
        if (sp2C->unkAA != -1) {
            sp2C->actionState = 6;
        } else {
            sp2C->unkAA = 1;
            sp2C->unkAC = 0;
            sp2C->actionState = 2;
        }
        sp2C->unk132 = 0;
        sp2C->Rot.z = 0.0f;
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

void func_800FCF68(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].actionState;
    switch (sp1C) {
        case 1:
            func_800FC2E4();
            break;
        case 2:
            func_800FC6BC();
            break;
        case 6:
            func_800FC8D0();
            break;
        case 4:
            func_800FCC98();
            break;
        case 3:
            func_800FCA8C();
            break;
        case 5:
            break;
        default:
            break;
    }
}

s32 func_800FD04C(s16 arg0, s16 arg1, s32 arg2) {
    struct ObjectStruct* sp3C;
    struct ObjectStruct* sp38;
    f32 sp34;
    s16 sp32;
    s16 sp30;

    sp3C = &gObjects[arg0];
    sp32 = func_80027464(1, &D_80113EC8, sp3C->Pos.x, sp3C->Pos.y, sp3C->Pos.z, sp3C->moveAngle);
    if (sp32 != -1) {
        func_80026F10((s32) (s16) arg0, (s32) sp32);
        sp38 = &gObjects[sp32];
        sp30 = (s16) arg1 - 1;

        sp38->moveAngle = Math_WrapAngle(sp3C->moveAngle, (f32) (sp30 * 0x23));
        sp38->unk40 = Math_WrapAngle(sp3C->unk40, (f32) (sp30 * 8));
        sp38->unk40 = Math_NormalizeAngle(sp38->unk40);
        sp38->unk44 = (f32) (((s16) arg1 * 3) + 0xF);
        sp38->unk48 = sp3C->unk48;
        sp38->unkA6 = 0;
        sp38->unkB2 = (sp30 * 0xA) + 0x64;
        sp38->Scale.y = sp38->Scale.z = sp38->Scale.x = 0.5f;

        if ((u8) arg2 == 1) {
            sp34 = Math_WrapAngle(sp3C->Rot.y, 0.0f);
            sp38->Vel.x = sinf((f32) ((f64) sp34 * DEG_TO_RAD)) * 95.0f;
            sp38->Vel.z = cosf((f32) ((f64) sp34 * DEG_TO_RAD)) * 95.0f;

            sp38->Pos.x += sp38->Vel.x;
            sp38->Pos.z += sp38->Vel.z;
            sp38->Pos.y += 130.0f; // jumping?

            sp38->moveAngle = Get_AngleToPlayer(gCurrentParsedObject);
            sp38->unk40 = 90.0f;
            sp38->unk44 = 10.0f;
            sp38->unk48 = 0.0f;
            sp38->unkA6 = 0x12;
            sp38->unkB2 = 0x32;
        }

        sp38->Rot.x = 270.0f;
        sp38->actionState = 1;
        sp38->unkA8 = (s16) arg1;
        sp38->unkAA = (s16) (u8) arg2;
        sp38->unk132 = 0;
        func_8001BB34((s32) sp32, 1);
    }
    return sp32;
}

void func_800FD3F8(void) {
}

void func_800FD408(void) {
    func_8002B0E4(gCurrentParsedObject);
    return;
}

void func_800FD440(void) {
    struct ObjectStruct* obj;
    struct ObjectStruct* PlayerObject;
    f32 sp3C;
    f32 sp38;
    s32 sp34;
    f32 sp30;
    s16 sp2E;

    PlayerObject = &PLAYER_OBJ;
    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        func_800272E8(gCurrentParsedObject);
        func_80019448(gCurrentParsedObject, 2, 0, 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1A8, &D_801175C4);
        func_8001BB34(gCurrentParsedObject, 0);
    }

    obj->unkA6++;
    if (obj->unkA6 >= 0x12) {
        sp2E = 0;
        if (obj->unkAA == 0) {
            sp2E = (-obj->unkA8 * 4) + 0xC;
        }
        sp30 = Math_CalcAngleRotated(PlayerObject->Pos.x - obj->Pos.x, PlayerObject->Pos.z - obj->Pos.z);
        sp34 = func_800157EC(obj->moveAngle, sp30, (f32) (sp2E + 0xC));
        if (obj->unkAA == 0) {
            sp34 *= 3;
        } else if (obj->Scale.x < 1.399999976f) {
            obj->Scale.x += 0.1000000015f;
            obj->Scale.y = obj->Scale.z = obj->Scale.x;
        }
        obj->moveAngle = Math_WrapAngle(obj->moveAngle, (f32) sp34);
        sp30 = Math_CalcAngleSimple(PlayerObject->Pos.x - obj->Pos.x, PlayerObject->Pos.y - obj->Pos.y);
        sp30 = Math_NormalizeAngle(sp30);
        sp34 = func_800157EC(obj->unk40, sp30, (f32) (sp2E + 0xC));
        if (obj->unkAA == 0) {
            sp34 *= 3;
        }
        obj->unk40 = Math_WrapAngle(obj->unk40, (f32) sp34);
    }

    obj->Rot.y = obj->moveAngle;
    obj->Rot.x = Math_WrapAngle(360.0f, -obj->unk40);
    func_80029D8C(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp3C, 0.0f, -120.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_80029018(gCurrentParsedObject, 4U, 0.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    obj->unkB2 -= 1;
    if (obj->unkB2 <= 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
    }
}

void func_800FD874(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unkAA == 1) {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_800FD04C(gCurrentParsedObject, 0, 0);
        func_800FD04C(gCurrentParsedObject, 1, 0);
        func_800FD04C(gCurrentParsedObject, 2, 0);
    }
    func_8002B0E4(gCurrentParsedObject);
}

void func_800FD940(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].actionState) {
            case 1:
                func_800FD440();
                break;
            case 2:
                func_800FD874();
                break;
            default:
                break;
        }
    }
}
