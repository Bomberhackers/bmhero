#include "ultra64.h"
#include "malloc/malloc.h"
#include "functions.h"
#include "types.h"
#include "macros.h"
#include "12AF0.h"


void func_80011EF0(struct UnkStruct800120FC *arg0)
{
    s32 i;
    s32 j;

    D_80055D54 = arg0->unk64;
    D_80055D58 = arg0->unk68;
    if (D_8004A3D0 != NULL)
    {
        free(D_8004A3D0);
    }
    D_8004A3D0 = NULL;
    D_80055D64 = 0;
    if (D_80055D58 != 0)
    {
        for (D_80055D64 = 0, i = 0; i < D_80055D58; i++)
        {
            if (D_80055D54[i].unk0 > D_80055D64)
            {
                D_80055D64 = D_80055D54[i].unk0;
            }
        }
        D_80055D64 += 1;
        D_8004A3D0 = malloc(D_80055D64 * 4);
        for (i = 0; i < D_80055D64; i++)
        {
            for (j = D_80055D58 - 1; j >= 0; j--)
            {
                if (D_80055D54[j].unk0 == i)
                {
                    break;
                }
            }
            D_8004A3D0[i] = j;
        }
    }
}

void func_800120FC(struct UnkStruct800120FC *arg0)
{
    s32 i;
    s32 j;

    D_80055D5C = arg0->unk6C;
    D_80055D60 = arg0->unk70;
    if (D_8004A3D4 != 0)
    {
        free(D_8004A3D4);
    }
    D_8004A3D4 = 0;
    D_80055D68 = 0;
    if (D_80055D60 != 0)
    {
        for (D_80055D68 = 0, i = 0; i < D_80055D60; i++)
        {
            if (D_80055D5C[i].unk0 > D_80055D68)
            {
                D_80055D68 = D_80055D5C[i].unk0;
            }
        }
        D_80055D68 += 1;
        D_8004A3D4 = malloc(D_80055D68 * 4);
        for (i = 0; i < D_80055D68; i++)
        {
            for (j = D_80055D60 - 1; j >= 0; j--)
            {
                if (D_80055D5C[j].unk0 == i)
                {
                    break;
                }
            }
            D_8004A3D4[i] = j;
        }
    }
}

void *func_800122F0(struct UnkStruct800122F0_Arg0 *arg0)
{
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    UNUSED s32 pad30;
    struct UnkStruct800122F0 *sp2C;
    union
    {
        s32 *sp28_0;
        f32 *sp28_1;
    } unksp28;

    f32 *sp24;
    struct UnkStruct800122F0_Arg0 *sp20;
    s32 *sp1C;
    s32 *sp18;

    sp20 = arg0 + 1;
    sp2C = malloc(sizeof(struct UnkStruct800122F0));
    sp2C->unk48 = arg0->unk4;
    sp2C->unk6C = NULL;
    sp2C->unk64 = NULL;

    for (sp3C = 0; sp3C < 3; sp3C++)
    {
        sp2C->unkC[sp3C] = D_8004A3D8[sp3C];
    }
    for (sp3C = 0; sp3C < 3; sp3C++)
    {
        sp2C->unk18[sp3C] = D_8004A3E4[sp3C];
    }

    for (sp3C = 0; sp3C < arg0->unk4; sp3C++)
    {
        if (sp20[sp3C].unk0 == 1)
        {
            break;
        }
    }

    if (sp3C < arg0->unk4)
    {
        D_80055D50 = (sp20[sp3C].unk8 + (char *)arg0); // why?
    }

    for (sp3C = 0; sp3C < arg0->unk4; sp3C++)
    {
        if (sp20[sp3C].unk0 == 2)
        {
            break;
        }
    }

    if (sp3C < arg0->unk4)
    {
        unksp28.sp28_0 = sp20[sp3C].unk8 + (char *)arg0;
        sp2C->unk68 = sp20[sp3C].unk4;
        sp2C->unk64 = malloc(sp2C->unk68 * 0xC);

        for (sp3C = 0; sp3C < sp2C->unk68; sp3C++)
        {
            sp2C->unk64[sp3C].unk0 = *unksp28.sp28_0++;
            sp2C->unk64[sp3C].unk8 = *unksp28.sp28_0++;
            sp2C->unk64[sp3C].unk4 = malloc(sp2C->unk64[sp3C].unk8 * 0x2C);

            for (sp38 = 0; sp38 < sp2C->unk64[sp3C].unk8; sp38++)
            {
                sp2C->unk64[sp3C].unk4[sp38].unk4 = *unksp28.sp28_0++;
                sp2C->unk64[sp3C].unk4[sp38].unk0 = malloc(sp2C->unk64[sp3C].unk4[sp38].unk4 * 4);

                for (sp34 = 0; sp34 < sp2C->unk64[sp3C].unk4[sp38].unk4; sp34++)
                {
                    sp2C->unk64[sp3C].unk4[sp38].unk0[sp34] = *unksp28.sp28_0++;
                }
                sp24 = unksp28.sp28_1;
                sp2C->unk64[sp3C].unk4[sp38].unk8 = ((f64)*sp24++);
                sp2C->unk64[sp3C].unk4[sp38].unkC = ((f64)*sp24++);
                sp2C->unk64[sp3C].unk4[sp38].unk10 = ((f64)*sp24++);
                sp2C->unk64[sp3C].unk4[sp38].unk14 = ((f64)*sp24++);
                sp2C->unk64[sp3C].unk4[sp38].unk18 = ((f64)*sp24++);
                sp2C->unk64[sp3C].unk4[sp38].unk1C = ((f64)*sp24++);
                sp2C->unk64[sp3C].unk4[sp38].unk20 = ((f64)*sp24++);
                sp2C->unk64[sp3C].unk4[sp38].unk24 = ((f64)*sp24++);
                sp2C->unk64[sp3C].unk4[sp38].unk28 = ((f64)*sp24++);
                unksp28.sp28_1 = sp24;
            }
        }
    }
    else
    {
        sp2C->unk68 = 0;
    }

    for (sp3C = 0; sp3C < arg0->unk4; sp3C++)
    {
        if (sp20[sp3C].unk0 == 3)
        {
            break;
        }
    }

    if (sp3C < arg0->unk4)
    {
        unksp28.sp28_0 = sp20[sp3C].unk8 + (char *)arg0;
        sp2C->unk70 = sp20[sp3C].unk4;
        sp2C->unk6C = malloc(sp2C->unk70 * 16);

        for (sp3C = 0; sp3C < sp2C->unk70; sp3C++)
        {
            sp2C->unk6C[sp3C].unk0 = *unksp28.sp28_0++;
            sp2C->unk6C[sp3C].unk8 = *unksp28.sp28_0++;
            sp2C->unk6C[sp3C].unkC = *unksp28.sp28_0++;
            sp2C->unk6C[sp3C].unk4 = malloc(sp2C->unk6C[sp3C].unk8 << 5); //???

            for (sp38 = 0; sp38 < sp2C->unk6C[sp3C].unk8; sp38++)
            {
                if (*unksp28.sp28_0 == 0x2F)
                {
                    sp2C->unk6C[sp3C].unk4[sp38].unk0 = *unksp28.sp28_0++;
                    sp2C->unk6C[sp3C].unk4[sp38].unk8 = *unksp28.sp28_0++;
                    sp2C->unk6C[sp3C].unk4[sp38].unk4 = *unksp28.sp28_0++;

                    // Alloc two things..
                    sp2C->unk6C[sp3C].unk4[sp38].unkC = malloc(sp2C->unk6C[sp3C].unk4[sp38].unk8 * 4);
                    sp2C->unk6C[sp3C].unk4[sp38].unk10 = malloc(sp2C->unk6C[sp3C].unk4[sp38].unk8 * 4);

                    for (sp34 = 0; sp34 < sp2C->unk6C[sp3C].unk4[sp38].unk8; sp34++)
                    {
                        sp2C->unk6C[sp3C].unk4[sp38].unkC[sp34] = *unksp28.sp28_0++;
                        sp2C->unk6C[sp3C].unk4[sp38].unk10[sp34] = *unksp28.sp28_0++;
                    }
                }
                else if (*unksp28.sp28_0 == 0x30)
                {
                    sp2C->unk6C[sp3C].unk4[sp38].unk0 = *unksp28.sp28_0++;
                    sp2C->unk6C[sp3C].unk4[sp38].unk4 = *unksp28.sp28_0++;
                    sp2C->unk6C[sp3C].unk4[sp38].unk8 = *unksp28.sp28_0++;
                    sp2C->unk6C[sp3C].unk4[sp38].unk14 = *unksp28.sp28_0++;
                    sp2C->unk6C[sp3C].unk4[sp38].unkC = *unksp28.sp28_0++;
                    sp2C->unk6C[sp3C].unk4[sp38].unk10 = 0x31;
                    sp2C->unk6C[sp3C].unk4[sp38].unk18 = malloc(sp2C->unk6C[sp3C].unk4[sp38].unk14 * 4);
                    sp2C->unk6C[sp3C].unk4[sp38].unk1C = malloc(sp2C->unk6C[sp3C].unk4[sp38].unk14 * 4);

                    for (sp34 = 0; sp34 < sp2C->unk6C[sp3C].unk4[sp38].unk14; sp34++)
                    {
                        sp2C->unk6C[sp3C].unk4[sp38].unk18[sp34] = *unksp28.sp28_0++;
                        sp2C->unk6C[sp3C].unk4[sp38].unk1C[sp34] = *unksp28.sp28_1++;
                    }
                }
            }
        }
    }
    else
    {
        sp2C->unk70 = 0;
    }

    for (sp3C = 0; sp3C < arg0->unk4; sp3C++)
    {
        if (sp20[sp3C].unk0 == 7)
        {
            break;
        }
    }

    if (sp3C < arg0->unk4)
    {
        if (sp20[sp3C].unk4 == 4)
        {
            sp1C = sp20[sp3C].unk8 + (char *)arg0;
            sp18 = sp1C + 3;

            for (sp3C = 0; sp3C < 3; sp3C++)
            {
                sp2C->unkC[sp3C] = sp1C[sp3C];
                sp2C->unk18[sp3C] = sp18[sp3C];
            }
        }
    }

    func_80011EF0(sp2C);
    func_800120FC(sp2C);

    return &sp2C->unk0;
}

void func_8001369C(struct UnkStruct_8001369C *arg0, s32 arg1)
{
    s32 sp1C;

    for (sp1C = 0; sp1C < arg1; sp1C++)
    {
        if (arg0[sp1C].unk4 != 0)
        {
            free(arg0[sp1C].unk0);
        }
    }
    free(arg0);
}

void func_80013754(struct UnkStruct800120FC *arg0)
{
    s32 sp1C;
    struct UnkStruct_80013754 *sp18;

    for (sp18 = arg0->unk64, sp1C = 0; sp1C < arg0->unk68; sp1C++)
    {
        func_8001369C(sp18[sp1C].unk4, sp18[sp1C].unk8);
    }
    free(arg0->unk64);
    arg0->unk64 = NULL;
    arg0->unk68 = 0;
}

void func_80013814(struct UnkStruct_80013814 *arg0, s32 arg1)
{
    s32 sp1C;

    for (sp1C = 0; sp1C < arg1; sp1C++)
    {
        if (arg0[sp1C].unk0 == 0x2F)
        {
            if (arg0[sp1C].unk8 != 0)
            {
                free(arg0[sp1C].unk10);
                free(arg0[sp1C].unkC);
            }
        }
        else if (arg0[sp1C].unk0 == 0x30)
        {
            free(arg0[sp1C].unk1C);
            free(arg0[sp1C].unk18);
        }
    }
    free((void *)arg0);
}

void func_80013948(struct UnkStruct800120FC *arg0)
{
    UNUSED s32 pad;
    s32 sp20;
    struct UnkStruct_80013948 *sp1C;

    for (sp1C = arg0->unk6C, sp20 = 0; (int)sp20 < arg0->unk70; sp20++)
    {
        func_80013814(sp1C[sp20].unk4, sp1C[sp20].unk8);
    }

    free(arg0->unk6C);
    arg0->unk6C = NULL;
    arg0->unk70 = 0;
}

// void func_80013754(void *);                             /* extern */

void func_80013A00(struct UnkStruct800120FC *arg0)
{
    if (D_8004A3D4 != NULL)
    {
        free(D_8004A3D4);
    }
    D_8004A3D4 = NULL;
    D_80055D68 = 0;
    if (D_8004A3D0 != NULL)
    {
        free(D_8004A3D0);
    }
    D_8004A3D0 = NULL;
    D_80055D64 = 0;
    if (arg0->unk6C != 0)
    {
        func_80013948(arg0);
    }
    if (arg0->unk64 != 0)
    {
        func_80013754(arg0);
    }
    free(arg0);
}

void func_80013AE0(f32 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        arg0[i + 12] += ((arg0[i] * arg1) + (arg0[i + 4] * arg2) + (arg0[i + 8] * arg3));
    }
}

void func_80013B70(f32 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        arg0[i] = arg0[i] * arg1;
        arg0[i + 4] = (f32)(arg0[i + 4] * arg2);
        arg0[i + 8] = (f32)(arg0[i + 8] * arg3);
    }
}

// Multiply two matrices and store the result in mf1
void func_80013C0C(float mf1[3][4], float mf2[3][3])
{
    int i;
    int j;
    int k;
    float result[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            result[i][j] = 0.0f;
            for (k = 0; k < 3; k++)
            {
                result[i][j] += mf2[i][k] * mf1[k][j];
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mf1[i][j] = result[i][j];
        }
    }
}

// Needs rodata
extern f32 D_8004A3F0;

void func_80013D68(f32 arg0[3][4], f32 arg1, f32 arg2, f32 arg3)
{
    f32 sp34[3][3];
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    arg1 *= D_8004A3F0;
    arg2 *= D_8004A3F0;
    arg3 *= D_8004A3F0;
    sp30 = sinf(arg1);
    sp24 = cosf(arg1);
    sp2C = sinf(arg2);
    sp20 = cosf(arg2);
    sp28 = sinf(arg3);
    sp1C = cosf(arg3);
    sp34[0][0] = (f32)(sp20 * sp1C);
    sp34[0][1] = (f32)(sp20 * sp28);
    sp34[0][2] = (f32)-sp2C;
    sp34[0][3] = (f32)((sp30 * sp2C * sp1C) - (sp24 * sp28));
    sp34[1][1] = (f32)((sp30 * sp2C * sp28) + (sp24 * sp1C));
    sp34[1][2] = (f32)(sp30 * sp20);
    sp34[1][3] = (f32)((sp24 * sp2C * sp1C) + (sp30 * sp28));
    sp34[2][1] = (f32)((sp24 * sp2C * sp28) - (sp30 * sp1C));
    sp34[2][2] = (f32)(sp24 * sp20);
    func_80013C0C(arg0, sp34);
}

//.data
extern f32 D_8004A3F4;

void func_80013F6C(f32 *arg0, f32 arg1)
{
    s32 i;
    f32 sp30;
    f32 sp2C;
    f32 unk4[3];
    f32 sp1C[1];

    sp1C[0] = arg1 * D_8004A3F4;
    sp30 = sinf(sp1C[0]);
    sp2C = cosf(sp1C[0]);

    for (i = 0; i < 3; i++)
    {
        unk4[i - 1] = arg0[i + 4];
    }

    for (i = 0; i < 3; i++)
    {
        arg0[i + 4] = (unk4[i - 1] * sp2C) + (arg0[i + 8] * sp30);
        arg0[i + 8] = ((-unk4[i - 1] * sp30)) + (arg0[i + 8] * sp2C);
    }
}

//.data
extern f32 D_8004A3F8;

void func_80014098(f32 *arg0, f32 arg1)
{
    s32 i;
    f32 sp30;
    f32 sp2C;
    f32 unk4[3];
    f32 sp1C[1];

    sp1C[0] = arg1 * D_8004A3F8;
    sp30 = sinf(sp1C[0]);
    sp2C = cosf(sp1C[0]);

    for (i = 0; i < 3; i++)
    {
        unk4[i - 1] = arg0[i];
    }

    for (i = 0; i < 3; i++)
    {
        arg0[i] = (unk4[i - 1] * sp2C) - (arg0[i + 8] * sp30);
        arg0[i + 8] = ((unk4[i - 1] * sp30)) + (arg0[i + 8] * sp2C);
    }
}

//.data
extern f32 D_8004A3FC;

void func_800141C4(f32 *arg0, f32 arg1)
{
    s32 i;
    f32 sp30;
    f32 sp2C;
    f32 unk4[3];
    f32 sp1C[1];

    sp1C[0] = arg1 * D_8004A3FC;
    sp30 = sinf(sp1C[0]);
    sp2C = cosf(sp1C[0]);

    for (i = 0; i < 3; i++)
    {
        unk4[i - 1] = arg0[i];
    }

    for (i = 0; i < 3; i++)
    {
        arg0[i] = (unk4[i - 1] * sp2C) + (arg0[i + 4] * sp30);
        arg0[i + 4] = ((-unk4[i - 1] * sp30)) + (arg0[i + 4] * sp2C);
    }
}

// Manual gfx stuff?
UNUSED void func_800142F0(Gfx *arg0, struct UnkStruct_800142F0 *arg1)
{
    u32 sp4;

    sp4 = 0xFC000000;
    sp4 |= (((s32)arg1->unk0 & 0xF) << 0x14) | ((arg1->unk8 & 0x1F) << 0xF) | (arg1->unk10 << 0xC) | (arg1->unk18 << 9);
    sp4 |= ((arg1->unk20 & 0xF) << 5) | (arg1->unk28 & 0x1F);
    arg0->words.w0 = sp4;
    sp4 = (arg1->unk1C << 9) | (((arg1->unk4 & 0xF) << 0x1C) | ((arg1->unkC & 7) << 0xF) | (arg1->unk14 << 0xC));
    sp4 |= (((arg1->unk24 & 0xF) << 0x18) | (arg1->unk30 << 0x15) | (arg1->unk38 << 0x12) | ((arg1->unk2C & 7) << 6) | (arg1->unk34 * 8) | arg1->unk3C);
    arg0->words.w1 = sp4;
}

UNUSED s32 func_80014414(u8 c)
{
    if (c >= 'a')
    {
        c = (c - ' ');
    }
    if (c >= 'A')
    {
        return c - '7';
    }
    return c - '0';
}

s32 func_80014414(u8); /* extern */

UNUSED void func_8001445C(Gfx *arg0, u8 *arg1)
{
    s32 sp64;
    UNUSED s32 sp1C[15];
    s32 sp24;
    register s32 temp;

    for (sp64 = 0; sp64 < 8; sp64++)
    {
        sp1C[sp64 + 7] = temp = func_80014414(arg1[sp64]);
        sp1C[sp64 - 1] = temp;
    }

    func_800142F0(arg0, &sp24);
}

UNUSED void func_800144F4(Gfx *arg0, u8 *arg1, u8 *arg2)
{
    s32 sp5C;
    UNUSED s32 sp1C[16];

    for (sp5C = 0; sp5C < 8; sp5C++)
    {
        sp1C[sp5C] = func_80014414(arg1[sp5C]);
        sp1C[sp5C + 8] = func_80014414(arg2[sp5C]);
    }

    func_800142F0(arg0, (struct UnkStruct_800142F0 *)&sp1C[0]);
}

UNUSED void func_800145A8(Gfx *arg0, u32 arg1)
{
    arg0->words.w0 = 0xB900031D;
    arg0->words.w1 = arg1;
}

UNUSED u32 func_800145C8(char *arg0)
{
    u32 sp4;

    sp4 = 0;
    if ((*arg0 >= 0x30) && (*arg0 < 0x34))
    {
        sp4 |= (*arg0 - 0x30) << 0x1E;
    }
    arg0++;
    if ((*(arg0) >= 0x30) && (*(arg0) < 0x34))
    {
        sp4 |= (*arg0 - 0x30) << 0x1A;
    }
    arg0++;
    if ((*arg0 >= 0x30) && ((s32)*arg0 < 0x34))
    {
        sp4 |= (*arg0 - 0x30) << 0x16;
    }
    arg0++;
    if ((*arg0 >= 0x30) && (*arg0 < 0x34))
    {
        sp4 |= (*arg0 - 0x30) << 0x12;
    }
    return sp4;
}

UNUSED void func_800146F8(Gfx *arg0, char *arg1, char *arg2, char *arg3)
{
    union
    {
        s32 sp2C_0;
        u32 sp2C_1;
    } unksp2C;

    u32 sp28;
    char *sp24;

    unksp2C.sp2C_0 = 0;
    sp24 = arg1;

    if ((*sp24++) == 0x31)
    {
        unksp2C.sp2C_0 |= 8;
    }
    if ((*sp24++) == 0x31)
    {
        unksp2C.sp2C_0 |= 0x10;
    }
    if ((*sp24++) == 0x31)
    {
        unksp2C.sp2C_0 |= 0x20;
    }
    if ((*sp24++) == 0x31)
    {
        unksp2C.sp2C_0 |= 0x40;
    }

    if ((*sp24++) == 0x31)
    {
        unksp2C.sp2C_0 |= 0x80;
    }
    if (((s32)*sp24 >= 0x30) && ((s32)*sp24 < 0x34))
    {
        unksp2C.sp2C_0 |= (*sp24 - 0x30) << 8;
    }
    sp24 += 1;
    if (((s32)*sp24 >= 0x30) && ((s32)*sp24 < 0x34))
    {
        unksp2C.sp2C_0 |= (*sp24 - 0x30) << 0xA;
    }
    sp24 += 1;

    if ((*sp24++) == 0x31)
    {
        unksp2C.sp2C_0 |= 0x1000;
    }
    if ((*sp24++) == 0x31)
    {
        unksp2C.sp2C_0 |= 0x2000;
    }
    if ((*sp24++) == 0x31)
    {
        unksp2C.sp2C_0 |= 0x4000;
    }
    if ((*sp24++) == 0x31)
    {
        unksp2C.sp2C_0 = unksp2C.sp2C_1;
    }

    sp28 = func_800145C8(arg2);
    sp28 |= func_800145C8(arg3) >> 2;
    func_800145A8(arg0, unksp2C.sp2C_0 | sp28);
}

UNUSED void func_80014A00(Gfx *arg0, char *arg1, char *arg2)
{
    func_800146F8(arg0, arg1, arg2, arg2);
}

UNUSED f32 func_80014A44(f32 arg0)
{
    s32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 sp4;

    sp8 = 1.0f;
    sp10 = arg0;
    spC = SQ(arg0);
    sp4 = arg0;

    for (sp14 = 3; sp14 < 7; sp14 += 2)
    {
        sp8 *= (f32)((sp14 - 1) * sp14);
        sp10 *= spC;
        sp4 -= sp10 / sp8;
    }

    return sp4;
}
