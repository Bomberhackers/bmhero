#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include <ultra64.h>

#define UNK_TYPE s32

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

// could be a Vector
struct UnkStruct8004A3A0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

// could be Struct Tri. describes 3 vectors
struct UnkInputStruct8000FEB0 {
    struct UnkStruct8004A3A0 unk0;
    struct UnkStruct8004A3A0 unkC;
    struct UnkStruct8004A3A0 unk18;
};

struct UnkStruct80055D50 {
    u32 unk0;
    struct UnkStruct8004A3A0 unk4[3];
    u32 unk28;
    u32 unk2C;
}; // size = 0x30

struct UnkInputStruct8000FF44 {
    u32 unk0;
    u32 unk4;
    char filler8[0x4];
    struct UnkInputStruct8000FF44 **unkC;
    s32 unk10;
    struct UnkStruct8004A3A0 unk14[3];
};

struct UnkInputStruct80010098 {
    u32 unk0;
    char filler4[0x24];
    struct UnkInputStruct8000FF44 *unk28;
};

struct UnkInputStruct800100E8_SP24 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 *unkC;
    u32 unk10;
    u32 unk14;
    char filler18[0x18];
};

struct UnkInputStruct80010350 {
    char filler0[0xC];
    u32 *unkC;
    s32 unk10;
};

struct UnkStruct8016E3AC {
    char filler0[0xC];
    u32 unkC;
    char filler10[0x8];
    u32 unk18;
};

struct UnkInputStruct80010408_Inner {
    u32 unk0;
    u32 unk4;
    char filler8[0x4];
};

struct UnkInputStruct80010408 {
    char filler0[0x4];
    u32 unk4;
    char filler8[0x4];
    struct UnkInputStruct80010408_Inner unkC[1];
};

struct UnkStruct80010408_SP2C {
    u32 unk0;
    struct UnkStruct8004A3A0 unk4[3];
    u32 unk28;
};

struct UnkStruct800105D8 {
    u32 unk0;
    char filler4[0x24];
    struct UnkInputStruct80010350* unk28;
};

struct UnkInputStruct80010634_SP20 {
    u32 *unk0;
    s32 unk4;
    struct UnkStruct8004A3A0 unk8;
    struct UnkStruct8004A3A0 unk14;
    struct UnkStruct8004A3A0 unk20;
};

struct UnkStruct80055D54 {
    char filler0[0x4];
    struct UnkInputStruct80010634_SP20 *unk4;
    u32 unk8;
};

struct UnkInputStruct800108D0 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

struct UnkInputStruct80010B6C {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

struct UnkInputStruct80010B6C_2 {
    struct UnkStruct8004A3A0 unk0[3];
};

struct UnkInputStruct80010C88 {
    u32 *unk0;
    char filler4[0x4];
    struct UnkInputStruct80010C88 **unk8;
    s32 unkC;
    u32 unk10[1]; // unk size
    char filler14[0x4];
    struct UnkInputStruct80010B6C_2 unk18[1];
};

struct UnkInputStruct80011084_Inner {
    u8 filler0[0x14];
    f32 unk14[3];
};

struct UnkInputStruct80011084 {
    struct UnkInputStruct80011084_Inner *unk0;
    u8 filler4[0x4];
    u32 *unk8;
    s32 unkC;
    u32 unk10;
    u32 unk14;
    f32 unk18[3];
    u8 filler24[0x18];
    f32 unk3C[3];
};

struct UnkStruct800111D4_Inner {
    u32 unk0[3];
    struct UnkStruct800111D4_Inner *unkC;
    u8 filler10[0x4];
    f32 unk14[3];
    f32 unk20[3];
    f32 unk2C[3];
};

struct UnkStruct800111D4 {
    u8 filler0[0x24];
    u32 unk24;
    struct UnkStruct800111D4_Inner *unk28;
};

struct UnkInputStruct8000E680 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    char fillerC[0x4];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    char filler1C[0x4];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    char filler2C[0x4];
};

struct UnkInnerStruct8000E944 {
    union {
        s32 unk0;
        f32 unk0_f;
    } u;
    f32 unk4;
    f32 unk8;
    char fillerC[0x1C];
    u32 unk28;
    u32 unk2C;
};

struct UnkInputStruct8000EEE8_SPE4 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};

struct UnkInputStruct8000EEE8_SPEC {
    s32 unk0; // type of unk4 union?
    union {
        f32 unk4_as_f;
        s32 unk4_as_s;
    } u;
    Gfx *dlist;
};

struct UnkInputStruct8000FC08 {
    s32 unk0;
    char filler4[0x8];
    u32 *unkC;
    s32 unk10;
    char filler14[0x14];
    u32 unk28;
};

struct UnkInputStruct800069D0 {
    u32 unk0;
    f32 unk4;
    u32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    u8 unk12;
    u8 unk13;
    s8 unk14;
    u8 unk15;
    u8 unk16;
};

struct UnkInputStruct80002F94 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u8 unk10;
    s32 *unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u16 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
};

struct UnkStruct80052D5C {
    u32 unk0;
    f32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    u16 unk1A;
    f32 unk1C;
    s16 unk20;
    s8 unk22;
    s8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    s8 unk29;
    char filler2A[0x2];
};

struct UnkStruct80052EB4 {
    u8 unk0;
    u8 unk1;
    char filler2[0x2];
    u32 len;
    u32 unk8;
    u32 unkC;
};

struct UnkStruct80052ED8 {
    struct UnkStruct80052ED8* unk0;
    char filler4[0x10];
};

struct UnkInputStruct800047C8 {
    u32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
};

struct UnkStruct80052D58 {
    s16 unk0;
    s16 unk2;
    char filler4[0x1]; // unk size
};

// this is some pointer ALBank has to, but it doesnt match up with an ALBank struct. What is this.
struct UnkALStruct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u16 unk4;
    u16 unk6;
};

struct UnkStruct80052D60 {
    u8 unk0;
    u8 unk1;
    char filler2[0x6];
};

struct UnkStructSP1C {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8  unkC;
    u8  unkD;
    u8  unkE;
    u8  unkF;
};

struct UnkStructSP18 {
    u32 unk0;
    char filler4[0x5];
    u8 unk9;
    char fillera[0x2];
    u32 unkC;
    u32 unk10;
};

struct UnkInputStruct80007140 {
    char filler0[0x13];
    u8 unk13;
};

typedef struct {  
    u8      rate;
    u8      depth;
    u8      oscCount;
} defData;

typedef struct {
    u8      halfdepth;
    u8      baseVol;
} tremSinData;
    
typedef struct {
    u8      curVal;
    u8      hiVal;
    u8      loVal;
} tremSqrData;

typedef struct {
    u8      baseVol;
    u8      depth;
} tremSawData;
    
typedef struct {
    f32     depthcents;
} vibSinData;

typedef struct {
    f32     loRatio;
    f32     hiRatio;
} vibSqrData;

typedef struct {
    s32     hicents;
    s32     centsrange;
} vibDSawData;

typedef struct {
    s32     locents;
    s32     centsrange;
} vibASawData;

// based on case 0xC9
typedef struct {
    f32    unkC;
} unkC9Data;

typedef struct oscData_s {
    struct oscData_s  *next;
    u8      type;
    u8      stateFlags;
    u16     maxCount;
    u16     curCount;
    union {
        defData         def;
        tremSinData     tsin;
        tremSqrData     tsqr;
        tremSawData     tsaw;
        vibSinData      vsin;
        vibSqrData      vsqr;
        vibDSawData     vdsaw;
        vibASawData     vasaw;
        unkC9Data       unk;
    } data;        
} oscData;

#define MAX_VOICES              22

/*
 * Number of osc states needed. In worst case will need two for each
 * voice. But if tremelo and vibrato not used on all instruments will
 * need less.
 */
#define  OSC_STATE_COUNT    2*MAX_VOICES 

#define  TREMELO_SIN        1
#define  TREMELO_SQR        2
#define  TREMELO_DSC_SAW    3
#define  TREMELO_ASC_SAW    4
#define  VIBRATO_SIN        128
#define  VIBRATO_SQR        129
#define  VIBRATO_DSC_SAW    130
#define  VIBRATO_ASC_SAW    131

#define AL_PAN_CENTER   64
#define AL_PAN_LEFT     0
#define AL_PAN_RIGHT    127
#define AL_VOL_FULL     127
#define AL_KEY_MIN      0
#define AL_KEY_MAX      127
#define AL_DEFAULT_FXMIX	0
#define AL_SUSTAIN      63

#define  OSC_HIGH   0
#define  OSC_LOW    1
#define  TWO_PI     6.2831853

struct UnkStruct8004A2A4 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    void* unk14;
    u32 unk18;
};

struct UnkStruct8004A310 {
    s32 unk0;
    void *unk4;
};

struct UnkStruct80052D80 {
    u32 unk0;
    u32 unk4;
};

struct UnkStruct80052D88 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s8 unkE;
};

struct UnkStruct80052DA8 {
    s16 unk0;
    s16 unk2;
    s8 unk4;
    s8 unk5;
    u8 unk6;
    s8 unk7;
    s8 unk8;
    s8 unk9;
    char fillerA[0x2];
};

struct UnkStruct_8011670C {
    s32 unk0;
    char pad[0x18];
};

struct UnkStruct_80027B34 {
    /* 0x0 */ s8 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s8 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC*/ s8 unkC;
};

struct UnkStruct_80027C00 {
    /* 0x0 */ s8 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s8 unk6;
    /* 0x7 */ s8 unk7;
    /* 0x8 */ s8 unk8;
    /* 0x9 */ s8 unk9;
    /* 0xA */ char unkA;
};

struct UnkStruct_80028260 {
    union {
        s32 unk0;
        f32 _unk0;
    };
    union {
        s32 unk4;
        f32 _unk4;
    };
};

struct UnkStruct_80026548 {
    // Dunno if this is real or not
    char unk0;
    char filler1[0x3];
    s8 unk4;
    char filler5[0x3];
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u8 unkE;
    s8 unkF;
    char filler10[0x4];
    void *(*routine)( );
    void *(*routine2)( );
    char filler1C[0x14];
    u64 unk30;
    char filler28[0x24];
};


struct UnkStruct_80027464 {
    s32 unk24[1];
    char pad[0x20];
};

typedef struct {
    s16 unk0;
    char padding[0x14E];
} UnkStruct800FA0DC;

typedef struct {
    f32 unk0;
} UnkStruct80114354;

struct String {
    u8 padding0[0x8];
    /* 0x08 */ s16 len;
    u8 padding8[0x2];
    s16 str[1]; // dynamic length
};

struct StringInfo {
    struct String *strInfo;
    s16 x;
    s16 y;
    s16 renderBG;
};

struct UnkStruct_801347A0 {
    s32 *arr;
};

struct UnkStruct80134794 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14[8];
    u32 unk34[8];
    s8 unk54;
};

struct UnkInputStruct_8001ABF4 {
    void *unk0;
    void *unk4;
    void *unk8;
    void *unkC;
    void *unk10;
    s16 unk14;
    u8 unk16;
    u8 unk17;
    u8 unk18;
};

struct UnkStruct_8010289C {
    struct String *unk0[7];
};

extern struct UnkStruct8016E230 {
    u32 unk0;
    u32 unk4;
} UnkStruct8016E230;

typedef struct UnkStruct_800600B8 {
    u8 Unk01;
    u8 Padding[3];
} UnkStruct_800600B8;

struct UnkStruct_56400 {
    s16* ptr;
    s16 Unk04;
    s16 Unk06;
};

struct UnkStruct80177778 {
    char filler0[0x18];
    s16 unk18;
};

struct UnkBigStruct_8006B64C
{
    u16 Unk0;
    u16 Unk1;
    u8 Padding[336 - sizeof(u32)];
};

// externs

// ROM Externs
extern Gfx D_01000000_unk_bin_0_2[];
extern u32 D_01000200_unk_bin_0_2[];
extern Vtx D_01000210_unk_bin_0_2[];
extern Vtx D_01000250_unk_bin_0_2[];
extern Gfx D_010002D0_unk_bin_0_2[];
extern u32 D_010004D0_unk_bin_0_2[];
extern Vtx D_010004E0_unk_bin_0_2[];
extern Vp D_01000B68_unk_bin_0_2;
extern u8 unk_bin_0_2_ROM_START[];
extern u8 code_extra_0_ROM_START[];
extern u8 gspF3DEX_fifoTextStart_bin[];
extern u8 _4A060_data__s[];
extern u8 _4DD30_bin[];
extern u8 _64C3C0_ROM_START[];
extern u8 _64EC60_ROM_START[];
extern u8 code_extra_0_ROM_START[]; 
extern u8 unk_bin_0_2_ROM_START[]; 
extern u8 D_1000768[];
extern u8 D_1000B78[];
extern u8 D_1000C50[];
extern u8 D_1000C68[];

// RAM Externs
extern u32 D_8004A280;
extern s32 D_8004A294;
extern s32 D_8004A298;
extern s32 D_8004A29C;
extern s32* D_8004A370;
extern s32 D_8004A380;
extern s32 D_8004A384;
extern s32 D_8004A388;
extern s32 D_8004A38C;
extern s32 D_8004A390;
extern s32 D_8004A394;
extern struct UnkStruct8004A3A0 D_8004A3A0;
extern struct UnkStruct8004A3A0 D_8004A3AC;
extern struct UnkStruct8004A3A0 D_8004A3B8;
extern s32 *D_8004A3D0;
extern f32 D_8004A400[]; // .rodata
extern Lights2 D_8004A590;
extern Lights2 gLightingSettings;
extern struct UnkStruct_8004A5F0 D_8004A5F0;
extern s32 D_8004A5F4;
extern u8 D_8004A610;
extern s32 D_8004A630;
extern s32 D_8004A634;
extern s32 D_8004A638;
extern s32 D_8004A63C;
extern s8 D_8004A650[];                        //.data
extern OSViMode osViModeTable[];
extern s32 osViClock;
extern f64 D_8004BBF0; // 180.0
extern f64 D_8004BBF8; // 360.0
extern f64 D_8004BC00; // 180.0
extern f64 D_8004BC08; // 360.0
extern f32 D_8004BC10; // .rodata
extern f32 D_8004BDB0;
extern f64 D_8004BDB8;
extern f64 D_8004BDC0;
extern f32 D_8004BDC8;
extern f64 D_8004BDD0;
extern f64 D_8004BDD8;
extern f64 D_8004BDF8;
extern f64 D_8004BE00;
extern f64 D_8004BE08;
extern f64 D_8004BE10;
extern f64 D_8004BE18;
extern f64 D_8004BE20;
extern f64 D_8004BE28;
extern f64 D_8004BE30;
extern ALHeap D_80052D40;
extern f32 D_800557E0[4];
extern s32 D_80055820;
extern s32 D_80055828;
extern u32 D_80055D30[];
extern u32 D_80055D40[];
extern s32 D_80055D4C;
extern struct UnkStruct80055D50 *D_80055D50;
extern struct UnkStruct80055D54 *D_80055D54;
extern u8 D_80055D70[];
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
extern struct UnkStruct_8001EFD0 D_80056E28[];
extern struct UnkStruct_8001EFD0 D_80056E98[];
extern struct UnkStruct_8001EFD0 D_80056E9C[];
extern struct UnkStruct_8001EFD0 D_80056EA4[];
extern OSPfsState D_80057040[];
extern u8 D_8005704E[2][1];
extern u8 D_80057240[];
extern s8 D_80057440;
extern s8 D_80057441;
extern struct UnkInputStruct_8001ABF4 D_80100560[4];
extern struct UnkInputStruct_8001ABF4 D_801005D0[4];
extern struct UnkInputStruct_8001ABF4 D_80100640[4];
extern struct UnkInputStruct_8001ABF4 D_801006B0[4];
extern struct UnkStruct80134794 D_80100720[];
extern struct UnkStruct80134794 D_80100A90[];
extern struct UnkStruct80134794 D_80100E00[];
extern struct UnkStruct80134794 D_80101170[];
extern struct UnkInputStruct_8001ABF4 D_80101758[25];
extern struct UnkInputStruct_8001ABF4 D_80101E8C[5];
extern struct UnkStruct80134794 D_80101A14[];
extern struct UnkStruct80134794 D_80101F18[];
extern struct UnkStruct_8010289C D_8010289C;
extern Gfx gDebugFont[];
extern s8 D_801039B0;
extern s8 D_801039B4;
extern s8 D_801039C4;
extern u8 D_80103948[];
extern s8 D_8010399C[0x12];
extern struct UnkStruct_800600B8 D_801039D4[];
extern void* D_80104A14[];
extern s16 D_80104B64[];
extern s16 D_80104C18[];
extern u8 D_80106DA0[];
extern u8 D_80106DA1[];
extern struct LevelInfo *gLevelInfo[4];
extern u32 D_8010BC30[];
extern s16 D_8010CD80[2];
extern s16 D_80110B78[];
extern s16* D_80110D4C[];
extern u32 D_801110F0[];
extern UnkStruct80165100 D_80113790;
extern UnkStruct80165100 D_801137D8;
extern UnkStruct80165100 D_801137E4;
extern struct ObjectStruct D_801137F0;
extern s32 D_801137FC;
extern s32 D_80113838;
extern struct UnkStruct_80027C00 D_80113694;
extern struct UnkStruct_80027C00 D_801136D0;
extern struct UnkStruct_80027C00 D_801136DC;
extern s32 D_80113A0C;
extern UNK_TYPE D_80113A18;
extern UNK_TYPE D_80113A24;
extern UNK_TYPE D_80113A30;
extern UNK_TYPE D_80113A3C;
extern UNK_TYPE D_80113A48;
extern UNK_TYPE D_80113A6C;
extern UNK_TYPE D_80113ACC;
extern UNK_TYPE D_80113AE4;
extern UNK_TYPE D_80113AF0;
extern s32 D_80113B08;
extern UNK_TYPE D_80113B68;
extern UNK_TYPE D_80113BB0;
extern UNK_TYPE D_80113C1C;
extern UNK_TYPE D_80113E50;
extern struct UnkStruct_80027C00 D_80113EC8;
extern UNK_TYPE D_80113D9C;
extern UNK_TYPE D_80113DA8;
extern UNK_TYPE D_80113DB4;
extern struct UnkStruct_80027C00 D_80113EBC;
extern UNK_TYPE D_80113DC0;
extern struct UnkStruct_80027C00 D_80114270;
extern struct UnkStruct_80027C00 D_8011427C;
extern s32 D_80114288[];
extern struct UnkStruct_80027C00 D_80114294;
extern struct UnkStruct_80027C00 D_801142A0;
extern struct UnkStruct_80027C00 D_801142C4;
extern struct UnkStruct_80027C00 D_801142D0;
extern struct UnkStruct_80027C00 D_801142DC;
extern UnkStruct80165100 D_801142E8;
extern UnkStruct80165100 D_801142F4;
extern UnkStruct80165100 D_80114300;
extern UnkStruct80165100 D_8011433C;
extern UnkStruct80165100 D_80114348;
extern void* D_80114354;
extern UnkStruct80165100 D_80114360;
extern UnkStruct80165100 D_8011436C;
extern struct ObjectStruct D_80114378;
extern struct ObjectStruct D_80114384;
extern UnkStruct80165100 D_80114390;
extern UnkStruct80165100 D_8011439C;
extern UnkStruct80165100 D_801143A8;
extern UnkStruct80165100 D_801143B4;
extern UnkStruct80165100 D_801143C0;
extern UnkStruct80165100 D_801143CC;
extern UnkStruct80165100 D_801143D8;
extern UnkStruct80165100 D_801143F0;
extern UnkStruct80165100 D_801143FC;
extern UnkStruct80165100 D_80114450;
extern UnkStruct80165100 D_8011445C;
extern UnkStruct80165100 D_80114468;
extern UnkStruct80165100 D_80114474;
extern struct ObjectStruct D_80114480;
extern struct ObjectStruct D_8011448C;
extern struct ObjectStruct D_80114498;
extern struct ObjectStruct D_801144A4;
extern UnkStruct80165100 D_801144B0;
extern s32 D_801144BC;
extern UnkStruct80165100 D_801144C8;
extern UnkStruct80165100 D_801144D4;
extern UnkStruct80165100 D_801144E0;
extern UnkStruct80165100 D_801144EC;
extern UnkStruct80165100 D_801144F8;
extern void* D_8011472C;
extern struct Vec3f D_80115180[];
extern struct Vec3f D_80115184[];
extern struct Vec3f D_80115188[];
extern f64 D_801153B8;
extern f64 D_801153C0;
extern f64 D_801153C8;
extern f64 D_801153F0;
extern f64 D_801153F8;
extern f64 D_80115400;
extern f64 D_80115428;
extern f64 D_80115430;
extern f64 D_80115438;
extern f64 D_80115460;
extern f64 D_80115468;
extern f32 D_8011550C;
extern f32 D_80115510;
extern f32 D_8011553C;
extern f32 D_80115540;
extern f32 D_80115544;
extern f32 D_80115548;
extern f32 D_8011554C;
extern f32 D_80115550;
extern f32 D_80115554;
extern f32 D_80115558;
extern f32 D_8011555C;
extern f32 D_80115560;
extern f64 D_801155C8;
extern f64 D_801155D0;
extern f64 D_801155D8;
extern f64 D_801155E0;
extern f64 D_801155E8;
extern f64 D_801155F0;
extern f64 D_80115610;
extern f64 D_80115618;
extern f64 D_80115620;
extern f64 D_80115628;
extern f64 D_80115630;
extern f64 D_80115638;
extern f32 D_801157BC;
extern s32 D_80116674[];                       //.rodata
extern struct UnkStruct_8011670C D_8011670C[]; //.rodata
extern s32 D_801168CC[];                       //.rodata
extern s32 D_801168D0[];                       //.rodata
extern s32 D_80117504;
extern s32 D_80117554;
extern s32 D_8011758C;
extern s32 D_80117AA0;
extern UNK_TYPE D_80117B4C;
extern UNK_TYPE D_80117B68;
extern UNK_TYPE D_80117B84;
extern UNK_TYPE D_80117BA0;
extern UNK_TYPE D_80117BBC;
extern UNK_TYPE D_80117BC0;
extern UNK_TYPE D_80117C00;
extern UNK_TYPE D_80117C1C;
extern UNK_TYPE D_80117C38;
extern UNK_TYPE D_80117C78;
extern UNK_TYPE D_80117D8C;
extern UNK_TYPE D_80117E04;
extern UNK_TYPE D_80117D8C;
extern UNK_TYPE D_80117DE8;
extern UNK_TYPE D_80117E20;
extern UNK_TYPE D_80117E48;
extern UNK_TYPE D_80117E64;
extern UNK_TYPE D_80117EA8;
extern UNK_TYPE D_80117EC4;
extern UNK_TYPE D_80117EE0;
extern UNK_TYPE D_80117EE8;
extern UNK_TYPE D_80117EF0;
extern void* D_80117F08;
extern UNK_TYPE* D_80118978[];
extern s32 D_80118B38;
extern s32 D_80118BDC;
extern s32 D_80118BE0;
extern s32 D_80118C10;
extern s32 D_80118C8C[];
extern struct ObjectStruct D_80118E9C;
extern struct ObjectStruct D_80118EB4;
extern struct ObjectStruct D_80118FE8;
extern struct ObjectStruct D_80118FF4;
extern struct ObjectStruct D_801190CC;
extern struct ObjectStruct D_80119128;
extern struct ObjectStruct D_80119194;
extern struct ObjectStruct D_801191F0;
extern struct ObjectStruct D_80119268;
extern struct ObjectStruct D_801192E0;
extern struct ObjectStruct D_8011935C;
extern struct ObjectStruct D_80119384;
extern struct ObjectStruct D_801193AC;
extern struct ObjectStruct D_8011940C;
extern struct ObjectStruct D_80119428;
extern struct ObjectStruct D_80119494;
extern struct ObjectStruct D_80119504;
extern struct ObjectStruct D_8011955C;
extern struct ObjectStruct D_801195D0;
extern struct ObjectStruct D_80119578;
extern struct ObjectStruct D_80119654;
extern struct ObjectStruct D_801196AC;
extern struct ObjectStruct D_80119750;
extern struct ObjectStruct D_80119788;
extern struct ObjectStruct D_80119828;
extern struct ObjectStruct D_801198D0;
extern struct ObjectStruct D_801198EC;
extern struct ObjectStruct D_80119908;
extern struct ObjectStruct D_8011990C;
extern struct ObjectStruct D_8011993C;
extern struct ObjectStruct D_80119974;
extern struct ObjectStruct D_80119978;
extern struct ObjectStruct D_8011997C;
extern struct ObjectStruct D_80119980;
extern struct ObjectStruct D_801199AC;
extern struct ObjectStruct D_801199E4;
extern struct ObjectStruct D_80119A40;
extern struct ObjectStruct D_80119A60;
extern struct ObjectStruct D_8011BA88;
extern struct ObjectStruct D_8011BA8C;
extern struct ObjectStruct D_8011BB50;
extern s32 D_8011BA94;
extern struct UnkStruct_80026548 D_80124D90[];
extern s32 gDebugCurrentMenuItem;
extern s32 D_80134218;
extern s32 gDebugSelectedMusicIndex;
extern s32 gDebugSelectedSoundIndex;
extern s32 gDebugSelectedDemoIndex;
extern s32 gDebugSaveIndex;
extern s8 D_80134334;
extern s8 D_80134340;
extern s8 D_8013435C;
extern s8 D_80134378;
extern s8 D_8013438C;
extern s8 D_801343A4;
extern s8 D_801343BC;
extern s8 D_801343CC;
extern s8 D_801343DC;
extern s8 D_801343F0;
extern s16 D_80134730;
extern s16 D_80134734;
extern s16 D_80134738[];
extern u16* D_80134784[2];
extern s8 D_80134790;
extern s8 D_80134791;
extern struct UnkStruct80134794* D_80134794;
extern s8 gDemoSceneID;
extern s8 gDemoID;
extern struct UnkStruct80134794* D_8013479C;
extern struct UnkStruct_801347A0 D_801347A0;
extern f32 *D_801347A4;
extern f32 D_801347A8;
extern s32 D_801347AC;
extern s32 D_801347B0;
extern f32 D_801347B4;
extern f32 D_801347B8;
extern f32 D_801347BC;
extern f32 D_801347C0;
extern f32 D_801347C4;
extern f32 D_801347C8;
extern f32 D_801347CC;
extern f32 D_801347D0;
extern f32 D_801347D4;
extern f32 D_801347D8;
extern f32 D_801347DC;
extern f32 D_801347E0;
extern s8 D_801347E4;
extern s8 D_801347E5;
extern s8 D_801347E6;
extern struct StringInfo D_801347E8;
extern s8 D_80134801;
extern s8 D_80134802;
extern s8 D_80134803;
extern u8 D_80134808[];
extern s8 D_8013488C;
extern s16 D_801348B0;
extern s8 D_801348B2;
extern struct UnkStruct_56400 D_801348B8[];
extern f32 D_80134F40;
extern s32 D_80134FD0;
extern struct ObjectStruct gObjects[];
extern struct UnkBigStruct_8006B64C D_801541F8[];
extern UnkStruct80165100 *D_80165100;
extern s16 D_80165108;
extern s16 D_8016510A;
extern s16 D_8016510C;
extern s16 D_8016510E;
extern s16 D_80165110;
extern s16 D_80165112;
extern s16 D_80165114;
extern s16 D_80165116;
extern u8 D_80165118[0x80];
extern s32 D_80165198;
extern s32 D_8016519C;
extern s16 D_801651A0;
extern u8 D_801651A8;
extern s32 D_801651AC;
extern s32 D_801651B0;
extern s32 D_801651B4;
extern s32 D_801651B8;
extern s32 D_801651BC;
extern f32 D_801651C0;
extern u8 D_80165238;
extern s8 D_80165239;
extern s8 D_8016523A;
extern s8 D_8016523B;
extern s8 D_8016523C;
extern u8 D_8016523D;
extern s8 gBombCount;
extern s8 gFireCount;
extern u8 gGemCount;
extern s8 D_80165242;
extern u8 gLifeCount;
extern s8 gHealthCount;
extern s8 gMaxHealth;
extern u32 D_8016524C;
extern s32 D_80165254;
extern s32 D_8016525C;
extern s32 D_80165264;
extern void (*D_8016526C)();
extern void (*D_80165274)();
extern s32 D_8016527C;
extern s32 D_80165284;
extern struct UnkStruct80165290 D_80165290[256];
extern struct UnkStruct_80060278 D_8016CAA0[700];
extern s32 D_8016E084;
extern s32 D_8016E08C;
extern s16 D_8016E092;
extern s32 D_8016E098;
extern s32 D_8016E0A0;
extern s32 D_8016E0A8;
extern s32 D_8016E0B0;
extern OSMesgQueue D_8016E0B8;
extern OSMesg D_8016E0D8;
extern Gfx *gMasterDisplayList;
extern struct UnkStruct8016E104 *D_8016E104;
extern struct UnkStruct8016E10C* D_8016E10C;
extern s8 D_8016E110;
extern s16 D_8016E112;
extern s8 D_8016E115;
extern s8 D_8016E134;
extern struct View gView;
extern u8 gDebugTextBuf[0xC8];
extern struct UnkStruct8016E230 D_8016E220[1];
extern struct UnkStruct8016E230 D_8016E230[1];
extern s32 D_8016E23C;
extern s32 D_8016E244;
extern u32 D_8016E254;
extern s32 D_8016E25C;
extern u32 D_8016E264;
extern s32 D_8016E26C;
extern s32 D_8016E274;
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
extern u16 gActiveContPort;
extern u16 gActiveContButton;
extern u16 gActiveContPressed;
extern f32 gActiveContStickX;
extern f32 gActiveContStickY;
extern u16 gActiveContCurrDir;
extern u16 gActiveContDirPressed;
extern s32 D_8016E3A4;
extern u32 *D_8016E3AC;
extern f32 D_8016E3B4;
extern f32 D_8016E3BC;
extern f32 D_8016E3C4;
extern s8 D_8016E3CC;
extern s8 D_8016E3CD;
extern s8 D_8016E3D4;
extern s8 D_8016E3DC;
extern s8 D_8016E3EC;
extern s8 D_8016E3EE;
extern s16 D_8016E3F4;
extern s8 gDebugShowTimerBar;
extern s8 gDebugDisplayMode;
extern s8 gDebugInvincibileFlag;
extern s8 gDebugAtrributeFlag;
extern s8 gGoldBomber;
extern s8 D_8016E414;
extern s16 D_8016E41C;
extern s8 gShowDebugMenu;
extern s32 gCurrentLevel;
extern s16 D_8016E432;
extern u8 D_8016E450[];
extern s32 gCameraType;
extern s32 D_801765F4;
extern s8 D_80176602;
extern struct ObjectStruct *D_8017753C;
extern f32 D_80177550[44];
extern u8 D_801775BC;
extern u8 D_801775C4;
extern u8 D_801775CC;
extern u8 D_801775D4;
extern u8 D_801775DC;
extern s8 D_801775EE;
extern u8 D_801775E4;
extern u8 D_801775EC;
extern s16 D_801775F6;
extern s16 D_801775FA;
extern s16 D_80177600;
extern s16 D_80177608;
extern s8 D_80177628;
extern s8 D_80177630;
extern s8 D_80177640;
extern OSContStatus D_80177650[];
extern OSContPad gContPads[4];
extern OSMesgQueue gContMesgQueue;
extern OSMesg D_801776CC;
extern s32 D_801776F0[];
extern s8 D_801776F8;
extern u8 D_801776E0;
extern f32 D_80177760[];
extern s16 D_80177788;
extern s16 D_80177798;
extern s16 D_801777A8;
extern s32 D_80177700[];
extern s32 D_80177710[];
extern s32 D_80177718;
extern s32 D_80177720[];
extern s32 D_80177728;
extern s32 D_80177730[];
extern s32 D_80177738;
extern s32 D_80177740[];
extern s8 D_80177708;
extern struct UnkStruct80177778* D_80177778;
extern u16 D_80177748[];
extern u16 D_80177758[];
extern u16 D_80177768[];
extern s32 D_801778F4;
extern s32 D_801778FC;
extern s32 D_80177904;
extern s8 D_8017792D;
extern u8 D_80177932;
extern u8 D_80177933;
extern u8 D_80177934;
extern u16 D_80177936;
extern u8 D_80177938;
extern u8 D_80177939;
extern u8 D_8017793A;
extern u16 D_8017793C;
extern u8 D_8017793E;
extern s8 D_8017793F;
extern u8 D_80177940;
extern u16 D_80177942;
extern s16 D_80177944;
extern u16 D_80177946;
extern s16 D_80177948;
extern u16 D_8017794A;
extern u16 D_80177950;
extern u16 D_80177958;
extern UnkStruct80165100 *D_8017796C;
extern u8 D_80177974;
extern u32 D_8017797C;
extern u32 D_80177984;
extern s16 D_8017798C;
extern s16 D_80177994;
extern s16 D_8017799C;
extern s16 D_801779A4;
extern s16 D_801779AC;
extern s16 D_801779B8;
extern u8 D_801779E0;
extern f32 D_801779C8;
extern s32 gCurrentParsedObject;
extern s32 D_80177A64;
extern u32 D_801C0E50;
extern u32 D_801C1A50;
extern u8 D_801D04B0[];
extern s32 D_80321428;
extern s32* D_80324994;
extern struct UnkStruct80340000 D_80340000[2];
extern s32 D_80380000;

#endif // VARIABLES_H
