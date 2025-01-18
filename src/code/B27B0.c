#include <ultra64.h>

void func_80069D04(s32, s32);                              /* extern */

// Vars only used in this file

//.rodata
extern UNK_TYPE D_80117F7C;
extern UNK_TYPE D_80117F98;
extern struct UnkStruct_80027C00 D_80113DFC;
extern struct UnkStruct_80027C00 D_80113E14;
extern UNK_TYPE D_80117F44;
extern UNK_TYPE D_80117F60;
extern UNK_TYPE D_80117FB4;
extern UNK_TYPE D_80117FD0;

void func_800C0290(void)
{
    s16 sp26;

    sp26 = func_80027464(1, &D_80113DFC, (f32)D_80165100->unk2, (f32)D_80165100->unk4, (f32)D_80165100->unk6, (f32)D_80165100->unk8);
    if (sp26 != -1)
    {
        gObjects[sp26].unkA4 = 3;
        gObjects[sp26].unkA8 = 1;
        gObjects[sp26].unkAA = 0;
        gObjects[sp26].unkAC = 0x258;
        gObjects[sp26].unkAE = 8;
        if (D_80165100->unkA > 0)
        {
            gObjects[sp26].unkAC = D_80165100->unkA * 0x3C;
        }
        if (D_80165100->unkC > 0)
        {
            gObjects[sp26].unkAE = D_80165100->unkC;
        }
        gObjects[sp26].unk132 = 0;
        func_8001BB34((s32)sp26, 0);
    }
}

void func_800C04B4(void)
{
}


void func_800C04C4(void)
{
    struct ObjectStruct *sp44;

    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0)
    {
        sp44->unk132 = 1;
        sp44->unk44 = 0.0f;
        sp44->unk48 = (f32)sp44->unkAE;

        sp44->unk40 = (sp44->unkA8 * 0x5A + 0x168 >= 0xB5) ? ((sp44->unkA8 * 0x5A + 0x168 >= 0x168 ? sp44->unkA8 * 0x5A : sp44->unkA8 * 0x5A + 0x168)) : ((sp44->unkA8 * 0x5A + 0x168 < 0) ? sp44->unkA8 * 0x5A + 0x2D0 : sp44->unkA8 * 0x5A + 0x168);

        sp44->unkA6 = sp44->unkAC;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    sp44->Rot.x = ((sp44->Rot.x + 12.0f) > 180.0f) ? ((sp44->Rot.x + 12.0f >= 360.0f) ? (sp44->Rot.x + 12.0f) - 360.0f : sp44->Rot.x + 12.0f) : ((sp44->Rot.x + 12.0f < 0.0f)) ? (sp44->Rot.x) + 360.0f + 12.0f
                                                                                                                                                                               : sp44->Rot.x + 12.0f;

    sp44->unkA6 -= sp44->unk48;
    if (sp44->unkA6 <= 0)
    {
        sp44->unkA4 = 3;
        sp44->unk132 = 0;
        sp44->unkA8 = -sp44->unkA8;
    }
}

void func_800C0858(void)
{
    func_8002B0E4(gCurrentParsedObject);
}

void func_800C0858_stub()
{
}

void func_800C0898(void) {

}


void func_800C08A8(void)
{
    s32 sp24;

    sp24 = (s32)gObjects[gCurrentParsedObject].unkA4;
    switch (sp24)
    {
    case 3:
        func_800C04C4();
        break;
    case 5:
        func_800C0858();
        break;
    case 7:
        func_800C0898();
        break;
    default:
        break;
    }
}


void func_800C0964(void) {
    s16 sp26;

    sp26 = func_80027464(1, &D_80113E14, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp26 != -1) {
        gObjects[sp26].unkA4  = 1;
        gObjects[sp26].unkA8  = 0;
        gObjects[sp26].unkAA  = -1;
        gObjects[sp26].unk132 = 0;
        gObjects[sp26].unk100 = -1;
        gObjects[sp26].unk102 = 0;
        func_8001ABF4((s32) sp26, 0, 0, &D_80117F44);
        func_8001ABF4((s32) sp26, 1, 0, &D_80117F60);
        if (D_80165100->unkA == 1) {
            gObjects[sp26].unkA8 = 2;
            func_8001ABF4((s32) sp26, 0, 0, &D_80117FB4);
            func_8001ABF4((s32) sp26, 1, 0, &D_80117FD0);
        }
    }
}

void func_800C0B78(void)
{
    struct ObjectStruct *sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 1)
    {
        if (sp4->unkAA == -1)
        {
            sp4->unkAC = 0;
        }
        if (sp4->unk10B == 0)
        {
            if (sp4->unkAA == 1)
            {
                sp4->unkAA = -1;
                sp4->unkA4 = 2;
                sp4->unk108 = -1;
                sp4->unk132 = 0;
                return;
            }
            sp4->unkAA = 0;
        }
        else
        {
            if (sp4->unkAA == 0)
            {
                sp4->unkAA = -1;
                sp4->unkA4 = 2;
                sp4->unk108 = -1;
                sp4->unk132 = 0;
                return;
            }
            sp4->unkAA = 1;
        }
    }
}

void func_800C0CC0(void)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0)
    {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, sp24->unkA8, 0x12B, &D_80117F08);
    }
}


void func_800C0D78(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x12B, (u32 *) &D_80117F08);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117F7C);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117F98);
        func_80029C40(gCurrentParsedObject);
    }
    if ((sp24->unk132 == 1) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x12B, (u32 *) &D_80117F08);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80117FB4);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80117FD0);
        sp24->unk132 = 2;
        func_80069D04(3, 0);
    }
}

void func_800C0F18(void) {
    struct ObjectStruct* sp3C;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 = 1;
        sp3C->unk44 = 0.0f;
            sp3C->unk3C =  ((sp3C->Rot.y + 180.0f) > 180.0f) ? 
        ((sp3C->Rot.y +  180.0f >= 360.0f) ? (sp3C->Rot.y +  180.0f) - 360.0f : sp3C->Rot.y +  180.0f) : 
        ((sp3C->Rot.y +  180.0f < 0.0f)) ? (sp3C->Rot.y) + 540.0f : sp3C->Rot.y +  180.0f;  
    
        sp3C->unkA6 = 0x3C;
        func_80029C40(gCurrentParsedObject);
    }
    if (sp3C->unkA6 <= 0) {
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x12B, (u32* ) &D_80117F08);
        sp3C->unkA4 = 1;
        sp3C->unk132 = 0;
    } else {
            sp3C->Rot.x =  ((sp3C->Rot.x + 12.0f) > 180.0f) ? 
        ((sp3C->Rot.x + 12.0f >= 360.0f) ? (sp3C->Rot.x + 12.0f) - 360.0f : sp3C->Rot.x + 12.0f) : 
        ((sp3C->Rot.x + 12.0f < 0.0f)) ? (sp3C->Rot.x ) + 360.0f + 12.0f : sp3C->Rot.x + 12.0f;  
    
        sp3C->unkA6 -= 6;
    }
}


void func_800C11F4(void)
{
}

void func_800C1204(void)
{
}

void func_800C1214(void)
{
}

void func_800C1224(void)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    switch (sp1C->unkA4)
    {
    case 1:
        func_800C0CC0();
        break;
    case 2:
        func_800C0D78();
        break;
    case 3:
        func_800C11F4();
        break;
    case 4:
        func_800C1204();
        break;
    case 5:
        func_800C1214();
        break;
    case 6:
        func_800C0F18();
        break;
    default:
        break;
    }
    if (sp1C->unkAA != -1)
    {
        sp1C->unkAC += 1;
        if (sp1C->unkAC >= 0x27)
        {
            sp1C->unkAC = 0;
            sp1C->unkAA = -1;
        }
    }
}
