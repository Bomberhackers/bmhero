#include <ultra64.h>
#include "38D0.h"

struct UnkInputStruct8000D120 {
    u32 unk0;
    u32 unk4;
    char filler8[0x8];
    u32 unk10;
};

struct UnkInputStruct8000D120_arg0 {
    char filler0[0x10];
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

struct UnkInputStruct8000D120_arg1 {
    u16 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    f32 unk18;
    u32 unk1C;
};

struct UnkStructPair {
    u32 unk0;
    u32 unk4;
};

struct UnkStruct80053180 {
    s32 unk0[2];
    char filler8[0x230];
    ALGlobals unk238;
};

struct UnkStruct80053188_Ptr {
    u32 unk0[2];
    char filler8[0x68];
    s16 unk70;
    u32 unk74;
};

// externs
s32 func_80001E78(s32, s32*, void*);                    /* extern */
s32 func_80001FDC(s32);                             /* extern */
void func_8000D8E0(void*);                          /* extern */
void func_8000E070();

extern s32 D_80053170;
extern s32 D_80053178;
extern struct UnkStruct80053180 D_80053180;
extern struct UnkStruct80053188_Ptr *D_80053188[];
extern s32 D_80053408;
extern s32 D_80055408;
extern s32 D_80055410;
extern ALCSPlayer* D_80055414;
extern s32 D_80055418;
extern s32 D_8005541C;
extern u16 D_80055420;
extern u32 D_80055424;
extern s32 D_80055428;
extern s32 D_8005542C;
extern s32 D_80055430;
extern u32 D_80055434;
extern s32 D_80055438;
extern OSMesgQueue D_80055740;
extern void* D_80055758;

// .bss
struct UnkStructPair D_80053160;
struct UnkStructPair D_80053168;

s32 func_8000D120(struct UnkInputStruct8000D120_arg0* arg0, struct UnkInputStruct8000D120_arg1* arg1) {
    s32 sp3C;
    f32 sp38;
    struct UnkInputStruct8000D120* sp34;
    s16 sp32;

    sp32 = 0;
    D_80053168.unk0 = D_80053168.unk4 = 0;
    D_80053160.unk0 = D_80053160.unk4 = 0;
    D_80055428 = 0;
    D_8005541C = 0;
    D_80055418 = 0;
    D_80055420 = arg1->unk0;
    D_80055424 = arg1->unk4;
    D_80055408 = arg0->unk14;
    arg0->unk10 = &func_8000E070;
    arg0->unk18 = osAiSetFrequency(arg1->unk10);
    if (D_8004A280 == 0) {
        sp38 = ((f32)arg1->unk8 * (s32)arg0->unk18) / 60.0f;
    } else {
        sp38 = ((f32)arg1->unk8 * (s32)arg0->unk18) / 50.0f;
    }

    D_80055434 = (s32) sp38;
    if (D_80055434 < sp38) {
        D_80055434 += 1;
    }

    if (D_80055434 & 0xF) {
        D_80055434 = (D_80055434 & ~0xF) + 0x10;
    }
    D_8005542C = D_80055434 - 0x10;
    D_80055430 = D_80055434 + 0x60;
    alInit(&D_80053180.unk238, (ALSynConfig* ) arg0);
    sp34 = (void*)func_8000D84C(D_80055420 * 0x14);
    if (sp34 == NULL) {
        sp32 = 1;;
    } else {
        sp34[D_80055420-1].unk0 = 0;
        sp34->unk4 = sp34->unk0 = sp34[D_80055420-1].unk0;

        for(sp3C = 0; sp3C < D_80055420 - 1; sp3C++) {
            alLink((void*)&sp34[sp3C+1].unk0, (void*)&sp34[sp3C].unk0);

            sp34[sp3C].unk10 = func_8000D84C(D_80055424);
            if (sp34[sp3C].unk10 == 0) {
                sp32 = 1;
                goto after;
            }
        }

        sp34[sp3C].unk10 = func_8000D84C(D_80055424);
        if (sp34[sp3C].unk10 == 0) {
            sp32 = 1;;
        } else {
            D_80055410 = 0;
            D_80055414 = (void*)sp34;
            D_80055438 = arg1->unkC;

            for(sp3C = 0; sp3C < 2; sp3C++) {
                D_80053180.unk0[sp3C] = func_8000D84C(D_80055438 * 8);
                if (D_80053180.unk0[sp3C] == 0) {
                    sp32 = 1;;
                    goto after;
                }
            }
            
            for(sp3C = 0; sp3C < 3; sp3C++) {
                D_80053188[sp3C] = (void*)func_8000D84C(0x90U);
                if (D_80053188[sp3C] == 0) {
                    sp32 = 1;;
                    goto after;
                }
                D_80053188[sp3C]->unk70 = 2,
                D_80053188[sp3C]->unk74 = D_80053188[sp3C];
                **(u32**)&D_80053188[sp3C] = func_8000D84C(D_80055430 * 4);
                if (**(u32**)&D_80053188[sp3C] == 0) {
                    sp32 = 1;;
                    goto after;
                }
            }
        }
    }
after:;
    osCreateMesgQueue((u32)&D_80053180 + 0x200, (u32)&D_80053180 + 0x218, 8);
    osCreateMesgQueue((u32)&D_80055740, (u32)&D_80055758, 0x20);
    if (arg1->unk14 != 0) {
        osCreateMesgQueue((u32)&D_80053180 + 0x1C8, (u32)&D_80053180 + 0x1E0, 8);
        D_80053170 = func_80001FDC(arg1->unk14);
        func_80001E78(arg1->unk14, (u32)&D_80053178, (u32)&D_80053180 + 0x1C8);
    }
    osCreateThread((u32)&D_80053180 + 0x18, (s32)arg1->unk1C, func_8000D8E0, NULL, (u32)&D_80053408 + 0x2000, *(u32*)&arg1->unk18);
    osStartThread((u32)&D_80053180 + 0x18);
    return (s32) sp32;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/DD20/func_8000D800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/DD20/func_8000D818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/DD20/func_8000D834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/DD20/func_8000D84C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/DD20/func_8000D8E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/DD20/func_8000DA70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/DD20/func_8000DD24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/DD20/func_8000DD40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/DD20/func_8000E070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/DD20/func_8000E088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/DD20/func_8000E098.s")
