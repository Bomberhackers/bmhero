#include <ultra64.h>

void func_800DAD20(void) {
    func_80027464(1, &D_801142E8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800DAD98(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->action_state = 5;
    } else {
        sp4->action_state = 6;
    }
    sp4->unk132 = 0;
}

void func_800DAE20(void) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unk44 = 1.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x54, &D_80118E9C);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp30 = Math_Random(-6);
    sp34->unk3C = func_80015538(sp34->unk3C, (f32) sp30);
    sp34->Rot.y = (f32) sp34->unk3C;
    if (sp34->unkA8 == 0) {
        if (sp34->unkA6 < 0xF) {
            sp34->Vel.y = 1.0f;
            sp34->unkA6 = (s16) (sp34->unkA6 + 1);
        } else {
            sp34->unkA8 = (s16) (sp34->unkA8 + 1);
            sp34->unkA6 = 0;
        }
    } else if (sp34->unkA6 < 0xF) {
        sp34->Vel.y = -1.0f;
        sp34->unkA6 = (s16) (sp34->unkA6 + 1);
    } else {
        sp34->unkA8 = 0;
        sp34->unkA6 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = (f32) sp34->Vel.z;
        sp34->Vel.y = 0.0f;
        sp34->action_state = 2;
        sp34->unk132 = 0U;
    }
}

void func_800DB0F8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x54, &D_80118E9C);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 3;
        sp24->unk132 = 0U;
    }
}

void func_800DB1EC(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    sp20 = 0;
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 20.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x54, (u32*) &D_80118E9C);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (sp24->unkAA != 0) {
        if (--sp24->unk44 < 5.0f) {
            sp24->unkAA = 0;
        }
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->unk3C = func_80015538(sp24->unk3C, 180.0f);
        sp24->unkAA = 1;
    }
    if ((func_8001B4AC(gCurrentParsedObject, 0) != 0) && (sp24->unkAA == 0)) {
        sp24->action_state = 4;
        sp24->unk132 = 0;
    }
}

void func_800DB3E8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = (f32) sp24->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x54, &D_80118E9C);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 1;
        sp24->unk132 = 0U;
    }
}

void func_800DB504(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800DB534(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = (u8) (sp4->unk132 + 1);
        sp4->unkAC = 0x1E;
        sp4->unk44 = 0.0f;
        sp4->Vel.z = 0.0f;
        sp4->Vel.x = (f32) sp4->Vel.z;
    }
    sp4->unkAC = (s16) (sp4->unkAC - 1);
    if (sp4->unkAC == 0) {
        sp4->action_state = 4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DB620.s")

void func_800DB710(void) {
    func_80027464(1, &D_801142F4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DB788.s")

void func_800DB840(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x56, &D_80118EB4);
    }
    if (func_8002A1FC(gCurrentParsedObject, 540.0f) != 0) {
        sp24->action_state = 2;
        sp24->unk132 = 0U;
    }
}

void func_800DB910(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        func_80029EF8(gCurrentParsedObject, 0.0f, 4.0f);
    }
    sp1C->Rot.y = func_8002A46C(gCurrentParsedObject);
    sp1C->unk3C = (f32) sp1C->Rot.y;
    if (func_8002A0D0(gCurrentParsedObject, 0.0f, 0.0f, 0.0f) == 1) {
        sp1C->action_state = 3;
        sp1C->unk132 = 0U;
    }
}

void func_800DBA0C(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x56, &D_80118EB4);
    }
    sp2C->Rot.y = func_8002A46C(gCurrentParsedObject);
    sp2C->unk3C = (f32) sp2C->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        sp2C->action_state = 5;
        sp2C->unk132 = 0U;
    }
}

void func_800DBB78(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800DBBA8(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x56, &D_80118EB4);
    }
    sp2C->Rot.y = func_8002A46C(gCurrentParsedObject);
    sp2C->unk3C = (f32) sp2C->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        if (func_8002A1FC(gCurrentParsedObject, 600.0f) != 0) {
            sp2C->action_state = 6;
            sp2C->unk132 = 0U;
        }
    }
}

void func_800DBCFC(void) {
    struct ObjectStruct* sp44;
    f32 sp40;
    f32 sp3C;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        sp44->unk3C = func_8002A46C(gCurrentParsedObject);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 15.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x56, &D_80118EB4);
        sp44->unkC0 = 0;
    }
    if (sp44->unkC0 == 0) {
        sp44->unkC0 = 4;
        func_800175F0(gCurrentParsedObject, 0, 0x11, -1, 0);
    } else {
        sp44->unkC0 = (s16) (sp44->unkC0 - 1);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (sp44->unkA6 != 0) {
        if (--sp44->unk44 < 5.0f) {
            sp44->unkA6 = 0;
        }
    }
    func_8002A8B4(gCurrentParsedObject, (f32) (Math_Random(4) + 2));
    sp44->Rot.y = (f32) sp44->unk3C;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1, 30.0f, 0, 0.0f, 0.0f) != 0) {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->action_state = 5;
        sp44->unk132 = 0U;
    }
    if (func_800295C0(gCurrentParsedObject, &sp40, &sp3C, 0.0f, 0.0f, 0.0f) != 0) {
        sp44->Pos.y = sp3C;
    } else {
        sp44->Pos.y = sp40;
    }
    if (func_8002A2EC(gCurrentParsedObject, 600.0f) != 0) {

    } else {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->unk44 = 0.0f;
        sp44->action_state = 5;
        sp44->unk132 = 0U;
    }
}

void func_800DC07C(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x56, &D_80118EB4);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        sp2C->action_state = 5;
        sp2C->unk132 = 0U;
    }
}

#ifdef NON_MATCHING
// matches but needs rodata
void func_800DC188(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    switch (sp1C->action_state) {
        case 1:
            func_800DB840();
            break;
        case 2:
            func_800DB910();
            break;
        case 3:
            func_800DBA0C();
            break;
        case 4:
            func_800DBB78();
            break;
        case 5:
            func_800DBBA8();
            break;
        case 6:
            func_800DBCFC();
            break;
        case 7:
            func_800DC07C();
            break;
        default:
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC188.s")
#endif

void func_800DC288(void) {
    func_80027464(1, &D_80114300, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800DC300(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x56, &D_80118EB4);
    }
    if (func_8002A1FC(gCurrentParsedObject, 540.0f) != 0) {
        sp24->action_state = 2;
        sp24->unk132 = 0U;
    }
}

void func_800DC3D0(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        func_80029EF8(gCurrentParsedObject, 50.0f, 4.0f);
    }
    sp1C->Rot.y = func_8002A46C(gCurrentParsedObject);
    sp1C->unk3C = (f32) sp1C->Rot.y;
    if (func_8002A0D0(gCurrentParsedObject, 0, 0, 0) == 1) {
        sp1C->action_state = 3;
        sp1C->unk132 = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC4CC.s")

void func_800DC5CC(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011433C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_80019448(sp24, 2, 0, 1);
    }
}

void func_800DC66C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    sp4->unk108 = 0;
    sp4->action_state = 4;
    sp4->unk132 = 0;
}

void func_800DC6D0(void) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unk44 = 1.0f;
        sp34->Rot.x = 60.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x60, &D_80118FE8);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp30 = Math_Random(-6);
    func_8002A8B4(gCurrentParsedObject, (f32) sp30);
    sp34->Rot.y = (f32) sp34->unk3C;
    if (sp34->unkA8 == 0) {
        if (sp34->unkA6 < 0x1E) {
            sp34->Vel.y = 1.0f;
            sp34->unkA6 = (s16) (sp34->unkA6 + 1);
        } else {
            sp34->unkA8 = (s16) (sp34->unkA8 + 1);
            sp34->unkA6 = 0;
        }
    } else if (sp34->unkA6 < 0x1E) {
        sp34->Vel.y = -1.0f;
        sp34->unkA6 = (s16) (sp34->unkA6 + 1);
    } else {
        sp34->unkA8 = 0;
        sp34->unkA6 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4, 60.0f, 0, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        sp34->action_state = 2;
        sp34->unk132 = 0U;
    }
}

void func_800DC984(void) {
    struct ObjectStruct* sp34;
    s32 temp;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x60, &D_80118FE8);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp34->Rot.y = (f32) sp34->unk3C;
    if (sp34->Rot.x < 139.0f) {
        sp34->Rot.x = func_80015538(sp34->Rot.x, 10.0f);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp34->action_state = 3;
        sp34->unk132 = 0U;
    }
}

void func_800DCAFC(void) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    sp30 = 0;
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unk44 = 26.0f;
        sp34->unk3C = func_8002A46C(gCurrentParsedObject);
        sp34->Rot.y = (f32) sp34->unk3C;
        sp34->Vel.y = -13.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x60, &D_80118FE8);
        func_800175F0(gCurrentParsedObject, 0, 0x5D, -1, 0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp34->Rot.y = (f32) sp34->unk3C;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3, 60.0f, 0, 0.0f, 0.0f) != 0) {
        sp34->action_state = 4;
        sp34->unk132 = 0U;
    }
    if (func_8002A0D0(gCurrentParsedObject, 0, 0, -20.0f) == 1) {
        sp34->action_state = 4;
        sp34->unk132 = 0U;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
    }
}

void func_800DCD20(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800DCD50(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->action_state) {
        case 1:
            func_800DC6D0();
            break;
        case 2:
            func_800DC984();
            break;
        case 3:
            func_800DCAFC();
            break;
        case 4:
            func_800DCD20();
            break;
        default:
            break;
    }
}

void func_800DCE2C(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114348, (f32) D_80165100->unk2, (f32) (D_80165100->unk4 - 5), (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unk13A = 1;
    }
}

void func_800DCEE4(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801190CC);
    }
    if (func_8002A1FC(gCurrentParsedObject, 900.0f) != 0) {
        sp1C->action_state = 2;
        sp1C->unk132 = 0U;
    }
}

void func_800DCFAC(void) {
    struct ObjectStruct* sp24;
    s16 temp_t9;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->Pos.y = (f32) (sp24->Pos.y + 5.0f);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801190CC);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801190CC.Rot.y);
        func_8001B754(gCurrentParsedObject, 0);
        sp24->unk13A = 0;
    }
    if ((func_80028FA0(gCurrentParsedObject) != 0) && ((sp24->unk106 == 0xA2) || (sp24->unk106 == 0xA3))) {
        func_800E3EE4();
        return;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 3;
        sp24->unk132 = 0U;
    }
}

void func_800DD160(void) {
    struct ObjectStruct* sp24;
    s16 temp_t9;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801190CC);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801190CC.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
    }
    if ((func_80028FA0(gCurrentParsedObject) != 0) && (((sp24->unk106 == 0xA2)) || (sp24->unk106 == 0xA3))) {
        func_800E3EE4();
        return;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 4;
        sp24->unk132 = 0U;
        sp24->unkB2 = 1;
    }
}

void func_800DD300(void) {
    struct ObjectStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801190CC);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801190CC.Rot.y);
        sp44->unk3C = func_8002A46C(gCurrentParsedObject);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkA8 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        if ((sp44->unk106 == 0xA2) || (sp44->unk106 == 0xA3)) {
            func_800E3EE4();
            return;
        } else {
            func_80029B60(gCurrentParsedObject);
        }
    }

    if (sp44->unkA8 < 4) {
        if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(gCurrentParsedObject, 20.0f, 4.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(gCurrentParsedObject, 0, 0, 0, 30.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
            if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
                sp44->unkA6 = 0;
                sp44->unkA8 = (s16) (sp44->unkA8 + 1);
            } else {
                sp44->Vel.z = 0.0f;
                sp44->Vel.x = (f32) sp44->Vel.z;
            }
        }
    } else {
        sp44->action_state = 3;
        sp44->unk132 = 0U;
        sp44->unkB2 = 0;
    }
}

void func_800DD690(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800DD6C0(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = (u8) (sp4->unk132 + 1);
        sp4->unk44 = 0.0f;
        sp4->Vel.z = 0.0f;
        sp4->Vel.x = (f32) sp4->Vel.z;
        if (sp4->unkB2 == 1) {
            sp4->action_state = 4;
            sp4->unkA8 = 3;
        } else {
            sp4->action_state = 3;
            sp4->unk132 = 0U;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DD7B0.s")

void func_800DD8A0(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->action_state = 5;
    } else {
        sp4->action_state = 6;
    }
    sp4->unk132 = 0;
}

void func_800DD928(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114354, (f32) D_80165100->unk2, (f32) (D_80165100->unk4 - 5), (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);

    if (sp24 != -1) {
        gObjects[sp24].unk13A = 1;
    }
}

void func_800DD9E0(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119128);
    }
    if (func_8002A1FC(gCurrentParsedObject, 900.0f) != 0) {
        sp1C->action_state = 2;
        sp1C->unk132 = 0U;
    }
}

void func_800DDAA8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->Pos.y = (f32) (sp24->Pos.y + 5.0f);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119128);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119128.Rot.y);
        func_8001B754(gCurrentParsedObject, 0);
        sp24->unk13A = 0;
    }
    if ((func_80028FA0(gCurrentParsedObject) != 0) && (((sp24->unk106 == 0xA1)) || (sp24->unk106 == 0xA3))) {
        func_800E3EE4();
        return;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 3;
        sp24->unk132 = 0U;
    }
}

void func_800DDC5C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119128);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119128.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
    }
    if ((func_80028FA0(gCurrentParsedObject) != 0) && (((sp24->unk106 == 0xA1)) || (sp24->unk106 == 0xA3))) {
        func_800E3EE4();
        return;
    }
    sp24->unk3C = func_8002A46C(gCurrentParsedObject);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 4;
        sp24->unk132 = 0U;
        sp24->unkB2 = 1;
    }
}

void func_800DDE08(void) {
    struct ObjectStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 8, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119128);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119128.Rot.y);
        sp44->unk3C = func_8002A46C(gCurrentParsedObject);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        if ((sp44->unk106 == 0xA1) || (sp44->unk106 == 0xA3)) {
            func_800E3EE4();
            return;
        } else {
            func_80029B60(gCurrentParsedObject);
        }
    }
    if (func_8001B62C(gCurrentParsedObject, 0) > 10.0f) {
        if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(gCurrentParsedObject, 30.0f, 3.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        }
        if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
            if (func_8002A1FC(gCurrentParsedObject, 240.0f) != 0) {
                sp44->action_state = 5;
                sp44->unkA6 = 0;
                sp44->unk132 = 0U;
                sp44->unkB2 = 0;
            } else {
                sp44->action_state = 3;
                sp44->unkA6 = 0;
                sp44->unk132 = 0U;
                sp44->unkB2 = 0;
            }
        }
    } else if (func_8002A1FC(gCurrentParsedObject, 240.0f) != 0) {
        sp44->action_state = 5;
        sp44->unkA6 = 0;
        sp44->unk132 = 0U;
        sp44->unkB2 = 0;
    }
}

void func_800DE1E8(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;
    f32 temp_f20;
    f32 temp_f20_2;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = (u8) (sp3C->unk132 + 1);
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 9, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119128);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119128.unk30.z);
        sp3C->unk3C = func_8002A46C(gCurrentParsedObject);
        sp3C->Rot.y = (f32) sp3C->unk3C;
        sp3C->unk44 = 6.0f;
    }
    if ((func_8001B62C(gCurrentParsedObject, 0) > 20.0f) && (sp3C->unkAA == 0)) {
        sp38 = func_80027464(1, &D_80114360, sp3C->Pos.x, sp3C->Pos.y + 60.0f, sp3C->Pos.z, sp3C->unk3C);
        if (sp38 != -1) {
            func_8001ABF4(sp38, 0, 3, &D_8011935C);
            func_80026F10(gCurrentParsedObject, sp38);
            gObjects[sp38].unk3C = gObjects[sp38].Rot.y = sp3C->unk3C;
            gObjects[sp38].unkB2 = 1;
            sp3C->unkAA = (s16) (sp3C->unkAA + 1);
        }
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        if ((sp3C->unk106 == 0xA1) || (sp3C->unk106 == 0xA3)) {
            func_800E3EE4();
            return;
        } else {
            func_80029B60(gCurrentParsedObject);
        }
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp3C->action_state = 3;
        sp3C->unkAA = 0;
        sp3C->unk132 = 0U;
    }
}

void func_800DE534(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800DE564(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = (u8) (sp4->unk132 + 1);
        sp4->unk44 = 0.0f;
        sp4->Vel.z = 0.0f;
        sp4->Vel.x = (f32) sp4->Vel.z;
        if (sp4->unkB2 == 1) {
            sp4->action_state = 4;
            sp4->unkA8 = 3;
        } else {
            sp4->action_state = 3;
            sp4->unk132 = 0U;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DE654.s")

void func_800DE754(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->action_state = 6;
    } else {
        sp4->action_state = 7;
    }
    sp4->unk132 = 0;
}

void func_800DE7DC(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011436C, (f32) D_80165100->unk2, (f32) (D_80165100->unk4 + 5), (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unk13A = 1;
    }
}

void func_800DE894(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119194);
    }
    if (func_8002A1FC(gCurrentParsedObject, 900.0f) != 0) {
        sp1C->action_state = 2;
        sp1C->unk132 = 0U;
    }
}

void func_800DE95C(void) {
    struct ObjectStruct* sp24;
    s16 temp_t9;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119194);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119194.Rot.y);
        sp24->Pos.y = (f32) (sp24->Pos.y - 5.0f);
        func_8001B754(gCurrentParsedObject, 0);
        func_80029EF8(gCurrentParsedObject, 0, 4.0f);
        sp24->unk13A = 0;
    }
    if ((func_80028FA0(gCurrentParsedObject) != 0) && (((sp24->unk106 == 0xA2)) || (sp24->unk106 == 0xA1))) {
        func_800E3EE4();
        return;
    }
    sp24->Rot.y = func_8002A46C(gCurrentParsedObject);
    sp24->unk3C = (f32) sp24->Rot.y;
    if (func_8002A0D0(gCurrentParsedObject, 0, 0, 0) == 1) {
        sp24->action_state = 3;
        sp24->unk132 = 0U;
    }
}

void func_800DEB3C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119194);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119194.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
        sp24->Vel.y = 0.0f;
    }
    if ((func_80028FA0(gCurrentParsedObject) != 0) && (((sp24->unk106 == 0xA2)) || (sp24->unk106 == 0xA1))) {
        func_800E3EE4();
        return;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 4;
        sp24->unk132 = 0U;
    }
}

void func_800DECE0(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    s16 temp_t1;
    s32 temp;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = (u8) (sp3C->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 8, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119194);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119194.Rot.y);
        sp3C->unk3C = func_8002A46C(gCurrentParsedObject);
        sp3C->Rot.y = (f32) sp3C->unk3C;
        sp3C->unkA6 = 0;
        sp3C->unkA8 = 0;
    }
    if ((func_80028FA0(gCurrentParsedObject) != 0) && (((sp3C->unk106 == 0xA2)) || (sp3C->unk106 == 0xA1))) {
        func_800E3EE4();
        return;
    }
    if (func_8001B62C(gCurrentParsedObject, 0) > 10.0f) {
        if (sp3C->unkA6 == 0) {
            sp3C->unkA6 = 1;
            func_80029EF8(gCurrentParsedObject, 20.0f, 2.0f);
        }
        sp38 = sp3C->Vel.y;
        sp3C->Vel.y = 0.0f;
        if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
        sp3C->Vel.y = sp38;
        if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 30.0f) == 1) {
            sp3C->Vel.y = 0.0f;
        }
        if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
            if (func_8002A1FC(gCurrentParsedObject, 300.0f) != 0) {
                sp3C->action_state = 5;
                sp3C->unkA6 = 0;
                sp3C->unkA8 = 0;
                sp3C->unk132 = 0U;
            } else {
                sp3C->unkA6 = 0;
            }
        }
    } else if (func_8002A1FC(gCurrentParsedObject, 300.0f) != 0) {
        sp3C->action_state = 5;
        sp3C->unkA6 = 0;
        sp3C->unkA8 = 0;
        sp3C->unk132 = 0U;
    }
}

void func_800DF034(void) {
    struct ObjectStruct* sp44;
    f32 sp40;
    f32 temp_f20;
    s16 temp_t1;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0xA, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119194);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119194.Rot.y);
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        if ((sp44->unk106 == 0xA1) || (sp44->unk106 == 0xA2)) {
            func_800E3EE4();
            return;
        } else {
            func_80029B60(gCurrentParsedObject);
        }
    }

    func_8002A8B4(gCurrentParsedObject, 5.0f);
    sp44->Rot.y = (f32) sp44->unk3C;
    if (func_8001B62C(gCurrentParsedObject, 0) > 10.0f) {
        if (func_8001B62C(gCurrentParsedObject, 0) > 29.0f) {
            if (sp44->unkA6 == 1) {
                sp44->unkA6 = 2;
                func_80029EF8(gCurrentParsedObject, 0, 1.0f);
            }
        } else if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(gCurrentParsedObject, 40.0f, 2.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(gCurrentParsedObject, 0, 0, 0, 30.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        }
        if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
            sp44->action_state = 6;
            sp44->unkB2 = 2;
            sp44->unk132 = 0U;
        }
    }
}

void func_800DF3D4(void) {
    struct ObjectStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119194);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119194.Rot.y);
        func_80029EF8(gCurrentParsedObject, -5.0f, 0.0f);
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkB2 = 2;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        if ((sp44->unk106 == 0xA1) || (sp44->unk106 == 0xA2)) {
            func_800E3EE4();
            return;
        } else {
            func_80029B60(gCurrentParsedObject);
        }
    }

    func_8002A8B4(gCurrentParsedObject, 5.0f);
    sp44->Rot.y = (f32) sp44->unk3C;
    sp40 = sp44->Vel.y;
    sp44->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp44->Vel.y = sp40;
    if (func_80029F58(gCurrentParsedObject, 0, 0, 0, 30.0f) == 1) {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->unk44 = 0.0f;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->action_state = 3;
        sp44->unkA6 = 0;
        sp44->unkB2 = 0;
        sp44->unk132 = 0U;
    }
}

void func_800DF704(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800DF734(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    sp4->unk44 = 0.0f;
    sp4->Vel.z = 0.0f;
    sp4->Vel.x = (f32) sp4->Vel.z;
    if (sp4->unkB2 == 1) {
        sp4->action_state = 5;
    } else if (sp4->unkB2 == 2) {
        sp4->action_state = 6;
    } else {
        sp4->action_state = 3;
        sp4->unk132 = 0;
        sp4->unkA6 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DF81C.s")

void func_800DF92C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->action_state = 7;
    } else {
        sp4->action_state = 8;
    }
}

void func_800DF9A8(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        func_80029EF8(gCurrentParsedObject, 0, 4.0f);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp34->Rot.y = func_8002A46C(gCurrentParsedObject);
    sp34->unk3C = (f32) sp34->Rot.y;
    func_8002A8B4(gCurrentParsedObject, 5.0f);
    sp34->Rot.y = (f32) sp34->unk3C;
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0, 0, 0, 0.0f) == 1) {
        sp34->Vel.y = 0.0f;
    }
    if (sp34->Scale.x < 2.0f) {
        sp34->Scale.x = (f32) ((f64) sp34->Scale.x + D_801153B8);
        sp34->Scale.y = (f32) ((f64) sp34->Scale.y + D_801153C0);
        sp34->Scale.z = (f32) ((f64) sp34->Scale.z + D_801153C8);
    } else {
        sp34->unk108 = 1;
        sp34->action_state = 2;
        sp34->unk132 = 0U;
    }
}

void func_800DFC2C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801191F0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801191F0.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (func_8002A1FC(gCurrentParsedObject, 300.0f) != 0) {
            sp24->action_state = 4;
            sp24->unkA8 = 0;
            sp24->unk132 = 0U;
        } else {
            sp24->action_state = 3;
            sp24->unk132 = 0U;
            sp24->unkB2 = 1;
        }
    }
}

void func_800DFDBC(void) {
    struct ObjectStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801191F0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801191F0.Rot.y);
        sp44->unk3C = func_8002A46C(gCurrentParsedObject);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkA8 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (sp44->unkA8 < 4) {
        if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(gCurrentParsedObject, 20.0f, 4.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(gCurrentParsedObject, 0, 0, 0, 30.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
            if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
                if (func_8002A1FC(gCurrentParsedObject, 300.0f) != 0) {
                    sp44->action_state = 4;
                    sp44->unkA8 = 0;
                    sp44->unkB2 = 0;
                    sp44->unk132 = 0U;
                } else {
                    sp44->unkA8 = (s16) (sp44->unkA8 + 1);
                }
                sp44->unkA6 = 0;
            } else {
                sp44->Vel.z = 0.0f;
                sp44->Vel.x = (f32) sp44->Vel.z;
            }
        }
    } else {
        sp44->action_state = 2;
        sp44->unkB2 = 0;
        sp44->unk132 = 0U;
    }
}

void func_800E0154(void) {
    struct ObjectStruct* sp44;
    s32 sp40;
    f32 temp_f20;
    s16 temp_t8;
    s32 temp2;
    s16 sp32;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 0xC, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801191F0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801191F0.Rot.y);
        sp44->unk3C = func_8002A46C(gCurrentParsedObject);
        sp44->Rot.y = (f32) sp44->unk3C;
    }
    if ((func_8001B62C(gCurrentParsedObject, 0) > 20.0f) && (sp44->unkAA == 0)) {
        sp32 = 0;
        do {
            sp40 = func_80027464(1, &D_80114378, sp44->Pos.x, sp44->Pos.y + 120.0f, sp44->Pos.z, sp44->unk3C);
            if (sp40 != -1) {
                func_8001ABF4(sp40, 0, 3, &D_80119384);
                func_80026F10(gCurrentParsedObject, sp40);
                if (sp32 == 0) {
                    func_8002A8B4(sp40, -325.0f);
                } else if (sp32 == 2) {
                    func_8002A8B4(sp40, -35.0f);
                } else {
                    func_8002A8B4(sp40, 0);
                }
                gObjects[sp40].unkB2 = 2;
                gObjects[sp40].unkAA = 1;
            }
            sp44->unkAA = (s16) (sp44->unkAA + 1);
        } while (++sp32 < 3);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp44->action_state = 2;
        sp44->unkAA = 0;
        sp44->unk132 = 0U;
    }
}

void func_800E047C(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800E04AC(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkD4 = (f32) sp2C->Vel.y;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801191F0.unk30.z);
    }
    sp2C->Vel.z = 0.0f;
    sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
    if (sp2C->unk108 == 1) {
        func_8001BBDC(gCurrentParsedObject, 0);
        sp2C->Vel.y = (f32) sp2C->unkD4;
        if (sp2C->unkB2 == 1) {
            if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
                func_8001C0EC(gCurrentParsedObject, 0, 5, 0x70, &D_80118FF4);
                func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801191F0);
                func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801191F0.Rot.y);
                sp2C->unkA6 = 0;
                sp2C->unkB2 = 0;
                sp2C->action_state = 2;
            } else {
                sp2C->action_state = 3;
                sp2C->unkA8 = 3;
            }
        } else {
            sp2C->action_state = 2;
            sp2C->unk132 = 0U;
            sp2C->unkA6 = 0;
        }
    }
}

void func_800E06E0(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    sp4->unk44 = 0.0f;
    sp4->Vel.z = 0.0f;
    sp4->Vel.x = (f32) sp4->Vel.z;
    if (sp4->unkB2 == 1) {
        sp4->action_state = 3;
        sp4->unkA8 = 3;
    } else if (sp4->unkB2 == 9) {
        sp4->action_state = 1;
        sp4->unk132 = 0;
    } else {
        sp4->action_state = 2;
        sp4->unk132 = 0;
        sp4->unkA6 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E07DC.s")

void func_800E0938(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->action_state = 5;
        sp4->unk132 = 0;
    } else if (D_80177A64 == 1) {
        sp4->unk108 = 0x3C;
    }
}

void func_800E09D0(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        func_80029EF8(gCurrentParsedObject, 0, 4.0f);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp34->Rot.y = func_8002A46C(gCurrentParsedObject);
    sp34->unk3C = (f32) sp34->Rot.y;
    func_8002A8B4(gCurrentParsedObject, 5.0f);
    sp34->Rot.y = (f32) sp34->unk3C;
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0, 0, 0, 0.0f) == 1) {
        sp34->Vel.y = 0.0f;
    }
    if (sp34->Scale.x < 2.0f) {
        sp34->Scale.x += D_801153F0;
        sp34->Scale.y += D_801153F8;
        sp34->Scale.z += D_80115400;
    } else {
        sp34->unk108 = 1;
        sp34->action_state = 2;
        sp34->unk132 = 0U;
    }
}

void func_800E0C54(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119268);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119268.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (func_8002A1FC(gCurrentParsedObject, 300.0f) != 0) {
            sp24->action_state = 4;
            sp24->unkA8 = 0;
            sp24->unk132 = 0U;
        } else {
            sp24->action_state = 3;
            sp24->unk132 = 0U;
            sp24->unkB2 = 1;
        }
    }
}

void func_800E0DE4(void) {
    struct ObjectStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 8, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119268);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119268.Rot.y);
        sp44->unk3C = func_8002A46C(gCurrentParsedObject);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) > 10.0f) {
        if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(gCurrentParsedObject, 30.0f, 3.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(gCurrentParsedObject, 0, 0, 0, 0.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        }
        if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
            if (func_8002A1FC(gCurrentParsedObject, 300.0f) != 0) {
                sp44->action_state = 4;
                sp44->unkA6 = 0;
                sp44->unk132 = 0U;
                sp44->unkB2 = 2;
            } else {
                sp44->action_state = 2;
                sp44->unkA6 = 0;
                sp44->unk132 = 0U;
                sp44->unkB2 = 0;
            }
        }
    } else {
        sp44->Vel.y = 0.0f;
        if (func_8002A1FC(gCurrentParsedObject, 300.0f) != 0) {
            sp44->action_state = 4;
            sp44->unkA6 = 0;
            sp44->unk132 = 0U;
            sp44->unkB2 = 2;
        }
    }
}

void func_800E119C(void) {
    struct ObjectStruct* sp44;
    s32 sp40;
    s32 temp1;
    s16 temp2;
    f32 temp_f20;
    s16 sp32;
    s32 temp_t6;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 0xD, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119268);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119268.Rot.y);
        sp44->unk3C = func_8002A46C(gCurrentParsedObject);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unkB2 = 2;
        sp44->unkAA = 0;
    }
    if (func_8001B62C(gCurrentParsedObject, 0) > 10.0f) {
        if ((func_8001B62C(gCurrentParsedObject, 0) > 25.0f) && (sp44->unkAA == 1)) {
            sp32 = 0;
            do {
                sp40 = func_80027464(1, &D_80114384, sp44->Pos.x, sp44->Pos.y + 120.0f, sp44->Pos.z, sp44->unk3C);
                if (sp40 != -1) {
                    func_8001ABF4(sp40, 0, 3, &D_801193AC);
                    func_80026F10(gCurrentParsedObject, sp40);
                    if (sp32 == 0) {
                        gObjects[sp40].unk3C = 0.0f;
                    } else if (sp32 == 1) {
                        gObjects[sp40].unk3C = 90.0f;
                    } else if (sp32 == 2) {
                        gObjects[sp40].unk3C = 180.0f;
                    } else {
                        gObjects[sp40].unk3C = 270.0f;
                    }
                    gObjects[sp40].unkB2 = 3;
                    gObjects[sp40].unkAA = 1;
                }
            } while (++sp32 < 4);
            sp44->unkAA = (s16) (sp44->unkAA + 1);
        } else if (sp44->unkAA == 0) {
            func_80029EF8(gCurrentParsedObject, 45.0f, 3.0f);
            sp44->unkAA = (s16) (sp44->unkAA + 1);
        }
    } else {
        sp44->Vel.y = 0.0f;
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        sp44->Vel.y = 0.0f;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp44->action_state = 2;
        sp44->unkAA = 0;
        sp44->unkB2 = 0;
        sp44->unk132 = 0U;
    }
}

void func_800E1640(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800E1670(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkD4 = (f32) sp2C->Vel.y;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119268.unk30.z);
    }
    sp2C->Vel.z = 0.0f;
    sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
    if (sp2C->unk108 == 1) {
        func_8001BBDC(gCurrentParsedObject, 0);
        if (sp2C->unkB2 == 1) {
            if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
                func_8001C0EC(gCurrentParsedObject, 0, 5, 0x70, &D_80118FF4);
                func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119268);
                func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119268.Rot.y);
                sp2C->unkB2 = 0;
                sp2C->action_state = 2;
            } else {
                sp2C->action_state = 3;
                sp2C->unkA8 = 3;
                sp2C->Vel.y = (f32) sp2C->unkD4;
            }
        } else if (sp2C->unkB2 == 2) {
            if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
                func_8001C0EC(gCurrentParsedObject, 0, 5, 0x70, &D_80118FF4);
                func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119268);
                func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119268.Rot.y);
                sp2C->unkB2 = 0;
                sp2C->action_state = 2;
            } else {
                sp2C->action_state = 4;
                sp2C->unkAA = 2;
                sp2C->Vel.y = (f32) sp2C->unkD4;
            }
        } else {
            sp2C->action_state = 2;
            sp2C->unk132 = 0U;
            sp2C->unkA6 = 0;
        }
    }
}

void func_800E1978(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    sp4->unk44 = 0.0f;
    sp4->Vel.z = 0.0f;
    sp4->Vel.x = (f32) sp4->Vel.z;
    if (sp4->unkB2 == 1) {
        sp4->action_state = 3;
        sp4->unkA8 = 3;
    } else if (sp4->unkB2 == 2) {
        sp4->action_state = 4;
        sp4->unkAA = 2;
    } else if (sp4->unkB2 == 9) {
        sp4->action_state = 1;
        sp4->unk132 = 0;
    } else {
        sp4->action_state = 2;
        sp4->unk132 = 0;
        sp4->unkA6 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E1AA8.s")

void func_800E1C04(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->action_state = 5;
        sp4->unk132 = 0;
    } else if (D_80177A64 == 1) {
        sp4->unk108 = 0x3C;
    }
}

void func_800E1C9C(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        func_80029EF8(gCurrentParsedObject, 0, 4.0f);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp34->Rot.y = func_8002A46C(gCurrentParsedObject);
    sp34->unk3C = (f32) sp34->Rot.y;
    func_8002A8B4(gCurrentParsedObject, 5.0f);
    sp34->Rot.y = (f32) sp34->unk3C;
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        sp34->Vel.y = 0.0f;
    }
    if (sp34->Scale.x < 2.0f) {
        sp34->Scale.x = (f32) ((f64) sp34->Scale.x + D_80115428);
        sp34->Scale.y = (f32) ((f64) sp34->Scale.y + D_80115430);
        sp34->Scale.z = (f32) ((f64) sp34->Scale.z + D_80115438);
    } else {
        sp34->unk108 = 1;
        sp34->action_state = 2;
        sp34->unk132 = 0U;
    }
}

void func_800E1F20(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 6, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801192E0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801192E0.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 3;
        sp24->unk132 = 0U;
    }
}

void func_800E2068(void) {
    struct ObjectStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801192E0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801192E0.Rot.y);
        sp44->unk3C = func_8002A46C(gCurrentParsedObject);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkA8 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (sp44->unkA8 < 4) {
        if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(gCurrentParsedObject, 20.0f, 4.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(gCurrentParsedObject, 0, 0, 0, 30.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
            if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
                if (func_8002A1FC(gCurrentParsedObject, 300.0f) != 0) {
                    sp44->action_state = 4;
                    sp44->unkA8 = 0;
                    sp44->unkB2 = 1;
                    sp44->unk132 = 0U;
                } else {
                    sp44->unkA8 = (s16) (sp44->unkA8 + 1);
                }
                sp44->unkA6 = 0;
            } else {
                sp44->Vel.z = 0.0f;
                sp44->Vel.x = (f32) sp44->Vel.z;
            }
        }
    } else {
        sp44->action_state = 2;
        sp44->unkB2 = 0;
        sp44->unk132 = 0U;
    }
}

void func_800E2400(void) {
    struct ObjectStruct* sp4C;
    f32 sp48;
    f32 temp_f20;
    s32 temp;
    s32 temp2;

    sp4C = &gObjects[gCurrentParsedObject];
    if (sp4C->unk132 == 0) {
        sp4C->unk132 = (u8) (sp4C->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0xA, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801192E0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801192E0.Rot.y);
        sp4C->unk44 = 5.0f;
        sp4C->unkA6 = 0;
        sp4C->unkB2 = 2;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp4C->Rot.y = (f32) sp4C->unk3C;
    if (func_8001B62C(gCurrentParsedObject, 0) > 10.0f) {
        if (func_8001B62C(gCurrentParsedObject, 0) > 29.0f) {
            if (sp4C->unkA6 == 1) {
                sp4C->unkA6 = 2;
                func_80029EF8(gCurrentParsedObject, 0, 1.0f);
            }
        } else if (sp4C->unkA6 == 0) {
            sp4C->unkA6 = 1;
            func_80029EF8(gCurrentParsedObject, 40.0f, 2.0f);
        }
        sp48 = sp4C->Vel.y;
        sp4C->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
        sp4C->Vel.y = sp48;
        if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
            sp4C->Vel.z = 0.0f;
            sp4C->Vel.x = sp4C->Vel.y = sp4C->Vel.z;
        }
        if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
            sp4C->action_state = 5;
            sp4C->unkB2 = 3;
            sp4C->unk132 = 0U;
        }
    }
}

void func_800E2738(void) {
    struct ObjectStruct* sp44;
    f32 sp40;
    f32 temp_f20;
    f32 temp_f20_2;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0x70, &D_80118FF4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801192E0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801192E0.Rot.y);
        func_80029EF8(gCurrentParsedObject, -5.0f, 0);
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkB2 = 3;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp44->Rot.y = (f32) sp44->unk3C;
    sp40 = sp44->Vel.y;
    sp44->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp44->Vel.y = sp40;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->unk44 = 0.0f;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->action_state = 2;
        sp44->unkA6 = 0;
        sp44->unkB2 = 0;
        sp44->unk132 = 0U;
    }
}

void func_800E2A00(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800E2A30(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkD4 = (f32) sp2C->Vel.y;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801192E0.unk30.z);
    }
    sp2C->Vel.z = 0.0f;
    sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
    if (sp2C->unk108 == 1) {
        func_8001BBDC(gCurrentParsedObject, 0);
        sp2C->Vel.y = (f32) sp2C->unkD4;
        if (sp2C->unkB2 == 1) {
            sp2C->action_state = 3;
            sp2C->unkA8 = 3;
        } else if (sp2C->unkB2 == 2) {
            if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
                func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0x70, &D_80118FF4);
                func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801192E0);
                func_8001ABF4(gCurrentParsedObject, 1, 0, &D_801192E0.Rot.y);
                func_80029EF8(gCurrentParsedObject, -5.0f, 0);
                sp2C->unk44 = 6.0f;
                sp2C->unkA6 = 0;
                sp2C->unkB2 = 3;
                sp2C->action_state = 5;
            } else {
                sp2C->action_state = 4;
            }
        } else if (sp2C->unkB2 == 3) {
            sp2C->action_state = 5;
        } else {
            sp2C->action_state = 2;
            sp2C->unk132 = 0U;
            sp2C->unkA6 = 0;
        }
    }
}

void func_800E2CDC(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    sp4->unk44 = 0.0f;
    sp4->Vel.z = 0.0f;
    sp4->Vel.x = (f32) sp4->Vel.z;
    if (sp4->unkB2 == 1) {
        sp4->action_state = 3;
        sp4->unkA8 = 3;
    } else if (sp4->unkB2 == 2) {
        sp4->action_state = 4;
    } else if (sp4->unkB2 == 3) {
        sp4->action_state = 5;
    } else if (sp4->unkB2 == 9) {
        sp4->action_state = 1;
        sp4->unk132 = 0;
    } else {
        sp4->action_state = 2;
        sp4->unk132 = 0;
        sp4->unkA6 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E2E28.s")

void func_800E2F94(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->action_state = 6;
        sp4->unk132 = 0;
    } else if (D_80177A64 == 1) {
        sp4->unk108 = 0x3C;
    }
}

void func_800E302C(void) {
    struct ObjectStruct* sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_80029EF8(gCurrentParsedObject, 40.0f, 4.0f);
        sp24->unk44 = 10.0f;
        func_800175F0(gCurrentParsedObject, 0, 0x5B, -1, 0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    if (sp24->Vel.y < 0.0f) {
        sp20 = sp24->Vel.y;
        sp24->Vel.y = 0.0f;
        if (func_80029018(gCurrentParsedObject, 3, 30.0f, 0, 0.0f, 0.0f) != 0) {
            sp24->action_state = 2;
        }
        sp24->Vel.y = sp20;
    }
    if (func_8002A0D0(gCurrentParsedObject, 0, 0, 0) == 1) {
        sp24->action_state = 2;
    }
}

void func_800E31E4(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800E3214(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    s32 temp;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB0 = 0;
        sp2C->unk44 = 30.0f;
        func_80029EF8(gCurrentParsedObject, 0, 4.0f);
        func_800175F0(gCurrentParsedObject, 0, 0x5B, -1, 0);
    }
    if (sp2C->unkAA == 1) {
        if (func_80028FA0(gCurrentParsedObject) != 0) {
            func_8002B114(gCurrentParsedObject);
        }
        if (sp2C->action_state != 2) {
            if (sp2C->unkB0 < 0x3C) {
                sp2C->unkB0 = (s16) (sp2C->unkB0 + 1);
                if ((sp2C->unkB0 >= 7) && (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1)) {
                    sp2C->action_state = 2;
                }
                sp28 = sp2C->Vel.y;
                sp2C->Vel.y = 0.0f;
                func_80029C40(gCurrentParsedObject);
                if (func_80029018(gCurrentParsedObject, 3, 30.0f, 0, 0.0f, 0.0f) != 0) {
                    sp2C->action_state = 2;
                }
                sp2C->Vel.y = sp28;
                sp2C->unk44 = (f32) ((f64) sp2C->unk44 * D_80115460);
            } else {
                sp2C->action_state = 2;
            }
        }
    }
}

void func_800E3474(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800E34A4(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    s32 temp;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB0 = 0;
        sp2C->unk44 = 30.0f;
        func_80029EF8(gCurrentParsedObject, 0, 4.0f);
        func_800175F0(gCurrentParsedObject, 0, 0x5B, -1, 0);
    }
    if (sp2C->unkAA == 1) {
        if (func_80028FA0(gCurrentParsedObject) != 0) {
            func_8002B114(gCurrentParsedObject);
        }
        if (sp2C->action_state != 2) {
            if (sp2C->unkB0 < 0x3C) {
                sp2C->unkB0 = (s16) (sp2C->unkB0 + 1);
                if ((sp2C->unkB0 >= 7) && (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1)) {
                    sp2C->action_state = 2;
                }
                sp28 = sp2C->Vel.y;
                sp2C->Vel.y = 0.0f;
                func_80029C40(gCurrentParsedObject);
                if (func_80029018(gCurrentParsedObject, 3, 30.0f, 0, 0.0f, 0.0f) != 0) {
                    sp2C->action_state = 2;
                }
                sp2C->Vel.y = sp28;
                sp2C->unk44 = (f32) ((f64) sp2C->unk44 * D_80115468);
            } else {
                sp2C->action_state = 2;
            }
        }
    }
}

void func_800E3704(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800E3734(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->unkB2) {
        case 1:
            switch (sp24->action_state) {
                case 1:
                    func_800E302C();
                    break;
                case 2:
                    func_800E31E4();
                    break;
                default:
                    break;
            }
            break;
        case 2:
            switch (sp24->action_state) {
                case 1:
                    func_800E3214();
                    break;
                case 2:
                    func_800E3474();
                    break;
                default:
                    break;
            }
            break;
        case 3:
            switch (sp24->action_state) {
                case 1:
                    func_800E34A4();
                    break;
                case 2:
                    func_800E3704();
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void func_800E38D8(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    sp4->action_state = 2;
    sp4->unk132 = 0;
}

void func_800E3930(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = (u8) (sp4->unk132 + 1);
        sp4->unkC2 = 0xE;
    }
    if (sp4->unkC2 == 0) {
        sp4->action_state = 2;
        sp4->unk132 = 0U;
    } else {
        sp4->unkC2 = (s16) (sp4->unkC2 - 1);
    }
}

void func_800E39F4(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    sp20 = func_80027464(1, &D_80114390, sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, sp24->unk3C);
    if (sp20 != -1) {
        func_8001C0EC(sp20, 0, 2, 0x70, &D_80118FF4);
        func_8001ABF4(sp20, 0, 0, &D_801191F0);
        func_8001ABF4(sp20, 1, 0, &D_801191F0.Rot.y);
        gObjects[sp20].Rot.y = sp24->Rot.y;
        gObjects[sp20].unk108 = 0;
        func_8002B114(gCurrentParsedObject);
        sp24->unkB2 = 9;
    }
}

void func_800E3B40(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    sp20 = func_80027464(1, &D_8011439C, sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, sp24->unk3C);
    if (sp20 != -1) {
        func_8001C0EC(sp20, 0, 5, 0x70, &D_80118FF4);
        func_8001ABF4(sp20, 0, 0, &D_80119268);
        func_8001ABF4(sp20, 1, 0, &D_80119268.Rot.y);
        gObjects[sp20].Rot.y = sp24->Rot.y;
        gObjects[sp20].unk108 = 0;
        func_8002B114(gCurrentParsedObject);
        sp24->unkB2 = 9;
    }
}

void func_800E3C8C(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    sp20 = func_80027464(1, &D_801143A8, sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, sp24->unk3C);
    if (sp20 != -1) {
        func_8001C0EC(sp20, 0, 6, 0x70, &D_80118FF4);
        func_8001ABF4(sp20, 0, 0, &D_801192E0);
        func_8001ABF4(sp20, 1, 0, &D_801192E0.Rot.y);
        gObjects[sp20].Rot.y = sp24->Rot.y;
        gObjects[sp20].unk108 = 0;
        func_8002B114(gCurrentParsedObject);
        sp24->unkB2 = 9;
    }
}

void func_800E3DD8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->action_state) {
        case 1:
            func_800E3930();
            break;
        case 2:
            switch (sp24->unkB2) {
                case 1:
                    func_800E39F4();
                    break;
                case 2:
                    func_800E3B40();
                    break;
                case 3:
                    func_800E3C8C();
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void func_800E3EE4(void) {
    struct ObjectStruct* sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;

    sp4C = &gObjects[gCurrentParsedObject];
    sp48 = sp4C->Pos.x;
    sp44 = sp4C->Pos.y;
    sp40 = sp4C->Pos.z;
    sp3C = gObjects[sp4C->unk104].Pos.x;
    sp38 = gObjects[sp4C->unk104].Pos.y;
    sp34 = gObjects[sp4C->unk104].Pos.z;
    sp30 = func_80027464(1, &D_801143B4, (sp48 + sp3C) / 2.0f, (sp44 + sp38) / 2.0f, (sp40 + sp34) / 2.0f, sp4C->unk3C);
    if (sp30 != -1) {
        func_8001ABF4(sp30, 0, 0, &D_8011940C);
        gObjects[sp30].Rot.y = sp4C->Rot.y;
        switch (sp4C->obj_id) {
            case 0xA1:
                if (sp4C->unk106 == 0xA2) {
                    if ((gObjects[sp4C->unk104].action_state == 0) || (gObjects[sp4C->unk104].action_state == 6)) {

                    } else {
                        gObjects[sp30].unkB2 = 1;
                    }
                } else {
                    if ((gObjects[sp4C->unk104].action_state == 0) || (gObjects[sp4C->unk104].action_state == 7)) {

                    } else {
                        gObjects[sp30].unkB2 = 3;
                    }
                }
                break;
            case 0xA2:
                if (sp4C->unk106 == 0xA1) {
                    if ((gObjects[sp4C->unk104].action_state == 0) || (gObjects[sp4C->unk104].action_state == 5)) {

                    } else {
                        gObjects[sp30].unkB2 = 1;
                    }
                } else {
                    if ((gObjects[sp4C->unk104].action_state == 0) || (gObjects[sp4C->unk104].action_state == 7)) {

                    } else {
                        gObjects[sp30].unkB2 = 2;
                    }
                }
                break;
            case 0xA3:
                if (sp4C->unk106 == 0xA2) {
                    if ((gObjects[sp4C->unk104].action_state == 0) || (gObjects[sp4C->unk104].action_state == 6)) {

                    } else {
                        gObjects[sp30].unkB2 = 2;
                    }
                } else {
                    if ((gObjects[sp4C->unk104].action_state == 0) || (gObjects[sp4C->unk104].action_state == 5)) {

                    } else {
                        gObjects[sp30].unkB2 = 3;
                    }
                }
                break;
        }
    }
    func_8002B114(sp4C->unk104);
    func_8002B114(gCurrentParsedObject);
}

void func_800E445C(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801143C0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = 0;
    }
}

void func_800E450C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->action_state = 0xB;
    } else {
        sp4->Vel.z = 0.0f;
        sp4->Vel.x = sp4->Vel.y = sp4->Vel.z;
        sp4->action_state = 0xC;
    }
    sp4->unk132 = 0;
}

void func_800E45C4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x7E, &D_80119428);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119494);
        sp24->unk108 = -1;
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8002A2EC(gCurrentParsedObject, 600.0f) != 0) {
        sp24->action_state = 2;
        sp24->unk132 = 0U;
    }
    if (sp24->unkA6 >= 2) {
        sp24->action_state = 0xA;
        sp24->unk132 = 0U;
    }
}

void func_800E4728(void) {
    struct ObjectStruct* sp34;
    s16 temp;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unkB2 = (s16) sp34->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x7E, &D_80119428);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119494.Rot.y);
        sp34->unkA6 = (s16) (sp34->unkA6 + 1);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    sp34->Rot.y = (f32) sp34->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp34->unk44 = 78.0f;
        func_80029EF8(gCurrentParsedObject, 83.0f, 0);
        sp2C = sp34->Vel.y;
        sp34->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 0.0f, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
            sp34->action_state = 9;
            sp34->unk132 = 0U;
        } else if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
            sp34->action_state = 9;
            sp34->unk132 = 0U;
        } else {
            sp34->action_state = 3;
            sp34->unk132 = 0U;
        }
        sp34->Vel.y = sp2C;
        sp34->unk44 = 0.0f;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
    }
}

void func_800E49AC(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unkB2 = (s16) sp34->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x7E, &D_80119428);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119494.unk54);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp34->unk44 = 163.0f;
        func_80029EF8(gCurrentParsedObject, 118.0f, 0);
        sp30 = sp34->Vel.y;
        sp34->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 0, 30.0f, 0, 0.0f, 0.0f) != 0) {
            sp34->action_state = 8;
            sp34->unk132 = 0U;
        } else if (func_80029F58(gCurrentParsedObject, 0, 0, 0, 0.0f) == 1) {
            sp34->action_state = 8;
            sp34->unk132 = 0U;
        } else {
            sp34->action_state = 4;
            sp34->unk132 = 0U;
        }
        sp34->Vel.y = sp30;
        sp34->unk44 = 0.0f;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
    }
}

void func_800E4BF4(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    f32 temp_f20;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unkB2 = (s16) sp34->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x7E, &D_80119428);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119494.unk54);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp34->unk44 = 222.0f;
        func_80029EF8(gCurrentParsedObject, 86.0f, 0);
        sp30 = sp34->Vel.y;
        sp34->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 0, 30.0f, 0, 0.0f, 0.0f) != 0) {
            sp34->action_state = 7;
            sp34->unk132 = 0U;
        } else if (func_80029F58(gCurrentParsedObject, 0, 0, 0, 0.0f) == 1) {
            sp34->action_state = 7;
            sp34->unk132 = 0U;
        } else {
            sp34->action_state = 5;
            sp34->unk132 = 0U;
        }
        sp34->Vel.y = sp30;
        sp34->unk44 = 0.0f;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
    }
}

void func_800E4E3C(void) {
    struct ObjectStruct* sp2C;
    s32 temp;
    s32 temp2;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0x7E, &D_80119428);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119494.unk54);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->action_state = 6;
        sp2C->unk132 = 0U;
    }
}

void func_800E4F40(void) {
    struct ObjectStruct* sp2C;
    s32 temp;
    s32 temp2;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 6, 0x7E, &D_80119428);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119494.unk54);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->action_state = 7;
        sp2C->unk132 = 0U;
    }
    sp2C->unkB2 = (s16) sp2C->action_state;
}

void func_800E5058(void) {
    struct ObjectStruct* sp2C;
    s32 temp;
    s32 temp2;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0x7E, &D_80119428);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119494.unk54);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->action_state = 8;
        sp2C->unk132 = 0U;
    }
}

void func_800E515C(void) {
    struct ObjectStruct* sp2C;
    s32 temp;
    s32 temp2;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 8, 0x7E, &D_80119428);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119494.unk54);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->action_state = 9;
        sp2C->unk132 = 0U;
    }
}

void func_800E5260(void) {
    struct ObjectStruct* sp2C;
    s32 temp;
    s32 temp2;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 9, 0x7E, &D_80119428);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119494.unk30.z);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->action_state = 1;
        sp2C->unk132 = 0U;
    }
}

void func_800E5364(void) {
    struct ObjectStruct* sp2C;
    s32 temp;
    s32 temp2;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 0xA, 0x7E, &D_80119428);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119494);
        sp2C->unk108 = 1;
        sp2C->unkA8 = 1;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->Rot.y = func_8002A46C(gCurrentParsedObject);
        sp2C->unk3C = (f32) sp2C->Rot.y;
        if (sp2C->unkA8 == 0) {
            sp2C->action_state = 1;
            sp2C->unk132 = 0U;
            sp2C->unkA6 = 0;
            sp2C->unk108 = -1;
        } else {
            sp2C->unkA8 = (s16) (sp2C->unkA8 - 1);
        }
    }
}

void func_800E54F8(void) {
    func_8002B0E4(gCurrentParsedObject);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E5528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E56D4.s")

void func_800E5824(void) {
    func_80027464(1, &D_801143CC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800E589C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        if ((sp4->unk106 == 9) || (sp4->unk106 == 0x10)) {
            sp4->unk108 = 0;
            sp4->action_state = 4;
        }
    } else {
        sp4->action_state = 5;
    }
    sp4->unk132 = 0;
}

void func_800E594C(void) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x82, &D_80119504);
        sp34->unk44 = 1.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp34->unkA6 == 0) {
            sp30 = Math_Random(4);
            switch (sp30) { /* irregular */
                case 0:
                    sp34->Rot.y = 0.0f;
                    sp34->unk3C = (f32) sp34->Rot.y;
                    break;
                case 1:
                    sp34->Rot.y = 90.0f;
                    sp34->unk3C = (f32) sp34->Rot.y;
                    break;
                case 2:
                    sp34->Rot.y = 180.0f;
                    sp34->unk3C = (f32) sp34->Rot.y;
                    break;
                default:
                    sp34->Rot.y = 270.0f;
                    sp34->unk3C = (f32) sp34->Rot.y;
                    break;
            }
            sp34->unkA6 = 3;
        } else {
            sp34->unkA6 = (s16) (sp34->unkA6 - 1);
        }
    }
    if (func_8002A1FC(gCurrentParsedObject, 600.0f) != 0) {
        sp34->action_state = 2;
        sp34->unk132 = 0U;
        sp34->unkA6 = 0;
    }
}

void func_800E5C14(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x82, &D_80119504);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp24->unk44 = 2.0f;
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = (f32) sp24->Vel.z;
        sp24->unk44 = 0.0f;
    }
    if (func_8002A1FC(gCurrentParsedObject, 180.0f) != 0) {
        sp24->action_state = 3;
        sp24->unk132 = 0U;
    } else if (func_8002A1FC(gCurrentParsedObject, 600.0f) != 0) {

    } else {
        sp24->action_state = 1;
        sp24->unk132 = 0U;
    }
}

void func_800E5DF0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x82, &D_80119504);
        sp24->unk44 = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = (f32) sp24->Vel.z;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 1;
        sp24->unk132 = 0U;
    }
}

void func_800E5F18(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unk44 = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = (f32) sp24->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x82, &D_80119504);
        func_800175F0(gCurrentParsedObject, 0, 0x58, -1, 0);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->unkAC = (s16) (sp24->unkAC + 1);
        if (sp24->unkAA == 0) {
            func_8001BBDC(gCurrentParsedObject, 1);
            sp24->unkAA = (s16) (sp24->unkAA + 1);
        }
    }
    if (sp24->unkAC != 0) {
        if (sp24->unkAA < 9) {
            sp24->unkAA = (s16) (sp24->unkAA + 1);
        } else {
            func_8002B0E4(gCurrentParsedObject);
        }
    }
}

void func_800E60D8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unk44 = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = (f32) sp24->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x82, &D_80119504);
        sp24->unk3C = func_8002A46C(gCurrentParsedObject);
        sp24->Rot.y = (f32) sp24->unk3C;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp24->unkA8 >= 3) {
            sp24->action_state = 1;
            sp24->unk132 = 0U;
            sp24->unkA8 = 0;
        } else {
            sp24->unkA8 = (s16) (sp24->unkA8 + 1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E624C.s")

void func_800E632C(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114450, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_8001ABF4(sp24, 0, 0, &D_80119750);
        gObjects[sp24].unk108 = 0;
    }
}

void func_800E63F4(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011445C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_8001ABF4(sp24, 0, 0, &D_80119828);
        func_8001ABF4(sp24, 1, 0, &D_80119828.Rot.y);
        func_8001ABF4(sp24, 2, 0, &D_80119828.unk30.z);
    }
}

void func_800E64D0(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        if (sp4->unkB2 != 9) {
            sp4->unk132 = 0;
        }
        sp4->action_state = 9;
    } else if (D_80177A64 == 1) {
        sp4->unk108 = 0x3C;
        sp4->action_state = (s16) sp4->unkB2;
    } else {
        if (sp4->unkB2 == 6) {
            sp4->unkA6 = 1;
        }
        sp4->action_state = (s16) sp4->unkB2;
        sp4->unk44 = 0.0f;
        sp4->Vel.x = sp4->Vel.z = sp4->unk44;
        sp4->unk132 = 0;
    }
}

void func_800E660C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB4, &D_80119788);
    }
    if (func_8002A1FC(gCurrentParsedObject, 360.0f) != 0) {
        sp24->action_state = 2;
        sp24->unk132 = 0U;
    } else if (func_8002A1FC(gCurrentParsedObject, 600.0f) != 0) {
        sp24->action_state = 6;
        sp24->unk132 = 0U;
    }
}

void func_800E6720(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xB4, &D_80119788);
    }
    sp24->unk3C = (f32) sp24->Rot.y;
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 3;
        sp24->unk132 = 0U;
    }
}

void func_800E683C(void) {
    struct ObjectStruct* sp3C;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = (u8) (sp3C->unk132 + 1);
        sp3C->unkB2 = (s16) sp3C->action_state;
        sp3C->unk44 = 10.0f;
        sp3C->unkA8 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0xB4, &D_80119788);
        func_80029EF8(gCurrentParsedObject, 16.0f, 4.0f);
    }
    if (func_80029018(gCurrentParsedObject, 0, 180.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = (f32) sp3C->Vel.z;
        sp3C->unk44 = 0.0f;
    } else {
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_80029824(gCurrentParsedObject, func_800297DC());
        }
    }
    if (func_8002A0D0(gCurrentParsedObject, 0.0f, 0.0f, 0.0f) == 1) {
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z;
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp3C->Rot.y = (f32) sp3C->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp3C->action_state = 4;
        sp3C->unk132 = 0U;
    }
}

void func_800E6AA0(void) {
    struct ObjectStruct* sp3C;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = (u8) (sp3C->unk132 + 1);
        sp3C->unkB2 = (s16) sp3C->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0xB4, &D_80119788);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_8002A0D0(gCurrentParsedObject, 0.0f, 0.0f, 0.0f) == 1) {
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp3C->action_state = 5;
        sp3C->unk132 = 0U;
    }
}

void func_800E6C48(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 0xD, 0xB4, &D_80119788);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 1;
        sp24->unk132 = 0U;
    }
}

void func_800E6D2C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xB4, &D_80119788);
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    sp24->Rot.y = func_80015538(sp24->Rot.y, 270.0f);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp24->unkA6 == 0) {
            sp24->action_state = 7;
        } else {
            sp24->action_state = 8;
        }
        sp24->unk132 = 0U;
    }
}

void func_800E6E80(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        sp2C->unk44 = 18.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 6, 0xB4, &D_80119788);
        sp2C->unkB6 = 0;
    }
    if (func_8002A1FC(gCurrentParsedObject, 960.0f) != 0) {
        if (sp2C->unkB6 == 0) {
            sp2C->unkB6 = 0xF;
            func_800175F0(gCurrentParsedObject, 0, 0x53, -1, 0);
        } else {
            sp2C->unkB6 = (s16) (sp2C->unkB6 - 1);
        }
    }
    func_8002A8B4(gCurrentParsedObject, 6.0f);
    sp2C->Rot.y = (f32) sp2C->unk3C;
    sp2C->Rot.y = func_80015538(sp2C->Rot.y, 270.0f);
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, 0);
    }
    if (func_8002A1FC(gCurrentParsedObject, 240.0f) != 0) {
        sp2C->unk44 = 0.0f;
        sp2C->Vel.x = sp2C->Vel.z = sp2C->unk44;
        sp2C->action_state = 8;
        sp2C->unk132 = 0U;
    }
}

void func_800E70D0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xB4, &D_80119788);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 1;
        sp24->unkA6 = 0;
        sp24->unk132 = 0U;
    }
}

void func_800E71C0(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unk108 = 0;
        sp2C->unkB2 = (s16) sp2C->action_state;
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 0xC, 0xB4, &D_80119788);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119828.unk54);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119828.unk64[0][3]);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119828.unk64[2][2]);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E7344.s")

void func_800E74C0(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114468, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
}

void func_800E753C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        if (sp4->unkB2 != 6) {
            sp4->unk132 = 0;
        }
        sp4->action_state = 6;
    } else if (D_80177A64 == 1) {
        sp4->unk108 = 0x3C;
        sp4->action_state = (s16) sp4->unkB2;
    } else {
        sp4->action_state = 5;
        sp4->Vel.z = 0.0f;
        sp4->Vel.x = sp4->Vel.y = sp4->Vel.z;
        sp4->unk132 = 0;
    }
}

void func_800E764C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0xB4, &D_80119788);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119828);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119828.Rot.y);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119828.unk30.z);
    }
    if (func_8002A1FC(gCurrentParsedObject, 540.0f) != 0) {
        sp24->action_state = 2;
        sp24->unk132 = 0U;
    }
}

void func_800E778C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_80029EF8(gCurrentParsedObject, 0.0f, 4.0f);
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0xB4, &D_80119788);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    sp24->Rot.y = func_8002A46C(gCurrentParsedObject);
    sp24->unk3C = (f32) sp24->Rot.y;
    if ((sp24->unkA6 == 0) && (func_8002A0D0(gCurrentParsedObject, 0.0f, 0.0f, -120.0f) == 1)) {
        func_8001C0EC(gCurrentParsedObject, 0, 8, 0xB4, &D_80119788);
        func_8001BBDC(gCurrentParsedObject, 0);
        sp24->unkA6 = 1;
    }
    if (func_8002A0D0(gCurrentParsedObject, 0.0f, 0.0f, 0.0f) == 1) {
        sp24->Vel.y = 0.0f;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 3;
        sp24->unk132 = 0U;
    }
}

void func_800E7974(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 9, 0xB4, &D_80119788);
    }
    func_8002A8B4(gCurrentParsedObject, 4.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 4;
        sp24->unk132 = 0U;
    }
}

void func_800E7A7C(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        sp2C->unk3C = func_8002A46C(gCurrentParsedObject);
        sp2C->Rot.y = (f32) sp2C->unk3C;
        sp2C->unk44 = 6.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0xA, 0xB4, &D_80119788);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_8002A8B4(gCurrentParsedObject, 4.0f);
    sp2C->Rot.y = (f32) sp2C->unk3C;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        sp2C->action_state = 5;
        sp2C->unk132 = 0U;
    }
}

void func_800E7C54(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0xB4, &D_80119788);
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 4;
        sp24->unk132 = 0U;
    }
}

void func_800E7D5C(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unk108 = 0;
        sp2C->unkB2 = (s16) sp2C->action_state;
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 0xC, 0xB4, &D_80119788);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119828.unk54);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119828.unk64[0][3]);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119828.unk64[2][2]);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E7EE0.s")

void func_800E802C(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114474, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unk13A = 1;
    }
}

void func_800E80E0(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->action_state = 5;
        sp4->unk132 = 0;
    } else {
        sp4->action_state = (s16) sp4->unkB2;
    }
}

void func_800E816C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB5, &D_801198D0);
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        sp24->action_state = 2;
        sp24->unk132 = 0U;
    }
}

void func_800E8250(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        sp1C->unkB2 = (s16) sp1C->action_state;
        sp1C->Vel.y = 48.0f;
        sp1C->unk13A = 0;
    }
    sp1C->Rot.y = func_80015538(sp1C->Rot.y, 36.0f);
    sp1C->unk3C = (f32) sp1C->Rot.y;
    if (sp1C->Vel.y <= 0.0f) {
        sp1C->action_state = 3;
        sp1C->unk132 = 0U;
        sp1C->Vel.y = 0.0f;
    } else {
        sp1C->Vel.y = (f32) (sp1C->Vel.y - 4.0f);
    }
}

void func_800E839C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xB5, &D_801198D0);
    }
    sp24->unk3C = func_8002A46C(gCurrentParsedObject);
    sp24->Rot.y = (f32) sp24->unk3C;
    sp24->Rot.y = func_80015538(sp24->Rot.y, 45.0f);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 4;
        sp24->unk132 = 0U;
    }
}

void func_800E84D4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        sp24->unk44 = 18.0f;
        sp24->Vel.y = -6.0f;
        sp24->unkA6 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xB5, &D_801198D0);
    }
    if (sp24->unkA6 == 1) {
        sp24->unk44 = (f32) (sp24->unk44 - 2.0f);
        if (sp24->unk44 <= 0.0f) {
            sp24->unk44 = 0.0f;
            sp24->Vel.z = 0.0f;
            sp24->Vel.x = (f32) sp24->Vel.z;
            sp24->unkA6 = 2;
            sp24->action_state = 9;
            sp24->unk132 = 0U;
        }
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = (f32) sp24->Vel.z;
        sp24->unk44 = 0.0f;
        sp24->action_state = 6;
        sp24->unk132 = 0U;
        sp24->unkA6 = 2;
    }
    func_8002A8B4(gCurrentParsedObject, 4.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    sp24->Rot.y = func_80015538(sp24->Rot.y, 45.0f);
    if (sp24->unkA6 != 2) {
        func_80029C40(gCurrentParsedObject);
    }
    if (func_80029018(gCurrentParsedObject, 0, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = (f32) sp24->Vel.z;
        sp24->unk44 = 0.0f;
        sp24->action_state = 6;
        sp24->unk132 = 0U;
    }
    if (func_8002A0D0(gCurrentParsedObject, 0.0f, 0.0f, 0.0f) == 1) {
        sp24->unkA6 = 1;
        sp24->Vel.y = 0.0f;
    }
}

void func_800E8804(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unk108 = 0;
        sp2C->unkB2 = (s16) sp2C->action_state;
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xB5, &D_801198D0);
        sp2C->unk13A = 1;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800E8934(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        sp24->unk44 = 6.0f;
        sp24->unk3C = func_80015538(sp24->unk3C, 180.0f);
        sp24->Vel.y = -5.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0xB5, &D_801198D0);
    }
    sp24->unk44 = (f32) (sp24->unk44 - 1.0f);
    func_80029C40(gCurrentParsedObject);
    sp24->Vel.y = (f32) (sp24->Vel.y + D_8011550C);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 7;
        sp24->unk132 = 0U;
    }
}

void func_800E8AAC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        sp24->unk44 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0xB5, &D_801198D0);
    }
    sp24->Vel.y = (f32) (sp24->Vel.y + D_80115510);
    if (func_8002A0D0(gCurrentParsedObject, 0.0f, 0.0f, -15.0f) == 1) {
        sp24->action_state = 8;
        sp24->unk132 = 0U;
    }
}

void func_800E8BC8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        sp24->unk108 = 0;
        sp24->Vel.y = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 6, 0xB5, &D_801198D0);
        sp24->unk13A = 1;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->action_state = 9;
        sp24->unk132 = 0U;
    }
}

void func_800E8CD4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        sp24->unk108 = 0;
        sp24->Vel.y = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xB5, &D_801198D0);
        sp24->unk13A = 1;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->action_state = 0xA;
        sp24->unk132 = 0U;
    }
}

void func_800E8DF0(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        sp1C->unkB2 = (s16) sp1C->action_state;
        sp1C->unk108 = 0x3C;
        sp1C->unk13A = 1;
    }
    if (sp1C->unk108 == 3) {
        func_8002B114(gCurrentParsedObject);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E8EC0.s")

void func_800E904C(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114480, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
}

void func_800E90C8(void) {
    struct ObjectStruct* spC;
    s32 temp;
    s16 sp6;

    spC = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        spC->unk108 = 0;
        spC->action_state = 9;
        spC->unk132 = 0;
    } else if (D_80177A64 == 1) {
        spC->unk108 = 0x3C;
        sp6 = 0;
        do {
            gObjects[spC->unkE8[sp6]].unk108 = 0x3C;
        } while (++sp6 < 3);
        spC->action_state = (s16) spC->unkB2;
    } else {
        spC->action_state = (s16) spC->unkB2;
    }
}

void func_800E91E4(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xC3, &D_801198EC);
        func_80027C00(gCurrentParsedObject, 0, &D_80114498, sp2C->Pos.x, sp2C->Pos.y + 172.0f, sp2C->Pos.z,
                      sp2C->Rot.y);
        func_80027C00(gCurrentParsedObject, 1, &D_801144A4, sp2C->Pos.x, sp2C->Pos.y + 172.0f, sp2C->Pos.z,
                      sp2C->Rot.y);
        func_80027C00(gCurrentParsedObject, 2, &D_8011448C, sp2C->Pos.x, sp2C->Pos.y + D_8011553C, sp2C->Pos.z,
                      sp2C->Rot.y);
        func_8001ABF4((s32) sp2C->unkE8[0], 0, 0, &D_8011993C);
        func_8001C0EC((s32) sp2C->unkE8[0], 0, 0, 0xC6, &D_80119974);
        func_8001C0EC((s32) sp2C->unkE8[1], 0, 0, 0xC7, &D_80119978);
        func_8001C0EC((s32) sp2C->unkE8[2], 0, 0, 0xC5, &D_8011990C);
    }
    if (func_8002A2EC(gCurrentParsedObject, 1500.0f) != 0) {
        sp2C->action_state = 2;
        sp2C->unk132 = 0U;
    }
}

void func_800E9420(void) {
    struct ObjectStruct* sp34;
    struct ObjectStruct* temp_t3;
    s16 sp2E;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unkB2 = (s16) sp34->action_state;
        sp34->unk3C = 0.0f;
        sp34->unk44 = 10.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xC3, &D_801198EC);
        func_8001C0EC((s32) sp34->unkE8[2], 0, 0, 0xC5, &D_8011990C);
        gObjects[sp34->unkE8[0]].unk30.z = D_80115540;
        gObjects[sp34->unkE8[1]].unk30.z = D_80115544;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = (f32) sp34->Vel.z;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp24;
    } else {
        sp34->Pos.y = sp28;
    }
    sp2E = 0;
    do {
        gObjects[sp34->unkE8[sp2E]].Pos.x = sp34->Pos.x + sp34->Vel.x;
        gObjects[sp34->unkE8[sp2E]].Pos.y = sp34->Pos.y + sp34->Vel.y;
        gObjects[sp34->unkE8[sp2E]].Pos.z = sp34->Pos.z + sp34->Vel.z;
    } while (++sp2E < 3);
    (&gObjects[sp34->unkE8[0]])->Pos.y = (f32) ((&gObjects[sp34->unkE8[0]])->Pos.y + 172.0f);
    (&gObjects[sp34->unkE8[1]])->Pos.y = (f32) ((&gObjects[sp34->unkE8[1]])->Pos.y + 172.0f);
    (&gObjects[sp34->unkE8[2]])->Pos.y = (f32) ((&gObjects[sp34->unkE8[2]])->Pos.y + D_80115548);
    if (func_8002A2EC(gCurrentParsedObject, 120.0f) != 0) {
        sp34->action_state = 3;
        sp34->unk132 = 0U;
    }
    if (sp34->unkA6 == 1) {
        if (sp34->unkA8 == 0) {
            sp34->action_state = 6;
            sp34->unk132 = 0U;
            sp34->unkA8 = 0x1E;
            return;
        } else {
            sp34->unkA8 = (s16) (sp34->unkA8 - 1);
        }
    }
    if ((gObjects[sp34->unkE8[1]].Rot.z < 270.0f) && (gObjects[sp34->unkE8[1]].Rot.z > 260.0f)) {
        sp34->action_state = 4;
        sp34->unk132 = 0U;
        return;
    } else if ((gObjects[sp34->unkE8[1]].Rot.z < 180.0f) && (gObjects[sp34->unkE8[1]].Rot.z > 170.0f)) {
        sp34->action_state = 4;
        sp34->unk132 = 0U;
        return;
    } else if ((gObjects[sp34->unkE8[1]].Rot.z < 90.0f) && (gObjects[sp34->unkE8[1]].Rot.z > 80.0f)) {
        sp34->action_state = 4;
        sp34->unk132 = 0U;
        return;
    }
    if ((sp34->unkA6 == 3)) {
        if (gObjects[sp34->unkE8[1]].Rot.z < 19.0f) {
            sp34->action_state = 7;
            sp34->unk132 = 0U;
            sp34->unk108 = -1;
            sp2E = 0;
            do {
                gObjects[sp34->unkE8[sp2E]].unk108 = -1;
            } while (++sp2E < 3);
        }
    }
}

void func_800E9AFC(void) {
    struct ObjectStruct* sp34;
    struct ObjectStruct* temp_t4;
    s16 sp2E;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unkB2 = (s16) sp34->action_state;
        sp34->unk3C = 180.0f;
        sp34->unk44 = 24.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xC3, &D_801198EC);
        func_8001C0EC((s32) sp34->unkE8[2], 0, 0, 0xC5, &D_8011990C);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = (f32) sp34->Vel.z;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp24;
    } else {
        sp34->Pos.y = sp28;
    }
    sp2E = 0;
    do {
        gObjects[sp34->unkE8[sp2E]].Pos.x = sp34->Pos.x + sp34->Vel.x;
        gObjects[sp34->unkE8[sp2E]].Pos.y = sp34->Pos.y + sp34->Vel.y;
        gObjects[sp34->unkE8[sp2E]].Pos.z = sp34->Pos.z + sp34->Vel.z;
    } while (++sp2E < 3);
    gObjects[sp34->unkE8[0]].Pos.y = (f32) (gObjects[sp34->unkE8[0]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[1]].Pos.y = (f32) (gObjects[sp34->unkE8[1]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[2]].Pos.y = (f32) (gObjects[sp34->unkE8[2]].Pos.y + D_8011554C);
    if (func_8002A2EC(gCurrentParsedObject, 780.0f) == 0) {
        sp34->action_state = 2;
        sp34->unk132 = 0U;
    }
    if ((sp34->unkA6 == 1) || (sp34->unkA6 == 3)) {
        if (sp34->unkA8 == 0) {
            sp34->action_state = 5;
            sp34->unk132 = 0U;
            sp34->unkA8 = 0x1E;
            return;
        } else {
            sp34->unkA8 = (s16) (sp34->unkA8 - 1);
        }
    }
    if ((gObjects[sp34->unkE8[1]].Rot.z < 270.0f) && (gObjects[sp34->unkE8[1]].Rot.z > 260.0f)) {
        sp34->action_state = 4;
        sp34->unk132 = 0U;
        return;
    } else if ((gObjects[sp34->unkE8[1]].Rot.z < 180.0f) && (gObjects[sp34->unkE8[1]].Rot.z > 170.0f)) {
        sp34->action_state = 4;
        sp34->unk132 = 0U;
        return;
    } else if ((gObjects[sp34->unkE8[1]].Rot.z < 90.0f) && (gObjects[sp34->unkE8[1]].Rot.z > 80.0f)) {
        sp34->action_state = 4;
        sp34->unk132 = 0U;
        sp34->unkAA = 0x64;
        return;
    }
    if (sp34->unkA6 == 3) {
        if (gObjects[sp34->unkE8[1]].Rot.z < 19.0f) {
            sp34->action_state = 7;
            sp34->unk132 = 0U;
            sp34->unk108 = -1;
            sp2E = 0;
            do {
                gObjects[sp34->unkE8[sp2E]].unk108 = -1;
            } while (++sp2E < 3);
        }
    }
}

void func_800EA194(void) {
    struct ObjectStruct* sp34;
    struct ObjectStruct* temp_t0;
    s16 sp2E;
    f32 sp28;
    f32 sp24;
    struct ObjectStruct* temp_t5;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unkB2 = (s16) sp34->action_state;
        sp34->unk3C = 180.0f;
        sp34->unk44 = 24.0f;
        sp34->unkA6 = (s16) (sp34->unkA6 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xC3, &D_801198EC);
        func_8001C0EC((s32) sp34->unkE8[2], 0, 0, 0xC5, &D_8011990C);
        func_800175F0(gCurrentParsedObject, 0, 0x16, -1, 0);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = (f32) sp34->Vel.z;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp24;
    } else {
        sp34->Pos.y = sp28;
    }
    sp2E = 0;
    do {
        gObjects[sp34->unkE8[sp2E]].Pos.x = sp34->Pos.x + sp34->Vel.x;
        gObjects[sp34->unkE8[sp2E]].Pos.y = sp34->Pos.y + sp34->Vel.y;
        gObjects[sp34->unkE8[sp2E]].Pos.z = sp34->Pos.z + sp34->Vel.z;
    } while (++sp2E < 3);
    gObjects[sp34->unkE8[0]].Pos.y = (f32) (gObjects[sp34->unkE8[0]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[1]].Pos.y = (f32) (gObjects[sp34->unkE8[1]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[2]].Pos.y = (f32) (gObjects[sp34->unkE8[2]].Pos.y + D_80115550);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp34->action_state = 3;
        sp34->unk132 = 0U;
        sp34->unkA8 = 0;
    }
}

void func_800EA55C(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    s16 sp2E;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unkB2 = (s16) sp34->action_state;
        sp34->unk3C = 180.0f;
        sp34->unk44 = 24.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0xC3, &D_801198EC);
        func_8001C0EC((s32) sp34->unkE8[2], 0, 0, 0xC5, &D_8011990C);
    }
    if ((func_8001B62C(gCurrentParsedObject, 0) > 20.0f) && (sp34->unk132 == 1)) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp30 =
            func_80027464(1, &D_801144B0, sp34->Pos.x + 160.0f, sp34->Pos.y + 134.0f, sp34->Pos.z + 36.0f, sp34->Rot.y);
        if (sp30 != -1) {
            func_80026F10(sp30, gCurrentParsedObject);
        }
        sp30 =
            func_80027464(1, &D_801144B0, sp34->Pos.x - 160.0f, sp34->Pos.y + 134.0f, sp34->Pos.z + 36.0f, sp34->Rot.y);
        if (sp30 != -1) {
            func_80026F10(sp30, gCurrentParsedObject);
        }
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = (f32) sp34->Vel.z;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp24;
    } else {
        sp34->Pos.y = sp28;
    }
    sp2E = 0;
    do {
        gObjects[sp34->unkE8[sp2E]].Pos.x = sp34->Pos.x + sp34->Vel.x;
        gObjects[sp34->unkE8[sp2E]].Pos.y = sp34->Pos.y + sp34->Vel.y;
        gObjects[sp34->unkE8[sp2E]].Pos.z = sp34->Pos.z + sp34->Vel.z;
    } while (++sp2E < 3);
    gObjects[sp34->unkE8[0]].Pos.y = (f32) (gObjects[sp34->unkE8[0]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[1]].Pos.y = (f32) (gObjects[sp34->unkE8[1]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[2]].Pos.y = (f32) (gObjects[sp34->unkE8[2]].Pos.y + D_80115554);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp34->action_state = 3;
        sp34->unk132 = 0U;
    }
    if (sp34->unkA6 == 3) {
        if (gObjects[sp34->unkE8[1]].Rot.z < 19.0f) {
            sp34->action_state = 7;
            sp34->unk132 = 0U;
        }
    }
}

void func_800EAAB8(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    s16 sp2E;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unkB2 = (s16) sp34->action_state;
        sp34->unk3C = 0.0f;
        sp34->unk44 = 10.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0xC3, &D_801198EC);
        func_8001C0EC((s32) sp34->unkE8[2], 0, 0, 0xC5, &D_8011990C);
    }
    if ((func_8001B62C(gCurrentParsedObject, 0) > 20.0f) && (sp34->unk132 == 1)) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp30 =
            func_80027464(1, &D_801144B0, sp34->Pos.x + 160.0f, sp34->Pos.y + 134.0f, sp34->Pos.z + 36.0f, sp34->Rot.y);
        if (sp30 != -1) {
            func_80026F10(sp30, gCurrentParsedObject);
        }
        sp30 =
            func_80027464(1, &D_801144B0, sp34->Pos.x - 160.0f, sp34->Pos.y + 134.0f, sp34->Pos.z + 36.0f, sp34->Rot.y);
        if (sp30 != -1) {
            func_80026F10(sp30, gCurrentParsedObject);
        }
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = (f32) sp34->Vel.z;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp24;
    } else {
        sp34->Pos.y = sp28;
    }
    sp2E = 0;
    do {
        gObjects[sp34->unkE8[sp2E]].Pos.x = sp34->Pos.x + sp34->Vel.x;
        gObjects[sp34->unkE8[sp2E]].Pos.y = sp34->Pos.y + sp34->Vel.y;
        gObjects[sp34->unkE8[sp2E]].Pos.z = sp34->Pos.z + sp34->Vel.z;
    } while (++sp2E < 3);
    gObjects[sp34->unkE8[0]].Pos.y = (f32) (gObjects[sp34->unkE8[0]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[1]].Pos.y = (f32) (gObjects[sp34->unkE8[1]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[2]].Pos.y = (f32) (gObjects[sp34->unkE8[2]].Pos.y + D_80115558);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp34->action_state = 2;
        sp34->unk132 = 0U;
        sp34->unkA8 = 0x1E;
    }
    if (sp34->unkA6 == 3) {
        if (gObjects[sp34->unkE8[1]].Rot.z < 19.0f) {
            sp34->action_state = 7;
            sp34->unk132 = 0U;
        }
    }
}

void func_800EB01C(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    s32 sp2C;
    f32 temp;
    f32 sp24;
    f32 sp20;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unkB2 = (s16) sp34->action_state;
        sp34->unk3C = 180.0f;
        sp34->unk44 = 8.0f;
        sp34->unkAC = 4;
        sp34->unk108 = -1;
        sp30 = 0;
        do {
            gObjects[sp34->unkE8[sp30]].unk108 = -1;
        } while (++sp30 < 3);
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xC3, &D_801198EC);
        func_8001C0EC((s32) sp34->unkE8[2], 0, 0, 0xC5, &D_8011990C);
        func_8001ABF4((s32) sp34->unkE8[2], 1, 0, &D_8011993C.Rot.y);
        func_800175F0(gCurrentParsedObject, 0, 0x16, -1, 0);
        sp34->unkC2 = 0x11;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = (f32) sp34->Vel.z;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp20, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp20;
    } else {
        sp34->Pos.y = sp24;
    }
    sp30 = 0;
    do {
        gObjects[sp34->unkE8[sp30]].Pos.x = sp34->Pos.x + sp34->Vel.x;
        gObjects[sp34->unkE8[sp30]].Pos.y = sp34->Pos.y + sp34->Vel.y;
        gObjects[sp34->unkE8[sp30]].Pos.z = sp34->Pos.z + sp34->Vel.z;
    } while (++sp30 < 3);
    gObjects[sp34->unkE8[0]].Pos.y = (f32) (gObjects[sp34->unkE8[0]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[1]].Pos.y = (f32) (gObjects[sp34->unkE8[1]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[2]].Pos.y = (f32) (gObjects[sp34->unkE8[2]].Pos.y + D_8011555C);

    gObjects[sp34->unkE8[2]].Scale.x = D_80115180[sp34->unkAE].x;
    gObjects[sp34->unkE8[2]].Scale.y = D_80115184[sp34->unkAE].x;
    gObjects[sp34->unkE8[2]].Scale.z = D_80115188[sp34->unkAE].x;
    sp34->unkAE = (s16) (sp34->unkAE + 1);
    if (sp34->unkC2 == 0) {
        func_800175F0(gCurrentParsedObject, 0, 0x16, -1, 0);
    } else {
        sp34->unkC2 = (s16) (sp34->unkC2 - 1);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp34->unkAC == 0) {
            sp30 = 0;
            do {
                sp2C = func_800281A4(gCurrentParsedObject, sp30);
                // sp2C = M2C_ERROR(/* Read from unset register $v0 */);
                func_8002B114(sp2C);
            } while (++sp30 < 3);
            func_8007EDF4(sp34->Pos.x, sp34->Pos.y + 172.0f, sp34->Pos.z, 2.0f);
            func_8002B114(gCurrentParsedObject);
        } else {
            sp34->unkAC = (s16) (sp34->unkAC - 1);
        }
    }
}

void func_800EB61C(void) {
    struct ObjectStruct* sp34;
    struct ObjectStruct* temp_t5;
    s16 sp2E;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unkB2 = (s16) sp34->action_state;
        sp34->unk3C = 180.0f;
        sp34->unk44 = 8.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 6, 0xC3, &D_801198EC);
        func_8001C0EC((s32) sp34->unkE8[2], 0, 1, 0xC5, &D_8011990C);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = (f32) sp34->Vel.z;
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp24;
    } else {
        sp34->Pos.y = sp28;
    }
    sp2E = 0;
    do {
        gObjects[sp34->unkE8[sp2E]].Pos.x = sp34->Pos.x + sp34->Vel.x;
        gObjects[sp34->unkE8[sp2E]].Pos.y = sp34->Pos.y + sp34->Vel.y;
        gObjects[sp34->unkE8[sp2E]].Pos.z = sp34->Pos.z + sp34->Vel.z;
    } while (++sp2E < 3);
    gObjects[sp34->unkE8[0]].Pos.y = (f32) (gObjects[sp34->unkE8[0]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[1]].Pos.y = (f32) (gObjects[sp34->unkE8[1]].Pos.y + 172.0f);
    gObjects[sp34->unkE8[2]].Pos.y = (f32) (gObjects[sp34->unkE8[2]].Pos.y + D_80115560);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp34->action_state = 3;
        sp34->unk132 = 0U;
    }
}

void func_800EB9A4(void) {
    struct ObjectStruct* sp24;
    s32 sp20;
    s16 sp1E;
    s16 temp_t1;

    sp24 = &gObjects[gCurrentParsedObject];
    sp1E = 0;
    do {
        sp20 = func_800281A4(gCurrentParsedObject, (s32) sp1E);
        func_8002B114(sp20);
    } while (++sp1E < 3);
    func_8002B0E4(gCurrentParsedObject);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EBA48.s")

void func_800EBC58(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800EBC88(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unk44 = 24.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xC4, &D_80119908);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
    if (sp34->unkA6 >= 0x10) {
        sp30 = Math_Random(6);
        func_8002A8B4(gCurrentParsedObject, (f32) sp30);
        sp34->Rot.y = (f32) sp34->unk3C;
    } else {
        sp34->unkA6 = (s16) (sp34->unkA6 + 1);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C = sp24;
    } else {
        sp2C = sp28;
    }
    if (sp34->Pos.y < sp2C) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800EBEA0(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    switch (sp1C->action_state) {
        case 1:
            func_800EBC88();
            break;
        default:
            break;
    }
}

void func_800EBF24(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801144BC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
}

void func_800EBFA0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        if (sp24->unkB2 == 4) {
            sp24->unk132 = (u8) (sp24->unk132 + 1);
            func_800175F0(gCurrentParsedObject, 0, 0x3A, -1, 0);
            func_8001C0EC(gCurrentParsedObject, 3, 0, 0x107, &D_8011997C);
        }
    }
    if ((sp24->unkB2 == 4) && (gPlayerObject->unk108 != 0) && (func_8002A2EC(gCurrentParsedObject, 60.0f) != 0) &&
        (sp24->unk132 == 1)) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
    }
    if (func_8001B62C(gCurrentParsedObject, 3) >= 88.0f) {
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->action_state = 2;
        sp24->unk132 = 0U;
    }
}

void func_800EC144(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
    }
    sp1C->Rot.y = func_80015538(sp1C->Rot.y, 12.0f);
    if ((sp1C->unkB2 == 4) && (gPlayerObject->unk108 != 0) && (func_8002A2EC(gCurrentParsedObject, 60.0f) != 0)) {
        func_8001BBDC(gCurrentParsedObject, 0);
        sp1C->action_state = 3;
        sp1C->unk132 = 0U;
        func_80284DF8();
    }
}

void func_800EC260(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkA6 = 0xB4;
        func_800175F0(gCurrentParsedObject, 0, 0x3A, -1, 0);
    }
    if (sp24->unkA6 == 0) {
        func_80069D88(0, 1);
    } else {
        sp24->unkA6 = (s16) (sp24->unkA6 - 1);
    }
}

void func_800EC348(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->action_state) {
        case 1:
            func_800EBFA0();
            break;
        case 2:
            func_800EC144();
            break;
        case 3:
            func_800EC260();
            break;
        default:
            break;
    }
}

void func_800EC408(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801144C8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_8001ABF4(sp24, 0, 0, &D_801199AC);
    }
}

void func_800EC4AC(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp1C->unk108 = 0;
        sp1C->unkA6 = 1;
        func_80069E60(0, 1, 0x3C);
    }
}

void func_800EC534(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkA6 = 0;
    }
    if (sp24->unkA6 == 1) {
        if (sp24->unk132 == 1) {
            sp24->unk132 = (u8) (sp24->unk132 + 1);
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0x10A, &D_80119980);
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801199AC.Rot.y);
            sp20 = func_80027464(1, &D_801144D4, sp24->Pos.x, sp24->Pos.y - 60.0f, sp24->Pos.z + 300.0f, 0.0f);
            if (sp20 != -1) {
                func_80026F10(sp20, gCurrentParsedObject);
                func_8001C0EC(sp20, 3, 0, 0x10B, &D_801199E4);
                func_8001ABF4(sp20, 0, 3, &D_80119A40);
                sp24->unkAA = (s16) sp20;
                func_800175F0(sp20, 0, 0x35, -1, 0);
            }
        }
    } else {
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801199AC);
    }
    if ((sp24->unk132 == 2) && (func_8001B4AC(gCurrentParsedObject, 0) != 0)) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001BBDC((s32) sp24->unkAA, 1);
        sp24->unkA8 = 0x2A;
    }
}

void func_800EC7B4(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801144E0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkA8 = 0;
        gObjects[sp24].unkC0 = 0;
    }
}

void func_800EC888(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->action_state = 5;
        sp4->unkC0 = 1;
    } else {
        sp4->action_state = 6;
        sp4->unk132 = 0;
    }
}

void func_800EC91C(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x16B, &D_80119A60);
    }
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp24;
    } else {
        sp2C->Pos.y = sp28;
    }
    if (func_8002A2EC(gCurrentParsedObject, 720.0f) != 0) {
        sp2C->action_state = 2;
        sp2C->unk132 = 0U;
    }
}

void func_800ECA50(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x16B, &D_80119A60);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp34->unk44 = 3.0f;
    func_8002A8B4(gCurrentParsedObject, 4.0f);
    sp34->Rot.y = (f32) sp34->unk3C;
    func_80029C40(gCurrentParsedObject);
    func_80029018(gCurrentParsedObject, 1, 70.0f, 0.0f, 0.0f, 0.0f);
    if (func_800295C0(gCurrentParsedObject, &sp30, &sp2C, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp2C;
    } else {
        sp34->Pos.y = sp30;
    }
    if (func_8002A2EC(gCurrentParsedObject, 480.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
        sp34->unk44 = 0.0f;
        sp34->action_state = 3;
        sp34->unk132 = 0U;
    }
}

void func_800ECC54(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x16B, &D_80119A60);
        if (func_800295C0(gCurrentParsedObject, &sp24, &sp20, 0.0f, 0.0f, 0.0f) != 0) {
            sp2C->Pos.y = sp20;
        } else {
            sp2C->Pos.y = sp24;
        }
        if (sp2C->unkA8 == 0) {
            sp28 = func_80027464(1, &D_801144EC, sp2C->Pos.x, sp2C->Pos.y + 165.0f, sp2C->Pos.z, sp2C->unk3C);
            if (sp28 != -1) {
                func_80026F10(gCurrentParsedObject, sp28);
                gObjects[sp28].unkC2 = (s16) gCurrentParsedObject;
                gObjects[sp28].unkC0 = 1;
                sp2C->unkB4 = (s16) sp28;
                sp2C->unkA8 = 1;
            }
        }
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp20, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp20;
    } else {
        sp2C->Pos.y = sp24;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->action_state = 4;
        sp2C->unk132 = 0U;
    }
}

void func_800ECEB0(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unk44 = 6.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x16B, &D_80119A60);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_8002A8B4(gCurrentParsedObject, 4.0f);
    sp2C->Rot.y = (f32) sp2C->unk3C;
    func_80029C40(gCurrentParsedObject);
    func_80029018(gCurrentParsedObject, 1, 70.0f, 0.0f, 0.0f, 0.0f);
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp24;
    } else {
        sp2C->Pos.y = sp28;
    }
}

void func_800ED038(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unkB4 != 0) {
        func_8002B114((s32) sp1C->unkB4);
    }
    if (sp1C->unkB6 != 0) {
        func_8002B114((s32) sp1C->unkB6);
    }
    if (sp1C->unkB8 != 0) {
        func_8002B114((s32) sp1C->unkB8);
    }
    if (sp1C->unkBA != 0) {
        func_8002B114((s32) sp1C->unkBA);
    }
    if (sp1C->unkBC != 0) {
        func_8002B114((s32) sp1C->unkBC);
    }
    func_8002B0E4(gCurrentParsedObject);
}

void func_800ED170(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x16B, &D_80119A60);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp2C->action_state = 4;
        sp2C->unk132 = 1U;
        sp2C->unk44 = 6.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x16B, &D_80119A60);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800ED2B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800ED3A4.s")

void func_800ED9E8(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801144F8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_80019448(sp24, 2, 0, 1);
    }
}

void func_800EDA88(void) {
    gObjects[gCurrentParsedObject].unk108 = 0;
    func_8002B0E4(gCurrentParsedObject);
}

void func_800EDAE0(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = (u8) (sp3C->unk132 + 1);
        sp3C->unk44 = 1.0f;
        sp3C->Rot.x = 60.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x60, &D_80118FE8);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp38 = Math_Random(-6);
    func_8002A8B4(gCurrentParsedObject, (f32) sp38);
    sp3C->Rot.y = (f32) sp3C->unk3C;
    if (sp3C->unkA8 == 0) {
        if (sp3C->unkA6 < 0x1E) {
            sp3C->Vel.y = 1.0f;
            sp3C->unkA6 = (s16) (sp3C->unkA6 + 1);
        } else {
            sp3C->unkA8 = (s16) (sp3C->unkA8 + 1);
            sp3C->unkA6 = 0;
        }
    } else if (sp3C->unkA6 < 0x1E) {
        sp3C->Vel.y = -1.0f;
        sp3C->unkA6 = (s16) (sp3C->unkA6 + 1);
    } else {
        sp3C->unkA8 = 0;
        sp3C->unkA6 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_8002A1FC(gCurrentParsedObject, 720.0f) != 0) {
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z;
        sp3C->unk44 = 0.0f;
        sp3C->action_state = 2;
        sp3C->unk132 = 0U;
    }
}

void func_800EDDE4(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x60, &D_80118FE8);
    }
    func_800EE354(gCurrentParsedObject, 6.0f);
    sp2C->Rot.y = (f32) sp2C->unk3C;
    sp28 = Math_CalcAngleSimple(gPlayerObject->Pos.x - sp2C->Pos.x, gPlayerObject->Pos.y - sp2C->Pos.y);
    sp28 = Math_NormalizeAngle(sp28);
    sp24 = (f32) func_8002A800(sp2C->unk40, sp28, 3.0f);
    if (sp24 != 0.0f) {
        sp2C->unk40 = func_80015538(sp2C->unk40, 1.0f * sp24);
    }
    sp2C->Rot.x = func_80015538(450.0f, -sp2C->unk40);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->action_state = 3;
        sp2C->unk132 = 0U;
    }
}

void func_800EDFA4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unk44 = 26.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x60, &D_80118FE8);
        func_800175F0(gCurrentParsedObject, 0, 0x5D, -1, 0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp24->Rot.y = (f32) sp24->unk3C;
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
    if (func_8002A0D0(gCurrentParsedObject, 0.0f, 0.0f, -20.0f) == 1) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800EE134(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->action_state) {
        case 1:
            func_800EDAE0();
            break;
        case 2:
            func_800EDDE4();
            break;
        case 3:
            func_800EDFA4();
            break;
        default:
            break;
    }
}

f32 func_800EE1F4(s32 arg0) {
    return func_80015634(gPlayerObject->Pos.x - gObjects[arg0].Pos.x,
                         (gPlayerObject->Pos.z - 240.0f) - gObjects[arg0].Pos.z);
}

s32 func_800EE274(s32 arg0, f32 arg1) {
    f32 sp1C;
    f32 sp18;

    sp1C = func_800EE1F4(arg0);
    sp18 = func_80015538(sp1C, -gObjects[arg0].unk3C);
    if ((sp18 < arg1) || ((360.0f - arg1) < sp18)) {
        return 0;
    }
    if (sp18 >= 180.0f) {
        return -1;
    }
    return 1;
}

void func_800EE354(s32 arg0, f32 arg1) {
    f32 sp1C;
    s32 sp18;

    sp1C = gObjects[arg0].unk3C;
    sp18 = func_800EE274(arg0, arg1);
    if (sp18 < 0) {
        sp1C = func_80015538(sp1C, -arg1);
    } else if (sp18 > 0) {
        sp1C = func_80015538(sp1C, arg1);
    } else {
        sp1C = func_800EE1F4(arg0);
    }
    gObjects[arg0].unk3C = sp1C;
}

void func_800EE444(void) {
    s32 sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = func_80027464(2, &D_801143D8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2C != -1) {
        func_8001ABF4(sp2C, 0, 3, &D_801195D0.Rot.y);
        func_8001ABF4((s32) gObjects[sp2C].unkE8[0], 1, 0, &D_801196AC.unk30.z);
        if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
            gObjects[sp2C].Pos.y = sp24;
        } else {
            gObjects[sp2C].Pos.y = sp28;
        }
        gObjects[sp2C].Pos.y = (f32) (gObjects[sp2C].Pos.y + 600.0f);
        (&gObjects[gObjects[sp2C].unkE8[0]])->Pos.y = (f32) gObjects[sp2C].Pos.y;
        gObjects[sp2C].unk13A = 1;
        gObjects[sp2C].unkC0 = (s16) (s32) gObjects[sp2C].Pos.x;
        gObjects[sp2C].unkC2 = (s16) (s32) gObjects[sp2C].Pos.z;
    }
}

void func_800EE6F8(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->Vel.z = 0.0f;
        sp4->Vel.x = (f32) sp4->Vel.z;
        sp4->unk44 = 0.0f;
        sp4->action_state = 6;
        sp4->unk132 = 0;
    }
}

void func_800EE7A4(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = (s32) sp2C->unkE8[0];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x84, &D_80119578);
        func_8001C0EC(sp28, 0, 0, 0x86, &D_80119654);
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_801195D0.Rot.y);
        func_8001ABF4(sp28, 1, 0, &D_801196AC.unk30.z);
        sp2C->Scale.x = 0.5f;
        sp2C->Scale.y = 0.5f;
        sp2C->Scale.z = 0.5f;
        gObjects[sp28].Scale.x = 0.5f;
        gObjects[sp28].Scale.y = 0.5f;
        gObjects[sp28].Scale.z = 0.5f;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp20, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp20;
    } else {
        sp2C->Pos.y = sp24;
    }
    sp2C->Pos.y = (f32) (sp2C->Pos.y + 600.0f);
    gObjects[sp28].Pos.y = sp2C->Pos.y;
    if (func_8002A1FC(gCurrentParsedObject, 840.0f) != 0) {
        sp2C->action_state = 2;
        sp2C->unk132 = 0U;
    }
}

void func_800EEA50(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = (s32) sp2C->unkE8[0];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x84, &D_80119578);
        func_8001C0EC(sp28, 0, 0, 0x86, &D_80119654);
        sp2C->unk13A = 0;
    }
    if (func_8001B62C(gCurrentParsedObject, 3) >= 6.0f) {
        sp2C->Scale.x = (f32) ((f64) sp2C->Scale.x + D_801155C8);
        sp2C->Scale.y = (f32) ((f64) sp2C->Scale.y + D_801155D0);
        sp2C->Scale.z = (f32) ((f64) sp2C->Scale.z + D_801155D8);
        gObjects[sp28].Scale.x = (f32) ((f64) gObjects[sp28].Scale.x + D_801155E0);
        gObjects[sp28].Scale.y = (f32) ((f64) gObjects[sp28].Scale.y + D_801155E8);
        gObjects[sp28].Scale.z = (f32) ((f64) gObjects[sp28].Scale.z + D_801155F0);
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp20, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp20;
    } else {
        sp2C->Pos.y = sp24;
    }
    sp2C->Pos.y = (f32) (sp2C->Pos.y + 600.0f);
    gObjects[sp28].Pos.y = sp2C->Pos.y;
    if (func_8001B4AC(gCurrentParsedObject, 3) != 0) {
        sp2C->Scale.x = 1.0f;
        sp2C->Scale.y = 1.0f;
        sp2C->Scale.z = 1.0f;
        gObjects[sp28].Scale.x = 1.0f;
        gObjects[sp28].Scale.y = 1.0f;
        gObjects[sp28].Scale.z = 1.0f;
        sp2C->action_state = 3;
        sp2C->unk132 = 0U;
    }
}

void func_800EEE30(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;
    s32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    sp20 = (s32) sp2C->unkE8[0];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 3, 1, 0x84, &D_80119578);
        func_8001C0EC(sp20, 0, 1, 0x86, &D_80119654);
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_801195D0.Rot.y);
        func_8001ABF4(sp20, 1, 0, &D_801196AC.unk30.z);
        if (sp2C->unkB0 == 0) {
            func_80029EF8(gCurrentParsedObject, 0.0f, 3.0f);
        }
    }
    sp2C->unk44 = 6.0f;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_8002A8B4(gCurrentParsedObject, 4.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029018(gCurrentParsedObject, 1, 90.0f, 0.0f, 0.0f, 0.0f);
    if ((sp2C->unk132 == 1) && (sp2C->unkB0 == 0)) {
        if (func_8002A0D0(gCurrentParsedObject, 0.0f, 0.0f, -360.0f) == 1) {
            sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        }
    } else {
        if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
            sp2C->Pos.y = sp24;
        } else {
            sp2C->Pos.y = sp28;
        }
        sp2C->Pos.y = (f32) (sp2C->Pos.y + 360.0f);
        gObjects[sp20].Pos.y = sp2C->Pos.y;
        if (sp2C->unkB6 == 0) {
            if (func_8002A2EC(gCurrentParsedObject, 180.0f) != 0) {
                sp2C->unkB6 = 0xA;
                sp2C->action_state = 4;
                sp2C->unk132 = 0U;
            }
        } else {
            sp2C->unkB6 = (s16) (sp2C->unkB6 - 1);
        }
    }
    gObjects[sp20].Pos.x = sp2C->Pos.x + sp2C->Vel.x;
    gObjects[sp20].Pos.y = sp2C->Pos.y + sp2C->Vel.y;
    gObjects[sp20].Pos.z = sp2C->Pos.z + sp2C->Vel.z;
    if (func_8002A2EC(gCurrentParsedObject, 840.0f) != 0) {

    } else {
        sp2C->action_state = 5;
        sp2C->unk132 = 0U;
    }
}

void func_800EF250(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    s32 sp2C;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    sp30 = (s32) sp34->unkE8[0];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unkB2 = (s16) sp34->action_state;
        func_8001C0EC(gCurrentParsedObject, 3, 2, 0x84, &D_80119578);
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_801195D0);
        func_8001ABF4((s32) sp34->unkE8[0], 1, 0, &D_801196AC.unk54);
        sp34->unkB0 = 1;
    }
    sp34->unk44 = 6.0f;
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_8002A8B4(gCurrentParsedObject, 4.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029018(gCurrentParsedObject, 1, 90.0f, 0.0f, 0.0f, 0.0f);
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp24;
    } else {
        sp34->Pos.y = sp28;
    }
    sp34->Pos.y = (f32) (sp34->Pos.y + 360.0f);
    gObjects[sp30].Pos.y = sp34->Pos.y;
    if (sp34->unkA6 == 0) {
        if (sp34->unkB6 == 0) {
            sp34->unkA6 = 0;
            sp34->unkB6 = 0x3C;
            sp34->action_state = 3;
            sp34->unk132 = 0U;
        } else if (func_8002A2EC(gCurrentParsedObject, 180.0f) != 0) {
            sp2C = func_80027464(1, &D_801143F0, sp34->Pos.x, sp34->Pos.y - 120.0f, sp34->Pos.z, 0.0f);
            if (sp30 != -1) {
                func_8001ABF4(sp2C, 0, 0, &D_8011955C);
                sp34->unkA6 = 2;
                sp34->unkB6 = (s16) (sp34->unkB6 - 1);
            }
        } else {
            sp34->unkA6 = 0;
            sp34->unkB6 = 0x3C;
            sp34->action_state = 3;
            sp34->unk132 = 0U;
        }
    } else {
        sp34->unkA6 = (s16) (sp34->unkA6 - 1);
    }
    gObjects[sp30].Pos.x = sp34->Pos.x + sp34->Vel.x;
    gObjects[sp30].Pos.y = sp34->Pos.y + sp34->Vel.y;
    gObjects[sp30].Pos.z = sp34->Pos.z + sp34->Vel.z;
    if (func_8002A2EC(gCurrentParsedObject, 840.0f) != 0) {

    } else {
        sp34->action_state = 5;
        sp34->unk132 = 0U;
    }
}

void func_800EF6AC(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    sp20 = (s32) sp24->unkE8[0];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unkB2 = (s16) sp24->action_state;
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = (f32) sp24->Vel.z;
        sp24->unk44 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x84, &D_80119578);
        func_8001C0EC(sp20, 0, 0, 0x86, &D_80119654);
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_801195D0.Rot.y);
        func_8001ABF4((s32) sp24->unkE8[0], 1, 0, &D_801196AC.unk30.z);
        sp24->unkBE = (s16) (s32) (sp24->Pos.y + 600.0f);
        sp24->Vel.y = 4.0f;
    }
    if (sp24->Pos.y >= sp24->unkBE) {
        sp24->Vel.y = 0.0f;
        sp24->Pos.y = (f32) sp24->unkBE;
        sp24->unkB0 = 0;
        sp24->action_state = 1;
        sp24->unk132 = 0U;
    } else {
        gObjects[sp20].Pos.y = (sp24->Pos.y + sp24->Vel.y);
    }
}

void func_800EF914(void) {
    struct ObjectStruct* sp1C;
    s32 sp18;

    sp1C = &gObjects[gCurrentParsedObject];
    sp18 = func_800281A4(gCurrentParsedObject, 0);
    func_8002B114(sp18);
    func_8002B0E4(gCurrentParsedObject);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EF990.s")

void func_800EFA80(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unk3C = 0.0f;
        sp24->Rot.y = (f32) sp24->unk3C;
        func_80029EF8(gCurrentParsedObject, 0.0f, 2.0f);
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 80.0f, 0.0f) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_800EFB6C(void) {
    s32 sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = func_80027464(2, &D_801143FC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2C != -1) {
        func_8001ABF4(sp2C, 0, 3, &D_801195D0.Rot.y);
        func_8001ABF4((s32) gObjects[sp2C].unkE8[0], 1, 0, &D_801196AC.unk30.z);
        if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
            gObjects[sp2C].Pos.y = sp24;
        } else {
            gObjects[sp2C].Pos.y = sp28;
        }
        gObjects[sp2C].Pos.y = (f32) (gObjects[sp2C].Pos.y + 600.0f);
        gObjects[gObjects[sp2C].unkE8[0]].Pos.y = (f32) gObjects[sp2C].Pos.y;
        gObjects[sp2C].unk13A = 1;
        gObjects[sp2C].unkC0 = (s16) (s32) gObjects[sp2C].Pos.x;
        gObjects[sp2C].unkC2 = (s16) (s32) gObjects[sp2C].Pos.z;
    }
}

void func_800EFE20(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->Vel.z = 0.0f;
        sp4->Vel.x = (f32) sp4->Vel.z;
        sp4->unk44 = 0.0f;
        sp4->action_state = 6;
        sp4->unk132 = 0;
    }
}

void func_800EFECC(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = (s32) sp2C->unkE8[0];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x84, &D_80119578);
        func_8001C0EC(sp28, 0, 0, 0x86, &D_80119654);
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_801195D0.Rot.y);
        func_8001ABF4(sp28, 1, 0, &D_801196AC.unk30.z);
        sp2C->Scale.x = 0.5f;
        sp2C->Scale.y = 0.5f;
        sp2C->Scale.z = 0.5f;
        gObjects[sp28].Scale.x = 0.5f;
        gObjects[sp28].Scale.y = 0.5f;
        gObjects[sp28].Scale.z = 0.5f;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp20, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp20;
    } else {
        sp2C->Pos.y = sp24;
    }
    sp2C->Pos.y = (f32) (sp2C->Pos.y + 600.0f);
    gObjects[sp28].Pos.y = sp2C->Pos.y;
    if (func_8002A1FC(gCurrentParsedObject, 840.0f) != 0) {
        sp2C->action_state = 2;
        sp2C->unk132 = 0U;
    }
}

void func_800F0178(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = (s32) sp2C->unkE8[0];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkB2 = (s16) sp2C->action_state;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x84, &D_80119578);
        func_8001C0EC(sp28, 0, 0, 0x86, &D_80119654);
        sp2C->unk13A = 0;
    }
    if (func_8001B62C(gCurrentParsedObject, 3) >= 6.0f) {
        sp2C->Scale.x = (f32) ((f64) sp2C->Scale.x + D_80115610);
        sp2C->Scale.y = (f32) ((f64) sp2C->Scale.y + D_80115618);
        sp2C->Scale.z = (f32) ((f64) sp2C->Scale.z + D_80115620);
        gObjects[sp28].Scale.x = (f32) ((f64) gObjects[sp28].Scale.x + D_80115628);
        gObjects[sp28].Scale.y = (f32) ((f64) gObjects[sp28].Scale.y + D_80115630);
        gObjects[sp28].Scale.z = (f32) ((f64) gObjects[sp28].Scale.z + D_80115638);
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp20, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp20;
    } else {
        sp2C->Pos.y = sp24;
    }
    sp2C->Pos.y = (f32) (sp2C->Pos.y + 600.0f);
    gObjects[sp28].Pos.y = sp2C->Pos.y;
    if (func_8001B4AC(gCurrentParsedObject, 3) != 0) {
        sp2C->Scale.x = 1.0f;
        sp2C->Scale.y = 1.0f;
        sp2C->Scale.z = 1.0f;
        gObjects[sp28].Scale.x = 1.0f;
        gObjects[sp28].Scale.y = 1.0f;
        gObjects[sp28].Scale.z = 1.0f;
        sp2C->action_state = 3;
        sp2C->unk132 = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F0558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F0978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F0DD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F103C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F10B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F11A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F11F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F1478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F14A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F154C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F161C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F18D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F197C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F1C28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F2008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F2428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F2BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F2E20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F2E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F2F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F2FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F310C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F3248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F32C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F33AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F3568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F37BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F387C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F38AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F3A68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F3E44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F3EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F3F60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F4078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F4164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F4378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F4534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F49A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F49D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F4AD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F4BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F4CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F4DEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F4FC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F5298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F52A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F52B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F5330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F5698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F574C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F57C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F5904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F5D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F5E14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F5E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F6058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F62BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F63B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F643C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F65C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F6968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F69DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F6A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F6B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F6D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F6F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F70F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F71C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7544.s")

void func_800F770C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = (u8) (sp4->unk132 + 1);
        sp4->unkAA = 0xF;
    }
    sp4->Vel.z = 0.0f;
    sp4->Vel.x = sp4->Vel.y = sp4->Vel.z;
    sp4->unkAA = (s16) (sp4->unkAA - 1);
    if (sp4->unkAA <= 0) {
        sp4->action_state = 1;
        sp4->unk132 = 0U;
    }
}

void func_800F7800(void) {

    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_800F7544();
            break;
        case 2:
            func_800F770C();
            break;
        default:
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7894.s")

void func_800F7A0C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1U;
        if (sp1C->unkA6 != 0) {
            sp1C->unkA8 = (s16) sp1C->unkA6;
            sp1C->unk40 = func_80015538(sp1C->unk40, 180.0f);
            sp1C->unk48 = 4.0f;
        } else {
            sp1C->unk48 = 0.0f;
            sp1C->unk40 = (f32) sp1C->unk48;
        }
        sp1C->unk44 = 0.0f;
        sp1C->unk3C = (f32) sp1C->unk44;
        sp1C->unkB0 = 1;
    }
    if (sp1C->unkA6 == 0) {
        return;
    }
    func_80029D04(gCurrentParsedObject);
    sp1C->unkA8 = (s16) (s32) ((f32) sp1C->unkA8 - sp1C->unk48);
    if (sp1C->unkA8 <= 0) {
        sp1C->unkB0 = 2;
        sp1C->action_state = (s16) sp1C->unkB0;
        sp1C->unk132 = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7D08.s")

void func_800F7E2C(void) {
    if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].action_state = 3;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7EA4.s")

void func_800F8028(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp2C = func_80027464(3, &D_80113790, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp2C != -1) {
        sp24 = (s32) gObjects[sp2C].unkE8[0];
        sp28 = (s32) gObjects[sp2C].unkE8[1];
        gObjects[sp24].Pos.x = gObjects[sp2C].Pos.x - 60.0f;
        gObjects[sp24].Pos.y = (f32) (gObjects[sp2C].Pos.y - 180.0f);
        gObjects[sp24].Pos.z = (f32) gObjects[sp2C].Pos.z;
        gObjects[sp28].Pos.x = gObjects[sp2C].Pos.x + 60.0f;
        gObjects[sp28].Pos.y = (f32) (gObjects[sp2C].Pos.y - 180.0f);
        gObjects[sp28].Pos.z = (f32) gObjects[sp2C].Pos.z;
    }
}

void func_800F82EC(void) {
    struct ObjectStruct* spC;
    s32 sp8;
    s32 sp4;

    spC = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp8 = (s32) spC->unkE8[0];
        sp4 = (s32) spC->unkE8[1];
        if (sp8 != -1) {
            if (gObjects[sp8].unk104 != -1) {
                spC->action_state = 2;
                spC->unk132 = 0;
            }
        }
        if (sp4 != -1) {
            if (gObjects[sp4].unk104 != -1) {
                spC->action_state = 2;
                spC->unk132 = 0;
            }
        }
    }
}

void func_800F8418(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1U;
        sp4->unkA6 = 0xA;
    }
    if ((sp4->unkE8[0] == -1) && (sp4->unkE8[1] == -1)) {
        if (sp4->unkA6 == 0) {
            sp4->action_state = 3;
            sp4->unk132 = 0U;
        } else {
            sp4->unkA6 = (s16) (sp4->unkA6 - 1);
        }
    }
}

void func_800F84F8(void) {
    struct ObjectStruct* sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1U;
        sp20 = (s32) sp24->unkE8[0];
        sp1C = (s32) sp24->unkE8[1];
        if ((sp20 != -1)) {
            if (gObjects[sp20].unk104 != -1) {
                func_800281A4(gCurrentParsedObject, 0);
                func_8002B0E4(sp20);
            }
        }
        if ((sp1C != -1)) {
            if (gObjects[sp1C].unk104 != -1) {
                func_800281A4(gCurrentParsedObject, 1);
                func_8002B0E4(sp1C);
            }
        }
    }
    sp24->action_state = 1;
    sp24->unk132 = 0U;
}

void func_800F8660(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1U;
        func_80029EF8(gCurrentParsedObject, 0.0f, 2.0f);
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -60.0f, 60.0f) == 1) {
        sp24->action_state = 4;
    }
}

void func_800F8720(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1U;
    }
    sp4->Vel.z = 0.0f;
    sp4->Vel.x = sp4->Vel.y = sp4->Vel.z;
}

void func_800F87B4(void) {

    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_800F8418();
            break;
        case 2:
            func_800F84F8();
            break;
        case 3:
            func_800F8660();
            break;
        case 4:
            func_800F8720();
            break;
    }
}

void func_800F8878(void) {
}

void func_800F8888(void) {
}

void func_800F8898(void) {
}

void func_800F88A8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F88B8.s")

void func_800F8AB8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F8AC8.s")

void func_800F901C(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_800F8AC8();
            break;
    }
}

void func_800F9088(void) {
}

void func_800F9098(void) {
}

void func_800F90A8(void) {
    func_80027464(1, &D_801137D8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800F9120(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if ((D_80177A64 == 1) && (sp4->action_state == 1)) {
        sp4->action_state = 2;
        sp4->unk132 = 0;
    }
}

void func_800F91A4(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x6A, &D_8011BA88);
    }
    func_8001B6BC(gCurrentParsedObject, 0, 0);
    sp2C->Vel.z = 0.0f;
    sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
}

void func_800F9294(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unk44 = 0.0f;
        sp24->unk3C = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk40 = 90.0f;
        sp24->unkA6 = 0;
        func_800175F0(gCurrentParsedObject, 0, 0x2D, -1, 0);
    }
    if (sp24->unkA6 == 0) {
        sp24->unk48 = (f32) (sp24->unk48 + 1.0f);
        if (sp24->unk48 == 19.0f) {
            sp24->unkA6 = 1;
        }
    } else if (sp24->unkA6 < 6) {
        sp24->unk48 = 20.0f;
        sp24->unkA6 = (s16) (sp24->unkA6 + 1);
    } else {
        sp24->unk48 = (f32) (sp24->unk48 - 1.0f);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unk48 == 0.0f) {
        sp24->action_state = 3;
        sp24->unk132 = 0U;
    }
}

void func_800F94A8(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        sp1C->unk44 = 0.0f;
        sp1C->unk3C = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unk40 = 90.0f;
        sp1C->unkA6 = 0;
    }
    func_8001B6BC(gCurrentParsedObject, 0, 0);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp1C->unkA6 >= 0x1E) {
        sp1C->action_state = 4;
        sp1C->unk132 = 0U;
    } else {
        sp1C->unkA6 = (s16) (sp1C->unkA6 + 1);
    }
}

void func_800F95F4(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        sp1C->unk44 = 0.0f;
        sp1C->unk3C = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unk40 = 270.0f;
        sp1C->unkA6 = 0;
    }
    if (sp1C->unkA6 == 0) {
        sp1C->unk48 = (f32) (sp1C->unk48 + 1.0f);
        if (sp1C->unk48 == 19.0f) {
            sp1C->unkA6 = 1;
        }
    } else if (sp1C->unkA6 < 6) {
        sp1C->unk48 = 20.0f;
        sp1C->unkA6 = (s16) (sp1C->unkA6 + 1);
    } else {
        sp1C->unk48 = (f32) (sp1C->unk48 - 1.0f);
    }
    func_8001B6BC(gCurrentParsedObject, 0, 0.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp1C->unk48 == 0.0f) {
        sp1C->action_state = 1;
        sp1C->unk132 = 0U;
    }
}

void func_800F9800(void) {

    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_800F91A4();
            break;
        case 2:
            func_800F9294();
            break;
        case 3:
            func_800F94A8();
            break;
        case 4:
            func_800F95F4();
            break;
    }
}

void func_800F98C4(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp20 = func_80027464(1, &D_801137E4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp20 != -1) {
        sp24 = &gObjects[sp20];
        sp24->obj_id = (s16) D_80165100->unk0;
        if (func_80026260(D_8016519C) == 1) {
            if (sp24->obj_id == 0x4D) {
                sp24->obj_id = 0x4E;
            } else {
                sp24->obj_id = 0x4D;
            }
            sp24->unkA6 = 1;
        }
        if (sp24->obj_id == 0x4D) {
            sp24->Pos.y = (f32) (sp24->Pos.y + 180.0f);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F9A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F9C4C.s")

void func_800F9CB8(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp20 = func_80027464(1, &D_801137F0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp20 != -1) {
        sp24 = &gObjects[sp20];
        sp24->obj_id = (s16) D_80165100->unk0;
        if (func_80026260(D_8016519C) == 1) {
            if (sp24->obj_id == 0x4F) {
                sp24->obj_id = 0x50;
            } else {
                sp24->obj_id = 0x4F;
            }
            sp24->unkA6 = 1;
        }
    }
}

void func_800F9DE0(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1U;
        if (sp24->obj_id == 0x4F) {
            sp20 = 1;
        } else {
            sp20 = 0;
        }
        func_8001C0EC(gCurrentParsedObject, 0, sp20, 0xBF, &D_8011BA8C);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (sp24->unkA6 == 0) {
        if (sp24->obj_id == 0x4F) {
            if (func_8002A1FC(gCurrentParsedObject, 360.0f) == 0) {
                sp24->unkA6 = 1;
                sp24->unkA8 = 1;
                func_800175F0(gCurrentParsedObject, 0, 0x31, -1, 0);
            }
        } else if (func_8002A1FC(gCurrentParsedObject, 360.0f) != 0) {
            sp24->unkA6 = 1;
            sp24->unkA8 = 1;
            func_800175F0(gCurrentParsedObject, 0, 0x31, -1, 0);
        }
    }
    if (sp24->unkA8 == 1) {
        sp24->unkA8 = 2;
        if (sp24->obj_id == 0x4F) {
            sp20 = 1;
        } else {
            sp20 = 0;
        }
        func_8001C0EC(gCurrentParsedObject, 0, sp20, 0xBF, &D_8011BA8C);
        func_8001BBDC(gCurrentParsedObject, 0);
    } else if ((sp24->unkA8 == 2) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp24->unkA8 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_800261E8(gCurrentParsedObject, 1);
        if (sp24->obj_id == 0x4F) {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0xBF, &D_8011BA8C);
            sp24->obj_id = 0x50;
        } else {
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0xBF, &D_8011BA8C);
            sp24->obj_id = 0x4F;
        }
    }
}

void func_800FA0DC(void) {
    if (gObjects[gCurrentParsedObject].action_state == 1) {
        goto stub;
    stub:;
        func_800F9DE0();
        goto stub2;
    stub2:;
    }
}

void func_800FA148(void) {
    func_80027464(2, &D_801137FC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800FA1C0(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].action_state = 3;
    } else if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].action_state = 2;
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800FA27C(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = (s32) sp2C->unkE8[0];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1U;
        if (sp2C->unkA8 != 0) {
            sp2C->unk108 = 0;
        } else {
            sp2C->unk108 = -1;
        }
        sp2C->unkAA = 0xA;
        sp2C->unkA6 = 0x14;
        func_8001BBDC(sp28, 0);
        func_8001ABF4(sp28, 0, 3, &D_8011BB50.unk30.z);
        func_8001ABF4(sp28, 1, 3, &D_8011BB50.unk54);
    }
    if (sp2C->unkA6 != 0) {
        sp2C->unkA6 = (s16) (sp2C->unkA6 - 1);
        func_80029D04(gCurrentParsedObject);
    } else {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = (f32) sp2C->Vel.z;
    }
    if ((func_8001B44C(sp28, 3) != 0) && (sp2C->unkA6 == 0)) {
        if (sp2C->unkA8 != 0) {
            func_800281A4(gCurrentParsedObject, 0);
            func_8002B0E4(sp28);
            func_8002B0E4(gCurrentParsedObject);
        } else {
            func_8001BBDC(sp28, 1);
            func_8001ABF4(sp28, 0, 3, &D_8011BB50);
            func_8001ABF4(sp28, 1, 3, &D_8011BB50.Rot.y);
            sp2C->action_state = 1;
        }
    }
}

void func_800FA4D4(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unkA8 = 1;
    }
    func_800FA27C();
}

void func_800FA54C(void) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    sp30 = (s32) sp34->unkE8[0];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1U;
        sp34->unkA8 = 0;
        func_8001C0EC(sp30, 3, 0, 0xC1, &D_8011BA94);
        func_8001BBDC(sp30, 1);
        func_8001ABF4(sp30, 0, 3, &D_8011BB50);
        func_8001ABF4(sp30, 1, 3, &D_8011BB50.Rot.y);
        sp34->unk40 = 270.0f;
        sp34->unk48 = 6.0f;
        sp34->unk44 = 0.0f;
        sp34->unk3C = (f32) sp34->unk44;
    }
    sp34->Vel.z = 0.0f;
    sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
    if (sp34->unk108 == -1) {
        if (sp34->unkAA != 0) {
            sp34->unkAA = (s16) (sp34->unkAA - 1);
        }
        if (sp34->unkAA == 0) {
            sp34->unk108 = 1;
        }
    }
}

void func_800FA730(void) {

    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_800FA54C();
            break;
        case 2:
            func_800FA27C();
            break;
        case 3:
            func_800FA4D4();
            break;
    }
}

void func_800FA7D8(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113838, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, 0.0f);
    if (sp24 != -1) {
        gObjects[sp24].unk40 = 270.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800FA888.s")

void func_800FAA88(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1U;
        sp2C->unk40 = func_80015538(sp2C->unk40, 180.0f);
        sp2C->unkA8 = 0xF0;
        sp2C->unk48 = (f32) ((s16) sp2C->unkA8 / 4);
        sp2C->unk44 = 0.0f;
        sp2C->unk3C = (f32) sp2C->unk44;
        func_800175F0(gCurrentParsedObject, 0, 0x31, -1, 0);
    }
    if (sp2C->unkA8 <= 0) {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = (f32) sp2C->Vel.z;
        func_8002B0E4(gCurrentParsedObject);
    } else {
        func_80029D04(gCurrentParsedObject);
        sp2C->unkA8 = (s16) (s32) ((f32) sp2C->unkA8 - sp2C->unk48);
    }
}

void func_800FAC60(void) {
    switch (gObjects[gCurrentParsedObject].action_state) {
        case 1:
            func_800FA888();
            break;
        case 2:
            func_800FAA88();
            break;
    }
}
