#include "PR/os_internal.h"
#include "controller.h"

extern OSTimer D_8005A498;

s32 osEepromLongRead(OSMesgQueue* mq, u8 address, u8* buffer, int length) {
    s32 ret = 0;

    if(address >= 0x41) {
        return -1;
    }

    while (length > 0) {
        ERRCK(osEepromRead(mq, address, buffer));
        length -= EEPROM_BLOCK_SIZE;
        address++;
        buffer += EEPROM_BLOCK_SIZE;

        osSetTimer(&D_8005A498, (0x2EE0 * osClockRate) / 0xF4240, 0, &__osEepromTimerQ, &__osEepromTimerMsg);
        osRecvMesg(&__osEepromTimerQ, 0, 1);
    }

    return ret;
}
