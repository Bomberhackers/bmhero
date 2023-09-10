#include <ultra64.h>

extern u64 osClockRate;
extern OSTimer D_8005A498;
extern OSMesgQueue D_8005A4B8;
extern OSMesg D_8005A4D0;

extern s32 func_80044D70(s32, u8, s32);

s32 func_80039F60(s32 arg0, u8 arg1, s32 arg2, s32 arg3) {
    s32 RetValue = 0;
    
    if(arg1 >= 0x41){
        return -1;
    }
    
    while(arg3 > 0) {
        RetValue = func_80044D70(arg0, arg1, arg2);
        if (RetValue != 0) {
            return RetValue;
        }

        arg3 -= 8;
        arg1 += 1;
        arg2 += 8;

        osSetTimer(&D_8005A498, (0x2EE0 * osClockRate) / 0xF4240, 0, &D_8005A4B8, &D_8005A4D0);
        osRecvMesg(&D_8005A4B8, 0, 1);
    }

    return RetValue;
}
