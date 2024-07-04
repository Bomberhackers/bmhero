#include "common.h"
#include "variables.h"

struct UnkBigStruct_8006B64C
{
    u16 Unk0;
    u16 Unk1;
    u8 Padding[336 - sizeof(u32)];
} UnkBigStruct_8006B64C;

extern f32 D_8016E140;
extern f32 D_8016E144;
extern f32 D_8016E148;
extern u8 D_801776E0;
extern s8 D_801775EE;
extern s8 D_801348B2;
extern s16 D_80134C22;
extern u16 D_80177958;
extern u16 D_80177950;
extern u16 D_8017793C;

extern u16 D_80177936;
extern u8 D_80177939;
extern struct UnkStructSTCG* D_8017753C;
extern f32 D_80104FA0;
extern u8 D_801775BC;
extern u8 D_801775C4;
extern u8 D_801775CC;
extern u8 D_801775D4;
extern u8 D_801775DC;
extern u8 D_801775E4;
extern u8 D_801775EC;
extern void* D_8011472C;

extern s8 D_8017793F;
extern s8 D_80165242;
extern struct UnkBigStruct_8006B64C D_801541F8[];

extern u8 D_80177933;

extern s32 func_80014E80(s32);                               /* extern */
extern void func_80067748(f32, f32, f32);                     /* extern */
extern void func_80081468(s32, f32, f32, f32);                  /* extern */
extern void func_80017BEC(s32, s32, s32, s32); 
extern void func_80017CFC(s32, s32, s32, s32); 
extern s32 func_80014E80(s32);                               /* extern */
extern void func_80067748(f32, f32, f32);                     /* extern */
extern void func_80081468(s32, f32, f32, f32);                  /* extern */
extern s32 func_80027464(s32, void*, f32, f32, f32, f32);
extern void func_800178D4(s32, s32, s32, s32, s32);                   /* extern */
extern s32 func_80026E58(s32, s32);                          /* extern */

void func_8006AFB0(void) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    sp24 = (f32) func_80014E80(-0x3C0) + D_8016E140;
    sp20 = (f32) func_80014E80(0xF0) + (D_8016E144 + 540.0f);
    sp1C = (f32) func_80014E80(-0x3C0) + D_8016E148;
    func_80067748(sp24, sp20, sp1C);
    if (!(D_801776E0 & 1)) {
        func_80081468(0x2C1, sp24, sp20, sp1C);
    }
}

void func_8006B084(void) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    if (D_801775EE == 0) {
        D_801775EE = 1;
        D_80177933 = 0;
    }
    if (D_80177933 == 0) {
        D_80177933 = 5;
        sp24 = (f32) func_80014E80(-960) + D_8016E140;
        sp20 = (f32) func_80014E80(240) + (D_8016E144 + 540.0f);
        sp1C = (f32) func_80014E80(-960) + D_8016E148;
        func_80067748(sp24, sp20, sp1C);
        if (!(D_801776E0 & 1)) {
            func_80081468(706, sp24, sp20, sp1C);
        }
    }
    D_80177933 -= 1;
}

void func_8006B1B4(void) {
    s32 sp04;
    return; //stubbed?
    if(D_801775EE == 0)
    {
        D_801775EE = 1;
        D_80177936 = 0;
        D_80177939 = 0;
    }

    if(D_80177939 == 0)
    {
        if(D_8017753C->Unk0 >= 3600.0f)
        {
            D_80177939 = 1; 
        }

        if(D_80177936 == 0)
        {
            sp04 = (s32) (D_80104FA0 - D_8017753C->Unk0);
            if(sp04 < 0)
            {
                sp04 = 0;
            }            
            else if(sp04 > 4000)
            {
                sp04 = 4000;
            }
            
            sp04 = (sp04 / 30) + 10;
            
            D_80177936 = sp04;
            D_801775BC = 3;
            D_801775C4 = 200;
            D_801775CC = 0;
            D_801775D4 = 0;
            D_801775DC = 200;
            D_801775E4 = 50;
            D_801775EC = 50;
        }
        else
        {
            D_80177936--;
        }
    }

    if(D_801775C4 != 0)
    {
        D_801775C4 -= 10;
        D_801775DC = D_801775C4;
        if(D_801775DC < 50)
        {
            D_801775DC = 50;
        }
    }
}

void func_8006B3BC(void) {
    f32 sp34; //unused
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp24;


    if (D_801775EE == 0) {
        D_801775EE = 1;
        D_8017793C = 0;
    }

    if(D_8017753C->Unk4 < 480.0f)
    {
        if (D_8017793C == 0)
        {
            D_8017793C = func_80014E80(0xA) + 15;
            if(D_8017753C->Unk24 == 0.0f && D_8017753C->Unk2C == 0.0f)
            {
                sp30 = (f32)func_80014E80(-480) + D_8017753C->Unk0;
            }
            else
            {
                sp30 = (f32)func_80014E80(-960) + D_8017753C->Unk0;
            }

            sp2C = D_8017753C->Unk4 + 540.0f;
            sp28 = (f32)func_80014E80(-240) + D_8017753C->Unk8;
            func_80067748(sp30, sp2C, sp28);
            if(D_801776E0 % 2 == 0)
            {
                sp24 = func_80027464(1, &D_8011472C, sp30, sp2C, sp28, 0.0f);
            }
        }
        else
        {
            D_8017793C -= 1;
        }
    }
}

void func_8006B5A4(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
        func_80017BEC(0, 0x35, -1, 0);
    }
}

void func_8006B5F8(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
        func_80017BEC(0, 0x35, -1, 0);
    }
}

void func_8006B64C(void) {
    s32 sp24;
    s32 sp28;

    if (D_801775EE == 0) {
        D_801775EE = 1;
        D_8017793F = 0;
    }
    if ((D_8017793F == 0) && (D_80165242 >= 0xA)) 
    {
        sp24 = 0xE;
        while(1)
        {
            sp24 = func_80026E58(0x54, sp24);
            if(sp24 == -1)
            {
                break;
            }
            else
            {
                D_801541F8[sp24].Unk0 = 1;
                func_800178D4(-1, 0, 0x61, -1, 0);
                D_8017793F = 1;
                break;
            }            
        }
    }
}

void func_8006B754(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
    }
    func_80017BEC(0, 0x38, -1, 1);
    func_80017CFC(0, 0x38, -1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006B7BC.s")

void func_8006B8CC(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
        func_80017BEC(0, 0x35, -1, 0);
    }
}

void func_8006B920(void) {
    if (D_80134C22 != 0) {
        if (D_80177950 == 0) {
            func_80017BEC(0, 0x78, -1, 2);
            D_80177950 = 8;
        } else {
            D_80177950 -= 1;
        }
    }
}

void func_8006B9A0(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
        func_80017BEC(0, 0x35, -1, 0);
    }
}

void func_8006B9F4(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
    }
    func_80017BEC(0, 0x3C, -1, 1);
    func_80017CFC(0, 0x3C, -1, 0);
}

void func_8006BA5C(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
    }
    func_80017BEC(0, 0x3C, -1, 1);
    func_80017CFC(0, 0x3C, -1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006BAC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006BBF4.s")

void func_8006BE9C(void) {
    if (D_801775EE == 0) {
        D_801775EE += 1;
        D_80177958 = 0;
    }
    if (D_80134C22 != 0) {
        if (D_80177958 == 0) {
            gMegaStruct.D_80134F28.x += 2.0f;
            D_80177958 += 1;
        }
        else
        {
            gMegaStruct.D_80134F28.x -= 2.0f;
            D_80177958 = 0;
        }
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006BF5C.s")

void func_8006C18C(void) {
    if ((D_80134C22 != 0) && (D_801775EE == 0)) {
        D_801775EE = 1;
        D_801348B2 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/5D4D0/func_8006C1DC.s")
