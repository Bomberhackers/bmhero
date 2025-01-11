#include <ultra64.h>
#include "malloc/malloc.h"
#include "1050.h"
#include "12AF0.h"
#include "17930.h"
#include "functions.h"

// Variables *only* used in this file
//.bss
extern char D_8016E111;
extern char D_8016E114;
extern char D_8016E116;
extern s16 D_8016E124;
extern s8 D_8016E11C;
extern char D_8016E12C;
extern s16 D_801776DE;
extern s16 D_801776E2;
extern s16 D_801776E8[];
extern s16 D_801776DA;

void func_80016D30(void)
{
    UNUSED s32 sp24;
    UNUSED s32 sp20;
    UNUSED s32 sp1C;

    sp24 = func_80003170();
    sp20 = func_800031CC();
    sp1C = func_800031E4();
}

void func_80016D74(s16 arg0)
{
    D_801776DA = arg0;
    func_80003214(D_801776DA);
}

s16 func_80016DB4(void)
{
    return D_801776DA;
}

s32 func_80016DD4(void)
{
    s32 i;

    for (i = 0; i < 1000000; i++)
    {
    }
    func_80003FE0(_38A1F0_ROM_START, 0, 0, 0, 0);
    func_8000ABEC(_229650_ROM_START, _229A60_ROM_START, _229A60_ROM_END, _230D50_ROM_START);
    func_80002E1C(0xC, 2, (void *)&D_8004D748, (void *)&D_80177A70, 0x493E0);
    func_80016D74(0);
}

void func_80016E84(void)
{
    s32 sp4;

    D_801776DA = 0;
    D_801776DE = 0;
    D_801776E2 = 0;

    for (sp4 = 0; sp4 < 4; sp4++)
    {
        D_801776E8[sp4] = -1;
    }
}

s32 func_8000401C(s16); /* extern */
s32 func_800041E0();    /* extern */

void func_80016EE4(void)
{
    if ((D_801776DE != 0) && (func_800041E0() == 0))
    {
        func_8000401C(D_801776E2);
    }
}

void PlayTrack_WithVolLoop(s16 trackID, s16 vol, s16 loop)
{
    if (trackID == -1)
    {
        func_80004284();
        D_801776DE = 0;
    }
    else
    {
        func_8000401C(trackID);
        if ((s16)vol != -1)
        {
            func_8000435C((s16)vol);
        }
        D_801776E2 = trackID;
        D_801776DE = (s16)loop;
    }
}

void func_80016FC8(s16 arg0)
{
    func_800042D8((s16)arg0);
}

void func_80016FF8(s32 arg0)
{
    func_8000435C((s16)(s8)arg0);
}

s16 func_80017028(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, u8 arg6)
{
    s16 sp1E;

    if ((arg5 != 0) && (arg1 == 0) && (func_8000B404(arg2) != -1))
    {
        return 0;
    }
    if (arg4 == 1)
    {
        if (arg0 != -1)
        {
            sp1E = gObjects[arg0].unk13C[arg1];
            if (sp1E != -1)
            {
                return sp1E;
            }
        }
    }
    else if (arg4 == 2)
    {
        sp1E = func_8000B404(arg2);
        if (sp1E != -1)
        {
            return sp1E;
        }
    }

    sp1E = func_8000AC1C(arg2);
    if (arg3 != -1)
    {
        func_8000C6F8(sp1E, arg3);
    }
    func_8000C7D4(sp1E, arg6);
    if (arg0 != -1)
    {
        gObjects[arg0].unk13C[arg1] = sp1E;
    }
    return sp1E;
}

u8 func_800171E0(s32 arg0)
{
    struct ObjectStruct *sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    if (arg0 == -1)
    {
        return 0x40;
    }
    sp3C = &gObjects[arg0];
    sp38 = func_80015634(sp3C->Pos.x - gView.at.x, sp3C->Pos.z - gView.at.z);
    sp34 = func_80015634(gView.eye.x - gView.at.x, gView.eye.z - gView.at.z);
    sp30 = sp3C->Pos.x - gView.at.x;
    sp2C = sp3C->Pos.z - gView.at.z;

    sp28 = sqrtf(SQ(sp30) + SQ(sp2C)) * sinf(((sp38 - sp34) * 0.0174532925199432955));
    if (sp28 >= 1000.0f)
    {
        sp28 = 1000.0f;
    }
    else if (sp28 <= -1000.0f)
    {
        sp28 = -1000.0f;
    }
    sp28 += 1000.0f;

    return (u32)((127.0f * sp28) / 2000.0f);
}

s16 func_80017460(s32 arg0)
{
    s32 sp2C;
    struct ObjectStruct *sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    s16 sp1A;

    if (arg0 == -1)
    {
        return -1;
    }
    sp28 = &gObjects[arg0];
    sp24 = gView.at.x - sp28->Pos.x;
    sp20 = gView.at.y - sp28->Pos.y;
    sp1C = gView.at.z - sp28->Pos.z;
    sp2C = (s32)sqrtf((sp24 * sp24) + SQ(sp20) + SQ(sp1C));
    if (sp2C >= 0x3C1)
    {
        sp2C = 0x3C0;
    }
    else if (sp2C < 0x1E0)
    {
        sp2C = 0x1E0;
    }
    sp1A = (s16)(0xEE20 / sp2C);
    return sp1A;
}

void func_800175F0(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4)
{
    func_80017028(arg0, arg1, arg2, arg3, arg4, 1, (u8)(func_800171E0(arg0)));
    return;
}

void func_80017664(s32 arg0, s32 arg1, s16 arg2, UNUSED s32 arg3, s32 arg4)
{
    func_80017028(arg0, arg1, (s16)arg2, func_80017460(arg0), arg4, 1, (func_800171E0(arg0)));
    return;
}

void func_800176F4(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4)
{
    func_80017028(arg0, arg1, arg2, arg3, arg4, 1, 0x40U);
    return;
}

void func_80017758(s32 arg0, s32 arg1, s16 arg2, UNUSED s32 arg3, s32 arg4)
{
    func_80017028(arg0, arg1, arg2, func_80017460(arg0), arg4, 1, 0x40U);
    return;
}

void func_800177D8(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4)
{
    func_80017028(arg0, arg1, arg2, arg3, arg4, 0, (u8)(func_800171E0(arg0)));
    return;
}

void func_80017848(s32 arg0, s32 arg1, s16 arg2, UNUSED s32 arg3, s32 arg4)
{
    func_80017028(arg0, arg1, arg2, func_80017460(arg0), arg4, 0, (u8)(func_800171E0(arg0)));
    return;
}

void func_800178D4(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4)
{
    func_80017028(arg0, arg1, (s16)arg2, (s16)arg3, arg4, 0, 0x40U);
    return;
}

void func_80017934(s32 arg0, s32 arg1, s16 arg2, UNUSED s32 arg3, s32 arg4)
{
    func_80017028(arg0, arg1, arg2, func_80017460(arg0), arg4, 0, 0x40U);
    return;
}

void func_800179B0(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4)
{
    s16 sp1E;
    s32 sp18;

    sp1E = gObjects[arg0].unk13C[arg1];
    if (sp1E == -1)
    {
        return;
    }
    sp18 = func_8000B4EC(sp1E);
    if ((sp18 == 2) || (sp18 == 0))
    {
        if (arg4 == 0)
        {
            sp1E = func_8000AC1C(arg2);
            if (arg3 != -1)
            {
                func_8000C6F8(sp1E, arg3);
            }
            gObjects[arg0].unk13C[arg1] = sp1E;
        }
        else
        {
            gObjects[arg0].unk13C[arg1] = -1;
        }
    }
}

void func_80017B04(s16 arg0)
{
    func_8000B404(arg0);
    return;
}

void func_80017B3C(s32 arg0, s32 arg1)
{
    s16 sp1E;

    sp1E = gObjects[arg0].unk13C[arg1];
    if (sp1E != -1)
    {
        func_8000B738(sp1E);
        gObjects[arg0].unk13C[arg1] = -1;
    }
}

s32 func_80017BEC(s32 arg0, s16 arg1, s16 arg2, s32 arg3)
{
    s16 sp1E;

    if (arg3 == 1)
    {
        sp1E = D_801776E8[arg0];
        if (sp1E != -1)
        {
            return sp1E;
        }
    }
    else if (arg3 == 2)
    {
        sp1E = func_8000B404((s16)arg1);
        if (sp1E != -1)
        {
            return sp1E;
        }
    }
    sp1E = func_8000AC1C((s16)arg1);
    if ((s16)arg2 != -1)
    {
        func_8000C6F8(sp1E, (s16)arg2);
    }
    D_801776E8[arg0] = sp1E;
    return sp1E;
}

void func_80017CFC(s32 arg0, s16 arg1, s16 arg2, s32 arg3)
{
    s16 sp1E;
    s32 sp18;

    sp1E = D_801776E8[arg0];
    if (sp1E == -1)
    {
        return;
    }
    sp18 = func_8000B4EC(sp1E);
    if ((sp18 == 2) || (sp18 == 0))
    {
        if (arg3 == 0)
        {
            sp1E = func_8000AC1C((s16)arg1);
            if ((s16)arg2 != -1)
            {
                func_8000C6F8(sp1E, (s16)arg2);
            }
            D_801776E8[arg0] = sp1E;
        }
        else
        {
            D_801776E8[arg0] = -1;
        }
    }
}

void func_80017DFC(s32 arg0)
{
    s16 sp1E;

    sp1E = D_801776E8[arg0];
    if (sp1E != -1)
    {
        func_8000B738(sp1E);
        D_801776E8[arg0] = -1;
    }
}

void func_80017E70(s16 arg0)
{
    func_8000B738(func_8000B404(arg0));
}

void func_80017EB8(void)
{
    func_8000B5DC();
}

void func_80017EE0(void)
{
    u16 sp36;
    UNUSED f32 sp30;

    sprintf(gDebugTextBuf, "A"); //??
    guPerspective(D_8016E104->unk00, &sp36, 50.0f, 1.3333334f, 100.0f, 20000.0f, 1.0f);
    guLookAt(&D_8016E104->unk00[2], gView.eye.x, gView.eye.y, gView.eye.z, gView.at.x, gView.at.y, gView.at.z, gView.up.x, gView.up.y, gView.up.z);
    sp30 = sqrtf(2.0f);
}

void printf(UNUSED char *str, ...)
{
}

s32 func_80017FF8(void)
{
    Lights2 *sp4 = gLevelInfo[gCurrentLevel]->unk20;

    if (sp4)
    {
        gLightingSettings = *sp4;

        if ((gCurrentLevel == MAP_FREEZE_LAKE) || (gCurrentLevel == MAP_SNOWLAND))
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

void func_800180C4(u32 arg0, u32 arg1)
{
    u32 *sp4;

    for (sp4 = arg0; (s32)sp4 < arg1; sp4++)
    {
        if ((sp4[0] == 0xBC00200A) && (sp4[2] == 0xBC00240A) && (sp4[4] == 0xBC00400A) && (sp4[6] == 0xBC00440A))
        {
            sp4[4] = 0;
            sp4[5] = 0;
            sp4[6] = 0;
            sp4[7] = 0;
            sp4 += 7;
        }
    }
}

void func_8001819C(void)
{
    gLightingSettings = D_8004A590;
}

void func_800181F0(void)
{
    u32 sp14;

    if ((s8)D_801775BC & 3)
    {
        if ((s8)D_801775BC & 1)
        {
            sp14 = (D_801775DC << 0x18) + (D_801775E4 << 0x10) + (D_801775EC << 8);
            gMoveWd(gMasterDisplayList++, G_MW_LIGHTCOL, G_MWO_aLIGHT_3, sp14);
            gMoveWd(gMasterDisplayList++, G_MW_LIGHTCOL, G_MWO_bLIGHT_3, sp14);
        }
        if ((s8)D_801775BC & 2)
        {
            sp14 = (D_801775C4 << 0x18) + (D_801775CC << 0x10) + (D_801775D4 << 8);
            gMoveWd(gMasterDisplayList++, G_MW_LIGHTCOL, G_MWO_aLIGHT_1, sp14);
            gMoveWd(gMasterDisplayList++, G_MW_LIGHTCOL, G_MWO_bLIGHT_1, sp14);
        }
    }
}

// fake
extern UNK_TYPE D_1000CB0;

void func_8001838C(void)
{
    gSPDisplayList(gMasterDisplayList++, &D_1000CB0);
    func_800181F0();
}

void func_800183E8(s32 r, s32 g, s32 b, s32 a, s32 arg4, s32 arg5)
{
    gDPPipeSync(gMasterDisplayList++);
    gDPSetCycleType(gMasterDisplayList++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetCombineLERP(gMasterDisplayList++, TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, TEXEL0, 0, SHADE, 0, 0, 0, 0, 1);
    gDPSetRenderMode(gMasterDisplayList++, AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | G_RM_FOG_SHADE_A, AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
    gDPSetFogColor(gMasterDisplayList++, r, g, b, a);
    gSPFogFactor(gMasterDisplayList++, (0x1F400 / (arg5 - arg4)), ((-1 * arg4) + 0x1F4) * 0x100 / (arg5 - arg4));
    gDPSetTextureFilter(gMasterDisplayList++, G_TF_BILERP);
    gDPSetTexturePersp(gMasterDisplayList++, G_TP_PERSP);
    gSPNumLights(gMasterDisplayList++, 2);
    gSPLight(gMasterDisplayList++, &gLightingSettings.l[0], 1);
    gSPLight(gMasterDisplayList++, &gLightingSettings.l[1], 2);
    gSPLight(gMasterDisplayList++, &gLightingSettings.a, 3);
}

void func_80018794(s32 r, s32 g, s32 b, s32 a, s32 arg4, s32 arg5)
{
    gDPPipeSync(gMasterDisplayList++);
    gDPSetCycleType(gMasterDisplayList++, G_CYC_2CYCLE);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetCombineLERP(gMasterDisplayList++, TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
    gDPSetFogColor(gMasterDisplayList++, r, g, b, a);
    gSPFogFactor(gMasterDisplayList++, (0x1F400 / (arg5 - arg4)), ((-1 * arg4) + 0x1F4) * 0x100 / (arg5 - arg4));
    gDPSetAlphaCompare(gMasterDisplayList++, G_AC_NONE);
    gDPSetAlphaDither(gMasterDisplayList++, G_AD_DISABLE);
    gDPSetColorDither(gMasterDisplayList++, G_CD_DISABLE);
    gDPSetBlendColor(gMasterDisplayList++, 0x00, 0x00, 0x00, 0x01);
    gDPSetTextureFilter(gMasterDisplayList++, G_TF_BILERP);
    gDPSetTexturePersp(gMasterDisplayList++, G_TP_PERSP);
    gSPNumLights(gMasterDisplayList++, 2);
    gSPLight(gMasterDisplayList++, &gLightingSettings.l[0], 1);
    gSPLight(gMasterDisplayList++, &gLightingSettings.l[1], 2);
    gSPLight(gMasterDisplayList++, &gLightingSettings.a, 3);
}

void func_80018C0C(void)
{
    Matrix spE0;
    Matrix spA0;
    Matrix sp60;
    Matrix sp20;
    guTranslateF(spE0, gView.eye.x, gView.eye.y, gView.eye.z);
    guRotateF(spA0, gView.rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(sp60, gView.rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(sp20, gView.rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp20, sp60, sp20);
    guMtxCatF(sp20, spA0, sp20);
    guMtxCatF(sp20, spE0, &gView.dist + 1);
}

void func_80018CF0(s32 arg0)
{
    Matrix sp120;
    Matrix spE0;
    Matrix spA0;
    Matrix sp60;
    Matrix sp20;

    guTranslateF(sp120, gObjects[arg0].Pos.x, gObjects[arg0].Pos.y, gObjects[arg0].Pos.z);
    guScaleF(spE0, gObjects[arg0].Scale.x, gObjects[arg0].Scale.y, gObjects[arg0].Scale.z);
    guRotateF(spA0, gObjects[arg0].Rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(sp60, gObjects[arg0].Rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(sp20, gObjects[arg0].Rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp20, sp60, sp20);
    guMtxCatF(sp20, spA0, sp20);
    guMtxCatF(sp20, spE0, sp20);
    guMtxCatF(sp20, sp120, gObjects[arg0].unk64);
    // fake
    guMtxCatF(gObjects[arg0].unk64, (f32(*)[1]) & gView.dist + 1, gObjects[arg0].unk64);
}

void func_80018EEC(s32 arg0, s32 arg1)
{
    Mtx sp20;

    func_80018CF0(arg0);
    guMtxF2L(gObjects[arg0].unk64, &sp20);
    if (arg1 != 0)
    {
        D_8016E104->unk00[1] = sp20;
    }
    else
    {
        D_8016E104->unkE0[D_8016E3A4] = sp20;
        gSPMatrix(gMasterDisplayList++, &D_8016E104->unkE0[D_8016E3A4++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW)
    }
}

void func_80019050(s32 arg0)
{
    Matrix sp178;
    Matrix sp138;
    Matrix spF8;

    Matrix spB8;
    Matrix sp78;
    Matrix sp38;
    s32 sp34;
    s32 sp30;

    guMtxIdentF(sp38);
    guTranslateF(sp178, gObjects[arg0].Pos.x, gObjects[arg0].Pos.y, gObjects[arg0].Pos.z);
    guScaleF(sp138, gObjects[arg0].Scale.x, gObjects[arg0].Scale.y, gObjects[arg0].Scale.z);
    guRotateF(spF8, gObjects[arg0].Rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF(spB8, gObjects[arg0].Rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF(sp78, gObjects[arg0].Rot.z, 0.0f, 0.0f, 1.0f);

    for (sp34 = 0; sp34 < 3; sp34++)
    {
        switch (gObjects[arg0].unk133[sp34])
        {
        case 0:
            guMtxCatF(sp38, sp178, sp38);
            break;
        case 1:
            guMtxCatF(sp38, sp138, sp38);
            break;
        case 2:
            for (sp30 = 0; sp30 < 3; sp30++)
            {
                switch (gObjects[arg0].unk136[sp30])
                {
                case 0:
                    guMtxCatF(sp38, spF8, sp38);
                    break;
                case 1:
                    guMtxCatF(sp38, spB8, sp38);
                    break;
                case 2:
                    guMtxCatF(sp38, sp78, sp38);
                    break;
                }
            }
            break;
        }
    }

    for (sp34 = 0; sp34 < 4; sp34++)
    {
        for (sp30 = 0; sp30 < 4; sp30++)
        {
            gObjects[arg0].unk64[sp34][sp30] = sp38[sp34][sp30];
        }
    }

    gObjects[arg0].unk139 = 1;
}

void func_800193CC(s32 arg0, char arg1, char arg2, char arg3)
{
    gObjects[arg0].unk133[0] = arg1;
    gObjects[arg0].unk133[1] = arg2;
    gObjects[arg0].unk133[2] = arg3;
}

void func_80019448(s32 arg0, char arg1, char arg2, char arg3)
{
    gObjects[arg0].unk136[0] = arg1;
    gObjects[arg0].unk136[1] = arg2;
    gObjects[arg0].unk136[2] = arg3;
}

void func_800194C4(s32 arg0)
{
    func_800193CC(arg0, 2, 1, 0);
    func_80019448(arg0, 2, 1, 0);
}

void func_8000E680(Matrix, Matrix); /* extern */

void func_80019510(s32 arg0, s32 arg1, s32 arg2)
{
    Mtx spA8;
    Matrix sp68;
    Matrix sp28;

    if (arg2 != 0)
    {
        func_80019050(arg0);
    }
    guMtxL2F(sp68, &D_8016E104->unk00[2]);
    guMtxCatF(gObjects[arg0].unk64, sp68, sp68);
    guMtxF2L(sp68, &spA8);
    if (arg1 == 0)
    {
        D_8016E104->unkE0[D_8016E3A4] = spA8;
        gSPMatrix(gMasterDisplayList++, &D_8016E104->unkE0[D_8016E3A4++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    }
    else if (arg1 == 1)
    {
        D_8016E3B4 = gObjects[arg0].Scale.x;
        D_8016E3BC = gObjects[arg0].Scale.y;
        D_8016E3C4 = gObjects[arg0].Scale.z;
        D_8016E104->unk00[1] = spA8;
    }
    else if (arg1 == 2)
    {
        guMtxIdentF(sp28);
        func_8000E680(sp28, sp68);
        func_80013B70(sp28, gObjects[arg0].Scale.x, gObjects[arg0].Scale.y, gObjects[arg0].Scale.z);
        guMtxCatF(sp28, sp68, sp68);
        guMtxF2L(sp68, &spA8);
        D_8016E104->unkE0[D_8016E3A4] = spA8;
        gSPMatrix(gMasterDisplayList++, &D_8016E104->unkE0[D_8016E3A4++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    }
    else if (arg1 == 3)
    {
        guMtxF2L(sp68, &spA8);
        D_8016E104->unkE0[D_8016E3A4] = spA8;
        gSPMatrix(gMasterDisplayList++, &D_8016E104->unkE0[D_8016E3A4++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    }
}

void func_8001994C(void)
{
    f32 sp2C;
    f32 sp28;

    if (D_8016E134 == 0)
    {
        sp2C = gView.rot.x;
        sp28 = gView.rot.y + 90.0f;
        if ((sp2C == 90.0f) || (sp2C == 270.0f))
        {
            sp2C -= 1.0f;
        }
        gView.eye.x = ((gView.dist * cosf((sp28 * 0.0174532925199432955))) * cosf((sp2C * 0.0174532925199432955))) + gView.at.x;
        gView.eye.y = (sinf((sp2C * 0.0174532925199432955)) * gView.dist) + gView.at.y;
        gView.eye.z = ((gView.dist * sinf((sp28 * 0.0174532925199432955))) * cosf((sp2C * 0.0174532925199432955))) + gView.at.z;
        if ((sp2C >= 90.0f) && (sp2C < 270.0f))
        {
            gView.up.y = -1.0f;
        }
        else
        {
            gView.up.y = 1.0f;
        }
    }
}

void func_80019B7C(void)
{
    s8 sp1F;

    sp1F = D_8016E134;
    D_8016E134 = 0;
    func_8001994C();
    D_8016E134 = sp1F;
}

void func_80019BC8(s32 arg0)
{
    D_80165290[arg0].unk24 = 0.0f;
    D_80165290[arg0].unk18 = 0;
    D_80165290[arg0].unk1C = 0;
    D_80165290[arg0].unk20 = 0;
    D_80165290[arg0].unk16 = 0;
    D_80165290[arg0].unk15 = 0;
    D_80165290[arg0].unk14 = 0;
}

void func_80019C84(void)
{
    s32 sp1C;

    for (sp1C = 0; sp1C < 256; sp1C++)
    {
        func_80019BC8(sp1C);
    }
}

void func_80019CCC(s32 arg0)
{
    D_8016C298[arg0].unk0 = NULL;
    D_8016C298[arg0].unk4 = 0;
    D_8016C298[arg0].unk5 = 0;
    D_8016C298[arg0].unk6 = 0;
    D_8016C298[arg0].unk7 = 0;
}

void func_80019D2C(void)
{
    s32 sp1C;

    for (sp1C = 0; sp1C < 0x100; sp1C++)
    {
        func_80019CCC(sp1C);
    }
}

/**
 * Initialize a specific game object by the index
 */
void Init_Obj(int index)
{
    struct ObjectStruct *obj;
    s32 i;

    obj = &gObjects[index];
    obj->unkA4 = 0;
    obj->unkA6 = 0;
    obj->unkA8 = 0;
    obj->unkAA = 0;
    obj->unkAC = 0;
    obj->unkAE = 0;
    obj->unkB0 = 0;
    obj->unkB2 = 0;
    obj->unkB4 = 0;
    obj->unkB6 = 0;
    obj->unkB8 = 0;
    obj->unkBA = 0;
    obj->unkBC = 0;
    obj->unkBE = 0;
    obj->unkC0 = 0;
    obj->unkC2 = 0;
    obj->unkC4 = 0;
    obj->unkC8 = 0;
    obj->unkCC = 0;
    obj->unkD0 = 0;
    obj->unkD4 = 0.0f;
    obj->unkD8 = 0.0f;
    obj->unkDC = 0.0f;
    obj->unkE0 = 0.0f;
    obj->unk132 = 0;
    obj->unkFC = -1;
    obj->unkE4 = 0;
    obj->unkE6[0] = -1;

    for (i = 0; i < 10; i++)
    {
        obj->unkE8[i] = -1;
        obj->unk10E[i] = -1;
    }

    obj->unkFE = 0;
    obj->unk100 = 1;
    obj->unk102 = 1;
    obj->unk103 = 0;
    obj->unk104 = -1;
    obj->unk108 = 0;
    obj->unk10A = 0;
    obj->unk10B = 0;
    obj->unk10C = 0;
    obj->unk106 = 0;
    obj->unk124 = 0.0f;
    obj->unk128 = 0.0f;
    obj->unk12C = 0.0f;
    obj->unk130 = 0;
    obj->unk131 = 0;
    obj->Pos.x = 0.0f;
    obj->Pos.y = 0.0f;
    obj->Pos.z = 0.0f;
    obj->Scale.x = 1.0f;
    obj->Scale.y = 1.0f;
    obj->Scale.z = 1.0f;
    obj->Rot.x = 0.0f;
    obj->Rot.y = 0.0f;
    obj->Rot.z = 0.0f;
    obj->Vel.x = 0.0f;
    obj->Vel.y = 0.0f;
    obj->Vel.z = 0.0f;
    obj->unk30.x = 0.0f;
    obj->unk30.y = 0.0f;
    obj->unk30.z = 0.0f;
    obj->unk3C = 0.0f;
    obj->unk40 = 0.0f;
    obj->unk44 = 0.0f;
    obj->unk48 = 0.0f;
    obj->unk4C = 0.0f;
    obj->unk5C = 0.0f;
    obj->unk60 = 0.0f;
    obj->unk13A = 0;
    obj->unk139 = 0;

    for (i = 0; i < 2; i++)
    {
        obj->unk13C[i] = -1;
    }

    for (i = 0; i < 4; i++)
    {
        obj->Unk140[i] = -1;
    }
    for (i = 0; i < 4; i++)
    {
        obj->Unk148[i] = -1;
    }
    func_800194C4(index);
}

void func_8001A258(void)
{
    s32 i;

    for (i = 0; i < 207; i++)
    {
        Init_Obj(i);
    }
}

void func_8001A2A0(void)
{
    D_8016E3AC = NULL;
    D_80055D50 = NULL;
    D_80055D54 = NULL;
    D_80055D58 = 0;
    D_80055D5C = NULL;
    D_80055D60 = 0;
    D_8004A3D0 = NULL;
    D_80055D64 = 0;
    D_8004A3D4 = 0;
    D_80055D68 = 0;
}

void func_8001A300(s32 id)
{
    struct UnkStruct80165290 *sp4;

    sp4 = &D_80165290[id];
    sp4->unk18 = D_8016E3AC;
    sp4->unk28 = D_80055D50;
    sp4->unk2C = D_80055D54;
    sp4->unk30 = D_80055D58;
    sp4->unk34 = D_80055D5C;
    sp4->unk38 = D_80055D60;
    sp4->unk3C = D_8004A3D0;
    sp4->unk40 = D_80055D64;
    sp4->unk44 = D_8004A3D4;
    sp4->unk48 = D_80055D68;
    sp4->unk4C = D_80055D30[0];
    sp4->unk50 = D_80055D30[1];
    sp4->unk54 = D_80055D30[2];
    sp4->unk58 = D_80055D40[0];
    sp4->unk5C = D_80055D40[1];
    sp4->unk60 = D_80055D40[2];
}

void func_8001A488(s32 id)
{
    struct UnkStruct80165290 *sp4 = &D_80165290[id];

    D_8016E3AC = sp4->unk18;
    D_80055D50 = sp4->unk28;
    D_80055D54 = sp4->unk2C;
    D_80055D58 = sp4->unk30;
    D_80055D5C = sp4->unk34;
    D_80055D60 = sp4->unk38;
    D_8004A3D0 = sp4->unk3C;
    D_80055D64 = sp4->unk40;
    D_8004A3D4 = sp4->unk44;
    D_80055D68 = sp4->unk48;
    D_80055D30[0] = sp4->unk4C;
    D_80055D30[1] = sp4->unk50;
    D_80055D30[2] = sp4->unk54;
    D_80055D40[0] = sp4->unk58;
    D_80055D40[1] = sp4->unk5C;
    D_80055D40[2] = sp4->unk60;
}

void func_8001A5F8(s32 id)
{
    func_8001A488(id);
    if (D_80165290[id].unk20 != 0)
    {
        func_80011DD0(D_80165290[id].unk20);
        D_80165290[id].unk20 = 0;
    }
    if (D_80165290[id].unk1C != 0)
    {
        func_800105D8(D_80165290[id].unk1C);
        D_80165290[id].unk1C = 0;
    }
    if (D_8016E3AC != NULL)
    {
        func_80013A00(D_8016E3AC);
        D_80165290[id].unk18 = 0;
    }
}

void func_8001A738(s32 arg0, s32 arg1)
{
    s32 sp1C;

    if ((sp1C = gObjects[arg0].Unk140[arg1]) != -1)
    {
        func_8001A5F8(sp1C);
        func_80019BC8(sp1C);
        gObjects[arg0].Unk140[arg1] = -1;
    }
}

void func_8001A7E8(s32 arg0, s32 arg1)
{
    s32 sp1C;

    if ((sp1C = gObjects[arg0].Unk148[arg1]) != -1)
    {
        func_80019CCC(sp1C);
        gObjects[arg0].Unk148[arg1] = -1;
    }
}

void func_8001A88C(s32 arg0, s32 arg1)
{
    s32 sp1C;

    for (sp1C = 0; sp1C < 4; sp1C++)
    {
        func_8001A738(arg0, sp1C);
    }

    for (sp1C = 0; sp1C < 4; sp1C++)
    {
        func_8001A7E8(arg0, sp1C);
    }

    if (arg1)
    {
        Init_Obj(arg0);
    }
}

void func_8001A928(s32 arg0)
{
    func_8001A88C(arg0, 1);
}

void func_8001A958(s32 arg0)
{
    func_8001A88C(arg0, 0);
}

s32 func_8001A988(void)
{
    s32 sp4;

    for (sp4 = 0; sp4 < 0x100; sp4++)
    {
        if (D_8016E084 >= 0x100)
        {
            D_8016E084 = 0;
        }
        if (D_80165290[D_8016E084].unk18 == 0)
        {
            D_8016E084++;
            return D_8016E084 - 1;
        }
        else
        {
            D_8016E084++;
        }
    }
    D_8016E084 = 0x100;

    return D_8016E084 - 1;
}

s32 func_8001AA60(void)
{
    s32 sp4;

    for (sp4 = 0; sp4 < 0x100; sp4++)
    {
        if (D_8016E08C >= 0x100)
        {
            D_8016E08C = 0;
        }
        if (D_8016C298[D_8016E08C].unk0 == NULL)
        {
            D_8016E08C++;
            return D_8016E08C - 1;
        }
        else
        {
            D_8016E08C++;
        }
    }
    D_8016E08C = 0x100;
    return D_8016E08C - 1;
}

u8 func_8001AB30(s32 arg0)
{
    u8 **sp4;
    u8 sp3;

    sp4 = (u8 *)D_8016C298[arg0].unk0;
    sp3 = D_8016C298[arg0].unk5;
    return *(*sp4 + sp3);
}

u8 func_8001AB94(s32 arg0)
{
    return (D_8016C298[arg0].unk0->unk18);
}
u8 func_8001ABC4(s32 arg0)
{
    return D_8016C298[arg0].unk0->unk19;
}

extern u8 D_8004A5E0[];

void func_8001ABF4(s32 arg0, s32 arg1, s32 arg2, void *arg3)
{
    s32 sp1C;

    if ((sp1C = gObjects[arg0].Unk148[arg1]) != -1)
    {
        func_80019CCC(sp1C);
    }
    sp1C = func_8001AA60();
    gObjects[arg0].Unk148[arg1] = (s16)sp1C;
    D_8016C298[sp1C].unk0 = (struct UnkStruct8016C298_1 *)arg3;
    D_8016C298[sp1C].unk4 = func_8001AB30(sp1C);
    D_8016C298[sp1C].unk5 = 0;
    D_8016C298[sp1C].unk6 = 1;
    D_8016C298[sp1C].unk7 = (char)arg2;
    gObjects[arg0].unk130 &= ~D_8004A5E0[arg1];
}

void func_8001AD6C(s32 arg0)
{
    s32 sp24;
    struct UnkStruct8016C298 *sp20;
    s32 sp1C;
    struct UnkStruct8016C298_1 *sp18;

    for (sp24 = 0; sp24 < 4; sp24++)
    {
        if (((sp1C = gObjects[arg0].Unk148[sp24]) != -1) && !(gObjects[arg0].unk130 & D_8004A5E0[sp24]))
        {
            sp20 = &D_8016C298[sp1C];
            sp20->unk6 = (u8)sp20->unk6 & ~0xC;
            if ((u8)sp20->unk6 & 1)
            {
                if ((u8)sp20->unk4 != 0)
                {
                    sp20->unk4 = (u8)sp20->unk4 - 1;
                }
                else
                {
                    sp20->unk6 = (u8)sp20->unk6 | 4;
                    sp20->unk5 = (u8)sp20->unk5 + 1;
                    sp18 = sp20->unk0;
                    if (*(sp18->unk4 + (u8)sp20->unk5) == 0xFF)
                    {
                        gObjects[arg0].unk130 |= D_8004A5E0[sp24];
                        sp20->unk5 = (u8)sp20->unk5 - 1;
                    }
                    if (func_8001AB94(sp1C) == (u8)sp20->unk5)
                    {
                        sp20->unk6 = (u8)sp20->unk6 | 8;
                        if ((u8)sp20->unk6 & 2)
                        {
                            sp20->unk6 = (u8)sp20->unk6 & ~1;
                            sp20->unk5 = (u8)sp20->unk5 - 1;
                        }
                        else
                        {
                            sp20->unk5 = func_8001ABC4(sp1C);
                        }
                    }
                    sp20->unk4 = func_8001AB30(sp1C) - 1;
                }
            }
        }
    }
}

void func_8001B014(s32 arg0, s32 arg1)
{
    s32 sp1C;
    struct UnkStruct8016C298_1 *sp18;
    u8 *sp14;
    u32 sp10;
    s32 spC;
    u8 spB;

    for (sp1C = 0; sp1C < 4; sp1C++)
    {
        if (((spC = gObjects[arg0].Unk148[sp1C]) != -1))
        {
            if (D_8016C298[spC].unk7 == arg1)
            {
                sp18 = D_8016C298[spC].unk0;
                spB = D_8016C298[spC].unk5;
                if (sp18->unk4 != NULL)
                {
                    sp14 = &gFileArray[sp18->unk14].ptr[sp18->unkC[sp18->unk4[spB]]];
                    gMoveWd(gMasterDisplayList++, 6 | 2, sp18->unk16 * 4, OS_PHYSICAL_TO_K0(sp14));
                }
                if (sp18->unk8 != 0)
                {
                    sp10 = &gFileArray[sp18->unk14].ptr[sp18->unk10[sp18->unk8[spB]]];
                    gMoveWd(gMasterDisplayList++, 6 | 2, sp18->unk17 * 4, OS_PHYSICAL_TO_K0(sp10));
                }
            }
        }
    }
}

void func_8001B234(s32 arg0, s32 arg1, s32 arg2)
{
    s32 sp1C;
    struct UnkStruct8016C298_1 *sp18;
    u8 *sp14;
    u32 sp10;
    s32 spC;
    u8 spB;

    for (sp1C = 0; sp1C < 4; sp1C++)
    {
        if (((spC = gObjects[arg0].Unk148[sp1C]) != -1))
        {
            if (D_8016C298[spC].unk7 == arg1)
            {
                sp18 = D_8016C298[spC].unk0;
                spB = D_8016C298[spC].unk5;
                if (sp18->unk4 != NULL)
                {
                    sp14 = &gFileArray[arg2].ptr[sp18->unkC[sp18->unk4[spB]]];
                    gMoveWd(gMasterDisplayList++, 6 | 2, sp18->unk16 * 4, OS_PHYSICAL_TO_K0(sp14));
                }
                if (sp18->unk8 != 0)
                {
                    sp10 = &gFileArray[arg2].ptr[sp18->unk10[sp18->unk8[spB]]];
                    gMoveWd(gMasterDisplayList++, 6 | 2, sp18->unk17 * 4, OS_PHYSICAL_TO_K0(sp10));
                }
            }
        }
    }
}

s32 func_8001B44C(s32 arg0, s32 arg1)
{
    return D_80165290[gObjects[arg0].Unk140[arg1]].unk16 & 2;
}

s32 func_8001B4AC(s32 arg0, s32 arg1)
{
    s32 sp1C;

    sp1C = (s32)gObjects[arg0].Unk140[arg1];
    func_8001A488(sp1C);
    if (D_80165290[sp1C].unk24 >= (D_80055D5C[D_80165290[sp1C].unk15].unkC - 2))
    {
        return 1;
    }
    return 0;
}

f32 func_8001B580(s32 arg0, s32 arg1)
{
    s32 sp1C;

    sp1C = (s32)gObjects[arg0].Unk140[arg1];
    func_8001A488(sp1C);
    return (f32)D_80055D5C[D_80165290[sp1C].unk15].unkC;
}

f32 func_8001B62C(s32 arg0, s32 arg1)
{
    return ((s32)D_80165290[gObjects[arg0].Unk140[arg1]].unk24 / (2) << 1);
}

void func_8001B6BC(s32 arg0, s32 arg1, f32 arg2)
{
    D_80165290[gObjects[arg0].Unk140[arg1]].unk24 = arg2;
    D_80165290[gObjects[arg0].Unk140[arg1]].unk16 = 0;
}

void func_8001B754(s32 arg0, s32 arg1)
{
    D_80165290[gObjects[arg0].Unk140[arg1]].unk16 = D_80165290[gObjects[arg0].Unk140[arg1]].unk16 | 1;
}

void func_8001B7E8(s32 arg0, s32 arg1)
{
    D_80165290[gObjects[arg0].Unk140[arg1]].unk16 = D_80165290[gObjects[arg0].Unk140[arg1]].unk16 & ~1;
}

s32 func_8001B880(s32 arg0, s32 arg1)
{
    return D_80165290[gObjects[arg0].Unk140[arg1]].unk14;
}

s32 func_8001B8D8(s32 arg0, s32 arg1)
{
    return D_8016C298[gObjects[arg0].Unk148[arg1]].unk6 & 8;
}

s32 func_8001B930(s32 arg0, s32 arg1)
{
    struct UnkStruct8016C298 *sp1C;
    s32 sp18;

    sp18 = gObjects[arg0].Unk148[arg1];
    sp1C = &D_8016C298[sp18];
    if (((u8)sp1C->unk4 == 1) && (func_8001AB94(sp18) == ((u8)sp1C->unk5 + 1)))
    {
        return 1;
    }
    return 0;
}

void func_8001B9F8(s32 arg0, s32 arg1)
{
    D_8016C298[gObjects[arg0].Unk148[arg1]].unk6 = (u8)D_8016C298[gObjects[arg0].Unk148[arg1]].unk6 | 2;
}

void func_8001BA7C(s32 arg0, s32 arg1)
{
    D_8016C298[gObjects[arg0].Unk148[arg1]].unk6 = (u8)D_8016C298[gObjects[arg0].Unk148[arg1]].unk6 & ~2;
}

void func_8001BB04(s32 arg0, s32 arg1)
{
    gObjects[arg0].unk13A = arg1;
}

void func_8001BB34(s32 arg0, s32 arg1)
{
    if (arg1 != 0)
    {
        gObjects[arg0].unk130 = (u8)gObjects[arg0].unk130 | 1;
    }
    else
    {
        gObjects[arg0].unk130 = (u8)gObjects[arg0].unk130 & ~1;
    }
}

void func_8001BBDC(s32 arg0, s32 arg1)
{
    if (arg1 != 0)
    {
        gObjects[arg0].unk130 = (u8)gObjects[arg0].unk130 | 2;
    }
    else
    {
        gObjects[arg0].unk130 = (u8)gObjects[arg0].unk130 & ~2;
    }
}

void func_8001BC84(s32 arg0, s32 arg1, s32 arg2)
{
    if (arg2 != 0)
    {
        gObjects[arg0].unk130 |= D_8004A5E4[arg1];
    }
    else
    {
        gObjects[arg0].unk130 &= ~D_8004A5E4[arg1];
    }
}

void func_8001BD44(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 sp1C;

    if (gObjects[arg0].Unk140[arg1] != -1)
    {
        return;
    }
    sp1C = func_8001A988();
    gObjects[arg0].Unk140[arg1] = sp1C;
    D_80165290[sp1C].unk0 = arg3;
    func_8001A2A0();
    D_8016E3AC = func_800122F0(arg3);
    D_80165290[sp1C].unk1C = func_80010408(arg3, arg2);
    func_8001A300(sp1C);
}

void func_8001BE6C(s32 objID, s32 arg1, s32 arg2, s32 arg3)
{
    s32 sp1C;

    gObjects[objID].unkFE = arg2;
    sp1C = gObjects[objID].Unk140[arg1];
    func_8001A488(sp1C);
    if (D_80165290[sp1C].unk20 != 0)
    {
        func_80011DD0(D_80165290[sp1C].unk20);
        D_80165290[sp1C].unk20 = 0;
    }
    if (arg3 != 0)
    {
        if (D_8016E3AC != NULL)
        {
            func_80013A00(D_8016E3AC);
            D_8016E3AC = NULL;
        }
        D_8016E3AC = func_800122F0(arg3);
        D_80165290[sp1C].unk20 = func_8001191C(D_80165290[sp1C].unk1C, 0);
        D_80165290[sp1C].unk15 = 0;
    }
    else
    {
        D_80165290[sp1C].unk20 = func_8001191C(D_80165290[sp1C].unk1C, arg2);
        D_80165290[sp1C].unk15 = arg2;
    }
    D_80165290[sp1C].unk14 = arg2;
    D_80165290[sp1C].unk24 = 0.0f;
    D_80165290[sp1C].unk16 = 0;
    func_8001A300(sp1C);
}

void func_8001C0EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 *arg4)
{
    func_8001BE6C(arg0, arg1, arg2, (void *)&gFileArray[arg3].ptr[arg4[arg2]]);
}

void func_8001C158(s32 arg0, s32 arg1, s32 arg2)
{
    func_8001BE6C(arg0, arg1, 0, (void *)gFileArray[arg2].ptr);
}

s32 func_8001C1A8(s32 arg0, s32 arg1)
{
    func_80019510(arg0, 1, 1);
    if (!((u8)gObjects[arg0].unk130 & 1) && (gObjects[arg0].Unk140[arg1] != -1))
    {
        return 1;
    }
    return 0;
}

s32 func_8001C248(s32 arg0, s32 arg1)
{
    func_80019510(arg0, 1, 0);
    if (!(gObjects[arg0].unk130 & 1))
    {
        if (gObjects[arg0].Unk140[arg1] != -1)
        {
            return 1;
        }
    }
    return 0;
}

s32 func_8001C300(s32 arg0, s32 arg1)
{
    if (!((u8)gObjects[arg0].unk130 & 1) && (gObjects[arg0].Unk140[arg1] != -1))
    {
        return 1;
    }
    return 0;
}

void func_8001C384(s32 arg0, s32 arg1)
{
    s32 sp2C;
    s32 sp28;

    sp2C = (s32)gObjects[arg0].Unk140[arg1];
    func_8001A488(sp2C);
    sp28 = D_80165290[sp2C].unk0;
    D_8016E3A4 = func_8000FD9C(D_80165290[sp2C].unk1C, &gMasterDisplayList, sp28, sp28, sp28, sp28, D_8016E3A4);
}

void func_8001C464(void)
{
    struct ObjectStruct *sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    for (sp34 = &gObjects[0xE], sp30 = 14; sp30 < 0x4E; sp34++, sp30++)
    {
        if (sp34->unkA4 != 0)
        {
            func_80019510(sp30, 1, 1);
            if (!((u8)sp34->unk130 & 1) && !(sp34->unk131 & 2) && (((sp2C = sp34->Unk140[0]) != -1)))
            {
                func_8001838C();
                func_8001B014(sp30, 0);
                func_8001A488(sp2C);
                sp28 = D_80165290[sp2C].unk0;
                D_8016E3A4 = func_8000FD9C(D_80165290[sp2C].unk1C, &gMasterDisplayList, sp28, sp28, sp28, sp28, D_8016E3A4);
            }
        }
    }
}

void func_8001C5B8(void)
{
    struct ObjectStruct *sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    for (sp34 = &gObjects[0xE], sp30 = 14; sp30 < 0x4E; sp34++, sp30++)
    {
        if (sp34->unkA4 != 0)
        {
            if (!((u8)sp34->unk130 & 1) && !(sp34->unk131 & 2) && (((sp2C = sp34->Unk140[3]) != -1)))
            {
                func_80019510(sp30, 1, 0);
                func_8001838C();
                func_8001B014(sp30, 3);
                func_8001A488(sp2C);
                sp28 = D_80165290[sp2C].unk0;
                D_8016E3A4 = func_8000FD9C(D_80165290[sp2C].unk1C, &gMasterDisplayList, sp28, sp28, sp28, sp28, D_8016E3A4);
            }
        }
    }
}

void func_8001C70C(void)
{
    struct ObjectStruct *sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    for (sp3C = &gObjects[0x4E], sp38 = 0x4E; sp38 < 0x8E; sp3C++, sp38++)
    {
        if (sp3C->unkA4 != 0)
        {
            if ((char)gObjects[sp38].unk139 != 0)
            {
                func_80019510(sp38, 1, 0);
            }
            else
            {
                func_80019510(sp38, 1, 1);
            }
            for (sp2C = 0; sp2C < 2; sp2C++)
            {
                if (!((u8)sp3C->unk130 & 1) && ((sp34 = sp3C->Unk140[sp2C]) != -1))
                {
                    if (D_8017792C == 0)
                    {
                        func_8001838C();
                    }
                    else if (D_8017792C == 1)
                    {
                        func_800183E8((s32)D_8017793A, (s32)D_8017793E, (s32)D_80177940, 0xFF, (s32)D_80177944, (s32)D_80177948);
                    }
                    else
                    {
                        func_80018794((s32)D_8017793A, (s32)D_8017793E, (s32)D_80177940, 0xFF, (s32)D_80177944, (s32)D_80177948);
                    }
                    func_8001B014(sp38, sp2C);
                    func_8001A488(sp34);
                    sp30 = D_80165290[sp34].unk0;
                    D_8016E3A4 = func_8000FD9C(D_80165290[sp34].unk1C, &gMasterDisplayList, sp30, sp30, sp30, sp30, D_8016E3A4);
                }
            }
        }
    }
}

void func_8001C96C(void)
{
    struct ObjectStruct *sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    func_8001838C();
    for (sp34 = &gObjects[0x4E], sp30 = 0x4E; sp30 < 0x8E; sp34++, sp30++)
    {
        if ((sp34->unkA4 != 0))
        {
            if (!((u8)sp34->unk130 & 1) && ((sp2C = (s32)sp34->Unk140[3]) != -1))
            {
                func_80019510(sp30, 1, 0);
                func_8001B014(sp30, 3);
                func_8001A488(sp2C);
                sp28 = D_80165290[sp2C].unk0;
                D_8016E3A4 = func_8000FD9C(D_80165290[sp2C].unk1C, &gMasterDisplayList, sp28, sp28, sp28, sp28, D_8016E3A4);
            }
        }
    }
}

void func_8001CAAC(s32 arg0, f32 arg1)
{
    s32 sp1C;
    s32 sp18;

    if (!(gObjects[arg0].unk130 & 2))
    {
        for (sp1C = 0; sp1C < 4; sp1C++)
        {
            if ((sp18 = gObjects[arg0].Unk140[sp1C]) != -1)
            {
                func_8001A488(sp18);
                if (D_80165290[sp18].unk20 != 0)
                {
                    func_80011424(D_80165290[sp18].unk20, D_80165290[sp18].unk24);
                    D_80165290[sp18].unk24 += arg1;
                    if (D_80165290[sp18].unk24 >= (f32)D_80055D5C[D_80165290[sp18].unk15].unkC)
                    {
                        if (D_80165290[sp18].unk16 & 1)
                        {
                            D_80165290[sp18].unk24 -= arg1;
                        }
                        else
                        {
                            D_80165290[sp18].unk24 = 0.0f;
                        }
                        D_80165290[sp18].unk16 |= 2;
                    }
                    else
                    {
                        D_80165290[sp18].unk16 &= ~2;
                    }
                }
            }
        }
    }
}

void func_8001CD20(s32 arg0)
{
    func_8001CAAC(arg0, 2.0f);
}

void func_8001CD50(s32 arg0, f32 arg1)
{
    func_8001CAAC(arg0, arg1);
}

void func_8001CD88(s32 arg0, u32 arg1)
{
    func_80019510(arg0, 0, 1);
    gSPDisplayList(gMasterDisplayList++, arg1);
}

void func_8001CDF4(s32 arg0, s32 arg1, s32 arg2, struct UnkStruct_8001CDF4 *arg3)
{
    void *sp24;
    s32 *sp20;

    func_80019510(arg0, arg2, 1);
    gMoveWd(gMasterDisplayList++, 6 | 2, arg3->unk8 * 4, OS_PHYSICAL_TO_K0(arg3));

    sp20 = &arg3[arg1].unk4 + 5;
    sp24 = *sp20 + (char *)arg3;
    gSPDisplayList(gMasterDisplayList++, sp24);
}

void func_8001CEF4(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    sp1C->Pos.x += sp1C->Vel.x;
    sp1C->Pos.y += sp1C->Vel.y;
    sp1C->Pos.z += sp1C->Vel.z;
    sp1C->Rot.x = func_80015538(sp1C->Rot.x, sp1C->unk30.x);
    sp1C->Rot.y = func_80015538(sp1C->Rot.y, sp1C->unk30.y);
    sp1C->Rot.z = func_80015538(sp1C->Rot.z, sp1C->unk30.z);
}

void func_8001D000(s32 red, s32 green, s32 blue, s32 alpha)
{
    gDPPipeSync(gMasterDisplayList++);
    gDPSetCycleType(gMasterDisplayList++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetCombineMode(gMasterDisplayList++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(gMasterDisplayList++, 0, 0, red, green, blue, alpha);
    gDPFillRectangle(gMasterDisplayList++, 0, 0, 319, 239);
}

s32 func_8001D1D4(void)
{
    return (s32)D_8016E11C;
}

void func_8001D1F4(void)
{
    D_8016E11C = 0;
    D_8016E124 = 0;
    D_8016E111 = 255;
    D_8016E114 = 255;
    D_8016E116 = 255;
    D_8016E12C = 16;
}

void func_8001D244(char red, char green, char blue, char alpha)
{
    D_8016E111 = red;
    D_8016E114 = green;
    D_8016E116 = blue;
    D_8016E12C = alpha;
}

void func_8001D284(void)
{
    if ((D_8016E11C != -1) && (D_8016E11C != -2))
    {
        D_8016E11C = -1;
    }
}

void func_8001D2C0(void)
{
    if ((D_8016E11C != 1) && (D_8016E11C != 2))
    {
        D_8016E11C = 1;
    }
}

void func_8001D2FC(void)
{
    if ((D_8016E11C == 1) || (D_8016E11C == -1))
    {
        D_8016E124 += (u8)D_8016E12C * D_8016E11C;
        if (D_8016E11C < 0)
        {
            if (D_8016E124 <= 0)
            {
                D_8016E124 = 0;
                D_8016E11C = -2;
            }
        }
        else if (D_8016E124 >= 0xFF)
        {
            D_8016E124 = 0xFF;
            D_8016E11C = 2;
        }
    }
}

void func_8001D3CC(void)
{
    if ((D_8016E11C == 1) || (D_8016E11C == -1) || (D_8016E11C == 2))
    {
        func_8001D000(D_8016E111, D_8016E114, D_8016E116, D_8016E124);
    }
}

// TODO: Remove this fake symbols
extern char D_302B8[];
extern char D_302D8[];

extern UNK_TYPE D_80200000;
extern UNK_TYPE D_80225800;
void func_8001D440(void)
{
    D_80340000->unk18148[0] = 2;
    D_80340000->unk18168 = &D_80200000;
    *((s16 *)(D_302B8 + (s32)&D_80340000)) = 2;
    *((s32 *)(D_302D8 + (s32)&D_80340000)) = &D_80225800;
    osViSetSpecialFeatures(0x42);
}
extern UNK_TYPE D_801DA800;

void func_8001D4D0(void)
{
    gDPPipeSync(gMasterDisplayList++);
    gDPSetDepthImage(gMasterDisplayList++, osVirtualToPhysical(&D_801DA800));
    gDPSetCycleType(gMasterDisplayList++, G_CYC_FILL);
    gDPSetColorImage(gMasterDisplayList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(&D_801DA800));
    gDPSetFillColor(gMasterDisplayList++, 0xFFFCFFFC);
    gDPFillRectangle(gMasterDisplayList++, 0, 0, 319, 239);
}

void func_8001D638(s32 arg0, char red, char green, char blue)
{

    gDPPipeSync(gMasterDisplayList++);
    gDPSetColorImage(gMasterDisplayList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320,
                     osVirtualToPhysical(D_8016E10C->unk18168));

    if (arg0 != 0)
    {
        gDPSetFillColor(gMasterDisplayList++,
                        (GPACK_RGBA5551(red, green, blue, 1) << 16) | GPACK_RGBA5551(red, green, blue, 1));

        gDPFillRectangle(gMasterDisplayList++, 0, 0, 319, 239);
    }
    gDPPipeSync(gMasterDisplayList++);
    gDPSetCycleType(gMasterDisplayList++, G_CYC_1CYCLE);
}

void stub1()
{
}

void stub2()
{
}

void func_8001D814(void)
{
    struct UnkStruct8016E10C *sp1C;
    struct UnkStruct8016E10C *sp18 = D_8016E10C;
    sp1C = sp18;

    sp1C->task.t.data_ptr = &D_8016E104->gfxWork;
    /**
     * Here's whats happening here: the size of the GFX heap is being calculated here. At this
     * moment, gMasterDisplayList points to at least D_8016E104->gfxWork or later. gfxWork begins
     * at 0x80E0 into the GFX heap struct, so the offset needs to be removed from the pointer. Finally,
     * after that, we account for Gfx work itself to get the size of the display list being sent, and then
     * the size is clamped to a multiple of 64-bit due to Gfx being an array of 64-bit.
     */
    sp1C->task.t.data_size = ((s32)(((u32)gMasterDisplayList - (u32)D_8016E104 - 0x80E0)) >> 3) << 3;
    sp1C->task.t.type = 1;
    sp1C->task.t.flags = 0;
    sp1C->task.t.ucode_boot = (u64 *)rspbootTextStart;
    sp1C->task.t.ucode_boot_size = (u32)rspbootTextEnd - (u32)rspbootTextStart;
    sp1C->task.t.ucode = (u64 *)rspbootTextEnd; // this is probably F3DEX Data start. TODO: Rename
    sp1C->task.t.ucode_size = 0x1000;
    sp1C->task.t.ucode_data = (u64 *)gspF3DEX_fifoTextStart_bin;
    sp1C->task.t.ucode_data_size = 0x800;
    sp1C->task.t.dram_stack = D_801D04B0;
    sp1C->task.t.dram_stack_size = 0x400;
    sp1C->task.t.output_buff = (void *)&D_801C1A50;
    sp1C->task.t.output_buff_size = (void *)((u32)&D_801C1A50 + 0xEA60);
    sp1C->task.t.yield_data_ptr = &D_801C0E50;
    sp1C->task.t.yield_data_size = 0xC00;
    sp1C->unk0 = 0;
    sp1C->unk8 = 0x63;
    sp1C->unk50 = &D_8016E0B8;
    sp1C->unk54 = &sp18->unk18148;
    sp1C->unkC = sp18->unk18168;
    osSendMesg(D_8004D9D0, sp1C, 1);
}

// init system area?
void func_8001D9E4(void *arg0)
{
    func_8005F0F4();
    D_8016E10C = arg0;
    D_8016E104 = &D_8016E10C->unk68;
    gMasterDisplayList = &D_8016E10C->unk68.gfxWork;
    gSPSegment(gMasterDisplayList++, 0x00, 0x00000000);
    gSPSegment(gMasterDisplayList++, 0x01, osVirtualToPhysical(gFileArray[0].ptr));
    gSPDisplayList(gMasterDisplayList++, D_1000C68);

    if (D_80165254 == 1)
    {
        gSPDisplayList(gMasterDisplayList++, D_1000B78);
    }

    gSPDisplayList(gMasterDisplayList++, D_1000C50);
    if (D_80165254 == 0)
    {
        if ((D_8016E0A8 != 0) && (D_8016526C != NULL))
        {
            D_8016526C();
        }
    }
    else if (D_80165254 == 2)
    {
        D_80165254 = 0;
    }
    else
    {
        D_80165254 += 1;
    }
    func_8001D3CC();
    gDPFullSync(gMasterDisplayList++);
    gSPEndDisplayList(gMasterDisplayList++);

    osWritebackDCacheAll();
    func_8001D814();
}

void func_8001DC78(void)
{
    D_801776F8 = 0;
    D_80177708 = 0;
    D_80177718 = 0;
    D_80177728 = 0;
    D_80177738 = 0;
    D_80177748[0] = 0;
    D_80177758[0] = 0;
    D_80177768[0] = 0;
}

void func_8001DCD4(int arg0)
{
    D_80177708 = arg0;
}

void func_8001DCEC(void)
{
    s32 port;
    OSContPad *pad;

    if (D_80177708 == 0)
    {
        return;
    }
    // whats the point of setting this var? was there a for loop here?
    port = 0;
    if ((gControllerBits >> port) & 1)
    {
        pad = &gContPads[port];
        if (pad->errno != 0)
        {
            return;
        }
        D_80177748[port] = D_80177758[port];
        D_80177758[port] = pad->button;
        D_80177768[port] = (D_80177758[port] ^ D_80177748[port]) & D_80177758[port];
    }
    if (D_80177768[port] & 0x1000)
    {
        D_80177718 += 1;
        D_80177728 = 0;
    }
    else
    {
        D_80177728 += 1;
    }
    if (D_80177728 >= 7)
    {
        D_80177718 = 0;
        D_80177738 = 0;
    }
    if (D_80177738 == 0x3C)
    {
        if ((D_80177718 >= 0xA) && (D_80177718 < 0xF))
        {
            D_801776F8 = 1;
        }
        D_80177718 = 0;
        D_80177738 = 0;
    }
    else
    {
        D_80177738 += 1;
    }
}

/**
 * Update the active controller masks.
 */
void UpdateActiveController(u16 port)
{
    gActiveContPort = port;
    gActiveContButton = gContCurrButton[gActiveContPort];
    gActiveContPressed = gContButtonPressed[gActiveContPort];
    gActiveContStickX = gContStickX[gActiveContPort];
    gActiveContStickY = gContStickY[gActiveContPort];
    gActiveContCurrDir = gContCurrDir[gActiveContPort];
    gActiveContDirPressed = gContDirPressed[gActiveContPort];
}

/**
 * Setup the mesg queue for the controllers and init them.
 */
void InitControllers(void)
{
    s32 status;
    u16 i;

    gControllerBits = 0;
    osCreateMesgQueue(&gContMesgQueue, &D_801776CC, 1);
    osSetEventMesg(5U, &gContMesgQueue, (void *)1);
    status = osContInit(&gContMesgQueue, &gControllerBits, &D_80177650);
    if (status != 0)
    {
        // presumedly for handling if the controller had an error, but there's nothing here.
        // missing assert?
    }
    for (i = 0; i < 4; i++)
    {
        gContRawPlugged[i] = 0;
        gContRawLastButton[i] = 0;
        gContRawCurrButton[i] = 0;
        gContRawButtonPressed[i] = 0;
        gContRawStickX[i] = 0;
        gContRawStickY[i] = 0;
        gContRawCurrDir[i] = 0;
        gContRawLastDir[i] = 0;
        gContRawDirPressed[i] = 0;
        gContLastButton[i] = 0;
        gContCurrButton[i] = 0;
        gContButtonPressed[i] = 0;
        gContStickX[i] = 0;
        gContStickY[i] = 0;
        gContCurrDir[i] = 0;
        gContLastDir[i] = 0;
        gContDirPressed[i] = 0;
    }
    UpdateActiveController(0);
    func_8001DC78();
}

/**
 * Reset the active controller masks.
 */
void ResetActiveController(void)
{
    gActiveContButton = 0;
    gActiveContPressed = 0;
    gActiveContStickX = 0.0f;
    gActiveContStickY = 0.0f;
    gActiveContCurrDir = 0;
    gActiveContDirPressed = 0;
}

/**
 * Perform the reading of the raw arrays front the OSContPad data itself. This will be later read
 * into the buffers to be used during gameplay.
 */
void UpdateRawControllers(void)
{
    OSContPad *pad;
    u16 dir;
    u16 i;
    s32 status;

    status = 1;
    if (gControllerBits & 1)
    {
        status = osContStartReadData(&gContMesgQueue);
        if (status == 0)
        {
            osRecvMesg(&gContMesgQueue, NULL, 1);
            osContGetReadData(gContPads);
        }
    }
    for (i = 0; i < 4; i++)
    {
        if ((gControllerBits >> i) & 1)
        {
            pad = &gContPads[i];
            // if any errors occurred or if no controllers are plugged in, treat the controller as if its not plugged in.
            if ((pad->errno != 0) || (status != 0))
            {
                gContRawPlugged[i] = 0;
                ;
            }
            else
            {
                gContRawPlugged[i] = 1;
                dir = 0;
                gContRawStickX[i] = pad->stick_x;
                gContRawStickY[i] = pad->stick_y;
                if (gContRawStickX[i] >= 0x32)
                {
                    dir |= CONT_RIGHT;
                }
                else if (gContRawStickX[i] < -0x31)
                {
                    dir |= CONT_LEFT;
                }
                if (gContRawStickY[i] >= 0x32)
                {
                    dir |= CONT_UP;
                }
                else if (gContRawStickY[i] < -0x31)
                {
                    dir |= CONT_DOWN;
                }
                if (D_8016525C != 0)
                {
                    gContRawCurrButton[i] = 0;
                    gContRawCurrDir[i] = 0;
                }
                else if (D_80165284 == 1)
                {
                    gContRawLastButton[i] = gContRawCurrButton[i];
                    gContRawCurrButton[i] = pad->button;
                    gContRawLastDir[i] = gContRawCurrDir[i];
                    gContRawCurrDir[i] = dir;
                }
                else
                {
                    gContRawCurrButton[i] |= pad->button;
                    gContRawCurrDir[i] |= dir;
                }
            }
        }
    }
}

/**
 * Set the pressed arrays and copy them to their live buffers later.
 */
void UpdateControllers(void)
{
    u16 i;

    for (i = 0; i < 4; i++)
    {
        // Only update if plugged in and initialized.
        if (gContRawPlugged[i] != 0)
        {
            gContRawButtonPressed[i] = (gContRawCurrButton[i] ^ gContRawLastButton[i]) & gContRawCurrButton[i];
            gContRawDirPressed[i] = (gContRawCurrDir[i] ^ gContRawLastDir[i]) & gContRawCurrDir[i];
            gContPlugged[i] = gContRawPlugged[i];
            gContLastButton[i] = gContRawLastButton[i];
            gContCurrButton[i] = gContRawCurrButton[i];
            gContButtonPressed[i] = gContRawButtonPressed[i];
            gContStickX[i] = gContRawStickX[i];
            gContStickY[i] = gContRawStickY[i];
            gContLastDir[i] = gContRawLastDir[i];
            gContCurrDir[i] = gContRawCurrDir[i];
            gContDirPressed[i] = gContRawDirPressed[i];
        }
        else
        {
            // We dont want lingering inputs, so clear the raw arrays.
            gContRawButtonPressed[i] = 0;
            gContRawDirPressed[i] = 0;
            gContPlugged[i] = 0;
            gContLastButton[i] = 0;
            gContCurrButton[i] = 0;
            gContButtonPressed[i] = 0;
            gContStickX[i] = 0;
            gContStickY[i] = 0;
            gContLastDir[i] = 0;
            gContCurrDir[i] = 0;
            gContDirPressed[i] = 0;
        }
    }
}

void func_8001E80C(void)
{
    UpdateRawControllers();
    func_8001DCEC();
    if (D_80165284 == 0)
    {
        func_8005F088();
        UpdateControllers();
        if (D_8016E0B0 != 0)
        {
            if (D_80165274 != NULL)
            {
                D_80165274();
            }
            func_8001D2FC();
            func_80016EE4();
            func_8001FBAC();
        }
        func_8005F0B8();
    }
    if (D_8016525C != 0)
    {
        if (D_8016525C == 8)
        {
            D_8016525C = 0;
        }
        else
        {
            D_8016525C += 1;
        }
    }
    D_80165284 += 1;
    if (D_80165284 >= D_8016527C)
    {
        D_80165284 = 0;
    }
    D_8016E244 += 1;
}

void func_8001E954(s32 *arg0)
{
    gDecompressHeap = (u8 *)arg0;
}

s32 func_8001E96C(void)
{
    return (s32)gDecompressHeap;
}

void func_8001E98C(s32 arg0, s32 arg1, s32 arg2)
{
    u32 sp1C; /* compiler-managed */
    s32 sp18;

    sp1C = gDecompressHeap;
    if ((s32)sp1C & 0xF)
    {
        sp1C = ALIGN16((s32)sp1C + 1);
        gDecompressHeap = (u8 *)sp1C;
    }
    sp18 = arg2 - arg1;
    gFileArray[arg0].ptr = gDecompressHeap;
    load_from_rom_to_addr(arg1, gFileArray[arg0].ptr, sp18);
    gDecompressHeap = &gDecompressHeap[sp18];
}

/**
 * Decompress a given area and add it to the file array's ID pointer.
 */
void DecompressFile(u32 id, u32 rom_start, u32 rom_end)
{
    u32 heap;
    u32 allocSize;
    u32 size;
    void *buf;

    // align the heap pointer's size.
    heap = gDecompressHeap;
    if (heap & 0xF)
    {
        // add 1 so the heap will point to the new blank area in the heap.
        heap = ALIGN16(heap + 1);
        gDecompressHeap = heap;
    }
    allocSize = rom_end - rom_start; // get size.
    buf = malloc(allocSize);         // alloc buf pointer.
    // first load the compressed bin to the buffer.
    load_from_rom_to_addr(rom_start, buf, allocSize);
    // then decompress the bin to the heap.
    size = Decode(buf, gDecompressHeap);
    free(buf);                            // free buf, we dont need it anymore.
    gFileArray[id].ptr = gDecompressHeap; // add the decompressed file to the file array.
    gDecompressHeap += size;              // re-set the heap pointer to the new area.
}

void func_8001EB68(s32 arg0, void *arg1, void *arg2)
{
    DecompressFile((u32)arg0, (u32)arg1, (u32)arg2);
    if (func_80017FF8() == 1)
    {
        func_800180C4((u32)gFileArray[arg0].ptr, func_8001E96C());
    }
}

void func_8001EBE8(void)
{
    D_8016E098 = 1;
}

void func_8001EC04(void)
{
    D_8016E098 = 0;
}

void func_8001EC1C(void)
{
    D_8016E0A0 = 1;
}

void func_8001EC38(void)
{
    D_8016E0A0 = 0;
}

void func_8001EC50(void)
{
    D_8016E0A8 = 1;
}

void func_8001EC6C(void)
{
    D_8016E0A8 = 0;
}

void func_8001EC84(void)
{
    D_8016E0B0 = 1;
}

void func_8001ECA0(void)
{
    D_8016E0B0 = 0;
}

void func_8001ECB8(void)
{
    func_8001F9DC();
    D_8016E244 = 0;
    D_8016E084 = 0;
    D_8016E08C = 0;
    D_801765F4 = 0;
    D_80176602 = 0;
    func_8001EBE8();
    func_8001EC1C();
    func_8001EC50();
    func_8001EC84();
    // Set the View struct.
    gView.at.x = 0.0f;
    gView.at.y = 0.0f;
    gView.at.z = 0.0f;
    gView.eye.x = 0.0f;
    gView.eye.y = 0.0f;
    gView.eye.z = 1000.0f;
    gView.rot.x = 0.0f;
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 1000.0f;
    gLightingSettings = D_8004A590;
    D_801775BC = 0;
    D_801775C4 = 0;
    D_801775CC = 0;
    D_801775D4 = 0;
    D_801775DC = 0;
    D_801775E4 = 0;
    D_801775EC = 0;
    D_8016E26C = 0x20;
    D_8016E274 = 0x20;
}

void func_8001EE64(void)
{
    u32 sp1C;

    for (sp1C = 0; sp1C < 0xCF; sp1C++)
    {
        func_8001A928(sp1C);
    }
}
