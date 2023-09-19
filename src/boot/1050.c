#include "common.h"

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
    u32 unk274;
    u32 unk278;
    u32 unk27C;
};

// extern functions
extern void func_8005BAD0();
extern void thread1_idle(void* arg);
s32 func_8001D9E4(void*);
s32 func_8001E80C();
s32 func_8001ECA0();
s32 func_8001EE64();
s32 func_8001F9DC();
s32 func_80016DD4();                                  /* extern */
s32 func_80016E84();                                  /* extern */
s32 func_80016F38(s32, s32, s32);                           /* extern */
s32 func_8001D1F4();                                  /* extern */
s32 func_8001D440();                                  /* extern */
s32 func_8001DFC8();                                  /* extern */
s32 func_8001F9DC();                                  /* extern */
s32 func_8001FAD4();                                  /* extern */
s32 func_80021158();                                  /* extern */
s32 func_80025E28();                                  /* extern */
s32 func_8002F738();                                  /* extern */
s32 func_8005E230(s32);                               /* extern */
s32 func_80083180(s32);                               /* extern */
u32 func_800FE898();                                /* extern */
s32 func_80002130(void*);                             /* extern */
s32 func_800022A0(void*);                             /* extern */
s32 func_80002424(void*);                             /* extern */

// extern symbols
extern u32 D_8004A280;
extern u32 D_8004A384;
extern u32 D_8016524C;
extern OSMesgQueue D_8016E0B8;
extern OSMesg D_8016E0D8;
extern s32 D_80165254;
extern s32 D_8016525C;
extern s32 D_80165264;
extern s32 D_80165284;
extern s32 D_8016E098;
extern s32 D_8016E0A0;

// extern ROM labels
extern u8 D_4DFF0[];
extern u8 D_126CB0[];
extern u8 D_147BB0[];
extern u8 D_14C540[];
extern u8 D_1528A0[];
extern u8 D_153B70[];
extern u8 D_156F90[];
extern u8 D_157520[];
extern u8 D_157A00[];
extern u8 D_15A0F0[];
extern u8 D_15A7D0[];
extern u8 D_15C0D0[];
extern u8 D_160560[];
extern u8 D_167950[];
extern u8 D_16D650[];
extern u8 D_175420[];
extern u8 D_184EE0[];
extern u8 D_189940[];
extern u8 D_194F10[];
extern u8 D_198140[];
extern u8 D_19C610[];
extern u8 D_1A89C0[];
extern u8 D_1ABC60[];
extern u8 D_1AECD0[];
extern u8 D_1B6C30[];
extern u8 D_1B3930[];
extern u8 D_1BC4E0[];
extern u8 D_1C73D0[];
extern u8 D_1C8320[];
extern u8 D_1C90D0[];
extern u8 D_1C9940[];
extern u8 D_1CA830[];
extern u8 D_1CA9B0[];
extern u8 D_1CAA50[];
extern u8 D_1CAB90[];
extern u8 D_1CBF80[];
extern u8 D_1CCCE0[];
extern u8 D_1D01D0[];
extern u8 D_1D1720[];
extern u8 D_1D9110[];
extern u8 D_1E3FF0[];
extern u8 D_1E7490[];
extern u8 D_1ED860[];
extern u8 D_1EF7F0[];
extern u8 D_1F0900[];
extern u8 D_1F6790[];
extern u8 D_1F7E80[];
extern u8 D_1F8D70[];
extern u8 D_1FACD0[];
extern u8 D_1FE7A0[];
extern u8 D_201C00[];
extern u8 D_205F30[];
extern u8 D_20DA60[];
extern u8 D_20F5B0[];
extern u8 D_2193A0[];

extern u8 D_8016E450[];
extern u32 D_801110F0[];
extern u32 D_8010BC30[];

struct UnkStruct80340000 {
    char filler0[0x18170];
}; // size = 0x18170

struct UnkStruct260 {
    u32 unk0;
    OSMesg unk4;
};

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

// .bss start
u8 D_8004D3F0[0x320];
u8 D_8004D710[0x18];
u8 D_8004D728[0x18];
u8 D_8004D740[0x8];
u8 D_8004D748[0x288];
u32 D_8004D9D0;
u8 D_8004D9D8[0x2000];
u8 D_8004F9D8[0x1B0];
u8 gIdleThread[0x1B0];
u8 D_8004FD38[0x1000];
u64 D_80050D38[0x200]; // needs to be same file to match
u64 gIdleThreadStack[0x200];
u32 D_80052D38[2];

// functions
void thread6_func(void* arg);
void func_80001CF0(struct UnkStruct80001CF0* arg0, void* arg1, s32 arg2, u8 arg3, u8 arg4);
void func_80001E78(struct UnkStruct80001CF0* arg0, u32* arg1, s32 arg2);
OSMesgQueue *func_80001FDC(struct UnkStruct80001CF0 *arg0);
void thread4_func(void*);

void main(void* arg) {
    int i;
    u8 padding[0x44];
    u8 *ptr;

    // clears code segment in RAM. Whats the need to do this, when a soft reset does this anyway?
    for (ptr = (u8*)func_8005BAD0; (u32)ptr < (u32)0x80400000; ptr++) {
        *ptr = 0;
    }
    if (D_8004A280 != 0) {
        osTvType = 0;
    }
    osInitialize();
    for (ptr = (u8* )0x80200000; (u32)ptr < (u32)0x80225800; ptr++) {
        *ptr = 0;
    }
    for (ptr = (u8* )0x80225800; (u32)ptr < (u32)0x8024B000; ptr++) {
        *ptr = 0;
    }
    for (i = 0; i < 0x200U; i++) {
        D_80050D38[i] = 0;
        gIdleThreadStack[i] = 0;
    }
    D_8016524C = 0;

    HS_ParseArg(NULL);
    osCreateThread(&gIdleThread, 1, &thread1_idle, arg, (u8*)&gIdleThreadStack + 0x1000, 10);
    osStartThread(&gIdleThread);
}

void thread1_idle(void* arg) {
    osCreatePiManager(150, &D_8004D710, &D_8004D3F0, 200);
    osCreateThread(&D_8004F9D8, 6, thread6_func, arg, (u8*)&D_80050D38 + 0x1000, 0xA);
    if (D_8004A384 == 0) {
        osStartThread(&D_8004F9D8);
    }
    osSetThreadPri(NULL, 0);

    // thread loop
    while(1)
        ;
}

void func_8000068C(void *start, void* func, s32 size) {
    OSIoMesg ioMesg;
    OSMesg dummy;
    u8 padding[4];
    s32 size_loc;
    s32 size_amount;
    u8* start_loc;
    u8* func_loc;

    osWritebackDCache(func, size);
    osInvalICache(func, size);
    osInvalDCache(func, size);
    start_loc = start;
    func_loc = func;
    size_loc = size;
    if (size_loc != 0) {
        do {
            // load in 0x4000 chunks.
            if (size_loc <= 0x4000) {
                size_amount = size_loc;
            } else {
                size_amount = 0x4000;
            }
            osPiStartDma(&ioMesg, 0, 0, start_loc, func_loc, size_amount, &D_8004D728);
            osRecvMesg(&D_8004D728, &dummy, 1);
            size_loc -= size_amount;
            start_loc += size_amount;
            func_loc += size_amount;
        } while (size_loc != 0);
    }
    osInvalICache(func, size);
    osInvalDCache(func, size);
}

void func_800007F4(void) {
    osCreateMesgQueue(&D_8004D728, &D_8004D740, 1);
    osCreateMesgQueue(&D_8016E0B8, &D_8016E0D8, 8);
    if (D_8004A280 == 0) {
        if (osTvType == 1) {
            func_80001CF0(&D_8004D748, (u8*)&D_8004D9D8 + 0x2000, 0xD, 2, 1);
        } else {
            func_80001CF0(&D_8004D748, (u8*)&D_8004D9D8 + 0x2000, 0xD, 0x1E, 1);
        }
    } else {
        func_80001CF0(&D_8004D748, (u8*)&D_8004D9D8 + 0x2000, 0xD, 0x10, 1);
    }
    func_80001E78(&D_8004D748, &D_80052D38, &D_8016E0B8);
    D_8004D9D0 = func_80001FDC(&D_8004D748);
}

// clears compression buffer area
void func_80000924(void) {
    u8* addr = (u8* )0x80380000U;

    do {
        *addr = 0;
    } while ((u32) ++addr < 0x80400000U);
}

void func_80000964(void) {
    s32 sp34 = 0;
    u32 sp30 = 0;
    OSMesg sp2C = 0;
    s32 sp28;
    s16 temp_s0;
    
    // why did you do this twice...?
    sp34 = 0;
    sp30 = 0;
    sp2C = 0;

    D_80165254 = 1;
    D_8016525C = 1;
    D_80165284 = 0;
    D_80165264 = 0;
    sp28 = -1;
    if (D_8016524C == 1) {
        sp30 = 2;
        osViSetYScale(1.0f);
        osViBlack(1U);
        func_8001F9DC();
        func_8001ECA0();
    }
    while (sp28 != 0) {
        osRecvMesg(&D_8016E0B8, &sp2C, 1);
        switch (*(s16 *)sp2C) {
        case 1:
            if (D_8016E0A0 != 0) {
                func_8001E80C();
            }
            if ((sp30 < 2) && (D_8016E098 != 0)) {
                func_8001D9E4(&D_80340000[sp34]);
                sp30 += 1;
                sp34 ^= 1;
            }
            if ((D_80165264 != 0) && (sp28 == -1)) {
                sp28 = 0x10;
                func_8001ECA0();
                sp30 += 2;
            }
            if (sp28 > 0) {
                sp28 -= 1;
            }
            break;
        case 2:
            sp30 -= 1;
            break;
        case 4:
            sp30 += 2;
            osViSetYScale(1.0f);
            osViBlack(1U);
            func_8001F9DC();
            func_8001ECA0();
            break;
        }
    }
    func_8001EE64();
}

void func_80000BE8(void) {
    func_8000068C(&D_4DFF0, &func_8005BAD0, (u32)&D_126CB0 - (u32)&D_4DFF0);
}

void func_80000C2C(void) {
    func_8000068C(&D_147BB0, 0x80320000, (u32)&D_14C540 - (u32)&D_147BB0);
    func_8000068C(&D_14C540, 0x80330000, (u32)&D_1528A0 - (u32)&D_14C540);
}

void func_80000C8C(void) {
    func_8000068C(&D_147BB0, 0x80320000, (u32)&D_14C540 - (u32)&D_147BB0);
    func_8000068C(&D_1528A0, 0x80330000, (u32)&D_153B70 - (u32)&D_1528A0);
}

void func_80000CEC(void) {
    func_8000068C(&D_147BB0, 0x80320000, (u32)&D_14C540 - (u32)&D_147BB0);
    func_8000068C(&D_153B70, 0x80330000, (u32)&D_156F90 - (u32)&D_153B70);
}

void func_80000D4C(void) {
    func_8000068C(&D_147BB0, 0x80320000, (u32)&D_14C540 - (u32)&D_147BB0);
    func_8000068C(&D_156F90, 0x80330000, (u32)&D_157520 - (u32)&D_156F90);
}

void func_80000DAC(void) {
    func_8000068C(&D_147BB0, 0x80320000, (u32)&D_14C540 - (u32)&D_147BB0);
    func_8000068C(&D_157520, 0x80330000, (u32)&D_157A00 - (u32)&D_157520);
}

void func_80000E0C(void) {
    func_8000068C(&D_147BB0, 0x80320000, (u32)&D_14C540 - (u32)&D_147BB0);
    func_8000068C(&D_157A00, 0x80330000, (u32)&D_15A0F0 - (u32)&D_157A00);
}

void func_80000E6C(void) {
    func_8000068C(&D_147BB0, 0x80320000, (u32)&D_14C540 - (u32)&D_147BB0);
    func_8000068C(&D_15A0F0, 0x80330000, (u32)&D_15A7D0 - (u32)&D_15A0F0);
}

void func_80000ECC(void) {
    func_8000068C(&D_147BB0, 0x80320000, (u32)&D_14C540 - (u32)&D_147BB0);
    func_8000068C(&D_15A7D0, 0x80330000, (u32)&D_15C0D0 - (u32)&D_15A7D0);
}

void func_80000F2C(void) {
    func_8000068C(&D_147BB0, 0x80320000, (u32)&D_14C540 - (u32)&D_147BB0);
    func_8000068C(&D_15C0D0, 0x80330000, (u32)&D_160560 - (u32)&D_15C0D0);
}

void func_80000F8C(s32 arg0) {
    s32 sp1C = (D_801110F0[arg0] + 0x7FCC6000); // wut

    func_8000068C((u32)&D_20F5B0 + sp1C, 0x8033A000, 0x4000);
}

void func_80000FF4(s32 arg0) {
    s32 sp1C = (D_8010BC30[arg0] + 0x7FD00000);

    func_8000068C((u32)&D_2193A0 + sp1C, &D_8016E450, 0x800);
}

void func_80001058(void) {
    func_8000068C(&D_160560, 0x80330000, (u32)&D_167950 - (u32)&D_160560);
    func_8000068C(&D_1C73D0, 0x8032E000, (u32)&D_1C8320 - (u32)&D_1C73D0);
}

void func_800010BC(void) {
    func_8000068C(&D_167950, 0x80330000, (u32)&D_16D650 - (u32)&D_167950);
    func_8000068C(&D_1C8320, 0x8032E000, (u32)&D_1C90D0 - (u32)&D_1C8320);
}

void func_80001120(void) {
    func_8000068C(&D_16D650, 0x80330000, (u32)&D_175420 - (u32)&D_16D650);
    func_8000068C(&D_1C90D0, 0x8032E000, (u32)&D_1C9940 - (u32)&D_1C90D0);
}

void func_80001184(void) {
    func_8000068C(&D_175420, 0x80330000, (u32)&D_184EE0 - (u32)&D_175420);
    func_8000068C(&D_1C9940, 0x8032E000, (u32)&D_1CA830 - (u32)&D_1C9940);
}

void func_800011E8(void) {
    func_8000068C(&D_189940, 0x80330000, (u32)&D_194F10 - (u32)&D_189940);
    func_8000068C(&D_1CA830, 0x8032E000, (u32)&D_1CA9B0 - (u32)&D_1CA830);
}

void func_8000124C(void) {
    func_8000068C(&D_194F10, 0x80330000, (u32)&D_198140 - (u32)&D_194F10);
    func_8000068C(&D_1CA9B0, 0x8032E000, (u32)&D_1CAA50 - (u32)&D_1CA9B0);
}

void func_800012B0(void) {
    func_8000068C(&D_198140, 0x80330000, (u32)&D_19C610 - (u32)&D_198140);
    func_8000068C(&D_1CAA50, 0x8032E000, (u32)&D_1CAB90 - (u32)&D_1CAA50);
}

void func_80001314(void) {
    func_8000068C(&D_19C610, 0x80330000, (u32)&D_1A89C0 - (u32)&D_19C610);
    func_8000068C(&D_1CAB90, 0x8032E000, (u32)&D_1CBF80 - (u32)&D_1CAB90);
}

void func_80001378(void) {
    func_8000068C(&D_1A89C0, 0x80330000, (u32)&D_1ABC60 - (u32)&D_1A89C0);
    func_8000068C(&D_1C73D0, 0x8032E000, (u32)&D_1C8320 - (u32)&D_1C73D0);
}

void func_800013DC(void) {
    func_8000068C(&D_1ABC60, 0x80330000, (u32)&D_1AECD0 - (u32)&D_1ABC60);
    func_8000068C(&D_1C8320, 0x8032E000, (u32)&D_1C90D0 - (u32)&D_1C8320);
}

void func_80001440(void) {
    func_8000068C(&D_1AECD0, 0x80330000, (u32)&D_1B3930 - (u32)&D_1AECD0);
    func_8000068C(&D_1C9940, 0x8032E000, (u32)&D_1CA830 - (u32)&D_1C9940);
}

void func_800014A4(void) {
    func_8000068C(&D_1B3930, 0x80330000, (u32)&D_1B6C30 - (u32)&D_1B3930);
    func_8000068C(&D_1C90D0, 0x8032E000, (u32)&D_1C9940 - (u32)&D_1C90D0);
}

void func_80001508(void) {
    func_8000068C(&D_1B6C30, 0x80330000, (u32)&D_1BC4E0 - (u32)&D_1B6C30);
    func_8000068C(&D_1C9940, 0x8032E000, (u32)&D_1CA830 - (u32)&D_1C9940);
}

void func_8000156C(void) {
    func_8000068C(&D_1BC4E0, 0x80330000, (u32)&D_1C73D0 - (u32)&D_1BC4E0);
    func_8000068C(&D_1CBF80, 0x8032E000, (u32)&D_1CCCE0 - (u32)&D_1CBF80);
}

void func_800015D0(void) {
    func_8000068C(&D_184EE0, 0x80330000, (u32)&D_189940 - (u32)&D_184EE0);
}

void func_80001610(void) {
    func_8000068C(&D_1CCCE0, 0x80330000, (u32)&D_1D01D0 - (u32)&D_1CCCE0);
}

void func_80001650(void) {
    func_8000068C(&D_1D01D0, 0x80330000, (u32)&D_1D1720 - (u32)&D_1D01D0);
}

void func_80001690(void) {
    func_8000068C(&D_1D1720, 0x80330000, (u32)&D_1D9110 - (u32)&D_1D1720);
}

void func_800016D0(void) {
    func_8000068C(&D_1D9110, 0x80330000, (u32)&D_1E3FF0 - (u32)&D_1D9110);
}

void func_80001710(void) {
    func_8000068C(&D_1E3FF0, 0x80330000, (u32)&D_1E7490 - (u32)&D_1E3FF0);
}

void func_80001750(void) {
    func_8000068C(&D_1E7490, 0x80330000, (u32)&D_1ED860 - (u32)&D_1E7490);
}

void func_80001790(void) {
    func_8000068C(&D_1ED860, 0x80330000, (u32)&D_1EF7F0 - (u32)&D_1ED860);
}

void func_800017D0(void) {
    func_8000068C(&D_1EF7F0, 0x80330000, (u32)&D_1F0900 - (u32)&D_1EF7F0);
}

void func_80001810(void) {
    func_8000068C(&D_1F0900, 0x80330000, (u32)&D_1F6790 - (u32)&D_1F0900);
}

void func_80001850(void) {
    func_8000068C(&D_1F6790, 0x8033C000, (u32)&D_1F7E80 - (u32)&D_1F6790);
}

void func_80001894(void) {
    func_8000068C(&D_1F7E80, 0x80338000, (u32)&D_1F8D70 - (u32)&D_1F7E80);
}

void func_800018D8(void) {
    func_8000068C(&D_1F8D70, 0x80330000, (u32)&D_1FACD0 - (u32)&D_1F8D70);
}

void func_80001918(void) {
    func_8000068C(&D_1FACD0, 0x8033A000, (u32)&D_1FE7A0 - (u32)&D_1FACD0);
}

void func_8000195C(void) {
    func_8000068C(&D_1FE7A0, 0x80330000, (u32)&D_201C00 - (u32)&D_1FE7A0);
}

void func_8000199C(void) {
    func_8000068C(&D_201C00, 0x8033A000, (u32)&D_205F30 - (u32)&D_201C00);
}

void func_800019E0(void) {
    func_8000068C(&D_205F30, 0x80330000, (u32)&D_20DA60 - (u32)&D_205F30);
}

void func_80001A20(void) {
    func_8000068C(&D_20DA60, 0x80338000, (u32)&D_20F5B0 - (u32)&D_20DA60);
}

void func_80001A64(void) {
    
}

void thread6_func(void* arg) {
    u32 sp1C;

    func_80000924();
    func_800007F4();
    func_80000BE8();
    func_8001D440();
    func_8001DFC8();
    if (D_8004A280 != 0) {
        osViSetYScale(0.8333f);
        D_8004A770[16].fldRegs[0].vStart = 0x250270;
        D_8004A770[16].fldRegs[1].vStart = 0x250270;
        osViClock = 0x02F5B2D2;
    }
    func_80025E28();
    func_8001FAD4();
    func_8001F9DC();
    func_80016DD4();
    func_80016E84();
    func_8001D1F4();
    D_8016E092 = 0x1234;
    D_8016527C = 2;
    D_8016E134 = 0;
    D_8016E428 = 0;
    D_801765EC = 2;
    D_8016E3E4 = 0;
    D_8016E3F7 = 0;
    D_8016E404 = 0;
    D_8016E414 = 0;
    D_8016E41C = 0;
    D_8016E3EC = 0;
    D_8016E3EE = 0;
    D_8016E3F4 = 0;
    D_8016E424 = 0;
    D_8016E3FC = 0;
    D_8016E40C = 0;
    func_80083180(0);

    // thread loop
    while(1) {
        D_8016E3DC = 0;
        D_8016E134 = 0;
        sp1C = func_800FE898();
        switch (sp1C) {
            case 0:
                D_8016E428 = 0;
                D_8016E3DC = 0;
                func_80083180(D_80134228);
                break;
            case 1:
                D_8016E3DC = 0;
                func_80083180(0x64);
                break;
            case 2:
                D_8016E3DC = 1;
                func_80083180(0x64);
                break;
            case 3: 
                break;
            case 4: 
                break;
            case 5:
                func_80016F38(-1, -1, 0);
                func_8002F738();
                break;
            case 8:
                func_8005E230(D_80134224);
                break;
            case 9:
                func_80021158();
                break;
            default:
                break;
        }
    }
}

void func_80001CF0(struct UnkStruct80001CF0* arg0, void* arg1, s32 arg2, u8 arg3, u8 arg4) {
    arg0->unk274 = 0;
    arg0->unk278 = 0;
    arg0->unk260 = 0;
    arg0->unk27C = 0;
    arg0->unk264 = 0;
    arg0->unk268 = 0;
    arg0->unk26C = 0;
    arg0->unk270 = 0;
    arg0->unk0 = 1;
    arg0->unk20 = 4;
    osCreateMesgQueue(&arg0->unk40, &arg0->unk58, 8);
    osCreateMesgQueue(&arg0->unk78, &arg0->unk90, 8);
    osCreateViManager(0xFE);
    osViSetMode(&D_8004A770[arg3]);
    osViBlack(1U);
    osSetEventMesg(4U, &arg0->unk40, (void* )0x29B);
    osSetEventMesg(9U, &arg0->unk40, (void* )0x29C);
    osSetEventMesg(0xEU, &arg0->unk40, (void* )0x29D);
    osViSetEvent(&arg0->unk40, (void* )0x29A, (u32) arg4);
    osCreateThread(&arg0->unkB0, 4, thread4_func, arg0, arg1, arg2);
    osStartThread(&arg0->unkB0);
}

void func_80001E78(struct UnkStruct80001CF0* arg0, u32* arg1, s32 arg2) {
    u32 mask = osSetIntMask(1);

    arg1[1] = arg2;
    arg1[0] = (void* ) arg0->unk260;
    arg0->unk260 = arg1;
    osSetIntMask(mask);
}

void func_80001EF0(struct UnkStruct80001CF0* arg0, u32** arg1) {
    u32* sp24;
    u32* sp20;
    u32 sp1C;

    sp24 = arg0->unk260;
    sp20 = NULL;
    sp1C = osSetIntMask(1U);
    while (sp24 != NULL) {
        if ((u32)sp24 == (u32)arg1) {
            if (sp20 != NULL) {
                *sp20 = *arg1;
            } else {
                arg0->unk260 = (u32* ) *arg1;
            }
            break;
        }
        sp20 = sp24;
        sp24 = *sp24;
    }
    osSetIntMask(sp1C);
}

OSMesgQueue *func_80001FDC(struct UnkStruct80001CF0 *arg0) {
    return &arg0->unk78;
}

void thread4_func(void* arg) {
    OSMesg mesg;
    struct UnkStruct80001CF0* sp28 = arg;
    struct UnkStruct260* sp24;

    // thread loop
    while(1) {
        osRecvMesg(&sp28->unk40, &mesg, 1);
        switch ((s32)mesg) {                                 /* irregular */
        case 0x29A:
            func_80002130(sp28);
            break;
        case 0x29B:
            func_800022A0(sp28);
            break;
        case 0x29C:
            func_80002424(sp28);
            break;
        case 0x29D: {
            if((sp24 = sp28->unk260) != 0) {
                do {
                    osSendMesg(sp24->unk4, &sp28->unk20, 0);
                } while ((sp24 = sp24->unk0) != 0);
            }
            D_8016524C = 1;
            osViSetYScale(1.0f);
            osViBlack(1U);
            break;
        }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80002130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800022A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80002424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800024F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80002574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_8000265C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800026F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_8000281C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80002890.s")
