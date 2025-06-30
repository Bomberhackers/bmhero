#include "prevent_bss_reordering.h"
#include <ultra64.h>
#include "1050.h"

// File types
typedef enum { MAIN_MENU, UNK_MENU } BACKUP_MEM_TEST_MENUS;

typedef enum { HAVE_RUMBLE_PAK, NO_RUMBLE_PAK, UNK_STATE } RUMBLE_PACK_STATES;

typedef enum { PAK_DATA_WRITE, PAK_DATA_READ, EEPROM_WRITE, EEPROM_READ } BACKUP_MEM_TEST_MENU_OPTS;

struct UnkStruct_8001EFD0 {
    OSPfs pfs;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    union {
        s32 raw;
        OSPfsState* pfs_buf[0x1]; // this is stil UB
    };
};

struct UnkStruct_8004A5F0 {
    union {
        u8 bytes[4];
        u32 raw;
    };
};

struct UnkStruct_8004A5F4 {
    int val;
    UNUSED char flags[0x18];
};

struct UnkStruct_8004A5F0 D_8004A5F0 = { 0, 0, 1, 0 }; // TODO: this doesn't make sense..

struct UnkStruct_8004A5F4 D_8004A5F4 = {
    1,
    {
        0,    1,    0,    0,    0,    0,    0x90, 0x91, 0x92, 0x93, 0x94, 0x10,
        0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0,    0,
    },
};

u8 D_8004A610[0x20] = {
    0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0xA,  0xB,  0xC,  0xD,  0xE,  0xF,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
};

s32 D_8004A630 = 0x1E;
s32 D_8004A634 = 1;
s32 D_8004A638 = 1;
s32 D_8004A63C = 0;

//.bss
extern struct UnkStruct_8001EFD0 D_80056E28[];
extern struct UnkStruct_8001EFD0 D_80056E98[];
extern struct UnkStruct_8001EFD0 D_80056E9C[];
extern struct UnkStruct_8001EFD0 D_80056EA4[];
extern s32 gNoRumblePak; //!< boolean only used in this file

#define MEMBER_ACCESS(ptr, index, member) ((struct UnkStruct_8001EFD0*) ((char*) ptr + (index * 0x84)))->member
#define ARRAY_ACCESS(ptr, index, type) ((type*) ptr + (index * 0x84))

// File functions
s32 func_8001F4B8(struct UnkStruct_8001EFD0* arg0, s32 arg1);
s32 func_8001F550(struct UnkStruct_8001EFD0* arg0, s32 arg1);
s32 func_8001F5F0(struct UnkStruct_8001EFD0* arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4);
s32 func_8001F68C(struct UnkStruct_8001EFD0* arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4);
s32 func_8001F728(struct UnkStruct_8001EFD0* arg0, s32 arg1, OSPfsState* arg2);
void func_8001FBAC(void);
void func_80020C44(void);
void* func_80020F18(void);

int GetSi_Status(void) {
    return HW_REG(SI_STATUS_REG, unsigned) & (SI_STATUS_DMA_BUSY | SI_STATUS_RD_BUSY);
}

void func_8001EED8(void) {
    u8 i;

    osContStartQuery(&gContMesgQueue);
    osRecvMesg(&gContMesgQueue, NULL, 1);
    osContGetQuery(sContStatus);
    for (i = 0; i < 4; i++) {
        if ((sContStatus[i].type & 4) && (sContStatus[i].type & 1) && (sContStatus[i].errno == 0)) {
            gControllerBits |= 1 << i;
        } else {
            gControllerBits &= ~(1 << i);
        }
    }
}

void func_8001EFD0(struct UnkStruct_8001EFD0* arg0, s32 arg1) {
    arg0[arg1].unk68 = -1;
    arg0[arg1].unk6C = -1;
    arg0[arg1].unk70 = -1;
    arg0[arg1].unk78 = -1;
    arg0[arg1].unk7C = -1;
    arg0[arg1].raw = -1;
    arg0[arg1].unk74 = -1;
}

void func_8001F088(struct UnkStruct_8001EFD0* arg0) {
    s32 sp1C;
    s32 sp18;

    for (sp1C = 0; sp1C < 4; sp1C++) {
        func_8001EFD0(arg0, sp1C);
        if ((gControllerBits >> sp1C) & 1) {
            if ((sContStatus[sp1C].type & CONT_JOYPORT) && (sContStatus[sp1C].type & CONT_ABSOLUTE)) {
                sp18 = osPfsInitPak(&gContMesgQueue, &MEMBER_ACCESS(arg0, sp1C, pfs), sp1C);
                arg0[sp1C].unk74 = sp18;
            }
        }
    }
}

void func_8001F174(struct UnkStruct_8001EFD0* arg0, s32 arg1) {
    UNUSED s32 pad;
    s32 sp18;

    if (((s32) gControllerBits >> arg1) & 1) {
        if ((sContStatus[arg1].type & CONT_JOYPORT) && (sContStatus[arg1].type & CONT_ABSOLUTE)) {
            sp18 = osPfsInitPak(&gContMesgQueue, &MEMBER_ACCESS(arg0, arg1, pfs), arg1);
            arg0[arg1].unk74 = sp18;
        }
    }
}

void func_8001F238(struct UnkStruct_8001EFD0* arg0) {
    s32 sp24;
    s32 sp20;
    u8 sp1F;

    func_8001EED8();
    osPfsIsPlug(&gContMesgQueue, &sp1F);
    for (sp24 = 0; sp24 < 4; sp24++) {
        if (((s32) sp1F >> sp24) & 1) {
            sp20 = 0;
            if (arg0[sp24].unk70 != 0) {
                func_8001F174(arg0, sp24);
            }
        } else {
            sp20 = 1;
            func_8001EFD0(arg0, sp24);
        }
        arg0[sp24].unk70 = sp20;
    }
}

s32 func_8001F328(struct UnkStruct_8001EFD0* arg0, s32 arg1, s32 arg2, OSPfsState* arg3) {
    s32 sp1C;

    return sp1C = osPfsFileState(ARRAY_ACCESS(arg0, arg1, char), arg2, arg3);
}

s32 func_8001F38C(struct UnkStruct_8001EFD0* arg0, s32 arg1) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp1C = 0;
    sp2C = osPfsFreeBlocks(((u32) arg0 + (arg1 * 0x84)), &sp28);
    if (sp2C == 0) {
        if (arg0->pfs_buf[0x64]->file_size > sp28) {
            sp1C = 1;
        }
    } else {
        sp1C = 1;
    }
    sp2C = osPfsNumFiles(((u32) arg0 + (arg1 * 0x84)), &sp24, &sp20);
    if (sp2C == 0) {
        if (sp20 == sp24) {
            sp1C = 1;
        }
    } else {
        sp1C = 1;
    }
    (arg0 + (arg1))->unk6C = sp1C;
    return sp2C;
}

s32 func_8001F4B8(struct UnkStruct_8001EFD0* arg0, s32 arg1) {
    s32 sp24;

    sp24 = osPfsFindFile(ARRAY_ACCESS(arg0, arg1, char), arg0->pfs_buf[0x64]->company_code,
                         arg0->pfs_buf[0x64]->game_code, &arg0->pfs_buf[0x64]->game_name,
                         &arg0->pfs_buf[0x64]->ext_name, &MEMBER_ACCESS(arg0, arg1, unk68));

    arg0[arg1].unk7C = sp24;
    // = 30;
    return sp24;
}

s32 func_8001F550(struct UnkStruct_8001EFD0* arg0, s32 arg1) {
    s32 sp2C;

    sp2C =
        osPfsAllocateFile(&MEMBER_ACCESS(arg0, arg1, pfs), arg0->pfs_buf[0x64]->company_code,
                          arg0->pfs_buf[0x64]->game_code, arg0->pfs_buf[0x64]->game_name, arg0->pfs_buf[0x64]->ext_name,
                          arg0->pfs_buf[0x64]->file_size, &MEMBER_ACCESS(arg0, arg1, unk68));

    arg0[arg1].unk78 = sp2C;
    return sp2C;
}

s32 func_8001F5F0(struct UnkStruct_8001EFD0* arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4) {
    s32 sp24;

    sp24 = osPfsReadWriteFile(&MEMBER_ACCESS(arg0, arg1, pfs), MEMBER_ACCESS(arg0, arg1, unk68), 1, arg2, arg3, arg4);
    arg0[arg1].raw = sp24;
    return sp24;
}

s32 func_8001F68C(struct UnkStruct_8001EFD0* arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4) {
    s32 sp24;

    sp24 =
        osPfsReadWriteFile(&MEMBER_ACCESS(arg0, arg1, pfs), MEMBER_ACCESS(arg0, arg1, unk68), '\0', arg2, arg3, arg4);
    arg0[arg1].raw = sp24;
    return sp24;
}

s32 func_8001F728(struct UnkStruct_8001EFD0* arg0, s32 arg1, OSPfsState* arg2) {
    s32 sp24;

    sp24 = osPfsDeleteFile(&MEMBER_ACCESS(arg0, arg1, pfs), arg2->company_code, arg2->game_code, (u8*) arg2->game_name,
                           (u8*) arg2->ext_name);
    return sp24;
}

s32 Eeprom_Write(OSMesgQueue* mq, u8* buf, u8 addr, u16 size) {
    s32 status = 0;

    if (osEepromProbe(mq) != 1) {
        return CONT_RANGE_ERROR;
    }

    status = osEepromLongWrite(mq, addr, buf, (int) size);
    return status;
}

s32 Eeprom_Read(OSMesgQueue* mq, u8* buf, u8 addr, u16 size) {
    s32 status = 0;

    if (osEepromProbe(mq) != 1) {
        return CONT_RANGE_ERROR;
    }
    
    status |= osEepromLongRead(mq, addr, buf, (int) size);
    return status;
}

s32 func_8001F8A0(void) {
    s32 sp1C;

    if (gRumblePakState != 0) {
        return 1;
    }
    if (GetSi_Status() != 0) {
        return 1;
    }

    sp1C = osMotorStart(&D_80056D90);
    if (sp1C != 0) {
        gRumblePakState = UNK_STATE;
        osMotorInit(&gContMesgQueue, &D_80056D90, 0);
    }
}

s32 RestartPak(void) {
    s32 sp1C;

    if (gRumblePakState != HAVE_RUMBLE_PAK) {
        return 1;
    }
    if (GetSi_Status() != 0) {
        return 1;
    }

    sp1C = osMotorStop(&D_80056D90);
    if (sp1C != 0) {
        gRumblePakState = UNK_STATE;
        osMotorInit(&gContMesgQueue, &D_80056D90, 0);
        osMotorStop(&D_80056D90);
    }
}

void Check_PakState(void) {
    if (gNoRumblePak != 0) {
        return;
    }
    if (GetSi_Status() != 0) {
        gRumblePakState = NO_RUMBLE_PAK;
    } else if (osMotorInit(&gContMesgQueue, &D_80056D90, 0) != 0) {
        gRumblePakState = NO_RUMBLE_PAK;
    } else {
        gRumblePakState = HAVE_RUMBLE_PAK;
    }
    D_80056DFC = 0;
    D_80056E00 = 0;
    D_80056E04 = 0;
    D_80056E08 = 0;
    D_80056E0C = 0;
    D_80056E10 = 0;
    D_80056E14 = 0;
    D_80056E18 = 0;
    D_80056E1C = 0;
    if (gRumblePakState == HAVE_RUMBLE_PAK) {
        RestartPak();
    }
}

void Init_Pak(void) {
    gNoRumblePak = FALSE;
    Check_PakState();
    if (gRumblePakState == HAVE_RUMBLE_PAK) {
        gNoRumblePak = FALSE;
    } else {
        gNoRumblePak = TRUE;
        gRumblePakState = NO_RUMBLE_PAK;
    }
}

s32 func_8001FB3C(s32 arg0, s32 arg1, s32 arg2) {
    if (gRumblePakState != HAVE_RUMBLE_PAK) {
        return 1;
    }
    D_80056DFC = 4;
    D_80056E00 = arg0;
    D_80056E08 = arg1;
    D_80056E10 = D_80056E08;
    D_80056E0C = arg2;
    D_80056E04 = 0;
    D_80056E14 = 0;
}

void func_8001FBAC(void) {
    if (gRumblePakState != 0) {
        if (D_80056E1C >= 0xF) {
            D_80056E1C = 0;
            Check_PakState();
        } else {
            D_80056E1C += 1;
        }
        return;
    }
    if (D_80056DFC == 0) {
        if (D_80056E18 >= 0xF) {
            RestartPak();
            D_80056E18 = 0;
        } else {
            D_80056E18 += 1;
        }
        return;
    }
    if (D_80056DFC < 4) {
        RestartPak();
        D_80056DFC -= 1;
    } else {
        if (D_80056E04 == 0) {
            if (D_80056E14 == 0) {
                D_80056E14 = 1;
                func_8001F8A0();
            }
            D_80056E10 -= 1;
            if (D_80056E10 == 0) {
                D_80056E10 = D_80056E0C;
                D_80056E04 = 1;
                D_80056E14 = 0;
            }
        } else {
            if (D_80056E14 == 0) {
                D_80056E14 = 1;
                RestartPak();
            }
            D_80056E10 -= 1;
            if (D_80056E10 == 0) {
                D_80056E10 = D_80056E08;
                D_80056E04 = 0;
                D_80056E14 = 0;
            }
        }
        D_80056E00 -= 1;
        if (D_80056E00 == 0) {
            D_80056DFC = 3;
        }
    }
}

void func_8001FDF4(void) {
    s32 sp24;
    s32 sp20;

    sp24 = 0;
    func_8001F238(D_80056E28);
    if (D_80056E98[sp24].pfs.status != 0) {
    } else {
        func_8001F174(D_80056E28, sp24);
        if (D_80056E9C[sp24].pfs.status != 0) {
        } else {
            for (sp20 = 0; sp20 < 16; sp20++) {
                D_8004A5F4.val = sp20 + 1;
                D_8004A5F0.bytes[14] = sp20 + 0x10;
                func_8001F4B8(D_80056E28, sp24);
                if (D_80056EA4[sp24].pfs.status == 5) {
                    func_8001F550(D_80056E28, sp24);
                    func_8001F4B8(D_80056E28, sp24);
                }

                if (D_80056EA4[sp24].pfs.status == 0) {
                    func_8001F5F0(D_80056E28, sp24, 0, 0x20, D_8004A610);
                }
            }
            return;
        }
    }
}

void func_8001FF80(void) {
    s32 sp24 = 0;

    D_8004A5F0.raw = 0x7B00;
    func_8001F238(D_80056E28);
    if (D_80056E98[sp24].pfs.status != 0) {
    } else {
        func_8001F174(D_80056E28, sp24);
        if (D_80056E9C[sp24].pfs.status != 0) {
        } else {
            func_8001F4B8(D_80056E28, sp24);
            if (D_80056EA4[sp24].pfs.status == 5) {
                func_8001F550(D_80056E28, sp24);
                func_8001F4B8(D_80056E28, sp24);
            }
            if (D_80056EA4[sp24].pfs.status == 0) {
                func_8001F5F0(D_80056E28, sp24, 0, 0x7B00, D_8004A610);
            }
            return;
        }
    }
}

void PakWrite(void) {
    s32 sp24;

    if (gContButtonPressed[0] & CONT_A) {
        sp24 = 0;
        if (D_80056E98[sp24].pfs.status == 0) {
            func_8001F174(D_80056E28, sp24);
            if (D_80056E9C[sp24].pfs.status == 0) {
                func_8001F4B8(D_80056E28, sp24);
                if (D_80056EA4[sp24].pfs.status == 5) {
                    func_8001F550(D_80056E28, sp24);
                    func_8001F4B8(D_80056E28, sp24);
                }
                if (D_80056EA4[sp24].pfs.status == 0) {
                    func_8001F5F0(D_80056E28, sp24, 0, 0x20, D_8004A610);
                }
            }
        }
    }
}

void PakRead(void) {
    s32 sp24;
    s32 i;

    if (gContButtonPressed[0] & CONT_A) {
        sp24 = 0;
        for (i = 0; i < 0x20; i++) {
            D_80057240[i] = 0;
        }
        if (D_80056E98[sp24].pfs.status == 0) {
            func_8001F174(D_80056E28, sp24);
            if (D_80056E9C[sp24].pfs.status == 0) {
                func_8001F4B8(D_80056E28, sp24);
                if (D_80056EA4[sp24].pfs.status == 0) {
                    func_8001F68C(D_80056E28, sp24, 0, 0x20, D_80057240);
                }
            }
        }
        i = 0;
        do { } while (++(i) < 0x20); }
}

void Write2Eeprom(void) {
    if ((gContButtonPressed[0] & CONT_A) && (Eeprom_Write(&gContMesgQueue, D_8004A610, 0, 0x200) != 0)) {}
}

void ReadEeprom(void) {
    if ((gContButtonPressed[0] & CONT_A) && (Eeprom_Read(&gContMesgQueue, D_80057240, 0, 0x200) != 0)) {}
}

void Debug_BackupMemTest_Unk(void) {
    s32 sp1C;

    if (gContDirPressed[0] & CONT_UP) {
        if (--gDebugBackMemTestItem < 0) {
            gDebugBackMemTestItem = 15;
        }
    } else if (gContDirPressed[0] & CONT_DOWN) {
        if (++gDebugBackMemTestItem >= 16) {
            gDebugBackMemTestItem = 0;
        }
    }
    if (gContButtonPressed[0] & CONT_A) {
        sp1C = 0;
        func_8001F728(D_80056E28, sp1C, D_80057040 + (gDebugBackMemTestItem));
        func_8001F328(D_80056E28, sp1C, gDebugBackMemTestItem, D_80057040 + (gDebugBackMemTestItem));
    }
}

UNUSED void Debug_BackupMemTest(void) {
    s32 i;
    UNUSED s32 pad;
    s32 sp24;

    if (gContButtonPressed[0] & CONT_START) {
        func_8001D2C0();
    }
    if (func_8001D1D4() == 1) {
        return;
    }
    if (func_8001D1D4() == 2) {
        D_80165264 = 1;
    }
    if (gContButtonPressed[0] & CONT_L) {
        if (gDebugBackupMemTestMenu == MAIN_MENU) {
            gDebugBackupMemTestMenu = UNK_MENU;
            gDebugBackMemTestItem = 0;
            sp24 = 0;
            func_8001F174(D_80056E28, sp24);
            for (i = 0; i < 16; i++) {
                func_8001F328(D_80056E28, sp24, i, D_80057040 + (i));
            }
        } else {
            gDebugBackupMemTestMenu = MAIN_MENU;
            gDebugBackMemTestItem = 0;
        }
    }
    if (gDebugBackupMemTestMenu == MAIN_MENU) {
        if (gContDirPressed[0] & CONT_UP) {
            if (--gDebugBackMemTestItem < 0) {
                gDebugBackMemTestItem = 3;
            }
        } else if (gContDirPressed[0] & CONT_DOWN) {
            if (++gDebugBackMemTestItem >= 4) {
                gDebugBackMemTestItem = 0;
            }
        }
        switch (gDebugBackMemTestItem) { /* irregular */
            case PAK_DATA_WRITE:
                PakWrite();
                break;
            case PAK_DATA_READ:
                PakRead();
                break;
            case EEPROM_WRITE:
                Write2Eeprom();
                break;
            case EEPROM_READ:
                ReadEeprom();
                break;
        }
    } else if (gDebugBackupMemTestMenu == UNK_MENU) {
        Debug_BackupMemTest_Unk();
    }
    func_8001F238(D_80056E28);
    for (i = 0; i < 4; i++) {
        if ((u32) D_80056E98[i].pfs.status == 0) {
            func_8001F38C(D_80056E28, i);
        }
    }
    func_8001994C();
}

UNUSED void Debug_BackupMemTest_Menu(void) {
    u16 perspNorm;
    s32 i;
    s32 j;

    func_8001D4D0();
    Debug_SetBg(1, 64, 64, 0);
    guPerspective(D_8016E104, &perspNorm, 50.0f, 1.3333334f, 100.0f, 4000.0f, 1.0f);
    gSPPerspNormalize(gMasterDisplayList++, perspNorm);
    guLookAt(&D_8016E104->unk00[2], gView.eye.x, gView.eye.y, gView.eye.z, gView.at.x, gView.at.y, gView.at.z,
             gView.up.x, gView.up.y, gView.up.z);
    gSPMatrix(gMasterDisplayList++, D_8016E104, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    D_8016E3A4 = 0;
    Debug_SetTextColor(255, 255, 255);
    switch (gDebugBackupMemTestMenu) { /* irregular */
        case MAIN_MENU:
            sprintf((char*) gDebugTextBuf, "BACKUP MEMORY TEST");
            debug_print_xy(32, 32);
            sprintf((char*) gDebugTextBuf, "    P  I  A  N RW  F  f");
            debug_print_xy(48, 48);
            for (i = 0; i < 4; i++) {
                sprintf((char*) gDebugTextBuf, "%dp=%2d %2d %2d %2d %2d %2d %2d", i + 1, D_80056E28[i].unk70,
                        D_80056E28[i].unk74, D_80056E28[i].unk78, D_80056E28[i].unk7C, D_80056E28[i].raw,
                        D_80056E28[i].unk6C, D_80056E28[i].unk68);

                debug_print_xy(48, (i * 16) + 64);
            }
            sprintf((char*) gDebugTextBuf, "PAK DATA WRITE");
            debug_print_xy(48, 144);
            sprintf((char*) gDebugTextBuf, "PAK DATA READ");
            debug_print_xy(48, 160);
            sprintf((char*) gDebugTextBuf, "EEPROM DATA WRITE");
            debug_print_xy(48, 176);
            sprintf((char*) gDebugTextBuf, "EEPROM DATA READ");
            debug_print_xy(48, 192);
            sprintf((char*) gDebugTextBuf, "=");
            debug_print_xy(32, (gDebugBackMemTestItem * 16) + 144);
            break;
        case UNK_MENU:
            for (i = 0; i < 16; i++) {
                for (j = 0; j < 16; j++) {
                    sprintf((char*) gDebugTextBuf, "%c", D_8005704E[i << 5][j] + 32);
                    debug_print_xy((j * 8) + 48, (i * 16) + 16);
                }
            }
            sprintf((char*) gDebugTextBuf, "=");
            debug_print_xy(32, (gDebugBackMemTestItem * 16) + 16);
            break;
    }
}

void Debug_ShockTest(void) {
    UNUSED char pad[0x8];

    if (gContButtonPressed[0] & CONT_START) {
        func_8001D2C0();
    }
    if (func_8001D1D4() == 1) {
        return;
    }
    if (func_8001D1D4() == 2) {
        D_80165264 = 1;
    }
    if (gContDirPressed[0] & CONT_UP) {
        if ((D_8004A63C--, D_8004A63C) < 0) {
            D_8004A63C = 2;
        }
    } else if (gContDirPressed[0] & CONT_DOWN) {

        if ((D_8004A63C++, D_8004A63C) >= 3) {
            D_8004A63C = 0;
        }
    }
    switch (D_8004A63C) { /* irregular */
        case 0:
            if (gContDirPressed[0] & CONT_LEFT) {
                D_8004A630 -= 1;
            } else if (gContDirPressed[0] & CONT_RIGHT) {
                D_8004A630 += 1;
            }
            break;
        case 1:
            if (gContDirPressed[0] & CONT_LEFT) {
                D_8004A634 -= 1;
            } else if (gContDirPressed[0] & CONT_RIGHT) {
                D_8004A634 += 1;
            }
            break;
        case 2:
            if (gContDirPressed[0] & CONT_LEFT) {
                D_8004A638 -= 1;
            } else if (gContDirPressed[0] & CONT_RIGHT) {
                D_8004A638 += 1;
            }
            break;
    }
    if (gContButtonPressed[0] & CONT_A) {
        func_8001FB3C(D_8004A630, D_8004A634, D_8004A638);
    }
    func_8001FBAC();
    func_8001994C();
}

void Debug_ShockTest_Menu(void) {
    u16 perspNorm;
    UNUSED char pad[0x8];

    func_8001D4D0();
    Debug_SetBg(1, 64, 64, 0);
    guPerspective(D_8016E104, &perspNorm, 50.0f, 1.3333334f, 100.0f, 4000.0f, 1.0f);
    gSPPerspNormalize(gMasterDisplayList++, perspNorm);

    guLookAt(&D_8016E104->unk00[2], gView.eye.x, gView.eye.y, gView.eye.z, gView.at.x, gView.at.y, gView.at.z,
             gView.up.x, gView.up.y, gView.up.z);
    gSPMatrix(gMasterDisplayList++, D_8016E104, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    D_8016E3A4 = 0;
    Debug_SetTextColor(255, 255, 255);
    sprintf((char*) gDebugTextBuf, "SHOCK TEST");
    debug_print_xy(32, 32);
    sprintf((char*) gDebugTextBuf, "  TOTAL TIME=%d", D_8004A630);
    debug_print_xy(32, 64);
    sprintf((char*) gDebugTextBuf, "     ON TIME=%d", D_8004A634);
    debug_print_xy(32, 80);
    sprintf((char*) gDebugTextBuf, "    OFF TIME=%d", D_8004A638);
    debug_print_xy(32, 96);
    sprintf((char*) gDebugTextBuf, "=");
    debug_print_xy(32, (D_8004A63C * 0x10) + 0x40);
}

s32 func_80021158(void) {
    func_8001ECB8();
    gDebugRoutine1 = &Debug_ShockTest_Menu;
    gDebugRoutine2 = &Debug_ShockTest;
    Check_PakState();
    Set_DecompressHeap((s32*) 0x8024C000);
    LoadFile(0, &unk_bin_0_2_ROM_START, code_extra_0_ROM_START);
    func_80019C84();
    func_80019D2C();
    func_8001A258();
    Set_BgColor(255, 255, 255, 16);
    func_8001D284();
    func_80000964();
}
