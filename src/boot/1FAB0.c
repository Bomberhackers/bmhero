#include "common.h"
#include "variables.h"

// Structs
struct UnkStruct_8001EFD0 {
    s32 unk0;
    char pad[0x64];
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
};

struct UnkStruct_8004A5F0 {
    s32 unk0;
    char pad [0xE];
    s8 unkE;
};

// External functions
extern void func_80000964(void);
extern void func_8001994C(void);
extern void func_8001D244(char arg0, char arg1, char arg2, char arg3);
extern void func_8001D4D0();
extern void func_8001D638(s32, s32, s32, s32);
extern void func_8001E954(s32*);
extern void func_8001E98C(s32, void*, void*);
extern void func_8001ECB8(void);
extern void func_80019C84(void);
extern void func_80019D2C(void);
extern void func_8001A258(void);
extern void func_8001D284(void);
extern void func_8001D2C0(void);
extern s32 func_8001D1D4(void);
extern void func_800200D8(void);
extern void func_8002021C(void);
extern void func_80020360(void);
extern void func_80020420(void);
extern void func_8001F38C(struct UnkStruct_8001EFD0*, s32);
extern void func_8005F96C(u8 arg0, u8 arg1, u8 arg2);
extern void debug_print_xy(int x, int y);

// External variables
extern struct UnkStruct_8004A5F0 D_8004A5F0;
extern s32 D_8004A5F4;
extern u8 D_8004A610;
extern s32 D_8004A630;
extern s32 D_8004A634;
extern s32 D_8004A638;
extern s32 D_8004A63C;
extern OSPfs D_80056D90;
extern s32 D_80056DF8;
extern s32 D_80056DFC;
extern s32 D_80056E00;
extern s32 D_80056E04;
extern s32 D_80056E08;
extern s32 D_80056E0C;
extern s32 D_80056E10;
extern s32 D_80056E14;
extern s32 D_80056E18;
extern s32 D_80056E1C;
extern s32 D_80056E20;
extern u8 D_80057240[];
extern u8 D_8005704E[2][1];
extern struct UnkStruct_8001EFD0 D_80056E28[];
extern struct UnkStruct_8001EFD0 D_80056E98[];
extern struct UnkStruct_8001EFD0 D_80056E9C[];
extern struct UnkStruct_8001EFD0 D_80056EA4[];
extern OSPfsState D_80057040[];
extern s8 D_80057440;
extern s8 D_80057441;

extern void* D_80165274;
extern s32 D_8016E3A4;

// File functions
void func_8001F4B8(struct UnkStruct_8001EFD0*, s32);
s32 func_8001F550(struct UnkStruct_8001EFD0* arg0, s32 arg1);
s32 func_8001F5F0(struct UnkStruct_8001EFD0*  arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4);
s32 func_8001F68C(struct UnkStruct_8001EFD0* arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4);
s32 func_8001F728(struct UnkStruct_8001EFD0* arg0, s32 arg1, OSPfsState* arg2);
s32 func_8001FB3C(s32, s32, s32);
void func_8001FBAC(void);
void func_80020C44(void);
void* func_80020F18(void);


int func_8001EEB0(void) {
    return HW_REG(SI_STATUS_REG, unsigned) & 3;
}

void func_8001EED8(void) {
    u8 sp1F;

    osContStartQuery(&gContMesgQueue);
    osRecvMesg(&gContMesgQueue, NULL, 1);
    osContGetQuery(D_80177650);
    for (sp1F = 0; sp1F < 4; sp1F++) {
        if ((D_80177650[sp1F].type & 4) && (D_80177650[sp1F].type & 1) && (D_80177650[sp1F].errno == 0)) {
            gControllerBits |= 1 << sp1F;
        } else {
            gControllerBits &= ~(1 << sp1F);
        }
    }
}


void func_8001EFD0(struct UnkStruct_8001EFD0* arg0, s32 arg1) {
    arg0[arg1].unk68 = -1;
    arg0[arg1].unk6C = -1;
    arg0[arg1].unk70 = -1;
    arg0[arg1].unk78 = -1;
    arg0[arg1].unk7C = -1;
    arg0[arg1].unk80 = -1;
    arg0[arg1].unk74 = -1;
}

#ifdef NON_MATCHING
void func_8001F088(struct UnkStruct_8001EFD0* arg0) {
    s32 sp1C;
    s32 sp18;

    for (sp1C = 0; sp1C < 4; sp1C++) {
        func_8001EFD0(arg0, sp1C);
        if ((gControllerBits >> sp1C) & 1) {
            if ((D_80177650[sp1C].type & CONT_JOYPORT) && (D_80177650[sp1C].type & CONT_ABSOLUTE)) {
                sp18 = osPfsInitPak(&gContMesgQueue, (OSPfs*)&arg0[sp1C], sp1C);
                arg0[sp1C].unk74 = sp18;
            }
        }

    } 
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F088.s")
#endif

#ifdef NON_MATCHING
void func_8001F174(struct UnkStruct_8001EFD0* arg0, s32 arg1) {
    s32 sp18;
    
    if (((s32) gControllerBits >> arg1) & 1) {
        if ((D_80177650[arg1].type & CONT_JOYPORT) && ( D_80177650[arg1].type & CONT_ABSOLUTE)) {
            sp18 = osPfsInitPak(&gContMesgQueue, (OSPfs*)arg0[arg1].unk0, arg1);
            arg0 [arg1].unk74 = sp18;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F174.s")
#endif

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

#ifdef NON_MATCHING
s32 func_8001F328(struct UnkStruct_8001EFD0* arg0, s32 arg1, s32 arg2, OSPfsState* arg3) {
    s32 ret;
     
    return ret = osPfsFileState((OSPfs*)&arg0[arg1].unk0, arg2, arg3);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F328.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F5F0.s")

#ifdef NON_MATCHING
s32 func_8001F68C(struct UnkStruct_8001EFD0* arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4) {
    s32 sp24;


    sp24 = osPfsReadWriteFile((OSPfs* ) &arg0[arg1], arg0[arg1].unk68, 0U, arg2, arg3, arg4);
    arg0[arg1].unk80 = sp24;
    return sp24;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F68C.s")
#endif

#ifdef NON_MATCHING
s32 func_8001F728(struct UnkStruct_8001EFD0* arg0, s32 arg1, OSPfsState* arg2) {
    s32 sp24;

    sp24 = osPfsDeleteFile((OSPfs* )&arg0[arg1], arg2->company_code, arg2->game_code, (u8*)arg2->game_name, (u8*)arg2->ext_name);    
    return sp24;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001F728.s")
#endif

s32 Eeprom_Write(OSMesgQueue* mq, u8* buf, u8 addr, u16 half_bytes) {
    s32 status;

    status = 0;
    if (osEepromProbe(mq) != 1) {
        return CONT_RANGE_ERROR;
    }

    status = osEepromLongWrite(mq, addr, buf, half_bytes);
    return status;
}


s32 Eeprom_Read(OSMesgQueue* mq, u8* buf, u8 addr, u16 half_bytes) {
    s32 status;

    status = 0;
    if (osEepromProbe(mq) != 1) {
        return CONT_RANGE_ERROR;
    }
    status |= osEepromLongRead(mq, addr, buf, (int)half_bytes);
    return status;
}

s32 func_8001F8A0(void) {
    s32 sp1C;

    if (D_80056DF8 != 0) {
        return 1;
    }
    if (func_8001EEB0() != 0) {
        return 1;
    }

    sp1C = osMotorStart(&D_80056D90);;
    if (sp1C != 0) {
        D_80056DF8 = 2; 
        osMotorInit(&gContMesgQueue, &D_80056D90, 0);
    }
}


s32 func_8001F938(void) {
    s32 sp1C;

    if (D_80056DF8 != 0) {
        return 1;
    }
    if (func_8001EEB0() != 0) {
        return 1;
    }

    sp1C = osMotorStop(&D_80056D90);;
    if (sp1C != 0) {
        D_80056DF8 = 2;
        osMotorInit(&gContMesgQueue, &D_80056D90, 0);
        osMotorStop(&D_80056D90);
    }
}

void func_8001F9DC(void) {
    if (D_80056E20 != 0) {
        return;
    }
    if (func_8001EEB0() != 0) {
        D_80056DF8 = 1;
    } else if (osMotorInit(&gContMesgQueue, &D_80056D90, 0) != 0) {
        D_80056DF8 = 1;
    } else {
        D_80056DF8 = 0;
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
    if (D_80056DF8 == 0) {
        func_8001F938();
    }
}

void func_8001FAD4(void) {
    D_80056E20 = 0;
    func_8001F9DC();
    if (D_80056DF8 == 0) {
        D_80056E20 = 0;
    } else {
        D_80056E20 = 1;
        D_80056DF8 = 1;
    }
}

s32 func_8001FB3C(s32 arg0, s32 arg1, s32 arg2) {
    if (D_80056DF8 != 0) {
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
    if (D_80056DF8 != 0) {
        if (D_80056E1C >= 0xF) {
            D_80056E1C = 0;
            func_8001F9DC();
        } else {
            D_80056E1C += 1;
        }
        return;
    }
    if (D_80056DFC == 0) {
        if (D_80056E18 >= 0xF) {
            func_8001F938();
            D_80056E18 = 0;
        } else {
            D_80056E18 += 1;
        }
        return;
    }
    if (D_80056DFC < 4) {
        func_8001F938();
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
                func_8001F938();
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

#ifdef NON_MATCHING
void func_8001FDF4(void) {
    s32 sp24;
    s32 sp20;
 

    sp24 = 0;
    func_8001F238(D_80056E28);
    if (D_80056E98[sp24].unk0 != 0) {

    } else {
        func_8001F174(D_80056E28, sp24);
        if (D_80056E9C[sp24].unk0 != 0) {
            
        } else {
            for (sp20 = 0; sp20 < 16; sp20++) {
                D_8004A5F4 = sp20 + 1;
                D_8004A5F0.unkE = sp20 + 0x10;
                func_8001F4B8(D_80056E28, sp24);
                if (D_80056EA4[sp24].unk0 == 5) {
                    func_8001F550(D_80056E28, sp24);
                    func_8001F4B8(D_80056E28, sp24);
                }
            
                if (D_80056EA4[sp24].unk0 == 0) {
                    func_8001F5F0(D_80056E28, sp24, 0, 0x20, &D_8004A610);
                } 
            }
            return;
        }
    }
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/boot/1FAB0/func_8001FDF4.s")
#endif

void func_8001FF80(void) {
    s32 sp24;

    sp24 = 0;
    D_8004A5F0.unk0 = 0x7B00;
    func_8001F238(D_80056E28);
    if (D_80056E98[sp24].unk0 != 0) {
    } else {
        func_8001F174(D_80056E28, sp24);
        if (D_80056E9C[sp24].unk0 != 0) {
        } else {
            func_8001F4B8(D_80056E28, sp24);
            if (D_80056EA4[sp24].unk0 == 5) {
                func_8001F550(D_80056E28, sp24);
                func_8001F4B8(D_80056E28, sp24);
            }
            if (D_80056EA4[sp24].unk0 == 0) {
                func_8001F5F0(D_80056E28, sp24, 0, 0x7B00, &D_8004A610);
            }
            return;
        }
    }
}


void func_800200D8(void) {
    s32 sp24;

    if (gContButtonPressed[0] & 0x8000) {
        sp24 = 0;
        if (D_80056E98[sp24].unk0 == 0) {
            func_8001F174(D_80056E28, sp24);
            if (D_80056E9C[sp24].unk0 == 0) {
                func_8001F4B8(D_80056E28, sp24);
                if (D_80056EA4[sp24].unk0 == 5) {
                    func_8001F550(D_80056E28, sp24);
                    func_8001F4B8(D_80056E28, sp24);
                }
                if (D_80056EA4[sp24].unk0 == 0) {
                    func_8001F5F0(D_80056E28, sp24, 0, 0x20, &D_8004A610);
                }
            }
        }
    }
}


void func_8002021C(void) {
    s32 sp24;
    s32 sp20;

    if (gContButtonPressed[0] & 0x8000) {
        sp24 = 0;
        for (sp20 = 0; sp20 < 0x20; sp20++) {
            D_80057240[sp20] = 0;
        }
        if (D_80056E98[sp24].unk0 == 0) {
            func_8001F174(D_80056E28, sp24);
            if (D_80056E9C[sp24].unk0 == 0) {
                func_8001F4B8(D_80056E28, sp24);
                if (D_80056EA4[sp24].unk0 == 0) {
                    func_8001F68C(D_80056E28, sp24, 0, 0x20, D_80057240);
                }
            }
        }
        sp20 = 0;
        do {
        } while (++(sp20) < 0x20);
    }
}


void func_80020360(void) {
    if ((gContButtonPressed[0] & 0x8000) && (Eeprom_Write(&gContMesgQueue, &D_8004A610, 0, 0x200) != 0)) {

    }
}

void func_800203C0(void) {
    if ((gContButtonPressed[0] & 0x8000) && (Eeprom_Read(&gContMesgQueue, D_80057240, 0, 0x200) != 0)) {
    }
}

void func_80020420(void) {
    s32 sp1C;

    if (gContDirPressed[0] & 0x800) {
        if ((D_80057440--, D_80057440) < 0) {
            D_80057440 = 0xF;
        }
    } else if (gContDirPressed[0] & 0x400) {
        if ((D_80057440++, D_80057440) >= 0x10) {
            D_80057440 = 0;
        }
    }
    if (gContButtonPressed[0] & 0x8000) {
        sp1C = 0;
        func_8001F728(D_80056E28, sp1C, D_80057040 + (D_80057440));
        func_8001F328(D_80056E28, sp1C, D_80057440, D_80057040 + (D_80057440));
    }
}

void func_80020550(void) {
    s32 sp2C;
    UNUSED s32 pad;
    s32 sp24;

    if (gContButtonPressed[0] & 0x1000) {
        func_8001D2C0();
    }
    if (func_8001D1D4() == 1) {
        return;
    }
    if (func_8001D1D4() == 2) {
        D_80165264 = 1;
    }
    if (gContButtonPressed[0] & 0x20) {
        if (D_80057441 == 0) {
            D_80057441 = 1;
            D_80057440 = 0;
            sp24 = 0;
            func_8001F174(D_80056E28, sp24);
            for (sp2C = 0; sp2C < 16; sp2C++) {
                func_8001F328(D_80056E28, sp24, sp2C, D_80057040 + (sp2C));
            }
        } else {
            D_80057441 = 0;
            D_80057440 = 0;
        }
    }
    if (D_80057441 == 0) {
        if (gContDirPressed[0] & 0x800) {
            if ((D_80057440--, D_80057440) < 0) {
                D_80057440 = 3;
            }
        } else if (gContDirPressed[0] & 0x400) {
         
            if ((D_80057440++, D_80057440) >= 4) {
                D_80057440 = 0;
            }
        }
        switch (D_80057440) {                       /* irregular */
        case 0:
            func_800200D8();
            break;
        case 1:
            func_8002021C();
            break;
        case 2:
            func_80020360();
            break;
        case 3:
            func_800203C0();
            break;
        }
    } else if (D_80057441 == 1) {
        func_80020420();
    }
    func_8001F238(D_80056E28);
    for (sp2C = 0; sp2C < 4; sp2C++) {
        if ((u32)D_80056E98[sp2C].unk0 == 0) {
            func_8001F38C(D_80056E28, sp2C);
        }
    }
    func_8001994C();
}

void func_80020844(void) {
    u16 sp4E;
    s32 sp48;
    s32 sp44;

    func_8001D4D0();
    func_8001D638(1, 64, 64, 0);
    guPerspective(D_8016E104, &sp4E, 50.0f, 1.3333334f, 100.0f, 4000.0f, 1.0f);
    gSPPerspNormalize(gMasterDisplayList++, sp4E);
    guLookAt(&D_8016E104->unk00[2], gView.eye.x, gView.eye.y, gView.eye.z, gView.at.x, gView.at.y, gView.at.z, gView.up.x, gView.up.y, gView.up.z);
    gSPMatrix(gMasterDisplayList++, D_8016E104, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    D_8016E3A4 = 0;
    func_8005F96C(255, 255, 255);
    switch (D_80057441) {                           /* irregular */
    case 0:
        sprintf((char*)gDebugTextBuf, "BACKUP MEMORY TEST");
        debug_print_xy(32, 32);
        sprintf((char*)gDebugTextBuf, "    P  I  A  N RW  F  f");
        debug_print_xy(48, 48);
        for (sp48 = 0; sp48 < 4; sp48++) {

            sprintf((char*)gDebugTextBuf, "%dp=%2d %2d %2d %2d %2d %2d %2d", sp48+1, 
                D_80056E28[sp48].unk70, D_80056E28[sp48].unk74, 
                D_80056E28[sp48].unk78, D_80056E28[sp48].unk7C, 
                D_80056E28[sp48].unk80,  D_80056E28[sp48].unk6C, D_80056E28[sp48].unk68);
            
            debug_print_xy(48, (sp48 * 16) + 64);
        }
        sprintf((char*)gDebugTextBuf, "PAK DATA WRITE");
        debug_print_xy(48, 144);
        sprintf((char*)gDebugTextBuf, "PAK DATA READ");
        debug_print_xy(48, 160);
        sprintf((char*)gDebugTextBuf, "EEPROM DATA WRITE");
        debug_print_xy(48, 176);
        sprintf((char*)gDebugTextBuf, "EEPROM DATA READ");
        debug_print_xy(48, 192);
        sprintf((char*)gDebugTextBuf, "=");
        debug_print_xy(32, (D_80057440 * 16) + 144);
        break;
    case 1:
        for (sp48 = 0; sp48 < 16; sp48++) {
            for (sp44 = 0; sp44 < 16; sp44++) {
                sprintf((char*)gDebugTextBuf, "%c", D_8005704E[sp48 << 5][sp44] + 32);
                debug_print_xy((sp44 * 8) + 48, (sp48 * 16) + 16);
            }
        } 
        sprintf((char*)gDebugTextBuf, "=");
        debug_print_xy(32, (D_80057440 * 16) + 16);
        break;
    }
}


void func_80020C44(void) {
    UNUSED char pad[0x8];

    if (gContButtonPressed[0] & 0x1000) {
        func_8001D2C0();
    }
    if (func_8001D1D4() == 1) {
        return;
    }
    if (func_8001D1D4() == 2) {
        D_80165264 = 1;
    }
    if (gContDirPressed[0] & 0x800) {
        if ((D_8004A63C--, D_8004A63C) < 0) {
            D_8004A63C = 2;
        }
    } else if (gContDirPressed[0] & 0x400) {

        if ((D_8004A63C++, D_8004A63C) >= 3) {
            D_8004A63C = 0;
        }
    }
    switch (D_8004A63C) {                           /* irregular */
    case 0:
        if (gContDirPressed[0] & 0x200) {
            D_8004A630 -= 1;
        } else if (gContDirPressed[0] & 0x100) {
            D_8004A630 += 1;
        }
        break;
    case 1:
        if (gContDirPressed[0] & 0x200) {
            D_8004A634 -= 1;
        } else if (gContDirPressed[0] & 0x100) {
            D_8004A634 += 1;
        }
        break;
    case 2:
        if (gContDirPressed[0] & 0x200) {
            D_8004A638 -= 1;
        } else if (gContDirPressed[0] & 0x100) {
            D_8004A638 += 1;
        }
        break;
    }
    if (gContButtonPressed[0] & 0x8000) {
        func_8001FB3C(D_8004A630, D_8004A634, D_8004A638);
    }
    func_8001FBAC();
    func_8001994C();
}

void* func_80020F18(void) {
    u16 sp46;
    UNUSED char pad[0x8];


    func_8001D4D0();
    func_8001D638(1, 64, 64, 0);
    guPerspective(D_8016E104, &sp46, 50.0f, 1.3333334f, 100.0f, 4000.0f, 1.0f);
    gSPPerspNormalize(gMasterDisplayList++, sp46);

    guLookAt(&D_8016E104->unk00[2], gView.eye.x, gView.eye.y, gView.eye.z, gView.at.x, gView.at.y, gView.at.z, gView.up.x, gView.up.y, gView.up.z);
    gSPMatrix(gMasterDisplayList++, D_8016E104, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    D_8016E3A4 = 0;
    func_8005F96C(255, 255, 255);
    sprintf((char*)gDebugTextBuf, "SHOCK TEST");
    debug_print_xy(32, 32);
    sprintf((char*)gDebugTextBuf, "  TOTAL TIME=%d", D_8004A630);
    debug_print_xy(32, 64);
    sprintf((char*)gDebugTextBuf, "     ON TIME=%d", D_8004A634);
    debug_print_xy(32, 80);
    sprintf((char*)gDebugTextBuf, "    OFF TIME=%d", D_8004A638);
    debug_print_xy(32, 96);
    sprintf((char*)gDebugTextBuf, "=");
    debug_print_xy(32, (D_8004A63C * 0x10) + 0x40);
}

s32 func_80021158(void) {
    func_8001ECB8();
    D_8016526C = &func_80020F18;
    D_80165274 = &func_80020C44;
    func_8001F9DC();
    func_8001E954((s32*)0x8024C000);
    func_8001E98C(0, &unk_bin_0_2_ROM_START, code_extra_0_ROM_START);
    func_80019C84();
    func_80019D2C();
    func_8001A258();
    func_8001D244(255, 255, 255, 16);
    func_8001D284();
    func_80000964();
}

