#include <ultra64.h>

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

s32 func_800600B8(s8 arg0, s8 arg1) {
    s16 sp26;

    switch(arg0)
    {
        case 0:
            {
                for(sp26 = 0; sp26 < D_801039D4[arg1].Unk01; sp26++)
                {
                    if(func_8005FE88(arg1, (s8)sp26) == 0)
                    {
                        return 0;
                    }
                }
                break;
            }
        case 1:
            {
                if(func_8005FE88(D_80134801, arg1) == 0)
                {
                    return 0;
                }
                break;
            }
        case 2:
            {
                if((D_80134808[(D_80134801 * 0x15) +  (D_80134802 * 7) + arg1] & 0xF) == 0)
                {
                    return 0;
                }
                if((D_80134808[(D_80134801 * 0x15) +  (D_80134802 * 7) + arg1] & 0xF) == 6)
                {
                    return -2;
                }
                break;
            }
    }

    return -1;
}

void func_80060278(void) {
    s32 i;
    for(i = 0; i < 700; i++)
    {
        D_8016CAA0[i].unk0 = 0;
    }
    func_8001E954(0x8024C000);
    func_8001E98C(0, unk_bin_0_2_ROM_START, code_extra_0_ROM_START);

    //why compare like this??
    if(&D_80321428 != D_80324994)
    {
        func_8001EA68(0x1A, &_64C3C0_ROM_START, &_64EC60_ROM_START);
    }
}

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
