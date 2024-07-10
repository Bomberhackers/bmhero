#include "common.h"
#include "variables.h"

extern s32 func_8002B0E4(s32);
extern s32 func_80027464(s32, void*, f32, f32, f32, f32);
extern s32 func_8001ABF4(s32, s32, s32, void*);
extern s32 func_8002A1FC(s32, f32);
extern s32 func_8001B4AC(s32, s32);
extern s32 func_8001B754(s32, s32);
extern s32 func_8001C0EC(s32, s32, s32, s32, void*);
extern f32 func_8001B62C(s32, s32);
extern s32 func_80028FA0(s32);
extern s32 func_8002A8B4(s32, f32);
extern s32 func_800E3EE4();
extern f32 func_8002A46C(s32);
extern s32 func_80014E80(s32);
extern f32 func_80015538(f32, f32);
extern s32 func_80029018(s32, s32, f32, f32, f32, f32);
extern s32 func_800295C0(s32, f32*, f32*, f32, f32, f32);
extern s32 func_800297DC();
extern s32 func_8002A0D0(s32, f32, f32, f32);
extern s32 func_8002A2EC(s32, f32);
extern s32 func_8001B44C(s32, s32);
extern s32 func_800261E8(s32, s32);
extern s32 func_80026260(s32);
extern s32 func_80029F58(s32, f32, f32, f32, f32);
extern void func_800175F0(s32, s32, s32, s32, s32);
extern void func_8001B6BC(s32, s32, f32);
extern void func_8001BBDC(s32, s32);
extern void func_80026F10(s32, s32);
extern void func_800281A4(s32, s32);
extern void func_80029824(s32, s32);
extern void func_80029D04(s32);
extern void func_80029B60(s32);
extern void func_80029C40(s32);
extern void func_80029EF8(s32, f32, f32);
extern void func_800F9DE0();
extern void func_800FA27C();
extern void func_800F91A4();
extern void func_800F9294();
extern void func_800F94A8();
extern void func_800F95F4();

typedef struct {
    s16 unk0;
    char padding[0x14E];
} UnkStruct800FA0DC;

typedef struct {
    f32 unk0;
} UnkStruct80114354;

extern UnkStruct80165100* D_80165100;
extern struct PlayerStruct D_80119128;
extern struct PlayerStruct D_80118FF4;
extern UnkStruct80165100 D_80113790;
extern UnkStruct80165100 D_801137D8;
extern UnkStruct80165100 D_801137E4;
extern UnkStruct80165100 D_8011436C;
extern UnkStruct80165100 D_801142E8;
extern UnkStruct80165100 D_80114300;
extern UnkStruct80165100 D_8011433C;
extern UnkStruct80165100 D_80114348;
extern UnkStruct80165100 D_80114360;
extern struct PlayerStruct D_80118E9C;
extern UnkStruct80165100 D_801142F4;
extern struct PlayerStruct D_801137F0;
extern struct PlayerStruct D_80114378;
extern struct PlayerStruct D_80114384;
extern struct PlayerStruct D_80118EB4;
extern struct PlayerStruct D_80118FE8;
extern struct PlayerStruct D_801190CC;
extern struct PlayerStruct D_80119194;
extern struct PlayerStruct D_801191F0;
extern struct PlayerStruct D_80119268;
extern struct PlayerStruct D_801192E0;
extern struct PlayerStruct D_80119384;
extern struct PlayerStruct D_8011935C;
extern struct PlayerStruct D_801193AC;
extern struct PlayerStruct D_8011BA88;
extern struct PlayerStruct D_8011BA8C;
extern struct PlayerStruct D_8011BB50;
extern s32 D_80177A60;
extern s32 D_80177A64;
extern s32 D_801137FC;
extern s32 D_80113838;
extern s32 D_8011BA94;
extern s32 D_8016519C;
extern void* D_80114354;
extern f64 D_801153B8;
extern f64 D_801153C0;
extern f64 D_801153C8;
extern f64 D_801153F0;
extern f64 D_801153F8;
extern f64 D_80115400;
extern f64 D_80115428;
extern f64 D_80115430;
extern f64 D_80115438;


void func_800DAD20(void) {
    func_80027464(1, &D_801142E8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
}


void func_800DAD98(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->unkA4 = 5;
    } else {
        sp4->unkA4 = 6;
    }
    sp4->unk132 = 0;
}

void func_800DAE20(void) {
    struct PlayerStruct* sp34;
    s32 sp30;

    sp34 = &gPlayerData[D_80177A60];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unk44 = 1.0f;
        func_8001C0EC(D_80177A60, 0, 0, 0x54, &D_80118E9C);
    }
    if (func_80028FA0(D_80177A60) != 0) {
        func_80029B60(D_80177A60);
    }
    sp30 = func_80014E80(-6);
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
    func_80029C40(D_80177A60);
    if (func_80029018(D_80177A60, 4, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(D_80177A60, func_800297DC());
    }
    if (func_8002A1FC(D_80177A60, 480.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = (f32) sp34->Vel.z;
        sp34->Vel.y = 0.0f;
        sp34->unkA4 = 2;
        sp34->unk132 = 0U;
    }
}

void func_800DB0F8(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 1, 0x54, &D_80118E9C);
    }
    func_8002A8B4(D_80177A60, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DB1EC.s")

void func_800DB3E8(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = (f32) sp24->Vel.z;
        func_8001C0EC(D_80177A60, 0, 3, 0x54, &D_80118E9C);
    }
    if (func_80028FA0(D_80177A60) != 0) {
        func_80029B60(D_80177A60);
    }
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp24->unkA4 = 1;
        sp24->unk132 = 0U;
    }
}

void func_800DB504(void) {
    func_8002B0E4(D_80177A60);
}

void func_800DB534(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (sp4->unk132 == 0) {
        sp4->unk132 = (u8) (sp4->unk132 + 1);
        sp4->unkAC = 0x1E;
        sp4->unk44 = 0.0f;
        sp4->Vel.z = 0.0f;
        sp4->Vel.x = (f32) sp4->Vel.z;
    }
    sp4->unkAC = (s16) (sp4->unkAC - 1);
    if (sp4->unkAC == 0) {
        sp4->unkA4 = 4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DB620.s")

void func_800DB710(void) {
    func_80027464(1, &D_801142F4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DB788.s")

void func_800DB840(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 0, 0x56, &D_80118EB4);
    }
    if (func_8002A1FC(D_80177A60, 540.0f) != 0) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0U;
    }
}

void func_800DB910(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        func_80029EF8(D_80177A60, 0.0f, 4.0f);
    }
    sp1C->Rot.y = func_8002A46C(D_80177A60);
    sp1C->unk3C = (f32) sp1C->Rot.y;
    if (func_8002A0D0(D_80177A60, 0.0f, 0.0f, 0.0f) == 1) {
        sp1C->unkA4 = 3;
        sp1C->unk132 = 0U;
    }
}

void func_800DBA0C(void) {
    struct PlayerStruct* sp2C;

    sp2C = &gPlayerData[D_80177A60];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        func_8001C0EC(D_80177A60, 0, 1, 0x56, &D_80118EB4);
    }
    sp2C->Rot.y = func_8002A46C(D_80177A60);
    sp2C->unk3C = (f32) sp2C->Rot.y;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        sp2C->unkA4 = 5;
        sp2C->unk132 = 0U;
    }
}

void func_800DBB78(void) {
    func_8002B0E4(D_80177A60);
}

void func_800DBBA8(void) {
    struct PlayerStruct* sp2C;

    sp2C = &gPlayerData[D_80177A60];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 2, 0x56, &D_80118EB4);
    }
    sp2C->Rot.y = func_8002A46C(D_80177A60);
    sp2C->unk3C = (f32) sp2C->Rot.y;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        if (func_8002A1FC(D_80177A60, 600.0f) != 0) {
            sp2C->unkA4 = 6;
            sp2C->unk132 = 0U;
        }
    }
}

void func_800DBCFC(void) {
    struct PlayerStruct* sp44;
    f32 sp40;
    f32 sp3C;

    sp44 = &gPlayerData[D_80177A60];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        sp44->unk3C = func_8002A46C(D_80177A60);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 15.0f;
        func_8001C0EC(D_80177A60, 0, 3, 0x56, &D_80118EB4);
        sp44->unkC0 = 0;
    }
    if (sp44->unkC0 == 0) {
        sp44->unkC0 = 4;
        func_800175F0(D_80177A60, 0, 0x11, -1, 0);
    } else {
        sp44->unkC0 = (s16) (sp44->unkC0 - 1);
    }
    if (func_80028FA0(D_80177A60) != 0) {
        func_80029B60(D_80177A60);
    }
    if (sp44->unkA6 != 0) {
        if (--sp44->unk44 < 5.0f) {
            sp44->unkA6 = 0;
        }
    }
    func_8002A8B4(D_80177A60, (f32) (func_80014E80(4) + 2));
    sp44->Rot.y = (f32) sp44->unk3C;
    func_80029C40(D_80177A60);
    if (func_80029018(D_80177A60, 1, 30.0f, 0, 0.0f, 0.0f) != 0) {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->unkA4 = 5;
        sp44->unk132 = 0U;
    }
    if (func_800295C0(D_80177A60, &sp40, &sp3C, 0.0f, 0.0f, 0.0f) != 0) {
        sp44->Pos.y = sp3C;
    } else {
        sp44->Pos.y = sp40;
    }
    if (func_8002A2EC(D_80177A60, 600.0f) != 0) {

    } else {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->unk44 = 0.0f;
        sp44->unkA4 = 5;
        sp44->unk132 = 0U;
    }
}

void func_800DC07C(void) {
    struct PlayerStruct* sp2C;

    sp2C = &gPlayerData[D_80177A60];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 4, 0x56, &D_80118EB4);
    }
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
        sp2C->unkA4 = 5;
        sp2C->unk132 = 0U;
    }
}

#ifdef NON_MATCHING
// matches but needs rodata
void func_800DC188(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
    switch (sp1C->unkA4) {
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
    func_80027464(1, &D_80114300, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
}

void func_800DC300(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 0, 0x56, &D_80118EB4);
    }
    if (func_8002A1FC(D_80177A60, 540.0f) != 0) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0U;
    }
}

void func_800DC3D0(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        func_80029EF8(D_80177A60, 50.0f, 4.0f);
    }
    sp1C->Rot.y = func_8002A46C(D_80177A60);
    sp1C->unk3C = (f32) sp1C->Rot.y;
    if (func_8002A0D0(D_80177A60, 0, 0, 0) == 1) {
        sp1C->unkA4 = 3;
        sp1C->unk132 = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC4CC.s")

void func_800DC5CC(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011433C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp24 != -1) {
        func_80019448(sp24, 2, 0, 1);
    }
}

void func_800DC66C(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    sp4->unk108 = 0;
    sp4->unkA4 = 4;
    sp4->unk132 = 0;
}

void func_800DC6D0(void) {
    struct PlayerStruct* sp34;
    s32 sp30;

    sp34 = &gPlayerData[D_80177A60];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unk44 = 1.0f;
        sp34->Rot.x = 60.0f;
        func_8001C0EC(D_80177A60, 0, 0, 0x60, &D_80118FE8);
    }
    if (func_80028FA0(D_80177A60) != 0) {
        func_80029B60(D_80177A60);
    }
    sp30 = func_80014E80(-6);
    func_8002A8B4(D_80177A60, (f32) sp30);
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
    func_80029C40(D_80177A60);
    if (func_80029018(D_80177A60, 4, 60.0f, 0, 0.0f, 0.0f) != 0) {
        func_80029824(D_80177A60, func_800297DC());
    }
    if (func_8002A1FC(D_80177A60, 480.0f) != 0) {
        sp34->unkA4 = 2;
        sp34->unk132 = 0U;
    }
}

void func_800DC984(void) {
    struct PlayerStruct* sp34;
    s32 temp;

    sp34 = &gPlayerData[D_80177A60];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
        func_8001C0EC(D_80177A60, 0, 2, 0x60, &D_80118FE8);
    }
    func_8002A8B4(D_80177A60, 6.0f);
    sp34->Rot.y = (f32) sp34->unk3C;
    if (sp34->Rot.x < 139.0f) {
        sp34->Rot.x = func_80015538(sp34->Rot.x, 10.0f);
    }
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp34->unkA4 = 3;
        sp34->unk132 = 0U;
    }
}

void func_800DCAFC(void) {
    struct PlayerStruct* sp34;
    s32 sp30;

    sp34 = &gPlayerData[D_80177A60];
    sp30 = 0;
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        sp34->unk44 = 26.0f;
        sp34->unk3C = func_8002A46C(D_80177A60);
        sp34->Rot.y = (f32) sp34->unk3C;
        sp34->Vel.y = -13.0f;
        func_8001C0EC(D_80177A60, 0, 2, 0x60, &D_80118FE8);
        func_800175F0(D_80177A60, 0, 0x5D, -1, 0);
    }
    if (func_80028FA0(D_80177A60) != 0) {
        func_80029B60(D_80177A60);
        sp34->Rot.y = (f32) sp34->unk3C;
    }
    func_80029C40(D_80177A60);
    if (func_80029018(D_80177A60, 3, 60.0f, 0, 0.0f, 0.0f) != 0) {
        sp34->unkA4 = 4;
        sp34->unk132 = 0U;
    }
    if (func_8002A0D0(D_80177A60, 0, 0, -20.0f) == 1) {
        sp34->unkA4 = 4;
        sp34->unk132 = 0U;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
    }
}

void func_800DCD20(void) {
    func_8002B0E4(D_80177A60);
}

void func_800DCD50(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    switch (sp24->unkA4) {
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

    sp24 = func_80027464(1, &D_80114348, (f32) D_80165100->unk2, (f32) (D_80165100->unk4 - 5), (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gPlayerData[sp24].unk13A = 1;
    }
}

void func_800DCEE4(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        func_8001ABF4(D_80177A60, 0, 0, &D_801190CC);
    }
    if (func_8002A1FC(D_80177A60, 900.0f) != 0) {
        sp1C->unkA4 = 2;
        sp1C->unk132 = 0U;
    }
}

void func_800DCFAC(void) {
    struct PlayerStruct* sp24;
    s16 temp_t9;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->Pos.y = (f32) (sp24->Pos.y + 5.0f);
        func_8001C0EC(D_80177A60, 0, 0, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_801190CC);
        func_8001ABF4(D_80177A60, 1, 0, &D_801190CC.Rot.y);
        func_8001B754(D_80177A60, 0);
        sp24->unk13A = 0;
    }
    if ((func_80028FA0(D_80177A60) != 0) && ((sp24->unk106 == 0xA2) || (sp24->unk106 == 0xA3))) {
        func_800E3EE4();
        return;
    }
    func_8002A8B4(D_80177A60, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0U;
    }
}

void func_800DD160(void) {
    struct PlayerStruct* sp24;
    s16 temp_t9;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 2, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_801190CC);
        func_8001ABF4(D_80177A60, 1, 0, &D_801190CC.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
    }
    if ((func_80028FA0(D_80177A60) != 0) && (((sp24->unk106 == 0xA2)) || (sp24->unk106 == 0xA3))) {
        func_800E3EE4();
        return;
    }
    func_8002A8B4(D_80177A60, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp24->unkA4 = 4;
        sp24->unk132 = 0U;
        sp24->unkB2 = 1;
    }
}

void func_800DD300(void) {
    struct PlayerStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gPlayerData[D_80177A60];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 7, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_801190CC);
        func_8001ABF4(D_80177A60, 1, 0, &D_801190CC.Rot.y);
        sp44->unk3C = func_8002A46C(D_80177A60);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkA8 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(D_80177A60) != 0) {
        if ((sp44->unk106 == 0xA2) || (sp44->unk106 == 0xA3)) {
            func_800E3EE4();
            return;
        } else {
            func_80029B60(D_80177A60);
        }
    }

    if (sp44->unkA8 < 4) {
        if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(D_80177A60, 20.0f, 4.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(D_80177A60);
        if (func_80029018(D_80177A60, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
            func_80029824(D_80177A60, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(D_80177A60, 0, 0, 0, 30.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
            if (func_8001B4AC(D_80177A60, 0) != 0) {
                sp44->unkA6 = 0;
                sp44->unkA8 = (s16) (sp44->unkA8 + 1);
            } else {
                sp44->Vel.z = 0.0f;
                sp44->Vel.x = (f32) sp44->Vel.z;
            }
        }
    } else {
        sp44->unkA4 = 3;
        sp44->unk132 = 0U;
        sp44->unkB2 = 0;
    }
}

void func_800DD690(void) {
    func_8002B0E4(D_80177A60);
}

void func_800DD6C0(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (sp4->unk132 == 0) {
        sp4->unk132 = (u8) (sp4->unk132 + 1);
        sp4->unk44 = 0.0f;
        sp4->Vel.z = 0.0f;
        sp4->Vel.x = (f32) sp4->Vel.z;
        if (sp4->unkB2 == 1) {
            sp4->unkA4 = 4;
            sp4->unkA8 = 3;
        } else {
            sp4->unkA4 = 3;
            sp4->unk132 = 0U;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DD7B0.s")

void func_800DD8A0(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->unkA4 = 5;
    } else {
        sp4->unkA4 = 6;
    }
    sp4->unk132 = 0;
}

void func_800DD928(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114354, (f32) D_80165100->unk2, (f32) (D_80165100->unk4 - 5), (f32) D_80165100->unk6, (f32) D_80165100->unk8);

    if(sp24 != -1)
    {
        gPlayerData[sp24].unk13A = 1;
    }
}

void func_800DD9E0(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119128);
    }
    if (func_8002A1FC(D_80177A60, 900.0f) != 0) {
        sp1C->unkA4 = 2;
        sp1C->unk132 = 0U;
    }
}

void func_800DDAA8(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->Pos.y = (f32) (sp24->Pos.y + 5.0f);
        func_8001C0EC(D_80177A60, 0, 1, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119128);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119128.Rot.y);
        func_8001B754(D_80177A60, 0);
        sp24->unk13A = 0;
    }
    if ((func_80028FA0(D_80177A60) != 0) && (((sp24->unk106 == 0xA1)) || (sp24->unk106 == 0xA3))) {
        func_800E3EE4();
        return;
    }
    func_8002A8B4(D_80177A60, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0U;
    }
}

void func_800DDC5C(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 3, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119128);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119128.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
    }
    if ((func_80028FA0(D_80177A60) != 0) && (((sp24->unk106 == 0xA1)) || (sp24->unk106 == 0xA3))) {
        func_800E3EE4();
        return;
    }
    sp24->unk3C = func_8002A46C(D_80177A60);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp24->unkA4 = 4;
        sp24->unk132 = 0U;
        sp24->unkB2 = 1;
    }
}

void func_800DDE08(void) {
    struct PlayerStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gPlayerData[D_80177A60];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 8, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119128);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119128.Rot.y);
        sp44->unk3C = func_8002A46C(D_80177A60);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(D_80177A60) != 0) {
        if ((sp44->unk106 == 0xA1) || (sp44->unk106 == 0xA3)) {
            func_800E3EE4();
            return;
        } else {
            func_80029B60(D_80177A60);
        }
    }
    if (func_8001B62C(D_80177A60, 0) > 10.0f) {
        if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(D_80177A60, 30.0f, 3.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(D_80177A60);
        if (func_80029018(D_80177A60, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
            func_80029824(D_80177A60, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(D_80177A60, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        }
        if (func_8001B4AC(D_80177A60, 0) != 0) {
            if (func_8002A1FC(D_80177A60, 240.0f) != 0) {
                sp44->unkA4 = 5;
                sp44->unkA6 = 0;
                sp44->unk132 = 0U;
                sp44->unkB2 = 0;
            } else {
                sp44->unkA4 = 3;
                sp44->unkA6 = 0;
                sp44->unk132 = 0U;
                sp44->unkB2 = 0;
            }
        }
    } else if (func_8002A1FC(D_80177A60, 240.0f) != 0) {
        sp44->unkA4 = 5;
        sp44->unkA6 = 0;
        sp44->unk132 = 0U;
        sp44->unkB2 = 0;
    }
}

void func_800DE1E8(void) {
    struct PlayerStruct* sp3C;
    s32 sp38;
    f32 temp_f20;
    f32 temp_f20_2;

    sp3C = &gPlayerData[D_80177A60];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = (u8) (sp3C->unk132 + 1);
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z;
        func_8001C0EC(D_80177A60, 0, 9, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119128);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119128.unk38);
        sp3C->unk3C = func_8002A46C(D_80177A60);
        sp3C->Rot.y = (f32) sp3C->unk3C;
        sp3C->unk44 = 6.0f;
    }
    if ((func_8001B62C(D_80177A60, 0) > 20.0f) && (sp3C->unkAA == 0)) {
        sp38 = func_80027464(1, &D_80114360, sp3C->Pos.x, sp3C->Pos.y + 60.0f, sp3C->Pos.z, sp3C->unk3C);
        if (sp38 != -1) {
            func_8001ABF4(sp38, 0, 3, &D_8011935C);
            func_80026F10(D_80177A60, sp38);
            gPlayerData[sp38].unk3C = gPlayerData[sp38].Rot.y = sp3C->unk3C;
            gPlayerData[sp38].unkB2 = 1;
            sp3C->unkAA = (s16) (sp3C->unkAA + 1);
        }
    }
    if (func_80028FA0(D_80177A60) != 0) {
        if ((sp3C->unk106 == 0xA1) || (sp3C->unk106 == 0xA3)) {
            func_800E3EE4();
            return;
        } else {
            func_80029B60(D_80177A60);
        }
    }
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp3C->unkA4 = 3;
        sp3C->unkAA = 0;
        sp3C->unk132 = 0U;
    }
}

void func_800DE534(void) {
    func_8002B0E4(D_80177A60);
}

void func_800DE564(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (sp4->unk132 == 0) {
        sp4->unk132 = (u8) (sp4->unk132 + 1);
        sp4->unk44 = 0.0f;
        sp4->Vel.z = 0.0f;
        sp4->Vel.x = (f32) sp4->Vel.z;
        if (sp4->unkB2 == 1) {
            sp4->unkA4 = 4;
            sp4->unkA8 = 3;
        } else {
            sp4->unkA4 = 3;
            sp4->unk132 = 0U;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DE654.s")

void func_800DE754(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->unkA4 = 6;
    } else {
        sp4->unkA4 = 7;
    }
    sp4->unk132 = 0;
}

void func_800DE7DC(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011436C, (f32) D_80165100->unk2, (f32) (D_80165100->unk4 + 5), (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gPlayerData[sp24].unk13A = 1;
    }
}

void func_800DE894(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119194);
    }
    if (func_8002A1FC(D_80177A60, 900.0f) != 0) {
        sp1C->unkA4 = 2;
        sp1C->unk132 = 0U;
    }
}

void func_800DE95C(void) {
    struct PlayerStruct* sp24;
    s16 temp_t9;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 0, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119194);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119194.Rot.y);
        sp24->Pos.y = (f32) (sp24->Pos.y - 5.0f);
        func_8001B754(D_80177A60, 0);
        func_80029EF8(D_80177A60, 0, 4.0f);
        sp24->unk13A = 0;
    }
    if ((func_80028FA0(D_80177A60) != 0) && (((sp24->unk106 == 0xA2)) || (sp24->unk106 == 0xA1))) {
        func_800E3EE4();
        return;
    }
    sp24->Rot.y = func_8002A46C(D_80177A60);
    sp24->unk3C = (f32) sp24->Rot.y;
    if (func_8002A0D0(D_80177A60, 0, 0, 0) == 1) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0U;
    }
}

void func_800DEB3C(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 4, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119194);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119194.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
        sp24->Vel.y = 0.0f;
    }
    if ((func_80028FA0(D_80177A60) != 0) && (((sp24->unk106 == 0xA2)) || (sp24->unk106 == 0xA1))) {
        func_800E3EE4();
        return;
    }
    func_8002A8B4(D_80177A60, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp24->unkA4 = 4;
        sp24->unk132 = 0U;
    }
}

void func_800DECE0(void) {
    struct PlayerStruct* sp3C;
    f32 sp38;
    s16 temp_t1;
    s32 temp;

    sp3C = &gPlayerData[D_80177A60];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = (u8) (sp3C->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 8, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119194);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119194.Rot.y);
        sp3C->unk3C = func_8002A46C(D_80177A60);
        sp3C->Rot.y = (f32) sp3C->unk3C;
        sp3C->unkA6 = 0;
        sp3C->unkA8 = 0;
    }
    if ((func_80028FA0(D_80177A60) != 0) && (((sp3C->unk106 == 0xA2)) || (sp3C->unk106 == 0xA1))) {
        func_800E3EE4();
        return;
    }
    if (func_8001B62C(D_80177A60, 0) > 10.0f) {
        if (sp3C->unkA6 == 0) {
            sp3C->unkA6 = 1;
            func_80029EF8(D_80177A60, 20.0f, 2.0f);
        }
        sp38 = sp3C->Vel.y;
        sp3C->Vel.y = 0.0f;
        if (func_80029018(D_80177A60, 0, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_80029824(D_80177A60, func_800297DC());
        }
        sp3C->Vel.y = sp38;
        if (func_80029F58(D_80177A60, 0.0f, 0.0f, 0.0f, 30.0f) == 1) {
            sp3C->Vel.y = 0.0f;
        }
        if (func_8001B4AC(D_80177A60, 0) != 0) {
            if (func_8002A1FC(D_80177A60, 300.0f) != 0) {
                sp3C->unkA4 = 5;
                sp3C->unkA6 = 0;
                sp3C->unkA8 = 0;
                sp3C->unk132 = 0U;
            } else {
                sp3C->unkA6 = 0;
            }
        }
    } else if (func_8002A1FC(D_80177A60, 300.0f) != 0) {
        sp3C->unkA4 = 5;
        sp3C->unkA6 = 0;
        sp3C->unkA8 = 0;
        sp3C->unk132 = 0U;
    }
}

void func_800DF034(void) {
    struct PlayerStruct* sp44;
    f32 sp40;
    f32 temp_f20;
    s16 temp_t1;

    sp44 = &gPlayerData[D_80177A60];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 0xA, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119194);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119194.Rot.y);
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(D_80177A60) != 0) {
        if ((sp44->unk106 == 0xA1) || (sp44->unk106 == 0xA2)) {
            func_800E3EE4();
            return;
        } else {
            func_80029B60(D_80177A60);
        }
    }

    func_8002A8B4(D_80177A60, 5.0f);
    sp44->Rot.y = (f32) sp44->unk3C;
    if (func_8001B62C(D_80177A60, 0) > 10.0f) {
        if (func_8001B62C(D_80177A60, 0) > 29.0f) {
            if (sp44->unkA6 == 1) {
                sp44->unkA6 = 2;
                func_80029EF8(D_80177A60, 0, 1.0f);
            }
        } else if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(D_80177A60, 40.0f, 2.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(D_80177A60);
        if (func_80029018(D_80177A60, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
            func_80029824(D_80177A60, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(D_80177A60, 0, 0, 0, 30.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        }
        if (func_8001B4AC(D_80177A60, 0) != 0) {
            sp44->unkA4 = 6;
            sp44->unkB2 = 2;
            sp44->unk132 = 0U;
        }
    }
}

void func_800DF3D4(void) {
    struct PlayerStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gPlayerData[D_80177A60];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 0xB, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119194);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119194.Rot.y);
        func_80029EF8(D_80177A60, -5.0f, 0.0f);
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkB2 = 2;
    }
    if (func_80028FA0(D_80177A60) != 0) {
        if ((sp44->unk106 == 0xA1) || (sp44->unk106 == 0xA2)) {
            func_800E3EE4();
            return;
        } else {
            func_80029B60(D_80177A60);
        }
    }

    func_8002A8B4(D_80177A60, 5.0f);
    sp44->Rot.y = (f32) sp44->unk3C;
    sp40 = sp44->Vel.y;
    sp44->Vel.y = 0.0f;
    func_80029C40(D_80177A60);
    if (func_80029018(D_80177A60, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
        func_80029824(D_80177A60, func_800297DC());
    }
    sp44->Vel.y = sp40;
    if (func_80029F58(D_80177A60, 0, 0, 0, 30.0f) == 1) {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->unk44 = 0.0f;
    }
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        sp44->unkA4 = 3;
        sp44->unkA6 = 0;
        sp44->unkB2 = 0;
        sp44->unk132 = 0U;
    }
}

void func_800DF704(void) {
    func_8002B0E4(D_80177A60);
}

void func_800DF734(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    sp4->unk44 = 0.0f;
    sp4->Vel.z = 0.0f;
    sp4->Vel.x = (f32) sp4->Vel.z;
    if (sp4->unkB2 == 1) {
        sp4->unkA4 = 5;
    } else if (sp4->unkB2 == 2) {
        sp4->unkA4 = 6;
    } else {
        sp4->unkA4 = 3;
        sp4->unk132 = 0;
        sp4->unkA6 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DF81C.s")

void func_800DF92C(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->unkA4 = 7;
    } else {
        sp4->unkA4 = 8;
    }
}

void func_800DF9A8(void) {
    struct PlayerStruct* sp34;
    f32 sp30;

    sp34 = &gPlayerData[D_80177A60];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        func_80029EF8(D_80177A60, 0, 4.0f);
    }
    if (func_80028FA0(D_80177A60) != 0) {
        func_80029B60(D_80177A60);
    }
    sp34->Rot.y = func_8002A46C(D_80177A60);
    sp34->unk3C = (f32) sp34->Rot.y;
    func_8002A8B4(D_80177A60, 5.0f);
    sp34->Rot.y = (f32) sp34->unk3C;
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    if (func_80029018(D_80177A60, 0, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(D_80177A60, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(D_80177A60, 0, 0, 0, 0.0f) == 1) {
        sp34->Vel.y = 0.0f;
    }
    if (sp34->Scale.x < 2.0f) {
        sp34->Scale.x = (f32) ((f64) sp34->Scale.x + D_801153B8);
        sp34->Scale.y = (f32) ((f64) sp34->Scale.y + D_801153C0);
        sp34->Scale.z = (f32) ((f64) sp34->Scale.z + D_801153C8);
    } else {
        sp34->unk108 = 1;
        sp34->unkA4 = 2;
        sp34->unk132 = 0U;
    }
}

void func_800DFC2C(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 2, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_801191F0);
        func_8001ABF4(D_80177A60, 1, 0, &D_801191F0.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
    }
    func_8002A8B4(D_80177A60, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        if (func_8002A1FC(D_80177A60, 300.0f) != 0) {
            sp24->unkA4 = 4;
            sp24->unkA8 = 0;
            sp24->unk132 = 0U;
        } else {
            sp24->unkA4 = 3;
            sp24->unk132 = 0U;
            sp24->unkB2 = 1;
        }
    }
}

void func_800DFDBC(void) {
    struct PlayerStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gPlayerData[D_80177A60];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 7, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_801191F0);
        func_8001ABF4(D_80177A60, 1, 0, &D_801191F0.Rot.y);
        sp44->unk3C = func_8002A46C(D_80177A60);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkA8 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(D_80177A60) != 0) {
        func_80029B60(D_80177A60);
    }
    if (sp44->unkA8 < 4) {
        if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(D_80177A60, 20.0f, 4.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(D_80177A60);
        if (func_80029018(D_80177A60, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
            func_80029824(D_80177A60, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(D_80177A60, 0, 0, 0, 30.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
            if (func_8001B4AC(D_80177A60, 0) != 0) {
                if (func_8002A1FC(D_80177A60, 300.0f) != 0) {
                    sp44->unkA4 = 4;
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
        sp44->unkA4 = 2;
        sp44->unkB2 = 0;
        sp44->unk132 = 0U;
    }
}

void func_800E0154(void) {
    struct PlayerStruct* sp44;
    s32 sp40;
    f32 temp_f20;
    s16 temp_t8;
    s32 temp2;
    s16 sp32;

    sp44 = &gPlayerData[D_80177A60];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        func_8001C0EC(D_80177A60, 0, 0xC, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_801191F0);
        func_8001ABF4(D_80177A60, 1, 0, &D_801191F0.Rot.y);
        sp44->unk3C = func_8002A46C(D_80177A60);
        sp44->Rot.y = (f32) sp44->unk3C;
    }
    if ((func_8001B62C(D_80177A60, 0) > 20.0f) && (sp44->unkAA == 0)) {
        sp32 = 0;
        do {
            sp40 = func_80027464(1, &D_80114378, sp44->Pos.x, sp44->Pos.y + 120.0f, sp44->Pos.z, sp44->unk3C);
            if (sp40 != -1) {
                func_8001ABF4(sp40, 0, 3, &D_80119384);
                func_80026F10(D_80177A60, sp40);
                if (sp32 == 0) {
                    func_8002A8B4(sp40, -325.0f);
                } else if (sp32 == 2) {
                    func_8002A8B4(sp40, -35.0f);
                } else {
                    func_8002A8B4(sp40, 0);
                }
                gPlayerData[sp40].unkB2 = 2;
                gPlayerData[sp40].unkAA = 1;
            }
            sp44->unkAA = (s16) (sp44->unkAA + 1);
        } while (++sp32 < 3);
    }
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp44->unkA4 = 2;
        sp44->unkAA = 0;
        sp44->unk132 = 0U;
    }
}

void func_800E047C(void) {
    func_8002B0E4(D_80177A60);
}

void func_800E04AC(void) {
    struct PlayerStruct* sp2C;

    sp2C = &gPlayerData[D_80177A60];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkD4 = (f32) sp2C->Vel.y;
        func_8001BBDC(D_80177A60, 1);
        func_8001ABF4(D_80177A60, 1, 0, &D_801191F0.unk38);
    }
    sp2C->Vel.z = 0.0f;
    sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
    if (sp2C->unk108 == 1) {
        func_8001BBDC(D_80177A60, 0);
        sp2C->Vel.y = (f32) sp2C->unkD4;
        if (sp2C->unkB2 == 1) {
            if (func_8001B4AC(D_80177A60, 0) != 0) {
                func_8001C0EC(D_80177A60, 0, 5, 0x70, &D_80118FF4);
                func_8001ABF4(D_80177A60, 0, 0, &D_801191F0);
                func_8001ABF4(D_80177A60, 1, 0, &D_801191F0.Rot.y);
                sp2C->unkA6 = 0;
                sp2C->unkB2 = 0;
                sp2C->unkA4 = 2;
            } else {
                sp2C->unkA4 = 3;
                sp2C->unkA8 = 3;
            }
        } else {
            sp2C->unkA4 = 2;
            sp2C->unk132 = 0U;
            sp2C->unkA6 = 0;
        }
    }
}

void func_800E06E0(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    sp4->unk44 = 0.0f;
    sp4->Vel.z = 0.0f;
    sp4->Vel.x = (f32) sp4->Vel.z;
    if (sp4->unkB2 == 1) {
        sp4->unkA4 = 3;
        sp4->unkA8 = 3;
    } else if (sp4->unkB2 == 9) {
        sp4->unkA4 = 1;
        sp4->unk132 = 0;
    } else {
        sp4->unkA4 = 2;
        sp4->unk132 = 0;
        sp4->unkA6 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E07DC.s")

void func_800E0938(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->unkA4 = 5;
        sp4->unk132 = 0;
    } else if (D_80177A64 == 1) {
        sp4->unk108 = 0x3C;
    }
}

void func_800E09D0(void) {
    struct PlayerStruct* sp34;
    f32 sp30;

    sp34 = &gPlayerData[D_80177A60];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        func_80029EF8(D_80177A60, 0, 4.0f);
    }
    if (func_80028FA0(D_80177A60) != 0) {
        func_80029B60(D_80177A60);
    }
    sp34->Rot.y = func_8002A46C(D_80177A60);
    sp34->unk3C = (f32) sp34->Rot.y;
    func_8002A8B4(D_80177A60, 5.0f);
    sp34->Rot.y = (f32) sp34->unk3C;
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    if (func_80029018(D_80177A60, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
        func_80029824(D_80177A60, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(D_80177A60, 0, 0, 0, 0.0f) == 1) {
        sp34->Vel.y = 0.0f;
    }
    if (sp34->Scale.x < 2.0f) {
        sp34->Scale.x +=  D_801153F0;
        sp34->Scale.y +=  D_801153F8;
        sp34->Scale.z +=  D_80115400;
    } else {
        sp34->unk108 = 1;
        sp34->unkA4 = 2;
        sp34->unk132 = 0U;
    }
}

void func_800E0C54(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 5, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119268);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119268.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
    }
    func_8002A8B4(D_80177A60, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        if (func_8002A1FC(D_80177A60, 300.0f) != 0) {
            sp24->unkA4 = 4;
            sp24->unkA8 = 0;
            sp24->unk132 = 0U;
        } else {
            sp24->unkA4 = 3;
            sp24->unk132 = 0U;
            sp24->unkB2 = 1;
        }
    }
}

void func_800E0DE4(void) {
    struct PlayerStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gPlayerData[D_80177A60];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 8, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119268);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119268.Rot.y);
        sp44->unk3C = func_8002A46C(D_80177A60);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(D_80177A60) != 0) {
        func_80029B60(D_80177A60);
    }
    if (func_8001B62C(D_80177A60, 0) > 10.0f) {
        if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(D_80177A60, 30.0f, 3.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(D_80177A60);
        if (func_80029018(D_80177A60, 0, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_80029824(D_80177A60, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(D_80177A60, 0, 0, 0, 0.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        }
        if (func_8001B4AC(D_80177A60, 0) != 0) {
            if (func_8002A1FC(D_80177A60, 300.0f) != 0) {
                sp44->unkA4 = 4;
                sp44->unkA6 = 0;
                sp44->unk132 = 0U;
                sp44->unkB2 = 2;
            } else {
                sp44->unkA4 = 2;
                sp44->unkA6 = 0;
                sp44->unk132 = 0U;
                sp44->unkB2 = 0;
            }
        }
    } else {
        sp44->Vel.y = 0.0f;
        if (func_8002A1FC(D_80177A60, 300.0f) != 0) {
            sp44->unkA4 = 4;
            sp44->unkA6 = 0;
            sp44->unk132 = 0U;
            sp44->unkB2 = 2;
        }
    }
}

void func_800E119C(void) {
    struct PlayerStruct* sp44;
    s32 sp40;
    s32 temp1;
    s16 temp2;
    f32 temp_f20;
    s16 sp32;
    s32 temp_t6;

    sp44 = &gPlayerData[D_80177A60];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        sp44->Vel.z = 0.0f;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
        func_8001C0EC(D_80177A60, 0, 0xD, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119268);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119268.Rot.y);
        sp44->unk3C = func_8002A46C(D_80177A60);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unkB2 = 2;
        sp44->unkAA = 0;
    }
    if (func_8001B62C(D_80177A60, 0) > 10.0f) {
        if ((func_8001B62C(D_80177A60, 0) > 25.0f) && (sp44->unkAA == 1)) {
            sp32 = 0;
            do {
                sp40 = func_80027464(1, &D_80114384, sp44->Pos.x, sp44->Pos.y + 120.0f, sp44->Pos.z, sp44->unk3C);
                if (sp40 != -1) {
                    func_8001ABF4(sp40, 0, 3, &D_801193AC);
                    func_80026F10(D_80177A60, sp40);
                    if (sp32 == 0) {
                        gPlayerData[sp40].unk3C = 0.0f;
                    } else if (sp32 == 1) {
                        gPlayerData[sp40].unk3C = 90.0f;
                    } else if (sp32 == 2) {
                        gPlayerData[sp40].unk3C = 180.0f;
                    } else {
                        gPlayerData[sp40].unk3C = 270.0f;
                    }
                    gPlayerData[sp40].unkB2 = 3;
                    gPlayerData[sp40].unkAA = 1;
                }
            } while (++sp32 < 4);
            sp44->unkAA = (s16) (sp44->unkAA + 1);
        } else if (sp44->unkAA == 0) {
            func_80029EF8(D_80177A60, 45.0f, 3.0f);
            sp44->unkAA = (s16) (sp44->unkAA + 1);
        }
    } else {
        sp44->Vel.y = 0.0f;
    }
    if (func_80029F58(D_80177A60, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        sp44->Vel.y = 0.0f;
    }
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp44->unkA4 = 2;
        sp44->unkAA = 0;
        sp44->unkB2 = 0;
        sp44->unk132 = 0U;
    }
}

void func_800E1640(void) {
    func_8002B0E4(D_80177A60);
}

void func_800E1670(void) {
    struct PlayerStruct* sp2C;

    sp2C = &gPlayerData[D_80177A60];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        sp2C->unkD4 = (f32) sp2C->Vel.y;
        func_8001BBDC(D_80177A60, 1);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119268.unk38);
    }
    sp2C->Vel.z = 0.0f;
    sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
    if (sp2C->unk108 == 1) {
        func_8001BBDC(D_80177A60, 0);
        if (sp2C->unkB2 == 1) {
            if (func_8001B4AC(D_80177A60, 0) != 0) {
                func_8001C0EC(D_80177A60, 0, 5, 0x70, &D_80118FF4);
                func_8001ABF4(D_80177A60, 0, 0, &D_80119268);
                func_8001ABF4(D_80177A60, 1, 0, &D_80119268.Rot.y);
                sp2C->unkB2 = 0;
                sp2C->unkA4 = 2;
            } else {
                sp2C->unkA4 = 3;
                sp2C->unkA8 = 3;
                sp2C->Vel.y = (f32) sp2C->unkD4;
            }
        } else if (sp2C->unkB2 == 2) {
            if (func_8001B4AC(D_80177A60, 0) != 0) {
                func_8001C0EC(D_80177A60, 0, 5, 0x70, &D_80118FF4);
                func_8001ABF4(D_80177A60, 0, 0, &D_80119268);
                func_8001ABF4(D_80177A60, 1, 0, &D_80119268.Rot.y);
                sp2C->unkB2 = 0;
                sp2C->unkA4 = 2;
            } else {
                sp2C->unkA4 = 4;
                sp2C->unkAA = 2;
                sp2C->Vel.y = (f32) sp2C->unkD4;
            }
        } else {
            sp2C->unkA4 = 2;
            sp2C->unk132 = 0U;
            sp2C->unkA6 = 0;
        }
    }
}

void func_800E1978(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    sp4->unk44 = 0.0f;
    sp4->Vel.z = 0.0f;
    sp4->Vel.x = (f32) sp4->Vel.z;
    if (sp4->unkB2 == 1) {
        sp4->unkA4 = 3;
        sp4->unkA8 = 3;
    } else if (sp4->unkB2 == 2) {
        sp4->unkA4 = 4;
        sp4->unkAA = 2;
    } else if (sp4->unkB2 == 9) {
        sp4->unkA4 = 1;
        sp4->unk132 = 0;
    } else {
        sp4->unkA4 = 2;
        sp4->unk132 = 0;
        sp4->unkA6 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E1AA8.s")

void func_800E1C04(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (D_80177A64 == 0) {
        sp4->unk108 = 0;
        sp4->unkA4 = 5;
        sp4->unk132 = 0;
    } else if (D_80177A64 == 1) {
        sp4->unk108 = 0x3C;
    }
}

void func_800E1C9C(void) {
    struct PlayerStruct* sp34;
    f32 sp30;

    sp34 = &gPlayerData[D_80177A60];
    if (sp34->unk132 == 0) {
        sp34->unk132 = (u8) (sp34->unk132 + 1);
        func_80029EF8(D_80177A60, 0, 4.0f);
    }
    if (func_80028FA0(D_80177A60) != 0) {
        func_80029B60(D_80177A60);
    }
    sp34->Rot.y = func_8002A46C(D_80177A60);
    sp34->unk3C = (f32) sp34->Rot.y;
    func_8002A8B4(D_80177A60, 5.0f);
    sp34->Rot.y = (f32) sp34->unk3C;
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    if (func_80029018(D_80177A60, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
        func_80029824(D_80177A60, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(D_80177A60, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
        sp34->Vel.y = 0.0f;
    }
    if (sp34->Scale.x < 2.0f) {
        sp34->Scale.x = (f32) ((f64) sp34->Scale.x + D_80115428);
        sp34->Scale.y = (f32) ((f64) sp34->Scale.y + D_80115430);
        sp34->Scale.z = (f32) ((f64) sp34->Scale.z + D_80115438);
    } else {
        sp34->unk108 = 1;
        sp34->unkA4 = 2;
        sp34->unk132 = 0U;
    }
}

void func_800E1F20(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 6, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_801192E0);
        func_8001ABF4(D_80177A60, 1, 0, &D_801192E0.Rot.y);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
    }
    func_8002A8B4(D_80177A60, 6.0f);
    sp24->Rot.y = (f32) sp24->unk3C;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0U;
    }
}

void func_800E2068(void) {
    struct PlayerStruct* sp44;
    f32 sp40;
    f32 temp_f20;

    sp44 = &gPlayerData[D_80177A60];
    if (sp44->unk132 == 0) {
        sp44->unk132 = (u8) (sp44->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 7, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_801192E0);
        func_8001ABF4(D_80177A60, 1, 0, &D_801192E0.Rot.y);
        sp44->unk3C = func_8002A46C(D_80177A60);
        sp44->Rot.y = (f32) sp44->unk3C;
        sp44->unk44 = 6.0f;
        sp44->unkA6 = 0;
        sp44->unkA8 = 0;
        sp44->unkB2 = 1;
    }
    if (func_80028FA0(D_80177A60) != 0) {
        func_80029B60(D_80177A60);
    }
    if (sp44->unkA8 < 4) {
        if (sp44->unkA6 == 0) {
            sp44->unkA6 = 1;
            func_80029EF8(D_80177A60, 20.0f, 4.0f);
        }
        sp40 = sp44->Vel.y;
        sp44->Vel.y = 0.0f;
        func_80029C40(D_80177A60);
        if (func_80029018(D_80177A60, 0, 80.0f, 0, 0.0f, 0.0f) != 0) {
            func_80029824(D_80177A60, func_800297DC());
        }
        sp44->Vel.y = sp40;
        if (func_80029F58(D_80177A60, 0, 0, 0, 30.0f) == 1) {
            sp44->Vel.z = 0.0f;
            sp44->Vel.x = sp44->Vel.y = sp44->Vel.z;
            if (func_8001B4AC(D_80177A60, 0) != 0) {
                if (func_8002A1FC(D_80177A60, 300.0f) != 0) {
                    sp44->unkA4 = 4;
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
        sp44->unkA4 = 2;
        sp44->unkB2 = 0;
        sp44->unk132 = 0U;
    }
}

void func_800E2400(void) {
    struct PlayerStruct* sp4C;
    f32 sp48;
    f32 temp_f20;
    s32 temp;
    s32 temp2;

    sp4C = &gPlayerData[D_80177A60];
    if (sp4C->unk132 == 0) {
        sp4C->unk132 = (u8) (sp4C->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 0xA, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_801192E0);
        func_8001ABF4(D_80177A60, 1, 0, &D_801192E0.Rot.y);
        sp4C->unk44 = 5.0f;
        sp4C->unkA6 = 0;
        sp4C->unkB2 = 2;
    }
    func_8002A8B4(D_80177A60, 6.0f);
    sp4C->Rot.y = (f32) sp4C->unk3C;
    if (func_8001B62C(D_80177A60, 0) > 10.0f) {
        if (func_8001B62C(D_80177A60, 0) > 29.0f) {
            if (sp4C->unkA6 == 1) {
                sp4C->unkA6 = 2;
                func_80029EF8(D_80177A60, 0, 1.0f);
            }
        } else if (sp4C->unkA6 == 0) {
            sp4C->unkA6 = 1;
            func_80029EF8(D_80177A60, 40.0f, 2.0f);
        }
        sp48 = sp4C->Vel.y;
        sp4C->Vel.y = 0.0f;
        func_80029C40(D_80177A60);
        if (func_80029018(D_80177A60, 0, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
            func_80029824(D_80177A60, func_800297DC());
        }
        sp4C->Vel.y = sp48;
        if (func_80029F58(D_80177A60, 0.0f, 0.0f, 0.0f, 0.0f) == 1) {
            sp4C->Vel.z = 0.0f;
            sp4C->Vel.x = sp4C->Vel.y = sp4C->Vel.z;
        }
        if (func_8001B4AC(D_80177A60, 0) != 0) {
            sp4C->unkA4 = 5;
            sp4C->unkB2 = 3;
            sp4C->unk132 = 0U;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E2738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E2A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E2A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E2CDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E2E28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E2F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E302C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E31E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E3214.s")

void func_800E3474(void) {
    func_8002B0E4(D_80177A60);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E34A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E3704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E3734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E38D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E3930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E39F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E3B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E3C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E3DD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E3EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E445C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E450C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E45C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E4728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E49AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E4BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E4E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E4F40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E5058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E515C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E5260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E5364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E54F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E5528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E56D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E5824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E589C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E594C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E5C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E5DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E5F18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E60D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E624C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E632C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E63F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E64D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E660C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E6720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E683C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E6AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E6C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E6D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E6E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E70D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E71C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E7344.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E74C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E753C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E764C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E778C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E7974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E7A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E7C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E7D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E7EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E802C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E80E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E816C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E8250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E839C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E84D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E8804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E8934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E8AAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E8BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E8CD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E8DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E8EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E904C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E90C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E91E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E9420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E9AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EA194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EA55C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EAAB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EB01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EB61C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EB9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EBA48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EBC58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EBC88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EBEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EBF24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EBFA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EC144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EC260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EC348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EC408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EC4AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EC534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EC7B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EC888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EC91C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800ECA50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800ECC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800ECEB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800ED038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800ED170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800ED2B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800ED3A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800ED9E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EDA88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EDAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EDDE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EDFA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EE134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EE1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EE274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EE354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EE444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EE6F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EE7A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EEA50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EEE30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EF250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EF6AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EF914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EF990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EFA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EFB6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EFE20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800EFECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F0178.s")

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
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (sp4->unk132 == 0) {
        sp4->unk132 = (u8) (sp4->unk132 + 1);
        sp4->unkAA = 0xF;
    }
    sp4->Vel.z = 0.0f;
    sp4->Vel.x = sp4->Vel.y = sp4->Vel.z;
    sp4->unkAA = (s16) (sp4->unkAA - 1);
    if (sp4->unkAA <= 0) {
        sp4->unkA4 = 1;
        sp4->unk132 = 0U;
    }
}

void func_800F7800(void) {

    switch (gPlayerData[D_80177A60].unkA4) {
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
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
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
    func_80029D04(D_80177A60);
    sp1C->unkA8 = (s16) (s32) ((f32) sp1C->unkA8 - sp1C->unk48);
    if (sp1C->unkA8 <= 0) {
        sp1C->unkB0 = 2;
        sp1C->unkA4 = (s16) sp1C->unkB0;
        sp1C->unk132 = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7D08.s")

void func_800F7E2C(void) {
    if (D_80177A64 == 1) {
        gPlayerData[D_80177A60].unkA4 = 3;
        gPlayerData[D_80177A60].unk132 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7EA4.s")

void func_800F8028(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp2C = func_80027464(3, &D_80113790, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp2C != -1) {
        sp24 = (s32) gPlayerData[sp2C].unkE8[0];
        sp28 = (s32) gPlayerData[sp2C].unkE8[1];
        gPlayerData[sp24].Pos.x = gPlayerData[sp2C].Pos.x - 60.0f;
        gPlayerData[sp24].Pos.y = (f32) (gPlayerData[sp2C].Pos.y - 180.0f);
        gPlayerData[sp24].Pos.z = (f32) gPlayerData[sp2C].Pos.z;
        gPlayerData[sp28].Pos.x = gPlayerData[sp2C].Pos.x + 60.0f;
        gPlayerData[sp28].Pos.y = (f32) (gPlayerData[sp2C].Pos.y - 180.0f);
        gPlayerData[sp28].Pos.z = (f32) gPlayerData[sp2C].Pos.z;
    }
}

void func_800F82EC(void) {
    struct PlayerStruct* spC;
    s32 sp8;
    s32 sp4;

    spC = &gPlayerData[D_80177A60];
    if (D_80177A64 == 0) {
        sp8 = (s32) spC->unkE8[0];
        sp4 = (s32) spC->unkE8[1];
        if (sp8 != -1) {
            if (gPlayerData[sp8].unk104 != -1) {
                spC->unkA4 = 2;
                spC->unk132 = 0;
            }
        }
        if (sp4 != -1) {
            if  (gPlayerData[sp4].unk104 != -1) {
                spC->unkA4 = 2;
                spC->unk132 = 0;
            }
        }
    }
}

void func_800F8418(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1U;
        sp4->unkA6 = 0xA;
    }
    if ((sp4->unkE8[0] == -1) && (sp4->unkE8[1] == -1)) {
        if (sp4->unkA6 == 0) {
            sp4->unkA4 = 3;
            sp4->unk132 = 0U;
        } else {
            sp4->unkA6 = (s16) (sp4->unkA6 - 1);
        }
    }
}

void func_800F84F8(void) {
    struct PlayerStruct* sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1U;
        sp20 = (s32) sp24->unkE8[0];
        sp1C = (s32) sp24->unkE8[1];
        if ((sp20 != -1)) {
            if (gPlayerData[sp20].unk104 != -1) {
                func_800281A4(D_80177A60, 0);
                func_8002B0E4(sp20);
            }
        }
        if ((sp1C != -1)) {
            if (gPlayerData[sp1C].unk104 != -1) {
                func_800281A4(D_80177A60, 1);
                func_8002B0E4(sp1C);
            }
        }
    }
    sp24->unkA4 = 1;
    sp24->unk132 = 0U;
}

void func_800F8660(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1U;
        func_80029EF8(D_80177A60, 0.0f, 2.0f);
    }
    if (func_80029F58(D_80177A60, 0.0f, 0.0f, -60.0f, 60.0f) == 1) {
        sp24->unkA4 = 4;
    }
}

void func_800F8720(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1U;
    }
    sp4->Vel.z = 0.0f;
    sp4->Vel.x = sp4->Vel.y = sp4->Vel.z;
}

void func_800F87B4(void) {

    switch (gPlayerData[D_80177A60].unkA4) {
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
    switch(gPlayerData[D_80177A60].unkA4) {
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
    func_80027464(1, &D_801137D8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
}

void func_800F9120(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if ((D_80177A64 == 1) && (sp4->unkA4 == 1)) {
        sp4->unkA4 = 2;
        sp4->unk132 = 0;
    }
}

void func_800F91A4(void) {
    struct PlayerStruct* sp2C;

    sp2C = &gPlayerData[D_80177A60];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = (u8) (sp2C->unk132 + 1);
        func_8001C0EC(D_80177A60, 0, 0, 0x6A, &D_8011BA88);
    }
    func_8001B6BC(D_80177A60, 0, 0);
    sp2C->Vel.z = 0.0f;
    sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z;
}

void func_800F9294(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->unk44 = 0.0f;
        sp24->unk3C = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk40 = 90.0f;
        sp24->unkA6 = 0;
        func_800175F0(D_80177A60, 0, 0x2D, -1, 0);
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
    func_80029C40(D_80177A60);
    func_80029D04(D_80177A60);
    if (sp24->unk48 == 0.0f) {
        sp24->unkA4 = 3;
        sp24->unk132 = 0U;
    }
}

void func_800F94A8(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        sp1C->unk44 = 0.0f;
        sp1C->unk3C = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unk40 = 90.0f;
        sp1C->unkA6 = 0;
    }
    func_8001B6BC(D_80177A60, 0, 0);
    func_80029C40(D_80177A60);
    func_80029D04(D_80177A60);
    if (sp1C->unkA6 >= 0x1E) {
        sp1C->unkA4 = 4;
        sp1C->unk132 = 0U;
    } else {
        sp1C->unkA6 = (s16) (sp1C->unkA6 + 1);
    }
}

void func_800F95F4(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
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
    func_8001B6BC(D_80177A60, 0, 0.0f);
    func_80029C40(D_80177A60);
    func_80029D04(D_80177A60);
    if (sp1C->unk48 == 0.0f) {
        sp1C->unkA4 = 1;
        sp1C->unk132 = 0U;
    }
}

void func_800F9800(void) {

    switch (gPlayerData[D_80177A60].unkA4) {
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
    struct PlayerStruct* sp24;
    s32 sp20;

    sp20 = func_80027464(1, &D_801137E4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp20 != -1) {
        sp24 = &gPlayerData[sp20];
        sp24->unkE4 = (s16) D_80165100->unk0;
        if (func_80026260(D_8016519C) == 1) {
            if (sp24->unkE4 == 0x4D) {
                sp24->unkE4 = 0x4E;
            } else {
                sp24->unkE4 = 0x4D;
            }
            sp24->unkA6 = 1;
        }
        if (sp24->unkE4 == 0x4D) {
            sp24->Pos.y = (f32) (sp24->Pos.y + 180.0f);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F9A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F9C4C.s")

void func_800F9CB8(void) {
    struct PlayerStruct* sp24;
    s32 sp20;

    sp20 = func_80027464(1, &D_801137F0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp20 != -1) {
        sp24 = &gPlayerData[sp20];
        sp24->unkE4 = (s16) D_80165100->unk0;
        if (func_80026260(D_8016519C) == 1) {
            if (sp24->unkE4 == 0x4F) {
                sp24->unkE4 = 0x50;
            } else {
                sp24->unkE4 = 0x4F;
            }
            sp24->unkA6 = 1;
        }
    }
}

void func_800F9DE0(void) {
    struct PlayerStruct* sp24;
    s32 sp20;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1U;
        if (sp24->unkE4 == 0x4F) {
            sp20 = 1;
        } else {
            sp20 = 0;
        }
        func_8001C0EC(D_80177A60, 0, sp20, 0xBF, &D_8011BA8C);
        func_8001BBDC(D_80177A60, 1);
    }
    if (sp24->unkA6 == 0) {
        if (sp24->unkE4 == 0x4F) {
            if (func_8002A1FC(D_80177A60, 360.0f) == 0) {
                sp24->unkA6 = 1;
                sp24->unkA8 = 1;
                func_800175F0(D_80177A60, 0, 0x31, -1, 0);
            }
        } else if (func_8002A1FC(D_80177A60, 360.0f) != 0) {
            sp24->unkA6 = 1;
            sp24->unkA8 = 1;
            func_800175F0(D_80177A60, 0, 0x31, -1, 0);
        }
    }
    if (sp24->unkA8 == 1) {
        sp24->unkA8 = 2;
        if (sp24->unkE4 == 0x4F) {
            sp20 = 1;
        } else {
            sp20 = 0;
        }
        func_8001C0EC(D_80177A60, 0, sp20, 0xBF, &D_8011BA8C);
        func_8001BBDC(D_80177A60, 0);
    } else if ((sp24->unkA8 == 2) && (func_8001B44C(D_80177A60, 0) != 0)) {
        sp24->unkA8 = 0;
        func_8001BBDC(D_80177A60, 1);
        func_800261E8(D_80177A60, 1);
        if (sp24->unkE4 == 0x4F) {
            func_8001C0EC(D_80177A60, 0, 0, 0xBF, &D_8011BA8C);
            sp24->unkE4 = 0x50;
        } else {
            func_8001C0EC(D_80177A60, 0, 1, 0xBF, &D_8011BA8C);
            sp24->unkE4 = 0x4F;
        }
    }
}

void func_800FA0DC(void) {
    if (gPlayerData[D_80177A60].unkA4 == 1) {
        goto stub;
        stub:;
        func_800F9DE0();
        goto stub2;
        stub2:;
    }
}

void func_800FA148(void) {
    func_80027464(2, &D_801137FC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
}

void func_800FA1C0(void) {
    if (D_80177A64 == 0) {
        gPlayerData[D_80177A60].unkA4 = 3;
    } else if (D_80177A64 == 1) {
        gPlayerData[D_80177A60].unkA4 = 2;
    }
    gPlayerData[D_80177A60].unk132 = 0;
}

void func_800FA27C(void) {
    struct PlayerStruct* sp2C;
    s32 sp28;

    sp2C = &gPlayerData[D_80177A60];
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
        func_8001ABF4(sp28, 0, 3, &D_8011BB50.unk38);
        func_8001ABF4(sp28, 1, 3, &D_8011BB50.unk54);
    }
    if (sp2C->unkA6 != 0) {
        sp2C->unkA6 = (s16) (sp2C->unkA6 - 1);
        func_80029D04(D_80177A60);
    } else {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = (f32) sp2C->Vel.z;
    }
    if ((func_8001B44C(sp28, 3) != 0) && (sp2C->unkA6 == 0)) {
        if (sp2C->unkA8 != 0) {
            func_800281A4(D_80177A60, 0);
            func_8002B0E4(sp28);
            func_8002B0E4(D_80177A60);
        } else {
            func_8001BBDC(sp28, 1);
            func_8001ABF4(sp28, 0, 3, &D_8011BB50);
            func_8001ABF4(sp28, 1, 3, &D_8011BB50.Rot.y);
            sp2C->unkA4 = 1;
        }
    }
}

void func_800FA4D4(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
    if (sp1C->unk132 == 0) {
        sp1C->unkA8 = 1;
    }
    func_800FA27C();
}

void func_800FA54C(void) {
    struct PlayerStruct* sp34;
    s32 sp30;

    sp34 = &gPlayerData[D_80177A60];
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

    switch (gPlayerData[D_80177A60].unkA4) {
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
        gPlayerData[sp24].unk40 = 270.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800FA888.s")

void func_800FAA88(void) {
    struct PlayerStruct* sp2C;

    sp2C = &gPlayerData[D_80177A60];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1U;
        sp2C->unk40 = func_80015538(sp2C->unk40, 180.0f);
        sp2C->unkA8 = 0xF0;
        sp2C->unk48 = (f32) ((s16) sp2C->unkA8 / 4);
        sp2C->unk44 = 0.0f;
        sp2C->unk3C = (f32) sp2C->unk44;
        func_800175F0(D_80177A60, 0, 0x31, -1, 0);
    }
    if (sp2C->unkA8 <= 0) {
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.y = (f32) sp2C->Vel.z;
        func_8002B0E4(D_80177A60);
    } else {
        func_80029D04(D_80177A60);
        sp2C->unkA8 = (s16) (s32) ((f32) sp2C->unkA8 - sp2C->unk48);
    }
}

void func_800FAC60(void) {
    switch (gPlayerData[D_80177A60].unkA4) {
    case 1:
        func_800FA888();
        break;
    case 2:
        func_800FAA88();
        break;
    }
}
