#include <ultra64.h>

struct UnkStructSp20
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

s32 func_80002890(struct UnkStruct80001CF0 *arg0, s32 *arg1, s32 *arg2, s32 arg3)
{
    s32 sp24 = arg3;
    struct UnkStructSp20 *sp20 = (struct UnkStructSp20 *)arg0->unk268;
    u32 sp1C = arg0->unk264;

    if ((arg0->unk280 != 0) && (sp24 & 2))
    {
        if ((sp20 != 0) && (sp20->unk8 & 0x10))
        {
            *arg1 = (s32)sp20;
            sp24 &= ~2;
        }
        else
        {
            *arg1 = (s32)sp1C;
            sp24 &= ~2;
            arg0->unk280 = 0;
            arg0->unk264 = **(u32 **)&arg0->unk264;
            if (arg0->unk264 == 0)
            {
                arg0->unk26C = 0;
            }
        }
    }
    else if (func_800024F4(sp20) != 0)
    {
        switch ((sp20->unk8 & 7) - 1)
        {
        case 2:
            if (sp20->unk4 & 0x20)
            {
                if (sp24 & 2)
                {
                    *arg1 = (s32)sp20;
                    sp24 &= ~2;
                    if (sp20->unk4 & 1)
                    {
                        *arg2 = (s32)sp20;
                        sp24 &= ~1;
                        if (FALSE) {}
                    }
                    arg0->unk268 = **(u32 **)&arg0->unk268;
                    if (arg0->unk268 == 0)
                    {
                        arg0->unk270 = 0;
                    }
                }
            }
            else if (sp24 == 3)
            {
                *arg2 = (s32)sp20;
                *arg1 = *arg2;
                sp24 &= ~3;
                arg0->unk268 = **(u32 **)&arg0->unk268;
                if (arg0->unk268 == 0)
                {
                    arg0->unk270 = 0;
                }
            }
            break;
        case 1:
        case 5:
        case 6:
            if (sp20->unk4 & 2)
            {
                if (sp24 & 2)
                {
                    *arg1 = (s32)sp20;
                    sp24 &= ~2;
                }
            }
            else if ((sp20->unk4 & 1) && (sp24 & 1))
            {
                *arg2 = (s32)sp20;
                sp24 &= ~1;
                arg0->unk268 = **(u32 **)&arg0->unk268;
                if (arg0->unk268 == 0)
                {
                    arg0->unk270 = 0;
                }
            }
            break;
        case 0:
        case 4:
        default:
            break;
        }
    }
    if (sp24 != arg3)
    {
        sp24 = func_80002890(arg0, arg1, arg2, sp24);
    }
    return sp24;
}
