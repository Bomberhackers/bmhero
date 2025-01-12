#include <ultra64.h>

void func_800260E0(s32 arg0)
{
    D_80165118[arg0] = 0;
}

void func_800260FC(s32 arg0)
{
    u8 sp7;

    sp7 = D_80165118[arg0] & 0xFC;
    D_80165118[arg0] = sp7 | 1;
}

void func_8002613C(s32 arg0)
{
    u8 sp7;

    sp7 = D_80165118[arg0] & 0xFC;
    D_80165118[arg0] = sp7 | 2;
}

void func_8002617C(s32 arg0)
{
    u8 sp7;

    sp7 = D_80165118[arg0] & 0xFC;
    D_80165118[arg0] = sp7 | 3;
}

s32 func_800261BC(s32 arg0)
{
    return D_80165118[arg0] & 3;
}

void func_800261E8(s32 arg0, char arg1)
{
    u8 sp7;
    s16 sp4;

    sp4 = gObjects[arg0].unkFC;
    sp7 = D_80165118[sp4] & 3;
    D_80165118[sp4] = sp7 | (arg1 << 2);
}

u8 func_80026260(s32 arg0)
{
    u8 sp7;

    sp7 = (u8)((s32)(D_80165118[arg0] & 0xFC) >> 2);
    return sp7;
}

void func_8002629C(void)
{
    s32 sp24;
    UNUSED s32 pad0;
    s32 sp1C; // Bool
    UNUSED s32 pad1;

    for (sp24 = 0; sp24 < 0x80; sp24++)
    {
        func_800260E0(sp24);
    }

    for (sp24 = 0; sp24 < 0x80; sp24++)
    {
        if (D_8017796C[sp24].unk0 == -1)
        {
            break;
        }
        if ((D_8017796C[sp24].unk2 != 0x7530) && (D_8017796C[sp24].unk4 != 0x7530) && (D_8017796C[sp24].unk6 != 0x7530))
        {
            sp1C = TRUE;
            if (D_8017796C[sp24].unk0 == 0x27)
            {
                if (func_80025460(D_8013488C, D_8017796C[sp24].unkA) != 0)
                {
                    sp1C = FALSE;
                }
            }
            else if (D_8017796C[sp24].unk0 == 0x36)
            {
                if ((D_80177630 == 0) || (func_800256E0(D_8013488C, 0, D_8017796C[sp24].unkA) != 0))
                {
                    sp1C = FALSE;
                }
            }
            else if (D_8017796C[sp24].unk0 == 0x37)
            {
                if ((D_80177630 == 0) || (func_800256E0(D_8013488C, 1, D_8017796C[sp24].unkA) != 0))
                {
                    sp1C = FALSE;
                }
            }
            else if ((D_8017796C[sp24].unk0 == 0x38))
            {
                if ((D_80177630 == 0) || (func_800256E0(D_8013488C, 2, D_8017796C[sp24].unkA) != 0))
                {
                    sp1C = FALSE;
                }
            }
            if (sp1C)
            {
                func_800260FC(sp24);
            }
        }
    }
}

void func_80026548(void)
{
    UnkStruct80165100 *sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    f32 view_x;
    f32 view_y;
    f32 view_z;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    struct ObjectStruct *sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    view_x = gView.at.x;
    view_y = gView.at.y;
    view_z = gView.at.z;

    for (sp24 = &gObjects[14], sp44 = 14; sp44 < 78; sp24++, sp44++)
    {
        if (sp24->unkA4 != 0)
        {
            sp1C = 0;
            sp30 = sp24->Pos.x - view_x;
            sp2C = sp24->Pos.y - view_y;
            sp28 = sp24->Pos.z - view_z;
            if ((sp24->unkE6[0] == -1) && !(D_80124D90[sp24->unkE4].unk4 & 1))
            {
                if ((SQ(sp30) + SQ(sp2C) + SQ(sp28)) > D_80177984)
                {
                    for (sp48 = 0; sp48 < 0xA; sp48++)
                    {
                        if (sp24->unk10E[sp48] != -1)
                        {
                            func_800272E8(sp44);
                        }
                    }

                    for (sp48 = 0; sp48 < 0xA; sp48++)
                    {
                        if (sp24->unkE8[sp48] != -1)
                        {
                            func_8001A928(sp24->unkE8[sp48]);
                        }
                    }
                    if (sp24->unkFC != -1)
                    {
                        func_8002613C((s32)sp24->unkFC);
                    }
                    func_8001A928(sp44);
                }
                else
                {
                    sp1C = 1;
                }
            }
            else
            {
                sp1C = 1;
            }
            if (sp1C != 0)
            {
                sp24->unk131 = 0;
                if (!(D_80124D90[sp24->unkE4].unk4 & 4))
                {
                    if (!(D_8017798C <= sp30) || !(D_80177994 >= sp30) || !(D_8017799C <= sp2C) || !(D_801779A4 >= sp2C) || !(D_801779AC <= sp28) || !(D_801779B8 >= sp28))
                    {
                        sp24->unk131 |= 2;
                    }
                }
                if (!(-960.0f <= sp30) || !(960.0f >= sp30) || !(-480.0f <= sp2C) || !(540.0f >= sp2C) || !(-960.0f <= sp28) || !(480.0f >= sp28))
                {
                    sp24->unk131 |= 4;
                }
            }
        }
    }
    sp4C = D_8017796C;

    for (sp40 = 0; sp40 < 0x80; sp40++)
    {
        sp20 = func_800261BC(sp40);
        if (sp20 == 2)
        {
            sp30 = sp4C[sp40].unk2 - view_x;
            sp2C = sp4C[sp40].unk4 - view_y;
            sp28 = sp4C[sp40].unk6 - view_z;
            if ((SQ(sp30) + SQ(sp2C) + SQ(sp28)) > D_8017797C)
            {
                func_800260FC(sp40);
            }
        }
        else if ((sp20 == 1))
        {
            sp18 = sp4C[sp40].unk0;
            sp30 = sp4C[sp40].unk2 - view_x;
            sp2C = sp4C[sp40].unk4 - view_y;
            sp28 = sp4C[sp40].unk6 - view_z;
            if (SQ(sp30) + SQ(sp2C) + SQ(sp28) <= (D_8017797C) || (D_80124D90[sp18].unk4 & 2))
            {
                D_80165108 = (s16)sp18;
                D_8016510A = sp4C[sp40].unk2;
                D_8016510C = sp4C[sp40].unk4;
                D_8016510E = sp4C[sp40].unk6;
                D_80165110 = sp4C[sp40].unk8;
                D_80165112 = sp4C[sp40].unkA;
                D_80165114 = sp4C[sp40].unkC;
                D_80165116 = sp4C[sp40].unkE;
                D_80165100 = &D_80165108;
                D_80165198 = -1;
                D_8016519C = sp40;
                D_80124D90[sp18].routine();
                if (D_80165198 != -1)
                {
                    gObjects[D_80165198].unkFC = (s16)sp40;
                    func_8002617C(sp40);
                }
            }
        }
    }
}

s32 func_80026DBC(s32 arg0)
{
    s32 spC;
    struct ObjectStruct *sp8;
    s32 sp4;

    sp4 = FALSE;

    for (spC = 0xE, sp8 = &gObjects[0xE]; spC < 0x4E; spC++, sp8++)
    {
        if (sp8->unkE4 == arg0)
        {
            sp4 = TRUE;
            break;
        }
    }

    if (sp4)
    {
        return spC;
    }

    return -1;
}

s32 func_80026E58(s32 arg0, s32 pos)
{
    s32 spC;
    struct ObjectStruct *sp8;
    s32 sp4;

    sp4 = FALSE;
    for (sp8 = &gObjects[pos], spC = pos; spC < 0x4E; spC++, sp8++)
    {
        if (sp8->unkE4 == arg0)
        {
            sp4 = TRUE;
            break;
        }
    }

    if (sp4)
    {
        return spC;
    }
    return -1; // Item not found
}

void func_80026F10(s32 arg0, s32 arg1)
{
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 sp4;

    for (sp14 = 0; sp14 < 10; sp14++)
    {
        if (gObjects[arg0].unk10E[sp14] == -1)
        {
            gObjects[arg0].unk10E[sp14] = arg1;
            break;
        }
    }

    for (sp14 = 0; sp14 < 10; sp14++)
    {
        if ((sp4 = gObjects[arg0].unk10E[sp14]) != -1)
        {
            for (sp10 = 0; sp10 < 10; sp10++)
            {
                if (gObjects[sp4].unk10E[sp10] == arg0)
                {
                    break;
                }
            }
            if (sp10 == 10)
            {
                for (sp10 = 0; sp10 < 10; sp10++)
                {
                    if (gObjects[sp4].unk10E[sp10] == -1)
                    {
                        gObjects[sp4].unk10E[sp10] = arg0;
                        break;
                    }
                }
            }

            for (spC = 0; spC < 10; spC++)
            {
                for (sp10 = 0; sp10 < 10; sp10++)
                {
                    if (gObjects[sp4].unk10E[sp10] == gObjects[arg0].unk10E[spC])
                    {
                        if ((gObjects[arg0].unk10E[spC] != -1))
                        {
                            break;
                        }
                    }
                }

                if ((sp10 == 10))
                {
                    if ((gObjects[arg0].unk10E[spC] != sp4))
                    {
                        for (sp8 = 0; sp8 < 10; sp8++)
                        {
                            if (gObjects[sp4].unk10E[sp8] == -1)
                            {
                                gObjects[sp4].unk10E[sp8] = gObjects[arg0].unk10E[spC];
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void func_800272E8(s32 arg0)
{
    s32 spC;
    s32 sp8;
    UNUSED s32 sp4;
    s32 sp0;

    for (spC = 0; spC < 10; spC++)
    {
        if (gObjects[arg0].unk10E[spC] != -1)
        {
            sp0 = gObjects[arg0].unk10E[spC];
            for (sp8 = 0; sp8 < 10; sp8++)
            {
                if (gObjects[sp0].unk10E[sp8] == arg0)
                {
                    gObjects[sp0].unk10E[sp8] = -1;
                    break;
                }
            }
        }
    }

    for (spC = 0; spC < 10; spC++)
    {
        gObjects[arg0].unk10E[spC] = -1;
    }
}

s32 func_80027464(s32 arg0, struct UnkStruct_80027C00 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    s32 unk24[11];
    s32 index;
    s32 sp1C;
    s32 sp18;

    for (index = 0; index < 11; index++)
    {
        unk24[index] = -1;
    }

    index = 0;
    for (sp1C = 0xE; sp1C < 0x4E; sp1C++)
    {
        if (gObjects[sp1C].unkA4 == 0)
        {
            unk24[index] = sp1C;
            index++;
            if (index == arg0)
            {
                break;
            }
        }
    }

    if (sp1C == 0x4E)
    {
        unk24[0] = -1;
    }
    else
    {
        index = 0;
        for (; index < arg0;)
        {
            if (unk24[index] == -1)
            {
                break;
            }

            func_8001A928(unk24[index]);
            func_8001BD44(unk24[index], arg1->unk0, arg1->unk6,
                          gFileArray[arg1->unk4].ptr);
            gObjects[unk24[index]].Pos.x = gObjects[unk24[index]].unk50 = arg2;
            gObjects[unk24[index]].Pos.y = gObjects[unk24[index]].unk54 = arg3;
            gObjects[unk24[index]].Pos.z = gObjects[unk24[index]].unk58 = arg4;
            gObjects[unk24[index]].Rot.y = arg5;
            gObjects[unk24[index]].unk3C = arg5;
            gObjects[unk24[index]].unkA4 = 1;
            gObjects[unk24[index]].unkE4 = arg1->unk2;
            gObjects[unk24[index]].unk100 = arg1->unk7;
            gObjects[unk24[index]].unk108 = arg1->unk8;
            gObjects[unk24[index]].unk102 = arg1->unk9;
            gObjects[unk24[index]].unk103 = arg1->unkA;
            if (index > 0)
            {
                gObjects[unk24[index]].unkE6[0] = unk24[0];
                gObjects[unk24[0]].unkE6[index] = unk24[index];
            }
            arg1++;
            index++;
        }
    }

    for (index = 0; (unk24[index] != -1) && (index < 11); index++)
    {
        for (sp18 = 0, sp1C = 0; (unk24[sp1C] != -1) && (sp1C < 11); sp1C++)
        {
            if (unk24[index] != unk24[sp1C])
            {
                gObjects[unk24[index]].unk10E[sp18] = unk24[sp1C];
                sp18++;
            }
        }
    }
    if (D_80165198 == -1)
    {
        D_80165198 = unk24[0];
    }
    return unk24[0];
}

s32 func_80027B34(s32 arg0, struct UnkStruct_80027B34 *arg1)
{
    s32 *sp1C;

    sp1C = (s32 *)arg1->unk8;
    if (gObjects[arg0].Unk140[arg1->unk0] != -1)
    {
        return FALSE;
    }
    func_8001BD44(arg0, arg1->unk0, arg1->unk4, gFileArray[arg1->unk2].ptr + sp1C[arg1->unkC]);
    return TRUE;
}

s32 func_80027C00(s32 arg0, s32 arg1, struct UnkStruct_80027C00 *arg2, f32 arg3, f32 arg4, f32 arg5,
                  f32 arg6)
{
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp24 = func_80064358(arg0);
    if (sp24 == -1)
    {
        return -1;
    }
    func_8001A928(sp24);
    func_8001BD44(sp24, arg2->unk0, arg2->unk6, gFileArray[arg2->unk4].ptr);
    gObjects[sp24].Pos.x = gObjects[sp24].unk50 = arg3;
    gObjects[sp24].Pos.y = gObjects[sp24].unk54 = arg4;
    gObjects[sp24].Pos.z = gObjects[sp24].unk58 = arg5;
    gObjects[sp24].Rot.y = arg6;
    gObjects[sp24].unk3C = arg6;
    gObjects[sp24].unkA4 = 1;
    gObjects[sp24].unkE4 = arg2->unk2;
    gObjects[sp24].unk100 = (s16)arg2->unk7;
    gObjects[sp24].unk108 = (s16)arg2->unk8;
    gObjects[sp24].unk102 = arg2->unk9;
    gObjects[sp24].unk103 = arg2->unkA;
    gObjects[sp24].unkE6[0] = arg0;
    gObjects[arg0].unkE8[arg1] = sp24;
    gObjects[sp24].unk10E[0] = (s16)arg0;

    for (sp20 = 0; sp20 < 10; sp20++)
    {
        if (gObjects[arg0].unk10E[sp20] == -1)
        {
            gObjects[arg0].unk10E[sp20] = (s16)sp24;
            break;
        }
    }

    for (sp20 = 0; sp20 < 10; sp20++)
    {
        if (((sp18 = gObjects[arg0].unkE8[sp20]) != -1))
        {
            if (sp24 != sp18)
            {
                for (sp1C = 0; sp1C < 10; sp1C++)
                {
                    if (gObjects[sp18].unk10E[sp1C] == -1)
                    {
                        gObjects[sp18].unk10E[sp1C] = (s16)sp24;
                        break;
                    }
                }

                for (sp1C = 0; sp1C < 10; sp1C++)
                {
                    if (gObjects[sp24].unk10E[sp1C] == -1)
                    {
                        gObjects[sp24].unk10E[sp1C] = (s16)sp18;
                        break;
                    }
                }
            }
        }
    }
    return sp24;
}

s32 func_800281A4(s32 arg0, s32 arg1)
{
    s32 sp4;

    sp4 = gObjects[arg0].unkE8[arg1];
    if (sp4 == -1)
    {
        return -1;
    }
    gObjects[arg0].unkE8[arg1] = -1;
    gObjects[sp4].unkE6[0] = -1;
    return sp4;
}

s32 func_80028260(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5)
{
    struct ObjectStruct *spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    s32 sp70;
    s32 sp6C;
    UNUSED u8 sp6B;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    UNUSED s32 sp54;
    f32 sp50;
    s32 sp4C;

    spA4 = &gObjects[arg0];
    spA0 = spA4->Pos.x + arg2;
    sp9C = spA4->Pos.y + arg3;
    sp98 = spA4->Pos.z + arg4;
    sp94 = spA4->Vel.x;
    sp90 = spA4->Vel.y;
    sp8C = spA4->Vel.z;
    func_80067748(spA0, sp9C, sp98);
    sp6C = D_801776E0 & 1;
    sp6B = D_801776E0;
    sp64 = D_801776F0[sp6C];
    sp60 = D_80177700[sp6C];
    sp5C = D_80177710[sp6C];
    sp58 = D_80177720[sp6C];
    sp50 = D_80177760[sp6C];
    sp54 = D_80177730[sp6C];
    sp70 = 0;
    sp7C = func_80015634(sp94, sp8C);
    for (sp4C = 0; sp4C < 3; sp4C++)
    {
        if (sp4C == 0)
        {
            sp78 = sp7C + 45.0f;
        }
        else if (sp4C == 1)
        {
            sp78 = sp7C;
        }
        else
        {
            sp78 = sp7C + 315.0f;
        }
        if (sp78 >= 360.0f)
        {
            sp78 -= 360.0f;
        }
        sp88 = sinf(sp78 * 0.017453292519943295) * arg1 + (spA0 + sp94);
        sp84 = sp9C + sp90;
        sp80 = (cosf((f32)((f64)sp78 * 0.017453292519943295)) * arg1) + (sp98 + sp8C);
        func_80067748(sp88, sp84, sp80);
        if (arg5 == 0)
        {
            if (!(D_801776E0 & 1))
            {
                sp74 = sp50 - D_80177760[0];
                sp74 = sp74 < 0.0f ? -sp74 : sp74;

                if (sp74 > (sqrtf(SQ(sp94) + SQ(sp8C)) + arg1))
                {
                    sp70 = sp70 | 1 << (sp4C + 3);
                }
            }
            else if ((D_80177760[1] - sp50) > (sqrtf(SQ(sp94) + SQ(sp8C)) + arg1))
            {
                sp70 = sp70 | 1 << sp4C;
            }
        }
        else if (!(D_801776E0 & 1))
        {
            if (!func_8001608C(sp64, sp60,
                               sp5C, sp58, (s32)D_801776F0[0], (s32)D_80177700[0], (s32)D_80177710[0],
                               D_80177720[0]))
            {

                sp70 = sp70 | 1 << (sp4C + 3);
            }
        }
        else if (func_8001608C(sp64,
                               sp60, sp5C,
                               sp58, (s32)D_801776F0[1],
                               D_80177700[1], D_80177710[1],
                               D_80177720[1]) == 0)
        {
            sp70 = sp70 | 1 << sp4C;
        }
    }
    if (!(sp70 & 7))
    {
        func_80067748(spA0 + sp94, sp9C + sp90, sp98 + sp8C);
        if (!(D_801776E0 & 1) && ((sp50 - D_80177760[0]) > sqrtf(SQ(sp94) + SQ(sp8C))))
        {
            sp70 = sp70 | 0x40;
        }
    }
    return sp70;
}

s32 func_8002894C(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    struct ObjectStruct *spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    UNUSED s32 sp74;
    s32 sp70;
    s32 sp6C;
    UNUSED u8 sp6B;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    UNUSED s32 sp54;
    UNUSED f32 sp50;
    s32 sp4C;
    UNUSED s32 temp_t9;

    spA4 = &gObjects[arg0];
    spA0 = spA4->Pos.x + arg2;
    sp9C = spA4->Pos.y + arg3;
    sp98 = spA4->Pos.z + arg4;
    sp94 = spA4->Vel.x;
    sp90 = spA4->Vel.y;
    sp8C = spA4->Vel.z;
    func_80067748(spA0, sp9C, sp98);
    sp6C = (D_801776E0 & 1) ^ 1;
    sp6B = D_801776E0;
    sp64 = D_801776F0[sp6C];
    sp60 = D_80177700[sp6C];
    sp5C = D_80177710[sp6C];
    sp58 = D_80177720[sp6C];
    sp50 = D_80177760[sp6C];
    sp54 = D_80177730[sp6C];
    sp70 = 0;
    sp7C = func_80015634(sp94, sp8C);
    for (sp4C = 0; sp4C < 3; sp4C++)
    {
        if (sp4C == 0)
        {
            sp78 = sp7C + 45.0f;
        }
        else if (sp4C == 1)
        {
            sp78 = sp7C;
        }
        else
        {
            sp78 = sp7C + 315.0f;
        }
        if (sp78 >= 360.0f)
        {
            sp78 -= 360.0f;
        }
        sp88 = (sinf((f32)((f64)sp78 * 0.017453292519943295)) * arg1) + (spA0 + sp94);
        sp84 = sp9C + sp90;
        sp80 = (cosf((f32)((f64)sp78 * 0.017453292519943295)) * arg1) + (sp98 + sp8C);
        func_80067748(sp88, sp84, sp80);
        if (!(D_801776E0 & 1))
        {
            if (func_8001608C(
                    sp64,
                    sp60,
                    sp5C,
                    sp58,
                    D_801776F0[1],
                    D_80177700[1],
                    D_80177710[1],
                    D_80177720[1]) == 0)
            {
                sp70 = sp70 | 1 << (sp4C + 3);
            }
        }
        else if (func_8001608C(
                     sp64,
                     sp60,
                     sp5C,
                     sp58,
                     D_801776F0[0],
                     D_80177700[0],
                     D_80177710[0],
                     D_80177720[0]) == 0)
        {
            sp70 = sp70 | 1 << sp4C;
        }
    }
    return sp70;
}

s32 func_80028E60(s32 arg0)
{
    struct ObjectStruct *sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    sp24 = &gObjects[arg0];
    sp20 = (sp24->Pos.x + sp24->Vel.x) - sp24->unk50;
    sp1C = (sp24->Pos.y + sp24->Vel.y) - sp24->unk54;
    sp18 = (sp24->Pos.z + sp24->Vel.z) - sp24->unk58;

    if (((D_80124D90[gObjects[arg0].unkE4].unk30)) <= (SQ(sp20) + SQ(sp1C) + SQ(sp18)))
    {
        return TRUE;
    }
    return FALSE;
}

s32 func_80028FA0(s32 arg0)
{
    struct ObjectStruct *sp4;

    sp4 = &gObjects[arg0];
    if ((sp4->unk104 != -1))
    {
        if ((sp4->unk10A == 4))
        {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_80029018(s32 arg0, u32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    struct ObjectStruct *sp2C;
    s32 sp28;
    s32 sp24;

    sp24 = FALSE;
    sp2C = &gObjects[arg0];
    switch (arg1)
    {
    case 0:
        sp28 = func_80028260(arg0, arg2, arg3, arg4, arg5, 0);
        if (sp28 != 0)
        {
            sp24 = TRUE;
        }
        else
        {
            func_80067748(sp2C->Pos.x + sp2C->Vel.x, sp2C->Pos.y + sp2C->Vel.y,
                          sp2C->Pos.z + sp2C->Vel.z);

            if ((D_801776F0[0] != 0) || (D_80177710[0] != 0))
            {
                sp24 = TRUE;
            }
        }
        break;
    case 1:
        sp28 = func_80028260(arg0, arg2, arg3, arg4, arg5, 0);
        if (sp28 != 0)
        {
            sp24 = TRUE;
        }
        break;
    case 2:
        sp28 = func_80028260(arg0, arg2, arg3, arg4, arg5, 0);
        if (sp28 & 7)
        {
            sp24 = TRUE;
        }
        else
        {
            func_80067748(sp2C->Pos.x + sp2C->Vel.x, sp2C->Pos.y + sp2C->Vel.y,
                          sp2C->Pos.z + sp2C->Vel.z);
            if ((D_801776F0[0] != 0) || (D_80177710[0] != 0))
            {
                sp24 = TRUE;
            }
        }
        break;
    case 3:
        sp28 = func_80028260(arg0, arg2, arg3, arg4, arg5, 0);
        if (sp28 & 7)
        {
            sp24 = TRUE;
        }
        break;
    case 4:
        sp28 = func_80028260(arg0, arg2, arg3, arg4, arg5, 1);
        if (sp28 != 0)
        {
            sp24 = TRUE;
        }
        break;
    case 5:
        sp28 = func_8002894C(arg0, arg2, arg3, arg4, arg5);
        if (sp28 != 0)
        {
            sp24 = TRUE;
        }
        break;
    default:
        break;
    }
    D_801651A0 = (s16)sp28;
    if (func_80028E60(arg0) != 0)
    {
        sp24 = TRUE;
        D_801651A0 |= 0x80;
    }
    if (sp24 == 0)
    {
        return FALSE;
    }
    sp2C->Vel.x = 0.0f;
    sp2C->Vel.y = 0.0f;
    sp2C->Vel.z = 0.0f;
    return TRUE;
}

s32 func_800293B8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 *arg6, f32 *arg7,
                  f32 *arg8, s32 arg9)
{
    UNUSED s32 pad;
    s32 sp20;
    s32 sp1C;

    sp1C = 0;

    for (sp20 = 0; sp20 < arg9; sp20++)
    {
        func_80067748(arg0, arg1, arg2);
        if (!(D_801776E0 & 1))
        {
            sp1C = 1;
            break;
        }
        arg0 += arg3;
        arg1 += arg4;
        arg2 += arg5;
    }

    if ((sp20 == 0) && (sp1C == 1))
    {
        sp1C = 2;
    }

    *arg6 = arg0;
    *arg7 = arg1;
    *arg8 = arg2;
    return sp1C;
}

s32 func_800294F0(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    func_80067748(sp1C->Pos.x + arg3, sp1C->Pos.y + arg4, sp1C->Pos.z + arg5);
    *arg1 = D_80177760[0];
    *arg2 = D_80177760[1];
    return D_801776E0 & 1;
}

s32 func_800295C0(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    func_80067748(sp1C->Pos.x + sp1C->Vel.x + arg3, sp1C->Pos.y + sp1C->Vel.y + arg4,
                  sp1C->Pos.z + sp1C->Vel.z + arg5);
    *arg1 = D_80177760[0];
    *arg2 = D_80177760[1];
    return D_801776E0 & 1;
}

s32 func_800296AC(s32 arg0, f32 arg1, s32 arg2, s32 arg3)
{
    struct ObjectStruct *sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[arg0];
    sp20 = sp2C->Pos.y;
    func_800294F0(arg0, &sp28, &sp24, 0.0f, 0.0f, 0.0f);
    if (arg2 == 0)
    {
        sp2C->Pos.y = sp28 + arg1;
    }
    else
    {
        sp2C->Pos.y = sp24 + arg1;
    }
    if (arg3 == 0)
    {
        func_80067748(sp2C->Pos.x, sp28 + arg1, sp2C->Pos.z);
        if ((D_801776E0 & 1) == 1)
        {
            sp2C->Pos.y = sp20;
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_800297DC(void)
{
    s16 sp6;

    sp6 = (D_801651A0 | (D_801651A0 >> 3)) & 7;
    return (s8)D_8004A650[sp6];
}

void func_80029824(s32 arg0, s32 arg1)
{
    struct ObjectStruct *sp2C;
    f32 sp28;

    sp2C = &gObjects[arg0];
    sp28 = sp2C->unk3C;
    if (arg1 == 0)
    {
        sp28 += 180.0f;
    }
    else
    {
        if (arg1 < 0)
        {
            if (sp28 < 90.0f)
            {
                sp28 = 360.0f - sp28;
            }
            else if (sp28 < 180.0f)
            {
                sp28 = 180.0f - sp28;
            }
            else if (sp28 < 270.0f)
            {
                sp28 = 360.0f - sp28;
            }
            else
            {
                sp28 = 540.0f - sp28;
            }
        }
        else if (sp28 < 90.0f)
        {
            sp28 = 180.0f - sp28;
        }
        else if (sp28 < 180.0f)
        {
            sp28 = 360.0f - sp28;
        }
        else if (sp28 < 270.0f)
        {
            sp28 = 540.0f - sp28;
        }
        else
        {
            sp28 = 360.0f - sp28;
        }
    }
    sp2C->unk3C = func_80015538(sp28, (f32)(func_80014E80(-2) * 0xA));
}

void func_80029A9C(s32 arg0, s32 arg1)
{
    struct ObjectStruct *sp2C;
    f32 sp28;

    sp2C = &gObjects[arg0];
    sp28 = sp2C->unk40;
    if (arg1 == 0)
    {
        sp28 = func_80015538(sp28, 180.0f);
    }
    sp2C->unk40 = func_80015538(sp28, (f32)(func_80014E80(-2) * 0xA));
}

void func_80029B60(s32 arg0)
{
    struct ObjectStruct *sp1C;
    sp1C = &gObjects[arg0];
    sp1C->unk3C = func_80015538(sp1C->unk128, 180.0f);
}

void func_80029BD0(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    sp1C->unk40 = func_80015538(sp1C->unk12C, 180.0f);
}

void func_80029C40(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    sp1C->Vel.x = sinf((f32)((f64)sp1C->unk3C * 0.0174532925199432955)) * sp1C->unk44;
    sp1C->Vel.z = cosf((f32)((f64)sp1C->unk3C * 0.0174532925199432955)) * sp1C->unk44;
}

void func_80029D04(s32 arg0)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[arg0];
    sp1C->Vel.y = sinf((f32)((f64)sp1C->unk40 * 0.0174532925199432955)) * sp1C->unk48;
}

void func_80029D8C(s32 arg0)
{
    struct ObjectStruct *sp24;

    sp24 = &gObjects[arg0];
    sp24->Vel.x = (sp24->unk44 * cosf(sp24->unk40 * 0.0174532925199432955)) * sinf(sp24->unk3C * 0.0174532925199432955);
    sp24->Vel.z = (sp24->unk44 * cosf(sp24->unk40 * 0.0174532925199432955)) * cosf(sp24->unk3C * 0.0174532925199432955);
    sp24->Vel.y = sinf(sp24->unk40 * 0.017453292519943295) * sp24->unk44;
}

void func_80029EF8(s32 arg0, f32 arg1, f32 arg2)
{
    struct ObjectStruct *sp4;

    sp4 = &gObjects[arg0];
    sp4->Vel.y = arg1;
    sp4->unk4C = arg2;
}

s32 func_80029F58(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    struct ObjectStruct *sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[arg0];
    sp28 = 0;
    sp2C->Vel.y -= sp2C->unk4C;
    if (sp2C->Vel.y < -48.0f)
    {
        sp2C->Vel.y = -48.0f;
    }
    if (sp2C->Vel.y < 0.0f)
    {
        if (func_800295C0(arg0, &sp24, &sp20, arg1, arg3, arg2) != 0)
        {
            sp28 = 1;
            sp2C->Vel.y = (sp20 - sp2C->Pos.y) - arg3;
        }
    }
    else if (func_800295C0(arg0, &sp24, &sp20, arg1, arg4, arg2) != 0)
    {
        sp28 = 2;
        sp2C->Vel.y = 0.0f;
    }
    return sp28;
}

s32 func_8002A0D0(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
    struct ObjectStruct *sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;

    sp2C = &gObjects[arg0];
    sp28 = 0;
    sp2C->Vel.y -= sp2C->unk4C;
    if (sp2C->Vel.y < -48.0f)
    {
        sp2C->Vel.y = -48.0f;
    }
    if ((sp2C->Vel.y < 0.0f) && (func_800295C0(arg0, &sp24, &sp20, arg1, arg3, arg2) != 0))
    {
        sp28 = 1;
        sp2C->Vel.y = (sp20 - sp2C->Pos.y) - arg3;
    }
    return sp28;
}

s32 func_8002A1FC(s32 arg0, f32 arg1)
{
    struct ObjectStruct *spC;
    f32 sp8;
    f32 sp4;
    f32 sp0;

    spC = &gObjects[arg0];
    sp8 = gPlayerObject->Pos.x - spC->Pos.x;
    sp4 = (gPlayerObject->Pos.y + 60.0f) - spC->Pos.y;
    sp0 = gPlayerObject->Pos.z - spC->Pos.z;
    if ((SQ(sp8) + SQ(sp4) + SQ(sp0)) < SQ(arg1))
    {
        return TRUE;
    }
    return FALSE;
}

s32 func_8002A2EC(s32 arg0, f32 arg1)
{
    struct ObjectStruct *spC;
    f32 sp8;
    f32 sp4;

    spC = &gObjects[arg0];
    sp8 = gPlayerObject->Pos.x - spC->Pos.x;
    sp4 = gPlayerObject->Pos.z - spC->Pos.z;
    if ((SQ(sp8) + SQ(sp4)) < SQ(arg1))
    {
        return TRUE;
    }
    return FALSE;
}

s32 func_8002A3A8(s32 arg0, f32 arg1)
{
    struct ObjectStruct *spC;
    f32 sp8;
    f32 sp4;

    spC = &gObjects[arg0];
    sp8 = gPlayerObject->Pos.x - spC->Pos.x;
    sp4 = (gPlayerObject->Pos.y + 60.0f) - spC->Pos.y;
    if ((SQ(sp8) + SQ(sp4)) < SQ(arg1))
    {
        return 1;
    }
    return 0;
}

f32 func_8002A46C(s32 arg0)
{
    func_80015634(gPlayerObject->Pos.x - gObjects[arg0].Pos.x,
                  gPlayerObject->Pos.z - gObjects[arg0].Pos.z);
    return;
}

f32 func_8002A4E0(s32 arg0)
{
    func_800156C4(gPlayerObject->Pos.x - gObjects[arg0].Pos.x,
                  (gPlayerObject->Pos.y + 60.0f) - gObjects[arg0].Pos.y);
    return;
}

s32 func_8002A560(s32 arg0, f32 arg1)
{
    f32 sp1C;
    f32 sp18;

    sp1C = func_8002A46C(arg0);
    sp18 = func_80015538(sp1C, -gObjects[arg0].unk3C);
    if ((sp18 < arg1) || ((360.0f - arg1) < sp18))
    {
        return 0;
    }
    if (sp18 >= 180.0f)
    {
        return -1;
    }
    return 1;
}

s32 func_8002A640(s32 arg0, f32 arg1)
{
    f32 sp1C;
    f32 sp18;

    sp1C = func_8002A46C(arg0);
    sp18 = func_80015538(sp1C, -gObjects[arg0].Rot.y);
    if ((sp18 < arg1) || ((360.0f - arg1) < sp18))
    {
        return 0;
    }
    if (sp18 >= 180.0f)
    {
        return -1;
    }
    return 1;
}

s32 func_8002A720(s32 arg0, f32 arg1)
{
    f32 sp1C;
    f32 sp18;

    sp1C = func_8002A4E0(arg0);
    sp18 = func_80015538(sp1C, -gObjects[arg0].unk40);
    if ((sp18 < arg1) || ((360.0f - arg1) < sp18))
    {
        return 0;
    }
    if (sp18 >= 180.0f)
    {
        return -1;
    }
    return 1;
}

s32 func_8002A800(f32 arg0, f32 arg1, f32 arg2)
{
    f32 sp1C;

    sp1C = func_80015538(arg1, -arg0);
    if ((sp1C < arg2) || ((360.0f - arg2) < sp1C))
    {
        return 0;
    }
    if (sp1C >= 180.0f)
    {
        return -1;
    }
    return 1;
}

void func_8002A8B4(s32 arg0, f32 arg1)
{
    f32 sp1C;
    s32 sp18;

    sp1C = gObjects[arg0].unk3C;
    sp18 = func_8002A560(arg0, arg1);
    if (sp18 < 0)
    {
        sp1C = func_80015538(sp1C, -arg1);
    }
    else if (sp18 > 0)
    {
        sp1C = func_80015538(sp1C, arg1);
    }
    else
    {
        sp1C = func_8002A46C(arg0);
    }
    sp1C = sp1C;
    gObjects[arg0].unk3C = sp1C;
}

void func_8002A9A4(s32 arg0, f32 arg1)
{
    f32 sp1C;
    s32 sp18;

    sp1C = gObjects[arg0].unk40;
    sp18 = func_8002A720(arg0, arg1);
    if (sp18 < 0)
    {
        sp1C = func_80015538(sp1C, -arg1);
    }
    else if (sp18 > 0)
    {
        sp1C = func_80015538(sp1C, arg1);
    }
    else
    {
        sp1C = func_8002A4E0(arg0);
    }
    sp1C = sp1C;
    gObjects[arg0].unk40 = sp1C;
}

void func_8002AA94(s32 arg0)
{
    s32 sp24;

    if (gObjects[arg0].unk108 == 0)
    {
        sp24 = 0;
    }
    else
    {
        sp24 = !(gObjects[arg0].unk108 & 1);
    }
    func_8001BB34(arg0, sp24);
}

s32 func_8002AB40(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4)
{
    s32 sp2C;
    struct ObjectStruct *sp28;

    sp2C = func_800642E0();
    if (sp2C == -1)
    {
        return -1;
    }
    sp28 = &gObjects[sp2C];
    func_8001A928(sp2C);
    if (arg4 < 0x10)
    {
        func_8001BD44(sp2C, 3, 2, gFileArray[0x43].ptr);
        func_8001BE6C(sp2C, 3, 0, gFileArray[0x43].ptr + D_80116674[0]);
        func_8001ABF4(sp2C, 0, 3, &D_8011670C[arg4].unk0);
    }
    else if (arg4 == 0x10)
    {
        func_8001BD44(sp2C, 3, 1, gFileArray[0x44].ptr);
        func_8001BE6C(sp2C, 3, 0, gFileArray[0x44].ptr + D_801168CC[0]);
    }
    else
    {
        func_8001BD44(sp2C, 3, 1, gFileArray[0x45].ptr);
        func_8001BE6C(sp2C, 3, 0, gFileArray[0x45].ptr + D_801168D0[0]);
    }
    sp28->unkA4 = 1;
    sp28->unkE4 = 0x47;
    sp28->Pos.x = arg0;
    sp28->Pos.y = arg1;
    sp28->Pos.z = arg2;
    sp28->Scale.z = arg3;
    sp28->Scale.x = sp28->Scale.y = sp28->Scale.z;
    return sp2C;
}

void func_8002AD90(void)
{
    struct ObjectStruct *sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    sp1C->Rot.y = func_80015634(gView.eye.x - sp1C->Pos.x, gView.eye.z - sp1C->Pos.z);
    if (func_8001B44C(gCurrentParsedObject, 3) != 0)
    {
        func_8001A928(gCurrentParsedObject);
    }
}

void func_8002AE38(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4)
{
    func_8002AB40(arg0, arg1, arg2, arg3, arg4);
}

void func_8002AE84(s32 ObjectIndex, s32 arg1)
{
    struct ObjectStruct *spC4;
    s32 spC0;
    f32 ox;
    f32 oy;
    f32 oz;
    f32 spB0;
    s32 spAC;
    Mtx_t sp6C;
    Mtx_t sp2C;

    spC4 = &gObjects[ObjectIndex];

    for (spC0 = 0; spC0 < 10; spC0++)
    {
        if (spC4->unkE8[spC0] != -1)
        {
        }
    }

    if (spC4->unkFC != -1)
    {
        func_800260E0(spC4->unkFC);
    }
    func_800272E8(ObjectIndex);
    if (arg1 != 0)
    {
        guRotateF(sp6C, spC4->Rot.y, 0, 1.0f, 0.0f);
        guTranslateF(sp2C, spC4->Pos.x, spC4->Pos.y, spC4->Pos.z);
        guMtxCatF(sp6C, sp2C, sp6C);
        guMtxXFMF(sp6C, D_80124D90[spC4->unkE4].unk8, D_80124D90[spC4->unkE4].unkA,
                  D_80124D90[spC4->unkE4].unkC, &ox, &oy, (f32 *)&oz);

        spB0 = D_80124D90[spC4->unkE4].unkE / 10.0f;
        spAC = D_80124D90[spC4->unkE4].unkF;
    }
    func_8001A928(ObjectIndex);
    if ((arg1 != 0) && (spAC != -1))
    {
        func_8002AB40(ox, oy, oz, spB0, spAC);
    }
}

void func_8002B0E4(s32 ObjectIndex)
{
    func_8002AE84(ObjectIndex, 1);
}

void func_8002B114(s32 arg0)
{
    func_8002AE84(arg0, 0);
}

void func_8002B144(void)
{
}

void func_8002B154(void)
{
    s32 sp1C;

    for (sp1C = 0xE; sp1C < 0x4E; sp1C++)
    {
        if (gObjects[sp1C].unkA4 != 0)
        {
            gCurrentParsedObject = sp1C;
            D_80124D90[gObjects[sp1C].unkE4].routine2();
            if (gObjects[sp1C].unkA4 != 0)
            {
                if (gObjects[sp1C].unk108 >= 2)
                {
                    gObjects[sp1C].unk108 -= 1;
                }
                func_8001CEF4(sp1C);
                func_8001CD20(sp1C);
                func_8001AD6C(sp1C);
            }
        }
    }
}

void func_8002B2D4(void)
{
}

void func_8002B2E4(void)
{
}
