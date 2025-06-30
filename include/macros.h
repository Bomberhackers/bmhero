#ifndef __MACROS_H__
#define __MACROS_H__

#ifdef __GNUC__
#define GLOBAL_ASM(...)
#endif

#define ALIGNED(x) __attribute__((aligned(x)))

#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

#define STUBBED_PRINTF(x) ((void)(x))

#define UNUSED __attribute__((unused))

#define SQ(x) (x * x)

#define HW_REG(reg, type)   *(volatile type *)(reg | 0xa0000000)

#define DEG_TO_RAD 0.0174532925199432955

#define PLAYER_OBJ gObjects[0]

#ifdef ENABLE_ISPRINT
#define DEBUG_PRINTF osSyncPrintf
#else
#define DEBUG_PRINTF printf_stub
#endif

#ifndef __GNUC__
#define __attribute__(x)
#endif

#endif
