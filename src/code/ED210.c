#include "common.h"
#include "variables.h"

extern void func_800FB804();                                  /* extern */
extern void func_800FBA24();                                  /* extern */
extern void func_8002B0E4(s32);
extern void func_80081468(s32, f32, f32, f32);  

extern s32 D_80177A60;
extern s32 D_80177A64;
extern s8 D_80165242;

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FACF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FAE00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FAE10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FAF10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FB05C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FB344.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FB548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FB694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FB764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FB804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FBA24.s")

void func_800FBAB8(void) 
{
    switch (gPlayerData[D_80177A60].unkA4) 
    {                              
    case 1:
        func_800FB804();
        break;
    case 2:
        func_800FBA24();
        break;
    default:
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FBB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FBC40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FBCB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FBE54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FBF10.s")

void func_800FC1D8(void) {
    struct PlayerStruct* sp1C;

    sp1C = &gPlayerData[D_80177A60];
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        return;
    }
    if (D_80177A64 == 0) {
        D_80165242 += 1;
        func_80081468(0x2CB, sp1C->Pos.x, sp1C->Pos.y + 120.0f, sp1C->Pos.z);
        sp1C->unk108 = 0;
        sp1C->unkA4 = 3;
        sp1C->unk132 = 0;
    } else {
        sp1C->unk108 = 0;
        sp1C->unkA4 = 4;
        sp1C->unk132 = 0;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FC2E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FC6BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FC8D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FCA8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FCC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FCF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FD04C.s")

void func_800FD3F8(void) {
    
}

void func_800FD408(void) {
    func_8002B0E4(D_80177A60);
    return;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FD440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FD874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/ED210/func_800FD940.s")
