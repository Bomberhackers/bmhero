#include "common.h"

struct UnkStruct8004A3A0 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

struct UnkInputStruct8000FEB0 {
    struct UnkStruct8004A3A0 unk0;
    struct UnkStruct8004A3A0 unkC;
    struct UnkStruct8004A3A0 unk18;
};

struct UnkStruct80055D50 {
    u32 unk0;
    struct UnkStruct8004A3A0 unk4;
    struct UnkStruct8004A3A0 unk10;
    struct UnkStruct8004A3A0 unk1C;
    u32 unk28;
    u32 unk2C;
}; // size = 0x30

struct UnkInputStruct8000FF44 {
    u32 unk0;
    u32 unk4;
    char filler8[0x4];
    struct UnkInputStruct8000FF44 **unkC;
    s32 unk10;
    struct UnkStruct8004A3A0 unk14;
    struct UnkStruct8004A3A0 unk20;
    struct UnkStruct8004A3A0 unk2C;
};

struct UnkInputStruct80010098 {
    u32 unk0;
    char filler4[0x24];
    struct UnkInputStruct8000FF44 *unk28;
};

struct UnkInputStruct800100E8_SP24 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 *unkC;
    u32 unk10;
    u32 unk14;
    char filler18[0x18];
};

struct UnkInputStruct80010350 {
    char filler0[0xC];
    u32 *unkC;
    s32 unk10;
};

struct UnkStruct8016E3AC {
    char filler0[0xC];
    u32 unkC;
    char filler10[0x8];
    u32 unk18;
};

struct UnkInputStruct80010408_Inner {
    u32 unk0;
    u32 unk4;
    char filler8[0x4];
};

struct UnkInputStruct80010408 {
    char filler0[0x4];
    u32 unk4;
    char filler8[0x4];
    struct UnkInputStruct80010408_Inner unkC[1];
};

struct UnkStruct80010408_SP2C {
    u32 unk0;
    struct UnkInputStruct8000FEB0 unk4;
    u32 unk28;
};

struct UnkStruct800105D8 {
    u32 unk0;
    char filler4[0x24];
    struct UnkInputStruct80010350* unk28;
};

struct UnkInputStruct80010634_SP20 {
    u32 *unk0;
    s32 unk4;
    struct UnkStruct8004A3A0 unk8;
    struct UnkStruct8004A3A0 unk14;
    struct UnkStruct8004A3A0 unk20;
};

struct UnkStruct80055D54 {
    char filler0[0x4];
    struct UnkInputStruct80010634_SP20 *unk4;
    u32 unk8;
};

struct UnkInputStruct800108D0 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

// extern functions
extern void* malloc(s32 size);
extern void free(void*);

// extern symbols
extern struct UnkStruct8004A3A0 D_8004A3A0;
extern struct UnkStruct8004A3A0 D_8004A3AC;
extern struct UnkStruct8004A3A0 D_8004A3B8;
extern s32 *D_8004A3D0;
extern u32 D_80055D30[];
extern u32 D_80055D40[];
extern s32 D_80055D4C;
extern struct UnkStruct80055D50 *D_80055D50;
extern struct UnkStruct80055D54 *D_80055D54;

extern u32 *D_8016E3AC;

// functions
void func_8000FEB0(struct UnkInputStruct8000FEB0* arg0);
void func_8000FF44(struct UnkInputStruct8000FF44* arg0);
void func_8001000C(struct UnkInputStruct8000FF44* arg0);
void func_80010098(struct UnkInputStruct80010098* arg0);
void* func_800100E8(void* arg0, s32 arg1);
void func_80010350(struct UnkInputStruct80010350* arg0);

void func_8000FEB0(struct UnkInputStruct8000FEB0* arg0) {
    arg0->unk0 = D_8004A3A0;
    arg0->unkC = D_8004A3AC;
    arg0->unk18 = D_8004A3B8;
}

void func_8000FF44(struct UnkInputStruct8000FF44* arg0) {
    struct UnkStruct80055D50* sp4;

    if (arg0 == NULL) {
        return;
    }
    sp4 = &D_80055D50[arg0->unk4];
    arg0->unk14 = sp4->unk4;
    arg0->unk20 = sp4->unk10;
    arg0->unk2C = sp4->unk1C;
}

void func_8001000C(struct UnkInputStruct8000FF44* arg0) {
    s32 sp1C;

    func_8000FF44(arg0);

    for(sp1C = 0; sp1C < arg0->unk10; sp1C++) {
        func_8001000C(arg0->unkC[sp1C]);
    }
}

void func_80010098(struct UnkInputStruct80010098* arg0) {
    if (arg0->unk0 == 1) {
        func_8001000C(arg0->unk28);
    }
}

void* func_800100E8(void* arg0, s32 arg1) {
    struct UnkInputStruct800100E8_SP24* sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    D_80055D4C += 1;
    sp24 = malloc(0x3C);
    sp24->unk8 = arg0;
    sp24->unk0 = D_80055D50[arg1].unk0;
    sp24->unk4 = arg1;
    func_8000FF44(sp24);
    if (D_80055D50[arg1].unk2C != 0) {
        for(sp1C = D_80055D50[arg1].unk2C + arg1, sp18 = 1; D_80055D50[sp1C].unk28 != 0; sp1C += D_80055D50[sp1C].unk28, sp18++) {

        }
        sp24->unk10 = sp18;
        sp24->unkC = malloc(sp18 * 4);
        for(sp1C = D_80055D50[arg1].unk2C + arg1, sp20 = 0; sp20 < sp18; sp1C += D_80055D50[sp1C].unk28, sp20++) {
            sp24->unkC[sp20] = func_800100E8(sp24, sp1C);
        }
    } else {
        sp24->unk10 = 0;
        sp24->unkC = NULL;
    }
    return sp24;
}

void func_80010350(struct UnkInputStruct80010350* arg0) {
    s32 sp1C;
    u32* sp18;

    if (arg0->unk10 != 0) {
        for(sp18 = arg0->unkC, sp1C = 0; sp1C < arg0->unk10; sp1C++) {
            func_80010350(sp18[sp1C]);
        }
        free(sp18);
    }
    free(arg0);
}

void* func_80010408(struct UnkInputStruct80010408* arg0, u32 arg1) {
    struct UnkStruct80010408_SP2C* sp2C;
    struct UnkInputStruct80010408_Inner *sp28;
    s32 sp24;

    sp28 = arg0->unkC;
    if (arg0->unk4 <= arg1) {
        return NULL;
    }
    sp2C = malloc(sizeof(struct UnkStruct80010408_SP2C));
    func_8000FEB0(&sp2C->unk4);
    switch (sp28[arg1].unk0) {                              /* irregular */
        case 0:
        case 5:
        case 6:
            sp2C->unk0 = 0;
            sp2C->unk28 = (void* ) arg1;
            break;
        case 1:
            D_80055D4C = 0;
            sp2C->unk0 = 1;
            sp2C->unk28 = func_800100E8(NULL, sp28[arg1].unk4);
            break;
        default:
            break;
    }

    for(sp24 = 0; sp24 < 3; sp24++) {
        D_80055D30[sp24] = D_8016E3AC[sp24+3];
    }

    for(sp24 = 0; sp24 < 3; sp24++) {
        D_80055D40[sp24] = D_8016E3AC[sp24+6];
    }

    return sp2C;
}

void func_800105D8(struct UnkStruct800105D8* arg0) {
    if (arg0->unk0 == 1) {
        func_80010350(arg0->unk28);
    }
    free(arg0);
}

void func_80010634(struct UnkInputStruct80010098* arg0, s32 arg1, s32 arg2) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    struct UnkInputStruct8000FF44* sp28;
    struct UnkInputStruct80010634_SP20 *sp24;
    struct UnkInputStruct80010634_SP20* sp20;
    char pad[1];

    if (arg0->unk0 != 1U) {
        return;
    }
    if (arg2 != 0) {
        func_80010098(arg0);
    }

    sp24 = D_80055D54[D_8004A3D0[arg1]].unk4;
    sp2C = D_80055D54[D_8004A3D0[arg1]].unk8;

    for(sp34 = 0; sp34 < sp2C; sp34++) {
        sp20 = &sp24[sp34];
        sp28 = arg0->unk28;

        for(sp30 = 1; sp30 < sp20->unk4; sp30++) {
            sp28 = sp28->unkC[sp20->unk0[sp30]];
        }

        sp28->unk14 = sp24[sp34].unk8;
        sp28->unk20 = sp24[sp34].unk14;
        sp28->unk2C = sp24[sp34].unk20;
        (sp28+1)->unk0 = 1;
    }
}

f32 func_800108D0(struct UnkInputStruct800108D0* arg0, f32 arg1) {
    char pad[4];
    s32 sp18;
    s32 sp14;
    f32 sp10;
    s32 *spC;
    s32 sp8;
    f32 *sp4;

    sp14 = (s32) arg1;

    switch(arg0->unk0) {
        case 0x31:
            spC = arg0->unk8;
            sp4 = arg0->unkC;
            sp8 = arg0->unk4;

            //! @bug: duplicate check? left in the ROM due to unoptimized code.
            for(sp18 = 0; sp18 < sp18 < sp8; sp18++) {
                if (spC[sp18] >= sp14) {
                    break;
                }
            }

            if (spC[sp18] == sp14) {
                sp10 = sp4[sp18];
            } else {
                sp10 = sp4[sp18-1] + (((sp4[sp18] - sp4[sp18-1]) / (f32) (spC[sp18] - spC[sp18-1])) * (arg1 - (f32)spC[sp18-1]));
            }
        break;
    }

    return sp10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80010A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80010AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80010B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80010C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80010C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80010E0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80011084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_800111D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80011424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_800117F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_8001191C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80011D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80011DD0.s")
