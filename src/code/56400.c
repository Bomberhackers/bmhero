#include "common.h"

extern s8 D_801348B2;
struct UnkStruct_56400
{
    s16* ptr;
    s16 Unk04;
    s16 Unk06;
} UnkStruct_56400;

extern void* D_80104A14[];
extern s16 D_80104B64[];
extern s16 D_80104C18[];
extern s16 D_801348B0;
extern struct UnkStruct_56400 D_801348B8[];

// functions
void func_80063EE0(void);
void func_80064000(void);
void func_80064120(void);
s32 func_800641E4(s16* ptr, s16 arg1, s16 arg2);

void func_80063EE0(void) {
    s32 sp4;
    s16 sp2;

    D_801348B2 = 0;
    D_801348B0 = 0;
    sp2 = 0;
    sp4 = 0;
    do
    {
        D_801348B8[sp4].ptr = D_80104A14[sp4];
        D_801348B8[sp4].Unk04 = D_80104C18[D_80104B64[sp4]];
        if(D_80104B64[sp4] == 1)
        {
            sp2++;
        }
        if(D_80104B64[sp4] == 2)
        {
            sp2 += 4;
        }
        D_801348B8[sp4].Unk06 = ((sp2 + sp4) << 5) + 0xFA;
    } while(++sp4 < 0x53);
}

void func_80064000(void) {
    s16 sp6;

    if (D_801348B2 == 0) 
    {
        return;
    }

    if(D_801348B8[D_801348B0].Unk06 <= 0)
    {
        D_801348B0++;
        if (D_801348B0 >= 0x53) {
            D_801348B2 = 0;
            return;
        }
    }

    for(sp6 = D_801348B0; sp6 < 0x53; sp6++)
    {
        D_801348B8[sp6].Unk06 = (D_801348B8[sp6].Unk06 - 0.5f);
    }
}

void func_80064120(void) {
    s16 sp1E;

    if (D_801348B2 == 0) {
        return;
    }

    func_8006357C();
    for(sp1E = D_801348B0; sp1E < (D_801348B0 + 0xF); sp1E++)
    {
        if(sp1E < 0x53)
        {
            func_800641E4(D_801348B8[sp1E].ptr, D_801348B8[sp1E].Unk04, D_801348B8[sp1E].Unk06);
        }
    }
}

s32 func_800641E4(s16* ptr, s16 arg1, s16 arg2) {
    s16 sp1E;

    if (ptr == 0) //NULL 
    {
        return - 1;
    }

    ptr += 5;
    
    for(sp1E = 0; *ptr != -1; sp1E++)
    {
        func_8006389C(arg1 + (sp1E * 8), arg2, (*ptr % 32) * 8, (*ptr / 32) * 0x10);
        ptr++;
    }
}
