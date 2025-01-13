#include "prevent_bss_reordering.h"
#include "common.h"
#include "21E10.h"

s32 func_80021210(s32 arg0)
{
    if ((gObjects[arg0].unkA4 != 0) && ((gObjects[arg0].unk108 == 1) || (gObjects[arg0].unk108 == -1)) && (gObjects[arg0].unk104 == -1))
    {
        return TRUE;
    }
    return FALSE;
}

s32 func_800212DC(s32 arg0, s32 arg1)
{
    s32 sp4;

    if ((gObjects[arg1].unkA4 != 0) && ((gObjects[arg1].unk108 > 0) || (gObjects[arg1].unk108 == -1)) && (gObjects[arg1].unk104) == -1)
    {
        for (sp4 = 0; sp4 < 10; sp4++)
        {
            if (gObjects[arg0].unk10E[sp4] == arg1)
            {
                break;
            }
        }
        if (sp4 == 10)
        {
            return TRUE;
        }
    }

    return FALSE;
}

s32 func_80021418(s32 arg0)
{
    if ((gObjects[arg0].unkA4 != 0) && (gObjects[arg0].unk108 != 0) && (gObjects[arg0].unk104 == -1))
    {
        return TRUE;
    }
    return FALSE;
}

s32 func_800214B8(s32 arg0)
{
    if ((gObjects[arg0].unkA4 != 0) && ((gObjects[arg0].unk108 > 0) || (gObjects[arg0].unk108 == -1)) && (gObjects[arg0].unk104 == -1))
    {
        return TRUE;
    }
    return FALSE;
}

s32 func_80021584(s32 arg0, s32 arg1)
{
    s16 sp3E;
    s16 sp3C;
    s16 sp3A;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp3E = func_80077CB0(arg0, arg1, &sp3C, &sp3A);
    if (sp3E != 0)
    {
        gObjects[arg0].unk104 = (s16)arg1;
        gObjects[arg0].unk10B = sp3C;
        gObjects[arg0].unk10C = sp3A;
        gObjects[arg0].unk106 = gObjects[arg1].unkE4;
        gObjects[arg1].unk104 = (s16)arg0;
        gObjects[arg1].unk10B = sp3A;
        gObjects[arg1].unk10C = sp3C;
        gObjects[arg1].unk106 = gObjects[arg0].unkE4;
        for (sp24 = 0; sp24 < 2; sp24++)
        {
            if (sp24 == 0)
            {
                sp20 = arg0;
                sp1C = arg1;
            }
            else
            {
                sp20 = arg1;
                sp1C = arg0;
            }
            if (sp20 == 0)
            {
                gObjects[sp1C].unk10A = 0;
            }
            else if (sp20 < 6)
            {
                gObjects[sp1C].unk10A = 1;
            }
            else
            {
                if (sp20 < 0xE)
                {
                    gObjects[sp1C].unk10A = 2;
                }
                else if (D_80124D90[gObjects[sp20].unkE4].unk2 == 0)
                {
                    gObjects[sp1C].unk10A = 4;
                }
                else
                {
                    gObjects[sp1C].unk10A = 5;
                }
            }
        }
        sp34 = gObjects[arg1].Pos.x - gObjects[arg0].Pos.x;
        sp30 = gObjects[arg1].Pos.y - gObjects[arg0].Pos.y;
        sp2C = gObjects[arg1].Pos.z - gObjects[arg0].Pos.z;
        gObjects[arg0].unk124 = sp28 = func_800155A8(sp30, sp2C);
        gObjects[arg1].unk124 = func_80015538(sp28, 180.0f);

        gObjects[arg0].unk128 = sp28 = func_80015634(sp34, sp2C);
        gObjects[arg1].unk128 = func_80015538(sp28, 180.0f);
        gObjects[arg0].unk12C = sp28 = func_800156C4(sp34, sp30);
        gObjects[arg1].unk12C = func_80015538(sp28, 180.0f);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void func_80021B74(void)
{
    s32 sp4;

    for (sp4 = 0; sp4 < 0x4E; sp4++)
    {
        gObjects[sp4].unk104 = -1;
    }
}

void func_80021BCC(void)
{
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s16 sp26;
    s16 sp24;
    s16 sp22;
    f32 sp1C;

    if ((gCurrentLevel == MAP_MOVE_STONE) && (gPlayerObject->unkA4 == 0x2A))
    {
        for (sp30 = 0xE; sp30 < 0x4E; sp30++)
        {
            if (gObjects[sp30].unkE4 == 0x18E)
            {
                sp26 = func_80077CB0(0, (s16)sp30, &sp24, &sp22);
                if (sp26 != 0)
                {
                    gObjects[sp30].unkA6 = 0;
                    if (gPlayerObject->Pos.y < (gObjects[sp30].Pos.y + 60.0f))
                    {
                        sp1C = func_80015634(gObjects[sp30].Pos.x - gObjects->Pos.x, gObjects[sp30].Pos.z - gObjects->Pos.z);
                        sp1C = func_80015538(sp1C, 45.0f);
                        sp1C = (f32)(((s32)sp1C / 90) * 0x5A);
                        if (gPlayerObject->Rot.y == sp1C)
                        {
                            if (gPlayerObject->Rot.y == 0.0f)
                            {
                                gObjects[sp30].unkA6 = 1;
                            }
                            else if (gPlayerObject->Rot.y == 90.0f)
                            {
                                gObjects[sp30].unkA6 = 2;
                            }
                            else if (gPlayerObject->Rot.y == 180.0f)
                            {
                                gObjects[sp30].unkA6 = 3;
                            }
                            else if (gPlayerObject->Rot.y == 270.0f)
                            {
                                gObjects[sp30].unkA6 = 4;
                            }
                        }
                    }
                }
            }
        }
    }
    if (func_80021418(0) != 0)
    {
        for (sp30 = 0xE; sp30 < 0x4E; sp30++)
        {
            if (func_800214B8(sp30) != 0)
            {
                sp2C = gObjects[sp30].unkE4;
                sp28 = 1;
                if (D_8016523E == 6)
                {
                }
                else if (D_80124D90[sp2C].unk2 == 0)
                {
                    if ((gPlayerObject->unk108 != 1) && (gPlayerObject->unk108 != -1))
                    {
                        sp28 = 0;
                    }
                }
                if (((u8)D_80124D90[sp2C].unk0 & 1) == 1)
                {
                    sp28 = 0;
                }
                if ((sp28 != 0) && (func_80021584(0, sp30) != 0))
                {
                    break;
                }
            }
        }
    }

    if ((func_80021210(0) != 0) && (D_80165258 == 0))
    {
        for (sp30 = 6; sp30 < 0xE; sp30++)
        {
            if ((func_80021210(sp30) != 0) && (func_80021584(0, sp30) != 0))
            {
                break;
            }
        }
    }
    for (sp34 = 2; sp34 < 6; sp34++)
    {
        if (func_80021210(sp34) != 0)
        {
            for (sp30 = 0xE; sp30 < 0x4E; sp30++)
            {
                if ((func_80021210(sp30) != 0))
                {
                    if (!((u8)D_80124D90[gObjects[sp30].unkE4].unk0 & 2))
                    {
                        if (func_80021584(sp34, sp30))
                        {
                            break;
                        }
                    }
                }
            }
        }
    }

    for (sp34 = 2; sp34 < 6; sp34++)
    {
        if (func_80021210(sp34) != 0)
        {
            for (sp30 = 6; sp30 < 0xE; sp30++)
            {
                if ((func_80021210(sp30) != 0) && (func_80021584(sp34, sp30) != 0))
                {
                    break;
                }
            }
        }
    }

    if (D_8016523E == 0)
    {
        for (sp34 = 2; sp34 < 5; sp34++)
        {
            if (func_80021210(sp34) != 0)
            {
                for (sp30 = sp34 + 1; sp30 < 6; sp30++)
                {
                    if ((func_80021210(sp30) != 0) && (func_80021584(sp34, sp30) != 0))
                    {
                        break;
                    }
                }
            }
        }
    }

    for (sp34 = 6; sp34 < 0xE; sp34++)
    {
        if (func_80021210(sp34) != 0)
        {
            for (sp30 = 0xE; sp30 < 0x4E; sp30++)
                if ((func_80021210(sp30) != 0))
                {
                    if (!((u8)D_80124D90[gObjects[sp30].unkE4].unk0 & 2))
                    {
                        if ((func_80021584(sp34, sp30) != 0))
                        {
                            break;
                        }
                    }
                }
        }
    }

    for (sp34 = 0xE; sp34 < 0x4D; sp34++)
    {
        if (func_800214B8(sp34) != 0)
        {
            for (sp30 = sp34 + 1; (sp30) < 0x4E; sp30++)
            {
                if ((func_800212DC(sp34, sp30) != 0) && (func_80021584(sp34, sp30) != 0))
                {
                    break;
                }
            }
        }
    }
}

s32 func_80022454(void)
{
    // TODO: Move this
    struct UnkStruct_80022454_SP24 sp24;
    s16 sp22;
    s32 sp1C;
    struct ObjectStruct *sp18;

    if (gPlayerObject->unkA4 == 0)
    {
        return 0;
    }

    for (sp1C = 2, sp18 = &gObjects[2]; sp1C < 6; sp1C++, sp18++)
    {
        if (((sp18->unkA4 == 0x28) || (sp18->unkA4 == 0x29) || (sp18->unkA4 == 0x2A) || (sp18->unkA4 == 0x26) || (sp18->unkA4 == 0x27)))
        {

            if ((func_80077CB0(0, (s16)sp1C, &sp24.unk0, &sp22) != 0))
            {
                if (sp24.unk0 == 0)
                {
                    return sp1C;
                }
            }
        }
    }
    return 0;
}

s32 func_80022558(s32 arg0)
{
    struct UnkStruct_80022454_SP24 sp1C;
    s16 sp1A;

    if ((gObjects[arg0].unkA4 != 0))
    {
        if ((func_80077CB0(0, (s16)arg0, &sp1C.unk0, &sp1A) != 0))
        {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_800225D8(s32 arg0, s32 arg1)
{
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    u8 sp1F;

    if (gObjects[arg1].unkE6[0] != -1)
    {
        if ((char)gObjects[arg1].unk103 == 0)
        {
            sp2C = gObjects[arg1].unkE6[0];
            sp28 = gObjects[arg1].unkE6[0];
        }
        else
        {
            sp2C = arg1;
            sp28 = gObjects[arg1].unkE6[0];
        }
    }
    else
    {
        sp2C = arg1;
        sp28 = arg1;
    }

    if ((gObjects[sp2C].unk100 != 0) &&
        (gObjects[sp2C].unk108 != -1) &&
        (gObjects[sp2C].unk10B <= D_80124D90[gObjects[sp2C].unkE4].unk3))
    {

        sp24 = 0;
        sp20 = (s32)gObjects[arg0].unkE4;
        sp1F = D_80124D90[gObjects[sp2C].unkE4].unk5;
        if (sp1F & 8)
        {
            if ((gObjects[arg1].unkE4 == 0x141) && (sp20 != 8))
            {
                sp24 = 1;
            }
        }
        else if ((sp20 == 9) || (sp20 == 0x10))
        {
            if (sp1F & 4)
            {
                sp24 = 1;
            }
        }
        else if ((sp20 == 0xA) || (sp20 == 0x11))
        {
            if (sp1F & 2)
            {
                sp24 = 1;
            }
        }
        else if (sp1F & 1)
        {
            sp24 = 1;
        }
        if (sp20 == 0x12)
        {
            if (gObjects[sp2C].unkE4 == 0x20A)
            {
                sp24 = 0;
            }
        }
        else if ((sp20 == 0x14) && (gObjects[sp2C].unkE4 == 0x1C8))
        {
            sp24 = 0;
        }
        if ((gObjects[sp2C].unk100 != -1) && (sp24 != 0))
        {
            gObjects[sp2C].unk100 -= 1;
        }
        if (sp24 != 0)
        {
            if (gObjects[sp2C].unk100 == 0)
            {
                Score_Update(D_80124D90[gObjects[sp2C].unkE4].unk6);
                gCurrentParsedObject = sp28;
                D_80177A64 = 0;
                D_80124D90[gObjects[sp28].unkE4].routine_1C();
                return 1;
            }
            else
            {
                gCurrentParsedObject = sp28;
                D_80177A64 = 1;
                D_80124D90[gObjects[sp28].unkE4].routine_1C();
            }
        }
    }

    return 0;
}

void func_80022B54(void)
{
    struct ObjectStruct *sp2C;
    s32 sp28;
    s32 sp24;
    s16 temp_t1;
    s16 temp_t3;

    sp28 = (s32)gPlayerObject->unk104;
    sp2C = &gObjects[sp28];
    switch (sp2C->unkE4)
    {
    case 0x20:
        if (gBombCount < 3)
        {
            gBombCount += 1;
        }
        D_80165250 = 0;
        D_80165268 = 0;
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x21:
        if (gFireCount < 3)
        {
            gFireCount += 1;
        }
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x22:
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x30:
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x23:
        if (gHealthCount < gMaxHealth)
        {
            gHealthCount += 1;
        }
        func_8008424C();
        func_800178D4(0, 0, 0x27, -1, 0);
        break;
    case 0x24:
        gHealthCount = gMaxHealth;
        func_8008424C();
        func_800178D4(0, 0, 0x27, -1, 0);
        break;
    case 0x25:
    case 0x31:
        if (sp2C->unkE4 == 0x25)
        {
            sp24 = 1;
        }
        else
        {
            sp24 = 5;
        }
        gGemCount += sp24;
        if ((s32)gGemCount < 0xC8)
        {
            func_800178D4(0, 0, 0x25, -1, 0);
        }
        else
        {
            if (gMaxHealth != 8)
            {
                gMaxHealth += 1;
                D_80177A54 = 0x1E;
                func_800178D4(0, 0, 0x27, -1, 0);
            }
            else if ((s32)gLifeCount < 0x63)
            {
                func_80088248(1);
                func_800178D4(0, 0, 0x24, -1, 0);
            }
            gGemCount -= 0xC8;
        }
        break;
    case 0x26:
        if ((s32)gLifeCount < 0x63)
        {
            func_80088248(1);
        }
        func_800178D4(0, 0, 0x24, -1, 0);
        break;
    case 0x27:
        func_80025568(D_8013488C, gObjects[sp28].unkA6);
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x28:
        D_80165246 = 1;
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x2C:
        D_80165242 += 1;
        if (D_80165242 == 4)
        {
            func_800178D4(0, 0, 0x61, -1, 0);
        }
        else
        {
            func_800178D4(0, 0, 0x25, -1, 0);
        }
        break;
    case 0x2F:
        D_80165247 = 1;
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x32:
        if ((gPlayerObject->unkA4 != 0x31) && (gPlayerObject->unk108 != 0x3D) && (gPlayerObject->unk108 != 0))
        {
            func_8028491C();
            func_800178D4(0, 0, 0x26, -1, 0);
        }
        break;
    case 0x33:
        func_800766B4(gObjects[sp28].unkA6);
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x35:
        D_80165248 = 1;
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x36:
        func_80025810(D_8013488C, 0, gObjects[sp28].unkA6);
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x37:
        func_80025810(D_8013488C, 1, gObjects[sp28].unkA6);
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x38:
        func_80025810(D_8013488C, 2, gObjects[sp28].unkA6);
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x29:
        D_80165250 = 3;
        D_80165258 = 0;
        D_80165260 = 0;
        D_80165268 = 0;
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x2A:
        D_80165250 = 2;
        D_80165258 = 0;
        D_80165260 = 0;
        D_80165268 = 0;
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x2B:
        D_80165250 = 1;
        D_80165258 = 0;
        D_80165260 = 0;
        D_80165268 = 0;
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x2D:
        D_80165250 = 0;
        D_80165258 = 1;
        D_80165260 = 0;
        D_80165268 = 0;
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x2E:
        D_80165250 = 0;
        D_80165258 = 0;
        D_80165260 = 1;
        D_80165268 = 0;
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    case 0x34:
        D_80165250 = 0;
        D_80165258 = 0;
        D_80165260 = 0;
        D_80165268 = 1;
        func_800178D4(0, 0, 0x26, -1, 0);
        break;
    }
    gCurrentParsedObject = sp28;
    D_80177A64 = 0;
    D_80124D90[gObjects[sp28].unkE4].routine_1C();
    Score_Update((s16)D_80124D90[gObjects[sp28].unkE4].unk6);
    D_801775FA += 1;
}

void func_80023404(void)
{
    s32 sp1C;

    if ((gPlayerObject->unk106 == 0x13E) || (gPlayerObject->unk106 == 0x1B1) || (gPlayerObject->unk106 == 0x1B4) || (gPlayerObject->unk106 == 0x1B5))
    {
        D_8016E088 = 5;
    }
    else
    {
        sp1C = (s32)gPlayerObject->unk104;
        if (*(&gObjects->unk102 + (sp1C * 0x150)) != 0)
        {
            D_80177648 = 1;
            D_8016E088 = 2;
        }
        gCurrentParsedObject = sp1C;
        D_80177A64 = 2;
        D_80124D90[gObjects[sp1C].unkE4].routine_1C();
    }
}

void func_80023534(void)
{
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp1C = 0;
    if (((s32)gPlayerObject->unk10B < 0xA))
    {
        if ((gPlayerObject->Vel.y <= 0.0f))
        {
            if ((D_801651A4 & 1) && (gPlayerObject->unk108 != 0x3D))
            {
                sp1C = 1;
            }
        }
    }
    if (sp1C != 0)
    {
        sp24 = (s32)gPlayerObject->unk104;
        D_8016E088 = 5;
        sp20 = func_800225D8(0, sp24);
        if ((sp20 == 1) && (gObjects[sp24].unkE4 == 0xA0))
        {
            D_80165242 += 1;
        }
    }
    else if (gPlayerObject->unk108 == 1)
    {
        sp24 = (s32)gPlayerObject->unk104;
        if (gObjects[sp24].unk102 != 0)
        {
            D_80177648 = 1;
            D_8016E088 = 2;
        }
        gCurrentParsedObject = sp24;
        D_80177A64 = 2;
        D_80124D90[gObjects[sp24].unkE4].routine_1C();
    }
}

void func_80023754(void)
{
    s32 sp1C;
    s32 sp18;

    sp1C = (s32)gPlayerObject->unk104;
    sp18 = 0;

    if (((gPlayerObject->unkA4 == 0x20D) || (gPlayerObject->unkA4 == 0x20E) || (gPlayerObject->unkA4 == 0x20F) || (gPlayerObject->unkA4 == 0x210) || (gPlayerObject->unkA4 == 0x211) || (gPlayerObject->unkA4 == 0x212) || (gPlayerObject->unkA4 == 0x216)) && (gObjects[sp1C].unk100 == 1))
    {
        sp18 = 1;
    }
    if (sp18 != 0)
    {
        D_8016E088 = 5;
        func_800225D8(0, sp1C);
    }
    else
    {
        if (gObjects[sp1C].unk102 != 0)
        {
            D_80177648 = 1;
            D_8016E088 = 2;
        }
        gCurrentParsedObject = sp1C;
        D_80177A64 = 2;
        D_80124D90[gObjects[sp1C].unkE4].routine_1C();
    }
}

void func_80023904(void)
{
    s32 sp1C;

    sp1C = (s32)gPlayerObject->unk104;
    if (gObjects[sp1C].unk102 != 0)
    {
        D_80177648 = 1;
        D_8016E088 = 2;
    }
    gCurrentParsedObject = sp1C;
    D_80177A64 = 2;
    D_80124D90[gObjects[sp1C].unkE4].routine_1C();
}

void func_800239E4(void)
{
    D_8016E088 = 0;
    D_80177648 = 0;
    if (gPlayerObject->unk104 != -1)
    {
        if (gPlayerObject->unk10A == 2)
        {
            if (gPlayerObject->unk108 != -1)
            {
                D_80177648 = 1;
                D_8016E088 = 1;
            }
        }
        else if (gPlayerObject->unk10A == 4)
        {
            if (gPlayerObject->unk108 != -1)
            {
                switch (D_8016523E)
                { /* irregular */
                case 0:
                    func_80023404();
                    break;
                case 5:
                    func_80023754();
                    break;
                case 6:
                    func_80023534();
                    break;
                default:
                    func_80023904();
                    break;
                }
            }
        }
        else if (gPlayerObject->unk10A == 5)
        {
            func_80022B54();
        }
    }

    switch (D_8016523E)
    {
    case 0:
    case 4:
    case 5:
    case 6:
        func_80086AD0();

        if ((u8)D_8016E080 == 3)
        {
            D_80177648 = 2;
            D_8016E088 = 3;
        }
        else if (((u8)D_8016E080 == 4) || ((u8)D_8016E080 == 5))
        {
            if (D_8016523E == 0)
            {
                D_80177648 = 1;
                D_8016E088 = 3;
            }
            else if ((D_8016523E == 4) && (gPlayerObject->unk108 == 1))
            {
                D_80177648 = 1;
                D_8016E088 = 3;
            }
        }
        else if (((u8)D_8016E080 != 0) && (gPlayerObject->unk108 == 1))
        {
            D_80177648 = 1;
            D_8016E088 = 3;
        }
        break;
    }

    if (gDebugInvincibileFlag == 0)
    {
        if ((D_801778F4 == 0) && (D_8016E3CC == 0))
        {
            if (D_80177648 == 1)
            {
                if (gHealthCount != 0)
                {
                    gHealthCount -= 1;
                }
                if (gHealthCount == 0)
                {
                    gPlayerObject->unk108 = 0;
                }
                else
                {
                    gPlayerObject->unk108 = 0x3D;
                }
            }
            else if (D_80177648 == 2)
            {
                gPlayerObject->unk108 = 0;
            }
            if ((D_8016E110 == 1) && (D_8016E112 == 0))
            {
                D_8016E112 = 0xB4;
                gHealthCount -= 1;
                if (gHealthCount == 0)
                {
                    gPlayerObject->unk108 = 0;
                    D_8016E088 = 4;
                }
            }
        }
        else if ((gPlayerObject->unk108 != 0) && (((u8)D_8016E080 == 3) || ((u8)D_8016E080 == 4) || ((u8)D_8016E080 == 5)))
        {
            D_8016E0D0 = 1;
        }
    }
}

void func_80023E78(void)
{
    s32 sp1C;
    s32 sp18;
    for (sp1C = 2; sp1C < 6; sp1C++)
    {
        if (gObjects[sp1C].unk104 != -1)
        {
            sp18 = (s32)gObjects[sp1C].unk104;
            if (gObjects[sp1C].unk10A == 1)
            {
                if (gObjects[sp1C].unkA4 != 0x26 && gObjects[sp18].unkA4 != 0x26 && (gObjects[sp1C].unkA4 != 0x1B && gObjects[sp18].unkA4 != 0x1B) && (gObjects[sp1C].unkA4 != 0x13 && gObjects[sp18].unkA4 != 0x13))
                {
                    gObjects[sp1C].unkA4 = 7;
                }
            }
            else if (gObjects[sp1C].unk10A == 2)
            {
                gObjects[sp1C].unkA4 = 7;
            }
            else if (gObjects[sp1C].unk10A == 4)
            {
                if (((gObjects[sp18].unkE4 == 0x1C8) && (gObjects[sp18].unkA4 == 0xC)) || ((gObjects[sp18].unkE4 == 0x1CF) && (gObjects[0xE].unkA4 == 0xC)))
                {
                }
                else
                {
                    gObjects[sp1C].unkA4 = 7;
                    func_800225D8(sp1C, sp18);
                }
            }
            else if (gObjects[sp1C].unk10A == 5)
            {
                gObjects[sp1C].unkA4 = 7;
                func_800225D8(sp1C, sp18);
            }
        }
    }
}

void func_800241CC(void)
{
    s32 sp1C;
    s32 sp18;
    for (sp18 = 6; sp18 < 0xE; sp18++)
    {
        if (gObjects[sp18].unk104 != -1)
        {
            sp1C = (s32)gObjects[sp18].unk104;
            if (gObjects[sp18].unk10A == 4)
            {
                func_800225D8(sp18, sp1C);
            }
            else if (gObjects[sp18].unk10A == 5)
            {
                func_800225D8(sp18, sp1C);
            }
        }
    }
}
s32 func_800242F0(void)
{
    if (D_801765F4 == 0)
    {
        if (gActiveContPressed & 0x1000)
        {
            if (gCurrentLevel >= 0x80)
            {
                if (D_80134C26 == 0)
                {
                    func_80069E00(0, 0);
                    func_8001F9DC();
                    return 1;
                }
            }
            else if ((gPlayerObject->unk108 != 0) && (D_801778F4 == 0) && (func_80076680() == 0))
            {
                D_801765FC = 0;
                D_801765F4 = 1;
                D_80176602 = 0;
                func_800178D4(-1, 0, 0x40, -1, 0);
                func_80016FF8(0x40);
                func_8001F9DC();
                return 1;
            }
        }
        goto end;
    }
    if (D_8016E3EE != 0)
    {
        func_80100148();
        return 1;
    }
    else if ((gActiveContPressed & 0x0020) && (gShowDebugMenu != 0))
    {
        D_8016E3EE = 1;
        gDebugDisplayMode = D_8016E3EC;
        D_8016E3EC = 0x64;
        D_8016E3F4 = 0;
        return 1;
    }
    else if ((gActiveContPressed & 0x1000) || (gActiveContPressed & 0x8000))
    {
        if (gShowDebugMenu != 0)
        {
            D_801765FC = 1;
        }
        else
        {
            func_800178D4(-1, 0, 0x40, -1, 0);
            if (D_80176602 != 0)
            {
                func_80069AA8(4, 0);
            }
            else
            {
                D_801765F4 = 0;
                func_80016FF8(0x7F);
            }
        }
        return 1;
    }
    else if (gActiveContDirPressed & 0x200)
    {
        D_80176602 = 0;
        func_800178D4(-1, 0, 0x6E, -1, 0);
        return 1;
    }
    else if (gActiveContDirPressed & 0x100)
    {
        D_80176602 = 1;
        func_800178D4(-1, 0, 0x6E, -1, 0);
        return 1;
    }
    else if (D_801765FC == 0)
    {
        return 1;
    }
    else if (!(gActiveContButton & 0x1000))
    {
        if ((D_801765FC > 0) && (D_801765FC < 0xA))
        {
            if (D_80176602 != 0)
            {
                func_80069AA8(4, 0);
            }
            else
            {
                D_801765F4 = 0;
                func_80016FF8(0x7F);
            }
        }
        else
        {
            D_801765FC = 0;
        }
        return 1;
    }
    else
    {
        D_801765FC++;
        if (D_801765FC < 0x14)
        {
            return 1;
        }
        D_801765FC = 0xA;
    }
end:
    return 0;
}

void func_800246F0(void)
{
    if (!(gActiveContPressed & 0x0020))
    {
        return;
    }
    func_8005FAA0(&D_80050D38, &D_80050D38 + 0x1000);
}

void func_80024744(void)
{
    f32 sp6C;
    Matrix sp2C;
    UpdateActiveController(FALSE);

    if ((gCameraType == 1) || (gCameraType == 2) || (gCameraType == 5) || (gCameraType == 6) || (gCameraType == 7) || (gCameraType == 8))
    {
        guRotateF(sp2C, gView.rot.y, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(sp2C, gActiveContStickX, 0.0f, gActiveContStickY, &gActiveContStickX, &sp6C, &gActiveContStickY);
    }

    if (gShowDebugMenu)
    {
        if ((gActiveContButton & (0x3000)) == 0x3000)
        {
            func_80069AA8(-1, 0);
        }
        if ((gGoldBomber != 0) && ((gActiveContButton & 0x2020) == 0x2020))
        {
            if (gCurrentLevel < 0x80)
            {
                func_80069D88(0, 1);
            }
            else
            {
                func_80069E00(0, 0);
            }
        }
    }

    if ((D_8016E3CC == 0) && (func_800242F0() != 0))
    {
    }
    else if (D_8016E3CC != 0)
    {
    }
    else
    {
        func_8006C1DC();
        func_80026548();
        func_80088ECC();
        func_80089C18();
        func_80021B74();
        func_80021BCC();
        func_80023E78();
        func_800241CC();
        func_800239E4();
        func_80076720();
        if (func_80076680() != 0)
        {
        }
        else
        {
            if ((u8)D_8017660A == 0)
            {
                func_8002B154();
            }
            else
            {
                func_8008C128();
            }
            if ((u8)D_80176606 == 0)
            {
                if (D_8016E3CC == 0)
                {
                    func_80087994();
                }
            }
            else
            {
                func_8008BCC0();
            }
            func_80069E88();
            func_8006A95C();
            func_8007E454();
            func_8007F24C();
            func_800816FC();
            func_8008B0F4();
            func_80076374();
            func_8006DDF4();
            func_800663EC();
            func_800654AC();
            func_8006AD28();
            if ((u32)D_801775F0 < 0x278D00U)
            {
                D_801775F0 += 1;
            }
            func_800842C0();
            func_80070AC8();
        }
    }
    func_800713D0();
    func_80070934();
    func_80064000();
    if (D_80177A20 >= 2)
    {
        func_80087B1C();
    }
    if (gCameraType == 1)
    {
        func_80071E28();
    }
    func_8001994C();
    if ((D_8016E3CC != 0) && (D_8016E3CD == 0))
    {
        if ((func_8001D1D4() != 1) && (func_8001D1D4() != 2))
        {
            if (gLevelInfo[gCurrentLevel]->unk33 == 0)
            {
                func_8001D244(-1, -1, -1, 0x10);
                func_80016FC8(0x20);
            }
            else if (gLevelInfo[gCurrentLevel]->unk33 == 1)
            {
                func_8001D244(-1, -1, -1, 4);
                func_80016FC8(0x80);
            }
            else
            {
                func_8001D244(0, 0, 0, -1);
            }
            func_8001D2C0();
        }
        if (func_8001D1D4() == 2)
        {
            PlayTrack_WithVolLoop(-1, -1, 0);
            func_80017EB8();
            D_80165264 = 1;
        }
    }
}
