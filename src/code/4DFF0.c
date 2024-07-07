#include "common.h"

extern s32 func_8005F96C(s32, s32, s32);                           /* extern */

extern s8 D_801039B0;
extern s8 D_801039B4;
extern s8 D_801039C4;

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
// Demo_SetViewAtEye(?)
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

extern s32 func_8001ABF4(s32, s32, s32, void*);
extern s32 D_80100560;
extern s32 D_801005D0;
extern s32 D_80100640;
extern s32 D_801006B0;
extern s32 D_80101758;
extern u8 * D_80101E8C;
extern s8 D_80134798;
extern s8 D_80134799;

void func_8005C950(void) {
    if (D_80134799 == 0) {
        switch (D_80134798) {                       
        case 9:                                     
            func_8001ABF4(0, 0, 0, (u32)&D_80101E8C);
            break;
        case 11:                                    
            func_8001ABF4(0, 0, 0, (u32)&D_80101E8C + 0x1C);
            break;
        case 14:                                    
            func_8001ABF4(0, 0, 0, (u32)&D_80101E8C + 0x38);
            break;
        case 19:                                    
            func_8001ABF4(0, 0, 0, (u32)&D_80101E8C + 0x70);
            break;
        case 20:                                    
            func_8001ABF4(0, 0, 0, (u32)&D_80101E8C + 0x70);
            break;
        case 21:                                    
            func_8001ABF4(0, 0, 0, (u32)&D_80101E8C + 0x54);
            break;
        default:
            break;
        }
    } else if (D_80134799 == 1) {
        switch (D_80134798) {                       /* switch 2 */
        case 1:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (u32)&D_80101758);
            func_8001ABF4(0, 1, 0, (u32)&D_80101758 + 0xE0);
            func_8001ABF4(0, 2, 0, (u32)&D_80101758 + 0x1C0);
            break;
        case 2:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (u32)&D_80101758 + 0x1C);
            func_8001ABF4(0, 1, 0, (u32)&D_80101758 + 0xFC);
            func_8001ABF4(0, 2, 0, (u32)&D_80101758 + 0x1DC);
            break;
        case 3:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (u32)&D_80101758 + 0x38);
            func_8001ABF4(0, 1, 0, (u32)&D_80101758 + 0x118);
            func_8001ABF4(0, 2, 0, (u32)&D_80101758 + 0x1F8);
            func_8001ABF4(0, 3, 0, (u32)&D_80101758 + 0x2A0);
            break;
        case 4:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (u32)&D_80101758 + 0x54);
            func_8001ABF4(0, 1, 0, (u32)&D_80101758 + 0x134);
            func_8001ABF4(0, 2, 0, (u32)&D_80101758 + 0x214);
            break;
        case 5:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (u32)&D_80101758 + 0x70);
            break;
        case 6:                                     /* switch 2 */
            func_8001ABF4(0, 1, 0, (u32)&D_80101758 + 0x150);
            func_8001ABF4(0, 2, 0, (u32)&D_80101758 + 0x230);
            break;
        case 7:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (u32)&D_80101758 + 0x8C);
            func_8001ABF4(0, 1, 0, (u32)&D_80101758 + 0x16C);
            func_8001ABF4(0, 2, 0, (u32)&D_80101758 + 0x24C);
            break;
        case 8:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (u32)&D_80101758 + 0xA8);
            func_8001ABF4(0, 1, 0, (u32)&D_80101758 + 0x188);
            func_8001ABF4(0, 2, 0, (u32)&D_80101758 + 0x268);
            break;
        case 9:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (u32)&D_80101758 + 0xC4);
            func_8001ABF4(0, 1, 0, (u32)&D_80101758 + 0x1A4);
            func_8001ABF4(0, 2, 0, (u32)&D_80101758 + 0x284);
            break;
        }
    } else if ((D_80134799 == 2) || (D_80134799 == 6)) {
        switch (D_80134798) {                       /* switch 6; irregular */
        case 3:                                     /* switch 6 */
            func_8001ABF4(0, 0, 0, (u32)&D_80100560);
            func_8001ABF4(0, 1, 0, (u32)&D_801005D0 + 0x1C);
            func_8001ABF4(0, 2, 0, (u32)&D_80100640 + 0x38);
            func_8001ABF4(0, 3, 0, (u32)&D_801006B0 + 0x54);
            break;
        case 4:                                     /* switch 6 */
            func_8001ABF4(0, 0, 0, (u32)&D_80100560);
            func_8001ABF4(0, 1, 0, (u32)&D_801005D0 + 0x1C);
            func_8001ABF4(0, 2, 0, (u32)&D_80100640 + 0x38);
            func_8001ABF4(0, 3, 0, (u32)&D_801006B0 + 0x54);
            break;
        }
    } else if ((D_80134799 == 3) || (D_80134799 == 7)) {
        switch (D_80134798) {                       /* switch 5; irregular */
        case 3:                                     /* switch 5 */
            func_8001ABF4(0, 3, 0, (u32)&D_80100560 + 0x54);
            func_8001ABF4(0, 0, 0, (u32)&D_801005D0);
            func_8001ABF4(0, 1, 0, (u32)&D_80100640 + 0x1C);
            func_8001ABF4(0, 2, 0, (u32)&D_801006B0 + 0x38);
            break;
        case 4:                                     /* switch 5 */
            func_8001ABF4(0, 3, 0, (u32)&D_80100560 + 0x54);
            func_8001ABF4(0, 0, 0, (u32)&D_801005D0);
            func_8001ABF4(0, 1, 0, (u32)&D_80100640 + 0x1C);
            func_8001ABF4(0, 2, 0, (u32)&D_801006B0 + 0x38);
            break;
        }
    } else if ((D_80134799 == 4) || (D_80134799 == 8)) {
        switch (D_80134798) {                       /* switch 4; irregular */
        case 3:                                     /* switch 4 */
            func_8001ABF4(0, 2, 0, (u32)&D_80100560 + 0x38);
            func_8001ABF4(0, 3, 0, (u32)&D_801005D0 + 0x54);
            func_8001ABF4(0, 0, 0, (u32)&D_80100640);
            func_8001ABF4(0, 1, 0, (u32)&D_801006B0 + 0x1C);
            break;
        case 4:                                     /* switch 4 */
            func_8001ABF4(0, 2, 0, (u32)&D_80100560 + 0x38);
            func_8001ABF4(0, 3, 0, (u32)&D_801005D0 + 0x54);
            func_8001ABF4(0, 0, 0, (u32)&D_80100640);
            func_8001ABF4(0, 1, 0, (u32)&D_801006B0 + 0x1C);
            break;
        }
    } else if ((D_80134799 == 5) || (D_80134799 == 9)) {
        switch (D_80134798) {                       /* switch 3; irregular */
        case 3:                                     /* switch 3 */
            func_8001ABF4(0, 1, 0, (u32)&D_80100560 + 0x1C);
            func_8001ABF4(0, 2, 0, (u32)&D_801005D0 + 0x38);
            func_8001ABF4(0, 3, 0, (u32)&D_80100640 + 0x54);
            func_8001ABF4(0, 0, 0, (u32)&D_801006B0);
            break;
        case 4:                                     /* switch 3 */
            func_8001ABF4(0, 1, 0, (u32)&D_80100560 + 0x1C);
            func_8001ABF4(0, 2, 0, (u32)&D_801005D0 + 0x38);
            func_8001ABF4(0, 3, 0, (u32)&D_80100640 + 0x54);
            func_8001ABF4(0, 0, 0, (u32)&D_801006B0);
            break;
        }
    }
exit:;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005D2D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005DA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005DD80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005E040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005E230.s")
