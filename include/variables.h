#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"

// structs and defines

struct UnkStruct8010B3FC {
    char filler0[0x20];
    Lights2 *unk20;
};

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} UnkStruct80165100;

struct UnkStruct8016E104 {
    /* 0x00 */ Mtx unk00[3];
    /* 0xC0 */ Hilite hilites[2];
    /* 0xE0 */ Mtx unkE0[1];
};

struct UnkStruct8016E10C {
    u32 unk0;
    u8 filler4[0x4];
    u32 unk8;
    u32 unkC;
    OSTask task;
    OSMesgQueue *unk50;
    u32 unk54;
    u32 unk58;
    u8 filler5C[0x4];
    u32 unk60;
    u8 filler64[0x18148-0x64];
    u32 unk18148[1];
    u8 filler1814C[0x1C];
    u32 unk18168;
};

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

struct Light
{
    u8 LightData[8];
};

struct LightingStruct
{
    struct Light AmbientLight;
    struct Light DiffuseLight;
    s8 Direction[8];
};

struct LevelInfo {
    /* 0x00 */ s8 Stage;
    /* 0x01 */ s8 Area;
    /* 0x02 */ s8 Map;
    /* 0x03 */ s8 Clear;
    char filler4[0x4];
    /* 0x08 */ u8* Unk8;
    char fillerC[0x13];
    /* 0x20 */ Lights2* unk20;
    /* 0x24 */ Lights2* LightingInfo;
};

struct ObjectStruct 
{
    struct Vec3f Pos;
    struct Vec3f Scale;
    struct Vec3f Rot;
    struct Vec3f Vel;
    char pad30[0x8];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    char padding15[0x14];
    f32 unk70;
    char padding16[0x18];
    f32 unk8C;
    char padding13[0x14];
    s16 unkA4;
    s16 unkA6;
    s16 unkA8;
    s16 unkAA;
    s16 unkAC;
    s16 unkAE;
    s16 unkB0;
    s16 unkB2;
    s16 unkB4;
    s16 unkB6;
    s16 unkB8;
    s16 unkBA;
    s16 unkBC;
    s16 unkBE;
    s16 unkC0;
    s16 unkC2;
    char padding8[0x10];
    f32 unkD4;
    char padding9[0xB];
    s16 unkE4;
    s16 unkE6[0x1];
    s16 unkE8[0x2];
    s16 unkEC;
    char padding10[0xE];
    s16 unkFC;
    char padding11[0x2];
    s16 unk100;
    s8 unk102;
    s8 unk103;
    s16 unk104;
    s16 unk106;
    s16 unk108;
    char Pad10A[1];
    u8 unk10B;
    u8 unk10C;
    s16 unk10E[1];
    char pad10C[0x18];
    f32 unk128;
    f32 unk12C;
    char pad[0x1];
    u8 unk131;
    u8 unk132;
    char pad133[0x7];
    s8 unk13A;
    s8 unk13B;
    s8 unk13C;
    s8 unk13D;
    s8 unk13E;
    s8 unk13F;
    s16 Unk140[1];
    char pad142[0xC];
};

struct UnkStruct80134D48 {
    u32 *unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
}; // size = 0x14

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

struct UnkStruct_80060278
{
    s32 unk0;
    u8 Padding[4];
};

struct View {
    /* 0x00 */ struct Vec3f at;
    /* 0x0C */ struct Vec3f eye;
    /* 0x18 */ struct Vec3f rot;
    /* 0x24 */ struct Vec3f up;
    /* 0x30 */ f32 dist;
}; // size=0x34

// DEMO IDs
#define DEMO_TITLE_INTRO                0
#define DEMO_CREDIT_SCENE               1
#define DEMO_BOMBER_CHANGE_JET_QUICK    2
#define DEMO_BOMBER_CHANGE_MARINE_QUICK 3
#define DEMO_BOMBER_CHANGE_COPTER_QUICK 4
#define DEMO_BOMBER_CHANGE_SLIDER_QUICK 5
#define DEMO_BOMBER_CHANGE_JET          6
#define DEMO_BOMBER_CHANGE_MARINE       7
#define DEMO_BOMBER_CHANGE_COPTER       8
#define DEMO_BOMBER_CHANGE_SLIDER       9
#define DEMO_LAST DEMO_BOMBER_CHANGE_SLIDER

struct UnkStruct80165290 {
    s32 unk0;
    char padding4[0x10];
    u8 unk14;
    char padding15[0x7];
    s32 unk1C;
    char padding20[0x50];
};

struct UnkStruct_8001EFD0 {
    s32 unk0;
    char pad[0x64];
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
};

struct UnkStruct_8004A5F0 {
    s32 unk0;
    char pad [0xE];
    s8 unkE;
};

// externs

extern struct UnkStruct_8004A5F0 D_8004A5F0;
extern s32 D_8004A5F4;
extern u8 D_8004A610;
extern s32 D_8004A630;
extern s32 D_8004A634;
extern s32 D_8004A638;
extern s32 D_8004A63C;
extern OSPfs D_80056D90;
extern s32 D_80056DF8;
extern s32 D_80056DFC;
extern s32 D_80056E00;
extern s32 D_80056E04;
extern s32 D_80056E08;
extern s32 D_80056E0C;
extern s32 D_80056E10;
extern s32 D_80056E14;
extern s32 D_80056E18;
extern s32 D_80056E1C;
extern s32 D_80056E20;
extern u8 D_80057240[];
extern u8 D_8005704E[2][1];
extern struct UnkStruct_8001EFD0 D_80056E28[];
extern struct UnkStruct_8001EFD0 D_80056E98[];
extern struct UnkStruct_8001EFD0 D_80056E9C[];
extern struct UnkStruct_8001EFD0 D_80056EA4[];
extern OSPfsState D_80057040[];
extern s8 D_80057440;
extern s8 D_80057441;

extern s32 D_8016E3A4;

extern u8 D_1000C68[];
extern u8 D_1000B78[];
extern u8 D_1000C50[];

extern s32 D_8016525C;
extern void (*D_80165274)();
extern s32 D_8016527C;
extern s32 D_80165284;
extern s32 D_8016E0B0;
extern s32 D_8016E244;

extern Gfx* gMasterDisplayList;

extern Lights2 D_8004A590;

extern struct LevelInfo* gLevelInfo[];

extern s32 D_8016E084;
extern s32 D_8016E08C;
extern s32 D_8016E244;
extern s32 D_8016E26C;
extern s32 D_8016E274;
extern s32 D_801765F4;
extern s8 D_80176602;
extern u8 D_801775BC;
extern u8 D_801775C4;
extern u8 D_801775CC;
extern u8 D_801775D4;
extern u8 D_801775DC;
extern u8 D_801775E4;
extern u8 D_801775EC;

extern u8 gspF3DEX_fifoTextStart_bin[];
extern u8 D_801D04B0[];
extern u32 D_801C1A50;
extern u32 D_801C0E50;

extern Lights2 gLightingSettings;

extern OSMesg D_801776CC;
extern OSContStatus D_80177650[];

extern s32 D_8016525C;
extern s32 D_80165284;
extern u8 gControllerBits;
extern u16 gContPlugged[4];
extern u16 gContCurrButton[4];
extern u16 gContLastButton[4];
extern u16 gContButtonPressed[4];
extern s8 gContStickX[4];
extern s8 gContStickY[4];
extern u16 gContCurrDir[4];
extern u16 gContLastDir[4];
extern u16 gContDirPressed[4];
extern u16 gContRawPlugged[4];
extern u16 gContRawCurrButton[4];
extern u16 gContRawLastButton[4];
extern u16 gContRawButtonPressed[4];
extern s8 gContRawStickX[4];
extern s8 gContRawStickY[4];
extern u16 gContRawCurrDir[4];
extern u16 gContRawLastDir[4];
extern u16 gContRawDirPressed[4];
extern OSContPad gContPads[4];
extern OSMesgQueue gContMesgQueue;

extern u16 gActiveContPort;
extern u16 gActiveContButton;
extern u16 gActiveContPressed;
extern f32 gActiveContStickX;
extern f32 gActiveContStickY;
extern u16 gActiveContCurrDir;
extern u16 gActiveContDirPressed;

extern s8 D_801776F8;
extern s8 D_80177708;
extern s32 D_80177718;
extern s32 D_80177728;
extern s32 D_80177738;
extern u16 D_80177748[];
extern u16 D_80177758[];
extern u16 D_80177768[];

extern void (*D_8016526C)();
extern s32 D_8016E0A8;

extern struct UnkStruct8016E104 *D_8016E104;

extern struct UnkStruct8016E10C* D_8016E10C;

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

extern s32 gDebugSelectedDemoIndex;
extern s32 gDebugSaveIndex;
extern s32 D_8016527C;
extern s16 D_8016E092;
extern s8 D_8016E134;
extern s8 D_8016E3DC;
extern s8 gDebugShowTimerBar;
extern s8 D_8016E3EC;
extern s8 D_8016E3EE;
extern s16 D_8016E3F4;
extern s8 gDebugDisplayMode;
extern s8 gDebugInvincibileFlag;
extern s8 gDebugAtrributeFlag;
extern s8 gGoldBomber;
extern s8 D_8016E414;
extern s16 D_8016E41C;
extern s8 gShowDebugMenu;
extern s32 gCurrentLevel;
extern s32 gCameraType;
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

extern struct UnkStruct80134D48 D_80134D48[0x18];
extern struct MegaStruct gMegaStruct;

extern u8 gDebugTextBuf[0xC8];

extern struct ObjectStruct gObjects[];

extern struct UnkStruct_80060278 D_8016CAA0[700];
extern struct View gView;

extern Gfx *gMasterDisplayList;

extern s8 gDemoSceneID;
extern s8 gDemoID;

extern struct UnkStruct80165290 D_80165290[256];
extern u32 *D_8016E3AC;

#endif // _VARIABLES_H_
