#include <ultra64.h>

u8 D_8024C000_unk_bin_0_2[] = {
#include "build/assets/unk_127FF0.ia4.inc"
};

u32 D_8024C200_unk_bin_0_2[] = { 0x00000001, 0x00000000, 0xB8000000, 0x00000000, 0x001E0000, 0xFFE20000, 0x04000400,
                                 0x007F0096, 0xFFE20000, 0xFFE20000, 0x00000400, 0x007F0096, 0xFFE20000, 0x001E0000,
                                 0x00000000, 0x007F0096, 0x001E0000, 0x001E0000, 0x04000000, 0x007F0096, 0xFFE20000,
                                 0xFFE20000, 0x00000000, 0x00000000, 0xFFE20000, 0x001E0000, 0x00000000, 0x00000000,
                                 0x001E0000, 0x001E0000, 0x00000000, 0x00000000, 0x001E0000, 0xFFE20000, 0x00000000,
                                 0x00000000, 0xFFE20000, 0xFFE20000, 0x00000000, 0x00000000, 0xFFE20000, 0x001E0000,
                                 0x00000000, 0x00000000, 0x001E0000, 0x001E0000, 0x00000000, 0x00000000, 0x001E0000,
                                 0xFFE20000, 0x00000000, 0x00000000 };

u8 D_8024C2D0_unk_bin_0_2[] = {
#include "build/assets/unk_1282C0.ia4.inc"
};

u32 D_8024C4D0_unk_bin_0_2[] = { 0x00000001, 0x00000000, 0xB8000000, 0x00000000, 0x001E0000, 0xFFE20000, 0x04000400,
                                 0x007F0096, 0xFFE20000, 0xFFE20000, 0x00000400, 0x007F0096, 0xFFE20000, 0x001E0000,
                                 0x00000000, 0x007F0096, 0x001E0000, 0x001E0000, 0x04000000, 0x007F0096, 0xFFE20000,
                                 0xFFE20000, 0x00000000, 0x00000000, 0xFFE20000, 0x001E0000, 0x00000000, 0x00000000,
                                 0x001E0000, 0x001E0000, 0x00000000, 0x00000000, 0x001E0000, 0xFFE20000, 0x00000000,
                                 0x00000000, 0xFFE20000, 0xFFE20000, 0x00000000, 0x00000000, 0xFFE20000, 0x001E0000,
                                 0x00000000, 0x00000000, 0x001E0000, 0x001E0000, 0x00000000, 0x00000000, 0x001E0000,
                                 0xFFE20000, 0x00000000, 0x00000000 };

Gfx D_8024C5A0_unk_bin_0_2[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                          G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_DECAL, G_RM_AA_ZB_XLU_DECAL2),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x01),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsSPVertex(&D_01000250_unk_bin_0_2[0], 8, 0),
    gsSPCullDisplayList(0, 7),
    gsMoveWd(G_MW_LIGHTCOL, G_MWO_aLIGHT_2, 0xC8C8C800),
    gsMoveWd(G_MW_LIGHTCOL, G_MWO_bLIGHT_2, 0xC8C8C800),
    gsMoveWd(G_MW_LIGHTCOL, G_MWO_aLIGHT_3, 0x64646400),
    gsMoveWd(G_MW_LIGHTCOL, G_MWO_bLIGHT_3, 0x64646400),
    gsSPEndDisplayList(),
};

Gfx D_8024C630_unk_bin_0_2[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsSPVertex(&D_01000210_unk_bin_0_2[0], 4, 0),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_01000200_unk_bin_0_2),
    gsDPLoadTextureBlock_4b(D_01000000_unk_bin_0_2, G_IM_FMT_CI, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPEndDisplayList(),
};

Gfx D_8024C6C8_unk_bin_0_2[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
    gsSPVertex(&D_010004E0_unk_bin_0_2[0], 4, 0),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, D_010004D0_unk_bin_0_2),
    gsDPLoadTextureBlock_4b(D_010002D0_unk_bin_0_2, G_IM_FMT_CI, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPEndDisplayList(),
};

Gfx D_8024C760_unk_bin_0_2[] = {
    gsSPEndDisplayList(),
};

u8 D_8024C768_unk_bin_0_2[] = {
#include "build/assets/unk_128758.ia8.inc"
};

u32 D_8024CB68_unk_bin_0_2[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000 };

Gfx D_8024CB78_unk_bin_0_2[] = {
    gsDPSetEnvColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0x00),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetFogColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetFillColor(0x00000000),
    gsDPSetPrimDepth(0, 0),
    gsDPSetConvert(0, 0, 0, 0, 0, 0),
    gsDPSetKeyR(0x00000000, 0x00, 0),
    gsDPSetKeyGB(0x00000000, 0x00, 0, 0x00000000, 0x00, 0),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 320, 240),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 320, 240),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_8024CC50_unk_bin_0_2[] = {
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetColorDither(G_CD_BAYER),
    gsSPEndDisplayList(),
};

Gfx D_8024CC68_unk_bin_0_2[] = {
    gsSPViewport(&D_01000B68_unk_bin_0_2),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClipRatio(FRUSTRATIO_3),
    gsSPEndDisplayList(),
};

Gfx D_8024CCB0_unk_bin_0_2[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                          G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsSPSetLights2(gLightingSettings),
    gsSPEndDisplayList(),
};
