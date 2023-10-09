#include "common.h"

extern s32 (*D_8004A750)();
extern void* D_80057EC4;
extern u32* D_80057EC8;
extern s32 D_80057ECC;
extern s32 D_80057ED0;
extern u32 D_80057F38;
extern s32 D_80057F3C;
extern s32 D_80057F48;
extern s32 (*D_80057F4C)();
extern s32 (*D_80057F50)();

// functions
void *func_8002F880(s32 unused);

#ifdef NON_MATCHING
// matches, but asm proc is broken and cant handle -O2 -mips1 I think
void *func_8002F880(s32 unused) {
    s32 temp_v0 = D_8004A750();
    s32 temp_v1 = temp_v0 & 0xFFF;

    if (temp_v1 != 0) {
        temp_v1 = (0x1000 - temp_v1);
        D_8004A750(temp_v1, temp_v0);
        temp_v0 = temp_v0 + temp_v1;
    }
    if (D_80057F50 != NULL) {
        D_80057F50();
    }
    return temp_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_8002F880.s")
#endif

#ifdef NON_MATCHING
// same as above
s32 func_8002F904(void) {
    if (D_80057F4C != NULL) {
        D_80057F4C();
    }
    D_80057ECC = 0x400;
    D_80057EC8 = func_8002F880(D_80057ECC * 0xC);
    if (D_80057EC8 == NULL) {
        return 0;
    }
    memset(D_80057EC8, 0, D_80057ECC * 0xC);
    D_80057EC8[0] = 0;
    D_80057EC8[2] = 0;
    D_80057EC8[1] = D_80057EC8[2];
    D_80057ED0 = 0;
    D_80057EC4 = D_80057EC8;
    D_80057F3C = D_80057ECC * 0xC;
    D_80057F38 = 1;
    D_80057F48 = 1;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_8002F904.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_8002F9F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_8002FC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_80030388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_800303A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_800303C8.s")
