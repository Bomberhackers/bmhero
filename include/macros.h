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

#ifndef __GNUC__
#define __attribute__(x)
#endif

#endif
