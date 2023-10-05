#include "common.h"

struct UnkStruct8008AD58
{
    s16 Unk0;
    s16 Unk2;
    s16 Unk4;
    s16 Unk6;
    s16 Unk8;
    s16 UnkA;
    s16 UnkC;
};

extern void func_80019B7C();
extern void func_8006AA60(s32*, s32*, s32*);
extern void func_8008A870(u8, u8, s32, s32, s32);
void func_8008B030(void);


extern f32 D_80134F44;
extern f32 D_80134F48;
extern f32 D_80134F4C;
extern s16 D_80134FA4;
extern s8 D_8016E134;
extern f32 D_8016E14C;
extern f32 D_8016E150;
extern f32 D_8016E154;
extern s16 D_80177600;
extern s8 D_80134BF0;
extern f32 D_80134F28;
extern f32 D_80134F2C;
extern f32 D_80134F30;
extern f32 D_80134F34;
extern f32 D_80134F38;
extern f32 D_80134F3C;
extern f32 D_80134F40;
extern f32 D_80134F50;
extern f32 D_80134F54;
extern f32 D_80134F58;
extern f32 D_80134F5C;
extern f32 D_80134F60;
extern f32 D_80134F64;
extern f32 D_80134F74;
extern s16 D_80134C1A;
extern f32 D_8016E140;
extern f32 D_8016E144;
extern f32 D_8016E148;
extern f32 D_8016E158;
extern f32 D_8016E15C;
extern f32 D_8016E160;
extern f32 D_8016E170;
extern s16 D_80134C1C;
extern f32 D_80134F78;
extern f32 D_80134F7C;
extern f32 D_80134F80;
extern f32 D_80134F84;
extern f32 D_80134F88;
extern f32 D_80134F8C;
extern f32 D_80134F90;
extern f32 D_80134F94;
extern f32 D_80134F98;
extern f32 D_80134F9C;
extern s16 D_80134FA0;
extern s16 D_80134FA2;
extern s32 D_801765EC;
extern s16 D_80134FA6;
extern s16 D_80134C20;
extern f32 D_80134F68;
extern f32 D_80134F6C;
extern f32 D_80134F70;

extern s16 D_80134C1E;

extern s16 D_8010CD80[2];
extern s16 D_80110B78[];
extern s32 D_80110D4C[];
extern s16 D_80134BF8;
extern s32 D_80134C08;
extern s16 D_80134C0E;
extern s16 D_80134C16;
extern s16 D_80134C18;

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_80088B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_80088D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_80088EAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_80088ECC.s")

void func_80089C18(void) {
    if (D_80134BF8 == -1) {
        return;
    }
    if (D_80134C0E == 0) {
        D_80134C0E += 1;
        D_80134C08 = D_80110D4C[D_80134BF8];
        D_80134C16 = D_80110B78[D_80134BF8];
        D_80134C18 = 0xA;
    }
    if (D_80134C16 == 0) {
        if (D_80134C18 == 0) {
            D_80134BF8 = -1;
            D_80134BF0 = 0;
            D_80134C0E = 0;
        } else 
        {
            D_80134C18 -= 1;
        }        
    }
    else
    {
        D_80134C16 -= 1;
    }
}

void func_80089D30(s32 arg0, s32 arg1, s32 arg2, s32 arg3) 
{
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    
    if(sp24 = 0, arg3 > 0)
    {
        do
        {
            sp28 = arg0 % 10;

            if(arg0 == 0)
            {
                sp2C = 0;
            }
            else
            {
                sp2C = sp28;
            }
            arg0 /= 10;
            sp2C++;
            func_8008A870(arg1, arg2, (sp2C % 32) * 8, (sp2C / 32) * 0x10, 0x1A);
            arg1 -= 8;
        }
        while (++sp24 < arg3);
    }
}


void func_80089E48(void) {
    s16 sp2E;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    if (D_80134BF0 == 1) {
        sp2E = 0x45;
        func_8006AA60(&sp28, &sp24, &sp20);
        func_80089D30(sp28, 0xC0, 0xB8, 2);
        func_8008A870(0xC8, 0xB8, (sp2E % 32) * 8, (sp2E / 32) * 0x10, 0x1A);
        func_80089D30(sp24, 0xD8, 0xB8, 2);
        func_8008A870(0xE0, 0xB8, (sp2E % 32) * 8, (sp2E / 32) * 0x10, 0x1A);
        func_80089D30(sp20, 0xF0, 0xB8, 2);
        sp2E = 0x3F;
        func_8008A870(0xF8, 0xB8, (sp2E % 32) * 8, (sp2E / 32) * 0x10, 0x1A);
    } else if (D_80134BF0 == 2) {
        func_80089D30(D_80177600 * 0xA, 0xB4, 0xC8, 5);
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008A000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008A384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008A6A4.s")

void func_8008A824(s16 arg0, s16 arg1, s16 arg2) {
    D_8010CD80[1] = ((arg0 << 0xB) + (arg1 << 6) + (arg2 * 2) + 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008A870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008ABC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008ABF4.s")

void func_8008AC08(s16* arg0) {

    switch(*arg0)
    {
        case 1:
            {
                D_8016E134 = 0;
                D_80134FA4 = 0;
                break;
            }
        case 2:
            {
                D_8016E134 = 1;
                D_80134FA4 = 1;
                func_8008B030();
                break;
            }
        case 3:
            {
                D_8016E134 = 0;
                D_80134FA4 = 1;
                break;
            }
        case 4:
            {
                D_8016E134 = 1;
                D_80134FA4 = 0;
                func_8008B030();
                break;
            }
        default:
            {
                D_8016E134 = 0;
                D_80134FA4 = 0;
                break;
            }
    }

    func_80019B7C();
    if (D_8016E134 == 1) {
        D_80134F44 = D_8016E14C;
        D_80134F48 = D_8016E150;
        D_80134F4C = D_8016E154;
    }
}

void func_8008AD58(struct UnkStruct8008AD58* arg0) {
    D_80134F28 = (f32) arg0->Unk0;
    D_80134F2C = (f32) arg0->Unk2;
    D_80134F30 = (f32) arg0->Unk4;
    D_80134F34 = (f32) arg0->Unk6;
    D_80134F38 = (f32) arg0->Unk8;
    D_80134F3C = (f32) arg0->UnkA;
    D_80134F40 = (f32) arg0->UnkC;
    D_80134F50 = 0.0f;
    D_80134F54 = 0.0f;
    D_80134F58 = 0.0f;
    D_80134F5C = 0.0f;
    D_80134F60 = 0.0f;
    D_80134F64 = 0.0f;
    D_80134F74 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008AE64.s")

void func_8008B030(void) {
    D_8016E140 = D_80134F28;
    D_8016E144 = D_80134F2C;
    D_8016E148 = D_80134F30;
    D_8016E158 = D_80134F34;
    D_8016E15C = D_80134F38;
    D_8016E160 = D_80134F3C;
    D_8016E170 = D_80134F40;
    if (D_8016E134 == 1) {
        D_8016E14C = D_80134F44;
        D_8016E150 = D_80134F48;
        D_8016E154 = D_80134F4C;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008B0F4.s")

void func_8008B5D4(struct UnkStruct8008AD58* arg0) {
    D_80134F74 = ((f32) arg0->Unk0 - D_80134F40) / (f32) arg0->Unk2;
    D_80134C1A = arg0->Unk2;
}

void func_8008B624(struct UnkStruct8008AD58* arg0) {
    D_80134F50 = ((f32) arg0->Unk0 - D_80134F28) / (f32) arg0->Unk6;
    D_80134F54 = ((f32) arg0->Unk2 - D_80134F2C) / (f32) arg0->Unk6;
    D_80134F58 = ((f32) arg0->Unk4 - D_80134F30) / (f32) arg0->Unk6;
    D_80134C1C = arg0->Unk6 - 1;
}

void func_8008B6E0(struct UnkStruct8008AD58* arg0) {
    if (arg0->Unk6 == 0)
    {
        if((f32)(arg0->Unk0) / 10 < D_80134F34)
        {
            D_80134F5C = ((((f32)(arg0->Unk0) / 10) - D_80134F34) + 360) / arg0->Unk4;
        }
        else
        {
            D_80134F5C = ((((f32)(arg0->Unk0) / 10) - D_80134F34)) / arg0->Unk4;
        }
    }
    else if ((f32)(arg0->Unk0) / 10 <= D_80134F34)
    {
        D_80134F5C = ((((f32)(arg0->Unk0) / 10) - D_80134F34)) / arg0->Unk4;
    }
    else
    {
        D_80134F5C = ((D_80134F34 - ((f32)(arg0->Unk0) / 10) + 360) / arg0->Unk4) * -1;
    }

    if (arg0->Unk8 == 0)
    {
        if((f32)(arg0->Unk2) / 10 < D_80134F38)
        {
            D_80134F60 = ((((f32)(arg0->Unk2) / 10) - D_80134F38) + 360) / arg0->Unk4;
        }
        else
        {
            D_80134F60 = ((((f32)(arg0->Unk2) / 10) - D_80134F38)) / arg0->Unk4;
        }
    }
    else if  ((f32)(arg0->Unk2) / 10 <= D_80134F38)
    {
        D_80134F60 = ((((f32)(arg0->Unk2) / 10) - D_80134F38)) / arg0->Unk4;
    }
        else
    {
        D_80134F60 = ((D_80134F38 - ((f32)(arg0->Unk2) / 10) + 360) / arg0->Unk4) * -1;
    }

    D_80134C1E = arg0->Unk4;
}

void func_8008BA3C(void) {
    D_80134FA0 = (s16) D_801765EC;
    D_80134FA2 = (s16) D_8016E134;
    D_80134F78 = D_8016E140;
    D_80134F7C = D_8016E144;
    D_80134F80 = D_8016E148;
    D_80134F84 = D_8016E158;
    D_80134F88 = D_8016E15C;
    D_80134F8C = D_8016E160;
    D_80134F9C = D_8016E170;
    D_80134F90 = D_8016E14C;
    D_80134F94 = D_8016E150;
    D_80134F98 = D_8016E154;
}

void func_8008BB0C(void) {
    D_801765EC = (s32) D_80134FA0;
    D_8016E134 = (s8) D_80134FA2;
    D_8016E140 = D_80134F78;
    D_8016E144 = D_80134F7C;
    D_8016E148 = D_80134F80;
    D_8016E158 = D_80134F84;
    D_8016E15C = D_80134F88;
    D_8016E160 = D_80134F8C;
    D_8016E14C = D_80134F90;
    D_8016E150 = D_80134F94;
    D_8016E154 = D_80134F98;
    D_8016E170 = D_80134F9C;
    D_80134FA4 = 0;
    D_80134FA6 = 0;
    func_80019B7C();
}

void func_8008BC04(struct UnkStruct8008AD58* arg0) {
    D_80134F68 = ((f32) arg0->Unk0 - D_80134F44) / (f32) arg0->Unk6;
    D_80134F6C = ((f32) arg0->Unk2 - D_80134F48) / (f32) arg0->Unk6;
    D_80134F70 = ((f32) arg0->Unk4 - D_80134F4C) / (f32) arg0->Unk6;
    D_80134C20 = arg0->Unk6;
}
