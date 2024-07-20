#include "common.h"
#include "variables.h"

extern s32 gCurrentParsedObject;
extern s32 D_80177A64;
extern void* D_80117F08;

#pragma GLOBAL_ASM("asm/nonmatchings/code/B27B0/func_800C0290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B27B0/func_800C04B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B27B0/func_800C04C4.s")

void func_800C0858(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800C0858_stub() {
    
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/B27B0/func_800C0898.s")

void func_800C08A8(void) {
    s32 sp24;

    sp24 = (s32) gObjects[gCurrentParsedObject].unkA4;
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

#pragma GLOBAL_ASM("asm/nonmatchings/code/B27B0/func_800C0964.s")

void func_800C0B78(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 1) {
        if (sp4->unkAA == -1) {
            sp4->unkAC = 0;
        }
        if (sp4->unk10B == 0) {
            if (sp4->unkAA == 1) {
                sp4->unkAA = -1;
                sp4->unkA4 = 2;
                sp4->unk108 = -1;
                sp4->unk132 = 0;
                return;
            }
            sp4->unkAA = 0;
        } else {
            if (sp4->unkAA == 0) {
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

void func_800C0CC0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unk44 = 0.0f;
        sp24->unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, sp24->unkA8, 0x12B, &D_80117F08);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/B27B0/func_800C0D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B27B0/func_800C0F18.s")

void func_800C11F4(void)
{

}

void func_800C1204(void)
{
    
}

void func_800C1214(void)
{
    
}

void func_800C1224(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    switch (sp1C->unkA4) {
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
    if (sp1C->unkAA != -1) {
        sp1C->unkAC += 1;
        if (sp1C->unkAC >= 0x27) {
            sp1C->unkAC = 0;
            sp1C->unkAA = -1;
        }
    }
}
