#include "common.h"

//FUNCTIONS
extern void func_8005F96C(u8, u8, u8);                           /* extern */
extern void func_8005F9EC(s8*, s8*); 
extern void func_8001E954(s32*);                                 /* extern */
extern void func_8001E98C(s32, s32*, s32*);                         /* extern */
void func_8005FA90();                                  /* extern */
void func_800FE9BC();                                  /* extern */
void func_800FEB6C();                                  /* extern */
void func_800FEE34();                                  /* extern */
void func_800FEFA0();                                  /* extern */
void func_800FF43C();                                  /* extern */

//RAM ADDRESSES
extern s8 D_80134334;
extern s8 D_80134340;
extern s8 D_8013435C;
extern s8 D_80134378;
extern s8 D_8013438C;
extern s8 D_801343A4;
extern s8 D_801343BC;
extern s8 D_801343CC;
extern s8 D_801343DC;
extern s8 D_801343F0;
extern s8 D_8016523F;
extern s8 D_80165240;
extern s8 D_8016E1B8;
extern u8 D_80177974;
extern s16 D_8016E3F4;
extern s16 D_80134730;
extern s16 D_80134734;
extern s16 D_80134738[];
extern f64 D_801346A0;
extern f64 D_801346A8;
extern u16 D_8016E290[];
extern f32 D_8016E158;
extern f32 D_8016E15C;
extern f32 D_8016E170;

//ROM ADDRESSES
extern u8 D_127FF0[];
extern u8 D_128D20[];

void func_800FDA10(void) {
    f32 sp4;

    if (D_8016E290[0] & 2) {
        sp4 = (f32) ((f64) D_8016E15C + 2.0);
        D_8016E15C = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (D_8016E290[0] & 1) {
        sp4 = (f32) ((f64) D_8016E15C + D_801346A0);
        D_8016E15C = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (D_8016E290[0] & 8) {
        sp4 = (f32) ((f64) D_8016E158 + 2.0);
        D_8016E158 = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (D_8016E290[0] & 4) {
        sp4 = (f32) ((f64) D_8016E158 + D_801346A8);
        D_8016E158 = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (D_8016E290[0] & 0x400) {
        D_8016E170 += 10.0f;
    }
    if (D_8016E290[0] & 0x800) {
        D_8016E170 -= 10.0f;
        if (D_8016E170 < 200.0f) {
            D_8016E170 = 200.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FDD48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FDF98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FE204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FE6D8.s")

void func_800FE854(void) {
    func_8001E954(0x8024C000);
    func_8001E98C(0, D_127FF0, D_128D20);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FE898.s")

void func_800FE9BC(void) {
    sprintf(&D_8016E1B8, &D_80134334);
    func_8005F9EC(0x20, 0x10);
    sprintf(&D_8016E1B8, &D_80134340, D_8016E3E4);
    func_8005F9EC(0x20, 0x20);
    sprintf(&D_8016E1B8, &D_8013435C, D_8016E3F7);
    func_8005F9EC(0x20, 0x30);
    sprintf(&D_8016E1B8, &D_80134378, D_8016E3FC);
    func_8005F9EC(0x20, 0x40);
    sprintf(&D_8016E1B8, &D_8013438C, D_8016E404);
    func_8005F9EC(0x20, 0x50);
    sprintf(&D_8016E1B8, &D_801343A4, D_8016E40C);
    func_8005F9EC(0x20, 0x60);
    sprintf(&D_8016E1B8, &D_801343BC, D_8016523F);
    func_8005F9EC(0x20, 0x70);
    sprintf(&D_8016E1B8, &D_801343CC, D_80165240);
    func_8005F9EC(0x20, 0x80);
    sprintf(&D_8016E1B8, &D_801343DC, D_80177974);
    func_8005F9EC(0x20, 0x90);
    sprintf(&D_8016E1B8, &D_801343F0);
    func_8005F9EC(0x28, (D_8016E3F4 * 0x10) + 0x20);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FEB6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FEE34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FEFA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FF43C.s")

void func_800FF7B4(void) {
    func_8005F96C(0xFF, 0xFF, 0xFF);
    switch (D_8016E3EC) {
        case 0x1:
            func_800FEFA0();
            break;
        case 0x2:
            func_800FF43C();
            break;
        case 0x64:
            func_800FE9BC();
            break;
        case 0x65:
            func_800FEB6C();
            break;
        case 0x66:
            func_800FEE34();
            break;
    }
    func_8005FA90();
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FF88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FFD30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FFF40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_80100148.s")

void func_80100260(void) {
    s16 i;

    D_80134734 = 0;
    D_80134730 = 0;
    for(i = 0; i < 2; i++)
    {
        D_80134738[i] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_801002BC.s")
