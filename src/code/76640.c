#include <ultra64.h>
#include "../boot/1050.h"

// RODATA START unk_FF0F0_rodata

extern f64 D_8010CD50;

extern f64 D_8010CD60;
extern f64 D_8010CD68;
extern f64 D_8010CD70;
extern f64 D_8010CD78;

extern f64 D_8010CD58;

extern struct Code_Extra_Entry D_8010CC68[];
extern u16 *_603530_ROM_START;
extern u16 *_610A40_ROM_START;
extern u16 *_613370_ROM_START;
extern u16 *_6165A0_ROM_START;
extern u16 *_618410_ROM_START;
extern u16 *_61A940_ROM_START;
extern u16 *_620560_ROM_START;
extern u16 *_626CF0_ROM_START;
extern u16 *_627030_ROM_START;
extern u16 *_627330_ROM_START;
extern u16 *_628770_ROM_START;
extern u16 *_628B10_ROM_START;
extern u16 *_62C280_ROM_START;
extern u16 *_62CB20_ROM_START;
extern u16 *_62D750_ROM_START;
extern u16 *_6407D0_ROM_START;
extern u16 *_640F90_ROM_START;
extern u16 *_6414B0_ROM_START;
extern u16 *_6419D0_ROM_START;
extern u16 *_641EC0_ROM_START;

extern u8 D_8010CBE0[];
extern s32 D_8010CBE8;
extern s32 D_8010CBEC[];

// RODATA END

s32 func_80084120(f32 arg0, f32 arg1, f32 arg2)
{
    f32 sp4;

    sp4 = arg1 - arg0;
    if (sp4 < 0.0f)
    {
        sp4 += 360.0f;
    }
    if ((sp4 < arg2) || ((360.0f - arg2) < sp4))
    {
        return 0;
    }
    if (sp4 >= 180.0f)
    {
        return -1;
    }
    return 1;
}

void func_800841E8(void) {
    if ((gCurrentLevel == MAP_MAGMA_LAKE) || (gCurrentLevel == MAP_MAGMA_DAM)) {
        D_8016E110 = 2;
        D_8016E112 = 0x3C;
    }
    else
    {
        D_8016E110 = 0;
        D_8016E112 = 0;
    }
    D_8016E115 = 0;
}

void func_8008424C(void)
{
    if ((gCurrentLevel == 0x28) || (gCurrentLevel == 0x29))
    {
        if (D_8016E110 == 1)
        {
            D_8016E112 = 0xB4;
        }
        else if (D_8016E110 == 2)
        {
            D_8016E112 = 0x3C;
        }
    }
}

void func_800842C0(void)
{
    if (D_8016E110 == 1)
    {
        if (D_8016E112 != 0)
        {
            D_8016E112 -= 1;
        }
        if ((D_8016E112 == 1) || (D_8016E112 == 0xF) || (D_8016E112 == 0x1E) || (D_8016E112 == 0x2D))
        {
            func_800178D4(-1, 0, 0x28, -1, 0);
        }
    }
    else if (D_8016E110 == 2)
    {
        if (D_8016E112 == 0)
        {
            D_8016E110 = 1;
            D_8016E112 = 0xB4;
        }
        else
        {
            D_8016E112 -= 1;
        }
    }
}

void func_800843CC(f32 arg0, f32 arg1, f32 arg2)
{
    func_80067748(arg0, arg1, arg2);
    func_800670E8();
    func_80068CC4(arg0, arg1, arg2);
    func_80069314();
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80084430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80084BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80085424.s")

void func_800857B0(void)
{
    func_80085424();
    gObjects[D_80165270].unkA6 = 1;
}

void func_80085804(void)
{
    func_80085424();
    gObjects[D_80165270].unkA6 = 1;
    gObjects[D_80165270].unkB6 = 1;
}

void func_80085884(void)
{
    s32 sp1C;
    s32 sp18;

    if (D_8016E238 == 0)
    {
        if (D_80165270 != -1)
        {
            if ((gObjects[D_80165270].unkA4 == 0) || (gObjects[D_80165270].unkE4 != D_80165280))
            {
                sp1C = -1;
            }
            else
            {
                sp1C = (s32)D_80165270;
            }
        }
        else
        {
            if ((gObjects[D_8016E2A8].unkA4 == 0) || (gObjects[D_8016E2A8].unkE4 != D_8016E2B8))
            {
                sp1C = -1;
            }
            else
            {
                sp1C = (s32)D_8016E2A8;
            }
        }
        if (sp1C != -1)
        {
            D_80124D90[gObjects[sp1C].unkE4].routine3();
        }
    }
    else
    {
        sp18 = D_8016E240 - 2;
        if (D_801779B0[sp18] != -1)
        {
            if ((gObjects[D_801779B0[sp18]].unkA4 == 0) || gObjects[D_801779B0[sp18]].unkE4 != D_801779C0[sp18])
            {
                sp1C = -1;
            }
            else
            {
                sp1C = D_801779B0[sp18];
            }
        }
        else
        {
            sp1C = -1;
        }
        if (sp1C != -1)
        {
            D_80124D90[gObjects[sp1C].unkE4].routine3();
        }
    }
}

void func_80085B34(f32 arg0, f32 arg1)
{
    s32 sp3C;

    func_800843CC(gPlayerObject->Pos.x + arg0, gPlayerObject->Pos.y, gPlayerObject->Pos.z + arg1);
    sp3C = D_801776E0 & 1;
    D_801651A8 = D_801776E0;
    D_801651AC = D_801776F0[sp3C];
    D_801651B0 = D_80177700[sp3C];
    D_801651B4 = D_80177710[sp3C];
    D_801651B8 = D_80177720[sp3C];
    D_801651BC = D_80177730[sp3C];
    D_801651C0 = D_80177760[sp3C];
    D_801651C4 = gPlayerObject->Pos.x + arg0;
    D_801651C8 = gPlayerObject->Pos.y;
    D_801651CC = gPlayerObject->Pos.z + arg1;
    D_801651D0 = gPlayerObject->unk3C;
    D_801651D4 = func_80015634(gActiveContStickX, -gActiveContStickY);
    func_80016A80(D_801651AC,
                  D_801651B0, D_801651B4, D_801651B8,
                  &D_801651D8[0], &D_801651D8[1], &D_801651D8[2], &D_801651D8[3]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80085D54.s")

void func_80086AD0(void)
{
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    s32 sp20;
    UNUSED s32 sp30;

    D_8016E080 = 0;
    sp2C = gPlayerObject->Pos.x;
    sp28 = gPlayerObject->Pos.y;
    sp24 = gPlayerObject->Pos.z;
    if (D_8016523E == 4)
    {
        sp28 = (f32)((f64)sp28 - D_8010CD50);
    }
    func_800843CC(sp2C, sp28, sp24);
    sp20 = D_801776E0 & 1;
    if (D_80177740[sp20] == 0xFF)
    {
        return;
    }
    else if (D_80177740[sp20] == 0xF8)
    {
        if (sp28 <= D_80177760[sp20])
        {
            D_8016E080 = 2;
        }
    }
    else if (D_80177740[sp20] == 0xF7)
    {
        if (sp28 <= D_80177760[sp20])
        {
            D_8016E080 = 1;
        }
    }
    else if (((D_80177740[sp20] == 0xF5) || (D_80177740[sp20] == 0xD9)) && (sp28 <= D_80177760[sp20]))
    {
        if (D_80177750[sp20] == 0)
        {
            D_8016E080 = 3;
        }
        else if (D_80177750[sp20] == 1)
        {
            D_8016E080 = 4;
        }
        else
        {
            D_8016E080 = 5;
        }
    }
}

void func_80086D50(void)
{
    Mtx_t sp120;
    Mtx_t spE0;
    Mtx_t spA0;
    Mtx_t sp60;
    Mtx_t sp20;

    guTranslateF((f32(*)[4]) & sp120[0], gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
    guScaleF((f32(*)[4]) & spE0[0], gPlayerObject->Scale.x, gPlayerObject->Scale.y, gPlayerObject->Scale.z);
    guRotateF((f32(*)[4]) & spA0[0], gPlayerObject->Rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF((f32(*)[4]) & sp60[0], gPlayerObject->Rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF((f32(*)[4]) & sp20[0], gPlayerObject->Rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF((f32(*)[4]) & sp20[0], (f32(*)[4]) & sp60[0], (f32(*)[4]) & sp20[0]);
    guMtxCatF((f32(*)[4]) & sp20[0], (f32(*)[4]) & spA0[0], (f32(*)[4]) & sp20[0]);
    guMtxCatF((f32(*)[4]) & sp20[0], (f32(*)[4]) & spE0[0], (f32(*)[4]) & sp20[0]);
    guMtxCatF((f32(*)[4]) & sp20[0], (f32(*)[4]) & sp120[0], (f32(*)[4])D_80177550);
}

void func_80086E70(f32 *arg0, f32 *arg1, f32 *arg2)
{
    guMtxXFMF((f32(*)[4])D_80177550, *arg0, *arg1, *arg2, arg0, arg1, arg2);
}

void func_80086ECC(void)
{
    Mtx_t sp78;
    Mtx_t sp38;
    f32 sp34;

    if (gPlayerArmWindObject->unkA4 == 0)
    {
        return;
    }

    if (gPlayerArmWindObject->unkE4 == 0x2A8)
    {
        if (gPlayerArmWindObject->unkA4 == 1)
        {
            gPlayerArmWindObject->Pos.x = gPlayerObject->Pos.x;
            gPlayerArmWindObject->Pos.y = gPlayerObject->Pos.y;
            gPlayerArmWindObject->Pos.z = gPlayerObject->Pos.z;
            gPlayerArmWindObject->Rot.y = gPlayerObject->Rot.y;
        }
        else if (gPlayerArmWindObject->unkA4 == 2)
        {
            gPlayerArmWindObject->Pos.x = gPlayerObject->Pos.x;
            gPlayerArmWindObject->Pos.y = gPlayerObject->Pos.y;
            gPlayerArmWindObject->Pos.z = gPlayerObject->Pos.z;
            gPlayerArmWindObject->Rot.y = gPlayerObject->Rot.y;
        }
    }
    else if (gPlayerArmWindObject->unkE4 == 0x2A9)
    {
        if (gPlayerArmWindObject->unkA4 == 1)
        {
            gPlayerArmWindObject->Pos.x = gPlayerObject->Pos.x;
            gPlayerArmWindObject->Pos.y = gPlayerObject->Pos.y;
            gPlayerArmWindObject->Pos.z = gPlayerObject->Pos.z;
            gPlayerArmWindObject->Rot.y = gPlayerObject->Rot.y;
        }
    }
    else if (gPlayerArmWindObject->unkE4 == 0x2AE)
    {
        if (gPlayerArmWindObject->unkA4 == 1)
        {
            gPlayerArmWindObject->Pos.x = gPlayerObject->Pos.x;
            gPlayerArmWindObject->Pos.y = gPlayerObject->Pos.y - 40.0f;
            gPlayerArmWindObject->Pos.z = gPlayerObject->Pos.z;
            gPlayerArmWindObject->Rot.y = gPlayerObject->Rot.y;
            if (gPlayerArmWindObject->Scale.x < 1.0f)
            {
                gPlayerArmWindObject->Scale.x = gPlayerArmWindObject->Scale.x + D_8010CD58;
                gPlayerArmWindObject->Scale.y = gPlayerArmWindObject->Scale.z = gPlayerArmWindObject->Scale.x;
            }
            if (D_8016E21C < 0x5A)
            {
                func_8001BB34(1, D_8016E21C & 1);
            }
            else
            {
                func_8001BB34(1, 0);
            }
        }
    }
    else if (gPlayerArmWindObject->unkE4 == 0x2AA)
    {
        if (gPlayerArmWindObject->unkA4 == 1)
        {
            gPlayerArmWindObject->Pos.x = gPlayerObject->Pos.x;
            gPlayerArmWindObject->Pos.y = gPlayerObject->Pos.y;
            gPlayerArmWindObject->Pos.z = gPlayerObject->Pos.z;
            gPlayerArmWindObject->Rot.y = gPlayerObject->Rot.y;
            if (func_8001B44C(1, 3) != 0)
            {
                func_8001B6BC(1, 3, 120.0f);
            }
            func_8001AD6C(1);
        }
    }
    else if (gPlayerArmWindObject->unkE4 == 0x2AB)
    {
        if (gPlayerArmWindObject->unkA4 == 1)
        {
            guRotateF((f32(*)[4]) & sp78[0], gPlayerObject->Rot.y, 0.0f, 1.0f, 0.0f);
            guTranslateF((f32(*)[4]) & sp38[0], gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
            guMtxCatF((f32(*)[4]) & sp78[0], (f32(*)[4]) & sp38[0], (f32(*)[4]) & sp78[0]);
            guMtxXFMF((f32(*)[4]) & sp78[0], 0.0f, 130.0f, -18.6f, &gPlayerArmWindObject->Pos.x, &gPlayerArmWindObject->Pos.y, &gPlayerArmWindObject->Pos.z);
            gPlayerArmWindObject->Rot.y = func_80015538(gPlayerArmWindObject->Rot.y, 50.0f);
        }
    }
    else if (gPlayerArmWindObject->unkE4 == 0x2AC)
    {
        if (gPlayerArmWindObject->unkA4 == 1)
        {
            if (gPlayerObject->unkA4 == 0x26D)
            {
                sp34 = func_8001B62C(1, 0);
                if (sp34 < 50.0f)
                {
                    gPlayerArmWindObject->Vel.y = 0.0f;
                }
                else
                {
                    gPlayerArmWindObject->Vel.y += 2.0f;
                    gPlayerArmWindObject->Pos.y -= gPlayerArmWindObject->Vel.y;
                }
            }
            else
            {
                gPlayerArmWindObject->Pos.x = gPlayerObject->Pos.x;
                gPlayerArmWindObject->Pos.y = gPlayerObject->Pos.y;
                gPlayerArmWindObject->Pos.z = gPlayerObject->Pos.z;
                gPlayerArmWindObject->Rot.y = gPlayerObject->Rot.y;
            }
        }
    }
    else if ((gPlayerArmWindObject->unkE4 == 0x2AD))
    {
        if (gPlayerArmWindObject->unkA4 == 1)
        {
            gPlayerArmWindObject->Pos.x = gPlayerObject->Pos.x;
            gPlayerArmWindObject->Pos.y = gPlayerObject->Pos.y;
            gPlayerArmWindObject->Pos.z = gPlayerObject->Pos.z;
            gPlayerArmWindObject->Rot.x = gPlayerObject->Rot.x;
            gPlayerArmWindObject->Rot.y = gPlayerObject->Rot.y;
            gPlayerArmWindObject->Rot.z = gPlayerObject->Rot.z;
            func_8001AD6C(1);
        }
    }
    func_8001CD20(1);
}

void func_80087694(void) {
    f32 spC;
    f32 sp8;
    f32 sp4;
    f32 sp0;

    if ((gActiveContStickX >= 10.0f) || (gActiveContStickX <= -10.0f)) {
        gObjects[0].Pos.x += gActiveContStickX / 1.0f;
    }
    if ((gActiveContStickY >= 10.0f) || (gActiveContStickY <= -10.0f)) {
        gObjects[0].Pos.z -= gActiveContStickY / 1.0f;
    }
    if (*gContCurrButton & 0x8000) {
        gObjects[0].Pos.y += 40.0f;
    }
    if (*gContCurrButton & 0x4000) {
        gObjects[0].Pos.y -= 40.0f;
    }
    if (((gActiveContStickX >= 10.0f) || (gActiveContStickX <= -10.0f) || (gActiveContStickY >= 10.0f) || (gActiveContStickY <= -10.0f))) {
        spC = (f32) ((f64) gActiveContStickX / D_8010CD60); 
        sp8 = (f32) ((f64) gActiveContStickY / D_8010CD68);
        sp4 = (f32) ((f64) gActiveContStickX / D_8010CD70);
        sp0 = (f32) -((f64) gActiveContStickY / D_8010CD78);

        if (((spC != 0.0)) || (sp8 != 0.0)) {
            gObjects[0].Rot.x = -sp4;
            gObjects[0].Rot.y = 0.0f;
            gObjects[0].Rot.z = -sp0;
        }
    }
}

void func_80087994(void)
{
    UNUSED s16 sp20;

    if ((gPlayerObject->unk108 >= 2) && (gPlayerObject->unk108 < 0x3D))
    {
        gPlayerObject->unk108 -= 1;
    }
    if (D_8016E0D0 != 0)
    {
        return;
    }
    if (D_8016523E == 0)
    {
        func_8028AA70();
    }
    else if (D_8016523E == 1)
    {
        func_802838DC();
    }
    else if (D_8016523E == 2)
    {
        func_802823A4();
    }
    else if (D_8016523E == 3)
    {
        func_80281314();
    }
    else if (D_8016523E == 4)
    {
        func_8028117C_code_extra_4();
    }
    else if (D_8016523E == 5)
    {
        func_802860F8();
    }
    else if (D_8016523E == 6)
    {
        func_80282F24();
    }
    func_80086D50();
    func_80086ECC();
}

void func_80087B1C(void)
{
    func_8001BB34(0, 0);
    func_8001BB34(1, 0);
    if (D_8016523E == 0)
    {
        func_8028ADB0();
    }
    else if (D_8016523E == 1)
    {
        func_80283A40();
    }
    else if (D_8016523E == 2)
    {
        func_802824DC();
    }
    else if (D_8016523E == 3)
    {
        func_802813E4();
    }
    else if (D_8016523E == 4)
    {
        func_802812AC();
    }
    else if (D_8016523E == 5)
    {
        func_80286374();
    }
    else if (D_8016523E == 6)
    {
        func_802831BC();
    }
    func_80086D50();
    func_80086ECC();
}

void func_80087C58(void)
{
    if (D_8016E0D0 == 0)
    {
        if ((gPlayerObject->unk108 >= 2) && (gPlayerObject->unk108 < 0x3D))
        {
            D_8016E250 += 1;
            if (D_8016E250 & 1)
            {
                return;
            }
        }
    }
    if (func_8001C1A8(0, 0) != 0)
    {
        func_8001838C();
        func_8001B014(0, 0);
        func_8001C384(0, 0);
    }
    if ((gPlayerArmWindObject->unkA4 != 0) && (func_8001C1A8(1, 0) != 0))
    {
        func_8001838C();
        func_8001B014(1, 0);
        func_8001C384(1, 0);
    }
}

void func_80087D70(void)
{
    if (func_8001C248(0, 3) != 0)
    {
        func_8001838C();
        func_8001B014(0, 3);
        func_8001C384(0, 3);
    }
    if ((gPlayerArmWindObject->unkA4 != 0) && (func_8001C248(1, 3) != 0))
    {
        func_8001838C();
        func_8001B014(1, 3);
        func_8001C384(1, 3);
    }
}

void func_80087E14(void)
{
    D_801651A4 = 0;
    D_801651A8 = 0;
    D_801651AC = 0;
    D_801651B0 = 0;
    D_801651B4 = 0;
    D_801651B8 = 0;
    D_801651BC = 0;
    D_801651C0 = 0.0f;
    D_801651C4 = 0.0f;
    D_801651C8 = 0.0f;
    D_801651CC = 0.0f;
    D_801651D0 = 0.0f;
    D_801651D4 = 0.0f;
    D_801651D8[0] = 0.0f;
    D_801651D8[1] = 0.0f;
    D_801651D8[2] = 0.0f;
    D_801651D8[3] = 0.0f;
    D_80165270 = -1;
    D_80165278 = -1;
    D_80165288 = 0.0f;
    D_8016C290 = 0.0f;
    D_8016CA98 = 0.0f;
    D_80165280 = 0;
    D_8016E094 = 0;
    D_8016E09C = 0;
    D_8016E0AC = 0;
    D_8016E0B4 = 0;
    D_8016E0D0 = 0;
    D_8016E0F8 = 0;
    D_80165250 = 0;
    D_80165260 = 0;
    D_80165268 = 0;
    D_80165246 = 0;
    if ((D_80177630 == 0) && (D_80177628 == 1))
    {
        D_80165258 = 1;
    }
    else
    {
        D_80165258 = 0;
    }
    D_8016E080 = 0;
    D_8016E088 = 0;
    D_8016E2D8 = 0;
    D_8016E090 = 0;
    D_80165242 = 0;
    D_80165248 = 0;
    D_8016E100 = 0;
    D_8016E108 = 0;
    D_8016E118 = 0;
    D_8016E21C = 0;
    D_8016E228 = 0;
    D_80165247 = 0;
    D_8016E318 = 0;
    D_8016E248 = 0;
    D_8016E348 = 0;
    D_8016E250 = 0;
    D_8016E2E8 = 0;
    D_8016E2F8 = 0;
    D_8016E120 = 0;
    D_8016E128 = 0;
    D_8016E130 = 0.0f;
    D_8016E138 = 0.0f;
    D_8016E1B4 = 0.0f;
    func_800841E8();
}

void func_80088094(void)
{
    gLifeCount = 1;
    gMaxHealth = 4;
    gHealthCount = gMaxHealth;
    gBombCount = 0;
    gFireCount = 0;
    gGemCount = 0;
}

void func_800880E4(void)
{
    gLifeCount = 3;
    gMaxHealth = 4;
    gHealthCount = gMaxHealth;
    gBombCount = 0;
    gFireCount = 0;
    gGemCount = 0;
}

void func_80088134(void)
{ // looks like the regular base stats
    gLifeCount = 3;
    gMaxHealth = 4;
    gHealthCount = gMaxHealth;
    gBombCount = 0;
    gFireCount = 0;
    gGemCount = 0;
}

void func_80088184(void)
{ // looks like the regular base stats
    gLifeCount = 3;
    gMaxHealth = 4;
    gHealthCount = gMaxHealth;
    gBombCount = 0;
    gFireCount = 0;
    gGemCount = 0;
}

void func_800881D4(void)
{
    gHealthCount = gMaxHealth;
    if (gFireCount != 0)
    {
        gFireCount -= 1;
    }
    else if (gBombCount != 0)
    {
        gBombCount -= 1;
    }
}

void func_80088248(s32 arg0)
{
    if (arg0 > 0)
    {
        gLifeCount += arg0;
        if ((s32)gLifeCount >= 99)
        {
            gLifeCount = 99;
        }
    }
    else if (gLifeCount != 0)
    {
        gLifeCount += arg0;
    }
}

void func_800882C8(void)
{
    D_80165238 = gLifeCount;
    D_80165239 = gHealthCount;
    D_8016523A = gMaxHealth;
    D_8016523B = gBombCount;
    D_8016523C = gFireCount;
    D_8016523D = gGemCount;
}

void func_80088338(void)
{
    gLifeCount = D_80165238;
    gHealthCount = D_80165239;
    gMaxHealth = D_8016523A;
    gBombCount = D_8016523B;
    gFireCount = D_8016523C;
    gGemCount = D_8016523D;
}

void func_800883A8(void)
{
    s32 FileSize;

    FileSize = D_8010CC68[D_8016523E].End_Addr - D_8010CC68[D_8016523E].Start_Addr;

    load_from_rom_to_addr(D_8010CC68[D_8016523E].Start_Addr, 0x80280000, FileSize);
    func_8001E954(FileSize + 0x80280000);

    if (D_8016523E == 0)
    {
        func_8001EB68(1, &_603530_ROM_START, &_610A40_ROM_START);
        func_8001EB68(2, &_626CF0_ROM_START, &_627030_ROM_START);
        func_8001EB68(3, &_627030_ROM_START, &_627330_ROM_START);
        func_8001EB68(4, &_627330_ROM_START, &_628770_ROM_START);
        func_8001EB68(8, &_62CB20_ROM_START, &_62D750_ROM_START);
        func_8001EB68(9, &_6407D0_ROM_START, &_640F90_ROM_START);
    }
    else if (D_8016523E == 1)
    {
        func_8001EB68(1, &_610A40_ROM_START, &_613370_ROM_START);
        func_8001EB68(0xA, &_640F90_ROM_START, &_6414B0_ROM_START);
    }
    else if (D_8016523E == 2)
    {
        func_8001EB68(1, &_613370_ROM_START, &_6165A0_ROM_START);
        func_8001EB68(7, &_62C280_ROM_START, &_62CB20_ROM_START);
        func_8001EB68(0xB, &_6414B0_ROM_START, &_6419D0_ROM_START);
    }
    else if (D_8016523E == 3)
    {
        func_8001EB68(1, &_6165A0_ROM_START, &_618410_ROM_START);
    }
    else if (D_8016523E == 4)
    {
        func_8001EB68(1, &_618410_ROM_START, &_61A940_ROM_START);
        func_8001EB68(5, &_628770_ROM_START, &_628B10_ROM_START);
        func_8001EB68(0xC, &_6419D0_ROM_START, &_641EC0_ROM_START);
    }
    else if (D_8016523E == 5)
    {
        func_8001EB68(1, &_61A940_ROM_START, &_620560_ROM_START);
    }
    else if (D_8016523E == 6)
    {
        func_8001EB68(1, &_620560_ROM_START, &_626CF0_ROM_START);
        func_8001EB68(6, &_628B10_ROM_START, &_62C280_ROM_START);
    }
}

void func_80088694(void)
{
    func_8001A928(0);
    func_8001A928(1);
    gPlayerObject->Pos.x = D_8016E438;
    gPlayerObject->Pos.y = D_8016E43C;
    gPlayerObject->Pos.z = D_8016E440;
    gPlayerObject->Rot.y = D_8016E444;
    gPlayerObject->unk3C = gPlayerObject->Rot.y;
    gPlayerObject->unk108 = 1;
    func_80087E14();
    func_8006828C();
    func_80085B34(0, 0);
    if (D_8016523E == 0)
    {
        func_8028AF38();
    }
    else if (D_8016523E == 1)
    {
        func_80283BD4();
    }
    else if (D_8016523E == 2)
    {
        func_80282698();
    }
    else if (D_8016523E == 3)
    {
        func_802814CC();
    }
    else if (D_8016523E == 4)
    {
        func_80281440();
    }
    else if (D_8016523E == 5)
    {
        func_80286508();
    }
    else
    {
        func_80283344();
    }
}

void func_8008884C(s32 arg0)
{
    func_8001A928(0);
    func_8001A928(1);
    func_8001BD44(0, 0, 0x10, gFileArray[0x223].ptr + D_80111880[arg0]);
    func_8001C0EC(0, 0, 0, 0x223, &D_80111888);
    gPlayerObject->unkE4 = 0x266;
    gPlayerObject->unkA4 = 1;
    func_80019448(0, 2, 0, 1);
    if (arg0 == 0)
    {
        func_8001ABF4(0, 0, 0, &D_80111A74);
        func_8001ABF4(0, 1, 0, &D_80111A74[0x3F]);
        func_8001ABF4(0, 2, 0, &D_80111A74[0x46]);
        func_8001ABF4(0, 3, 0, &D_80111A74[0x4D]);
    }
    else
    {
        func_8001ABF4(0, 0, 0, &D_80111A74[0x69]);
    }
}

void func_800889A8(void)
{
    func_8001E954((s32 *)0x80280000);
    func_8001EB68(0x223, &_9B5440_ROM_START, &_9BD180_ROM_START);
    func_8008884C(0);
    gPlayerObject->Pos.x = D_8016E438;
    gPlayerObject->Pos.y = D_8016E43C;
    gPlayerObject->Pos.z = D_8016E440;
    gPlayerObject->Rot.y = D_8016E444;
    gPlayerObject->unk3C = gPlayerObject->Rot.y;
    func_80087E14();
    func_8006828C();
    func_80085B34(0.0f, 0.0f);
}

void func_80088A88(s32 arg0)
{
    s32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    D_8016523E = (s8)arg0;
    func_8001EC04();
    for (sp24 = 0; sp24 < 1000000; sp24++)
    {
    }
    sp20 = gPlayerObject->Pos.x;
    sp1C = gPlayerObject->Pos.y;
    sp18 = gPlayerObject->Pos.z;
    func_800883A8();
    func_80088694();
    gPlayerObject->Pos.x = sp20;
    gPlayerObject->Pos.y = sp1C;
    gPlayerObject->Pos.z = sp18;
    func_8001EBE8();
}
