#include "common.h"

// extern functions
extern void func_8005BAD0();
extern void thread1_idle(void* arg);
extern void thread6_func(void* arg);
s32 func_8001D9E4(void*);
s32 func_8001E80C();
s32 func_8001ECA0();
s32 func_8001EE64();
s32 func_8001F9DC();

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

struct UnkStruct80340000 {
    char filler0[0x18170];
}; // size = 0x18170

extern struct UnkStruct80340000 D_80340000[2];

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
u32 D_80052D38; // unk

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

void func_8000068C(u32 arg0, void* arg1, s32 arg2) {
    OSIoMesg sp40;
    void* sp3C;
    u8 padding[4];
    s32 sp34;
    s32 sp30;
    u32 sp2C;
    u8* sp28;

    osWritebackDCache(arg1, arg2);
    osInvalICache(arg1, arg2);
    osInvalDCache(arg1, arg2);
    sp2C = arg0;
    sp28 = arg1;
    sp34 = arg2;
    if (sp34 != 0) {
        do {
            if (sp34 < 0x4001) {
                sp30 = sp34;
            } else {
                sp30 = 0x4000;
            }
            osPiStartDma(&sp40, 0, 0, sp2C, sp28, (u32) sp30, &D_8004D728);
            osRecvMesg(&D_8004D728, &sp3C, 1);
            sp34 -= sp30;
            sp2C += sp30;
            sp28 += sp30;
        } while (sp34 != 0);
    }
    osInvalICache(arg1, arg2);
    osInvalDCache(arg1, arg2);
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

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000BE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800010BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800011E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_8000124C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800012B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800013DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800014A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_8000156C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800015D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800016D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800017D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800018D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_8000195C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_8000199C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800019E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/thread6_func.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80001FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80002130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800022A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80002424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800024F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80002574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_8000265C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800026F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_8000281C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80002890.s")
