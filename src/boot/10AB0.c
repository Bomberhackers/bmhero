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
    char filler0[0x4];
    struct UnkStruct8004A3A0 unk4;
    struct UnkStruct8004A3A0 unk10;
    struct UnkStruct8004A3A0 unk1C;
    char filler28[0x8];
}; // size = 0x30

struct UnkInputStruct8000FF44 {
    char filler0[0x4];
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

extern struct UnkStruct8004A3A0 D_8004A3A0;
extern struct UnkStruct8004A3A0 D_8004A3AC;
extern struct UnkStruct8004A3A0 D_8004A3B8;

extern struct UnkStruct80055D50 *D_80055D50;

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

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_800100E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80010350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80010408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_800105D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_80010634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/10AB0/func_800108D0.s")

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
