#include <ultra64.h>
#include "520E0.h"

void func_8005FBC0(void) {
}

void func_8005FBD0(void) {
    s16 sp6;
    s16 sp4;
    s16 sp2;
    for (sp6 = 0; sp6 < 6; sp6++) {
        for (sp4 = 0; sp4 < 3; sp4++) {
            for (sp2 = 0; sp2 < 7; sp2 = sp2 + 1) {
                D_80134808[(sp6 * 21) + sp4 * 7 + sp2] = 0;
            }
        }
    }

    D_80134808[0] = 6;
}

void func_8005FC98(s8 arg0, s8 arg1, s8 arg2, s8 arg3) {
    s16 sp6;
    s16 sp4;
    s16 sp2;

    for (sp6 = 0; sp6 < (arg0 - 1); sp6++) {
        for (sp4 = 0; sp4 < 3; sp4++) {
            for (sp2 = 0; sp2 < 7; sp2++) {
                D_80134808[(sp6 * 0x15) + (sp4 * 7) + sp2] = (u8) arg3;
            }
        }
    }

    for (sp4 = 0; sp4 < (arg1 - 1); sp4++) {
        for (sp2 = 0; sp2 < 7; sp2++) {
            D_801347F3[(arg0 * 0x15) + (sp4 * 7) + sp2] = arg3;
        }
    }

    for (sp2 = 0; sp2 < arg2; sp2++) {
        D_801347EC[(arg0 * 0x15) + (arg1 * 7) + sp2] = arg3;
    }
    D_801347EB[(arg0 * 0x15) + (arg1 * 7) + sp2] = 6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_8005FE88.s")

s32 func_800600B8(s8 arg0, s8 arg1) {
    s16 sp26;

    switch (arg0) {
        case 0: {
            for (sp26 = 0; sp26 < D_801039D4[arg1].Unk01; sp26++) {
                if (func_8005FE88(arg1, (s8) sp26) == 0) {
                    return 0;
                }
            }
            break;
        }
        case 1: {
            if (func_8005FE88(D_80134801, arg1) == 0) {
                return 0;
            }
            break;
        }
        case 2: {
            if ((D_80134808[(D_80134801 * 0x15) + (D_80134802 * 7) + arg1] & 0xF) == 0) {
                return 0;
            }
            if ((D_80134808[(D_80134801 * 0x15) + (D_80134802 * 7) + arg1] & 0xF) == 6) {
                return -2;
            }
            break;
        }
    }

    return -1;
}

void func_80060278(void) {
    s32 i;
    for (i = 0; i < 700; i++) {
        gFileArray[i].ptr = NULL;
    }
    Set_DecompressHeap(0x8024C000);
    LoadFile(0, unk_bin_0_2_ROM_START, unk_bin_0_2_ROM_END);

    // why compare like this??
    if (&D_80321428 != D_80324994) {
        DecompressFile(0x1A, &_64C3C0_ROM_START, &_64C3C0_ROM_END);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_8006031C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_800604A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_800608B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_80060F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_800623E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/520E0/func_800628C0.s")

s32 func_80062EAC(void) {
    s32 sp4;

    if (D_801039D0 != 0) {
        D_801039D0 -= 1;
    }
    sp4 = 0;
    if (D_801039D0 == 0) {
        if (*gContDirPressed & 0x100) {
            sp4 = 1;
        } else if (*gContDirPressed & 0x200) {
            sp4 = -1;
        } else if (*gContDirPressed & 0x800) {
            sp4 = 2;
        } else if (*gContDirPressed & 0x400) {
            sp4 = -2;
        }
        if (sp4 != 0) {
            D_801039D0 = 0xF;
        }
    } else if (*gContCurrDir & 0x100) {
        if (D_801039D0 == 1) {
            sp4 = 1;
            D_801039D0 = 4;
        }
    } else if (*gContCurrDir & 0x200) {
        if (D_801039D0 == 1) {
            sp4 = -1;
            D_801039D0 = 4;
        }
    } else if (*gContCurrDir & 0x800) {
        if (D_801039D0 == 1) {
            sp4 = 2;
            D_801039D0 = 4;
        }
    } else if (*gContCurrDir & 0x400) {
        if (D_801039D0 == 1) {
            sp4 = -2;
            D_801039D0 = 4;
        }
    } else {
        D_801039D0 = 0;
    }
    return sp4;
}

void func_80063104(void) {
    D_80134890 = NULL;
    D_80134894 = 0;
    D_80134898 = 0;
    D_8013489C = -1;
    D_801348A0 = 0;
    D_801348A4 = 0;
    D_801348A8 = 0;
    D_801348AC = 0;
}

void func_80063158(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 != -1) {
        D_80134890 = D_80103CDC[arg0];
        D_80134894 = arg1;
        D_80134898 = arg2;
    } else {
        D_80134890 = NULL;
    }
}

void func_800631A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    if (arg0 == -1) {
        D_8013489C = -1;
    } else {
        D_8013489C = arg0;
        D_801348A0 = arg1;
        D_801348A4 = arg2;
        D_801348A8 = arg3;
        D_801348AC = arg4;
    }
}

void func_80063200(s32 ulx, s32 uly, s32 lrx, s32 lry, s32 alpha) {
    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                   G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetCombineMode(gMasterDisplayList++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(gMasterDisplayList++, 0, 0, 0, 0, 0, alpha);
    gDPFillRectangle(gMasterDisplayList++, ulx, uly, lrx, lry);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gDPSetPrimColor(gMasterDisplayList++, 0, 0, 255, 255, 255, 255);
    gDPFillRectangle(gMasterDisplayList++, ulx, uly, lrx, uly + 1);
    gDPFillRectangle(gMasterDisplayList++, ulx, lry - 1, lrx, lry);
    gDPFillRectangle(gMasterDisplayList++, ulx, uly, ulx + 1, lry);
    gDPFillRectangle(gMasterDisplayList++, lrx - 1, uly, lrx, lry);
}

void func_8006357C(void) {
    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                   G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetTexturePersp(gMasterDisplayList++, G_TP_NONE);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gDPSetCombineMode(gMasterDisplayList++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetColorDither(gMasterDisplayList++, G_CD_BAYER);
    gDPSetTextureFilter(gMasterDisplayList++, G_TF_BILERP);
    gDPSetTextureLUT(gMasterDisplayList++, G_TT_RGBA16);
    gDPSetTextureImage(gMasterDisplayList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, gFileArray[0x1A].ptr + 0x10);
    gDPTileSync(gMasterDisplayList++);
    gDPSetTile(gMasterDisplayList++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMasterDisplayList++);
    gDPLoadTLUTCmd(gMasterDisplayList++, G_TX_LOADTILE, 15);
    gDPPipeSync(gMasterDisplayList++);
}

void func_8006389C(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    gDPLoadTextureTile_4b(gMasterDisplayList++, (gFileArray[0x1A].ptr + 0x30), G_IM_FMT_CI, 256, 0, arg2, arg3,
                          arg2 + 8, arg3 + 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                          G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetTileSize(gMasterDisplayList++, G_TX_RENDERTILE, 0, 0, 64, 64);
    gSPTextureRectangle(gMasterDisplayList++, arg0 << 2, arg1 << 2, (arg0 + 8) << 2, (arg1 + 16) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
}

void func_80063BE8(s16 arg0, s32 arg1, s32 arg2) {
    func_8006389C((s16) arg1, (s16) arg2, (arg0 % 32) * 8, (arg0 / 32) * 0x10);
}

void func_80063C58(s32 arg0, s32 arg1, s32 arg2, s16* arg3) {
    s16 sp26;

    if (arg0 != 0) {
        while (TRUE) {
            if (*(arg3++) + 1 == 0) {
                arg0--;
                if (arg0 == 0) {
                    break;
                }
            }
        }
    }

    while (TRUE) {
        sp26 = *arg3++;

        if (sp26 == -1) {
            break;
        }
        func_8006389C(arg1, (s16) arg2, (sp26 % 32) * 8, (sp26 / 32) * 0x10);
        arg1 += 8;
    }
}

void func_80063D7C(void) {
    s16* sp24;
    s16 sp22;
    s16 sp20;
    s16 sp1E;

    if (D_80134890 == NULL) {
        return;
    }
    func_8006357C();
    sp20 = (s16) D_80134894;
    sp1E = (s16) D_80134898;
    sp22 = D_80134890->unk8;
    sp24 = &D_80134890->unkA;

    while (TRUE) {
        if (*sp24 == -1) {
            sp22--;

            if (sp22 == 0) {
                break;
            }
            sp1E += 16;
            sp20 = (s16) D_80134894;
        } else {
            func_8006389C((s32) sp20, sp1E, (*sp24 % 32) * 8, (*sp24 / 32) * 16);
            sp20 += 8;
        }
        sp24++;
    }
}
