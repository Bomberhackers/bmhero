#include <ultra64.h>

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
    char filler0[0x8];
    u32 unk8;
    u32 unkC;
    u32 unk10;
    char filler14[0x2];
    s16 unk16;
    u16 unk18;
    u16 unk1A;
    f32 unk1C;
    char filler20[0x2];
    u8 unk22;
    char filler23[0x1];
    u8 unk24;
    u8 unk25;
    u8 unk26;
    char filler27[0x1];
    u8 unk28;
    u8 unk29;
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

struct UnkStruct80052ED8* sp3C;

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

f32 _depth2Cents(u8 depth);

s32 func_800038A4(s32);                             /* extern */
s32 func_80005B14();                                /* extern */
s32 func_8000D120(s32*, s32*);                          /* extern */
ALCSPlayer* func_8000D84C(u32);                     /* extern */
s32 func_800060AC(u32);                             /* extern */
s32 func_8000616C();                                /* extern */
s32 func_80006284(ALCSPlayer*);                     /* extern */
s32 func_800064BC(ALCSPlayer*);                     /* extern */
s32 func_800065B8(ALCSPlayer*);                     /* extern */
s16 func_80006DF4(s32);                             /* extern */
s32 func_800080D8();                                /* extern */
s32 func_800081B0();                                /* extern */

extern s32 D_8004A2A0;
extern s32 D_8004A2A4;
extern s32 D_8004A2A8;
extern s32 D_8004A2AC;
extern u8 D_8004A2C0;
extern s32* D_8004A2C4;
extern u16 D_8004A2C8;
extern s32 D_8004A2CC;
extern s32 D_8004A2D0;
extern s32 D_8004A2D4;
extern s32 D_8004A2D8;
extern s32 D_8004A2DC;
extern s32 D_8004A2E0;
extern s32 D_8004A2E4;
extern ALSeqpConfig D_8004A2E8;
extern s32 D_8004A304;
extern s32 D_8004A308;
extern s32 D_8004A30C;
extern s32 D_8004A310;
extern s32 D_8004A318;
extern u8* D_8004A340;
extern s32 D_8004A344;
extern s32 D_8004A348;
extern s32 D_8004A34C;
extern u32 D_8004A350;
extern u32 D_8004A354;
extern s32 D_8004A358;
extern s16 D_8004A364;
extern f64 D_8004BAD8;
extern ALHeap D_80052D40;
extern s32 D_80052D50;
extern ALCSPlayer* D_80052D54;
extern struct UnkStruct80052D58* D_80052D58;
extern struct UnkStruct80052D5C *D_80052D5C;
extern s32 D_80052D60;
extern s32 D_80052D64;
extern s32 D_80052D68;
extern f32 D_80052D6C;
extern s16 D_80052D74;
extern s16 D_80052D76;
extern s16 D_80052D78;
extern s8 D_80052D7A;
extern u8 D_80052D7B;
extern u8 D_80052D7C;
extern s32 D_80052D80;
extern u8 D_80052DB7;
extern void* D_80052DB8;
extern OSMesgQueue D_80052E80;
extern u8* D_80052E98;
extern s32 D_80052E9C;
extern ALBankFile* D_80052EA0;
extern ALSeqPlayer* D_80052EA4;
extern ALCSPlayer* D_80052EA8;
extern ALCSPlayer* D_80052EAC;
extern ALSeqFile* D_80052EB0;
extern struct UnkStruct80052EB4* D_80052EB4;
extern s32 D_80052EB8;
extern s32 D_80052EBC;
extern s32 D_80052EC0;
extern f32 D_80052EC4;
extern f32 D_80052EC8;
extern s16 D_80052ECC;
extern s16 D_80052ECE;
extern s16 D_80052ED0;
extern s16 D_80052ED2;
extern oscData  *freeOscStateList;
extern struct UnkStruct80052ED8 D_80052ED8[];

// functions
s32 func_80003304(void);
void func_80004284(void);

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
    D_8004A2A4 = arg0->unk0;
    D_8004A2A8 = arg0->unk4;
    D_8004A2AC = arg0->unk8;
    D_8004A2C0 = arg0->unk10;
    D_8004A2C4 = arg0->unk14;
    D_8004A2E8.maxVoices = arg0->unk18;
    D_8004A2E8.maxEvents = arg0->unk1C;
    D_8004A304 = arg0->unk20;
    D_8004A308 = arg0->unk24;
    D_8004A310 = arg0->unk28;
    D_8004A2C8 = arg0->unk2C;
    D_8004A2CC = arg0->unk30;
    D_8004A2D0 = arg0->unk34;
    D_8004A2D4 = arg0->unk38;
    D_8004A2A0 = arg0->unkC;
}

void func_80003058(struct UnkInputStruct80002F94* arg0) {
    arg0->unk0 = D_8004A2A4;
    arg0->unk4 = D_8004A2A8;
    arg0->unk8 = D_8004A2AC;
    arg0->unk10 = D_8004A2C0;
    arg0->unk14 = D_8004A2C4;
    arg0->unk18 = D_8004A2E8.maxVoices;
    arg0->unk1C = D_8004A2E8.maxEvents;
    arg0->unk20 = D_8004A304;
    arg0->unk24 = D_8004A308;
    arg0->unk28 = D_8004A310;
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
    alCSeqNew((ALCSeq* ) D_80052EAC, (u8* ) D_80052EA8);
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
        alBnkfNew((ALBankFile* ) D_80052EA0, (u8* ) sp2C);
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

extern f32 D_8004BAE0; // .rodata. TODO: Move

f32 _depth2Cents(u8 depth)
{
    f32     x = D_8004BAE0;
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
    ALCSPlayer* sp38;
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
    alSndpNew((ALSndPlayer* ) D_80052D54, (ALSndpConfig* ) &D_8004A30C);
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
        sp3C->unk18 = (u16) D_80052D78;
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
    switch (D_80052D58->unk0) {                              /* irregular */
    case 0x5431:
        if (D_8004A358 == 0) {
            return 0;
        }
        sp2C = (D_80052D58->unk2 * 8) + 4;
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
        sp2C = (D_80052D58->unk2 * 8) + 4;
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
        sp38->node.clientData = (u32)D_8004A354 + (u32)sp38->node.clientData;
        sp38->node.callTime = (u32)D_8004A354 + (u32)sp38->node.callTime;
        sp30 = func_80006284(sp38);
        if (sp30 != 0) {
            return sp30 - 1;
        }
        if (func_800065B8(sp38) != 0) {
            return 1;
        }
        if (D_80052D58->unk0 == 0x5432) {
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
        D_80052D58->unk2 = func_80006DF4(D_80052D50);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_800060AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000616C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80006284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_800064BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_800065B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000678C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80006830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_800069D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80006DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80006EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80006FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80007140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80007690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80007890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80007BC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_800080D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_800081B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000826C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80008360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_800083EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80008744.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80008B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80008CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80009AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80009B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_80009BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000A534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000A724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000A7B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000A8B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000A9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000AAB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000ABB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000ABEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000AC1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000AF40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000B1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000B25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000B390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000B404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000B4CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000B4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000B598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000B5DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000B738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000BA54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000BAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000BBC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000BD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000C2D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000C48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000C670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000C6F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000C7D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000C8CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000C9C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000CAD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000CB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000CC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000CD28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000CE24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000CF40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000CF60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000CF80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000CFA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000CFC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000D050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/38D0/func_8000D070.s")
