#include "common.h"

extern void func_800303F0();          /* extern */
extern s32 func_800309D0(s32 arg0);                                  /* extern */
extern s32 func_80030AA0(s32 arg0);                                  /* extern */

extern s32 (*D_8004A750)(s32);
extern u32 D_80057EC4;

struct UnkStruct80057EC8 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern struct UnkStruct80057EC8 *D_80057EC8;

extern u32 D_80057ECC;
extern s32 D_80057ED0;
extern u32 D_80057ED4;
extern u32 D_80057F38;
extern s32 D_80057F3C;
extern s32 D_80057F48;
extern s32 (*D_80057F4C)();
extern s32 (*D_80057F50)();

// functions
void *func_8002F880(s32 arg0);
s32 func_8002F904(void);

#ifdef NON_MATCHING
// matches, but asm proc is broken and cant handle -O2 -mips1 I think
void *func_8002F880(s32 arg0) {
    s32 temp_v0 = D_8004A750(arg0);
    s32 temp_v1 = temp_v0 & 0xFFF;

    if (temp_v1 != 0) {
        temp_v1 = (0x1000 - temp_v1);
        D_8004A750(temp_v1);
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
    D_80057EC8->unk0 = 0;
    D_80057EC8->unk8 = 0;
    D_80057EC8->unk4 = D_80057EC8->unk8;
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

#ifdef NON_MATCHING
// same thing
void* func_8002F9F8(s32 arg0) {
    void* sp34;
    struct UnkStruct80057EC8* temp_v0_2;
    u32 var_s0;
    u32 temp;

    sp34 = func_8002F880(arg0);
    if (sp34 == NULL) {
        return NULL;
    }
    
    if ((u32) D_80057ECC < (((s32) (((u32)sp34 + arg0) - D_80057EC4) / 4096) + 1)) {
        for(var_s0 = D_80057ECC; var_s0 < (((s32) (((u32)sp34 + arg0) - D_80057EC4) / 4096) + 1); var_s0 *= 2) {
            
        }
        temp_v0_2 = func_8002F880((s32)(var_s0 * 0xC));
        if (temp_v0_2 == NULL) {
            D_8004A750(-arg0);
            return NULL;
        }
        memcpy(temp_v0_2, D_80057EC8, D_80057ECC * 0xC);
        memset(&temp_v0_2[D_80057ECC], 0, (var_s0 - D_80057ECC) * 0xC);
        temp = D_80057EC8;
        temp_v0_2[((s32) (temp - D_80057EC4) / 4096)+1].unk0 = 0;
        temp_v0_2[((s32) (temp - D_80057EC4) / 4096)+1].unk4 = (((D_80057ECC * 0xC) + 0xFFF) >> 0xC);
        D_80057F3C += (s32)(var_s0 * 0xC);
        D_80057F38 += 1;
        D_80057EC8 = temp_v0_2;
        func_800303F0(temp);
        D_80057ECC = var_s0;
    }
    D_80057ED4 = ((s32) (((u32)sp34 + arg0) - D_80057EC4) / 4096) + 1;
    return sp34;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_8002F9F8.s")
#endif

// some kind of allocator. too big to match right now
#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_8002FC34.s")

#ifdef NON_MATCHING
// also OK
void func_80030388(u32 arg0) {
    func_8002FC34(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_80030388.s")
#endif

#ifdef NON_MATCHING
// also OK
void func_800303A8(s32 arg0) {
    func_800309D0(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_800303A8.s")
#endif

#ifdef NON_MATCHING
// also OK
void func_800303C8(s32 arg0) {
    func_80030AA0(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/30480/func_800303C8.s")
#endif
