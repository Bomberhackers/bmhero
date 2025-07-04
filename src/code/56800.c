#include <ultra64.h>

struct ScoreTable {
    s16 scores[4];
    s16 maxScore;
};

extern struct ScoreTable D_8010B700[];
extern s8 D_80134800;

// LEVEL LOADING RELATED FILE

// find free slot above N slot
s32 func_800642E0(void) {
    s32 i;

    for (i = 14; i < 78; i++) {
        if (gObjects[i].actionState == 0) {
            return i;
        }
    }
    return -1;
}

// find free slot
s32 func_80064358(s32 arg0) {
    while (arg0 < 78) {
        if (gObjects[arg0].actionState == 0) {
            return arg0;
        }
        arg0++;
    }
    return -1;
}

void func_800643C0(s32 id, f32* sPtr, f32* tPtr, s32 width, s32 height, s32 isRGBA16, s32 xlu, u32 timg, u32 dram,
                   struct UnkInputStruct800643C0_arg9* arg9) {
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
        D_80176458[id].vertices[i].n.tc[1] = arg9[i + 1].unk00s16;    // But fixing that line breaks this line...
        D_80176458[id].vertices[i].n.a = (u32) (u8) arg9[0].unk00s16; // -> because it causes problems here... ^^^
    }
    s = *sPtr;
    t = *tPtr;

    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                   G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
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
        gDPLoadTextureBlock_4b(gMasterDisplayList++, timg, G_IM_FMT_CI, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                               G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    } else {
        gDPSetTextureLUT(gMasterDisplayList++, G_TT_NONE);
        gDPLoadTextureBlock(gMasterDisplayList++, timg, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    }

    gDPSetTileSize(gMasterDisplayList++, G_TX_RENDERTILE, s * 4, t * 4, (s + width) * 4, (t + height) * 4);
    gSPVertex(gMasterDisplayList++, D_80176458[id].vertices, 4, 0);
    gSP1Triangle(gMasterDisplayList++, 0, 1, 2, 0);
    gSP1Triangle(gMasterDisplayList++, 2, 3, 0, 0);
    gSPTexture(gMasterDisplayList++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
}

void func_800650F0(void) {
    s32 i;
    struct UnkStruct80177964* sp20;
    s32 fileID;

    sp20 = D_80177964;

    for (i = 0; i < 0xA; i++) {
        D_801765C0[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        D_80176458[i].unk40[0] = 0.0f;
        D_80176458[i].unk40[1] = 0.0f;
        D_80176458[i].unk40[2] = 0.0f;
        D_80176458[i].unk40[3] = 0.0f;
        D_80176458[i].unk50 = -1;
    }
    gFileArray[0x14].ptr = NULL;
    gFileArray[0x15].ptr = NULL;
    gFileArray[0x16].ptr = NULL;
    gFileArray[0x17].ptr = NULL;

    if (sp20 != NULL) {
        for (i = 0; i < 4; i++) {
            if (sp20[i].unk0 == -1) {
                break;
            }
            if (D_801765C0[sp20->unk0] == 0) {
                for (fileID = 0x14; fileID < 0x18; fileID++) {
                    // is it not loaded?
                    if (gFileArray[fileID].ptr == NULL) {
                        DecompressFile(fileID, D_80104C20[sp20->unk0].romAddr, D_80104C20[sp20->unk0].size);
                        D_801765C0[sp20->unk0] = fileID;
                        break;
                    }
                }
            } else {
                fileID = D_801765C0[sp20->unk0];
            }
            D_80176458[i].unk40[0] = 0.0f;
            D_80176458[i].unk40[1] = 0.0f;
            D_80176458[i].unk40[2] = sp20[i].unk2C;
            D_80176458[i].unk40[3] = sp20[i].unk30;
            D_80176458[i].unk50 = fileID;
        }
    }
}

void func_800654AC(void) {
    s32 spC;
    s32 sp8;
    s32 i;
    struct UnkStruct800654AC_SP0* sp0;

    for (i = 0; i < 4; i++) {
        if (D_80176458[i].unk50 != -1) {
            sp0 = (void*) gFileArray[D_80176458[i].unk50].ptr;
            spC = sp0->unk8;
            sp8 = sp0->unkC;
            D_80176458[i].unk40[0] += D_80176458[i].unk40[2];
            if (D_80176458[i].unk40[0] < 0) {
                D_80176458[i].unk40[0] += spC;
            } else if (D_80176458[i].unk40[0] > spC) {
                D_80176458[i].unk40[0] -= spC;
            }
            D_80176458[i].unk40[1] += D_80176458[i].unk40[3];
            if (D_80176458[i].unk40[1] < 0) {
                D_80176458[i].unk40[1] += sp8;
            } else if (D_80176458[i].unk40[1] > sp8) {
                D_80176458[i].unk40[1] -= sp8;
            }
        }
    }
}

void func_800657E8(void) {
    s32 i;
    Matrix sp184;
    Matrix sp144;
    Matrix sp104;
    Matrix spC4;
    Matrix sp84;
    Matrix sp44;

    guTranslateF(sp184, 0.0f, 0.0f, 0.0f);
    guScaleF(sp144, 1.0f, 1.0f, 1.0f);
    guRotateF(sp104, 0.0f, 1.0f, 0.0f, 0.0f);
    guRotateF(spC4, 0.0f, 0.0f, 1.0f, 0.0f);
    guRotateF(sp84, 0.0f, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp84, spC4, sp84);
    guMtxCatF(sp84, sp104, sp84);
    guMtxCatF(sp84, sp144, sp84);
    guMtxCatF(sp84, sp184, sp84);
    guMtxL2F(sp44, &D_8016E104->unk00[2]);
    guMtxCatF(sp44, sp84, sp44);

    for (i = 0; i < 4; i++) {
        if (D_80176458[i].unk50 != -1) {
            struct UnkStruct800657E8_sp40* sp40;
            s32 sp3C;
            u8* sp38;

            guMtxF2L(sp44, &D_8016E104->unkE0[D_8016E3A4]);
            gSPMatrix(gMasterDisplayList++, &D_8016E104->unkE0[D_8016E3A4++], G_MTX_NOPUSH | G_MTX_LOAD);
            sp40 = (void*) gFileArray[D_80176458[i].unk50].ptr;
            sp3C = ((sp40->unk4 << 1) + (u32) sp40->unk7 & ~7) + 0x10;
            sp38 = (void*) (sp40 + 1);
            func_800643C0(i, &D_80176458[i].unk40[0], &D_80176458[i].unk40[1], sp40->unk7[1], sp40->unkC, 0, 1, sp3C,
                          sp38, &D_80177964[i]);
        }
    }
}

s32 func_80065ACC(void) {
    return D_80177778;
}

void func_80065AEC(f32 arg0, f32 arg1, f32 arg2, s32* arg3, s32* arg4, s32* arg5) {
    *arg3 = (s32) (((arg0 - (f32) D_80177788) / 60.0f) / 16.0f);
    *arg4 = (s32) (((arg1 - (f32) D_80177798) / 60.0f) / 16.0f);
    *arg5 = (s32) (((arg2 - (f32) D_801777A8) / 60.0f) / 16.0f);
}

void func_80065C20(void) {
    s32 i;
    s32 j;
    u32 fileID;
    s32 k;

    for (i = 0; i < (D_80177910 * D_80177914 * D_80177918); i++) {
        for (j = 0; j < 4; j++) {
            k = D_8017794C[i].unkB[j];
            if (k != 0xFF) {
                fileID = D_80122B08[k].unk0->unk14;
                if (gFileArray[fileID].ptr == NULL) {
                    DecompressFile(fileID, D_80122B08[k].romStart, D_80122B08[k].romEnd);
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80065D88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800660DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800663EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800669E0.s")

void func_80066AE8(void) {
    D_80177778 = *(u32*) gFileArray[0x1C].ptr;
    D_80177788 = D_80177778->unk0;
    D_80177798 = D_80177778->unk2;
    D_801777A8 = D_80177778->unk4;
    D_801777B8 = D_80177778->unk6;
    D_801777C8 = D_80177778->unk8;
    D_801777D8 = D_80177778->unkA;
    D_801777E8 = D_80177778->unkC;
    D_801778F0 = D_80177778->unkE;
    D_801778F8 = D_80177778->unk10;
    D_80177900 = D_80177778->unk12;
    D_80177908 = D_80177778->unk14;
    D_8017790C = D_80177778->unk16;
    D_80177910 = D_80177778->unk18;
    D_80177914 = D_80177778->unk1A;
    D_80177918 = D_80177778->unk1C;
    D_8017791C[0] = D_80177778->unk24;
    D_8017791C[1] = D_80177778->unk25;
    D_8017791C[2] = D_80177778->unk26;
    D_8017791C[3] = D_80177778->unk27;
    D_80177921 = D_80177778->unk28;
    D_80177928 = D_80177778->unk2A;
    D_8017792C = D_80177778->unk2B;
    D_8017792E = D_80177778->unk2C;
    D_80177930 = D_80177778->unk2D;
    D_80177932 = D_80177778->unk2E;
    D_80177934 = D_80177778->unk2F;
    D_80177938 = D_80177778->unk30;
    D_8017793A = D_80177778->unk31;
    D_8017793E = D_80177778->unk32;
    D_80177940 = D_80177778->unk33;
    D_80177944 = D_80177778->unk34;
    D_80177948 = D_80177778->unk36;
    D_8017794C = D_80177778->unk38;
    D_80177954 = D_80177778->unk3C;
    D_8017795C = D_80177778->unk40;
    D_80177964 = D_80177778->unk44;
    if (D_80108238[gCurrentLevel]->unk20 != -1) {
        D_80177928 = 1;
        D_8017792C = 0;
    }
    gDebugDispType = gLevelInfo[gCurrentLevel]->unk4;
    D_8017796C = (UnkStruct80165100*) D_8016E450;
    D_8017797C = gLevelInfo[gCurrentLevel]->unk18;
    D_80177984 = gLevelInfo[gCurrentLevel]->unk1C;
    D_8017798C = gLevelInfo[gCurrentLevel]->unkC;
    D_80177994 = gLevelInfo[gCurrentLevel]->unkE;
    D_8017799C = gLevelInfo[gCurrentLevel]->unk10;
    D_801779A4 = gLevelInfo[gCurrentLevel]->unk12;
    D_801779AC.raw = gLevelInfo[gCurrentLevel]->unk14;
    D_801779B8 = gLevelInfo[gCurrentLevel]->unk16;
    D_801779C8.raw = gLevelInfo[gCurrentLevel]->unk2C;
    D_801779E0.raw = gLevelInfo[gCurrentLevel]->unk6;
}

void func_8006707C(void) {
    s32 sp1C;

    func_80066AE8();
    for (sp1C = 0x4E; sp1C < 0x8E; sp1C++) {
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

void func_800695A0(void) {
    UnkStruct80165100* sp1C;
    struct UnkStruct_80026548_SP24* sp18;

    DecompressFile(0x43, (u32) &_9EC7B0_ROM_START, (u32) &_9ED1E0_ROM_START);
    DecompressFile(0x44, (u32) &_9ED1E0_ROM_START, (u32) &_9ED670_ROM_START);
    DecompressFile(0x45, (u32) &_9ED670_ROM_START, (u32) &_9ED920_ROM_START);

    sp1C = D_8017796C;
    while (sp1C->unk0 != -1) {
        sp18 = gObjInfo[sp1C->unk0].unk24;
        while (1) {
            if (gFileArray[sp18->unk0].ptr == NULL) {
                func_8001EB68(sp18->unk0, sp18->unk4, sp18->unk8);
            }
            if (sp18->unk2 == 0) {
                break;
            }
            sp18++;
        }
        sp1C++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_80069700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/56800/func_800697F0.s")

s32 func_800699B0(void) {
    u8 sp1F;
    s32 sp18;

    if (func_800254E8(D_8013488C) != 0) {
        sp18 = 0;
        for (sp1F = 0; sp1F < 5; sp1F++) {
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

void func_8007121C(void);

// Game_ClearLevel?
void func_80069AD8(s32 arg0, s32 arg1) {
    u8 sp1F;
    u8 sp1E;

    sp1F = gLevelInfo[gCurrentLevel]->Unk8[arg0 << 1];
    sp1E = gLevelInfo[gCurrentLevel]->Unk8[(arg0 << 1) + 1];
    D_8016E434 = (s16) gCurrentLevel;
    D_8016E430 = 0;
    D_8016E432 = (s16) sp1F;
    D_8016E438 = (f32) D_80108238[sp1F]->unk0[sp1E * 4];
    D_8016E43C = (f32) D_80108238[sp1F]->unk0[(sp1E * 4) + 1];
    D_8016E440 = (f32) D_80108238[sp1F]->unk0[(sp1E * 4) + 2];
    D_8016E444 = (f32) D_80108238[sp1F]->unk0[(sp1E * 4) + 3];
    if (gLevelInfo[gCurrentLevel]->Clear) {
        D_8016E3CC = 3;
    } else {
        D_8016E3CC = 2;
    }
    if (arg1 != 0) {
        D_80177620 = 1;
        func_8007121C();
        D_8016E3CD = 1;
    }
}

void func_80069D04(s32 arg0, s32 arg1) {
    if (D_8016E3CC != 0) {
        return;
    }
    if (gPlayerObject->damageState == 0) {
        return;
    }
    func_80069AD8(arg0, arg1);
    D_8016E3CC = 2;
}

void func_80069D88(s32 arg0, s32 arg1) {
    if (D_8016E3CC != 0) {
        return;
    }

    // If the player is already dead, don't clear the level
    if (gPlayerObject->damageState == OBJ_DEATH) {
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

// looks like this is handling level loading in some way
void func_80069F0C(s32 arg0) {
    if (arg0 != 0) {
        gCurrentLevel = D_80106DA1[D_80134801 * 0x2A + D_80134802 * 0xE + D_80134803 * 2];
    } else {
        gCurrentLevel = D_80106DA0[D_80134801 * 0x2A + D_80134802 * 0xE + D_80134803 * 2];
    }
}

void func_80069FD8(void) {
    struct LevelInfo* level = gLevelInfo[gCurrentLevel];

    D_80134801 = level->Stage - 1;
    D_80134802 = level->Area - 1;
    D_80134803 = level->Map - 1;
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
    s32 backupMapID;

    if (D_8016E3D4 == 0) {
        gCurrentLevel = D_8016E432;
    } else {
        backupMapID = gCurrentLevel;
        gCurrentLevel = D_8016E432;
        func_80069FD8();
        if (func_8006A054() != 0) {
            gCurrentLevel = backupMapID;
        }
    }
}

s32 func_8006A1F4(s32 arg0) {
    if (gLevelInfo[arg0]->Clear != 0) {
        arg0 = D_8016E432;
    } else {
        while (TRUE) {
            arg0 = *gLevelInfo[arg0]->Unk8;
            if (gLevelInfo[arg0]->Clear != 0) {
                break;
            }
        }
        arg0 = (s16) *gLevelInfo[arg0]->Unk8;
    }
    return arg0;
}

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

s32 func_8006A404(void) {
    s16 sp2E;
    s16 sp2C;
    s32 sp28;
    s32 sp24;
    u8 sp23;
    s8 sp22;

    func_8002598C(D_8013488C);
    sp24 = gCurrentLevel;
    func_80069FD8();
    if ((D_8016E3D4 == 0) && (func_800600B8(0, D_80134801) != 0)) {
        if (D_80134801 == 5) {
            sp23 = func_800253EC(D_8013488C);
            func_80025428(D_8013488C, sp23 | 4);
        } else if (D_80134801 == 4) {
            sp23 = func_800253EC(D_8013488C);
            func_80025428(D_8013488C, sp23 | 1);
        }
    }
    gCurrentLevel = sp24;

    for (sp28 = 0; sp28 < 4; sp28++) {
        if (gScore >= D_8010B700[gCurrentLevel].scores[sp28]) {
            break;
        }
    }
    sp2E = 5 - sp28;
    func_80069FD8();
    sp2C = D_80134808[(D_80134801 * 0x15) + (D_80134802 * 7) + D_80134803] & 0xF;
    if (sp2C >= 6) {
        sp2C = 0;
    }
    if (sp2C <= sp2E) {
        D_80134808[(D_80134801 * 0x15) + (D_80134802 * 7) + D_80134803] = sp2E;
    }
    if (func_800699B0() != 0) {
        sp23 = func_800253EC(D_8013488C);
        func_80025428(D_8013488C, sp23 | 2);
        func_8006A388();
    }
    func_80069FD8();
    func_800250A0((s32) D_8013488C);
    if (D_8016E3D4 == 0) {
        if (func_800600B8(0, D_80134801) != 0) {
            D_80134800 = 0;
        } else if (func_800600B8(1, D_80134802) != 0) {
            D_80134800 = 1;
        } else {
            D_80134800 = 2;
        }
        if (gCurrentLevel != 0x55) {
            sp24 = gCurrentLevel;
            gCurrentLevel = func_8006A1F4(gCurrentLevel);
            func_80069FD8();
            if (func_8006A054() == 0) {
                sp22 = 1;
                if (D_80134801 == 5) {
                    sp23 = func_800253EC(D_8013488C);
                    if (!(sp23 & 2)) {
                        sp22 = 0;
                    }
                }
                if (sp22 != 0) {
                    func_8006A2BC();
                    func_8002536C(D_8013488C, D_80134801, D_80134802, D_80134803, (s32) D_80134800);
                }
            }
            gCurrentLevel = sp24;
        }
    } else if (gCurrentLevel != 0x55) {
        sp24 = gCurrentLevel;
        gCurrentLevel = func_8006A1F4(gCurrentLevel);
        func_80069FD8();
        if (func_8006A0E4() == 0) {
            func_8006A2BC();
        }
        gCurrentLevel = sp24;
    }
    return sp2E & 0xF & 0xFF;
}

s32 func_8006A898(void) {
    s16 sp6;
    s32 sp0;

    D_80177600 += gScore;
    for (sp0 = 0; sp0 < 4; sp0++) {
        if (gScore >= D_8010B700[gCurrentLevel].scores[sp0]) {
            break;
        }
    }
    sp6 = 5 - sp0;
    return sp6 & 0xF & 0xFF;
}

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
    *min = (gScore / 1800);      // FPS(30) * 60
    *sec = (gScore % 1800) / 30; // modulo to get the seconds
    *ms = (gScore % 30) * 3.33333;
}

extern s8 D_80177610;
extern s16 D_80177618;

void func_8006AB14(void) {
    s32 sp4;
    s8 sp3;

    sp4 = 0;
    sp3 = gLevelInfo[gCurrentLevel]->unk34;
    if (sp3 == 0) {
        sp4 = 1;
    } else if (sp3 == 2) {
        if (gCurrentLevel == 0x30) {
            if (D_8016E434 != 0x2E) {
                sp4 = 1;
            }
        } else if (gCurrentLevel == 0x33) {
            if (D_8016E434 != 0x5C) {
                sp4 = 1;
            }
        } else if (gCurrentLevel == 0x43) {
            if (D_8016E434 != 0x5F) {
                sp4 = 1;
            }
        } else if (D_8016E3CC != 2) {
            sp4 = 1;
        }
    }
    if (sp4 != 0) {
        if (D_801779E0.raw == 3) {
            D_80177618 = 8;
            gScore = 0x3E8;
        } else if (D_801779E0.raw == 1) {
            D_80177618 = 8;
            gScore = 0x3E8;
        } else if (D_801779E0.raw == 2) {
            D_80177618 = 1;
            gScore = 0x3E8;
        } else {
            if (D_801779E0.raw == 5) {
                D_80177618 = 0x82;
                gScore = 0;
            } else {
                D_80177618 = 0;
                gScore = 0;
            }
        }
    }
    D_80177610 = 0;
}

void func_8006AD28(void) {
    if ((D_801778F4 != 0) || (D_8016E3CC != 0)) {
        return;
    }
    if (D_801779E0.raw == 3) {
        if ((D_80177618 == 0) && (gScore != 0)) {
            if (D_80177610 == 0) {
                gScore -= 1;
                D_80177610 = 4;
            } else {
                D_80177610 -= 1;
            }
        }
    } else if ((D_801779E0.raw == 2) || (D_801779E0.raw == 1)) {
        if (D_80177618 != 0) {
            D_80177618 -= 1;
        } else if (gScore != 0) {
            if (D_80177610 == 0) {
                gScore -= 1;
                D_80177610 = 4;
            } else {
                D_80177610 -= 1;
            }
        }
    } else if (D_801779E0.raw == 5) {
        if (D_80177618 != 0) {
            D_80177618 -= 1;
        } else if (gScore < 0x4650) {
            gScore += 1;
        }
    }
}

/**
 * Update the score value.
 */
void Score_Update(s16 c) {
    if (D_801779E0.raw != 0) {
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
