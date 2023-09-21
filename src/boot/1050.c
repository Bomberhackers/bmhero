#include <ultra64.h>

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
void thread1_idle(void* arg);
void thread6_func(void* arg);
void func_80001CF0(struct UnkStruct80001CF0* arg0, void* arg1, s32 arg2, u8 arg3, u8 arg4);
void func_80001E78(struct UnkStruct80001CF0* arg0, u32* arg1, s32 arg2);
OSMesgQueue *func_80001FDC(struct UnkStruct80001CF0 *arg0);
void thread4_func(void*);
void func_80002130(struct UnkStruct80001CF0* arg0);
void func_800022A0(struct UnkStruct80001CF0* arg0);
void func_80002424(struct UnkStruct80001CF0* arg0);
s32 func_80002574(s32 arg0, struct UnkStruct80002424* arg1);
void func_8000265C(struct UnkStruct80001CF0* arg0, struct UnkStruct8000265C* arg1);
void func_800026F4(struct UnkStruct80001CF0* arg0, struct UnkStruct800026F4_Arg1* arg1, struct UnkStruct800026F4_Arg2* arg2);
void func_8000281C(struct UnkStruct80001CF0* arg0);

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

/**
 * Load a given ROM area to a specific virtual address.
 */
void load_from_rom_to_addr(void *start, void* addr, s32 size) {
    OSIoMesg ioMesg;
    OSMesg dummy;
    u8 padding[4];
    s32 size_loc;
    s32 size_amount;
    u8* start_loc;
    u8* addr_loc;

    osWritebackDCache(addr, size);
    osInvalICache(addr, size);
    osInvalDCache(addr, size);
    start_loc = start;
    addr_loc = addr;
    size_loc = size;
    if (size_loc != 0) {
        do {
            // load in 0x4000 chunks.
            if (size_loc <= 0x4000) {
                size_amount = size_loc;
            } else {
                size_amount = 0x4000;
            }
            osPiStartDma(&ioMesg, 0, 0, start_loc, addr_loc, size_amount, &D_8004D728);
            osRecvMesg(&D_8004D728, &dummy, 1);
            size_loc -= size_amount;
            start_loc += size_amount;
            addr_loc += size_amount;
        } while (size_loc != 0);
    }
    osInvalICache(addr, size);
    osInvalDCache(addr, size);
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

/**
 * Resets the compression buffer area.
 */
void clear_compression_buffer(void) {
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

/**
 * Load game code section to VRAM.
 */
void load_game_section(void) {
    load_from_rom_to_addr(&game_ROM_START, &game_TEXT_START, (u32)&game_ROM_END - (u32)&game_ROM_START);
}

void func_80000C2C(void) {
    load_from_rom_to_addr(&unk_bin_1_ROM_START, (void*)0x80320000, (u32)&unk_bin_1_ROM_END - (u32)&unk_bin_1_ROM_START);
    load_from_rom_to_addr(&unk_bin_2_ROM_START, (void*)0x80330000, (u32)&unk_bin_2_ROM_END - (u32)&unk_bin_2_ROM_START);
}

void func_80000C8C(void) {
    load_from_rom_to_addr(&unk_bin_1_ROM_START, (void*)0x80320000, (u32)&unk_bin_1_ROM_END - (u32)&unk_bin_1_ROM_START);
    load_from_rom_to_addr(&unk_bin_3_ROM_START, (void*)0x80330000, (u32)&unk_bin_3_ROM_END - (u32)&unk_bin_3_ROM_START);
}

void func_80000CEC(void) {
    load_from_rom_to_addr(&unk_bin_1_ROM_START, (void*)0x80320000, (u32)&unk_bin_1_ROM_END - (u32)&unk_bin_1_ROM_START);
    load_from_rom_to_addr(&unk_bin_4_ROM_START, (void*)0x80330000, (u32)&unk_bin_4_ROM_END - (u32)&unk_bin_4_ROM_START);
}

void func_80000D4C(void) {
    load_from_rom_to_addr(&unk_bin_1_ROM_START, (void*)0x80320000, (u32)&unk_bin_1_ROM_END - (u32)&unk_bin_1_ROM_START);
    load_from_rom_to_addr(&unk_bin_5_ROM_START, (void*)0x80330000, (u32)&unk_bin_5_ROM_END - (u32)&unk_bin_5_ROM_START);
}

void func_80000DAC(void) {
    load_from_rom_to_addr(&unk_bin_1_ROM_START, (void*)0x80320000, (u32)&unk_bin_1_ROM_END - (u32)&unk_bin_1_ROM_START);
    load_from_rom_to_addr(&unk_bin_6_ROM_START, (void*)0x80330000, (u32)&unk_bin_6_ROM_END - (u32)&unk_bin_6_ROM_START);
}

void func_80000E0C(void) {
    load_from_rom_to_addr(&unk_bin_1_ROM_START, (void*)0x80320000, (u32)&unk_bin_1_ROM_END - (u32)&unk_bin_1_ROM_START);
    load_from_rom_to_addr(&unk_bin_7_ROM_START, (void*)0x80330000, (u32)&unk_bin_7_ROM_END - (u32)&unk_bin_7_ROM_START);
}

void func_80000E6C(void) {
    load_from_rom_to_addr(&unk_bin_1_ROM_START, (void*)0x80320000, (u32)&unk_bin_1_ROM_END - (u32)&unk_bin_1_ROM_START);
    load_from_rom_to_addr(&unk_bin_8_ROM_START, (void*)0x80330000, (u32)&unk_bin_8_ROM_END - (u32)&unk_bin_8_ROM_START);
}

void func_80000ECC(void) {
    load_from_rom_to_addr(&unk_bin_1_ROM_START, (void*)0x80320000, (u32)&unk_bin_1_ROM_END - (u32)&unk_bin_1_ROM_START);
    load_from_rom_to_addr(&unk_bin_9_ROM_START, (void*)0x80330000, (u32)&unk_bin_9_ROM_END - (u32)&unk_bin_9_ROM_START);
}

void func_80000F2C(void) {
    load_from_rom_to_addr(&unk_bin_1_ROM_START,  (void*)0x80320000, (u32)&unk_bin_1_ROM_END  - (u32)&unk_bin_1_ROM_START);
    load_from_rom_to_addr(&unk_bin_10_ROM_START, (void*)0x80330000, (u32)&unk_bin_10_ROM_END - (u32)&unk_bin_10_ROM_START);
}

void func_80000F8C(s32 arg0) {
    s32 sp1C = (D_801110F0[arg0] + 0x7FCC6000); // wut

    load_from_rom_to_addr((u32)&D_20F5B0 + sp1C, 0x8033A000, 0x4000);
}

void func_80000FF4(s32 arg0) {
    s32 sp1C = (D_8010BC30[arg0] + 0x7FD00000);

    load_from_rom_to_addr((u32)&D_2193A0 + sp1C, &D_8016E450, 0x800);
}

void func_80001058(void) {
    load_from_rom_to_addr(&unk_bin_11_ROM_START, (void*)0x80330000, (u32)&unk_bin_11_ROM_END - (u32)&unk_bin_11_ROM_START);
    load_from_rom_to_addr(&unk_bin_26_ROM_START, (void*)0x8032E000, (u32)&unk_bin_26_ROM_END - (u32)&unk_bin_26_ROM_START);
}

void func_800010BC(void) {
    load_from_rom_to_addr(&unk_bin_12_ROM_START, (void*)0x80330000, (u32)&unk_bin_12_ROM_END - (u32)&unk_bin_12_ROM_START);
    load_from_rom_to_addr(&unk_bin_27_ROM_START, (void*)0x8032E000, (u32)&unk_bin_27_ROM_END - (u32)&unk_bin_27_ROM_START);
}

void func_80001120(void) {
    load_from_rom_to_addr(&unk_bin_13_ROM_START, (void*)0x80330000, (u32)&unk_bin_13_ROM_END - (u32)&unk_bin_13_ROM_START);
    load_from_rom_to_addr(&unk_bin_28_ROM_START, (void*)0x8032E000, (u32)&unk_bin_28_ROM_END - (u32)&unk_bin_28_ROM_START);
}

void func_80001184(void) {
    load_from_rom_to_addr(&unk_bin_14_ROM_START, (void*)0x80330000, (u32)&unk_bin_14_ROM_END - (u32)&unk_bin_14_ROM_START);
    load_from_rom_to_addr(&unk_bin_29_ROM_START, (void*)0x8032E000, (u32)&unk_bin_29_ROM_END - (u32)&unk_bin_29_ROM_START);
}

void func_800011E8(void) {
    load_from_rom_to_addr(&unk_bin_16_ROM_START, (void*)0x80330000, (u32)&unk_bin_16_ROM_END - (u32)&unk_bin_16_ROM_START);
    load_from_rom_to_addr(&unk_bin_30_ROM_START, (void*)0x8032E000, (u32)&unk_bin_30_ROM_END - (u32)&unk_bin_30_ROM_START);
}

void func_8000124C(void) {
    load_from_rom_to_addr(&unk_bin_17_ROM_START, (void*)0x80330000, (u32)&unk_bin_17_ROM_END - (u32)&unk_bin_17_ROM_START);
    load_from_rom_to_addr(&unk_bin_31_ROM_START, (void*)0x8032E000, (u32)&unk_bin_31_ROM_END - (u32)&unk_bin_31_ROM_START);
}

void func_800012B0(void) {
    load_from_rom_to_addr(&unk_bin_18_ROM_START, (void*)0x80330000, (u32)&unk_bin_18_ROM_END - (u32)&unk_bin_18_ROM_START);
    load_from_rom_to_addr(&unk_bin_32_ROM_START, (void*)0x8032E000, (u32)&unk_bin_32_ROM_END - (u32)&unk_bin_32_ROM_START);
}

void func_80001314(void) {
    load_from_rom_to_addr(&unk_bin_19_ROM_START, (void*)0x80330000, (u32)&unk_bin_19_ROM_END - (u32)&unk_bin_19_ROM_START);
    load_from_rom_to_addr(&unk_bin_33_ROM_START, (void*)0x8032E000, (u32)&unk_bin_33_ROM_END - (u32)&unk_bin_33_ROM_START);
}

void func_80001378(void) {
    load_from_rom_to_addr(&unk_bin_20_ROM_START, (void*)0x80330000, (u32)&unk_bin_20_ROM_END - (u32)&unk_bin_20_ROM_START);
    load_from_rom_to_addr(&unk_bin_26_ROM_START, (void*)0x8032E000, (u32)&unk_bin_26_ROM_END - (u32)&unk_bin_26_ROM_START);
}

void func_800013DC(void) {
    load_from_rom_to_addr(&unk_bin_21_ROM_START, (void*)0x80330000, (u32)&unk_bin_21_ROM_END - (u32)&unk_bin_21_ROM_START);
    load_from_rom_to_addr(&unk_bin_27_ROM_START, (void*)0x8032E000, (u32)&unk_bin_27_ROM_END - (u32)&unk_bin_27_ROM_START);
}

void func_80001440(void) {
    load_from_rom_to_addr(&unk_bin_22_ROM_START, (void*)0x80330000, (u32)&unk_bin_22_ROM_END - (u32)&unk_bin_22_ROM_START);
    load_from_rom_to_addr(&unk_bin_29_ROM_START, (void*)0x8032E000, (u32)&unk_bin_29_ROM_END - (u32)&unk_bin_29_ROM_START);
}

void func_800014A4(void) {
    load_from_rom_to_addr(&unk_bin_23_ROM_START, (void*)0x80330000, (u32)&unk_bin_23_ROM_END - (u32)&unk_bin_23_ROM_START);
    load_from_rom_to_addr(&unk_bin_28_ROM_START, (void*)0x8032E000, (u32)&unk_bin_28_ROM_END - (u32)&unk_bin_28_ROM_START);
}

void func_80001508(void) {
    load_from_rom_to_addr(&unk_bin_24_ROM_START, (void*)0x80330000, (u32)&unk_bin_24_ROM_END - (u32)&unk_bin_24_ROM_START);
    load_from_rom_to_addr(&unk_bin_29_ROM_START, (void*)0x8032E000, (u32)&unk_bin_29_ROM_END - (u32)&unk_bin_29_ROM_START);
}

void func_8000156C(void) {
    load_from_rom_to_addr(&unk_bin_25_ROM_START, (void*)0x80330000, (u32)&unk_bin_25_ROM_END - (u32)&unk_bin_25_ROM_START);
    load_from_rom_to_addr(&unk_bin_34_ROM_START, (void*)0x8032E000, (u32)&unk_bin_34_ROM_END - (u32)&unk_bin_34_ROM_START);
}

void func_800015D0(void) {
    load_from_rom_to_addr(&unk_bin_15_ROM_START, (void*)0x80330000, (u32)&unk_bin_15_ROM_END - (u32)&unk_bin_15_ROM_START);
}

void func_80001610(void) {
    load_from_rom_to_addr(&unk_bin_35_ROM_START, (void*)0x80330000, (u32)&unk_bin_35_ROM_END - (u32)&unk_bin_35_ROM_START);
}

void func_80001650(void) {
    load_from_rom_to_addr(&unk_bin_36_ROM_START, (void*)0x80330000, (u32)&unk_bin_36_ROM_END - (u32)&unk_bin_36_ROM_START);
}

void func_80001690(void) {
    load_from_rom_to_addr(&unk_bin_37_ROM_START, (void*)0x80330000, (u32)&unk_bin_37_ROM_END - (u32)&unk_bin_37_ROM_START);
}

void func_800016D0(void) {
    load_from_rom_to_addr(&unk_bin_38_ROM_START, (void*)0x80330000, (u32)&unk_bin_38_ROM_END - (u32)&unk_bin_38_ROM_START);
}

void func_80001710(void) {
    load_from_rom_to_addr(&unk_bin_39_ROM_START, (void*)0x80330000, (u32)&unk_bin_39_ROM_END - (u32)&unk_bin_39_ROM_START);
}

void func_80001750(void) {
    load_from_rom_to_addr(&unk_bin_40_ROM_START, (void*)0x80330000, (u32)&unk_bin_40_ROM_END - (u32)&unk_bin_40_ROM_START);
}

void func_80001790(void) {
    load_from_rom_to_addr(&unk_bin_41_ROM_START, (void*)0x80330000, (u32)&unk_bin_41_ROM_END - (u32)&unk_bin_41_ROM_START);
}

void func_800017D0(void) {
    load_from_rom_to_addr(&unk_bin_42_ROM_START, (void*)0x80330000, (u32)&unk_bin_42_ROM_END - (u32)&unk_bin_42_ROM_START);
}

void func_80001810(void) {
    load_from_rom_to_addr(&unk_bin_43_ROM_START, (void*)0x80330000, (u32)&unk_bin_43_ROM_END - (u32)&unk_bin_43_ROM_START);
}

void func_80001850(void) {
    load_from_rom_to_addr(&unk_bin_44_ROM_START, (void*)0x8033C000, (u32)&unk_bin_44_ROM_END - (u32)&unk_bin_44_ROM_START);
}

void func_80001894(void) {
    load_from_rom_to_addr(&unk_bin_45_ROM_START, (void*)0x80338000, (u32)&unk_bin_45_ROM_END - (u32)&unk_bin_45_ROM_START);
}

void func_800018D8(void) {
    load_from_rom_to_addr(&unk_bin_46_ROM_START, (void*)0x80330000, (u32)&unk_bin_46_ROM_END - (u32)&unk_bin_46_ROM_START);
}

void func_80001918(void) {
    load_from_rom_to_addr(&unk_bin_47_ROM_START, (void*)0x8033A000, (u32)&unk_bin_47_ROM_END - (u32)&unk_bin_47_ROM_START);
}

void func_8000195C(void) {
    load_from_rom_to_addr(&unk_bin_48_ROM_START, (void*)0x80330000, (u32)&unk_bin_48_ROM_END - (u32)&unk_bin_48_ROM_START);
}

void func_8000199C(void) {
    load_from_rom_to_addr(&unk_bin_49_ROM_START, (void*)0x8033A000, (u32)&unk_bin_49_ROM_END - (u32)&unk_bin_49_ROM_START);
}

void func_800019E0(void) {
    load_from_rom_to_addr(&unk_bin_50_ROM_START, (void*)0x80330000, (u32)&unk_bin_50_ROM_END - (u32)&unk_bin_50_ROM_START);
}

void func_80001A20(void) {
    load_from_rom_to_addr(&unk_bin_51_ROM_START, (void*)0x80338000, (u32)&unk_bin_51_ROM_END - (u32)&unk_bin_51_ROM_START);
}

void func_80001A64(void) {
    
}

void thread6_func(void* arg) {
    u32 sp1C;

    clear_compression_buffer();
    func_800007F4();
    load_game_section();
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

void func_80002130(struct UnkStruct80001CF0* arg0) {
    void* sp2C;
    struct UnkStruct260* sp28;
    u8 pad[4];
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp1C = 0;
    sp18 = 0;
    arg0->unk27C++;
    if (osRecvMesg(&arg0->unk78, &sp2C, 0) != -1) {
        do {
            func_8000265C(arg0, (struct UnkStruct8000265C*)sp2C); // TODO: Fix aliasing
        } while (osRecvMesg(&arg0->unk78, &sp2C, 0) != -1);
    }
    if ((arg0->unk280 != 0) && (arg0->unk274 != 0)) {
        func_8000281C(arg0);
    } else {
        sp20 = ((arg0->unk274 == 0) * 2) | (arg0->unk278 == 0);
        if (func_80002890(arg0, &sp1C, &sp18, sp20) != sp20) {
            func_800026F4(arg0, sp1C, sp18);
        }
    }
    if ((sp28 = arg0->unk260) != NULL) {
        do {
            osSendMesg(sp28->unk4, arg0, 0);
        } while ((sp28 = sp28->unk0) != NULL);
    }
}

void func_800022A0(struct UnkStruct80001CF0* arg0) {
    struct UnkInputStruct80001CF0* sp24;
    s32 sp20 = 0;
    s32 sp1C = 0;
    s32 sp18;

    sp24 = arg0->unk274;
    arg0->unk274 = 0;
    if ((sp24->unk4 & 0x10) && (osSpTaskYielded(&sp24->unk10) != 0)) {
        sp24->unk4 = (s32) (sp24->unk4 | 0x20);
        if ((sp24->unk8 & 7) == 3) {
            sp24->unk0 = (void* ) arg0->unk268;
            arg0->unk268 = sp24;
            if (arg0->unk270 == 0) {
                arg0->unk270 = sp24;
            }
        }
    } else {
        sp24->unk4 = (s32) (sp24->unk4 & ~2);
        func_80002574(arg0, sp24);
    }
    sp18 = ((arg0->unk274 == 0) * 2) | (arg0->unk278 == 0);
    if (func_80002890(arg0, &sp20, &sp1C, sp18) != sp18) {
        func_800026F4(arg0, sp20, sp1C);
    }
}

void func_80002424(struct UnkStruct80001CF0* arg0) {
    struct UnkStruct80002424* sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp20 = 0;
    sp1C = 0;
    sp24 = arg0->unk278;
    arg0->unk278 = 0;
    sp24->unk4 = (s32) (sp24->unk4 & ~1);
    func_80002574(arg0, sp24);
    sp18 = ((arg0->unk274 == 0) * 2) | (arg0->unk278 == 0);
    if (func_80002890(arg0, &sp20, &sp1C, sp18) != sp18) {
        func_800026F4(arg0, sp20, sp1C);
    }
}

s32 func_800024F4(s32 arg0) {
    s32 sp2C = 0;

    if (arg0 != 0) {
        void *buf, *buf2; // weird, but ok
        if ((buf = osViGetCurrentFramebuffer()) != (buf2 = osViGetNextFramebuffer())) {
            return 0;
        }
        return arg0;
    }
    return 0;
}

s32 func_80002574(s32 arg0, struct UnkStruct80002424* arg1) {
    s32 sp1C;

    if (!(arg1->unk4 & 3)) {
        sp1C = osSendMesg(arg1->unk50, arg1->unk54, 1);
        if (arg1->unk10 == 1) {
            if ((arg1->unk8 & 0x40) && (arg1->unk8 & 0x20)) {
                if (D_8004A29C != 0) {
                    osViBlack(0U);
                    D_8004A29C = 0;
                }
                osViSwapBuffer(arg1->unkC);
            }
        }
        return 1;
    }
    return 0;
}

void func_8000265C(struct UnkStruct80001CF0* arg0, struct UnkStruct8000265C* arg1) {
    s32 sp4 = arg1->unk10;

    if (sp4 == 2) {
        if (arg0->unk26C != 0) {
            **(u32**)&arg0->unk26C = arg1; // TODO: Fix
        } else {
            arg0->unk264 = arg1;
        }
        arg0->unk26C = arg1;
        arg0->unk280 = 1;
    } else {
        if (arg0->unk270 != 0) {
            **(u32**)&arg0->unk270 = arg1; // TODO: Fix
        } else {
            arg0->unk268 = arg1;
        }
        arg0->unk270 = arg1;
    }
    arg1->unk0 = 0;
    arg1->unk4 = (s32) (arg1->unk8 & 3);
}

void func_800026F4(struct UnkStruct80001CF0* arg0, struct UnkStruct800026F4_Arg1* arg1, struct UnkStruct800026F4_Arg2* arg2) {
    s32 sp1C;
    u64* temp_t9;

    if (arg1 != NULL) {
        if (*(s32*)&arg1->unk10 == 2) {
            osWritebackDCacheAll();
        }
        arg1->unk4 &= ~0x30;
        osSpTaskLoad(&arg1->unk10);
        osSpTaskStartGo(&arg1->unk10);
        arg0->unk274 = arg1;
        if ((u32)arg1 == (u32)arg2) {
            arg0->unk278 = arg2;
        }
    }
    if ((arg2 != NULL) && ((u32)arg2 != (u32)arg1)) {
        sp1C = osDpSetNextBuffer(arg2->unk38, *arg2->unk3C);
        D_8004A294 = 1;
        D_8004A298 = 0;
        arg0->unk278 = arg2;
    }
}

void func_8000281C(struct UnkStruct80001CF0* arg0) {
    if (arg0->unk274->unk10.t.type == 1) {
        arg0->unk274->unk4 = (s32) (arg0->unk274->unk4 | 0x10);
        osSpTaskYield();
    } else {
        
    }
}
