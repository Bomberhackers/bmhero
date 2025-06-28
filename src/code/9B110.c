#include "common.h"
#include "9B110.h"

void func_800AE8A4(struct ObjectStruct* arg0, s32 arg1);

void func_800A8BF0(void) {
    s16 sp26;

    sp26 = func_80027464(1, &D_80113928, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].unkA4 = 2;
        gObjects[sp26].unkA8 = 0;
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32) sp26, 0, 0, 0x81, &D_801175D0);
    }
}

void func_800A8D0C(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 5;
    } else if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].unkA4 = 6;
    } else {
        gObjects[gCurrentParsedObject].unkA4 = 7;
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800A8DF8(void) {
    struct ObjectStruct* sp44;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = 1;
        sp44->unk3C = (Math_Random(-0x5A) + (sp44->unk3C + 180.0f)) > 180.0f
                          ? ((Math_Random(-0x5A) + (sp44->unk3C + 180.0f)) >= 360.0f
                                 ? ((f32) Math_Random(-0x5A) + (sp44->unk3C + 180.0f)) - 360.0f
                                 : ((f32) Math_Random(-0x5A) + (sp44->unk3C + 180.0f)))
                      : ((Math_Random(-0x5A) + (sp44->unk3C + 180.0f)) < 0.0f)
                          ? Math_Random(-0x5A) + (360.0f + sp44->unk3C + 180.0f)
                          : Math_Random(-0x5A) + (sp44->unk3C + 180.0f);
        ;
        sp44->unk3C = sp44->unk3C > 180.0f ? (sp44->unk3C >= 360.0f ? sp44->unk3C - 360.0f : sp44->unk3C)
                                           : (sp44->unk3C < 0.0f ? sp44->unk3C + 360.0f : sp44->unk3C);

        sp44->unk44 = 6.0f;
        sp44->unk48 = 0.0f;
        sp44->unkA6 = 0x12C;
        if (sp44->unkA8 == 0) {
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0x81, &D_801175D0);
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp44->unkA6 -= 6;
    sp44->Rot.y = sp44->unk3C;
    if (sp44->unkA6 < 0) {
        sp44->unkA4 = 1;
        sp44->unk132 = 0;
    }
    if (func_8002A1FC(gCurrentParsedObject, 600.0f) != 0) {
        sp44->unkA4 = 9;
        sp44->unk132 = 0;
    }
}

void func_800A9260(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
        if (sp24->unkA8 == 0) {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0x81, &D_801175D0);
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->Rot.y = sp24->unk3C;
    sp24->unkA6 += 1;
    if (sp24->unkA6 == 0x14) {
        sp24->unkA4 = 8;
        if (sp24->unkA8 == 2) {
            sp24->unkA4 = 3;
        }
        sp24->unk132 = 0;
    }
    if (func_8002A1FC(gCurrentParsedObject, 600.0f) != 0) {
        sp24->unkA4 = 9;
        sp24->unk132 = 0;
    }
}

void func_800A9424(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk40 = 90.0f;
        if (sp24->unkA8 == 0) {
            sp24->unkA8 = 1;
            func_8001C0EC(gCurrentParsedObject, 0, 2, 0x81, &D_801175D0);
        }
    }
    if ((sp24->unk132 != 3) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        if (sp24->unkA8 == 1) {
            sp24->unkA8 = 2;
            sp24->unk48 = 2.0f;
            sp24->unk132 = 2;
            func_8001C0EC(gCurrentParsedObject, 0, 5, 0x81, &D_801175D0);
        } else {
            sp24->unk48 = 0.0f;
            sp24->unk132 = 3;
            func_8001C0EC(gCurrentParsedObject, 0, 6, 0x81, &D_801175D0);
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->Rot.y = sp24->unk3C;
    if ((sp24->unk132 == 3) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800A966C(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0x2D;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->unkA6 -= 1;
    if (sp2C->unkA6 <= 0) {
        sp2C->unkA4 = 8;
        sp2C->unk132 = 0;
    }
    if (func_8002A560(gCurrentParsedObject, 15.0f) == 0) {
        if (func_8002A1FC(gCurrentParsedObject, 720.0f) != 0) {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
        if (sp2C->unkA8 == 2) {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
    }
}

void func_800A98A0(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 12.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0x294;
        if (sp2C->unkA8 == 0) {
            func_8001C0EC(gCurrentParsedObject, 0, 3, 0x81, &D_801175D0);
        }
    }
    func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_8002A1FC(gCurrentParsedObject, 240.0f) != 0) {
        if (sp2C->unkA8 == 2) {
            sp2C->unkA4 = 4;
            sp2C->unk132 = 0;
        } else {
            sp2C->unkA4 = 9;
            sp2C->unk132 = 0;
        }
    }
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->unkA6 -= 0xC;
    if (sp2C->unkA6 < 0) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
    }
}

void func_800A9AEC(void) {
    struct ObjectStruct* sp2C;
    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011763C);
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp2C->unkA6 += 1;
    if (sp2C->unkA6 & 1) {
        sp2C->Rot.z += 4.0f;
        func_800175F0(gCurrentParsedObject, 0, 0x17, -1, 0);
    } else {
        sp2C->Rot.z -= 4.0f;
    }
    if (sp2C->unkA6 >= 7) {
        if ((f64) sp2C->Scale.x <= 2.0) {
            sp2C->Scale.y = sp2C->Scale.z = sp2C->Scale.x += 0.1;
        } else {
            sp2C->unkA4 = 5;
            sp2C->unk132 = 0;
            return;
        }
    }
    if (sp2C->unkA6 >= 0xD) {
        sp2C->unkA6 = 0;
        sp2C->Rot.z = 0.0f;
    }
}

void func_800A9D74(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = 0;
        sp24->unkA6 = 0x1E;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_8011763C);
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkA6 & 1) {
        sp24->Rot.z += 4.0f;
    } else {
        sp24->Rot.z -= 4.0f;
    }
    sp24->unkA6 -= 1;
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (sp24->unkA6 <= 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 3.0f);
        func_8002B114(gCurrentParsedObject);
    }
}

void func_800A9F94(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = 0x28;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8001BB34(gCurrentParsedObject, !(sp24->unk108 & 1));
    if (sp24->unk108 == 1) {
        sp24->unkA4 = 4;
        sp24->unk132 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

void func_800AA0BC(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unk108 = 0;
        sp1C->unkB2 = 0x1E;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkB2 -= 1;
    if (sp1C->unkB2 <= 0) {
        sp1C->unkA4 = 4;
        sp1C->unk132 = 0;
        sp1C->unk108 = 1;
    }
}

// RODATA
void func_800AA1D8(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].unkA4;
    switch (sp1C) {
        case 1:
            func_800A9260();
            break;
        case 2:
            func_800A966C();
            break;
        case 3:
            func_800A98A0();
            break;
        case 4:
            func_800A9AEC();
            break;
        case 5:
            func_800A9D74();
            break;
        case 6:
            func_800A9F94();
            break;
        case 7:
            func_800AA0BC();
            break;
        case 8:
            func_800A8DF8();
            break;
        case 9:
            func_800A9424();
            break;
        default:
            break;
    }
}

void func_800AA2F4(void) {
    s16 sp26;

    sp26 = func_80027464(1, &D_80113934, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].unkA4 = 8;
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32) sp26, 0, 0, 0x81, &D_801175D0);
        func_8001ABF4((s32) sp26, 0, 0, &D_80117620);
    }
}

void func_800AA404(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 5;
    } else {
        if (D_80177A64 == 1) {
            gObjects[gCurrentParsedObject].unkA4 = 6;
        } else {
            return;
        }
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800AA4CC(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk3C = func_80015538(sp2C->unk3C, 180.0f);
        sp2C->unk3C = func_80015538(sp2C->unk3C, (f32) Math_Random(-0x5A));
        sp2C->unk44 = 6.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0x78;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x81, &D_801175D0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        sp2C->unkA4 = 9;
        sp2C->unk132 = 0;
    }
    sp2C->unkA6 = (s16) (s32) ((f32) sp2C->unkA6 - sp2C->unk44);
    sp2C->Rot.y = sp2C->unk3C;
    if (sp2C->unkA6 <= 0) {
        sp2C->unkA4 = 1;
        sp2C->unk132 = 0;
    }
}

void func_800AA758(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->Rot.y = sp24->unk3C;
    sp24->unkA6 += 1;
    if (sp24->unkA6 >= 0x28) {
        sp24->unkA4 = 8;
        sp24->unk132 = 0;
    }
}

void func_800AA8B4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
        if (sp24->unkA8 == 0) {
            sp24->unkA8 = 1;
            func_8001C0EC(gCurrentParsedObject, 0, 2, 0x81, &D_801175D0);
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
        }
    }
    if ((sp24->unk132 == 1) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x81, &D_801175D0);
        sp24->unk132 = 2;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->Rot.y = sp24->unk3C;
    if ((sp24->unk132 == 2) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800AAAA0(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->unkA6 += 1;
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (sp2C->unkA6 >= 0x28) {
        sp2C->unkA4 = 1;
        sp2C->unk132 = 0;
    }
    if (func_8002A560(gCurrentParsedObject, 15.0f) == 0) {
        sp2C->unkA4 = 3;
        sp2C->unk132 = 0;
    }
}

void func_800AAC90(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 10.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0x21C;
        sp2C->unkB2 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x81, &D_801175D0);
    }
    if (!(sp2C->unkB2 & 0x3F)) {
        func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    }
    sp2C->unkB2 += 1;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_8002A1FC(gCurrentParsedObject, 240.0f) != 0) {
        sp2C->unkA4 = 4;
        sp2C->unk132 = 0;
    }
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->unkA6 = (s16) (s32) ((f32) sp2C->unkA6 - sp2C->unk44);
    if (sp2C->unkA6 <= 0) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
    }
}

void func_800AAF08(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011763C);
        func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp2C->Scale.x <= 2.0f) {
        sp2C->Scale.y = sp2C->Scale.z = sp2C->Scale.x += 0.1f;
        func_800175F0(gCurrentParsedObject, 1, 0x17, -1, 0);
    } else {
        sp2C->unkA4 = 5;
        sp2C->unk132 = 0;
    }
}

void func_800AB0CC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkB2 = 0x2D;
        sp24->unk108 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011763C);
        func_8001BBDC(gCurrentParsedObject, 0);
        func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkB2 & 1) {
        sp24->Rot.z += 4.0f;
    } else {
        sp24->Rot.z -= 4.0f;
    }
    sp24->unkB2 -= 1;
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (sp24->unkB2 <= 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 3.0f);
        func_8002B114(gCurrentParsedObject);
    }
}

void func_800AB308(void) {
    struct ObjectStruct* sp24;
    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = 0x3C;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8001BB34(gCurrentParsedObject, !(sp24->unk108 & 1));
    if (sp24->unk108 == 1) {
        sp24->unkA4 = 4;
        sp24->unk132 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}

void func_800AB450(void) {
}

// RODATA
void func_800AB460(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].unkA4;
    switch (sp1C) {
        case 1:
            func_800AA758();
            break;
        case 8:
            func_800AA4CC();
            break;
        case 2:
            func_800AAAA0();
            break;
        case 3:
            func_800AAC90();
            break;
        case 4:
            func_800AAF08();
            break;
        case 9:
            func_800AA8B4();
            break;
        case 6:
            func_800AB308();
            break;
        default:
            func_800AB0CC();
            break;
    }
}

void func_800AB564(void) {
    s16 sp26;

    sp26 = func_80027464(1, &D_80113940, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].unkA4 = 1;
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32) sp26, 0, 0, 0x81, &D_801175D0);
    }
}

void func_800AB65C(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 5;
    } else if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].unkA4 = 6;
    } else {
        gObjects[gCurrentParsedObject].unkA4 = 7;
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800AB748(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        if (sp24->unkAA == 1) {
            sp24->unkAA = 2;
            func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
        }
    }
    if ((sp24->unkAA == 2) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp24->unkAA = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x81, &D_801175D0);
    }
    sp24->unkA6 += 1;
    if (sp24->unkA6 == 0x78) {
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
    }
    if ((sp24->unkA6 >= 0x78)) {
        if (((f64) sp24->Scale.x >= 1.0)) {
            sp24->Scale.x = sp24->Scale.x - 0.1;
            sp24->Scale.y = sp24->Scale.y - 0.1;
            sp24->Scale.z = sp24->Scale.z - 0.1;
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp24->Rot.y = sp24->unk3C;
    }
    if (func_8002A1FC(gCurrentParsedObject, 540.0f) != 0) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800ABA38(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
    }
    func_8002A8B4(gCurrentParsedObject, 8.0f);
    sp2C->Rot.y = sp2C->unk3C;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp2C->Rot.y = sp2C->unk3C;
    }
    if (func_8002A560(gCurrentParsedObject, 15.0f) == 0) {
        if (func_8002A1FC(gCurrentParsedObject, 540.0f) != 0) {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
        if (sp2C->unkA8 == 3) {
            sp2C->unkA4 = 4;
            sp2C->unk132 = 0;
        }
    } else if (func_8002A1FC(gCurrentParsedObject, 540.0f) == 0) {
        sp2C->unkA4 = 1;
        sp2C->unk132 = 0;
    }
}

void func_800ABC88(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA8 = 3;
    }
    func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    if (sp2C->unkAA != 1) {
        if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
            sp2C->unkAA = 1;
            func_8001C0EC(gCurrentParsedObject, 0, 2, 0x81, &D_801175D0);
        }
    } else if ((sp2C->unk132 == 1) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp2C->unk132 = 2;
        sp2C->unk44 = 4.0f;
        sp2C->unkA6 = 0x1E0;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x81, &D_801175D0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (sp2C->unk132 == 2) {
        sp2C->unkA6 -= 4;
        sp2C->Rot.y = sp2C->unk3C;
    }
    if (sp2C->unkA6 < 0) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
    }
}

void func_800ABF34(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA8 = 4;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011763C);
    }
    func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    func_8002A8B4(gCurrentParsedObject, 8.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->unkA4 = 2;
        sp24->unkAA = 0;
        sp24->unk132 = 0;
    } else if (func_8001B62C(gCurrentParsedObject, 0) > 60.0f) {
        if ((f64) sp24->Scale.x <= 3.0) {
            sp24->Scale.x = (f32) ((f64) sp24->Scale.x + 0.05);
            sp24->Scale.y = (f32) ((f64) sp24->Scale.y + 0.05);
            sp24->Scale.z = (f32) ((f64) sp24->Scale.z + 0.05);
            func_800175F0(gCurrentParsedObject, 1, 0x17, -1, 0);
        } else {
            sp24->unkA4 = 5;
            sp24->unk132 = 0;
        }
    }
}

void func_800AC194(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0x2D;
        sp24->unk108 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011763C);
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    func_8002A8B4(gCurrentParsedObject, 8.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkA6 & 1) {
        sp24->Rot.z += 4.0f;
    } else {
        sp24->Rot.z -= 4.0f;
    }
    sp24->unkA6 -= 1;
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (sp24->unkA6 <= 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 3.0f);
        func_8002B114(gCurrentParsedObject);
    }
}

void func_800AC3D0(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk108 = 0x28;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
    }
    func_8001BB34(gCurrentParsedObject, !(sp2C->unk108 & 1));
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((func_8001B44C(gCurrentParsedObject, 0) != 0) && (sp2C->unk132 != 2)) {
        sp2C->unk132 = 2;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x81, &D_801175D0);
    }
    if (sp2C->unk108 == 1) {
        sp2C->unkA4 = 4;
        sp2C->unk132 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

void func_800AC57C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkB2 = 0x1E;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkB2 -= 1;
    if (sp1C->unkB2 <= 0) {
        sp1C->unkA4 = 4;
        sp1C->unk132 = 0;
    }
}

// RODATA
void func_800AC680(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].unkA4;
    switch (sp1C) {
        case 1:
            func_800AB748();
            break;
        case 2:
            func_800ABA38();
            break;
        case 3:
            func_800ABC88();
            break;
        case 4:
            func_800ABF34();
            break;
        case 5:
            func_800AC194();
            break;
        case 6:
            func_800AC3D0();
            break;
        case 7:
            func_800AC57C();
            break;
        default:
            break;
    }
}

void func_800AC77C(void) {
    s16 sp2E;

    sp2E = func_80027464(1, &D_8011394C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].Scale.x = 1.5f;
        gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.x;
        gObjects[sp2E].unkA4 = 3;
        gObjects[sp2E].unkAC = 0;
        gObjects[sp2E].unkA8 = 0;
        gObjects[sp2E].unk132 = 0;
        func_8001C0EC((s32) sp2E, 0, 1, 0x91, &D_80117658);
    }
}

void func_800AC948(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 4;
    } else {
        if (D_80177A64 == 1) {
            gObjects[gCurrentParsedObject].unkA4 = 5;
        } else {
            return;
        }
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800ACA10(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        if (sp24->unkAC == 0) {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0x91, &D_80117658);
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800ACB2C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unkA6 = 0x78;
        sp24->unk44 = 3.0f;
        if (sp24->unkAC == 0) {
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0x91, &D_80117658);
        }
    }
    sp24->unkA8 = (s16) (s32) func_80015538((f32) sp24->unkA8, 5.0f);
    sp24->unkD8 = sinf((f32) ((f64) sp24->unkA8 * DEG_TO_RAD)) * 32.0f;
    sp24->unk3C = func_80015538(sp24->unkD4, sp24->unkD8);
    sp24->Rot.y = sp24->unk3C;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
        sp24->unkD8 = sp24->unkD4;
        return;
    }
    sp24->unkA6 = (s16) (s32) ((f32) sp24->unkA6 - sp24->unk44);
    if ((sp24->unkA6 <= 0) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
    }
}

void func_800ACDCC(void) {
    struct ObjectStruct* sp1C;
    union {
        s16 sp18;
    } fake;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 0;
        sp1C->unkAE = func_8002A560(gCurrentParsedObject, 2.0f) * 5;
        sp1C->unkD4 = func_8002A46C(gCurrentParsedObject);
        if (sp1C->unkD4 == sp1C->unkD8) {
            sp1C->unkA4 = 1;
            sp1C->unk132 = 0;
            sp1C->unkAC = 1;
            return;
        }
        sp1C->unkAC = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (((s16) sp1C->unkA6 % 2)) {
        fake.sp18 = func_800BFFCC(sp1C, 0, sp1C->unkD4, (f32) sp1C->unkAE);
        if (fake.sp18 == 0) {
            sp1C->unk132 = 2;
        }
    } else {
        sp1C->unk3C = func_80015538(sp1C->unk3C, (f32) - ((s16) sp1C->unkAE / 2));
    }
    sp1C->Rot.y = sp1C->unk3C;
    sp1C->unkA6 += 1;
    if (sp1C->unk132 == 2) {
        sp1C->unkA4 = 1;
        sp1C->unk132 = 0;
    }
}

void func_800AD034(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 3.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 0x28;
        sp1C->unk108 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unk3C = func_80015538(sp1C->unk3C, 16.0f);
    sp1C->Rot.y = func_80015538(sp1C->Rot.y, -16.0f);
    sp1C->unk44 -= 0.1f;
    if (sp1C->Scale.y > 0.1f) {
        sp1C->Scale.y -= 0.045f;
    } else {
        sp1C->unkA6 = 0;
    }
    sp1C->unkA6 -= 1;
    if (sp1C->unkA6 <= 0) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_800AD21C(void) {
    struct ObjectStruct* sp2C;
    s16 sp2A;
    sp2C = &gObjects[gCurrentParsedObject];
    sp2A = sp2C->unkE8[0];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk108 = 0x28;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8001BB34(gCurrentParsedObject, !(sp2C->unk108 & 1));
    if (sp2C->unk108 == 1) {
        sp2C->unk108 = 1;
        sp2C->unkA4 = 3;
        sp2C->unk132 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

void func_800AD364(void) {
}

// RODATA
void func_800AD374(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].unkA4;
    switch (sp1C) {
        case 1:
            func_800ACA10();
            break;
        case 2:
            func_800ACB2C();
            break;
        case 3:
            func_800ACDCC();
            break;
        case 4:
            func_800AD034();
            break;
        case 5:
            func_800AD21C();
            break;
        default:
            func_800AD034();
            break;
    }
}

void func_800AD458(void) {
    s16 sp26;
    s16 sp24;
    s16 temp_t5;

    sp26 = func_80027464(1, &D_80113958, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].unkA4 = 1;
        gObjects[sp26].unkA4 = 9;
        gObjects[sp26].unkA8 = 0;
        if (D_80165100->unkA != 0) {
            gObjects[sp26].unkA4 = 8;
            if ((sp24 = D_80165100->unk8) == 2) {
                sp24 = 0;
            }
            sp24 %= 4;
            gObjects[sp26].unkA8 = sp24;
        }
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32) sp26, 0, 0, 0x99, &D_80117874);
    }
}

void func_800AD648(void) {
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        return;
    }
    func_8002B0E4(gCurrentParsedObject);
}

void func_800AD6A0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 6.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0x258;
        sp24->unk3C = (f32) (sp24->unkA8 * 0x5A);
    }
    sp24->Rot.y = sp24->unk3C;
    func_80029C40(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
        sp24->unkA6 = 0;
    }
    if (func_80029018(gCurrentParsedObject, 0U, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->unkA6 = 0;
    }
    sp24->unkA6 = (s16) (s32) ((f32) sp24->unkA6 - sp24->unk44);
    if (sp24->unkA6 < 0) {
        sp24->unkA8 = (s16) ((s32) (sp24->unkA8 + 2) % 4);
        sp24->unkA4 = 8;
        sp24->unk132 = 0;
    }
}

void func_800AD8CC(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 6.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0x258;
        sp2C->unkA8 = func_8002A560(gCurrentParsedObject, 8.0f) * 8;
        sp2C->unkD4 = func_8002A46C(gCurrentParsedObject);
    }
    if ((sp2C->unk132 == 1)) {
        if ((!func_800BFFCC(sp2C, 0, sp2C->unkD4, (f32) sp2C->unkA8))) {
            sp2C->unk132 = 2;
        }
    }
    sp2C->Rot.y = sp2C->unk3C;
    func_80029C40(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_80029018(gCurrentParsedObject, 0U, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp2C->unkA6 = 0;
    }
    sp2C->unkA6 = (s16) (s32) ((f32) sp2C->unkA6 - sp2C->unk44);
    if (sp2C->unkA6 < 0) {
        sp2C->unkA4 = 9;
        sp2C->unk132 = 0;
    }
}

void func_800ADB1C(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800ADB4C(void) {
    s32 sp24;

    sp24 = gObjects[gCurrentParsedObject].unkA4;
    switch (sp24) { /* irregular */
        case 8:
            func_800AD6A0();
            break;
        case 9:
            func_800AD8CC();
            break;
        default:
            func_800ADB1C();
            break;
    }
}

void func_800ADBF4(void) {
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;

    sp36 = func_80027464(4, &D_80113964, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp36 != -1) {
        sp34 = gObjects[sp36].unkE8[0];
        sp32 = gObjects[sp36].unkE8[1];
        sp30 = gObjects[sp36].unkE8[2];
        gObjects[sp34].unkB4 = 0;
        gObjects[sp32].unkB4 = 1;
        gObjects[sp30].unkB4 = 2;
        gObjects[sp34].unkA4 = gObjects[sp32].unkA4 = gObjects[sp30].unkA4 = 1;
        gObjects[sp34].unk132 = gObjects[sp32].unk132 = gObjects[sp30].unk132 = 0;
        func_80019448((s32) sp36, 2, 0, 1);
        func_80019448((s32) sp34, 2, 0, 1);
        func_80019448((s32) sp32, 2, 0, 1);
        func_80019448((s32) sp30, 2, 0, 1);
        func_8001C0EC((s32) sp36, 0, 0, 0x9A, &D_80117810);
        func_8001C0EC((s32) sp34, 0, 0, 0x9B, &D_80117810);
        func_8001C0EC((s32) sp32, 0, 0, 0x9B, &D_80117810);
        func_8001C0EC((s32) sp30, 0, 0, 0x9B, &D_80117810);
        func_8001ABF4((s32) sp36, 0, 0, &D_8011783C);
        func_8001ABF4((s32) sp34, 0, 0, &D_8011783C);
        func_8001ABF4((s32) sp32, 0, 0, &D_8011783C);
        func_8001ABF4((s32) sp30, 0, 0, &D_8011783C);
        func_8001BB04((s32) sp34, 1);
        func_8001BB04((s32) sp32, 1);
        func_8001BB04((s32) sp30, 1);
        gObjects[sp36].unkA4 = 1;
        gObjects[sp36].unk132 = 0;
        gObjects[sp36].unk3C = 0.0f;
        gObjects[sp34].unkB0 = 0;
        gObjects[sp32].unkB0 = 0;
        gObjects[sp30].unkB0 = 0;
        if (D_80165100->unkA != 0) {
            gObjects[sp34].unkB0 = 1;
            gObjects[sp32].unkB0 = 1;
            gObjects[sp30].unkB0 = 1;
        }
        gObjects[sp36].unk108 = -1;
        gObjects[sp34].unk108 = -1;
        gObjects[sp32].unk108 = -1;
        gObjects[sp30].unk108 = -1;
    }
}

void func_800AE210(void) {
    if (D_80177A64 != 0) {
        return;
    }
    gObjects[gCurrentParsedObject].unkA4 = 4;
    gObjects[gCurrentParsedObject].unk108 = 0;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800AE2B8(void) {
    struct ObjectStruct* sp1C;
    s16 sp1A;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        sp1C->unkA6 += 1;
        if (sp1C->unkA6 >= 0x14) {
            sp1C->unkA4 = 2;
            sp1C->unk132 = 0;
        }
        if (sp1C->unk132 == 1) {
            sp1C->unk132 = 2;
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117858);
            if ((sp1A = sp1C->unkE8[0]) != -1) {
                func_8001ABF4((s32) sp1A, 0, 0, &D_80117858);
            }
            if ((sp1A = sp1C->unkE8[1]) != -1) {
                func_8001ABF4((s32) sp1A, 0, 0, &D_80117858);
            }
            if ((sp1A = sp1C->unkE8[2]) != -1) {
                func_8001ABF4((s32) sp1A, 0, 0, &D_80117858);
            }
        }
    }
}

void func_800AE4A8(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 0.0f;
        sp34->unk48 = 0.0f;
        sp34->unk108 = 0;
        sp34->Rot.x = 0.0f;
        sp34->Rot.z = 0.0f;
        sp34->unkAA = 0;
        sp30 = func_8002A46C(gCurrentParsedObject);
        sp34->unkA8 = (s16) (s32) (func_80015538(sp30, 60.0f) / 90.0f);
        sp34->unk3C = (f32) (sp34->unkA8 * 0x5A);
        func_80019448(gCurrentParsedObject, 2, 0, 1);
    }
    switch (sp34->unkA8) { /* irregular */
        case 3:
            sp34->Rot.z = func_80015538(sp34->Rot.z, 5.0f);
            if (sp34->Rot.z > 90.0f) {
                sp34->unk132 = 2;
            }
            sp34->unkAA = 2;
            break;
        case 1:
            sp34->Rot.z = func_80015538(sp34->Rot.z, -5.0f);
            if (sp34->Rot.z < 270.0f) {
                sp34->unk132 = 2;
            }
            sp34->unkAA = 2;
            break;
        case 2:
            sp34->Rot.x = func_80015538(sp34->Rot.x, -5.0f);
            if (sp34->Rot.x < 270.0f) {
                sp34->unk132 = 2;
            }
            sp34->unkAA = 1;
            break;
        default:
            sp34->Rot.x = func_80015538(sp34->Rot.x, 5.0f);
            if (sp34->Rot.x > 90.0f) {
                sp34->unk132 = 2;
            }
            sp34->unkAA = 1;
            break;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp34->unk132 == 2) {
        func_800AE8A4(sp34, 0);
        func_800AE8A4(sp34, 1);
        func_800AE8A4(sp34, 2);
        func_800175F0(gCurrentParsedObject, 0, 0x34, -1, 0);
        sp34->unkA4 = 4;
        sp34->unk132 = 0;
    }
}

void func_800AE894(void) {
}

void func_800AE8A4(struct ObjectStruct* arg0, s32 arg1) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp22 = arg0->unkE8[(s16) arg1];
    sp24 = &gObjects[sp22];
    if (sp22 != -1) {
        sp24->unk108 = 0;
        sp24->unkA4 = 1;
        sp24->unkA6 = Math_Random(8) + 0xC;
        sp24->unk132 = 0;
        func_8001BB04((s32) sp22, 0);
        func_80019448((s32) sp22, 2, 0, 1);
        func_800281A4(gCurrentParsedObject, (s32) (s16) arg1);
        func_800175F0((s32) sp22, 0, 0x34, -1, 0);
    }
}

void func_800AE9A4(void) {
    struct ObjectStruct* sp1C;
    s16 sp1A;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkB2 = 6;
        sp1C->unk108 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkB2 -= 1;
    if (sp1C->unkB2 <= 0) {
        sp1A = sp1C->unkE8[0];
        if (sp1A != -1) {
            func_800281A4(gCurrentParsedObject, 0);
            func_8002B0E4((s32) sp1A);
        }
        sp1A = sp1C->unkE8[1];
        if (sp1A != -1) {
            func_800281A4(gCurrentParsedObject, 1);
            func_8002B0E4((s32) sp1A);
        }
        sp1A = sp1C->unkE8[2];
        if (sp1A != -1) {
            func_800281A4(gCurrentParsedObject, 2);
            func_8002B0E4((s32) sp1A);
        }
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800AEB7C(void) {
}

void func_800AEB8C(void) {
}

void func_800AEB9C(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].unkA4;
    switch (sp1C) {
        case 1:
            func_800AE2B8();
            break;
        case 2:
            func_800AE4A8();
            break;
        case 4:
            func_800AE9A4();
            break;
        case 5:
            func_800AEB7C();
            break;
        case 6:
            func_800AEB8C();
            break;
        case 8:
            func_800AE894();
            break;
        default:
            break;
    }
}

void func_800AEB9C_1(void) {
}

void func_800AEC98(void) {
}

void func_800AECA8(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 2.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk108 = -1;
        func_80029EF8(gCurrentParsedObject, 0.0f, 9.0f);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -40.0f, 80.0f) == 1) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
        if (D_80177740[D_801776E0 & 1] == 0xF5) {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
    }
}

void func_800AEE6C(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk3C = func_80015538((f32) Math_Random(0x166), 1.0f);
        sp2C->unk44 = (f32) Math_Random(4);
        sp2C->unk48 = 0.0f;
        func_80029EF8(gCurrentParsedObject, (f32) sp2C->unkA6, 1.0f);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -40.0f, 80.0f) == 1) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
        sp2C->unkA6 -= Math_Random(6) + 6;
        if (sp2C->unkB0 == 1) {
            sp2C->unkA6 = Math_Random(6) + 0x18;
            if (sp2C->unkA6 >= 0xB4) {
                sp2C->unkA6 = 0xB4;
            }
        } else if (sp2C->unkA6 <= 0) {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
        if (D_80177740[D_801776E0 & 1] == 0xF5) {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
    }
}

void func_800AF118(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800AF148(void) {
    struct ObjectStruct* sp2C;
    struct ObjectStruct* sp28;
    f32 sp24;
    f32 sp20;
    s16 sp1E;

    sp28 = &gObjects[gCurrentParsedObject];
    if (sp28->unkE6[0] != -1) {
        sp2C = &gObjects[sp28->unkE6[0]];
        sp1E = sp28->unkB4 + 1;
        sp24 = (f32) (sp1E * 5);
        sp28->Rot.x = sp2C->Rot.x;
        sp28->Rot.z = sp2C->Rot.z;
        sp28->Rot.y = sp2C->Rot.y;
        sp20 = 0.0f;
        if (sp2C->unkAA == 2) {
            sp20 = sp2C->Rot.z;
            if (sp20 >= 180.0f) {
                sp20 = 90.0f - (sp2C->Rot.z - 270.0f);
            }
            if (sp20 != 0.0f) {
                sp20 = (f32) ((f64) sp20 / 3.2);
            }
            sp28->Rot.x = 0.0f;
        }
        if (sp2C->unkAA == 1) {
            sp20 = sp2C->Rot.x;
            if (sp20 >= 180.0f) {
                sp20 = 90.0f - (sp2C->Rot.x - 270.0f);
            }
            if (sp20 != 0.0f) {
                sp20 = (f32) ((f64) sp20 / 3.5);
            }
            sp28->Rot.z = 0.0f;
        }
        sp24 *= sp20;
        sp28->Pos.x = sp2C->Pos.x + (sinf((f32) ((f64) sp2C->unk3C * DEG_TO_RAD)) * sp24);
        sp28->Pos.z = sp2C->Pos.z + (cosf((f32) ((f64) sp2C->unk3C * DEG_TO_RAD)) * sp24);
        sp28->Pos.y = (sp2C->Pos.y + (f32) (sp1E * 0x78)) - sp24;
        sp28->unk3C = sp2C->unk3C;
        sp28->unk40 = sp2C->unk40;
        sp28->unk48 = (f32) sp1E;
        if (sp28->Pos.y <= 60.0f) {
            sp28->Pos.y = 60.0f;
        }
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
    }
}

// STOP
void func_800AF538(void) {
    struct ObjectStruct* sp2C;
    s16 temp_s0;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unkE6[0] == -1) {
        switch (sp2C->unkA4) { /* irregular */
            case 1:
                func_800AECA8();
                break;
            case 2:
                func_800AEE6C();
                break;
            case 3:
                func_800AF118();
                break;
            default:
                break;
        }
    } else {
        func_800AF148();
    }
}

void func_800AF620(void) {
    s16 sp2E;

    sp2E = func_80027464(1, &D_80113994, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].unkA4 = 1;
        gObjects[sp2E].unk132 = 0;
        gObjects[sp2E].unkA8 = 0xF;
        if (D_80165100->unkA == 1) {
            gObjects[sp2E].unkA8 = 0x14;
        }

        gObjects[sp2E].Scale.x = gObjects[sp2E].unkA8 / 10.0f;
        gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.x;
        func_8001BB04((s32) sp2E, 1);
    }
}

void func_800AF814(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 6;
    } else {
        if (D_80177A64 == 1) {
            gObjects[gCurrentParsedObject].unkA4 = 7;
        } else {
            return;
        }
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800AF8DC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = -1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x9C, &D_80117660);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117700);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117738);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_8011778C);
    }
    if ((func_8002A2EC(gCurrentParsedObject, 600.0f) != 0) && (func_8002A3A8(gCurrentParsedObject, 1500.0f) != 0)) {
        sp24->unkA4 = 9;
        sp24->unk132 = 0;
    }
}

void func_800AFA3C(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 34.0f;
        sp2C->unk40 = 270.0f;
        sp2C->unkA6 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001BB04(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, -360.0f, 0.0f) != 0) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}

void func_800AFB8C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x9C, &D_80117660);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->unkA4 = 4;
        sp24->unk132 = 0;
        sp24->unk108 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x9C, &D_80117660);
    }
}

void func_800AFCC0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
    }
    sp24->unkA6 += 1;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkA6 == 0xA) {
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117754);
    }
    if (sp24->unkA6 == 0x1E) {
        func_800175F0(gCurrentParsedObject, 0, 0x1B, -1, 0);
        func_800B0A78(sp24, gCurrentParsedObject, 0);
    }
    if (sp24->unkA6 == 0x46) {
        func_800175F0(gCurrentParsedObject, 0, 0x1B, -1, 0);
        func_800B0A78(sp24, gCurrentParsedObject, 1);
        sp24->unk132 = 2;
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        if (sp24->unk132 == 2) {
            sp24->unkA4 = 5;
            sp24->unk132 = 0;
        } else {
            sp24->unk132 = 2;
        }
    }
}

void func_800AFEB8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = -1;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x9C, &D_80117660);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117738);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x9C, &D_80117660);
    }
}

void func_800B0008(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkA6 += 1;
    if (sp1C->unkA6 >= 0x78) {
        sp1C->unkA4 = 2;
        sp1C->unk132 = 0;
    }
}

void func_800B0110(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkAA = 4;
        sp24->unk108 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x9C, &D_80117660);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011771C);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117770);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_801177A8);
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_8001BBDC(gCurrentParsedObject, 0);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800B0298(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk132 = 1;
        sp24->unk108 = 0x3C;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    func_8001BB34(gCurrentParsedObject, !(sp24->unk108 & 1));
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unk108 == 1) {
        sp24->unkA4 = 5;
        sp24->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

void func_800B03E0(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkB2 = 0x19;
        sp1C->unk108 = -1;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkB2 -= 1;
    if (sp1C->unkB2 <= 0) {
        sp1C->unkA4 = 5;
        sp1C->unk132 = 0;
        sp1C->unk108 = 1;
    }
}

// RODATA
void func_800B04FC(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].unkA4;
    switch (sp1C) {
        case 1:
            func_800AF8DC();
            break;
        case 9:
            func_800AFA3C();
            break;
        case 2:
            func_800AFB8C();
            break;
        case 3:
            func_800B0008();
            break;
        case 4:
            func_800AFCC0();
            break;
        case 5:
            func_800AFEB8();
            break;
        case 7:
            func_800B0298();
            break;
        case 6:
            func_800B0110();
            break;
        case 8:
            func_800B03E0();
            break;
        default:
            break;
    }
}

void stub_9B110_2() {
}

void func_800B0628(void) {
    gObjects[gCurrentParsedObject].unkA4 = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800B068C(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 6.0f;
        sp2C->unk48 = 6.0f;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x9D, &D_801177C4);
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_801177F4);
        func_800272E8(gCurrentParsedObject);
    }
    func_8002A8B4(gCurrentParsedObject, 20.0f);
    if ((sp2C->unk3C >= 90.0f) && (sp2C->unk3C <= 180.0f)) {
        sp2C->unk3C = 85.0f;
    }
    if ((sp2C->unk3C <= 270.0f) && (sp2C->unk3C > 180.0f)) {
        sp2C->unk3C = 275.0f;
    }
    sp2C->unk40 = (f32) (Math_Random(-0xA) + 0x154);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, -40.0f, 0.0f) != 0) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
    }
    sp2C->unkB2 -= 1;
    if (sp2C->unkB2 <= 0) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
    }
}

void func_800B08FC(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unk108 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8002B0E4(gCurrentParsedObject);
}

void func_800B09C8(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        if (gObjects[gCurrentParsedObject].unkA4 == 1) {
            if (FALSE)
                ;
            func_800B068C();
        } else {
            func_800B08FC();
            if (FALSE)
                ;
        }
    }
}

int func_800B0A78(struct ObjectStruct* arg0, s32 arg1, s32 arg2) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp32 = func_80027464(1, &D_801139A0, arg0->Pos.x, arg0->Pos.y, arg0->Pos.z + 80.0f, arg0->unk3C);
    if (sp32 != -1) {
        func_80026F10((s32) (s16) arg1, (s32) sp32);
        arg0->unk108 = -1;
        sp34 = &gObjects[sp32];
        sp34->unk40 = arg0->unk40;
        sp34->unkA4 = 1;
        sp34->unkB2 = 0x5A;
        sp34->unk132 = 0;
        sp34->unk108 = 1;
        sp34->Scale.x = arg0->unkA8 / 10.0f;
        sp34->Scale.z = sp34->Scale.y = sp34->Scale.x;
        func_8001C0EC((s32) sp32, 3, 0, 0x9D, &D_801177C4);
        func_80029C40((s32) sp32);
        func_80029D04((s32) sp32);
        arg0->unk108 = 1;
    }
    return sp32;
}

void func_800B0C1C(void) {
    s16 sp26;
    s16 sp24;

    sp26 = func_80027464(2, &D_801139AC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].unkA4 = 1;
        gObjects[sp26].unkB4 = D_80165100->unkA;
        gObjects[sp26].unk132 = 0;
        sp24 = gObjects[sp26].unkE8[0];
        gObjects[sp24].unkA4 = 1;
        gObjects[sp24].unk132 = 0;
        gObjects[sp26].unkA8 = 0x6E;
        func_800296AC((s32) sp26, (f32) gObjects[sp26].unkA8, 0, 0);
        gObjects[sp26].unkB0 = (s16) (s32) gObjects[sp26].Pos.y;
        func_80019448((s32) sp24, 2, 0, 1);
        func_8001C0EC((s32) sp26, 0, 0, 0xA2, &D_80117884);
    }
}

void func_800B0E8C(void) {
    struct ObjectStruct* sp1C;
    s16 sp1A;

    sp1C = &gObjects[gCurrentParsedObject];
    func_8001BB34(gCurrentParsedObject, 0);
    sp1A = sp1C->unkE8[0];
    if ((sp1A != -1)) {
        if ((gObjects[sp1A].unk104 != -1)) {
            if (((gObjects[sp1A].unk106 == 0xF)) || (gObjects[sp1A].unk106 == 8)) {
                sp1C->unkA4 = 7;
                sp1C->unk132 = 0;
                gObjects[sp1A].unk108 = 0;
                func_800281A4(gCurrentParsedObject, 0);
                return;
            }
        }
    }
    if (D_80177A64 == 0) {
        sp1C->unkA4 = 4;
    } else if (D_80177A64 == 1) {
        sp1C->unkA4 = 5;
    } else if (sp1A == -1) {
        sp1C->unkA4 = 7;
    } else {
        return;
    }
    sp1C->unk132 = 0;
}

void func_800B1048(void) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp24 = &gObjects[gCurrentParsedObject];
    sp22 = sp24->unkE8[0];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xA2, &D_80117884);
        if (sp22 != -1) {
            gObjects[sp22].unk108 = 1;
        }
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    func_80029C40(gCurrentParsedObject);
    sp24->Rot.y = sp24->unk3C;
    sp24->unkB0 = (s16) (s32) sp24->Pos.y;
    sp24->unkA6 += 1;
    if ((sp24->unkA6 >= 0x14) && (func_8002A1FC(gCurrentParsedObject, 1080.0f) != 0)) {
        sp24->unkA4 = 0xB;
        if (sp22 != -1) {
            sp24->unkA4 = 2;
        }
        sp24->unk132 = 0;
    }
}

void func_800B1248(void) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp34 = &gObjects[gCurrentParsedObject];
    sp32 = sp34->unkE8[0];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 12.0f;
        sp34->unk48 = 0.0f;
        sp34->unkA6 = 0x12C;
        sp34->unkAA = 1;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xA2, &D_80117884);
        func_80029D04(gCurrentParsedObject);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    } else {
        func_800C00F4(sp34, 0.0f);
    }
    sp34->Rot.y = sp34->unk3C;
    if ((sp34->unkB4 == 1)) {
        if (((sp34->Pos.z + sp34->Vel.z) < -960.0f)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp34->Vel.x = 0.0f;
            sp34->Vel.z = 0.0f;
        }
    }
    if ((sp34->unkB4 == 2)) {
        if (((sp34->Pos.z + sp34->Vel.z) > -2400.0f)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp34->Vel.x = 0.0f;
            sp34->Vel.z = 0.0f;
        }
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp34->unkA4 = 7;
        sp34->unk132 = 0;
    }
    sp34->unkA6 = (s16) (s32) ((f32) sp34->unkA6 - sp34->unk44);
    if ((sp34->unkA6 <= 0) && (func_8002A1FC(gCurrentParsedObject, 1080.0f) != 0)) {
        sp34->unkA4 = 7;
        sp34->unk132 = 0;
    }
}

void func_800B15A0(void) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp34 = &gObjects[gCurrentParsedObject];
    sp32 = sp34->unkE8[0];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 0.0f;
        sp34->unk48 = 0.0f;
        sp34->unkA6 = 0x384;
        sp34->unkB2 = 0;
        if (sp32 != -1) {
            gObjects[sp32].unk108 = 1;
        }
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xA2, &D_80117884);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801178D4);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (sp34->unk44 < 8.0f) {
        sp34->unk44 += 0.75f;
    }
    func_80029C40(gCurrentParsedObject);
    sp34->Rot.y = sp34->unk3C;
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    func_800296AC(gCurrentParsedObject, (f32) sp34->unkA8, 0, 0);
    if ((sp34->unkB4 == 1)) {
        if (((sp34->Pos.z + sp34->Vel.z) < -960.0f)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp34->Vel.x = 0.0f;
            sp34->Vel.z = 0.0f;
        }
    }
    if ((sp34->unkB4 == 2)) {
        if (((sp34->Pos.z + sp34->Vel.z) > -2400.0f)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp34->Vel.x = 0.0f;
            sp34->Vel.z = 0.0f;
        }
    }
    sp34->unkB0 = (s16) (s32) sp34->Pos.y;
}

void func_800B1914(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        sp24->unkAA = 1;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xA2, &D_80117884);
        func_800296AC(gCurrentParsedObject, (f32) sp24->unkA8, 0, 0);
        sp24->unkB0 = (s16) (s32) sp24->Pos.y;
    }
    if (sp24->unk44 > 0.0f) {
        sp24->unk44 -= 2.0f;
    }
    sp24->unkA6 += 1;
    if (sp24->unkA6 == 0xF) {
        func_800175F0(gCurrentParsedObject, 0, 0x5B, -1, 0);
        func_800B34AC(sp24, gCurrentParsedObject, 1);
        sp24->unk132 = 2;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((sp24->unk132 == 2) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp24->unkA4 = 6;
        sp24->unkA4 = 1;
        sp24->unk132 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xA2, &D_80117884);
    }
}

void func_800B1B7C(void) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp34 = &gObjects[gCurrentParsedObject];
    sp32 = sp34->unkE8[0];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 0.0f;
        sp34->unk48 = 0.0f;
        sp34->unk108 = 1;
        sp34->unkAA = 3;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, (s32) sp34->unkAA, 0xA2, &D_80117884);
        if (sp32 != -1) {
            gObjects[sp32].unk108 = 1;
        }
        func_800175F0(gCurrentParsedObject, 0, 0x13, -1, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if ((sp34->unkB4 == 1)) {
        if (((sp34->Pos.z + sp34->Vel.z) < -960.0f)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp34->Vel.x = 0.0f;
            sp34->Vel.z = 0.0f;
        }
    }
    if ((sp34->unkB4 == 2)) {
        if (((sp34->Pos.z + sp34->Vel.z) > -2400.0f)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp34->Vel.x = 0.0f;
            sp34->Vel.z = 0.0f;
        }
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp34->unkAA += 1;
        sp34->unkAA += 1;
        if (sp34->unkAA >= 6) {
            sp34->unkA4 = 1;
            sp34->unkAA = 0;
            sp34->unk132 = 0;
        }
        if (sp34->unkAA == 4) {
            sp34->unkAE = (s16) (s32) sp34->Pos.y;
            sp34->Pos.y += 30.0f;
        }
        if (sp34->unkAA == 5) {
            sp34->unkAE = (s16) (s32) sp34->Pos.y;
            sp34->Pos.y = (f32) sp34->unkAE;
        }
        func_8001C0EC(gCurrentParsedObject, 0, (s32) sp34->unkAA, 0xA2, &D_80117884);
    }
}

void func_800B1FA8(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    func_8002A8B4(gCurrentParsedObject, 30.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->unkA4 = 0xB;
        sp2C->unk132 = 1;
        return;
    }
    func_800296AC(gCurrentParsedObject, (f32) sp2C->unkA8, 0, 0);
    if ((sp2C->unkB4 == 1)) {
        if (((sp2C->Pos.z + sp2C->Vel.z) < -960.0f)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp2C->Vel.x = 0.0f;
            sp2C->Vel.z = 0.0f;
        }
    }
    if ((sp2C->unkB4 == 2)) {
        if (((sp2C->Pos.z + sp2C->Vel.z) > -2400.0f)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp2C->Vel.x = 0.0f;
            sp2C->Vel.z = 0.0f;
        }
    }
    sp2C->Rot.y = sp2C->unk3C;
    if (func_8002A560(gCurrentParsedObject, 15.0f) == 0) {
        sp2C->unkA4 = 3;
        sp2C->unkAA = 3;
        sp2C->unk132 = 0;
    }
}

void func_800B2250(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 16.0f;
        sp2C->unk48 = 24.0f;
        sp2C->unk40 = 65.0f;
        sp2C->unkAC = 0;
        sp2C->unk108 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
        func_80019448(gCurrentParsedObject, 2, 0, 1);
        if (sp2C->unkAA == 1) {
            sp2C->unkAA = 4;
            func_8001C0EC(gCurrentParsedObject, 0, (s32) sp2C->unkAA, 0xA2, &D_80117884);
            func_800175F0(gCurrentParsedObject, 0, 0x13, -1, 0);
        }
        func_800296AC(gCurrentParsedObject, (f32) sp2C->unkA8, 0, 0);
        sp2C->unkAE = (s16) (s32) sp2C->Pos.y;
    }
    if ((sp2C->unkAC < 3)) {
        if (sp2C->Pos.y >= ((f32) (sp2C->unkAE + 0x28))) {
            sp2C->Rot.x += 32.0f;
            if (sp2C->Rot.x >= 360.0f) {
                sp2C->Rot.x -= 360.0f;
                sp2C->unkAC += 1;
            }
        }
    }
    if (sp2C->Pos.y >= (f32) (sp2C->unkAE + 0xF0)) {
        sp2C->unk44 = 0.0f;
        sp2C->unk40 = 0.0f;
        sp2C->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp2C->Rot.y = sp2C->unk3C;
    if ((sp2C->unkB4 == 1)) {
        if ((sp2C->Pos.z + sp2C->Vel.z) < -960.0f) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp2C->Vel.x = 0.0f;
            sp2C->Vel.z = 0.0f;
        }
    }
    if ((sp2C->unkB4 == 2)) {
        if (((sp2C->Pos.z + sp2C->Vel.z) > -2400.0f)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp2C->Vel.x = 0.0f;
            sp2C->Vel.z = 0.0f;
        }
    }
    if (sp2C->unkAC == 2) {
        sp2C->unkAA += 1;
        sp2C->unkA4 = 8;
        sp2C->Rot.x = 0.0f;
        sp2C->unk132 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, (s32) sp2C->unkAA, 0xA2, &D_80117884);
    }
}

void func_800B271C(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    f32 sp34;
    s16 sp32;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = 1;
        sp3C->unk44 = 8.0f;
        sp3C->unk48 = 28.0f;
        sp3C->unk40 = 295.0f;
        sp3C->unkA8 = 0x18;
        func_8001BB34(gCurrentParsedObject, 0);
    }
    sp3C->Rot.y = sp3C->unk3C;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
    }
    if ((sp3C->unkB4 == 1)) {
        if (((sp3C->Pos.z + sp3C->Vel.z) < -960.0f)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp3C->Vel.x = 0.0f;
            sp3C->Vel.z = 0.0f;
        }
    }
    if ((sp3C->unkB4 == 2)) {
        if (((sp3C->Pos.z + sp3C->Vel.z) > -2400.0f)) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp3C->Vel.x = 0.0f;
            sp3C->Vel.z = 0.0f;
        }
    }
    if (sp3C->unk132 == 1) {
        sp32 = func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f);
        if (sp32 != 0) {
            sp3C->unk44 = 0.0f;
            sp3C->unk48 = 0.0f;
            sp3C->unk40 = 0.0f;
            sp3C->unkA4 = 0xA;
            sp3C->unkAA = 0;
            sp3C->unk132 = 0;
            sp3C->unk108 = 1;
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0xA2, &D_80117884);
            func_800296AC(gCurrentParsedObject, 24.0f, 0, 0);
        }
    }
}

void func_800B2AAC(void) {
    struct ObjectStruct* sp24;
    s16 sp22;
    s16 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 6, 0xA2, &D_80117884);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp22 = sp24->unkE8[0];
        sp20 = sp24->unkE8[1];
        if (sp22 != -1) {
            func_800281A4(gCurrentParsedObject, 0);
            func_8002B0E4((s32) sp22);
        }
        if (sp20 != -1) {
            func_800281A4(gCurrentParsedObject, 1);
            func_8002B0E4((s32) sp20);
        }
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800B2C54(void) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp34 = &gObjects[gCurrentParsedObject];
    sp32 = sp34->unkE8[0];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 0.0f;
        sp34->unk48 = 0.0f;
        sp34->unk108 = 0x3C;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BBDC(gCurrentParsedObject, 1);
        if (sp32 != -1) {
            gObjects[sp32].unk108 = 0;
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8001BB34(gCurrentParsedObject, !(sp34->unk108 & 1));
    if (sp34->unk108 == 1) {
        sp34->unkA4 = 1;
        sp34->unkAA = 1;
        sp34->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001BB34(gCurrentParsedObject, 0);
        if (sp32 != -1) {
            gObjects[sp32].unk108 = 1;
        }
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xA2, &D_80117884);
    }
}

void func_800B2E5C(void) {
}

// RODATA
void func_800B2E6C(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].unkA4;
    if ((gObjects[gCurrentParsedObject].unk100 <= 0)) {
        if ((gObjects[gCurrentParsedObject].unkA4 != 4)) {
            gObjects[gCurrentParsedObject].unk108 = 0;
            gObjects[gCurrentParsedObject].unkA4 = 4;
            gObjects[gCurrentParsedObject].unk132 = 0;
            func_8001BB34(gCurrentParsedObject, 0);
            func_8002B0E4(gCurrentParsedObject);
            return;
        }
    }
    switch (sp1C) {
        case 1:
            func_800B1048();
            break;
        case 11:
            func_800B1248();
            break;
        case 2:
            func_800B15A0();
            break;
        case 6:
            func_800B1B7C();
            break;
        case 3:
            func_800B1914();
            break;
        case 10:
            func_800B1FA8();
            break;
        case 7:
            func_800B2250();
            break;
        case 8:
            func_800B271C();
            break;
        case 5:
            func_800B2C54();
            break;
        case 4:
            func_800B2AAC();
            break;
        default:
            break;
    }
}

void stub_9B110_3() {
}

void func_800B30B4(void) {
    gObjects[gCurrentParsedObject].unkA4 = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800B3118(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    f32 sp34;
    s16 sp32;
    f32 temp_f20;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = 1;
        sp3C->unk44 = 32.0f;
        sp3C->unk48 = 8.0f;
        func_800272E8(gCurrentParsedObject);
    }
    if ((sp3C->unk132 == 1) && (func_8002A560(gCurrentParsedObject, 15.0f) == 0)) {
        func_8002A8B4(gCurrentParsedObject, 20.0f);
        func_8002A9A4(gCurrentParsedObject, 20.0f);
        sp3C->unk132 = 2;
    }
    if ((f64) sp3C->Scale.x < 3.0) {
        sp3C->Scale.x = (f32) ((f64) sp3C->Scale.x + 0.2);
        sp3C->Scale.y = sp3C->Scale.z = sp3C->Scale.x;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp34, &sp38, 0.0f, -20.0f, 0.0f) != 0) {
        sp3C->unkA4 = 2;
        sp3C->unk132 = 0;
    }
    if (func_80029018(gCurrentParsedObject, 3U, 20.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp3C->unkA4 = 2;
        sp3C->unk132 = 0;
    }
    sp32 = D_801651A0;
    sp3C->Rot.y = sp3C->unk3C;
    sp3C->unkB2 -= 1;
    if (sp3C->unkB2 <= 0) {
        sp3C->unkA4 = 2;
        sp3C->unk132 = 0;
    }
}

void func_800B33B4(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800B33E4(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].unkA4) { /* irregular */
            case 1:
                func_800B3118();
                break;
            case 2:
                func_800B33B4();
                break;
            default:
                break;
        }
    }
}

extern struct UnkStruct_80027C00 D_801139C4;
extern f32 D_80114B88;

int func_800B34AC(struct ObjectStruct* arg0, s32 arg1, s32 arg2) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp32 = func_80027464(1, &D_801139C4, arg0->Pos.x, arg0->Pos.y + 60.0f, arg0->Pos.z, arg0->unk3C);
    if (sp32 != -1) {
        func_80026F10((s32) (s16) arg1, (s32) sp32);
        sp34 = &gObjects[sp32];
        sp34->unk3C = arg0->unk3C;
        sp34->unk40 = arg0->unk40;
        sp34->Rot.y = arg0->unk3C;
        sp34->unkA4 = 1;
        sp34->unkB2 = 0x3C;
        sp34->unk132 = 0;
        sp34->unk108 = 1;
        func_80029C40((s32) sp32);
        func_80029D04((s32) sp32);
        sp34->Scale.x = sp34->Scale.y = sp34->Scale.z = 0.7f;
    }
    return sp32;
}

void func_800B3630(void) {
}

void func_800B3640(void) {
    gObjects[gCurrentParsedObject].unkA4 = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800B36A4(void) {
    func_8002B0E4(gCurrentParsedObject);
}

#define NORMALIZE_ANGLE(angle, offset)                                                           \
    (((angle) + (offset)) > 180.0f                                                               \
         ? (((angle) + (offset)) >= 360.0f ? ((angle) + (offset)) - 360.0f : (angle) + (offset)) \
         : (((angle) + (offset)) < 0.0f ? ((angle) + (360.0f + (offset))) : (angle) + (offset)))

void func_800B36D4(void) {
    struct ObjectStruct* sp34;
    struct ObjectStruct* sp30;

    sp30 = &gObjects[gCurrentParsedObject];
    if (sp30->unkE6[0] != -1) {
        sp34 = &gObjects[sp30->unkE6[0]];
        sp30->Pos.x = sp34->Pos.x;
        sp30->Pos.y = (f32) (sp34->unkB0 - 0x32);
        sp30->Pos.z = sp34->Pos.z;
        sp30->unk3C = sp34->unk3C;
        sp30->unk40 = sp34->unk40;
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
        sp30->Rot.y = sp34->Rot.y;

        if (((sp34->Vel.x < 0.0f) ? -sp34->Vel.x : sp34->Vel.x) >=
            ((sp34->Vel.z < 0.0f) ? -sp34->Vel.z : sp34->Vel.z)) {
            sp30->Rot.x = ((sp30->Rot.x + sp34->Vel.x) > 180.0f)
                              ? (((sp30->Rot.x + sp34->Vel.x) >= 360.0f) ? ((sp30->Rot.x + sp34->Vel.x) - 360.0f)
                                                                         : (sp30->Rot.x + sp34->Vel.x))
                              : (((sp30->Rot.x + sp34->Vel.x) < 0.0f) ? (sp30->Rot.x + 360.0f + sp34->Vel.x)
                                                                      : (sp30->Rot.x + sp34->Vel.x));
        } else {
            sp30->Rot.x = ((sp30->Rot.x + sp34->Vel.z) > 180.0f)
                              ? (((sp30->Rot.x + sp34->Vel.z) >= 360.0f) ? ((sp30->Rot.x + sp34->Vel.z) - 360.0f)
                                                                         : (sp30->Rot.x + sp34->Vel.z))
                              : (((sp30->Rot.x + sp34->Vel.z) < 0.0f) ? (sp30->Rot.x + 360.0f + sp34->Vel.z)
                                                                      : (sp30->Rot.x + sp34->Vel.z));
        }
    } else {
        func_800B36A4();
    }
}

void func_800B3A80(void) {
    s16 sp26;

    sp26 = func_80027464(1, &D_801139D0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].unkA4 = 1;
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32) sp26, 0, 0, 0xB6, &D_80117928);
        func_8001ABF4((s32) sp26, 0, 0, &D_801179B4);
        func_8001ABF4((s32) sp26, 1, 0, &D_801179EC);
        func_8001ABF4((s32) sp26, 2, 0, &D_80117A24);
    }
}

void func_800B3BC0(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unkA4 = 8;
    } else if (D_80177A64 == 1) {
        sp4->unkA4 = 7;
    } else {
        return;
    }
    sp4->unk132 = 0;
}

void func_800B3C5C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = Math_Random(0x14) + 0x3C;
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((sp1C->unk132 == 1) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp1C->unk132 = 2;
    }
    sp1C->unkA6 -= 1;
    if ((sp1C->unkA6 <= 0) && (func_8002A1FC(gCurrentParsedObject, 720.0f) != 0)) {
        sp1C->unkA4 = 2;
        sp1C->unk132 = 0;
    }
}

void func_800B3DCC(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 6.0f;
        sp34->unk48 = 0.0f;
        sp34->unkA6 = 0x168;
        sp34->unkA8 = 0;
    }
    func_8002A8B4(gCurrentParsedObject, 2.0f);
    sp34->Rot.y = sp34->unk3C;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        if (sp34->unk104 <= gCurrentParsedObject) {
            func_80029B60(gCurrentParsedObject);
        } else {
            sp34->unk44 = 0.0f;
        }
    }
    func_80029C40(gCurrentParsedObject);
    sp34->unk44 = 4.0f;
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp30 = sp34->unk3C;
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp34->unkD4 = sp34->unk3C;
        sp34->unk3C = sp30;
        sp34->unkB4 = func_8002A800(sp34->unkD4, sp34->unk3C, 8.0f);
        sp34->Vel.x = 0.0f;
        sp34->Vel.z = 0.0f;
        sp34->unkA4 = 0xA;
        sp34->unk44 = 0.0f;
        sp34->unk132 = 0;
        return;
    } else {
        func_800C00F4(sp34, 0.0f);
    }
    sp34->unkA6 = (s16) (s32) ((f32) sp34->unkA6 - sp34->unk44);
    if ((func_8002A2EC(gCurrentParsedObject, 150.0f) != 0) && ((sp34->Pos.y + 60.0f) <= gObjects->Pos.y)) {
        sp34->unkA4 = 3;
        sp34->unk132 = 0;
        return;
    }
    if (sp34->unkA6 <= 0) {
        sp34->unkA4 = 3;
        sp34->unkA8 = 1;
        sp34->unk132 = 0;
    }
}

void func_800B4120(void) {
    struct ObjectStruct* sp1C;
    f32 sp18;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
    }
    sp1C->Rot.y = sp1C->unk3C;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp18 = (f32) (sp1C->unkB4 * 2);
    if (func_8002A800(sp1C->unk3C, sp18, 8.0f) == 0) {
        sp1C->unkA4 = 2;
        sp1C->unk132 = 0;
        sp1C->Rot.y = sp1C->unk3C;
        return;
    }
    sp1C->unk3C = func_80015538(sp1C->unk3C, sp18);
}

void func_800B4258(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xB6, &D_80117928);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801179D0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117A08);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80117A40);
    }
    func_8002A8B4(gCurrentParsedObject, 4.0f);
    sp24->Rot.y = sp24->unk3C;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((func_8002A2EC(gCurrentParsedObject, 150.0f) != 0)) {
        if ((sp24->Pos.y + 60.0f) >= gObjects->Pos.y) {
            sp24->unkA8 = 0;
        }
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->unkA4 = 4;
        if (sp24->unkA8 == 1) {
            sp24->unkA4 = 6;
        }
        sp24->unk132 = 0;
    }
}

void func_800B444C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xB6, &D_80117928);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801179D0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117A08);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80117A40);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->unkA6 += 1;
    if (sp24->unkA6 == 0xA) {
        func_800B5368(sp24, gCurrentParsedObject, 1);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB6, &D_80117928);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801179B4);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801179EC);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80117A24);
        sp24->unkA4 = 1;
        sp24->unk132 = 0;
    }
}

void func_800B466C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xB6, &D_80117928);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801179D0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117A08);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80117A40);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->unkA6 += 1;
    if (sp24->unkA6 == 1) {
        func_800B4EFC(sp24, gCurrentParsedObject, 0);
        sp24->unk132 = 2;
    }
    if (sp24->unkA6 == 6) {
        sp24->unkA4 = 1;
        sp24->unk132 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB6, &D_80117928);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801179B4);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801179EC);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80117A24);
    }
}

void func_800B4898(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0xB6, &D_80117928);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800B49C0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = 0x3C;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    func_8001BB34(gCurrentParsedObject, !(sp24->unk108 & 1));
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unk108 == 1) {
        sp24->unkA4 = 1;
        sp24->unk132 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}

// RODATA
void func_800B4B08(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].unkA4;
    switch (sp1C) {
        case 1:
            func_800B3C5C();
            break;
        case 2:
            func_800B3DCC();
            break;
        case 10:
            func_800B4120();
            break;
        case 3:
            func_800B4258();
            break;
        case 4:
            func_800B466C();
            break;
        case 6:
            func_800B444C();
            break;
        case 7:
            func_800B49C0();
            break;
        default:
            func_800B4898();
            break;
    }
}

void __stub() {
}

void func_800B4C1C(void) {
    gObjects[gCurrentParsedObject].unkA4 = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800B4C80(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 20.0f;
        func_800175F0(gCurrentParsedObject, 0, 0x1B, -1, 0);
    }
    func_800272E8(gCurrentParsedObject);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, -30.0f, 0.0f) != 0) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
        return;
    }
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
        return;
    }
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->unkB2 -= 1;
    if (sp2C->unkB2 <= 0) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
    }
}

void func_800B4E60(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800B4E90(void) {
    if (gObjects[gCurrentParsedObject].unkA4 == 1) {
        func_800B4C80();
    } else {
        func_800B4E60();
    }
}

int func_800B4EFC(struct ObjectStruct* arg0, s32 arg1, s32 arg2) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp22 = func_80027464(1, &D_801139F4, arg0->Pos.x, arg0->Pos.y + 60.0f, arg0->Pos.z, arg0->unk3C);
    if (sp22 != -1) {
        func_80026F10((s32) (s16) arg1, (s32) sp22);
        sp24 = &gObjects[sp22];
        sp24->unkA4 = 1;
        sp24->unkB2 = 0x5A;
        sp24->unk132 = 0;
        sp24->unk40 = 90.0f;
        sp24->Rot.y = arg0->unk3C;
        sp24->unk108 = 1;
        func_8001C0EC((s32) sp22, 0, 0, 0xB7, &D_80117A5C);
        func_8001ABF4((s32) sp22, 0, 0, &D_80117A7C);
        func_80029C40((s32) sp22);
        func_80029D04((s32) sp22);
    }
    return sp22;
}

void func_800B5074_1() {
}

void func_800B5074(void) {
}

void func_800B5084(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 10.0f;
        sp24->unk48 = 0.0f;
        func_80017664(gCurrentParsedObject, 0, 0x37, -1, 0);
    }
    if (sp24->unkB2 == 0x20) {
        func_800272E8(gCurrentParsedObject);
        sp24->unk108 = 1;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    sp24->Rot.y = sp24->unk3C;
    if (func_8001B44C(gCurrentParsedObject, 3) != 0) {
        func_8002B114(gCurrentParsedObject);
        return;
    }
    if (func_80029018(gCurrentParsedObject, 3U, 180.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        func_8002B114(gCurrentParsedObject);
        return;
    }
    sp24->unkB2 -= 1;
    if (sp24->unkB2 <= 0) {
        func_8002B114(gCurrentParsedObject);
        return;
    }
}

void func_800B52A4(void) {
    func_8002B114(gCurrentParsedObject);
}

void func_800B52D4(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) { /* irregular */
        case 1:
            func_800B5084();
            break;
        case 2:
            func_800B52A4();
            break;
        default:
            break;
    }
}

int func_800B5368(struct ObjectStruct* arg0, s32 arg1, s32 arg2) {
    struct ObjectStruct* sp2C;
    s16 sp2A;
    f32 sp24;

    sp2A = func_80027464(1, &D_80113A00, arg0->Pos.x, arg0->Pos.y, arg0->Pos.z, arg0->unk3C);
    if (sp2A != -1) {
        func_80026F10((s32) (s16) arg1, (s32) sp2A);
        sp2C = &gObjects[sp2A];
        sp24 = func_80015538(arg0->unk3C, 35.0f);
        sp2C->Vel.x = 140.0f * sinf((f32) ((f64) sp24 * DEG_TO_RAD));
        sp2C->Vel.z = 140.0f * cosf((f32) ((f64) sp24 * DEG_TO_RAD));
        sp2C->Pos.x = arg0->Pos.x + sp2C->Vel.x;
        sp2C->Pos.z = arg0->Pos.z + sp2C->Vel.z;
        sp2C->Pos.y = arg0->Pos.y + 100.0f;
        sp2C->unk40 = arg0->unk40;
        sp2C->unk3C = arg0->unk3C;
        sp2C->unk44 = 0.0f;
        sp2C->Rot.y = arg0->unk3C;
        sp2C->unkA4 = 1;
        sp2C->unkB2 = 0x3C;
        sp2C->unk132 = 0;
        sp2C->unk108 = 0;
        func_8001C0EC((s32) sp2A, 3, 0, 0xB8, &D_80117A98);
        func_80029C40((s32) sp2A);
        func_80029D04((s32) sp2A);
    }
    return sp2A;
}
