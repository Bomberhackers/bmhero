#include "common.h"

// rodata = 107500
extern f64 D_801150B8;
extern f64 D_801150C0;
extern f64 D_801150C8;
extern f64 D_801150D0;
extern f64 D_801150D8;
extern f64 D_801150E0;

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

void func_800D3048();                                  /* extern */
#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D3048.s")

void func_800D31A8(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = 1;
        sp3C->unkAC = 0;
        sp3C->unk44 = 0.0f;
        sp3C->unk3C = func_8002A46C(gCurrentParsedObject);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118784 + 0x1C / 4); //this line WILL have to be refactored later, but we gotta figure out WHAT this is first
    }
    if (sp3C->unk44 != 12.0f) {
        sp3C->unk44 = (f32) ((f64) sp3C->unk44 + 0.5);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp3C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 45.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) {
        sp30 = sp34;
    } else {
        sp30 = sp38;
    }
    sp3C->Pos.y = 90.0f + sp30;
}

void func_800D33B0(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800D33E0(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
    case 1:
        func_800D2F1C();
        break;
    case 2:
        func_800D3048();
        break;
    case 3:
        func_800D31A8();
        break;
    case 4:
        func_800D33B0();
        break;
    default:
        break;
    }
}

void func_800D34AC(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80114114, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkBA = D_80165100->unkA;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D3568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D3578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D36E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D375C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D3824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D3974.s")

void func_800D3E54(void) {
    struct ObjectStruct* sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) 
    {
        sp34->unk132 = 1;
        sp34->unk108 = 0;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x97, &D_801187BC);
        func_8001BBDC(gCurrentParsedObject, 0);
    }

    if (func_8001B44C(gCurrentParsedObject, 0) != 0)
    {
        sp30 = 0xE;
        
        while (TRUE)
        {
            sp30 = func_80026E58(0xCC, sp30);

            if (sp30 == -1)
            {
                break;
            }
            else if (gObjects[sp30].unkBA == sp34->unkBA)
            {
                if (gObjects[sp30].unkA8 != 0)
                {
                    gObjects[sp30].unkA8--;
                }
                break;
            }    
            else sp30++;    
        }
        func_8002B0E4(gCurrentParsedObject);   
    }
}

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

void func_800D4D74(void) {
    //something something "circle of 120.0f OR 140.0f size"
    struct ObjectStruct* CurrentObject;
    f32 sp38;
    f32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    CurrentObject = &gObjects[gCurrentParsedObject];
    if (CurrentObject->unk132 == 0) {
        CurrentObject->unk132 = 1;
        CurrentObject->unkA6 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
    }

    if (CurrentObject->unkA6 == 0)
    {
        CurrentObject->unk44 = 13.0f;
        CurrentObject->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        sp30 = sinf(CurrentObject->unk3C * D_801150B8) * 120.0f + CurrentObject->Pos.x;
        sp28 = cosf(CurrentObject->unk3C * D_801150C0) * 120.0f + CurrentObject->Pos.z;
        sp2C = (s32) (CurrentObject->Pos.y - 120.0f);

        func_80067748((f32) sp30, (f32) sp2C, (f32) sp28);
        sp24 = D_801776E0 & 1;
        if(sp24 == 0)
        {
            sp2C = D_80177760[sp24];
            if(CurrentObject->Pos.y - 120.0f - sp2C >= 120.0f)
            {
                CurrentObject->unkA4 = 4;
                CurrentObject->unk132 = 0;
            }
            else
            {
                if(func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0)
                {
                    CurrentObject->Pos.y = sp34;
                }
                else
                {
                    CurrentObject->Pos.y = sp38;
                }
                CurrentObject->Pos.y += 120.0f;
            }
        }
        else
        {
            if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) 
            {
                CurrentObject->Pos.y = sp34;
            } 
            else 
            {
                CurrentObject->Pos.y = sp38;
            }

            CurrentObject->Pos.y += 120.0f;
            CurrentObject->unkA6 = 9;
            CurrentObject->unk44 = 0.0f;
            CurrentObject->Vel.z = 0.0f;
            CurrentObject->Vel.x = CurrentObject->Vel.z;
            CurrentObject->unkA8 = (s16) (s32) (CurrentObject->unk3C - 90.0f);

            if (CurrentObject->unkA8 < 0) {

            }
            CurrentObject->unkAA = (s16) (s32) (CurrentObject->unk3C + 90.0f);
            if (CurrentObject->unkAA >= 0x168) {

            }

            sp30 = sinf(CurrentObject->unkA8 * D_801150C8) * 140.0f + CurrentObject->Pos.x;
            sp28 = cosf(CurrentObject->unkA8 * D_801150D0) * 140.0f + CurrentObject->Pos.z;
            sp2C = CurrentObject->Pos.y - 120.0f;

            func_80067748(sp30, sp2C, sp28);
            sp24 = D_801776E0 & 1;
            if(sp24 == 0 && CurrentObject->Pos.y - 120.0f - D_80177760[sp24] <= 120.0f)
            {
                CurrentObject->unkB6 = -0xA;
            }
            else
            {
                sp30 = sinf(CurrentObject->unkAA * D_801150D8) * 140.0f + CurrentObject->Pos.x;
                sp28 = cosf(CurrentObject->unkAA * D_801150E0) * 140.0f + CurrentObject->Pos.z;
                sp2C = CurrentObject->Pos.y - 120.0f;

                func_80067748(sp30, sp2C, sp28);
                sp24 = D_801776E0 & 1;

                if(sp24 == 0 && CurrentObject->Pos.y - 120.0f - D_80177760[sp24] <= 120.0f)
                {
                    CurrentObject->unkB6 = 0xA;
                }
                else
                {
                    func_8002B114(gCurrentParsedObject);
                }
            }
        }
    }
    else
    {
        CurrentObject->unk3C += CurrentObject->unkB6;
        CurrentObject->Rot.y = CurrentObject->unk3C;
        CurrentObject->unkA6 -= 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D5610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D577C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D5848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D58C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D5938.s")

void func_800D5AA4(void) {
    struct ObjectStruct* CurrentObject;
    s32 sp40;
    f32 sp3C;

    CurrentObject = &gObjects[gCurrentParsedObject];
    if (CurrentObject->unk132 == 0) {
        CurrentObject->unk132 += 1;
        CurrentObject->Vel.x = CurrentObject->Vel.y = CurrentObject->Vel.z = 0.0f;
        CurrentObject->unkA6 = CurrentObject->unkA8 = CurrentObject->unkAA = 0;

        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xA8, &D_80118868);
        func_8001BBDC(gCurrentParsedObject, 0);
        CurrentObject->unk108 = -1;
    }
    if(CurrentObject->unkA6 != 0)
    {
        if(CurrentObject->unkA8 == 1 || CurrentObject->unkA8 == 3)
        {
            if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
                CurrentObject->unkA6 = 0;
                CurrentObject->unkA8 += 1;
                func_8001BBDC(gCurrentParsedObject, 1);
            }
        }
        else if (CurrentObject->unkA8 == 3)
        {
            if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
                CurrentObject->unkA6 = 0;
                CurrentObject->unkA8 += 1;
                func_8001C0EC(gCurrentParsedObject, 0, 1, 0xA8, &D_80118868);
                func_8001BBDC(gCurrentParsedObject, 1);
            }
        }
        else
        {
            if(CurrentObject->unkA8 == 0 || CurrentObject->unkA8 == 2)
            {
                if (CurrentObject->unkAA == 0)
                {
                    CurrentObject->unkA6 = 0;
                    CurrentObject->unkA8++;
                }
                else
                {
                    CurrentObject->unkAA--;
                }
            }
            else if(CurrentObject->unkA8 == 4)
            {
                if(CurrentObject->unkAA < 0x28 && CurrentObject->unkAA >= 0x10)
                {
                    sp3C = CurrentObject->unkAA & 0xF;
                    if(sp3C == 3.0f || sp3C == 6.0f || sp3C == 9.0f)
                    {
                        sp40 = func_80027464(1, &D_80114168, CurrentObject->Pos.x, CurrentObject->Pos.y - 20.0f, CurrentObject->Pos.z + 80.0f, CurrentObject->Rot.y);
                        if(sp40 != -1)
                        {
                            func_8001ABF4(sp40, 0, 3, &D_80118898);

                            gObjects[sp40].Scale.x = gObjects[sp40].Scale.y = gObjects[sp40].Scale.z = D_801150E8;
                            func_800175F0(gCurrentParsedObject, 0, 0x58, -1, 0);
                        }
                    }
                }
                if(CurrentObject->unkAA == 0)
                {
                    CurrentObject->unkA6 = 0;
                    CurrentObject->unkA8++;
                }
                else
                {
                    CurrentObject->unkAA -= 1;
                }
            }
        }
    }
    else
    {
        if(CurrentObject->unkA8 == 0 || CurrentObject->unkA8 == 2)
        {
            CurrentObject->unkA6 = 1;
            CurrentObject->unkAA = 5;
        }
        else if(CurrentObject->unkA8 == 1)
        {
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0xA8, &D_80118868);
            func_8001BBDC(gCurrentParsedObject, 0);
            CurrentObject->unkA6 = 1;
        }
        else if (CurrentObject->unkA8 == 3) 
        {
            func_8001C0EC(gCurrentParsedObject, 0, 2, 0xA8, &D_80118868);
            func_8001BBDC(gCurrentParsedObject, 0);
            CurrentObject->unkA6 = 1;
        } 
        else if (CurrentObject->unkA8 == 4) 
        {
            CurrentObject->unkA6 = 1;
            CurrentObject->unkAA = 0x32;
            CurrentObject->unk108 = 1;
        } 
        else if (CurrentObject->unkA8 == 5) 
        {
            func_8001BBDC(gCurrentParsedObject, 1);
            if (func_8002A2EC(gCurrentParsedObject, 1200.0f) != 0) {
                CurrentObject->unk132 = 0;
            } else {
                CurrentObject->unkA4 = 3;
                CurrentObject->unk132 = 0;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D613C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D63C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D6540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D660C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/C4470/func_800D6684.s")

void func_800D6C14(void) {
    func_8002B114(gCurrentParsedObject);
}

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

void func_800D6DFC(void) {
    struct ObjectStruct* CurrentObject;
    f32 sp40;
    f32 sp3C;

    CurrentObject = &gObjects[gCurrentParsedObject];
    if (CurrentObject->unk132 == 0) {
        CurrentObject->unk132 = 1;
        CurrentObject->unkA6 = CurrentObject->unkA8 = CurrentObject->unkB6 = 0;
        CurrentObject->unk44 = 0.0f;
        CurrentObject->Rot.y = CurrentObject->unk3C;
        func_80017664(gCurrentParsedObject, 0, 0x59, -1, 0);
    }
    if ((CurrentObject->unkB6 == 0) && (CurrentObject->unkA6 == 0) && (func_80028FA0(gCurrentParsedObject) != 0)) {
        CurrentObject->unkB6 = 5;
        CurrentObject->unkB8 = (s16) (s32) CurrentObject->unk3C;
        CurrentObject->unk44 = 8.0f;
        CurrentObject->unk3C += 180.0f;
        if (CurrentObject->unk3C >= 360.0f) {
            CurrentObject->unk3C -= 360.0f;
        }
    }
    if (CurrentObject->unkB6 != 0) {
        CurrentObject->unkB6 -= 1;
        if (CurrentObject->unkB6 == 0) {
            CurrentObject->unk44 = CurrentObject->Vel.x = CurrentObject->Vel.z = 0;
            CurrentObject->unkA8 = (s16) (s32) CurrentObject->unk3C;
            CurrentObject->unk3C = (f32) CurrentObject->unkB8;
            CurrentObject->unkA6 = 1;
        }
    }
    if (CurrentObject->unkA6 != 0) {
        CurrentObject->unk3C = func_80015538(CurrentObject->unk3C, 10.0f);
        CurrentObject->Rot.y = CurrentObject->unk3C;
        if ((CurrentObject->unk3C - (f32) CurrentObject->unkA8) == 0.0f) {
            CurrentObject->unkA6 = 0;
        }
    } else {
        if (CurrentObject->unk44 < 12.0f) {
            CurrentObject->unk44 = (f32) ((f64) CurrentObject->unk44 + 0.25);
        }
        CurrentObject->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (CurrentObject->unkA6 == 0) {
            if (func_80029018(gCurrentParsedObject, 1U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
                CurrentObject->Vel.x = CurrentObject->Vel.y = CurrentObject->Vel.z = 0;
                if (CurrentObject->unkB6 == 0) {
                    CurrentObject->unkB6 = 5;
                    CurrentObject->unkB8 = (s16) (s32) CurrentObject->unk3C;
                    CurrentObject->unk44 = 8.0f;
                    CurrentObject->unk3C += 180.0f;
                    if (CurrentObject->unk3C >= 360.0f) {
                        CurrentObject->unk3C -= 360.0f;
                    }
                } else {
                    CurrentObject->unkB6 = 1;
                }
            }
            if (func_800295C0(gCurrentParsedObject, &sp40, &sp3C, 0.0f, 0.0f, 0.0f) != 0) {
                CurrentObject->Pos.y = sp3C;
            } else {
                CurrentObject->Pos.y = sp40;
            }
        }
    }
}


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
