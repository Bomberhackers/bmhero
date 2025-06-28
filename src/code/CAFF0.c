#include <ultra64.h>

void func_800D8AD0(void) {
    s32 sp24 = func_80027464(1, &D_80114270, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);

    if (sp24 != -1) {
        gObjects[sp24].unkB6 = gObjects[sp24].Pos.x;
        gObjects[sp24].unkB8 = gObjects[sp24].Pos.y;

        if (D_80165100->unkA == 0) {
            D_80165100->unkA = 120;
        }
        gObjects[sp24].unkBA = D_80165100->unkA;
        if (D_80165100->unkC == 0) {
            D_80165100->unkC = 3;
        }
        gObjects[sp24].unkBC = D_80165100->unkC;
        if (D_80165100->unkE == 0) {
            D_80165100->unkE = 60;
        }
        gObjects[sp24].unkA6 = D_80165100->unkE;

        gObjects[sp24].Pos.x = gObjects[sp24].unkB6 + gObjects[sp24].unkBA * sinf(gObjects[sp24].unkA6 * DEG_TO_RAD);
        gObjects[sp24].Pos.y = gObjects[sp24].unkB8 + gObjects[sp24].unkBA * cosf(gObjects[sp24].unkA6 * DEG_TO_RAD);
    }
}

void func_800D8E30(void) {
}

void func_800D8E40(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118B38);
    }

    sp1C->unkA6 = func_80015538(sp1C->unkA6, sp1C->unkBC);
    sp1C->Pos.x = sinf(sp1C->unkA6 * DEG_TO_RAD) * (f32) sp1C->unkBA + (f32) sp1C->unkB6;
    sp1C->Pos.y = cosf(sp1C->unkA6 * DEG_TO_RAD) * (f32) sp1C->unkBA + (f32) sp1C->unkB8;
}

void func_800D8FD0(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1: {
            func_800D8E40();
            break;
        }
        default:
            break;
    }
}

void func_800D9044(void) {
    func_80027464(1, &D_8011427C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800D90BC(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 5;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800D9134(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = 0xA;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x184, &D_80118BDC);
        func_8001BBDC(gCurrentParsedObject, 1);
    }

    if (obj->unkA6 == 0) {
        if (func_8002A1FC(gCurrentParsedObject, 960.0f) != 0) {
            if (gPlayerObject->Pos.y - obj->Pos.y > -360.0f && gPlayerObject->Pos.y - obj->Pos.y < 360.f) {
                obj->unkA4 = 2;
                obj->unk132 = 0;
            }
        }
    } else {
        obj->unkA6 -= 1;
    }
}

void func_800D9298(void) {
    struct ObjectStruct* obj;
    f32 sp18;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = (s16) (s32) func_8002A46C(gCurrentParsedObject);
        obj->unkA8 = func_8002A560(gCurrentParsedObject, 2.0f);
    }
    sp18 = func_80015538((f32) obj->unkA6, -obj->unk3C);
    if ((sp18 <= 7.0f) || (353.0f <= sp18)) {
        obj->unkA4 = 3;
        obj->unk132 = 0;
    } else {
        obj->unk3C = func_80015538(obj->unk3C, (f32) (obj->unkA8 * 0xE));
        obj->Rot.y = obj->unk3C;
    }
}

void func_800D9420(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
        sp20 = func_80027464(1, &D_80114288, sp24->Pos.x, sp24->Pos.y + 100.0f, sp24->Pos.z, sp24->Rot.y);
        sp24->unkA4 = 4;
        sp24->unk132 = 0;
    }
}

void func_800D9520(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unkA6 = 0x14;
    }
    if (sp24->unkA6 == 0) {
        sp24->unkA4 = 1;
        sp24->unk132 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x184, &D_80118BDC);
        func_8001BBDC(gCurrentParsedObject, 1);
    } else {
        sp24->unkA6 -= 1;
    }
}

void func_800D9620(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800D9650(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1:
            func_800D9134();
            break;
        case 2:
            func_800D9298();
            break;
        case 3:
            func_800D9420();
            break;
        case 4:
            func_800D9520();
            break;
        case 5:
            func_800D9620();
            break;
        default:
            break;
    }
}

void func_800D9720(void) {
    if ((D_80177A64 == 0) || (D_80177A64 == 2)) {
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800D97A4(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkA6 = 0xA;
        sp2C->unk44 = 20.0f;
        sp2C->unk3C = func_8002A46C(gCurrentParsedObject);
        sp2C->Rot.y = sp2C->unk3C;
    }
    sp2C->unkA8 = 0;
    if (sp2C->unkA6 == 0) {
        if (func_80028FA0(gCurrentParsedObject) != 0) {
            sp2C->unkA4 = 2;
            sp2C->unk132 = 0;
        }
    } else {
        sp2C->unkA6 -= 1;
    }
    sp2C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 20.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->unkA8 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, -20.0f, 0.0f) != 0) {
        sp2C->unkA8 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, 20.0f, 0.0f) != 0) {
        sp2C->unkA8 = 1;
    }
    if (sp2C->unkA8 != 0) {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.z;
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
    }
}

void func_800D9A14(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800D9A44(void) {

    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].unkA4) {
            case 1: {
                func_800D97A4();
                break;
            }
            case 2: {
                func_800D9A14();
                break;
            }
            default: {
                break;
            }
        }
    }
}

void func_800D9B0C(void) {
    func_80027464(1, &D_80114294, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800D9B84(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 2;
    }
}

void func_800D9BD4(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = 1;
        sp3C->unk44 = 4.0f;
        sp3C->unk3C = sp3C->Rot.y;
        sp3C->unk40 = 0.0f;
        sp3C->unkA8 = 0;
        sp3C->unkAA = 0;
        func_80019448(gCurrentParsedObject, 2, 0, 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x186, &D_80118BE0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118C10);
    }
    sp3C->unkAC = 0;
    if (sp3C->unkAA != 0) {
        sp3C->unk44 = 4.0f;
        sp3C->Rot.y = func_80015538(sp3C->Rot.y, (f32) (sp3C->unkB6 * 0xA));
        sp3C->unkA8 -= 1;
        if (sp3C->unkA8 == 0) {
            sp3C->unkAA = 0;
            sp3C->unk44 = 5.0f;
        }
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp3C->unkAA = 1;
        sp3C->unkA8 = 0x12;
        if (sp3C->unkB6 == 1) {
            sp3C->unkB6 = -1;
        } else {
            sp3C->unkB6 = 1;
        }
    }
    if (sp3C->unkAA == 0) {
        sp30 = func_80015634(gPlayerObject->Pos.x - sp3C->Pos.x, gPlayerObject->Pos.z - sp3C->Pos.z);
        sp3C->unkB6 = func_800157EC(sp3C->unk3C, sp30, 2.0f);
        sp3C->unk3C = func_80015538(sp3C->unk3C, (f32) (sp3C->unkB6 * 2));
        sp30 = Math_CalcAngleSimple(gPlayerObject->Pos.x - sp3C->Pos.x, gPlayerObject->Pos.y - (sp3C->Pos.y - 100.0f));
        sp30 = Math_NormalizeAngle(sp30);
        sp3C->unkB8 = func_800157EC(sp3C->unk40, sp30, 2.0f);
        sp3C->unk40 = func_80015538(sp3C->unk40, (f32) sp3C->unkB8);
        sp3C->Rot.y = sp3C->unk3C;
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp3C->unkAC = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp34, &sp38, 0.0f, -60.0f, 0.0f) != 0) {
        sp3C->unkAC = 2;
    }
    if (func_800295C0(gCurrentParsedObject, &sp34, &sp38, 0.0f, 60.0f, 0.0f) != 0) {
        sp3C->unkAC = 2;
    }
    if (sp3C->unkAC != 0) {
        sp3C->unk48 = 0.0f;
        sp3C->unk44 = sp3C->unk48;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z = 0;
        sp3C->unkAA = sp3C->unkAC;
        sp3C->unkAC = 0;
        sp3C->unkA8 = 0x12;
        sp3C->unk3C = func_80015538(sp3C->unk3C, 180.0f);
        sp3C->unk40 = func_80015538(sp3C->unk40, 180.0f);
        sp3C->unk40 = Math_NormalizeAngle(sp3C->unk40);
    }
}

void func_800DA128(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800DA158(void) {
    s16 temp_s0;

    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1: {
            func_800D9BD4();
            break;
        }
        case 2: {
            func_800DA128();
            break;
        }
        default: {
            break;
        }
    }
}

void func_800DA1EC(void) {
    func_80027464(1, &D_801142A0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800DA264(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].unk108 = 0;
    }
}

void func_800DA304(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118C8C[0]);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80118C8C[7]);
    }
}

void func_800DA3B0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unkA6 = 0x14;
        func_8001ABF4(gCurrentParsedObject, 1, 0, D_80118C8C + 0xE);
    }
    if (sp24->unkA6 == 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp24->Pos.x, sp24->Pos.y + (f32) sp24->unkA6, sp24->Pos.z, 2.0f);
        func_8002B114(gCurrentParsedObject);
    } else {
        sp24->unkA6 -= 1;
    }
}

void func_800DA4D8(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1:
            func_800DA304();
            break;
        case 2:
            func_800DA3B0();
            break;
        default:
            break;
    }
}

void func_800DA56C(void) {
    func_80027464(1, &D_801142D0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800DA5E4(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1;
    }
}

void func_800DA648(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1: {
            func_800DA5E4();
            break;
        }
        default: {
            break;
        }
    }
}

void func_800DA6BC(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801142DC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_8001ABF4(sp24, 0, 3, &D_80118978);
    }
}

void func_800DA760(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1;
    }
}

void func_800DA7C4(void) {

    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1:
            func_800DA760();
            break;
        default:
            break;
    }
}

void func_800DA838(void) {
    func_80027464(1, &D_801142C4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800DA8B0(void) {
    if ((D_80177A64 == 1) && gObjects[gCurrentParsedObject].unkA4 == 1) {
        gObjects[gCurrentParsedObject].unk108 = 0x32;
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 3;
    }
}

void func_800DA9C8(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1;
    }
}

void func_800DAA2C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1;
        sp4->unkA6 = 0;
    }
    if (sp4->unkA6 < 0xC) {
        sp4->Scale.x = (f32) ((f64) sp4->Scale.x + 0.05);
        sp4->Scale.y = (f32) ((f64) sp4->Scale.y + 0.05);
        sp4->Scale.z = (f32) ((f64) sp4->Scale.z + 0.05);
    } else {
        sp4->Scale.x = (f32) ((f64) sp4->Scale.x - 0.05);
        sp4->Scale.y = (f32) ((f64) sp4->Scale.y - 0.05);
        sp4->Scale.z = (f32) ((f64) sp4->Scale.z - 0.05);
    }
    sp4->unkA6 += 1;
    if (sp4->unkA6 == 0x18) {
        sp4->unkA6 = 0;
    }
    if (sp4->unk108 == 1) {
        sp4->Scale.x = 1.0f;
        sp4->Scale.y = 1.0f;
        sp4->Scale.z = 1.0f;
        sp4->unkA4 = 1;
        sp4->unk132 = 0;
    }
}

void func_800DAC3C(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800DAC6C(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1:
            func_800DA9C8();
            break;
        case 2:
            func_800DAA2C();
            break;
        case 3:
            func_800DAC3C();
            break;
        default:
            break;
    }
}
