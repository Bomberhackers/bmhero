#include "common.h"

extern s32 func_8005F96C(s32, s32, s32);                           /* extern */

extern struct UnkStruct8016E230 {
    u32 unk0;
    u32 unk4;
} UnkStruct8016E230;

struct UnkStruct8016E10C {
    char filler0[0x58];
    u32 unk58;
    char filler5C[0x4];
    u32 unk60;
};

extern Gfx gDebugFont[];
extern u8 D_80103948[];
extern s8 D_8010399C[0x12];
extern s8 D_801039B0;
extern s8 D_801039B4;
extern s8 D_801039C4;
extern Gfx *gMasterDisplayList;
extern struct UnkStruct8016E10C* D_8016E10C;
extern struct UnkStruct8016E230 D_8016E220[1];
extern struct UnkStruct8016E230 D_8016E230[1];
extern s32 D_8016E23C;
extern s32 D_8016E244;
extern u32 D_8016E254;
extern s32 D_8016E25C;
extern u32 D_8016E264;

extern s32 D_8013479C;
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
extern s8 D_8016E134;

struct UnkStruct_801347A0 {
    s32 *arr;
};

extern struct UnkStruct_801347A0 D_801347A0;

extern f32 *D_801347A4;

struct String {
    u8 padding0[0x8];
    /* 0x08 */ s16 len;
    u8 padding8[0x2];
    s16 str[1]; // dynamic length
};

struct StringInfo {
    struct String *str;
    s16 x; // D_801347EC
    s16 y; // D_801347EE
};

extern struct String* D_801347E8;
extern s16 D_801347EC;
extern s16 D_801347EE;
extern s16 D_801347F0;

// functions
void debug_print_xy(s32 x, s32 y);
void func_8005F124(void);
void func_8005FA90(void);

/**
 * Renders the text background behind the text during a Demo.
 */
void Demo_RenderTextBG(void) {
    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++,
        G_SHADE | G_SHADING_SMOOTH | G_CULL_FRONT | G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD
    );
    gSPSetGeometryMode(gMasterDisplayList++,
        G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK 
    );
    gDPSetCombineMode(gMasterDisplayList++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gMasterDisplayList++,
        AA_EN | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | FORCE_BL | 0x500000,
        0
    );
    gDPSetPrimColor(gMasterDisplayList++, 0, 0, 0, 0, 0, 80);
    gDPFillRectangle(gMasterDisplayList++, 24, 180, 298, 220);
}

/**
 * Sets up the combiners and palette memory for the text during a Demo.
 */
void Demo_SetupTextPal(void) {
    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++,
        G_SHADE | G_SHADING_SMOOTH | G_CULL_FRONT | G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD
    );
    gSPSetGeometryMode(gMasterDisplayList++,
        G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK | G_LIGHTING
    );
    gDPSetTexturePersp(gMasterDisplayList++, G_TP_NONE);
    gDPSetRenderMode(gMasterDisplayList++,
        AA_EN | IM_RD | CVG_X_ALPHA | ALPHA_CVG_SEL | 0x550000,
        0
    );
    gDPSetCombineMode(gMasterDisplayList++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetColorDither(gMasterDisplayList++, G_CD_BAYER);
    gDPSetTextureFilter(gMasterDisplayList++, G_TF_BILERP);
    gDPSetTextureLUT(gMasterDisplayList++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gMasterDisplayList++, 0, D_8016CAA0[3].unk0 + 0x10);
}

/**
 * Render the next character in the Demo text being rendered using a given character
 * ([s, t] specify the coordinates in tilemap space for the character to use).
 */
void Demo_RenderChar(s16 x, s16 y, s16 s, s16 t) {
    gDPLoadMultiTile_4b(gMasterDisplayList++,
        D_8016CAA0[3].unk0 + 0x30, 0, 0,
        G_IM_FMT_CI,
        256, 256,
        s, t, (s + 8), (t + 16),
        0, 0, 0, 0, 0, 0, 0
    );
    gDPSetTileSize(gMasterDisplayList++,  0, 0, 0, 0x40, 0x40);
    gSPTextureRectangle(gMasterDisplayList++,
        (x << 2), (y << 2), ((x + 8) << 2), ((y + 16) << 2),
        0, 0, 0, 0x400, 0x400);
}

// Demo_HandlePrintText
void func_8005C2BC(void) {
    s16* str;
    s16 len;
    s16 x;
    s16 y;

    // If there is no str to print, do not print.
    if (D_801347E8 == NULL) {
        return;
    }

    // If there is a background to render for the text, render it.
    if(D_801347F0 != 0) {
        Demo_RenderTextBG();
    }

    Demo_SetupTextPal();

    // set initial x/y and len/str for the printing.
    x = D_801347EC;
    y = D_801347EE;
    len = D_801347E8->len;
    str = D_801347E8->str;

    while(1) {
        // Every -1 is a new line unless it is the last character being printed.
        // If we are not at one, print it as the next character.
        if(*str == -1) {
            len--;
            // If we are at EOS, end the text printing.
            if(len == 0) {
                break;
            }
    
            y += 16; // increment to the next line.
            x = D_801347EC; // set x back to the starting left side of the line.
        }
        else {
            // Render the char; use the str character to calculate where
            // on the tilemap we should pick the character from.
            Demo_RenderChar(x, y, (*str % 32) * 8, (*str / 32) * 16);
            x += 8;
        }
    
        str++;
    }
}

// seems to handle camera stuff for the Demo scenes.
void func_8005C438(void) {
    u32 i;
    u32 j;

    if (D_8013479C == 0) {
        return;
    }
    if (D_801347AC == D_801347A8) {
        D_801347A8 = 0.0f;
        D_801347AC = D_801347A0.arr[D_801347B0 * 2 + 7];
        if (D_801347AC != 0) {
            i = D_801347A0.arr[D_801347B0 * 2 + 6];
            j = D_801347A0.arr[D_801347B0 * 2 + 8];
            D_801347B4 = (D_801347A4 + (i * 0x25))[0x10];
            D_801347B8 = (D_801347A4 + (i * 0x25))[0x11];
            D_801347BC = (D_801347A4 + (i * 0x25))[0x12];
            D_801347C0 = (D_801347A4 + (i * 0x25))[0x1C];
            D_801347C4 = (D_801347A4 + (i * 0x25))[0x1D];
            D_801347C8 = (D_801347A4 + (i * 0x25))[0x1E];
            D_801347CC = (D_801347A4 + (j * 0x25))[0x10];
            D_801347D0 = (D_801347A4 + (j * 0x25))[0x11];
            D_801347D4 = (D_801347A4 + (j * 0x25))[0x12];
            D_801347D8 = (D_801347A4 + (j * 0x25))[0x1C];
            D_801347DC = (D_801347A4 + (j * 0x25))[0x1D];
            D_801347E0 = (D_801347A4 + (j * 0x25))[0x1E];
        }
        D_8016E134 = 1;
        D_801347B0 = D_801347B0 + 1;
    }
    if (D_801347AC != 0) {
        gView.at.x = (((D_801347CC - D_801347B4) * D_801347A8) / D_801347AC) + D_801347B4;
        gView.at.y = (((D_801347D0 - D_801347B8) * D_801347A8) / D_801347AC) + D_801347B8;
        gView.at.z = (((D_801347D4 - D_801347BC) * D_801347A8) / D_801347AC) + D_801347BC;
        gView.eye.x = (((D_801347D8 - D_801347C0) * D_801347A8) / D_801347AC) + D_801347C0;
        gView.eye.y = (((D_801347DC - D_801347C4) * D_801347A8) / D_801347AC) + D_801347C4;
        gView.eye.z = (((D_801347E0 - D_801347C8) * D_801347A8) / D_801347AC) + D_801347C8;
    }
    D_801347A8 += 2.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005C950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005D2D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005DA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005DD80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005E040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005E230.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005EF78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005EFE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005F024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005F088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005F0B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005F0F4.s")

void func_8005F124(void) {
        D_8016E264 = osGetCount() - D_8016E25C;
}

void func_address() {}


#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005F170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005F488.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005F96C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005FAA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005FAB8.s")

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
