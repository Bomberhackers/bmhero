#include "common.h"
#include "7B0A0.h"
#include "69AA0.h"

// rodata
extern f32 D_801133EC;
extern f32 D_801133F0;
extern f32 D_801133E8;
extern u32 D_801131F0;
extern f64 D_801133E0;
extern UNK_TYPE D_801133B8[];
extern struct UnkStruct_80027C00 D_801133D4; // rodata...?

void func_8008E4A4(u32);
void func_8008E788(u32, s16); /* extern */
void func_8008E9DC(s16);
void func_8008ED8C(s16);
void func_8008D188(s16);
void func_8008D3F8(s16);
void func_8008DD54(s16);
void func_8008F1DC(s16);
void func_8008DA20(s16);
void func_80094680(); /* extern */
void func_8009473C(); /* extern */
s32 func_8008E074(s32 arg0, f32 *arg1, f32 arg2);
void func_8008E190(s16 arg0);
void func_8008F710(u32, s16);

// BYTECODE PARSER

void func_8008BCC0(void)
{
    u32 sp24;

    sp24 = D_80134D48->ObjectID;
    if (D_80134C28[0] == 0)
    {
        gObjects->unk44 = 0.0f;
        D_80134D48->unkC = 0;
        D_80134C28[0] = -1;
    }
    else if (D_80134C28[0] != -1)
    {
        D_80134C28[0] -= 1;
    }

    if (D_80134C58[0] == 0)
    {
        gObjects->Vel.y = 0.0f;
        D_80134C58[0] = -1;
    }
    else if (D_80134C58[0] != -1)
    {
        D_80134C58[0] -= 1;
    }

    if (D_80134C88[0] == 0)
    {
        gObjects[sp24].unk30.x = 0;
        gObjects[sp24].unk30.y = 0;
        D_80134C88[0] = -1;
    }
    else if (D_80134C88[0] != -1)
    {
        D_80134C88[0] -= 1;
    }

    if (D_80134CB8[0] == 0)
    {
        func_8001BB34((s32)sp24, 0);
        D_80134CB8[0] = -1;
    }
    else if (D_80134CB8[0] != -1)
    {
        func_8008ED8C(0);
        D_80134CB8[0] -= 1;
    }

    if (D_80134CE8[0] == 0)
    {
        gObjects[sp24].unkD8 = 0;
        gObjects[sp24].unkDC = 0;
        gObjects[sp24].unkE0 = 0;
        D_80134CE8[0] = -1;
    }
    else if (D_80134CE8[0] != -1)
    {
        D_80134CE8[0] -= 1;
    }

    func_8008E9DC(0);
    func_8008D188(0);
    func_8008F1DC(0);

    if (D_80134D18[0] == 1)
    {
        func_8008DD54(0);
    }
    else
    {
        func_8008D3F8(0);
    }

    if (gObjects[sp24].unkA4 != 0)
    {
        func_8001CEF4((s32)sp24);
        func_8001CD20((s32)sp24);
        func_8001AD6C((s32)sp24);
    }

    if ((u8)D_80134C24 == 1)
    {
        if ((u8)D_80134C25 == 0)
        {
            func_800175F0(-1, 0, 0x4C, -1, 0);
            D_80134C25 = 0xF;
        }
        D_80134C25 = (u8)D_80134C25 - 1;
    }
    else if ((u8)D_80134C24 == 2)
    {
        if ((u8)D_80134C25 == 0)
        {
            func_800175F0(-1, 0, 0x4D, -1, 0);
            D_80134C25 = 0xA;
        }
        D_80134C25 = (u8)D_80134C25 - 1;
    }
}

void func_8008C128(void)
{
    u32 sp1C;
    s16 sp1A;

    for (sp1A = 1; sp1A < 0x18; sp1A++)
    {
        if (D_80134D48[sp1A].ObjectID != -1)
        {
            sp1C = D_80134D48[sp1A].ObjectID;

            if (D_80134C28[sp1A] == 0)
            {
                gObjects[sp1C].unk44 = 0;
                D_80134D48[sp1A].unkC = 0;
                D_80134C28[sp1A] = -1;
            }
            else if (D_80134C28[sp1A] != -1)
            {
                D_80134C28[sp1A]--;
            }

            if (D_80134C58[sp1A] == 0)
            {
                gObjects[sp1C].Vel.y = 0.0f;
                D_80134C58[sp1A] = -1;
            }
            else if (D_80134C58[sp1A] != -1)
            {
                D_80134C58[sp1A]--;
            }

            if (D_80134C88[sp1A] == 0)
            {
                gObjects[sp1C].unk30.x = 0.0f;
                gObjects[sp1C].unk30.y = 0.0f;
                D_80134C88[sp1A] = -1;
            }
            else if (D_80134C88[sp1A] != -1)
            {
                D_80134C88[sp1A]--;
            }

            if (D_80134CB8[sp1A] == 0)
            {
                func_8001BB34(sp1C, 0);
                D_80134CB8[sp1A] = -1;
            }
            else if (D_80134CB8[sp1A] != -1)
            {
                func_8008ED8C(sp1A);
                D_80134CB8[sp1A]--;
            }

            if (D_80134CE8[sp1A] == 0)
            {
                gObjects[sp1C].unkD8 = 0;
                gObjects[sp1C].unkDC = 0;
                gObjects[sp1C].unkE0 = 0;
                D_80134CE8[sp1A] = -1;
            }
            else if (D_80134CE8[sp1A] != -1)
            {
                D_80134CE8[sp1A]--;
            }

            func_8008E9DC(sp1A);
            func_8008D188(sp1A);
            func_8008F1DC(sp1A);

            if (D_80134D18[sp1A] == 1)
            {
                func_8008DD54(sp1A);
            }
            else
            {
                func_8008D3F8(sp1A);
            }

            func_8008E190(sp1A);
            func_8001CEF4(sp1C);
            func_8001CD20(sp1C);
            func_8001AD6C(sp1C);
        }
    }
}

void func_8008C61C(void)
{
    D_80176606 = 1;
}

void func_8008C638(void)
{
    D_80176606 = 0;
}

void func_8008C650(void)
{
    D_8017660A = 1;
}

void func_8008C66C(void)
{
    D_8017660A = 0;
}

void func_8008C684(s16 *arg0)
{
    s32 sp4;
    for (sp4 = 0; sp4 < 0x4E; sp4++)
    {
        if (gObjects[sp4].unkE4 == arg0[0])
        {
            D_80134D48[arg0[1]].ObjectID = sp4;
            D_80134D48[arg0[1]].unk4 = arg0[2] / 10.0f;
            D_80134D48[arg0[1]].unk8 = arg0[3] / 10.0f;
            break;
        }
    }
}

void func_8008C778(s16 *arg0)
{
    u32 spC;
    s32 sp8;
    s16 i;

    spC = D_80134D48[arg0[0]].ObjectID;

    gObjects[spC].Pos.x = arg0[1];
    gObjects[spC].Pos.y = arg0[2];
    gObjects[spC].Pos.z = arg0[3];

    gObjects[spC].Rot.y = arg0[4];

    for (i = 0; i < 0xA; i++)
    {
        sp8 = gObjects[spC].unkE8[i];
        if (sp8 != -1)
        {
            gObjects[sp8].Pos.x = gObjects[spC].Pos.x;
            gObjects[sp8].Pos.y = gObjects[spC].Pos.y;
            gObjects[sp8].Pos.z = gObjects[spC].Pos.z;
        }
    }
}

void func_8008C9B4(s16 *arg0)
{
    u32 spC;
    s32 sp8;
    s16 i;

    spC = D_80134D48[arg0[0]].ObjectID;
    gObjects[spC].unk30.x = arg0[1] / 10.0f;

    for (i = 0; i < 0xA; i++)
    {
        sp8 = gObjects[spC].unkE8[i];
        if (sp8 != -1)
        {
            gObjects[sp8].unk30.x = gObjects[spC].unk30.x;
        }
    }
}

void func_8008CADC(s16 *arg0)
{
    u32 spC;
    s32 sp8;
    s16 i;

    spC = D_80134D48[arg0[0]].ObjectID;
    gObjects[spC].unk30.y = arg0[1] / 10.0f;

    for (i = 0; i < 0xA; i++)
    {
        sp8 = gObjects[spC].unkE8[i];

        if (sp8 != -1)
        {
            gObjects[sp8].unk30.y = gObjects[spC].unk30.y;
        }
    }
}

void func_8008CC04(s16 *arg0)
{
    u32 spC;
    s32 sp8;
    s16 i;

    spC = D_80134D48[arg0[0]].ObjectID;
    gObjects[spC].unk30.z = arg0[1] / 10.0f;

    for (i = 0; i < 0xA; i++)
    {
        sp8 = gObjects[spC].unkE8[i];

        if (sp8 != -1)
        {
            gObjects[sp8].unk30.z = gObjects[spC].unk30.z;
        }
    }
}

void func_8008CD2C(s16 *arg0)
{
    u32 sp4;

    sp4 = D_80134D48[arg0[0]].ObjectID;

    gObjects[sp4].unk44 = arg0[1] / 10.0f;
    gObjects[sp4].unk3C = arg0[2] / 10.0f;

    if (arg0[1] == 0)
    {
        gObjects[sp4].unk60 = 0.0f;
        gObjects[sp4].unk5C = 0.0f;
    }

    D_80134D48[arg0[0]].unkC = (arg0[3] == 1) ? 1 : 0;
}

void func_8008CE8C(s16 *arg0)
{
    f32 sp2C;
    f32 sp28;
    u32 sp24;

    sp24 = D_80134D48[arg0[0]].ObjectID;
    sp2C = arg0[1] - gObjects[sp24].Pos.x;
    sp28 = arg0[2] - gObjects[sp24].Pos.z;

    gObjects[sp24].unk3C = func_80015634(sp2C, sp28);
    gObjects[sp24].unk44 = sqrtf((sp2C * sp2C) + (sp28 * sp28)) / arg0[3]; // pythagoras

    D_80134C28[arg0[0]] = arg0[3];

    if (arg0[4] == 1)
    {
        D_80134D48[arg0[0]].unkC = 1;
    }
    else
    {
        D_80134D48[arg0[0]].unkC = 0;
    }
}

void func_8008D074(s16 *arg0)
{
    UNUSED UNK_TYPE sp4;
    u32 sp0;
    sp0 = D_80134D48[arg0[0]].ObjectID;

    gObjects[sp0].Vel.y = (arg0[1] - gObjects[sp0].Pos.y) / arg0[2];
    D_80134C58[arg0[0]] = arg0[2];
}

void func_8008D114(s16 *arg0)
{
    UNUSED UNK_TYPE sp4;
    u32 sp0;

    sp0 = D_80134D48[arg0[0]].ObjectID;
    gObjects[sp0].Vel.y = arg0[1] / 10.0f;
}

void func_8008D188(s16 arg0)
{
    u32 sp24;
    s32 sp20;
    s16 sp1E;

    sp24 = D_80134D48[(s16)arg0].ObjectID;
    gObjects[sp24].Vel.x = gObjects[sp24].unk44 * sinf(gObjects[sp24].unk3C * 0.017453292519943295); // 1°
    gObjects[sp24].Vel.z = gObjects[sp24].unk44 * cosf(gObjects[sp24].unk3C * 0.017453292519943295);

    if (D_80134D48[arg0].unkE == 0)
    {
        func_8008DA20(arg0);
    }
    for (sp1E = 0; sp1E < 0xA; sp1E++)
    {
        sp20 = gObjects[sp24].unkE8[sp1E];
        if (sp20 != -1)
        {
            gObjects[sp20].Pos.x = gObjects[sp24].Pos.x + gObjects[sp24].Vel.x;
            gObjects[sp20].Pos.z = gObjects[sp24].Pos.z + gObjects[sp24].Vel.z;
        }
    }
}

void func_8008D3F8(s16 arg0)
{
    u32 sp24;
    s32 sp20;
    s16 i;

    sp24 = D_80134D48[(s16)arg0].ObjectID;
    if (D_80134D48[arg0].unkE == 0)
    {
        func_8008DA20(arg0);
    }

    for (i = 0; i < 0xA; i++)
    {
        sp20 = gObjects[sp24].unkE8[i];

        if (sp20 != -1)
        {
            gObjects[sp20].Pos.y = gObjects[sp24].Pos.y + gObjects[sp24].Vel.y;
        }
    }
}

void func_8008D530(s16 *arg0)
{
    UNUSED UNK_TYPE spC;
    UNUSED UNK_TYPE sp8;
    u32 sp4;

    sp4 = D_80134D48[arg0[0]].ObjectID;
    if (arg0[4] == 1)
    {
        if (arg0[1] / 10.0f < gObjects[sp4].Rot.x)
        {
            gObjects[sp4].unk30.x = (((arg0[1] / 10.0f) - gObjects[sp4].Rot.x) + 360.0f) / arg0[3];
        }
        else
        {
            gObjects[sp4].unk30.x = ((arg0[1] / 10.0f) - gObjects[sp4].Rot.x) / arg0[3];
        }
    }
    else if (arg0[1] / 10.0f <= gObjects[sp4].Rot.x)
    {
        gObjects[sp4].unk30.x = ((arg0[1] / 10.0f) - gObjects[sp4].Rot.x) / arg0[3];
    }
    else
    {
        gObjects[sp4].unk30.x = ((gObjects[sp4].Rot.x - (arg0[1] / 10.0f) + 360.0f) / arg0[3]) * -1.0f;
    }

    if (arg0[5] == 1)
    {
        if (arg0[2] / 10.0f < gObjects[sp4].Rot.y)
        {
            gObjects[sp4].unk30.y = (((arg0[2] / 10.0f) - gObjects[sp4].Rot.y) + 360.0f) / arg0[3];
        }
        else
        {
            gObjects[sp4].unk30.y = ((arg0[2] / 10.0f) - gObjects[sp4].Rot.y) / arg0[3];
        }
    }
    else if (arg0[2] / 10.0f <= gObjects[sp4].Rot.y)
    {
        gObjects[sp4].unk30.y = ((arg0[2] / 10.0f) - gObjects[sp4].Rot.y) / arg0[3];
    }
    else
    {
        gObjects[sp4].unk30.y = ((gObjects[sp4].Rot.y - (arg0[2] / 10.0f) + 360.0f) / arg0[3]) * -1.0f;
    }

    D_80134C88[arg0[0]] = arg0[3];
}

void func_8008DA20(s16 arg0)
{
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s16 sp26;
    u32 sp20;
    s32 sp1C;

    sp20 = D_80134D48[arg0].ObjectID;
    sp34 = gObjects[sp20].Pos.x + gObjects[sp20].Vel.x;
    sp30 = gObjects[sp20].Pos.y + gObjects[sp20].Vel.y + D_80134D48[arg0].unk8;
    sp2C = gObjects[sp20].Pos.z + gObjects[sp20].Vel.z;

    func_80067748(sp34, sp30, sp2C);
    sp28 = D_80177760[D_801776E0 & 1];

    if (D_80134D18[0] == 0)
    {
        gObjects[sp20].Vel.y = (sp28 - gObjects[sp20].Pos.y) - D_80134D48[arg0].unk8;
        for (sp26 = 0; sp26 < 0xA; sp26++)
        {
            sp1C = gObjects[sp20].unkE8[sp26];
            if (sp1C != -1)
            {
                gObjects[sp1C].Pos.y = gObjects[sp20].Pos.y + gObjects[sp20].Vel.y;
            }
        }
    }
}

void func_8008DC8C(s16 *arg0)
{
    u32 ObjectID;

    ObjectID = D_80134D48[arg0[0]].ObjectID;
    gObjects[ObjectID].Vel.y = arg0[1] / 10.0f;
    gObjects[ObjectID].unk4C = arg0[2] / 10.0f;
    D_80134D18[arg0[0]] = 1;
}

void func_8008DD54(s16 arg0)
{
    u32 sp24;
    s32 sp20;
    f32 sp1C;
    s16 sp1A;

    sp24 = D_80134D48[arg0].ObjectID;
    gObjects[sp24].Vel.y -= gObjects[sp24].unk4C;

    if (gObjects[sp24].Vel.y < -48.0f)
    {
        gObjects[sp24].Vel.y = -48.0f;
    }

    if (D_80134D48[sp24].unk10 == 0)
    {
        if (gObjects[sp24].Vel.y < 0.0f)
        {
            if (func_8008E074(sp24, &sp1C, D_80134D48[arg0].unk8) != 0)
            {
                gObjects[sp24].Vel.y = 0.0f;
                gObjects[sp24].Pos.y = sp1C - D_80134D48[arg0].unk8;

                D_80134D18[arg0] = 0;
            }
        }
        else if (func_8008E074(sp24, &sp1C, D_80134D48[arg0].unk4) != 0)
        {
            gObjects[sp24].Vel.y = 0.0f;
        }
    }

    for (sp1A = 0; sp1A < 0xA; sp1A++)
    {
        sp20 = gObjects[sp24].unkE8[sp1A];
        if (sp20 != -1)
        {
            gObjects[sp20].Pos.y = gObjects[sp24].Pos.y + gObjects[sp24].Vel.y;
        }
    }
}

s32 func_8008E074(s32 arg0, f32 *arg1, f32 arg2)
{
    struct Vec3f sp1C;

    sp1C.z = gObjects[arg0].Pos.x + gObjects[arg0].Vel.x;
    sp1C.y = gObjects[arg0].Pos.y + gObjects[arg0].Vel.y + arg2;
    sp1C.x = gObjects[arg0].Pos.z + gObjects[arg0].Vel.z;

    func_80067748(sp1C.z, sp1C.y, sp1C.x);

    *arg1 = D_80177760[1];
    return D_801776E0 & 1;
}

void func_8008E190(s16 arg0)
{
    u32 spC;
    s32 sp8;
    s16 sp6;
    s16 temp_t4;

    spC = D_80134D48[arg0].ObjectID;
    for (sp6 = 0; sp6 < 0xA; sp6++)
    {
        sp8 = gObjects[spC].unkE8[sp6];
        if (sp8 != -1)
        {
            gObjects[sp8].Rot.x = gObjects[spC].Rot.x + gObjects[spC].unk30.x;
            gObjects[sp8].Rot.y = gObjects[spC].Rot.y + gObjects[spC].unk30.y;
            gObjects[sp8].Rot.z = gObjects[spC].Rot.z + gObjects[spC].unk30.z;
        }
    }
}

void func_8008E328(s16 *arg0)
{
    u32 sp24;

    sp24 = D_80134D48[arg0[0]].ObjectID;
    func_8008E4A4(sp24);
    func_8001C0EC((s32)sp24, D_80134FB0, (s32)arg0[1], D_80134FB4, D_80134FB8);
}

void func_8008E3B0(s16 *arg0)
{
    u32 CurrentObject;

    CurrentObject = D_80134D48[arg0[0]].ObjectID;
    func_8001C158(CurrentObject, arg0[1], arg0[2]);
}

void func_8008E418(s16 *arg0)
{
    u32 sp24;

    sp24 = D_80134D48[arg0[0]].ObjectID;
    func_8008E788(sp24, arg0[1]);
    func_8001C0EC(sp24, arg0[1], arg0[2], D_80134FB4, D_80134FB8);
}

void func_8008E4A4(u32 arg0)
{
    switch (gObjects[arg0].unkE4)
    {
    case 0x266:
        D_80134FB0 = 0;
        D_80134FB4 = 0x223;
        D_80134FB8 = &D_80111888;
        break;
    case 0x244:
        D_80134FB0 = 0;
        D_80134FB4 = 0x22A;
        D_80134FB8 = &D_80116164;
        break;
    case 0x26A:
        D_80134FB0 = 0;
        D_80134FB4 = 0x275;
        D_80134FB8 = &D_80115CF8;
        break;
    case 0x281:
        D_80134FB0 = 0;
        D_80134FB4 = 0x28A;
        D_80134FB8 = &D_80116058;
        break;
    case 0x256:
        D_80134FB0 = 3;
        D_80134FB4 = 0x16A;
        D_80134FB8 = &D_80118914;
        break;
    case 0x25C:
        D_80134FB0 = 0;
        D_80134FB4 = 0x268;
        D_80134FB8 = &D_80112F30;
        break;
    case 0x25D:
        D_80134FB0 = 0;
        D_80134FB4 = 0x268;
        D_80134FB8 = &D_80112F30;
        break;
    case 0x25E:
        D_80134FB0 = 0;
        D_80134FB4 = 0x268;
        D_80134FB8 = &D_80112F30;
        break;
    case 0x25F:
        D_80134FB0 = 3;
        D_80134FB4 = 0x269;
        D_80134FB8 = &D_80112FC4;
        break;
    case 0x260:
        D_80134FB0 = 3;
        D_80134FB4 = 0x269;
        D_80134FB8 = &D_80112FC4;
        break;
    case 0x261:
        D_80134FB0 = 3;
        D_80134FB4 = 0x269;
        D_80134FB8 = &D_80112FC4;
        break;
    case 0x267:
        D_80134FB0 = 0;
        D_80134FB4 = 0x12B;
        D_80134FB8 = &D_8011313C;
        break;
    case 0x275:
        D_80134FB0 = 0;
        D_80134FB4 = 0x280;
        D_80134FB8 = &D_801131A0;
        break;
    case 0x280:
        D_80134FB0 = 3;
        D_80134FB4 = 0x288;
        D_80134FB8 = &D_801131A8;
        break;
    default:
        break;
    }
}

void func_8008E788(u32 arg0, s16 arg1)
{
    switch (gObjects[arg0].unkE4)
    {
    case 0xF8:
    {
        if (arg1 == 0)
        {
            D_80134FB8 = &D_8011694C;
        }
        else
            D_80134FB8 = &D_80116950;

        D_80134FB4 = 0xA5;

        break;
    }
    default:
        break;
    }
}

void func_8008E81C(s16 *arg0)
{
    u32 sp1C;

    sp1C = D_80134D48[arg0[0]].ObjectID;
    func_8008F710(sp1C, arg0[1]);
    func_8001ABF4((s32)sp1C, (s32)arg0[2], D_80134FC0, D_80134FC4);
}

void func_8008E8A4(s16 *arg0)
{
    u32 sp4;

    sp4 = D_80134D48[arg0[0]].ObjectID;
    gObjects[sp4].unk60 = arg0[1] / 10.0f;
}

void func_8008E918(s16 *arg0)
{
    u32 sp4;

    sp4 = D_80134D48[arg0[0]].ObjectID;
    gObjects[sp4].unk5C = (f32)arg0[1] / 10.0f;
    if (arg0[2] == 1)
    {
        D_80134D48[arg0[0]].unkC = 1;
    }
    else
    {
        D_80134D48[arg0[0]].unkC = 0;
    }
}

void func_8008E9DC(s16 arg0)
{
    u32 spC;
    UNUSED s32 sp8;
    UNUSED s32 sp4;

    spC = D_80134D48[arg0].ObjectID;
    gObjects[spC].unk3C += gObjects[spC].unk5C;
    gObjects[spC].unk44 += gObjects[spC].unk60;

    if (D_80134D48[arg0].unkC == 1)
    {
        gObjects[spC].Rot.y = gObjects[spC].unk3C + gObjects[spC].unk5C;
    }
}

void func_8008EAE4(s16 *arg0)
{
    D_80134D48[arg0[0]].unkE = 0;
}

void func_8008EB10(s16 *arg0)
{
    D_80134D48[arg0[0]].unkE = 1;
}

void func_8008EB40(s16 *arg0)
{
    D_80134D48[arg0[0]].unk10 = 0;
}

void func_8008EB6C(s16 *arg0)
{
    D_80134D48[arg0[0]].unk10 = 1;
}

void func_8008EB9C(s16 *arg0)
{
    func_8001BBDC(D_80134D48[arg0[0]].ObjectID, 1);
}

void func_8008EBEC(s16 *arg0)
{
    func_8001BBDC((s32)D_80134D48[arg0[0]].ObjectID, 0);
}

void func_8008EC3C(s16 *arg0)
{
    func_8001BB34((s32)D_80134D48[arg0[0]].ObjectID, 0);
    gObjects[D_80134D48[arg0[0]].ObjectID].unk13A = 0;
}

void func_8008ECD0(s16 *arg0)
{
    func_8001BB34((s32)D_80134D48[arg0[0]].ObjectID, 1);
    gObjects[D_80134D48[arg0[0]].ObjectID].unk13A = 1;
}

void func_8008ED64(s16 *arg0)
{
    D_80134CB8[arg0[0]] = arg0[1];
}

void func_8008ED8C(s16 arg0)
{
    u32 sp2C;
    s32 sp28;
    s16 sp26;

    sp2C = D_80134D48[arg0].ObjectID;
    func_8001BB34((s32)sp2C, !(D_80134CB8[arg0] & 1));
    if (D_80134CB8[arg0] & 1)
    {
        gObjects[sp2C].unk13A = 0;
    }
    else
    {
        gObjects[sp2C].unk13A = 1;
    }

    for (sp26 = 0; sp26 < 0xA; sp26++)
    {
        sp28 = (s32)gObjects[sp2C].unkE8[sp26];
        if (sp28 != -1)
        {
            func_8001BB34(sp28, !(D_80134CB8[arg0] & 1));

            if (D_80134CB8[arg0] & 1)
            {
                gObjects[sp28].unk13A = 0;
            }
            else
            {
                gObjects[sp28].unk13A = 1;
            }
        }
    }
}

void ByteParser_SetObjectScale(s16 *arg0)
{
    u32 spC;
    UNK_TYPE UNUSED sp8;
    UNK_TYPE UNUSED sp4;

    spC = D_80134D48[arg0[0]].ObjectID;
    gObjects[spC].Scale.x = arg0[1] / 10.0f;
    gObjects[spC].Scale.y = arg0[2] / 10.0f;
    gObjects[spC].Scale.z = arg0[3] / 10.0f;
}

void func_8008F078(s16 *arg0)
{
    UNUSED UNK_TYPE spC;
    UNUSED UNK_TYPE sp8;
    u32 sp4;

    sp4 = D_80134D48[arg0[0]].ObjectID;
    gObjects[sp4].unkD8 = ((arg0[1] / 10.0f) - gObjects[sp4].Scale.x) / arg0[4];
    gObjects[sp4].unkDC = ((arg0[2] / 10.0f) - gObjects[sp4].Scale.y) / arg0[4];
    gObjects[sp4].unkE0 = ((arg0[3] / 10.0f) - gObjects[sp4].Scale.z) / arg0[4];

    D_80134CE8[arg0[0]] = arg0[4];
}

void func_8008F1DC(s16 arg0)
{
    u32 spC;
    s32 sp8;
    s16 sp6;

    spC = D_80134D48[(s16)arg0].ObjectID;
    gObjects[spC].Scale.x = gObjects[spC].Scale.x + gObjects[spC].unkD8;
    gObjects[spC].Scale.y = gObjects[spC].Scale.y + gObjects[spC].unkDC;
    gObjects[spC].Scale.z = gObjects[spC].Scale.z + gObjects[spC].unkE0;

    for (sp6 = 0; sp6 < 0xA; sp6++)
    {
        sp8 = gObjects[spC].unkE8[sp6];
        if (sp8 != -1)
        {
            gObjects[sp8].Scale.x = gObjects[sp8].Scale.x + gObjects[sp8].unkD8;
            gObjects[sp8].Scale.y = gObjects[sp8].Scale.y + gObjects[sp8].unkDC;
            gObjects[sp8].Scale.z = gObjects[sp8].Scale.z + gObjects[sp8].unkE0;
        }
    }
}

void func_8008F3D4(s16 *arg0)
{
    u32 sp24;
    s32 sp20;
    s32 sp1C;
    s16 sp1A;

    sp24 = D_80134D48[arg0[0]].ObjectID;
    D_80134D48[arg0[0]].ObjectID = -1U;
    D_80134D48[arg0[0]].unk4 = 0.0f;
    D_80134D48[arg0[0]].unk8 = 0.0f;
    D_80134D48[arg0[0]].unkC = 0;
    D_80134D48[arg0[0]].unkE = 0;
    D_80134D48[arg0[0]].unk10 = 0;

    D_80134C28[arg0[0]] = -1;
    D_80134C58[arg0[0]] = -1;
    D_80134C88[arg0[0]] = -1;
    D_80134CB8[arg0[0]] = -1;
    D_80134CE8[arg0[0]] = -1;
    D_80134D18[arg0[0]] = 0;

    for (sp1A = 0; sp1A < 0xA; sp1A++)
    {
        sp20 = gObjects[sp24].unkE8[sp1A];
        if (sp20 != -1)
        {
            sp1C = func_800281A4(sp24, sp1A);
            func_8002B114(sp1C);
        }
    }

    func_8002B114(sp24);
}

void func_8008F63C(s16 *arg0)
{
    u32 sp24;

    sp24 = D_80134D48[arg0[0]].ObjectID;
    func_800178D4(sp24, arg0[1], arg0[2], arg0[3], arg0[4]);
}

void func_8008F6AC(s16 *arg0)
{
    u32 sp1C;

    sp1C = D_80134D48[arg0[0]].ObjectID;
    func_80017B3C(sp1C, arg0[1]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008F710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8008FFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800900DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800901EC.s")

void func_80090268(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801113CC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_801121A4);
    func_8001ABF4(sp24, 1, 0, &D_801121A4[14]);
    func_8001ABF4(sp24, 2, 0, &D_801121A4[28]);
    func_8001ABF4(sp24, 3, 0, &D_801121A4[42]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800903CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090448.s")

void func_800904DC(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_801113FC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, D_80111EB4 + 21);
    func_8001ABF4(sp24, 1, 0, D_80111EB4 + 56);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090590.s")

void func_8009060C(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_80111414, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_80112298);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800906A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009071C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800908C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090940.s")

void func_800909D4(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_80111468, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_80111EB4);
    func_8001ABF4(sp24, 1, 0, &D_80111EB4[42]);
}

void func_80090A84(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_80111474, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

void func_80090B00(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_80111480, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_80112414);
}

void func_80090B94(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_8011148C, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090C10.s")

void func_80090C8C(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_801114A4, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

void func_80090D08(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_801114B0, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

void func_80090D84(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_801114BC, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    func_8001ABF4(sp24, 0, 3, &D_80112518);
    func_8001ABF4(sp24, 1, 3, &D_80112518[1]);
    func_8001ABF4(sp24, 2, 3, &D_80112518[2]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090E50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80090FC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091040.s")

void func_800910BC(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_80111504, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091138.s")

void func_800911B4(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_8011151C, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091230.s")

void func_800912AC(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_80111534, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091328.s")

void func_800913A4(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_8011154C, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009149C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091644.s")

void func_800916C0(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_80111594, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009173C.s")

void func_800917D0(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_801115AC, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_8011263C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091864.s")

void func_800918E0(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_801115C4, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009195C.s")

void func_800919F0(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_801115DC, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_80112940);
    func_8001ABF4(sp24, 1, 0, &D_80112940[7]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80091FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009219C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092310.s")

void func_800923DC(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_801116A8, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092458.s")

void func_800924D4(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_801116C0, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    func_8001ABF4(sp24, 0, 3, D_80113118);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092568.s")

void func_800925E4(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_801116D8, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    func_8001C0EC(sp24, 0, 0, 0x26E, &D_80113134);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092680.s")

void func_800926FC(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_801116F0, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_80117E48);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092824.s")

void func_800928B8(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_80111714, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    func_8001C0EC(sp24, 3, 0, 0x278, &D_8011319C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800929D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092C38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092F1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80092FB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093054.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800930F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009318C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800932C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009359C.s")

void func_80093618(void)
{
    s32 sp24;
    s32 sp20;

    sp24 = func_80027464(2, &D_80111838, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    if (sp24 != -1)
    {
        func_80027B34(sp24, &D_80111828);
        sp20 = (gObjects[sp24].unkE8[0]);
        func_8001ABF4(sp20, 0, 0, &D_8011698C);
        func_8001ABF4(sp20, 1, 0, &D_8011698C + (0x1C / 4));
    }
}

void func_80093714(void)
{
    s32 sp24;
    s32 sp20;

    sp24 = func_80027464(2, &D_80111850, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    if (sp24 != -1)
    {
        func_80027B34(sp24, &D_80111828);
        sp20 = gObjects[sp24].unkE8[0];
        func_8001ABF4(sp20, 0, 0, &D_8011698C);
        func_8001ABF4(sp20, 1, 0, &D_8011698C + (0x1C / 4));
    }
}

void func_80093810(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_80111868, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, D_80111EB4 + 21);
    func_8001ABF4(sp24, 1, 0, D_80111EB4 + 56);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_800938C4.s")

struct UnkStruct_80027C00 *func_80093940(s32 arg0)
{
    return D_80113294[arg0];
}

void func_80093968(void)
{
    struct UnkStruct_80027C00 *sp24;
    s32 sp20;

    sp24 = func_80093940((s32)D_80165100->unk0);
    sp20 = func_80027464(1, sp24, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    if (sp20 != -1)
    {
        gObjects[sp20].unkA6 = D_80165100->unkA;
        gObjects[sp20].unkAC = 0;
        gObjects[sp20].unkD4 = 1.0f;
        gObjects[sp20].unkD8 = 56.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_80093AB8.s")

void func_80093B64(void)
{
    struct ObjectStruct *sp3C;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0)
    {
        sp3C->unk132 += 1;
        if (sp3C->unkE4 == 0x27)
        {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0x39, &D_801131F0);
        }
        sp3C->unk108 = 1;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BB04(gCurrentParsedObject, 0);
    }

    if (sp3C->unkD4 < 1.0f)
    {
        sp3C->unkD4 = sp3C->unkD4 + D_801133E0;
        if (sp3C->unkD4 >= 1.0f)
        {
            sp3C->unkD4 = 1.0f;
        }
        sp3C->Scale.x = sp3C->Scale.y = sp3C->Scale.z = sp3C->unkD4;
    }

    if (sp3C->unkD8 < 56.0f)
    {
        sp3C->unkD8 = sp3C->unkD8 + 0.5;
        if (sp3C->unkD8 >= 56.0f)
        {
            sp3C->unkD8 = 56.0f;
        }
    }

    sp3C->Rot.y = func_80015538(sp3C->Rot.y, 60.0f - sp3C->unkD8);

    if (sp3C->unkAC != 0)
    {
        sp3C->Vel.y -= sp3C->unk4C;
        if (sp3C->Vel.y < -24.0f)
        { // clamp
            sp3C->Vel.y = -24.0f;
        }

        sp3C->Pos.y += sp3C->Vel.y;
        func_80067748(sp3C->Pos.x, sp3C->Pos.y - 60.0f, sp3C->Pos.z);

        if (D_801776E0 & 1)
        {
            if ((D_80177740[D_801776E0 & 1] == 0xF5) || (D_80177740[D_801776E0 & 1] == 0xD9))
            {
                sp3C->unkA4 = 2;
                sp3C->unk132 = 0;
                return;
            }
            else
            {
                sp3C->unkAC = 0;
                sp3C->Pos.y = D_80177760[D_801776E0 & 1] + 60.0f;
                sp3C->Vel.y = 0.0f;
                sp3C->unk4C = 0.0f;
            }
        }
    }
}

void func_80093F30(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unkE4 == 0x32)
    {
        if (sp24->unk132 == 0)
        {
            sp24->unk132 += 1;
            sp24->unkB2 = 0;
            sp24->unk108 = 0;
            func_8001BB34(gCurrentParsedObject, 1);
            func_8001BB04(gCurrentParsedObject, 1);
            func_8002AE38(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 1.0f, 0x11);
        }
        if (sp24->unkB2 == 0x78)
        {
            sp24->unkA4 = 1;
            sp24->unk132 = 0;
            sp24->unkD4 = 0.0f;
            sp24->unkD8 = 0.0f;
        }
        else
        {
            sp24->unkB2 += 1;
        }
    }
    else
    {
        func_8002B0E4(gCurrentParsedObject);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009409C.s")

s32 func_80094128(void)
{
    s32 sp1C;
    s32 sp18;

    for (sp18 = 0; sp18 < 4; sp18++)
    {
        sp1C = func_80014E80(5);
        if (gFileArray[D_80124D90[sp1C + 32].unk24[0].unk0].ptr != NULL)
        {
            return sp1C;
        }
    }

    return 0;
}

void func_800941C4(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    struct UnkStruct_80027C00 *sp34;
    s32 sp30;

    if (arg0 == 0xC)
    {
        return;
    }

    if (gFileArray[D_80124D90[arg0 + 32].unk24[0].unk0].ptr != NULL)
    {
        sp34 = func_80093940(arg0 + 0x20);
        sp30 = func_80027464(1, sp34, arg1, arg2, arg3, 0.0f);
        if (sp30 != -1)
        {
            gObjects[sp30].unkD4 = 0.0f;
            gObjects[sp30].unkD8 = 0.0f;
            gObjects[sp30].Scale.x = gObjects[sp30].Scale.y = gObjects[sp30].Scale.z = D_801133E8;
        }
    }
}

void func_80094370(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    struct UnkStruct_80027C00 *sp34;
    s32 sp30;

    if (arg0 == 0xC)
    {
        return;
    }

    if (gFileArray[D_80124D90[arg0 + 32].unk24[0].unk0].ptr != NULL)
    {
        sp34 = func_80093940(arg0 + 0x20);
        sp30 = func_80027464(1, sp34, arg1, arg2, arg3, 0.0f);

        if (sp30 != -1)
        {
            gObjects[sp30].unkAC = 1;
            gObjects[sp30].unkD4 = 0.0f;
            gObjects[sp30].unkD8 = 0.0f;
            gObjects[sp30].unk4C = D_801133EC;
            gObjects[sp30].Scale.x = gObjects[sp30].Scale.y = gObjects[sp30].Scale.z = D_801133F0;
        }
    }
}

void func_80094570(void)
{
    func_80027464(1, &D_801133D4, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

void func_800945E8(void)
{
    if (D_80177A64 == 0)
    {
        gObjects[gCurrentParsedObject].unkA4 = 2;
    }
    else if (D_80177A64 == 1)
    {
    }
    else
    {
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_80094680(void)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0)
    {
        sp1C->unk132 += 1;
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_801133B8);
    }
    sp1C->Rot.y = func_80015538(sp1C->Rot.y, 4.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7E1E0/func_8009473C.s")

void func_8009476C(void)
{
    switch (gObjects[gCurrentParsedObject].unkA4)
    {
    case 1:
        func_80094680();
        break;
    case 2:
        func_8009473C();
        break;
    }
}
