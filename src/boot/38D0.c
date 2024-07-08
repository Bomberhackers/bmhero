#include <ultra64.h>
#include "38D0.h"

// forward prototypes
ALMicroTime initOsc(void **oscState, f32 *initVal,u8 oscType, u8 oscRate,u8 oscDepth,u8 oscDelay);
ALMicroTime updateOsc(void *oscState, f32 *updateVal);
void stopOsc(void *oscState);

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

// in other files
extern s32 func_8000D120(struct UnkStruct8004A2A4*, s32*);
extern ALCSPlayer* func_8000D84C(u32);
extern ALHeap D_80052D40;

// .data
s32 D_8004A2A0 = 0x00007D00;

// some unidentified struct between now and 8004A2C0. size 0x1C

struct UnkStruct8004A2A4 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    void* unk14;
    u32 unk18;
};

struct UnkStruct8004A2A4 D_8004A2A4 = {
    0x00000010,
    0x00000010,
    0x00000200,
    0x00000000,
    0x00000000,
    (void*)&D_80052D40,
    0x00000000
};

u8 D_8004A2C0 = 0x01;
s32* D_8004A2C4 = 0x00000000;
u16 D_8004A2C8 = 0x0020;
s32 D_8004A2CC = 0x00000800;
s32 D_8004A2D0 = 0x00000001;
s32 D_8004A2D4 = 0x00001000;
s32 D_8004A2D8 = 0x00000000;
s32 D_8004A2DC = 0x00000000;
s32 D_8004A2E0 = 0x00000000;
s32 D_8004A2E4 = 0x00000000;

ALSeqpConfig D_8004A2E8 = {
    0x0000000E,
    0x00000100,
    0x10,
    0x00,
    &D_80052D40,
    &initOsc,
    &updateOsc,
    &stopOsc,
};

s32 D_8004A304 = 0x00000004;
s32 D_8004A308 = 0x00000004;
s32 D_8004A30C = 0x00000008;

// this is probably a struct since a pointer is after D_8004A310 and isnt
// called, but i am not sure how it gets referenced yet. TODO: Fix
struct UnkStruct8004A310 {
    s32 unk0;
    void *unk4;
};

struct UnkStruct8004A310 D_8004A310 = {
    0x00000100,
    (void*)&D_80052D40,
};

// borrowed from drvrnew.c, as this is not in a header.
/*
 * the following arrays contain default parameters for
 * a few hopefully useful effects.
 */
#define ms *(((s32)((f32)44.1))&~0x7)

// custom parameters
s32 D_8004A318[10] = {
    /* sections	   length */
          1,       320 ms,
                                      /*       chorus  chorus   filter
       input  output  fbcoef  ffcoef   gain     rate   depth     coef   */
           0,  200 ms, 12000,      0, 0x7fff,      0,      0,   0x3E80
};

u8* D_8004A340 = 0x00000000;
s32 D_8004A344 = 0x00000000;
s32 D_8004A348 = 0x00000000;
s32 D_8004A34C = 0x00000000;
u32 D_8004A350 = 0x00000000;
u32 D_8004A354 = 0x00000000;
s32 D_8004A358 = 0x00000000;
s32 D_8004A35C = 0x00000000;
u8* D_8004A360 = 0x00000000;
s16 D_8004A364 = 0x0008;
u8 D_8004A368 = 0x01;

// .bss
ALHeap D_80052D40;
void* D_80052D50; // generic working pointer to an AL element.
ALSndPlayer* D_80052D54;
ALBankFile* D_80052D58;
struct UnkStruct80052D5C *D_80052D5C;
struct UnkStruct80052D60 *D_80052D60;
s32 D_80052D64;
s32 D_80052D68;
f32 D_80052D6C;
f32 D_80052D70;
s16 D_80052D74;
s16 D_80052D76;
s16 D_80052D78;
s8 D_80052D7A;
u8 D_80052D7B;
u8 D_80052D7C;
s8 D_80052D7D;

struct UnkStruct80052D80 {
    u32 unk0;
    u32 unk4;
};

struct UnkStruct80052D80* D_80052D80;

struct UnkStruct80052D84 *D_80052D84;

struct UnkStruct80052D88 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s8 unkE;
};

struct UnkStruct80052D88 *D_80052D88;

f32 D_80052D8C;
f32 D_80052D90;
f32 D_80052D94;
f32 D_80052D98;
s16 D_80052D9C;
s16 D_80052D9E;
f32 D_80052DA0;
f32 D_80052DA4;

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

struct UnkStruct80052DA8 *D_80052DA8;
f32 D_80052DAC;
f32 D_80052DB0;
s8 D_80052DB4;
s8 D_80052DB5;
s8 D_80052DB6;
u8 D_80052DB7;
void* D_80052DB8;
u8 unused_80052DC0[0xC0];
OSMesgQueue D_80052E80;
u8* D_80052E98;
s32 D_80052E9C;
ALBankFile* D_80052EA0;
ALSeqPlayer* D_80052EA4;
ALCSPlayer* D_80052EA8;
ALCSeq* D_80052EAC;
ALSeqFile* D_80052EB0;
struct UnkStruct80052EB4* D_80052EB4;
s32 D_80052EB8;
s32 D_80052EBC;
s32 D_80052EC0;
f32 D_80052EC4;
f32 D_80052EC8;
s16 D_80052ECC;
s16 D_80052ECE;
s16 D_80052ED0;
s16 D_80052ED2;
oscData  *freeOscStateList;
struct UnkStruct80052ED8 D_80052ED8[32];

// functions
s32 func_80003304(void);
s32 func_800038A4(s32);
void func_80004284(void);
f32 _depth2Cents(u8 depth);
s32 func_80005B14();
s32 func_800060AC(s32 arg0);
s32 func_8000616C();
s32 func_80006284(ALSynConfig*);
s32 func_800064BC(ALSynConfig*);
s32 func_800065B8(ALSynConfig*);
ALBank** func_800069D0(s16 arg0, struct UnkInputStruct800069D0* arg1);
s16 func_80006DF4(s16 **arg0);
s32 func_80006EE8(s16** arg0, u8 arg1, u8 arg2, u8 arg3);
s32 func_80006FD4(s16** arg0, s16 arg1);
void func_80007690(s16*, s16*, s32, s32);
void func_80007890(s16 arg0);
s32 func_800080D8(void);
s32 func_800081B0(void);
void func_80008360();
void func_800083EC(s16 arg0, s8 arg1);
void func_80008744();
void func_80008B84(s16 arg0, s16 arg1, s8 arg2);
void func_80008CF4(s16 arg0);
s16 func_80009AD0(s16 arg0);
void func_80009B4C(s16 arg0);
void func_80009BA4(struct UnkStruct80052D5C* arg0, struct UnkStruct80052D84* arg1);
void func_8000A534(struct UnkStruct80052D5C* arg0, struct UnkStruct80052D84* arg1);
void func_8000A724(struct UnkStruct80052D5C* arg0, struct UnkStruct80052D84* arg1);
s16 func_8000AC1C(s16 arg0);
void func_8000AF40(s16 arg0);
void func_8000B5DC();
void func_8000BD20(s16 arg0, s16 arg1, f32 arg2);
void func_8000C2D0(s16 arg0, s8 arg1);
void func_8000C48C(s16 arg0, f32 arg1);
void func_8000C6F8(s16 arg0, s8 arg1);
void func_8000C7D4(s16 arg0, u8 arg1);
void func_8000C8CC(s16 arg0, s16 arg1);
void func_8000C9C4(s16 arg0, s8 arg1);

void func_80002CD0(u32 devAddr, void* vaddr, s32 nbytes) {
    OSIoMesg mesg;

    osWritebackDCache(vaddr, nbytes);
    osInvalICache(vaddr, nbytes);
    osInvalDCache(vaddr, nbytes);
    osPiStartDma(&mesg, 0, 0, devAddr, vaddr, nbytes, &D_80052E80);
    osRecvMesg(&D_80052E80, NULL, 1);
    osInvalICache(vaddr, nbytes);
    osInvalDCache(vaddr, nbytes);
}

s16 func_80002D90(s8 arg0) {
    return (arg0 > 0) ? (arg0 << 8) + 0xFF : 0;
}

void func_80002DD4(s16* arg0, s16 arg1) {
    if (*arg0 < 0) {
        *arg0 = 0;
    } else if (arg1 < *arg0) {
        *arg0 = arg1;
    }
}

s32 func_80002E1C(s32 arg0, s32 arg1, s32 arg2, u8* arg3, s32 arg4) {
    s32 sp1C;

    osCreateMesgQueue(&D_80052E80, &D_80052DB8, 0x32);
    D_80052E98 = arg3;
    D_80052E9C = arg4;
    alHeapInit(&D_80052D40, D_80052E98, D_80052E9C);
    D_8004A2DC = arg2;
    D_8004A2C0 = 6;
    D_8004A2C4 = &D_8004A318;
    D_8004A2E0 = arg0;
    D_8004A2E4 = arg1;
    D_8004A2D8 = D_8004A2A0;
    sp1C = func_8000D120(&D_8004A2A4, &D_8004A2C8);
    if (sp1C != 0) {
        return sp1C;
    }
    sp1C = func_80003304();
    if (sp1C != 0) {
        return sp1C;
    }
    sp1C = func_80005B14();
    if (sp1C != 0) {
        return sp1C;
    }
    D_80052DB7 = 0;
    return 0;
}

s32 func_80002F7C(void) {
    return 0;
}

// this function isnt called, so dont know what this struct is supposed to be.
void func_80002F94(struct UnkInputStruct80002F94* arg0) {
    D_8004A2A4.unk0 = arg0->unk0;
    D_8004A2A4.unk4 = arg0->unk4;
    D_8004A2A4.unk8 = arg0->unk8;
    D_8004A2C0 = arg0->unk10;
    D_8004A2C4 = arg0->unk14;
    D_8004A2E8.maxVoices = arg0->unk18;
    D_8004A2E8.maxEvents = arg0->unk1C;
    D_8004A304 = arg0->unk20;
    D_8004A308 = arg0->unk24;
    D_8004A310.unk0 = arg0->unk28;
    D_8004A2C8 = arg0->unk2C;
    D_8004A2CC = arg0->unk30;
    D_8004A2D0 = arg0->unk34;
    D_8004A2D4 = arg0->unk38;
    D_8004A2A0 = arg0->unkC;
}

void func_80003058(struct UnkInputStruct80002F94* arg0) {
    arg0->unk0 = D_8004A2A4.unk0;
    arg0->unk4 = D_8004A2A4.unk4;
    arg0->unk8 = D_8004A2A4.unk8;
    arg0->unk10 = D_8004A2C0;
    arg0->unk14 = D_8004A2C4;
    arg0->unk18 = D_8004A2E8.maxVoices;
    arg0->unk1C = D_8004A2E8.maxEvents;
    arg0->unk20 = D_8004A304;
    arg0->unk24 = D_8004A308;
    arg0->unk28 = D_8004A310.unk0;
    arg0->unk2C = D_8004A2C8;
    arg0->unk30 = D_8004A2CC;
    arg0->unk34 = D_8004A2D0;
    arg0->unk38 = D_8004A2D4;
    arg0->unkC = D_8004A2A0;
}

s32 func_80003158(void) {
    return 24;
}

s32 func_80003170(void) {
    s32 sp4 = (D_80052D40.len - (D_80052D40.cur - D_80052D40.base));

    return sp4;
}

s32 func_800031B4(void) {
    return 0;
}

s32 func_800031CC(void) {
    return 0;
}

s32 func_800031E4(void) {
    return 0;
}

s32 func_800031FC(void) {
    return 0;
}

void func_80003214(u8 arg0) {
    struct UnkStruct80052D5C* sp4;
    s32 i;

    arg0 &= 1;

    D_80052DB7 = 0;
    D_80052DB7 |= arg0;

    for(i = 0; i < D_8004A30C; i++) {
        sp4 = &D_80052D5C[i];
        if (sp4->unkC != 1) {

        } else {
            sp4->unk8 |= 4;
        }
    }
}

s32 func_800032E8(s32 arg0) {
    return 0;
}

s32 func_80003304(void) {
    struct UnkStruct80052ED8* sp3C;
    u32 sp38;
    s32 sp34;
    u32 sp30;
    u32 sp2C;                                       /* compiler-managed */
    s16 sp2A;

    D_80052EA4 = func_8000D84C(0x7CU);
    if (D_80052EA4 == 0) {
        return 1;
    }
    alCSPNew(D_80052EA4, &D_8004A2E8);
    D_80052EC0 = 0;
    D_80052EBC = 0;
    D_80052EC4 = 0.0f;
    D_80052ED2 = 0x7FFF;
    D_80052EB8 = 0;
    if (D_8004A340 == NULL) {
        return 0;
    }
    if (func_800038A4(4) != 0) {
        return 1;
    }
    sp2A = D_80052EB0->seqCount;
    switch (D_80052EB0->revision) {                              /* irregular */
    case 0x5331:
        sp34 = (sp2A * 8) + 4;
        if (func_800038A4(sp34) != 0) {
            return 1;
        }
        alSeqFileNew(D_80052EB0, (u8*)D_8004A340);
        sp2C = 0;
        for(sp38 = 0; sp38 < sp2A; sp38++) {
            if (sp2C < D_80052EB0->seqArray[sp38].len) {
                sp2C = D_80052EB0->seqArray[sp38].len;
            }
        }
        sp30 = D_8004A34C - D_8004A348;
        break;
    case 0x5332:
        sp34 = (sp2A * 0x18) + 4;
        if (func_800038A4(sp34) != 0) {
            return 1;
        }
        D_80052EB4 = (void*)&D_80052EB0->seqArray[sp2A];
        sp2C = 0;
        sp30 = 0;

        for(sp38 = 0; sp38 < sp2A; sp38++) {
            if (D_80052EB0->seqArray[sp38].len < 0) {

            } else {
                D_80052EB0->seqArray[sp38].offset = &D_80052EB0->seqArray[sp38].offset[(u32)D_8004A340];
                D_80052EB4[sp38].len = &D_8004A340[D_80052EB4[sp38].len];
                D_80052EB4[sp38].unkC = &D_8004A340[D_80052EB4[sp38].unkC];
                if (sp30 < D_80052EB4[sp38].unk8) {
                    sp30 = D_80052EB4[sp38].unk8;
                }
                if (sp2C < D_80052EB0->seqArray[sp38].len) {
                    sp2C = D_80052EB0->seqArray[sp38].len;
                }
            }
        }
        break;
    default:
        sp2C = (s32)D_8004A344 - (s32)D_8004A340;
        sp30 = D_8004A34C - D_8004A348;
        D_80052EB0->seqCount = 1;
    }

    if ((sp30 == 0) || (sp2C == 0)) {
        D_8004A340 = NULL;
        return 0;
    }
    D_80052EAC = func_8000D84C(0xF8U);
    if (D_80052EAC == NULL) {
        return 1;
    }
    if (sp2C & 1) {
        sp2C += 1;
    }
    D_80052EA8 = func_8000D84C(sp2C);
    if (D_80052EA8 == NULL) {
        return 1;
    }
    if (sp30 & 1) {
        sp30 += 1;
    }
    D_80052EA0 = func_8000D84C(sp30);
    if (D_80052EA0 == NULL) {
        return 1;
    }
    freeOscStateList = &D_80052ED8;
    sp3C = &D_80052ED8;

    for(sp38 = 0; sp38 < 0x1F; sp38++) {
        sp3C->unk0 = &D_80052ED8[sp38 + 1];
        sp3C = sp3C->unk0;
    }
    sp3C->unk0 = 0;
    return 0;
}

s32 func_800038A4(s32 arg0) {
    if (arg0 & 1) {
        arg0 += 1;
    }
    D_80052EB0 = func_8000D84C(arg0);
    if (D_80052EB0 == 0) {
        return 1;
    }
    func_80002CD0(D_8004A340, D_80052EB0, arg0);
    return 0;
}

void func_80003940(void) {
    s32 sp3C;                                       /* compiler-managed */
    ALSeqData* sp38;
    struct UnkStruct80052EB4* sp34;
    s32 sp30;
    u32 sp2C;
    u8 sp2B;

    switch(D_80052EB0->revision) {
        case 0x5331:
        case 0x5332:
            sp38 = &D_80052EB0->seqArray[D_80052ECC];
            sp3C = sp38->len;
            if (sp3C & 1) {
                sp3C += 1;
            }
            func_80002CD0(sp38->offset, D_80052EA8, sp3C);
            break;
        default:
            sp3C = (s32)D_8004A344 - (s32)D_8004A340;
            if (sp3C & 1) {
                sp3C += 1;
            }
            func_80002CD0(D_8004A340, D_80052EA8, sp3C);
    }
    alCSeqNew(D_80052EAC, (u8* ) D_80052EA8);
    switch(D_80052EB0->revision) {
        case 0x5332:
            sp34 = &D_80052EB4[D_80052ECC];
            sp30 = sp34->len;
            sp2C = sp34->unkC;
            sp3C = sp34->unk8;
            sp2B = sp34->unk0;
            break;
        default:
            sp30 = D_8004A348;
            sp2C = D_8004A350;
            sp2B = 0;
            sp3C = D_8004A34C - D_8004A348;
            if (sp3C & 1) {
                sp3C += 1;
            }
    }
    if (sp30 != D_80052EB8) {
        func_80002CD0((u8* ) sp30, D_80052EA0, sp3C);
        alBnkfNew(D_80052EA0, (u8* ) sp2C);
        D_80052EB8 = sp30;
    }
    alSeqpSetBank((ALSeqPlayer* ) D_80052EA4, D_80052EA0->bankArray[sp2B]);
    alSeqpSetSeq((ALSeqPlayer* ) D_80052EA4, (ALSeq* ) D_80052EAC);
    alSeqpSetVol((ALSeqPlayer* ) D_80052EA4, (s16) ((s32) (D_80052ED2 * D_80052ED0) / 32767));
    if (D_80052EC0 & 2) {
        return;
    }
    alSeqpPlay((ALSeqPlayer* ) D_80052EA4);
    D_80052EC0 = 0;
    D_80052EBC = 1;
}

void func_80003C94(void) {
    s16 sp26;

    D_80052EBC = alSeqpGetState(D_80052EA4);
    if (D_80052EC0 & 1) {
        switch (D_80052EBC) {                       /* irregular */
        case 0:
            func_80003940();
            break;
        case 2:
            D_80052EBC = 1;
        }
    }
    if (D_80052EBC == 0) {
        return;
    }
    if (D_80052EC4 > 0.0f) {
        D_80052EC8 += D_80052EC4;
        if (D_80052EC8 >= D_80052ED2) {
            func_80004284();
            D_80052EC4 = 0.0f;
        } else if (D_80052EC8 != 0.0f) {
            sp26 = (s16) (s32) ((f32) D_80052ED2 - D_80052EC8);
            if (D_80052ECE != sp26) {
                alSeqpSetVol(D_80052EA4, (s16) ((s32) (sp26 * D_80052ED0) / 32767));
                D_80052ECE = sp26;
            }
        }
    }
    if (D_80052EC4 < 0.0f) {
        D_80052EC8 -= D_80052EC4;
        if (D_80052EC8 >= D_80052ED2) {
            sp26 = D_80052ED2;
            D_80052EC4 = 0.0f;
        } else {
            sp26 = (s16) (s32) D_80052EC8;
        }
        if (D_80052ECE != sp26) {
            alSeqpSetVol(D_80052EA4, (s16) ((s32) (sp26 * D_80052ED0) / 32767));
            D_80052ECE = sp26;
        }
    }
}

void func_80003FA0(void) {
    alSeqpStop(D_80052EA4);
    alSeqpDelete(D_80052EA4);
}

void func_80003FE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_8004A340 = arg0;
    D_8004A344 = arg1;
    D_8004A348 = arg2;
    D_8004A34C = arg3;
    D_8004A350 = arg4;
}

s32 func_8000401C(s16 arg0) {
    s8 sp27;

    if (D_8004A340 == NULL) {
        return -1;
    }
    if ((arg0 >= D_80052EB0->seqCount) || (arg0 < 0)) {
        return -1;
    }
    switch (D_80052EB0->revision) {                              /* irregular */
    case 0x5332:
        if (D_80052EB0->seqArray[arg0].len < 0) {
            return -1;
        }
        sp27 = D_80052EB4[arg0].unk1;
        break;
    case 0x5331:
        if (D_80052EB0->seqArray[arg0].len < 0) {
            return -1;
        }
    default:
        sp27 = 0x7F;
    }
    D_80052ED0 = func_80002D90(sp27);
    if ((alSeqpGetState(D_80052EA4) == 1) && !(D_80052EC0 & 1)) {
        alSeqpStop(D_80052EA4);
    } else {
        D_80052EBC = 1;
    }
    D_80052EC4 = 0.0f;
    D_80052ECC = arg0;
    D_80052EC0 = 1;
    return 0;
}

s32 func_800041E0(void) {
    if (D_80052EC0 & 2) {
        return 0x100;
    }
    if (D_80052EC0 & 1) {
        return 0x200;
    }
    return D_80052EBC;
}

s16 func_80004240(void) {
    if (D_8004A340 == 0) {
        return 0;
    }
    return D_80052EB0->seqCount;
}

void func_80004284(void) {
    if (alSeqpGetState(D_80052EA4) == 1) {
        alSeqpStop(D_80052EA4);
    }
    D_80052EC0 = 0;
}

void func_800042D8(s16 arg0) {
    if (D_80052EBC != 1) {
        return;
    }
    if (arg0 < 0) {
        arg0 = 1;
    }
    D_80052EC8 = 0.0f;
    D_80052ECE = D_80052ED2;
    D_80052EC4 = (f32) D_80052ED2 / (f32) arg0;
}

void func_8000435C(s8 arg0) {
    D_80052ED0 = func_80002D90(arg0);
    alSeqpSetVol(D_80052EA4, (s16) ((s32) (D_80052ED2 * D_80052ED0) / 32767));
}

void func_800043D4(s8 arg0) {
    D_80052EC4 = 0.0f;
    D_80052ED2 = func_80002D90(arg0);
    alSeqpSetVol(D_80052EA4, (s16) ((s32) (D_80052ED2 * D_80052ED0) / 32767));
}

s8 func_80004458(void) {
    return (s8) ((s16) D_80052ED0 / 256);
}

void func_8000449C(s16 arg0) {
    s32 sp1C;

    if (arg0 <= 0) {
        arg0 = 1;
    }
    sp1C = (s32) ((60.0f / (f32) arg0) * 1000.0f * 1000.0f);
    alSeqpSetTempo(D_80052EA4, sp1C);
}

s16 func_80004548(void) {
    s32 sp1C;
    s16 sp1A;

    if (D_8004A340 == 0) {
        return 0;
    }
    sp1C = alCSPGetTempo(D_80052EA4);
    if (sp1C == 0) {
        return 0;
    }
    sp1A = (s16) (s32) (60.0f / ((f32) sp1C / 1000000.0f));
    return sp1A;
}

void func_80004610(void) {
    if (D_80052EC0 & 2) {
        return;
    }
    if (D_80052EBC != 1) {
        return;
    }
    if ((alSeqpGetState(D_80052EA4) == 1) && !(D_80052EC0 & 1)) {
        alSeqpStop(D_80052EA4);
    }
    D_80052EC0 |= 2;
}

void func_800046C4(s16 arg0) {
    if (!(D_80052EC0 & 2)) {
        return;
    }
    alSeqpPlay(D_80052EA4);
    D_80052EBC = 1;
    D_80052EC0 &= ~2;
    if ((arg0 == 0) || (D_80052EC4 > 0.0f)) {
        return;
    }
    D_80052EC8 = 0.0f;
    D_80052ECE = 0;
    alSeqpSetVol(D_80052EA4, 0);
    D_80052EC4 = -((f32) D_80052ED2 / (f32) arg0);
}

void func_800047C8(u8 arg0, struct UnkInputStruct800047C8* arg1) {
    if (D_80052EBC != 1) {
        return;
    }
    arg1->unk0 = alSeqpGetChlProgram(D_80052EA4, arg0);
    arg1->unk4 = alSeqpGetChlVol(D_80052EA4, arg0);
    arg1->unk5 = alSeqpGetChlPan(D_80052EA4, arg0);
    arg1->unk6 = alSeqpGetChlFXMix(D_80052EA4, arg0);
}

ALMicroTime initOsc(void **oscState, f32 *initVal,u8 oscType, u8 oscRate,u8 oscDepth,u8 oscDelay)
{
    oscData         *statePtr;
    ALMicroTime     deltaTime = 0;
    s32 cents;
    

    if(freeOscStateList)  /* yes there are oscStates available */
    {
        statePtr = freeOscStateList;
        freeOscStateList = freeOscStateList->next;
        statePtr->type = oscType;
        *oscState = statePtr;

        /*
         * Convert delay into usec's, In this example, multiply by
         * 0x4000, but could easily use another conversion method.
         */
        deltaTime = oscDelay * 0x4000;

        switch(oscType) /* set the initVal */
        {
            case TREMELO_SIN:
                statePtr->curCount = 0;
                statePtr->maxCount = 259-oscRate; /* gives values 4-259 */
                statePtr->data.tsin.halfdepth = oscDepth >> 1;
                statePtr->data.tsin.baseVol = AL_VOL_FULL - statePtr->data.tsin.halfdepth;
                *initVal = (f32)statePtr->data.tsin.baseVol;
                break;

            case TREMELO_SQR:
                statePtr->maxCount = 256-oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                statePtr->stateFlags = OSC_HIGH;
                statePtr->data.tsqr.loVal = AL_VOL_FULL-oscDepth;
                statePtr->data.tsqr.hiVal = AL_VOL_FULL;
                statePtr->data.tsqr.curVal = AL_VOL_FULL;
                *initVal = (f32)AL_VOL_FULL;
                break;

            case TREMELO_DSC_SAW:
                statePtr->maxCount = 256-oscRate;
                statePtr->curCount = 0;
                statePtr->data.tsaw.depth = oscDepth;
                statePtr->data.tsaw.baseVol = AL_VOL_FULL;
                *initVal = (f32)statePtr->data.tsaw.baseVol;
                break;

            case TREMELO_ASC_SAW: 
                statePtr->maxCount = 256-oscRate;
                statePtr->curCount = 0;
                statePtr->data.tsaw.depth = oscDepth;
                statePtr->data.tsaw.baseVol = AL_VOL_FULL - oscDepth;
                *initVal = (f32)statePtr->data.tsaw.baseVol;
                break;           

            case VIBRATO_SIN:
                statePtr->data.vsin.depthcents = _depth2Cents(oscDepth);
                statePtr->curCount = 0;
                statePtr->maxCount = 259-oscRate; /* gives values 4-259 */
                *initVal = 1.0f; /* start at unity pitch */
                break;

            case VIBRATO_SQR:
                {
                    statePtr->maxCount = 256-oscRate; /* values from 1-256 */
                    statePtr->curCount = statePtr->maxCount;
                    statePtr->stateFlags = OSC_HIGH;
                    cents = _depth2Cents(oscDepth);
                    statePtr->data.vsqr.loRatio = alCents2Ratio(-cents);
                    statePtr->data.vsqr.hiRatio = alCents2Ratio(cents);
                    *initVal = statePtr->data.vsqr.hiRatio;
                }
                break;
                    
            case VIBRATO_DSC_SAW:
                {
                    statePtr->maxCount = 256-oscRate; /* values from 1-256 */
                    statePtr->curCount = statePtr->maxCount;
                    cents = _depth2Cents(oscDepth);
                    statePtr->data.vdsaw.hicents = cents;
                    statePtr->data.vdsaw.centsrange = 2 * cents;
                    *initVal = alCents2Ratio(statePtr->data.vdsaw.hicents);
                }
                break;
                
            case VIBRATO_ASC_SAW:
                {
                    statePtr->maxCount = 256-oscRate; /* values from 1-256 */
                    statePtr->curCount = statePtr->maxCount;
                    cents = _depth2Cents(oscDepth);
                    statePtr->data.vasaw.locents = -cents;
                    statePtr->data.vasaw.centsrange = 2 * cents;
                    *initVal = alCents2Ratio(statePtr->data.vasaw.locents);
                }
                break;
            case 201: // extra case?
                {
                    cents = _depth2Cents(oscDepth);
                    statePtr->data.unk.unkC = cents;
                    statePtr->curCount = 0;
                    statePtr->maxCount = 259-oscRate;
                    statePtr->stateFlags = oscDelay;
                    *initVal = alCents2Ratio(-cents);
                    deltaTime = 0x4000;
                }
                break;
            default:
                deltaTime = 0x3FC000;
        }
    }
    return(deltaTime);  /* if there are no oscStates, return zero, but if
                           oscState was available, return delay in usecs */
}

ALMicroTime updateOsc(void *oscState, f32 *updateVal)
{
    f32             tmpFlt;
    oscData         *statePtr = (oscData*)oscState;
    ALMicroTime     deltaTime = AL_USEC_PER_FRAME; /* in this example callback every */
                                              /* frame, but could be at any interval */

    switch(statePtr->type)   /* perform update calculations */
    {
        case TREMELO_SIN:
            statePtr->curCount++;
            if(statePtr->curCount >= statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt = sinf(tmpFlt*TWO_PI);
            tmpFlt = tmpFlt * (f32)statePtr->data.tsin.halfdepth;
            *updateVal = (f32)statePtr->data.tsin.baseVol + tmpFlt;
            break;

        case TREMELO_SQR:
            if(statePtr->stateFlags == OSC_HIGH)
            {
                *updateVal = (f32)statePtr->data.tsqr.loVal;
                statePtr->stateFlags = OSC_LOW;
            }
            else
            {
                *updateVal = (f32)statePtr->data.tsqr.hiVal;
                statePtr->stateFlags = OSC_HIGH;
            }
            deltaTime *= statePtr->maxCount;
            break;
            
        case TREMELO_DSC_SAW:
            statePtr->curCount++;
            if(statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.tsaw.depth;
            *updateVal = (f32)statePtr->data.tsaw.baseVol - tmpFlt;
            break;
            
        case TREMELO_ASC_SAW: 
            statePtr->curCount++;
            if(statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.tsaw.depth;
            *updateVal = (f32)statePtr->data.tsaw.baseVol + tmpFlt;
            break;

        case VIBRATO_SIN:
            /* calculate a sin value (from -1 to 1) and multiply it by depthcents.
               Then convert cents to ratio. */

            statePtr->curCount++;
            if(statePtr->curCount >= statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt = sinf(tmpFlt*TWO_PI) * statePtr->data.vsin.depthcents;
            *updateVal = alCents2Ratio((s32)tmpFlt);
            break;
            
        case VIBRATO_SQR:
            if(statePtr->stateFlags == OSC_HIGH)
            {
                statePtr->stateFlags = OSC_LOW;
                *updateVal = statePtr->data.vsqr.loRatio;
            }
            else
            {
                statePtr->stateFlags = OSC_HIGH;
                *updateVal = statePtr->data.vsqr.hiRatio;
            }
            deltaTime *= statePtr->maxCount;
            break;

        case VIBRATO_DSC_SAW:
            statePtr->curCount++;
            if(statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.vdsaw.centsrange;
            tmpFlt = (f32)statePtr->data.vdsaw.hicents - tmpFlt;
            *updateVal = alCents2Ratio((s32)tmpFlt);
            break;
            
        case VIBRATO_ASC_SAW:
            statePtr->curCount++;
            if(statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.vasaw.centsrange;
            tmpFlt += (f32)statePtr->data.vasaw.locents;
            *updateVal = alCents2Ratio((s32)tmpFlt);
            break;
        case 0xC9:
            statePtr->curCount++;
            if(statePtr->curCount >= statePtr->maxCount)
                statePtr->curCount = 0;
            if(statePtr->stateFlags != OSC_HIGH) {
                if (statePtr->curCount == 0) {
                    statePtr->data.unk.unkC = _depth2Cents(0x61);
                    statePtr->maxCount = 0xEU;
                    *updateVal = 1.0f;
                    deltaTime = statePtr->stateFlags << 0xE;
                    statePtr->stateFlags = 0;
                    break;
                }
                tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
                tmpFlt = statePtr->data.unk.unkC - (tmpFlt * statePtr->data.unk.unkC);
                *updateVal = alCents2Ratio((-1.0f * tmpFlt));
            } else {
                tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
                tmpFlt = sinf(((f64)tmpFlt * TWO_PI)) * statePtr->data.unk.unkC;
                *updateVal = alCents2Ratio(tmpFlt);
            }
            break;
    }
    return(deltaTime);
}

void stopOsc(void *oscState)
{
    ((oscData*)oscState)->next = freeOscStateList;
    freeOscStateList = (oscData*)oscState;
}

/************************************************************************
 *   _depth2Cents()  convert a u8 (0-255) to a cents value. Convert using
 *   1.03099303^(depth). This gives an exponential range of values from
 *   1 to 2400.  (2400 cents is 2 octaves). Lots of small values for
 *   good control of depth in musical applications, and a couple of
 *   really broad ranges for special effects.
 ************************************************************************/

f32 _depth2Cents(u8 depth)
{
    f32     x = 1.03099303;
    f32     cents = 1.0;

    while(depth)
    {
        if(depth & 1)
            cents *= x;
        x *= x;
        depth >>= 1;
    }

    return(cents);
}

s32 func_80005B14(void) {
    struct UnkStruct80052D5C* sp3C;
    ALSynConfig* sp38;
    s32 sp34;
    s32 sp30;
    u32 sp2C;
    s16 sp2A;

    D_80052D80 = 0;
    D_80052D60 = 0;
    sp2A = D_8004A364;
    D_8004A364 = 0;
    D_8004A30C = D_8004A304 + D_8004A308;
    D_80052D54 = func_8000D84C(0x54U);
    if (D_80052D54 == NULL) {
        return 1;
    }
    alSndpNew(D_80052D54, (ALSndpConfig* ) &D_8004A30C);
    sp2C = D_8004A30C * 0x2C;
    D_80052D5C = func_8000D84C(sp2C);
    if (D_80052D5C == NULL) {
        return 1;
    }
    D_80052D78 = 0;
    D_80052D7A = 0x7F;
    D_80052D7B = 0x40;
    D_80052D7C = 0;
    D_80052D76 = D_80052D74 = 0x7FFF;
    D_80052D64 = 0;
    D_80052D68 = 0;
    D_80052D6C = 0.0f;

    for(sp30 = 0; sp30 < D_8004A30C; sp30++) {
        sp3C = &D_80052D5C[sp30];
        sp3C->unkC = 0;
        sp3C->unk10 = sp3C->unkC;
        sp3C->unk8 = 0;
        sp3C->unk16 = -1;
        sp3C->unk26 = 0;
        sp3C->unk22 = D_80052D7A;
        sp3C->unk24 = D_80052D7B;
        sp3C->unk25 = sp3C->unk24;
        sp3C->unk28 = D_80052D7C;
        sp3C->unk18 = D_80052D78;
        sp3C->unk1A = (u16) (s16) sp3C->unk18;
        sp3C->unk1C = 1.0f;
        sp3C->unk29 = 0;
    }

    if (func_800080D8() != 0) {
        return 1;
    }
    if (func_800060AC(4U) != 0) {
        return 1;
    }
    switch (D_80052D58->revision) {                              /* irregular */
    case 0x5431:
        if (D_8004A358 == 0) {
            return 0;
        }
        sp2C = (D_80052D58->bankCount * 8) + 4;
        if (func_800060AC(sp2C) != 0) {
            return 1;
        }
        sp30 = func_8000616C();
        if (sp30 != 0) {
            return sp30 - 1;
        }
        break;
    case 0x5432:
    case 0x5433:
        sp2C = (D_80052D58->bankCount * 8) + 4;
        if (func_800060AC(sp2C) != 0) {
            return 1;
        }
        sp34 = D_8004A354 + sp2C + ((s32) sp2C % 8);
        sp2C = 0x24;
        sp38 = func_8000D84C(sp2C);
        if (sp38 == NULL) {
            return 1;
        }
        func_80002CD0(sp34, sp38, sp2C);
        sp38->maxPVoices = (u32)D_8004A354 + sp38->maxPVoices;
        sp38->maxFXbusses = (u32)D_8004A354 + sp38->maxFXbusses;
        sp30 = func_80006284(sp38);
        if (sp30 != 0) {
            return sp30 - 1;
        }
        if (func_800065B8(sp38) != 0) {
            return 1;
        }
        if (D_80052D58->revision == 0x5432) {
            break;
        }
        sp30 = func_800064BC(sp38);
        if (sp30 != 0) {
            return sp30 - 1;
        }
        D_8004A364 = sp2A;
        if (func_800081B0() != 0) {
            return 1;
        }
        break;
    default:
        if (D_8004A358 == 0) {
            return 0;
        }
        sp30 = func_8000616C();
        if (sp30 != 0) {
            return sp30 - 1;
        }
        D_80052D58->bankCount = func_80006DF4(D_80052D50);
    }
    return 0;
}

s32 func_800060AC(s32 arg0) {
    if (arg0 & 1) {
        arg0 += 1;
    }
    D_80052D58 = func_8000D84C(arg0);
    if (D_80052D58 == NULL) {
        return 1;
    }
    if (D_8004A354 == 0) {
        D_80052D58->revision = 0;
    } else {
        func_80002CD0(D_8004A354, D_80052D58, arg0);
    }
    return 0;
}

s32 func_8000616C(void) {
    s32 sp1C;

    sp1C = D_8004A35C - D_8004A358;
    if (sp1C == 0) {
        D_8004A358 = 0;
        return 1;
    }
    if (sp1C & 1) {
        sp1C += 1;
    }
    D_80052D50 = func_8000D84C(sp1C);
    if (D_80052D50 == NULL) {
        return 2;
    }
    func_80002CD0(D_8004A358, D_80052D50, sp1C);
    if (((ALBankFile*)D_80052D50)->revision != 0x4231) {
        D_8004A358 = 0;
        return 1;
    }
    alBnkfNew((ALBankFile*)D_80052D50, D_8004A360);
    return 0;
}

s32 func_80006284(ALSynConfig* arg0) {
    s32 sp24;
    s32 i;
    struct UnkStructSP1C* sp1C;
    struct UnkStructSP18* sp18;

    sp24 = arg0->maxUpdates;
    if (sp24 == 0) {
        D_8004A358 = 0;
        return 1;
    }
    if (sp24 & 1) {
        sp24 += 1;
    }
    D_80052D50 = func_8000D84C(sp24);
    if (D_80052D50 == NULL) {
        return 2;
    }
    D_8004A358 = arg0->maxPVoices;
    func_80002CD0(D_8004A358, D_80052D50, sp24);

    for(i = 0; i < arg0->maxVVoices; i++) {
        // because writing &D_80052D50[sp20] is too sane for these geniuses
        sp1C = ((struct UnkStructSP1C *)D_80052D50) + i;
        if (sp1C->unkE != 0) {
                
        } else {
            sp1C->unkE = 1U;
            sp1C->unk0 += (int)D_80052D50;
            // why are you writing it like this
            sp1C->unk8 = sp18 = (struct UnkStructSP18 *)((char *)sp1C->unk8 + (int)D_80052D50);
            if (sp18->unk9 != 0) {

            } else {
                sp18->unk9 = 1U;
                sp18->unk0 += arg0->maxFXbusses;
                sp18->unk10 += (int)D_80052D50; // so is this a pointer or not?
                if ((void*)sp18->unkC != NULL) {
                    sp18->unkC += (int)D_80052D50;
                }
            }
        }
    }
    return 0;
}

// this function is also proof(?) it's not an ALSynConfig. But then the compiled in libaudio files
// (src/libultra/audio/, etc) show that fxType access is 8-bit. Whats going on with this struct?
s32 func_800064BC(ALSynConfig* arg0) {
    u8* sp1C;

    if ((*(u32*)&arg0->fxType == 0) || (arg0->params == NULL)) {
        return 1;
    }
    sp1C = arg0->params;
    if ((s32) sp1C & 1) {
        sp1C += 1;
    }
    D_80052D60 = func_8000D84C(sp1C);
    if (D_80052D60 == 0) {
        return 2;
    }
    *(u32*)&arg0->fxType = (s32) (*(u32*)&arg0->fxType + D_8004A354);
    func_80002CD0(*(u32*)&arg0->fxType, D_80052D60, sp1C);
    return 0;
}

s32 func_800065B8(ALSynConfig* arg0) {
    s16 i;
    s16 sp1C;

    if ((arg0->heap == NULL) || (arg0->outputRate == 0)) {
        return 0;
    }
    sp1C = (s16) arg0->outputRate;
    if (sp1C & 1) {
        sp1C += 1;
    }
    D_80052D80 = func_8000D84C(sp1C);
    if (D_80052D80 == NULL) {
        return 1;
    }
    *(u32*)&arg0->heap += (u32)D_8004A354;
    func_80002CD0(arg0->heap, D_80052D80, sp1C);
    *(u32*)&D_80052D80->unk0 += (u32)D_80052D80;
    *(u32*)&D_80052D80->unk4 += (u32)D_80052D80;
    sp1C = D_8004A30C * 0x54;
    D_80052D84 = func_8000D84C(sp1C);
    if (D_80052D84 == NULL) {
        return 1;
    }
    for(i = 0; i < D_8004A30C; i++) {
        func_80009B4C(i);
    }
    D_80052D7D = 0;
    return 0;
}

void func_8000678C(void) {
    struct UnkStruct80052D5C* sp4;
    s32 i;

    for(i = 0; i < D_8004A30C; i++) {
        sp4 = &D_80052D5C[i];
        if (sp4->unkC != 1) {

        } else {
            sp4->unk8 |= 2;
        }
    }
}

struct UnkStackStruct {
    char filler0[0xA];
    s16 unkA;
    char fillerC[0x6];
    s8 unk13;
    struct UnkStruct80052D5C* unk0;
};

void func_80006830(s16 arg0) {
    struct UnkStackStruct sp34;
    void* sp1C;

    sp34.unk0 = &D_80052D5C[arg0];
    sp34.unk0->unk8 &= ~0x1000;
    sp34.unk0->unkC = 0;
    func_800069D0(sp34.unk0->unk14, &sp1C);
    sp34.unk0->unk0 = sp1C;
    if (sp34.unk0->unk0 == 0) {
        return;
    }
    sp34.unk0->unk16 = alSndpAllocate(D_80052D54, sp34.unk0->unk0);
    if (sp34.unk0->unk16 < 0) {
        return;
    }
    alSndpSetPriority(D_80052D54, sp34.unk0->unk16, sp34.unk0->unk26 + 0xB);
    func_80008B84(sp34.unkA, arg0, sp34.unk0->unk29);
    func_80008CF4(arg0);
    func_800083EC(arg0, sp34.unk13);
    sp34.unk0->unk8 |= 0xF;
    func_80007890(arg0);
    alSndpSetSound(D_80052D54, sp34.unk0->unk16);
    alSndpPlay(D_80052D54);
    sp34.unk0->unkC = 1;
}

ALBank** func_800069D0(s16 arg0, struct UnkInputStruct800069D0* arg1) {
    struct UnkALStruct* sp34;
    struct UnkALStruct* sp30;
    struct UnkStruct80052D60* sp2C;
    struct UnkALStruct* sp28;
    s16 temp_s0;

    arg1->unkC = arg0;
    arg1->unk10 = 0x7F;
    arg1->unk12 = 0x40;
    arg1->unkE = -1;
    arg1->unk8 = 0;
    arg1->unk15 = 0;
    arg1->unk16 = 0;
    arg1->unk14 = 0;

    switch (D_80052D58->revision) {                              /* irregular */
    case 0x5431:
        sp28 = sp34 = (struct UnkALStruct*)D_80052D58[arg0].bankArray;

        arg1->unk0 = func_80006EE8(D_80052D50, sp34->unk0, sp34->unk1, sp34->unk2);
        arg1->unk4 = (f32) ((f32) sp34->unk6 / (f32) D_8004A2D8);
        arg1->unk13 = (u8) sp34->unk3;
        break;
    case 0x5432:
    case 0x5433:
        sp28 = sp30 = (struct UnkALStruct*)D_80052D58[arg0].bankArray;

        arg1->unk0 = (void* ) ((u32)D_80052D50 + ((sp30->unk4 & 0x1FFF) * 0x10));
        if (sp30->unk4 & 0x8000) {
            arg1->unk8 = (s32) (arg1->unk8 | 0x10);
        }
        if (sp30->unk4 & 0x4000) {
            arg1->unk8 = (s32) (arg1->unk8 | 0x40);
        }
        if (sp30->unk4 & 0x2000) {
            arg1->unk8 = (s32) (arg1->unk8 | 0x80);
        }
        if ((s8)sp30->unk0 >= 0) {
            arg1->unk10 = (s16) ((s8)sp30->unk1 & 0x7F);
            arg1->unk12 = *(s8*)&sp30->unk0;
        } else if (D_80052D80 != NULL) {
            arg1->unkE = (s16) ((((s8)sp30->unk0 & 0x7F) << 8) + (u8) sp30->unk1);
        }
        *(u8*)&arg1->unk14 = (s8) sp30->unk2;
        arg1->unk4 = (f32) ((f32) sp30->unk6 / (f32) D_8004A2D8);
        arg1->unk13 = (u8) sp30->unk3;

        if (D_80052D58->revision == 0x5432) {
            break;
        }
        if (D_80052D60 != 0) {
            sp2C = ((struct UnkStruct80052D60 *)D_80052D60) + arg0;
            arg1->unk15 = (s8) sp2C->unk0;
            arg1->unk16 = (s8) sp2C->unk1;
        }
        break;
    default:
        sp28 = NULL;
        arg1->unk0 = func_80006FD4(D_80052D50, arg0);
        arg1->unk4 = 1.0f;
        arg1->unk13 = 0x50U;
    }
    return sp28;
}

s16 func_80006DF4(s16 **arg0) {
    s16* sp14;
    s16* sp10;
    s16 i;
    s16 j;
    s16 spA;
    s16 sp8; 
    s16 sp6;

    spA = 0;
    sp8 = ((s16*)arg0)[1];

    for(i = 0; i < sp8; i++) {
        sp14 = ((s16 **)arg0)[i+1];
        sp6 = sp14[0];
        for(j = 0; j < sp6; j++) {
            sp10 = ((s16 **)sp14)[j+3];
            spA += sp10[7];
        }
    }
    return spA;
}

s32 func_80006EE8(s16** arg0, u8 arg1, u8 arg2, u8 arg3) {
    s16** spC;
    s16** sp8;
    s16 sp6;
    s16 sp4;
    s16 sp2;

    sp6 = ((s16*)arg0)[1];
    if (sp6 < arg1) {
        return 0;
    }
    spC = arg0[arg1+1];
    sp4 = ((s16*)spC)[0];
    if (sp4 < arg2) {
        return 0;
    }
    sp8 = spC[arg2+3];
    sp2 = ((s16*)sp8)[7];
    if (sp2 < arg3) {
        return 0;
    }
    return sp8[arg3+4];
}

s32 func_80006FD4(s16** arg0, s16 arg1) {
    s16* sp1C;
    s16* sp18;
    s32 sp14;
    s16 i; // i
    s16 j; // j
    s16 k; // k
    s16 spC = 0;
    s16 spA = ((s16*)arg0)[1];

    for(i = 0; i < spA; i++) {
        s16 sp8;

        sp1C = ((s16 **)arg0)[i+1];
        sp8 = sp1C[0];
        for(j = 0; j < sp8; j++) {
            s16 sp6;

            sp18 = ((s16 **)sp1C)[j+3];
            sp6 = sp18[7];
            for(k = 0; k < sp6; k++) {
                sp14 = ((s16**)sp18)[k+4];
                if (spC == arg1) {
                    return sp14;
                }
                spC += 1;
            }
        }
    }

    return 0;
}

s16 func_80007140(struct UnkInputStruct80007140* arg0, s32 arg1) {
    struct UnkStruct80052D5C* sp64;
    s32 sp60;
    s32 sp5C;
    s16 sp3C[16];
    s16 sp1C[16];
    u8 sp1B;

    sp5C = arg0->unk13 & 0xF;
    sp1B = (arg0->unk13 >> 4) & 0xF;
    if (D_8004A308 == 0) {
        sp5C = 0;
    }
    if (sp5C || D_8004A304 < 2) {
        if (D_8004A308 < sp5C) {
            return -1;
        }

        // this is probably not right.
        D_8004A304 ? (sp5C = D_8004A304 - 1 + sp5C) : 0;

        sp64 = &D_80052D5C[sp5C];
        if (sp64->unkC == 1 && sp64->unk26 > sp1B) {
            return -1;
        }
        return sp5C;
    }

    for(sp5C = 0; sp5C < D_8004A304; sp5C++) {
        sp64 = &D_80052D5C[sp5C];
        if (sp64->unkC != 1) {
            break;
        }
        sp3C[sp5C] = sp64->unk27;
        sp1C[sp5C] = sp5C;
    }

    if (sp5C == D_8004A304) {
        func_80007690(sp3C, sp1C, 0, D_8004A304 - 1);

        for(sp60 = 0; sp60 < D_8004A304; sp60++) {
            sp5C = sp1C[sp60];
            sp64 = &D_80052D5C[sp5C];

            if ( sp64->unk26 <= sp1B ) {
                break;
            }
        }
        if (sp60 == D_8004A304) {
            return -1;
        }
        sp1B = 0xFF;
    }

    if (arg1 == 0) {
        sp64->unk27 = D_8004A368++;
        if (D_8004A368 == 0) {
            if (sp1B == 0xFF) {
                sp64->unk27 = D_8004A304;
                for (sp60 = D_8004A304 - 1; sp60 >= 0; sp60--) {
                    if (sp1C[sp60] == sp5C) {
                        
                    } else {
                        D_80052D5C[sp1C[sp60]].unk27 = sp60;
                    }
                }
            } else {
                sp1B = 0;

                for(sp60 = 0; sp60 < D_8004A304; sp60++) {
                    sp64 = &D_80052D5C[sp60];
                    if (sp64->unkC != 1) {

                    } else {
                        sp3C[sp1B] = sp64->unk27;
                        sp1C[sp1B] = sp60;
                        sp1B++;
                    }
                }
                func_80007690(sp3C, sp1C, 0, sp1B - 1);
                D_80052D5C[sp5C].unk27 = sp1B;
                for (sp60 = sp1B - 1; sp60 >= 0; sp60--) {
                    D_80052D5C[sp1C[sp60]].unk27 = sp60;
                }
            }
        }
    }
    return sp5C;
}

void func_80007690(s16* arg0, s16* arg1, s32 arg2, s32 arg3) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s16 sp1A;

    sp1C = 1;
    if ((s16) arg2 < (s16) arg3) {
        sp24 = (s32) (s16) arg2;
        sp20 = (s32) (s16) arg3;
        if (sp24 < sp20) {
            do {
                if (arg0[sp24] > arg0[sp20]) {
                    sp1A = arg0[sp24];
                    arg0[sp24] = arg0[sp20];
                    arg0[sp20] = sp1A;
                    sp1A = arg1[sp24];
                    arg1[sp24] = arg1[sp20];
                    arg1[sp20] = sp1A;
                    if (sp1C != 0) {
                        sp1C = 0;
                    } else {
                        sp1C = 1;
                    }
                }
                if (sp1C != 0) {
                    sp20 -= 1;
                } else {
                    sp24 += 1;
                }
            } while (sp24 < sp20);
        }
        func_80007690(arg0, arg1, (s32) (s16) arg2, sp24 - 1);
        func_80007690(arg0, arg1, sp24 + 1, (s32) (s16) arg3);
    }
}

void func_80007890(s16 arg0) {
    struct UnkStruct80052D5C* sp24;
    f32 sp20;
    s16 sp1E;

    sp24 = &D_80052D5C[arg0];
    if (sp24->unk16 < 0) {
        return;
    }
    if (sp24->unk8 & 1) {
        sp20 = alCents2Ratio((s16) sp24->unk18 + (s16) sp24->unk1A) * sp24->unk1C;
        alSndpSetSound(D_80052D54, sp24->unk16);
        alSndpSetPitch(D_80052D54, sp24->unk4 * sp20);
        sp24->unk8 &= ~1;
    }
    if (sp24->unk8 & 2) {
        sp1E = (s16) ((s32) (sp24->unk20 * (s8) sp24->unk22 * sp24->unk23) / 16129);
        alSndpSetSound(D_80052D54, sp24->unk16);
        alSndpSetVol(D_80052D54, (s16) ((s32) (sp1E * D_80052D76) / 32767));
        sp24->unk8 &= ~2;
    }
    if (sp24->unk8 & 8) {
        alSndpSetSound(D_80052D54, sp24->unk16);
        alSndpSetFXMix(D_80052D54, sp24->unk28);
        sp24->unk8 &= ~8;
    }
    if (sp24->unk8 & 4) {
        if (D_80052DB7 & 1) {
            alSndpSetSound(D_80052D54, sp24->unk16);
            alSndpSetPan(D_80052D54, 0x40U);
        } else {
            sp1E = (sp24->unk25 + sp24->unk24) - 0x40;
            if (sp1E < 0) {
                sp1E = 0;
            }
            if (sp1E >= 0x80) {
                sp1E = 0x7F;
            }
            alSndpSetSound(D_80052D54, sp24->unk16);
            alSndpSetPan(D_80052D54, (u8) sp1E);
        }
        sp24->unk8 &= ~4;
    }
}

void func_80007BC4(void) {
    struct UnkStruct80052D5C* sp2C;
    s16 sp2A;
    s16 sp28;

    sp2A = alSndpGetSound(D_80052D54);
    D_80052D64 = 0;
    for(sp28 = 0; sp28 < D_8004A30C; sp28++) {
        sp2C = &D_80052D5C[sp28];
        if (sp2C->unk16 >= 0) {
            alSndpSetSound(D_80052D54, sp2C->unk16);
            sp2C->unkC = sp2C->unk10 = alSndpGetState(D_80052D54);
            switch (sp2C->unkC) {                  /* irregular */
            case 0:
                alSndpDeallocate(D_80052D54, sp2C->unk16);
                sp2C->unk16 = -1;
                sp2C->unk8 &= ~0x2000;
                break;
            case 2:
                if (sp2C->unk8 & 0x1000) {
                    sp2C->unkC = 1;
                }
                sp2C->unk8 &= ~0x2000;
                D_80052D64 += 1;
                break;
            case 1:
                if (sp2C->unk8 & 0x2000) {
                    alSndpStop(D_80052D54);
                } else if (D_80052D68 == 0) {
                    func_80008CF4(sp28);
                }
                D_80052D64 += 1;
            }
        }
        if (D_80052D68 != 0) {
            
        } else {
            if ((sp2C->unk8 & 0x1000) && (sp2C->unk16 < 0)) {
                func_80006830(sp28);
                D_80052D64 += 1;
            }
            if (sp2C->unk8 & 0xF) {
                func_80007890(sp28);
            }
        }
    }
    if (D_80052D68 != 0) {
        if (sp2A != -1) {
            alSndpSetSound(D_80052D54, sp2A);
        }
        return;
    }
    func_80008744();
    if (D_80052D6C > 0.0f) {
        D_80052D70 += D_80052D6C;
        if (D_80052D70 >= D_80052D74) {
            func_8000B5DC();
            D_80052D6C = 0.0f;
            D_80052D76 = D_80052D74;
        } else {
            sp28 = (s16) (s32) ((f32) D_80052D74 - D_80052D70);
            if (D_80052D76 != sp28) {
                D_80052D76 = sp28;
                func_8000678C();
            }
        }
    }
    if (D_80052D6C < 0.0f) {
        D_80052D70 -= D_80052D6C;
        if (D_80052D70 >= D_80052D74) {
            sp28 = D_80052D74;
            D_80052D6C = 0.0f;
        } else {
            sp28 = (s16) (s32) D_80052D70;
        }
        if (D_80052D76 != sp28) {
            D_80052D76 = sp28;
            func_8000678C();
        }
    }
    if (sp2A != -1) {
        alSndpSetSound(D_80052D54, sp2A);
    }
}

s32 func_800080D8(void) {
    u32 sp1C;

    sp1C = D_8004A30C * 0x10;
    D_80052D88 = func_8000D84C(sp1C);
    if (D_80052D88 == NULL) {
        return 1;
    }
    D_80052D8C = 50.0f;
    D_80052D90 = 500.0f;
    D_80052D94 = 0.0f;
    D_80052D98 = 0.0f;
    D_80052D9C = 0;
    D_80052D9E = 0xA;
    D_80052DA0 = 1224.0f;
    D_80052DA4 = 1.0f;
    return 0;
}

s32 func_800081B0(void) {
    u32 sp1C;

    if (D_8004A364 == 0) {
        return 0;
    }
    sp1C = D_8004A364 * 0xC;
    D_80052DA8 = func_8000D84C(sp1C);
    if (D_80052DA8 == NULL) {
        return 1;
    }
    func_80008360();
    D_80052DB5 = 0;
    D_80052DB4 = 0;
    D_80052DAC = D_80052DB0 = 0.0f;
    return 0;
}

void func_8000826C(s16 arg0) {
    s32 sp4;
    struct UnkStruct80052DA8* sp0;

    if (D_8004A364 == 0) {
        return;
    }
    for(sp4 = 0; sp4 < D_8004A364; sp4++) {
        sp0 = &D_80052DA8[sp4];
        if (D_80052D5C[arg0].unk14 != sp0->unk0) {
            continue;
        }
        if (sp0->unk2 == arg0) {
            sp0->unk0 = -1;
            return;
        }
    }
}

void func_80008360(void) {
    s32 sp4;

    if (D_8004A364 == 0) {
        return;
    }
    for(sp4 = 0; sp4 < D_8004A364; sp4++) {
        D_80052DA8[sp4].unk0 = -1;
    }
    D_80052DB6 = 0;
}

void func_800083EC(s16 arg0, s8 arg1) {
    s32 spC;
    s32 sp8;
    struct UnkStruct80052DA8* sp4;
    struct UnkStruct80052D5C* sp0;

    if ((D_8004A364 == 0) || (D_80052D5C[arg0].unk8 & 0x20)) {
        return;
    }
    if ((D_80052DB4 <= 0) || (D_80052DB5 < 2)) {
        return;
    }
    if ((D_80052DAC == 0.0f) || (D_80052DB0 == 0.0f)) {
        return;
    }
    if ((arg0 != 0) || (D_8004A304 < 2)) {
        for(spC = 0; spC < D_8004A364; spC++) {
            sp4 = &D_80052DA8[spC];
            if (sp4->unk0 < 0) {
                continue;
            }
            if (sp4->unk2 == arg0) {
                sp8 = spC;
                break;
            }
        }
        if (arg1 == 0) {
            if (spC < D_8004A364) {
                D_80052DA8[sp8].unk0 = -1;
            }
            return;
        }
        if (D_8004A364 == spC) {
            sp8 = D_80052DB6++;
        }
    } else {
        if (arg1 == 0) {
            return;
        }
        sp8 = D_80052DB6++;
    }
    if (D_80052DB6 >= D_8004A364) {
        D_80052DB6 = 0;
    }
    sp0 = &D_80052D5C[arg0];
    sp4 = &D_80052DA8[sp8];
    sp4->unk0 = sp0->unk14;
    sp4->unk2 = arg0;
    sp4->unk4 = sp0->unk22;
    sp4->unk5 = sp0->unk23;
    sp4->unk6 = sp0->unk25;
    sp4->unk7 = arg1;
    sp4->unk8 = D_80052DB4;
    sp4->unk9 = D_80052DB5;
}

void func_80008744(void) {
    s32 sp24;
    s32 sp20;
    struct UnkStruct80052DA8* sp1C;
    s16 sp1A;
    s16 sp18;

    if (D_8004A364 == 0) {
        return;
    }
    for(sp24 = 0; sp24 < D_8004A364; sp24++) {
        sp1C = &D_80052DA8[sp24];
        if (sp1C->unk0 < 0) {

        } else {
            sp1C->unk8 -= 1;
            if (sp1C->unk8 != 0) {

            } else {
                sp1C->unk9 -= 1;
                if (sp1C->unk9 == 0) {
                    sp1C->unk0 = -1;;
                } else {
                    sp18 = sp1C->unk2;
                    if ((D_8004A304 >= 2) && (sp18 < D_8004A304)) {
                        sp20 = 1;
                    } else {
                        sp20 = 0;
                    }
                    if ((sp20 == 0) && (D_80052D5C[sp18].unk8 & 0x1000)) {
                        sp1C->unk0 = -1;;
                    } else {
                        if ((sp1C->unk9 + 1) == D_80052DB5) {
                            sp1C->unk4 = (s8) (s32) (((f32) sp1C->unk4 * D_80052DB0 * (f32) sp1C->unk7) / 127.0f);
                        } else {
                            sp1C->unk4 = (s8) (s32) ((f32) sp1C->unk4 * D_80052DAC);
                        }
                        if (sp1C->unk4 >= 6) {
                            if (sp20 != 0) {
                                D_80052D5C[sp18].unk26 += 1;
                                sp1A = func_8000AC1C(sp1C->unk0);
                                D_80052D5C[sp18].unk26 -= 1;
                            } else {
                                sp1A = func_8000AC1C(sp1C->unk0);
                            }
                            if (sp1A < 0) {
                                sp1C->unk0 = -1;
                                continue;
                            }
                            func_8000C6F8(sp1A, sp1C->unk4);
                            func_8000C7D4(sp1A, sp1C->unk6);
                            D_80052D5C[sp1A].unk23 = sp1C->unk5;
                            sp1C->unk8 = D_80052DB4;
                            D_80052D5C[sp1A].unk8 |= 0x20;
                        } else {
                            sp1C->unk0 = -1;;
                        }
                    }
                }
            }
        }
    }
}

void func_80008B84(s16 arg0, s16 arg1, s8 arg2) {
    struct UnkStruct80052D84* sp4;
    u16 *sp0;

    if (D_80052D80 == NULL) {
        return;
    }
    sp4 = &D_80052D84[arg1];
    if (arg2 != 3) {
        sp4->unkA = -1;
    }
    sp4->unk4 = 0;
    sp4->unk8 = arg0;
    if (arg0 < 0) {
        return;
    }
    sp0 = D_80052D80->unk0;
    sp4->unk0 = (void* )((u32)D_80052D80 + sp0[arg0]);
    sp4->unkC = 0;
    sp4->u.unk18_as16[1] = 0;
    sp4->unk1C = 0;
    sp4->unk2C = 1.0f;
    sp4->unk30 = 0;
    sp4->unk40 = 1.0f;
    sp4->unkE = 0;
    sp4->unk10 = 0x7F;
    sp4->unk12 = 0x40;
    sp4->unk53 = 0;
}

void func_80008CF4(s16 arg0) {
    struct UnkStruct80052D5C* sp3C;
    struct UnkStruct80052D84* sp38;
    u8 *sp34;
    s8* sp30;
    u16 *sp2C;
    s16 sp2A;
    s16 sp28;
    u8 temp_t0;

    if (D_80052D80 == NULL) {
        return;
    }
    sp38 = &D_80052D84[arg0];
    if (sp38->unk8 < 0) {
        return;
    }
    if (D_80052D7D != 0) {
        if (sp38->unk53 != 0) {
            sp38->unk53 -= 1;
            return;
        } else
        sp38->unk53 = D_80052D7D;
    }

    sp3C = &D_80052D5C[arg0];
    sp34 = (u8*)sp38->unk0;
    if (sp38->unkC == 0) {
        do {
            temp_t0 = *(sp34++);
            sp38->unkC = (sp34[0] << 8) + sp34[1];
            sp34+=2;
            switch (temp_t0) {
            case 0x82:
                break;
            case 0x83:
                sp2A = (sp34[0] << 8) + sp34[1];
                sp34+=2;
                
                if ((sp2A != sp3C->unk14) && (sp38->unkA < 0) && (sp38->u.unk18_as16[1] < 3)) {
                    sp28 = func_80009AD0(sp2A);
                    if ((sp28 < 0) || (sp28 == arg0)) {
                        break;
                    }
                    sp28 = func_8000AC1C(sp2A);
                    // ((u32*)((u32*)sp38)[sp38->unk1A])
                    ((struct UnkStruct80052D84*)((u32)sp38 + (sp38->u.unk18_as16[1]++ * 2)))->unk14 = sp28;
                    D_80052D5C[sp28].unk29 = 3;
                    D_80052D84[sp28].unkA = arg0;
                    D_80052D5C[sp28].unk22 = sp3C->unk22;
                    D_80052D5C[sp28].unk23 = sp3C->unk23;
                    D_80052D5C[sp28].unk25 = sp3C->unk25;
                    D_80052D5C[sp28].unk1A = (u16) (s16) sp3C->unk1A;
                    D_80052D5C[sp28].unk28 = sp3C->unk28;
                }
                break;
            case 0x84:
                sp30 = &sp38->unk1C;
                if ((u8) *sp30 == 1) {
                    *sp30 = 0;
                    sp34+=3;;
                    break;
                }
                if ((u8) *sp30 != 0) {
                    *sp30 = (u8) *sp30 - 1;
                } else {
                    if (*sp34 == 0) {
                        sp34+=3;;
                        break;
                    }
                    *sp30 = *sp34;
                }
                sp34 = (void*)( ((s16)((sp34[1] << 8) + sp34[2]) + (u32)sp34) - 3);
                break;
            case 0x85:
                sp34 = (void*)( ((s16)((sp34[0] << 8) + sp34[1]) + (u32)sp34) - 3);
                break;
            case 0x88:
                sp38->unk1D = sp34[0];
                sp34+=1;
                sp38->unk1F = sp34[0];
                sp34+=1;
                sp38->unk1E = sp34[0];
                sp34+=1;
                break;
            case 0x89:
                sp2A = (sp34[0] << 8) + sp34[1];
                sp38->unk2C = (f32) sp2A / 100.0f;
                sp34+=2;
                break;
            case 0x90:
                sp38->unk10 = (s16) sp34[0];
                sp34+=1;
                break;
            case 0x91:
                sp38->unk10 += (s8) sp34[0];
                sp34+=1;
                break;
            case 0x98:
                sp38->unk12 = (s16) sp34[0];
                sp34+=1;
                break;
            case 0x99:
                sp38->unk12 += (s8) sp34[0];
                sp34+=1;
                break;
            case 0x9A:
                if (*(sp34++) & 1) {
                    sp38->unk4 |= 8;
                } else {
                    sp38->unk4 |= 0x10;
                }
                sp38->unk50 = (s16) ((sp34[0] << 8) + sp34[1]);
                sp38->unk4E = (s16) ((s32) (sp38->unk50 * sp38->unk12) / 127);
                sp34+=2;
                break;
            case 0xA0:
                sp38->unkE = (sp34[0] << 8) + sp34[1];
                sp34+=2;
                break;
            case 0xA1:
                sp38->unkE += (s16) ((sp34[0] << 8) + sp34[1]);
                sp34+=2;
                break;
            case 0xA2:
                if (*(sp34++)) {
                    sp38->unk26 = 0;
                    sp38->unk28 = -200.0f;
                    sp38->unk22 = (0x105 - sp38->unk1F);
                    sp38->unk24 = (s16) (s32) _depth2Cents((u8) sp38->unk1E);
                    sp38->unk20 = 0;
                    sp38->unk4 |= 2;
                } else {
                    sp38->unk4 &= ~2;
                }
                break;
            case 0xA3:
                sp38->unk30 = (s16) sp34[0];
                sp34 += 1;
                sp38->unk32 = (s16) ((sp34[0] << 8) + sp34[1]);
                sp38->unk36 = (s16) ((sp34[2] << 8) + sp34[3]);
                sp38->unk34 = 0;
                sp34 += 4;
                break;
            case 0xA4:
                sp2C = D_80052D80->unk4;
                sp38->unk3C = sp38->unk38 = ((u32)sp2C + sp2C[sp34[0]]);
                sp38->unk44 = (s16) ((sp34[1] << 8) + sp34[2]);
                sp38->unk46 = (s16) ((sp34[3] << 8) + sp34[4]);
                sp38->unk4C = 0;
                sp38->unk4A = 0;
                sp38->unk4 |= 0x20;
                sp34 += 5;
                break;
            case 0xA5:
                sp2A = (sp34[0] << 8) + sp34[1];
                sp38->unk40 = (f32) sp2A / 100.0f;
                sp34 += 2;
                break;
            case 0xA6:
                sp38->unk4 &= ~0x20;
                break;
            case 0xA8:
                sp3C->unk28 = sp34[0];
                sp34 += 1;
                sp3C->unk8 |= 8;
                break;
            case 0x80:
                sp38->unk4 |= 0x100;
                /* fallthrough */
            case 0x81:
                sp38->unk4 |= 0x200;
                sp38->unk8 = -1;
                sp38->unkC = 1;
                break;
            default:
                sp38->unk4 |= 0x300;
                sp38->unk8 = -1;
                sp38->unkC = 1;
            }
        } while (sp38->unkC == 0);
    }
    sp38->unkC -= 1;
    sp38->unk0 = sp34;
    func_80009BA4(sp3C, sp38);
    func_8000A534(sp3C, sp38);
    func_8000A724(sp3C, sp38);
    if (sp38->unk4 & 0x100) {
        if (sp38->u.unk18_as16[1] > 0) {
            do {
                sp38->u.unk18_as16[1] -= 1; // (struct UnkStruct80052D84*)
                sp2A = ((struct UnkStruct80052D84*)((u32)sp38 + ((s16)sp38->u.unk18 * 2)))->unk14;
                if (D_80052D84[sp2A].unkA != arg0) {

                } else {
                    sp3C = &D_80052D5C[sp2A];
                    if (sp3C->unkC != 1) {

                    } else {
                        if (sp3C->unk8 & 0x1000) {
                            sp3C->unk8 &= ~0x1000;
                            sp3C->unkC = sp3C->unk10;
                        } else {
                            alSndpSetSound(D_80052D54, sp3C->unk16);
                            alSndpStop(D_80052D54);
                            sp3C->unk8 |= 0x2000;
                        }
                        sp3C->unk29 = 0;
                        func_80009B4C(sp2A);
                    }
                }
            } while (sp38->u.unk18_as16[1] > 0);
        }
        sp3C = &D_80052D5C[arg0];
        alSndpSetSound(D_80052D54, sp3C->unk16);
        alSndpStop(D_80052D54);
        sp3C->unk8 |= 0x2000;
        sp3C->unk29 = 0;
    }
}

s16 func_80009AD0(s16 arg0) {
    struct UnkInputStruct800069D0 sp20;
    s16 retVar;

    if ((arg0 >= D_80052D58->bankCount) || (arg0 < 0)) {
        return -1;
    }
    func_800069D0(arg0, &sp20);
    retVar = func_80007140(&sp20, 1);
    return retVar;
}

void func_80009B4C(s16 arg0) {
    struct UnkStruct80052D84* sp4 = &D_80052D84[arg0];

    sp4->unk8 = -1;
    sp4->unk4 = 0;
}

void func_80009BA4(struct UnkStruct80052D5C* arg0, struct UnkStruct80052D84* arg1) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp24 = 0.0f;
    if (arg1->unk4 & 2) {
        switch (arg1->unk1D) {
        case 1:
            arg1->unk20 = (s16) (arg1->unk20 + 2);
            if (arg1->unk20 >= arg1->unk22) {
                arg1->unk20 = 0;
            } else {
                sp2C = (f32) arg1->unk20 / (f32) arg1->unk22;
                sp24 = sinf((f32) ((f64) sp2C * 6.28318530000000042)) * (f32) arg1->unk24 * arg1->unk2C;
            }
            break;
        case 2:
            if (arg1->unk20 >= ((s16) arg1->unk22 / 4)) {
                arg1->unk26 = (s16) (arg1->unk26 + 1);
                if (arg1->unk26 >= 4) {
                    arg1->unk26 = 0;
                }
                arg1->unk20 = 0;
            }
            sp2C = (f32) arg1->unk20 / (f32) ((s16) arg1->unk22 / 4);
            switch (arg1->unk26) {                      /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                sp2C = 1.0f - sp2C;
                break;
            case 3:                                 /* switch 1 */
                sp2C = 1.0f - sp2C;
                /* fallthrough */
            case 2:                                 /* switch 1 */
                sp2C *= -1.0f;
                break;
            }
            sp24 = (f32) arg1->unk24 * sp2C * arg1->unk2C;
            arg1->unk20 = (s16) (arg1->unk20 + 2);
            break;
        case 3:
            if (arg1->unk20 >= arg1->unk22) {
                arg1->unk20 = 0;
            }
            sp28 = (f32) arg1->unk22 / 2.0f;
            sp2C = (f32) arg1->unk20 - sp28;
            sp24 = (f32) arg1->unk24 * (sp2C / sp28) * arg1->unk2C;
            arg1->unk20 = (s16) (arg1->unk20 + 2);
            break;
        case 4:
            if (arg1->unk20 >= arg1->unk22) {
                arg1->unk20 = 0;
                arg1->unk26 = (s16) ~arg1->unk26;
            }
            if (arg1->unk26 == 0) {
                sp24 = (f32) arg1->unk24 * arg1->unk2C;
            } else {
                sp24 = (f32) arg1->unk24 * -arg1->unk2C;
            }
            arg1->unk20 = (s16) (arg1->unk20 + 2);
            break;
        case 5:
            if ((arg1->unk20 >= ((s16) arg1->unk22 / 2)) || (arg1->unk28 == -200.0f)) {
                arg1->unk20 = 0;
                arg1->unk28 = (f32) ((f32) (0x64 - (guRandom() % 200)) / 100.0f);
            }
            sp24 = (f32) arg1->unk24 * arg1->unk28 * arg1->unk2C;
            arg1->unk20 = (s16) (arg1->unk20 + 2);
            break;
        }
    }
    if (arg1->unk30 == 1) {
        goto useless;
        useless:;
        
        if (++arg1->unk34 >= arg1->unk36) {
            arg1->unk30 = 0;
            arg1->unkE = (s16) (arg1->unkE + arg1->unk32);
            sp24 = 0.1000000015;
        } else {
            sp2C = (f32) arg1->unk34 / (f32) arg1->unk36;
            sp24 = sp24 + ((f32) arg1->unk32 * sp2C);
        }
        goto useless_2;
    } 
    useless_2:;
    if (arg1->unk4 & 0x20) {
        if (arg1->unk44 != 0) {
            arg1->unk44 = (s16) (arg1->unk44 - 1);
        } else {
            if (arg1->unk4C == 0) {
                arg1->unk4C = *arg1->unk38;
                if (arg1->unk4C == 0) {
                    arg1->unk38 = (void* ) arg1->unk3C;
                    arg1->unk4C = (s16) *arg1->unk38;
                }
                arg1->unk48 = ((((u8*)arg1->unk38)[1] << 8)) + (((u8*)arg1->unk38)[2]);
                arg1->unk48 = (s16) (s32) ((f32) arg1->unk48 * arg1->unk40);
                arg1->unk38 = (void* ) (arg1->unk38 + 3);
            }
            if (arg1->unk4C == -0x80) {
                sp24 += (f32) (arg1->unk46 + arg1->unk4A);
            } else if (arg1->unk4C > 0) {
                arg1->unk4C = (s16) (arg1->unk4C - 1);
                sp24 += (f32) (arg1->unk46 + arg1->unk48);
                arg1->unk4A = (s16) arg1->unk48;
            } else {
                arg1->unk4C = (s16) (arg1->unk4C + 1);
                arg1->unk4A = (s16) (arg1->unk4A + arg1->unk48);
                sp24 += (f32) (arg1->unk46 + arg1->unk4A);
            }
        }
    }
    sp24 += (f32) arg1->unkE;
    if (sp24 > 1200.0f) {
        sp24 = 1200.0f;
    }
    if (arg0->unk18 != (s16) (s32) sp24) {
        arg0->unk18 = (s16) (s32) sp24;
        arg0->unk8 |= 1;
    }
}

void func_8000A534(struct UnkStruct80052D5C* arg0, struct UnkStruct80052D84* arg1) {
    s16 sp1E;

    func_80002DD4(&arg1->unk12, 0x7F);
    if (arg1->unk4 & 0x18) {
        if (arg1->unk4 & 8) {
            arg1->unk4E += 1;
            if (arg1->unk4E >= arg1->unk50) {
                arg1->unk4E = arg1->unk50;
                arg1->unk4 &= ~8;
            }
        } else {
            arg1->unk4E -= 1;
            if (arg1->unk4E <= 0) {
                arg1->unk4E = 0;
                arg1->unk4 &= ~0x10;
            }
        }
        sp1E = (s16) (s32) (((f32) arg1->unk4E * 127.0f) / (f32) arg1->unk50);
        func_80002DD4(&sp1E, 0x7F);
        arg1->unk12 = (u8)sp1E;
    }
    if (arg0->unk24 != arg1->unk12) {
        arg0->unk24 = (u8) arg1->unk12;
        arg0->unk8 |= 4;
    }
}

void func_8000A724(struct UnkStruct80052D5C* arg0, struct UnkStruct80052D84* arg1) {
    s16 sp1E;

    func_80002DD4(&arg1->unk10, 0x7F);
    sp1E = func_80002D90(arg1->unk10);;
    if (arg0->unk20 != sp1E) {
        arg0->unk20 = sp1E;
        arg0->unk8 |= 2;
    }
}

void func_8000A7B4(s16 arg0, s8 arg1) {
    struct UnkStruct80052D84* sp1C = &D_80052D84[arg0];
    s16 sp1A;
    s16 sp18;

    sp18 = sp1C->u.unk18_as16[1];
    if (sp18 > 0) {
        do {
            sp18 -= 1;
            sp1A = ((struct UnkStruct80052D84*)((u32)sp1C + (sp18 * 2)))->unk14;
            if (D_80052D84[sp1A].unkA != arg0) {

            } else {
                func_8000C6F8(sp1A, arg1);
            }
        } while (sp18 > 0);
    }
}

void func_8000A8B4(s16 arg0, u8 arg1) {
    struct UnkStruct80052D84* sp1C = &D_80052D84[arg0];
    s16 sp1A;
    s16 sp18;

    sp18 = sp1C->u.unk18_as16[1];
    if (sp18 > 0) {
        do {
            sp18 -= 1;
            sp1A = ((struct UnkStruct80052D84*)((u32)sp1C + (sp18 * 2)))->unk14;
            if (D_80052D84[sp1A].unkA != arg0) {

            } else {
                func_8000C7D4(sp1A, arg1);
            }
        } while (sp18 > 0);
    }
}

void func_8000A9B4(s16 arg0, s16 arg1) {
    struct UnkStruct80052D84* sp1C;
    s16 sp1A;
    s16 sp18;

    sp1C = &D_80052D84[arg0];
    sp18 = sp1C->u.unk18_as16[1];
    if (sp18 > 0) {
        do {
            sp18 -= 1;
            sp1A = ((struct UnkStruct80052D84*)((u32)sp1C + (sp18 * 2)))->unk14;
            if (D_80052D84[sp1A].unkA != arg0) {

            } else {
                func_8000C8CC(sp1A, arg1);
            }
        } while (sp18 > 0);
    }
}

void func_8000AAB4(s16 arg0, s8 arg1) {
    struct UnkStruct80052D84* sp1C;
    s16 sp1A;
    s16 sp18;

    sp1C = &D_80052D84[arg0];
    sp18 = sp1C->u.unk18_as16[1];
    if (sp18 > 0) {
        do {
            sp18 -= 1;
            sp1A = ((struct UnkStruct80052D84*)((u32)sp1C + (sp18 * 2)))->unk14;
            if (D_80052D84[sp1A].unkA != arg0) {

            } else {
                func_8000C9C4(sp1A, arg1);
            }
        } while (sp18 > 0);
    }
}

void func_8000ABB4(void) {
    func_8000B5DC();
    alSndpDelete(D_80052D54);
}

void func_8000ABEC(u32 arg0, s32 arg1, s32 arg2, u8* arg3) {
    D_8004A354 = arg0;
    D_8004A358 = arg1;
    D_8004A35C = arg2;
    D_8004A360 = arg3;
}

s16 func_8000AC1C(s16 arg0) {
    struct UnkStruct80052D5C* sp44;
    struct UnkStruct80052D88* sp40;
    struct UnkInputStruct800069D0 sp28;
    s16 sp26;
    s16 temp_s0;

    if (D_8004A358 == 0) {
        return -1;
    }
    if ((arg0 >= D_80052D58->bankCount) || (arg0 < 0)) {
        return -1;
    }
    func_800069D0(arg0, &sp28);

    switch(D_80052D58->revision) {
        case 0x5431:
        case 0x5432:
        case 0x5433:
            sp26 = func_80007140(&sp28, 0);
            if (sp26 < 0) {
                return -1;
            }
            break;
        default:
            sp26 = sp28.unk13 & 0xF;
    }

    sp44 = &D_80052D5C[sp26];
    if ((sp44->unkC == 1) && !(sp44->unk8 & 0x1000)) {
        func_8000AF40(sp26);
    } else {
        sp44->unk8 = 0;
    }
    sp44->unk14 = arg0;
    sp44->unk22 = D_80052D7A;
    sp44->unk20 = func_80002D90(sp28.unk10);
    sp44->unk23 = 0x7F;
    sp44->unk25 = D_80052D7B;
    sp44->unk24 = sp28.unk12;
    sp44->unk1A = (u16) D_80052D78;
    sp44->unk18 = 0;
    sp44->unk1C = 1.0f;
    sp44->unk4 = sp28.unk4;
    sp44->unkC = 1;
    sp44->unk26 = ((s32) sp28.unk13 >> 4) & 0xF;
    if ((s8) sp28.unk15 != 0) {
        sp44->unk28 = (u8) (s8) sp28.unk15;
    } else {
        sp44->unk28 = D_80052D7C;
    }
    sp40 = &D_80052D88[sp26];
    sp40->unk4 = 0.0f;
    sp40->unk0 = sp40->unk4;
    sp40->unkE = sp28.unk14;
    sp40->unk8 = -1.0f;
    if (sp28.unkE < 0) {
        sp44->unk29 = 1;
    } else {
        sp44->unk29 = 2;
    }
    sp44->unk8 |= sp28.unk8 | 0x1000;
    return sp26;
}

void func_8000AF40(s16 arg0) {
    struct UnkStruct80052D5C* sp24;
    struct UnkStruct80052D84* sp20;
    s16 sp1E;

    sp24 = &D_80052D5C[arg0];
    if (sp24->unk16 < 0) {
        return;
    }
    alSndpSetSound(D_80052D54, sp24->unk16);
    alSndpStop(D_80052D54);
    sp24->unk8 = 0x2000;
    if (sp24->unk29 == 2) {
        sp20 = &D_80052D84[arg0];
        if (sp20->u.unk18_as16[1] > 0) {
            do {
                sp20->u.unk18_as16[1] -= 1;
                sp1E = ((struct UnkStruct80052D84*)((u32)sp20 + ((s16)sp20->u.unk18 * 2)))->unk14;
                if (D_80052D84[sp1E].unkA != arg0) {

                } else {
                    sp24 = &D_80052D5C[sp1E];
                    if (sp24->unkC != 1) {

                    } else {
                        if (sp24->unk8 & 0x1000) {
                            sp24->unk8 &= ~0x1000;
                            sp24->unkC = sp24->unk10;
                        } else {
                            alSndpSetSound(D_80052D54, sp24->unk16);
                            alSndpStop(D_80052D54);
                            sp24->unk8 |= 0x2000;
                        }
                        sp24->unk29 = 0;
                        func_80009B4C(sp1E);
                    }
                }
            } while (sp20->u.unk18_as16[1] > 0);
        }
    }
    D_80052D5C[arg0].unk29 = 0;
    if (D_80052D80 != NULL) {
        func_80009B4C(arg0);
    }
}

void func_8000B1FC(f32 arg0, s32 arg1, s16 arg2) {
    if (arg0 >= 0.0f) {
        D_80052DA0 = arg0;
    }
    if (arg2 >= 0) {
        D_80052D9E = arg2;
    }
    if (arg1 >= 0) {
        D_80052DA4 = (f32) arg1;
    }
}

void func_8000B25C(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    if (arg0 >= 0) {
        D_80052D9C = arg0;
        if (D_80052D9C >= 0x168) {
            D_80052D9C = 0;
        }
    }
    if (arg1 >= 0.0f) {
        D_80052D8C = arg1;
    }
    if (arg2 >= 0.0f) {
        D_80052D90 = arg2 - arg1;
    }
    if (arg3 >= 0.0f) {
        D_80052D94 = arg3;
    }
    if (arg4 >= 0.0f) {
        D_80052D98 = arg4 - D_80052D94;
        if (D_80052D98 < 0.0f) {
            D_80052D98 = 0.0f;
        }
    }
}

s16 func_8000B390(s16 arg0, s16 arg1, f32 arg2) {
    s16 sp1E = func_8000AC1C(arg0);

    if (sp1E < 0) {
        return -1;
    }
    func_8000BD20(sp1E, arg1, arg2);
    return sp1E;
}

s16 func_8000B404(s16 arg0) {
    struct UnkStruct80052D5C* sp4;
    s16 sp2;

    for(sp2 = 0; sp2 < D_8004A30C; sp2++) {
        sp4 = &D_80052D5C[sp2];
        if (sp4->unkC == 0) {
            
        } else if (sp4->unk14 == arg0) {
            return sp2;
        }
    }

    return -1;
}

s32 func_8000B4CC(void) {
    return D_80052D64;
}

u32 func_8000B4EC(s16 arg0) {
    struct UnkStruct80052D5C* sp4;

    sp4 = &D_80052D5C[arg0];
    if ((D_80052D68 != 0) && (sp4->unkC != 0)) {
        return 0x100U;
    }
    if (sp4->unk8 & 0x1000) {
        return 0x200U;
    }
    return sp4->unkC;
}

s16 func_8000B598(void) {
    if (D_8004A358 == 0) {
        return 0;
    }
    return D_80052D58->bankCount;
}

void func_8000B5DC(void) {
    struct UnkStruct80052D5C* sp1C;
    s16 sp1A;

    for(sp1A = 0; sp1A < D_8004A30C; sp1A++) {
        sp1C = &D_80052D5C[sp1A];
        if (sp1C->unkC != 1) {

        } else {
            if (sp1C->unk8 & 0x1000) {
                sp1C->unk8 &= ~0x1000;
                sp1C->unkC = sp1C->unk10;
            } else {
                alSndpSetSound(D_80052D54, sp1C->unk16);
                alSndpStop(D_80052D54);
                sp1C->unk8 |= 0x2000;
            }
            if (D_80052D80 != NULL) {
                func_80009B4C(sp1A);
            }
            sp1C->unk29 = 0;
        }
    }
    func_80008360();
}

void func_8000B738(s16 arg0) {
    struct UnkStruct80052D5C* sp24;
    struct UnkStruct80052D84* sp20;
    s16 sp1E;

    sp24 = &D_80052D5C[arg0];
    if (sp24->unkC != 1) {
        return;
    }
    if (sp24->unk8 & 0x1000) {
        sp24->unk8 &= ~0x1000;
        sp24->unkC = sp24->unk10;
    } else {
        alSndpSetSound(D_80052D54, sp24->unk16);
        alSndpStop(D_80052D54);
        sp24->unk8 |= 0x2000;
        if (sp24->unk29 == 2) {
            sp20 = &D_80052D84[arg0];
            if (sp20->u.unk18_as16[1] > 0) {
                do {
                    sp20->u.unk18_as16[1] -= 1;
                    sp1E = ((struct UnkStruct80052D84*)((u32)sp20 + ((s16)sp20->u.unk18 * 2)))->unk14;
                    if (D_80052D84[sp1E].unkA != arg0) {

                    } else {
                        sp24 = &D_80052D5C[sp1E];
                        if (sp24->unkC != 1) {

                        } else {
                            if (sp24->unk8 & 0x1000) {
                                sp24->unk8 &= ~0x1000;
                                sp24->unkC = sp24->unk10;
                            } else {
                                alSndpSetSound(D_80052D54, sp24->unk16);
                                alSndpStop(D_80052D54);
                                sp24->unk8 |= 0x2000;
                            }
                            sp24->unk29 = 0;
                            func_80009B4C(sp1E);
                        }
                    }
                } while (sp20->u.unk18_as16[1] > 0);
            }
        }
    }
    D_80052D5C[arg0].unk29 = 0;
    if (D_80052D80 != NULL) {
        func_80009B4C(arg0);
    }
    func_8000826C(arg0);
}

void func_8000BA54(s16 arg0) {
    if (arg0 < 0) {
        arg0 = 1;
    }
    D_80052D70 = 0.0f;
    D_80052D6C = (f32) D_80052D74 / (f32) arg0;
}

void func_8000BAAC(void) {
    struct UnkStruct80052D5C* sp1C;
    s32 sp18;

    if (D_80052D68 != 0) {
        return;
    }
    D_80052D68 = 1;

    for(sp18 = 0; sp18 < D_8004A30C; sp18++) {
        sp1C = &D_80052D5C[sp18];
        if (sp1C->unkC != 1) {

        } else if (sp1C->unk8 & 0x40) {
            func_8000B738(sp18);
        } else {
            alSndpSetSound(D_80052D54, sp1C->unk16);
            alSndpSetVol(D_80052D54, 0);
        }
    }
}

void func_8000BBC4(s16 arg0) {
    struct UnkStruct80052D5C* sp1C;
    s32 sp18;

    if (D_80052D68 == 0) {
        return;
    }
    
    for(sp18 = 0; sp18 < D_8004A30C; sp18++) {
        sp1C = &D_80052D5C[sp18];
        if (sp1C->unkC != 1) {

        } else {
            sp1C->unk8 |= 2;
        }
    }

    D_80052D68 = 0;
    if ((arg0 == 0) || (D_80052D6C > 0.0f)) {
        return;
    }
    D_80052D70 = 0.0f;
    D_80052D76 = 0;
    func_8000678C();
    D_80052D6C = -((f32) D_80052D74 / (f32) arg0);
}

void func_8000BD20(s16 arg0, s16 arg1, f32 arg2) {
    struct UnkStruct80052D5C* sp2C;
    struct UnkStruct80052D88* sp28;
    f32 sp24;
    f32 sp20;
    s16 sp1E;
    s8 sp1D;
    u8 sp1C;

    sp28 = &D_80052D88[arg0];
    sp2C = &D_80052D5C[arg0];
    if (sp2C->unkC != 1) {
        return;
    }
    if (arg2 < 0.0f) {
        arg2 = -arg2;
    }
    sp24 = arg2 - D_80052D8C;
    if (sp24 < 0.0f) {
        sp24 = 0.0f;
    }
    sp1E = 0;
    if (sp24 <= D_80052D90) {
        sp1E = (s16) (s32) (((D_80052D90 - sp24) * 128.0f) / D_80052D90);
        if (sp1E >= 0x80) {
            sp1E = 0x7F;
        }
        sp1D = sp28->unkE;
        if (sp1E < (sp1D & 0x7F)) {
            sp1E = (sp1D & 0x80) ? sp1D & 0x7F : 0;
        }
    }
    func_8000C2D0(arg0, sp1E);
    arg1 += D_80052D9C;
    if (arg1 >= 0x168) {
        arg1 -= 0x168;
    }
    if (arg1 >= 0xB5) {
        arg1 = 0x168 - arg1;
    }
    sp1C = (u8) ((s32) (arg1 << 7) / 180);
    if ((s32) sp1C >= 0x80) {
        sp1C = 0x7F;
    }
    if (D_80052D98 != 0.0f) {
        sp24 = arg2 - D_80052D94;
        if (sp24 < 0.0f) {
            sp24 = 0.0f;
        }
        if (sp24 < D_80052D98) {
            sp1C = (u8) (u32) (64.0f - ((f32) (0x40 - sp1C) * (sp24 / D_80052D98)));
        }
    }
    func_8000C7D4(arg0, sp1C);
    if ((sp28->unk0 + sp28->unk4) != 0.0f) {
        sp24 = sp28->unk0 * D_80052DA4;
        sp20 = sp28->unk4 * D_80052DA4;
        if ((sp28->unk8 >= 0.0f) && (sp28->unk8 < arg2)) {
            sp24 *= -1.0f;
            sp20 *= -1.0f;
            if (sp28->unkC < D_80052D9E) {
                sp28->unkC = (s16) (s32) ((f32) sp28->unkC + (arg2 - sp28->unk8));
                sp20 += -sp20 * 2.0f * ((f32) (D_80052D9E - sp28->unkC) / (f32) D_80052D9E);
            }
        } else {
            sp28->unkC = 0;
        }
        sp24 = (D_80052DA0 - sp24) / (D_80052DA0 - sp20);
        func_8000C48C(arg0, sp24);
    }
    sp28->unk8 = arg2;
}

void func_8000C2D0(s16 arg0, s8 arg1) {
    struct UnkStruct80052D5C* spC;
    struct UnkStruct80052D84* sp8;
    s16 sp6;
    s16 sp4;

    spC = &D_80052D5C[arg0];
    if (!(spC->unk8 & 0x1000)) {
        spC->unk8 |= 2;
        if (spC->unk29 == 2) {
            sp8 = &D_80052D84[arg0];
            sp4 = sp8->u.unk18_as16[1];
            if (sp4 > 0) {
                do {
                    sp4 -= 1;
                    sp6 = ((struct UnkStruct80052D84*)((u32)sp8 + (sp4 * 2)))->unk14;
                    if (D_80052D84[sp6].unkA != arg0) {

                    } else {
                        D_80052D5C[sp6].unk23 = arg1;
                        D_80052D5C[sp6].unk8 |= 2;
                    }
                } while (sp4 > 0);
            }
        }
    }
    spC->unk23 = arg1;
}

void func_8000C48C(s16 arg0, f32 arg1) {
    struct UnkStruct80052D5C* spC;
    struct UnkStruct80052D84* sp8;
    s16 sp6;
    s16 sp4;

    if (arg1 < 0.0f) {
        return;
    }
    spC = &D_80052D5C[arg0];
    if (!(spC->unk8 & 0x1000)) {
        spC->unk8 |= 1;
        if (spC->unk29 == 2) {
            sp8 = &D_80052D84[arg0];
            sp4 = sp8->u.unk18_as16[1];
            if (sp4 > 0) {
                do {
                    sp4 -= 1;
                    sp6 = ((struct UnkStruct80052D84*)((u32)sp8 + (sp4 * 2)))->unk14;
                    if (D_80052D84[sp6].unkA != arg0) {

                    } else {
                        D_80052D5C[sp6].unk1C = arg1;
                        D_80052D5C[sp6].unk8 |= 1;
                    }
                } while (sp4 > 0);
            }
        }
    }
    spC->unk1C = arg1;
}

void func_8000C670(s16 arg0, f32 arg1, f32 arg2) {
    D_80052D88[arg0].unk0 = arg1;
    D_80052D88[arg0].unk4 = (arg2 < 0.0f) ? -arg2 : arg2;
}

void func_8000C6F8(s16 arg0, s8 arg1) {
    struct UnkStruct80052D5C* sp1C;

    sp1C = &D_80052D5C[arg0];
    if (sp1C->unkC != 1) {
        return;
    }
    if (!(sp1C->unk8 & 0x1000)) {
        sp1C->unk8 |= 2;
        if (sp1C->unk29 == 2) {
            func_8000A7B4(arg0, arg1);
        }
    }
    sp1C->unk22 = arg1;
}

void func_8000C7D4(s16 arg0, u8 arg1) {
    struct UnkStruct80052D5C* sp1C;

    sp1C = &D_80052D5C[arg0];
    if (sp1C->unkC != 1) {
        return;
    }
    if ((s32) arg1 >= 0x80) {
        arg1 = 0x7FU;
    }
    if (!(sp1C->unk8 & 0x1000)) {
        sp1C->unk8 |= 4;
        if (sp1C->unk29 == 2) {
            func_8000A8B4(arg0, arg1);
        }
    }
    sp1C->unk25 = arg1;
}

void func_8000C8CC(s16 arg0, s16 arg1) {
    struct UnkStruct80052D5C* sp1C;

    sp1C = &D_80052D5C[arg0];
    if (sp1C->unkC != 1) {
        return;
    }
    if (arg1 >= 0x4B1) {
        arg1 = 0x4B0;
    }
    if (!(sp1C->unk8 & 0x1000)) {
        sp1C->unk8 |= 1;
        if (sp1C->unk29 == 2) {
            func_8000A9B4(arg0, arg1);
        }
    }
    sp1C->unk1A = (u16) arg1;
}

void func_8000C9C4(s16 arg0, s8 arg1) {
    struct UnkStruct80052D5C* sp1C;

    sp1C = &D_80052D5C[arg0];
    if (sp1C->unkC != 1) {
        return;
    }
    if (sp1C->unk8 & 0x10) {
        return;
    }
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (!(sp1C->unk8 & 0x1000)) {
        sp1C->unk8 |= 8;
        if (sp1C->unk29 == 2) {
            func_8000AAB4(arg0, arg1);
        }
    }
    sp1C->unk28 = (u8) arg1;
}

void func_8000CAD8(s8 arg0) {
    D_80052D76 = func_80002D90(arg0);
    D_80052D74 = D_80052D76;
    func_8000678C();
    D_80052D6C = 0.0f;
}

void func_8000CB34(s8 arg0) {
    struct UnkStruct80052D5C* sp4;
    s32 sp0;

    D_80052D7A = arg0;

    for(sp0 = 0; sp0 < D_8004A30C; sp0++) {
        sp4 = &D_80052D5C[sp0];
        if (sp4->unkC != 1) {

        } else {
            if (!(sp4->unk8 & 0x1000) && (sp4->unk22 != D_80052D7A)) {
                sp4->unk8 |= 2;
            }
            sp4->unk22 = D_80052D7A;
        }
    }
}

void func_8000CC30(u8 arg0) {
    struct UnkStruct80052D5C* sp4;
    s32 sp0;

    if (arg0 >= 0x80) {
        arg0 = 0x7F;
    }
    for(sp0 = 0; sp0 < D_8004A30C; sp0++) {
        sp4 = &D_80052D5C[sp0];
        if (sp4->unkC != 1) {

        } else {
            if (!(sp4->unk8 & 0x1000) && (sp4->unk25 != arg0)) {
                sp4->unk8 |= 4;
            }
            sp4->unk25 = arg0;
        }
    }
    D_80052D7B = arg0;
}

void func_8000CD28(s16 arg0) {
    struct UnkStruct80052D5C* sp4;
    s32 sp0;

    if (arg0 >= 0x4B1) {
        arg0 = 0x4B0;
    }
    for(sp0 = 0; sp0 < D_8004A30C; sp0++) {
        sp4 = &D_80052D5C[sp0];
        if (sp4->unkC != 1) {

        } else {
            if (!(sp4->unk8 & 0x1000) && ((s16) sp4->unk1A != arg0)) {
                sp4->unk8 |= 1;
            }
            sp4->unk1A = (u16) arg0;
        }
    }
    D_80052D78 = arg0;
}

void func_8000CE24(s8 arg0) {
    struct UnkStruct80052D5C* sp4;
    s32 sp0;

    if (arg0 < 0) {
        arg0 = 0;
    }
    for(sp0 = 0; sp0 < D_8004A30C; sp0++) {
        sp4 = &D_80052D5C[sp0];
        if (sp4->unkC != 1) {

        } else if (sp4->unk8 & 0x10) {

        } else {
            if (!(sp4->unk8 & 0x1000) && (sp4->unk28 != (arg0 & 0xFF))) {
                sp4->unk8 |= 8;
            }
            sp4->unk28 = (u8) arg0;
        }
    }
    D_80052D7C = (u8) arg0;
}

s8 func_8000CF40(void) {
    return D_80052D7A;
}

u8 func_8000CF60(void) {
    return D_80052D7B;
}

s16 func_8000CF80(void) {
    return D_80052D78;
}

s8 func_8000CFA0(void) {
    return D_80052D7C;
}

void func_8000CFC0(s8 arg0, s8 arg1, s8 arg2, s8 arg3) {
    func_80008360();
    D_80052DB4 = arg0;
    D_80052DB5 = arg1;
    D_80052DAC = (f32) arg2 / 127.0f;
    D_80052DB0 = (f32) arg3 / 127.0f;
}

void func_8000D050(s8 arg0) {
    D_80052D7D = arg0;
}

s32 func_8000D070(s16 arg0) {
    struct UnkInputStruct800069D0 sp28;

    if (D_8004A358 == 0) {
        return -1;
    }
    if ((arg0 >= D_80052D58->bankCount) || (arg0 < 0)) {
        return -1;
    }
    func_800069D0(arg0, &sp28);

    return (sp28.unk8 & 0x80) ? 1 : 0;
}
