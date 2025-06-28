#include "common.h"
#include "86D20.h"

#define RECLAMP_FLOAT(x) (((x) > 48.0f) ? 48.0f : ((x) < -48.0f ? -48.0f : (x)))

void func_80094800(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk3C = (f32) Math_Random(0x168);
        sp34->unk44 = 20.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_800295C0(gCurrentParsedObject, &sp30, &sp2C, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp2C;
    } else {
        sp34->Pos.y = sp30;
    }
}

void func_80094990(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unkA6 = 0;
        sp3C->unk3C = (f32) Math_Random(0x168);
        sp3C->unk44 = 20.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (sp3C->unkA6 == 1) {
        sp3C->unkA6 = 2;
        func_80029EF8(gCurrentParsedObject, 0.0f, 2.0f);
    }
    sp30 = sp3C->Vel.y;
    sp3C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (D_801651A0 & 0x40) {
        sp3C->unkA6 = 1;
    }
    if (sp3C->unkA6 == 0) {
        if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) {
            sp3C->Pos.y = sp34;
        } else {
            sp3C->Pos.y = sp38;
        }
    } else if (sp3C->unkA6 == 2) {
        sp3C->Vel.y = sp30;
        if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
            sp3C->unkA6 = 0;
        }
    }
}

void func_80094C20(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkA6 = 1;
        sp34->unk3C = (f32) Math_Random(0x168);
        sp34->unk44 = 10.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (sp34->unkA6 != 0) {
        sp34->unkA6 = 0;
        func_80029EF8(gCurrentParsedObject, 30.0f, 2.0f);
    }
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        sp34->unkA6 = 1;
    }
}

void func_80094E04(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk3C = 0.0f;
        sp2C->Rot.y = sp2C->unk3C;
        sp2C->unk44 = 5.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk40 = sp2C->unk48;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    } else {
        func_8002A8B4(gCurrentParsedObject, 6.0f);
        sp2C->Rot.y = sp2C->unk3C;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
}

// Needs Rodata
extern f64 D_801148D0;

void func_80094F94(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unkA8 = 0;
        sp34->unk3C = (f32) Math_Random(0x168);
        sp34->unk44 = 5.0f;
        sp34->unk40 = 90.0f;
        sp34->unk48 = 30.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    sp34->unkA6 = (s16) (s32) func_80015538((f32) sp34->unkA6, 10.0f);
    func_800294F0(gCurrentParsedObject, &sp30, &sp2C, 0.0f, 0.0f, 0.0f);
    sp34->unk48 = ((sinf((f32) ((f64) sp34->unkA6 * (f64) D_801148D0)) * 30.0f) + (sp30 + 100.0f)) - sp34->Pos.y;
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp34->unkA6 = (s16) (s32) func_80015538((f32) sp34->unkA6, -10.0f);
    }
    sp34->Rot.y = func_8002A46C(gCurrentParsedObject);
}

void func_80095228(void) {
    struct ObjectStruct* sp2C;
    UNUSED s32 pad[2];
    s32 sp20;

    sp20 = 0;
    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unkA6 = 0;
        sp2C->unk48 = 0.0f;
        sp2C->unk40 = sp2C->unk48;
        sp20 = 1;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp2C->unkA6 = 1;
    }
    if (sp2C->unkA6 != 0) {
        if ((--sp2C->unk44) < 5.0f) {
            sp2C->unkA6 = 0;
            sp20 = 1;
        }
    }
    if (sp20 != 0) {
        sp2C->unk3C = func_8002A46C(gCurrentParsedObject);
        sp2C->unk44 = 20.0f;
        sp2C->Rot.y = sp2C->unk3C;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->unk3C = func_80015538(sp2C->unk3C, 180.0f);
        sp2C->unkA6 = 1;
    }
}

void func_80095448(void) {
    struct ObjectStruct* sp34;
    UNUSED s32 pad[2];

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk3C = (f32) Math_Random(0x168);
        sp34->unk44 = 5.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 5U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
}

void func_80095588(void) {
    UNUSED s32 sp2C;
    UNUSED s32 pad[2];

    sp2C = func_80027464(1, &D_801147F0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
}

void func_80095604(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].action_state = 4;
    } else if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].action_state = 5;
    } else {
        gObjects[gCurrentParsedObject].action_state = 6;
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

extern u32 D_8011B8E0;

void func_800956F0(void) {
    UNUSED s32 pad[2];
    if (gObjects[gCurrentParsedObject].unk132 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 1;
        gObjects[gCurrentParsedObject].unkA8 = 0;
        gObjects[gCurrentParsedObject].unk3C = (f32) Math_Random(0x168);
        gObjects[gCurrentParsedObject].unk44 = 0.0f;
        gObjects[gCurrentParsedObject].unk40 = 0.0f;
        gObjects[gCurrentParsedObject].unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x47, &D_8011B8E0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        gObjects[gCurrentParsedObject].unkA6 =
            (s16) (s32) func_80015538((f32) gObjects[gCurrentParsedObject].unkA6, -10.0f);
    }
    gObjects[gCurrentParsedObject].Rot.y = func_80015538(gObjects[gCurrentParsedObject].Rot.y, 4.0f);
}

void func_800959F0(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80095A20(void) {
    if (gObjects[gCurrentParsedObject].unk132 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 1;
        gObjects[gCurrentParsedObject].unk108 = 0x50;
    }

    gObjects[gCurrentParsedObject].Vel.x = gObjects[gCurrentParsedObject].Vel.y = gObjects[gCurrentParsedObject].Vel.z =
        0.0f;

    func_8001BB34(gCurrentParsedObject, !(gObjects[gCurrentParsedObject].unk108 & 1));
    if (gObjects[gCurrentParsedObject].unk108 == 1) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].action_state = 1;
    }
}

void func_80095C30(void) {
    if (gObjects[gCurrentParsedObject].unk132 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 1;
        gObjects[gCurrentParsedObject].unkA6 = 0x1E;
        gObjects[gCurrentParsedObject].unk44 = 0.0f;
        gObjects[gCurrentParsedObject].unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    gObjects[gCurrentParsedObject].unkA6 -= 1;

    if (gObjects[gCurrentParsedObject].unkA6 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].action_state = 1;
    }
}

void func_80095E14(void) {
    gObjects[gCurrentParsedObject].Rot.y = func_80015538(gObjects[gCurrentParsedObject].Rot.y, 4.0f);
}

void func_80095E94(void) {
    UNUSED s32 sp24;

    sp24 = func_80027464(1, &D_80113400, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, 0.0f);
}

extern f32 D_801147F8[];

void func_80095F08(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unkA6 != 0) {
        sp4->unkA6 -= 1;
    }
    if (sp4->unkA8 != 0) {
        sp4->Pos.y = sp4->Pos.y + D_801147F8[sp4->unkA8];
        sp4->unkA8 += 1;
        if (sp4->unkA8 >= 0xA) {
            sp4->unkA8 = 0;
        }
    }
}

void func_80095FF8(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011340C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA;
    }
}

void func_800960B4(void) {
    if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].action_state = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_8009612C(struct ObjectStruct* arg0) {
    if (D_801765D9[arg0->unkA6].unk0 == 0) {
        func_8001B6BC(gCurrentParsedObject, 0, 0.0f);
    } else {
        func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
    }
}

extern u32 D_80116934;

void func_800961A8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AB, &D_80116934);
    }
    func_8009612C(sp24);
}

void func_80096254(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk108 = 0x20;
        func_800175F0(gCurrentParsedObject, 0, 0x61, -1, 0);
    }
    if (sp24->unk108 == 1) {
        D_801765D8[sp24->unkA6].unk1 = (u8) (D_801765D8[sp24->unkA6].unk1 ^ 1);
        func_8009612C(sp24);
        sp24->action_state = 1;
    }
}

void func_80096350(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_800961A8();
            break;
        case 2:
            func_80096254();
            break;
    }
}

void func_800963DC(void) {
    func_80027464(1, &D_80113418, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_80096454(void) {
    if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].action_state = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

extern s8 D_8016E328;

void func_800964CC(UNUSED s32 arg0) {
    if (D_8016E328 == 0) {
        func_8001B6BC(gCurrentParsedObject, 0, 0.0f);
        func_8001BBDC(gCurrentParsedObject, 1);
    } else {
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}

extern u32 D_8011693C;

void func_80096540(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AD, &D_8011693C);
        func_800964CC((s32) sp24);
    }
}

void func_800965EC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk108 = 0x20;
        D_8016E328 ^= 1;
        func_800964CC((s32) sp24);
        func_800175F0(gCurrentParsedObject, 0, 0x61, -1, 0);
    }
    if (sp24->unk108 == 1) {
        sp24->action_state = 1;
    }
}

void func_800966D4(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_80096540();
            break;
        case 2:
            func_800965EC();
            break;
    }
}

void func_80096760(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113424, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkAE = D_80165100->unkE;
    }
}

void func_8009681C(void) {
    if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].action_state = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_80096894(struct ObjectStruct* arg0) {
    if (arg0->unkA6 == 0) {
        func_8001B6BC(gCurrentParsedObject, 0, 0.0f);
    } else {
        func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
    }
}

extern u32 D_80116938;

void func_80096900(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AC, &D_80116938);
    }
    func_80096894(sp24);
}

void func_800969AC(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk108 = 0x20;
        func_800175F0(gCurrentParsedObject, 0, 0x61, -1, 0);
    }
    if (sp24->unk108 == 1) {
        sp24->unkA6 ^= 1;
        func_80096894(sp24);
        sp24->action_state = 1;
        sp20 = 0xE;

        while (TRUE) {
            sp20 = Get_ObjIdx_ByPos(0x5A, sp20);
            if (sp20 == -1) {
                break;
            }

            if (gObjects[sp20].unkAE == sp24->unkAE) {
                if (gObjects[sp20].action_state == 1) {
                    gObjects[sp20].action_state = 2;
                } else {
                    gObjects[sp20].action_state = 1;
                }

                gObjects[sp20].unk132 = 0;
                break;
            }
            sp20++;
        }
    }
}

void func_80096BC8(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_80096900();
            break;
        case 2:
            func_800969AC();
            break;
    }
}

void func_80096C54(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011361C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, 0.0f);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA * 0x3C;
        if (D_80165100->unkC < 4) {
            gObjects[sp24].unk3C = (f32) D_80114820[D_80165100->unkC];
            gObjects[sp24].unkAC = 0;
        } else if (D_80165100->unkC < 6) {
            gObjects[sp24].unk40 = D_80114820[D_80165100->unkC];
            gObjects[sp24].unkAC = 1;
        } else {
            gObjects[sp24].unkAC = 2;
        }
        gObjects[sp24].unkA8 = gObjects[sp24].unkA6;
        gObjects[sp24].unk3C = func_80015538(gObjects[sp24].unk3C, 180.0f);
        gObjects[sp24].unk40 = func_80015538(gObjects[sp24].unk40, 180.0f);
        gObjects[sp24].unkAE = D_80165100->unkE;
        func_8001ABF4(sp24, 0, 0, &D_8011B92C);
    }
}

void func_80096F88(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    sp4->Vel.x = sp4->Vel.y = sp4->Vel.z = 0.0f;
}

void func_80096FF8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 4.0f;
    }
    if (sp24->unkAC == 0) {
        sp24->unk40 = 0.0f;
        func_80029D8C(gCurrentParsedObject);
        sp24->Vel.y = 0.0f;
    } else if (sp24->unkAC == 1) {
        sp24->unk3C = 0.0f;
        func_80029D8C(gCurrentParsedObject);
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    } else {
        sp24->Vel.x = sp24->Vel.y = sp24->Vel.z = 0.0f;
    }
    if (sp24->unkAC < 2) {
        sp24->unkA8 = (s16) (s32) ((f32) sp24->unkA8 - sp24->unk44);
        if (sp24->unkA8 <= 0) {
            sp24->unkA8 = sp24->unkA6;
            sp24->unk3C = func_80015538(sp24->unk3C, 180.0f);
            sp24->unk40 = func_80015538(sp24->unk40, 180.0f);
        }
    }
}

void func_80097244(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_80096F88();
            break;
        case 2:
            func_80096FF8();
            break;
    }
}

void func_800972D0(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113640, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA;
    }
}

void func_8009738C(void) {
    if ((D_80177A64 == 1) && (gObjects[gCurrentParsedObject].action_state == 1)) {
        gObjects[gCurrentParsedObject].action_state = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_80097438(struct ObjectStruct* arg0) {
    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AC, &D_80116938);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
}

void func_800974C0(struct ObjectStruct* arg0) {
    s32 sp24;

    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        arg0->unk108 = 0x20;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_800175F0(gCurrentParsedObject, 0, 0x61, -1, 0);
    }
    if (arg0->unk108 == 1) {
        func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
        arg0->action_state = 3;
        sp24 = 0xE;

        while (TRUE) {
            sp24 = Get_ObjIdx_ByPos(0x54, sp24);
            if (sp24 == -1) {
                break;
            }

            if (gObjects[sp24].unkA6 == arg0->unkA6) {
                gObjects[sp24].unkA8 = 1;
                break;
            }

            sp24++;
        }
    }
}

void func_80097634(UNUSED s32 arg0) {
    func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
}

void func_8009766C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->action_state) {
        case 1:
            func_80097438(sp24);
            break;
        case 2:
            func_800974C0(sp24);
            break;
        case 3:
            func_80097634((s32) sp24);
            break;
    }
}

void func_80097730(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011364C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA;
    }
}

void func_800977EC(struct ObjectStruct* arg0) {
    UNUSED s32 pad;

    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
    }
    if ((func_8002A1FC(gCurrentParsedObject, 360.0f) != 0) && (arg0->unkA8 != 0)) {
        arg0->action_state = 2;
        arg0->unk132 = 0U;
    }
}

void func_80097888(struct ObjectStruct* arg0) {
    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        arg0->unkAA = 0;
        arg0->unk48 = 60.0f;
        arg0->unk40 = 90.0f;
        func_800175F0(gCurrentParsedObject, 0, 0x31, -1, 0);
    }
    func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
    arg0->Vel.x = arg0->Vel.z = 0.0f;
    func_80029D04(gCurrentParsedObject);
    arg0->unkAA = (s16) (s32) ((f32) arg0->unkAA + arg0->unk48);
    if (arg0->unkAA >= 0xB4) {
        arg0->unk48 = 0.0f;
    }
}

void func_800979EC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->action_state) {
        case 1:
            func_800977EC(sp24);
            break;
        case 2:
            func_80097888(sp24);
            break;
    }
}

void func_80097A90(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113628, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA;
    }
}

extern u32 D_80116ECC;

void func_80097B4C(struct ObjectStruct* arg0) {
    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1A9, &D_80116ECC);
    }
    if ((arg0->unkA8 == 0) && (D_80165247 != 0)) {
        arg0->unkA8 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x1A9, &D_80116ECC);
    }
    if ((func_8002A1FC(gCurrentParsedObject, 360.0f) != 0) && (arg0->unkA8 != 0)) {
        arg0->action_state = 2;
        arg0->unk132 = 0U;
    }
}

void func_80097C68(struct ObjectStruct* arg0) {
    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        func_800175F0(gCurrentParsedObject, 0, 0x31, -1, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x1A9, &D_80116ECC);
        arg0->unkAA = 0;
        arg0->unk44 = 60.0f;
        arg0->unk3C = 270.0f;
    }
    arg0->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    arg0->unkAA = (s16) (s32) ((f32) arg0->unkAA + arg0->unk44);
    if (arg0->unkAA >= 0xB4) {
        arg0->unk44 = 0.0f;
    }
}

void func_80097DC8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];

    switch (sp24->action_state) {
        case 1:
            func_80097B4C(sp24);
            break;
        case 2:
            func_80097C68(sp24);
            break;
    }
}

void func_80097E6C(void) {
    func_80027464(1, &D_80113634, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

extern u32 D_80116ED4;

void func_80097EE4(struct ObjectStruct* arg0) {
    UNUSED s32 pad;

    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AA, &D_80116ED4);
    }
    if ((arg0->unkA8 == 0) && (D_80165248 != 0)) {
        arg0->unkA8 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x1AA, &D_80116ED4);
    }
    if ((func_8002A1FC(gCurrentParsedObject, 360.0f) != 0) && (arg0->unkA8 != 0)) {
        arg0->action_state = 2;
        arg0->unk132 = 0U;
    }
}

void func_80098000(struct ObjectStruct* arg0) {
    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        arg0->unkAA = 0;
        arg0->unk48 = 60.0f;
        arg0->unk40 = 90.0f;
        func_800175F0(gCurrentParsedObject, 0, 0x31, -1, 0);
    }
    func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
    arg0->Vel.x = arg0->Vel.z = 0.0f;
    func_80029D04(gCurrentParsedObject);
    arg0->unkAA = (s16) (s32) ((f32) arg0->unkAA + arg0->unk48);
    if (arg0->unkAA >= 0xB4) {
        arg0->unk48 = 0.0f;
    }
}

void func_80098164(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];

    switch (sp24->action_state) {
        case 1:
            func_80097EE4(sp24);
            break;
        case 2:
            func_80098000(sp24);
            break;
    }
}

void func_80098208(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113664, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA;
    }
}

void func_800982C4(void) {
    if ((D_80177A64 == 1) && (gObjects[gCurrentParsedObject].action_state == 1)) {
        gObjects[gCurrentParsedObject].action_state = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_80098370(struct ObjectStruct* arg0) {
    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AC, &D_80116938);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
}

void func_800983F8(struct ObjectStruct* arg0) {
    s32 sp24;

    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        arg0->unk108 = 0x20;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_800175F0(gCurrentParsedObject, 0, 0x61, -1, 0);
    }
    if (arg0->unk108 == 1) {
        func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
        arg0->action_state = 3;
        sp24 = 0xE;

        while (TRUE) {
            sp24 = Get_ObjIdx_ByPos(0x194, sp24);
            if (sp24 == -1) {
                break;
            }

            if (gObjects[sp24].unkA6 == arg0->unkA6) {
                gObjects[sp24].obj_id = 0x195;
                gObjects[sp24].unk132 = 0;
                break;
            }

            sp24 += 1;
        }
    }
}

void func_80098590(UNUSED s32 arg0) {
    func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
}

void func_800985C8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];

    switch (sp24->action_state) {
        case 1:
            func_80098370(sp24);
            break;
        case 2:
            func_800983F8(sp24);
            break;
        case 3:
            func_80098590((s32) sp24);
            break;
    }
}

void func_8009868C(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113670, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA;
        if (D_80165100->unkC == 1) {
            gObjects[sp24].obj_id = 0x195;
        }
    }
}

extern s32 D_80116D78;

void func_8009878C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        if (sp1C->obj_id == 0x194) {
            func_8001ABF4(gCurrentParsedObject, 0, 3, &D_80116D78);
        } else {
            func_8001ABF4(gCurrentParsedObject, 0, 3, &D_80116D78 + 7);
        }
    }
}

extern struct Vec3f D_8011482C[];

void func_80098864(s32 arg0, s32 arg1, s32 arg2) {
    struct ObjectStruct* spAC;
    struct ObjectStruct* spA8;
    Matrix sp68;
    Matrix sp28;

    spAC = &gObjects[arg0];
    spA8 = &gObjects[spAC->unkE6[0]];
    if (spAC->unkE6[0] != -1) {
        guRotateF(sp68, spA8->Rot.y, 0.0f, 1.0f, 0.0f);
        guTranslateF(sp28, spA8->Pos.x, spA8->Pos.y, spA8->Pos.z);
        guMtxCatF(sp68, sp28, sp68);

        guMtxXFMF(sp68, D_8011482C[arg1].x, D_8011482C[arg1].y, D_8011482C[arg1].z, &spAC->Pos.x, &spAC->Pos.y,
                  &spAC->Pos.z);
        if (arg2 != 0) {
            spAC->Rot.x = spA8->Rot.x;
            spAC->Rot.y = spA8->Rot.y;
            spAC->Rot.z = spA8->Rot.z;
        }
    }
}

void func_800989E0(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA8 = 1;
    } else if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].unkA8 = 1;
    } else {

        gObjects[gCurrentParsedObject].unkA8 = 1;
    }
}

void func_80098AA4(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    s32 sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 20.0f;
        sp34->unk3C = sp34->Rot.y;
        sp34->unk40 = 0.0f;
        func_80019448(gCurrentParsedObject, 2, 0, 1);
    }
    sp28 = 0;
    if (func_8002A1FC(gCurrentParsedObject, 960.0f) != 0) {
        sp30 = func_80015634(gPlayerObject->Pos.x - sp34->Pos.x, gPlayerObject->Pos.z - sp34->Pos.z);
        sp2C = func_8002A800(sp34->unk3C, sp30, 3.0f);
        if (sp2C != 0) {
            sp34->unk3C = func_80015538(sp34->unk3C, (f32) sp2C);
        }
        sp30 = Math_CalcAngleSimple(gPlayerObject->Pos.x - sp34->Pos.x, gPlayerObject->Pos.y - sp34->Pos.y);
        sp30 = Math_NormalizeAngle(sp30);
        sp2C = func_8002A800(sp34->unk40, sp30, 3.0f);
        if (sp2C != 0) {
            sp34->unk40 = func_80015538(sp34->unk40, (f32) sp2C);
        }
    }
    sp34->Rot.y = sp34->unk3C;
    sp34->Rot.x = 360.0f - sp34->unk40;
    if (sp34->Rot.x >= 360.0f) {
        sp34->Rot.x -= 360.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp28 = 1;
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp28 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp20, &sp24, 0.0f, -30.0f, 0.0f) != 0) {
        sp28 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp20, &sp24, 0.0f, 30.0f, 0.0f) != 0) {
        sp28 = 1;
    }
    if (sp34->unkA8 != 0) {
        sp28 = 1;
    }
    if (sp28 != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_80098E18(void) {
    if (D_80177A64 == 0) {
    } else {

        if (D_80177A64 == 1) {
        } else {
        }
    }
}

// Needs Rodata
extern f64 D_801148D8;

void func_80098E60(void) {
    struct ObjectStruct* sp44;
    UNUSED s32 pad[2];
    s32 sp38;
    f32 sp34;
    f32 sp30;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = 1;
        sp44->unk44 = 2.0f;
        sp44->unk3C = sp44->Rot.y;
        sp44->unk40 = 0.0f;
    }
    sp44->Scale.x = (f32) ((f64) sp44->Scale.x + D_801148D8);
    sp44->Scale.y = sp44->Scale.z = sp44->Scale.x;

    sp38 = 0;
    if (sp44->unkA6 >= 0x3C) {
        sp38 = 1;
    } else {
        sp44->unkA6 += 1;
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp38 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp30, &sp34, 0.0f, -30.0f, 0.0f) != 0) {
        sp38 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp30, &sp34, 0.0f, 30.0f, 0.0f) != 0) {
        sp38 = 1;
    }
    if (sp38 != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_80099084(void) {
    s32 sp24;

    sp24 = func_80027464(5, &D_8011346C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_80098864(gObjects[sp24].unkE8[0], 0, 1);
        func_80098864(gObjects[sp24].unkE8[1], 1, 1);
        func_80098864(gObjects[sp24].unkE8[2], 2, 1);
        func_80098864(gObjects[sp24].unkE8[3], 3, 1);
    }
}

void func_800991D0(void) {
    struct ObjectStruct* sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp24->action_state = 2;
        sp24->unk132 = 0;
        sp24->unk108 = 0;
        for (sp1C = 0; sp1C < 4; sp1C++) {
            if ((sp20 = sp24->unkE8[sp1C]) != -1) {
                gObjects[sp20].unk108 = 0;
            }
        }
        sp20 = (s32) sp24->unkE8[0];
        if (sp20 != -1) {
            func_800281A4(gCurrentParsedObject, 0);
            func_8002B0E4(sp20);
        }
        sp20 = (s32) sp24->unkE8[1];
        if (sp20 != -1) {
            func_800281A4(gCurrentParsedObject, 1);
            func_8002B0E4(sp20);
        }
        sp20 = (s32) sp24->unkE8[2];
        if (sp20 != -1) {
            func_800281A4(gCurrentParsedObject, 2);
            func_8002B0E4(sp20);
        }
        sp20 = (s32) sp24->unkE8[3];
        if (sp20 != -1) {
            func_800281A4(gCurrentParsedObject, 3);
            func_8002B0E4(sp20);
        }
    } else if (D_80177A64 == 1) {
        sp24->unk108 = 0x50;
        for (sp1C = 0; sp1C < 4; sp1C++) {
            sp20 = (s32) sp24->unkE8[sp1C];
            if (sp20 != -1) {
                gObjects[sp20].unk108 = 0x50;
            }
        }
    } else {
    }
}

// Needs Rodata
extern f32 D_801148E0;
extern f32 D_801148E4;

void func_80099454(void) {
    struct ObjectStruct* spD4;
    s32 spD0;
    s32 spCC;
    f32 spC8;
    Matrix sp88;
    Matrix sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    UNUSED s32 pad;
    s32 sp34;

    spD4 = &gObjects[gCurrentParsedObject];
    if (spD4->unk132 == 0) {
        spD4->unk132 = 1;
        spD4->unk44 = 1.0f;
        spD4->unk3C = 0.0f;
        spD4->unk40 = 0.0f;
        spD4->unkAC = Math_Random(2);
    }
    if (spD4->unkA8 == 0) {
        if (func_8002A1FC(gCurrentParsedObject, 1920.0f) != 0) {
            spD4->unkA8 = 1;
            spD4->unk3C = func_80015538(spD4->unk3C, 180.0f);
        } else {
            spD4->unk44 = 3.0f;
            func_8002A8B4(gCurrentParsedObject, 0.1f);
            if ((spD4->unk3C >= 20.0f) && (spD4->unk3C <= 180.0f)) {
                spD4->unk3C = 20.0f;
            } else {
                if ((spD4->unk3C >= 180.0f) && (spD4->unk3C <= 340.0f)) {
                    spD4->unk3C = 340.0f;
                }
            }
            spD4->Rot.y = spD4->unk3C;
        }
    } else if (func_8002A1FC(gCurrentParsedObject, 2880.0f) == 0) {
        spD4->unkA8 = 0;
        spD4->unk3C = func_80015538(spD4->unk3C, 180.0f);
    } else {
        spD4->unk44 = 10.0f;
        spC8 = func_80015538(func_8002A46C(gCurrentParsedObject), 180.0f);
        spCC = func_8002A800(spD4->unk3C, spC8, 2.0f);
        if (spCC == 0) {
            spD4->unk3C = spC8;
        } else {
            spD4->unk3C = func_80015538(spD4->unk3C, (f32) ((f64) spCC * 0.5));
        }
        if (spD4->unk3C <= 160.0f) {
            spD4->unk3C = 160.0f;
        } else if (spD4->unk3C >= 200.0f) {
            spD4->unk3C = 200.0f;
        }
        spD4->Rot.y = func_80015538(spD4->unk3C, 180.0f);
    }
    if ((spD4->unkA8 == 1) && (spD4->unkAA == 0) && (spD4->unkAC == 0) && (Math_Random(0xA) == 0) &&
        ((spD4->Pos.z + 120.0f) < gPlayerObject->Pos.z)) {
        spD4->unkAC = 0x40;
        spD4->unkAA = 0x3C;
    }
    if (spD4->unkAC != 0) {
        if (!(spD4->unkAC & 0x1F) && (spD4->Vel.z != 0.0f)) {
            guRotateF(sp88, spD4->Rot.y, 0.0f, 1.0f, 0.0f);
            guTranslateF(sp48, spD4->Pos.x, spD4->Pos.y, spD4->Pos.z);
            guMtxCatF(sp88, sp48, sp88);
            guMtxXFMF(sp88, -100.0f, -30.0f, 180.0f, &sp44, &sp40, &sp3C);
            spD0 = func_80027464(1, &D_80113460, sp44, sp40, sp3C, spD4->Rot.y);
            if (spD0 != -1) {
                gObjects[spD0].Scale.x = gObjects[spD0].Scale.y = gObjects[spD0].Scale.z = D_801148E0;
            }
            guMtxXFMF(sp88, 100.0f, -30.0f, 180.0f, &sp44, &sp40, &sp3C);
            spD0 = func_80027464(1, &D_80113460, sp44, sp40, sp3C, spD4->Rot.y);
            if (spD0 != -1) {
                gObjects[spD0].Scale.x = gObjects[spD0].Scale.y = gObjects[spD0].Scale.z = D_801148E4;
            }
        }
        spD4->unkAC -= 1;
    } else if (spD4->unkAA != 0) {
        spD4->unkAA -= 1;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 240.0f, 0.0f, 0.0f, 0.0f) != 0) {}
    if (spD4->Pos.z > (gPlayerObject->Pos.z + 240.0f)) {
        for (sp34 = 0; sp34 < 4; sp34++) {
            if ((spD0 = spD4->unkE8[sp34]) != -1) {
                func_800281A4(gCurrentParsedObject, sp34);
                func_8002B0E4(spD0);
            }
        }
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_80099C4C(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    s32 sp2C;
    f32 sp28;
    f32 sp24;
    s32 sp20;

    sp34 = &gObjects[gCurrentParsedObject];
    sp30 = 0;
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unkAE = 0x3C;
        if (Math_Random(2) != 0) {
            sp34->unkB0 = 1;
        } else {
            sp34->unkB0 = -1;
        }
    }
    sp34->unk44 = 6.0f;
    sp34->unk40 = 340.0f;
    sp34->unk3C = func_8002A46C(gCurrentParsedObject);
    sp34->Rot.z = func_80015538(sp34->Rot.z, (f32) ((f64) sp34->unkB0 * 0.5));
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp30 = 1;
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, -60.0f, 0.0f) != 0) {
        sp30 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, 60.0f, 0.0f) != 0) {
        sp30 = 1;
    }
    if (sp34->unkAE == 0) {
        sp30 = 1;
    } else {
        sp34->unkAE -= 1;
    }
    if (sp30 != 0) {
        for (sp2C = 0; sp2C < 4; sp2C++) {
            if ((sp20 = sp34->unkE8[sp2C]) != -1) {
                func_800281A4(gCurrentParsedObject, sp2C);
                func_8002B0E4(sp20);
            }
        }
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_80099EDC(void) {

    func_8002AA94(gCurrentParsedObject);
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_80099454();
            break;
        case 2:
            func_80099C4C();
            break;
        default:
            break;
    }
}

extern u32 D_80116940;

void func_80099F80(void) {
    struct ObjectStruct* spBC;
    UNUSED s32 spB8;
    s32 spB4;
    Matrix sp74;
    Matrix sp24;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    spBC = &gObjects[gCurrentParsedObject];
    func_8002AA94(gCurrentParsedObject);
    func_80098864(gCurrentParsedObject, 0, 0);
    spB4 = func_8002A640(gCurrentParsedObject, 2.0f);
    if (spB4 == 0) {
        spBC->Rot.y = func_8002A46C(gCurrentParsedObject);
    } else {
        spBC->Rot.y = func_80015538(spBC->Rot.y, (f32) (spB4 * 2));
    }
    if (spBC->unkA6 == 0) {
        if ((spB4 == 0) && ((spBC->Pos.z + 120.0f) < gPlayerObject->Pos.z) && (Math_Random(0xA) == 0)) {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0xAB, &D_80116940);
            func_8001B754(gCurrentParsedObject, 0);
            spBC->unkA6 = 0x1E;
        }
    } else {
        spBC->unkA6 -= 1;
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 20.0f) {
        guRotateF(sp74, spBC->Rot.y, 0.0f, 1.0f, 0.0f);
        guTranslateF(sp24, spBC->Pos.x, spBC->Pos.y, spBC->Pos.z);
        guMtxCatF(sp74, sp24, sp74);
        guMtxXFMF(sp74, 0.0f, 40.0f, 120.0f, &sp30, &sp2C, &sp28);
        spB8 = func_80027464(1, &D_80113454, sp30, sp2C, sp28, spBC->Rot.y);
    }
}

extern u32 D_80116944;

void func_8009A1F8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    func_80098864(gCurrentParsedObject, 1, 0);
    func_8002AA94(gCurrentParsedObject);
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xAC, &D_80116944);
    }
}

void func_8009A2B0(void) {
    UNUSED struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    func_80098864(gCurrentParsedObject, 2, 1);
    func_8002AA94(gCurrentParsedObject);
}

void func_8009A320(void) {
    UNUSED struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    func_80098864(gCurrentParsedObject, 3, 1);
    func_8002AA94(gCurrentParsedObject);
}

void func_8009A390(void) {
    s32 sp24;

    sp24 = func_80027464(5, &D_801134A8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_80098864(gObjects[sp24].unkE8[0], 0, 1);
        func_80098864(gObjects[sp24].unkE8[1], 1, 1);
        func_80098864(gObjects[sp24].unkE8[2], 2, 1);
        func_80098864(gObjects[sp24].unkE8[3], 3, 1);
    }
}

void func_8009A4DC(void) {
    struct ObjectStruct* sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp24->unkA6 = 2;
        sp24->unk108 = 0;
        sp20 = (s32) sp24->unkE8[0];
        if (sp20 != -1) {
            func_800281A4(gCurrentParsedObject, 0);
            func_8002B0E4(sp20);
        }
        sp20 = (s32) sp24->unkE8[3];
        if (sp20 != -1) {
            func_800281A4(gCurrentParsedObject, 3);
            func_8002B0E4(sp20);
        }
    } else if (D_80177A64 == 1) {
        sp24->unk108 = 0x50;
        for (sp1C = 0; sp1C < 4; sp1C++) {
            sp20 = (s32) sp24->unkE8[sp1C];
            if (sp20 != -1) {
                gObjects[sp20].unk108 = 0x50;
            }
        }
    } else {
    }
}

void func_8009A674(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unkA6 == 0) {
        if (func_8002A2EC(gCurrentParsedObject, 480.0f) != 0) {
            sp24->unkA6 = 1;
        }
        sp24->unk44 = 4.0f;
        sp24->unk3C = 270.0f;
    } else if (sp24->unkA6 == 1) {
        if (func_8002A2EC(gCurrentParsedObject, 960.0f) == 0) {
            sp24->unkA6 = 0;
        }
        sp24->unk44 = 2.0f;
        sp24->unk3C = 90.0f;
    } else if (sp24->unkA6 == 2) {
        sp24->unk44 = 2.0f;
        sp24->unk3C = 0.0f;
        sp24->unk40 = 90.0f;
        sp24->unkA8 += 1;
        if (sp24->unkA8 >= 0x1E0) {
            sp24->unkA6 = 3;
        }
    } else if (sp24->unkA6 == 3) {
        sp24->unk44 = 0.0f;
        sp24->unk3C = 0.0f;
        sp24->unk40 = 0.0f;
        sp24->unkAA += 1;
        if (sp24->unkAA >= 0x78) {
            sp20 = (s32) sp24->unkE8[1];
            if (sp20 != -1) {
                func_800281A4(gCurrentParsedObject, 1);
                func_8002B0E4(sp20);
            }
            sp20 = (s32) sp24->unkE8[2];
            if (sp20 != -1) {
                func_800281A4(gCurrentParsedObject, 2);
                func_8002B0E4(sp20);
            }
            func_8002B0E4(gCurrentParsedObject);
        }
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 240.0f, 0.0f, 0.0f, 0.0f) != 0) {}
}

void func_8009A994(void) {
    func_8002AA94(gCurrentParsedObject);

    if ((gObjects[gCurrentParsedObject].action_state == 1)) {
        if (FALSE) {}
        func_8009A674();
    } else {
    }
}

void func_8009AA10(void) {
    struct ObjectStruct* spBC;
    s32 spB8;
    s32 spB4;
    Matrix sp74;
    Matrix sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    spBC = &gObjects[gCurrentParsedObject];
    func_8002AA94(gCurrentParsedObject);
    func_80098864(gCurrentParsedObject, 0, 0);
    spB4 = func_8002A640(gCurrentParsedObject, 2.0f);
    if (spB4 == 0) {
        spBC->Rot.y = func_8002A46C(gCurrentParsedObject);
    } else {
        spBC->Rot.y = func_80015538(spBC->Rot.y, (f32) (spB4 * 2));
    }
    if (spBC->unkA6 == 0) {
        if ((spB4 == 0) && (func_8002A1FC(gCurrentParsedObject, 960.0f) != 0) && (Math_Random(0xA) == 0)) {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0xAB, &D_80116940);
            func_8001B754(gCurrentParsedObject, 0);
            spBC->unkA6 = 0x3C;
        }
    } else {
        spBC->unkA6 -= 1;
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 20.0f) {
        guRotateF(sp74, spBC->Rot.y, 0.0f, 1.0f, 0.0f);
        guTranslateF(sp34, spBC->Pos.x, spBC->Pos.y, spBC->Pos.z);
        guMtxCatF(sp74, sp34, sp74);
        guMtxXFMF(sp74, 0.0f, 40.0f, 120.0f, &sp30, &sp2C, &sp28);
        spB8 = func_80027464(1, &D_80113454, sp30, sp2C, sp28, spBC->Rot.y);
        if (spB8 != -1) {
            func_80026F10(gCurrentParsedObject, spB8);
        }
    }
}

void func_8009AC94(void) {
    struct ObjectStruct* sp2C;
    UNUSED s32 pad[2];

    sp2C = &gObjects[gCurrentParsedObject];
    func_8002AA94(gCurrentParsedObject);
    if (sp2C->action_state == 1) {
        if (FALSE) {}
        if (sp2C->unk132 == 0) {
            sp2C->unk132 = 1;
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0xAC, &D_80116944);
        }
        func_80098864(gCurrentParsedObject, 1, 0);
    } else {
    }
}

void func_8009AD74(void) {
    UNUSED struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    func_80098864(gCurrentParsedObject, 2, 1);
    func_8002AA94(gCurrentParsedObject);
}

void func_8009ADE4(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    func_8002AA94(gCurrentParsedObject);
    if (sp1C->action_state == 1) {
        if (FALSE) {}
        func_80098864(gCurrentParsedObject, 3, 0);
    } else {
    }
}

extern struct UnkStruct_80027B34 D_8011485C;

void func_8009AE7C(void) {
    s32 sp24;

    sp24 = func_80027464(3, &D_801134E4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_80027B34(sp24, &D_8011485C);
    }
}

extern u32 D_80116950;

void func_8009AF18(void) {
    struct ObjectStruct* sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;

    sp40 = 0;
    sp44 = &gObjects[gCurrentParsedObject];
    sp3C = (s32) sp44->unkE8[0];
    sp38 = (s32) sp44->unkE8[1];

    switch (sp44->action_state) {
        case 1:
            if (sp44->unk132 == 0) {
                sp44->unk132 += 1;
                func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011698C);
                func_8001ABF4(gCurrentParsedObject, 1, 0, &D_8011698C + 7);
                func_8001BB34((s32) sp44->unkE8[1], 1);
                sp44->unk44 = 0.0f;
                sp44->unk3C = 0.0f;
                sp44->unk40 = 90.0f;
            }
            if (func_8002A1FC(gCurrentParsedObject, 360.0f) != 0) {
                sp44->action_state = 2;
                sp44->unk132 = 0;
            }
            break;
        case 2:
            if (sp44->unk132 == 0) {
                sp44->unk132 += 1;
                sp44->unk44 = 10.0f;
                sp44->unk3C = 0.0f;
                sp44->unk40 = 90.0f;
                func_800175F0(gCurrentParsedObject, 0, 0x2C, -1, 0);
            }
            if (sp44->unkA6 < 0xA) {
                sp44->unkA6 += 1;
            } else {
                sp44->action_state = 3;
                sp44->unk132 = 0;
            }
            break;
        case 3:
            if (sp44->unk132 == 0) {
                sp44->unk132 += 1;
                func_8001C0EC(gCurrentParsedObject, 3, 0, 0xA5, &D_80116950);
                sp44->unk44 = 0.0f;
                sp44->unk3C = 0.0f;
                sp44->unk40 = 0.0f;
                func_800175F0(gCurrentParsedObject, 0, 0x2D, -1, 0);
            }
            if (func_8001B44C(gCurrentParsedObject, 3) != 0) {
                sp44->action_state = 4;
                sp44->unk132 = 0;
            }
            break;
        case 4:
            if (sp44->unk132 == 0) {
                sp44->unk132 += 1;
                func_8001C0EC(gCurrentParsedObject, 3, 1, 0xA5, &D_80116950);
                sp44->unkA6 = 0;
                sp44->unk44 = 30.0f;
                sp44->unk3C = 90.0f;
                sp44->unk40 = 0.0f;
            }
            if (sp44->unkA6 < 0x3C) {
                sp44->unkA6 += 1;
            } else {
                sp40 = 1;
            }
            break;
    }
    func_80029D8C(gCurrentParsedObject);

    gObjects[sp3C].Vel.x = gObjects[sp38].Vel.x = sp44->Vel.x;
    gObjects[sp3C].Vel.y = gObjects[sp38].Vel.y = sp44->Vel.y;
    gObjects[sp3C].Vel.z = gObjects[sp38].Vel.z = sp44->Vel.z;

    if (sp40 != 0) {
        func_800281A4(gCurrentParsedObject, 0);
        func_800281A4(gCurrentParsedObject, 1);
        func_8002B0E4(sp3C);
        func_8002B0E4(sp38);
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_8009B4C0(void) {
    func_80027464(1, &D_80113508, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_8009B538(void) {
}

// Unused?
void func_8009B548(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113514, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_8001ABF4(sp24, 0, 3, D_80122B08->unkC[45]); //?
    }
}

void func_8009B5F0(void) {
}

void func_8009B600(void) {
    s32 sp34;
    f32 sp30;

    sp34 = func_80027464(1, &D_80113520, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp34 != -1) {
        sp30 = (f32) D_80165100->unkA;
        if (sp30 == 0.0f) {
            sp30 = 10.0f;
        } else if (sp30 <= 5.0f) {
            sp30 = 5.0f;
        } else if (sp30 >= 15.0f) {
            sp30 = 15.0f;
        }

        gObjects[sp34].Scale.y = sp30 / 10.0f;
        sp30 = (f32) D_80165100->unkC;
        if (sp30 == 0.0f) {
            sp30 = 10.0f;
        } else if (sp30 <= 5.0f) {
            sp30 = 5.0f;
        } else if (sp30 >= 15.0f) {
            sp30 = 15.0f;
        }
        gObjects[sp34].Scale.x = gObjects[sp34].Scale.z = sp30 / 10.0f;
    }
}

void func_8009B884(void) {
    if (D_80177A64 == 0) {
    } else {

        if (D_80177A64 == 1) {
        } else {
        }
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_8009B8F4(void) {
}

void func_8009B904(void) {
    func_80027464(1, &D_8011352C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_8009B97C(void) {
    func_80027464(1, &D_80113538, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_8009B9F4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->action_state == 1) {
        if ((gPlayerObject->Pos.z < 960.0f) && (gPlayerObject->Pos.x > -480.0f) && (gPlayerObject->Pos.x < 480.0f)) {
            sp24->action_state = 2;
            func_800175F0(gCurrentParsedObject, 0, 0x5E, -1, 0);
        }
    } else if (sp24->action_state == 2) {
        if (sp24->obj_id == 0x18B) {
            sp24->Vel.x = 4.0f;
            if (sp24->Pos.x >= 656.0f) {
                sp24->action_state = 3;
            }
        } else {
            sp24->Vel.x = -4.0f;
            if (sp24->Pos.x <= -656.0f) {
                sp24->action_state = 3;
            }
        }
    } else {
        sp24->Vel.x = 0.0f;
    }
}

extern f32 D_801148E8;

void func_8009BBC4(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 sp2C;

    sp2C = func_80027464(1, &D_80113544, arg0, arg1, arg2, arg3);
    if (sp2C != -1) {
        gObjects[sp2C].Scale.x = gObjects[sp2C].Scale.y = gObjects[sp2C].Scale.z = D_801148E8;
    }
}

void func_8009BCBC(void) {
    if (D_80177A64 == 0) {
    } else if (D_80177A64 == 1) {
    } else {
        gObjects[gCurrentParsedObject].action_state = 3;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

// Needs Rodata
extern f64 D_801148F0;

void func_8009BD58(struct ObjectStruct* arg0) {

    if (arg0->unk132 == 0) {
        arg0->unk132 = 1U;
    }
    arg0->Scale.x = (f32) ((f64) arg0->Scale.x + D_801148F0);
    if (arg0->Scale.x >= 1.0f) {
        arg0->Scale.x = 1.0f;
        arg0->action_state = 2;
        arg0->unk132 = 0U;
    }
    arg0->Scale.y = arg0->Scale.z = arg0->Scale.x;
}

void func_8009BDF0(struct ObjectStruct* arg0) {
    s32 sp2C;
    f32 sp28;
    f32 sp24;

    if (arg0->unk132 == 0) {
        arg0->unk132 = 1U;
        arg0->unk44 = 10.0f;
        arg0->unk3C = (f32) arg0->Rot.y;
        arg0->unk40 = 0.0f;
    }
    sp2C = 0;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp2C = 1;
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, -30.0f, 0.0f) != 0) {
        sp2C = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, 30.0f, 0.0f) != 0) {
        sp2C = 1;
    }
    if (sp2C != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_8009BF7C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->action_state) {
        case 1:
            func_8009BD58(sp24);
            break;
        case 2:
            func_8009BDF0(sp24);
            break;
        case 3:
            func_8002B0E4(gCurrentParsedObject);
            break;
    }
}

void func_8009C044(void) {
    struct UnkStruct_80027C00* sp24;
    s32 sp20;

    if (D_80165100->unk0 == 0x41) {
        sp24 = &D_80113550;
    } else if (D_80165100->unk0 == 0x42) {
        sp24 = &D_8011355C;
    } else if (D_80165100->unk0 == 0x43) {
        sp24 = &D_80113568;
    } else {
        sp24 = &D_80113574;
    }
    sp20 = func_80027464(1, sp24, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp20 != -1) {
        gObjects[sp20].unkA6 = D_80165100->unkA;
    }
}

void func_8009C18C(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].action_state = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    } else if (D_80177A64 == 1) {
    } else {
    }
}

void func_8009C224(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, -60.0f, 0.0f) != 0) {
            sp2C->unk13A = 1;
        }
    }
}

extern u32 D_80116A88;

void func_8009C2E0(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unk108 = 0;
        sp3C->unk13A = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x42, &D_80116A88);
        if (sp3C->obj_id == 0x42) {
            func_800941C4((s32) sp3C->unkA6, sp3C->Pos.x, sp3C->Pos.y + 60.0f, sp3C->Pos.z);
        } else if (sp3C->obj_id == 0x43) {
            if ((D_801775F6 != 0) && (Math_Random(0x64) < 0x32)) {
                sp38 = D_8011486C[0].unk0_1[Math_Random(4)] - 0x20;
                func_800941C4(sp38, sp3C->Pos.x, sp3C->Pos.y + 60.0f, sp3C->Pos.z);
            }
        } else if (sp3C->obj_id == 0x44) {
            func_8009BBC4(sp3C->Pos.x, sp3C->Pos.y + 60.0f, sp3C->Pos.z, func_8002A46C(gCurrentParsedObject));
        }
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_8009C50C(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_8009C224();
            break;
        case 2:
            func_8009C2E0();
            break;
    }
}

void func_8009C598(void) {
    s32 sp24;
    s32 sp20;

    sp24 = func_80027464(2, &D_8011358C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        sp20 = gObjects[sp24].unkE8[0];
        gObjects[sp20].Pos.x = gObjects[sp24].Pos.x - 210.0f;
        gObjects[sp20].Pos.y = gObjects[sp24].Pos.y - 180.0f;
        gObjects[sp20].Pos.z = gObjects[sp24].Pos.z - 20.0f;
    }
}

void func_8009C74C(void) {
    if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].action_state = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

extern UNK_TYPE D_80116A50;

void func_8009C7C4(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80116A50);
    }
}

void func_8009C85C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80116A50 + 7);
        sp1C->unk108 = -1;
        gObjects[sp1C->unkE8[0]].action_state = 2;
        gObjects[sp1C->unkE8[0]].unk132 = 0;
        func_800281A4(gCurrentParsedObject, 0);
    }
}

void func_8009C96C(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_8009C7C4();
            break;
        case 2:
            func_8009C85C();
            break;
    }
}

extern UNK_TYPE D_80116A18;

void func_8009C9F8(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80116A18);
    }
}

extern u32 D_801169FC;

void func_8009CA90(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xF8, &D_801169FC);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_8009CB58(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_8009C9F8();
            break;
        case 2:
            func_8009CA90();
            break;
    }
}

extern UNK_TYPE D_80116AB8;

void func_8009CBE4(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801135A4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_80116AB8);
}

void func_8009CC78(void) {
}

extern struct UnkStruct8011486C D_8011486E[];
extern struct UnkStruct8011486C D_80114874[];
extern struct ShortPair D_80114890[];
extern struct ShortPair D_80114892[];
extern struct ShortPair D_801148A4[];

void func_8009CC88(void) {
    struct ObjectStruct* sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;

    sp4C = &gObjects[gCurrentParsedObject];
    if (sp4C->unk132 == 0) {
        sp4C->unk132 += 1;
    }
    if (sp4C->unk132 == 1) {
        for (sp38 = 0; sp38 < 4; sp38++) {
            func_80067748((f32) D_801148A4[sp38].unk0 + sp4C->Pos.x, sp4C->Pos.y - 60.0f,
                          (f32) D_801148A4[sp38].unk2 + sp4C->Pos.z);
            if (D_80177740[D_801776E0 & 1] == 0xE5) {
                sp4C->unkB2 += 1;
            } else if (D_80177740[D_801776E0 & 1] == 0xE4) {
                sp4C->unkB4 += 1;
            }
        }
    }
    if (sp4C->unkB2 == 4) {
        if (sp4C->unk132 == 1) {
            if (sp4C->Rot.x == 0.0f) {
                sp34 = func_80027464(1, &D_801135B0, sp4C->Pos.x, sp4C->Pos.y, sp4C->Pos.z + 55.0f, sp4C->Rot.y);
                func_800175F0(gCurrentParsedObject, 0, 0x3E, -1, 0);
            } else {
                sp34 = func_80027464(1, &D_801135B0, sp4C->Pos.x, sp4C->Pos.y + 55.0f, sp4C->Pos.z, sp4C->Rot.y);
                func_800175F0(gCurrentParsedObject, 0, 0x3E, -1, 0);
            }
            gObjects[sp34].unkA6 = (s16) gCurrentParsedObject;
            func_80026F10(sp34, gCurrentParsedObject);
            sp4C->unk132 += 1;
            gObjects[sp34].Rot.x = sp4C->Rot.x;
            sp34 = Get_ObjIdx_ById(0x190);
            gObjects[sp34].unkB2 += 1;
            sp4C->unkA8 = 1;
        }
    } else {
        sp4C->unkB2 = 0;
    }
    if (sp4C->unkB4 == 4) {
        if (sp4C->unk132 == 1) {
            sp4C->unkA8 = 0x3D;
            sp4C->unk132 += 1;
        }
    } else {
        sp4C->unkB4 = 0;
    }
    if (sp4C->unkA8 == 0) {
        if (sp4C->unkA6 == 1) {
            sp4C->Pos.z += 4.0f;
        } else if (sp4C->unkA6 == 2) {
            sp4C->Pos.x += 4.0f;
        } else if (sp4C->unkA6 == 3) {
            sp4C->Pos.z -= 4.0f;
        } else if (sp4C->unkA6 == 4) {
            sp4C->Pos.x -= 4.0f;
        }
        if (sp4C->unkA6 != 0) {
            func_800175F0(gCurrentParsedObject, 0, 0x34, -1, 0);
        }
    } else if (sp4C->unkA8 == 1) {
        if (sp4C->unkB2 != 4) {
            sp4C->unk132 = 1;
            sp4C->unkA8 = 0;
            sp4C->unkB2 = 0;
            sp4C->unkB4 = 0;
        }
    } else {
        sp4C->Pos.z += 4.0f;
        sp4C->unkA8 -= 1;
    }
    if (sp4C->unkA6 != 0) {
        for (sp38 = 0; sp38 < 2; sp38++) {
            sp3C = func_800293B8((s16) (D_80114874[sp4C->unkA6].unk0_2[sp38 - 2].unk0) + sp4C->Pos.x,
                                 sp4C->Pos.y - 60.0f, ((s16) D_80114874[sp4C->unkA6].unk0_0[sp38 - 2]) + sp4C->Pos.z,
                                 (f32) D_80114890[sp4C->unkA6].unk0, 0.0f, (f32) D_80114892[sp4C->unkA6].unk0, &sp48,
                                 &sp44, &sp40, 0x1E);

            if (sp3C == 1) {
                sp4C->Pos.x = sp48 - D_8011486C[sp4C->unkA6].unk0_2[sp38].unk0;
                sp4C->Pos.y = sp44;
                sp4C->Pos.z = sp40 - D_8011486E[sp4C->unkA6].unk0_2[sp38].unk0;
            }
        }
    }
    sp4C->unkD4 -= 2.0f;
    sp4C->Pos.y += sp4C->unkD4;

    for (sp38 = 0; sp38 < 4; sp38++) {
        func_80067748((f32) D_801148A4[sp38].unk0 + sp4C->Pos.x, sp4C->Pos.y - 60.0f,
                      (f32) D_801148A4[sp38].unk2 + sp4C->Pos.z);

        if (D_801776E0 & 1) {
            sp4C->Pos.y = D_80177760[D_801776E0 & 1] + 60.0f;
            sp4C->unkD4 = 0.0f;
            break;
        }
    }

    sp4C->unkA6 = 0;
}

void func_8009D4EC(void) {
    if (gObjects[gCurrentParsedObject].action_state == 1) {
        if (FALSE) {}
        func_8009CC88();
    } else {
    }
}

void func_8009D558(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801135BC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_80116AB8);
    gObjects[sp24].Rot.x = 270.0f;
}

extern u32 D_80116AF0;

void func_8009D618(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x109, &D_80116AF0);
    }
    if ((func_8001B62C(gCurrentParsedObject, 3) > 26.0f) && (sp24->unk132 == 1)) {
        sp24->unk132 += 1;
        func_8001ABF4((s32) sp24->unkA6, 0, 0, &D_80116AB8 + 7);
    }
    if (func_8001B4AC(gCurrentParsedObject, 3) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_8009D75C(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_80027464(1, &D_801135D4, arg0, arg1, arg2, arg3);
}

void func_8007EE40(f32, f32, f32, f32); /* extern */

void func_8009D7B4(void) {
    struct ObjectStruct* sp1C;
    s32 sp18;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->action_state == 1) {
        if (FALSE) {}
        if (sp1C->unk132 == 0) {
            func_80019448(gCurrentParsedObject, 2, 0, 1);
            sp1C->Rot.x = 20.0f;
            sp1C->unk132 = 1;
            sp1C->unk44 = 15.0f;
            sp1C->unk3C = sp1C->Rot.y;
            sp1C->unk40 = 340.0f;
        }
        func_80029D8C(gCurrentParsedObject);
        if (!(sp1C->unkA6 & 3)) {
            func_80081468(0x2BD, sp1C->Pos.x, sp1C->Pos.y, sp1C->Pos.z);
        }
        sp1C->unkA6 += 1;
        if (sp1C->Pos.z < -420.0f) {
            func_8007EE40(sp1C->Pos.x, sp1C->Pos.y, sp1C->Pos.z, 2.0f);
            func_8002B0E4(gCurrentParsedObject);
            sp18 = Get_ObjIdx_ById(0xFB);
            gObjects[sp18].action_state = 5;
            gObjects[sp18].unk132 = 0;
        }
    } else {
    }
}

void func_8009D9BC(f32 arg0, f32 arg1, f32 arg2) {
    s32 sp24;

    sp24 = func_80027464(3, &D_801135E0, arg0, arg1, arg2, 180.0f);
    if (sp24 != -1) {
        func_80027B34(sp24, &D_8011485C);
    }
}

extern f32 D_801148F8;

void func_8009DA38(void) {
    struct ObjectStruct* sp44;
    s32 sp40;
    s32 sp3C;

    sp44 = &gObjects[gCurrentParsedObject];
    switch (sp44->action_state) {
        case 1:
            if (sp44->unk132 == 0) {
                sp44->unk132 = 1;
                sp40 = (s32) sp44->unkE8[0];
                sp3C = (s32) sp44->unkE8[1];
                func_8001C0EC(gCurrentParsedObject, 3, 1, 0xA5, &D_80116950);
                func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011698C + 14);
                func_8001ABF4(gCurrentParsedObject, 1, 0, &D_8011698C + 21);
                func_80019448(gCurrentParsedObject, 2, 0, 1);
                func_80019448(sp40, 2, 0, 1);
                func_80019448(sp3C, 2, 0, 1);
                sp44->Rot.x = 20.0f;
                func_800175F0(gCurrentParsedObject, 0, 0x2C, -1, 0);
            }
            sp44->Pos.y -= 5.0f;
            if (sp44->Pos.y < D_801148F8) {
                sp44->action_state = 2;
                sp44->unk132 = 0;
            }
            break;
        case 2:
            sp44->Pos.y -= 1.0f;
            sp44->Rot.y = func_80015538(sp44->Rot.y, -2.0f);
            if (sp44->Rot.y == 170.0f) {
                sp44->action_state = 3;
                sp44->unk132 = 0;
            }
            break;
        case 3:
            if (sp44->unk132 == 0) {
                sp44->unk132 = 1;
                func_8009D75C(sp44->Pos.x, sp44->Pos.y - 120.0f, sp44->Pos.z, sp44->Rot.y);
            }
            sp44->Pos.z += 3.0f;
            sp44->Pos.x -= 6.0f;
            sp44->Pos.y += 2.0f;
            if (sp44->Pos.x < -600.0f) {
                sp44->action_state = 4;
                sp40 = (s32) sp44->unkE8[0];
                sp3C = (s32) sp44->unkE8[1];
                func_800281A4(gCurrentParsedObject, 0);
                func_800281A4(gCurrentParsedObject, 1);
                func_8002B0E4(sp40);
                func_8002B0E4(sp3C);
                func_8002B0E4(gCurrentParsedObject);
            }
            break;
    }
    sp40 = (s32) sp44->unkE8[0];
    sp3C = (s32) sp44->unkE8[1];
    if ((sp40 != -1) && (sp3C != -1)) {
        gObjects[sp40].Pos.x = gObjects[sp3C].Pos.x = sp44->Pos.x;
        gObjects[sp40].Pos.y = gObjects[sp3C].Pos.y = sp44->Pos.y;
        gObjects[sp40].Pos.z = gObjects[sp3C].Pos.z = sp44->Pos.z;
        gObjects[sp40].Rot.y = gObjects[sp3C].Rot.y = sp44->Rot.y;
        gObjects[sp40].Rot.x = gObjects[sp3C].Rot.x = sp44->Rot.x;
    }
}

void func_8009DFF0(void) {
    func_80027464(1, &D_80113604, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_8009E068(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1;
    }
    if (gPlayerObject->Pos.z < 180.0f) {
        sp4->action_state = 2;
        sp4->unk132 = 0;
    }
}

void func_8009E10C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unkA6 = 0;
    }
    if (sp1C->unkA6 < 0xA) {
        sp1C->unkA6 += 1;
        sp1C->Pos.y += 43.0f;
    } else {
        sp1C->action_state = 3;
        sp1C->unk132 = 0;
        func_800941C4(8, 90.0f, 2230.0f, -60.0f);
    }
}

void func_8009E20C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
    }
    if (D_80165246 != 0) {
        D_80165246 = 0;
        sp1C->unkA8 = 1;
        func_8009D9BC(-120.0f, 2800.0f, 0.0f);
    }
    if (gPlayerObject->Pos.z > 900.0f) {
        sp1C->action_state = 4;
        sp1C->unk132 = 0;
    }
}

void func_8009E2FC(void) {
    struct ObjectStruct* sp1C;
    s32 sp18;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unkA6 = 0;
    }
    if (sp1C->unkA6 < 0xA) {
        sp1C->unkA6 += 1;
        sp1C->Pos.y -= 43.0f;
    } else {
        sp1C->action_state = 1;
        sp1C->unk132 = 0;
        sp18 = Get_ObjIdx_ById(0x28);
        if (sp18 != -1) {
            func_8002B0E4(sp18);
        }
    }
}

extern u32 D_80116AF4;

void func_8009E40C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x12F, &D_80116AF4);
        func_800175F0(gCurrentParsedObject, 0, 0x67, -1, 0);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        sp24->unkA8 = 0;
    }
}

#ifdef NEEDS_RODATA
extern void ResetActiveController(); /* extern */

void func_8009E4F0(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_8009E068();
            break;
        case 2:
            func_8009E10C();
            break;
        case 3:
            func_8009E20C();
            break;
        case 4:
            func_8009E2FC();
            break;
        case 5:
            func_8009E40C();
            break;
    }
    if (gObjects[gCurrentParsedObject].unkA8 != 0) {
        ResetActiveController();
    }
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E4F0.s")
#endif

void func_8009E5F4(void) {
    func_80027464(1, &D_80113610, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_8009E66C(void) {
}

extern struct UnkStruct8004A2A4 D_80116B60[]; // Maybe?

void func_8009E67C(void) {
    s32 sp24;
    s32 sp20;

    sp24 = func_80027464(1, &D_80113658, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        sp20 = D_80165100->unkA * 4;
        func_8001ABF4(sp24, 0, 0, &D_80116B60[sp20].unk0);
        func_8001ABF4(sp24, 1, 0, &D_80116B60[sp20].unk0 + 7);
        func_8001ABF4(sp24, 2, 0, &D_80116B60[sp20].unk0 + 14);
        func_8001ABF4(sp24, 3, 0, &D_80116B60[sp20].unk0 + 21);
    }
}

void func_8009E7E0(void) {
}

void func_8009E7F0(void) {
    struct UnkStruct_80027C00* sp2C;
    s32 sp28;
    s32 sp24;

    if (D_80165100->unk0 == 0x5D) {
        sp2C = &D_8011367C;
        sp24 = -1;
    } else {
        sp2C = &D_80113688;
        sp24 = 1;
    }
    sp28 = func_80027464(1, sp2C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp28 != -1) {
        gObjects[sp28].unkA6 = D_80165100->unkA * 0x3C;
        gObjects[sp28].unkA8 = (s16) sp24;
        gObjects[sp28].unkAA = D_80165100->unkC;
    }
}

void func_8009E954(void) {
    if ((D_80177A64 == 1) && (gObjects[gCurrentParsedObject].action_state) == 1) {
        gObjects[gCurrentParsedObject].action_state = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

extern UNK_TYPE D_80116E50;

void func_8009EA00(struct ObjectStruct* arg0) {
    s32* sp24;

    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        arg0->unk108 = 1;
        if (arg0->obj_id == 0x5D) {
            sp24 = &D_80116E50;
        } else {
            sp24 = &D_80116E50 + 14;
        }
        func_8001ABF4(gCurrentParsedObject, 0, 0, sp24);
        arg0->Vel.x = arg0->Vel.y = arg0->Vel.z = 0.0f;
    }
}

void func_8009EAEC(struct ObjectStruct* arg0) {
    s32* sp1C;

    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        arg0->unk108 = -1;
        arg0->unkAC = 0;
        if (arg0->obj_id == 0x5D) {
            sp1C = &D_80116E50 + 7;
        } else {
            sp1C = &D_80116E50 + 21;
        }
        func_8001ABF4(gCurrentParsedObject, 0, 0, sp1C);
    }
    arg0->Vel.y = (f32) (arg0->unkAA * arg0->unkA8);
    arg0->unkAC = (s16) (arg0->unkAC + arg0->unkAA);
    if (arg0->unkAC >= arg0->unkA6) {
        arg0->unkA8 = (s16) -arg0->unkA8;
        arg0->action_state = 1;
        arg0->unk132 = 0U;
    }
}

void func_8009EC44(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];

    switch (sp24->action_state) {
        case 1:
            func_8009EA00(sp24);
            break;
        case 2:
            func_8009EAEC(sp24);
            break;
    }
}

void func_8009ECE8(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801136A0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_80019448(sp24, 2, 0, 1);
    }
}

void func_8009ED88(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801136AC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].Rot.x = 90.0f;
        func_80019448(sp24, 2, 0, 1);
    }
}

void func_8009EE54(struct ObjectStruct* arg0) {

    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        arg0->unk102 = 0;
        arg0->Vel.x = arg0->Vel.y = arg0->Vel.z = 0.0f;
    }
    if (func_8002A1FC(gCurrentParsedObject, 600.0f) != 0) {
        arg0->action_state = 2;
        arg0->unk132 = 0U;
    }
}

void func_8009EF20(struct ObjectStruct* arg0) {

    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        arg0->unk102 = 0;
        arg0->unkA6 = 0;
        arg0->unk44 = 40.0f;
        if (arg0->obj_id == 0x169) {
            arg0->unk3C = 0.0f;
            arg0->unk40 = 90.0f;
        } else {
            arg0->unk3C = (f32) arg0->Rot.y;
            arg0->unk40 = 0.0f;
        }
        func_800175F0(gCurrentParsedObject, 0, 0x22, -1, 0);
    }
    func_80029D8C(gCurrentParsedObject);
    if (arg0->unkA6 == 6) {
        arg0->action_state = 3;
        arg0->unk132 = 0U;
        arg0->Vel.x = arg0->Vel.y = arg0->Vel.z = 0.0f;
    } else {
        arg0->unkA6 = (s16) (arg0->unkA6 + 1);
    }
}

void func_8009F0B0(struct ObjectStruct* arg0) {

    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        arg0->unk102 = 1;
        arg0->unkA6 = 0;
        arg0->Vel.x = arg0->Vel.y = arg0->Vel.z = 0.0f;
    }
    if (arg0->unkA6 == 0xF) {
        arg0->action_state = 4;
        arg0->unk132 = 0U;
    } else {
        arg0->unkA6 = (s16) (arg0->unkA6 + 1);
    }
}

void func_8009F13C(struct ObjectStruct* arg0) {
    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        arg0->unk102 = 1;
        arg0->unkA6 = 0;
        arg0->unk44 = -40.0f;
        if (arg0->obj_id == 0x169) {
            arg0->unk3C = 0.0f;
            arg0->unk40 = 90.0f;
        } else {
            arg0->unk3C = (f32) arg0->Rot.y;
            arg0->unk40 = 0.0f;
        }
    }
    func_80029D8C(gCurrentParsedObject);
    if (arg0->unkA6 == 6) {
        arg0->action_state = 5;
        arg0->unk132 = 0U;
        arg0->Vel.x = arg0->Vel.y = arg0->Vel.z = 0.0f;
    } else {
        arg0->unkA6 = (s16) (arg0->unkA6 + 1);
    }
}

void func_8009F2B0(struct ObjectStruct* arg0) {
    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
        arg0->unk102 = 0;
        arg0->unkA6 = 0;
        arg0->Vel.x = arg0->Vel.y = arg0->Vel.z = 0.0f;
    }
    if (arg0->unkA6 == 0x3C) {
        arg0->action_state = 2;
        arg0->unk132 = 0;
        return;
    } else {
        arg0->unkA6 = (s16) (arg0->unkA6 + 1);
    }

    if (func_8002A1FC(gCurrentParsedObject, 600.0f) == 0) {
        arg0->action_state = 1;
        arg0->unk132 = 0U;
        return;
    }
}

#ifdef NEEDS_RODATA
void func_8009F3E8(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    switch (sp1C->action_state) {
        case 1:
            func_8009EE54(sp1C);
            break;
        case 2:
            func_8009EF20(sp1C);
            break;
        case 3:
            func_8009F0B0(sp1C);
            break;
        case 4:
            func_8009F13C(sp1C);
            break;
        case 5:
            func_8009F2B0(sp1C);
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F3E8.s")
#endif

void func_8009F4D4(void) {
    func_80027464(1, &D_801136B8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_8009F54C(void) {
    if (D_80177A64 == 0) {
    } else {

        if (D_80177A64 == 1) {
        } else {
        }
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_8009F5BC(struct ObjectStruct* arg0) {
    if (arg0->unk132 == 0) {
        arg0->unk132 = (u8) (arg0->unk132 + 1);
    }
}

void func_8009F5EC(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->action_state == 1) {
        if (FALSE) {}
        func_8009F5BC(sp1C);
    } else {
    }
}

void func_8009F66C(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011382C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, 0.0f);
    if (sp24 != -1) {
        gObjects[sp24].unk40 = 270.0f;
    }
}

void func_8009F71C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unkD4 = 20.0f;
        sp1C->unk40 = func_80015538(sp1C->unk40, 180.0f);
        sp1C->unk48 = 0.5f;
        sp1C->unk44 = 0.0f;
        sp1C->unk3C = sp1C->unk44;
    }
    func_80029D04(gCurrentParsedObject);
    sp1C->unkD4 -= sp1C->unk48;
    if (sp1C->unkD4 <= 0.0f) {
        sp1C->action_state = 3;
        sp1C->unk132 = 0;
    }
    if (sp1C->unkA6 != 0) {
        sp1C->action_state = 2;
        sp1C->unk132 = 0;
    }
}

void func_8009F890(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unkD8 = sp1C->unk40;
        sp1C->unkDC = sp1C->unk48;
        sp1C->unk48 = 3.0f;
        sp1C->unkAC = -1;
        sp1C->unkAA = 0;
        sp1C->unk44 = 0.0f;
        sp1C->unk3C = sp1C->unk44;
    }
    if ((sp1C->unkA6 == 0) && (sp1C->unkAC == 1)) {
        sp1C->unk40 = 90.0f;
        sp1C->unk48 = 3.0f;
        sp1C->unkAC = -1;
    }
    if ((sp1C->unkA6 != 0) && (sp1C->unkAC == -1)) {
        sp1C->unk40 = 270.0f;
        sp1C->unk48 = 3.0f;
        sp1C->unkAC = 1;
    }
    if (sp1C->unkA6 != 0) {
        sp1C->unkA6 = 0;
    }
    func_80029D04(gCurrentParsedObject);
    sp1C->unkAA = (s16) (s32) ((f32) sp1C->unkAA + (sp1C->unk48 * (f32) sp1C->unkAC));
    if (sp1C->unkAA == 0) {
        sp1C->action_state = 1;
        sp1C->unk40 = sp1C->unkD8;
        sp1C->unk48 = sp1C->unkDC;
    }
}

void func_8009FB08(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 += 1;
        sp4->unkA8 = 2;
    }
    sp4->Vel.x = sp4->Vel.y = sp4->Vel.z = 0.0f;
    sp4->unkA8 -= 1;
    if ((sp4->unkA8 <= 0) || (sp4->unkA6 != 0)) {
        sp4->action_state = 1;
        sp4->unk132 = 0;
    }
}

void func_8009FC0C(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_8009F71C();
            break;
        case 2:
            func_8009F890();
            break;
        case 3:
            func_8009FB08();
            break;
        default:
            break;
    }
}

void func_8009FCBC(void) {
    func_80027464(1, &D_801136E8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

extern u32 D_80116EE4;

void func_8009FD34(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x1B1, &D_80116EE4);
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z = 0.0f;
    }
}

extern s16 D_801148B4[];
extern s16 D_80116F20[];

void func_8009FE10(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801136F4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, 0.0f);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA * 0x3C;
        if (D_80165100->unkC < 4) {
            gObjects[sp24].unk3C = (f32) D_801148B4[D_80165100->unkC];
            gObjects[sp24].unkAC = 0;
        } else if (D_80165100->unkC < 6) {
            gObjects[sp24].unk40 = (f32) D_801148B4[D_80165100->unkC];
            gObjects[sp24].unkAC = 1;
        } else {
            gObjects[sp24].unkAC = 2;
        }
        func_8001ABF4(sp24, 0, 0, &D_80116F20);
    }
}

void func_800A0034(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkA8 = sp24->unkA6;
        sp24->unk3C = func_80015538(sp24->unk3C, 180.0f);
        sp24->unk40 = func_80015538(sp24->unk40, 180.0f);
        sp24->unk44 = 4.0f;
    }
    if (sp24->unkAC == 0) {
        sp24->unk40 = 0.0f;
        func_80029D8C(gCurrentParsedObject);
        sp24->Vel.y = 0.0f;
    } else if (sp24->unkAC == 1) {
        sp24->unk3C = 0.0f;
        func_80029D8C(gCurrentParsedObject);
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    } else {
        sp24->Vel.x = sp24->Vel.y = sp24->Vel.z = 0.0f;
    }
    if (sp24->unkAC < 2) {
        sp24->unkA8 = (s16) (s32) ((f32) sp24->unkA8 - sp24->unk44);
        if (sp24->unkA8 <= 0) {
            sp24->action_state = 2;
            sp24->unk132 = 0;
        }
    }
}

void func_800A0298(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 += 1;
        sp4->unkAA = 0xF;
    }
    sp4->Vel.x = sp4->Vel.y = sp4->Vel.z = 0.0f;
    sp4->unkAA -= 1;
    if (sp4->unkAA <= 0) {
        sp4->action_state = 1;
        sp4->unk132 = 0;
    }
}

void func_800A038C(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_800A0034();
            break;
        case 2:
            func_800A0298();
            break;
    }
}

void func_800A0418(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011343C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkAE = D_80165100->unkE;
    }
}

void func_800A04D4(void) {
    if ((D_80177A64 == 1) && (gObjects[gCurrentParsedObject].action_state == 1)) {
        gObjects[gCurrentParsedObject].action_state = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800A0580(struct ObjectStruct* arg0) {
    if (arg0->unkA6 == 0) {
        func_8001B6BC(gCurrentParsedObject, 0, 0.0f);
    } else {
        func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
    }
}

void func_800A05EC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AC, &D_80116938);
    }
    func_800A0580(sp24);
}

void func_800A0698(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk108 = 0x20;
        func_800175F0(gCurrentParsedObject, 0, 0x61, -1, 0);
    }
    if (sp24->unk108 == 1) {
        sp24->unkA6 ^= 1;
        func_800A0580(sp24);
        sp24->action_state = 3;
        sp20 = 0xE;

        while (TRUE) {
            sp20 = Get_ObjIdx_ByPos(0x5C, sp20);
            if (sp20 == -1) {
                break;
            }

            if (gObjects[sp20].unkAE == sp24->unkAE) {
                if (gObjects[sp20].action_state == 1) {
                    gObjects[sp20].action_state = 2;
                } else {
                    gObjects[sp20].action_state = 1;
                }
                gObjects[sp20].unk132 = 0;
                break;
            }
            sp20++;
        }
    }
}

void func_800A08B4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AC, &D_80116938);
    }
    func_800A0580(sp24);
}

void func_800A0960(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_800A05EC();
            break;
        case 2:
            func_800A0698();
            break;
        case 3:
            func_800A08B4();
            break;
    }
}

extern s16 D_801148C0[];

void func_800A0A08(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113448, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, 0.0f);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA * 0x3C;
        if (D_80165100->unkC < 4) {
            gObjects[sp24].unk3C = (f32) D_801148C0[D_80165100->unkC];
            gObjects[sp24].unkAC = 0;
        } else if (D_80165100->unkC < 6) {
            gObjects[sp24].unk40 = (f32) D_801148C0[D_80165100->unkC];
            gObjects[sp24].unkAC = 1;
        } else {
            gObjects[sp24].unkAC = 2;
        }
        gObjects[sp24].unkA8 = gObjects[sp24].unkA6;
        gObjects[sp24].unk3C = func_80015538(gObjects[sp24].unk3C, 180.0f);
        gObjects[sp24].unk40 = func_80015538(gObjects[sp24].unk40, 180.0f);
        gObjects[sp24].unkAE = D_80165100->unkE;
        func_8001ABF4(sp24, 0, 0, D_8011B92C);
    }
}

void func_800A0D3C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    sp4->Vel.x = sp4->Vel.y = sp4->Vel.z = 0.0f;
}

void func_800A0DAC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 4.0f;
    }
    if (sp24->unkAC == 0) {
        sp24->unk40 = 0.0f;
        func_80029D8C(gCurrentParsedObject);
        sp24->Vel.y = 0.0f;
    } else if (sp24->unkAC == 1) {
        sp24->unk3C = 0.0f;
        func_80029D8C(gCurrentParsedObject);
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    } else {
        sp24->Vel.x = sp24->Vel.y = sp24->Vel.z = 0.0f;
    }
    if (sp24->unkAC < 2) {
        sp24->unkA8 = (s16) (s32) ((f32) sp24->unkA8 - sp24->unk44);
        if (sp24->unkA8 <= 0) {
            sp24->action_state = 3;
        }
    }
}

void func_800A0FA8(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];

    sp4->Vel.x = sp4->Vel.y = sp4->Vel.z = 0.0f;
}

void func_800A1018(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_800A0D3C();
            break;
        case 2:
            func_800A0DAC();
            break;
        case 3:
            func_800A0FA8();
            break;
    }
}

extern u32 D_80117020;

void func_800A10C0(void) {
    s16 sp26;
    s16 sp24;

    sp26 = func_80027464(4, &D_80113844, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].action_state = 1;
        gObjects[sp26].unkA8 = 1;
        gObjects[sp26].unkAA = 1;
        gObjects[sp26].Rot.y = 90.0f;
        gObjects[sp26].unk108 = 0;
        gObjects[sp26].unk100 = -1;
        gObjects[sp26].unk102 = 0;
        gObjects[sp26].unk103 = 1;
        gObjects[sp26].unk132 = 0;
        func_8001BB34((s32) sp26, 1);
        sp24 = gObjects[sp26].unkE8[0];
        gObjects[sp24].action_state = 1;
        gObjects[sp24].unk132 = 0;
        gObjects[sp24].unkA8 = 0;
        gObjects[sp24].unkAA = -0x3C;
        gObjects[sp24].unkAC = 0;
        gObjects[sp24].unk108 = 1;
        func_8001C0EC((s32) sp24, 0, 0, 0x51, &D_80117020);
        sp24 = gObjects[sp26].unkE8[1];
        gObjects[sp24].action_state = 1;
        gObjects[sp24].unk132 = 0;
        gObjects[sp24].unkA8 = 1;
        gObjects[sp24].unkAA = 0x3C;
        gObjects[sp24].unkAC = -0x3C;
        gObjects[sp24].unk108 = 1;
        func_8001C0EC((s32) sp24, 0, 0, 0x51, &D_80117020);
        sp24 = gObjects[sp26].unkE8[2];
        gObjects[sp24].action_state = 1;
        gObjects[sp24].unk132 = 0;
        gObjects[sp24].unkA8 = 2;
        gObjects[sp24].unkAA = 0x3C;
        gObjects[sp24].unkAC = 0x3C;
        gObjects[sp24].unk108 = 1;
        func_8001C0EC((s32) sp24, 0, 0, 0x51, &D_80117020);
    }
}

void func_800A1658(void) {
    UNUSED s16 sp1E;

    sp1E = func_800A169C(0);
    sp1E = func_800A169C(1);
    sp1E = func_800A169C(2);
}

s16 func_800A169C(int arg0) {
    struct ObjectStruct* sp24;
    struct ObjectStruct* sp20;
    s16 sp1E;

    sp24 = &gObjects[gCurrentParsedObject];
    sp1E = sp24->unkE8[(s16) arg0];
    if (sp1E != -1) {
        sp20 = &gObjects[sp1E];

        if ((D_80177A64 == 0)) {
            if ((((!(sp20->unk104 < 2)) && ((sp20->unk104 < 6)))) || (!(sp20->unk104 < 6) && (sp20->unk104 < 0xE))) {

                func_800281A4(gCurrentParsedObject, (s16) arg0);

                sp20->unk108 = 0;

                sp20->action_state = 2;

                sp20->unk132 = 0;
            }
        }
    }
    return sp1E;
}

s16 func_800A1DAC(); /* extern */

void func_800A17E8(void) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 8.0f;
        sp24->unk3C = func_80015538(360.0f, (f32) (sp24->unkA8 * 0x5A));
        sp24->unkA6 = 0x12C;
        func_80017664(gCurrentParsedObject, 0, 0x5C, -1, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unk132 == 1) {
        sp22 = func_8002A800(sp24->Rot.y, sp24->unk3C, 12.0f);
        if (sp22 != 0) {
            sp24->Rot.y = func_80015538(sp24->Rot.y, (f32) (sp22 * 0xC));
        } else {
            sp24->unk132 = 2;
        }
    }
    sp24->unkA6 -= 8;
    if (sp24->unkA6 <= 0) {
        sp24->action_state = 2;
        sp24->unk132 = 0;
        sp24->unkA8 = -sp24->unkA8;
    }
    sp22 = func_800A1DAC();
    if (sp22 == 0) {
        sp24->action_state = 5;
        sp24->unk132 = 0;
    }
}

void func_800A1A0C(void) {
    struct ObjectStruct* sp1C;
    s16 sp1A;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = (s16) (s32) ((f32) ((sp1C->unkA8 * 0x5A) + 0x438) + (360.0f - sp1C->Rot.y));
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->Rot.y = func_80015538(sp1C->Rot.y, 12.0f);
    sp1C->unkA6 -= 0xC;
    if (sp1C->unkA6 <= 0) {
        sp1C->action_state = sp1C->unkAA;
        sp1C->unk132 = 0;
    }
    if ((sp1C->unkAA == 8) && (func_8002A2EC(gCurrentParsedObject, 240.0f) != 0) &&
        (func_8002A3A8(gCurrentParsedObject, 720.0f) != 0)) {
        sp1C->action_state = 4;
        sp1C->unkB0 = 2;
        sp1C->unk132 = 0;
    }
    sp1A = func_800A1DAC();
    if (sp1A == 0) {
        sp1C->action_state = 5;
        sp1C->unk132 = 0;
    }
}

s16 func_800A1C40(s16 arg0) {
    struct ObjectStruct* sp24;
    struct ObjectStruct* sp20;
    s16 sp1E;
    s16 sp1C;

    sp1C = 0;
    sp24 = &gObjects[gCurrentParsedObject];
    sp1E = sp24->unkE8[arg0];
    if (sp1E != -1) {
        sp20 = &gObjects[sp1E];
        sp20->Pos.x = sp24->Pos.x + (f32) sp20->unkAA;
        sp20->Pos.z = sp24->Pos.z + (f32) sp20->unkAC;
        sp20->unk3C = sp24->unk3C;
        sp20->unk40 = sp24->unk40;
        sp20->Pos.y = sp24->Pos.y;
        sp20->Rot.y = sp24->Rot.y;
        sp1C = 1;
        func_80029C40((s32) sp1E);
        func_80029D04((s32) sp1E);
    }
    return sp1C;
}

s16 func_800A1DAC(void) {
    s16 sp26;

    sp26 = 0;
    sp26 += func_800A1C40(0);
    sp26 += func_800A1C40(1);
    sp26 += func_800A1C40(2);
    return sp26;
}

void func_800A1E40(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800A1E70(void) {
}

void func_800A1E80(void) {
}

void func_800A25F0(); /* extern */
void func_800A28AC(); /* extern */

#ifdef NEEDS_RODATA

void func_800A1E90(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].action_state;
    switch (sp1C) {
        case 1:
            func_800A17E8();
            break;
        case 2:
            func_800A1A0C();
            break;
        case 3:
            func_800A1DAC();
            break;
        case 8:
            func_800A28AC();
            break;
        case 4:
            func_800A25F0();
            break;
        case 6:
            func_800A1E70();
            break;
        case 5:
            func_800A1E40();
            break;
        case 7:
            func_800A1E80();
            break;
        default:
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1E90.s")

#endif

void func_800A1FAC(void) {
}

void func_800A1FBC(void) {
    func_8001BB34(gCurrentParsedObject, 0);
    func_8002B0E4(gCurrentParsedObject);
}

void func_800A1FFC(void) {
    if (gObjects[gCurrentParsedObject].action_state == 2) {
        func_800A1FBC();
    }
}

void func_800A2058(void) {
    s16 sp26;
    s16 sp24;

    sp26 = func_80027464(4, &D_80113874, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].action_state = 1;
        gObjects[sp26].unkA8 = 1;
        gObjects[sp26].unkAA = 8;
        gObjects[sp26].unk108 = 0;
        gObjects[sp26].Rot.y = 90.0f;
        gObjects[sp26].unk100 = -1;
        gObjects[sp26].unk102 = 0;
        gObjects[sp26].unk103 = 1;
        gObjects[sp26].unk132 = 0;
        func_8001BB34((s32) sp26, 1);
        sp24 = gObjects[sp26].unkE8[0];
        gObjects[sp24].action_state = 1;
        gObjects[sp24].unk132 = 0;
        gObjects[sp24].unkA8 = 0;
        gObjects[sp24].unkAA = -0x3C;
        gObjects[sp24].unkAC = 0;
        gObjects[sp24].unk108 = 1;
        func_8001C0EC((s32) sp24, 0, 1, 0x51, &D_80117020);
        sp24 = gObjects[sp26].unkE8[1];
        gObjects[sp24].action_state = 1;
        gObjects[sp24].unk132 = 0;
        gObjects[sp24].unkA8 = 1;
        gObjects[sp24].unkAA = 0x3C;
        gObjects[sp24].unkAC = -0x3C;
        gObjects[sp24].unk108 = 1;
        func_8001C0EC((s32) sp24, 0, 1, 0x51, &D_80117020);
        sp24 = gObjects[sp26].unkE8[2];
        gObjects[sp24].action_state = 1;
        gObjects[sp24].unk132 = 0;
        gObjects[sp24].unkA8 = 2;
        gObjects[sp24].unkAA = 0x3C;
        gObjects[sp24].unkAC = 0x3C;
        gObjects[sp24].unk108 = 1;
        func_8001C0EC((s32) sp24, 0, 1, 0x51, &D_80117020);
    }
}

void func_800A25F0(void) {
    struct ObjectStruct* sp24;
    s16 sp22;
    s16 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 8.0f;
        sp24->unk40 = 270.0f;
        if (sp24->unkB0 == 2) {
            func_80029EF8(gCurrentParsedObject, 0.0f, 2.0f);
        } else {
            func_80029EF8(gCurrentParsedObject, 8.0f, 0.98f);
        }
    }
    func_80029C40(gCurrentParsedObject);
    sp24->Rot.y = func_80015538(sp24->Rot.y, 12.0f);
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -30.0f, 60.0f) == 1) {
        sp24->unkB0 -= 1;
        if (sp24->unkB0 > 0) {
            sp24->unk132 = 0;
            return;
        }
        sp24->action_state = 1;
        sp24->unkAA = 1;
        sp24->unk40 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk132 = 0;

        if ((sp22 = sp24->unkE8[0]) != -1) {
            func_8001C0EC((s32) sp22, 0, 0, 0x51, &D_80117020);
        }

        if ((sp22 = sp24->unkE8[1]) != -1) {
            func_8001C0EC((s32) sp22, 0, 0, 0x51, &D_80117020);
        }

        if ((sp22 = sp24->unkE8[2]) != -1) {
            func_8001C0EC((s32) sp22, 0, 0, 0x51, &D_80117020);
        }
    }
    sp20 = func_800A1DAC();
    if (sp20 == 0) {
        sp24->action_state = 5;
        sp24->unk132 = 0;
    }
}

void func_800A28AC(void) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 8.0f;
        sp24->unk3C = func_80015538(360.0f, (f32) (sp24->unkA8 * 0x5A));
        sp24->unkA6 = 0x12C;
        func_80017664(gCurrentParsedObject, 0, 0x5C, -1, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->unkA6 -= 8;
    if (sp24->unkA6 <= 0) {
        sp24->action_state = 2;
        sp24->unk132 = 0;
        sp24->unkA8 = -sp24->unkA8;
    }
    if ((func_8002A2EC(gCurrentParsedObject, 240.0f) != 0) && (func_8002A3A8(gCurrentParsedObject, 720.0f) != 0)) {
        sp24->action_state = 4;
        sp24->unkB0 = 2;
        sp24->unk132 = 0;
    }
    sp22 = func_800A1DAC();
    if (sp22 == 0) {
        sp24->action_state = 5;
        sp24->unk132 = 0;
    }
}

void func_800A2AA4(void) {
    s16 sp2E;

    sp2E = func_80027464(1, &D_801138A4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].Scale.x = 1.5f;
        gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.x;
    }
}

void func_800A2C44(); /* extern */
void func_800A30E8(); /* extern */

void func_800A2BBC(void) {
    s16 sp1E;

    sp1E = gObjects[gCurrentParsedObject].action_state;
    if (sp1E == 1) {
        if (FALSE) {}
        func_800A2C44();
    } else {
        func_800A30E8();
        if (FALSE) {}
    }
}

// Needs Rodata
extern f64 D_80114950;
extern f64 D_80114958;
extern f64 D_80114960;

void func_800A2C44(void) {
    struct ObjectStruct* sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    s16 sp3E;

    sp4C = &gObjects[gCurrentParsedObject];
    if (sp4C->unk132 == 0) {
        sp4C->unk132 = 1;
        sp4C->unk3C = (f32) Math_Random(0x168);
        sp4C->unk44 = 5.0f;
        sp4C->unk40 = 90.0f;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp3E = func_800294F0(gCurrentParsedObject, &sp48, &sp44, 0.0f, 0.0f, 0.0f);
    if (sp3E != 0) {
        sp48 = sp44;
    }
    sp4C->unkA6 = (s16) (s32) func_80015538((f32) sp4C->unkA6, 10.0f);
    sp40 = sinf((f32) ((f64) sp4C->unkA6 * (f64) D_80114950)) * 60.0f;
    sp4C->unk48 = (f32) (((f64) (sp40 + sp48) + D_80114958) - (f64) sp4C->Pos.y);
    if (((s16) sp4C->unkA6 % 180) == 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x12, -1, 0);
    }
    if ((((f64) sp48 + D_80114960) < (f64) sp4C->Pos.y) && (sp4C->unk48 < -60.0f)) {
        sp4C->unk48 = (sp4C->unk54 + sp40) - sp4C->Pos.y;
    }
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 100.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp4C->unkA6 = (s16) (s32) func_80015538((f32) sp4C->unkA6, -10.0f);
    }

    sp4C->Vel.y = (sp4C->Vel.y > 48.0f) ? 48.0f : (sp4C->Vel.y < -48.0F) ? -48.0f : sp4C->Vel.y;
    sp4C->Rot.y = func_8002A46C(gCurrentParsedObject);
}

void func_800A3034(void) {
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        return;
    }
    gObjects[gCurrentParsedObject].action_state = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
    gObjects[gCurrentParsedObject].unk108 = 0;
}

void func_800A30E8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk132 = 1;
        sp24->unk108 = 0;
        func_80029D04(gCurrentParsedObject);
        func_80029EF8(gCurrentParsedObject, 0.0f, 0.98f);
    }
    func_80029C40(gCurrentParsedObject);
    sp24->unk3C = func_80015538(sp24->unk3C, 8.0f);
    sp24->Rot.x = func_80015538(sp24->Rot.x, -8.0f);
    if (sp24->Rot.x < 180.0f) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_800A32E4(void) {
    s16 sp2E;

    sp2E = func_80027464(1, &D_801138B0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].action_state = 1;
        gObjects[sp2E].unk132 = 0;
        gObjects[sp2E].unkA8 = 0x5A;
        gObjects[sp2E].unkAA = 2;
        gObjects[sp2E].Scale.x = 1.5f;
        gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.x;
    }
}

void func_800A3520(); /* extern */
void func_800A39D0(); /* extern */

void func_800A3498(void) {
    s16 sp1E;

    sp1E = gObjects[gCurrentParsedObject].action_state;
    if (sp1E == 1) {
        if (FALSE) {}
        func_800A3520();
    } else {
        func_800A39D0();
        if (FALSE) {}
    }
}

// Needs Rodata
extern f64 D_80114968;
extern f64 D_80114970;
extern f64 D_80114978;

void func_800A3520(void) {
    struct ObjectStruct* sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    s16 sp3E;

    sp4C = &gObjects[gCurrentParsedObject];
    if (sp4C->unk132 == 0) {
        sp4C->unk132 = 1;
        sp4C->unk3C = 0.0f;
        sp4C->unk44 = 0.0f;
        sp4C->unk40 = 90.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    if (((s16) sp4C->unkA6 % 180) == 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x12, -1, 0);
    }
    sp4C->unkA6 += 1;
    sp3E = func_800294F0(gCurrentParsedObject, &sp48, &sp44, 0.0f, 0.0f, 0.0f);
    if (sp3E != 0) {
        sp48 = sp44;
    }

    sp4C->unkA6 = (s16) (s32) func_80015538((f32) sp4C->unkA6, 10.0f);

    sp40 = sinf((f32) ((f64) sp4C->unkA6 * (f64) D_80114968)) * 60.0f;

    sp4C->unk48 = (f32) (((f64) (sp40 + sp48) + D_80114970) - (f64) sp4C->Pos.y);

    if ((((f64) sp48 + D_80114978) < (f64) sp4C->Pos.y) && (sp4C->unk48 < -60.0f)) {
        sp4C->unk48 = (sp4C->unk54 + sp40) - sp4C->Pos.y;
    }

    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 100.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp4C->unkA6 = (s16) (s32) func_80015538((f32) sp4C->unkA6, -10.0f);
    }
    sp4C->Vel.y = RECLAMP_FLOAT(sp4C->Vel.y);
    sp4C->Rot.y = func_8002A46C(gCurrentParsedObject);
}

void func_800A391C(void) {
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        return;
    }
    gObjects[gCurrentParsedObject].action_state = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
    gObjects[gCurrentParsedObject].unk108 = 0;
}

void func_800A39D0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk132 = 1;
        sp24->unk108 = 0;
        func_80029D04(gCurrentParsedObject);
        func_80029EF8(gCurrentParsedObject, 0.0f, 0.98f);
    }
    func_80029C40(gCurrentParsedObject);
    sp24->unk3C = func_80015538(sp24->unk3C, 8.0f);
    sp24->Rot.x = func_80015538(sp24->Rot.x, -8.0f);
    if (sp24->Rot.x < 180.0f) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_800A3BCC(void) {
    s16 sp2E;

    sp2E = func_80027464(1, &D_801138BC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].action_state = 1;
        gObjects[sp2E].unk132 = 0;
        gObjects[sp2E].unkA8 = 0x5A;
        gObjects[sp2E].unkAA = 2;
        gObjects[sp2E].Scale.x = 1.5f;
        gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.x;
    }
}

void func_800A3E28(); /* extern */
void func_800A4178(); /* extern */
void func_800A44E8(); /* extern */

void func_800A3D80(void) {
    s16 sp26;

    sp26 = gObjects[gCurrentParsedObject].action_state;
    switch (sp26) {
        case 1:
            func_800A3E28();
            break;
        case 5:
            func_800A4178();
            break;
        default:
            func_800A44E8();
            break;
    }
}

// Needs Rodata
extern f64 D_80114980;

void func_800A3E28(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk3C = (f32) sp24->unkA8;
        sp24->unk44 = 8.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0x168;
        sp24->unk40 = 90.0f;
        sp24->Pos.y = sp24->unk54;
    }
    sp24->unkA6 = (s16) (s32) func_80015538((f32) sp24->unkA6, -10.0f);
    sp24->unk48 = sinf((f32) ((f64) sp24->unkA6 * (f64) D_80114980)) * 8.0f;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    sp24->Vel.y = RECLAMP_FLOAT(sp24->Vel.y);

    sp24->Rot.y = func_8002A46C(gCurrentParsedObject);
    if (sp24->Vel.y >= 7.0f) {
        sp24->unk132 = 2;
    }
    if ((sp24->Pos.y == sp24->unk54) && (sp24->unk132 == 2)) {
        sp24->unkAA -= 1;
        sp24->action_state = 5;
        sp24->unk132 = 0;
        if (sp24->unkAA <= 0) {
            sp24->action_state = 1;
            sp24->unkA8 = (s16) (s32) func_80015538((f32) sp24->unkA8, 180.0f);
            sp24->unkAA = 2;
            sp24->unk132 = 0;
        }
    }
}

// Needs Rodata
extern f64 D_80114988;

void func_800A4178(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk3C = func_80015538((f32) sp24->unkA8, 180.0f);
        sp24->unk44 = 6.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0x168;
        sp24->unk40 = 90.0f;
        sp24->Pos.y = sp24->unk54;
    }
    sp24->unkA6 = func_80015538((f32) sp24->unkA6, -20.0f);
    sp24->unk48 = sinf((sp24->unkA6 * (f64) D_80114988)) * 6.0f;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    sp24->Vel.y = RECLAMP_FLOAT(sp24->Vel.y);
    sp24->Rot.y = func_8002A46C(gCurrentParsedObject);
    if (sp24->Vel.y >= 5.0f) {
        sp24->unk132 = 2;
    }
    if ((sp24->Pos.y == sp24->unk54) && (sp24->unk132 == 2)) {
        sp24->action_state = 1;
        sp24->unk132 = 0;
    }
}

void func_800A4434(void) {
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        return;
    }
    gObjects[gCurrentParsedObject].action_state = 2;
    gObjects[gCurrentParsedObject].unk132 = 0;
    gObjects[gCurrentParsedObject].unk108 = 0;
}

// Almost there !
void func_800A44E8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk132 = 1;
        sp24->unk108 = 0;
        func_80029D04(gCurrentParsedObject);
        func_80029EF8(gCurrentParsedObject, 0.0f, 0.98f);
    }
    func_80029C40(gCurrentParsedObject);
    sp24->unk3C = func_80015538(sp24->unk3C, 8.0f);
    sp24->Rot.x = func_80015538(sp24->Rot.x, -8.0f);
    if (sp24->Rot.x < 180.0f) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

extern u32 D_80117028;

void func_800A46E4(void) {
    s16 sp2E;

    sp2E = func_80027464(1, &D_801138C8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].Scale.x = 1.5f;
        gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.x;
        gObjects[sp2E].action_state = 1;
        gObjects[sp2E].unkA8 = 0;
        gObjects[sp2E].unk132 = 0;
        func_8001C0EC((s32) sp2E, 0, 0, 0x5F, &D_80117028);
    }
}

void func_800A488C(void) {
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        gObjects[gCurrentParsedObject].unk44 = 0.0f;
        func_80029C40(gCurrentParsedObject);
        return;
    }
    gObjects[gCurrentParsedObject].action_state = 6;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800A4964(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 0;
        sp1C->unkA8 = 0;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkA6 += 1;
    if ((sp1C->unkA6 >= 0x14) && (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0)) {
        sp1C->action_state = 3;
        sp1C->unk132 = 0;
    }
}

void func_800A4AB8(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
    }
    func_8002A8B4(gCurrentParsedObject, 8.0f);
    sp1C->Rot.y = sp1C->unk3C;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8002A560(gCurrentParsedObject, 5.0f) == 0) {
        if (func_8002A1FC(gCurrentParsedObject, 420.0f) != 0) {
            sp1C->action_state = 4;
            sp1C->unk132 = 0;
        }
        if (sp1C->unkA8 == 1) {
            sp1C->action_state = 5;
            sp1C->unk132 = 0;
        }
    } else if ((func_8002A1FC(gCurrentParsedObject, 480.0f) == 0) && (sp1C->unkA8 != 1)) {
        sp1C->action_state = 1;
        sp1C->unk132 = 0;
    }
}

void func_800A4C54(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 2.0f;
        sp34->unk48 = 8.0f;
        sp34->unk40 = 60.0f;
        sp34->unkA6 = 0x1A4;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x5F, &D_80117028);
        func_8001BBDC(gCurrentParsedObject, 0);
        func_800175F0(gCurrentParsedObject, 0, 0x57, -1, 0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp34->unkA6 -= 8;
    if (func_800295C0(gCurrentParsedObject, &sp30, &sp2C, 0.0f, 32.0f, 0.0f) != 0) {
        sp34->action_state = 5;
        sp34->unk132 = 0;
    }
    if (func_80029018(gCurrentParsedObject, 3U, 50.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        if ((D_801651A0 & 0x80) &&
            (((sp34->Pos.y < (sp34->unk54 - 1920.0f))) || ((sp34->unk54 + 1920.0f) < sp34->Pos.y))) {
            sp34->action_state = 6;
            sp34->unk132 = 0;
            return;
        }
    }
    if (sp34->unkA6 <= 0) {
        sp34->action_state = 5;
        sp34->unk132 = 0;
    }
}

void func_800A4F08(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 0.0f;
        sp34->unk48 = 0.0f;
        if (sp34->unkA8 == 0) {
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0x5F, &D_80117028);
            func_8001BBDC(gCurrentParsedObject, 1);
            sp34->action_state = 3;
            sp34->unkA8 = 1;
            sp34->unk132 = 0;
            return;
        }
        func_800175F0(gCurrentParsedObject, 0, 0x30, -1, 0);
        sp34->unk44 = 12.0f;
        sp34->unk48 = 0.0f;
        sp34->unk40 = 60.0f;
        func_80029EF8(gCurrentParsedObject, 0.0f, 0.98f);
    }
    func_80029C40(gCurrentParsedObject);
    sp30 = sp34->Vel.y;
    if (func_80029018(gCurrentParsedObject, 3U, 50.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->unk44 = 4.0f;
        if (D_80177740[D_801776E0 & 1] == 0xF5) {
            sp34->unk44 = 0.0f;
            sp34->Vel.y = sp30;
        }
        if ((D_801651A0 & 0x80) &&
            (((sp34->Pos.y < (sp34->unk54 - 1920.0f))) || ((sp34->unk54 + 1920.0f) < sp34->Pos.y))) {
            sp34->action_state = 6;
            sp34->unk132 = 0;
            return;
        }
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        sp34->action_state = 2;
        sp34->unkA8 = 0;
        sp34->unk44 = 0.0f;
        sp34->unk48 = 0.0f;
        sp34->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
        if (D_80177740[D_801776E0 & 1] == 0xF5) {
            sp34->action_state = 6;
            sp34->unk132 = 0;
        }
    }
}

void func_800A528C(void) {
    struct ObjectStruct* sp34;
    s16 sp32;
    UNUSED s8 sp31;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 4.0f;
        sp34->unk48 = 0.0f;
        sp34->unkA6 = 0x3C;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x5F, &D_80117028);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp34->unkA6 -= 4;
    if (sp34->unkA6 < 0) {
        sp34->action_state = 3;
        sp34->unk132 = 0;
        func_800C00F4(sp34, 0.0f);
    }
    sp32 = func_800C0194((struct UnkStructSTCG*) sp34, 0.0f);
    if (sp32 < -0xB4) {
        sp34->action_state = 5;
        sp34->unkA8 = 1;
        sp34->unk132 = 0;
        func_800C00F4(sp34, 0.0f);
        return;
    }
    sp31 = 0;
    if (func_80029018(gCurrentParsedObject, 3U, 50.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp31 = 1;
        sp34->unk44 = 0.0f;
    }
}

void func_800A54B4(void) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk3C = (f32) Math_Random(0x168);
        sp34->unk44 = 2.0f;
        sp34->unk48 = 0.0f;
        sp34->unkA6 = 0x1A4;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp34->unkA6 -= 2;
    if (sp34->unkA6 < 0) {
        sp34->action_state = 1;
        sp34->unk132 = 0;
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        sp34->action_state = 3;
        sp34->unk132 = 0;
    }
    sp32 = func_800C0194((struct UnkStructSTCG*) sp34, 0.0f);
    if (sp32 < -0xB4) {
        sp34->action_state = 5;
        sp34->unkA8 = 1;
        sp34->unk132 = 0;
        return;
    }
    if (func_80029018(gCurrentParsedObject, 3U, 50.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        if ((D_801651A0 & 0x80) &&
            (((sp34->Pos.y < (sp34->unk54 - 1920.0f))) || ((sp34->unk54 + 1920.0f) < sp34->Pos.y))) {
            sp34->action_state = 6;
            sp34->unk132 = 0;
            return;
        }
    } else {
        func_800C00F4(sp34, 0.0f);
    }
}

extern f64 D_80114990;
extern f32 D_80114998;
extern f32 D_8011499C;
extern f32 D_801149A0;

void func_800A5760(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 12.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk40 = 270.0f;
        sp2C->unk108 = 0;
        sp2C->unkA6 = 0x28;
        func_80029D04(gCurrentParsedObject);
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001BB34(gCurrentParsedObject, 0);
        func_80029EF8(gCurrentParsedObject, 0.0f, 0.14f);
    }
    sp2C->unk3C = func_80015538(sp2C->unk3C, 12.0f);
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->Rot.x = sinf((f32) ((f64) sp2C->unkA6 * (f64) D_80114990)) * 24.0f;
    if (sp2C->unk44 < 0.0f) {
        sp2C->unk44 -= D_80114998;
    } else {
        sp2C->unk44 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    if (sp2C->Scale.x <= D_8011499C) {
        sp2C->Scale.x -= D_801149A0;
        sp2C->Scale.z = sp2C->Scale.y = sp2C->Scale.x;
    }
    sp2C->unkA6 -= 1;
    if (sp2C->unkA6 <= 0) {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if ((sp2C->unk132 == 1) && (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1)) {
        sp2C->unk48 = 0.0f;
        sp2C->unk40 = 0.0f;
        sp2C->unk132 = 2;
        func_80029D04(gCurrentParsedObject);
    }
}

#ifdef NEEDS_RODATA
void func_800A5A80(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].action_state;
    switch (sp1C) {
        case 1:
            func_800A4964();
            break;
        case 3:
            func_800A4AB8();
            break;
        case 4:
            func_800A4C54();
            break;
        case 2:
            func_800A528C();
            break;
        case 5:
            func_800A4F08();
            break;
        case 9:
            func_800A54B4();
            break;
        default:
            func_800A5760();
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A5A80.s")
#endif

extern u32 D_80117088;
extern UNK_TYPE D_80117108;
extern UNK_TYPE D_80117124;
extern u32 D_801171B0;

void func_800A5B74(void) {
    s16 sp26;
    s16 sp24;

    sp26 = func_80027464(2, &D_801138F8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].action_state = 1;
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32) sp26, 0, 1, 0x75, &D_80117088);
        func_8001ABF4((s32) sp26, 0, 0, &D_80117108);
        func_8001ABF4((s32) sp26, 1, 0, &D_80117124);
        sp24 = gObjects[sp26].unkE8[0];
        gObjects[sp24].unk132 = 0;
        func_8001C0EC((s32) sp24, 0, 0, 0x76, &D_801171B0);
        func_8001BB04((s32) sp24, 1);
    }
}

void func_800A5D18(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->action_state = 5;
    } else if (D_80177A64 == 1) {
        sp4->action_state = 6;
    } else {
        return;
    }

    sp4->unk132 = 0;
}

void func_800A5DB4(void) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0x3C;
    }
    sp24->unkA6 += 1;
    if (sp24->unkA6 == 0x28) {
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x75, &D_80117088);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117108);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117124);
        sp22 = sp24->unkE8[0];
        if (sp22 != -1) {
            func_8001C0EC((s32) sp22, 0, 0, 0x76, &D_801171B0);
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp24->Rot.y = sp24->unk3C;
    if (sp24->unkA6 >= 0x3C) {
        if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
            sp24->action_state = 2;
            sp24->unkB0 = 1;
            sp24->unk132 = 0;
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0x75, &D_80117088);
        } else if (sp24->unkA6 >= 0x50) {
            sp24->unk3C = func_8002A46C(gCurrentParsedObject);
            sp24->action_state = 9;
            sp24->unkB0 = 1;
            sp24->unk132 = 0;
        }
    }
}

void func_800A605C(void) {
    struct ObjectStruct* sp34;
    UNUSED s32 pad;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 0.0f;
        sp34->unk48 = 0.0f;
        sp34->unkA6 = 0;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->Rot.y = sp34->unk3C;
    sp34->unkA6 += 1;
    if (sp34->unkA6 >= 0x3C) {
        sp34->action_state = 9;
        sp34->unk132 = 0;
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) == 0) {
        sp34->action_state = 1;
        sp34->unk132 = 0;
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        func_8002A8B4(gCurrentParsedObject, 12.0f);
        if (func_8002A560(gCurrentParsedObject, 15.0f) == 0) {
            sp34->action_state = 3;
            sp34->unkB0 = 2;
            sp34->unk132 = 0;
        }
        sp34->action_state = 3;
        sp34->unkB0 = 2;
        sp34->unk132 = 0;
    }
}

void func_800A62A8(void) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 8.0f;
        sp34->unk48 = 0.0f;
        sp34->unkAE = (s16) (s32) func_80015538(sp34->unk3C, (f32) (Math_Random(-1) * 0x3C));
        sp34->unkAE = (s16) (s32) func_80015538((f32) sp34->unkAE, (f32) Math_Random(-0x1E));
        sp34->unkA6 = Math_Random(0x3C) + 0xB4;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp32 = func_8002A800((f32) sp34->unkAE, sp34->unk3C, 15.0f);
    if (sp32 != 0) {
        sp34->unkAE = (s16) (s32) func_80015538(sp34->unk3C, (f32) (sp32 * 8));
    }
    if (func_80029018(gCurrentParsedObject, 4U, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->unkA6 -= 8;
    sp34->Rot.y = sp34->unk3C;
    if (sp34->unkA6 < 0) {
        sp34->action_state = 2;
        sp34->unkB0 = 9;
        sp34->unk132 = 0;
    }
}

void func_800A6574(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 10.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0x168;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x75, &D_80117088);
        func_800175F0(gCurrentParsedObject, 0, 0x11, -1, 0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp2C->unkA6 = 0;
        sp2C->unk44 = 0.0f;
    }
    sp2C->unkA6 -= 0xA;
    sp2C->Rot.y = sp2C->unk3C;
    if (sp2C->unkA6 < 0) {
        sp2C->action_state = 8;
        sp2C->unkB0 = 3;
        sp2C->unk132 = 0;
    }
}

void func_800A6D1C(struct ObjectStruct*, f32); /* extern */

void func_800A6770(void) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp24 = &gObjects[gCurrentParsedObject];
    sp22 = sp24->unkE8[0];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        sp24->unkAA = -func_8002A560(gCurrentParsedObject, 5.0f);
        sp24->unkAC = 0x4B0;
        if (sp22 != -1) {
            func_8001C0EC((s32) sp22, 0, 0, 0x76, &D_801171B0);
        }
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x75, &D_80117088);
    }
    if (sp24->unkAA == 0) {
        sp24->unkAA = 1;
    }
    sp24->unkA6 += 1;
    if (sp24->unkA6 == 0xA) {
        sp24->unkAA = -sp24->unkAA;
    }

    if ((sp24->unkA6 >= 0x10) && (sp24->unkA6 < 0x21)) {
        sp24->unkAC = sp24->unkAC + 0x5A;
    } else if ((sp24->unkA6 >= 0x21)) {
        if ((sp24->unkAC >= 0)) {
            sp24->unkAC = sp24->unkAC - 0xA5;
        }
    }

    func_800A6D1C(sp24, (sp24->unkAC / 100));
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->Rot.y = sp24->unk3C;
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 9;
        sp24->unkB0 = 8;
        sp24->unk132 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x75, &D_80117088);
    }
}

extern UNK_TYPE D_80117178;
extern UNK_TYPE D_80117194;

void func_800A6A5C(void) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp34 = &gObjects[gCurrentParsedObject];
    sp32 = sp34->unkE8[0];
    if (sp34->unk132 == 0) {
        sp34->unk44 = 0.0f;
        sp34->unk48 = 0.0f;
        sp34->unk132 = 1;
        sp34->unk108 = 0x1E;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0x75, &D_80117088);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117178);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117194);
        if (sp32 != -1) {
            gObjects[sp32].unk108 = 0;
        }
    }
    func_8001BB34(gCurrentParsedObject, !(sp34->unk108 & 1));
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp32 != -1) {
        func_8001BB34((s32) sp32, !(sp34->unk108 & 1));
    }
    if (sp34->unk108 == 1) {
        sp34->unk108 = 1;
        sp34->action_state = 2;
        sp34->unk132 = 0;
        if (sp32 != -1) {
            gObjects[sp32].unk108 = -1;
            func_8001BB34((s32) sp32, 0);
        }
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x75, &D_80117088);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117108);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117124);
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

void func_800A6D0C(void) {
}

void func_800A6D1C(struct ObjectStruct* arg0, f32 arg1) {
    if (arg0->unkAA < 0) {
        arg0->unk3C -= arg1;
    } else if (arg0->unkAA > 0) {
        arg0->unk3C += arg1;
    } else {
        arg0->unk3C = func_8002A46C(gCurrentParsedObject);
    }
    arg0->unk3C = func_80015538(arg0->unk3C, 0.0f);
}

extern UNK_TYPE D_80117140;
extern UNK_TYPE D_8011715C;

void func_800A6DE8(void) {
    struct ObjectStruct* sp34;
    s16 sp32;

    sp34 = &gObjects[gCurrentParsedObject];
    sp32 = sp34->unkE8[0];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unk44 = 0.0f;
        sp34->unk48 = 0.0f;
        sp34->unk108 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x75, &D_80117088);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117140);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_8011715C);
        if (sp32 != -1) {
            func_8001C0EC((s32) sp32, 0, 1, 0x76, &D_801171B0);
            func_8001BB34((s32) sp32, 0);
            gObjects[sp32].unk108 = -1;
        }
        func_8001BB34(gCurrentParsedObject, 0);
        sp34->Rot.y = sp34->unk3C;
    }
    if ((sp32 != -1)) {
        if ((!gObjects[sp32].unk132)) {
            if ((func_8001B44C((s32) sp32, 0))) {
                func_8001BB04((s32) sp32, 0);
                func_8001C0EC((s32) sp32, 0, 2, 0x76, &D_801171B0);
                gObjects[sp32].unk132 = 0xA;
            }
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp34->unk132 == 2) {
        sp34->unk3C = func_80015538(sp34->unk3C, (f32) Math_Random(-0x28));
        sp34->unk44 = (f32) (Math_Random(5) + 2);
        if (func_80029018(gCurrentParsedObject, 4U, 20.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        if (sp34->unk132 == 1) {
            sp34->unk132 = 2;
            func_8001C0EC(gCurrentParsedObject, 0, 4, 0x75, &D_80117088);
            if (sp32 != -1) {
                func_800281A4(gCurrentParsedObject, 0);
            }
        } else {
            func_8002B0E4(gCurrentParsedObject);
            return;
        }
    }
}

#ifdef NEEDS_RODATA
void func_800A7194(void) {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].action_state;
    switch (sp1C) {
        case 1:
            func_800A5DB4();
            break;
        case 2:
            func_800A605C();
            break;
        case 9:
            func_800A62A8();
            break;
        case 3:
            func_800A6574();
            break;
        case 5:
            func_800A6DE8();
            break;
        case 6:
            func_800A6A5C();
            break;
        case 7:
            func_800A6D0C();
            break;
        case 8:
            func_800A6770();
            break;
        default:
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A7194.s")
#endif

void func_800A72B0(void) {
}

extern UNK_TYPE D_80117230;
extern UNK_TYPE D_8011724C;
extern UNK_TYPE D_80117268;
extern UNK_TYPE D_80117284;

void func_800A72C0(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    f32 sp34;
    s16 sp32;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0xA) {
        sp3C->unk132 = 1;
        sp3C->unkA8 = 0;
        sp3C->unk44 = 0.0f;
        sp3C->unk108 = 1;
        sp3C->unk3C = func_80015538(sp3C->unk3C, 180.0f);
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x76, &D_801171B0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117230);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_8011724C);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80117268);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80117284);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    sp3C->Rot.y = func_80015538(sp3C->Rot.y, 45.0f);
    if (sp3C->unk44 <= 10.0f) {
        sp3C->unk44 += 0.75f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 20.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }

    if ((sp32 = func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f)) == 0) {
        if (sp3C->Pos.y > (sp38 + 16.0f)) {
            sp3C->Vel.x = 0.0f;
            sp3C->Vel.z = 0.0f;
            sp3C->unkA8 += 1;
        }
    } else {
        sp3C->Vel.x = 0.0f;
        sp3C->Vel.z = 0.0f;
        sp3C->unkA8 += 1;
    }
    if (func_8001B930(gCurrentParsedObject, 3) != 0) {
        func_8001BC84(gCurrentParsedObject, 0, 1);
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp3C->Pos.x, sp3C->Pos.y, sp3C->Pos.z, 2.2f);
        func_8002B114(gCurrentParsedObject);
    }
}

// Needs Rodata
extern f64 D_801149F0;
extern f64 D_801149F8;

void func_800A7644(void) {
    struct ObjectStruct* sp24;
    struct ObjectStruct* sp20;
    f32 sp1C;

    sp20 = &gObjects[gCurrentParsedObject];
    if (sp20->unkE6[0] != -1) {
        sp24 = &gObjects[sp20->unkE6[0]];
        sp20->Pos.x = sp24->Pos.x;
        sp20->Pos.y = sp24->Pos.y;
        sp20->Pos.z = sp24->Pos.z;
        sp20->unk3C = sp24->unk3C;
        sp20->unk40 = sp24->unk40;
        sp20->Rot.y = sp24->Rot.y;
        if (sp20->unk132 == 0xA) {
            sp1C = func_80015538(sp24->unk3C, 140.0f);
            sp20->Vel.x = sinf((f32) ((f64) sp1C * D_801149F0)) * 90.0f;
            sp20->Vel.z = cosf((f32) ((f64) sp1C * D_801149F8)) * 90.0f;
            sp20->Pos.x = sp24->Pos.x + sp20->Vel.x;
            sp20->Pos.z = sp24->Pos.z + sp20->Vel.z;
            sp20->Rot.y = func_80015538(sp24->Rot.y, -40.0f);
        }
        sp20->unk44 = 0.0f;
        sp20->unk48 = 0.0f;
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
    } else {
        func_800A72C0();
    }
}

void func_800A7894(void) {
    s16 sp26;
    s16 sp24;

    sp26 = func_80027464(2, &D_80113910, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].action_state = 1;
        gObjects[sp26].unkA8 = 0;
        gObjects[sp26].unk132 = 0;
        gObjects[sp26].unk108 = 1;
        sp24 = gObjects[sp26].unkE8[0];
        gObjects[sp24].unk108 = 0;
    }
}

void func_800A7A08(void) {
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        return;
    }
    gObjects[gCurrentParsedObject].action_state = 6;
    gObjects[gCurrentParsedObject].unk132 = 0;
    gObjects[gCurrentParsedObject].unk108 = 0;
}

extern u32 D_801172A0;
extern UNK_TYPE D_801172EC;

void func_800A7ABC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x7F, &D_801172A0);
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_801172EC);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        sp24->action_state = 3;
        sp24->unk132 = 0;
    }
    sp24->Rot.y = sp24->unk3C;
}

void func_800A7C18(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = (f32) (Math_Random(5) + 2);
        sp2C->unk48 = 0.0f;
    }
    func_8002A8B4(gCurrentParsedObject, 8.0f);
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 40.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_8002A560(gCurrentParsedObject, 5.0f) == 0) {
        if (func_8002A1FC(gCurrentParsedObject, 420.0f) != 0) {
            sp2C->action_state = 2;
            sp2C->unk132 = 0;
        }
    } else if (func_8002A1FC(gCurrentParsedObject, 480.0f) == 0) {
        sp2C->action_state = 1;
        sp2C->unk132 = 0;
    }
    sp2C->Rot.y = sp2C->unk3C;
}

// Needs Rodata
extern f64 D_80114A00;
extern f64 D_80114A08;
extern f64 D_80114A10;
extern f64 D_80114A18;

void func_800A7DF0(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    f32 sp34;
    s16 sp32;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = 1;
        sp3C->unkA6 = 0;
        sp3C->unk40 = 90.0f;
        func_800175F0(gCurrentParsedObject, 0, 0x43, -1, 0);
    }
    sp3C->unk44 = (f32) (Math_Random(5) + 2);
    sp3C->Scale.x = (f32) ((f64) Math_Random(-1) + D_80114A00);
    sp3C->Scale.y = (f32) ((f64) Math_Random(-1) + D_80114A08);
    sp3C->Scale.z = (f32) ((f64) Math_Random(-1) + D_80114A10);
    sp3C->unkA8 = (s16) (s32) func_80015538((f32) sp3C->unkA8, 4.0f);
    sp3C->unk48 = sinf((f32) ((f64) sp3C->unkA8 * (f64) D_80114A18)) * 2.0f;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 40.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp32 = func_800295C0(gCurrentParsedObject, &sp38, &sp34, sp3C->Vel.x, sp3C->Vel.y, sp3C->Vel.z);
    if (sp32 != 0) {
        sp38 = sp34;
    }
    if (sp3C->Pos.y <= (sp38 + 60.0f)) {
        sp3C->Pos.y = sp38 + 60.0f;
    }
    sp3C->unkA6 -= 4;
    sp3C->Rot.y = sp3C->unk3C;
    if (sp3C->unkA6 >= 0x3C) {
        sp3C->action_state = 3;
        sp3C->unk132 = 0;
    }
}

extern UNK_TYPE D_801172D0;

void func_800A8144(void) {
    struct ObjectStruct* sp24;
    s16 sp22;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkAE = 2;
        sp24->unkB0 = 0xB4;
        sp24->unk108 = 0;
        func_8001C0EC(gCurrentParsedObject, 3, 1, 0x7F, &D_801172A0);
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->unkB0 -= 1;
    if ((func_8001B44C(gCurrentParsedObject, 3) != 0) || (sp24->unkB0 <= 0)) {
        sp24->unkAE -= 1;
        if (sp24->unkAE <= 0) {
            func_8001BBDC(gCurrentParsedObject, 1);
            sp22 = sp24->unkE8[0];
            func_8001ABF4(gCurrentParsedObject, 0, 3, &D_801172D0);
            if (sp22 != -1) {
                gObjects[sp22].action_state = 1;
                gObjects[sp22].unk132 = 0;
                gObjects[sp22].unk44 = 0.0f;
                gObjects[sp22].unk48 = 0.0f;
                gObjects[sp22].unkB2 = 0x28;
                gObjects[sp22].unk108 = 0;
                func_800281A4(gCurrentParsedObject, 0);
            }
            func_8002B0E4(gCurrentParsedObject);
        }
    }
}

void stub_1() {
}

void stub_2() {
}

void func_800A843C(void) {
    s32 sp24;

    sp24 = gObjects[gCurrentParsedObject].action_state;
    switch (sp24) {
        case 1:
            func_800A7ABC();
            break;
        case 3:
            func_800A7C18();
            break;
        case 2:
            func_800A7DF0();
            break;
        default:
            func_800A8144();
            break;
    }
}

void func_800A8500(void) {
    if ((D_80177A64 == 0) || (D_80177A64 == 1)) {
        gObjects[gCurrentParsedObject].unk108 = 0;
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_800A8580(void) {
    struct ObjectStruct* sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = 1;
        sp44->unk44 = 0.0f;
        sp44->unk3C = func_80015538((f32) (Math_Random(0x165) + 1), 1.0f);
        sp44->unk40 = 270.0f;
        sp44->unk48 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 0.0f, 4.0f);
        func_800272E8(gCurrentParsedObject);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp44->unk44 = 20.0f;
    }
    func_80029C40(gCurrentParsedObject);
    sp44->Rot.y = func_80015538(sp44->Rot.y, 20.0f);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        if (D_801651A0 & 0x80) {
            func_8002B0E4(gCurrentParsedObject);
            return;
        }
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 8.0f, 0.0f, 60.0f) == 1) {
        sp44->action_state = 2;
        sp44->unk132 = 0;
        if (D_80177740[D_801776E0 & 1] == 0xF5) {
            func_8002B0E4(gCurrentParsedObject);
            return;
        }
        func_80016C54(sp44->Pos.x, sp44->Pos.y, sp44->Pos.z, &sp40, &sp3C, &sp38, &sp34);
        if (sp34 > 45.0f) {
            func_8002B0E4(gCurrentParsedObject);
            return;
        }
    }
}

void func_800A8858(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 3.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk40 = 0.0f;
        sp2C->unk108 = 1;
        sp2C->unkA6 = 0;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    } else if (!(sp2C->unkA6 & 0x1F)) {
        sp2C->unk3C = func_80015538(sp2C->unk3C, (f32) Math_Random(-0x14));
        sp2C->unk3C = func_80015538(sp2C->unk3C, 180.0f);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    func_800C00F4(sp2C, 8.0f);
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->unkA6 += 1;
}

void func_800A8A58(void) {
    struct ObjectStruct* sp2C;
    struct ObjectStruct* sp28;

    sp28 = &gObjects[gCurrentParsedObject];
    if (sp28->unkE6[0] != -1) {
        sp2C = &gObjects[sp28->unkE6[0]];
        sp28->Pos.x = sp2C->Pos.x;
        sp28->Pos.y = sp2C->Pos.y;
        sp28->Pos.z = sp2C->Pos.z;
        sp28->unk3C = sp2C->unk3C;
        sp28->unk40 = sp2C->unk40;
        sp28->Rot.y = sp2C->Rot.y;
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
    } else {
        switch (sp28->action_state) {
            case 1:
                func_800A8580();
                break;
            case 2:
                func_800A8858();
                break;
            default:
                func_800A8858();
                break;
        }
    }
}
