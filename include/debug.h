#ifndef DEBUG_H
#define DEBUG_H


extern void printf_stub(char* fmt, ...);

#ifdef ENABLE_ISPRINT
#define DEBUG_PRINTF osSyncPrintf
#else
#define DEBUG_PRINTF printf_stub
#endif

#endif /* DEBUG_H */
