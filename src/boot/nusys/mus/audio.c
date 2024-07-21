#include <ultra64.h>
#include "../../38D0.h"
#include "nusys/audio.h"
#include "prevent_bss_reordering.h"

// might be based on an older nusys 1.0 version we dont have due to some of the absent safety checks.

/**** audio manager globals ****/

struct UnkStructPair D_80053160;
struct UnkStructPair D_80053168;
s32 D_80053170;
s32 D_80053174_unused;
s32 D_80053178;
AMAudioMgr __am;
u64 audioStack[AUDIO_STACKSIZE/sizeof(u64)];
struct UnkStruct80055408 *D_80055408;
AMDMAState dmaState;
u32 audFrameCt;
s32 nextDMA;
u16 num_dmas;
u32 audio_dma_length;
u32 curAcmdList;
u32 minFrameSize;
s32 maxFrameSize;
u32 frameSize;
s32 D_80055438;
s32 D_8005543C;
OSIoMesg audio_IO_mess_buf[32];
OSMesgQueue audDMAMessageQ;
void* audio_mess_buf;
u8 D_80055760_unused[0x80];

static void __amMain(void* arg);
static s32 __amHandleFrameMsg(AudioInfo* info, AudioInfo *lastInfo);
static void __amHandleDoneMsg(AudioInfo *info);
static s32 __amDMA(s32 addr, s32 len, void *state);
static ALDMAproc *__amDmaNew(AMDMAState** state);
static void __clearAudioDMA(void);

s32 amCreateAudioMgr(ALSynConfig* c, amConfig* amc) {
    s32 i;
    f32 fsize;
    AMDMABuffer* audio_dma_buffers;
    s16 ret = 0;

    D_80053168.unk0  = D_80053168.unk4 = 0;
    D_80053160.unk0  = D_80053160.unk4 = 0;
    curAcmdList      = 0;
    nextDMA          = 0;
    audFrameCt       = 0;
    num_dmas         = amc->numDmas;
    audio_dma_length = amc->unk4;
    D_80055408       = (void*)c->heap;
    c->dmaproc       = &__amDmaNew;
    c->outputRate    = osAiSetFrequency(amc->outputRate);

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
            audio_dma_buffers[i].ptr = h_alHeapAlloc(audio_dma_length);
            if (audio_dma_buffers[i].ptr == NULL) {
                ret = 1;
                goto after;
            }
        }

        audio_dma_buffers[i].ptr = h_alHeapAlloc(audio_dma_length);
        if (audio_dma_buffers[i].ptr == NULL) {
            ret = 1;;
        } else {
            dmaState.firstUsed = 0;
            dmaState.firstFree = (void*)audio_dma_buffers;
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

static s32 __amHandleFrameMsg(AudioInfo* info, AudioInfo *lastInfo) {
    s16 *audioPtr;
    Acmd* cmdp;
    s32 cmdLen;
    int samplesLeft = 0;
    OSScTask *t;

    __clearAudioDMA(); /* call once a frame, before doing alAudioFrame */
    audioPtr = (s16 *) osVirtualToPhysical(info->data);

    if (lastInfo)
        osAiSetNextBuffer(lastInfo->data, lastInfo->frameSamples << 2);

    /* calculate how many samples needed for this frame to keep the DAC full */
    /* this will vary slightly frame to frame, must recalculate every frame */
    samplesLeft = osAiGetLength() >> 2; /* divide by four, to convert bytes */
                                        /* to stereo 16 bit samples */

    info->frameSamples = 16 + ((frameSize - samplesLeft + EXTRA_SAMPLES) & ~0xf); // need the extra parens to match.. why, its not there in the demo code
    if (info->frameSamples < minFrameSize)
        info->frameSamples = minFrameSize;
    cmdp = alAudioFrame((Acmd* ) __am.ACMDList[curAcmdList], &cmdLen, audioPtr, info->frameSamples);
    if (cmdLen == 0) /* no task produced, return zero to show no valid task */
        return 0;

    t = &info->task;
    
    t->next      = 0;                    /* paranoia */
    t->flags     = OS_SC_NEEDS_RSP;      // ...the flags write is up here instead i guess
    t->msgQ      = &__am.audioReplyMsgQ; /* reply to when finished */
    t->msg       = (OSMesg)&info->msg;   /* reply with this message */
    
    t->list.t.data_ptr    = (u64 *) __am.ACMDList[curAcmdList];
    t->list.t.data_size   = (cmdp - __am.ACMDList[curAcmdList]) * sizeof(Acmd);
    t->list.t.type  = M_AUDTASK;
    t->list.t.ucode_boot = (u64 *)rspbootTextStart;
    t->list.t.ucode_boot_size = ((int) rspbootTextEnd - (int) rspbootTextStart);
    t->list.t.flags  = 0; //OS_TASK_DP_WAIT;
    t->list.t.ucode = _4A060_data__s; // aspMainTextStart
    t->list.t.ucode_data = _4DD30_bin; // aspMainDataStart
    t->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    t->list.t.dram_stack = (u64 *) NULL;
    t->list.t.dram_stack_size = 0;
    t->list.t.output_buff = (u64 *) NULL;
    t->list.t.output_buff_size = 0;
    t->list.t.yield_data_ptr = NULL;
    t->list.t.yield_data_size = 0;

    osSendMesg((OSMesgQueue* ) D_80053170, t, OS_MESG_BLOCK);

    curAcmdList ^= 1; /* swap which acmd list you use each frame */    

    return 1;
}

static void __amHandleDoneMsg(AudioInfo *info) {
/*
    s32    samplesLeft;
    static int firstTime = 1;

    samplesLeft = osAiGetLength()>>2;
    if (samplesLeft == 0 && !firstTime) 
    {
#ifdef _AUDIODEBUG
        osSyncPrintf("AUDIO.C: ai out of samples\n");    
#endif
        firstTime = 0;
    }
*/
    return;
}

static s32 __amDMA(s32 addr, s32 len, void *state) {
    void* foundBuffer;
    s32 delta, addrEnd, buffEnd;
    AMDMABuffer *dmaPtr, *lastDmaPtr;

    lastDmaPtr = 0;
    dmaPtr = dmaState.firstUsed;
    addrEnd = addr + len;

    /* first check to see if a currently existing buffer contains the
       sample that you need.  */

    while (dmaPtr) {
        buffEnd = dmaPtr->startAddr + audio_dma_length;
        if (dmaPtr->startAddr > addr) { /* since buffers are ordered */
            break;                      /* abort if past possible */
        } else if (addrEnd <= buffEnd) {    /* yes, found a buffer with samples */
            dmaPtr->lastFrame = audFrameCt; /* mark it used */
            foundBuffer = dmaPtr->ptr + addr - dmaPtr->startAddr;
            return (int) osVirtualToPhysical(foundBuffer);
        }
        lastDmaPtr = dmaPtr;
        dmaPtr = (AMDMABuffer*)dmaPtr->node.next;
    }
    
    /* get here, and you didn't find a buffer, so dma a new one */
    
    /* get a buffer from the free list */
    dmaPtr = dmaState.firstFree;
    
    /* if no dma buffer is free, return bogus value - stops crashes */
    if (!dmaPtr) {
        return osVirtualToPhysical(dmaState.firstUsed);
    }

    dmaState.firstFree = (ALCSPlayer* ) dmaPtr->node.next;
    alUnlink((ALLink* ) dmaPtr);

    /* add it to the used list */
    if (lastDmaPtr) { /* if you have other dmabuffers used, add this one */
                      /* to the list, after the last one checked above */
        alLink((ALLink* ) dmaPtr, (ALLink* )lastDmaPtr);
    } else if (dmaState.firstUsed != 0) { /* if this buffer is before any others */
        lastDmaPtr = dmaState.firstUsed;  /* jam at begining of list */ 
        dmaState.firstUsed = (s32) dmaPtr;
        dmaPtr->node.next = (ALPlayer* ) lastDmaPtr;
        dmaPtr->node.prev = 0;
        lastDmaPtr->node.prev = (ALLink*)dmaPtr;
    } else { /* no buffers in list, this is the first one */
        dmaState.firstUsed = (s32) dmaPtr;
        dmaPtr->node.next = 0;
        dmaPtr->node.prev = 0;
    }

    foundBuffer = dmaPtr->ptr;
    delta = addr & 0x1;
    addr -= delta;
    dmaPtr->startAddr = addr;
    dmaPtr->lastFrame = audFrameCt;  /* mark it */
    osWritebackDCache(foundBuffer, audio_dma_length);
    osInvalDCache(foundBuffer, audio_dma_length);
    osPiStartDma(&audio_IO_mess_buf[nextDMA++], OS_MESG_PRI_NORMAL, OS_READ, (u32)addr, foundBuffer, audio_dma_length, &audDMAMessageQ);

    return (int) osVirtualToPhysical(foundBuffer) + delta;
}

static ALDMAproc *__amDmaNew(AMDMAState** state) {
    *state = &dmaState;
    return &__amDMA;
}

static void __clearAudioDMA(void) {
    u32          i;
    OSIoMesg     *iomsg;
    AMDMABuffer  *dmaPtr,*nextPtr;

    for(i = 0; i < nextDMA; i++) {
        osRecvMesg(&audDMAMessageQ, &iomsg, OS_MESG_BLOCK); // this blocks where as the original demo code doesnt...
    }
    
    dmaPtr = dmaState.firstUsed;
    while(dmaPtr) {
        nextPtr = (AMDMABuffer*)dmaPtr->node.next;

        /* remove old dma's from list */
        /* Can change FRAME_LAG value.  Should be at least one.  */
        /* Larger values mean more buffers needed, but fewer DMA's */
        if (dmaPtr->lastFrame + FRAME_LAG  < audFrameCt) {
            if (dmaState.firstUsed == dmaPtr) {
                dmaState.firstUsed = (AMDMABuffer*)dmaPtr->node.next;
            }
            alUnlink((ALLink* ) dmaPtr);
            if (dmaState.firstFree != NULL) {
                alLink((ALLink* ) dmaPtr, (ALLink* ) dmaState.firstFree);
            } else {
                dmaState.firstFree = (ALCSPlayer* ) dmaPtr;
                dmaPtr->node.next = 0;
                dmaPtr->node.prev = 0;
            }
        }
        dmaPtr = nextPtr;
    }
    nextDMA = 0; /* reset */
    audFrameCt++;
}

/* end of file */
