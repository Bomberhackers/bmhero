#include <ultra64.h>
#include "functions.h"
#include "types.h"

extern struct UnkStruct_80027C00 D_80113ED4;

void func_800C1380(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113ED4, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].Scale.x = 1.5f;
        gObjects[sp24].Scale.y = 1.5f;
        gObjects[sp24].Scale.z = 1.5f;
    }
}

void func_800C1490(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 6;
    } else if (D_80177A64 == 2) {
        if ((gObjects[gCurrentParsedObject].unkB2 == 0) && (gObjects[gCurrentParsedObject].unkA4 == 3)) {
            gObjects[gCurrentParsedObject].unkB2 = 0x1E;
        }
    }
}

extern u32 D_80117FF0;
extern UNK_TYPE D_80118044;

void func_800C156C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->Vel.x = 0.0f;
        sp24->Vel.y = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->unkB2 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x48, &D_80117FF0);
        if (sp24->unkB6 == 0) {
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118044);
        }
    }
    if (func_8002A1FC(gCurrentParsedObject, 420.0f) != 0) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800C16BC(void) {
    struct ObjectStruct* sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 12.0f, 0.75f);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    sp20 = sp24->Vel.y;
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.x = 0.0f;
        sp24->Vel.z = 0.0f;
    }
    sp24->Vel.y = sp20;
    if ((func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) &&
        (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp24->unk108 = 1;
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
    }
}

void func_800C187C(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unkA6 = 0x64;
        sp3C->unkB0 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x48, &D_80117FF0);
    }
    if (sp3C->unkB2 == 0) {
        sp3C->unk44 = 5.0f;
    } else {
        sp3C->unkB2 -= 1;
        sp3C->unk44 = 0.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp3C->unkB0 = 0xA;
    }
    if (sp3C->unkB0 == 0) {
        sp30 = func_8002A640(gCurrentParsedObject, 10.0f);
        sp3C->Rot.y = func_80015538(sp3C->Rot.y, (sp30 * 0xA));
        sp3C->unk3C = sp3C->Rot.y;
    } else {
        sp3C->unkB0 -= 1;
    }
    sp3C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 40.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) {
        sp3C->Pos.y = sp34;
    } else {
        sp3C->Pos.y = sp38;
    }
    sp3C->unkA6 -= 1;
    if (sp3C->unkA6 == 0) {
        sp3C->unkA4 = 4;
        sp3C->unk132 = 0;
    }
}

extern struct UnkStruct_80027C00 D_80113EE0;

void func_800C1B5C(void) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
        sp34->unkA6 = 0x14;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x48, &D_80117FF0);
        if (sp34->unkB6 == 0) {
            sp34->unkB6 = 1;
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118044 + 7);
        }
    }
    if (sp34->unkA6 == 0) {
        sp30 = func_80027464(1, &D_80113EE0, sp34->Pos.x, sp34->Pos.y + 90.0f, sp34->Pos.z, sp34->Rot.y);
        sp34->unkA6 = 0x14;
    } else {
        sp34->unkA6 -= 1;
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp34->unkA4 = 5;
        sp34->unk132 = 0;
    }
}

void func_800C1D38(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->Vel.x = 0.0f;
        sp24->Vel.y = 0.0f;
        sp24->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0x48, &D_80117FF0);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->unk108 = -1;
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->unkA4 = 1;
        sp24->unk132 = 0;
    }
}

void func_800C1E54(void) {
    func_8002B0E4(gCurrentParsedObject);
}

// NEEDS RODATA
void func_800C1E84(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1:
            func_800C156C();
            break;
        case 2:
            func_800C16BC();
            break;
        case 3:
            func_800C187C();
            break;
        case 4:
            func_800C1B5C();
            break;
        case 5:
            func_800C1D38();
            break;
        case 6:
            func_800C1E54();
            break;
        default:
            break;
    }
}

void func_800C1F64(void) {

    if (D_80177A64 == 2) {
        gObjects[gCurrentParsedObject].unkA6 = 0;
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800C2004(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk44 = 8.0f;
        sp34->unkA6 = (s16) (s32) func_8002A46C(gCurrentParsedObject);
        sp34->unkA6 += Math_Random(0x2D);
        if (sp34->unkA6 >= 0x168) {
            sp34->unkA6 -= 0x168;
        }
        sp34->unk3C = sp34->unkA6;
        func_80029EF8(gCurrentParsedObject, 16.0f, 1.0f);
    }
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->unkA4 = 2;
        sp34->unk132 = 0;
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -15.0f, 15.0f) == 1) {
        sp34->unkA4 = 2;
        sp34->unk132 = 0;
    }
}

void func_800C2230(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
    func_8007EDF4(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 1.0f);
    func_8002B114(gCurrentParsedObject);
}

void func_800C22C4(void) {
    s16 temp_s0;

    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].unkA4) { /* irregular */
            case 1:
                func_800C2004();
                break;
            case 2:
                func_800C2230();
                break;
            default:
                break;
        }
    }
}

extern struct UnkStruct_80027C00 D_80113EEC;

void func_800C238C(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113EEC, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].Scale.x = 1.5f;
        gObjects[sp24].Scale.y = 1.5f;
        gObjects[sp24].Scale.z = 1.5f;
    }
}

void func_800C249C(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 6;
    }
}

void func_800C24EC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->Vel.x = 0.0f;
        sp24->Vel.y = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->unkB2 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x48, &D_80117FF0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118044);
    }
    if (func_8002A1FC(gCurrentParsedObject, 420.0f) != 0) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800C2624(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 17.142857f, 2.142857f);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    sp20 = func_8002A640(gCurrentParsedObject, 10.0f);
    sp24->Rot.y = func_80015538(sp24->Rot.y, (sp20 * 0xA));
    sp24->unk3C = sp24->Rot.y;
    if ((func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) &&
        (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp24->unk108 = 1;
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
    }
}

void func_800C27B0(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk44 = 10.0f;
        sp34->unkA6 = 0x3C;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x48, &D_80117FF0);
        func_800175F0(gCurrentParsedObject, 0, 0x14, -1, 0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp34->Rot.y = sp34->unk3C;
    }
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 40.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp34->Rot.y = sp34->unk3C;
    }
    if (func_800295C0(gCurrentParsedObject, &sp30, &sp2C, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp2C;
    } else {
        sp34->Pos.y = sp30;
    }
    sp34->unkA6 -= 1;
    if (sp34->unkA6 == 0) {
        sp34->unkA4 = 4;
        sp34->unk132 = 0;
    }
}

void func_800C29F4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->Vel.x = 0.0f;
        sp24->Vel.y = 0.0f;
        sp24->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 6, 0x48, &D_80117FF0);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->unkA4 = 5;
        sp24->unk132 = 0;
    }
}

void func_800C2B04(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->Vel.x = 0.0f;
        sp24->Vel.y = 0.0f;
        sp24->Vel.z = 0.0f;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0x48, &D_80117FF0);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->unk108 = -1;
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->unkA4 = 1;
        sp24->unk132 = 0;
    }
}

void func_800C2C30(void) {
    func_8002B0E4(gCurrentParsedObject);
}

// RODATA
void func_800C2C60(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1:
            func_800C24EC();
            break;
        case 2:
            func_800C2624();
            break;
        case 3:
            func_800C27B0();
            break;
        case 4:
            func_800C29F4();
            break;
        case 5:
            func_800C2B04();
            break;
        case 6:
            func_800C2C30();
            break;
        default:
            break;
    }
}

extern struct UnkStruct_80027C00 D_80113EF8;

void func_800C2D40(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113EF8, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].Scale.x = 1.5f;
        gObjects[sp24].Scale.y = 1.5f;
        gObjects[sp24].Scale.z = 1.5f;
    }
}

void func_800C2E50(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 5;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

extern u32 D_801180FC;

void func_800C2EC8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    sp24->unk44 = 0.0f;
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkA6 = 1;
    }
    if (sp24->unkA6 != 0) {
        sp24->unkA6 = 0;
        func_80029EF8(gCurrentParsedObject, 14.378698f, 1.06089f);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x52, &D_801180FC);
        func_80017664(gCurrentParsedObject, 0, 0x56, -1, 0);
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        if (func_8002A1FC(gCurrentParsedObject, 240.0f) != 0) {
            sp24->unkA4 = 2;
            sp24->unk132 = 0;
        } else {
            sp24->unkA6 = 1;
        }
    }
}

void func_800C304C(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    sp24->unk44 = 0.0f;
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_80029EF8(gCurrentParsedObject, 14.378698f, 1.06089f);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x52, &D_801180FC);
        func_80017664(gCurrentParsedObject, 0, 0x56, -1, 0);
    }
    sp20 = func_8002A640(gCurrentParsedObject, 10.0f);
    sp24->Rot.y = func_80015538(sp24->Rot.y, (sp20 * 0xA));
    sp24->unk3C = sp24->Rot.y;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
    }
}

void func_800C31D4(void) {
    struct ObjectStruct* sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 5.0f;
        sp24->unkA6 = 1;
        sp24->unkA8 = 0;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (sp24->unkA6 != 0) {
        sp24->unkA6 = 0;
        func_80029EF8(gCurrentParsedObject, 14.378698f, 1.06089f);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x52, &D_801180FC);
        func_80017664(gCurrentParsedObject, 0, 0x56, -1, 0);
    }
    sp20 = sp24->Vel.y;
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    sp24->Vel.y = sp20;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        sp24->unk3C = sp24->Rot.y;
        sp24->unkA8 += 1;
        if (sp24->unkA8 == 2) {
            sp24->unkA4 = 4;
            sp24->unk132 = 0;
        } else {
            sp24->unkA6 = 1;
        }
    }
}

void func_800C3454(void) {
    struct ObjectStruct* sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 5.0f;
        func_80029EF8(gCurrentParsedObject, 17.647058f, 0.980392f);
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x52, &D_801180FC);
        func_80017664(gCurrentParsedObject, 0, 0x56, -1, 0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp20 = sp24->Vel.y;
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    sp24->Vel.y = sp20;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        sp24->unk44 = 0.0f;
        if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
            sp24->unkA4 = 1;
            sp24->unk132 = 0;
        }
    }
}

void func_800C3670(void) {
    struct ObjectStruct* sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkA6 = 0x1E;
        sp24->unk44 = 5.0f;
        sp24->unk3C = func_80015538(sp24->unk128, 180.0f);
        func_80029EF8(gCurrentParsedObject, 17.647058f, 0.980392f);
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->unk108 = 0;
    }
    sp24->Rot.y = func_80015538(sp24->Rot.y, 25.0f);
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

void func_800C38A8(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1:
            func_800C2EC8();
            break;
        case 2:
            func_800C304C();
            break;
        case 3:
            func_800C31D4();
            break;
        case 4:
            func_800C3454();
            break;
        case 5:
            func_800C3670();
            break;
        default:
            break;
    }
}

extern struct UnkStruct_80027C00 D_80113F10;

void func_800C3978(void) {
    func_80027464(1, &D_80113F10, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);
}

void func_800C39F0(void) {
}

extern u32 D_80118108;
extern UNK_TYPE D_80118138;

void func_800C3A00(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    f32 temp_f20;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138);
    }
    if (func_8002A2EC(gCurrentParsedObject, 720.0f) != 0) {
        sp34->unkA4 = 2;
        sp34->unk132 = 0;
        sp30 = (s32) func_8002A46C(gCurrentParsedObject);
        if (sp30 < 0x2D) {
            sp34->unk3C = 0.0f;
        } else if (sp30 < 0x87) {
            sp34->unk3C = 90.0f;
        } else if (sp30 < 0xE1) {
            sp34->unk3C = 180.0f;
        } else if (sp30 < 0x13B) {
            sp34->unk3C = 270.0f;
        } else {
            sp34->unk3C = 0.0f;
        }
    }
}

void func_800C3C10(void) {
    struct ObjectStruct* sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 10.0f;
        func_80029EF8(gCurrentParsedObject, 20.0f, 2.0f);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138 + 7);
    }
    sp20 = sp24->Vel.y;
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 90.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    sp24->Vel.y = sp20;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -107.0f, 60.0f) == 1) {
        func_800175F0(gCurrentParsedObject, 0, 0x3E, -1, 0);
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
    }
}

void func_800C3E18(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 10.0f, 3.0f);
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -107.0f, 60.0f) == 1) {
        sp24->unkA4 = 4;
        sp24->unk132 = 0;
    }
}

void func_800C3F00(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->Vel.x = 0.0f;
        sp24->Vel.y = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->unkA6 = 0xA;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138);
    }
    if (sp24->unkA6 == 0) {
        sp24->unkA4 = 1;
        sp24->unk132 = 0;
    }
    sp24->unkA6 -= 1;
}

void func_800C4040(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) { /* irregular */
        case 1:
            func_800C3A00();
            break;
        case 2:
            func_800C3C10();
            break;
        case 3:
            func_800C3E18();
            break;
        case 4:
            func_800C3F00();
            break;
        default:
            break;
    }
}

extern struct UnkStruct_80027C00 D_80113F1C;

void func_800C410C(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s16 temp_t4;

    sp2C = func_80027464(3, &D_80113F1C, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);
    if (sp2C != -1) {
        sp28 = (s32) gObjects[sp2C].unkE8[0];
        sp24 = (s32) gObjects[sp2C].unkE8[1];
        gObjects[sp28].Pos.x = 1680.0f;
        gObjects[sp24].Pos.z = 1160.0f;
        gObjects[sp28].Rot.y = 0.0f;
        gObjects[sp28].unk3C = 0.0f;
        gObjects[sp24].Pos.x = 2040.0f;
        gObjects[sp24].Pos.z = 1160.0f;
        gObjects[sp24].Rot.y = 90.0f;
        gObjects[sp24].unk3C = 90.0f;
    }
}

void func_800C4348(void) {
}

void func_800C4358(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    s32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = gObjects[gCurrentParsedObject].unkE8[0];
    sp24 = gObjects[gCurrentParsedObject].unkE8[1];
    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB6 = 0;
        gObjects[sp28].unkB6 = 1;
        gObjects[sp24].unkB6 = 2;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138);
        func_8001C0EC(sp28, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(sp28, 0, 0, &D_80118138);
        func_8001C0EC(sp24, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(sp24, 0, 0, &D_80118138);
    }
    sp2C->unk132 = 0;
    sp2C->unkA4 = 2;
}

extern s16 D_80114D20[];

void func_800C4584(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    s32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    sp30 = gObjects[gCurrentParsedObject].unkE8[0];
    sp2C = gObjects[gCurrentParsedObject].unkE8[1];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138 + 7);
        func_8001C0EC(sp30, 0, 1, 0x55, &D_80118108);
        func_8001ABF4(sp30, 0, 0, &D_80118138 + 7);
        func_8001C0EC(sp2C, 0, 1, 0x55, &D_80118108);
        func_8001ABF4(sp2C, 0, 0, &D_80118138 + 7);
        sp34->unk44 = gObjects[sp30].unk44 = gObjects[sp2C].unk44 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 13.333334f, 1.34f);
        func_80029EF8(sp30, 13.333334f, 1.34f);
        func_80029EF8(sp2C, 13.333334f, 1.34f);
    }
    sp34->Rot.y = sp34->unk3C = func_80015538(sp34->Rot.y, 5.0f);

    gObjects[sp30].Rot.y = gObjects[sp30].unk3C = func_80015538(gObjects[sp30].Rot.y, 5.0f);

    gObjects[sp2C].Rot.y = gObjects[sp2C].unk3C = func_80015538(gObjects[sp2C].Rot.y, 5.0f);

    func_80029F58(sp30, 0.0f, 0.0f, -107.0f, 60.0f);
    func_80029F58(sp2C, 0.0f, 0.0f, -107.0f, 60.0f);
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -107.0f, 60.0f) == 1) {
        func_800175F0(gCurrentParsedObject, 0, 0x3E, -1, 0);
        sp34->unk132 = 0;
        sp34->unkA4 = 3;
        sp34->Rot.y = sp34->unk3C = D_80114D20[sp34->unkB6];
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;

        gObjects[sp30].Rot.y = gObjects[sp30].unk3C = D_80114D20[gObjects[sp30].unkB6];

        gObjects[sp30].Vel.x = gObjects[sp30].Vel.y = gObjects[sp30].Vel.z = 0.0f;

        gObjects[sp2C].Rot.y = gObjects[sp2C].unk3C = D_80114D20[gObjects[sp2C].unkB6];

        gObjects[sp2C].Vel.x = gObjects[sp2C].Vel.y = gObjects[sp2C].Vel.z = 0.0f;
    }
}

// RODATA
extern f32 D_80114D74;

void func_800C4C08(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    s32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    sp30 = gObjects[gCurrentParsedObject].unkE8[0];
    sp2C = gObjects[gCurrentParsedObject].unkE8[1];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk44 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 10.0f, 3.0f);
        func_80029EF8(sp30, 10.0f, 3.0f);
        func_80029EF8(sp2C, 10.0f, 3.0f);
    }
    func_80029F58(sp30, 0.0f, 0.0f, -107.0f, 60.0f);
    func_80029F58(sp2C, 0.0f, 0.0f, -107.0f, 60.0f);
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -107.0f, 60.0f) == 1) {
        sp34->unkA4 = 4;
        sp34->unk132 = 0;

        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z = 0.0f;

        sp34->Pos.y = gObjects[sp30].Pos.y = gObjects[sp2C].Pos.y = 467.0f;

        gObjects[sp30].Vel.x = gObjects[sp30].Vel.y = gObjects[sp30].Vel.z = 0.0f;

        gObjects[sp2C].Vel.x = gObjects[sp2C].Vel.y = gObjects[sp2C].Vel.z = 0.0f;
    }
}

void func_800C4F64(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    s32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = gObjects[gCurrentParsedObject].unkE8[0];
    sp24 = gObjects[gCurrentParsedObject].unkE8[1];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkA6 = 0x14;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138);
        func_8001C0EC(sp28, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(sp28, 0, 0, &D_80118138);
        func_8001C0EC(sp24, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(sp24, 0, 0, &D_80118138);
    }
    if (sp2C->unkA6 == 0) {
        sp2C->unk132 = 0;
        sp2C->unkA4 = 5;
    } else {
        sp2C->unkA6 -= 1;
    }
}

extern s16 D_80114D10[];
extern s16 D_80114D18[];
void func_800C5148(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    s32 sp2C;
    sp34 = &gObjects[gCurrentParsedObject];
    sp30 = (s32) gObjects[gCurrentParsedObject].unkE8[0];
    sp2C = (s32) gObjects[gCurrentParsedObject].unkE8[1];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138 + 7);
        func_8001C0EC(sp30, 0, 1, 0x55, &D_80118108);
        func_8001ABF4(sp30, 0, 0, &D_80118138 + 7);
        func_8001C0EC(sp2C, 0, 1, 0x55, &D_80118108);
        func_8001ABF4(sp2C, 0, 0, &D_80118138 + 7);
        sp34->unk44 = gObjects[sp30].unk44 = gObjects[sp2C].unk44 = 9.0f;
        func_80029EF8(gCurrentParsedObject, 12.000001f, 0.571429f);
        func_80029EF8(sp30, 12.000001f, 0.571429f);
        func_80029EF8(sp2C, 12.000001f, 0.571429f);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029C40(sp30);
    func_80029C40(sp2C);
    func_80029F58(sp30, 0.0f, 0.0f, -107.0f, 60.0f);
    func_80029F58(sp2C, 0.0f, 0.0f, -107.0f, 60.0f);
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -107.0f, 60.0f) == 1) {
        func_800175F0(gCurrentParsedObject, 0, 0x3E, -1, 0);
        sp34->unk132 = 0;
        sp34->unkA4 = 6;
        sp34->Pos.x = D_80114D10[sp34->unkB6];
        sp34->Pos.z = D_80114D18[sp34->unkB6];
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z = 0.0f;
        gObjects[sp30].Pos.x = D_80114D10[gObjects[sp30].unkB6];
        gObjects[sp30].Pos.z = D_80114D18[gObjects[sp30].unkB6];
        gObjects[sp30].Vel.x = gObjects[sp30].Vel.y = gObjects[sp30].Vel.z = 0.0f;
        gObjects[sp2C].Pos.x = D_80114D10[gObjects[sp2C].unkB6];
        gObjects[sp2C].Pos.z = D_80114D18[gObjects[sp2C].unkB6];
        gObjects[sp2C].Vel.x = gObjects[sp2C].Vel.y = gObjects[sp2C].Vel.z = 0.0f;
        sp34->unkB6 += 1;
        if (sp34->unkB6 == 4) {
            sp34->unkB6 = 0;
        }
        gObjects[sp30].unkB6++;
        if (gObjects[sp30].unkB6 == 4) {
            gObjects[sp30].unkB6 = 0;
        }
        gObjects[sp2C].unkB6++;
        if (gObjects[sp2C].unkB6 == 4) {
            gObjects[sp2C].unkB6 = 0;
        }
    }
}

// RODATA
extern f32 D_80114D78;

void func_800C5888(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    s32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    sp30 = gObjects[gCurrentParsedObject].unkE8[0];
    sp2C = gObjects[gCurrentParsedObject].unkE8[1];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk44 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 10.0f, 3.0f);
        func_80029EF8(sp30, 10.0f, 3.0f);
        func_80029EF8(sp2C, 10.0f, 3.0f);
    }
    func_80029F58(sp30, 0.0f, 0.0f, -107.0f, 60.0f);
    func_80029F58(sp2C, 0.0f, 0.0f, -107.0f, 60.0f);
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -107.0f, 60.0f) == 1) {
        sp34->unkA4 = 7;
        sp34->unk132 = 0;

        sp34->Pos.y = gObjects[sp30].Pos.y = gObjects[sp2C].Pos.y = 467.0f;

        sp34->Vel.z = 0.0f;

        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;

        gObjects[sp30].Vel.x = gObjects[sp30].Vel.y = gObjects[sp30].Vel.z = 0.0f;

        gObjects[sp2C].Vel.x = gObjects[sp2C].Vel.y = gObjects[sp2C].Vel.z = 0.0f;
    }
}

void func_800C5BE4(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    s32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = gObjects[gCurrentParsedObject].unkE8[0];
    sp24 = gObjects[gCurrentParsedObject].unkE8[1];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkA6 = 0x14;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118138);
        func_8001C0EC(sp28, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(sp28, 0, 0, &D_80118138);
        func_8001C0EC(sp24, 0, 0, 0x55, &D_80118108);
        func_8001ABF4(sp24, 0, 0, &D_80118138);
    }
    if (sp2C->unkA6 == 0) {
        sp2C->unk132 = 0;
        sp2C->unkA4 = 2;
    } else {
        sp2C->unkA6 -= 1;
    }
}

// RODATA
void func_800C5DC8(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1:
            func_800C4358();
            break;
        case 2:
            func_800C4584();
            break;
        case 3:
            func_800C4C08();
            break;
        case 4:
            func_800C4F64();
            break;
        case 5:
            func_800C5148();
            break;
        case 6:
            func_800C5888();
            break;
        case 7:
            func_800C5BE4();
            break;
        default:
            break;
    }
}

extern struct UnkStruct_80027C00 D_80113F4C;

void func_800C5EB8(void) {
    func_80027464(1, &D_80113F4C, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);
}

void func_800C5F30(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 8;
    }
}

extern u32 D_80118170;

void func_800C5F80(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unkA6 = 0x14;
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x58, &D_80118170);
    }
    if (func_8002A1FC(gCurrentParsedObject, 200.0f) != 0) {
        sp2C->unkA4 = 4;
        sp2C->unk132 = 0;
    } else {
        sp2C->unkA6 -= 1;
        if (sp2C->unkA6 == 0) {
            sp2C->unkA4 = (Math_Random(0xA) & 1) + 2;
            sp2C->unk132 = 0;
        }
    }
}

// RODATA
extern f64 D_80114D98;
extern f64 D_80114DA0;
extern f64 D_80114DA8;
extern f64 D_80114DB0;
extern f64 D_80114DB8;
extern f64 D_80114DC0;

void func_800C60F0(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unkA6 = 0;
        sp2C->unkA8 = 0;
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x58, &D_80118170);
        func_8001BBDC(gCurrentParsedObject, 1);
        func_800175F0(gCurrentParsedObject, 0, 0x17, -1, 0);
    }
    if (sp2C->unkA8 == 0) {
        if (sp2C->unkA6 == 0x1E) {
            sp2C->unkA8 = 1;
        } else {
            sp2C->unkA6 += 1;
            sp2C->Scale.x = (sp2C->Scale.x + 0.05);
            sp2C->Scale.y = (sp2C->Scale.y + 0.05);
            sp2C->Scale.z = (sp2C->Scale.z + 0.05);
        }
    } else if (sp2C->unkA6 == 0) {
        sp2C->unkA4 = 1;
        sp2C->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
    } else {
        sp2C->unkA6 -= 1;
        sp2C->Scale.x = (sp2C->Scale.x - 0.05);
        sp2C->Scale.y = (sp2C->Scale.y - 0.05);
        sp2C->Scale.z = (sp2C->Scale.z - 0.05);
    }
}

void func_800C639C(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    s32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk44 = 3.0f;
        sp34->unkA6 = 1;
        sp34->unkA8 = 0;
        sp34->unkB0 = 0;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp34->unkB0 = 0xA;
    }
    if (sp34->unkA6 != 0) {
        sp34->unkA6 = 0;
        func_80029EF8(gCurrentParsedObject, 6.0f, 0.545455f);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x58, &D_80118170);
    }
    if (sp34->unkB0 == 0) {
        sp2C = func_8002A640(gCurrentParsedObject, 10.0f);
        sp34->Rot.y = func_80015538(sp34->Rot.y, (sp2C * 0xA));
        sp34->unk3C = sp34->Rot.y;
    } else {
        sp34->unkB0 -= 1;
    }
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        if (func_8002A1FC(gCurrentParsedObject, 200.0f) != 0) {
            sp34->unkA4 = 4;
            sp34->unk132 = 0;
        } else if (sp34->unkA8 == 2) {
            sp34->unkA4 = 1;
            sp34->unk132 = 0;
        } else {
            sp34->unkA8 += 1;
            sp34->unkA6 = 1;
        }
    }
}

void func_800C66B4(void) {
    struct ObjectStruct* sp34;
    UNUSED s32 pad;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
        sp34->unkA6 = func_8002A46C(gCurrentParsedObject);
        sp34->unkA8 = func_8002A640(gCurrentParsedObject, 10.0f);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x58, &D_80118170);
    }
    sp2C = sp34->unkA6 - sp34->Rot.y;
    if ((sp2C <= 10.0f) && (sp2C >= -10.0f)) {
        sp34->unkA4 = 5;
        sp34->unk132 = 0;
    } else {
        sp34->Rot.y = func_80015538(sp34->Rot.y, (sp34->unkA8 * 0xA));
        sp34->unk3C = sp34->Rot.y;
    }
}

// RODATA
extern f64 D_80114DC8;
extern f64 D_80114DD0;
extern f64 D_80114DD8;
extern f64 D_80114DE0;
extern f64 D_80114DE8;
extern f64 D_80114DF0;

void func_800C689C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x58, &D_80118170);
        func_8001BBDC(gCurrentParsedObject, 1);
        func_800175F0(gCurrentParsedObject, 0, 0x17, -1, 0);
    }
    if (sp24->unkA8 == 0) {
        if (sp24->unkA6 == 0x1E) {
            sp24->unkA8 += 1;
            func_8001BBDC(gCurrentParsedObject, 0);
        } else {
            sp24->unkA6 += 1;
            sp24->Scale.x = (sp24->Scale.x + 0.05);
            sp24->Scale.y = (sp24->Scale.y + 0.05);
            sp24->Scale.z = (sp24->Scale.z + 0.05);
        }
    } else if (sp24->unkA8 == 1) {
        if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
            sp24->unkA8 += 1;
            func_8001BBDC(gCurrentParsedObject, 1);
        }
    } else if (sp24->unkA6 == 0) {
        sp24->unkA4 = 6;
        sp24->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
    } else {
        sp24->unkA6 -= 1;
        sp24->Scale.x = (sp24->Scale.x - 0.05);
        sp24->Scale.y = (sp24->Scale.y - 0.05);
        sp24->Scale.z = (sp24->Scale.z - 0.05);
    }
}

void func_800C6B8C(void) {
    struct ObjectStruct* sp34;
    s32 pad;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
        sp34->unkA6 = func_8002A46C(gCurrentParsedObject);
        sp34->unkA6 -= 0xB4;
        if (sp34->unkA6 < 0) {
            sp34->unkA6 += 0x168;
        }
        sp34->unkA8 = func_8002A640(gCurrentParsedObject, 10.0f);
        if (sp34->unkA8 == 0) {
            sp34->unkA8 = 1;
        } else {
            sp34->unkA8 = -1;
        }
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x58, &D_80118170);
    }
    sp2C = func_80015538(sp34->unkA6, -sp34->Rot.y);
    if ((sp2C <= 10.0f) || (sp2C >= 350.0f)) {
        sp34->unkA4 = 7;
        sp34->unk132 = 0;
    } else {
        sp34->Rot.y = func_80015538(sp34->Rot.y, (sp34->unkA8 * 0xA));
        sp34->unk3C = sp34->Rot.y;
    }
}

void func_800C6DF0(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    s32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk44 = 6.0f;
        sp34->unkA6 = 1;
        sp34->unkA8 = 0;
        sp34->unkB0 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp34->unkB0 = 0xA;
    }
    if (sp34->unkA6 != 0) {
        sp34->unkA6 = 0;
        func_80029EF8(gCurrentParsedObject, 8.0f, 0.727273f);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x58, &D_80118170);
    }
    if (sp34->unkB0 == 0) {
        sp2C = func_8002A46C(gCurrentParsedObject);
        sp2C -= 0xB4;
        if (sp2C < 0) {
            sp2C += 0x168;
        }
        sp34->Rot.y = sp2C;
        sp34->unk3C = sp2C;
    } else {
        sp34->unkB0 -= 1;
    }
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        if (sp34->unkA8 == 2) {
            sp34->unkA4 = 1;
            sp34->unk132 = 0;
        } else {
            sp34->unkA8 += 1;
            sp34->unkA6 = 1;
        }
    }
}

void func_800C7130(void) {
    func_8002B0E4(gCurrentParsedObject);
}

// RODATA
void func_800C7160(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1:
            func_800C5F80();
            break;
        case 2:
            func_800C60F0();
            break;
        case 3:
            func_800C639C();
            break;
        case 4:
            func_800C66B4();
            break;
        case 5:
            func_800C689C();
            break;
        case 6:
            func_800C6B8C();
            break;
        case 7:
            func_800C6DF0();
            break;
        case 8:
            func_800C7130();
            break;
        default:
            break;
    }
}

extern struct UnkStruct_80027C00 D_80113F58;
extern f32 D_80114E60;
extern f32 D_80114E64;
extern f32 D_80114E68;
extern f32 D_80114E6C;
extern f32 D_80114E70;
extern f32 D_80114E74;

void func_800C7260(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    sp2C = func_80027464(3, &D_80113F58, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);
    if (sp2C != -1) {
        sp28 = gObjects[sp2C].unkE8[0];
        sp24 = gObjects[sp2C].unkE8[1];
        gObjects[sp2C].unkB6 = gObjects[sp2C].Pos.x;
        gObjects[sp2C].unkB8 = gObjects[sp2C].Pos.z;
        if (D_80165100->unkA == 0) {
            D_80165100->unkA = 0xFA;
        }
        gObjects[sp2C].unkBA = D_80165100->unkA;

        gObjects[sp28].unkBA = gObjects[sp2C].unkBA;
        gObjects[sp24].unkBA = gObjects[sp2C].unkBA;

        gObjects[sp2C].Pos.x = gObjects[sp2C].unkB6 + (gObjects[sp2C].unkBA * sinf(D_80114E60));
        gObjects[sp28].Pos.x = gObjects[sp2C].unkB6 + (gObjects[sp28].unkBA * sinf(D_80114E64));
        gObjects[sp24].Pos.x = gObjects[sp2C].unkB6 + (gObjects[sp24].unkBA * sinf(D_80114E68));
        gObjects[sp2C].Pos.z = gObjects[sp2C].unkB8 + (gObjects[sp2C].unkBA * cosf(D_80114E6C));
        gObjects[sp28].Pos.z = gObjects[sp2C].unkB8 + (gObjects[sp28].unkBA * cosf(D_80114E70));
        gObjects[sp24].Pos.z = gObjects[sp2C].unkB8 + (gObjects[sp24].unkBA * cosf(D_80114E74));
        gObjects[sp2C].unkA6 = 0x3C;
        gObjects[sp28].unkA6 = 0xB4;
        gObjects[sp24].unkA6 = 0x12C;
    }
}

void func_800C77D8(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if ((D_80177A64 == 0) && (sp4->unkE6[0] == -1)) {
        sp4->unk132 = 0;
        sp4->unkA4 = 4;
    }
}

// RODATA
extern f32 D_80114E78;
extern f32 D_80114E7C;
extern f32 D_80114E80;
extern u32 D_8011817C;
extern UNK_TYPE D_801181B4;

void func_800C785C(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;
    s32 sp34;
    s32 pad;

    sp3C = &gObjects[gCurrentParsedObject];
    sp38 = gObjects[gCurrentParsedObject].unkE8[0];
    sp34 = gObjects[gCurrentParsedObject].unkE8[1];

    if (sp3C->unk132 == 0) {
        sp3C->unk132++;

        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x5B, &D_8011817C);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801181B4);
        func_8001C0EC(sp38, 0, 0, 0x5B, &D_8011817C);
        func_8001ABF4(sp38, 0, 0, &D_801181B4 + 7);
        func_8001C0EC(sp34, 0, 0, 0x5B, &D_8011817C);
        func_8001ABF4(sp34, 0, 0, &D_801181B4 + 7);

        sp3C->Scale.z = D_80114E78;

        sp3C->Scale.x = sp3C->Scale.y = sp3C->Scale.z;

        gObjects[sp38].Scale.x = gObjects[sp38].Scale.y = gObjects[sp38].Scale.z = D_80114E7C;

        gObjects[sp34].Scale.x = gObjects[sp34].Scale.y = gObjects[sp34].Scale.z = D_80114E80;

        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001BBDC(sp38, 1);
        func_8001BBDC(sp34, 1);
        func_8001BB34(gCurrentParsedObject, 1);
        func_8001BB34(sp38, 1);
        func_8001BB34(sp34, 1);
        func_8001BB04(gCurrentParsedObject, 1);
        func_8001BB04(sp38, 1);
        func_8001BB04(sp34, 1);
    }
    if (func_8002A1FC(gCurrentParsedObject, 540.0f) != 0) {
        sp3C->unkA4 = 2;
        sp3C->unk132 = 0;
    }
}

// RODATA
extern f64 D_80114E88;
extern f64 D_80114E90;
extern f64 D_80114E98;
extern f64 D_80114EA0;
extern f64 D_80114EA8;
extern f64 D_80114EB0;
extern f64 D_80114EB8;
extern f64 D_80114EC0;
extern f64 D_80114EC8;

void func_800C7BD8(void) {
    struct ObjectStruct* sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = &gObjects[gCurrentParsedObject];
    sp20 = gObjects[gCurrentParsedObject].unkE8[0];
    sp1C = gObjects[gCurrentParsedObject].unkE8[1];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001BBDC(sp20, 0);
        func_8001BBDC(sp1C, 0);
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BB34(sp20, 0);
        func_8001BB34(sp1C, 0);
        func_8001BB04(gCurrentParsedObject, 0);
        func_8001BB04(sp20, 0);
        func_8001BB04(sp1C, 0);
    }
    sp24->Scale.x = (sp24->Scale.x + D_80114E88);
    sp24->Scale.y = (sp24->Scale.y + D_80114E90);
    sp24->Scale.z = (sp24->Scale.z + D_80114E98);
    gObjects[sp20].Scale.x = (gObjects[sp20].Scale.x + D_80114EA0);
    gObjects[sp20].Scale.y = (gObjects[sp20].Scale.y + D_80114EA8);
    gObjects[sp20].Scale.z = (gObjects[sp20].Scale.z + D_80114EB0);
    gObjects[sp1C].Scale.x = (gObjects[sp1C].Scale.x + D_80114EB8);
    gObjects[sp1C].Scale.y = (gObjects[sp1C].Scale.y + D_80114EC0);

    gObjects[sp1C].Scale.z += D_80114EC8;

    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
        sp24->unk108 = 1;
        gObjects[sp20].unk108 = 1;
        gObjects[sp1C].unk108 = 1;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001BBDC(sp20, 1);
        func_8001BBDC(sp1C, 1);
    }
}

// RODATA
extern f64 D_80114ED0;
extern f64 D_80114ED8;
extern f64 D_80114EE0;
extern f64 D_80114EE8;
extern f64 D_80114EF0;
extern f64 D_80114EF8;

void func_800C7FE4(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;
    s32 sp34;
    UNUSED s32 pad30;
    UNUSED s32 pad2C;
    f32 sp28;
    f32 sp24;

    sp3C = &gObjects[gCurrentParsedObject];
    sp38 = gObjects[gCurrentParsedObject].unkE8[0];
    sp34 = gObjects[gCurrentParsedObject].unkE8[1];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unk44 = 5.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x5B, &D_8011817C);
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(sp38, 0, 1, 0x5B, &D_8011817C);
        func_8001BBDC(sp38, 0);
        func_8001C0EC(sp34, 0, 1, 0x5B, &D_8011817C);
        func_8001BBDC(sp34, 0);
    }

    sp3C->Rot.y = func_80015538(sp3C->Rot.y, 10.0f);

    sp28 = (sinf((sp3C->unkA6 * D_80114ED0)) * sp3C->unkBA) + sp3C->unkB6;
    sp24 = (cosf((sp3C->unkA6 * D_80114ED8)) * sp3C->unkBA) + sp3C->unkB8;

    sp3C->Vel.x = sp28 - sp3C->Pos.x;
    sp3C->Vel.z = sp24 - sp3C->Pos.z;

    sp3C->unkA6 = func_80015538(sp3C->unkA6, 3.0f);

    gObjects[sp38].Rot.y = func_80015538(gObjects[sp38].Rot.y, 10.0f);
    sp28 = sp3C->unkB6 + (gObjects[sp38].unkBA * sinf((D_80114EE0 * gObjects[sp38].unkA6)));
    sp24 = sp3C->unkB8 + (gObjects[sp38].unkBA * cosf((D_80114EE8 * gObjects[sp38].unkA6)));

    gObjects[sp38].Vel.x = sp28 - gObjects[sp38].Pos.x;
    gObjects[sp38].Vel.z = sp24 - gObjects[sp38].Pos.z;

    gObjects[sp38].unkA6 = func_80015538(gObjects[sp38].unkA6, 3.0f);
    gObjects[sp34].Rot.y = func_80015538(gObjects[sp34].Rot.y, 10.0f);

    sp28 = sp3C->unkB6 + gObjects[sp34].unkBA * sinf((D_80114EF0 * gObjects[sp34].unkA6));
    sp24 = sp3C->unkB8 + gObjects[sp34].unkBA * cosf((D_80114EF8 * gObjects[sp34].unkA6));

    gObjects[sp34].Vel.x = sp28 - gObjects[sp34].Pos.x;
    gObjects[sp34].Vel.z = sp24 - gObjects[sp34].Pos.z;
    gObjects[sp34].unkA6 = func_80015538(gObjects[sp34].unkA6, 3.0f);
}

void func_800C8764(void) {
    struct ObjectStruct* sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = &gObjects[gCurrentParsedObject];
    sp20 = gObjects[gCurrentParsedObject].unkE8[0];
    sp1C = gObjects[gCurrentParsedObject].unkE8[1];
    func_800281A4(gCurrentParsedObject, 0);
    func_800281A4(gCurrentParsedObject, 1);
    func_8002B0E4(sp20);
    func_8002B0E4(sp1C);
    func_8002B0E4(gCurrentParsedObject);
}

void func_800C8858(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) { /* irregular */
        case 1:
            func_800C785C();
            break;
        case 2:
            func_800C7BD8();
            break;
        case 3:
            func_800C7FE4();
            break;
        case 4:
            func_800C8764();
            break;
        default:
            break;
    }
}

extern struct UnkStruct_80027C00 D_80113F7C;

void func_800C8924(void) {
    func_80027464(1, &D_80113F7C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800C899C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk132 = 0;
        sp4->unkA4 = 4;
    }
}

// RODATA
extern f32 D_80114F00;

void func_800C8A08(void) {
    struct ObjectStruct* sp34;
    UNUSED s32 pad[2];

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x5B, &D_8011817C);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801181B4);
        func_8001BBDC(gCurrentParsedObject, 1);
        sp34->Scale.z = D_80114F00;
        sp34->Scale.x = sp34->Scale.y = sp34->Scale.z;
        func_8001BB34(gCurrentParsedObject, 1);
        func_8001BB04(gCurrentParsedObject, 1);
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        sp34->unkA4 = 2;
        sp34->unk132 = 0;
    }
}

// RODATA
extern f64 D_80114F08;
extern f64 D_80114F10;
extern f64 D_80114F18;

void func_800C8B64(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BB04(gCurrentParsedObject, 0);
    }
    sp1C->Scale.x = (f32) ((f64) sp1C->Scale.x + D_80114F08);
    sp1C->Scale.y = (f32) ((f64) sp1C->Scale.y + D_80114F10);
    sp1C->Scale.z = (f32) ((f64) sp1C->Scale.z + D_80114F18);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp1C->unkA4 = 3;
        sp1C->unk132 = 0;
        sp1C->unk108 = 1;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
}

void func_800C8CC8(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x5B, &D_8011817C);
        func_8001BBDC(gCurrentParsedObject, 0);
        sp3C->unkB0 = 0;
    }
    if (sp3C->unkB2 == 0) {
        sp3C->unk44 = 5.0f;
    } else {
        sp3C->unkB2 -= 1;
        sp3C->unk44 = 0.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp3C->unkB0 = 0xA;
    }
    if (sp3C->unkB0 == 0) {
        sp30 = func_8002A640(gCurrentParsedObject, 10.0f);
        sp3C->Rot.y = func_80015538(sp3C->Rot.y, (f32) (sp30 * 0xA));
        sp3C->unk3C = sp3C->Rot.y;
    } else {
        sp3C->unkB0 -= 1;
    }
    sp3C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) {
        sp3C->Pos.y = sp34;
    } else {
        sp3C->Pos.y = sp38;
    }
}

void func_800C8F54(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    func_8002B0E4(gCurrentParsedObject);
}

void func_800C8FB0(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) { /* irregular */
        case 1:
            func_800C8A08();
            break;
        case 2:
            func_800C8B64();
            break;
        case 3:
            func_800C8CC8();
            break;
        case 4:
            func_800C8F54();
            break;
        default:
            break;
    }
}

extern struct UnkStruct_80027C00 D_80113F88;

void func_800C907C(void) {
    func_80027464(1, &D_80113F88, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800C90F4(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk132 = 0;
        sp4->unkA4 = 5;
    }
}

extern f32 D_80114F20;

void func_800C9160(void) {
    struct ObjectStruct* sp34;
    f32 temp_f20;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x5B, &D_8011817C);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801181B4);
        func_8001BBDC(gCurrentParsedObject, 1);
        sp34->Scale.z = D_80114F20;
        sp34->Scale.x = sp34->Scale.y = sp34->Scale.z;
        func_8001BB34(gCurrentParsedObject, 1);
        func_8001BB04(gCurrentParsedObject, 1);
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        sp34->unkA4 = 2;
        sp34->unk132 = 0;
    }
}

// RODATA
extern f64 D_80114F28;
extern f64 D_80114F30;
extern f64 D_80114F38;

void func_800C92BC(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BB04(gCurrentParsedObject, 0);
    }
    sp1C->Scale.x = (f32) ((f64) sp1C->Scale.x + D_80114F28);
    sp1C->Scale.y = (f32) ((f64) sp1C->Scale.y + D_80114F30);
    sp1C->Scale.z = (f32) ((f64) sp1C->Scale.z + D_80114F38);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp1C->unkA4 = 3;
        sp1C->unk132 = 0;
        sp1C->unk108 = 1;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
}

extern struct UnkStruct_80027C00 D_80113F94;
extern f32 D_80114F40;
extern f32 D_80114F44;
extern f32 D_80114F48;

void func_800C9420(void) {
    struct ObjectStruct* sp44;
    UNUSED s32 pad40;
    UNUSED s32 pad3C;
    s32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x5B, &D_8011817C);
        func_8001BBDC(gCurrentParsedObject, 0);
        sp44->unkA6 = 0;
    }
    if (sp44->unkA6 == 0) {
        sp34 = sp44->Pos.x;
        sp30 = sp44->Pos.y + 120.0f;
        sp2C = sp44->Pos.z;
        sp38 = func_80027464(1, &D_80113F94, sp34 - 30.0f, sp30, sp2C + 30.0f, sp44->Rot.y);
        if (sp38 != -1) {
            gObjects[sp38].Scale.x = gObjects[sp38].Scale.y = gObjects[sp38].Scale.z = D_80114F40;
        }
        sp38 = func_80027464(1, &D_80113F94, sp34, sp30, sp2C, sp44->Rot.y);
        if (sp38 != -1) {
            gObjects[sp38].Scale.x = gObjects[sp38].Scale.y = gObjects[sp38].Scale.z = D_80114F44;
        }
        sp38 = func_80027464(1, &D_80113F94, sp34 + 30.0f, sp30, sp2C - 30.0f, sp44->Rot.y);
        if (sp38 != -1) {
            gObjects[sp38].Scale.x = gObjects[sp38].Scale.y = gObjects[sp38].Scale.z = D_80114F48;
        }
        sp44->unkA6 = 0x28;
    } else {
        sp44->unkA6 -= 1;
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) == 0) {
        sp44->unkA4 = 4;
        sp44->unk132 = 0;
    }
}

// RODATA
extern f64 D_80114F50;
extern f64 D_80114F58;
extern f64 D_80114F60;

void func_800C980C(void) {
    struct ObjectStruct* sp24;
    UNUSED s32 pad[2];

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->unkA6 = 0x1E;
    }
    if (sp24->unkA6 != 0) {
        sp24->Scale.x = (f32) ((f64) sp24->Scale.x - D_80114F50);
        sp24->Scale.y = (f32) ((f64) sp24->Scale.y - D_80114F58);
        sp24->Scale.z = (f32) ((f64) sp24->Scale.z - D_80114F60);
        sp24->unkA6 -= 1;
        if (sp24->unkA6 == 0) {
            sp24->unk132 = 0;
            sp24->unkA4 = 1;
        }
    }
}

void func_800C9970(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    func_8002B0E4(gCurrentParsedObject);
}

// RODATA
#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C99CC.s")

void func_800C9A9C(void) {
    if (D_80177A64 == 2) {
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

// RODATA
extern f64 D_80114F80;
extern f64 D_80114F88;
extern f64 D_80114F90;
extern UNK_TYPE D_801177F4;

void func_800C9B14(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk44 = 8.0f;
        sp34->unkA6 = (s16) (s32) func_8002A46C(gCurrentParsedObject);
        sp34->unkA6 += Math_Random(0x2D);
        if (sp34->unkA6 >= 0x168) {
            sp34->unkA6 -= 0x168;
        }
        sp34->unk3C = (f32) sp34->unkA6;
        func_80029EF8(gCurrentParsedObject, 15.0f, 1.0f);
        sp34->unkA8 = 0x28;
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_801177F4);
    }
    if (sp34->unkA8 != 0) {
        sp34->Scale.x = (f32) ((f64) sp34->Scale.x + D_80114F80);
        sp34->Scale.y = (f32) ((f64) sp34->Scale.y + D_80114F88);
        sp34->Scale.z = (f32) ((f64) sp34->Scale.z + D_80114F90);
    }
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        sp34->unkA6 = 0xA;
        sp34->unkA4 = 2;
        sp34->unk132 = 0;
    }
}

void func_800C9DF8(void) {
    func_8002B114(gCurrentParsedObject);
}

void func_800C9E28(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        switch (gObjects[gCurrentParsedObject].unkA4) { /* irregular */
            case 1:
                func_800C9B14();
                break;
            case 2:
                func_800C9DF8();
                break;
            default:
                break;
        }
    }
}

extern struct UnkStruct_80027C00 D_80113FD0;
extern struct UnkStruct_80027B34 D_80114E20;

void func_800C9EF0(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113FD0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_80027B34(sp24, &D_80114E20);
    }
}

void func_800C9F8C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unkA4 = 6;
        sp4->unk132 = 0;
    }
}

extern u32 D_801181F0;
extern u32 D_80118200;
extern UNK_TYPE D_80118234;

void func_800C9FF8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->Vel.x = 0.0f;
        sp24->Vel.y = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->unk3C = sp24->Rot.y;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x68, &D_801181F0);
        func_8001C0EC(gCurrentParsedObject, 3, 1, 0x68, &D_80118200);
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_80118234);
    }
    if (func_8002A1FC(gCurrentParsedObject, 2000.0f) != 0) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800CA140(void) {
    struct ObjectStruct* sp2C;
    UNUSED s32 pad[2];

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkA6 = 0x28;
        sp2C->unk44 = 10.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x68, &D_801181F0);
        func_8001C0EC(gCurrentParsedObject, 3, 1, 0x68, &D_80118200);
    }
    sp2C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->unkA4 = 5;
        sp2C->unk132 = 0;
    }
    if (sp2C->unkA6 == 0) {
        sp2C->unkA4 = 3;
        sp2C->unk132 = 0;
    } else {
        sp2C->unkA6 -= 1;
    }
}

extern struct UnkStruct_80027C00 D_80113FDC;

void func_800CA2D4(void) {
    struct ObjectStruct* sp2C;
    UNUSED s32 pad[2];
    s32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkA6 = 2;
        sp2C->unk44 = 10.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x68, &D_801181F0);
        func_8001C0EC(gCurrentParsedObject, 3, 2, 0x68, &D_80118200);
    }
    sp2C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->unkA4 = 5;
        sp2C->unk132 = 0;
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 6.0f) {
        sp20 = func_80027464(1, &D_80113FDC, sp2C->Pos.x + 30.0f, sp2C->Pos.y, sp2C->Pos.z, sp2C->Rot.y);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        if (sp2C->unkA6 == 0) {
            sp2C->unkA4 = 2;
            sp2C->unk132 = 0;
        } else {
            sp2C->unkA6 -= 1;
        }
    }
}

void func_800CA4EC(void) {
}

void func_800CA4FC(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800CA52C(void) {
    func_8002B0E4(gCurrentParsedObject);
}

// RODATA
#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA55C.s")

void func_800CA63C(void) {
    if (D_80177A64 == 2) {
        gObjects[gCurrentParsedObject].unkA6 = 0;
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800CA6DC(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk44 = 0.0f;
        sp34->unk3C = 0.0f;
        func_80029EF8(gCurrentParsedObject, 5.0f, 1.0f);
    }
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        gObjects[gCurrentParsedObject].unkA6 = 0xA;
        sp34->unkA4 = 2;
        sp34->unk132 = 0;
    }
}

void func_800CA890(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
    func_8007EDF4(sp24->Pos.x, sp24->Pos.y + (f32) sp24->unkA6, sp24->Pos.z, 1.0f);
    func_8002B114(gCurrentParsedObject);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA9F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CAA94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CAB00.s")

void func_800CAC6C(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkA6 = 0x1E;
        sp24->unk44 = 0.0f;
        sp24->unk40 = 90.0f;
        sp24->unk48 = 10.0f;
        sp24->unk108 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x68, &D_801181F0);
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x68, &D_80118200);
    }
    sp20 = func_8002A640(gCurrentParsedObject, 10.0f);
    sp24->Rot.y = func_80015538(sp24->Rot.y, (f32) (sp20 * 0xA));
    sp24->unk3C = sp24->Rot.y;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkA6 == 0) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
    } else {
        sp24->unkA6 -= 1;
    }
}

extern struct UnkStruct_80027C00 D_80113FF4;
extern f64 D_80114FB0;
extern f64 D_80114FB8;
extern f64 D_80114FC0;

void func_800CAE40(void) {
    struct ObjectStruct* sp5C;
    UNUSED s32 pad[2];
    f32 sp50;
    f32 sp4C;
    s32 sp48;

    sp5C = &gObjects[gCurrentParsedObject];
    if (sp5C->unk132 == 0) {
        sp5C->unk132 += 1;
        sp5C->Vel.x = 0.0f;
        sp5C->Vel.y = 0.0f;
        sp5C->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x68, &D_801181F0);
        func_8001C0EC(gCurrentParsedObject, 3, 3, 0x68, &D_80118200);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 30.0f) {
        sp50 = sp5C->unk3C;
        sp4C = sp5C->unk40;
        sp48 = func_80027464(1, &D_80113FF4, (sinf((f32) ((f64) sp50 * D_80114FB0)) * 100.0f) + sp5C->Pos.x,
                             (sinf((f32) ((f64) sp4C * D_80114FB8)) * 10.0f) + sp5C->Pos.y,
                             (cosf((f32) ((f64) sp50 * D_80114FC0)) * 100.0f) + sp5C->Pos.z, sp5C->Rot.y);
        if (sp48 != -1) {
            func_80019448(sp48, 2, 0, 1);
        }
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp5C->unkA4 = 4;
        sp5C->unk132 = 0;
    }
}

void func_800CB0DC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkA6 = 0x1E;
        sp24->unk44 = 0.0f;
        sp24->unk40 = 270.0f;
        sp24->unk48 = 10.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x68, &D_801181F0);
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x68, &D_80118200);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkA6 == 0) {
        sp24->unkA4 = 1;
        sp24->unk132 = 0;
    } else {
        sp24->unkA6 -= 1;
    }
}

void func_800CB24C(void) {
}

void func_800CB25C(void) {
    func_8002B0E4(gCurrentParsedObject);
}

// RODATA
#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB28C.s")

void func_800CB36C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 2) {
        sp4->unkA4 = 2;
        sp4->unk132 = 0;
    }
}

void func_800CB3D8(void) {
    struct ObjectStruct* sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    s32 sp34;
    f32 sp30;
    f32 temp_f20;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = 1;
        sp44->unk44 = 20.0f;
        sp44->unk3C = sp44->Rot.y;
        sp44->unk40 = 0.0f;
        sp44->unkA8 = 0xF;
        sp44->Scale.z = 1.5f;
        sp44->Scale.x = sp44->Scale.y = sp44->Scale.z;
    }
    sp40 = 0;
    if (sp44->unkA8 != 0) {
        sp44->unkA8 -= 1;
    }
    if ((sp44->unkA8 == 0) && (func_80028FA0(gCurrentParsedObject) != 0)) {
        sp40 = 1;
    }
    if (sp44->unkA8 == 0) {
        sp30 = func_80015634(gPlayerObject->Pos.x - sp44->Pos.x, gPlayerObject->Pos.z - sp44->Pos.z);
        sp34 = func_800157EC(sp44->unk3C, sp30, 2.0f);
        sp44->unk3C = func_80015538(sp44->unk3C, (f32) sp34);
        sp30 = Math_CalcAngleSimple(gPlayerObject->Pos.x - sp44->Pos.x, gPlayerObject->Pos.y - sp44->Pos.y);
        sp30 = Math_NormalizeAngle(sp30);
        sp34 = func_800157EC(sp44->unk40, sp30, 2.0f);
        sp44->unk40 = func_80015538(sp44->unk40, (f32) sp34);
    }
    sp44->Rot.y = sp44->unk3C;
    sp44->Rot.x = func_80015538(360.0f, -sp44->unk40);
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp3C, 0.0f, -30.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp3C, 0.0f, 30.0f, 0.0f) != 0) {
        sp40 = 1;
    }
    if (sp44->unkA6 != 0) {
        sp40 = 1;
    }
    if (sp40 != 0) {
        sp44->unkA4 = 2;
        sp44->unk132 = 0;
    }
}

void func_800CB770(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800CB7A0(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) { /* irregular */
        case 1:
            func_800CB3D8();
            break;
        case 2:
            func_800CB770();
            break;
        default:
            break;
    }
}

void func_800CB834(s32 arg0) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[arg0];
    if (sp4->unk3C >= 180.0f) {
        sp4->unk3C -= 180.0f;
    } else {
        sp4->unk3C += 180.0f;
    }
    if (sp4->unk3C == 90.0f) {
        sp4->Rot.z = 360.0f - sp4->Rot.z;
    } else if (sp4->unk3C == 180.0f) {
        sp4->Rot.x = 360.0f - sp4->Rot.x;
    }
}

extern struct UnkStruct_80027C00 D_80114000;

void func_800CB950(void) {
    func_80027464(1, &D_80114000, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800CB9C8(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 3;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

extern u32 D_80118254;

void func_800CBA40(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->Vel.x = 0.0f;
        sp24->Vel.y = 0.0f;
        sp24->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x77, &D_80118254);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 2.0f) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

extern s16 D_80114E40[];
extern s16 D_80114E48[];
extern s16 D_80114E50[];
void func_800CBB58(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    s32 temp_f8;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk44 = 8.0f;
        sp34->unkA6 = Math_Random(4);
        sp34->unk3C = (f32) D_80114E40[sp34->unkA6];
        sp34->Rot.x = (f32) D_80114E48[sp34->unkA6];
        sp34->Rot.z = (f32) D_80114E50[sp34->unkA6];
        sp34->unkA8 = 0;
        func_80029EF8(gCurrentParsedObject, 16.0f, 1.0f);
        func_800175F0(gCurrentParsedObject, 0, 0x56, -1, 0);
    }
    if (sp34->unkA8 == 0) {
        if (func_80028FA0(gCurrentParsedObject) != 0) {
            func_800CB834(gCurrentParsedObject);
            sp34->unkA8 = 0x14;
        }
    } else {
        sp34->unkA8 -= 1;
    }

    switch ((s32) gObjects[gCurrentParsedObject].unk3C) { /* irregular */
        case 0x0:
            sp34->Rot.x += 12.0f;
            break;
        case 0x5A:
            sp34->Rot.z -= 12.0f;
            break;
        case 0xB4:
            sp34->Rot.x -= 12.0f;
            break;
        case 0x10E:
            sp34->Rot.z += 12.0f;
            break;
        default:
            break;
    }
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_800CB834(gCurrentParsedObject);
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -90.0f, 90.0f) == 1) {
        func_800CB834(gCurrentParsedObject);
        sp34->Rot.z = 0.0f;
        sp34->Rot.x = sp34->Rot.z;
        sp34->unk44 = 0.0f;
        sp34->unkA4 = 1;
        sp34->unk132 = 0;
    }
}

void func_800CBF5C(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800CBF8C(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) { /* irregular */
        case 1:
            func_800CBA40();
            break;
        case 2:
            func_800CBB58();
            break;
        case 3:
            func_800CBF5C();
            break;
        default:
            break;
    }
}
