#include <ultra64.h>

struct Vec3f D_8004A3A0 = {0.0f, 0.0f, 0.0f};
struct Vec3f D_8004A3AC = {0.0f, 0.0f, 0.0f};
struct Vec3f D_8004A3B8 = {1.0f, 1.0f, 1.0f};

// functions
void func_8000FEB0(struct UnkInputStruct8000FEB0 *arg0);                                                                                     // in file
void func_8000FF44(struct UnkInputStruct8000FF44 *arg0);                                                                                     // in file
void func_8001000C(struct UnkInputStruct8000FF44 *arg0);                                                                                     // in file
void func_80010098(struct UnkInputStruct80010098 *arg0);                                                                                     // in file
void *func_800100E8(void *arg0, s32 arg1);                                                                                                   // in file
void func_80010350(struct UnkInputStruct80010350 *arg0);                                                                                     // in file
struct UnkStruct80010408_SP2C *func_80010408(struct UnkInputStruct80010408 *arg0, u32 arg1);                                                 // externally called
void func_800105D8(struct UnkStruct800105D8 *arg0);                                                                                          // externally called
void func_80010634(struct UnkInputStruct80010098 *arg0, s32 arg1, s32 arg2);                                                                 // in file
f32 func_800108D0(struct UnkInputStruct800108D0 *arg0, f32 arg1);                                                                            // in file
void func_80010A5C(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3);                                                                               // in file
f32 func_80010AD0(f32 arg0, f32 arg1, f32 arg2);                                                                                             // in file
void func_80010B6C(struct UnkInputStruct80010B6C *arg0, struct UnkInputStruct80010B6C *arg1, struct UnkInputStruct80010B6C *arg2, f32 arg3); // in file
void func_80010C14(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3);                                                                               // in file
void func_80010C88(struct UnkInputStruct80010C88 *arg0, s32 arg1);                                                                           // in file
void func_80010E0C(struct UnkInputStruct80010C88 *arg0, s32 arg1, s32 arg2);                                                                 // in file
void func_80011084(struct UnkInputStruct80011084 *arg0, f32 arg1);                                                                           // in file
void func_800111D4(struct UnkStruct800111D4 *arg0, s32 arg1, f32 arg2);                                                                      // in file
void func_80011424(struct UnkInputStruct80011424 *arg0, f32 arg1);                                                                           // externally called
void *func_800117F8(struct UnkStruct800117F8_Arg0 *arg0);                                                                                    // in file
void *func_8001191C(struct UnkStruct80010408_SP2C *arg0, s32 arg1);                                                                          // externally called
void func_80011D18(struct UnkStruct80011D18 *arg0);                                                                                          // in file
void func_80011DD0(struct UnkStruct80011DD0 *arg0);                                                                                          // externally called

void func_8000FEB0(struct UnkInputStruct8000FEB0 *arg0)
{
    arg0->unk0 = D_8004A3A0;
    arg0->unkC = D_8004A3AC;
    arg0->unk18 = D_8004A3B8;
}

void func_8000FF44(struct UnkInputStruct8000FF44 *arg0)
{
    struct UnkStruct80055D50 *sp4;

    if (arg0 == NULL)
    {
        return;
    }
    sp4 = &D_80055D50[arg0->unk4];
    arg0->unk14[0] = sp4->unk4[0];
    arg0->unk14[1] = sp4->unk4[1];
    arg0->unk14[2] = sp4->unk4[2];
}

void func_8001000C(struct UnkInputStruct8000FF44 *arg0)
{
    s32 sp1C;

    func_8000FF44(arg0);

    for (sp1C = 0; sp1C < arg0->unk10; sp1C++)
    {
        func_8001000C(arg0->unkC[sp1C]);
    }
}

void func_80010098(struct UnkInputStruct80010098 *arg0)
{
    if (arg0->unk0 == 1)
    {
        func_8001000C(arg0->unk28);
    }
}

void *func_800100E8(void *arg0, s32 arg1)
{
    struct UnkInputStruct800100E8_SP24 *sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    D_80055D4C += 1;
    sp24 = malloc(0x3C);
    sp24->unk8 = arg0;
    sp24->unk0 = D_80055D50[arg1].unk0;
    sp24->unk4 = arg1;
    func_8000FF44(sp24);
    if (D_80055D50[arg1].unk2C != 0)
    {
        for (sp1C = D_80055D50[arg1].unk2C + arg1, sp18 = 1; D_80055D50[sp1C].unk28 != 0; sp1C += D_80055D50[sp1C].unk28, sp18++)
        {
        }
        sp24->unk10 = sp18;
        sp24->unkC = malloc(sp18 * 4);
        for (sp1C = D_80055D50[arg1].unk2C + arg1, sp20 = 0; sp20 < sp18; sp1C += D_80055D50[sp1C].unk28, sp20++)
        {
            sp24->unkC[sp20] = func_800100E8(sp24, sp1C);
        }
    }
    else
    {
        sp24->unk10 = 0;
        sp24->unkC = NULL;
    }
    return sp24;
}

void func_80010350(struct UnkInputStruct80010350 *arg0)
{
    s32 sp1C;
    u32 *sp18;

    if (arg0->unk10 != 0)
    {
        for (sp18 = arg0->unkC, sp1C = 0; sp1C < arg0->unk10; sp1C++)
        {
            func_80010350(sp18[sp1C]);
        }
        free(sp18);
    }
    free(arg0);
}

struct UnkStruct80010408_SP2C *func_80010408(struct UnkInputStruct80010408 *arg0, u32 arg1)
{
    struct UnkStruct80010408_SP2C *sp2C;
    struct UnkInputStruct80010408_Inner *sp28;
    s32 sp24;

    sp28 = arg0->unkC;
    if (arg0->unk4 <= arg1)
    {
        return NULL;
    }
    sp2C = malloc(sizeof(struct UnkStruct80010408_SP2C));
    func_8000FEB0(&sp2C->unk4);
    switch (sp28[arg1].unk0)
    { /* irregular */
    case 0:
    case 5:
    case 6:
        sp2C->unk0 = 0;
        sp2C->unk28 = (void *)arg1;
        break;
    case 1:
        D_80055D4C = 0;
        sp2C->unk0 = 1;
        sp2C->unk28 = func_800100E8(NULL, sp28[arg1].unk4);
        break;
    default:
        break;
    }

    for (sp24 = 0; sp24 < 3; sp24++)
    {
        D_80055D30[sp24] = D_8016E3AC[sp24 + 3];
    }

    for (sp24 = 0; sp24 < 3; sp24++)
    {
        D_80055D40[sp24] = D_8016E3AC[sp24 + 6];
    }

    return sp2C;
}

void func_800105D8(struct UnkStruct800105D8 *arg0)
{
    if (arg0->unk0 == 1)
    {
        func_80010350(arg0->unk28);
    }
    free(arg0);
}

void func_80010634(struct UnkInputStruct80010098 *arg0, s32 arg1, s32 arg2)
{
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    struct UnkInputStruct8000FF44 *sp28;
    struct UnkInputStruct80010634_SP20 *sp24;
    struct UnkInputStruct80010634_SP20 *sp20;
    char pad[1];

    if (arg0->unk0 != 1U)
    {
        return;
    }
    if (arg2 != 0)
    {
        func_80010098(arg0);
    }

    sp24 = D_80055D54[D_8004A3D0[arg1]].unk4;
    sp2C = D_80055D54[D_8004A3D0[arg1]].unk8;

    for (sp34 = 0; sp34 < sp2C; sp34++)
    {
        sp20 = &sp24[sp34];
        sp28 = arg0->unk28;

        for (sp30 = 1; sp30 < sp20->unk4; sp30++)
        {
            sp28 = sp28->unkC[sp20->unk0[sp30]];
        }

        sp28->unk14[0] = sp24[sp34].unk8;
        sp28->unk14[1] = sp24[sp34].unk14;
        sp28->unk14[2] = sp24[sp34].unk20;
        (sp28 + 1)->unk0 = 1;
    }
}

f32 func_800108D0(struct UnkInputStruct800108D0 *arg0, f32 arg1)
{
    char pad[4];
    s32 sp18;
    s32 sp14;
    f32 sp10;
    s32 *spC;
    s32 sp8;
    f32 *sp4;

    sp14 = (s32)arg1;

    switch (arg0->unk0)
    {
    case 0x31:
        spC = arg0->unk8;
        sp4 = arg0->unkC;
        sp8 = arg0->unk4;

        //! @bug: duplicate check? left in the ROM due to unoptimized code.
        for (sp18 = 0; sp18 < sp18 < sp8; sp18++)
        {
            if (spC[sp18] >= sp14)
            {
                break;
            }
        }

        if (spC[sp18] == sp14)
        {
            sp10 = sp4[sp18];
        }
        else
        {
            sp10 = sp4[sp18 - 1] + (((sp4[sp18] - sp4[sp18 - 1]) / (f32)(spC[sp18] - spC[sp18 - 1])) * (arg1 - (f32)spC[sp18 - 1]));
        }
        break;
    }

    return sp10;
}

// this might operate on Vectors, but I dont know yet
void func_80010A5C(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3)
{
    arg2[0] = (f32)(((arg1[0] - arg0[0]) * arg3) + arg0[0]);
    arg2[1] = (f32)(((arg1[1] - arg0[1]) * arg3) + arg0[1]);
    arg2[2] = (f32)(((arg1[2] - arg0[2]) * arg3) + arg0[2]);
}

f32 func_80010AD0(f32 arg0, f32 arg1, f32 arg2)
{
    if (arg0 > 180.0)
    {
        arg0 -= 360.0;
    }
    if (arg1 > 180.0)
    {
        arg1 -= 360.0;
    }
    return ((arg1 - arg0) * arg2) + arg0;
}

void func_80010B6C(struct UnkInputStruct80010B6C *arg0, struct UnkInputStruct80010B6C *arg1, struct UnkInputStruct80010B6C *arg2, f32 arg3)
{
    arg2->unk0 = func_80010AD0(arg0->unk0, arg1->unk0, arg3);
    arg2->unk4 = func_80010AD0(arg0->unk4, arg1->unk4, arg3);
    arg2->unk8 = func_80010AD0(arg0->unk8, arg1->unk8, arg3);
}

void func_80010C14(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3)
{
    arg0[0] = (f32)(((arg1[0] - arg2[0]) * arg3) + arg0[0]);
    arg0[1] = (f32)(((arg1[1] - arg2[1]) * arg3) + arg0[1]);
    arg0[2] = (f32)(((arg1[2] - arg2[2]) * arg3) + arg0[2]);
}

void func_80010C88(struct UnkInputStruct80010C88 *arg0, s32 arg1)
{
    s32 sp24;
    struct UnkStruct80055D50 *sp20;
    struct UnkStruct8004A3A0 *sp1C;

    if (arg0 == NULL)
    {
        return;
    }
    sp1C = &arg0->unk18[arg1];
    sp20 = &D_80055D50[arg0->unk0[1]];
    sp1C[0] = sp20->unk4[0];
    sp1C[1] = sp20->unk4[1];
    sp1C[2] = sp20->unk4[2];

    arg0->unk10[arg1] = 0;

    for (sp24 = 0; sp24 < arg0->unkC; sp24++)
    {
        func_80010C88(arg0->unk8[sp24], arg1);
    }
}

void func_80010E0C(struct UnkInputStruct80010C88 *arg0, s32 arg1, s32 arg2)
{
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    char pad[4];
    struct UnkInputStruct80010C88 *sp2C;
    struct UnkInputStruct80010634_SP20 *sp28;
    struct UnkInputStruct80010634_SP20 *sp24;
    struct UnkInputStruct80010B6C_2 *sp20;
    char pad2[4];

    func_80010C88(arg0, arg2);
    sp3C = arg1;
    sp28 = D_80055D54[sp3C].unk4;
    sp34 = D_80055D54[sp3C].unk8;

    for (sp3C = 0; sp3C < sp34; sp3C++)
    {
        sp2C = arg0;
        sp24 = &sp28[sp3C];
        for (sp38 = 1; sp38 < sp24->unk4; sp38++)
        {
            sp2C = sp2C->unk8[sp24->unk0[sp38]];
        }
        sp20 = &sp2C->unk18[arg2];
        sp20->unk0[0] = sp28[sp3C].unk8;
        sp20->unk0[1] = sp28[sp3C].unk14;
        sp20->unk0[2] = sp28[sp3C].unk20;
        sp2C->unk10[arg2] = 1;
    }
}

void func_80011084(struct UnkInputStruct80011084 *arg0, f32 arg1)
{
    s32 sp24;
    f32 *sp20;
    f32 *sp1C;
    f32 *sp18;

    if (arg0 == NULL)
    {
        return;
    }
    if ((arg0->unk14 | arg0->unk10) != 0)
    {
        sp20 = arg0->unk18;
        sp1C = arg0->unk3C;
        sp18 = arg0->unk0->unk14;
        func_80010A5C(sp20, sp1C, sp18, arg1);
        func_80010B6C((struct UnkInputStruct80010B6C *)(sp20 + 0x3), (struct UnkInputStruct80010B6C *)(sp1C + 0x3), (struct UnkInputStruct80010B6C *)(sp18 + 0x3), arg1);
        func_80010A5C(sp20 + 0x6, sp1C + 0x6, sp18 + 0x6, arg1);
    }
    for (sp24 = 0; sp24 < arg0->unkC; sp24++)
    {
        func_80011084(arg0->unk8[sp24], arg1);
    }
}

void func_800111D4(struct UnkStruct800111D4 *arg0, s32 arg1, f32 arg2)
{
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    struct UnkStruct800111D4_Inner *sp30;
    s32 unused[3];
    struct UnkInputStruct80010634_SP20 *sp20;
    struct UnkInputStruct80010634_SP20 *sp1C;

    sp20 = D_80055D54[arg1].unk4;
    sp34 = D_80055D54[arg1].unk8;

    for (sp3C = 0; sp3C < sp34; sp3C++)
    {
        sp1C = &sp20[sp3C];
        sp30 = arg0->unk28;

        for (sp38 = 1; sp38 < sp1C->unk4; sp38++)
        {
            sp30 = sp30->unkC->unk0[sp1C->unk0[sp38]];
        }
        func_80010C14(&sp30->unk14, &sp20[sp3C].unk8.unk0, &D_80055D50[sp30->unk0[1]].unk4[0].unk0, arg2);
        func_80010C14(&sp30->unk20, &sp20[sp3C].unk14.unk0, &D_80055D50[sp30->unk0[1]].unk4[1].unk0, arg2);
        func_80010C14(&sp30->unk2C, &sp20[sp3C].unk20.unk0, &D_80055D50[sp30->unk0[1]].unk4[2].unk0, arg2);
    }
}

void func_80011424(struct UnkInputStruct80011424 *arg0, f32 arg1)
{
    s32 i;
    s32 j;
    s32 sp3C;
    struct UnkStruct80011424_SP38 *sp38;
    f32 sp34;
    struct UnkInputStruct80010098 *sp30;
    s32 *sp2C;
    s32 sp28;
    s32 *sp24;
    f32 sp20;
    u32 pad;
    f32 sp18;

    arg0->unk4 = arg1;
    sp30 = arg0->unk0;
    func_80010098(sp30);

    for (i = 0; i < arg0->unkC; i++)
    {
        sp38 = &arg0->unk10[i];

        if ((arg1 < sp38->unk8) || (arg1 > sp38->unkC))
        {
            continue;
        }
        sp34 = arg1 - sp38->unk8;
        if (sp38->unk4 == 0x2F)
        {
            sp28 = sp38->unk18;
            sp2C = sp38->unk14;
            sp24 = sp38->unk10;
            sp3C = sp34;
            for (j = 1; j < sp28; j++)
            {
                if (sp2C[j] > sp3C)
                {
                    break;
                }
            }
            if ((j == sp28) && (sp3C == sp34))
            {
                j -= 1;
            }
            else
            {
            }
            if (sp24[j - 1] != sp38->unk20)
            {
                sp38->unk20 = sp24[j - 1];
                func_80010E0C(sp38->unk1C, sp24[j - 1], 0);
            }
            if (sp24[j] != sp38->unk24)
            {
                sp38->unk24 = sp24[j];
                func_80010E0C(sp38->unk1C, sp24[j], 1);
            }
            sp20 = (sp34 - sp2C[j - 1]) / (sp2C[j] - sp2C[j - 1]);
            func_80011084(sp38->unk1C, sp20);
        }
        else if (sp38->unk4 == 0x30)
        {
            sp18 = func_800108D0(sp38->unk18, sp34);
            func_800111D4(sp30, sp38->unk10, sp18);
        }
    }
}

void *func_800117F8(struct UnkStruct800117F8_Arg0 *arg0)
{
    s32 i;
    s32 count;
    struct UnkStruct800117F8_SP1C *sp1C;

    if (arg0 == NULL)
    {
        return NULL;
    }
    sp1C = malloc(sizeof(struct UnkStruct800117F8_SP1C));
    sp1C->unk0 = arg0;
    if ((count = arg0->unk10) != 0)
    {
        sp1C->unk8 = malloc(count * 4);
        for (i = 0; i < count; i++)
        {
            sp1C->unk8[i] = func_800117F8(arg0->unkC[i]);
        }
        sp1C->unkC = i;
    }
    else
    {
        sp1C->unkC = 0;
        sp1C->unk8 = NULL;
    }
    return sp1C;
}

void *func_8001191C(struct UnkStruct80010408_SP2C *arg0, s32 arg1)
{
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    u8 *sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    u32 *sp3C;
    u32 *sp38;
    struct UnkStruct8001191C_SP34 *sp34;
    struct UnkStruct80165290_Unk20 *sp30;
    struct UnkStruct80165290_Unk20_Unk10 *sp2C;
    struct UnkStruct8001191C_SP28 *sp28;
    struct UnkStruct8001191C_SP2C *sp24;

    if (arg0->unk0 != 1)
    {
        return 0;
    }
    sp30 = malloc(0x14);
    sp30->unk0 = arg0;
    sp30->unk4 = 0.0f;
    sp30->unkC = sp4C = D_80055D5C[arg1].unk8;
    sp30->unk10 = malloc(sp4C * 0x28);
    sp34 = D_80055D5C[arg1].unk4;
    sp54 = 0;

    for (sp5C = 0; sp5C < sp4C; sp5C++)
    {
        sp2C = &sp30->unk10[sp5C];
        sp50 = NULL;
        // todo: more stupid nested structs. Fix
        switch (sp2C->unk4 = sp34[sp5C].unk0)
        {
        case 47:
            if (sp34[sp5C].unk8 <= 0)
            {
            }
            sp28 = (void *)&sp34[sp5C].unk4;
            sp48 = sp28->unk4;
            sp38 = malloc(sp48 * 4);
            sp2C->unk10 = sp38;
            sp3C = malloc(sp48 * 4);
            sp2C->unk14 = sp3C;
            sp2C->unk18 = (s32 *)sp48;
            sp2C->unk1C = func_800117F8(arg0->unk28);
            sp2C->unk20 = -1;
            sp2C->unk24 = -1;
            for (sp58 = 0; sp58 < sp48; sp58++)
            {
                sp38[sp58] = sp28->unk8[sp58];
                sp3C[sp58] = sp50;
                sp50 += sp28->unkC[sp58];
            }
            sp44 = sp28->unk0;
            break;
        case 48:
            sp24 = (void *)&sp34[sp5C].unk4;
            sp2C->unk10 = (void *)sp24->unk8;
            sp2C->unk14 = sp50 = sp24->unk4;
            sp2C->unk18 = (s32 *)(sp24 + 0x1);
            sp44 = sp24->unk0;
            sp40 = sp24->unk0 + sp24->unk4;
            break;
        default:
            break;
        }
        sp2C->unk8 = sp44;
        sp2C->unkC = (void *)(sp44 + sp50);
        if (sp54 < (s32)sp50)
        {
            sp54 = sp50;
        }
    }
    sp30->unk8 = sp54;
    func_80011424(sp30, 0);
    return sp30;
}

void func_80011D18(struct UnkStruct80011D18 *arg0)
{
    s32 i;

    if (arg0->unkC != 0)
    {
        for (i = 0; i < arg0->unkC; i++)
        {
            func_80011D18(arg0->unk8[i]);
        }
        free(arg0->unk8);
    }
    free(arg0);
}

void func_80011DD0(struct UnkStruct80011DD0 *arg0)
{
    s32 i;
    struct UnkStruct80011DD0_SP28 *sp28;

    for (i = 0; i < arg0->unkC; i++)
    {
        sp28 = &arg0->unk10[i];
        switch (sp28->unk4)
        {
        case 47:
            free(sp28->unk10);
            free(sp28->unk14);
            func_80011D18(sp28->unk1C);
            break;
        case 48:
        default:
            break;
        }
    }
    free(arg0->unk10);
    free(arg0);
}
