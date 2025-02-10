#include <ultra64.h>
#include "types.h"

// RODATA START unk_FF0F0_rodata


extern u8 D_8010CBD0[0x10];

extern u8 D_8010CBE0[8];

extern struct Vec2i D_8010CBE8[];

extern s32 D_8010CC68[7][2];

// RODATA END

extern u8 _603530_ROM_START[];
extern u8 _603530_ROM_END[];
extern u8 _610A40_ROM_START[];
extern u8 _610A40_ROM_END[];
extern u8 _613370_ROM_START[];
extern u8 _613370_ROM_END[];
extern u8 _6165A0_ROM_START[];
extern u8 _6165A0_ROM_END[];
extern u8 _618410_ROM_START[];
extern u8 _618410_ROM_END[];
extern u8 _61A940_ROM_START[];
extern u8 _61A940_ROM_END[];
extern u8 _620560_ROM_START[];
extern u8 _620560_ROM_END[];
extern u8 _626CF0_ROM_START[];
extern u8 _626CF0_ROM_END[];
extern u8 _627030_ROM_START[];
extern u8 _627030_ROM_END[];
extern u8 _627330_ROM_START[];
extern u8 _627330_ROM_END[];
extern u8 _628770_ROM_START[];
extern u8 _628770_ROM_END[];
extern u8 _628B10_ROM_START[];
extern u8 _628B10_ROM_END[];
extern u8 _62C280_ROM_START[];
extern u8 _62C280_ROM_END[];
extern u8 _62CB20_ROM_START[];
extern u8 _62CB20_ROM_END[];
extern u8 _62D750_ROM_START[];
extern u8 _62D750_ROM_END[];
extern u8 _6407D0_ROM_START[];
extern u8 _6407D0_ROM_END[];
extern u8 _640F90_ROM_START[];
extern u8 _640F90_ROM_END[];
extern u8 _6414B0_ROM_START[];
extern u8 _6414B0_ROM_END[];
extern u8 _6419D0_ROM_START[];
extern u8 _6419D0_ROM_END[];
extern u8 _641EC0_ROM_START[];
extern u8 _641EC0_ROM_END[];

//.bss
extern f32 D_801779D0[];
extern f32 D_801779E8[];
extern f32 D_80177A00[];

void func_80078168(f32, f32, f32);

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

void func_800841E8(void)
{
    if ((gCurrentLevel == MAP_MAGMA_LAKE) || (gCurrentLevel == MAP_MAGMA_DAM))
    {
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

s32 func_80084430(f32 arg0, f32 arg1, f32 arg2)
{
    s32 spAC;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    UNUSED s32 sp98;
    f32 sp94;
    u8 sp93;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    s32 sp6C;
    s32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;

    func_800843CC(arg0, arg1, arg2);
    spAC = D_801776E0 & 1;
    sp93 = D_801776E0;
    spA8 = D_801776F0[spAC];
    spA4 = D_80177700[spAC];
    spA0 = D_80177710[spAC];
    sp9C = D_80177720[spAC];
    sp98 = D_80177730[spAC];
    sp94 = D_80177760[spAC];
    func_80016A80(D_801651AC,
                  D_801651B0,
                  D_801651B4,
                  D_801651B8,
                  &sp8C,
                  &sp88,
                  &sp84,
                  &sp80);
    func_80016A80(spA8, spA4, spA0, sp9C, &sp7C, &sp78, &sp74, &sp70);

    if ((func_8001608C(D_801651AC,
                       D_801651B0,
                       D_801651B4,
                       D_801651B8,
                       D_801776F0[spAC],
                       D_80177700[spAC],
                       D_80177710[spAC],
                       D_80177720[spAC]) != 0) &&
        (sp80 < 60.0f))
    {
        return 0;
    }
    if (sp93 == 0)
    {
        if ((sp80 < 60.0f) && (sp70 < 60.0f))
        {
            if ((D_801651C0 - sp94) < 30.0f)
            {
                return 1;
            }
            if (((sp80 != 0.0f) || (sp70 != 0.0f)) && ((func_80016714(D_801651AC, D_801651B0, D_801651B4, D_801651B8, spA8, spA4, spA0, sp9C, &sp64, &sp60, &sp5C, &sp58), (sp64 != 0.0f)) || (sp60 != 0.0f) || (sp5C != 0.0f) || (sp58 != 0.0f)))
            {
                sp6C = func_800162F0(D_801651C4, D_801651CC, sp64, sp60, sp5C, sp58);
                sp68 = func_800162F0(arg0, arg2, sp64, sp60, sp5C, sp58);
                if (sp6C != sp68)
                {
                    return 1;
                }
            }
        }
        return 3;
    }
    else
    {

        if ((sp80 < 60.0f) && (sp70 < 60.0f))
        {
            if ((sp94 - D_801651C0) < 30.0f)
            {
                return 2;
            }
            if (((sp80 != 0.0f) || (sp70 != 0.0f)) && ((func_80016714(D_801651AC, D_801651B0, D_801651B4, D_801651B8, spA8, spA4, spA0, sp9C, &sp64, &sp60, &sp5C, &sp58), (sp64 != 0.0f)) || (sp60 != 0.0f) || (sp5C != 0.0f) || (sp58 != 0.0f)))
            {
                sp6C = func_800162F0(D_801651C4, D_801651CC, sp64, sp60, sp5C, sp58);
                sp68 = func_800162F0(arg0, arg2, sp64, sp60, sp5C, sp58);
                if (sp6C != sp68)
                {
                    return 2;
                }
            }
        }

        return 4;
    }
}

void func_80084BD8(f32 *arg0, s32 arg1, f32 arg2, f32 arg3)
{
    f32 player_pos_x;
    f32 player_pos_y;
    f32 player_pos_z;
    f32 player_vel_x;
    f32 player_vel_y;
    f32 player_vel_z;
    s32 sp34;
    s32 sp30;
    u8 sp2F;
    u8 sp2E;
    u8 sp2D;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    f32 sp1C;
    f32 sp18;

    player_pos_x = gPlayerObject->Pos.x;
    player_pos_y = gPlayerObject->Pos.y;
    player_pos_z = gPlayerObject->Pos.z;
    player_vel_x = gPlayerObject->Vel.x;
    player_vel_y = gPlayerObject->Vel.y;
    player_vel_z = gPlayerObject->Vel.z;
    player_pos_y += player_vel_y;
    sp34 = 0;

    if (arg1 == 0)
    {
        func_800843CC(arg0[0] + player_pos_x, player_pos_y + arg2, arg0[5] + player_pos_z);
        if (D_801776E0 & 1)
        {
            player_pos_y = D_80177760[0] - (arg2 + 1.0f);
        }
        func_800843CC(arg0[0] + player_pos_x, player_pos_y + arg3, arg0[5] + player_pos_z);
        if ((D_801776E0 & 1))
        {
            player_pos_y = D_80177760[1] - arg3;
        }
        if (D_80177760[D_801776E0 & 1] == player_pos_y)
        {
            sp34 = 1;
        }
    }
    player_pos_x += player_vel_x;
    player_pos_z += player_vel_z;
    if (arg1 == 1)
    {
    }
    else
    {
        D_8016E09C = 0;
        D_8016E0A4 = 0;

        sp20 = 8;
        sp2D = 0;

        for (sp30 = 0; sp30 < 0x1E; sp30++)
        {
            sp2F = 0;
            sp2E = 0;
            for (sp28 = 0; sp28 < 8; sp28++)
            {
                sp24 = func_80084430(arg0[sp28 * 3 + 0] + player_pos_x, arg0[sp28 * 3 + 1] + player_pos_y, arg0[sp28 * 3 + 2] + player_pos_z);
                if (sp24 == 4)
                {
                    sp2F = sp2F | D_8010CBE0[sp28];
                    if (D_801776E4 != 0)
                    {
                        sp2E = sp2E | D_8010CBE0[sp28];
                    }
                }
            }
            sp2F = (sp2F & 0xF) | ((s32)sp2F >> 4);
            if (sp30 == 0)
            {
                D_8016E09C = (s16)sp2F;
                D_8016E0A4 = (sp2E & 0xF) | ((s32)sp2E >> 4);
            }
            if ((sp2F == 0) && ((sp30 == 0) || (sp20 == 1)))
            {
                break;
            }
            if (sp2F == 0)
            {
                player_pos_x = sp1C;
                player_pos_z = sp18;
                sp20 = sp20 / 2;
                sp2F = sp2D;
            }
            else if ((sp2D != sp2F) && (sp30 != 0) && ((sp20 / 2) != 0))
            {
                sp2F = sp2D;
                sp20 = sp20 / 2;
                player_pos_x = sp1C;
                player_pos_z = sp18;
            }
            sp1C = player_pos_x;
            sp18 = player_pos_z;
            sp2D = sp2F;
            player_pos_x = player_pos_x + D_8010CBE8[sp2F].x * sp20;
            player_pos_z = player_pos_z + D_8010CBE8[sp2F].y * sp20;
        }
    }
    if ((D_8016523E == 0) || (D_8016523E == 5) || (D_8016523E == 6))
    {
        D_8016E0B4 = D_8016E0AC;
        D_8016E0AC = 0;
        sp24 = func_80084430(player_pos_x, player_pos_y, player_pos_z);
        if (sp24 < 3)
        {
            if ((D_801651A4 & 1) && (gPlayerObject->Vel.y > 0.0f))
            {
                func_800843CC(player_pos_x, player_pos_y, player_pos_z);
                if (D_801776E0 & 1)
                {
                    player_pos_y = D_80177760[D_801776E0 & 1] + gPlayerObject->Vel.y;
                }
            }
            else if (sp34 != 0)
            {
                func_800843CC(player_pos_x, player_pos_y, player_pos_z);
                if (!(D_801776E0 & 1))
                {
                    player_pos_y = D_80177760[0];
                }
                D_8016E0AC = 1;
            }
        }
        func_800843CC(player_pos_x, player_pos_y, player_pos_z);
        D_80165278 = D_80165270;
        D_80165270 = (s16)D_80177770[D_801776E0 & 1];
        if (D_80165270 != -1)
        {
            if (D_80177760[D_801776E0 & 1] == player_pos_y)
            {
                D_80165280 = gObjects[D_80165270].unkE4;
                D_80165288 = player_pos_x - gObjects[D_80165270].Pos.x;
                D_8016C290 = player_pos_y - gObjects[D_80165270].Pos.y;
                D_8016CA98 = player_pos_z - gObjects[D_80165270].Pos.z;
            }
            else
            {
                D_80165270 = -1;
            }
        }
    }
    gPlayerObject->Pos.x = player_pos_x;
    gPlayerObject->Pos.y = player_pos_y;
    gPlayerObject->Pos.z = player_pos_z;
}

void func_80085424(void)
{
    struct ObjectStruct *sp24;
    struct ObjectStruct *sp20;
    s32 sp1C;
    s32 sp18;

    if (D_8016E238 == 0)
    {
        if (D_80165270 != -1)
        {
            sp1C = (s32)D_80165270;
            sp24 = &gObjects[sp1C];
            gPlayerObject->Pos.x = sp24->Pos.x + D_80165288;
            gPlayerObject->Pos.y = sp24->Pos.y + D_8016C290;
            gPlayerObject->Pos.z = sp24->Pos.z + D_8016CA98;
            func_800843CC(gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
            if (D_80177770[D_801776E0 & 1] == sp1C)
            {
                gPlayerObject->Pos.y = D_80177760[D_801776E0 & 1];
            }
        }
        else
        {
            sp1C = (s32)D_8016E2A8;
            sp24 = &gObjects[sp1C];
            gPlayerObject->Pos.x = sp24->Pos.x + D_80165288;
            gPlayerObject->Pos.y = sp24->Pos.y + D_8016C290;
            gPlayerObject->Pos.z = sp24->Pos.z + D_8016CA98;
        }
    }
    else
    {
        sp18 = D_8016E240 - 2;
        if (D_801779B0[sp18] != -1)
        {
            sp20 = &gObjects[D_8016E240];
            sp1C = D_801779B0[sp18];
            sp24 = &gObjects[sp1C];

            sp20->Pos.x = D_801779D0[sp18] + sp24->Pos.x;
            sp20->Pos.y = D_801779E8[sp18] + sp24->Pos.y;
            sp20->Pos.z = D_80177A00[sp18] + sp24->Pos.z;

            func_80078168(sp20->Pos.x, sp20->Pos.y, sp20->Pos.z);

            if (D_80177770[D_801776E0 & 1] == sp1C)
            {
                sp20->Pos.y = D_80177760[D_801776E0 & 1];
            }
        }
    }
}

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

void func_80069D04(s32, s32);
void func_8006AA24(s32);
void func_8007A6DC();
void func_80282198();
void func_802828C0();
void func_802844D4();
void func_802845C4();
void func_80284758();
void func_80284840();

extern s8 D_8016E27D;
extern s8 D_8016E288;
extern s8 D_8016E338;

s32 func_80085D54(void)
{
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    int pad2C;
    int pad28;
    int sp24;
    int pad20;
    u8 sp1F;
    u8 sp1E;
    u8 sp1D;

    sp24 = 0;
    sp44 = gObjects[sp24].Pos.x;
    sp40 = gObjects[sp24].Pos.y;
    sp3C = gObjects[sp24].Pos.z;

    if (D_8016523E == 4)
    {
        sp40 = sp40 - 59.0;
    }

    if ((D_8016523E == 0) && (D_80165270 != -1) && (D_80165280 == 0x4A))
    {
        if ((gPlayerObject->unk108 != 0x3D) && (gPlayerObject->unk108 != 0) && gObjects[D_80165270].unkA6 == 0)
        {
            gObjects[D_80165270].unkA6 = 8;
            gObjects[D_80165270].unkA8 = 1;
            if (D_8016E100 != 0)
            {
                func_8007A6DC();
            }
            func_802828C0();
            D_801651A4 |= 4;
            return 1;
        }
    }

    D_8016E338 = 0;
    func_800843CC(sp44, sp40, sp3C);

    sp38 = D_801776E0 & 1;
    sp1F = D_80177740[sp38];
    if ((u8)D_8016E094 != 0)
    {
        if (sp1F != (u8)D_8016E094)
        {
            D_8016E094 = 0;
        }
    }

    D_8016E414 = (s8)sp1F;
    D_8016E41C = (s16)D_80177750[sp38];

    switch (sp1F)
    {
    case 0xFF:
    {
        return 0;
    }
    case 0xE6:
    case 0xE7:
    case 0xF6:
    case 0xFE:
    {
        func_8006AA24(1);
        if (gDebugAtrributeFlag != 0)
        {
            return 0;
        }
        sp30 = 0;
        if ((sp1F == 0xFE) || (sp1F == 0xE7))
        {
            if (sp40 <= D_80177760[sp38])
            {
                sp30 = 1;
            }
        }
        else
        {
            sp30 = 1;
        }
        if (sp30 != 0)
        {
            sp34 = (s32)D_80177750[sp38] % 256;
            sp30 = (s32)D_80177750[sp38] / 256;
            if ((sp1F == 0xFE) || (sp1F == 0xF6))
            {
                func_80069D88(sp34, sp30 ^ 1);
            }
            else
            {
                func_80069D04(sp34, 0);
            }
            return 0;
        }
        break;
    }
    case 0xEE:
    case 0xF1:
    {
        if (gDebugAtrributeFlag != 0)
        {
            break;
        }
        if ((u8)D_8016E094 != 0)
        {
            break;
        }
        sp30 = 0;
        if (D_80177740[sp38] == 0xF1)
        {
            if (sp40 <= D_80177760[sp38])
            {
                sp30 = 1;
            }
        }
        else
        {
            sp30 = 1;
        }

        if (sp30)
        {
            D_8016E094 = sp1F;
            sp34 = (s32)D_80177750[sp38] % 256;
            sp1E = gLevelInfo[gCurrentLevel]->Unk8[sp34 << 1];
            sp1D = gLevelInfo[gCurrentLevel]->Unk8[(sp34 << 1) + 1];
            D_8016E438 = (s16)D_80108238[sp1E]->unk0[sp1D * 4];
            D_8016E43C = (f32)D_80108238[sp1E]->unk0[(sp1D * 4) + 1];
            D_8016E440 = (f32)D_80108238[sp1E]->unk0[(sp1D * 4) + 2];
            D_8016E444 = (f32)D_80108238[sp1E]->unk0[(sp1D * 4) + 3];

            if ((gPlayerObject->unk108 != 0x3D) && (gPlayerObject->unk108 != 0))
            {

                if (D_8016523E == 0)
                {
                    func_802845C4();
                    return 1;
                }
                else if (D_8016523E == 1)
                {
                    func_80282198();
                    return 1;
                }
            }
        }
    }
    break;

    case 0xDA:
        if (gDebugAtrributeFlag != 0)
        {
            return 0;
        }

        if (sp40 <= D_80177760[sp38])
        {

            sp34 = (s32)D_80177750[sp38] % 256;

            if ((sp34 == 0) && (gCurrentLevel == 0x44))
            {

                func_80069D04(sp34, 0);
            }
            else if ((sp34 == 1) && (gCurrentLevel == 0x69))
            {

                func_80069D04(sp34, 0);
            }
            else if ((sp34 == 2) && (gCurrentLevel == 0x6A))
            {

                func_80069D04(sp34, 0);
            }
            else if ((sp34 == 3) && (gCurrentLevel == 0x6B))
            {

                func_80069D88(sp34, 0);
            }
        }

        return 0;
        break;

    case 0xF0:
        if (sp40 <= D_80177760[sp38])
        {
            if ((gPlayerObject->unk108 != 0x3D) && (gPlayerObject->unk108 != 0))
            {
                func_802828C0();
                D_801651A4 |= 4;
                return 1;
            }
        }
        break;

    case 0xFC:
        if (gDebugAtrributeFlag != 0)
        {
            return 0;
        }
        if (sp40 <= D_80177760[sp38])
        {
            D_8016E27D = D_80177750[sp38] + 1;
        }
        break;

    case 0xEF:
        if (gDebugAtrributeFlag != 0)
        {
            return 0;
        }
        if (sp40 <= D_80177760[sp38])
        {
            if ((gPlayerObject->unk108 != 0x3D) && (gPlayerObject->unk108 != 0))
            {
                func_802844D4();
                gPlayerObject->unk3C = (f32)(D_80177750[sp38] * 0x5A);
                return 1;
            }
        }
        break;

    case 0xD7:
    case 0xE8:
    case 0xEC:
    case 0xED:
        if (gDebugAtrributeFlag != 0)
        {
            return 0;
        }
        if (sp40 <= D_80177760[sp38])
        {
            if (D_80177740[sp38] == 0xED)
            {
                D_8016E288 = 1;
            }
            else if (D_80177740[sp38] == 0xEC)
            {
                D_8016E288 = 2;
            }
            else if (D_80177740[sp38] == 0xE8)
            {
                D_8016E288 = 3;
            }
            else if (D_80177740[sp38] == 0xD7)
            {
                D_8016E288 = 4;
            }
        }
        break;

    case 0xE3:
        if (gDebugAtrributeFlag != 0)
        {
            return 0;
        }
        D_8016E338 = 1;
        if ((gPlayerObject->unk108 != 0x3D) && (gPlayerObject->unk108 != 0))
        {
            func_80284840();
            return 1;

            break;
        }

    case 0xE9:
        if (gDebugAtrributeFlag != 0)
        {
            return 0;
        }
        if ((u8)D_8016E094 != 0)
        {
            break;
        }
        if (sp40 <= D_80177760[sp38])
        {
            func_800843CC(sp44, sp40, sp3C + 25.0f);
            if (D_80177740[D_801776E0 & 1] != 0xE9)
            {
                break;
            }
            func_800843CC(sp44 + 25.0f, sp40, sp3C);
            if (D_80177740[D_801776E0 & 1] != 0xE9)
            {
                break;
            }
            func_800843CC(sp44, sp40, sp3C - 25.0f);
            if (D_80177740[D_801776E0 & 1] != 0xE9)
            {
                break;
            }
            func_800843CC(sp44 - 25.0f, sp40, sp3C);
            if (D_80177740[D_801776E0 & 1] != 0xE9)
            {
                break;
            }

            if ((gPlayerObject->unk108 != 0x3D) && (gPlayerObject->unk108 != 0))
            {
                func_80284758();
                D_8016E094 = (s8)sp1F;
                return 1;
            }
        }

        break;
    }
    return 0;
}

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
        sp28 = (f32)((f64)sp28 - 59.0);
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
                gPlayerArmWindObject->Scale.x = gPlayerArmWindObject->Scale.x + 0.05;
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

void func_80087694(void)
{
    f32 spC;
    f32 sp8;
    f32 sp4;
    f32 sp0;

    if ((gActiveContStickX >= 10.0f) || (gActiveContStickX <= -10.0f))
    {
        gObjects[0].Pos.x += gActiveContStickX / 1.0f;
    }
    if ((gActiveContStickY >= 10.0f) || (gActiveContStickY <= -10.0f))
    {
        gObjects[0].Pos.z -= gActiveContStickY / 1.0f;
    }
    if (*gContCurrButton & 0x8000)
    {
        gObjects[0].Pos.y += 40.0f;
    }
    if (*gContCurrButton & 0x4000)
    {
        gObjects[0].Pos.y -= 40.0f;
    }
    if (((gActiveContStickX >= 10.0f) || (gActiveContStickX <= -10.0f) || (gActiveContStickY >= 10.0f) || (gActiveContStickY <= -10.0f)))
    {
        spC = (f32)((f64)gActiveContStickX / 90.0);
        sp8 = (f32)((f64)gActiveContStickY / 90.0);
        sp4 = (f32)((f64)gActiveContStickX / 90.0);
        sp0 = (f32) - ((f64)gActiveContStickY / 90.0);

        if (((spC != 0.0)) || (sp8 != 0.0))
        {
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

    FileSize = D_8010CC68[D_8016523E][1] - D_8010CC68[D_8016523E][0];

    load_from_rom_to_addr(D_8010CC68[D_8016523E][0], 0x80280000, FileSize);
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
