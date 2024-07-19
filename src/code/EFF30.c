#include "common.h"
#include "variables.h"

//STRUCTS

struct UnkStruct80177778 {
    char filler0[0x18];
    s16 unk18;
};

//FUNCTIONS
extern void func_80000964();                                  /* extern */
extern void func_80019C84();                                  /* extern */
extern void func_80019D2C();                                  /* extern */
extern void func_8001A258();                                  /* extern */
extern void func_8001D244(s32, s32, s32, s32);                        /* extern */
extern void func_8001D284();                                  /* extern */
extern void func_8001ECB8();                                  /* extern */
extern void func_800FE854();                                  /* extern */
extern void func_8005F96C(u8, u8, u8);                           /* extern */
extern void func_8001E954(s32*);                                 /* extern */
extern void func_8001E98C(s32, s32*, s32*);                         /* extern */
extern void func_800175F0(s32, s32, s32, s32, s32);                 /* extern */
extern void func_8001994C();                                  /* extern */
extern s32 func_8001D1D4();                                /* extern */
extern void func_8001D2C0();                                  /* extern */
extern void func_8001D4D0();                               /* extern */
extern void func_8001D638(s32, s32, s32, s32);             /* extern */
extern void func_8005E6A0(s32, s32);                              /* extern */
extern void func_80065AEC(f32, f32, f32, s32*, s32*, s32*);
void func_800FDD48();                                  /* extern */
void func_800FDA10();                                  /* extern */
s32 func_800FDF98();                                /* extern */
void func_8005FA90();                                  /* extern */
void func_800FE9BC();                                  /* extern */
void func_800FEB6C();                                  /* extern */
void func_800FEE34();                                  /* extern */
void func_800FEFA0();                                  /* extern */
void func_800FF43C();                                  /* extern */
void func_800FF88C();                                  /* extern */
void func_800FFD30();                                  /* extern */
void func_800FFF40();                                  /* extern */

//RAM ADDRESSES
extern u16* D_80134784[2];
extern s8 D_80134334;
extern s8 D_80134340;
extern s8 D_8013435C;
extern s8 D_80134378;
extern s8 D_8013438C;
extern s8 D_801343A4;
extern s8 D_801343BC;
extern s8 D_801343CC;
extern s8 D_801343DC;
extern s8 D_801343F0;
extern s8 gBombCount;
extern s8 gFireCount;
extern u8 D_80177974;
extern s16 D_8016E3F4;
extern s16 D_80134730;
extern s16 D_80134734;
extern s16 D_80134738[];
extern s32 gDebugCurrentMenuItem;
extern s32 gDebugSelectedMusicIndex;
extern s32 gDebugSelectedSoundIndex;

extern s32 D_8016E244;
extern s32 D_801765F4;
extern u8 D_8017793A;
extern u8 D_8017793E;
extern u8 D_80177940;
extern s16 D_80177944;
extern s16 D_80177948;
extern f32 D_801779C8;
extern s32 D_80134218;
extern s32 D_80134FD0;
extern struct LightingStruct gLightingSettings[];

extern s16 D_80134C14;

extern u8 D_80177932;
extern u8 D_80177934;
extern u8 D_80177938;

extern s32 D_8016E3A4;
extern Gfx* gMasterDisplayList;

extern void* D_80165274;

extern u8 D_801651A8;
extern s32 D_801651AC;
extern s32 D_801651B0;
extern s32 D_801651B4;
extern s32 D_801651B8;
extern s32 D_801651BC;
extern f32 D_801651C0;

extern struct UnkStructSTCG* D_8017753C;
extern struct UnkStruct80177778* D_80177778;
extern struct LevelInfo *gLevelInfo[4];

//ROM ADDRESSES
extern u8 unk_bin_0_2_ROM_START[];
extern u8 code_extra_0_ROM_START[];

void func_800FDA10(void) {
    f32 sp4;

    if (gContCurrButton[0] & 2) {
        sp4 = (f32) ((f64) gView.rot.y + 2.0);
        gView.rot.y = sp4 - (f32) (((s32) sp4 / 360) * 360);
    }
    if (gContCurrButton[0] & 1) {
        sp4 = (f32) ((f64) gView.rot.y + 358.0);
        gView.rot.y = sp4 - (f32) (((s32) sp4 / 360) * 360);
    }
    if (gContCurrButton[0] & 8) {
        sp4 = (f32) ((f64) gView.rot.x + 2.0);
        gView.rot.x = sp4 - (f32) (((s32) sp4 / 360) * 360);
    }
    if (gContCurrButton[0] & 4) {
        sp4 = (f32) ((f64) gView.rot.x + 358.0);
        gView.rot.x = sp4 - (f32) (((s32) sp4 / 360) * 360);
    }
    if (gContCurrButton[0] & 0x400) {
        gView.dist += 10.0f;
    }
    if (gContCurrButton[0] & 0x800) {
        gView.dist -= 10.0f;
        if (gView.dist < 200.0f) {
            gView.dist = 200.0f;
        }
    }
}

void func_800FDD48(void) {
    func_8005F96C(0xFFU, 0xFFU, 0xFFU);
    sprintf(&gDebugTextBuf, "%8d", D_8016E244);
    debug_print_xy((s8* )0xD0, (s8* )0xD8);
    sprintf(&gDebugTextBuf, "[BOMBERMAN ACTION MENU]");
    debug_print_xy((s8* )0x20, (s8* )0x10);
    sprintf(&gDebugTextBuf, "   GAME START = %d", gDebugSaveIndex);
    debug_print_xy((s8* )0x20, (s8* )0x20);
    sprintf(&gDebugTextBuf, "   MAP NUMBER  = 0x%X", gCurrentLevel);
    debug_print_xy((s8* )0x20, (s8* )0x30);
    sprintf(&gDebugTextBuf, "   MAP TEST    = 0x%X", gCurrentLevel);
    debug_print_xy((s8* )0x20, (s8* )0x40);
    sprintf(&gDebugTextBuf, "   CAMERA TYPE = %d", gCameraType);
    debug_print_xy((s8* )0x20, (s8* )0x50);
    sprintf(&gDebugTextBuf, "   TITLE TEST");
    debug_print_xy((s8* )0x20, (s8* )0x60);
    sprintf(&gDebugTextBuf, "   ENTRY EDIT = 0x%X", gCurrentLevel);
    debug_print_xy((s8* )0x20, (s8* )0x70);
    sprintf(&gDebugTextBuf, "   MUSIC NUMBER = %d", gDebugSelectedMusicIndex);
    debug_print_xy((s8* )0x20, (s8* )0x80);
    sprintf(&gDebugTextBuf, "   SOUND NUMBER = %d", gDebugSelectedSoundIndex);
    debug_print_xy((s8* )0x20, (s8* )0x90);
    sprintf(&gDebugTextBuf, "   DEMO = %d", gDebugSelectedDemoIndex);
    debug_print_xy((s8* )0x20, (s8* )0xA0);
    sprintf(&gDebugTextBuf, "   SHOCK TEST");
    debug_print_xy((s8* )0x20, (s8* )0xB0);
    sprintf(&gDebugTextBuf, "=");
    debug_print_xy((s8* )0x28, (gDebugCurrentMenuItem * 0x10) + 0x20);
    sprintf(&gDebugTextBuf, "MASTER ----- DEBUG");
    debug_print_xy((s8* )0x98, (s8* )0xC0);
    func_8005FA90();
}

s32 func_800FDF98(void) {
    s32 sp4;
    s32 var_t9;

    if (D_80134218 != 0) {
        D_80134218 -= 1;
    }
    sp4 = 0;
    if (D_80134218 == 0) {
        if (gContDirPressed[0] & 0x100) {
            D_80134218 = 0xF;
            sp4 = 1;
        } else {
            if (gContDirPressed[0] & 0x200) {
                D_80134218 = 0xF;
                sp4 = -1;
            }
            else if (gContDirPressed[0] & 0x800) {
                D_80134218 = 0xF;
                sp4 = 2;
            } 
            else if (gContDirPressed[0] & 0x400) {
                D_80134218 = 0xF;
                sp4 = -2;
            }
        }
    } else if (gContCurrDir[0] & 0x100) {
        if (D_80134218 == 1) {
            sp4 = 1;
            D_80134218 = 2;
        }
    } else if (gContCurrDir[0] & 0x200) {
        if (D_80134218 == 1) {
            sp4 = -1;
            D_80134218 = 2;
        }
    } else if (gContCurrDir[0] & 0x800) {
        if (D_80134218 == 1) {
            sp4 = 2;
            D_80134218 = 2;
        }
    } else if (gContCurrDir[0] & 0x400) {
        if (D_80134218 == 1) {
            sp4 = -2;
            D_80134218 = 2;
        }
    } else {
        D_80134218 = 0;
    }
    return sp4;
}

void func_800FE204(void) {
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;

    if (gContButtonPressed[0] & 0x8000) {
        switch(gDebugCurrentMenuItem)
        {
            case 6:
            {
                if (gDebugSelectedMusicIndex != 0) {
                    PlayTrack_WithVolLoop(gDebugSelectedMusicIndex, -1, 0);
                } else {
                    PlayTrack_WithVolLoop(-1, -1, 0);
                }            
                break;
            }
            case 7:
            {
                func_800175F0(-1, 0, gDebugSelectedSoundIndex, -1, 0);
                break;
            }
            default:
            {
                func_8001D2C0();
                D_80134FD0 = gDebugCurrentMenuItem;
                break;
            }
        }
    }
    if (func_8001D1D4() == 1) 
    {
        return;
    }
    if (func_8001D1D4() == 2) 
    {
        D_80165264 = 1;
    }
    sp30 = func_800FDF98();
    if (sp30 == 2) {
        if (--gDebugCurrentMenuItem < 0) {
            gDebugCurrentMenuItem = 9;
        }
    }   
    if (sp30 == -2) {
        if (++gDebugCurrentMenuItem >= 0xA) {
            gDebugCurrentMenuItem = 0;
        }
    }
    switch(gDebugCurrentMenuItem)
    {
        case 0:
        {
            if (sp30 == 1) {
                if (++gDebugSaveIndex >= 8) {
                    gDebugSaveIndex = 0;
                }
            } else if (sp30 == -1) {
                if (--gDebugSaveIndex < 0) {
                    gDebugSaveIndex = 7;
                }
            }
            break;
        }
        case 1:
        case 2:
        case 5:
        {
            if (sp30 == 1) {
                if (++gCurrentLevel >= 0xC0) 
                {
                    gCurrentLevel = 0;
                }
            } 
            else if (sp30 == -1) {
                if (--gCurrentLevel < 0) 
                {
                    gCurrentLevel = 0xBF;
                }
            }
            break;
        }
        case 3:
        {
            if (sp30 == 1) 
            {
                if (++gCameraType >= 0xB) 
                {
                    gCameraType = 0;
                }
            } else if (sp30 == -1) 
            {
                if (--gCameraType < 0) {
                    gCameraType = 0xA;
                }
            }
            break;
        }
        case 6:
        {
            if (sp30 == 1) {
                if (++gDebugSelectedMusicIndex >= 0x101) {
                    gDebugSelectedMusicIndex = 0;
                }
            } else if (sp30 == -1) {
                if (--gDebugSelectedMusicIndex < 0) {
                    gDebugSelectedMusicIndex = 0x100;
                }
            }
            break;                    
        }
    case 7:
    {
        if (sp30 == 1) {
            if (++gDebugSelectedSoundIndex >= 0x101) {
                gDebugSelectedSoundIndex = 0;
            }
        } else if (sp30 == -1) {
            if (--gDebugSelectedSoundIndex < 0) {
                gDebugSelectedSoundIndex = 0x100;
            }
        }
        break;            
    }
    case 8:
        {                
            if (sp30 == 1) {
                if (++gDebugSelectedDemoIndex >= 0xA) {
                    gDebugSelectedDemoIndex = 0;
                }
            } else if (sp30 == -1) {
                if (--gDebugSelectedDemoIndex < 0) {
                    gDebugSelectedDemoIndex = 9;
                }
            }
        break;
        }
    }    
    func_800FDA10();
    func_8001994C();
}

void func_800FE6D8(void) {
    u16 sp3E;


    func_8001D4D0();
    func_8001D638(1, 0x40, 0x40, 0);
    guPerspective(D_8016E104, &sp3E, 50.0f, 1.3333334f, 100.0f, 4000.0f, 1.0f);
    gSPPerspNormalize(gMasterDisplayList++, (s32) sp3E);
    guLookAt(&D_8016E104->unk00[2], gView.eye.x, gView.eye.y, gView.eye.z, gView.at.x, gView.at.y, gView.at.z, gView.up.x, gView.up.y, gView.up.z);
    gSPMatrix(gMasterDisplayList++, D_8016E104, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    D_8016E3A4 = 0;
    func_800FDD48();
    func_8005E6A0(0x2E, 0xD0);
}


void func_800FE854(void) {
    func_8001E954(0x8024C000);
    func_8001E98C(0, unk_bin_0_2_ROM_START, code_extra_0_ROM_START);
}

u32 func_800FE898(void) {
    s32 sp20;
    func_8001ECB8();
    D_8016526C = &func_800FE6D8;
    D_80165274 = &func_800FE204;
    gDebugSaveIndex = 0;
    func_800FE854();
    gView.at.x = 0.0f;
    gView.at.y = 0.0f;
    gView.at.z = 0.0f;
    gView.rot.x = 0.0f;
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 800.0f;
    func_80019C84();
    func_80019D2C();
    func_8001A258();
    func_8001D244(0xFF, 0xFF, 0xFF, 0x10);
    func_8001D284();
    func_80000964();
    return (u32) D_80134FD0;
}

void func_800FE9BC(void) {
    sprintf(&gDebugTextBuf, "[MAIN MENU]");
    debug_print_xy(0x20, 0x10);
    sprintf(&gDebugTextBuf, "   TIMER BAR ON/OFF = %d", gDebugShowTimerBar);
    debug_print_xy(0x20, 0x20);
    sprintf(&gDebugTextBuf, "   DEBUG DISPLAY MODE = %d", gDebugDisplayMode);
    debug_print_xy(0x20, 0x30);
    sprintf(&gDebugTextBuf, "   NO DAMAGE = %d", gDebugInvincibileFlag);
    debug_print_xy(0x20, 0x40);
    sprintf(&gDebugTextBuf, "   NO ATTRIBUTE = %d", gDebugAtrributeFlag);
    debug_print_xy(0x20, 0x50);
    sprintf(&gDebugTextBuf, "   G BUTTON DEBUG = %d", gGoldBomber);
    debug_print_xy(0x20, 0x60);
    sprintf(&gDebugTextBuf, "   BOM  = %d", gBombCount);
    debug_print_xy(0x20, 0x70);
    sprintf(&gDebugTextBuf, "   FIRE = %d", gFireCount);
    debug_print_xy(0x20, 0x80);
    sprintf(&gDebugTextBuf, "   DISPTYPE = %d", D_80177974);
    debug_print_xy(0x20, 0x90);
    sprintf(&gDebugTextBuf, "=");
    debug_print_xy(0x28, (D_8016E3F4 * 0x10) + 0x20);
}

void func_800FEB6C(void) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    sprintf(&gDebugTextBuf, "[LIGHT EDIT]");
    debug_print_xy((s8* )0x20, (s8* )0x10);
    sprintf(&gDebugTextBuf, "   AMBIENT R = %d", (u8)gLightingSettings[0].AmbientLight.LightData[0]);
    debug_print_xy((s8* )0x20, (s8* )0x20);
    sprintf(&gDebugTextBuf, "   AMBIENT G = %d", gLightingSettings[0].AmbientLight.LightData[1]);
    debug_print_xy((s8* )0x20, (s8* )0x30);
    sprintf(&gDebugTextBuf, "   AMBIENT B = %d", gLightingSettings[0].AmbientLight.LightData[2]);
    debug_print_xy((s8* )0x20, (s8* )0x40);
    sprintf(&gDebugTextBuf, "   DIFFUSE R = %d", gLightingSettings[0].DiffuseLight.LightData[0]);
    debug_print_xy((s8* )0x20, (s8* )0x50);
    sprintf(&gDebugTextBuf, "   DIFFUSE G = %d", gLightingSettings[0].DiffuseLight.LightData[1]);
    debug_print_xy((s8* )0x20, (s8* )0x60);
    sprintf(&gDebugTextBuf, "   DIFFUSE B = %d", gLightingSettings[0].DiffuseLight.LightData[2]);
    debug_print_xy((s8* )0x20, (s8* )0x70);
    sprintf(&gDebugTextBuf, "   DIR     X = %d", gLightingSettings[0].Direction[0]);
    debug_print_xy((s8* )0x20, (s8* )0x80);
    sprintf(&gDebugTextBuf, "   DIR     Y = %d", gLightingSettings[0].Direction[1]);
    debug_print_xy((s8* )0x20, (s8* )0x90);
    sprintf(&gDebugTextBuf, "   DIR     Z = %d", gLightingSettings[0].Direction[2]);
    debug_print_xy((s8* )0x20, (s8* )0xA0);
    sp24 = (f32) gLightingSettings[0].Direction[0];
    sp20 = (f32) gLightingSettings[0].Direction[1];
    sp1C = (f32) gLightingSettings[0].Direction[2];
    sp18 = sqrtf((sp24 * sp24) + (sp20 * sp20) + (sp1C * sp1C));
    sprintf(&gDebugTextBuf, "   DIR TOTAL = %d", (s32) sp18);
    debug_print_xy((s8* )0x20, (s8* )0xB0);
    sprintf(&gDebugTextBuf, "=");
    debug_print_xy((s8* )0x28, (D_8016E3F4 * 0x10) + 0x20);
}


void func_800FEE34(void) {
    sprintf(&gDebugTextBuf, "[FOG EDIT]");
    debug_print_xy((s8* )0x20, (s8* )0x10);
    sprintf(&gDebugTextBuf, "   FOG R    = %d", D_8017793A);
    debug_print_xy((s8* )0x20, (s8* )0x20);
    sprintf(&gDebugTextBuf, "   FOG G    = %d", D_8017793E);
    debug_print_xy((s8* )0x20, (s8* )0x30);
    sprintf(&gDebugTextBuf, "   FOG B    = %d", D_80177940);
    debug_print_xy((s8* )0x20, (s8* )0x40);
    sprintf(&gDebugTextBuf, "   DIR MINI = %d", D_80177944);
    debug_print_xy((s8* )0x20, (s8* )0x50);
    sprintf(&gDebugTextBuf, "   DIR MAX  = %d", D_80177948);
    debug_print_xy((s8* )0x20, (s8* )0x60);
    sprintf(&gDebugTextBuf, "   ZFAR     = %f", (f64) D_801779C8);
    debug_print_xy((s8* )0x20, (s8* )0x70);
    sprintf(&gDebugTextBuf, "=");
    debug_print_xy((s8* )0x28, (D_8016E3F4 * 0x10) + 0x20);
}

//TODO: redecomp due, some struct info here feels weird
void func_800FEFA0(void) {
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;

    sprintf(&gDebugTextBuf, "(%d %d %d) ST=%d CG=%d %d",
            (s32)D_8017753C->Unk0, (s32)D_8017753C->Unk4, (s32) D_8017753C->Unk8,
            D_8017753C->UnkA4, D_80165290[gPlayerData[0].Unk140[0]].unk14,
            D_8017753C->Unk108
        );
    debug_print_xy((s8*)0x20, (s8*)0x10);
    sp54 = (s32)D_8017753C->Unk0 / 60;
    sp4C = (s32)D_8017753C->Unk0 % 60;

    if((sp4C < 0 ? -sp4C : sp4C) >= 0x1E)
    {
        if (sp4C >= 0) {
            sp54 += 1;
        } else {
            sp54 -= 1;
        }
    }

    sp54 *= 0x3C;
    sp50 = (s32) D_8017753C->Unk8 / 60;
    sp48 = (s32) D_8017753C->Unk8 % 60;

    if ((sp48 < 0 ? -sp48 : sp48) >= 0x1E) {
        if (sp48 >= 0) {
            sp50 += 1;
        } else {
            sp50 -= 1;
        }
    }

    sp50 *= 0x3C;
    sprintf(&gDebugTextBuf, "(%d %d %d) R=%d GB=%d", sp54, (s32) D_8017753C->Unk4, sp50, (s32) (u8) D_8016E414, (s32) (u16) D_8016E41C);
    debug_print_xy((s8* )0x20, (s8* )0x20);
    func_80065AEC(gPlayerData[0].Pos.x, gPlayerData[0].Pos.y, gPlayerData[0].Pos.z, &sp40, &sp3C, &sp38);
    sp44 = (D_80177778->unk18 * sp38) + sp40;
    sprintf(&gDebugTextBuf, "[MAP INDEX=%d FLOOR=%d]", sp44, sp3C + 1);
    debug_print_xy((s8* )0x20, (s8* )0x30);
    sprintf(&gDebugTextBuf, "STAGE=%d AREA=%d MAP=%d CLEAR=%d (%02X)", gLevelInfo[(gCurrentLevel)]->Stage, 
        gLevelInfo[(gCurrentLevel)]->Area, gLevelInfo[(gCurrentLevel)]->Map, gLevelInfo[(gCurrentLevel)]->Clear, gCurrentLevel);
    debug_print_xy((s8* )0x20, (s8* )0x40);
    sprintf(&gDebugTextBuf, "prm=%d ny=%d y=%f", D_801651A8, D_801651BC, (f64) D_801651C0);
    debug_print_xy((s8* )0x20, (s8* )0x50);
    sprintf(&gDebugTextBuf, "a=%d b=%d c=%d d=%d", D_801651AC, D_801651B0, D_801651B4, D_801651B8);
    debug_print_xy((s8* )0x20, (s8* )0x60);
}

void func_800FF43C(void) {
    sprintf(&gDebugTextBuf, "PLAY.POS X=%5d Y=%5d Z=%5d", (s32) gPlayerData[0].Pos.x, (s32) gPlayerData[0].Pos.y, (s32) gPlayerData[0].Pos.z);
    debug_print_xy((s8* )0x20, (s8* )0x10);
    sprintf(&gDebugTextBuf, "PLAY.ROT X=%5d Y=%5d Z=%5d", (s32) gPlayerData[0].Rot.x, (s32) gPlayerData[0].Rot.y, (s32) gPlayerData[0].Rot.z);
    debug_print_xy((s8* )0x20, (s8* )0x20);
    sprintf(&gDebugTextBuf, "VIEW.AT  X=%5d Y=%5d Z=%5d", (s32) gView.at.x, (s32) gView.at.y, (s32) gView.at.z);
    debug_print_xy((s8* )0x20, (s8* )0x30);
    sprintf(&gDebugTextBuf, "VIEW.EYE X=%5d Y=%5d Z=%5d", (s32) gView.eye.x, (s32) gView.eye.y, (s32) gView.eye.z);
    debug_print_xy((s8* )0x20, (s8* )0x40);
    sprintf(&gDebugTextBuf, "VIEW.ROT X=%5d Y=%5d Z=%5d", (s32) gView.rot.x, (s32) gView.rot.y, (s32) gView.rot.z);
    debug_print_xy((s8* )0x20, (s8* )0x50);
    sprintf(&gDebugTextBuf, "VIEW.DIST =%5d", (s32) gView.dist);
    debug_print_xy((s8* )0x20, (s8* )0x60);
    sprintf(&gDebugTextBuf, "FRWAIT =%5d", D_80134C14);
    debug_print_xy((s8* )0x20, (s8* )0x70);
}

void func_800FF7B4(void) {
    func_8005F96C(0xFF, 0xFF, 0xFF);
    switch (D_8016E3EC) {
        case 0x1:
            func_800FEFA0();
            break;
        case 0x2:
            func_800FF43C();
            break;
        case 0x64:
            func_800FE9BC();
            break;
        case 0x65:
            func_800FEB6C();
            break;
        case 0x66:
            func_800FEE34();
            break;
    }
    func_8005FA90();
}

void func_800FF88C(void) {

    if (gContDirPressed[0] & 0x800) {
        if (--D_8016E3F4 < 0) {
            D_8016E3F4 = 7;
        }
    }
    if (gContDirPressed[0] & 0x400) {
        if (++D_8016E3F4 >= 8) {
            D_8016E3F4 = 0;
        }
    }
    switch (D_8016E3F4) {
        case 0:
            {
                if (gContDirPressed[0] & 0x200) {
                    if (--gDebugShowTimerBar < 0) {
                        gDebugShowTimerBar = 1;
                    }
                }
                if (gContDirPressed[0] & 0x100) {
                    if (++gDebugShowTimerBar >= 2) {
                        gDebugShowTimerBar = 0;
                    }
                }
                break;                
            }
        case 1:
            {
                if (gContDirPressed[0] & 0x200) {
                    if (--gDebugDisplayMode < 0) {
                        gDebugDisplayMode = 2;
                    }
                }
                if (gContDirPressed[0] & 0x100) {
                    if (++gDebugDisplayMode >= 3) {
                        gDebugDisplayMode = 0;
                    }
                }
                break;                
            }
        case 2:
            {
                if ((gActiveContDirPressed & 0x200) || (gActiveContDirPressed & 0x100)) {
                    gDebugInvincibileFlag ^= 1;
                }
                break;                
            }
        case 3:
            {
                if ((gActiveContDirPressed & 0x200) || (gActiveContDirPressed & 0x100)) {
                    gDebugAtrributeFlag ^= 1;
                }                
                break;
            }
        case 4:
            {
                if ((gActiveContDirPressed & 0x200) || (gActiveContDirPressed & 0x100)) {
                    gGoldBomber ^= 1;
                }
                break;                
            }
        case 5:
            {
                if (gContDirPressed[0] & 0x200) {
                    if (--gBombCount < 0) {
                        gBombCount = 3;
                    }
                }
                if (gContDirPressed[0] & 0x100) {
                    if (++gBombCount >= 4) {
                        gBombCount = 0;
                    }
                }
                break;                
            }
        case 6:
            {
                if (gContDirPressed[0] & 0x200) {
                    if (--gFireCount < 0) {
                        gFireCount = 3;
                    }
                }
                if (gContDirPressed[0] & 0x100) {
                    if (++gFireCount >= 4) {
                        gFireCount = 0;
                    }
                }
                break;                
            }
        case 7:
            {
                if (gContDirPressed[0] & 0x200) {
                    if ((--D_80177974) == 0xFF) {
                        D_80177974 = 0x1E;
                    }
                }
                if (gContDirPressed[0] & 0x100) {
                    if ((++D_80177974) >= 0x1F) {
                        D_80177974 = 0;
                    }
                }                
            }
        break;
    }
}

void func_800FFD30(void) {
    s32 sp1C;
    s32 sp18;

    sp1C = func_800FDF98();
    if (sp1C == 2) {
        if (--D_8016E3F4 < 0) {
            D_8016E3F4 = 8;
        }
    } else if (sp1C == -2) {
        if (++D_8016E3F4 >= 9) {
            D_8016E3F4 = 0;
        }
    }
    if ((sp1C == 1) || (sp1C == -1)) {
        switch (D_8016E3F4) {
        case 0:
        case 1:
        case 2:
            sp18 = (s32) D_8016E3F4;
            gLightingSettings[0].AmbientLight.LightData[sp18] += sp1C;
            gLightingSettings[0].AmbientLight.LightData[sp18 + 4] = gLightingSettings[0].AmbientLight.LightData[sp18];
            break;
        case 3:
        case 4:
        case 5:
            sp18 = D_8016E3F4 - 3; // - 3 so we index back to 0-2
            gLightingSettings[0].DiffuseLight.LightData[sp18] += sp1C;
            gLightingSettings[0].DiffuseLight.LightData[sp18 + 4] = gLightingSettings[0].DiffuseLight.LightData[sp18];
            break;
        case 6:
        case 7:
        case 8:
            sp18 = D_8016E3F4 - 6; // - 6 so we index back to 0-2
            gLightingSettings[0].Direction[sp18] += sp1C;
            gLightingSettings[0].Direction[sp18 + 0x10] = gLightingSettings[0].Direction[sp18];
            break;
        }
    }
}

void func_800FFF40(void) {
    s32 sp1C;

    sp1C = func_800FDF98();
    if (sp1C == 2) {
        if (--D_8016E3F4 < 0) {
            D_8016E3F4 = 5;
        }
    } else if (sp1C == -2) {
        if (++D_8016E3F4 >= 6) {
            D_8016E3F4 = 0;
        }
    }
    if ((sp1C == 1) || (sp1C == -1)) {
        switch (D_8016E3F4) {
        case 0:
            D_8017793A += sp1C;
            D_80177932 = D_8017793A;
            break;
        case 1:
            D_8017793E += sp1C;
            D_80177934 = D_8017793E;
            break;
        case 2:
            D_80177940 += sp1C;
            D_80177938 = D_80177940;
            break;
        case 3:
            D_80177944 += sp1C;
            break;
        case 4:
            D_80177948 += sp1C;
            break;
        case 5:
            D_801779C8 = D_801779C8 + (sp1C * 0x64);
            break;
        }
    }
}

void func_80100148(void) {
    if (gActiveContPressed & 0x1000) {
        D_8016E3EE = 0;
        D_8016E3EC = gDebugDisplayMode;
        D_801765F4 = 0;
        return;
    }
    if (gActiveContPressed & 0x20) {
        D_8016E3EC += 1;
        D_8016E3F4 = 0;
        if (D_8016E3EC == 0x67) {
            D_8016E3EC = 0x64;
        }
    }
    if (D_8016E3EC == 0x64) {
        func_800FF88C();
    } else if (D_8016E3EC == 0x65) {
        func_800FFD30();
    } else if (D_8016E3EC == 0x66) {
        func_800FFF40();
    }
}

void func_80100260(void) {
    s16 i;

    D_80134734 = 0;
    D_80134730 = 0;
    for(i = 0; i < 2; i++)
    {
        D_80134738[i] = 0;
    }
}

s32 func_801002BC(void) {
    s16 sp6;
    s16 sp4;

    if(gContButtonPressed[0] != 0) {
        for (sp6 = 0; sp6 < 2; sp6++) {
            if (!D_80134738[sp6]) {
                if ((gContButtonPressed[0] & D_80134784[sp6][D_80134734]) ==  D_80134784[sp6][D_80134734]) {
                    if (D_80134784[sp6][D_80134734 + 1] == 1) {
                        D_80134734 = 0;
                        for (sp4 = 0; sp4 < 2; sp4++) {
                            D_80134738[sp4] = 0;
                        }
                        return (sp6 + 2) & 0xFF;
                    } else {                    
                    D_80134730 = 0;
                    }
                } else {
                    D_80134738[sp6] = 1;
                }
            }
        }
        for (sp6 = 0; sp6 < 2; sp6++) {
            if (D_80134738[sp6] == 0) {
                D_80134734 += 2;
                return 1;
            }      
        }
    } else {
        if (D_80134730 < 0x1E) {
            D_80134730 += 1;
        } else {
            D_80134734 = 0;
            D_80134730 = 0;
            for (sp6 = 0; sp6 < 2; sp6++) {
                D_80134738[sp6] = 0;
            }
            return 0;            
        }   
    }
    return 1;
}