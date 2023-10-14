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
    Mtx *unk0[4][0x10];
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

// externs
s32 func_8000EEE8(void**, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_80013AE0(f32*, f32, f32, f32);               /* extern */
s32 func_80013B70(f32*, f32, f32, f32);               /* extern */
s32 func_80013F6C(f32*, f32);                         /* extern */
s32 func_80014098(f32*, f32);                         /* extern */
s32 func_800141C4(f32*, f32);                         /* extern */

extern s32 D_80055820;
extern s32 D_80055828;
extern u32 D_80055D30[];
extern u32 D_80055D40[];

extern struct UnkStruct8016E104 *D_8016E104;

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

s32 func_8000E944(Gfx** arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 sp9C;
    s32 sp98;
    Gfx* sp94;
    struct UnkInnerStruct8000E944* sp90;
    struct UnkInnerStruct8000E944* sp8C;
    struct UnkInnerStruct8000E944* sp88;
    struct UnkInnerStruct8000E944* sp84;
    float sp44[4][4];
    char pad[4];
    s32 sp3C;

    sp3C = 0;
    sp84 = arg1 + arg5;
    sp94 = *arg0;
    guMtxIdentF(&sp44);

    for(sp9C = 0; sp9C < 3; sp9C++) {
        switch (D_80055D30[sp9C]) {                          /* irregular */
        case 17:
            sp90 = (void*)((u32)&sp84[arg6]+4);
            if ((sp90->u.unk0_f != 0.0f) || (sp90->unk4 != 0.0f) || (sp90->unk8 != 0.0f)) {
                func_80013AE0(&sp44[0], sp90->u.unk0_f, sp90->unk4, sp90->unk8);
                sp3C = 1;
            }
            break;
        case 19:
            sp8C = (void*)((u32)&sp84[arg6]+0x10);
            if ((sp8C->u.unk0_f != 0.0f) || (sp8C->unk4 != 0.0f) || (sp8C->unk8 != 0.0f)) {
                for(sp98 = 0; sp98 < 3; sp98++) {
                    switch (D_80055D40[sp98]) {            /* switch 1; irregular */
                    case 0x33:                      /* switch 1 */
                        func_80013F6C(&sp44[0], sp8C->u.unk0_f);
                        break;
                    case 0x34:                      /* switch 1 */
                        func_80014098(&sp44[0], sp8C->unk4);
                        break;
                    case 0x35:                      /* switch 1 */
                        func_800141C4(&sp44[0], sp8C->unk8);
                        break;
                    }
                }
                sp3C = 1;
            }
            break;
        case 21:
            sp88 = (void*)((u32)&sp84[arg6]+0x1C);
            if ((sp88->u.unk0_f != 1.0f) || (sp88->unk4 != 1.0f) || (sp88->unk8 != 1.0f)) {
                func_80013B70(&sp44[0], sp88->u.unk0_f, sp88->unk4, sp88->unk8);
                sp3C = 1;
            }
            break;
        }
    }

    if (sp3C != 0) {
        D_80055820 += 1;
        guMtxCatF((f32 (*)[4]) &sp44[0], (D_80055820 << 6) - 0x40 + (u32)&D_80055828, (D_80055820 << 6) + (u32)&D_80055828);
    }
    guMtxF2L((D_80055820 << 6) + (u32)&D_80055828, (void*)((u32)&D_8016E104->unk0[arg7] + 0xE0));

    gSPMatrix(sp94++, osVirtualToPhysical((void*)((u32)&D_8016E104->unk0[arg7++] + 0xE0)), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    if (sp84[arg6].u.unk0 >= 0) {
        arg7 = func_8000EEE8(&sp94, arg1, arg2, arg3, arg4, sp84[arg6].u.unk0, arg7);
    }
    if ((sp9C = sp84[arg6].unk2C) != 0) {
        arg7 = func_8000E944(&sp94, arg1, arg2, arg3, arg4, arg5, arg6 + sp9C, arg7);
    }
    if (sp3C != 0) {
        D_80055820 -= 1;
    }
    if ((sp9C = sp84[arg6].unk28) != 0) {
        arg7 = func_8000E944(&sp94, arg1, arg2, arg3, arg4, arg5, arg6 + sp9C, arg7);
    }
    *arg0 = sp94;
    return arg7;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/F280/func_8000EEE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/F280/func_8000F888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/F280/func_8000FC08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/F280/func_8000FD9C.s")
