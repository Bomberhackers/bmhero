#include "common.h"
#include "2BF00.h"






void func_8002B300(void)
{
    f32 sp4;

    if (gActiveContButton & 0x2000)
    {
        if (gActiveContButton & 8)
        {
            gView.dist = gView.dist - 10.0f;
            if (gView.dist < 100.0f)
            {
                gView.dist = 100.0f;
            }
        }
        if (gActiveContButton & 4)
        {
            gView.dist = gView.dist + 10.0f;
        }
    }
    else
    {
        if (gActiveContButton & 2)
        {
            sp4 = (f32)((f64)gView.rot.y + 2.0);
            gView.rot.y = sp4 - (f32)(((s32)sp4 / 360) * 0x168);
        }
        if (gActiveContButton & 1)
        {
            sp4 = (f32)((f64)gView.rot.y + 358.0);
            gView.rot.y = sp4 - (f32)(((s32)sp4 / 360) * 0x168);
        }
        if (gActiveContButton & 8)
        {
            sp4 = (f32)((f64)gView.rot.x + 2.0);
            gView.rot.x = sp4 - (f32)(((s32)sp4 / 360) * 0x168);
        }
        if (gActiveContButton & 4)
        {
            sp4 = (f32)((f64)gView.rot.x + 358.0);
            gView.rot.x = sp4 - (f32)(((s32)sp4 / 360) * 0x168);
        }
    }
}

void func_8002B640(f32 arg0, f32 arg1, f32 arg2)
{
    gView.at.x = arg0;
    gView.at.y = arg1;
    gView.at.z = arg2;
}

void func_8002B670(void)
{
    s32 sp4;

    for (sp4 = 0; sp4 < 0x81; sp4++)
    {
        D_800576A8[sp4].unk0 = -1;
    }

    for (sp4 = 0; sp4 < 0x80; sp4++)
    {
        if (D_8017796C[sp4].unk0 == -1)
        {
            break;
        }
        D_800576A8[sp4].unk0 = D_8017796C[sp4].unk0;
        D_800576A8[sp4].unk2 = D_8017796C[sp4].unk2;
        D_800576A8[sp4].unk4 = D_8017796C[sp4].unk4;
        D_800576A8[sp4].unk6 = D_8017796C[sp4].unk6;
        D_800576A8[sp4].unk8 = D_8017796C[sp4].unk8;
        D_800576A8[sp4].unkA = D_8017796C[sp4].unkA;
        D_800576A8[sp4].unkC = D_8017796C[sp4].unkC;
        D_800576A8[sp4].unkE = D_8017796C[sp4].unkE;
    }
    D_8017796C = D_800576A8;
}

s32 func_8002B830(void)
{
    s32 sp4;

    for (sp4 = 0; sp4 < 0x80; sp4++)
    {
        if (D_800576A8[sp4].unk0 == -1)
        {
            return sp4;
        }
    }
    return -1;
}

s32 func_8002B894(s32 arg0)
{
    s32 sp4;

    for (sp4 = 0xE; sp4 < 0x4E; sp4++)
    {
        if ((gObjects[sp4].unkA4) &&
            (gObjects[sp4].unkE4 == D_800576A8[arg0].unk0) &&
            (gObjects[sp4].Pos.x == D_800576A8[arg0].unk2) &&
            (gObjects[sp4].Pos.y == D_800576A8[arg0].unk4) &&
            (gObjects[sp4].Pos.z == D_800576A8[arg0].unk6))
        {

            return sp4;
        }
    }

    return -1;
}

void func_8002B9B8(void)
{
    s32 sp1C;

    for (sp1C = 0xE; sp1C < 0x4E; sp1C++)
    {
        if (gObjects[sp1C].unkA4 != 0)
        {
            func_8001BB34(sp1C, 0);
        }
    }
}

s32 func_8002BA34(void)
{
    s32 sp4;

    for (sp4 = 0; sp4 < 0x80; sp4++)
    {
        if ((D_800576A8[sp4].unk0 != -1) && (D_800576A8[sp4].unk2 != 0x7530) && (D_800576A8[sp4].unk4 != 0x7530) && (D_800576A8[sp4].unk6 != 0x7530))
        {
            return 0;
        }
    }
    return 1;
}

void func_8002BAC8(void)
{
    u16 sp6;

    if (D_800576A2 != 0)
    {
        D_800576A2 -= 1;
    }
    sp6 = 0;
    if (D_800576A2 == 0)
    {
        if (gActiveContPressed & 0x100)
        {
            D_800576A2 = 0xF;
            sp6 = 0x100;
        }
        else if (gActiveContPressed & 0x200)
        {
            D_800576A2 = 0xF;
            sp6 = 0x200;
        }
        else if (gActiveContPressed & 0x800)
        {
            D_800576A2 = 0xF;
            sp6 = 0x800;
        }
        else if (gActiveContPressed & 0x400)
        {
            D_800576A2 = 0xF;
            sp6 = 0x400;
        }
        else if (gActiveContPressed & 0x8000)
        {
            D_800576A2 = 0xF;
            sp6 = 0x8000;
        }
        else if (gActiveContPressed & 0x4000)
        {
            D_800576A2 = 0xF;
            sp6 = 0x4000;
        }
    }
    else if (gActiveContButton & 0x100)
    {
        if (D_800576A2 == 1)
        {
            sp6 = 0x100;
            D_800576A2 = 2;
        }
    }
    else if (gActiveContButton & 0x200)
    {
        if (D_800576A2 == 1)
        {
            sp6 = 0x200;
            D_800576A2 = 2;
        }
    }
    else if (gActiveContButton & 0x800)
    {
        if (D_800576A2 == 1)
        {
            sp6 = 0x800;
            D_800576A2 = 2;
        }
    }
    else if (gActiveContButton & 0x400)
    {
        if (D_800576A2 == 1)
        {
            sp6 = 0x400;
            D_800576A2 = 2;
        }
    }
    else if (gActiveContButton & 0x8000)
    {
        if (D_800576A2 == 1)
        {
            sp6 = 0x8000;
            D_800576A2 = 2;
        }
    }
    else if (gActiveContButton & 0x4000)
    {
        if (D_800576A2 == 1)
        {
            sp6 = 0x4000;
            D_800576A2 = 2;
        }
    }
    else
    {
        D_800576A2 = 0;
    }
    D_800576A0 = sp6;
}

void func_8002BE04(void)
{
    s32 sp3C;
    void *sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    void *sp28;
    s32 sp24;

    for (sp3C = 14; sp3C < 0x4E; sp3C++)
    {
        if (gObjects[sp3C].unkA4 != 0)
        {
            if (gObjects[sp3C].unkE6[0] == -1)
            {
                sp38 = D_80124D90[gObjects[sp3C].unkE4].unk40;
                sp34 = D_80124D90[gObjects[sp3C].unkE4].unk38->unk0;
                sp30 = D_80124D90[gObjects[sp3C].unkE4].unk38->unk4;
                sp2C = gObjects[sp3C].Unk140[sp34];
                func_8001A488(sp2C);
                if ((D_80165290[sp2C].unk20 == 0) && (sp38 != NULL))
                {
                    func_8001C0EC(sp3C, sp34, 0, sp30, sp38);
                }
            }
            if ((gObjects[sp3C].unkE6[0] == -1))
            {
                if ((gObjects[sp3C].Unk140[4] == -1))
                {

                    sp28 = D_80124D90[gObjects[sp3C].unkE4].unk44;

                    sp24 = D_80124D90[gObjects[sp3C].unkE4].unk38->unk0;

                    if (sp28 != NULL)
                    {
                        func_8001ABF4(sp3C, 0, sp24, sp28);
                    }
                }
            }
            func_8001CD20(sp3C);
            func_8001AD6C(sp3C);
        }
    }
}

void func_8002C144(f32 arg0, f32 arg1, f32 arg2)
{
    func_80067748(arg0, arg1, arg2);
}

s32 func_8002C184(f32 x, f32 y, f32 z)
{
    s32 spAC;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    UNUSED s32 sp98;
    f32 sp94;
    u8 sp93;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    s32 sp6C;
    s32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;

    func_8002C144(x, y, z);
    spAC = D_801776E0 & 1;
    sp93 = D_801776E0;
    spA8 = D_801776F0[spAC];
    spA4 = D_80177700[spAC];
    spA0 = D_80177710[spAC];
    sp9C = D_80177720[spAC];
    sp98 = D_80177730[spAC];
    sp94 = D_80177760[spAC];
    func_80016A80(D_80057664, D_80057668, D_8005766C, D_80057670, &sp8C, &sp88, &sp84, &sp80);
    func_80016A80(spA8, spA4, spA0, sp9C, &sp7C, &sp78, &sp74, &sp70);
    if ((func_8001608C(
             D_80057664,
             D_80057668,
             D_8005766C,
             D_80057670,
             D_801776F0[spAC],
             D_80177700[spAC],
             D_80177710[spAC],
             D_80177720[spAC]) != 0) &&
        (sp80 < 60.0f))
    {
        return 0;
    }

    if (sp93 == 0)
    {
        if ((sp80 < 60.0f) && (sp70 < 60.0f))
        {
            if ((D_80057678 - sp94) < 30.0f)
            {
                return 1;
            }

            if (((sp80 != 0.0f) || (sp70 != 0.0f)) && ((func_80016714(D_80057664, D_80057668, D_8005766C, D_80057670, spA8, spA4, spA0, sp9C, &sp64, &sp60, &sp5C, &sp58), (sp64 != 0.0f)) || (sp60 != 0.0f) || (sp5C != 0.0f) || (sp58 != 0.0f)))
            {
                sp6C = func_800162F0(D_8005767C, D_80057684, sp64, sp60, sp5C, sp58);
                sp68 = func_800162F0(x, z, sp64, sp60, sp5C, sp58);
                if (sp6C != sp68)
                {
                    return 1;
                }
            }
        }
        return 3;
    }
    else
    {
        if ((sp80 < 60.0f) && (sp70 < 60.0f))
        {
            if ((sp94 - D_80057678) < 30.0f)
            {
                return 2;
            }

            if (((sp80 != 0.0f) || (sp70 != 0.0f)) && ((func_80016714(D_80057664, D_80057668, D_8005766C, D_80057670, spA8, spA4, spA0, sp9C, &sp64, &sp60, &sp5C, &sp58), (sp64 != 0.0f)) || (sp60 != 0.0f) || (sp5C != 0.0f) || (sp58 != 0.0f)))
            {
                sp6C = func_800162F0(D_8005767C, D_80057684, sp64, sp60, sp5C, sp58);
                sp68 = func_800162F0(x, z, sp64, sp60, sp5C, sp58);

                if (sp6C != sp68)
                {
                    return 2;
                }
            }
        }
        return 4;
    }
}

void func_8002C92C(void)
{
    s32 sp1C;

    func_8002C144(gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
    sp1C = D_801776E0 & 1;
    D_80057660 = D_801776E0;
    D_80057664 = D_801776F0[sp1C];
    D_80057668 = D_80177700[sp1C];
    D_8005766C = D_80177710[sp1C];
    D_80057670 = D_80177720[sp1C];
    D_80057674 = D_80177730[sp1C];
    D_80057678 = D_80177760[sp1C];
    D_8005767C = gPlayerObject->Pos.x;
    D_80057680 = gPlayerObject->Pos.y;
    D_80057684 = gPlayerObject->Pos.z;
}

void func_8002CA80(void)
{
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    s32 sp34;
    s32 sp30;
    u8 sp2F;
    u8 sp2E;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    f32 sp1C;
    f32 sp18;

    sp4C = gPlayerObject->Pos.x;
    sp48 = gPlayerObject->Pos.y;
    sp44 = gPlayerObject->Pos.z;
    sp40 = gPlayerObject->Vel.x;
    sp3C = gPlayerObject->Vel.y;
    sp38 = gPlayerObject->Vel.z;
    sp48 += sp3C;
    func_8002C144(sp4C, sp48 + 59.0f, sp44);
    if (D_801776E0 & 1)
    {
        sp48 = D_80177760[0] - 60.0f;
    }
    func_8002C144(sp4C, sp48, sp44);
    if (D_801776E0 & 1)
    {
        sp48 = D_80177760[1];
    }
    if (D_80177760[D_801776E0 & 1] == sp48)
    {
        sp34 = 1;
    }
    else
    {
        sp34 = 0;
    }
    sp4C += sp40;
    sp44 += sp38;
    sp20 = 8;
    sp2E = 0;

    for (sp30 = 0; sp30 < 0x1E; sp30++)
    {
        sp2F = 0;

        for (sp28 = 0; sp28 < 8; sp28++)
        {
            sp24 = func_8002C184(D_8004A660[sp28].x + sp4C, D_8004A660[sp28].y + sp48, D_8004A660[sp28].z + sp44);
            if (sp24 == 4)
            {
                sp2F = sp2F | D_8004A6C0[sp28];
            }
        }

        sp2F = (sp2F & 0xF) | ((s32)sp2F >> 4);

        if ((sp2F == 0) && ((sp30 == 0) || (sp20 == 1)))
        {
            break;
        }

        if (sp2F == 0)
        {
            sp4C = sp1C;
            sp44 = sp18;
            sp20 = sp20 / 2;
            sp2F = sp2E;
        }
        else if ((sp2E != sp2F) && (sp30 != 0) && ((sp20 / 2) != 0))
        {
            sp2F = sp2E;
            sp20 = sp20 / 2;
            sp4C = sp1C;
            sp44 = sp18;
        }
        sp1C = sp4C;
        sp18 = sp44;
        sp2E = sp2F;
        sp4C = sp4C + D_8004A6C8[sp2F].unk0 * sp20;
        sp44 = sp44 + D_8004A6CC[sp2F].unk0 * sp20;
    }

    sp24 = func_8002C184(sp4C, sp48, sp44);
    if ((sp24 < 3) && (sp34 != 0))
    {
        func_8002C144(sp4C, sp48, sp44);
        if (!(D_801776E0 & 1))
        {
            sp48 = D_80177760[0];
        }
    }
    gPlayerObject->Pos.x = sp4C;
    gPlayerObject->Pos.y = sp48;
    gPlayerObject->Pos.z = sp44;
}

s32 func_8002CF78(void)
{
    s32 sp1C;

    sp1C = 0;
    func_8002C144(gPlayerObject->Pos.x, gPlayerObject->Pos.y + 60.0f, gPlayerObject->Pos.z);
    if (D_801776E0 & 1)
    {
        sp1C |= 1;
    }
    func_8002C144(gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
    if (!(D_801776E0 & 1))
    {
        if (*D_80177760 == gPlayerObject->Pos.y)
        {
            sp1C |= 2;
        }
    }
    else
    {
        sp1C |= 2;
    }
    return sp1C;
}

void func_8002D080(void)
{
    gPlayerObject->Vel.x = sinf((f32)((f64)gPlayerObject->unk3C * 0.0174532925199432955)) * gPlayerObject->unk44;
    gPlayerObject->Vel.z = cosf((f32)((f64)gPlayerObject->unk3C * 0.0174532925199432955)) * gPlayerObject->unk44;
}

void func_8002D128(void)
{
    f32 sp1C;

    func_8002C92C();
    gPlayerObject->unk3C = func_80015634(gActiveContStickX, -gActiveContStickY);
    sp1C = sqrtf((gActiveContStickX * gActiveContStickX) + (gActiveContStickY * gActiveContStickY));
    if (sp1C > 10.0f)
    {
        sp1C /= 2.0f;
        gPlayerObject->unk44 = sp1C;
        if (gPlayerObject->unk44 >= 20.0f)
        {
            gPlayerObject->unk44 = 20.0f;
        }
    }
    else
    {
        gPlayerObject->unk44 = 0.0f;
    }
    if (D_8005768A == 0)
    {
        if (D_80057689 == 0)
        {
            if (func_8002CF78() & 2)
            {
                if (gActiveContPressed & 0x8000)
                {
                    D_80057689 = 1;
                    gPlayerObject->Vel.y = 33.29999924;
                }
                else
                {
                    D_80057689 = 0;
                    gPlayerObject->Vel.y = 0.0f;
                }
            }
            else
            {
                D_80057689 = 1;
                gPlayerObject->Vel.y = 0.0f;
            }
        }
        else
        {
            if (func_8002CF78() & 1)
            {
                gPlayerObject->Vel.y = -gPlayerObject->Vel.y;
            }
            if (func_8002CF78() & 2)
            {
                D_80057689 = 0;
                gPlayerObject->Vel.y = 0.0f;
            }
        }
    }
    else
    {
        D_80057689 = 0;
        gPlayerObject->Vel.y = 0.0f;
        if (!(gActiveContButton & 0x2000))
        {
            if (D_800576A0 & 0x8000)
            {
                gPlayerObject->Vel.y = 10.0f;
            }
            else if (D_800576A0 & 0x4000)
            {
                gPlayerObject->Vel.y = -10.0f;
            }
        }
    }
    if (D_80057689 == 1)
    {
        gPlayerObject->Vel.y = (f32)((f64)gPlayerObject->Vel.y - 2.083333);
        if (gPlayerObject->Vel.y <= -48.0f)
        {
            gPlayerObject->Vel.y = -48.0f;
        }
    }
    gPlayerObject->Rot.y = (f32)D_80057694;
    func_8002D080();
    if (D_8005768A == 2)
    {
        gPlayerObject->Pos.x += gPlayerObject->Vel.x;
        gPlayerObject->Pos.y += gPlayerObject->Vel.y;
        gPlayerObject->Pos.z += gPlayerObject->Vel.z;
    }
    else
    {
        func_8002CA80();
    }
    func_8001CD20(0);
    func_8001AD6C(0);
}

void func_8002D538(void)
{
    struct UnkStruct_80027C00 *sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    UNUSED s32 pad;
    struct UnkStruct_80026548_SP24 *sp30;
    u32 sp2C;
    s32 sp28;
    u32 *sp24;
    void *sp20;

    func_8001EC04();

    for (sp28 = 0; sp28 < 0xF4240; sp28++)
        ;

    func_8001E954((s32 *)0x80280000);
    sp30 = D_80124D90[D_80057690].unk24;

    for (sp2C = 1; (s32)sp2C < 2; sp2C++)
    {
        DecompressFile(sp2C, sp30->unk4, sp30->unk8);

        if (sp30->unk2 == 0)
        {
            break;
        }

        sp30++;
    }
    sp44 = D_80124D90[D_80057690].unk38;
    sp24 = D_80124D90[D_80057690].unk40;
    sp20 = D_80124D90[D_80057690].unk44;
    sp40 = 0;
    func_8001A958(sp40);
    sp3C = (s32)sp44->unk0;
    sp38 = (s32)sp44->unk6;
    func_8001BD44(sp40, sp3C, sp38, (s32)gFileArray[1].ptr);
    gPlayerObject->unkE4 = sp44->unk2;
    gPlayerObject->unkA4 = 1;
    if (sp24 != NULL)
    {
        func_8001C0EC(sp40, sp3C, 0, 1, sp24);
    }
    if (sp20 != NULL)
    {
        func_8001ABF4(sp40, 0, sp3C, sp20);
    }
    func_8001EBE8();
}

void func_8002D768(void)
{
    s32 sp1C;

    sp1C = 0;
    if (gActiveContButton & 0x2000)
    {
        if (gActiveContPressed & 0x8000)
        {
            sp1C = 1;
        }
        else if (gActiveContButton & 0x4000)
        {
            sp1C = -1;
        }
        if (gActiveContButton & 0x10)
        {
            sp1C *= 0xA;
        }
    }
    if (sp1C != 0)
    {
        while (TRUE)
        {
            D_80057690 += sp1C;

            if (D_80057690 < 0x20)
            {
                D_80057690 = 0x287;
            }
            else if (D_80057690 >= 0x288)
            {
                D_80057690 = 0x20;
            }

            if (D_80124D90[D_80057690].unk38 != 0)
            {
                break;
            }
        }

        D_80057694 = 0;
        D_80057696 = 0;
        D_80057698 = 0;
        D_8005769A = 0;
        D_8005769C = 4;
        func_8002D538();
    }
}

void func_8002D8FC(void)
{
    if ((D_80057688 == 0) && (func_8001C1A8(0, 0) != 0))
    {
        func_8001838C();
        func_8001B234(0, 0, 1);
        func_8001C384(0, 0);
    }
}

void func_8002D968(void)
{
    if ((D_80057688 == 0) && (func_8001C1A8(0, 3) != 0))
    {
        func_8001838C();
        func_8001B234(0, 3, 1);
        func_8001C384(0, 3);
    }
}

void func_8002D9D4(void)
{
    struct UnkStruct_80026548_SP24 *sp24;
    s32 sp20;
    s32 line;
    s32 sp18;

    if (gActiveContPressed & 0x1000)
    {
        line = func_8002B830();
        if (line != -1)
        {
            D_800576A8[line].unk0 = D_80057690;
            D_800576A8[line].unk2 = (s16)(s32)gPlayerObject->Pos.x;
            D_800576A8[line].unk4 = (s16)(s32)gPlayerObject->Pos.y;
            D_800576A8[line].unk6 = (s16)(s32)gPlayerObject->Pos.z;
            D_800576A8[line].unk8 = D_80057694;
            D_800576A8[line].unkA = D_80057696;
            D_800576A8[line].unkC = D_80057698;
            D_800576A8[line].unkE = D_8005769A;
            D_80165118[line] = 1;

            printf("<Set> line=%d MemoryAD=%x\n", line, D_8005768C);
            func_8001EC04();
            for (sp18 = 0; sp18 < 0xF4240; sp18++)
                ;

            func_8001E954((s32 *)D_8005768C);
            sp24 = D_80124D90[D_80057690].unk24;

            for (sp20 = 1; sp20 < 10; sp20++)
            {
                if (gFileArray[sp24->unk0].ptr == NULL)
                {
                    DecompressFile((u32)sp24->unk0, sp24->unk4, sp24->unk8);
                }

                if (sp24->unk2 == 0)
                {

                    break;
                }

                sp24++;
            }

            D_8005768C = func_8001E96C();
            func_8001EBE8();
            func_8002E8B4();
        }
    }
}

void func_8002DCA8(void)
{
    if (D_800576A0 & 0x800)
    {
        if ((--D_8005769C) < 0)
        {
            D_8005769C = 9;
        }
    }
    else if (D_800576A0 & 0x400)
    {
        if ((++D_8005769C) >= 0xA)
        {
            D_8005769C = 0;
        }
    }
    switch (D_8005769C)
    {
    case 1:
        if (D_800576A0 & 0x100)
        {
            gPlayerObject->Pos.x += 1.0f;
        }
        else if (D_800576A0 & 0x200)
        {
            gPlayerObject->Pos.x -= 1.0f;
        }
        break;
    case 2:
        if (D_800576A0 & 0x100)
        {
            gPlayerObject->Pos.y += 1.0f;
        }
        else if (D_800576A0 & 0x200)
        {
            gPlayerObject->Pos.y -= 1.0f;
        }
        break;
    case 3:
        if (D_800576A0 & 0x100)
        {
            gPlayerObject->Pos.z += 1.0f;
        }
        else if (D_800576A0 & 0x200)
        {
            gPlayerObject->Pos.z -= 1.0f;
        }
        break;
    case 4:
        if ((gActiveContPressed & 0x100) || (gActiveContPressed & 0x200))
        {
            gPlayerObject->Pos.x = (f32)(((s32)gPlayerObject->Pos.x / 30) * 0x1E);
            gPlayerObject->Pos.z = (f32)(((s32)gPlayerObject->Pos.z / 30) * 0x1E);
        }
        break;
    case 5:
        if (D_800576A0 & 0x100)
        {
            D_80057694 += 1;
        }
        else if (D_800576A0 & 0x200)
        {
            D_80057694 -= 1;
        }
        break;
    case 6:
        if (D_800576A0 & 0x100)
        {
            D_80057696 += 1;
        }
        else if (D_800576A0 & 0x200)
        {
            D_80057696 -= 1;
        }
        break;
    case 7:
        if (D_800576A0 & 0x100)
        {
            D_80057698 += 1;
        }
        else if (D_800576A0 & 0x200)
        {
            D_80057698 -= 1;
        }
        break;
    case 8:
        if (D_800576A0 & 0x100)
        {
            D_8005769A += 1;
        }
        else if (D_800576A0 & 0x200)
        {
            D_8005769A -= 1;
        }
        break;
    case 9:
        func_8002C144(gPlayerObject->Pos.x, gPlayerObject->Pos.y + 60.0f, gPlayerObject->Pos.z);
        if (!(D_801776E0 & 1))
        {
            if (D_800576A0 & 0x200)
            {
                if ((--D_8005768A) < 0)
                {
                    D_8005768A = 2;
                }
            }
            else if (D_800576A0 & 0x100)
            {
                if ((++D_8005768A) >= 3)
                {
                    D_8005768A = 0;
                }
            }
        }
        break;
    }
}

void func_8002E23C(void)
{
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    if (func_8002BA34() != 0)
    {
        return;
    }
    sp24 = (s32)D_80057692;
    if ((D_800576A8[D_80057692].unk0 == -1) || ((D_800576A8[D_80057692].unk2 == 0x7530) && (D_800576A8[D_80057692].unk4 == 0x7530) && (D_800576A8[D_80057692].unk6 == 0x7530)))
    {
        return;
    }
    if (gActiveContPressed & 0x1000)
    {
        sp20 = func_8002B894(sp24);
        if (sp20 != -1)
        {
            for (sp1C = 0; sp1C < 10; sp1C++)
            {
                if (gObjects[sp20].unkE8[sp1C] != -1)
                {
                    func_8001A928(gObjects[sp20].unkE8[sp1C]);
                }
            }
            func_8001A928(sp20);
        }
        gPlayerObject->Pos.x = D_800576A8[sp24].unk2;
        gPlayerObject->Pos.y = D_800576A8[sp24].unk4;
        gPlayerObject->Pos.z = D_800576A8[sp24].unk6;
        D_80057690 = D_800576A8[sp24].unk0;
        func_8002D538();
        printf("<Reset> line=%d\n", D_80057692);
        D_800576A8[sp24].unk0 = -1;
        D_800576A8[sp24].unk2 = 0;
        D_800576A8[sp24].unk4 = 0;
        D_800576A8[sp24].unk6 = 0;
        D_800576A8[sp24].unk8 = 0;
        D_800576A8[sp24].unkA = 0;
        D_800576A8[sp24].unkC = 0;
        D_800576A8[sp24].unkE = 0;
        D_80165118[sp24] = 0;
        func_8002E8B4();
    }
}

void func_8002E524(void)
{
    s32 sp24;
    UNUSED s32 pad;
    s32 sp1C;

    if (func_8002BA34() != 0)
    {
        return;
    }
    sp24 = 0;
    if (gActiveContButton & 0x2000)
    {
        if (gActiveContPressed & 0x8000)
        {
            sp24 = 1;
        }
        else if (gActiveContPressed & 0x4000)
        {
            sp24 = -1;
        }
    }

    if (sp24 != 0)
    {
        while (TRUE)
        {

            D_80057692 += sp24;

            if (D_80057692 < 0)
            {
                D_80057692 = 0x7F;
            }
            else if (D_80057692 >= 0x80)
            {
                D_80057692 = 0;
            }

            if ((D_800576A8[D_80057692].unk0 != -1 &&
                 D_800576A8[D_80057692].unk2 != 0x7530 &&
                 D_800576A8[D_80057692].unk4 != 0x7530 &&
                 D_800576A8[D_80057692].unk6 != 0x7530))
            {
                break;
            }
        }
    }

    func_8002B9B8();

    sp1C = func_8002B894((s32)D_80057692);

    if (sp1C != -1)
    {
        func_8001BB34(sp1C, (u8)D_8005769E & 1);
        D_8005769E = (u8)D_8005769E + 1;
    }
}

void func_8002E6E8(void)
{
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    if (gActiveContPressed & 0x1000)
    {
        printf("<SAVE>\n");

        for (sp34 = 0; sp34 < 0x80; sp34++)
        {

            sp2C = (s32)D_800576A8[sp34].unk0;

            if ((sp2C != -1) && (D_800576A8[sp34].unk2 != 0x7530))
            {

                printf("  ");

                for (sp30 = 0; sp30 < 0x14; sp30++)
                {
                    if (D_80124D90->unk48[(sp2C * 0x60) + sp30] == 0x20)
                    {
                        break;
                    }
                    printf("%c", D_80124D90->unk48[(sp2C * 0x60) + sp30]);
                }

                printf(",");

                for (; sp30 < 0x14; sp30++)
                {
                    printf(" ");
                }

                printf("%6d,%6d,%6d,0x%04x,0x%04x,0x%04x,0x%04x,\n",
                       D_800576A8[sp34].unk2,
                       D_800576A8[sp34].unk4,
                       D_800576A8[sp34].unk6, (s32)D_800576A8[sp34].unk8, (s32)D_800576A8[sp34].unkA, (s32)D_800576A8[sp34].unkC, (s32)D_800576A8[sp34].unkE);
            }
        }
    }
}

void func_8002E8B4(void)
{
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    printf("<SAVE>\n");
    for (sp34 = 0; sp34 < 0x80; sp34++)
    {
        sp2C = (s32)D_800576A8[sp34].unk0;
        if ((sp2C != -1) && (D_800576A8[sp34].unk2 != 0x7530))
        {
            printf("  ");
            for (sp30 = 0; sp30 < 0x14; sp30++)
            {
                if (D_80124D90->unk48[(sp2C * 0x60) + sp30] == 0x20)
                {
                    break;
                }
                printf("%c", D_80124D90->unk48[(sp2C * 0x60) + sp30]);
            }
            printf(",");
            for (; sp30 < 0x14; sp30++)
            {
                printf(" ");
            }
            printf("%6d,%6d,%6d,0x%04x,0x%04x,0x%04x,0x%04x,\n", D_800576A8[sp34].unk2, D_800576A8[sp34].unk4, D_800576A8[sp34].unk6, (s32)D_800576A8[sp34].unk8, (s32)D_800576A8[sp34].unkA, (s32)D_800576A8[sp34].unkC, (s32)D_800576A8[sp34].unkE);
        }
    }
}

void func_8002EA68(void)
{
    if (gActiveContPressed & 0x20)
    {
        D_80057688 += 1;
        if (D_80057688 >= 3)
        {
            D_80057688 = 0;
        }
        if (D_80057688 == 0)
        {
            D_8005769C = 4;
            D_80057694 = 0;
            D_80057696 = 0;
            D_80057698 = 0;
            D_8005769A = 0;
            func_8002B9B8();
        }
        else if (D_80057688 == 1)
        {
            D_80057692 = 0;
        }
        else if (D_80057688 == 2)
        {
        }
    }
}

void func_8002EB58(void)
{
    char sp27;
    s32 sp20;
    f32 sp1C;

    func_8002C144(gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
    sp1C = D_80177760[D_801776E0 & 1];
    sprintf((char *)gDebugTextBuf, "SET MODE");
    debug_print_xy(0x20, 0x10);
    sprintf((char *)gDebugTextBuf, "CHR=%d", D_80057690);
    debug_print_xy(0x20, 0x20);

    for (sp20 = 0; sp20 < 0x14; sp20++)
    {
        sp27 = D_80124D90[D_80057690].unk48[sp20];
        sprintf((char *)gDebugTextBuf, "%c", sp27);
        debug_print_xy((sp20 * 8) + 0x60, 0x20);
    }
    sprintf((char *)gDebugTextBuf, "X=%d", (s32)gPlayerObject->Pos.x);
    debug_print_xy(0x20, 0x30);
    sprintf((char *)gDebugTextBuf, "Y=%d(%d)", (s32)gPlayerObject->Pos.y, (s32)(gPlayerObject->Pos.y - sp1C));
    debug_print_xy(0x20, 0x40);
    sprintf((char *)gDebugTextBuf, "Z=%d", (s32)gPlayerObject->Pos.z);
    debug_print_xy(0x20, 0x50);
    sprintf((char *)gDebugTextBuf, "ADJUST");
    debug_print_xy(0x20, 0x60);
    sprintf((char *)gDebugTextBuf, "ANGLE=%u(0x%X)", D_80057694, D_80057694);
    debug_print_xy(0x20, 0x70);
    sprintf((char *)gDebugTextBuf, "PRM1=%u(0x%X)", D_80057696, D_80057696);
    debug_print_xy(0x20, 0x80);
    sprintf((char *)gDebugTextBuf, "PRM2=%u(0x%X)", D_80057698, D_80057698);
    debug_print_xy(0x20, 0x90);
    sprintf((char *)gDebugTextBuf, "PRM3=%u(0x%X)", D_8005769A, D_8005769A);
    debug_print_xy(0x20, 0xA0);
    sprintf((char *)gDebugTextBuf, "MOVE=%d", D_8005768A);
    debug_print_xy(0x20, 0xB0);
    sprintf((char *)gDebugTextBuf, "=");
    debug_print_xy(0x18, (D_8005769C * 0x10) + 0x20);
}

void func_8002EEB8(void)
{
    sprintf((char *)&gDebugTextBuf, "RESET MODE : LINE=%d", D_80057692);
    debug_print_xy(32, 16);
}

void func_8002EF00(void)
{
    sprintf((char *)&gDebugTextBuf, "SAVE MODE");
    debug_print_xy(0x20, 0x10);
    sprintf((char *)&gDebugTextBuf, "PRESS START BUTTON");
    debug_print_xy(0x58, 0x64);
}

void func_8002EF60(void)
{
    func_8005F96C(0xFFU, 0xFFU, 0xFFU);
    switch (D_80057688)
    { /* irregular */
    case 0:
        func_8002EB58();
        break;
    case 1:
        func_8002EEB8();
        break;
    case 2:
        func_8002EF00();
        break;
    }
    func_8005FA90();
}

void func_8002F000(void)
{
    struct UnkStruct80108238 *sp1C;
    s32 i;

    D_80057688 = 0;
    D_80057689 = 0;
    D_8005768A = 1;
    D_80057690 = 0x20;
    D_8005769E = 0;
    D_80057692 = 0;
    D_80057694 = 0;
    D_80057696 = 0;
    D_80057698 = 0;
    D_8005769A = 0;
    D_8005769C = 0;
    D_800576A2 = 0;

    for (i = 0; i < 0x2BC; i++)
    {
        gFileArray[i].ptr = NULL;
    }
    func_8001E954((s32 *)0x8024C000);
    func_8001E98C(0, (void *)&unk_bin_0_2_ROM_START, (void *)&unk_bin_0_2_ROM_END);
    gPlayerObject = gObjects;
    func_80019C84();
    func_80019D2C();
    func_8001A258();
    func_80088B80();
    func_8001E954((s32 *)0x802D0000);
    sp1C = D_80108238[gCurrentLevel];
    DecompressFile(0x1C, sp1C->unk4, sp1C->unk8);
    func_8001EB68(0x1B, (void *)sp1C->unkC, (void *)sp1C->unk10);
    func_80000FF4(gCurrentLevel);
    func_8006707C();
    func_800695A0();
    func_8006E088();
    func_8002629C();
    gLevelInfo[gCurrentLevel]->unk24();
    gLevelInfo[gCurrentLevel]->unk28();
    func_8002B670();
    D_8005768C = func_8001E96C();
    func_8002D538();
    gPlayerObject->Pos.x = D_80108238[gCurrentLevel]->unk0[0];
    gPlayerObject->Pos.y = D_80108238[gCurrentLevel]->unk0[1];
    gPlayerObject->Pos.z = D_80108238[gCurrentLevel]->unk0[2];
    gPlayerObject->Rot.x = 0.0f;
    gPlayerObject->Rot.y = 0.0f;
    gPlayerObject->Rot.z = 0.0f;
    gCameraType = 1;
    func_80076458();
    func_8001D244(-1, -1, -1, 0x10);
    func_8001D284();
}

void func_8002F32C(void)
{
    f32 sp6C;
    Matrix sp2C;

    UpdateActiveController(0U);
    if ((gCameraType == 1) || (gCameraType == 5))
    {
        guRotateF(sp2C, gView.rot.y, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(sp2C, gActiveContStickX, 0.0f, gActiveContStickY, &gActiveContStickX, &sp6C, &gActiveContStickY);
    }
    func_8002BAC8();
    func_8002EA68();
    if (D_80057688 == 0)
    {
        func_8002D768();
        func_8002D128();
        func_8002DCA8();
        func_8002D9D4();
    }
    else if (D_80057688 == 1)
    {
        func_8002E524();
        func_8002E23C();
    }
    else if (D_80057688 == 2)
    {
        func_8002E6E8();
    }
    func_80026548();
    func_8002BE04();
    func_800663EC();
    func_800654AC();
    func_8002B300();
    if (D_80057688 == 0)
    {
        func_8002B640(gPlayerObject->Pos.x, gPlayerObject->Pos.y + 100.0f, gPlayerObject->Pos.z);
    }
    else if ((D_80057688 == 1) && (D_800576A8[D_80057692].unk0 != -1))
    {
        if ((D_800576A8[D_80057692].unk2 != 0x7530) && (D_800576A8[D_80057692].unk4 != 0x7530) && (D_800576A8[D_80057692].unk6 != 0x7530))
        {
            func_8002B640((f32)D_800576A8[D_80057692].unk2, (f32)D_800576A8[D_80057692].unk4, (f32)D_800576A8[D_80057692].unk6);
        }
    }
    func_8001994C();
}

void func_8002F598(void)
{
    UNUSED u16 pad;
    UNUSED u16 pad1;
    UNUSED u16 sp3E;

    func_8001D4D0();
    func_8001D638(1, 0x3C, 0x3C, 0x3C);
    guPerspective(D_8016E104->unk00, &pad, 50.0f, 1.3333334f, 100.0f, 20000.0f, 1.0f);
    gSPPerspNormalize(gMasterDisplayList++, pad);
    guLookAt(&D_8016E104->unk00[2], gView.eye.x, gView.eye.y, gView.eye.z, gView.at.x, gView.at.y, gView.at.z, gView.up.x, gView.up.y, gView.up.z);
    gSPMatrix(gMasterDisplayList++, D_8016E104, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    D_8016E3A4 = 0;
    func_8002D8FC();
    func_8001C464();
    func_8001C70C();
    func_8002D968();
    func_8001C5B8();
    func_8001C96C();
    func_8002EF60();
}

void func_8002F738(void)
{
    func_8001ECB8();
    D_8016526C = &func_8002F598;
    D_80165274 = &func_8002F32C;
    func_8002F000();
    func_80000964();
}
