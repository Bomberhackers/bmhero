#include "common.h"

extern struct UnkStruct8016E230 {
    u32 unk0;
    u32 unk4;
} UnkStruct8016E230;

extern struct UnkStruct8016E230 D_8016E220[1];
extern struct UnkStruct8016E230 D_8016E230[1];

extern Gfx gDebugFont[];

extern u8 D_80103948[];
extern s8 D_8010399C[0x12];

extern s32 D_8016E25C;
extern u32 D_8016E264;

extern s32 D_8016E244;
extern u32 D_8016E254;

extern s32 D_8016E23C;

// functions
void debug_print_xy(s32 x, s32 y);
void func_8005F124(void);
void func_8005FA90(void);

void func_8005E6A0(s32 arg0, s32 arg1) {
    struct UnkStruct8016E10C* sp8C;
    u32 i;

    func_8005F124();
    func_8005F96C(0xFF, 0xFF, 0xFF);
    sprintf(gDebugTextBuf, "%8d", D_8016E244);
    debug_print_xy(208, 216);
    sprintf(gDebugTextBuf, "%04d %04d %04d", D_8016E254 / 1000, D_8016E264 / 1000, (D_8016E254 + D_8016E264) / 1000);
    debug_print_xy(48, 216);
    func_8005FA90();

    sp8C = D_8016E10C;
    gDPPipeSync(gMasterDisplayList++);
    gDPSetCycleType(gMasterDisplayList++, G_CYC_FILL);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetFillColor(gMasterDisplayList++, -1);
    gDPFillRectangle(gMasterDisplayList++, arg0, arg1, arg0 + 0xE4, arg1 + 7);
    gDPPipeSync(gMasterDisplayList++);
    gDPSetFillColor(gMasterDisplayList++, 0x00010001);
    gDPFillRectangle(gMasterDisplayList++, arg0 + 1, arg1 + 1, arg0 + 0xE3, arg1 + 6);
    gDPPipeSync(gMasterDisplayList++);
    gDPSetFillColor(gMasterDisplayList++, 0xF801F801);
    gDPFillRectangle(gMasterDisplayList++, arg0 + 1, arg1 + 1, arg0 + (sp8C->unk58 / 10000U) + 1, arg1 + 2);
    gDPPipeSync(gMasterDisplayList++);
    gDPSetFillColor(gMasterDisplayList++, 0x07C107C1);
    gDPFillRectangle(gMasterDisplayList++, arg0 + 1, arg1 + 3, arg0 + (sp8C->unk60 / 10000U) + 1, arg1 + 4);
    gDPPipeSync(gMasterDisplayList++);
    gDPSetFillColor(gMasterDisplayList++, 0xF83FF83F);
    gDPFillRectangle(gMasterDisplayList++, arg0 + 1, arg1 + 5, arg0 + (D_8016E254 / 10000U) + 1, arg1 + 6);
    gDPPipeSync(gMasterDisplayList++);
    gDPSetFillColor(gMasterDisplayList++, 0xFFC1FFC1);
    gDPFillRectangle(gMasterDisplayList++, arg0 + (D_8016E254 / 10000) + 1, arg1 + 5, arg0 + (D_8016E254 / 10000) + (D_8016E264 / 10000) + 1, arg1 + 6);
    gDPPipeSync(gMasterDisplayList++);
    gDPSetFillColor(gMasterDisplayList++, 0xFFFFFFFF);

    for(i = 1; i < 3; i++) {
        gDPFillRectangle(gMasterDisplayList++, arg0 + (i * 0x4C) + 1, arg1 + 1, arg0 + (i * 0x4C) + 1, arg1 + 6);
    }

    gDPPipeSync(gMasterDisplayList++);
    gDPSetCycleType(gMasterDisplayList++, G_CYC_1CYCLE);
}

void func_8005EF30(void) {
    D_8016E23C = 0;
    D_8016E230[0].unk0 = 0;
    D_8016E230[0].unk4 = 0;
    D_8016E220[0].unk0 = 0;
    D_8016E220[0].unk4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/50BC0/func_8005EF78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/50BC0/func_8005EFE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/50BC0/func_8005F024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/50BC0/func_8005F088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/50BC0/func_8005F0B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/50BC0/func_8005F0F4.s")

void func_8005F124(void) {
        D_8016E264 = osGetCount() - D_8016E25C;
}

void func_address() {}


#pragma GLOBAL_ASM("asm/nonmatchings/code/50BC0/func_8005F170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/50BC0/func_8005F488.s")

void debug_print_char(s16 c, s16 x, s16 y, f32 unused1, f32 unused2) {
    u32 uls;
    u32 ult;
    s32 i;

    // look up the char in the supported glyph array to ensure that it can be printed.
    for(i = 0; i < 0x50; i++) {
        if (D_80103948[i] == c) {
            break;
        }
    }
    // character was not found in the array. abort.
    if (i == 0x50) {
        return;
    }

    // calculate uls and ult for the load texture tile command.
    uls = (i & 7) << 3;
    ult = D_8010399C[i / 8 * 2];

    gDPLoadTextureTile_4b(gMasterDisplayList++, gDebugFont, G_IM_FMT_CI, 64, 0 /*unknown*/, uls, ult, uls+8, 
        (D_8010399C[1+(i / 8 * 2)] + ult), 0, 0, 0, 0, 0, 0, 0);
    gDPSetTileSize(gMasterDisplayList++, G_TX_RENDERTILE, 0, 0, 32, D_8010399C[1+(i / 8 * 2)] << 2);
    gSPTextureRectangle(gMasterDisplayList++, (x * 4), (y * 4), ((x * 4) + 0x20), (D_8010399C[1+(i / 8 * 2)] + y) << 2, 0, 0, 0, 0x400, 0x400);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/50BC0/func_8005F96C.s")

void debug_print_xy(s32 x, s32 y) {
    s32 i;

    for(i = 0; i < 0xC8; i++) {
        s16 c = gDebugTextBuf[i];

        if (c == 0) {
            break;
        }
        debug_print_char(c, x, y, 1.0f, 1.0f);
        x += 8;
    }
}

void func_8005FA90(void) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/50BC0/func_8005FAA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/50BC0/func_8005FAB8.s")

void func_8005FAF4(u8* buf, s32 x, s32 y) {
    u8 i;

    func_8005F96C(0xFF, 0, 0xFF);

    for(i = 0; i < 0x10; i++) {
        sprintf(gDebugTextBuf, "%02x ", *buf);
        debug_print_xy(x, y);
        x += 0x12;
        buf += 1;
    }
    func_8005FA90();
}

void func_8005FBA4(void) {
    
}
