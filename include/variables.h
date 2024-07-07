#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"

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

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

struct ShortPair {
    s16 unk0;
    s16 unk2;
};

struct MegaStruct {
     struct Vec3f D_80134F28;
     struct Vec3f D_80134F34;
     f32 D_80134F40;
     struct Vec3f D_80134F44;
     struct Vec3f D_80134F50;
     struct Vec3f D_80134F5C;
     struct Vec3f D_80134F68;
     f32 D_80134F74;
     struct Vec3f D_80134F78;
     struct Vec3f D_80134F84;
     struct Vec3f D_80134F90;
     f32 D_80134F9C;
     struct ShortPair D_80134FA0;
     struct ShortPair D_80134FA4;
     s32 D_80134FA8;
};

struct UnkStruct_8008AE64
{
    s32 Unk0;
    char Padding[9];
};

struct UnkStruct80088B80
{
    s16 Unk0;
    char Padding[17];
};

struct UnkStruct80088B80_2
{
    f32 Unk0;
    char Padding[13];
};

struct UnkStruct80088B80_3
{
    struct UnkStruct_8008AE64 Unk0;
    char Padding[0x3];
};

struct PlayerStruct
{
    f32 PosX; //00
    f32 PosY; //04
    f32 PosZ; //08
    f32 ScaleX;
    f32 ScaleY;
    f32 ScaleZ;
    f32 RotX; //18
    f32 RotY; //1C
    f32 RotZ; //20
    f32 VelX; //24
    f32 VelY; //28
    f32 VelZ; //2C
    char pad30[0x8];
    f32 unk38;
    f32 unk3C;
    f32 unk40;                          /* inferred */
    f32 unk44;
    f32 unk48;                          /* inferred */
    char padding6[0x8];
    f32 unk54;
    char padding13[0x4C];
    s16 unkA4;
    s16 unkA6;
    s16 unkA8;
    s16 unkAA;
    s16 unkAC;
    s16 unkAE;                          /* inferred */
    char padB0[2];
    s16 unkB2;
    char padding8[0x30];
    s16 unkE4;
    char padding9[0x2];
    s16 unkE8;
    s16 unkEA;
    char padding10[0x18];
    s16 unk104;
    s16 unk106;
    s16 unk108;
    char padding14[0x28];
    u8 unk132;
    char padding11[0x7];
    s8 unk13A;
    s8 unk13B;
    s8 unk13C;
    s8 unk13D;
    s8 unk13E;
    s8 unk13F;
    s16 Unk140;
    char padding12[0x150 - 0x140 - sizeof(s16)];
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
extern s8 gShowDebugMenu;
extern s32 D_8016E428;
extern s32 D_801765EC;
extern s32 osViClock;

extern OSViMode osViModeTable[];

extern s8 D_80134BF0;
extern s16 D_80134BF2;
extern s16 D_80134BF4;
extern s16 D_80134BF6_unused; // need this because bss shenanigans
extern s16 D_80134BF8;
extern s16 D_80134BFA;
extern s16 D_80134BFC;
extern s16 *D_80134C00;
extern s16 *D_80134C04_unused;
extern s16* D_80134C08;
extern s16 D_80134C0C;
extern s16 D_80134C0E;
extern s16 D_80134C10;
extern s16 D_80134C12;
extern s16 D_80134C14;
extern s16 D_80134C16;
extern s16 D_80134C18;
extern s16 D_80134C1A;
extern s16 D_80134C1C;
extern s16 D_80134C1E;
extern s16 D_80134C20;
extern s16 D_80134C22;
extern s8 D_80134C24;
extern s8 D_80134C25;
extern s8 D_80134C26;
extern s16 D_80134C28[0x18];
extern s16 D_80134C58[0x18];
extern s16 D_80134C88[0x18];
extern s16 D_80134CB8[0x18];
extern s16 D_80134CE8[0x18];
extern s16 D_80134D18[0x18];

struct UnkStruct80134D48 {
    u32 *unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
}; // size = 0x14

extern struct UnkStruct80134D48 D_80134D48[0x18];
extern struct MegaStruct gMegaStruct; // 80134F28

extern u8 gDebugTextBuf[0xC8];

struct UnkStructSTCG
{
    f32 Unk0;
    f32 Unk4;
    f32 Unk8;
    char Padding_3[0x24 - (sizeof(f32) * 3)];
    f32 Unk24;
    f32 Unk28;
    f32 Unk2C;
    char Padding_1[0xA4 - 0x24 - (sizeof(s32) * 3)];
    s16 UnkA4;
    char Padding_2[0x108 - 0xA4 - sizeof(s16)];
    s16 Unk108;
};

extern struct PlayerStruct gPlayerData[];

struct UnkStruct_80060278
{
    s32 unk0;
    u8 Padding[4];
};

extern struct UnkStruct_80060278 D_8016CAA0[700];

struct View {
    /* 0x00 */ struct Vec3f at;
    /* 0x0C */ struct Vec3f eye;
    /* 0x18 */ struct Vec3f rot;
    /* 0x24 */ struct Vec3f up;
    /* 0x30 */ f32 dist;
}; // size=0x34

extern struct View gView;

extern Gfx *gMasterDisplayList;

#endif // _VARIABLES_H_
