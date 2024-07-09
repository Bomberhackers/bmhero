#ifndef _NUSYS_AUDIO_H_
#define _NUSYS_AUDIO_H_

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
    /* 0x000 */ s32 unk0[2];
    char filler8[0x1C0];
    /* 0x1C0 */ OSMesgQueue queue;
    char filler1E0[0x20];
    /* 0x200 */ OSMesgQueue queue2;
    /* 0x218 */ OSMesg mesg218;
    char filler21C[0x1C];
    /* 0x238 */ ALGlobals unk238;
};

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
extern struct UnkStruct80053180 D_80053180;
extern struct UnkStruct80053188_Ptr *D_80053188[];
extern s32 D_80053408;
extern struct UnkStruct80055408 *D_80055408;
extern struct UnkStruct80055410 *D_80055410;
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
extern s32 D_8005543C;
extern struct UnkStruct80055440 D_80055440[];
extern OSMesgQueue D_80055740;
extern void* D_80055758;

// functions
s32 amCreateAudioMgr(struct UnkInputStruct8000D120_arg0* arg0, struct UnkInputStruct8000D120_arg1* arg1);
void* func_8000D84C(s32);
void __amMain(void*);
s32 __amHandleFrameMsg(struct UnkStruct80053188_Ptr* arg0, struct UnkInputStruct8000DA70_Arg1 *arg1);
void __amHandleDoneMsg(s32 arg0);
u32 __amDMA(u32 arg0, u32 arg1, s32 arg2);
void *__amDmaNew(s32** arg0);
void __clearAudioDMA(void);

#endif // _NUSYS_AUDIO_H_
