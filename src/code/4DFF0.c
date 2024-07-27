#include <ultra64.h>

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

/**
 * Renders the loaded string for the Demo scene.
 */
void Demo_HandlePrintText(void) {
    s16* str;
    s16 len;
    s16 x;
    s16 y;

    // If there is no str to print, do not print.
    if (D_801347E8.strInfo == NULL) {
        return;
    }

    // If there is a background to render for the text, render it.
    if(D_801347E8.renderBG != 0) {
        Demo_RenderTextBG();
    }

    Demo_SetupTextPal();

    // set initial x/y and len/str for the printing.
    x = D_801347E8.x;
    y = D_801347E8.y;
    len = D_801347E8.strInfo->len;
    str = D_801347E8.strInfo->str;

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
            x = D_801347E8.x; // set x back to the starting left side of the line.
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
void Demo_SetView(void) {
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

// Most likely handles setting the "animated" textures for the respective Demos.
void Demo_HandleSetAnimTextures(void) {
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
        switch (gDemoSceneID) {
        case 1:
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[8]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[16]);
            break;
        case 2:
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[1]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[9]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[17]);
            break;
        case 3:
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[2]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[10]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[18]);
            func_8001ABF4(0, 3, 0, (void*)&D_80101758[24]);
            break;
        case 4:
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[3]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[11]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[19]);
            break;
        case 5:
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[4]);
            break;
        case 6:
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[12]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[20]);
            break;
        case 7:
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[5]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[13]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[21]);
            break;
        case 8:
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[6]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[14]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[22]);
            break;
        case 9:
            func_8001ABF4(0, 0, 0, (void*)&D_80101758[7]);
            func_8001ABF4(0, 1, 0, (void*)&D_80101758[15]);
            func_8001ABF4(0, 2, 0, (void*)&D_80101758[23]);
            break;
        }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_JET_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_JET)) {
        switch (gDemoSceneID) {
        case 3:
            func_8001ABF4(0, 0, 0, (void*)&D_80100560[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_801005D0[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_80100640[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_801006B0[3]);
            break;
        case 4:
            func_8001ABF4(0, 0, 0, (void*)&D_80100560[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_801005D0[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_80100640[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_801006B0[3]);
            break;
        }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_MARINE_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_MARINE)) {
        switch (gDemoSceneID) {
        case 3:
            func_8001ABF4(0, 3, 0, (void*)&D_80100560[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_801005D0[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_80100640[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_801006B0[2]);
            break;
        case 4:
            func_8001ABF4(0, 3, 0, (void*)&D_80100560[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_801005D0[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_80100640[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_801006B0[2]);
            break;
        }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_COPTER_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_COPTER)) {
        switch (gDemoSceneID) {
        case 3:
            func_8001ABF4(0, 2, 0, (void*)&D_80100560[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_801005D0[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_80100640[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_801006B0[1]);
            break;
        case 4:
            func_8001ABF4(0, 2, 0, (void*)&D_80100560[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_801005D0[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_80100640[0]);
            func_8001ABF4(0, 1, 0, (void*)&D_801006B0[1]);
            break;
        }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_SLIDER_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_SLIDER)) {
        switch (gDemoSceneID) {
        case 3:
            func_8001ABF4(0, 1, 0, (void*)&D_80100560[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_801005D0[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_80100640[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_801006B0[0]);
            break;
        case 4:
            func_8001ABF4(0, 1, 0, (void*)&D_80100560[1]);
            func_8001ABF4(0, 2, 0, (void*)&D_801005D0[2]);
            func_8001ABF4(0, 3, 0, (void*)&D_80100640[3]);
            func_8001ABF4(0, 0, 0, (void*)&D_801006B0[0]);
            break;
        }
    }
}

/**
 * Setup the string to be printed depending on the Demo and its current state.
 */
void Demo_PrepareStr(void) {
    f32 sp2C;

    if (gDemoID == DEMO_CREDIT_SCENE) {
        D_801347E8.y = 184;
        D_801347E8.renderBG = TRUE;
        D_801347E8.strInfo = NULL;
        if (gObjects[0].unkA4 != 0) {
            sp2C = func_8001B62C(0, 0);
        }
        switch (gDemoSceneID) {
            case 2:
                if ((sp2C >= 600.0f) && (sp2C <= 700.0f)) {
                    D_801347E8.x = 32;
                    D_801347E8.strInfo = D_8010289C.unk0[0];
                }
                break;
            case 4:
                if ((sp2C >= 300.0f) && (sp2C <= 500.0f)) {
                    D_801347E8.x = 40;
                    D_801347E8.strInfo = D_8010289C.unk0[1];
                } else if ((sp2C >= 600.0f) && (sp2C <= 800.0f)) {
                    D_801347E8.x = 32;
                    D_801347E8.strInfo = D_8010289C.unk0[2];
                }
                break;
            }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_JET_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_JET)) {
        switch (gDemoSceneID) {
            case 8:
                sp2C = func_8001B62C(0, 0);
                if (sp2C == 112.0f) {
                    func_800178D4(-1, 0, 0xE, -1, 0);
                } else if (sp2C == 270.0f) {
                    func_800178D4(-1, 0, 0x7A, -1, 0);
                } else if (sp2C == 276.0f) {
                    D_801347E8.x = 160;
                    D_801347E8.y = 192;
                    D_801347E8.renderBG = FALSE;
                    D_801347E8.strInfo = D_8010289C.unk0[3];
                    func_800178D4(-1, 0, 0xB, -1, 0);
                }
                break;
            default:
                D_801347E8.strInfo = NULL;
                break;
            }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_MARINE_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_MARINE)) {
        switch (gDemoSceneID) {
            case 8:
                sp2C = func_8001B62C(0, 0);
                if (sp2C == 80.0f) {
                    func_800178D4(-1, 0, 0xE, -1, 0);
                } else if (sp2C == 140.0f) {
                    func_800178D4(-1, 0, 0x7A, -1, 0);
                } else if (sp2C == 276.0f) {
                    D_801347E8.x = 176;
                    D_801347E8.y = 192;
                    D_801347E8.renderBG = FALSE;
                    D_801347E8.strInfo = D_8010289C.unk0[4];
                    func_800178D4(-1, 0, 0xB, -1, 0);
                }
                break;
            default:
                D_801347E8.strInfo = NULL;
                break;
        }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_COPTER_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_COPTER)) {
        switch (gDemoSceneID) {
            case 8:
                sp2C = func_8001B62C(0, 0);
                if (sp2C == 80.0f) {
                    func_800178D4(-1, 0, 0xE, -1, 0);
                } else if (sp2C == 200.0f) {
                    func_800178D4(-1, 0, 0x7A, -1, 0);
                } else if (sp2C == 276.0f) {
                    D_801347E8.x = 160;
                    D_801347E8.y = 192;
                    D_801347E8.renderBG = FALSE;
                    D_801347E8.strInfo = D_8010289C.unk0[5];
                    func_800178D4(-1, 0, 0xB, -1, 0);
                }
                break;
            default:
                D_801347E8.strInfo = NULL;
                break;
        }
    } else if ((gDemoID == DEMO_BOMBER_CHANGE_SLIDER_QUICK) || (gDemoID == DEMO_BOMBER_CHANGE_SLIDER)) {
        switch (gDemoSceneID) {
            case 8:
                sp2C = func_8001B62C(0, 0);
                if (sp2C == 48.0f) {
                    func_800178D4(-1, 0, 0xE, -1, 0);
                } else if (sp2C == 100.0f) {
                    func_800178D4(-1, 0, 0x7A, -1, 0);
                } else if (sp2C == 276.0f) {
                    D_801347E8.x = 144;
                    D_801347E8.y = 192;
                    D_801347E8.renderBG = 0;
                    D_801347E8.strInfo = D_8010289C.unk0[6];
                    func_800178D4(-1, 0, 0xB, -1, 0);
                }
                break;
            default:
                D_801347E8.strInfo = NULL;
                break;
        }
    }
}

// Demo_ProgressScene(?)
void func_8005DA00(void) {
    s32 i;

    if (D_80134790 == 0) {
        return;
    } else if (D_80134790 < D_80134791) {
        func_8001EC04();
        D_80134790 += 1;
        return;
    }
    D_80134790 = 0;
    if (D_80134794->unk0 == 0) {
        D_801347E5 = 1;
        D_801347E6 = 1;
        func_8001D244(0xFF, 0xFF, 0xFF, 0x10);
        func_8001D2C0();
        func_8001EBE8();
        return;
    }
    for(i = 0; i < 8; i++) {
        func_8001A928(i);
    }
    func_8001E954(0x80280000);
    if (D_80134794->unk0 != 0) {
        DecompressFile(1, D_80134794->unk0, D_80134794->unk4);
    }
    if (D_80134794->unk8 != 0) {
        DecompressFile(2, D_80134794->unk8, D_80134794->unkC);
    }
    if (D_80134794->unk10 == -1) {
        D_8013479C = NULL;
    } else {
        D_8013479C = (void*)(D_80134794->unk10 + D_8016CAA0[1].unk0);
        D_801347A8 = 0.0f;
        D_801347AC = 0;
        D_801347B0 = 0;
        D_801347A4 = D_8013479C->unk14[3] + (u32)D_8013479C;
        D_801347A0.arr = D_8013479C->unk14[6] + (u32)D_8013479C;
    }
    for(i = 0; i < 8; i++) {
        if ((D_80134794->unk14[i] != -1) && (D_80134794->unk34[i] != -1)) {
            func_8001BD44(i, 0, D_80134794->unk34[i], D_8016CAA0[1].unk0 + D_80134794->unk14[i]);
            func_8001BE6C(i, 0, 0, 0);
            func_8001B754(0, 0);
            gObjects[i].unkA4 = 1;
        }
    }
    Demo_HandleSetAnimTextures();
    if ((D_801347E4 != 0) && (func_8001D1D4() == 2)) {
        func_8001D284();
    }
    D_801347E4 = D_80134794->unk54;
    gDemoSceneID += 1;
    D_80134794++;
    func_8001EBE8();
}

void func_8005DD80(void) {
    s32 sp24;

    if ((gContButtonPressed[0] & 0x1000) && (func_8001D1D4() != -1) && (func_8001D1D4() != 1)) {
        D_801347E5 = 1;
        func_8001D244(0xFF, 0xFF, 0xFF, 0x10);
        func_8001D2C0();
        func_80016FC8(0x20);
    }
    if ((func_8001D1D4() == 2) && (D_801347E5 != 0)) {
        D_80165264 = 1;
    }
    func_8005DA00();
    if (D_801347E6 == 0) {
        Demo_PrepareStr();
        if (D_80134790 == 0) {
            Demo_SetView();
            for(sp24 = 0; sp24 < 8; sp24++) {
                if (gObjects[sp24].unkA4 != 0) {
                    func_8001CD20(sp24);
                    func_8001AD6C(sp24);
                }
            }
            for(sp24 = 0; sp24 < 8; sp24++) {
                if (gObjects[sp24].unkA4 != 0) {
                    if ((func_8001B44C(sp24, 0) != 0)) {
                        D_80134790 = 1;
                        if (gDemoID == 1) {
                            D_80134791 = 3;
                        } else {
                            D_80134791 = 2;
                        }
                        break;
                    }
                }
            }
        }
    }
    if (D_801347E4 != 0) {
        if (func_8001B62C(0, 0) == func_8001B580(0, 0) - 48.0f) {
            if (D_801347E4 == 1) {
                func_8001D244(0, 0, 0, 0x10);
            } else {
                func_8001D244(0xFF, 0xFF, 0xFF, 0x10);
            }
            func_8001D2C0();
        }
    }
    func_8001994C();
}

void func_8005E040(void) {
    u16 sp3E;
    s32 i;

    func_8001D4D0();
    func_8001D638(1, 0, 0, 0);
    guPerspective(D_8016E104, &sp3E, 50.0f, 1.3333334f, 10.0f, 8000.0f, 1.0f);
    gSPPerspNormalize(gMasterDisplayList++, sp3E);
    guLookAt(&D_8016E104->unk00[2], gView.eye.x, gView.eye.y, gView.eye.z, gView.at.x, gView.at.y, gView.at.z, gView.up.x, gView.up.y, gView.up.z);
    gSPMatrix(gMasterDisplayList++, D_8016E104, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    D_8016E3A4 = 0;
    func_8001838C();
    for(i = 0; i < 8; i++) {
        if ((gObjects[i].unkA4 != 0)) {
            if (func_8001C1A8(i, 0) != 0) {
                func_8001B014(i, 0);
                func_8001C384(i, 0);
            }
        }
    }
    Demo_HandlePrintText();
}

/**
 * Start the demo ID given.
 */
void Demo_Start(s32 demoID) {
    u32 unused;

    func_8001ECB8();
    D_8016526C = &func_8005E040;
    D_80165274 = &func_8005DD80;
    gView.at.x = 0.0f;
    gView.at.y = 0.0f;
    gView.at.z = 0.0f;
    gView.rot.x = 0.0f;
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 1.0f;
    func_80019B7C();
    func_80019C84();
    func_80019D2C();
    func_8001A258();
    func_8001E954(0x8024C000);
    func_8001E98C(0, &unk_bin_0_2_ROM_START, &unk_bin_0_2_ROM_END);
    DecompressFile(3, &_64C3C0_ROM_START, &_64C3C0_ROM_END);
    D_80134790 = 1;
    gDemoID = demoID;
    if (gDemoID == 0) {
        D_80134794 = &D_80101F18[0];
        gDemoSceneID = 0;
        PlayTrack_WithVolLoop(0x18, -1, 0);
    } else if (gDemoID == 1) {
        D_80134794 = &D_80101A14[0];
        gDemoSceneID = 0;
        PlayTrack_WithVolLoop(0x1D, -1, 0);
    } else if (gDemoID == 2) {
        D_80134794 = &D_80100720[5];
        gDemoSceneID = 5;
        PlayTrack_WithVolLoop(0x13, -1, 0);
    } else if (gDemoID == 3) {
        D_80134794 = &D_80100A90[5];
        gDemoSceneID = 5;
        PlayTrack_WithVolLoop(0x13, -1, 0);
    } else if (gDemoID == 4) {
        D_80134794 = &D_80100E00[5];
        gDemoSceneID = 5;
        PlayTrack_WithVolLoop(0x13, -1, 0);
    } else if (gDemoID == 5) {
        D_80134794 = &D_80101170[5];
        gDemoSceneID = 5;
        PlayTrack_WithVolLoop(0x13, -1, 0);
    } else if (gDemoID == 6) {
        D_80134794 = &D_80100720[0];
        gDemoSceneID = 0;
        PlayTrack_WithVolLoop(0x20, -1, 0);
    } else if (gDemoID == 7) {
        D_80134794 = &D_80100A90[0];
        gDemoSceneID = 0;
        PlayTrack_WithVolLoop(0x20, -1, 0);
    } else if (gDemoID == 8) {
        D_80134794 = &D_80100E00[0];
        gDemoSceneID = 0;
        PlayTrack_WithVolLoop(0x20, -1, 0);
    } else if (gDemoID == 9) {
        D_80134794 = &D_80101170[0];
        gDemoSceneID = 0;
        PlayTrack_WithVolLoop(0x20, -1, 0);
    }
    D_801347B0 = 0;
    D_801347E4 = 0;
    D_801347E5 = 0;
    D_801347E6 = 0;
    D_801347E8.strInfo = NULL;
    D_801347E8.x = 0x20;
    D_801347E8.y = 0xB8;
    D_801347E8.renderBG = 1;
    func_8001D244(0xFF, 0xFF, 0xFF, 0x10);
    func_8001D284();
    func_80000964();
}
