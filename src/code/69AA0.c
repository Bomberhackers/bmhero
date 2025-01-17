#include "common.h"
#include "69AA0.h"

void func_80077580(s32 arg0, s32 arg1)
{
    s32 i;
    s32 j;
    struct ObjectStruct *sp1C;

    if (gObjects[arg0].unk139 == 0)
    {
        func_80019050(arg0);
    }
    if (gObjects[arg1].unk139 == 0)
    {
        func_80019050(arg1);
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            D_80134B68[i][j] = gObjects[arg0].unk64[i][j];
            D_80134BA8[i][j] = gObjects[arg1].unk64[i][j];
        }
    }

    sp1C = &gObjects[arg0];
    D_80134BE8 = (sp1C->Scale.x + sp1C->Scale.y + sp1C->Scale.z) / 3.0f;
    sp1C = &gObjects[arg1];
    D_80134BEC = (sp1C->Scale.x + sp1C->Scale.y + sp1C->Scale.z) / 3.0f;
}

void func_80077798(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3)
{
    if (arg0 == 0)
    {
        guMtxXFMF(D_80134B68, *arg1, *arg2, *arg3, arg1, arg2, arg3);
    }
    else
    {
        guMtxXFMF(D_80134BA8, *arg1, *arg2, *arg3, arg1, arg2, arg3);
    }
}

f32 func_80077840(s32 arg0, f32 arg1)
{
    UNUSED s32 pad;

    if (arg0 == 0)
    {
        return arg1 * D_80134BE8;
    }
    else
    {
        return arg1 * D_80134BEC;
    }
}

s32 func_800778A0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7)
{
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 sp4;

    sp14 = arg0 - arg4;
    sp10 = arg1 - arg5;
    spC = arg2 - arg6;
    sp8 = (SQ(sp14)) + (SQ(sp10)) + (SQ(spC));

    sp4 = (arg3 + arg7) * (arg3 + arg7);
    if (sp8 <= sp4)
    {
        return 1;
    }
    return 0;
}

s32 func_8007795C(void)
{
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    sp44 = (f32)D_80134B54->unk0[D_80134B50];
    sp40 = (f32)D_80134B54->unk0[D_80134B50 + 1];
    sp3C = (f32)D_80134B54->unk0[D_80134B50 + 2];
    sp38 = (f32)D_80134B58->unk0[D_80134B52];
    sp34 = (f32)D_80134B58->unk0[D_80134B52 + 1];
    sp30 = (f32)D_80134B58->unk0[D_80134B52 + 2];
    sp2C = (f32)D_80134B54->unk0[D_80134B50 + 3];
    sp28 = (f32)D_80134B58->unk0[D_80134B52 + 3];

    func_80077798(0, &sp44, &sp40, &sp3C);
    func_80077798(1, &sp38, &sp34, &sp30);
    sp2C = func_80077840(0, sp2C);
    sp28 = func_80077840(1, sp28);
    if (func_800778A0(sp44, sp40, sp3C, sp2C, sp38, sp34, sp30, sp28) != 0)
    {
        return 1;
    }
    return 0;
}

extern s16 D_8010BF30[];
extern s16 D_80134B60;

s32 func_80077B90(void)
{
    s16 sp1E;
    s16 sp1C;

    D_80134B60 = 0;
    sp1E = 0;
    D_80134B52 = 4;

    while (TRUE)
    {
        sp1C = D_80134B58[D_80134B52].unk0[0];
        if (sp1C == 0)
        {
            break;
        }
        sp1C &= 0x7F;
        D_80134B52 += 1;
        if (sp1C != 0)
        {
        }
        else
        {
            sp1E = func_8007795C();
        }
        if (sp1E != 0)
        {
            return 1;
        }

        D_80134B60 += 1;
        D_80134B52 += D_8010BF30[sp1C];
    }
    return 0;
}

s32 func_80077CB0(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3)
{
    s16 sp5E;
    s16 sp5C;
    UNUSED s32 pad[2];
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    struct ObjectStruct *sp30;
    struct ObjectStruct *sp2C;
    sp30 = &gObjects[arg0];
    sp2C = &gObjects[arg1];
    D_80134B54 = D_80124D90[sp30->unkE4].unk20[sp30->unkFE];

    D_80134B58 = D_80124D90[sp2C->unkE4].unk20[sp2C->unkFE];

    sp50 = (f32)D_80134B54->unk0[0] + sp30->Pos.x;
    sp4C = (f32)D_80134B54->unk0[1] + sp30->Pos.y;
    sp48 = (f32)D_80134B54->unk0[2] + sp30->Pos.z;
    sp44 = D_80134B58->unk0[0] + sp2C->Pos.x;
    sp40 = (f32)D_80134B58->unk0[1] + sp2C->Pos.y;
    sp3C = (f32)D_80134B58->unk0[2] + sp2C->Pos.z;
    sp38 = ((f32)D_80134B54->unk0[3] * (sp30->Scale.x + sp30->Scale.y + sp30->Scale.z)) / 3.0f;
    sp34 = ((f32)D_80134B58->unk0[3] * (sp2C->Scale.x + sp2C->Scale.y + sp2C->Scale.z)) / 3.0f;
    if (func_800778A0(sp50, sp4C, sp48, sp38, sp44, sp40, sp3C, sp34) == 0)
    {
        return 0;
    }
    func_80077580((s32)arg0, (s32)arg1);
    D_80134B5E = 0;
    D_80134B60 = 0;
    sp5C = 4;
    while (1)
    {
        D_80134B5C = D_80134B54[sp5C].unk0[0];
        if (D_80134B5C == 0)
        {
            return 0;
        }
        sp5E = 0;
        D_80134B5C &= 0x7F;
        sp5C += 1;
        D_80134B50 = sp5C;
        if (D_80134B5C != 0)
        {
        }
        else
        {
            sp5E = func_80077B90();
        }
        if (sp5E != 0)
        {
            *arg2 = D_80134B5E;
            *arg3 = D_80134B60;
            return 1;
        }
        D_80134B5E += 1;
        sp5C += D_8010BF30[D_80134B5C];
    }
}

s32 func_800780A0(f32 arg0, f32 arg1, f32 arg2)
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

void func_80078168(f32 arg0, f32 arg1, f32 arg2)
{
    func_80067748(arg0, arg1, arg2);
    func_800670E8();
    func_80068CC4(arg0, arg1, arg2);
    func_80069314();
    func_800673D4();
}

s32 func_800781D4(f32 arg0, f32 arg1, f32 arg2)
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

    func_80078168(arg0, arg1, arg2);
    spAC = D_801776E0 & 1;
    sp93 = D_801776E0;
    spA8 = D_801776F0[spAC];
    spA4 = D_80177700[spAC];
    spA0 = D_80177710[spAC];
    sp9C = D_80177720[spAC];
    sp98 = D_80177730[spAC];
    sp94 = D_80177760[spAC];
    func_80016A80(D_80177968, D_80177970, D_80177978, D_80177980, &sp8C, &sp88, &sp84, &sp80);
    func_80016A80(spA8, spA4, spA0, sp9C, &sp7C, &sp78, &sp74, &sp70);

    if ((func_8001608C(D_80177968,
                       D_80177970,
                       D_80177978,
                       D_80177980,
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
            if ((D_80177990 - sp94) < 30.0f)
            {
                return 1;
            }
            if (((sp80 != 0.0f) || (sp70 != 0.0f)) && ((func_80016714(D_80177968, D_80177970, D_80177978, D_80177980, spA8, spA4, spA0, sp9C, &sp64, &sp60, &sp5C, &sp58), (sp64 != 0.0f)) || (sp60 != 0.0f) || (sp5C != 0.0f) || (sp58 != 0.0f)))
            {
                sp6C = func_800162F0(D_80177998, D_801779A8, sp64, sp60, sp5C, sp58);
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
            if ((sp94 - D_80177990) < 30.0f)
            {
                return 2;
            }
            if (((sp80 != 0.0f) || (sp70 != 0.0f)) && ((func_80016714(D_80177968, D_80177970, D_80177978, D_80177980, spA8, spA4, spA0, sp9C, &sp64, &sp60, &sp5C, &sp58), (sp64 != 0.0f)) || (sp60 != 0.0f) || (sp5C != 0.0f) || (sp58 != 0.0f)))
            {
                sp6C = func_800162F0(D_80177998, D_801779A8, sp64, sp60, sp5C, sp58);
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

void func_8007897C(s32 arg0)
{
    struct ObjectStruct *sp1C;
    s32 sp18;

    sp1C = &gObjects[arg0];
    func_80078168(sp1C->Pos.x, sp1C->Pos.y, sp1C->Pos.z);
    sp18 = D_801776E0 & 1;
    D_80177960 = D_801776E0;
    D_80177968 = D_801776F0[sp18];
    D_80177970 = D_80177700[sp18];
    D_80177978 = D_80177710[sp18];
    D_80177980 = D_80177720[sp18];
    D_80177988 = D_80177730[sp18];
    D_80177990 = D_80177760[sp18];
    D_80177998 = sp1C->Pos.x;
    D_801779A0 = sp1C->Pos.y;
    D_801779A8 = sp1C->Pos.z;
}

s32 func_80078AEC(s32 arg0)
{
    struct ObjectStruct *sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp4C = &gObjects[arg0];
    sp48 = sp4C->Pos.x;
    sp44 = sp4C->Pos.y;
    sp40 = sp4C->Pos.z;
    sp3C = sp4C->Vel.x;
    sp38 = sp4C->Vel.y;
    sp34 = sp4C->Vel.z;
    sp28 = 0;
    func_80078168(sp48, sp44, sp40);
    if (D_801776E0 & 1)
    {
        return 4;
    }
    sp24 = 0;
    sp18 = 0;
    if (!(D_801776E0 & 1) && (D_80177760[0] == -30000.0f) && (D_801776E4 != 0))
    {
        sp18 = (s32)D_8017791B[D_801776E4];
        if ((sp18 == 2) && (sp4C->unkA4 == 0x2A))
        {
            sp18 = 3;
        }
    }
    if (sp18 < 3)
    {
        sp44 += sp38;
        if (sp18 != 2)
        {
            func_80078168(sp48, sp44 + 30.0f, sp40);
            if (D_801776E0 & 1)
            {
                sp44 = D_80177760[0] - 30.0f;
                sp28 |= 1;
            }
            func_80078168(sp48, sp44 - 30.0f, sp40);
            if (D_801776E0 & 1)
            {
                sp44 = D_80177760[1] + 30.0f;
                sp4C->Vel.y = 0.0f;
                sp24 = 1;
                sp28 |= 2;
            }
        }
        else if (sp44 < sp4C->unkD4)
        {
            sp44 = sp4C->unkD4;
            sp4C->Vel.y = 0.0f;
            sp24 = 0;
            sp28 |= 2;
        }
    }
    sp48 += sp3C;
    sp40 += sp34;
    sp30 = sinf((f32)((f64)sp4C->unk3C * 0.0174532925199432955)) * 15.0f;
    sp2C = cosf((f32)((f64)sp4C->unk3C * 0.0174532925199432955)) * 15.0f;
    if ((func_800781D4(sp48 + sp30, sp44, sp40 + sp2C) == 4))
    {
        sp28 |= 4;

        if (((D_80177770[D_801776E0 & 1] == -1)) || (sp4C->unkE4 == 0xB))
        {
            sp48 -= sp3C;
            sp40 -= sp34;
        }
    }
    sp20 = func_800781D4(sp48, sp44, sp40);
    if ((sp20 < 3) && (sp24 != 0))
    {
        func_80078168(sp48, sp44, sp40);
        if (!(D_801776E0 & 1))
        {
            sp44 = D_80177760[0] + 30.0f;
        }
        func_80078168(sp48, sp44, sp40);
        D_801779AC.bytes[arg0] = (s16)D_80177770[D_801776E0 & 1];
        if (D_801779AC.bytes[arg0] != -1)
        {
            D_801779BC[arg0] = gObjects[D_801779AC.bytes[arg0]].unkE4;
            D_801779C8.bytes[arg0] = sp48 - gObjects[D_801779AC.bytes[arg0]].Pos.x;
            D_801779E0.bytes[arg0] = sp44 - gObjects[D_801779AC.bytes[arg0]].Pos.y;
            D_801779F8[arg0] = sp40 - gObjects[D_801779AC.bytes[arg0]].Pos.z;
        }
    }
    else
    {
        D_801779AC.bytes[arg0] = -1;
    }
    func_80078168(sp48, sp44, sp40);
    if (!(D_801776E0 & 1) && (D_80177760[0] == -30000.0f))
    {
        if (sp4C->unkAC == 0)
        {
            sp4C->unkAC = 1;
        }
    }
    else
    {
        sp1C = D_801776E0 & 1;
        sp4C->unkAE = (s16)D_80177740[sp1C];
        sp4C->unkB0 = (s16)D_80177750[sp1C];
        sp4C->unkD4 = D_80177760[sp1C];
    }
    if (sp4C->unkAE != 0xFF)
    {
        if ((sp4C->unkAE == 0xF8) && ((sp44 - 30.0f) <= sp4C->unkD4))
        {
            sp28 |= 8;
        }
        else if ((sp4C->unkAE == 0xF7) && ((sp44 - 30.0f) <= sp4C->unkD4))
        {
            sp28 |= 8;
        }
        else
        {
            if (((sp4C->unkAE == 0xF5) || (sp4C->unkAE == 0xD9)) && ((sp44 - 30.0f) <= sp4C->unkD4))
            {
                if (sp4C->unkB0 == 1)
                {
                    func_80081468(0x2CB, sp48, sp44 + 120.0f, sp40);
                    sp28 |= 8;
                }
                else if (sp4C->unkB0 == 2)
                {
                    func_80081468(0x2CC, sp48, sp44 + 60.0f, sp40);
                    sp28 |= 8;
                }
            }
        }
    }
    sp4C->Pos.x = sp48;
    sp4C->Pos.y = sp44;
    sp4C->Pos.z = sp40;
    return sp28;
}

s32 func_8007944C(void)
{
    s32 sp4;

    for (sp4 = 2; sp4 <= 5; sp4++)
    {
        if (gObjects[sp4].unkA4 == 0)
        {
            return sp4;
        }
    }
    return -1;
}

void func_800794C4(s32 arg0)
{
    s32 sp1C;

    sp1C = arg0 - 2;
    func_8001A928(arg0);
    D_801779B0[sp1C] = -1;
    D_801779C0[sp1C] = -1;
    D_801779D0[sp1C] = 0.0f;
    D_801779E8[sp1C] = 0.0f;
    D_80177A00[sp1C] = 0.0f;
}

void func_8007957C(void)
{
    s32 sp1C;

    for (sp1C = 2; sp1C < 6; sp1C++)
    {
        func_800794C4(sp1C);
    }
}

void func_800795C8(s32 arg0)
{
    struct ObjectStruct *sp1C;
    s32 sp18;

    sp1C = &gObjects[arg0];
    if (sp1C->unkE4 == 9)
    {
        sp18 = 1;
    }
    else if (sp1C->unkE4 == 0xA)
    {
        sp18 = 2;
    }
    else
    {
        sp18 = 0;
    }
    func_8007E76C(sp1C->Pos.x, sp1C->Pos.y, sp1C->Pos.z, sp18);
    func_8001A928(arg0);
}

void func_80079688(s32 arg0)
{
    struct ObjectStruct *sp4;

    sp4 = &gObjects[arg0];
    if (sp4->unkAA == 0)
    {
        sp4->unkA8 -= 2;
        if (sp4->unkA8 < 0x5B)
        {
            sp4->unkA8 = 0x5A;
            sp4->unkAA = 1;
        }
    }
    else
    {
        sp4->unkA8 += 2;
        if (sp4->unkA8 >= 0x6E)
        {
            sp4->unkA8 = 0x6E;
            sp4->unkAA = 0;
        }
    }
}

void func_80079778(s32 arg0)
{
    struct ObjectStruct *sp4;

    sp4 = &gObjects[arg0];
    sp4->unkA8 += 0xA;
    if (sp4->unkA8 >= 0x64)
    {
        sp4->unkA8 = 0x64;
        sp4->unkAA = 0;
    }
}

void func_800797FC(s32 arg0)
{
    struct ObjectStruct *spC;

    spC = &gObjects[arg0];
    spC->Scale.x =
        spC->Scale.y =
            spC->Scale.z = spC->unkA8 / 100.0f;
}

extern f64 D_8010C9C0;
extern f64 D_8010C9C8;

void func_80079874(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    sp1C->Pos.x = (sinf((f32)((f64)gPlayerObject->Rot.y * 0.0174532925199432955)) * 32.0f) + gPlayerObject->Pos.x;
    sp1C->Pos.z = (cosf((f32)((f64)gPlayerObject->Rot.y * 0.0174532925199432955)) * 32.0f) + gPlayerObject->Pos.z;
}

void func_80079960(s32 arg0)
{
    gObjects[arg0].Pos.y = gPlayerObject->Pos.y + 50.0f;
}

void func_800799A8(s32 arg0)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[arg0];
    sp24->Vel.x = (sp24->unk44 * cosf((f32)((f64)sp24->unk40 * 0.0174532925199432955))) * sinf((f32)((f64)sp24->unk3C * 0.0174532925199432955));
    sp24->Vel.z = (sp24->unk44 * cosf((f32)((f64)sp24->unk40 * 0.0174532925199432955))) * cosf((f32)((f64)sp24->unk3C * 0.0174532925199432955));
}

void func_80079AD8(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    sp1C->Vel.y = sinf((f32)((f64)sp1C->unk40 * 0.0174532925199432955)) * sp1C->unk44;
}

void func_80079B60(s32 arg0)
{
    struct ObjectStruct *sp4;

    sp4 = &gObjects[arg0];
    sp4->Vel.y -= 2.0f;
    if (sp4->Vel.y < -48.0f)
    {
        sp4->Vel.y = -48.0f;
    }
}
void func_80079BEC(f32 *arg0, s32 arg1, s16 *arg2, f32 arg3)
{
    Matrix spE8;
    Matrix spA8;
    Matrix sp68;
    Matrix sp28;

    guRotateF(spE8, gPlayerObject->Rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(spA8, gPlayerObject->Rot.y, 0.0f, 1.0f, 0.0f);
    guTranslateF(sp68, gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
    guMtxCatF(spE8, spA8, sp28);
    guMtxCatF(sp28, sp68, sp28);

    guMtxXFMF(sp28,
              arg2[(arg1 * 3)],
              arg2[(arg1 * 3) + 1] + arg3,
              arg2[arg1 * 3 + 2], arg0,
              arg0 + 1,
              arg0 + 2);
}

void func_80079D18(s32 arg0)
{
    func_800795C8(arg0);
}

s32 func_80079D48(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    if (sp1C->unkAC != 0)
    {
        sp1C->unkAC += 1;
        if (sp1C->unkAC >= 0x15)
        {
            func_800795C8(arg0);
            return 1;
        }
    }
    return 0;
}

// Update bomb count?
s32 func_80079DFC(void)
{
    struct ObjectStruct *spC;
    s32 sp8;
    s32 sp4;

    sp4 = 0;
    spC = &gObjects[2];

    for (sp8 = 0; sp8 < 4; sp8++, spC++)
    {
        if (spC->unkA4 != 0)
        {
            sp4 += 1;
        }
    }

    if (sp4 > gBombCount)
    {
        return 1;
    }
    return 0;
}

void func_80079E9C(s32 arg0)
{
    struct ObjectStruct *sp1C;
    s32 sp18;

    func_800794C4(arg0);
    sp1C = &gObjects[arg0];
    func_8001BD44(arg0, 0, 0, (s32)gFileArray[9].ptr);
    if (D_80165250 == 0)
    {
        sp1C->unkE4 = 8;
        sp18 = 0;
    }
    else if (D_80165250 == 1)
    {
        sp1C->unkE4 = 9;
        sp18 = 1;
    }
    else if (D_80165250 == 2)
    {
        sp1C->unkE4 = 0xA;
        sp18 = 2;
    }
    else
    {
        sp1C->unkE4 = 0xB;
        sp18 = 3;
    }
    func_8001ABF4(arg0, 0, 0, &D_801163DC[sp18]);
    sp1C->unkA6 = 0x64;
    sp1C->unkA8 = 0x14;
    sp1C->unkAA = 0;
    sp1C->unkAE = 0xFF;
    sp1C->unkB0 = 0;
    sp1C->unkD4 = gPlayerObject->Pos.y;
}

void func_8007A024(void)
{
    s32 sp1C;
    struct ObjectStruct *sp18;

    sp1C = func_8007944C();
    if (sp1C != -1)
    {
        func_80079E9C(sp1C);
        sp18 = &gObjects[sp1C];
        ;
        sp18->unkA4 = 0x20;
        sp18->Pos.x = gPlayerObject->Pos.x;
        sp18->Pos.y = gPlayerObject->Pos.y + 50.0f;
        sp18->Pos.z = gPlayerObject->Pos.z;
        sp18->unk3C = gPlayerObject->Rot.y;
        D_8016E100 = (s16)sp1C;
    }
    else
    {
        D_8016E100 = 0;
    }
}

void func_8007A120(void)
{
    struct ObjectStruct *sp4;

    sp4 = &gObjects[D_8016E100];
    sp4->unkA4 = 0x24;
    sp4->unkB4 = (s16)(s32)gPlayerObject->unk44;
    D_8016E100 = 0;
}

void func_8007A1A8(void)
{
    func_8001A928((s32)D_8016E100);
    D_8016E100 = 0;
}

void func_8007A1E0(void)
{
    struct ObjectStruct *sp1C;
    s32 sp18;

    if (D_8016E100 == 0)
    {
        sp18 = func_8007944C();
        if (sp18 != -1)
        {
            func_80079E9C(sp18);
        }
    }
    else
    {
        sp18 = (s32)D_8016E100;
    }
    if (sp18 != -1)
    {
        sp1C = &gObjects[sp18];
        sp1C->unkA4 = 0x21;
        D_8016E100 =
            D_8016E108 = (s16)sp18;
    }
    else
    {
        D_8016E100 = 0;
    }
}

void func_8007A2C0(void)
{
    struct ObjectStruct *sp1C;
    s32 sp18;

    if (D_8016E100 == 0)
    {
        sp18 = func_8007944C();
        if (sp18 != -1)
        {
            func_80079E9C(sp18);
        }
    }
    else
    {
        sp18 = (s32)D_8016E100;
    }
    if (sp18 != -1)
    {
        sp1C = &gObjects[sp18];
        sp1C->unkA4 = 0x22;
        D_8016E100 = D_8016E108 = sp18;
    }
    else
    {
        D_8016E100 = 0;
    }
}

void func_8007A3A0(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    if (sp1C->unkA4 != 0)
    {
        sp1C->unkA4 = 0x2A;
        sp1C->unkD4 = gPlayerObject->Pos.y;
        sp1C->unkB6 = 0;
        sp1C->unk44 = 30.0f;
        sp1C->unk3C = gPlayerObject->Rot.y;
        sp1C->unk40 = 0.0f;
        func_800799A8(arg0);
        func_80079AD8(arg0);
    }
}

void func_8007A488(s32 arg0)
{
    s32 sp1C;
    struct ObjectStruct *sp18;

    if (D_80165268 != 0)
    {
        arg0 += 0xA;
    }
    sp1C = func_8007944C();
    if (sp1C != -1)
    {
        func_80079E9C(sp1C);
        sp18 = &gObjects[sp1C];
        sp18->unkA4 = 0x25;
        sp18->Pos.x = gPlayerObject->Pos.x;
        sp18->Pos.y = gPlayerObject->Pos.y + 50.0f;
        sp18->Pos.z = gPlayerObject->Pos.z;
        sp18->unk40 = D_8010C7E4[arg0].y;
        sp18->unk3C = func_80015538(gPlayerObject->Rot.y, D_8010C7E4[arg0].z);
        sp18->unk44 = D_8010C7E4[arg0].x;
        func_800799A8(sp1C);
        func_80079AD8(sp1C);
    }
}

void func_8007A620(s32 arg0)
{
    UNUSED s32 pad;

    if (arg0 == 1)
    {
        func_8007A488(0);
    }
    else if (arg0 == 2)
    {
        func_8007A488(1);
        func_8007A488(2);
    }
    else if (arg0 == 3)
    {
        func_8007A488(3);
        func_8007A488(4);
        func_8007A488(5);
    }
    else
    {
        func_8007A488(6);
        func_8007A488(7);
        func_8007A488(8);
        func_8007A488(9);
    }
}

void func_8007A6DC(void)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[D_8016E100];
    sp1C->unkA4 = 0x26;
    sp1C->unkD4 = gPlayerObject->Pos.y;
    sp1C->unk40 = 80.0f;
    sp1C->unk3C = gPlayerObject->Rot.y;
    sp1C->unk44 = 35.0f;
    func_800799A8((s32)D_8016E100);
    func_80079AD8((s32)D_8016E100);
    D_8016E100 = 0;
}

void func_8007A7B4(f32 arg0, f32 arg1, f32 arg2)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[D_8016E100];
    sp1C->unkA4 = 0x26;
    sp1C->unkD4 = gPlayerObject->Pos.y;
    sp1C->unk40 = 80.0f;
    sp1C->unk3C = gPlayerObject->Rot.y;
    sp1C->unk44 = 35.0f;
    sp1C->Pos.x = sp1C->Pos.x + arg0 * sinf((f32)((f64)gPlayerObject->Rot.y * 0.0174532925199432955));
    sp1C->Pos.y += arg1;
    sp1C->Pos.z = sp1C->Pos.z + arg2 * cosf((f32)((f64)gPlayerObject->Rot.y * 0.0174532925199432955));
    func_800799A8((s32)D_8016E100);
    func_80079AD8((s32)D_8016E100);
    D_8016E100 = 0;
}

extern f64 D_8010CA08;
extern f64 D_8010CA10;

void func_8007A938(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    sp1C->Pos.x = (sinf((gPlayerObject->Rot.y * 0.0174532925199432955)) * 32.0f) + gPlayerObject->Pos.x;
    sp1C->Pos.z = (cosf((gPlayerObject->Rot.y * 0.0174532925199432955)) * 32.0f) + gPlayerObject->Pos.z;
    sp1C->Pos.y = gPlayerObject->Pos.y + 50.0f;
    func_80079778(arg0);
    func_800797FC(arg0);
    if (sp1C->unkA8 == 0x64)
    {
        sp1C->unkA4 = 0x23;
    }
}

void func_8007AA80(s32 arg0)
{
    struct ObjectStruct *sp24;
    s32 sp20;
    s16 *sp1C;
    s32 sp18;

    sp24 = &gObjects[arg0];
    sp1C = NULL;
    sp18 = func_8001B880(0, 0);
    if (sp18 == 0xE)
    {
        sp1C = &D_8010BF40;
    }
    else
    {
        if (sp18 == 0xF)
        {
            sp1C = &D_8010BFFC;
        }
        else if (sp18 == 0x10)
        {
            sp1C = &D_8010C0C4;
        }
        else if (sp18 == 0x11)
        {
            sp1C = &D_8010C15C;
        }
        else if (sp18 == 0x12)
        {
            sp1C = &D_8010C1C4;
        }
        else if (sp18 == 0x13)
        {
            sp1C = &D_8010C1FC;
        }
        else
        {
            if (sp18 == 0x14)
            {
                sp1C = &D_8010C214;
            }
            else if (sp18 == 0x15)
            {
                sp1C = &D_8010C27C;
            }
            else if (sp18 == 0x16)
            {
                sp1C = &D_8010C2DC;
            }
            else if (sp18 == 0x17)
            {
                sp1C = &D_8010C308;
            }
            else if (sp18 == 0x18)
            {
                sp1C = &D_8010C370;
            }
            else if (sp18 == 0x19)
            {
                sp1C = &D_8010C3D0;
            }
        }
    }
    sp20 = (s32)((func_8001B62C(0, 0) - 2.0f) / 2.0f);
    if (sp20 < 0)
    {
        sp20 = (s32)(func_8001B580(0, 0) / 2.0f);
    }
    if (sp1C != NULL)
    {
        func_80079BEC(&sp24->Pos.x, sp20, sp1C, 0.0f);
    }
    else
    {
        func_80079874(arg0);
        func_80079960(arg0);
    }
    func_80079688(arg0);
    func_800797FC(arg0);
}

void func_8007AD60(s32 arg0)
{
    struct ObjectStruct *sp1C;
    s32 sp18;

    sp1C = &gObjects[arg0];
    if ((gPlayerObject->unkA4 == 0xE) || (gPlayerObject->unkA4 == 0xF) || (gPlayerObject->unkA4 == 0x10))
    {
        sp18 = (s32)((func_8001B62C(0, 0) - 2.0f) / 2.0f);
        if (sp18 < 0)
        {
            sp18 = 0;
        }
        func_80079BEC(&sp1C->Pos.x, sp18, &D_8010C3FC, 0.0f);
    }
    else
    {
        sp18 = 4;
    }
    func_80079688(arg0);
    func_800797FC(arg0);
    if (sp18 == 4)
    {
        if (sp1C->unkA4 == 0x24)
        {
            sp1C->unkA4 = 0x27;
            sp1C->unkD4 = gPlayerObject->Pos.y;
            if (D_801651A4 & 1)
            {
                sp1C->unk40 = 30.0f;
            }
            else
            {
                sp1C->unk40 = 30.0f;
            }
            sp1C->unk3C = gPlayerObject->Rot.y;
            if (D_80165268 == 0)
            {
                sp1C->unk44 = ((f32)sp1C->unkB4 / 3.0f) + 28.0f + (f32)gFireCount;
            }
            else
            {
                sp1C->unk44 = ((f32)sp1C->unkB4 / 3.0f) + 60.0f + (f32)gFireCount;
            }
            func_800799A8(arg0);
            func_80079AD8(arg0);
        }
        else
        {
            sp1C->unkA4 = 0x26;
            sp1C->unkD4 = gPlayerObject->Pos.y;
        }
    }
}

void func_8007B004(s32 arg0)
{
    struct ObjectStruct *sp9C;
    s32 sp98;
    UNUSED char pad[0x80]; // what?

    sp9C = &gObjects[arg0];
    if (gPlayerObject->unkA4 == 0x11)
    {
        sp98 = (s32)((func_8001B62C(0, 0) - 2.0f) / 2.0f);
        if (sp98 < 0)
        {
            sp98 = (s32)(func_8001B580(0, 0) / 2.0f);
        }
        if (sp98 < 6)
        {
            func_80079BEC(&sp9C->Pos.x, sp98, &D_8010C41C, 10.0f);
        }
    }
    else
    {
        sp98 = 6;
    }
    func_80067748(sp9C->Pos.x, sp9C->Pos.y - 30.0f, sp9C->Pos.z);
    if (D_801776E0 & 1)
    {
        sp9C->Pos.y = D_80177760[D_801776E0 & 1] + 30.0f;
    }
    func_80079778(arg0);
    func_800797FC(arg0);
    if (sp98 == 6)
    {
        sp9C->unkA4 = 0x28;
        sp9C->unkD4 = gPlayerObject->Pos.y;
        sp9C->unk44 = 0.0f;
        sp9C->unk3C = gPlayerObject->Rot.y;
        sp9C->unk40 = 0.0f;
        func_800799A8(arg0);
        func_80079AD8(arg0);
        sp9C->unk108 = 1;
        D_8016E100 = 0;
    }
}

void func_8007B268(s32 arg0)
{
    struct ObjectStruct *sp9C;
    UNUSED char pad[0x80];

    sp9C = &gObjects[arg0];
    if ((gPlayerObject->unkA4 == 0x12) || (gPlayerObject->unkA4 == 0x13))
    {
        sp9C->Pos.x = (sinf((f32)((f64)gPlayerObject->Rot.y * 0.0174532925199432955)) * 32.0f) + gPlayerObject->Pos.x;
        sp9C->Pos.z = (cosf((f32)((f64)gPlayerObject->Rot.y * 0.0174532925199432955)) * 32.0f) + gPlayerObject->Pos.z;
        sp9C->Pos.y = gPlayerObject->Pos.y + 50.0f;
    }
    func_80079778(arg0);
    func_800797FC(arg0);
    if (sp9C->unkA8 == 0x64)
    {
        sp9C->unkA4 = 0x29;
        sp9C->unkD4 = gPlayerObject->Pos.y;
        sp9C->unk44 = 0.0f;
        sp9C->unk3C = gPlayerObject->Rot.y;
        sp9C->unk40 = 0.0f;
        func_800799A8(arg0);
        if (gPlayerObject->Vel.y >= 0.0f)
        {
            sp9C->Vel.y = 0.0f;
        }
        else if (D_8016E258 & 2)
        {
            sp9C->Vel.y = 0.0f;
        }
        else
        {
            sp9C->Vel.y = gPlayerObject->Vel.y;
        }
        sp9C->unk108 = 1;
        D_8016E100 = 0;
    }
}

s32 func_8007B4BC(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    if (sp1C->unkE4 == 0xB)
    {
        if (gActiveContPressed & 0x2000)
        {
            func_800795C8(arg0);
            return 1;
        }
    }
    else
    {
        sp1C->unkA6 -= 1;
        if (sp1C->unkA6 == 0)
        {
            func_800795C8(arg0);
            return 1;
        }
    }
    return 0;
}
/* extern */

void func_8007B5A0(s32 arg0)
{
    struct ObjectStruct *sp24;
    s32 sp20;
    f32 sp1C;

    sp24 = &gObjects[arg0];

    func_800682E0(arg0, 30.0f, 1);
    D_8016E238 = 1;
    D_8016E240 = arg0;
    func_80085884();
    func_8007897C(arg0);
    sp24->unk108 = 1;
    func_80079688(arg0);
    func_800797FC(arg0);
    func_80079B60(arg0);

    if (sp24->unkE4 == 0xB)
    {
        sp1C = sp24->Vel.y;
        sp20 = func_80078AEC(arg0);
        if (sp20 & 8)
        {
            func_800795C8(arg0);
            return;
        }
        else if (sp20 & 1)
        {
            sp24->Vel.y = -sp1C;
        }
        else if (sp20 & 2)
        {
            sp24->Vel.x /= 5.0f;
            sp24->Vel.z /= 5.0f;
            sp24->Vel.y = -sp1C / 3.0f;
        }
        else if (sp20 & 4)
        {
            sp24->Vel.x = -sp24->Vel.x / 5.0f;
            sp24->Vel.z = -sp24->Vel.z / 5.0f;
        }
        if (sp20 != 0)
        {
            if ((sp24->Vel.x < 1.0f) && (sp24->Vel.x > -1.0f))
            {
                sp24->Vel.x = 0.0f;
            }
            if ((sp24->Vel.z < 1.0f) && (sp24->Vel.z > -1.0f))
            {
                sp24->Vel.z = 0.0f;
            }
        }
        if ((sp24->unkA4 == 0x26))
        {
            if ((sp24->Vel.x == 0.0f) && (sp24->Vel.z == 0.0f))
            {
                sp24->unkA4 = 0x27;
            }
        }
    }
    else if (func_80078AEC(arg0) != 0)
    {
        func_800795C8(arg0);
        return;
    }
    if (func_80079D48(arg0) != 0)
    {
        return;
    }
    if (func_8007B4BC(arg0) != 0)
    {
        return;
    }
}

void func_8007B928(s32 arg0)
{
    struct ObjectStruct *sp24;
    UNUSED s32 sp20;
    s32 sp1C;

    sp24 = &gObjects[arg0];

    func_800682E0(arg0, 30.0f, 1);
    D_8016E238 = 1;
    D_8016E240 = arg0;
    func_80085884();
    func_8007897C(arg0);
    func_80079688(arg0);
    func_800797FC(arg0);
    func_80079B60(arg0);
    if (sp24->unkE4 == 0xB)
    {
        sp1C = func_80078AEC(arg0);
        if (sp1C & 8)
        {
            func_800795C8(arg0);
            return;
        }
        else if (sp1C & 4)
        {
            sp24->unkB6 = 1;
            sp24->Vel.x = -sp24->Vel.x;
            sp24->Vel.z = -sp24->Vel.z;
        }
        if (sp24->unkB6 != 0)
        {
            sp24->Vel.x /= 2.0f;
            sp24->Vel.z /= 2.0f;
            if ((sp24->Vel.x < 1.0f) && (sp24->Vel.x > -1.0f))
            {
                sp24->Vel.x = 0.0f;
            }
            if ((sp24->Vel.z < 1.0f) && (sp24->Vel.z > -1.0f))
            {
                sp24->Vel.z = 0.0f;
            }
        }
    }
    else if (func_80078AEC(arg0) & 0xC)
    {
        func_800795C8(arg0);
        return;
    }
    if (func_80079D48(arg0) != 0)
    {
        return;
    }
    if (func_8007B4BC(arg0) != 0)
    {
        return;
    }
}

void func_8007BBD8(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    if ((sp1C->unkA4 == 0x26) || (sp1C->unkA4 == 0x27) || (sp1C->unkA4 == 0x2A))
    {
    }
    else if (sp1C->unkA4 == 0x28)
    {
        func_8007A3A0(arg0);
        sp1C->unk3C = arg3;
    }
    else if (sp1C->unkA4 == 0x29)
    {
        func_8007A3A0(arg0);
        sp1C->unk3C = arg3;
    }
    sp1C->unk3C = func_80015538(sp1C->unk3C, arg1);
    func_800799A8(arg0);
    if (arg2 != 0.0f)
    {
        sp1C->Vel.y = -sp1C->Vel.y;
    }
}

void func_8007BD30(s32 arg0)
{
    struct ObjectStruct *sp1C;

    func_800794C4(arg0);
    sp1C = &gObjects[arg0];
    func_8001BD44(arg0, 0, 2, (s32)gFileArray[0xA].ptr);
    sp1C->unkE4 = 0xC;
    sp1C->unkA6 = 0x3C;
    sp1C->unkA8 = 0x14;
    sp1C->unkAA = 0;
    sp1C->unkAE = 0xFF;
    sp1C->unkB0 = 0;
    sp1C->unkD4 = gPlayerObject->Pos.y;
    func_80019448(arg0, 2, 0, 1);
    func_8001ABF4(arg0, 0, 0, &D_8011649C);
}

void func_8007BE30(void)
{
    s32 sp1C;
    struct ObjectStruct *sp18;

    sp1C = func_8007944C();
    if (sp1C != -1)
    {
        func_8007BD30(sp1C);
        sp18 = &gObjects[sp1C];
        sp18->unkA4 = 0x10;
        sp18->Pos.x = gPlayerObject->Pos.x;
        sp18->Pos.y = gPlayerObject->Pos.y;
        sp18->Pos.z = gPlayerObject->Pos.z;
        sp18->unk3C = gPlayerObject->Rot.y;
        D_8016E100 = (s16)sp1C;
    }
}

void func_8007BF18(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[D_8016E100];
    sp24->unkA4 = 0x12;
    sp24->unkD4 = gPlayerObject->Pos.y;
    sp24->unk3C = gPlayerObject->Rot.y;
    if (gPlayerObject->Pos.y < (D_801651C0 + 120.0f))
    {
        sp24->unk40 = 0.0f;
    }
    else
    {
        sp24->unk40 = func_80015538(360.0f, -gPlayerObject->Rot.x);
    }
    sp24->unk44 = 24.0f;
    sp24->Scale.z = 1.0f;
    sp24->Scale.x = sp24->Scale.y = sp24->Scale.z;
    D_8016E100 = 0;
    D_8016E2F8 = 0;
}

void func_8007C06C(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    s32 sp1C;
    struct ObjectStruct *sp18;

    sp1C = func_8007944C();
    if (sp1C != -1)
    {
        func_8007BD30(sp1C);
        sp18 = &gObjects[sp1C];
        sp18->unkA4 = 0x13;
        sp18->unkD4 = gPlayerObject->Pos.y;
        sp18->Pos.x = arg1;
        sp18->Pos.y = arg2;
        sp18->Pos.z = arg3;
        sp18->unk40 = 0.0f;
        sp18->unk3C = func_80015538(gPlayerObject->Rot.y, D_8010C8FC[arg0]);
        sp18->unk44 = 24.0f;
        func_800799A8(sp1C);
        func_80079AD8(sp1C);
    }
}

void func_8007C1B0(void)
{
    UNUSED s32 pad[2];
    s32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    sp24 = ((s16)D_8016E2F8 / 21) + 2;
    if (sp24 >= 4)
    {
        sp24 = 4;
    }
    sp20 = gObjects[D_8016E100].Pos.x;
    sp1C = gObjects[D_8016E100].Pos.y;
    sp18 = gObjects[D_8016E100].Pos.z;
    func_8001A928((s32)D_8016E100);
    D_8016E2F8 = 0;
    D_8016E100 = 0;
    if (sp24 == 2)
    {
        func_8007C06C(1, sp20, sp1C, sp18);
        func_8007C06C(2, sp20, sp1C, sp18);
    }
    else if (sp24 == 3)
    {
        func_8007C06C(3, sp20, sp1C, sp18);
        func_8007C06C(4, sp20, sp1C, sp18);
        func_8007C06C(5, sp20, sp1C, sp18);
    }
    else
    {
        func_8007C06C(6, sp20, sp1C, sp18);
        func_8007C06C(7, sp20, sp1C, sp18);
        func_8007C06C(8, sp20, sp1C, sp18);
        func_8007C06C(9, sp20, sp1C, sp18);
    }
}

void func_8007C39C(s32 arg0)
{
    struct ObjectStruct *sp24;
    s32 sp20;
    s16 *sp1C;
    s32 sp18;

    sp24 = &gObjects[arg0];
    sp20 = (s32)((func_8001B62C(0, 0) - 2.0f) / 2.0f);
    if (sp20 < 0)
    {
        sp20 = (s32)(func_8001B580(0, 0) / 2.0f);
    }
    sp1C = NULL;
    sp18 = func_8001B880(0, 0);
    if (sp18 == 1)
    {
        sp1C = &D_8010C448;
        sp20 = 0;
    }
    else if (sp18 == 6)
    {
        sp1C = &D_8010C450;
        sp20 = 0;
    }
    else
    {
        if (sp18 == 7)
        {
            sp1C = &D_8010C458;
        }
        else if (sp18 == 8)
        {
            sp1C = &D_8010C49C;
        }
        else if (sp18 == 9)
        {
            sp1C = &D_8010C4E0;
        }
        else if (sp18 == 0xD)
        {
            sp1C = &D_8010C56C;
            sp20 = 0;
        }
        else if (sp18 == 0xE)
        {
            sp1C = &D_8010C574;
        }
        else if (sp18 == 0xF)
        {
            sp1C = &D_8010C5B8;
        }
    }
    if (sp1C != NULL)
    {
        func_80079BEC(&sp24->Pos.x, sp20, sp1C, 0.0f);
    }
    else
    {
        func_80079874(arg0);
        func_80079960(arg0);
    }
    sp24->Rot.y = func_80015538(gPlayerObject->Rot.y, 180.0f);
    sp24->Rot.x = func_80015538(360.0f, -gPlayerObject->Rot.x);
}

void func_8007C640(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    func_8007C39C(arg0);
    func_80079778(arg0);
    func_800797FC(arg0);
    if (sp1C->unkA8 == 0x64)
    {
        sp1C->unkA4 = 0x11;
    }
}

void func_8007C6D4(s32 arg0)
{
    struct ObjectStruct *sp34;
    f32 sp30;

    sp34 = &gObjects[arg0];
    func_8007C39C(arg0);
    if (D_8016E2F8 != 0)
    {
        sp30 = (f32)(((s16)D_8016E2F8 / 21) + 1);
        if (sp30 >= 3.0f)
        {
            sp30 = 3.0f;
        }
        sp34->Scale.x = sp34->Scale.y = sp34->Scale.z = (((f64)sp30 * 0.25) + 1.0);
        if (D_8016E2F8 == 1)
        {
            func_8001ABF4(arg0, 0, 0, &D_8011649C + 1);
        }
        else if (D_8016E2F8 == 0x15)
        {
            func_8001ABF4(arg0, 0, 0, &D_8011649C + 1);
        }
        else if (D_8016E2F8 == 0x2A)
        {
            func_8001ABF4(arg0, 0, 0, &D_8011649C + 2);
        }
    }
}

void func_8007C8A0(s32 arg0)
{
    struct ObjectStruct *sp6C;
    f32 sp68;
    s32 sp64;
    struct ObjectStruct *sp60;
    UNUSED s32 pad5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    u64 sp3C;
    s32 sp34;

    sp6C = &gObjects[arg0];
    sp6C->unk108 = 1;
    func_8006828C();
    func_8007897C(arg0);

    sp60 = &gObjects[0xE];

    for (sp34 = 0; sp34 < 64; sp34++, sp60++)
    {
        if ((sp60->unkA4 != 0))
        {
            sp58 = sp60->Pos.x - sp6C->Pos.x;
            sp54 = sp60->Pos.y - sp6C->Pos.y;
            sp50 = sp60->Pos.z - sp6C->Pos.z;
            sp3C = (sp58 * sp58) + ((sp54 * sp54)) + (sp50 * sp50);

            if ((sp3C < 0xE1000U))
            {
                if ((sp60->Pos.z < sp6C->Pos.z))
                {
                    if ((D_80124D90[sp60->unkE4].unk1 != 0))
                    {
                        sp4C = sp58;
                        sp48 = sp54;
                        sp44 = sp50;
                        break;
                    }
                }
            }
        }
    }

    if (sp34 != 64)
    {
        sp68 = func_80015634(sp4C, sp44);
        sp64 = func_800157EC(sp6C->unk3C, sp68, 2.0f);
        sp6C->unk3C = func_80015538(sp6C->unk3C, (f32)sp64);
        sp68 = func_800156C4(sp4C, sp48);
        sp68 = func_80015744(sp68);
        sp64 = func_800157EC(sp6C->unk40, sp68, 2.0f);
        sp6C->unk40 = func_80015538(sp6C->unk40, (f32)sp64);
    }
    sp6C->Rot.y = func_80015538(sp6C->unk3C, -180.0f);
    sp6C->Rot.x = sp6C->unk40;
    func_800799A8(arg0);
    func_80079AD8(arg0);
    if (func_80078AEC(arg0) != 0)
    {
        func_800795C8(arg0);
        return;
    }
    sp6C->unkA6 -= 1;
    if (sp6C->unkA6 == 0)
    {
        func_800795C8(arg0);
        return;
    }
    if (sp6C->unkB2 == 0)
    {
        func_80081468(0x2C5, sp6C->Pos.x - (sinf((f32)((f64)sp6C->unk3C * 0.0174532925199432955)) * 20.0f), sp6C->Pos.y, sp6C->Pos.z - (cosf((f32)((f64)sp6C->unk3C * 0.0174532925199432955)) * 20.0f));
        sp6C->unkB2 = 1;
    }
    else
    {
        sp6C->unkB2 -= 1;
    }
}

void func_8007CCE8(s32 arg0)
{
    struct ObjectStruct *sp1C;

    func_800794C4(arg0);
    sp1C = &gObjects[arg0];
    func_8001BD44(arg0, 0, 2, (s32)gFileArray[0xB].ptr);
    sp1C->unkE4 = 0xD;
    sp1C->unkA6 = 0x3C;
    sp1C->unkA8 = 0x14;
    sp1C->unkAA = 0;
    sp1C->unkAE = 0xFF;
    sp1C->unkB0 = 0;
    sp1C->unkD4 = gPlayerObject->Pos.y;
    func_80019448(arg0, 2, 0, 1);
    func_8001ABF4(arg0, 0, 0, &D_80116540);
}

void func_8007CDE8(void)
{
    s32 sp1C;
    struct ObjectStruct *sp18;

    sp1C = func_8007944C();
    if (sp1C != -1)
    {
        func_8007CCE8(sp1C);
        sp18 = &gObjects[sp1C];
        sp18->unkA4 = 0x18;
        sp18->Pos.x = gPlayerObject->Pos.x;
        sp18->Pos.y = gPlayerObject->Pos.y;
        sp18->Pos.z = gPlayerObject->Pos.z;
        D_8016E100 = (s16)sp1C;
    }
}

void func_8007CEB8(void)
{
    struct ObjectStruct *sp4;

    sp4 = &gObjects[D_8016E100];
    sp4->unkA4 = 0x1A;
    sp4->unkD4 = gPlayerObject->Pos.y;
    sp4->unk3C = 180.0f;
    sp4->unk40 = 0.0f;
    sp4->unk44 = 40.0f;
    sp4->Scale.x = sp4->Scale.y = sp4->Scale.z = 1.0f;
    D_8016E100 = 0;
    D_8016E2F8 = 0;
}

void func_8007CF98(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    s32 sp1C;
    struct ObjectStruct *sp18;

    sp1C = func_8007944C();
    if (sp1C != -1)
    {
        func_8007CCE8(sp1C);
        sp18 = &gObjects[sp1C];
        sp18->unkA4 = 0x1B;
        sp18->unkD4 = gPlayerObject->Pos.y;
        sp18->Pos.x = arg1;
        sp18->Pos.y = arg2;
        sp18->Pos.z = arg3;
        sp18->unk40 = 0.0f;
        sp18->unk3C = func_80015538(gPlayerObject->Rot.y, D_8010C924[arg0]);
        sp18->unk44 = 40.0f;
        func_800799A8(sp1C);
        func_80079AD8(sp1C);
    }
}

void func_8007D0DC(void)
{
    UNUSED s32 pad[2];
    s32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    sp24 = ((s16)D_8016E2F8 / 21) + 2;
    if (sp24 >= 4)
    {
        sp24 = 4;
    }
    sp20 = gObjects[D_8016E100].Pos.x;
    sp1C = gObjects[D_8016E100].Pos.y;
    sp18 = gObjects[D_8016E100].Pos.z;
    func_8001A928((s32)D_8016E100);
    D_8016E2F8 = 0;
    D_8016E100 = 0;
    if (sp24 == 2)
    {
        func_8007CF98(1, sp20, sp1C, sp18);
        func_8007CF98(2, sp20, sp1C, sp18);
    }
    else if (sp24 == 3)
    {
        func_8007CF98(3, sp20, sp1C, sp18);
        func_8007CF98(4, sp20, sp1C, sp18);
        func_8007CF98(5, sp20, sp1C, sp18);
    }
    else
    {
        func_8007CF98(6, sp20, sp1C, sp18);
        func_8007CF98(7, sp20, sp1C, sp18);
        func_8007CF98(8, sp20, sp1C, sp18);
        func_8007CF98(9, sp20, sp1C, sp18);
    }
}

void func_8007D2C8(s32 arg0)
{
    struct ObjectStruct *sp24;
    s32 sp20;
    s16 *sp1C;
    s32 sp18;

    sp24 = &gObjects[arg0];
    sp20 = (s32)((func_8001B62C(0, 0) - 2.0f) / 2.0f);
    if (sp20 < 0)
    {
        sp20 = (s32)(func_8001B580(0, 0) / 2.0f);
    }
    sp1C = NULL;
    sp18 = func_8001B880(0, 0);
    if (sp18 == 8)
    {
        sp1C = &D_8010C5FC;
        sp20 = 0;
    }
    else if (sp18 == 9)
    {
        sp1C = &D_8010C640;
        sp20 = 0;
    }
    else if (sp18 == 0xA)
    {
        sp1C = &D_8010C5FC;
    }
    else if (sp18 == 0xB)
    {
        sp1C = &D_8010C640;
    }
    else if (sp18 == 0xC)
    {
        sp1C = &D_8010C684;
    }
    if (sp1C != NULL)
    {
        func_80079BEC(&sp24->Pos.x, sp20, sp1C, 0.0f);
    }
    else
    {
        func_80079874(arg0);
        func_80079960(arg0);
    }
    sp24->Rot.y = func_80015538(gPlayerObject->Rot.y, 180.0f);
    sp24->Rot.x = func_80015538(360.0f, -gPlayerObject->Rot.x);
}

void func_8007D508(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    func_8007D2C8(arg0);
    func_80079778(arg0);
    func_800797FC(arg0);
    if (sp1C->unkA8 == 0x64)
    {
        sp1C->unkA4 = 0x19;
    }
}

void func_8007D59C(s32 arg0)
{
    struct ObjectStruct *sp34;
    f32 sp30;

    sp34 = &gObjects[arg0];
    func_8007D2C8(arg0);
    if (D_8016E2F8 != 0)
    {
        sp30 = (f32)(((s16)D_8016E2F8 / 21) + 1);
        if (sp30 >= 3.0f)
        {
            sp30 = 3.0f;
        }
        sp34->Scale.x = sp34->Scale.y = sp34->Scale.z = (f32)(((f64)sp30 * 0.25) + 1.0);
        if (D_8016E2F8 == 1)
        {
            func_8001ABF4(arg0, 0, 0, &D_80116540 + 1);
        }
        else if (D_8016E2F8 == 0x15)
        {
            func_8001ABF4(arg0, 0, 0, &D_80116540 + 1);
        }
        else if (D_8016E2F8 == 0x2A)
        {
            func_8001ABF4(arg0, 0, 0, &D_80116540 + 2);
        }
    }
}

void func_8007D768(s32 arg0)
{
    struct ObjectStruct *sp34;

    sp34 = &gObjects[arg0];
    sp34->unk108 = 1;
    func_8006828C();
    func_8007897C(arg0);
    func_800799A8(arg0);
    func_80079AD8(arg0);
    if (func_80078AEC(arg0) != 0)
    {
        func_800795C8(arg0);
        return;
    }
    sp34->unkA6 -= 1;
    if (sp34->unkA6 == 0)
    {
        func_800795C8(arg0);
        return;
    }
    if (sp34->unkB2 == 0)
    {
        func_80081468(0x2C5, sp34->Pos.x - (sinf((f32)((f64)sp34->unk3C * 0.0174532925199432955)) * 20.0f), sp34->Pos.y, sp34->Pos.z - (cosf((f32)((f64)sp34->unk3C * 0.0174532925199432955)) * 20.0f));
        sp34->unkB2 = 1;
    }
    else
    {
        sp34->unkB2 -= 1;
    }
}

void func_8007D944(s32 arg0)
{
    struct ObjectStruct *sp1C;

    func_800794C4(arg0);
    sp1C = &gObjects[arg0];
    func_8001BD44(arg0, 0, 2, (s32)gFileArray[0xC].ptr);
    sp1C->unkE4 = 0xE;
    sp1C->unkA6 = 0x3C;
    sp1C->unkA8 = 0x14;
    sp1C->unkAA = 0;
    sp1C->unkAE = 0xFF;
    sp1C->unkB0 = 0;
    sp1C->unkD4 = gPlayerObject->Pos.y;
    func_80019448(arg0, 2, 0, 1);
    func_8001ABF4(arg0, 0, 0, &D_801165E4);
}

void func_8007DA44(void)
{
    s32 sp1C;
    struct ObjectStruct *sp18;

    sp1C = func_8007944C();
    if (sp1C != -1)
    {
        func_8007D944(sp1C);
        sp18 = &gObjects[sp1C];
        sp18->unkA4 = 0x30;
        sp18->Pos.x = gPlayerObject->Pos.x;
        sp18->Pos.y = gPlayerObject->Pos.y;
        sp18->Pos.z = gPlayerObject->Pos.z;
        sp18->unk3C = gPlayerObject->Rot.y;
        D_8016E100 = (s16)sp1C;
    }
}

void func_8007DB2C(void)
{
    struct ObjectStruct *sp4;

    sp4 = &gObjects[D_8016E100];
    sp4->unkA4 = 0x32;
    sp4->unkD4 = gPlayerObject->Pos.y;
    sp4->unk44 = 14.0f;
    sp4->unk3C = 0.0f;
    sp4->unk40 = 270.0f;
    sp4->Scale.x = sp4->Scale.y = sp4->Scale.z = 1.0f;
    D_8016E100 = 0;
    D_8016E2F8 = 0;
}

void func_8007DC0C(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    s32 sp1C;
    struct ObjectStruct *sp18;

    sp1C = func_8007944C();
    if (sp1C != -1)
    {
        func_8007D944(sp1C);
        sp18 = &gObjects[sp1C];
        sp18->unkA4 = 0x32;
        sp18->unkD4 = gPlayerObject->Pos.y;
        sp18->Pos.x = arg1;
        sp18->Pos.y = arg2;
        sp18->Pos.z = arg3;
        sp18->unk40 = D_8010C94C[arg0].y;
        sp18->unk3C = func_80015538(gPlayerObject->Rot.y, D_8010C94C[arg0].x);
        sp18->unk44 = 14.0f;
        func_800799A8(sp1C);
        func_80079AD8(sp1C);
    }
}

void func_8007DD60(void)
{
    UNUSED s32 pad[2];
    s32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    sp24 = ((s16)D_8016E2F8 / 21) + 2;
    if (sp24 >= 4)
    {
        sp24 = 4;
    }
    sp20 = gObjects[D_8016E100].Pos.x;
    sp1C = gObjects[D_8016E100].Pos.y;
    sp18 = gObjects[D_8016E100].Pos.z;
    func_8001A928((s32)D_8016E100);
    D_8016E2F8 = 0;
    D_8016E100 = 0;
    if (sp24 == 2)
    {
        func_8007DC0C(1, sp20, sp1C, sp18);
        func_8007DC0C(2, sp20, sp1C, sp18);
    }
    else if (sp24 == 3)
    {
        func_8007DC0C(3, sp20, sp1C, sp18);
        func_8007DC0C(4, sp20, sp1C, sp18);
        func_8007DC0C(5, sp20, sp1C, sp18);
    }
    else
    {
        func_8007DC0C(6, sp20, sp1C, sp18);
        func_8007DC0C(7, sp20, sp1C, sp18);
        func_8007DC0C(8, sp20, sp1C, sp18);
        func_8007DC0C(9, sp20, sp1C, sp18);
    }
}

void func_8007DF4C(s32 arg0)
{
    struct ObjectStruct *sp1C;
    s32 sp18;

    sp1C = &gObjects[arg0];
    sp18 = (s32)((func_8001B62C(0, 0) - 2.0f) / 2.0f);
    if (sp18 < 0)
    {
        sp18 = (s32)(func_8001B580(0, 0) / 2.0f);
    }
    func_80079BEC(&sp1C->Pos.x, sp18, &D_8010C74C, 0.0f);
}

void func_8007E058(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    func_8007DF4C(arg0);
    func_80079778(arg0);
    func_800797FC(arg0);
    if (sp1C->unkA8 == 0x64)
    {
        sp1C->unkA4 = 0x31;
    }
}

void func_8007E0EC(s32 arg0)
{
    struct ObjectStruct *sp34;
    f32 sp30;

    sp34 = &gObjects[arg0];
    func_8007DF4C(arg0);
    if (D_8016E2F8 != 0)
    {
        sp30 = (f32)(((s16)D_8016E2F8 / 21) + 1);
        if (sp30 >= 3.0f)
        {
            sp30 = 3.0f;
        }
        sp34->Scale.x = sp34->Scale.y = sp34->Scale.z = (f32)(((f64)sp30 * 0.25) + 1.0);
        if (D_8016E2F8 == 1)
        {
            func_8001ABF4(arg0, 0, 0, &D_801165E4 + 1);
        }
        else if (D_8016E2F8 == 0x15)
        {
            func_8001ABF4(arg0, 0, 0, &D_801165E4 + 1);
        }
        else if (D_8016E2F8 == 0x2A)
        {
            func_8001ABF4(arg0, 0, 0, &D_801165E4 + 2);
        }
    }
}

void func_8007E2B8(s32 arg0)
{
    struct ObjectStruct *sp5C;
    UNUSED char pad[0x40];

    sp5C = &gObjects[arg0];
    sp5C->unk108 = 1;
    func_800682E0(arg0, 30.0f, 1);
    D_8016E238 = 1;
    D_8016E240 = arg0;
    func_80085884();
    func_8007897C(arg0);
    func_800799A8(arg0);
    func_80079AD8(arg0);
    if (func_80078AEC(arg0) != 0)
    {
        func_800795C8(arg0);
        return;
    }
    if (func_80079D48(arg0) != 0)
    {
        return;
    }
    sp5C->unkA6 -= 1;
    if (sp5C->unkA6 == 0)
    {
        func_800795C8(arg0);
        return;
    }
    if (sp5C->unkB2 == 0)
    {
        func_80081468(0x2C5, sp5C->Pos.x, sp5C->Pos.y + 20.0f, sp5C->Pos.z);
        sp5C->unkB2 = 3;
    }
    else
    {
        sp5C->unkB2 -= 1;
    }
}

void func_8007E454(void)
{
    s32 sp1C;

    for (sp1C = 2; sp1C < 6; sp1C++)
    {
        if (gObjects[sp1C].unkA4)
        {
            switch (gObjects[sp1C].unkA4)
            {
            case 7:
                func_80079D18(sp1C);
                break;
            case 16:
                func_8007C640(sp1C);
                break;
            case 17:
                func_8007C6D4(sp1C);
                break;
            case 18:
            case 19:
                func_8007C8A0(sp1C);
                break;
            case 24:
                func_8007D508(sp1C);
                break;
            case 25:
                func_8007D59C(sp1C);
                break;
            case 26:
            case 27:
                func_8007D768(sp1C);
                break;
            case 48:
                func_8007E058(sp1C);
                break;
            case 49:
                func_8007E0EC(sp1C);
                break;
            case 50:
                func_8007E2B8(sp1C);
                break;
            case 32:
                func_8007A938(sp1C);
                break;
            case 35:
                func_8007AA80(sp1C);
                break;
            case 36:
            case 37:
                func_8007AD60(sp1C);
                break;
            case 38:
            case 39:
                func_8007B5A0(sp1C);
                break;
            case 33:
                func_8007B004(sp1C);
                break;
            case 34:
                func_8007B268(sp1C);
                break;
            case 40:
            case 41:
            case 42:
                func_8007B928(sp1C);
                break;
            }
            func_8001AD6C(sp1C);
        }
    }
}

void func_8007E678(void)
{
    s32 sp1C;

    func_8001838C();
    for (sp1C = 2; sp1C < 6; sp1C++)
    {
        if ((gObjects[sp1C].unkA4 != 0))
        {
            if (func_8001C1A8(sp1C, 0))
            {
                func_8001B014(sp1C, 0);
                func_8001C384(sp1C, 0);
            }
        }
    }
}
