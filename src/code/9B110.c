#include "common.h"

extern struct UnkStruct_80027C00 D_80113928;
extern u32 D_801175D0;

void func_800A8BF0(void)
{
    s16 sp26;

    sp26 = func_80027464(1, &D_80113928, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    if (sp26 != -1)
    {
        gObjects[sp26].unkA4 = 2;
        gObjects[sp26].unkA8 = 0;
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32)sp26, 0, 0, 0x81, &D_801175D0);
    }
}

void func_800A8D0C(void)
{
    if (D_80177A64 == 0)
    {
        gObjects[gCurrentParsedObject].unkA4 = 5;
    }
    else if (D_80177A64 == 1)
    {
        gObjects[gCurrentParsedObject].unkA4 = 6;
    }
    else
    {
        gObjects[gCurrentParsedObject].unkA4 = 7;
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

// #define UNK(x, y) ((((y) + (x)) > 180.0f) ? ((y) + (x) >= 360.0f ? ((x) + (y)) - 360.0f : (x) + (y)) : ((x) + (y)) < 0.0f ? (x) + (360.0f + x + 180.0f) : x + y + 180.0f )

void func_800A8DF8(void)
{
    struct ObjectStruct *sp44;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0)
    {
        sp44->unk132 = 1;
        sp44->unk3C = (func_80014E80(-0x5A) + (sp44->unk3C + 180.0f)) > 180.0f   ? ((func_80014E80(-0x5A) + (sp44->unk3C + 180.0f)) >= 360.0f ? ((f32)func_80014E80(-0x5A) + (sp44->unk3C + 180.0f)) - 360.0f : ((f32)func_80014E80(-0x5A) + (sp44->unk3C + 180.0f)))
                      : ((func_80014E80(-0x5A) + (sp44->unk3C + 180.0f)) < 0.0f) ? func_80014E80(-0x5A) + (360.0f + sp44->unk3C + 180.0f)
                                                                                 : func_80014E80(-0x5A) + (sp44->unk3C + 180.0f);
        ;
        sp44->unk3C = sp44->unk3C > 180.0f ? (sp44->unk3C >= 360.0f ? sp44->unk3C - 360.0f : sp44->unk3C) : (sp44->unk3C < 0.0f ? sp44->unk3C + 360.0f : sp44->unk3C);

        sp44->unk44 = 6.0f;
        sp44->unk48 = 0.0f;
        sp44->unkA6 = 0x12C;
        if (sp44->unkA8 == 0)
        {
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0x81, &D_801175D0);
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp44->unkA6 -= 6;
    sp44->Rot.y = sp44->unk3C;
    if (sp44->unkA6 < 0)
    {
        sp44->unkA4 = 1;
        sp44->unk132 = 0;
    }
    if (func_8002A1FC(gCurrentParsedObject, 600.0f) != 0)
    {
        sp44->unkA4 = 9;
        sp44->unk132 = 0;
    }
}

extern UNK_TYPE D_80117620;

void func_800A9260(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
        if (sp24->unkA8 == 0)
        {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0x81, &D_801175D0);
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->Rot.y = sp24->unk3C;
    sp24->unkA6 += 1;
    if (sp24->unkA6 == 0x14)
    {
        sp24->unkA4 = 8;
        if (sp24->unkA8 == 2)
        {
            sp24->unkA4 = 3;
        }
        sp24->unk132 = 0;
    }
    if (func_8002A1FC(gCurrentParsedObject, 600.0f) != 0)
    {
        sp24->unkA4 = 9;
        sp24->unk132 = 0;
    }
}

void func_800A9424(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk40 = 90.0f;
        if (sp24->unkA8 == 0)
        {
            sp24->unkA8 = 1;
            func_8001C0EC(gCurrentParsedObject, 0, 2, 0x81, &D_801175D0);
        }
    }
    if ((sp24->unk132 != 3) && (func_8001B44C(gCurrentParsedObject, 0) != 0))
    {
        if (sp24->unkA8 == 1)
        {
            sp24->unkA8 = 2;
            sp24->unk48 = 2.0f;
            sp24->unk132 = 2;
            func_8001C0EC(gCurrentParsedObject, 0, 5, 0x81, &D_801175D0);
        }
        else
        {
            sp24->unk48 = 0.0f;
            sp24->unk132 = 3;
            func_8001C0EC(gCurrentParsedObject, 0, 6, 0x81, &D_801175D0);
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->Rot.y = sp24->unk3C;
    if ((sp24->unk132 == 3) && (func_8001B44C(gCurrentParsedObject, 0) != 0))
    {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800A966C(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0x2D;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->unkA6 -= 1;
    if (sp2C->unkA6 <= 0)
    {
        sp2C->unkA4 = 8;
        sp2C->unk132 = 0;
    }
    if (func_8002A560(gCurrentParsedObject, 15.0f) == 0)
    {
        if (func_8002A1FC(gCurrentParsedObject, 720.0f) != 0)
        {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
        if (sp2C->unkA8 == 2)
        {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
    }
}

void func_800A98A0(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 12.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0x294;
        if (sp2C->unkA8 == 0)
        {
            func_8001C0EC(gCurrentParsedObject, 0, 3, 0x81, &D_801175D0);
        }
    }
    func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_8002A1FC(gCurrentParsedObject, 240.0f) != 0)
    {
        if (sp2C->unkA8 == 2)
        {
            sp2C->unkA4 = 4;
            sp2C->unk132 = 0;
        }
        else
        {
            sp2C->unkA4 = 9;
            sp2C->unk132 = 0;
        }
    }
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->unkA6 -= 0xC;
    if (sp2C->unkA6 < 0)
    {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
    }
}

extern f64 D_80114A20;
extern UNK_TYPE D_8011763C;

void func_800A9AEC(void)
{
    struct ObjectStruct *sp2C;
    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011763C);
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp2C->unkA6 += 1;
    if (sp2C->unkA6 & 1)
    {
        sp2C->Rot.z += 4.0f;
        func_800175F0(gCurrentParsedObject, 0, 0x17, -1, 0);
    }
    else
    {
        sp2C->Rot.z -= 4.0f;
    }
    if (sp2C->unkA6 >= 7)
    {
        if ((f64)sp2C->Scale.x <= 2.0)
        {
            sp2C->Scale.y = sp2C->Scale.z = sp2C->Scale.x += D_80114A20;
        }
        else
        {
            sp2C->unkA4 = 5;
            sp2C->unk132 = 0;
            return;
        }
    }
    if (sp2C->unkA6 >= 0xD)
    {
        sp2C->unkA6 = 0;
        sp2C->Rot.z = 0.0f;
    }
}

void func_800A9D74(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = 0;
        sp24->unkA6 = 0x1E;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_8011763C);
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkA6 & 1)
    {
        sp24->Rot.z += 4.0f;
    }
    else
    {
        sp24->Rot.z -= 4.0f;
    }
    sp24->unkA6 -= 1;
    if (func_8001B44C(gCurrentParsedObject, 0) != 0)
    {
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (sp24->unkA6 <= 0)
    {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 3.0f);
        func_8002B114(gCurrentParsedObject);
    }
}

void func_800A9F94(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = 0x28;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8001BB34(gCurrentParsedObject, !(sp24->unk108 & 1));
    if (sp24->unk108 == 1)
    {
        sp24->unkA4 = 4;
        sp24->unk132 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

void func_800AA0BC(void)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0)
    {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unk108 = 0;
        sp1C->unkB2 = 0x1E;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkB2 -= 1;
    if (sp1C->unkB2 <= 0)
    {
        sp1C->unkA4 = 4;
        sp1C->unk132 = 0;
        sp1C->unk108 = 1;
    }
}

// RODATA
#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800AA1D8.s")

extern struct UnkStruct_80027C00 D_80113934;

void func_800AA2F4(void)
{
    s16 sp26;

    sp26 = func_80027464(1, &D_80113934, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    if (sp26 != -1)
    {
        gObjects[sp26].unkA4 = 8;
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32)sp26, 0, 0, 0x81, &D_801175D0);
        func_8001ABF4((s32)sp26, 0, 0, &D_80117620);
    }
}

void func_800AA404(void)
{
    if (D_80177A64 == 0)
    {
        gObjects[gCurrentParsedObject].unkA4 = 5;
    }
    else
    {
        if (D_80177A64 == 1)
        {
            gObjects[gCurrentParsedObject].unkA4 = 6;
        }
        else
        {
            return;
        }
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800AA4CC(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk3C = func_80015538(sp2C->unk3C, 180.0f);
        sp2C->unk3C = func_80015538(sp2C->unk3C, (f32)func_80014E80(-0x5A));
        sp2C->unk44 = 6.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0x78;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x81, &D_801175D0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        func_80029824(gCurrentParsedObject, func_800297DC());
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0)
    {
        sp2C->unkA4 = 9;
        sp2C->unk132 = 0;
    }
    sp2C->unkA6 = (s16)(s32)((f32)sp2C->unkA6 - sp2C->unk44);
    sp2C->Rot.y = sp2C->unk3C;
    if (sp2C->unkA6 <= 0)
    {
        sp2C->unkA4 = 1;
        sp2C->unk132 = 0;
    }
}

void func_800AA758(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->Rot.y = sp24->unk3C;
    sp24->unkA6 += 1;
    if (sp24->unkA6 >= 0x28)
    {
        sp24->unkA4 = 8;
        sp24->unk132 = 0;
    }
}

void func_800AA8B4(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
        if (sp24->unkA8 == 0)
        {
            sp24->unkA8 = 1;
            func_8001C0EC(gCurrentParsedObject, 0, 2, 0x81, &D_801175D0);
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
        }
    }
    if ((sp24->unk132 == 1) && (func_8001B44C(gCurrentParsedObject, 0) != 0))
    {
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x81, &D_801175D0);
        sp24->unk132 = 2;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp24->Rot.y = sp24->unk3C;
    if ((sp24->unk132 == 2) && (func_8001B44C(gCurrentParsedObject, 0) != 0))
    {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800AAAA0(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->unkA6 += 1;
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (sp2C->unkA6 >= 0x28)
    {
        sp2C->unkA4 = 1;
        sp2C->unk132 = 0;
    }
    if (func_8002A560(gCurrentParsedObject, 15.0f) == 0)
    {
        sp2C->unkA4 = 3;
        sp2C->unk132 = 0;
    }
}

void func_800AAC90(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 10.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0x21C;
        sp2C->unkB2 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x81, &D_801175D0);
    }
    if (!(sp2C->unkB2 & 0x3F))
    {
        func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    }
    sp2C->unkB2 += 1;
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_8002A1FC(gCurrentParsedObject, 240.0f) != 0)
    {
        sp2C->unkA4 = 4;
        sp2C->unk132 = 0;
    }
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->unkA6 = (s16)(s32)((f32)sp2C->unkA6 - sp2C->unk44);
    if (sp2C->unkA6 <= 0)
    {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
    }
}

extern f32 D_80114A4C;

void func_800AAF08(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011763C);
        func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    }
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp2C->Scale.x <= 2.0f)
    {
        sp2C->Scale.y = sp2C->Scale.z = sp2C->Scale.x += D_80114A4C;
        func_800175F0(gCurrentParsedObject, 1, 0x17, -1, 0);
    }
    else
    {
        sp2C->unkA4 = 5;
        sp2C->unk132 = 0;
    }
}

void func_800AB0CC(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkB2 = 0x2D;
        sp24->unk108 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011763C);
        func_8001BBDC(gCurrentParsedObject, 0);
        func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkB2 & 1)
    {
        sp24->Rot.z += 4.0f;
    }
    else
    {
        sp24->Rot.z -= 4.0f;
    }
    sp24->unkB2 -= 1;
    if (func_8001B44C(gCurrentParsedObject, 0) != 0)
    {
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (sp24->unkB2 <= 0)
    {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 3.0f);
        func_8002B114(gCurrentParsedObject);
    }
}

void func_800AB308(void)
{
    struct ObjectStruct *sp24;
    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = 0x3C;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8001BB34(gCurrentParsedObject, !(sp24->unk108 & 1));
    if (sp24->unk108 == 1)
    {
        sp24->unkA4 = 4;
        sp24->unk132 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}

void func_800AB450(void)
{
}

// RODATA
#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800AB460.s")

extern struct UnkStruct_80027C00 D_80113940;

void func_800AB564(void)
{
    s16 sp26;

    sp26 = func_80027464(1, &D_80113940, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    if (sp26 != -1)
    {
        gObjects[sp26].unkA4 = 1;
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32)sp26, 0, 0, 0x81, &D_801175D0);
    }
}

void func_800AB65C(void)
{
    if (D_80177A64 == 0)
    {
        gObjects[gCurrentParsedObject].unkA4 = 5;
    }
    else if (D_80177A64 == 1)
    {
        gObjects[gCurrentParsedObject].unkA4 = 6;
    }
    else
    {
        gObjects[gCurrentParsedObject].unkA4 = 7;
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

extern f64 D_80114A78;
extern f64 D_80114A80;
extern f64 D_80114A88;

void func_800AB748(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
        if (sp24->unkAA == 1)
        {
            sp24->unkAA = 2;
            func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
        }
    }
    if ((sp24->unkAA == 2) && (func_8001B44C(gCurrentParsedObject, 0) != 0))
    {
        sp24->unkAA = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x81, &D_801175D0);
    }
    sp24->unkA6 += 1;
    if (sp24->unkA6 == 0x78)
    {
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
    }
    if ((sp24->unkA6 >= 0x78))
    {
        if (((f64)sp24->Scale.x >= 1.0))
        {
            sp24->Scale.x = sp24->Scale.x - D_80114A78;
            sp24->Scale.y = sp24->Scale.y - D_80114A80;
            sp24->Scale.z = sp24->Scale.z - D_80114A88;
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
        sp24->Rot.y = sp24->unk3C;
    }
    if (func_8002A1FC(gCurrentParsedObject, 540.0f) != 0)
    {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800ABA38(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117620);
    }
    func_8002A8B4(gCurrentParsedObject, 8.0f);
    sp2C->Rot.y = sp2C->unk3C;
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp2C->Rot.y = sp2C->unk3C;
    }
    if (func_8002A560(gCurrentParsedObject, 15.0f) == 0)
    {
        if (func_8002A1FC(gCurrentParsedObject, 540.0f) != 0)
        {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
        if (sp2C->unkA8 == 3)
        {
            sp2C->unkA4 = 4;
            sp2C->unk132 = 0;
        }
    }
    else if (func_8002A1FC(gCurrentParsedObject, 540.0f) == 0)
    {
        sp2C->unkA4 = 1;
        sp2C->unk132 = 0;
    }
}

void func_800ABC88(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA8 = 3;
    }
    func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    if (sp2C->unkAA != 1)
    {
        if (func_8001B44C(gCurrentParsedObject, 0) != 0)
        {
            sp2C->unkAA = 1;
            func_8001C0EC(gCurrentParsedObject, 0, 2, 0x81, &D_801175D0);
        }
    }
    else if ((sp2C->unk132 == 1) && (func_8001B44C(gCurrentParsedObject, 0) != 0))
    {
        sp2C->unk132 = 2;
        sp2C->unk44 = 4.0f;
        sp2C->unkA6 = 0x1E0;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x81, &D_801175D0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (sp2C->unk132 == 2)
    {
        sp2C->unkA6 -= 4;
        sp2C->Rot.y = sp2C->unk3C;
    }
    if (sp2C->unkA6 < 0)
    {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
    }
}

extern f64 D_80114A90;
extern f64 D_80114A98;
extern f64 D_80114AA0;

void func_800ABF34(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA8 = 4;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011763C);
    }
    func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    func_8002A8B4(gCurrentParsedObject, 8.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0)
    {
        sp24->unkA4 = 2;
        sp24->unkAA = 0;
        sp24->unk132 = 0;
    }
    else if (func_8001B62C(gCurrentParsedObject, 0) > 60.0f)
    {
        if ((f64)sp24->Scale.x <= 3.0)
        {
            sp24->Scale.x = (f32)((f64)sp24->Scale.x + D_80114A90);
            sp24->Scale.y = (f32)((f64)sp24->Scale.y + D_80114A98);
            sp24->Scale.z = (f32)((f64)sp24->Scale.z + D_80114AA0);
            func_800175F0(gCurrentParsedObject, 1, 0x17, -1, 0);
        }
        else
        {
            sp24->unkA4 = 5;
            sp24->unk132 = 0;
        }
    }
}

void func_800AC194(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0x2D;
        sp24->unk108 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011763C);
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_800175F0(gCurrentParsedObject, 0, 0x33, -1, 0);
    func_8002A8B4(gCurrentParsedObject, 8.0f);
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkA6 & 1)
    {
        sp24->Rot.z += 4.0f;
    }
    else
    {
        sp24->Rot.z -= 4.0f;
    }
    sp24->unkA6 -= 1;
    if (func_8001B44C(gCurrentParsedObject, 0) != 0)
    {
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (sp24->unkA6 <= 0)
    {
        func_800175F0(gCurrentParsedObject, 0, 0x29, -1, 0);
        func_8007EDF4(sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, 3.0f);
        func_8002B114(gCurrentParsedObject);
    }
}

void func_800AC3D0(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk108 = 0x28;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x81, &D_801175D0);
    }
    func_8001BB34(gCurrentParsedObject, !(sp2C->unk108 & 1));
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if ((func_8001B44C(gCurrentParsedObject, 0) != 0) && (sp2C->unk132 != 2))
    {
        sp2C->unk132 = 2;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x81, &D_801175D0);
    }
    if (sp2C->unk108 == 1)
    {
        sp2C->unkA4 = 4;
        sp2C->unk132 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

void func_800AC57C(void)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0)
    {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkB2 = 0x1E;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkB2 -= 1;
    if (sp1C->unkB2 <= 0)
    {
        sp1C->unkA4 = 4;
        sp1C->unk132 = 0;
    }
}

// RODATA
#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800AC680.s")

extern struct UnkStruct_80027C00 D_8011394C;
extern u32 D_80117658;

void func_800AC77C(void)
{
    s16 sp2E;

    sp2E = func_80027464(1, &D_8011394C, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    if (sp2E != -1)
    {
        gObjects[sp2E].Scale.x = 1.5f;
        gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.x;
        gObjects[sp2E].unkA4 = 3;
        gObjects[sp2E].unkAC = 0;
        gObjects[sp2E].unkA8 = 0;
        gObjects[sp2E].unk132 = 0;
        func_8001C0EC((s32)sp2E, 0, 1, 0x91, &D_80117658);
    }
}

void func_800AC948(void)
{
    if (D_80177A64 == 0)
    {
        gObjects[gCurrentParsedObject].unkA4 = 4;
    }
    else
    {
        if (D_80177A64 == 1)
        {
            gObjects[gCurrentParsedObject].unkA4 = 5;
        }
        else
        {
            return;
        }
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800ACA10(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        if (sp24->unkAC == 0)
        {
            func_8001C0EC(gCurrentParsedObject, 0, 0, 0x91, &D_80117658);
        }
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0)
    {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

extern f64 D_80114AC8;

void func_800ACB2C(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unkA6 = 0x78;
        sp24->unk44 = 3.0f;
        if (sp24->unkAC == 0)
        {
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0x91, &D_80117658);
        }
    }
    sp24->unkA8 = (s16)(s32)func_80015538((f32)sp24->unkA8, 5.0f);
    sp24->unkD8 = sinf((f32)((f64)sp24->unkA8 * D_80114AC8)) * 32.0f;
    sp24->unk3C = func_80015538(sp24->unkD4, sp24->unkD8);
    sp24->Rot.y = sp24->unk3C;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 80.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
        sp24->unkD8 = sp24->unkD4;
        return;
    }
    sp24->unkA6 = (s16)(s32)((f32)sp24->unkA6 - sp24->unk44);
    if ((sp24->unkA6 <= 0) && (func_8001B44C(gCurrentParsedObject, 0) != 0))
    {
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
    }
}

void func_800ACDCC(void)
{
    struct ObjectStruct *sp1C;
    union
    {
        s16 sp18;
    } fake;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0)
    {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 0;
        sp1C->unkAE = func_8002A560(gCurrentParsedObject, 2.0f) * 5;
        sp1C->unkD4 = func_8002A46C(gCurrentParsedObject);
        if (sp1C->unkD4 == sp1C->unkD8)
        {
            sp1C->unkA4 = 1;
            sp1C->unk132 = 0;
            sp1C->unkAC = 1;
            return;
        }
        sp1C->unkAC = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (((s16)sp1C->unkA6 % 2))
    {
        fake.sp18 = func_800BFFCC(sp1C, 0, sp1C->unkD4, (f32)sp1C->unkAE);
        if (fake.sp18 == 0)
        {
            sp1C->unk132 = 2;
        }
    }
    else
    {
        sp1C->unk3C = func_80015538(sp1C->unk3C, (f32) - ((s16)sp1C->unkAE / 2));
    }
    sp1C->Rot.y = sp1C->unk3C;
    sp1C->unkA6 += 1;
    if (sp1C->unk132 == 2)
    {
        sp1C->unkA4 = 1;
        sp1C->unk132 = 0;
    }
}

extern f32 D_80114AD0;
extern f32 D_80114AD4;
extern f32 D_80114AD8;

void func_800AD034(void)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0)
    {
        sp1C->unk132 = 1;
        sp1C->unk44 = 3.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 0x28;
        sp1C->unk108 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unk3C = func_80015538(sp1C->unk3C, 16.0f);
    sp1C->Rot.y = func_80015538(sp1C->Rot.y, -16.0f);
    sp1C->unk44 -= D_80114AD0;
    if (sp1C->Scale.y > D_80114AD4)
    {
        sp1C->Scale.y -= D_80114AD8;
    }
    else
    {
        sp1C->unkA6 = 0;
    }
    sp1C->unkA6 -= 1;
    if (sp1C->unkA6 <= 0)
    {
        func_8001BB34(gCurrentParsedObject, 0);
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_800AD21C(void)
{
    struct ObjectStruct *sp2C;
    s16 sp2A;
    sp2C = &gObjects[gCurrentParsedObject];
    sp2A = sp2C->unkE8[0];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk108 = 0x28;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8001BB34(gCurrentParsedObject, !(sp2C->unk108 & 1));
    if (sp2C->unk108 == 1)
    {
        sp2C->unk108 = 1;
        sp2C->unkA4 = 3;
        sp2C->unk132 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

void func_800AD364(void)
{
}

// RODATA
#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800AD374.s")

extern struct UnkStruct_80027C00 D_80113958;
extern u32 D_80117874;

void func_800AD458(void)
{
    s16 sp26;
    s16 sp24;
    s16 temp_t5;

    sp26 = func_80027464(1, &D_80113958, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    if (sp26 != -1)
    {
        gObjects[sp26].unkA4 = 1;
        gObjects[sp26].unkA4 = 9;
        gObjects[sp26].unkA8 = 0;
        if (D_80165100->unkA != 0)
        {
            gObjects[sp26].unkA4 = 8;
            if ((sp24 = D_80165100->unk8) == 2)
            {
                sp24 = 0;
            }
            sp24 %= 4;
            gObjects[sp26].unkA8 = sp24;
        }
        gObjects[sp26].unk132 = 0;
        func_8001C0EC((s32)sp26, 0, 0, 0x99, &D_80117874);
    }
}

void func_800AD648(void)
{
    if ((D_80177A64 != 0) && (D_80177A64 != 1))
    {
        return;
    }
    func_8002B0E4(gCurrentParsedObject);
}

void func_800AD6A0(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 6.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0x258;
        sp24->unk3C = (f32)(sp24->unkA8 * 0x5A);
    }
    sp24->Rot.y = sp24->unk3C;
    func_80029C40(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
        sp24->unkA6 = 0;
    }
    if (func_80029018(gCurrentParsedObject, 0U, 120.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        sp24->unkA6 = 0;
    }
    sp24->unkA6 = (s16)(s32)((f32)sp24->unkA6 - sp24->unk44);
    if (sp24->unkA6 < 0)
    {
        sp24->unkA8 = (s16)((s32)(sp24->unkA8 + 2) % 4);
        sp24->unkA4 = 8;
        sp24->unk132 = 0;
    }
}

void func_800AD8CC(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 6.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unkA6 = 0x258;
        sp2C->unkA8 = func_8002A560(gCurrentParsedObject, 8.0f) * 8;
        sp2C->unkD4 = func_8002A46C(gCurrentParsedObject);
    }
    if ((sp2C->unk132 == 1))
    {
        if ((!func_800BFFCC(sp2C, 0, sp2C->unkD4, (f32)sp2C->unkA8)))
        {
            sp2C->unk132 = 2;
        }
    }
    sp2C->Rot.y = sp2C->unk3C;
    func_80029C40(gCurrentParsedObject);
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
    }
    if (func_80029018(gCurrentParsedObject, 0U, 120.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp2C->unkA6 = 0;
    }
    sp2C->unkA6 = (s16)(s32)((f32)sp2C->unkA6 - sp2C->unk44);
    if (sp2C->unkA6 < 0)
    {
        sp2C->unkA4 = 9;
        sp2C->unk132 = 0;
    }
}

void func_800ADB1C(void)
{
    func_8002B0E4(gCurrentParsedObject);
}

void func_800ADB4C(void)
{
    s32 sp24;

    sp24 = gObjects[gCurrentParsedObject].unkA4;
    switch (sp24)
    { /* irregular */
    case 8:
        func_800AD6A0();
        break;
    case 9:
        func_800AD8CC();
        break;
    default:
        func_800ADB1C();
        break;
    }
}

extern struct UnkStruct_80027C00 D_80113964;
extern u32 D_80117810;
extern UNK_TYPE D_8011783C;

void func_800ADBF4(void)
{
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;

    sp36 = func_80027464(4, &D_80113964, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    if (sp36 != -1)
    {
        sp34 = gObjects[sp36].unkE8[0];
        sp32 = gObjects[sp36].unkE8[1];
        sp30 = gObjects[sp36].unkE8[2];
        gObjects[sp34].unkB4 = 0;
        gObjects[sp32].unkB4 = 1;
        gObjects[sp30].unkB4 = 2;
        gObjects[sp34].unkA4 = gObjects[sp32].unkA4 = gObjects[sp30].unkA4 = 1;
        gObjects[sp34].unk132 = gObjects[sp32].unk132 = gObjects[sp30].unk132 = 0;
        func_80019448((s32)sp36, 2, 0, 1);
        func_80019448((s32)sp34, 2, 0, 1);
        func_80019448((s32)sp32, 2, 0, 1);
        func_80019448((s32)sp30, 2, 0, 1);
        func_8001C0EC((s32)sp36, 0, 0, 0x9A, &D_80117810);
        func_8001C0EC((s32)sp34, 0, 0, 0x9B, &D_80117810);
        func_8001C0EC((s32)sp32, 0, 0, 0x9B, &D_80117810);
        func_8001C0EC((s32)sp30, 0, 0, 0x9B, &D_80117810);
        func_8001ABF4((s32)sp36, 0, 0, &D_8011783C);
        func_8001ABF4((s32)sp34, 0, 0, &D_8011783C);
        func_8001ABF4((s32)sp32, 0, 0, &D_8011783C);
        func_8001ABF4((s32)sp30, 0, 0, &D_8011783C);
        func_8001BB04((s32)sp34, 1);
        func_8001BB04((s32)sp32, 1);
        func_8001BB04((s32)sp30, 1);
        gObjects[sp36].unkA4 = 1;
        gObjects[sp36].unk132 = 0;
        gObjects[sp36].unk3C = 0.0f;
        gObjects[sp34].unkB0 = 0;
        gObjects[sp32].unkB0 = 0;
        gObjects[sp30].unkB0 = 0;
        if (D_80165100->unkA != 0)
        {
            gObjects[sp34].unkB0 = 1;
            gObjects[sp32].unkB0 = 1;
            gObjects[sp30].unkB0 = 1;
        }
        gObjects[sp36].unk108 = -1;
        gObjects[sp34].unk108 = -1;
        gObjects[sp32].unk108 = -1;
        gObjects[sp30].unk108 = -1;
    }
}

void func_800AE210(void)
{
    if (D_80177A64 != 0)
    {
        return;
    }
    gObjects[gCurrentParsedObject].unkA4 = 4;
    gObjects[gCurrentParsedObject].unk108 = 0;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

extern UNK_TYPE D_80117858;

void func_800AE2B8(void)
{
    struct ObjectStruct *sp1C;
    s16 sp1A;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0)
    {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkA6 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0)
    {
        sp1C->unkA6 += 1;
        if (sp1C->unkA6 >= 0x14)
        {
            sp1C->unkA4 = 2;
            sp1C->unk132 = 0;
        }
        if (sp1C->unk132 == 1)
        {
            sp1C->unk132 = 2;
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117858);
            if ((sp1A = sp1C->unkE8[0]) != -1)
            {
                func_8001ABF4((s32)sp1A, 0, 0, &D_80117858);
            }
            if ((sp1A = sp1C->unkE8[1]) != -1)
            {
                func_8001ABF4((s32)sp1A, 0, 0, &D_80117858);
            }
            if ((sp1A = sp1C->unkE8[2]) != -1)
            {
                func_8001ABF4((s32)sp1A, 0, 0, &D_80117858);
            }
        }
    }
}

void func_800AE8A4(struct ObjectStruct *, UNK_TYPE); /* extern */

void func_800AE4A8(void)
{
    struct ObjectStruct *sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0)
    {
        sp34->unk132 = 1;
        sp34->unk44 = 0.0f;
        sp34->unk48 = 0.0f;
        sp34->unk108 = 0;
        sp34->Rot.x = 0.0f;
        sp34->Rot.z = 0.0f;
        sp34->unkAA = 0;
        sp30 = func_8002A46C(gCurrentParsedObject);
        sp34->unkA8 = (s16)(s32)(func_80015538(sp30, 60.0f) / 90.0f);
        sp34->unk3C = (f32)(sp34->unkA8 * 0x5A);
        func_80019448(gCurrentParsedObject, 2, 0, 1);
    }
    switch (sp34->unkA8)
    { /* irregular */
    case 3:
        sp34->Rot.z = func_80015538(sp34->Rot.z, 5.0f);
        if (sp34->Rot.z > 90.0f)
        {
            sp34->unk132 = 2;
        }
        sp34->unkAA = 2;
        break;
    case 1:
        sp34->Rot.z = func_80015538(sp34->Rot.z, -5.0f);
        if (sp34->Rot.z < 270.0f)
        {
            sp34->unk132 = 2;
        }
        sp34->unkAA = 2;
        break;
    case 2:
        sp34->Rot.x = func_80015538(sp34->Rot.x, -5.0f);
        if (sp34->Rot.x < 270.0f)
        {
            sp34->unk132 = 2;
        }
        sp34->unkAA = 1;
        break;
    default:
        sp34->Rot.x = func_80015538(sp34->Rot.x, 5.0f);
        if (sp34->Rot.x > 90.0f)
        {
            sp34->unk132 = 2;
        }
        sp34->unkAA = 1;
        break;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp34->unk132 == 2)
    {
        func_800AE8A4(sp34, 0);
        func_800AE8A4(sp34, 1);
        func_800AE8A4(sp34, 2);
        func_800175F0(gCurrentParsedObject, 0, 0x34, -1, 0);
        sp34->unkA4 = 4;
        sp34->unk132 = 0;
    }
}

void func_800AE894(void)
{
}

void func_800AE8A4(struct ObjectStruct *arg0, s32 arg1)
{
    struct ObjectStruct *sp24;
    s16 sp22;

    sp22 = arg0->unkE8[(s16)arg1];
    sp24 = &gObjects[sp22];
    if (sp22 != -1)
    {
        sp24->unk108 = 0;
        sp24->unkA4 = 1;
        sp24->unkA6 = func_80014E80(8) + 0xC;
        sp24->unk132 = 0;
        func_8001BB04((s32)sp22, 0);
        func_80019448((s32)sp22, 2, 0, 1);
        func_800281A4(gCurrentParsedObject, (s32)(s16)arg1);
        func_800175F0((s32)sp22, 0, 0x34, -1, 0);
    }
}

void func_800AE9A4(void)
{
    struct ObjectStruct *sp1C;
    s16 sp1A;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0)
    {
        sp1C->unk132 = 1;
        sp1C->unk44 = 0.0f;
        sp1C->unk48 = 0.0f;
        sp1C->unkB2 = 6;
        sp1C->unk108 = 0;
        func_8001BB34(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    sp1C->unkB2 -= 1;
    if (sp1C->unkB2 <= 0)
    {
        sp1A = sp1C->unkE8[0];
        if (sp1A != -1)
        {
            func_800281A4(gCurrentParsedObject, 0);
            func_8002B0E4((s32)sp1A);
        }
        sp1A = sp1C->unkE8[1];
        if (sp1A != -1)
        {
            func_800281A4(gCurrentParsedObject, 1);
            func_8002B0E4((s32)sp1A);
        }
        sp1A = sp1C->unkE8[2];
        if (sp1A != -1)
        {
            func_800281A4(gCurrentParsedObject, 2);
            func_8002B0E4((s32)sp1A);
        }
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800AEB7C(void)
{
}

void func_800AEB8C(void)
{
}

// RODATA
#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800AEB9C.s")

void func_800AEC98(void)
{
}

void func_800AECA8(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk44 = 2.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk108 = -1;
        func_80029EF8(gCurrentParsedObject, 0.0f, 9.0f);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -40.0f, 80.0f) == 1)
    {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
        if (D_80177740[D_801776E0 & 1] == 0xF5)
        {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
    }
}

void func_800AEE6C(void)
{
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0)
    {
        sp2C->unk132 = 1;
        sp2C->unk3C = func_80015538((f32)func_80014E80(0x166), 1.0f);
        sp2C->unk44 = (f32)func_80014E80(4);
        sp2C->unk48 = 0.0f;
        func_80029EF8(gCurrentParsedObject, (f32)sp2C->unkA6, 1.0f);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0)
    {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -40.0f, 80.0f) == 1)
    {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
        sp2C->unkA6 -= func_80014E80(6) + 6;
        if (sp2C->unkB0 == 1)
        {
            sp2C->unkA6 = func_80014E80(6) + 0x18;
            if (sp2C->unkA6 >= 0xB4)
            {
                sp2C->unkA6 = 0xB4;
            }
        }
        else if (sp2C->unkA6 <= 0)
        {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
        if (D_80177740[D_801776E0 & 1] == 0xF5)
        {
            sp2C->unkA4 = 3;
            sp2C->unk132 = 0;
        }
    }
}

void func_800AF118(void)
{
    func_8002B0E4(gCurrentParsedObject);
}

extern f64 D_80114B10;
extern f64 D_80114B18;
extern f64 D_80114B20;

void func_800AF148(void)
{
    struct ObjectStruct *sp2C;
    struct ObjectStruct *sp28;
    f32 sp24;
    f32 sp20;
    s16 sp1E;

    sp28 = &gObjects[gCurrentParsedObject];
    if (sp28->unkE6[0] != -1)
    {
        sp2C = &gObjects[sp28->unkE6[0]];
        sp1E = sp28->unkB4 + 1;
        sp24 = (f32)(sp1E * 5);
        sp28->Rot.x = sp2C->Rot.x;
        sp28->Rot.z = sp2C->Rot.z;
        sp28->Rot.y = sp2C->Rot.y;
        sp20 = 0.0f;
        if (sp2C->unkAA == 2)
        {
            sp20 = sp2C->Rot.z;
            if (sp20 >= 180.0f)
            {
                sp20 = 90.0f - (sp2C->Rot.z - 270.0f);
            }
            if (sp20 != 0.0f)
            {
                sp20 = (f32)((f64)sp20 / D_80114B10);
            }
            sp28->Rot.x = 0.0f;
        }
        if (sp2C->unkAA == 1)
        {
            sp20 = sp2C->Rot.x;
            if (sp20 >= 180.0f)
            {
                sp20 = 90.0f - (sp2C->Rot.x - 270.0f);
            }
            if (sp20 != 0.0f)
            {
                sp20 = (f32)((f64)sp20 / 3.5);
            }
            sp28->Rot.z = 0.0f;
        }
        sp24 *= sp20;
        sp28->Pos.x = sp2C->Pos.x + (sinf((f32)((f64)sp2C->unk3C * D_80114B18)) * sp24);
        sp28->Pos.z = sp2C->Pos.z + (cosf((f32)((f64)sp2C->unk3C * D_80114B20)) * sp24);
        sp28->Pos.y = (sp2C->Pos.y + (f32)(sp1E * 0x78)) - sp24;
        sp28->unk3C = sp2C->unk3C;
        sp28->unk40 = sp2C->unk40;
        sp28->unk48 = (f32)sp1E;
        if (sp28->Pos.y <= 60.0f)
        {
            sp28->Pos.y = 60.0f;
        }
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
    }
}

// STOP
void func_800AF538(void) {
    struct ObjectStruct *sp2C;
    s16 temp_s0;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unkE6[0] == -1) {
        switch (sp2C->unkA4) {                          /* irregular */
        case 1:
            func_800AECA8();
            break;
        case 2:
            func_800AEE6C();
            break;
        case 3:
            func_800AF118();
            break;
            default:break;
        }
    } else {
        func_800AF148();
    }
}

extern struct UnkStruct_80027C00 D_80113994;

void func_800AF620(void) {
    s16 sp2E;

    sp2E = func_80027464(1, &D_80113994, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp2E != -1) {
        gObjects[sp2E].unkA4  = 1;
        gObjects[sp2E].unk132 = 0;
        gObjects[sp2E].unkA8 = 0xF;
        if (D_80165100->unkA == 1) {
            gObjects[sp2E].unkA8 = 0x14;
        }
       
        gObjects[sp2E].Scale.x = gObjects[sp2E].unkA8 / 10.0f;
        gObjects[sp2E].Scale.z = gObjects[sp2E].Scale.y = gObjects[sp2E].Scale.x;
        func_8001BB04((s32) sp2E, 1);
    }
}

void func_800AF814(void)
{
    if (D_80177A64 == 0)
    {
        gObjects[gCurrentParsedObject].unkA4 = 6;
    }
    else
    {
        if (D_80177A64 == 1)
        {
            gObjects[gCurrentParsedObject].unkA4 = 7;
        }
        else
        {
            return;
        }
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

extern u32 D_80117660;
extern UNK_TYPE D_80117700;
extern UNK_TYPE D_80117738;
extern UNK_TYPE D_8011778C;

void func_800AF8DC(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unk108 = -1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x9C, &D_80117660);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117700);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117738);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_8011778C);
    }
    if ((func_8002A2EC(gCurrentParsedObject, 600.0f) != 0) && (func_8002A3A8(gCurrentParsedObject, 1500.0f) != 0)) {
        sp24->unkA4 = 9;
        sp24->unk132 = 0;
    }
}

void func_800AFA3C(void) {
    struct ObjectStruct *sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 0.0f;
        sp2C->unk48 = 34.0f;
        sp2C->unk40 = 270.0f;
        sp2C->unkA6 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001BB04(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, -360.0f, 0.0f) != 0) {
        sp2C->unkA4 = 2;
        sp2C->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}


void func_800AFB8C(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x9C, &D_80117660);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->unkA4 = 4;
        sp24->unk132 = 0;
        sp24->unk108 = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x9C, &D_80117660);
    }
}

void func_800B0A78(struct ObjectStruct *, s32, s32);     /* extern */
extern UNK_TYPE D_80117754;

void func_800AFCC0(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        sp24->unkA6 = 0;
    }
    sp24->unkA6 += 1;
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (sp24->unkA6 == 0xA) {
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117754);
    }
    if (sp24->unkA6 == 0x1E) {
        func_800175F0(gCurrentParsedObject, 0, 0x1B, -1, 0);
        func_800B0A78(sp24, gCurrentParsedObject, 0);
    }
    if (sp24->unkA6 == 0x46) {
        func_800175F0(gCurrentParsedObject, 0, 0x1B, -1, 0);
        func_800B0A78(sp24, gCurrentParsedObject, 1);
        sp24->unk132 = 2;
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        if (sp24->unk132 == 2) {
            sp24->unkA4 = 5;
            sp24->unk132 = 0;
        } else {
            sp24->unk132 = 2;
        }
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800AFEB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B0008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B0110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B0298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B03E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B04FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B0628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B068C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B08FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B09C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B0A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B0C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B0E8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B1048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B1248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B15A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B1914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B1B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B1FA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B2250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B271C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B2AAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B2C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B2E5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B2E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B30B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B3118.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B33B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B33E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B34AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B3630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B3640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B36A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B36D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B3A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B3BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B3C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B3DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B4120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B4258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B444C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B466C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B4898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B49C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B4B08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B4C1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B4C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B4E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B4E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B4EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B5074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B5084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B52A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B52D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/9B110/func_800B5368.s")
