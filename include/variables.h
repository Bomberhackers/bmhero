#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"
#include "prevent_bss_reordering.h"

extern OSMesgQueue D_801776B0;
extern OSMesg D_801776CC;
extern u8 D_8016E27C;
extern OSContStatus D_80177650;

struct UnkStruct8016E280 {
    u16 unk00[4];
    char filler8[0x8];
    u16 unk10[4];
    char filler18[0x8];
    u16 unk20[4];
    char filler28[0x8];
    u16 unk30[4];
    char filler38[0x4];
    u8 unk3C[4];
    char filler40[0x4];
    u8 unk44[4];
    char filler48[0x8];
    u16 unk50[4];
    char filler58[0x8];
    u16 unk60[4];
    char filler68[0x8];
    u16 unk70[4];
    char filler78[0x8];
};

extern struct UnkStruct8016E280 D_8016E280;
extern struct UnkStruct8016E280 D_8016E300;

struct UnkInputStruct80001CF0 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    char filler8[0x4];
    OSTask unk10;
};

struct UnkStruct80001CF0 {
    s16 unk0;
    char filler2[0x1E];
    s16 unk20;
    char filler22[0x40-0x22];
    OSMesgQueue unk40;
    OSMesg unk58;
    char filler5C[0x1C];
    OSMesgQueue unk78;
    OSMesg unk90;
    char filler94[0x1C];
    OSThread unkB0;
    u32 unk260;
    u32 unk264;
    u32 unk268;
    u32 unk26C;
    u32 unk270;
    struct UnkInputStruct80001CF0 *unk274;
    u32 unk278;
    u32 unk27C;
    u32 unk280;
};

struct UnkStruct80340000 {
    char filler0[0x18170];
}; // size = 0x18170

struct UnkStruct260 {
    u32 unk0;
    OSMesg unk4;
};

struct UnkStruct80002424 {
    char filler0[0x4];
    u32 unk4;
    u32 unk8;
    void *unkC;
    u32 unk10;
    char filler14[0x3C];
    OSMesgQueue *unk50;
    OSMesg unk54;
};

struct UnkStruct8000265C {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    char fillerC[0x4];
    u32 unk10;
};

struct UnkStruct800026F4_Arg1 {
    char filler0[0x4];
    u32 unk4;
    char filler8[0x8];
    OSTask unk10;
};

struct UnkStruct800026F4_Arg2 {
    char filler0[0x38];
    u32 unk38;
    u64 *unk3C;
};

// extern symbols
extern u32 D_8004A280;
extern s32 D_8004A294;
extern s32 D_8004A298;
extern s32 D_8004A29C;
extern s32 D_8004A380;
extern s32 D_8004A384;
extern s32 D_8004A388;
extern s32 D_8004A38C;
extern u32 D_8016524C;
extern OSMesgQueue D_8016E0B8;
extern OSMesg D_8016E0D8;
extern s32 D_80165254;
extern s32 D_8016525C;
extern s32 D_80165264;
extern s32 D_80165284;
extern s32 D_8016E098;
extern s32 D_8016E0A0;

extern u8 D_8016E450[];
extern u32 D_801110F0[];
extern u32 D_8010BC30[];

extern struct UnkStruct80340000 D_80340000[2];

extern s32 D_80134224;
extern s32 D_80134228;
extern s32 D_8016527C;
extern s16 D_8016E092;
extern s8 D_8016E134;
extern s8 D_8016E3DC;
extern s8 D_8016E3E4;
extern s8 D_8016E3EC;
extern s8 D_8016E3EE;
extern s16 D_8016E3F4;
extern s8 D_8016E3F7;
extern s8 D_8016E3FC;
extern s8 D_8016E404;
extern s8 D_8016E40C;
extern s8 D_8016E414;
extern s16 D_8016E41C;
extern s8 D_8016E424;
extern s32 D_8016E428;
extern s32 D_801765EC;
extern s32 osViClock;

extern OSViMode D_8004A770[];

#endif // _VARIABLES_H_
