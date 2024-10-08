#include "common.h"

// rodata = 107500
extern f64 D_801150B8;
extern f64 D_801150C0;
extern f32 D_801150C8;
extern f32 D_801150D0;
extern f32 D_801150D8;
extern f32 D_801150E0;

// temp func defs
extern void func_800D464C(); /* extern */
extern void func_800D47C0(); /* extern */
extern void func_800D6684(); /* extern */
extern void func_800D6C14(); /* extern */
extern void func_800D7704(); /* extern */
extern void func_800D88F4(); /* extern */
extern void func_800D8958(); /* extern */

void func_800D1F50(void)
{
    s32 sp24;

    sp24 = func_80027464(1, &D_801140F0, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

void func_800D1FCC(void) {
    if (D_80177A64 == 0) 
    {
        gObjects[gCurrentParsedObject].unkA4 = 6;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
    else if(D_80177A64 == 1 && gObjects[gCurrentParsedObject].unk108 == 1)
    {
        gObjects[gCurrentParsedObject].unkA4 = 5;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D20E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D2208.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D2334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D247C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D26A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D2870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D28A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D2980.s")

void func_800D2A04(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 += 1;
        sp24->unk44 = 30.0f;
        sp24->unkA6 = 1;
        func_8001BBDC(gCurrentParsedObject, 1);
    }

    if (sp24->unkA6 != 0)
    {
        sp24->unkA6 -= 1;
        sp24->unkA8 = (s16)(s32)func_8002A46C(gCurrentParsedObject);
        if (sp24->unkA8 >= 0xB4)
        {
            sp24->unkAA = -5;
            sp24->unkAC = -4;
        }
        else
        {
            sp24->unkAC = 5;
            sp24->unkAA = 4;
        }
        sp24->unkAE = 4;
    }
    else
    {
        if (sp24->unkAE != 0)
        {
            sp24->unkB0 = (s16)(s32)func_80015538(sp24->unk3C, (f32)-sp24->unkA8);
            if ((sp24->unkB0 < 6) || (sp24->unkB0 >= 0x163))
            {
                sp24->unk3C = func_80015538(sp24->unk3C, (f32)sp24->unkAA);
                sp24->unkAE -= 1;
            }
            else
            {
                sp24->unkAE = 0;
            }
        }
        else
        {
            sp24->unk3C = (f32)sp24->unkA8;
        }
        sp24->Rot.y = func_80015538(sp24->Rot.y, (f32)sp24->unkAC);
    }

    sp24->Vel.y = 0.0f;

    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800D2D34(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800D2D64(void)
{
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1)
    {
        switch (gObjects[gCurrentParsedObject].unkA4)
        {
        case 1:
            func_800D2A04();
            break;

        case 2:
            func_800D2D34();
            break;

        default:
            break;
        }
    }
}

void func_800D2E2C(void) {
    func_80027464(1, &D_80114108, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
}

void func_800D2EA4(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].unkA4 = 4;
    }
}

void func_800D2F1C(void) {
    struct ObjectStruct* sp34;
    UNUSED s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z = 0.0f;

        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x96, &D_80118754);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118784);
        func_8001BB04(gCurrentParsedObject, 1);
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        sp34->unkA4 = 2;
        sp34->unk132 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D3048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D31A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D33B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D33E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D34AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D3568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D3578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D36E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D375C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D3824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D3974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D3E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D4064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D4114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D418C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D4258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D4268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D4430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D4530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D45C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D464C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D47C0.s")

void func_800D4A10(void)
{
    switch (gObjects[gCurrentParsedObject].unkA4)
    {
    case 1:
        func_800D464C();
        break;
    case 2:
        func_800D47C0();
        break;
    default:
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D4AA4.s")

void func_800D4AB4(void)
{
    struct ObjectStruct *sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 += 1;
        sp24->unk44 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 0.0f, 2.0f);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xB3, &D_80118864);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    sp20 = sp24->Vel.y;
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 2U, 60.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    sp24->Vel.y = sp20;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -120.0f, 60.0f) == 1)
    {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800D4C8C(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 += 1;
        sp24->unk44 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 8.0f, 1.0f);
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -120.0f, 60.0f) == 1)
    {
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D4D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D5610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D577C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D5848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D58C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D5938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D5AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D613C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D63C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D6540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D660C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D6684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D6C14.s")

void func_800D6C44(void)
{
    s16 temp_s0;

    if (gObjects[gCurrentParsedObject].unkE6[0] == -1)
    {
        switch (gObjects[gCurrentParsedObject].unkA4)
        {
        case 1:
            func_800D6684();
            break;
        case 2:
            func_800D6C14();
            break;
        default:
            break;
        }
    }
}

void func_800D6D0C(void)
{
    func_80027464(1, &D_80114228, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

void func_800D6D84(void)
{
    if (D_80177A64 == 0)
    {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].unkA4 = 2;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D6DFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D7348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D7580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D7614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D768C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D7704.s")

void func_800D7CD0(void)
{
    struct ObjectStruct *sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 += 1;
        sp24->unkA6 = 0x1E;
        sp24->unk44 = 5.0f;
        sp24->unk3C = func_80015538(sp24->unk128, 180.0f);
        func_80029EF8(gCurrentParsedObject, 14.378698f, 1.06089f);
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->unk108 = 0;
    }
    sp24->Rot.y = func_80015538(sp24->Rot.y, 25.0f);
    sp20 = sp24->Vel.y;
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 60.0f, 0.0f, 0.0f, 0.0f) != 0)
    {
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    sp24->Vel.y = sp20;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1)
    {
        sp24->unkA6 = 0;
    }
    if (sp24->unkA6 == 0)
    {
        func_8002B0E4(gCurrentParsedObject);
    }
    else
    {
        sp24->unkA6 -= 1;
    }
}

void func_800D7F08(void)
{
    switch (gObjects[gCurrentParsedObject].unkA4)
    {
    case 1:
        func_800D7704();
        break;
    case 2:
        func_800D7CD0();
        break;
    default:
        break;
    }
}

void func_800D7F9C(void)
{
    func_80027464(1, &D_80114240, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D8014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D808C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D86E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D8714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D87A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D8820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D88F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D8958.s")

void func_800D8A30(void)
{
    switch (gObjects[gCurrentParsedObject].unkA4)
    {
    case 1:
        func_800D88F4();
        break;
    case 2:
        func_800D8958();
        break;
    default:
        break;
    }
}
