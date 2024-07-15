#include "common.h"
#include "variables.h"

// Structs
struct UnkStruct_8001EFD0 {
    OSPfs unk0;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
};

// External variables
extern void* D_8016526C;
extern void* D_80165274;


void func_80020C44(void);
void* func_80020F18(void);



#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001EEB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001EEC8.s")

void func_8001EED8(void) {
    u8 sp1F;

    osContStartQuery(&D_801776B0);
    osRecvMesg(&D_801776B0, NULL, 1);
    osContGetQuery(D_80177650);
    for (sp1F = 0; sp1F < 4; sp1F++) {
        if ((D_80177650[sp1F].type & 4) && (D_80177650[sp1F].type & 1) && (D_80177650[sp1F].errno == 0)) {
            D_8016E27C |= 1 << sp1F;
        } else {
            D_8016E27C &= ~(1 << sp1F);
        }
    }
}


void func_8001EFD0(struct UnkStruct_8001EFD0* arg0, s32 arg1) {
    arg0[arg1].unk68 = -1;
    arg0[arg1].unk6C = -1;
    arg0[arg1].unk70 = -1;
    arg0[arg1].unk78 = -1;
    arg0[arg1].unk7C = -1;
    arg0[arg1].unk80 = -1;
    arg0[arg1].unk74 = -1;
}

#ifdef NON_MATCHING
void func_8001F088(struct UnkStruct_8001EFD0* arg0) {
    s32 sp1C;
    s32 sp18;

    for (sp1C = 0; sp1C < 4; sp1C++) {
        func_8001EFD0(arg0, sp1C);
        if ((D_8016E27C >> sp1C) & 1) {
            if ((D_80177650[sp1C].type & CONT_JOYPORT) && (D_80177650[sp1C].type & CONT_ABSOLUTE)) {
                sp18 = osPfsInitPak(&D_801776B0, &arg0[sp1C].unk0, sp1C);
                arg0[sp1C].unk74 = sp18;
            }
        }

    } 
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F088.s")
#endif

#ifdef NON_MATCHING
void func_8001F174(struct UnkStruct_8001EFD0* arg0, s32 arg1) {
    s32 sp18;
    
    if (((s32) D_8016E27C >> arg1) & 1) {
        if ((D_80177650[arg1].type & CONT_JOYPORT) && ( D_80177650[arg1].type & CONT_ABSOLUTE)) {
            sp18 = osPfsInitPak(&D_801776B0, &arg0[arg1].unk0, arg1);
            arg0 [arg1].unk74 = sp18;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F174.s")
#endif

void func_8001F238(struct UnkStruct_8001EFD0* arg0) {
    s32 sp24;
    s32 sp20;
    u8 sp1F;

    func_8001EED8();
    osPfsIsPlug(&D_801776B0, &sp1F);
    for (sp24 = 0; sp24 < 4; sp24++) {
        if (((s32) sp1F >> sp24) & 1) {
            sp20 = 0;
            if (arg0[sp24].unk70 != 0) {
                func_8001F174(arg0, sp24);
            }
        } else {
            sp20 = 1;
            func_8001EFD0(arg0, sp24);
        }
        arg0[sp24].unk70 = sp20;
    } 
}

#ifdef NON_MATCHING
s32 func_8001F328(struct UnkStruct_8001EFD0* arg0, s32 arg1, s32 arg2, OSPfsState* arg3) {
    s32 ret;
     
    return ret = osPfsFileState(&arg0[arg1].unk0, arg2, arg3);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F328.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F5F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F68C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F728.s")

s32 Eeprom_Write(OSMesgQueue* mq, u8* buf, u8 addr, u16 half_bytes) {
    s32 status;

    status = 0;
    if (osEepromProbe(mq) != 1) {
        return CONT_RANGE_ERROR;
    }

    status = osEepromLongWrite(mq, addr, buf, half_bytes);
    return status;
}


#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F8A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F9DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001FAD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001FB3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001FBAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001FDF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001FF80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_800200D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8002021C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_80020360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_800203C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_80020420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_80020550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_80020844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_80020C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_80020F18.s")

s32 func_80021158(void) {
    func_8001ECB8();
    D_8016526C = &func_80020F18;
    D_80165274 = &func_80020C44;
    func_8001F9DC();
    func_8001E954(0x8024C000);
    func_8001E98C(0, &unk_bin_0_2_ROM_START, code_extra_0_ROM_START);
    func_80019C84();
    func_80019D2C();
    func_8001A258();
    func_8001D244(0xFF, 0xFF, 0xFF, 0x10);
    func_8001D284();
    func_80000964();
}

