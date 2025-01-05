#include <ultra64.h>
#include <stdarg.h>
#include "os.h"
#include "../libultra/io/piint.h"

// enhancement file for IS Print functionality to work. This file is not part of the original game
// and was added to make documenting the project easier.

#ifdef ENABLE_ISPRINT

// borrowed from ultralib

s32 osEPiWriteIo(OSPiHandle *pihandle, u32 devAddr, u32 data)
{
    register s32 ret;

    __osPiGetAccess();
    ret = __osEPiRawWriteIo(pihandle, devAddr, data);
    __osPiRelAccess();

    return ret;
}

s32 osEPiReadIo(OSPiHandle *pihandle, u32 devAddr, u32 *data)
{
    register s32 ret;

    __osPiGetAccess();
    ret = __osEPiRawReadIo(pihandle, devAddr, data);
    __osPiRelAccess();

    return ret;
}

// borrowed from is_debug.c

void *is_proutSyncPrintf(void *arg, const char *str, size_t count);

extern OSPiHandle *sISVHandle; // official name : is_Handle

typedef struct
{
    /* 0x00 */ u32 magic; // IS64
    /* 0x04 */ u32 get;
    /* 0x08 */ u8 unk_08[0x14 - 0x08];
    /* 0x14 */ u32 put;
    /* 0x18 */ u8 unk_18[0x20 - 0x18];
    /* 0x20 */ u8 data[0x10000 - 0x20];
} ISVDbg;

#define gISVDbgPrnAdrs ((ISVDbg *)0xB3FF0000)
#define ASCII_TO_U32(a, b, c, d) ((u32)((a << 24) | (b << 16) | (c << 8) | (d << 0)))

void isPrintfInit(void)
{
    sISVHandle = osCartRomInit();
    osEPiWriteIo(sISVHandle, (u32)&gISVDbgPrnAdrs->put, 0);
    osEPiWriteIo(sISVHandle, (u32)&gISVDbgPrnAdrs->get, 0);
    osEPiWriteIo(sISVHandle, (u32)&gISVDbgPrnAdrs->magic, ASCII_TO_U32('I', 'S', '6', '4'));
}

void osSyncPrintf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    _Printf(is_proutSyncPrintf, NULL, fmt, args);

    va_end(args);
}

void *is_proutSyncPrintf(void *arg, const char *str, size_t count)
{
    u32 data;
    s32 pos;
    s32 start;
    s32 end;

    osEPiReadIo(sISVHandle, (u32)&gISVDbgPrnAdrs->magic, &data);
    if (data != ASCII_TO_U32('I', 'S', '6', '4'))
    {
        return (void *)1;
    }
    osEPiReadIo(sISVHandle, (u32)&gISVDbgPrnAdrs->get, &data);
    pos = data;
    osEPiReadIo(sISVHandle, (u32)&gISVDbgPrnAdrs->put, &data);
    start = data;
    end = start + count;
    if (end >= 0xFFE0)
    {
        end -= 0xFFE0;
        if (pos < end || start < pos)
        {
            return (void *)1;
        }
    }
    else
    {
        if (start < pos && pos < end)
        {
            return (void *)1;
        }
    }
    while (count)
    {
        u32 addr = (u32)&gISVDbgPrnAdrs->data + (start & 0xFFFFFFC);
        s32 shift = ((3 - (start & 3)) * 8);

        if (*str)
        {
            osEPiReadIo(sISVHandle, addr, &data);
            osEPiWriteIo(sISVHandle, addr, (*str << shift) | (data & ~(0xFF << shift)));

            start++;
            if (start >= 0xFFE0)
            {
                start -= 0xFFE0;
            }
        }
        count--;
        str++;
    }
    osEPiWriteIo(sISVHandle, (u32)&gISVDbgPrnAdrs->put, start);

    return (void *)1;
}
#endif
