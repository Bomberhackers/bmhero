#ifndef _NUSYS_AUDIO_H_
#define _NUSYS_AUDIO_H_

#include <sched.h>

#define EXTRA_SAMPLES           80
#define NUM_OUTPUT_BUFFERS      3
#define MAX_MESGS               8
#define NUM_ACMD_LISTS          2

#define AUDIO_STACKSIZE         0x2000

// AMDMABuffer
typedef struct {
    ALLink        node;
    u32           startAddr;
    u32           lastFrame;
    char          *ptr;
} AMDMABuffer;

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

typedef union {    
    struct {
        short     type;
    } gen;
    struct {
        short     type;
        struct    AudioInfo_s *info;
    } done;
    OSScMsg       app;
} AudioMsg;

typedef struct AudioInfo_s {
    short         *data;          /* Output data pointer */
    short         frameSamples;   /* # of samples synthesized in this frame */
    OSScTask      task;           /* scheduler structure */
    AudioMsg      msg;            /* completion message */
} AudioInfo;

typedef struct {
    Acmd          *ACMDList[2];
    AudioInfo     *audioInfo[NUM_OUTPUT_BUFFERS];
    OSThread      thread;
    OSMesgQueue   audioFrameMsgQ;
    OSMesg        audioFrameMsgBuf[MAX_MESGS];
    OSMesgQueue   audioReplyMsgQ;
    OSMesg        audioReplyMsgBuf[MAX_MESGS];
    ALGlobals     g;
} AMAudioMgr;

struct UnkInnerStruct80053188_Ptr {
    u32 unk0;
    char filler4[0x4];
    u32 unk8;
    char fillerC[0x4];
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    char filler24[0x4];
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;
    u32 unk50;
    u32 unk54;
    char filler58[0x10];
    s16 unk68;
    u32 unk70;
};

struct UnkStruct80053188_Ptr {
    u32 unk0[2];
    struct UnkInnerStruct80053188_Ptr unk8;
};

struct UnkStruct80055408 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct UnkInputStruct8000DA70_Arg1 {
    u32 unk0;
    s16 unk4;
};

struct UnkStruct80055440 {
    char filler0[0x18];
};

struct UnkInputStruct8000DD40_sp2C {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
};

struct UnkInputStruct8000DD40_sp28 {
    u32 unk0;
    u32 unk4;
};

struct UnkStruct80055410 {
    u32 unk0;
    u32 unk4;
    char filler8[0x4];
    u32 unkC;
};

extern s32 D_80047F60;
extern s32 D_80048030;
extern s32 D_80049460;
extern s32 D_80053170;
extern s32 D_80053178;
extern AMAudioMgr __am;
extern struct UnkStruct80053188_Ptr *D_80053188[];
extern u64 audioStack[];
extern struct UnkStruct80055408 *D_80055408;
extern struct UnkStruct80055410 *D_80055410;
extern ALCSPlayer* D_80055414;
extern s32 D_80055418;
extern s32 D_8005541C;
extern u16 num_dmas;
extern u32 D_80055424;
extern s32 D_80055428;
extern s32 minFrameSize;
extern s32 maxFrameSize;
extern u32 frameSize;
extern s32 D_80055438;
extern s32 D_8005543C;
extern struct UnkStruct80055440 D_80055440[];
extern OSMesgQueue audDMAMessageQ;
extern void* audio_mess_buf;

typedef struct {
    /* 0x00 */ u16 numDmas;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 framesPerField;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 outputRate;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 pri;
    /* 0x1C */ u32 threadID;
} amConfig; // size=0x20

// functions
s32 amCreateAudioMgr(ALSynConfig* c, amConfig* amc);
void* h_alHeapAlloc(s32);
void __amMain(void*);
s32 __amHandleFrameMsg(struct UnkStruct80053188_Ptr* arg0, struct UnkInputStruct8000DA70_Arg1 *arg1);
void __amHandleDoneMsg(s32 arg0);
u32 __amDMA(u32 arg0, u32 arg1, s32 arg2);
void *__amDmaNew(s32** arg0);
void __clearAudioDMA(void);

#endif // _NUSYS_AUDIO_H_
