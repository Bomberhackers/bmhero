#include <ultra64.h>

void func_800B55B0(void) {
    s8 sp2F;

    sp2F = func_80027464(1, &D_80113A0C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2F != -1) {
        gObjects[sp2F].actionState = 1;
        gObjects[sp2F].unk132 = 0;
        gObjects[sp2F].Scale.x = 1.5f;
        gObjects[sp2F].Scale.z = gObjects[sp2F].Scale.y = gObjects[sp2F].Scale.x;
        if (D_80165100->unkA != 0) {
            gObjects[sp2F].unkB0 = 1;
        }
        func_8001C0EC(sp2F, 0, 0, 0xB9, &D_80117AA0);
    }
}

void func_800B5778(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];

    if (D_80177A64 == 0) {
        sp4->actionState = 7;
    } else if (D_80177A64 == 1) {
        sp4->actionState = 6;
    } else {
        return;
    }
    sp4->unk132 = 0;
}

void func_800B5814(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB9, &D_80117AA0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117B4C);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->unkA6 += 1;
    if ((sp24->unkA6 >= 0x14) && (func_8002A1FC(gCurrentParsedObject, 1500.0f) != 0)) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
    }
}

void func_800B5978(void) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 3.0f;
        sp34->unk48 = 0.0f;
        sp34->unkA6 = 0x294;
        sp34->unkA8 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, (s32) sp34->unkA8, 0xB9, &D_80117AA0);
        func_800175F0(gCurrentParsedObject, 0, 0x11, -1, 0);
    }

    func_8002A8B4(gCurrentParsedObject, 8.0f);
    sp34->Rot.y = sp34->unk3C;
    sp34->unkA6 -= 3;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3, 30.0f, 0, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if ((sp34->unkB0 == 1)) {
        if ((sp34->Pos.z + sp34->Vel.z) < -5760.0f) {
            func_80029824(gCurrentParsedObject, func_800297DC());
            sp34->Vel.x = 0.0f;
            sp34->Vel.z = 0.0f;
        }
    }

    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp34->unkA8 += 1;
        if (sp34->unkA8 >= 4) {
            sp34->actionState = 0xC;
            sp34->unkAE = 2;
            sp34->unk132 = 0;
        }
        if (sp34->unkA8 == 2) {
            sp34->unk44 = 15.0f;
            sp34->unk48 = 0.0f;
        }
        if (sp34->unkA8 == 3) {
            sp34->unk44 = 3.0f;
            sp34->unk48 = 0.0f;
        }
        func_8001C0EC(gCurrentParsedObject, 0, (s32) sp34->unkA8, 0xB9, &D_80117AA0);
    }
    sp32 = func_800C0194((struct UnkStructSTCG*) sp34, 0.0f);
    if (sp32 < -0x50) {
        sp34->actionState = 0xB;
        sp34->unk132 = 0;
        return;
    }
    func_800C00F4(sp34, 0);
}

void func_800B5D18(void) {
    struct ObjectStruct* sp44;
    UNUSED char pad[0x8];

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = 1;
        sp44->unk44 = 0.0f;
        sp44->unk48 = 0.0f;
        sp44->unkA8 = 4;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, (s32) sp44->unkA8, 0xB9, &D_80117AA0);
        func_80029D04(gCurrentParsedObject);
    }

    if (((sp44->unk132 == 1) || (sp44->unk132 == 2)) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp44->unkA8 += 1;
        if ((sp44->unk132 == 1)) {
            if (sp44->unkA8 == 5) {
                sp44->unk132 = 2;
                sp44->unk44 = 12.0f;
                func_80029EF8(gCurrentParsedObject, 20.0f, 2.0f);
                func_800175F0(gCurrentParsedObject, 0, 4, -1, 0);
            }
        }
        if (sp44->Vel.y <= 0.0f) {
            sp44->unkA8 = 7;
            sp44->unk132 = 3;
        }
        func_8001C0EC(gCurrentParsedObject, 0, (s32) sp44->unkA8, 0xB9, &D_80117AA0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    if ((s32) sp44->unk132 >= 2) {
        if (func_80029F58(gCurrentParsedObject, 0, 0, 0, 120.0f) == 1) {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB9, &D_80117AA0);
            sp44->unkAE -= 1;
            sp44->actionState = 0xC;
            if (sp44->unkAE <= 0) {
                sp44->actionState = 3;
                sp44->unk44 = 0.0f;
                sp44->unk48 = 0.0f;
            }
            sp44->unk132 = 0;
        }
        if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
        if ((sp44->unkB0 == 1)) {
            if ((sp44->Pos.z + sp44->Vel.z) < -5760.0f) {
                func_80029824(gCurrentParsedObject, func_800297DC());
                sp44->Vel.x = 0.0f;
                sp44->Vel.z = 0.0f;
            }
        }
    }

    sp44->Vel.x = MIN_CLAMP(sp44->Vel.x, 48.0f);

    sp44->Vel.y = MIN_CLAMP(sp44->Vel.y, 48.0f);

    sp44->Vel.z = MIN_CLAMP(sp44->Vel.z, 48.0f);

    sp44->Rot.y = sp44->unk3C;
}

void func_800B62C8(void) {
    struct ObjectStruct* sp44;
    f32 sp40;
    f32 sp3C;
    s16 sp3A;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = 1;
        sp44->unk44 = 0.0f;
        sp44->unk48 = 0.0f;
        sp44->unkA8 = 4;
        sp44->unkAE = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, (s32) sp44->unkA8, 0xB9, &D_80117AA0);
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
    }
    if (((sp44->unk132 == 1) || (sp44->unk132 == 2)) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp44->unkA8 += 1;
        if ((sp44->unk132 == 1)) {
            if (sp44->unkA8 == 5) {
                sp44->unk132 = 2;
                sp40 = gObjects->Pos.x - sp44->Pos.x;
                sp3C = gObjects->Pos.z - sp44->Pos.z;
                sp3A = (s16) (s32) (sqrtf((sp40 * sp40) + (sp3C * sp3C)) / 60.0f);
                sp44->unkAA = sp3A + 0x20;
                sp44->unkAC = sp3A + 0x10;
                if ((sp3A < 6) && ((gObjects->Pos.y - sp44->Pos.y) > 120.0f)) {
                    sp44->unkAA = 0x30;
                    sp44->unkAC = 0;
                    sp44->unkAE = 1;
                    sp44->unk3C = func_8002A46C(gCurrentParsedObject);
                }
                func_80029EF8(gCurrentParsedObject, (f32) sp44->unkAA, 2.0f);
                sp44->unk44 = (f32) sp44->unkAC;
                func_800175F0(gCurrentParsedObject, 0, 4, -1, 0);
            }
        }
        if (sp44->Vel.y <= 0.0f) {
            sp44->unkA8 = 7;
            sp44->unk132 = 3;
            if (sp44->unkAE == 1) {
                sp44->unk44 = 10.0f;
            }
        }
        func_8001C0EC(gCurrentParsedObject, 0, (s32) sp44->unkA8, 0xB9, &D_80117AA0);
    }
    if ((s32) sp44->unk132 >= 2) {
        if (func_80028FA0(gCurrentParsedObject) != 0) {
            func_80029B60(gCurrentParsedObject);
            if ((gObjects[sp44->interactingObjIdx].Pos.y + 60.0f) >= sp44->Pos.y) {
                sp44->unkA8 = 7;
                sp44->unk132 = 3;
                sp44->unk44 = 4.0f;
                sp44->unk40 = 90.0f;
                if (sp44->Vel.y > -6.0f) {
                    sp44->Vel.y = -6.0f;
                }
            }
        }
        if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 120.0f) == 1) {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB9, &D_80117AA0);
            sp44->actionState = 0xA;
            sp44->unk44 = 0.0f;
            sp44->unk132 = 0;
        }
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
        if ((sp44->unkB0 == 1)) {
            if ((sp44->Pos.z + sp44->Vel.z) < -5760.0f) {
                func_80029824(gCurrentParsedObject, func_800297DC());
                sp44->Vel.x = 0.0f;
                sp44->Vel.z = 0.0f;
            }
        }
    }
    sp44->Vel.x = MIN_CLAMP(sp44->Vel.x, 48.0f);

    sp44->Vel.y = MIN_CLAMP(sp44->Vel.y, 48.0f);

    sp44->Vel.z = MIN_CLAMP(sp44->Vel.z, 48.0f);

    sp44->Rot.y = sp44->unk3C;
}

void func_800B6A94(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0xB9, &D_80117AA0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117B68);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkA6 == 0x12) {
        func_800B7720(sp24, gCurrentParsedObject, 0);
        func_800175F0(gCurrentParsedObject, 0, 0x5B, -1, 0);
    }
    sp24->unkA6++;
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 9;
        sp24->unk132 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0xC, 0xB9, &D_80117AA0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117B4C);
    }
}

void func_800B6C60(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp1C->actionState = 1;
        sp1C->unk132 = 0;
    }
}

void func_800B6D40(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 15.0f;
        sp2C->unk48 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 0.0f, 3.0f);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
        if (D_80177740[D_801776E0 & 1] == 0xF5) {
            sp2C->actionState = 7;
            sp2C->unk132 = 0;
        }
    }
    sp2C->Vel.y = MIN_CLAMP(sp2C->Vel.y, 48.0f);
}

void func_800B6F2C(void) {
    func_8001BB34(gCurrentParsedObject, 0);
    func_8002B0E4(gCurrentParsedObject);
}

void func_800B6F6C(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk132 = 1;
        sp2C->damageState = 0x3C;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB9, &D_80117AA0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117B4C);
        func_80029EF8(gCurrentParsedObject, 0.0f, 8.0f);
    }

    func_8001BB34(gCurrentParsedObject, !(sp2C->damageState & 1));
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((sp2C->unk132 == 1) && (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1)) {
        sp2C->unk132 = 2;
    }
    if (sp2C->damageState == 1) {
        sp2C->actionState = 1;
        sp2C->unk132 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}

void func_800B7148(void) {
}

void func_800B7158(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
    }
    func_8002A8B4(gCurrentParsedObject, 30.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8002A560(gCurrentParsedObject, 15.0f) == 0) {
        sp1C->actionState = 5;
        sp1C->unk132 = 0;
    }
    sp1C->Rot.y = sp1C->unk3C;
}

void func_800B725C(void) {
    s32 sp1C;

    sp1C = (s32) gObjects[gCurrentParsedObject].actionState;
    switch (sp1C) {
        case 1:
            func_800B5814();
            break;
        case 2:
            func_800B5978();
            break;
        case 3:
            func_800B62C8();
            break;
        case 5:
            func_800B6A94();
            break;
        case 9:
            func_800B6C60();
            break;
        case 11:
            func_800B6D40();
            break;
        case 10:
            func_800B7158();
            break;
        case 6:
            func_800B6F6C();
            break;
        case 7:
            func_800B6F2C();
            break;
        case 12:
            func_800B5D18();
            break;
        default:
            break;
    }
}

void _stub0() {
}

void func_800B7398(void) {
    gObjects[gCurrentParsedObject].actionState = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800B73FC(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 22.0f;
        sp2C->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xBA, &D_80117BBC);
        func_80019448(gCurrentParsedObject, 2, 0, 1);
        func_800272E8(gCurrentParsedObject);
    }
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->Rot.x = func_80015538(sp2C->Rot.x, 30.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, -30.0f, 0.0f) != 0) {
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 30.0f, 0.0f) != 0) {
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
    }
    sp2C->unkB2 -= 1;
    if (sp2C->unkB2 <= 0) {
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
    }
}

void func_800B765C(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800B768C(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_800B73FC();
            break;
        case 2:
            func_800B765C();
            break;
        default:
            break;
    }
}

s16 func_800B7720(struct ObjectStruct* arg0, s16 arg1, UNUSED s32 arg2) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp32 = func_80027464(1, &D_80113A18, arg0->Pos.x, arg0->Pos.y + 120.0f, arg0->Pos.z, arg0->unk3C);
    if (sp32 != -1) {
        func_80026F10(arg1, sp32);

        sp34 = &gObjects[sp32];
        sp34->unk40 = arg0->unk40;
        sp34->unk44 = 10.0f;
        sp34->Rot.y = arg0->unk3C;
        sp34->actionState = 1;
        sp34->unkB2 = 0x28;
        sp34->unk132 = 0;
        sp34->damageState = 1;
        sp34->Scale.x = 1.0f;
        sp34->Scale.z = sp34->Scale.y = sp34->Scale.x;
        func_80029C40((s32) sp32);
        func_80029D04((s32) sp32);
    }
    return sp32;
}

void func_800B78A4(void) {
    s8 sp2F;

    sp2F = func_80027464(1, &D_80113A24, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2F != -1) {
        gObjects[sp2F].actionState = 1;
        gObjects[sp2F].unk132 = 0;
        gObjects[sp2F].Scale.x = 1.5f;
        gObjects[sp2F].Scale.z = gObjects[sp2F].Scale.y = gObjects[sp2F].Scale.x;
        func_8001C0EC((s32) sp2F, 0, 0, 0xB9, &D_80117AA0);
    }
}

void func_800B7A28(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        sp24->damageState = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB9, &D_80117AA0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117B4C);
    }
    func_8002A8B4(gCurrentParsedObject, 8.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->unkA6 += 1;
    if ((sp24->unkA6 >= 0x14) && (func_8002A1FC(gCurrentParsedObject, 1500.0f) != 0)) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
        sp24->actionState = 3;
    }
}

void func_800B7BB4(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;
    s8 sp23;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp28 = gObjects->Pos.x - sp2C->Pos.x;
        sp24 = gObjects->Pos.z - sp2C->Pos.z;
        sp23 = (s8) (s32) ((sqrtf((sp28 * sp28) + (sp24 * sp24)) / 60.0f) + 1.0f);
        sp2C->damageState = 0;
        sp2C->unkA6 = sp23 * 0x3C;
        sp2C->unkA8 = 4;
        sp2C->unkAA = sp2C->unkA6;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0xB9, &D_80117AA0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp2C->Rot.y = sp2C->unk3C;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {}
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        if (sp2C->unk132 == 1) {
            sp2C->unkA8 += 1;
        }
        if (sp2C->unkA8 == 5) {
            sp2C->unk44 = 12.0f;
            sp2C->unk48 = 16.0f;
            sp2C->unk40 = 35.0f;
        }
        if (sp2C->unkA8 == 6) {
            sp2C->unk132 = 2;
        }
        func_8001C0EC(gCurrentParsedObject, 0, (s32) sp2C->unkA8, 0xB9, &D_80117AA0);
    }
    if (sp2C->unk132 == 2) {
        sp2C->unkA6 = (s16) (s32) ((f32) sp2C->unkA6 - sp2C->unk44);
        if (sp2C->unkA6 <= (sp2C->unkAA / 2)) {
            sp2C->actionState = 4;
            sp2C->unk132 = 0;
            func_8001C0EC(gCurrentParsedObject, 0, 7, 0xB9, &D_80117AA0);
        }
    }
}

void func_800B7F90(void) {
    struct ObjectStruct* sp2C;
    UNUSED char pad[0x5];

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk40 = 325.0f;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117B84);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80117BA0);
        func_80029EF8(gCurrentParsedObject, 4.0f, 2.0f);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp2C->Rot.y = sp2C->unk3C;
    if (sp2C->unk132 == 1) {
        if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 120.0f) == 1) {
            sp2C->unk132 = 2;
            sp2C->unk44 = 0.0f;
            sp2C->unk48 = 0.0f;
            func_8001C0EC(gCurrentParsedObject, 0, 8, 0xB9, &D_80117AA0);
            func_8001BBDC(gCurrentParsedObject, 0);
        }
    } else if ((sp2C->unk132 == 2) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp2C->unk132 = 3;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB9, &D_80117AA0);
    }
    if (sp2C->unk132 == 3) {
        sp2C->actionState = 0xA;
        sp2C->unk132 = 0;
        sp2C->damageState = 1;
    }
}

void func_800B81F0(void) {
    s32 sp1C;

    sp1C = (s32) gObjects[gCurrentParsedObject].actionState;
    switch (sp1C) {
        case 1:
            func_800B7A28();
            break;
        case 2:
            func_800B5978();
            break;
        case 3:
            func_800B7BB4();
            break;
        case 4:
            func_800B7F90();
            break;
        case 5:
            func_800B6A94();
            break;
        case 9:
            func_800B6C60();
            break;
        case 10:
            func_800B7158();
            break;
        case 6:
            func_800B6F6C();
            break;
        case 7:
            func_800B6F2C();
            break;
        case 8:
            func_800B7148();
            break;
        default:
            break;
    }
}

void func_800B831C(void) {
    s16 sp26;

    sp26 = func_80027464(1, &D_80113A30, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].actionState = 1;
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32) sp26, 0, 0, 0xEC, &D_80117BC0);
    }
}

void func_800B8414(void) {
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        return;
    }
    func_8002B0E4(gCurrentParsedObject);
}

void func_800B846C(void) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->Rot.y = func_8002A46C(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp22 = Math_Random(0xA);
        if (sp22 < 6) {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0xEC, &D_80117BC0);
        } else {
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0xEC, &D_80117BC0);
        }
    }
}

void func_800B85C0(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 20.0f;
        sp2C->unk48 = 3.0f;
        sp2C->unk40 = 270.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp2C->unk3C = func_80015538(sp2C->unk3C, 12.0f);
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, -15.0f, 0.0f) != 0) {
        sp2C->actionState = 1;
        sp2C->unk132 = 0;
    }
}

void func_800B86FC(void) {
    s32 sp24;

    sp24 = gObjects[gCurrentParsedObject].actionState;
    switch (sp24) { /* irregular */
        case 1:
            func_800B846C();
            break;
        case 2:
            func_800B85C0();
            break;
        case 3:
            func_8002B0E4(gCurrentParsedObject);
            break;
        default:
            break;
    }
}

void func_800B87C0(void) {
    s8 sp27;

    sp27 = func_80027464(1, &D_80113A3C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp27 != -1) {
        gObjects[sp27].unk3C = 0.0f;
        gObjects[sp27].unk102 = 0;
        gObjects[sp27].damageState = 1;
        gObjects[sp27].actionState = 1;
        gObjects[sp27].unk132 = 0;
    }
}

s8 func_800B890C(void) {
    s8 sp1F;

    for (sp1F = 0; sp1F < 5; sp1F++) {
        func_800B8968(sp1F);
    }
    return sp1F;
}

s8 func_800B8968(s8 arg0) {
    struct ObjectStruct* sp24;
    struct ObjectStruct* sp20;
    s8 sp1F;

    sp24 = &gObjects[gCurrentParsedObject];
    sp1F = (s8) sp24->unkE8[arg0];

    if (sp1F != -1) {
        sp20 = &gObjects[sp1F];
        if (((sp20->interactingObjIdx != -1)) || (sp20->unk100 == 0)) {
            func_800281A4(gCurrentParsedObject, arg0);
            sp20->damageState = 0;
            sp20->actionState = 3;
            sp20->unk132 = 0;
        }
    }
    return sp1F;
}

void func_800B8A78(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA8 = 2;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117C00);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((func_8002A2EC(gCurrentParsedObject, 360.0f) != 0) && (func_8002A3A8(gCurrentParsedObject, 1200.0f) != 0)) {
        sp1C->actionState = 2;
        sp1C->unk132 = 0;
    }
}

void func_800B8B98(void) {
    struct ObjectStruct* sp1C;
    s8 sp1B;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unkA6 = 0;
        sp1C->unkAA = 0;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        if (sp1C->unkA8 == 0) {
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117C38);
            sp1C->actionState = 1;
            sp1C->unk132 = 0;
            return;
        }
        if (sp1C->unkA8 == 1) {
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117C1C);
        }
    }

    if ((sp1C->unkA8 > 0)) {
        if ((sp1C->unkAA < 5)) {
            if (!(sp1C->unkA6 & 7)) {
                func_800B9070(sp1C, gCurrentParsedObject, sp1C->unkAA);
                sp1C->unkAA += 1;
            }
        }
    }

    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    sp1C->unkA6 += 1;
    sp1B = func_800B8F38();
    if (sp1B == 0) {
        sp1C->actionState = 2;
        sp1C->unk132 = 0;
        sp1C->unkA8 -= 1;
    }
}

void func_800B8DCC(void) {
    struct ObjectStruct* sp1C;
    s8 sp1B;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    for (sp1B = 0; sp1B < 5; sp1B++) {
        func_800B8968(sp1B);
    }

    func_8002B0E4(gCurrentParsedObject);
}

s8 func_800B8EBC(s8 arg0) {
    struct ObjectStruct* spC;
    UNUSED char pad[0x4];
    s8 sp7;

    spC = &gObjects[gCurrentParsedObject];
    sp7 = FALSE;
    if (spC->unkE8[arg0] != -1) {
        sp7 = TRUE;
    }
    return sp7;
}

s8 func_800B8F38(void) {
    s8 sp27;
    s8 sp26;

    for (sp27 = 0, sp26 = 0; sp26 < 5; sp26++) {
        sp27 += func_800B8EBC(sp26);
    }

    return sp27;
}

void func_800B8FB4(void) {
    s32 sp24;

    sp24 = gObjects[gCurrentParsedObject].actionState;
    switch (sp24) { /* irregular */
        case 1:
            func_800B8A78();
            break;
        case 2:
            func_800B8B98();
            break;
        case 3:
            func_800B8DCC();
            break;
        default:
            break;
    }
}

s16 func_800B9070(struct ObjectStruct* arg0, s16 arg1, s16 arg2) {
    struct ObjectStruct* sp2C;
    s16 sp2A;

    sp2A = func_80027C00(arg1, arg2, &D_80113A48, arg0->Pos.x, arg0->Pos.y, arg0->Pos.z, 0.0f);
    if (sp2A != -1) {
        sp2C = &gObjects[sp2A];
        sp2C->Pos.x = arg0->Pos.x;
        sp2C->Pos.y = arg0->Pos.y + 240.0f;
        sp2C->Pos.y += (f32) (arg2 << 5);
        sp2C->Pos.z = arg0->Pos.z;
        sp2C->Rot.y = arg0->unk3C;
        sp2C->unk40 = arg0->unk40;
        sp2C->unk3C = arg0->unk3C;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->damageState = 1;
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
        func_80029C40((s32) sp2A);
        func_80029D04((s32) sp2A);
        func_8001C0EC((s32) sp2A, 0, 0, 0xEC, &D_80117BC0);
    }
    return sp2A;
}

void func_800B9234(void) {
    s8 sp2F;

    sp2F = func_80027464(1, &D_80113A6C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2F != -1) {
        gObjects[sp2F].actionState = 1;
        gObjects[sp2F].unk132 = 0;
        gObjects[sp2F].unk3C = 0.0f;
        gObjects[sp2F].damageState = 1;
        gObjects[sp2F].unk100 = -1;
        gObjects[sp2F].unkA8 = 0x10;
        if (D_80165100->unkA != 0) {
            gObjects[sp2F].unkA8 = D_80165100->unkA;
        }
        gObjects[sp2F].unkAE = 0;
        if (D_80165100->unkC != 0) {
            gObjects[sp2F].unkAE = 1;
        }
        gObjects[sp2F].Scale.x = gObjects[sp2F].Scale.y = gObjects[sp2F].Scale.z = 1.3f;
        gObjects[sp2F].unkAA = 0x140;
        func_8001ABF4((s32) sp2F, 0, 0, &D_80117C78);
        func_80019448((s32) sp2F, 2, 0, 1);
        func_8001BB04(sp2F, 1);
    }
}

void func_800B954C(void) {
}

void func_800B955C(void) {
    struct ObjectStruct* sp1C;
    struct ObjectStruct* sp18;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unk3C = 0.0f;
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
    }
    sp18 = gObjects;
    if (sp18->Pos.z >= (sp1C->unk58 + 360.0f)) {
        sp1C->actionState = 3;
        sp1C->unk44 = 16.0f;
        sp1C->unkAC = 0x28;
        sp1C->unk40 = 0.0f;
        sp1C->unk132 = 0;
    }
}

void func_800B969C(void) {
    struct ObjectStruct* sp34;
    s16 sp32;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk48 = (f32) sp34->unkAC;
        func_8001BB04(gCurrentParsedObject, 0);
        func_80029EF8(gCurrentParsedObject, sp34->unk48, 3.0f);
    }
    func_80029C40(gCurrentParsedObject);
    sp2C = sp34->Vel.y;
    if (func_80029018(gCurrentParsedObject, 3U, 140.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Vel.y = sp2C;
    }
    sp32 = func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -180.0f, 180.0f);
    if (sp32 == 1) {
        func_800175F0(gCurrentParsedObject, 0, 0x19, -1, 0);
        sp34->actionState = 3;
        sp34->unk132 = 0;
        sp34->unkAA -= 0x32;
        if (sp34->unkAA <= 0) {
            sp34->actionState = 2;
        }
        sp34->unkAC -= 3;
        if (sp34->unkAC <= 0) {
            sp34->unkAC = 3;
        }
        if (D_80177740[D_801776E0 & 1] == 0xF5) {
            sp34->actionState = 5;
            sp34->unk132 = 0;
        }
    }
    sp34->Vel.y = MIN_CLAMP(sp34->Vel.y, 48.0f);
    sp34->Rot.x = func_80015538(sp34->Rot.x, 16.0f);
    sp34->Rot.y = sp34->unk3C;
}

void func_800B99A4(void) {
    struct ObjectStruct* sp34;
    UNUSED char pad[0x3];
    s16 sp2E;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = (f32) sp34->unkA8;
        sp34->unk48 = 0.0f;
        sp34->unk3C = 0.0f;
        sp34->unk40 = 0.0f;
        func_800175F0(gCurrentParsedObject, 0, 0x19, -1, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        if (sp34->unkAE == 0) {
            sp34->Vel.x = 0.0f;
            sp34->Vel.z = 0.0f;
            if ((gObjects[sp34->interactingObjIdx].Pos.z) < sp34->Pos.z) {
                func_80029C40(gCurrentParsedObject);
            }
        }
        if (sp34->unk106 == 0x185) {
            func_8002B0E4(gCurrentParsedObject);
            return;
        }
    }

    sp2E = func_800C0194((struct UnkStructSTCG*) sp34, 180.0f);
    if (sp2E < -0x50) {
        func_800175F0(gCurrentParsedObject, 0, 0x19, -1, 0);
        sp34->actionState = 3;
        sp34->unkAA = (s16) (s32) (sp34->unk44 * 20.0f);
        sp34->unkAC = 0;
        sp34->unk132 = 0;
        return;
    }
    if (func_80029018(gCurrentParsedObject, 3U, 140.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        if (sp34->unkAE == 0) {
            if ((sp34->unk3C >= 90.0f) && (sp34->unk3C <= 270.0f)) {
                sp34->unk3C = func_80015538(sp34->unk3C, 180.0f);
                sp34->unk3C = 0.0f;
            }
        }
        func_80029C40(gCurrentParsedObject);
        func_800175F0(gCurrentParsedObject, 0, 0x19, -1, 0);
    }
    func_800C00F4(sp34, 180.0f);
    sp34->Rot.x = func_80015538(sp34->Rot.x, 16.0f);
    sp34->Rot.y = sp34->unk3C;
}

void func_800B9D6C(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800B9D9C(void) {
    s32 sp24;

    sp24 = gObjects[gCurrentParsedObject].actionState;
    switch (sp24) { /* irregular */
        case 1:
            func_800B955C();
            break;
        case 2:
            func_800B99A4();
            break;
        case 3:
            func_800B969C();
            break;
        case 5:
            func_800B9D6C();
            break;
        default:
            break;
    }
    gObjects[gCurrentParsedObject].unk40 = 0.0f;
}

void func_800B9EA0(void) {
    s16 sp26;

    sp26 = func_80027464(1, &D_80113ACC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].actionState = 1;
        gObjects[sp26].unk132 = 0;
        gObjects[sp26].damageState = 1;
        gObjects[sp26].unk100 = -1;
        gObjects[sp26].unk102 = 2;
        func_8001BB34(sp26, 1);
    }
}

void func_800B9FFC(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 5;
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].damageState = 0;
    }
}

void func_800BA09C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xF3, &D_80117D8C);
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117E04);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((func_8002A2EC(gCurrentParsedObject, 480.0f) != 0) && (func_8002A3A8(gCurrentParsedObject, 960.0f) != 0)) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
    }
}

void func_800BA1E4(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 30.0f;
        sp2C->unk40 = 270.0f;
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, -10.0f, 0.0f) != 0) {
        sp2C->actionState = 3;
        sp2C->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_800175F0(gCurrentParsedObject, 0, 0x4A, -1, 0);
    }
}

void func_800BA334(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xF3, &D_80117D8C);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117DE8);
        func_800BA9C8(sp24, gCurrentParsedObject, 0);
        sp24->actionState = 4;
        sp24->unk132 = 0;
    }
}

void func_800BA468(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkB2 = 0x82;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (((s16) sp24->unkB2 % 24) == 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x28, -1, 0);
    }
    sp24->unkB2 -= 1;
    if (sp24->unkB2 <= 0) {
        sp24->actionState = 5;
        sp24->unk132 = 0;
    }
}

void func_800BA5A8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    sp24->damageState = 0;
    func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
    func_8007EDF4(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 5.0f);
    func_8002B114(gCurrentParsedObject);
}

void func_800BA648(void) {
    s32 sp1C;

    sp1C = (s32) gObjects[gCurrentParsedObject].actionState;
    switch (sp1C) {
        case 1:
            func_800BA09C();
            break;
        case 2:
            func_800BA1E4();
            break;
        case 3:
            func_800BA334();
            break;
        case 4:
            func_800BA468();
            break;
        case 5:
            func_800BA5A8();
            break;
        default:
            break;
    }
}

void _stub1() {
}

void func_800BA734(void) {
    gObjects[gCurrentParsedObject].actionState = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
    gObjects[gCurrentParsedObject].damageState = 0;
}

void func_800BA7C0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.5f;
        sp24->unk40 = 270.0f;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0xF4, &D_80117E20);
        func_800272E8(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->unkB2 -= 1;
    if (sp24->unkB2 <= 0) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
    }
}

void func_800BA904(void) {
    func_8002B114(gCurrentParsedObject);
}

void func_800BA934(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_800BA7C0();
            break;
        case 2:
            func_800BA904();
            break;
        default:
            break;
    }
}

s16 func_800BA9C8(struct ObjectStruct* arg0, s16 arg1, UNUSED s32 arg2) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp22 = func_80027464(1, &D_80113AE4, arg0->Pos.x, arg0->Pos.y + 390.0f, arg0->Pos.z, arg0->unk3C);
    if (sp22 != -1) {
        func_80026F10(arg1, sp22);
        sp24 = &gObjects[sp22];
        sp24->Rot.y = arg0->unk3C;
        sp24->unk40 = arg0->unk40;
        sp24->unk3C = arg0->unk3C;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->damageState = 1;
        sp24->actionState = 1;
        sp24->unkB2 = 0x80;
        sp24->unk132 = 0;
        sp24->damageState = 1;
        sp24->unk100 = -1;
        func_80029C40((s32) sp22);
        func_80029D04((s32) sp22);
    }
    return sp22;
}

void func_800BAB44(void) {
    s8 sp27;

    sp27 = func_80027464(1, &D_80113AF0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp27 != -1) {
        gObjects[sp27].actionState = 1;
        gObjects[sp27].unkA8 = 4;
        gObjects[sp27].unk132 = 0;
        gObjects[sp27].damageState = 1;
        gObjects[sp27].unk100 = -1;
    }
}

void func_800BAC94(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 5;
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].damageState = 0;
    }
}

void func_800BAD34(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 35;
        if (sp1C->unkA8 == 4) {
            sp1C->unkA6 = 0;
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkA6 -= 1;
    if ((sp1C->unkA6 <= 0) && (func_8002A3A8(gCurrentParsedObject, 720.0f) != 0) &&
        (func_8002A2EC(gCurrentParsedObject, 360.0f) != 0)) {
        sp1C->actionState = sp1C->unkA8;
        sp1C->unk132 = 0;
    }
}

void func_800BAE94(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 24.0f;
        sp24->unk48 = 0.0f;
        sp24->unk3C = 0.0f;
        sp24->unkA6 = 0x1E;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((f64) sp24->Scale.x < 2.0) {
        sp24->Scale.x = (f32) ((f64) sp24->Scale.x + 0.05);
        sp24->Pos.y = (f32) ((f64) sp24->Pos.y + 2.5);
    }

    sp24->Scale.y = sp24->Scale.z = sp24->Scale.x;
    if (sp24->unkA6 < 9) {
        sp24->unk44 -= 1.0f;
    }
    sp24->unkA6 -= 1;
    if (sp24->unkA6 <= 0) {
        sp24->actionState = 3;
        sp24->unk132 = 0;
    }
}

void func_800BB080(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 24.0f;
        sp24->unk48 = 0.0f;
        sp24->unk3C = 180.0f;
        sp24->unkA6 = 0x1E;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((f64) sp24->Scale.x >= 1.0) {
        sp24->Scale.x = (f32) ((f64) sp24->Scale.x - 0.05);
        sp24->Pos.y = (f32) ((f64) sp24->Pos.y - 2.5);
    }

    sp24->Scale.y = sp24->Scale.z = sp24->Scale.x;
    if (sp24->unkA6 < 9) {
        sp24->unk44 -= 1.0f;
    }
    sp24->unkA6 -= 1;
    if (sp24->unkA6 <= 0) {
        sp24->actionState = 1;
        sp24->unk132 = 0;
    }
}

void func_800BB270(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkB2 = 0x82;
        func_800BBAD4(sp1C, gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkB2 -= 1;
    if (sp1C->unkB2 <= 0) {
        sp1C->actionState = 1;
        sp1C->unk132 = 0;
    }
}

void func_800BB388(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->damageState = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8007EDF4(sp1C->Pos.x, sp1C->Pos.y, sp1C->Pos.z, 5.0f);
    func_8002B114(gCurrentParsedObject);
}

void func_800BB480(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].actionState;
    switch (sp1C) {
        case 1:
            func_800BAD34();
            break;
        case 2:
            func_800BAE94();
            break;
        case 3:
            func_800BB080();
            break;
        case 4:
            func_800BB270();
            break;
        case 5:
            func_800BB388();
            break;
        default:
            break;
    }
}

void func_800BB55C(void) {
    s8 sp27;

    sp27 = func_80027464(1, &D_80113B08, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);
    if (sp27 != -1) {
        gObjects[sp27].actionState = 1;
        gObjects[sp27].unkA8 = 2;
        gObjects[sp27].unk132 = 0;
        gObjects[sp27].damageState = 1;
        gObjects[sp27].unk100 = -1;
    }
}

void stub() {
}

void func_800BB6BC(void) {
    gObjects[gCurrentParsedObject].actionState = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
    gObjects[gCurrentParsedObject].damageState = 0;
}

void func_800BB748(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 16.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkB2 = 0x84;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((f64) sp2C->Scale.x < 2.0) {
        sp2C->Scale.x = (f32) ((f64) sp2C->Scale.x + 0.01);
    }
    sp2C->Scale.y = sp2C->Scale.z = sp2C->Scale.x;
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
        sp2C->unkB2 = 0;
    }
    sp2C->unkB2 -= 1;
    if (sp2C->unkB2 <= 0) {
        sp2C->actionState = 2;
        sp2C->unk132 = 0;
    }
}

void func_800BB91C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkB2 -= 1;
    if (sp1C->unkB2 <= 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800BBA0C(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
            case 1:
                func_800BB748();
                break;
            case 2:
                func_800BB91C();
                break;
            default:
                break;
        }
    }
}

s16 func_800BBAD4(struct ObjectStruct* arg0, s16 arg1, UNUSED s32 arg2) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp22 = func_80027464(1, &D_80113B68, arg0->Pos.x, arg0->Pos.y + 20.0f, arg0->Pos.z, arg0->unk3C);
    if (sp22 != -1) {
        func_80026F10(arg1, sp22);
        sp24 = &gObjects[sp22];
        sp24->Rot.y = arg0->unk3C;
        sp24->unk40 = arg0->unk40;
        sp24->unk3C = arg0->unk3C;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->damageState = 1;
        sp24->damageState = 0;
        sp24->unk100 = -1;
        sp24->unk102 = 0;
        sp24->unk103 = 1;
        sp24->Scale.x = 0.25f;
        sp24->Scale.y = 0.25f;
        sp24->Scale.z = 0.25f;
        sp24->actionState = 1;
        sp24->unkB2 = 0x84;
        sp24->unk132 = 0;
        func_80029C40((s32) sp22);
        func_80029D04((s32) sp22);
    }
    return sp22;
}

void func_800BBCA4(void) {
    s8 sp27;

    sp27 = func_80027464(9, &D_80113BB0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp27 != -1) {
        gObjects[sp27].unkAE = D_80165100->unkA;
        gObjects[sp27].unkB0 = D_80165100->unkC;
        gObjects[sp27].unk3C = (f32) D_80165100->unkE;
        gObjects[sp27].unk44 = 0.0f;
        gObjects[sp27].unk48 = 0.0f;
        gObjects[sp27].unk102 = 0;
        gObjects[sp27].damageState = -1;
        gObjects[sp27].Scale.x = 1.2f;
        gObjects[sp27].actionState = 1;
        gObjects[sp27].unk132 = 0;
        gObjects[sp27].unkB2 = Math_Random(0x10) + 0x20;
        func_8001ABF4((s32) sp27, 0, 0, &D_80117E48);
        func_800BBF30(sp27);
    }
}

s8 func_800BBF30(s8 arg0) {
    s8 sp1F;
    s8 sp1E;

    for (sp1E = 0; sp1E < 8; sp1E++) {
        sp1F = gObjects[arg0].unkE8[sp1E];
        gObjects[sp1F].actionState = 1;
        gObjects[sp1F].unk132 = 0;
        gObjects[sp1F].unkA8 = gObjects[arg0].unkE6[sp1E];
        gObjects[sp1F].unkAA = 1;
        gObjects[sp1F].damageState = -1;
        func_8001ABF4((s32) sp1F, 0, 0, &D_80117E48);
        if (sp1E == 0) {
            gObjects[sp1F].unkA8 = (s16) arg0;
        }
    }
    gObjects[arg0].unkA8 = (s16) sp1F;
    return sp1E;
}

void func_800BC124(void) {
}

void func_800BC134(UNUSED s8 arg0) {
}

void func_800BC148(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->Pos.x = sp1C->unk50;
        sp1C->Pos.y = sp1C->unk54;
        sp1C->Pos.z = sp1C->unk58;
        sp1C->unk40 = 45.0f;
        sp1C->unkA6 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkA6 += 1;
    if (sp1C->unkA6 >= sp1C->unkB2) {
        sp1C->actionState = 2;
        sp1C->unk132 = 0;
    }
    if (!(sp1C->unkA6 & 3)) {
        func_800BC86C(1);
    }
}

void func_800BC2C8(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0;
        func_800BC86C(1);
        func_800175F0(gCurrentParsedObject, 0, 1, -1, 0);
    }
    if (sp2C->unkA6 == 8) {
        sp2C->unk44 = (f32) sp2C->unkAE;
        sp2C->unk48 = (f32) sp2C->unkB0;
        sp2C->unk132 = 2;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp2C->unk132 == 2) {
        if (sp2C->Vel.y > 0.0f) {
            if ((f64) sp2C->Scale.x < 2.0) {
                sp2C->Scale.x = (f32) ((f64) sp2C->Scale.x + 0.025);
            }
        } else if ((f64) sp2C->Scale.x > 1.2) {
            sp2C->Scale.x = (f32) ((f64) sp2C->Scale.x - 0.025);
        }

        sp2C->Scale.y = sp2C->Scale.z = sp2C->Scale.x;

        sp2C->unk40 = func_80015538(sp2C->unk40, 8.0f);
        if (sp2C->unk40 >= 270.0f) {
            sp2C->unk40 = 270.0f;
        }
        if (sp2C->unkA6 >= 0x1C) {
            if (sp2C->Pos.y < (sp2C->unk54 - 200.0f)) {
                sp2C->unk44 = 0.0f;
                sp2C->unk48 = 0.0f;
            }
            if ((sp2C->unk44 == 0.0f)) {
                if ((gObjects[sp2C->unkA8].Pos.y < sp2C->unk54)) {
                    sp2C->actionState = 1;
                    sp2C->unk132 = 0;
                }
            }
        }
        if (!(sp2C->unkA6 & 3)) {
            func_800BC86C(0);
        }
    }
    sp2C->unkA6 += 1;
}

void func_800BC684(void) {
    struct ObjectStruct* sp1C;
    s8 sp1B;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    for (sp1B = 0; sp1B < 8; sp1B++) {
        func_800BC134(sp1B);
    }
    func_8002B0E4(gCurrentParsedObject);
}

s8 func_800BC774(s8 arg0) {
    struct ObjectStruct* sp4;
    s8 sp3;

    sp4 = &gObjects[gCurrentParsedObject];
    sp3 = 0;
    if (sp4->unkE8[arg0] != -1) {
        sp3 = 1;
    }
    return sp3;
}

s8 func_800BC7F0(void) {
    s8 sp27;
    s8 sp26;

    sp27 = 0;
    for (sp26 = 0; sp26 < 8; sp26++) {
        sp27 += func_800BC774(sp26);
    }
    return sp27;
}

s8 func_800BC86C(s8 arg0) {
    UNUSED struct ObjectStruct* sp24;
    s8 sp23;
    s8 sp22;

    sp23 = 0;
    sp24 = &gObjects[gCurrentParsedObject];
    for (sp22 = 8; sp22 > 0; sp22--) {
        sp23 += func_800BC91C(sp22 - 1, arg0);
    }
    return sp23;
}

s16 func_800BC91C(s16 arg0, s8 arg1) {
    struct ObjectStruct* spC;
    struct ObjectStruct* sp8;
    s8 sp7;

    spC = &gObjects[gCurrentParsedObject];
    sp7 = spC->unkE8[arg0];
    if (sp7 != -1) {
        sp8 = &gObjects[sp7];
        spC = &gObjects[sp8->unkA8];
        if (arg1 == 1) {
            sp8->Pos.x = spC->Pos.x;
            sp8->Pos.y = spC->Pos.y;
            sp8->Pos.z = spC->Pos.z;
        }

        sp8->Rot.y = spC->unk3C;
        sp8->unk3C = spC->unk3C;
        sp8->unk40 = spC->unk40;
        sp8->unk44 = spC->unk44;
        sp8->unk48 = spC->unk48;
        sp8->Scale.x = spC->Scale.x;
        sp8->Scale.y = spC->Scale.y;
        sp8->Scale.z = spC->Scale.z;
    } else {
    }
    return ~(sp7 != 0) ? 0 : 1;
}

void func_800BCB04(void) {
    s32 sp24;

    sp24 = gObjects[gCurrentParsedObject].actionState;
    switch (sp24) { /* irregular */
        case 1:
            func_800BC148();
            break;
        case 2:
            func_800BC2C8();
            break;
        case 3:
            func_800BC684();
            break;
        default:
            break;
    }
}

void func_800BCBC0(void) {
    return;
    return;
}

void func_800BCBE0(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800BCC10(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];

    if ((sp1C->unkE6[0] != -1)) {
        if ((sp1C->unkAA == 1)) {
            func_80029C40(gCurrentParsedObject);
            func_80029D04(gCurrentParsedObject);
        }
    }
}

void func_800BCCAC(void) {
    UNUSED s8 sp27;

    if (func_80026260(D_8016519C) == 0) {
        sp27 = func_80027464(1, &D_80113C1C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                             (f32) D_80165100->unk8);
    }
}

void func_800BCD40(void) {
}

void func_800BCD50(void) {
}

void func_800BCD60(void) {
    s8 sp2F;

    sp2F = func_80027464(8, &D_80113E50, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    gObjects[sp2F].unk102 = 0;
    gObjects[sp2F].actionState = 2;
    gObjects[sp2F].unk132 = 0;
    func_8001ABF4((s32) sp2F, 0, 0, &D_80117E48);
    gObjects[sp2F].Scale.x = 0.6f;
    gObjects[sp2F].Scale.y = gObjects[sp2F].Scale.z = gObjects[sp2F].Scale.x;
    func_8001BB34((s32) sp2F, 1);
    func_800BCF08(sp2F);
}

s8 func_800BCF08(s8 arg0) {
    s8 sp27;
    s8 sp26;

    for (sp26 = 0; sp26 < 7; sp26++) {
        sp27 = (s8) gObjects[arg0].unkE8[sp26];
        gObjects[sp27].actionState = 1;
        gObjects[sp27].unk132 = 0;
        gObjects[sp27].unkA8 = gObjects[arg0].unkE6[sp26];
        gObjects[sp27].unkAA = 1;
        func_8001ABF4((s32) sp27, 0, 0, &D_80117E48);
        gObjects[sp27].Scale.x = (sp26 + 1) * 0.200000000000000011 + 0.6000000238418579;
        gObjects[sp27].Scale.y = gObjects[sp27].Scale.z = gObjects[sp27].Scale.x;
        if (sp26 == 0) {
            gObjects[sp27].unkA8 = (s16) arg0;
        }
    }
    return sp26;
}

void func_800BD164(void) {
}

void func_800BD174(UNUSED s8 arg0) {
}

void func_800BD188(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 30.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unk3C = 0.0f;
        sp1C->unk40 = 0.0f;
        sp1C->unkA6 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->Rot.y = func_80015538(sp1C->Rot.y, 20.0f);
    if (!(sp1C->unkA6 & 1)) {
        func_800BD4B0();
    }
    sp1C->unkA6++;
}

void func_800BD2C8(void) {
    struct ObjectStruct* sp1C;
    s8 sp1B;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    for (sp1B = 0; sp1B < 7; sp1B++) {
        func_800BD174(sp1B);
    }
    func_8002B0E4(gCurrentParsedObject);
}

s8 func_800BD3B8(s8 arg0) {
    struct ObjectStruct* spC;
    UNUSED char pad[0x3];
    s8 sp7;

    spC = &gObjects[gCurrentParsedObject];
    sp7 = 0;
    if (spC->unkE8[arg0] != -1) {
        sp7 = 1;
    }
    return sp7;
}

s8 func_800BD434(void) {
    s8 sp27;
    s8 sp26;

    sp27 = 0;

    for (sp26 = 0; sp26 < 7; sp26++) {
        sp27 += func_800BD3B8(sp26);
    }

    return sp27;
}

s8 func_800BD4B0(void) {
    UNUSED struct ObjectStruct* sp24;
    s8 sp23;
    s8 sp22;

    sp23 = 0;
    sp24 = &gObjects[gCurrentParsedObject];
    for (sp22 = 7; sp22 > 0; sp22--) {
        sp23 += func_800BD558(sp22 - 1);
    }
    return sp23;
}

s16 func_800BD558(s16 arg0) {
    struct ObjectStruct* sp34;
    struct ObjectStruct* sp30;
    s8 sp2F;
    f32 sp28;

    sp34 = &gObjects[gCurrentParsedObject];
    sp2F = (s8) sp34->unkE8[arg0];
    if (sp2F != -1) {
        sp30 = &gObjects[sp2F];
        sp34 = &gObjects[sp30->unkA8];
        sp28 = func_80015538(sp34->Rot.y, (f32) ((arg0 * 20) + 20));
        sp30->Vel.x = sinf((f32) ((f64) sp28 * DEG_TO_RAD)) * 65.0f;
        sp30->Vel.y = cosf((f32) ((f64) sp28 * DEG_TO_RAD)) * 65.0f;
        sp30->Vel.z = (f32) ((arg0 * 16) + 16);
        sp30->Pos.x = sp34->Pos.x + sp30->Vel.x;
        sp30->Pos.y = sp34->Pos.y + sp30->Vel.y;
        sp30->Pos.z = sp34->Pos.z - sp30->Vel.z;
        sp30->Rot.y = sp34->Rot.y;
        sp30->unk3C = sp34->unk3C;
        sp30->unk40 = sp34->unk40;
        sp30->unk44 = sp34->unk44;
        sp30->unk48 = sp34->unk48;
    }
    return ~(sp2F != 0) ? 0 : 1; // lsb?
}

void func_800BD7CC(void) {
    s32 sp24;

    sp24 = (s32) gObjects[gCurrentParsedObject].actionState;
    switch (sp24) { /* irregular */
        case 2:
            func_800BD188();
            break;
        case 3:
            func_800BD2C8();
            break;
        default:
            break;
    }
}

void func_800BD86C(void) {
    s8 sp2F;

    sp2F = func_80027464(1, &D_80113D9C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2F != -1) {
        gObjects[sp2F].actionState = 1;
        gObjects[sp2F].unkA8 = 1;
        gObjects[sp2F].unkAA = 0;
        gObjects[sp2F].unkAE = 3;
        gObjects[sp2F].unkB0 = 0x1E0;
        gObjects[sp2F].unkB6 = 0x190;
        gObjects[sp2F].unkB8 = 0;
        gObjects[sp2F].unk132 = 0;
        func_8001C0EC((s32) sp2F, 0, 0, 0x114, &D_80117E64);
        func_8001ABF4((s32) sp2F, 0, 0, &D_80117EA8);
        if (D_80165100->unkA != 0) {
            gObjects[sp2F].unkAA = 1;
            gObjects[sp2F].unkAE = IABS(D_80165100->unkC);
            gObjects[sp2F].unkB0 = IABS(D_80165100->unkE) * 0x3C;
        }
    }
}

void func_800BDB8C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if ((D_80177A64 == 1)) {
        sp24->damageState = -1;
        sp24->actionState = 8;
        sp24->unk132 = 0;

        if (sp24->unk106 == 0xA || sp24->unk106 == 0x11) {
            sp24->unk100 = (s16) (sp24->unk100 + 1);
            sp24->actionState = 6;
            func_800175F0(gCurrentParsedObject, 0, 0x6D, -1, 0);
            if (sp24->unkE8[0] == -1) {
                func_800BF3A4(sp24, gCurrentParsedObject, 0);
            } else {
                func_800BF3A4(sp24, gCurrentParsedObject, 1);
            }
        }
    }

    if (D_80177A64 == 0) {
        sp24->damageState = 0;
        sp24->actionState = 7;
        sp24->unk132 = 0;
    }
}

void func_800BDCF4(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp1C->unkAE == 0) {
        sp1C->Rot.y = func_8002A46C(gCurrentParsedObject);
    } else if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp1C->Rot.y = sp1C->unk3C;
    }
    sp1C->unkA6 += 1;
    if (sp1C->unkA6 == 0xA) {
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117EA8);
    }
    if (sp1C->unkA6 >= 0x28) {
        if (sp1C->unkAA != 0) {
            sp1C->actionState = 0xB;
            sp1C->unk132 = 0;
        } else {
            sp1C->actionState = 2;
            sp1C->unk132 = 0;
        }
    }
}

void func_800BDEE0(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 0.0f;
        sp34->unk48 = 0.0f;
        sp34->unkD4 = func_80015538(sp34->unk3C, Math_Random(-0x5A) + 3);
        sp34->unkB4 = func_8002A800(sp34->unkD4, sp34->unk3C, 4.0f);
    }
    sp34->Rot.y = sp34->unk3C;
    sp34->unkB6 -= 1;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp34->actionState = 3;
        sp34->unk132 = 0;
        return;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_8002A800(sp34->unk3C, sp34->unkD4, 4.0f) == 0) {
        sp34->actionState = 3;
        sp34->unk132 = 0;
        sp34->Rot.y = sp34->unk3C;
        return;
    }
    sp30 = (f32) sp34->unkB4 * 1.5f;
    sp34->unk3C = func_80015538(sp34->unk3C, sp30);
    if (func_80029018(gCurrentParsedObject, 1U, 240.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->unkD4 = func_80015538(sp34->unkD4, (f32) (Math_Random(8) * sp34->unkB4));
    }
}

void func_800BE14C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 3.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0x1A4;
        if (sp24->unkA8 == 1) {
            sp24->unkA6 = 0x1E0;
        }
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117EA8);
    }
    sp24->unkA6 = (s16) (s32) ((f32) sp24->unkA6 - sp24->unk44);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
        sp24->Rot.y = sp24->unk3C;
        return;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 240.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
        sp24->Rot.y = sp24->unk3C;
    } else {
        func_800C00F4(sp24, 0.0f);
    }
    sp24->unkB6 -= 1;
    if (sp24->unkB6 <= 0) {
        sp24->actionState = 5;
        sp24->unk132 = 0;
    }
    if (sp24->unkA6 <= 0) {
        sp24->actionState = 5;
        sp24->unk132 = 0;
    }
}

void func_800BE3B4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkB6 = 0x190;
        if (sp24->unkA8 == 1) {
            func_8001C0EC(gCurrentParsedObject, 0, 3, 0x114, &D_80117E64);
            sp24->unkA8 = 2;
        } else {
            func_8001C0EC(gCurrentParsedObject, 0, 2, 0x114, &D_80117E64);
            sp24->unkA8 = 3;
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 1;
        sp24->unk132 = 0;
        if (sp24->unkA8 == 3) {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0x114, &D_80117E64);
            sp24->unkA8 = 1;
        } else {
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0x114, &D_80117E64);
            sp24->unkA8 = 0;
        }
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117EA8);
        sp24->actionState = 4;
        sp24->unk132 = 0;
    }
}

void func_800BE5CC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = (f32) sp24->unkAE;
        sp24->unk48 = 0.0f;
        if (sp24->unkB8 == 0) {
            sp24->unkBA = sp24->unkB0;
            sp24->unk3C = func_80015538(360.0f, (f32) (sp24->unkAA * 0x5A));
            sp24->unkB8 = 1;
        }
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117EA8);
    }
    sp24->unkBA = (s16) (s32) ((f32) sp24->unkBA - sp24->unk44);
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->unkAA = -sp24->unkAA;
        sp24->unk3C = func_80015538(360.0f, (f32) (sp24->unkAA * 0x5A));
    } else {
        if ((sp24->Pos.x <= (sp24->unk50 - sp24->unkB0)) || ((sp24->unk50 + sp24->unkB0) < sp24->Pos.x)) {
            sp24->unkAA = -sp24->unkAA;
            sp24->unk3C = func_80015538(360.0f, (f32) (sp24->unkAA * 0x5A));
        }
    }
    if (sp24->unkBA <= 0) {
        sp24->actionState = 5;
        sp24->unkAA = -sp24->unkAA;
        sp24->unkB8 = 0;
        sp24->unk132 = 0;
    }
    if (sp24->unkAE == 0) {
        sp24->Rot.y = func_8002A46C(gCurrentParsedObject);
    } else {
        sp24->Rot.y = sp24->unk3C;
    }
}

void func_800BE928(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 0x2000;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117EC4);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    sp1C->Rot.y = sp1C->unk3C;
    if ((sp1C->unk132 == 1) && ((func_8002A560(gCurrentParsedObject, 8.0f) == 0) || (sp1C->unkAE == 0))) {
        func_8001BBDC(gCurrentParsedObject, 1);
        func_800BFD94(sp1C, gCurrentParsedObject, 2);
        sp1C->unk132 = 2;
        sp1C->unkA6 = 0xC;
    }
    sp1C->unkA6 -= 1;
    if ((sp1C->unk132 == 2) && (sp1C->unkA6 <= 0)) {
        sp1C->actionState = 1;
        sp1C->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}

void func_800BEB10(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        sp24->damageState = -1;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkA6 >= 0xF0) {
        if (sp24->unkA6 & 1) {
            sp24->Rot.z += 4.0f;
        } else {
            sp24->Rot.z -= 4.0f;
        }
    }
    sp24->unkA6 += 1;
    if (sp24->unkA6 >= 0x12C) {
        func_8001BBDC(gCurrentParsedObject, 0);
        if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
            func_8001BBDC(gCurrentParsedObject, 1);
            if (sp24->unkA8 >= 2) {
                if (sp24->unkA8 == 3) {
                    func_8001C0EC(gCurrentParsedObject, 0, 0, 0x114, &D_80117E64);
                    sp24->unkA8 = 1;
                } else {
                    func_8001C0EC(gCurrentParsedObject, 0, 1, 0x114, &D_80117E64);
                    sp24->unkA8 = 0;
                }
            }
            sp24->actionState = 1;
            sp24->unk132 = 0;
            sp24->Rot.z = 0.0f;
            sp24->damageState = 1;
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117EA8);
        }
    }
}

void func_800BEDB0(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    s16 sp2E;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk48 = 0.0f;
        func_8001BB04(gCurrentParsedObject, 0);
        func_80029EF8(gCurrentParsedObject, sp34->unk48, 0.98f);
    }
    func_80029C40(gCurrentParsedObject);
    sp30 = sp34->Vel.y;
    if (func_80029018(gCurrentParsedObject, 3U, 140.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Vel.y = sp30;
    }
    sp2E = func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f);
    if (sp2E == 1) {
        sp34->actionState = 3;
        sp34->unk132 = 0;
        if (D_80177740[D_801776E0 & 1] == 0xF5) {
            sp34->actionState = 5;
            sp34->unk132 = 0;
        }
    }
    sp34->Vel.y = MIN_CLAMP(sp34->Vel.y, 48.0f);
    sp34->Rot.y = sp34->unk3C;
}

void func_800BEFF0(void) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0x14;
        sp24->damageState = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x114, &D_80117E64);
        func_8001BB34(gCurrentParsedObject, 0);
        sp22 = sp24->unkE8[0];
        if (sp22 != -1) {
            func_800281A4(gCurrentParsedObject, 0);
            func_8002B0E4((s32) sp22);
        }
        sp22 = sp24->unkE8[1];
        if (sp22 != -1) {
            func_800281A4(gCurrentParsedObject, 1);
            func_8002B0E4((s32) sp22);
        }
        sp22 = sp24->unkE8[2];
        if (sp22 != -1) {
            func_800281A4(gCurrentParsedObject, 2);
            func_8002B0E4((s32) sp22);
        }
    }
    func_8002A8B4(gCurrentParsedObject, 1.5f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->unkA6 -= 1;
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (sp24->unkA6 <= 0) {
        func_8007EDF4(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 3.0f);
        func_8002B114(gCurrentParsedObject);
    }
}

void func_800BF240(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->damageState = 0x50;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8001BB34(gCurrentParsedObject, !(sp24->damageState & 1));
    if (sp24->damageState == 1) {
        sp24->damageState = 1;
        sp24->actionState = 1;
        sp24->unk132 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}

void func_800BF394(void) {
}

s16 func_800BF3A4(struct ObjectStruct* arg0, s16 arg1, s16 arg2) {
    struct ObjectStruct* sp2C;
    s16 ret;

    if (arg0->unkA8 == 0) {
        ret = func_80027C00((s32) arg1, (s32) arg2, &D_80113DB4, arg0->Pos.x, arg0->Pos.y, arg0->Pos.z, 0.0f);
    } else {
        ret = func_80027C00((s32) arg1, (s32) arg2, &D_80113DA8, arg0->Pos.x, arg0->Pos.y, arg0->Pos.z, 0.0f);
    }

    if (ret != -1) {
        sp2C = &gObjects[ret];
        ;
        sp2C->unkA8 = arg0->unkA8;
        sp2C->Pos.x = arg0->Pos.x;
        sp2C->Pos.y = arg0->Pos.y;
        sp2C->Pos.z = arg0->Pos.z;
        sp2C->unk3C = arg0->unk3C;
        sp2C->unk40 = arg0->unk40;
        sp2C->actionState = 1;
        sp2C->unkB2 = 0x12C;
        sp2C->unk132 = 0;
        sp2C->damageState = -1;
        if (arg0->unkA8 == 0) {
            func_8001C0EC((s32) ret, 3, 0, 0x116, &D_80117EE8);
        } else {
            func_8001C0EC((s32) ret, 3, 0, 0x115, &D_80117EE0);
        }
        func_80029C40((s32) ret);
        func_80029D04((s32) ret);
        func_800281A4((s32) arg1, (s32) arg2);
    }
    return ret;
}

void func_800BF5D0(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].actionState;
    switch (sp1C) {
        case 1:
            func_800BDCF4();
            break;
        case 2:
            func_800BDEE0();
            break;
        case 3:
            func_800BE14C();
            break;
        case 5:
            func_800BE3B4();
            break;
        case 4:
            func_800BE928();
            break;
        case 6:
            func_800BEB10();
            break;
        case 7:
            func_800BEFF0();
            break;
        case 8:
            func_800BF240();
            break;
        case 9:
            func_800BF394();
            break;
        case 10:
            func_800BEDB0();
            break;
        case 11:
            func_800BE5CC();
            break;
        default:
            break;
    }
}

void _stub2() {
}

void func_800BF71C() {
}

void func_800BF72C(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800BF75C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkB2 = 0x12C;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkB2 -= 1;
    if ((sp1C->unk132 == 1) && (func_8001B44C(gCurrentParsedObject, 3) != 0)) {
        func_8001BBDC(gCurrentParsedObject, 1);
        sp1C->unk132 = 2;
    }
    if (sp1C->unkB2 <= 0) {
        sp1C->actionState = 2;
        sp1C->unk132 = 0;
    }
}

void func_800BF8AC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        if (sp24->unkA8 == 0) {
            func_8001C0EC(gCurrentParsedObject, 3, 1, 0x116, &D_80117EE8);
        } else {
            func_8001C0EC(gCurrentParsedObject, 3, 1, 0x115, &D_80117EE0);
        }
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 3) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_800BFA14(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unkE6[0] == -1) {
        switch (sp24->actionState) { /* irregular */
            case 1:
                func_800BF75C();
                break;
            case 2:
                func_800BF8AC();
                break;
            default:
                break;
        }
    }
}

void func_800BFAD0(void) {
    return; // What??
    return;
}

void func_800BFAF0(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800BFB20(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unkE6[0] == -1) {
        if (sp24->unk132 == 0) {
            sp24->unk132 = 1;
            sp24->unk44 = 0.0f;
            sp24->unk48 = 0.0f;
            sp24->unk40 = 0.0f;
            sp24->unkA6 = 0;
            sp24->damageState = 0;
            func_8001BBDC(gCurrentParsedObject, 1);
            func_8001C0EC(gCurrentParsedObject, 3, 0, 0x117, &D_80117EF0);
        }
        if (sp24->unkA6 == 0xE) {
            sp24->unk44 = 10.0f;
            sp24->unk132 = 2;
            func_80017664(gCurrentParsedObject, 0, 0x22, -1, 0);
            func_8001BBDC(gCurrentParsedObject, 0);
        }
        if (sp24->unkA6 == 0x14) {
            sp24->damageState = -1;
        }
        if (sp24->unkA6 == 0x28) {
            sp24->damageState = 0;
        }
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
        sp24->Rot.y = sp24->unk3C;
        sp24->unkA6 += 1;
        if (func_80029018(gCurrentParsedObject, 3U, 0.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_8002B0E4(gCurrentParsedObject);
            return;
        }
        if (func_8001B44C(gCurrentParsedObject, 3) != 0) {
            func_8002B0E4(gCurrentParsedObject);
            return;
        }
    }
}

s16 func_800BFD94(struct ObjectStruct* arg0, s16 arg1, UNUSED s16 arg2) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp22 = func_80027464(1, &D_80113DC0, arg0->Pos.x, arg0->Pos.y, arg0->Pos.z, arg0->unk3C);
    if (sp22 != -1) {
        func_80026F10(arg1, sp22);
        sp24 = &gObjects[sp22];
        sp24->Pos.y = arg0->Pos.y + (f32) (arg0->unkA8 * 0x73) + 90.0f;
        sp24->Rot.y = arg0->unk3C;
        sp24->unk40 = arg0->unk40;
        sp24->unk3C = arg0->unk3C;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->damageState = 0;
        sp24->actionState = 1;
        sp24->unk132 = 0;
        func_80029C40((s32) sp22);
        func_80029D04((s32) sp22);
    }
    return sp22;
}

s8 func_800BFF20(struct ObjectStruct* arg0, f32 arg1, f32 arg2) {
    s8 sp27;

    sp27 = func_8002A800(arg0->unk3C, arg1, FABS(arg2));
    arg0->unk3C = func_80015538(arg0->unk3C, arg2);
    return sp27;
}

s8 func_800BFFCC(struct ObjectStruct* arg0, s8 arg1, f32 arg2, f32 arg3) {
    s8 sp27;

    if (arg1 == 0) {
        sp27 = func_8002A800(arg0->unk3C, arg2, FABS(arg3));
        arg0->unk3C = func_80015538(arg0->unk3C, arg3);
    } else {
        sp27 = func_8002A800(arg0->unk40, arg2, FABS(arg3));
        arg0->unk40 = func_80015538(arg0->unk40, arg3);
    }
    return sp27;
}

s8 func_800C00F4(struct ObjectStruct* arg0, f32 arg1) {
    f32 sp2C;
    f32 sp28;
    s8 sp27;

    sp27 = func_800294F0(gCurrentParsedObject, &sp2C, &sp28, arg0->Vel.x, arg0->Vel.y, arg0->Vel.z);
    if (sp27 != 0) {
        arg0->Pos.y = sp28 + arg1;
    } else {
        arg0->Pos.y = sp2C + arg1;
    }
    return sp27;
}

s32 func_800C0194(struct UnkStructSTCG* arg0, f32 arg1) {
    f32 sp2C;
    f32 sp28;
    s8 sp27;

    sp27 = func_800295C0(gCurrentParsedObject, &sp2C, &sp28, arg0->Unk24, arg0->Unk28, arg0->Unk2C);
    if (sp27 != 0) {
        return (s32) ((sp28 + arg1) - arg0->Unk4);
    }
    return (s32) ((sp2C + arg1) - arg0->Unk4);
}
