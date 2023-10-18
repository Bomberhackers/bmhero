#include <ultra64.h>

struct UnkInputStruct8000E680 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    char fillerC[0x4];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    char filler1C[0x4];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    char filler2C[0x4];
};

struct UnkStruct8016E104 {
    char filler0[0xC0];
    /* 0xC0 */ Hilite hilites[2];
    /* 0xE0 */ Mtx unkE0[1];
};

struct UnkInnerStruct8000E944 {
    union {
        s32 unk0;
        f32 unk0_f;
    } u;
    f32 unk4;
    f32 unk8;
    char fillerC[0x1C];
    u32 unk28;
    u32 unk2C;
};

struct UnkInputStruct8000EEE8_SPE4 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};

struct UnkInputStruct8000EEE8_SPEC {
    s32 unk0; // type of unk4 union?
    union {
        f32 unk4_as_f;
        s32 unk4_as_s;
    } u;
    Gfx *dlist;
};

// externs
s32 func_80013AE0(f32*, f32, f32, f32);               /* extern */
s32 func_80013B70(f32*, f32, f32, f32);               /* extern */
s32 func_80013F6C(f32*, f32);                         /* extern */
s32 func_80014098(f32*, f32);                         /* extern */
s32 func_800141C4(f32*, f32);                         /* extern */

extern u8 D_1000768[];
extern s32 D_8004A390;
extern s32 D_8004A394;
extern f32 D_800557E0[4];
extern s32 D_80055820;
extern s32 D_80055828;
extern u32 D_80055D30[];
extern u32 D_80055D40[];
extern f32 D_8016E3B4;
extern f32 D_8016E3BC;
extern f32 D_8016E3C4;

extern struct UnkStruct8016E104 *D_8016E104;

// functions
s32 func_8000EEE8(Gfx** gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_8000E680(struct UnkInputStruct8000E680* arg0, struct UnkInputStruct8000E680* arg1) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    sp38 = arg1->unk0;
    sp34 = arg1->unk10;
    sp30 = arg1->unk20;
    sp2C = arg1->unk4;
    sp28 = arg1->unk14;
    sp24 = arg1->unk24;
    sp20 = arg1->unk8;
    sp1C = arg1->unk18;
    sp18 = arg1->unk28;

    sp3C = ((sp38 * sp28 * sp18) 
          + (sp34 * sp24 * sp20) 
          + (sp30 * sp2C * sp1C)) 
          - ((sp38 * sp24 * sp1C) 
          + (sp34 * sp2C * sp18) 
          + (sp30 * sp28 * sp20));

    arg0->unk0 =  (f32) (((sp28 * sp18) - (sp24 * sp1C)) / sp3C);
    arg0->unk10 = (f32) (((sp30 * sp1C) - (sp34 * sp18)) / sp3C);
    arg0->unk20 = (f32) (((sp34 * sp24) - (sp30 * sp28)) / sp3C);
    arg0->unk4 =  (f32) (((sp24 * sp20) - (sp2C * sp18)) / sp3C);
    arg0->unk14 = (f32) (((sp38 * sp18) - (sp30 * sp20)) / sp3C);
    arg0->unk24 = (f32) (((sp30 * sp2C) - (sp38 * sp24)) / sp3C);
    arg0->unk8 =  (f32) (((sp2C * sp1C) - (sp28 * sp20)) / sp3C);
    arg0->unk18 = (f32) (((sp34 * sp20) - (sp38 * sp1C)) / sp3C);
    arg0->unk28 = (f32) (((sp38 * sp28) - (sp34 * sp2C)) / sp3C);
}

s32 func_8000E944(Gfx** gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 i;
    s32 j;
    Gfx* dlist;
    struct UnkInnerStruct8000E944* sp90;
    struct UnkInnerStruct8000E944* sp8C;
    struct UnkInnerStruct8000E944* sp88;
    struct UnkInnerStruct8000E944* sp84;
    float mf[4][4];
    char pad[4];
    s32 sp3C;

    sp3C = 0;
    sp84 = arg1 + arg5;
    dlist = *gfx;
    guMtxIdentF(mf);

    for(i = 0; i < 3; i++) {
        switch (D_80055D30[i]) {                          /* irregular */
        case 17:
            sp90 = (void*)((u32)&sp84[arg6]+4);
            if ((sp90->u.unk0_f != 0.0f) || (sp90->unk4 != 0.0f) || (sp90->unk8 != 0.0f)) {
                func_80013AE0(mf, sp90->u.unk0_f, sp90->unk4, sp90->unk8);
                sp3C = 1;
            }
            break;
        case 19:
            sp8C = (void*)((u32)&sp84[arg6]+0x10);
            if ((sp8C->u.unk0_f != 0.0f) || (sp8C->unk4 != 0.0f) || (sp8C->unk8 != 0.0f)) {
                for(j = 0; j < 3; j++) {
                    switch (D_80055D40[j]) {            /* switch 1; irregular */
                    case 0x33:                      /* switch 1 */
                        func_80013F6C(mf, sp8C->u.unk0_f);
                        break;
                    case 0x34:                      /* switch 1 */
                        func_80014098(mf, sp8C->unk4);
                        break;
                    case 0x35:                      /* switch 1 */
                        func_800141C4(mf, sp8C->unk8);
                        break;
                    }
                }
                sp3C = 1;
            }
            break;
        case 21:
            sp88 = (void*)((u32)&sp84[arg6]+0x1C);
            if ((sp88->u.unk0_f != 1.0f) || (sp88->unk4 != 1.0f) || (sp88->unk8 != 1.0f)) {
                func_80013B70(mf, sp88->u.unk0_f, sp88->unk4, sp88->unk8);
                sp3C = 1;
            }
            break;
        }
    }

    if (sp3C != 0) {
        D_80055820 += 1;
        guMtxCatF(mf, (D_80055820 << 6) - 0x40 + (u32)&D_80055828, (D_80055820 << 6) + (u32)&D_80055828);
    }
    guMtxF2L((D_80055820 << 6) + (u32)&D_80055828, &D_8016E104->unkE0[arg7]);

    gSPMatrix(dlist++, osVirtualToPhysical(&D_8016E104->unkE0[arg7++]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    if (sp84[arg6].u.unk0 >= 0) {
        arg7 = func_8000EEE8(&dlist, arg1, arg2, arg3, arg4, sp84[arg6].u.unk0, arg7);
    }
    // ok but why load into a temp.
    if ((i = sp84[arg6].unk2C) != 0) {
        arg7 = func_8000E944(&dlist, arg1, arg2, arg3, arg4, arg5, arg6 + i, arg7);
    }
    if (sp3C != 0) {
        D_80055820 -= 1;
    }
    if ((i = sp84[arg6].unk28) != 0) {
        arg7 = func_8000E944(&dlist, arg1, arg2, arg3, arg4, arg5, arg6 + i, arg7);
    }
    *gfx = dlist;
    return arg7;
}

s32 func_8000EEE8(Gfx** gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    struct UnkInputStruct8000EEE8_SPEC *spEC;
    Gfx* dlist;
    struct UnkInputStruct8000EEE8_SPE4* spE4;
    f32 spA4[4][4];
    s32 spA0;
    

    spA0 = 0;
    spE4 = arg1 + 8;
    spEC = (void*)(arg1 + 0xC);
    dlist = *gfx;
    guMtxIdentF(spA4);

    gSPSegment(dlist++, spE4->unk0, (s32)(arg1 + 0x80000000));
    gSPSegment(dlist++, spE4->unk1, (s32)(arg2 + 0x80000000));
    gSPSegment(dlist++, spE4->unk2, (s32)(arg3 + 0x80000000));
    gSPSegment(dlist++, spE4->unk3, (s32)(arg4 + 0x80000000));
    gDPPipelineMode(dlist++, G_PM_1PRIMITIVE);

    if ((spEC[arg5].unk0 == 0) 
     || (spEC[arg5].unk0 == 5) 
     || (spEC[arg5].unk0 == 6)
     || (spEC[arg5].unk0 == 8)) {
        switch (spEC[arg5].unk0) {                          /* irregular */
        case 5:
            guMtxIdentF((f32 (*)[4]) D_800557E0);
            func_8000E680(D_800557E0, (D_80055820 << 6) + (u32)&D_80055828);
            func_80013B70(D_800557E0, D_8016E3B4, D_8016E3BC, D_8016E3C4);
            D_80055820 += 1;
            guMtxCatF((f32 (*)[4]) D_800557E0, (D_80055820 << 6) - 0x40 + (u32)&D_80055828, (D_80055820 << 6) + (u32)&D_80055828);
            spA0 += 1;
            break;
        case 6:
            D_8004A390 = 1;
            gDPSetTextureLUT(dlist++, G_TT_NONE);
            gSPSetGeometryMode(dlist++, G_TEXTURE_GEN);
            gSPTexture(dlist++, 0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_ON);
            gDPSetTexturePersp(dlist++, G_TP_PERSP);
            gDPSetPrimColor(dlist++, 0, 0, 255, 255, 255, 255);
            gDPSetEnvColor(dlist++, 64, 64, 64, 255);
            gDPSetCombineMode(dlist++, G_CC_HILITERGBA, G_CC_HILITERGBA);
            gDPSetTextureImage(dlist++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, D_1000768);
            gDPSetTile(dlist++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gDPLoadSync(dlist++);
            gDPLoadBlock(dlist++, G_TX_LOADTILE, 0, 0, 511, 512);
            gDPPipeSync(dlist++);
            gDPSetTile(dlist++, G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gDPSetTileSize(dlist++, G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C);
            gDPSetHilite1Tile(dlist++, G_TX_RENDERTILE, &D_8016E104->hilites[0], 32, 32);
            break;
        case 8:
            D_8004A394 = 1;
            gSPSetGeometryMode(dlist++, G_TEXTURE_GEN);
            break;
        default:
            if (D_8004A390 != 0) {
                gSPClearGeometryMode(dlist++, G_TEXTURE_GEN);
                gSPTexture(dlist++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
                D_8004A390 = 0;
            } else if (D_8004A394 != 0) {
                gSPClearGeometryMode(dlist++, G_TEXTURE_GEN);
                D_8004A394 = 0;
            }
            break;
        }
        if (spEC[arg5].u.unk4_as_f != 1.0f) {
            func_80013B70(&spA4[0], spEC[arg5].u.unk4_as_f, spEC[arg5].u.unk4_as_f, spEC[arg5].u.unk4_as_f);
            D_80055820 += 1;
            guMtxCatF((f32 (*)[4]) &spA4[0], (D_80055820 << 6) - 0x40 + (u32)&D_80055828, (D_80055820 << 6) + (u32)&D_80055828);
            spA0 += 1;
        }
        guMtxF2L((D_80055820 << 6) + (u32)&D_80055828, &D_8016E104->unkE0[arg6]);
        gSPMatrix(dlist++, osVirtualToPhysical(&D_8016E104->unkE0[arg6++]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(dlist++, (s32)(spEC[arg5].dlist) + arg1);
        D_80055820 -= spA0;
    } else if (spEC[arg5].unk0 == 1) {
        arg6 = func_8000E944(&dlist, arg1, arg2, arg3, arg4, spEC[arg5].dlist, spEC[arg5].u.unk4_as_s, arg6);
    }
    *gfx = dlist;
    return arg6;
}

s32 func_8000F888(void* arg0, s32* arg1, s32 arg2, s32 arg3, s32 *unused, s32* arg5) {
    struct UnkInnerStruct8000E944* sp84;
    struct UnkInnerStruct8000E944* sp80;
    struct UnkInnerStruct8000E944* sp7C;
    s32 sp78;
    
    Mtx sp38;
    char pad[4];
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    sp28 = 0;
    sp78 = *arg1;

    guMtxIdentF(&sp38.m[0][0]);
    for(sp30 = 0; sp30 < 3; sp30++) {
        switch (D_80055D30[sp30]) {                          /* irregular */
        case 17:
            sp84 = arg0;
            if ((sp84->u.unk0_f != 0.0f) || (sp84->unk4 != 0.0f) || (sp84->unk8 != 0.0f)) {
                func_80013AE0(&sp38.m[0][0], sp84->u.unk0_f, sp84->unk4, sp84->unk8);
                sp28 = 1;
            }
            break;
        case 19:
            sp80 = (void*)((u32)arg0 + 0xC);
            if ((sp80->u.unk0_f != 0.0f) || (sp80->unk4 != 0.0f) || (sp80->unk8 != 0.0f)) {
                for(sp2C = 0; sp2C < 3; sp2C++) {
                    switch (D_80055D40[sp2C]) {            /* switch 1; irregular */
                    case 0x33:                      /* switch 1 */
                        func_80013F6C(&sp38.m[0][0], sp80->u.unk0_f);
                        break;
                    case 0x34:                      /* switch 1 */
                        func_80014098(&sp38.m[0][0], sp80->unk4);
                        break;
                    case 0x35:                      /* switch 1 */
                        func_800141C4(&sp38.m[0][0], sp80->unk8);
                        break;
                    }
                }
                sp28 = 1;
            }
            break;
        case 21:
            sp7C = (void*)((u32)arg0 + 0x18);
            if ((sp7C->u.unk0_f != 1.0f) || (sp7C->unk4 != 1.0f) || (sp7C->unk8 != 1.0f)) {
                func_80013B70(&sp38.m[0][0], sp7C->u.unk0_f, sp7C->unk4, sp7C->unk8);
                sp28 = 1;
            }
            break;
        }
    }
    if (sp28 != 0) {
        D_80055820 += 1;
        guMtxCatF(&sp38.m[0][0], (D_80055820 << 6) - 0x40 + (u32)&D_80055828, (D_80055820 << 6) + (u32)&D_80055828);
    }
    *arg1 = sp78;
    *arg5 = sp28;
    return arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/F280/func_8000FC08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/F280/func_8000FD9C.s")
