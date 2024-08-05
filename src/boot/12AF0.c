#include <ultra64.h>

// functions
void func_80011EF0(struct UnkStruct80011EF0* arg0);
void func_800120FC(struct UnkStruct800120FC* arg0);

void func_80011EF0(struct UnkStruct80011EF0* arg0) {
    s32 i;
    s32 j;

    D_80055D54 = arg0->unk64;
    D_80055D58 = arg0->unk68;
    if (D_8004A3D0 != NULL) {
        free(D_8004A3D0);
    }
    D_8004A3D0 = NULL;
    D_80055D64 = 0;
    if (D_80055D58 != 0) {
        for(D_80055D64 = 0, i = 0; i < D_80055D58; i++) {
            if (D_80055D54[i].unk0 > D_80055D64) {
                D_80055D64 = D_80055D54[i].unk0;
            }
        }
        D_80055D64 += 1;
        D_8004A3D0 = malloc(D_80055D64 * 4);
        for(i = 0; i < D_80055D64; i++) {
            for(j = D_80055D58 - 1; j >= 0; j--) {
                if (D_80055D54[j].unk0 == i) {
                    break;
                }
            }
            D_8004A3D0[i] = j;
        }
    }
}

void func_800120FC(struct UnkStruct800120FC* arg0) {
    s32 i;
    s32 j;

    D_80055D5C = arg0->unk6C;
    D_80055D60 = arg0->unk70;
    if (D_8004A3D4 != 0) {
        free(D_8004A3D4);
    }
    D_8004A3D4 = 0;
    D_80055D68 = 0;
    if (D_80055D60 != 0) {
        for(D_80055D68 = 0, i = 0; i < D_80055D60; i++) {
            if (D_80055D5C[i].unk0 > D_80055D68) {
                D_80055D68 = D_80055D5C[i].unk0;
            }
        }
        D_80055D68 += 1;
        D_8004A3D4 = malloc(D_80055D68 * 4);
        for(i = 0; i < D_80055D68; i++) {
            for(j = D_80055D60 - 1; j >= 0; j--) {
                if (D_80055D5C[j].unk0 == i) {
                    break;
                }
            }
            D_8004A3D4[i] = j;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_800122F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_8001369C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80013754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80013814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80013948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80013A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80013AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80013B70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80013C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80013D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80013F6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80014098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_800141C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_800142F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80014414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_8001444C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_8001445C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_800144F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_800145A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_800145C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_800146F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80014A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/12AF0/func_80014A44.s")
