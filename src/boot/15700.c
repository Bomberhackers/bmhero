#include <ultra64.h>

s16 func_80014B00(u8** arg0, s32* arg1) {
    s16 sp6;

    if (*arg1 == 0) {
        return -1;
    }
    *arg1 -= 1;
    sp6 = (s16) **arg0;
    *arg0 += 1;
    return sp6;
}

void func_80014B6C(s16 arg0, s8** arg1) {
    **arg1 = (s8) arg0;
    *arg1 += 1;
}

//stub
void func_80014B98(void);

s32 func_80014BA0(u8* arg0, s8* arg1) {
    s16 i;
    s16 sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp26;
    u16 sp24;
    s32 sp20;
    s32 sp1C;

    sp1C = 0;
    sp20 = 0;

    for(i = 3; i >= 0; i--)
    {
        sp20 = arg0[i] + (sp20 << 8);        
    }

    arg0 += 4;

    for(i = 0; i < 0xFEE; i = (s32)(i + 1))
    {
        D_80055D70[i] = 0;
    }
    
    sp28 = 0xFEE;
    sp24 = 0;

    while(1) {
        if(((sp24 = ((u16)((u32)sp24 >> 1))) & 0x100) == 0)
        {
            sp26 = func_80014B00(&arg0, &sp20);
    
            if(sp26 == -1)
            {
                break;
            }
    
            sp24 = sp26 | 0xFF00;            
        }
            
        if((sp24 & 1) != 0)
        {
            sp26 = func_80014B00(&arg0, &sp20);

            if(sp26 == -1)
            {
                break;
            }

            func_80014B6C(sp26, &arg1);
            sp1C += 1;
            
            D_80055D70[sp28++] = sp26;
            sp28 &= 0xFFF;
        }
        else
        {
            i = func_80014B00(&arg0, &sp20);

            if(i == -1)
            {
                break;
            }

            sp2C = func_80014B00(&arg0, &sp20);

            if(sp2C == -1)
            {
                break;
            }

            i = i | ((sp2C & 0xF0) << 4);
            sp2C = (sp2C & 0xF) + 2;
            
            for(sp2A = 0; sp2A <= sp2C; sp2A++) {
                sp26 = D_80055D70[(i + sp2A) & 0xFFF];
                  
                func_80014B6C(sp26, &arg1);
                sp1C += 1;

                D_80055D70[sp28++] = sp26;
                    
                sp28 &= 0xFFF;
            }
        }
    }

    return sp1C;
}
