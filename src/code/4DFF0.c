#include <ultra64.h>

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

struct UnkInputStruct_8001ABF4 {
    void *unk0;
    void *unk4;
    void *unk8;
    void *unkC;
    void *unk10;
    s16 unk14;
    u8 unk16;
    u8 unk17;
    u8 unk18;
};

extern s32 func_8001ABF4(s32, s32, s32, void*);

extern struct UnkInputStruct_8001ABF4 D_80101E8C[5];
extern struct UnkInputStruct_8001ABF4 D_80101758[25];
extern struct UnkInputStruct_8001ABF4 D_80100560[4];
extern struct UnkInputStruct_8001ABF4 D_801005D0[4];
extern struct UnkInputStruct_8001ABF4 D_80100640[4];
extern struct UnkInputStruct_8001ABF4 D_801006B0[4];

// Most likely handles setting the "animated" textures for the respective Demos.
void func_8005C950(void) {
    if (gDemoID == DEMO_TITLE_INTRO) {
        switch (gDemoSceneID) {                       
        case 9: // sliding down the snow, bombermans face hasnt looked back at the snowball yet
            func_8001ABF4(0, 0, 0, (void*)&D_80101E8C[0]);
            break;
        case 11: // sliding down the snow, he has looked at the snowball now and makes an expression
            func_8001ABF4(0, 0, 0, (void*)&D_80101E8C[1]);
            break;
        case 14: // snowman and him get hit by the snowball, face is still seen
            func_8001ABF4(0, 0, 0, (void*)&D_80101E8C[2]);
            break;
        case 19: // using copter to fly over the water; water needs the texture
            func_8001ABF4(0, 0, 0, (void*)&D_80101E8C[4]);
            break;
        case 20: // cannon has fired
            func_8001ABF4(0, 0, 0, (void*)&D_80101E8C[4]);
            break;
        case 21: // bomberman expression when cannon is fired
            func_8001ABF4(0, 0, 0, (void*)&D_80101E8C[3]);
            break;
        default:
            break;
        }
    } else if (gDemoID == DEMO_CREDIT_SCENE) {
        switch (gDemoSceneID) {                       /* switch 2 */
        case 1:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[8]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[16]);
            break;
        case 2:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[1]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[9]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[17]);
            break;
        case 3:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[2]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[10]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[18]);
            func_8001ABF4(0, 3, 0, (void*)&D_80101758[24]);
            break;
        case 4:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[3]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[11]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[19]);
            break;
        case 5:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[4]);
            break;
        case 6:                                     /* switch 2 */
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[12]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[20]);
            break;
        case 7:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[5]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[13]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[21]);
            break;
        case 8:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[6]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[14]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[22]);
            break;
        case 9:                                     /* switch 2 */
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[7]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[15]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[23]);
            break;
        }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_JET_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_JET)) {
        switch (gDemoSceneID) {                       /* switch 6; irregular */
        case 3:                                     /* switch 6 */
            func_8001ABF4(0, 0, 0, (void*)&D_80100560[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_801005D0[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_80100640[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_801006B0[3]);
            break;
        case 4:                                     /* switch 6 */
            func_8001ABF4(0, 0, 0, (void*)&D_80100560[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_801005D0[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_80100640[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_801006B0[3]);
            break;
        }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_MARINE_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_MARINE)) {
        switch (gDemoSceneID) {                       /* switch 5; irregular */
        case 3:                                     /* switch 5 */
            func_8001ABF4(0, 3, 0, (void*)&D_80100560[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_801005D0[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_80100640[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_801006B0[2]);
            break;
        case 4:                                     /* switch 5 */
            func_8001ABF4(0, 3, 0, (void*)&D_80100560[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_801005D0[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_80100640[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_801006B0[2]);
            break;
        }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_COPTER_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_COPTER)) {
        switch (gDemoSceneID) {                       /* switch 4; irregular */
        case 3:                                     /* switch 4 */
            func_8001ABF4(0, 2, 0, (void*)&D_80100560[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_801005D0[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_80100640[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_801006B0[1]);
            break;
        case 4:                                     /* switch 4 */
            func_8001ABF4(0, 2, 0, (void*)&D_80100560[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_801005D0[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_80100640[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_801006B0[1]);
            break;
        }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_SLIDER_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_SLIDER)) {
        switch (gDemoSceneID) {                       /* switch 3; irregular */
        case 3:                                     /* switch 3 */
            func_8001ABF4(0, 1, 0, (void*)&D_80100560[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_801005D0[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_80100640[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_801006B0[0]);
            break;
        case 4:                                     /* switch 3 */
            func_8001ABF4(0, 1, 0, (void*)&D_80100560[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_801005D0[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_80100640[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_801006B0[0]);
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005D2D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005DA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005DD80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005E040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/4DFF0/func_8005E230.s")
