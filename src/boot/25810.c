#include "prevent_bss_reordering.h"
#include "functions.h"
#include "variables.h"
#include "25810.h"

u8 D_8004A640[16] = { 'B', 'O', 'M', 'H', 'E', 'R', 'O', 0, 0, 0, 0, 0, 0, 0, 0, 0 };

u8 D_8004A650[7] = { 0, 255, 0, 255, 1, 0, 1 };

u8 func_80024C10(s32 arg0) {
    s32 spC;
    s32 sp8;
    s32 sp4;
    u8 sp3;

    spC = arg0 * 0x78; // What?
    sp3 = 0;
    if (arg0 < 4) {
        sp8 = 0x6F;
    } else {
        sp8 = 0x17;
    }
    for (sp4 = 0; sp4 < sp8; sp4++) {
        sp3 = sp3 + D_80057450[spC + sp4];
    }
    return sp3;
}

u8 func_80024CB4(s32 arg0) {
    u8 sp7;

    if (arg0 < 4) {
        sp7 = D_800574BF[arg0].unk0;
    } else {
        sp7 = D_80057467[arg0].unk0;
    }
    return sp7;
}

void func_80024D20(s32 arg0, char arg1) {
    if (arg0 < 4) {
        D_800574BF[arg0].unk0 = arg1;
    } else {
        D_80057467[arg0].unk0 = arg1;
    }
}

s32 func_80024D74(s32 arg0) {
    s32 sp4;
    s32 sp0;

    if (arg0 < 4) {
        sp4 = (arg0 * 0x78) + 0x68;
    } else {
        sp4 = (arg0 * 0x78) + 0x10;
    }

    for (sp0 = 0; sp0 <= 6; sp0++) {
        if (D_80057450[sp4 + sp0] != (u8) D_8004A640[sp0]) {
            return 1;
        }
    }
    return 0;
}

void func_80024E1C(s32 arg0) {
    s32 spC;
    UNUSED s32 pad;
    s32 sp4;

    if (arg0 < 4) {
        spC = (arg0 * 0x78) + 0x68;
    } else {
        spC = (arg0 * 0x78) + 0x10;
    }
    for (sp4 = 0; sp4 < 7; sp4++) {
        D_80057450[spC + sp4] = (u8) D_8004A640[sp4];
    }
}

s32 func_80024EA8(void) {
    int status;

    status = Eeprom_Read(&gContMesgQueue, D_80057450, 0x0, 512);
    return status;
}

s32 func_80024EF4(s32 arg0) {
    s32 sp2C;
    s32 sp28;
    u16 sp26;

    func_80024D20(arg0, func_80024C10(arg0));
    if (arg0 < 4) {
        sp26 = 0x78;
    } else {
        sp26 = 0x20;
    }
    sp28 = arg0 * 0x78;
    D_80057448[sp28 + sp26] = 1;
    sp2C = Eeprom_Write(&gContMesgQueue, &D_80057450[(sp28 + sp26) - 8], (s32) ((sp26 + sp28) - 8) / 8, 8U);
    sp2C = Eeprom_Write(&gContMesgQueue, &D_80057450[sp28], sp28 / 8, sp26) + sp2C;
    D_80057448[sp28 + sp26] = 0;
    sp2C = Eeprom_Write(&gContMesgQueue, &D_80057450[(sp28 + sp26) - 8], (s32) ((sp26 + sp28) - 8) / 8, 8U) + sp2C;
    return sp2C;
}

void func_800250A0(s32 arg0) {
    u8 sp17;
    u8 sp16;
    s32 sp10;
    s32 spC;
    s32 i;
    s32 j;
    s32 k;

    spC = arg0 * 0x78;
    sp10 = 0;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 7; k++) {
                if (sp10 == 0) {
                    sp16 = 0;
                }
                sp17 = D_80134808[(i * 0x15) + (j * 7) + k] & 0xF;
                sp16 |= sp17 << (sp10 * 4);
                sp10++;
                if (sp10 == 2) {
                    sp10 = 0;
                    D_80057450[spC++] = sp16;
                }
            }
        }
    }
}

void func_800251D4(s32 arg0) {
    s32 spC;
    s32 sp8;
    u8* sp4;
    u8 sp3;

    spC = arg0 * 0x78;
    sp4 = D_80134808;

    for (sp8 = 0;;) {
        sp3 = ((D_80057450[spC]) >> (sp8 * 4)) & 0xF;
        *sp4 = sp3;
        sp4++;

        if (sp4 > (D_80134808 + 0x7D)) {
            break;
        }

        sp8++;

        if (sp8 == 2) {
            sp8 = 0;
            spC++;
        }
    }
}

void func_800252AC(s32 arg0, s32* arg1, u8* arg2, u8* arg3, u8* arg4) {
    s32 sp4;
    u8 sp3;

    sp4 = arg0 * 0x78;
    sp3 = D_80057490[sp4];
    if (sp3 == 0xFF) {
        *((s8*) arg1) = -1;
        *arg2 = 0;
        *arg3 = 0;
        *arg4 = 0;
    } else {
        *((s8*) arg1) = sp3;
        *arg2 = D_80057491[sp4];
        *arg3 = D_80057492[sp4];
        *arg4 = D_80057493[sp4];
    }
}

void func_8002536C(s32 arg0, s8 arg1, s8 arg2, s8 arg3, s8 arg4) {
    s32 sp4;

    sp4 = arg0 * 0x78;
    D_80057490[sp4] = (u8) arg1;
    D_80057491[sp4] = (u8) arg2;
    D_80057492[sp4] = (u8) arg3;
    D_80057493[sp4] = (u8) arg4;
}

u8 func_800253EC(s32 arg0) {
    s32 sp4;

    sp4 = arg0 * 0x78;
    return D_80057494[sp4];
}

void func_80025428(s32 arg0, u8 arg1) {
    s32 sp4;

    sp4 = arg0 * 0x78;
    D_80057494[sp4] = arg1;
}

s32 func_80025460(s32 arg0, s32 arg1) {
    s32 sp4;
    u8 sp3;

    sp4 = arg0 * 0x78;
    sp3 = D_80057495[sp4 + (arg1 / 8)];
    if (((s32) sp3 >> (arg1 % 8)) & 1) {
        return 1;
    }
    return 0;
}

s32 func_800254E8(s32 arg0) {
    s32 sp1C;

    for (sp1C = 0; sp1C < 0x18; sp1C++) {
        if (func_80025460(arg0, sp1C) == 0) {
            break;
        }
    }

    if (sp1C == 0x18) {
        return TRUE;
    }

    return FALSE;
}

void func_80025568(s32 arg0, s32 arg1) {
    s32 sp4;
    u8 sp3;

    sp4 = arg0 * 0x78;
    sp3 = D_80057495[sp4 + (arg1 / 8)];
    sp3 |= 1 << (arg1 % 8);
    D_80057495[sp4 + (arg1 / 8)] = sp3;
}

void func_80025608(s32 arg0) {
    s32 sp4;

    sp4 = arg0 * 0x78;
    D_80057650 = D_80057495[sp4];
    D_80057651 = D_80057496[sp4];
    D_80057652 = D_80057497[sp4];
}

void func_80025674(s32 arg0) {
    s32 sp4;

    sp4 = arg0 * 0x78;
    D_80057495[sp4] = D_80057650;
    D_80057496[sp4] = D_80057651;
    D_80057497[sp4] = D_80057652;
}

s32 func_800256E0(s32 arg0, s32 arg1, s32 arg2) {
    s32 spC;
    s32 sp8;
    u8 sp7;

    spC = arg0 * 0x78;
    sp8 = arg1 + 0x48;
    sp7 = D_80057450[spC + sp8];
    if (((s32) sp7 >> (arg2 % 8)) & 1) {
        return 1;
    }
    return 0;
}

s32 func_80025764(s32 arg0) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp1C = 0;
    for (sp24 = 0; sp24 < 3; sp24++) {
        for (sp20 = 0; sp20 < 8; sp20++) {
            if (func_800256E0(arg0, sp24, sp20) != 0) {
                sp1C++;
            }
        }
    }
    if (sp1C == 0x18) {
        return 1;
    }
    return 0;
}

void func_80025810(s32 arg0, s32 arg1, s32 arg2) {
    s32 spC;
    s32 sp8;
    u8 sp7;

    spC = arg0 * 0x78;
    sp8 = arg1 + 0x48;
    sp7 = D_80057450[spC + sp8];
    sp7 |= 1 << (arg2 % 8);
    D_80057450[spC + sp8] = sp7;
}

void func_800258A0(s32 arg0) {
    s32 sp4;

    sp4 = arg0 * 0x78;
    D_80057653 = D_80057498[sp4];
    D_80057654 = D_80057499[sp4];
    D_80057655 = D_8005749A[sp4];
}

void func_8002590C(s32 arg0) {
    s32 sp4;

    sp4 = arg0 * 0x78;
    D_80057498[sp4] = D_80057653;
    D_80057499[sp4] = D_80057654;
    D_8005749A[sp4] = D_80057655;
}

void func_80025978(UNUSED s32 arg0) {
}

void func_8002598C(UNUSED s32 arg0) {
}

void func_800259A0(s32 arg0, s32 arg1) {
    s32 spC;
    s32 sp8;
    s32 sp4;

    spC = arg0 * 0x78;
    sp8 = arg1 * 0x78;

    for (sp4 = 0; sp4 < 0x78; sp4++) {
        D_80057450[sp8 + sp4] = D_80057450[spC + sp4];
    }
}

s32 func_80025A1C(s32 arg0) {
    s32 sp2C;
    s32 sp28;
    u8 sp27;
    u16 sp24;

    if (arg0 < 4) {
        sp24 = 0x78;
    } else {
        sp24 = 0x20;
    }
    sp28 = arg0 * 0x78;
    if (func_80024D74(arg0) != 0) {
        return 1;
    }
    if ((u8) D_80057448[sp28 + sp24] != 0) {
        return 4;
    }

    if (func_80024C10(arg0) != func_80024CB4(arg0)) {
        return 2;
    }
    if (arg0 < 4) {
        for (sp2C = 0; sp2C < 0x3F; sp2C++) {
            sp27 = D_80057450[sp28 + sp2C] & 0xF;
            if ((s32) sp27 >= 7) {
                return 3;
            }
            sp27 = (u8) ((s32) (D_80057450[sp28 + sp2C] & 0xF) >> 4);
            if ((s32) sp27 >= 7) {
                return 3;
            }
        }
        if (((s32) D_80057490[sp28] >= 6) && ((s32) D_80057490[sp28] < 0xFF)) {
            return 3;
        }

        if ((s32) D_80057491[sp28] >= 3) {
            return 3;
        }

        if ((s32) D_80057492[sp28] >= 7) {
            return 3;
        }

        if ((s32) D_80057493[sp28] >= 3) {
            return 3;
        }

        if ((s32) D_8005749B[sp28] >= 0x64) {
            return 3;
        }

        if ((s32) D_8005749C[sp28] >= 9) {
            return 3;
        }

        if ((s32) D_8005749D[sp28] >= 9) {
            return 3;
        }

        if ((s32) D_8005749E[sp28] >= 4) {
            return 3;
        }

        if ((s32) D_8005749F[sp28] >= 4) {
            return 3;
        }

        if ((s32) D_800574A0[sp28] >= 0xC8) {
            return 3;
        }
    }
    return 0;
}

void func_80025D4C(s32 arg0) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp2C = arg0 * 0x78;
    if (arg0 < 4) {
        sp28 = 0x78;
    } else {
        sp28 = 0x20;
    }

    for (sp24 = 0; sp24 < sp28; sp24++) {
        D_80057450[sp2C + sp24] = 0;
    }
    func_80024E1C(arg0);
    if (arg0 < 4) {
        func_8002536C(arg0, -1, 0, 0, 0);
    }
}

void func_80025E28(void) {
    s32 sp1C;

    // Read_PlayerFile
    func_80024EA8(); // read eeprom?
    for (sp1C = 0; sp1C < 5; sp1C++) {
        if (func_80025A1C(sp1C) != 0) {
            func_80025D4C(sp1C);
        }
    }
}

void func_80025E8C(void) {
    int i;
    int j;
    int k;

    func_8005FAA0(D_80057450, D_80057450 + 0x1FF);
    D_80134808[0] = 3;
    D_80134808[1] = 2;
    D_80134808[2] = 5;
    D_80134808[3] = 4;
    D_80134808[4] = 1;
    D_80134808[5] = 3;
    D_80134808[6] = 2;
    D_80134808[7] = 4;
    D_80134808[8] = 3;
    D_80134808[9] = 2;
    D_80134808[10] = 7;
    D_80134808[11] = 0;
    D_80134808[12] = 5;
    D_80134808[13] = 3;
    func_800250A0(0);
    func_8005FAA0(D_80057450, D_80057450 + 0x1FF);
    D_80057450[0] = 0x23;
    D_80057450[1] = 0x45;
    D_80057450[2] = 0x31;
    D_80057450[3] = 0x42;
    D_80057450[4] = 0x23;
    D_80057450[5] = 7;
    D_80057450[6] = 0x35;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 7; k++) {
                D_80134808[(i * 21) + (j * 7) + k] = 0x68;
            }
        }
    }
    func_800251D4(0);
    func_8005FAA0(D_80134808, D_80134808 + 0xBA);
}
