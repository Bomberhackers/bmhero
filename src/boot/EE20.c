#include <ultra64.h>

void *memset(void *dest, u32 c, s32 size)
{
    u8 *dest_new = (u8 *)dest;

    while (size--)
    {
        *(dest_new++) = c;
    }

    return dest;
}

void *memmove(void *dest, u32 *src, s32 size)
{
    u32 Unk00 = (u32)dest; // C
    u32 Unk01 = (u32)src;  // 8

    if (size != 0 && (dest != src))
    {
        if (Unk00 > Unk01 && Unk00 < ((u32)Unk01 + size))
        {
            while (size--)
            {
                *(u8 *)(size + (u32)Unk00) = *(u8 *)(size + (u32)Unk01);
            }
        }
        else
        {
            while (size--)
            {
                *(u8 *)(Unk00) = *(u8 *)Unk01, Unk00 += 1, Unk01 += 1;
            }
        }
    }

    return dest;
}

s32 *sbrk(u32 arg0)
{
    s32 *Unk00 = D_8004A370;

    D_8004A370 = arg0 + (s32)D_8004A370;

    if (((s32)D_8004A370 - (s32)&D_80380000) >= 0x80000)
    {
        printf("sbrk : can not change data segment space allocation!\n");
        return -1;
    }

    return Unk00;
}
