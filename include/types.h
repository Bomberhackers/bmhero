#ifndef _BMHERO_TYPES_H_
#define _BMHERO_TYPES_H_

// structs and defines

#define UNK_TYPE s32
#define FABS(x) ((x) < 0.0f ? -(x) : (x))
#define IABS(x) ((x) < 0 ? -(x) : (x))
#define CLAMP_FLOAT(x) (((x) < -48.0f ? -48.0f : (x)))
#define MIN_CLAMP(a, b) ((a) > (b) ? (b) : CLAMP_FLOAT(a))
#define ALIGN16(val) (((val) + 0xF) & ~0xF)



typedef float Matrix[4][4];

struct UnkStruct8010B3FC {
    char pad0[0x20];
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

// Gfx work area
struct UnkStruct8016E104 {
    /* 0x00 */ Mtx unk00[3];
    /* 0xC0 */ Hilite hilites[2];
    /* 0xE0 */ Mtx unkE0[1];
    u8 pad120[0x80E0-0x120];
    /* 0x80E0 */ Gfx gfxWork[1]; // unk size
}; // size: unk due to Gfx

// a kind of "SystemWork" struct?
struct UnkStruct8016E10C {
    /* 0x00000 */ u32 unk0;
    u8 pad4[0x4];
    /* 0x00008 */ u32 unk8;
    /* 0x0000C */ u32 unkC;
    /* 0x00010 */ OSTask task;
    /* 0x00050 */ OSMesgQueue *unk50;
    /* 0x00054 */ u32 unk54;
    /* 0x00058 */ u32 redBarTimer; // seems to be never used or accessed.
    u8 pad5C[0x4];
    /* 0x00060 */ u32 greenBarTimer; // same as redBarTimer.
    u8 pad64[0x4];
    /* 0x00068 */ struct UnkStruct8016E104 unk68; // Gfx work?
    u8 pad8150[0x18148-0x8150];
    /* 0x18148 */ s16 unk18148[1];
    u8 pad1814C[0x1C];
    /* 0x18168 */ u32 unk18168;
};

struct UnkInputStruct80001CF0 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    char pad8[0x4];
    OSTask unk10;
};

struct UnkStruct80001CF0 {
    s16 unk0;
    char pad2[0x1E];
    s16 unk20;
    char pad22[0x40-0x22];
    OSMesgQueue unk40;
    OSMesg unk58;
    char pad5C[0x1C];
    OSMesgQueue unk78;
    OSMesg unk90;
    char pad94[0x1C];
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
    char pad0[0x18170];
}; // size = 0x18170

struct UnkStruct260 {
    u32 unk0;
    OSMesg unk4;
};

struct UnkStruct80002424 {
    char pad0[0x4];
    u32 unk4;
    u32 unk8;
    void *unkC;
    u32 unk10;
    char pad14[0x3C];
    OSMesgQueue *unk50;
    OSMesg unk54;
};

struct UnkStruct8000265C {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    char padC[0x4];
    u32 unk10;
};

struct UnkStruct800026F4_Arg1 {
    char pad0[0x4];
    u32 unk4;
    char pad8[0x8];
    OSTask unk10;
};

struct UnkStruct800026F4_Arg2 {
    char pad0[0x38];
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
    char padding[9];
};

struct UnkStruct80088B80
{
    s16 Unk0;
    char padding[17];
};

struct UnkStruct80088B80_2
{
    f32 Unk0;
    char padding[13];
};

struct UnkStruct80088B80_3
{
    struct UnkStruct_8008AE64 Unk0;
    char padding[0x3];
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
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 trackID;
    /* 0x08 */ u8* Unk8;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ Lights2* unk20;
    /* 0x24 */ void (*unk24)();
    /* 0x28 */ void (*unk28)();
    /* 0x2C */ f32 unk2C;
               s16 unk30;
               char pad;
               s8 unk33;
               s8 unk34;
};

struct ObjectStruct {
    /* 0x000 */ struct Vec3f Pos;
    /* 0x00C */ struct Vec3f Scale;
    /* 0x018 */ struct Vec3f Rot;
    /* 0x024 */ struct Vec3f Vel;
    /* 0x030 */ struct Vec3f unk30;
    /* 0x03C */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04C */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05C */ f32 unk5C;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ Matrix unk64;
    /* 0x0A4 */ s16 unkA4;
    /* 0x0A6 */ s16 unkA6;
    /* 0x0A8 */ s16 unkA8;
    /* 0x0AA */ s16 unkAA;
    /* 0x0AC */ s16 unkAC;
    /* 0x0AE */ s16 unkAE;
    /* 0x0B0 */ s16 unkB0;
    /* 0x0B2 */ s16 unkB2;
    /* 0x0B4 */ s16 unkB4;
    /* 0x0B6 */ s16 unkB6;
    /* 0x0B8 */ s16 unkB8;
    /* 0x0BA */ s16 unkBA;
    /* 0x0BC */ s16 unkBC;
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ s16 unkC0;
    /* 0x0C2 */ s16 unkC2;
    /* 0x0C4 */ s32 unkC4;                   /* maybe part of unkC2[9]? */
    /* 0x0C8 */ s32 unkC8;
    /* 0x0CC*/  s32 unkCC;
    /* 0x0D0 */ s32 unkD0;
    /* 0x0D4 */ f32 unkD4;
    /* 0x0D8 */ f32 unkD8;
    /* 0x0DC */ f32 unkDC;                          /* inferred */
    /* 0x0E0 */ f32 unkE0;                          /* inferred */
    /* 0x0E4 */ s16 unkE4;
    /* 0x0E6 */ s16 unkE6[1];
    /* 0x0E8 */ s16 unkE8[0xA];
    /* 0x0FC */ s16 unkFC;
    /* 0x0FE */ s16 unkFE;
    /* 0x100 */ s16 unk100;
    /* 0x102 */ s8 unk102;
    /* 0x103 */ s8 unk103;
    /* 0x104 */ s16 unk104;
    /* 0x106 */ s16 unk106;
    /* 0x108 */ s16 unk108;
    /* 0x10A */ u8 unk10A;
    /* 0x10B */ u8 unk10B;
    /* 0x10C */ u8 unk10C;
    /* 0x10D */ char pad10D[1];
    /* 0x10E */ s16 unk10E[10];
    /* 0x124 */ f32 unk124;
    /* 0x128 */ f32 unk128;
    /* 0x12C */ f32 unk12C;
    /* 0x130 */ char unk130;
    /* 0x131 */ u8 unk131;
    /* 0x132 */ u8 unk132;
    /* 0x133 */ char unk133[3];                     /* maybe part of unk132[8]? */
    /* 0x136 */ char unk136[3];
    /* 0x139 */ s8 unk139;
    /* 0x13A */ s8 unk13A;
    /* 0x13B */ s8 unk13B;
    /* 0x13C */ s16 unk13C[1];
    /* 0x13E */ s8 unk13E;
    /* 0x13F */ s8 unk13F;
    /* 0x140 */ s16 Unk140[4];
    /* 0x148 */ s16 Unk148[4];
                
};                                                

struct UnkStruct80134D48 {
    u32 ObjectID;
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
    char padding_3[0x24 - (sizeof(f32) * 3)];
    f32 Unk24;
    f32 Unk28;
    f32 Unk2C;
    char padding_1[0xA4 - 0x24 - (sizeof(s32) * 3)];
    s16 UnkA4;
    char padding_2[0x108 - 0xA4 - sizeof(s16)];
    s16 Unk108;
};

struct DecompressedFileEntry
{
    u8 *ptr; // ptr to the decompressed file area
    u8 pad4[4]; // unused
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

struct UnkStruct80165290_Unk20_Unk10 {
    char pad0[0x4];
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
};

struct UnkStruct80165290_Unk20 {
    struct UnkStruct80010408_SP2C *unk0;
    f32 unk4;
    u32 unk8;
    u32 unkC;
    struct UnkStruct80165290_Unk20_Unk10 *unk10;
    char pad14[0x8];
};

struct UnkStruct80165290 {
    /* 0x00 */ s32 unk0;
    char pad4[0x10];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    char pad17[0x1];
    /* 0x18 */ void* unk18;
    /* 0x1C */ struct UnkStruct80010408_SP2C* unk1C;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ void* unk28;
    /* 0x2C */ void* unk2C;
    /* 0x30 */ u32 unk30;
    /* 0x34 */ void* unk34;
    /* 0x38 */ u32 unk38;
    /* 0x4C */ void* unk3C;
    /* 0x40 */ u32 unk40;
    /* 0x44 */ void* unk44;
    /* 0x48 */ u32 unk48;
    /* 0x4C */ u32 unk4C;
    /* 0x50 */ u32 unk50;
    /* 0x54 */ u32 unk54;
    /* 0x58 */ u32 unk58;
    /* 0x5C */ u32 unk5C;
    /* 0x60 */ u32 unk60;
    char pad64[0xC];
}; // size:0x70

struct UnkStruct_8001EFD0_1 {
    u32 unk0;
    u32 unk4;
    u16 unk8;
    u8 unkA;
    u8 padB;
    u8 padC;
    u8 padD;
    u8 unkE;
};

struct UnkStruct_8001EFD0 {
    OSPfs pfs;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    OSPfsState* unk80[1]; // TODO: This is UB
};

// could be a Vector
struct UnkStruct8004A3A0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

// could be Struct Tri. describes 3 vectors
struct UnkInputStruct8000FEB0 {
    struct Vec3f unk0;
    struct Vec3f unkC;
    struct Vec3f unk18;
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
    char pad8[0x4];
    struct UnkInputStruct8000FF44 **unkC;
    s32 unk10;
    struct UnkStruct8004A3A0 unk14[3];
};

struct UnkInputStruct80010098 {
    u32 unk0;
    char pad4[0x24];
    struct UnkInputStruct8000FF44 *unk28;
};

struct UnkInputStruct800100E8_SP24 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 *unkC;
    u32 unk10;
    u32 unk14;
    char pad18[0x18];
};

struct UnkInputStruct80010350 {
    char pad0[0xC];
    u32 *unkC;
    s32 unk10;
};

struct UnkStruct8016E3AC {
    char pad0[0xC];
    u32 unkC;
    char pad10[0x8];
    u32 unk18;
};

struct UnkInputStruct80010408_Inner {
    u32 unk0;
    u32 unk4;
    char pad8[0x4];
};

struct UnkInputStruct80010408 {
    char pad0[0x4];
    u32 unk4;
    char pad8[0x4];
    struct UnkInputStruct80010408_Inner unkC[1];
};

struct UnkStruct80010408_SP2C {
    u32 unk0;
    struct UnkStruct8004A3A0 unk4[3];
    u32 unk28;
};

struct UnkStruct800105D8 {
    u32 unk0;
    char pad4[0x24];
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
    s32 unk0;
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
    char pad4[0x4];
    struct UnkInputStruct80010C88 **unk8;
    s32 unkC;
    u32 unk10[1]; // unk size
    char pad14[0x4];
    struct UnkInputStruct80010B6C_2 unk18[1];
};

struct UnkInputStruct80011084_Inner {
    u8 pad0[0x14];
    f32 unk14[3];
};

struct UnkInputStruct80011084 {
    struct UnkInputStruct80011084_Inner *unk0;
    u8 pad4[0x4];
    u32 *unk8;
    s32 unkC;
    u32 unk10;
    u32 unk14;
    f32 unk18[3];
    u8 pad24[0x18];
    f32 unk3C[3];
};

struct UnkStruct800111D4_Inner {
    u32 unk0[3];
    struct UnkStruct800111D4_Inner *unkC;
    u8 pad10[0x4];
    f32 unk14[3];
    f32 unk20[3];
    f32 unk2C[3];
};

struct UnkStruct800111D4 {
    u8 pad0[0x24];
    u32 unk24;
    struct UnkStruct800111D4_Inner *unk28;
};

struct UnkInputStruct8000E680 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    char padC[0x4];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    char pad1C[0x4];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    char pad2C[0x4];
};

struct UnkInnerStruct8000E944 {
    union {
        s32 unk0;
        f32 unk0_f;
    } u;
    f32 unk4;
    f32 unk8;
    char padC[0x1C];
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
    char pad4[0x8];
    u32 *unkC;
    s32 unk10;
    char pad14[0x14];
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
    char pad2A[0x2];
};

struct UnkStruct80052EB4 {
    u8 unk0;
    u8 unk1;
    char pad2[0x2];
    u32 len;
    u32 unk8;
    u32 unkC;
};

struct UnkStruct80052ED8 {
    struct UnkStruct80052ED8* unk0;
    char pad4[0x10];
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
    char pad4[0x1]; // unk size
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
    char pad2[0x6];
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
    char pad4[0x5];
    u8 unk9;
    char pada[0x2];
    u32 unkC;
    u32 unk10;
};

struct UnkInputStruct80007140 {
    char pad0[0x13];
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
    char padA[0x2];
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


struct UnkStruct_80026548_SP24 {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
};

struct UnkStruct_80026548 {
    s8 unk0;
    char unk1;
    char unk2;
    char unk3;
    s8 unk4;
    char unk5;
    char unk6;
    char unk7;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u8 unkE;
    s8 unkF;
    char pad10[4];
    void* (*routine)();
    void* (*routine2)();
    void* (*routine_1C)();
    char pad1C[0x4];
    struct UnkStruct_80026548_SP24 *unk24;
    char pad28[0x4];
    void* (*routine3)();
    u64 unk30;
    struct UnkStruct_80027C00* unk38;
    s32 pad3C;
    void* unk40;
    void* unk44;
    u8 unk48[1];
    char pad38[0x17];
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

struct CutsceneString {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 len;
    /* 0x0A */ s16 str[1]; // dynamic length
};

struct DemoString {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 len;
    u8 paddingA[0x2];
    /* 0x0C */ s16 str[1]; // dynamic length
};

struct StringInfo {
    struct DemoString *strInfo;
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
    u8 padding[3];
} UnkStruct_800600B8;

struct UnkStruct_56400 {
    s16* ptr;
    s16 Unk04;
    s16 Unk06;
};

struct UnkStruct80177778 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    u8 pad1E[0x4];
    s16 unk22;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2A;
    u8 unk2B;
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
    u8 unk2F;
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    s16 unk34;
    s16 unk36;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
};

struct UnkBigStruct_8006B64C
{
    u16 Unk0;
    u16 Unk1;
    u8 padding[336 - sizeof(u32)];
};

struct UnkStruct80176458 {
    Vtx vertices[4];
    f32 unk40[4];
    u32 unk50;
    u8 padding54[0x4]; // Or, really, unidentified members
}; // size 0x58;

// Not entierly sure about this struct, needs more investigation
struct UnkInputStruct800643C0_arg9 {
    s16 unk00s16;
    s16 unk02[3];
    s16 unk08;
}; // size = 0xA;

struct UnkStruct80177964 {
    s8 unk0;
    u8 padding1[0x2B];
    f32 unk2C;
    f32 unk30;
}; // size=0x34

struct UnkStruct80104C20 {
    u8 *romAddr;
    int size;
};

struct UnkStruct800654AC_SP0 {
    char pad0[0x8];
    s8 unk8;
    char pad9[0x3];
    s8 unkC;
};

struct UnkStruct800657E8_sp40 {
    char pad0[0x4];
    s8 unk4;
    s8 pad5[0x2];
    s8 unk7[2]; // unk size, could be rest of struct
    s8 pad9[0x3];
    s8 unkC;
    s8 padD[0x3];
};

struct Code_Extra_Entry
{
    const s32* const Start_Addr;
    const s32* const End_Addr;
};

struct UnkStruct80108238 {
    s16 *unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u8 pad14[0xC];
    u32 unk20;
};

struct UnkStruct8017791C {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};

struct UnkStruct_80057450 {
    char unk0;
    char pad[0x77];
};

struct UnkStruct8017794C {
    char pad0[0xB];
    u8 unkB[1];
    char padC[0x4];
};

struct UnkStruct80122B08_Unk0 {
    char pad0[0x4];
    u32 unk4;
    u32 unk8;
    char padC[0x8];
    s16 unk14;
};

struct UnkStruct80122B08 {
    struct UnkStruct80122B08_Unk0 *unk0;
    u32 romStart;
    u32 romEnd;
    void* unkC[1];
};

struct UnkStruct80011424_SP38 {
    char pad0[0x4];
    u32 unk4;
    s32 unk8;
    s32 unkC;
    s32 *unk10;
    s32 *unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

struct UnkInputStruct80011424 {
    struct UnkInputStruct80010098 *unk0;
    f32 unk4;
    char pad8[0x4];
    s32 unkC;
    struct UnkStruct80011424_SP38 *unk10;
};

struct UnkStruct800117F8_SP1C {
    u32 unk0;
    char pad4[0x4];
    u32 *unk8;
    u32 unkC;
    char pad10[0x50];
};

struct UnkStruct800117F8_Arg0 {
    char pad0[0xC];
    u32 *unkC;
    u32 unk10;
};

struct FileEntry {
    u32 romStart;  
    u32 romEnd;
};

struct UnkStruct80055D5C {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ s32 unkC;                            /* inferred */
};       

struct UnkStruct8001191C_SP34 {
    u32 unk0;
    u32 unk4;
    s32 unk8;
    char padC[0x14];
};

struct UnkStruct8001191C_SP2C {
    u32 unk0;
    u32 unk4;
    u32 *unk8;
};

struct UnkStruct8001191C_SP28 {
    u32 unk0;
    u32 unk4;
    u32 *unk8;
    u32 *unkC;
};

struct UnkStruct8001191C_SP38 {
    u32 unk0;
};

struct UnkStruct80011D18 {
    char pad0[0x8];
    u32 *unk8;
    s32 unkC;
};

struct UnkStruct80011DD0_SP28 {
    char pad0[0x4];
    u32 unk4;
    char pad8[0x8];
    u32 unk10;
    u32 unk14;
    char pad18[0x4];
    u32 unk1C;
    char pad20[0x8];
};

struct UnkStruct80011DD0 {
    char pad0[0xC];
    s32 unkC;
    struct UnkStruct80011DD0_SP28 *unk10;
};

struct UnkStruct80011EF0 {
    char pad0[0x64];
    u32 unk64;
    u32 unk68;
};

struct UnkStruct800120FC {
    char pad0[0x64];
    void* unk64;
    int unk68;
    void* unk6C;
    s32 unk70;
};

struct UnkStruct_80022454_SP24 {
    /* 0x0 */ s16 unk0;
};

struct UnkStruct_80112518
{
    char Pad[0x1C];
};

struct UnkStruct_D_004A280 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

#endif // _BMHERO_TYPES_H_
