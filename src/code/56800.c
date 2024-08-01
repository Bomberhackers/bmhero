#include <ultra64.h>

//LEVEL LOADING RELATED FILE

//find free slot
s32 func_800642E0(void) {
    s32 i;
    
    for(i = 14; i < 78; i++) {
        if(gObjects[i].unkA4 == 0) {
            return i;
        }
    }
    return -1;
}

//find free slot above N slot
s32 func_80064358(s32 arg0) {
    while(arg0 < 78) {
        if (gObjects[arg0].unkA4 == 0) {
            return arg0;
        }
        arg0++;
    }
    return -1;
}

void func_800643C0(s32 id, f32* sPtr, f32* tPtr, s32 width, s32 height, s32 isRGBA16, s32 xlu, u32 timg, u32 dram, struct UnkInputStruct800643C0_arg9 *arg9) {
    s32 s;
    s32 t;
    s32 i;

    for (i = 0; i < 4; i++) {
        D_80176458[id].vertices[i].n.ob[0] = arg9[i].unk02[0];
        D_80176458[id].vertices[i].n.ob[1] = arg9[i].unk02[1];
        D_80176458[id].vertices[i].n.ob[2] = arg9[i].unk02[2];
        D_80176458[id].vertices[i].n.flag = 0;
        D_80176458[id].vertices[i].n.n[0] = 0;
        D_80176458[id].vertices[i].n.n[1] = 0;
        D_80176458[id].vertices[i].n.n[2] = 0;
        D_80176458[id].vertices[i].n.tc[0] = arg9[i].unk08;
        D_80176458[id].vertices[i].n.tc[1] = arg9[i + 1].unk00s16; // But fixing that line breaks this line...
        D_80176458[id].vertices[i].n.a = (u32)(u8)arg9[0].unk00s16;// -> because it causes problems here... ^^^
    }
    
    s = *sPtr;
    t = *tPtr;

    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BACK);
    gDPSetColorDither(gMasterDisplayList++, G_CD_BAYER);
    gDPPipelineMode(gMasterDisplayList++, G_PM_NPRIMITIVE);
    gDPSetTextureFilter(gMasterDisplayList++, G_TF_BILERP);
    gDPSetTexturePersp(gMasterDisplayList++, G_TP_PERSP);
    gDPSetCombineMode(gMasterDisplayList++, G_CC_DECALRGB, G_CC_DECALRGB);
    gSPTexture(gMasterDisplayList++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);

    if (xlu) {
        gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    } else {
        gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    }
    if (isRGBA16 == FALSE) {
        gDPSetTextureLUT(gMasterDisplayList++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gMasterDisplayList++, 0, dram);
        gDPLoadTextureBlock_4b(gMasterDisplayList++, timg, G_IM_FMT_CI, width, height, 0, \
            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    } else {
        gDPSetTextureLUT(gMasterDisplayList++, G_TT_NONE);
        gDPLoadTextureBlock(gMasterDisplayList++, timg, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0, \
            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    }
    gDPSetTileSize(gMasterDisplayList++, G_TX_RENDERTILE, s * 4, t * 4, (s + width) * 4, (t + height) * 4);
    gSPVertex(gMasterDisplayList++, D_80176458[id].vertices, 4, 0);
    gSP1Triangle(gMasterDisplayList++, 0, 1, 2, 0);
    gSP1Triangle(gMasterDisplayList++, 2, 3, 0, 0);
    gSPTexture(gMasterDisplayList++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800650F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800654AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800657E8.s")

s32 func_80065ACC(void) {
    return D_80177778;
}

void func_80065AEC(f32 arg0, f32 arg1, f32 arg2, s32* arg3, s32* arg4, s32* arg5) {
    *arg3 = (s32) (((arg0 - (f32) D_80177788) / 60.0f) / 16.0f);
    *arg4 = (s32) (((arg1 - (f32) D_80177798) / 60.0f) / 16.0f);
    *arg5 = (s32) (((arg2 - (f32) D_801777A8) / 60.0f) / 16.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80065C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80065D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800660DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800663EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800669E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80066AE8.s")

void func_8006707C(void) {
    s32 sp1C;

    func_80066AE8();
    for(sp1C = 0x4E; sp1C < 0x8E; sp1C++)
    {
        func_8001A928(sp1C);
    }
    func_80065C20();
    func_800669E0();
    func_800650F0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800670E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80067238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800673D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800675DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80067674.s")

void func_8006770C(void) {
    func_800675DC();
    func_80067674();
    D_801776E0 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80067748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006828C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800682E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80068CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800695A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800697F0.s")

s32 func_800699B0(void) {
    u8 sp1F;
    s32 sp18;

    if(func_800254E8(D_8013488C) != 0)
    {
        sp18 = 0;
        for(sp1F = 0; sp1F < 5; sp1F++)
        {
            if (func_800697F0(sp1F) == 0) {
                sp18 += 1;
            }
        }
        if (sp18 >= 5) {
            return 1;
        }
    }

    return 0;
}

s32 func_80069A54(s8 arg0, s8 arg1) {
    if (D_8016E3CC != 0) {
        return 0;
    }
    D_8016E3CC = arg0;
    D_8016E3CD = arg1;
    return 1;
}

void func_80069AA8(s8 arg0, s8 arg1) {
    D_8016E3CC = arg0;
    D_8016E3CD = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069AD8.s")

void func_80069D04(s32 arg0, s32 arg1) {
    if (D_8016E3CC != 0) {
        return;
    }
    if (D_8017753C->unk108 == 0) {
        return;
    }
    func_80069AD8(arg0, arg1);
    D_8016E3CC = 2;
}


void func_80069D88(s32 arg0, s32 arg1) {
    if (D_8016E3CC != 0) {
        return;
    }
    if (D_8017753C->unk108 == 0) {
        return;
    }
    func_80069AD8(arg0, arg1);
}

void func_80069E00(s32 arg0, s32 arg1) {
    func_80069AD8(arg0, arg1);
}

void func_80069E38(void) {
    D_801778F4 = 0;
    D_801778FC = 0;
    D_80177904 = 0;
}

void func_80069E60(s32 arg0, s32 arg1, s32 arg2) {
    D_801778F4 = arg2;
    D_801778FC = arg0;
    D_80177904 = arg1;
}

void func_80069E88(void) {
    if (D_801778F4 == 0) {
        return;
    }
    D_801778F4 -= 1;
    if (D_801778F4 != 0) {
        return;
    }
    func_80069D88(D_801778FC, D_80177904);
}

//looks like this is handling level loading in some way
void func_80069F0C(s32 arg0) {
    if(arg0 != 0)
    {
        gCurrentLevel = D_80106DA1[D_80134801 * 0x2A + D_80134802 * 0xE + D_80134803 * 2];
    }
    else
    {
        gCurrentLevel = D_80106DA0[D_80134801 * 0x2A + D_80134802 * 0xE + D_80134803 * 2];
    }
}

void func_80069FD8(void) {
    struct LevelInfo* sp4;

    sp4 = gLevelInfo[gCurrentLevel];
    D_80134801 = sp4->Stage - 1;
    D_80134802 = sp4->Area - 1;
    D_80134803 = sp4->Map - 1;
}

s32 func_8006A054(void) {
    u8 sp7;

    sp7 = D_80134808[(D_80134801 * 0x15) + (D_80134802 * 7) + D_80134803] & 0xF;
    if ((sp7 == 0) || (sp7 == 6)) {
        return 0;
    }
    return 1;
}

s32 func_8006A0E4(void) {
    u8 sp7;

    sp7 = D_80134808[D_80134801 * 0x15 + D_80134802 * 7 + D_80134803] & 0xF;
    if (sp7 == 0) {
        return 0;
    }

    return 1;
}

void func_8006A168(void) {
    s32 sp1C;

    if (D_8016E3D4 == 0) {
        gCurrentLevel = (s32) D_8016E432;
    } else {
        sp1C = gCurrentLevel;
        gCurrentLevel = (s32) D_8016E432;
        func_80069FD8();
        if (func_8006A054() != 0) {
            gCurrentLevel = sp1C;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006A1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006A2AC.s")

void func_8006A2BC(void) {
    u8 sp1F;

    sp1F = D_80134808[(D_80134801 * 0x15) + (D_80134802 * 7) + D_80134803] & 0xF0;
    D_80134808[(D_80134801 * 0x15) + (D_80134802 * 7) + D_80134803] = sp1F | 6;
    func_800250A0(D_8013488C);
}

void func_8006A388(void) {
    u8 sp1F;

    sp1F = D_80134808[0x69];
    if (!(sp1F & 0xF)) {
        sp1F &= 0xF0;
        D_80134808[0x69] = (u8) (sp1F | 6);
        func_800250A0(D_8013488C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006A404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006A898.s")

void func_8006A95C(void) {
    if (D_80177628 == 0) {
        return;
    }
    if ((gScore == 0) || (D_801775FA == D_801775F6)) {
        D_8016E3CC = 3;
        D_8016E3CD = 1;
        if (gScore == 0) {
            func_80070664(2);
        } else {
            func_80070664(3);
        }
    }
}

void func_8006AA0C(void) {
    D_80177640 = 0;
}

s32 func_8006AA24(s32 arg0) {
    if (D_80177640 == 0) {
        D_80177640 = arg0;
        return 1;
    }
    return 0;
}

/**
 * Calculate the min/sec/ms for the Slider Race timer.
 */
void Score_UpdateTimer(s32* min, s32* sec, s32* ms) {
    *min = (gScore / 1800); // FPS(30) * 60
    *sec = (gScore % 1800) / 30; // modulo to get the seconds
    *ms  = (gScore % 30) * 3.33333;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006AB14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_8006AD28.s")

/**
 * Update the score value.
 */
void Score_Update(s16 c) {
    if (D_801779E0 != 0) {
        return;
    }
    // increase the score by the amount.
    gScore += c;
    // if the score got reduced below 0, cap it to 0.
    if (gScore <= 0) {
        gScore = 0;
    } 
    // if the score went above the maximum 99990 (score is multiplied by
    // 10 to show the display amount), cap it to 9999.
    else if (gScore >= 9999) {
        gScore = 9999;
    }
}
