#include "common.h"

// externs;
extern void thread1_idle(void* arg);
extern void thread6_func(void* arg);
extern u32 D_8004A280;
extern u32 D_8004A384;
extern u32 D_8016524C;
extern void func_8005BAD0();

// .bss start
u8 D_8004D3F0[0x320];
u8 D_8004D710[0x18];
u8 D_8004D728[0x18];
u8 D_8004D740[0x8];
u8 D_8004D748[0x288];
u8 D_8004D9D0[0x8];
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

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_8000068C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_800007F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1050/func_80000964.s")

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
