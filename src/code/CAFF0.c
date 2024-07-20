#include "common.h"

void func_800D97A4();                                  /* extern */
void func_800D9A14();                                  /* extern */
void func_800DA9C8();                                  /* extern */
void func_800DAA2C();                                  /* extern */
void func_800DAC3C();                                  /* extern */
void func_8002B0E4(s32);                               /* extern */
void func_8001BBDC(s32, s32);                            /* extern */
void func_8001C0EC(s32, s32, s32, s32, s32*);                  /* extern */
s32 func_8001B44C(s32, s32);                          /* extern */
s32 func_80027464(s32, s32*, f32, f32, f32, f32);       /* extern */
void func_8001ABF4(s32, s32, s32, s32*);                     /* extern */

extern s32 gCurrentParsedObject;
extern s32 D_80177A64;
extern s32 D_80114288[];

extern s32 D_80118C8C[];
extern s32 D_80118BDC;

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D8AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D8E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D8E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D8FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D9044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D90BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D9134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D9298.s")

void func_800D9420(void) {
    struct PlayerStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
        sp20 = func_80027464(1, &D_80114288, sp24->Pos.x, sp24->Pos.y + 100.0f, sp24->Pos.z, sp24->Rot.y);
        sp24->unkA4 = 4;
        sp24->unk132 = 0;
    }
}

void func_800D9520(void) {
    struct PlayerStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
        sp24->unkA6 = 0x14;
    }
    if (sp24->unkA6 == 0) {
        sp24->unkA4 = 1;
        sp24->unk132 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x184, &D_80118BDC);
        func_8001BBDC(gCurrentParsedObject, 1);
    } else {
        sp24->unkA6 -= 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D9620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D9650.s")

void func_800D9720(void) {
    if ((D_80177A64 == 0) || (D_80177A64 == 2)) {
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D97A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D9A14.s")

void func_800D9A44(void) {

    if(gObjects[gCurrentParsedObject].unkE6[0] == -1)
    {
        switch(gObjects[gCurrentParsedObject].unkA4)
        {
            case 1:
                {
                    func_800D97A4();
                    break;
                }
            case 2:
                {
                    func_800D9A14();
                    break;
                }
            default:
                {
                    break;
                }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D9B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D9B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800D9BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA1EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA264.s")

void func_800DA304(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 = 1;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118C8C[0]);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80118C8C[7]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA4D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA56C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA5E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA6BC.s")

void func_800DA760(void) {
    struct PlayerStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA7C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA8B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DA9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/CAFF0/func_800DAA2C.s")

void func_800DAC3C(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800DAC6C(void) {
    switch(gObjects[gCurrentParsedObject].unkA4) 
    {
        case 1:
            func_800DA9C8();
            break;
        case 2:
            func_800DAA2C();
            break;
        case 3:
            func_800DAC3C();
            break;
        default:
            break;
    }
}
