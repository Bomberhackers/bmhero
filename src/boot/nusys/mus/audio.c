#include <ultra64.h>
#include "../../38D0.h"
#include "nusys/audio.h"

// externs
s32 func_80001E78(s32, s32*, void*);                    /* extern */
s32 func_80001FDC(s32);                             /* extern */
s32 func_80003C94();                                  /* extern */
s32 func_80003FA0();                                  /* extern */
s32 func_80007BC4();                                  /* extern */
s32 func_8000ABB4();                                  /* extern */

// .bss
struct UnkStructPair D_80053160;
struct UnkStructPair D_80053168;

s32 amCreateAudioMgr(struct UnkInputStruct8000D120_arg0* arg0, struct UnkInputStruct8000D120_arg1* arg1) {
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
    D_80055408 = (void*)arg0->unk14;
    arg0->unk10 = &__amDmaNew;
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
                D_80053188[sp3C]->unk8.unk68 = 2,
                D_80053188[sp3C]->unk8.unk70 = D_80053188[sp3C];
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
    osCreateThread((u32)&D_80053180 + 0x18, (s32)arg1->unk1C, __amMain, NULL, (u32)&D_80053408 + 0x2000, *(u32*)&arg1->unk18);
    osStartThread((u32)&D_80053180 + 0x18);
    return (s32) sp32;
}

// functions added(?) or that may have been present in the nusys-1.0 this was based on. It's hard to say.
void func_8000D800(void) {
    return; // what. an explicit return in an empty function? but why though?
}

void func_8000D818(s32 arg0) {
    return; // same as above.
}

s32 func_8000D834(void) {
    return 0;
}

void* func_8000D84C(s32 arg0) {
    if ((D_80055408->unk8 - (D_80055408->unk4 - D_80055408->unk0)) < arg0) {
        D_80053160.unk0 |= 1;
        return NULL;
    }
    return alHeapDBAlloc(NULL, 0, (ALHeap* ) D_80055408, 1, arg0);
}

void __amMain(void* arg0) {
    s32 sp34;
    s32 sp30;
    OSMesg *sp2C;
    s32 sp28;

    sp30 = 0;
    sp28 = 0;
    if (sp30 == 0) {
        do {
            osRecvMesg((OSMesgQueue* ) &D_80053180.queue, &sp2C, 1);
            switch (*(s16*)sp2C) {                      /* irregular */
            case 1:
                sp34 = __amHandleFrameMsg(D_80053188[(u32) D_80055418 % 3U], sp28);
                if (sp34 != 0) {
                    osRecvMesg((OSMesgQueue* ) &D_80053180.queue2, &sp2C, 1);
                    __amHandleDoneMsg(((s32*)sp2C)[1]);
                    sp28 = ((s32*)sp2C)[1];
                    func_80003C94();
                    func_80007BC4();
                }
                D_8005543C += 1;
                break;
            case 4:
                func_80003FA0();
                func_8000ABB4();
                sp30 = 1;
                break;
            case 10:
                sp30 = 1;
                break;
            }
        } while (sp30 == 0);
    }
    alClose(&D_80053180.unk238);
}

extern u8 _4A060_data__s[];
extern u8 _4DD30_bin[];

s32 __amHandleFrameMsg(struct UnkStruct80053188_Ptr* arg0, struct UnkInputStruct8000DA70_Arg1 *arg1) {
    u32 sp2C;
    Acmd* sp28;
    s32 sp24;
    u32 sp20;
    struct UnkInnerStruct80053188_Ptr * sp1C;
    s8* temp_t8;

    sp20 = 0;
    __clearAudioDMA();
    sp2C = osVirtualToPhysical((void* ) arg0->unk0[0]);
    if (arg1 != 0) {
        osAiSetNextBuffer(arg1->unk0, arg1->unk4 * 4);
    }
    sp20 = osAiGetLength() >> 2;
    *(s16*)&arg0->unk0[1] = ((((D_80055434 - sp20) + 0x50) & ~0xF) + 0x10);
    if (*(s16*)&arg0->unk0[1] < (u32) D_8005542C) {
        *(s16*)&arg0->unk0[1] = (s16) D_8005542C;
    }
    sp28 = alAudioFrame((Acmd* ) D_80053180.unk0[D_80055428], &sp24, (s16* ) sp2C, *(s16*)&arg0->unk0[1]);
    if (sp24 == 0) {
        return 0;
    }

    sp1C = &arg0->unk8;
    sp1C->unk0 = 0;
    sp1C->unk8 = 2;
    sp1C->unk50 = &D_80053180.filler8[0x1F8];
    sp1C->unk54 = &arg0->unk8.unk68;
    sp1C->unk40 = (s32) D_80053180.unk0[D_80055428];
    sp1C->unk44 = (((s32) ((u32)sp28 - D_80053180.unk0[D_80055428]) >> 3) * 8);
    sp1C->unk10 = 2;
    sp1C->unk18 = &D_80047F60;
    sp1C->unk1C = (s32) ((u32)&D_80048030 - (u32)&D_80047F60);
    sp1C->unk14 = 0;
    sp1C->unk20 = _4A060_data__s; // .data start?
    sp1C->unk28 = _4DD30_bin;     // .data end?
    sp1C->unk2C = 0x800;
    sp1C->unk30 = 0;
    sp1C->unk34 = 0;
    sp1C->unk38 = 0;
    sp1C->unk3C = 0;
    sp1C->unk48 = 0;
    sp1C->unk4C = 0;
    osSendMesg((OSMesgQueue* ) D_80053170, sp1C, 1);
    D_80055428 ^= 1;
    return 1;
}

void __amHandleDoneMsg(s32 arg0) {
    return;
}

u32 __amDMA(u32 arg0, u32 arg1, s32 arg2) {
    void* sp3C;                                     /* compiler-managed */
    s32 sp38;
    s32 sp34;
    s32 sp30;
    struct UnkInputStruct8000DD40_sp2C *sp2C;                                       /* compiler-managed */
    struct UnkInputStruct8000DD40_sp28 *sp28;

    sp28 = 0;
    sp2C = D_80055410;
    sp34 = arg0 + arg1;
    while (sp2C != 0) {
        sp30 = sp2C->unk8 + D_80055424;
        if (sp2C->unk8 > arg0) {
            break;
        } else if (sp34 <= sp30) {
            sp2C->unkC = D_80055418;
            sp3C = (sp2C->unk10 + arg0) - sp2C->unk8;
            return osVirtualToPhysical(sp3C);
        }
        sp28 = sp2C;
        sp2C = sp2C->unk0;
    }
    sp2C = D_80055414;
    if (sp2C == NULL) {
        return osVirtualToPhysical((void* ) D_80055410);
    }
    D_80055414 = (ALCSPlayer* ) sp2C->unk0;
    alUnlink((ALLink* ) sp2C);
    if (sp28 != 0) {
        alLink((ALLink* ) sp2C, (ALLink* ) sp28);
    } else if (D_80055410 != 0) {
        sp28 = D_80055410;
        D_80055410 = (s32) sp2C;
        sp2C->unk0 = (ALPlayer* ) sp28;
        sp2C->unk4 = 0;
        sp28->unk4 = sp2C;
    } else {
        D_80055410 = (s32) sp2C;
        sp2C->unk0 = 0;
        sp2C->unk4 = 0;
    }
    sp3C = sp2C->unk10;
    sp38 = arg0 & 1;
    arg0 -= sp38;
    sp2C->unk8 = (s32 (*)(void*)) arg0;
    sp2C->unkC = D_80055418;
    osWritebackDCache((void* ) sp3C, (s32) D_80055424);
    osInvalDCache((void* ) sp3C, (s32) D_80055424);
    osPiStartDma(&D_80055440[D_8005541C++], 0, 0, arg0, (void* ) sp3C, D_80055424, &D_80055740);
    return osVirtualToPhysical((void* ) sp3C) + sp38;
}

void *__amDmaNew(s32** arg0) {
    *arg0 = &D_80055410;
    return &__amDMA;
}

void __clearAudioDMA(void) {
    u32 sp24;
    void* sp20;
    struct UnkStruct80055410 *sp1C;
    s32 sp18;

    for(sp24 = 0; sp24 < D_8005541C; sp24++) {
        osRecvMesg(&D_80055740, &sp20, 1);
    }
    
    sp1C = D_80055410;
    if (sp1C != 0) {
        do {
            sp18 = sp1C->unk0;
            if ((u32) (sp1C->unkC + 1) < (u32) D_80055418) {
                if (D_80055410 == sp1C) {
                    D_80055410 = sp1C->unk0;
                }
                alUnlink((ALLink* ) sp1C);
                if (D_80055414 != NULL) {
                    alLink((ALLink* ) sp1C, (ALLink* ) D_80055414);
                } else {
                    D_80055414 = (ALCSPlayer* ) sp1C;
                    sp1C->unk0 = 0;
                    sp1C->unk4 = 0;
                }
            }
            sp1C = sp18;
        } while (sp1C != 0);
    }
    D_8005541C = 0;
    D_80055418 += 1;
}
