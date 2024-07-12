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

static void __amMain(void* arg);

s32 amCreateAudioMgr(ALSynConfig* c, amConfig* amc) {
    s32 i;
    f32 fsize;
    AMDMABuffer* audio_dma_buffers;
    s16 ret = 0;

    D_80053168.unk0 = D_80053168.unk4 = 0;
    D_80053160.unk0 = D_80053160.unk4 = 0;
    D_80055428      = 0;
    D_8005541C      = 0;
    audFrameCt      = 0;
    num_dmas        = amc->numDmas;
    D_80055424      = amc->unk4;
    D_80055408      = (void*)c->heap;
    c->dmaproc      = &__amDmaNew;
    c->outputRate   = osAiSetFrequency(amc->outputRate);

    /*
     * Calculate the frame sample parameters from the
     * video field rate and the output rate
     */
    if (D_8004A280 == 0) {
        fsize = ((f32)amc->framesPerField * (s32)c->outputRate) / 60.0f;
    } else {
        fsize = ((f32)amc->framesPerField * (s32)c->outputRate) / 50.0f;
    }

    frameSize = (s32) fsize;
    if (frameSize < fsize) {
        frameSize += 1;
    }

#ifdef N_AUDIO
    frameSize = ((frameSize / SAMPLES) + 1) * SAMPLES;
    minFrameSize = frameSize - SAMPLES;
#else
    if (frameSize & 0xf)
        frameSize = (frameSize & ~0xf) + 0x10;
    minFrameSize = frameSize - 16;
#endif

    maxFrameSize = frameSize + EXTRA_SAMPLES + 16;

    alInit(&__am.g, c);

    audio_dma_buffers = h_alHeapAlloc(num_dmas*sizeof(AMDMABuffer));
    if (audio_dma_buffers == NULL) {
        ret = 1;;
    } else {
        audio_dma_buffers[num_dmas-1].node.next = 0;
        audio_dma_buffers->node.prev = audio_dma_buffers->node.next = audio_dma_buffers[num_dmas-1].node.next;

        for(i = 0; i < num_dmas-1; i++) {
            alLink((ALLink*)&audio_dma_buffers[i+1],(ALLink*)&audio_dma_buffers[i]);
            audio_dma_buffers[i].ptr = h_alHeapAlloc(D_80055424);
            if (audio_dma_buffers[i].ptr == NULL) {
                ret = 1;
                goto after;
            }
        }

        audio_dma_buffers[i].ptr = h_alHeapAlloc(D_80055424);
        if (audio_dma_buffers[i].ptr == NULL) {
            ret = 1;;
        } else {
            D_80055410 = 0;
            D_80055414 = (void*)audio_dma_buffers;
            D_80055438 = amc->unkC;

            for(i = 0; i < NUM_ACMD_LISTS; i++) {
                __am.ACMDList[i] = (Acmd*)h_alHeapAlloc(D_80055438 * sizeof(Acmd));
                if (__am.ACMDList[i] == NULL) {
                    ret = 1;;
                    goto after;
                }
            }
            
            /**** initialize the done messages ****/
            for(i = 0; i < 3; i++) {
                __am.audioInfo[i] = (AudioInfo *)h_alHeapAlloc(sizeof(AudioInfo));
                if (__am.audioInfo[i] == NULL) {
                    ret = 1;;
                    goto after;
                }
                __am.audioInfo[i]->msg.done.type = OS_SC_DONE_MSG;
                __am.audioInfo[i]->msg.done.info = __am.audioInfo[i];
                __am.audioInfo[i]->data = h_alHeapAlloc(4*maxFrameSize);
                if (__am.audioInfo[i]->data == NULL) {
                    ret = 1;;
                    goto after;
                }
            }
        }
    }
after:;
    osCreateMesgQueue(&__am.audioReplyMsgQ, __am.audioReplyMsgBuf, MAX_MESGS);
    osCreateMesgQueue(&audDMAMessageQ, &audio_mess_buf, 0x20);
    if (amc->unk14 != 0) {
        osCreateMesgQueue(&__am.audioFrameMsgQ, __am.audioFrameMsgBuf, MAX_MESGS);
        D_80053170 = func_80001FDC(amc->unk14);
        func_80001E78(amc->unk14, (u32)&D_80053178, (u32)&__am.audioFrameMsgQ);
    }
    osCreateThread(&__am.thread, amc->threadID, __amMain, NULL, (void *)(audioStack+AUDIO_STACKSIZE/sizeof(u64)), amc->pri);
    osStartThread(&__am.thread);
    return ret;
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

/**
 * Safer version of alHeapAlloc. Do not alloc anything if the heap size doesnt have enough.
 */
void* h_alHeapAlloc(s32 size) {
    if ((D_80055408->unk8 - (D_80055408->unk4 - D_80055408->unk0)) < size) {
        D_80053160.unk0 |= 1;
        return NULL;
    }
    return alHeapAlloc((ALHeap* ) D_80055408, 1, size);
}

static void __amMain(void* arg) {
    u32       validTask;
    u32       done=0;
    AudioMsg  *msg;
    AudioInfo *lastInfo = 0;

    while(!done) {
        (void) osRecvMesg(&__am.audioFrameMsgQ, (OSMesg *)&msg, OS_MESG_BLOCK);
        switch (msg->gen.type) {
        case OS_SC_RETRACE_MSG:
            validTask = __amHandleFrameMsg(__am.audioInfo[audFrameCt % NUM_OUTPUT_BUFFERS], lastInfo);
            if (validTask) {
                osRecvMesg(&__am.audioReplyMsgQ, (OSMesg *)&msg, OS_MESG_BLOCK);
                __amHandleDoneMsg(msg->done.info);
                lastInfo = msg->done.info;
                func_80003C94();
                func_80007BC4();
            }
            D_8005543C += 1;
            break;
        case OS_SC_PRE_NMI_MSG:
            func_80003FA0();
            func_8000ABB4();
            done = 1;
            break;
        case QUIT_MSG:
            done = 1;
            break;
        }
    }
    alClose(&__am.g);
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
    *(s16*)&arg0->unk0[1] = ((((frameSize - sp20) + 0x50) & ~0xF) + 0x10);
    if (*(s16*)&arg0->unk0[1] < (u32) minFrameSize) {
        *(s16*)&arg0->unk0[1] = (s16) minFrameSize;
    }
    sp28 = alAudioFrame((Acmd* ) __am.ACMDList[D_80055428], &sp24, (s16* ) sp2C, *(s16*)&arg0->unk0[1]);
    if (sp24 == 0) {
        return 0;
    }

    sp1C = &arg0->unk8;
    sp1C->unk0 = 0;
    sp1C->unk8 = 2;
    sp1C->unk50 = &__am.audioReplyMsgQ;
    sp1C->unk54 = &arg0->unk8.unk68;
    sp1C->unk40 = (s32) __am.ACMDList[D_80055428];
    sp1C->unk44 = (((s32) ((u32)sp28 - (u32)__am.ACMDList[D_80055428]) >> 3) * 8);
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
            sp2C->unkC = audFrameCt;
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
    sp2C->unkC = audFrameCt;
    osWritebackDCache((void* ) sp3C, (s32) D_80055424);
    osInvalDCache((void* ) sp3C, (s32) D_80055424);
    osPiStartDma(&D_80055440[D_8005541C++], 0, 0, arg0, (void* ) sp3C, D_80055424, &audDMAMessageQ);
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
        osRecvMesg(&audDMAMessageQ, &sp20, 1);
    }
    
    sp1C = D_80055410;
    if (sp1C != 0) {
        do {
            sp18 = sp1C->unk0;
            if ((u32) (sp1C->unkC + 1) < (u32) audFrameCt) {
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
    audFrameCt += 1;
}
