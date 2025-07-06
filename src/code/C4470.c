#include "common.h"
#include "debug.h"

void func_800D1F50(void) {
    UNUSED s32 sp24;

    sp24 = func_80027464(1, &D_801140F0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
}

void func_800D1FCC(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 6;
        gObjects[gCurrentParsedObject].unk132 = 0;
    } else if (D_80177A64 == 1 && gObjects[gCurrentParsedObject].damageState == 1) {
        gObjects[gCurrentParsedObject].actionState = 5;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800D20E4(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x94, &D_80118530);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118600 + 0xFC / 4);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80118600 + 0x118 / 4);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80118600 + 0x134 / 4);
    }
    if (func_8002A1FC(gCurrentParsedObject, 360.0f) != 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
    }
}

void func_800D2208(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = 0x28;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118600);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80118600 + 0x1C / 4);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80118600 + 0x38 / 4);
    }
    if (obj->unkA6 == 0) {
        obj->damageState = 1;
        obj->actionState = 3;
        obj->unk132 = 0;
    } else {
        obj->unkA6 -= 1;
    }
}

void func_800D2334(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = 0x14;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x94, &D_80118530);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118600 + 0x54 / 4);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80118600 + 0x70 / 4);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80118600 + 0x8C / 4);
    }
    if (obj->unkA6 == 0) {
        obj->actionState = 4;
        obj->unk132 = 0;
    } else {
        obj->unkA6 -= 1;
    }
}

void func_800D247C(void) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x94, &D_80118530);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 64.0f) {
        sp30 = func_80027464(1, &D_801140FC, sp34->Pos.x, sp34->Pos.y + 60.0f, sp34->Pos.z, sp34->Rot.y);
        if (sp30 != -1) {
            gObjects[sp30].Scale.x = gObjects[sp30].Scale.y = gObjects[sp30].Scale.z = 1.5f;
            func_800175F0(gCurrentParsedObject, 0, 0x5B, -1, 0);
        }
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x18, -1, 0);
        sp34->actionState = 3;
        sp34->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
}

void func_800D26A0(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        gObjects[gCurrentParsedObject].damageState = 0x32;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x94, &D_80118530);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118600 + 0xA8 / 4);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80118600 + 0xC4 / 4);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80118600 + 0xE0 / 4);
    }
    if ((gObjects[gCurrentParsedObject].damageState) >= 2) {
        func_8001BB34(gCurrentParsedObject, !(obj->damageState % 2));
    }
    if (obj->damageState == 1) {
        func_8001BB34(gCurrentParsedObject, 0);
        obj->actionState = 3;
        obj->unk132 = 0;
    }
}

void func_800D2870(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800D28A0(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800D20E4();
            break;
        case 2:
            func_800D2208();
            break;
        case 3:
            func_800D2334();
            break;
        case 4:
            func_800D247C();
            break;
        case 5:
            func_800D26A0();
            break;
        case 6:
            func_800D2870();
            break;
        default:
            break;
    }
}

void func_800D2980(void) {
    if ((D_80177A64 == 0) || (D_80177A64 == 2)) {
        gObjects[gCurrentParsedObject].actionState = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800D2A04(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 30.0f;
        sp24->unkA6 = 1;
        func_8001BBDC(gCurrentParsedObject, 1);
    }

    if (sp24->unkA6 != 0) {
        sp24->unkA6 -= 1;
        sp24->unkA8 = (s16) (s32) Get_AngleToPlayer(gCurrentParsedObject);
        if (sp24->unkA8 >= 0xB4) {
            sp24->unkAA = -5;
            sp24->unkAC = -4;
        } else {
            sp24->unkAC = 5;
            sp24->unkAA = 4;
        }
        sp24->unkAE = 4;
    } else {
        if (sp24->unkAE != 0) {
            sp24->unkB0 = (s16) (s32) Math_WrapAngle(sp24->moveAngle, (f32) -sp24->unkA8);
            if ((sp24->unkB0 < 6) || (sp24->unkB0 >= 0x163)) {
                sp24->moveAngle = Math_WrapAngle(sp24->moveAngle, (f32) sp24->unkAA);
                sp24->unkAE -= 1;
            } else {
                sp24->unkAE = 0;
            }
        } else {
            sp24->moveAngle = (f32) sp24->unkA8;
        }
        sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, (f32) sp24->unkAC);
    }

    sp24->Vel.y = 0.0f;

    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
        sp24->actionState = 2;
        sp24->unk132 = 0;
    }
}

void func_800D2D34(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800D2D64(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].actionState) {
            case 1:
                func_800D2A04();
                break;

            case 2:
                func_800D2D34();
                break;

            default:
                break;
        }
    }
}

void func_800D2E2C(void) {
    func_80027464(1, &D_80114108, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800D2EA4(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 4;
    }
}

void func_800D2F1C(void) {
    struct ObjectStruct* sp34;
    UNUSED s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z = 0.0f;

        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x96, &D_80118754);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118784);
        func_8001BB04(gCurrentParsedObject, 1);
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        sp34->actionState = 2;
        sp34->unk132 = 0;
    }
}

void func_800D3048(void) {
    struct ObjectStruct* obj;
    f32 sp28;
    f32 sp24;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unk44 = 0.0f;
        obj->unk40 = 90.0f;
        obj->unk48 = 8.0f;
        func_8001BB04(gCurrentParsedObject, 0);
    }
    func_80029D04(gCurrentParsedObject);
    if ((func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) == 0)) {
        if ((obj->Pos.y >= (sp28 + 90.0f))) {
            obj->Vel.y = 0.0f;
            obj->damageState = 1;
            obj->actionState = 3;
            obj->unk132 = 0;
        }
    }
}

void func_800D31A8(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = 1;
        sp3C->unkAC = 0;
        sp3C->unk44 = 0.0f;
        sp3C->moveAngle = Get_AngleToPlayer(gCurrentParsedObject);
        func_8001ABF4(
            gCurrentParsedObject, 0, 0,
            &D_80118784 +
                0x1C / 4); // this line WILL have to be refactored later, but we gotta figure out WHAT this is first
    }
    if (sp3C->unk44 != 12.0f) {
        sp3C->unk44 = (f32) ((f64) sp3C->unk44 + 0.5);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp3C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 45.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) {
        sp30 = sp34;
    } else {
        sp30 = sp38;
    }
    sp3C->Pos.y = 90.0f + sp30;
}

void func_800D33B0(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800D33E0(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800D2F1C();
            break;
        case 2:
            func_800D3048();
            break;
        case 3:
            func_800D31A8();
            break;
        case 4:
            func_800D33B0();
            break;
        default:
            break;
    }
}

void func_800D34AC(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114114, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkBA = D_80165100->unkA;
    }
}

void func_800D3568(void) {
}

void func_800D3578(void) {
    struct ObjectStruct* obj;
    s32 sp20;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = 0x1E;
        func_8001BB34(gCurrentParsedObject, 1);
    }
    if (obj->unkA6 == 0) {
        if (obj->unkA8 < 2) {
            sp20 =
                func_80027464(1, &D_80114120, obj->Pos.x, obj->Pos.y, obj->Pos.z, 0.0f);
            if (sp20 != -1) {
                gObjects[sp20].unkBA = obj->unkBA;
                obj->unkA6 = 0x1E;
                obj->unkA8 += 1;
            }
        }
    } else {
        obj->unkA6 -= 1;
    }
}

void func_800D36E8(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1: {
            func_800D3578();
            break;
        }
        default:
            break;
    }
}

void func_800D375C(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if ((D_80177A64 == 0) && (obj->actionState == 2)) {
        obj->actionState = 3;
        obj->unk132 = 0;
    } else if ((D_80177A64 == 2) && (obj->actionState == 2)) {
        obj->actionState = 3;
        obj->unk132 = 0;
    }
}

void func_800D3824(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk44 = 0.0f;
        obj->unk40 = 90.0f;
        obj->unk48 = 5.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x97, &D_801187BC);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        obj->unk48 = 0.0f;
        obj->Vel.y = obj->unk48;
        obj->actionState = 2;
        obj->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
}

void func_800D3974(void) {
    struct ObjectStruct* obj;
    f32 sp30;
    f32 sp2C;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA8 = 0xA;
        obj->unkAC = (s16) (s32) obj->Pos.x;
        obj->unkAE = (s16) (s32) obj->Pos.z;
        obj->moveAngle = (f32) Math_Random(0x168);
        obj->unk44 = 4.0f;
        obj->unkB6 = (s16) (s32) obj->Pos.y;
        obj->unkB8 = 0;
        obj->unk40 = 90.0f;
        obj->unk48 = 30.0f;
        obj->damageState = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x97, &D_801187BC);
        func_8001BBDC(gCurrentParsedObject, 0);
    }

    if ((obj->unkA8 == 0) && (func_80028FA0(gCurrentParsedObject) != 0)) {
        func_80029B60(gCurrentParsedObject);
        obj->unkA8 = 0xA;
    }

    obj->moveAngle = Math_WrapAngle(obj->moveAngle, 0.5f);
    func_80029C40(gCurrentParsedObject);
    obj->unkB8 = Math_WrapAngle(obj->unkB8, 10.0f);
    func_800294F0(gCurrentParsedObject, &sp30, &sp2C, 0.0f, 0.0f, 0.0f);
    obj->unk48 =
        sinf(obj->unkB8 * DEG_TO_RAD) * 30.0f + obj->unkB6 - obj->Pos.y;
    func_80029D04(gCurrentParsedObject);

    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        obj->unkA8 = 0xA;
    }
    if (obj->unkA8 == 0) {
        obj->unkB0 = (obj->Pos.x - obj->unkAC);
        obj->unkB2 = (obj->Pos.z - obj->unkAE);
        if ((obj->unkB0 >= 0x190) || (obj->unkB0 < -0x18F)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            obj->unkA8 = 0xA;
        } else {
            if ((obj->unkB2 >= 0x190) || (obj->unkB2 < -0x18F)) {
                func_80029824(gCurrentParsedObject, func_800297DC());
                obj->unkA8 = 0xA;
            }
        }
    }
    if (obj->unkA8 != 0) {
        obj->unkA8 -= 1;
    }
}

void func_800D3E54(void) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->damageState = 0;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x97, &D_801187BC);
        func_8001BBDC(gCurrentParsedObject, 0);
    }

    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp30 = 0xE;

        while (TRUE) {
            sp30 = Get_ObjIdx_ByPos(0xCC, sp30);

            if (sp30 == -1) {
                break;
            } else if (gObjects[sp30].unkBA == sp34->unkBA) {
                if (gObjects[sp30].unkA8 != 0) {
                    gObjects[sp30].unkA8--;
                }
                break;
            } else
                sp30++;
        }
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800D4064(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800D3824();
            break;
        case 2:
            func_800D3974();
            break;
        case 3:
            func_800D3E54();
            break;
        default:
            break;
    }
}

void func_800D4114(void) {
    func_80027464(1, &D_8011412C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800D418C(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114138, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].Rot.x = 90.0f;
        func_80019448(sp24, 2, 0, 1);
    }
}

void func_800D4258(void) {
}

void func_800D4268(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x98, &D_801187C8);
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_80118848);
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BBDC(gCurrentParsedObject, 0);
        sp34->Scale.x = sp34->Scale.y = sp34->Scale.z = 1.5f;
        func_800175F0(gCurrentParsedObject, 0, 0x44, -1, 0);
    }
    sp30 = func_8001B62C(gCurrentParsedObject, 3);
    if ((sp30 >= 20.0f) && (sp30 <= 60.0f)) {
        sp34->damageState = 1;
    } else {
        sp34->damageState = 0;
    }
    if (func_8001B44C(gCurrentParsedObject, 3) != 0) {
        sp34->actionState = 2;
        sp34->unk132 = 0;
    }
}

void func_800D4430(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkA6 = 0;
        obj->damageState = 0;
        func_8001BB34(gCurrentParsedObject, 1);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (obj->unkA6 >= 0x2E) {
        obj->actionState = 1;
        obj->unk132 = 0;
    } else {
        obj->unkA6 += 1;
    }
}

void func_800D4530(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800D4268();
            break;
        case 2:
            func_800D4430();
            break;
        default:
            break;
    }
}

void func_800D45C4(void) {
    func_80027464(1, &D_80114144, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void stub_unknown_800D45C4() {
}

void func_800D464C(void) {
    struct ObjectStruct* obj;
    UNUSED s32 sp20;
    f32 sp1C;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        func_8001BB34(gCurrentParsedObject, 1);
        func_8001BB04(gCurrentParsedObject, 1);
    }
    sp1C = (gPlayerObject->Pos.y + 750.0f) - obj->Pos.y;
    if ((sp1C > -350.0f) && (sp1C < 50.0f)) {
        sp1C = gPlayerObject->Pos.x - obj->Pos.x;
        if ((sp1C > -800.0f) && (sp1C < 800.0f)) {
            obj->actionState = 2;
            obj->unk132 = 0;
        }
    }
}

void func_800D47C0(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;
    UNUSED s32 sp34;
    UNUSED s32 sp30;
    f32 sp2C;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unkA6 = 0;
        sp3C->unkAA = 0xFF;
    }
    if (sp3C->unkAA == 0xFF) {
        if (sp3C->unkA6 == 0) {
            sp38 = func_80027464(1, &D_80114150, sp3C->Pos.x, sp3C->Pos.y, sp3C->Pos.z, 0.0f);
            if (sp38 != -1) {
                gObjects[sp38].Rot.y = gObjects[sp38].moveAngle = sp3C->Rot.y;
                sp3C->unkA6 = 0x96;
            }
        } else {
            sp3C->unkA6 -= 1;
        }
        sp2C = (gPlayerObject->Pos.y + 750.0f) - sp3C->Pos.y;
        if ((sp2C <= -800.0f) || (sp2C >= 50.0f)) {
            sp3C->unkAA = 0x96;
        }
    } else if (sp3C->unkAA != 0) {
        sp3C->unkAA -= 1;
    } else {
        sp3C->actionState = 1;
        sp3C->unk132 = 0;
    }
}

void func_800D4A10(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800D464C();
            break;
        case 2:
            func_800D47C0();
            break;
        default:
            break;
    }
}

void func_800D4AA4(void) {
}

void func_800D4AB4(void) {
    struct ObjectStruct* sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 0.0f, 2.0f);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB3, &D_80118864);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    sp20 = sp24->Vel.y;
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 2U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    sp24->Vel.y = sp20;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -120.0f, 60.0f) == 1) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
        sp24->actionState = 2;
        sp24->unk132 = 0;
    }
}

void func_800D4C8C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 8.0f, 1.0f);
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -120.0f, 60.0f) == 1) {
        sp24->actionState = 3;
        sp24->unk132 = 0;
    }
}

void func_800D4D74(void) {
    // something something "circle of 120.0f OR 140.0f size"
    struct ObjectStruct* obj;
    f32 sp38;
    f32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
    }

    if (obj->unkA6 == 0) {
        obj->unk44 = 13.0f;
        obj->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        sp30 = sinf(obj->moveAngle * DEG_TO_RAD) * 120.0f + obj->Pos.x;
        sp28 = cosf(obj->moveAngle * DEG_TO_RAD) * 120.0f + obj->Pos.z;
        sp2C = (s32) (obj->Pos.y - 120.0f);

        func_80067748((f32) sp30, (f32) sp2C, (f32) sp28);
        sp24 = D_801776E0 & 1;
        if (sp24 == 0) {
            sp2C = D_80177760[sp24];
            if (obj->Pos.y - 120.0f - sp2C >= 120.0f) {
                obj->actionState = 4;
                obj->unk132 = 0;
            } else {
                if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) {
                    obj->Pos.y = sp34;
                } else {
                    obj->Pos.y = sp38;
                }
                obj->Pos.y += 120.0f;
            }
        } else {
            if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) {
                obj->Pos.y = sp34;
            } else {
                obj->Pos.y = sp38;
            }

            obj->Pos.y += 120.0f;
            obj->unkA6 = 9;
            obj->unk44 = 0.0f;
            obj->Vel.z = 0.0f;
            obj->Vel.x = obj->Vel.z;
            obj->unkA8 = (s16) (s32) (obj->moveAngle - 90.0f);

            if (obj->unkA8 < 0) {}
            obj->unkAA = (s16) (s32) (obj->moveAngle + 90.0f);
            if (obj->unkAA >= 0x168) {}

            sp30 = sinf(obj->unkA8 * DEG_TO_RAD) * 140.0f + obj->Pos.x;
            sp28 = cosf(obj->unkA8 * DEG_TO_RAD) * 140.0f + obj->Pos.z;
            sp2C = obj->Pos.y - 120.0f;

            func_80067748(sp30, sp2C, sp28);
            sp24 = D_801776E0 & 1;
            if (sp24 == 0 && obj->Pos.y - 120.0f - D_80177760[sp24] <= 120.0f) {
                obj->unkB6 = -0xA;
            } else {
                sp30 = sinf(obj->unkAA * DEG_TO_RAD) * 140.0f + obj->Pos.x;
                sp28 = cosf(obj->unkAA * DEG_TO_RAD) * 140.0f + obj->Pos.z;
                sp2C = obj->Pos.y - 120.0f;

                func_80067748(sp30, sp2C, sp28);
                sp24 = D_801776E0 & 1;

                if (sp24 == 0 && obj->Pos.y - 120.0f - D_80177760[sp24] <= 120.0f) {
                    obj->unkB6 = 0xA;
                } else {
                    func_8002B114(gCurrentParsedObject);
                }
            }
        }
    } else {
        obj->moveAngle += obj->unkB6;
        obj->Rot.y = obj->moveAngle;
        obj->unkA6 -= 1;
    }
}

void func_800D5610(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = 0x1E;
        obj->unkD8 = 6.0f;
        obj->unk44 = 12.0f;
        func_80029EF8(gCurrentParsedObject, 2.0f, 0.75f);
    }
    if (obj->unkA6 == 0) {
        func_8002B0E4(gCurrentParsedObject);
    } else {
        func_80029C40(gCurrentParsedObject);
        if (obj->unkA6 < 0x19) {
            obj->Pos.y -= obj->unkD8;
            obj->unkD8 = (f32) ((f64) obj->unkD8 + 0.5);
        }
        obj->unkA6 -= 1;
    }
}

void func_800D577C(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800D4AB4();
            break;
        case 2:
            func_800D4C8C();
            break;
        case 3:
            func_800D4D74();
            break;
        case 4:
            func_800D5610();
            break;
        default:
            break;
    }
}

void func_800D5848(void) {
    func_80027464(1, &D_8011415C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800D58C0(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 4;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800D5938(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xA8, &D_80118868);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (gObjects->Pos.y < (obj->Pos.y - 60.0f)) {
        if (func_8002A1FC(gCurrentParsedObject, 1200.0f) != 0) {
            obj->actionState = 2;
            obj->unk132 = 0;
        }
    } else {
        obj->actionState = 3;
        obj->unk132 = 0;
    }
}

void func_800D5AA4(void) {
    struct ObjectStruct* obj;
    s32 sp40;
    f32 sp3C;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
        obj->unkA6 = obj->unkA8 = obj->unkAA = 0;

        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xA8, &D_80118868);
        func_8001BBDC(gCurrentParsedObject, 0);
        obj->damageState = -1;
    }
    if (obj->unkA6 != 0) {
        if (obj->unkA8 == 1 || obj->unkA8 == 3) {
            if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
                obj->unkA6 = 0;
                obj->unkA8 += 1;
                func_8001BBDC(gCurrentParsedObject, 1);
            }
        } else if (obj->unkA8 == 3) {
            if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
                obj->unkA6 = 0;
                obj->unkA8 += 1;
                func_8001C0EC(gCurrentParsedObject, 0, 1, 0xA8, &D_80118868);
                func_8001BBDC(gCurrentParsedObject, 1);
            }
        } else {
            if (obj->unkA8 == 0 || obj->unkA8 == 2) {
                if (obj->unkAA == 0) {
                    obj->unkA6 = 0;
                    obj->unkA8++;
                } else {
                    obj->unkAA--;
                }
            } else if (obj->unkA8 == 4) {
                if (obj->unkAA < 0x28 && obj->unkAA >= 0x10) {
                    sp3C = obj->unkAA & 0xF;
                    if (sp3C == 3.0f || sp3C == 6.0f || sp3C == 9.0f) {
                        sp40 = func_80027464(1, &D_80114168, obj->Pos.x, obj->Pos.y - 20.0f,
                                             obj->Pos.z + 80.0f, obj->Rot.y);
                        if (sp40 != -1) {
                            func_8001ABF4(sp40, 0, 3, &D_80118898);

                            gObjects[sp40].Scale.x = gObjects[sp40].Scale.y = gObjects[sp40].Scale.z = 0.200000003f;
                            func_800175F0(gCurrentParsedObject, 0, 0x58, -1, 0);
                        }
                    }
                }
                if (obj->unkAA == 0) {
                    obj->unkA6 = 0;
                    obj->unkA8++;
                } else {
                    obj->unkAA -= 1;
                }
            }
        }
    } else {
        if (obj->unkA8 == 0 || obj->unkA8 == 2) {
            obj->unkA6 = 1;
            obj->unkAA = 5;
        } else if (obj->unkA8 == 1) {
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0xA8, &D_80118868);
            func_8001BBDC(gCurrentParsedObject, 0);
            obj->unkA6 = 1;
        } else if (obj->unkA8 == 3) {
            func_8001C0EC(gCurrentParsedObject, 0, 2, 0xA8, &D_80118868);
            func_8001BBDC(gCurrentParsedObject, 0);
            obj->unkA6 = 1;
        } else if (obj->unkA8 == 4) {
            obj->unkA6 = 1;
            obj->unkAA = 0x32;
            obj->damageState = 1;
        } else if (obj->unkA8 == 5) {
            func_8001BBDC(gCurrentParsedObject, 1);
            if (func_8002A2EC(gCurrentParsedObject, 1200.0f) != 0) {
                obj->unk132 = 0;
            } else {
                obj->actionState = 3;
                obj->unk132 = 0;
            }
        }
    }
}

void func_800D613C(void) {
    struct ObjectStruct* obj;
    f32 sp28;
    f32 sp24;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkA6 = Math_Random(0xA) & 1;
        obj->moveAngle = (f32) ((obj->unkA6 * 0xB4) + 0x5A);
        obj->unk44 = 5.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xA8, &D_80118868);
        func_8001BBDC(gCurrentParsedObject, 0);
        obj->damageState = 1;
    }
    obj->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 180.0f, 0.0f, 0.0f, 0.0f) != 0) {
        if (obj->moveAngle == 90.0f) {
            obj->moveAngle = 270.0f;
        } else {
            obj->moveAngle = 90.0f;
        }
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 60.0f, 0.0f) != 0) {
        obj->Pos.y = sp24;
    } else {
        obj->Pos.y = sp28;
    }
    obj->Pos.y += 60.0f;
    if ((func_8001B44C(gCurrentParsedObject, 0) != 0) && (func_8002A2EC(gCurrentParsedObject, 1200.0f) != 0)) {
        func_8001BBDC(gCurrentParsedObject, 1);
        obj->unk132 = 0;
        obj->actionState = 2;
    }
}

void func_800D63C4(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
        obj->unkA8 = 0;
        obj->damageState = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xA8, &D_80118868);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (obj->Rot.z >= 180.0f) {
        obj->unkA8 += 1;
    } else {
        obj->Rot.z += 10.0f;
    }
    if (obj->unkA8 == 0xF) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800D6540(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800D5938();
            break;
        case 2:
            func_800D5AA4();
            break;
        case 3:
            func_800D613C();
            break;
        case 4:
            func_800D63C4();
            break;
        default:
            break;
    }
}

void func_800D660C(void) {
    if (D_80177A64 == 2) {
        gObjects[gCurrentParsedObject].actionState = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800D6684(void) {
    struct ObjectStruct* obj;
    f32 sp40;
    f32 sp3C;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unk44 = 12.0f;
        obj->unk48 = 5.0f;
        obj->unkA6 = 1;
        obj->unkB6 = 0x32;
    }
    if (obj->unkA6 != 0) {
        obj->unkA6 -= 1;
        func_800158B4(gPlayerObject->Pos.x - obj->Pos.x,
                      (gPlayerObject->Pos.y + 60.0f) - obj->Pos.y,
                      gPlayerObject->Pos.z - obj->Pos.z, &sp40, &sp3C);
        obj->unkA8 = sp3C;
        if ((obj->unkA8 >= 0x2E) && (obj->unkA8 < 0xB5)) {
            obj->unkA8 = Math_WrapAngle(45.0f, Math_Random(-0xA));
        } else {
            if ((obj->unkA8 >= 0xB5) && (obj->unkA8 < 0x13C)) {
                obj->unkA8 = Math_WrapAngle(315.0f, Math_Random(-0xA));
            } else {
                obj->unkA8 = Math_WrapAngle(obj->unkA8, Math_Random(-0xF));
            }
        }
        sp40 = 360.0f - sp40;
        obj->unk40 = Math_WrapAngle(sp40, Math_Random(-5) + 0x14);
        if (obj->unkA8 >= 0xB4) {
            obj->unkAC = -5;
        } else {
            obj->unkAC = 5;
        }
        obj->unkAE = 0;
    } else if (obj->unkAE != 0) {
        obj->unkB0 = Math_WrapAngle(obj->moveAngle, -obj->unkA8);
        if ((obj->unkB0 < 6) || (obj->unkB0 >= 0x163)) {
            obj->moveAngle = Math_WrapAngle(obj->moveAngle, obj->unkAC);
            obj->unkAE -= 1;
        } else {
            obj->unkAE = 0;
        }
    } else {
        obj->moveAngle = obj->unkA8;
    }
    obj->Scale.x = obj->Scale.x + 0.0100000000000000002;
    obj->Scale.y = obj->Scale.y + 0.0100000000000000002;
    obj->Scale.z = obj->Scale.z + 0.0100000000000000002;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
        obj->actionState = 2;
        obj->unk132 = 0;
    } else if (obj->unkB6 == 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
    } else {
        obj->unkB6 -= 1;
    }
}

void func_800D6C14(void) {
    func_8002B114(gCurrentParsedObject);
}

void func_800D6C44(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].actionState) {
            case 1:
                func_800D6684();
                break;
            case 2:
                func_800D6C14();
                break;
            default:
                break;
        }
    }
}

void func_800D6D0C(void) {
    func_80027464(1, &D_80114228, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800D6D84(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 2;
    }
}

void func_800D6DFC(void) {
    struct ObjectStruct* obj;
    f32 sp40;
    f32 sp3C;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = obj->unkA8 = obj->unkB6 = 0;
        obj->unk44 = 0.0f;
        obj->Rot.y = obj->moveAngle;
        func_80017664(gCurrentParsedObject, 0, 0x59, -1, 0);
    }
    if ((obj->unkB6 == 0) && (obj->unkA6 == 0) && (func_80028FA0(gCurrentParsedObject) != 0)) {
        obj->unkB6 = 5;
        obj->unkB8 = (s16) (s32) obj->moveAngle;
        obj->unk44 = 8.0f;
        obj->moveAngle += 180.0f;
        if (obj->moveAngle >= 360.0f) {
            obj->moveAngle -= 360.0f;
        }
    }
    if (obj->unkB6 != 0) {
        obj->unkB6 -= 1;
        if (obj->unkB6 == 0) {
            obj->unk44 = obj->Vel.x = obj->Vel.z = 0;
            obj->unkA8 = (s16) (s32) obj->moveAngle;
            obj->moveAngle = (f32) obj->unkB8;
            obj->unkA6 = 1;
        }
    }
    if (obj->unkA6 != 0) {
        obj->moveAngle = Math_WrapAngle(obj->moveAngle, 10.0f);
        obj->Rot.y = obj->moveAngle;
        if ((obj->moveAngle - (f32) obj->unkA8) == 0.0f) {
            obj->unkA6 = 0;
        }
    } else {
        if (obj->unk44 < 12.0f) {
            obj->unk44 = (f32) ((f64) obj->unk44 + 0.25);
        }
        obj->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (obj->unkA6 == 0) {
            if (func_80029018(gCurrentParsedObject, 1U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
                obj->Vel.x = obj->Vel.y = obj->Vel.z = 0;
                if (obj->unkB6 == 0) {
                    obj->unkB6 = 5;
                    obj->unkB8 = (s16) (s32) obj->moveAngle;
                    obj->unk44 = 8.0f;
                    obj->moveAngle += 180.0f;
                    if (obj->moveAngle >= 360.0f) {
                        obj->moveAngle -= 360.0f;
                    }
                } else {
                    obj->unkB6 = 1;
                }
            }
            if (func_800295C0(gCurrentParsedObject, &sp40, &sp3C, 0.0f, 0.0f, 0.0f) != 0) {
                obj->Pos.y = sp3C;
            } else {
                obj->Pos.y = sp40;
            }
        }
    }
}

void func_800D7348(void) {
    struct ObjectStruct* obj;
    f32 sp20;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkA6 = 0x1E;
        obj->unk44 = 5.0f;
        obj->moveAngle = Math_WrapAngle(obj->unk128, 180.0f);
        func_80029EF8(gCurrentParsedObject, 14.378698f, 1.06089f);
        func_8001BBDC(gCurrentParsedObject, 1);
        obj->damageState = 0;
    }
    obj->Rot.y = Math_WrapAngle(obj->Rot.y, 25.0f);
    sp20 = obj->Vel.y;
    obj->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        obj->Vel.z = 0.0f;
        obj->Vel.x = obj->Vel.z;
    }
    obj->Vel.y = sp20;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        obj->unkA6 = 0;
    }
    if (obj->unkA6 == 0) {
        func_8002B0E4(gCurrentParsedObject);
    } else {
        obj->unkA6 -= 1;
    }
}

void func_800D7580(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800D6DFC();
            break;
        case 2:
            func_800D7348();
            break;
        default:
            break;
    }
}

void func_800D7614(void) {
    func_80027464(1, &D_80114234, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800D768C(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 2;
    }
}

void func_800D7704(void) {
    struct ObjectStruct* obj;
    f32 sp48;
    f32 sp44;
    s32 sp40;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = obj->unkA8 = obj->unkB6 = 0;
        obj->unk44 = 0.0f;
        obj->moveAngle = Math_Random(0x168);
        obj->Rot.y = obj->moveAngle;
        func_80017664(gCurrentParsedObject, 0, 0x59, -1, 0);
    }
    if ((obj->unkB6 == 0) && (obj->unkA6 == 0) && (func_80028FA0(gCurrentParsedObject) != 0)) {
        obj->unkB6 = 5;
        obj->unkB8 = obj->moveAngle;
        obj->unk44 = 8.0f;
        func_80029B60(gCurrentParsedObject);
    }
    if (obj->unkB6 != 0) {
        obj->unkB6 -= 1;
        if (obj->unkB6 == 0) {
            obj->unk44 = obj->Vel.x = obj->Vel.z = 0.0f;
            obj->moveAngle = obj->unkB8;
            obj->unkA6 = 1;
            obj->unkA8 = Get_AngleToPlayer(gCurrentParsedObject);
            obj->unkA8 = Math_WrapAngle(obj->unkA8, Math_Random(-0xF));
            obj->unkAA = func_8002A640(gCurrentParsedObject, 10.0f);
        }
    }
    if (obj->unkA6 != 0) {
        obj->moveAngle = Math_WrapAngle(obj->moveAngle, (obj->unkAA * 0xA));
        obj->Rot.y = obj->moveAngle;
        sp40 = obj->moveAngle - obj->unkA8;
        if ((sp40 < 0xB) && (sp40 >= -0xA)) {
            obj->unkA6 = 0;
        } else if (obj->unkAA == 0) {
            obj->unkA6 = 0;
        }
    } else {
        if (obj->unk44 < 12.0f) {
            obj->unk44 = obj->unk44 + 0.25;
        }
        obj->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (obj->unkA6 == 0) {
            if (func_80029018(gCurrentParsedObject, 1U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
                obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
                if (obj->unkB6 == 0) {
                    obj->unkB6 = 5;
                    obj->unkB8 = obj->moveAngle;
                    obj->unk44 = 8.0f;
                    func_80029824(gCurrentParsedObject, func_800297DC());
                } else {
                    obj->unkB6 = 1;
                }
            }
            if (func_800295C0(gCurrentParsedObject, &sp48, &sp44, 0.0f, 0.0f, 0.0f) != 0) {
                obj->Pos.y = sp44;
            } else {
                obj->Pos.y = sp48;
            }
        }
    }
}

void func_800D7CD0(void) {
    struct ObjectStruct* sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkA6 = 0x1E;
        sp24->unk44 = 5.0f;
        sp24->moveAngle = Math_WrapAngle(sp24->unk128, 180.0f);
        func_80029EF8(gCurrentParsedObject, 14.378698f, 1.06089f);
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->damageState = 0;
    }
    sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, 25.0f);
    sp20 = sp24->Vel.y;
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    sp24->Vel.y = sp20;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        sp24->unkA6 = 0;
    }
    if (sp24->unkA6 == 0) {
        func_8002B0E4(gCurrentParsedObject);
    } else {
        sp24->unkA6 -= 1;
    }
}

void func_800D7F08(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800D7704();
            break;
        case 2:
            func_800D7CD0();
            break;
        default:
            break;
    }
}

void Init_ObjTrainingRobo(void) {
    func_80027464(1, &D_80114240, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800D8014(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 2;
    }
}

void func_800D808C(void) {
    struct ObjectStruct* obj;
    f32 sp48;
    f32 sp44;
    s32 sp40;

    obj = &gObjects[gCurrentParsedObject];
//    DEBUG_PRINTF("unk132: %d!\n", obj->unk132);

    // Initialize the object
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = obj->unkA8 = obj->unkB6 = 0;
        obj->unk44 = 0.0f;
        obj->moveAngle = (f32) Math_Random(0x168);
        obj->Rot.y = obj->moveAngle;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801188DC + 0x1C / 4);
    }

    if ((obj->unkB6 == 0) && (obj->unkA6 == 0) && (func_80028FA0(gCurrentParsedObject))) {
        obj->unkB6 = 5;
        obj->unkB8 = (s16) (s32) obj->moveAngle;
        obj->unk44 = 6.0f;
        func_80029B60(gCurrentParsedObject);
    }
    if (obj->unkB6 != 0) {
        obj->unkB6 -= 1;
        if (obj->unkB6 == 0) {
            obj->unk44 = obj->Vel.x = obj->Vel.z = 0.0f;
            obj->moveAngle = (f32) obj->unkB8;
            obj->unkA6 = 1;
            obj->unkA8 = (s16) (s32) Get_AngleToPlayer(gCurrentParsedObject);
            obj->unkA8 = (s16) (s32) Math_WrapAngle((f32) obj->unkA8, (f32) Math_Random(-15));
            obj->unkAA = func_8002A640(gCurrentParsedObject, 10.0f);
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801188DC);
        }
    }
    if (obj->unkA6 != 0) {
        obj->moveAngle = Math_WrapAngle(obj->moveAngle, (f32) (obj->unkAA * 0xA));
        obj->Rot.y = obj->moveAngle;
        sp40 = (s32) (obj->moveAngle - (f32) obj->unkA8);
        if ((sp40 < 0xB) && (sp40 >= -0xA)) {
            obj->unkA6 = 0;
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801188DC + 0x1C / 4);
        } else if (obj->unkAA == 0) {
            obj->unkA6 = 0;
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801188DC + 0x1C / 4);
        }
    } else {
        if (obj->unk44 < 8.0f) {
            obj->unk44 = (f32) ((f64) obj->unk44 + 0.25);
        }
        obj->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (obj->unkA6 == 0) {
            if (func_80029018(gCurrentParsedObject, 4U, 60.0f, 0.0f, -30.0f, 0.0f) != 0) {
                obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
                if (obj->unkB6 == 0) {
                    obj->unkB6 = 5;
                    obj->unkB8 = (s16) (s32) obj->moveAngle;
                    obj->unk44 = 6.0f;
                    func_80029824(gCurrentParsedObject, func_800297DC());
                } else {
                    obj->unkB6 = 1;
                }
            }
            if (func_800295C0(gCurrentParsedObject, &sp48, &sp44, 0.0f, -30.0f, 0.0f) != 0) {
                obj->Pos.y = sp44;
            } else {
                obj->Pos.y = sp48;
            }
            obj->Pos.y += 30.0f;
        }
    }
}

void func_800D86E4(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800D8714(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800D808C();
            break;
        case 2:
            func_800D86E4();
            break;
        default:
            break;
    }
}

void func_800D87A8(void) {
    func_80027464(1, &D_80114258, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800D8820(void) {
    if ((D_80177A64 == 0) && (gObjects[gCurrentParsedObject].actionState == 1)) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 2;
        gObjects[gCurrentParsedObject].damageState = 0;
    }
}

void func_800D88F4(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
    }
}

void func_800D8958(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x172, &D_80118A60);
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800D8A30(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800D88F4();
            break;
        case 2:
            func_800D8958();
            break;
        default:
            break;
    }
}
