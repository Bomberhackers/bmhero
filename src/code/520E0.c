#include "common.h"

extern s8 D_80134808[];

void func_8005FBC0(void) {

}

void func_8005FBD0(void) {
    s16 sp6;
    s16 sp4;
    s16 sp2;
    for(sp6 = 0; sp6 < 6; sp6++)
    {       
        for(sp4 = 0;sp4 < 3; sp4++)
        {
            for(sp2 = 0; sp2 < 7; sp2 = sp2 + 1)
            {
                D_80134808[(sp6 * 21) + sp4 * 7 + sp2] = 0;
            }
        }
    }

    D_80134808[0] = 6;
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_8005FC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_8005FE88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_800600B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_8006031C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_800604A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_800608B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_800623E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_800628C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80062EAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80063104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80063158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_800631A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80063200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_8006357C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_8006389C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80063BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80063C58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80063D7C.s")
