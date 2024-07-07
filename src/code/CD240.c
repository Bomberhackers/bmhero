#include "common.h"
#include "variables.h"

extern s32 func_8002B0E4(s32);
extern s32 func_80027464(s32, void*, f32, f32, f32, f32);
extern s32 func_8001ABF4(s32, s32, s32, void*);
extern s32 func_8002A1FC(s32, s32);
extern s32 func_8001B4AC(s32, s32);
extern s32 func_8001B754(s32, s32);
extern s32 func_8001C0EC(s32, s32, s32, s32, void*);
extern s32 func_80028FA0(s32);
extern s32 func_8002A8B4(s32, s32);
extern s32 func_800E3EE4();
extern f32 func_8002A46C(s32);
extern s32 func_80014E80(s32);
extern f32 func_80015538(f32, f32);
extern s32 func_80029018(s32, s32, s32, f32, f32, f32);
extern s32 func_800297DC();
extern s32 func_8002A0D0(s32, f32, f32, f32);
extern s32 func_8001B44C(s32, s32);
extern s32 func_800261E8(s32, s32);
extern s32 func_80026260(s32);
extern s32 func_80029F58(s32, f32, f32, s32, f32);
extern void func_800175F0(s32, s32, s32, s32, s32);
extern void func_8001B6BC(s32, s32, f32);
extern void func_8001BBDC(s32, s32);
extern void func_800281A4(s32, s32);
extern void func_80029824(s32, s32);
extern void func_80029D04(s32);
extern void func_80029B60(s32);
extern void func_80029C40(s32);
extern void func_80029EF8(s32, f32, s32);
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
extern struct PlayerStruct D_80118E9C;
extern UnkStruct80165100 D_801142F4;
extern struct PlayerStruct D_801137F0;
extern struct PlayerStruct D_80118EB4;
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
    sp34->RotY = (f32) sp34->unk3C;
    if (sp34->unkA8 == 0) {
        if (sp34->unkA6 < 0xF) {
            sp34->VelY = 1.0f;
            sp34->unkA6 = (s16) (sp34->unkA6 + 1);
        } else {
            sp34->unkA8 = (s16) (sp34->unkA8 + 1);
            sp34->unkA6 = 0;
        }
    } else if (sp34->unkA6 < 0xF) {
        sp34->VelY = -1.0f;
        sp34->unkA6 = (s16) (sp34->unkA6 + 1);
    } else {
        sp34->unkA8 = 0;
        sp34->unkA6 = 0;
    }
    func_80029C40(D_80177A60);
    if (func_80029018(D_80177A60, 4, 0x42700000, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(D_80177A60, func_800297DC());
    }
    if (func_8002A1FC(D_80177A60, 0x43F00000) != 0) {
        sp34->VelZ = 0.0f;
        sp34->VelX = (f32) sp34->VelZ;
        sp34->VelY = 0.0f;
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
    func_8002A8B4(D_80177A60, 0x40C00000);
    sp24->RotY = (f32) sp24->unk3C;
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
        sp24->VelZ = 0.0f;
        sp24->VelX = (f32) sp24->VelZ;
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
        sp4->VelZ = 0.0f;
        sp4->VelX = (f32) sp4->VelZ;
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
    if (func_8002A1FC(D_80177A60, 0x44070000) != 0) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0U;
    }
}

void func_800DB910(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = (u8) (sp1C->unk132 + 1);
        func_80029EF8(D_80177A60, 0.0f, 0x40800000);
    }
    sp1C->RotY = func_8002A46C(D_80177A60);
    sp1C->unk3C = (f32) sp1C->RotY;
    if (func_8002A0D0(D_80177A60, 0.0f, 0.0f, 0.0f) == 1) {
        sp1C->unkA4 = 3;
        sp1C->unk132 = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DBA0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DBB78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DBBA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DBCFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC07C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC4CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC5CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC66C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DC984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DCAFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DCD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DCD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DCE2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DCEE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DCFAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DD160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DD300.s")

void func_800DD690(void) {
    func_8002B0E4(D_80177A60);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DD6C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DD7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DD8A0.s")

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
    if (func_8002A1FC(D_80177A60, 0x44610000) != 0) {
        sp1C->unkA4 = 2;
        sp1C->unk132 = 0U;
    }
}

void func_800DDAA8(void) {
    struct PlayerStruct* sp24;

    sp24 = &gPlayerData[D_80177A60];
    if (sp24->unk132 == 0) {
        sp24->unk132 = (u8) (sp24->unk132 + 1);
        sp24->PosY = (f32) (sp24->PosY + 5.0f);
        func_8001C0EC(D_80177A60, 0, 1, 0x70, &D_80118FF4);
        func_8001ABF4(D_80177A60, 0, 0, &D_80119128);
        func_8001ABF4(D_80177A60, 1, 0, &D_80119128.RotY);
        func_8001B754(D_80177A60, 0);
        sp24->unk13A = 0;
    }
    if ((func_80028FA0(D_80177A60) != 0) && (((sp24->unk106 == 0xA1)) || (sp24->unk106 == 0xA3))) {
        func_800E3EE4();
        return;
    }
    func_8002A8B4(D_80177A60, 0x40C00000);
    sp24->RotY = (f32) sp24->unk3C;
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
        func_8001ABF4(D_80177A60, 1, 0, &D_80119128.RotY);
        sp24->unkA6 = 0;
        sp24->unkA8 = 0;
    }
    if ((func_80028FA0(D_80177A60) != 0) && (((sp24->unk106 == 0xA1)) || (sp24->unk106 == 0xA3))) {
        func_800E3EE4();
        return;
    }
    sp24->unk3C = func_8002A46C(D_80177A60);
    sp24->RotY = (f32) sp24->unk3C;
    if (func_8001B4AC(D_80177A60, 0) != 0) {
        sp24->unkA4 = 4;
        sp24->unk132 = 0U;
        sp24->unkB2 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DDE08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DE1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DE534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DE564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DE654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DE754.s")

void func_800DE7DC(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011436C, (f32) D_80165100->unk2, (f32) (D_80165100->unk4 + 5), (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gPlayerData[sp24].unk13A = 1;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DE894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DE95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DEB3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DECE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DF034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DF3D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DF704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DF734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DF81C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DF92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DF9A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DFC2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800DFDBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E0154.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E047C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E04AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E06E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E07DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E0938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E09D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E0C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E0DE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E119C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E1640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E1670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E1978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E1AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E1C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E1C9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E1F20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E2068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800E2400.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F770C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7E2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CD240/func_800F7EA4.s")

void func_800F8028(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp2C = func_80027464(3, &D_80113790, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp2C != -1) {
        sp24 = (s32) gPlayerData[sp2C].unkE8[0];
        sp28 = (s32) gPlayerData[sp2C].unkE8[1];
        gPlayerData[sp24].PosX = gPlayerData[sp2C].PosX - 60.0f;
        gPlayerData[sp24].PosY = (f32) (gPlayerData[sp2C].PosY - 180.0f);
        gPlayerData[sp24].PosZ = (f32) gPlayerData[sp2C].PosZ;
        gPlayerData[sp28].PosX = gPlayerData[sp2C].PosX + 60.0f;
        gPlayerData[sp28].PosY = (f32) (gPlayerData[sp2C].PosY - 180.0f);
        gPlayerData[sp28].PosZ = (f32) gPlayerData[sp2C].PosZ;
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
        func_80029EF8(D_80177A60, 0.0f, 0x40000000);
    }
    if (func_80029F58(D_80177A60, 0.0f, 0.0f, 0xC2700000, 60.0f) == 1) {
        sp24->unkA4 = 4;
    }
}

void func_800F8720(void) {
    struct PlayerStruct* sp4;

    sp4 = &gPlayerData[D_80177A60];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1U;
    }
    sp4->VelZ = 0.0f;
    sp4->VelX = sp4->VelY = sp4->VelZ;
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
    sp2C->VelZ = 0.0f;
    sp2C->VelX = sp2C->VelY = sp2C->VelZ;
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
            sp24->PosY = (f32) (sp24->PosY + 180.0f);
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
            if (func_8002A1FC(D_80177A60, 0x43B40000) == 0) {
                sp24->unkA6 = 1;
                sp24->unkA8 = 1;
                func_800175F0(D_80177A60, 0, 0x31, -1, 0);
            }
        } else if (func_8002A1FC(D_80177A60, 0x43B40000) != 0) {
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
        sp2C->VelZ = 0.0f;
        sp2C->VelX = sp2C->VelY = (f32) sp2C->VelZ;
    }
    if ((func_8001B44C(sp28, 3) != 0) && (sp2C->unkA6 == 0)) {
        if (sp2C->unkA8 != 0) {
            func_800281A4(D_80177A60, 0);
            func_8002B0E4(sp28);
            func_8002B0E4(D_80177A60);
        } else {
            func_8001BBDC(sp28, 1);
            func_8001ABF4(sp28, 0, 3, &D_8011BB50);
            func_8001ABF4(sp28, 1, 3, &D_8011BB50.RotY);
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
        func_8001ABF4(sp30, 1, 3, &D_8011BB50.RotY);
        sp34->unk40 = 270.0f;
        sp34->unk48 = 6.0f;
        sp34->unk44 = 0.0f;
        sp34->unk3C = (f32) sp34->unk44;
    }
    sp34->VelZ = 0.0f;
    sp34->VelX = sp34->VelY = sp34->VelZ;
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
        sp2C->VelZ = 0.0f;
        sp2C->VelX = sp2C->VelY = (f32) sp2C->VelZ;
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
