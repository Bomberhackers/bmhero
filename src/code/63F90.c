#include "common.h"
#include "63F90.h"

// .bss
extern f32 D_80177680;
extern f32 D_801776A8;
extern f32 D_801776C8;
extern f32 D_801776D0;
extern u8 D_801776D8;
extern u8 D_801776DC;
extern s8 D_801775EF;
extern u8 D_80177920;
extern s32 D_8017763C;
extern s32 D_80177644;
extern s32 D_8017764C;
extern s32 D_80177660;

void func_80071A70(s32 arg0) {
    D_801775EF = arg0;
}

f32 func_80071A88(f32 arg0, f32 arg1, s8* arg2) {
    f32 spC;
    f32 sp8;
    f32 sp4;

    if (*arg2 == 0) {
        sp4 = arg1;
    } else {
        sp8 = arg1 - arg0;
        spC = sp8;
        if (spC < 0.0f) {
            sp8 = -spC;
        }
        if (sp8 < 4.0f) {
            *arg2 = 0;
            sp4 = arg1;
        } else {
            sp4 = (spC / (f32) *arg2) + arg0;
        }
    }
    return sp4;
}

extern f32 D_801775B0;
extern f32 D_80177614;
extern f32 D_8017761C;
extern f32 D_80177624;

void func_80071B50(f32 arg0) {
    f32 sp4;

    if (D_801651A4 & 1) {
        if (arg0 <= D_80177614) {
            D_801775B0 = arg0 + D_80177624;
        } else if ((D_80177614 + 480.0f) <= arg0) {
            D_801775B0 = arg0 - (480.0f - D_80177624);
        } else {
            D_801775B0 = ((arg0 - D_8017761C) / 2.0f) + D_80177614;
            D_80177624 = (arg0 - D_8017761C) / 2.0f;
        }
    } else {
        sp4 = arg0 - gView.at.y;
        if ((sp4 < 2.0f) && (sp4 > -2.0f)) {
            D_801775B0 = arg0;
        } else {
            D_801775B0 = (sp4 / 6.0f) + gView.at.y;
        }
        D_80177624 = 0.0f;
        D_8017761C = arg0;
        D_80177614 = D_801775B0;
    }
}

extern f32 D_801775C0;
extern f32 D_801775D8;

void func_80071CF4(s32 arg0) {
    UNUSED f32 player_x;
    UNUSED f32 player_y;
    UNUSED f32 player_z;

    player_x = gPlayerObject->Pos.x;
    player_y = gPlayerObject->Pos.y;
    player_z = gPlayerObject->Pos.z;

    if (arg0 == 0) {
        D_801775B0 = gView.at.y;
        D_801775C0 = gView.rot.x;
        D_801775D8 = gView.dist;
    } else {
        D_801775B0 = gView.at.y;
        if (D_801775C0 < 40.0f) {
            D_801775C0 = (f32) ((f64) D_801775C0 + 0.1);
        }
        if (D_801775D8 > 400.0f) {
            D_801775D8 -= 1.0f;
        }
    }
}

void func_80071E28(void) {
    f32 sp4;

    if (*gContCurrButton & 2) {
        sp4 = (f32) ((f64) gView.rot.y + 2.0);
        gView.rot.y = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (*gContCurrButton & 1) {
        sp4 = (f32) ((f64) gView.rot.y + 358.0);
        gView.rot.y = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (*gContCurrButton & 8) {
        sp4 = (f32) ((f64) gView.rot.x + 2.0);
        gView.rot.x = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (*gContCurrButton & 4) {
        sp4 = (f32) ((f64) gView.rot.x + 358.0);
        gView.rot.x = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (*gContCurrButton & 0x400) {
        gView.dist = gView.dist + 10.0f;
    }
    if (*gContCurrButton & 0x800) {
        gView.dist = gView.dist - 10.0f;
        if (gView.dist < 200.0f) {
            gView.dist = 200.0f;
        }
    }
}

void func_80072160(void) {
    D_8017763C = 0;
    D_80177644 = 0;
    D_8017764C = 0;
    D_80177660 = 0;
}

void func_80072190(void) {
    D_8017763C = -1;
    D_80177644 = 0;
    D_8017764C = 5;
    D_80177660 = 0xA;
}

void func_800721CC(void) {
    if (D_8017763C == 0) {
        return;
    }
    D_80177644 = D_80177644 + D_8017764C * D_8017763C;
    if (D_8017763C > 0) {
        if (D_80177644 >= D_80177660) {
            D_8017763C = -1;
            D_80177660 -= 2;
        }
    } else if (D_80177644 <= -D_80177660) {
        D_8017763C = 1;
        D_80177660 -= 2;
    }
    if (D_80177660 <= 0) {
        D_8017763C = 0;
    }
    D_801775B0 += (f32) D_80177644;
}

void func_800722FC(void) {
    if (D_801776DC != 0) {
        D_801776DC = 0;
        gView.rot.y = D_801776C8;
        gView.rot.x = D_801776D0;
        gDebugDispType = D_801776D8;
    }
}

void func_80072358(void) {
    D_801776DC = 1;
    D_801776C8 = gView.rot.y;
    D_801776D0 = gView.rot.x;
    D_801776D8 = gDebugDispType;
}

void func_800723A4(void) {
    func_80072358();
    D_801776DC = 0;
    D_80177680 = 0.0f;
    D_801776A8 = 0.0f;
}

void func_800723EC(void) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    if (gCameraType < 2) {
        return;
    }
    sp1C = 0;
    if (D_8016523E == 0) {
        if ((gPlayerObject->Vel.x == 0.0f) && (gPlayerObject->Vel.y == 0.0f) && (gPlayerObject->Vel.z == 0.0f)) {
            sp1C = 1;
        }
    } else if (D_8016523E == 6) {
        if ((gPlayerObject->Vel.x == 0.0f) && (gPlayerObject->Vel.y == 0.0f) && (gPlayerObject->Vel.z == 0.0f)) {
            sp1C = 1;
        }
    } else if (D_8016523E == 4) {
        sp1C = 1;
    }
    sp24 = 0;
    sp20 = 0;
    if (sp1C != 0) {
        if (gActiveContButton & 2) {
            sp24 = 1;
            if (D_80177680 < 30.0f) {
                D_80177680 += 2.0f;
            }
        } else if (gActiveContButton & 1) {
            sp24 = 1;
            if (D_80177680 > -30.0f) {
                D_80177680 -= 2.0f;
            }
        }
        if (gActiveContButton & 8) {
            sp20 = 1;
            if (D_801776A8 < 20.0f) {
                D_801776A8 += 1.0f;
            }
        }
    }
    if (sp24 == 0) {
        if (D_80177680 > 0.0f) {
            D_80177680 -= 2.0f;
        } else if (D_80177680 < 0.0f) {
            D_80177680 += 2.0f;
        }
    }
    if (sp20 == 0) {
        if (D_801776A8 > 0.0f) {
            D_801776A8 -= 1.0f;
        } else if (D_801776A8 < 0.0f) {
            D_801776A8 += 1.0f;
        }
    }
    if ((D_801776A8 != 0.0f) || (D_80177680 != 0.0f)) {
        func_80072358();
        gDebugDispType = gLevelInfo[gCurrentLevel]->unk5;
        gView.rot.x = func_80015538(gView.rot.x, D_801776A8);
        gView.rot.y = func_80015538(gView.rot.y, D_80177680);
    }
}

void* func_80065ACC(); /* extern */

void func_80072854(void) {
    struct UnkStruct80177778* sp2C;
    s32 sp28;
    UNUSED s32 sp24;
    UNUSED f32 player_x;
    UNUSED f32 player_y;
    UNUSED f32 player_z;

    player_x = PLAYER.Pos.x;
    player_y = PLAYER.Pos.y;
    player_z = PLAYER.Pos.z;

    sp2C = func_80065ACC();
    sp28 = (s32) sp2C->unk4;
    sp24 = (sp2C->unk1C * sp2C->unk22 * 0x3C) + sp28;
    gView.at.x = PLAYER.Pos.x;
    gView.at.y = PLAYER.Pos.y + 100.0f;
    gView.at.z = PLAYER.Pos.z;
}

void func_80072948(void) {
    gView.rot.x = 26.0f;
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 800.0f;
    gView.at.x = gPlayerObject->Pos.x;
    gView.at.y = gPlayerObject->Pos.y + 200.0f;
    gView.at.z = gPlayerObject->Pos.z;
}

extern f32 D_80177634;
extern f32 D_80177A58;
extern f32 D_80177A5C;

void func_80072A08(f32 arg0, f32 arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5) {
    f32 sp4;
    f32 sp0;

    sp0 = (f32) (D_8017790C - 0x3C0);
    if (sp0 < arg1) {
        sp4 = arg1 - sp0;
    } else {
        sp4 = 0.0f;
    }
    *arg5 = sp4 / 960.0f;
    *arg2 = (*arg5 * 100.0f) + (arg0 + D_80177634);
    *arg3 = D_80177A58 - (*arg5 * 5.0f);
    *arg4 = D_80177A5C - (*arg5 * 200.0f);
}

extern f32 D_801775A8;
extern f32 D_801775B8;
extern f32 D_801775C8;
extern f32 D_801775D0;
extern f32 D_801775E0;
extern f32 D_8017762C;

void func_80072B08(void) {
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    UNUSED f32 sp60;
    UNUSED f32 sp5C;
    UNUSED f32 sp58;
    UNUSED f32 sp54;
    f32 sp50;
    f32 sp4C;
    UNUSED s32 pad48;
    f32 sp44;
    f32 sp40;
    UNUSED s32 pad3C;
    f32 sp38;
    s8 sp37;
    f32 sp30;
    f32 sp2C;

    sp74 = gPlayerObject->Pos.x;
    sp70 = gPlayerObject->Pos.y;
    sp6C = gPlayerObject->Pos.z;

    sp68 = (f32) (D_801777E8 + 0x3C0);
    sp64 = (f32) (D_80177900 - 0x3C0);
    sp60 = (f32) (D_801778F0 + 0x3C0);
    sp5C = (f32) (D_80177908 - 0x3C0);
    sp58 = (f32) (D_801778F8 + 0x3C0);
    sp54 = (f32) (D_8017790C - 0x3C0);
    if (sp64 <= sp68) {
        sp68 = sp64 = (sp64 + sp68) / 2.0f;
    }
    if (sp74 <= sp68) {
        sp4C = sp74 - sp68;
    } else if (sp74 >= sp64) {
        sp4C = sp74 - sp64;
    } else {
        sp4C = 0.0f;
    }
    if (sp4C < 0.0f) {
        sp4C = -sp4C;
    }
    if (sp64 == sp68) {
        sp50 = 0.8f; // TO CHECK
    } else {
        sp50 = (f32) ((((f64) sp4C * -0.2) / 960.0) + 1.0);
    }
    sp40 = D_801651C4 - gPlayerObject->Pos.x;
    if (sp74 < sp68) {
        sp37 = 0;
        sp30 = 5.0f;
    } else if (sp74 > sp64) {
        sp37 = 1;
        sp30 = 5.0f;
    } else {
        if ((gPlayerObject->unkA4 == 0x2D) || (gPlayerObject->unkA4 == 0x2E)) {
            sp37 = 2;
            sp30 = 2.0f;
        } else if (gPlayerObject->unk108 == 0) {
            sp37 = 2;
            sp30 = 2.0f;
        } else if ((sp40 <= 1.0f) && (sp40 >= -1.0f)) {
            if (D_8016E09C == 0) {
                sp38 = D_801651CC - gPlayerObject->Pos.z;
                if ((sp38 <= 1.0f) && (sp38 >= -1.0f)) {
                    if ((gPlayerObject->Rot.y <= 45.0f) || (315.0f <= gPlayerObject->Rot.y) ||
                        ((gPlayerObject->Rot.y >= 135.0f) && (gPlayerObject->Rot.y <= 225.0f))) {
                        sp37 = 2;
                        sp30 = 2.0f;
                    } else if (gPlayerObject->Rot.y < 180.0f) {
                        sp37 = 3;
                        sp30 = 2.0f;
                    } else {
                        sp37 = 3;
                        sp30 = -2.0f;
                    }
                } else {
                    sp37 = 2;
                    sp30 = 2.0f;
                }
            } else {
                sp37 = 2;
                sp30 = 20.0f;
            }
        } else {
            if ((gPlayerObject->Rot.y <= 45.0f) || (315.0f <= gPlayerObject->Rot.y) ||
                ((gPlayerObject->Rot.y >= 135.0f) && (gPlayerObject->Rot.y <= 225.0f))) {
                sp37 = 2;
                sp30 = 2.0f;
            } else if (gPlayerObject->Rot.y <= 180.0f) {
                sp37 = 3;
                sp30 = 5.0f;
            } else {
                sp37 = 3;
                sp30 = -5.0f;
            }
        }
    }
    switch (sp37) {
        case 0:
            if (D_801775E0 >= sp30) {
                D_801775E0 -= sp30;
            } else if (D_801775E0 <= -sp30) {
                D_801775E0 += sp30;
            } else {
                D_801775E0 = 0.0f;
            }
            D_801775A8 = (-sp4C * sp50) + sp68 + D_801775E0;
            break;
        case 1:
            if (D_801775E0 >= sp30) {
                D_801775E0 -= sp30;
            } else if (D_801775E0 <= -sp30) {
                D_801775E0 += sp30;
            } else {
                D_801775E0 = 0.0f;
            }
            D_801775A8 = (sp4C * sp50) + sp64 + D_801775E0;
            break;
        case 2:
            if (D_801775E0 >= sp30) {
                D_801775E0 -= sp30;
            } else if (D_801775E0 <= -sp30) {
                D_801775E0 += sp30;
            } else {
                D_801775E0 = 0.0f;
            }
            D_801775A8 = sp74 + D_801775E0;
            break;
        case 3:
            D_801775E0 += sp30;
            if (D_801775E0 >= D_8017762C) {
                D_801775E0 = D_8017762C;
            } else if (D_801775E0 <= -D_8017762C) {
                D_801775E0 = -D_8017762C;
            }
            D_801775A8 = sp74 + D_801775E0;
            break;
    }
    D_801775B8 = sp6C;
    if (gPlayerObject->unk108 != 0) {
        func_80072A08(sp70, sp6C, &sp2C, &D_801775C0, &D_801775D8, &sp44);
        func_80071B50(sp2C);
    } else {
        if ((gPlayerObject->unkA4 == 0x25) || (gPlayerObject->unkA4 == 0x26D) || (gPlayerObject->unkA4 == 0x217)) {
            func_80071CF4(0);
        } else {
            func_80071CF4(1);
        }
    }
    func_800721CC();
    gView.at.y = func_80071A88(gView.at.y, D_801775B0, &D_801775EF);
    gView.at.x = D_801775A8;
    gView.at.z = D_801775B8;
    gView.dist = D_801775D8;
    gView.rot.x = D_801775C0;
    gView.rot.y = D_801775C8;
    gView.rot.z = D_801775D0;
}

extern f32 D_80105630;
extern s8 D_801775F4;
extern s8 D_801775F8;

void func_80073580(void) {
    f32 sp24;

    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.at.x = gPlayerObject->Pos.x;
    gView.at.z = gPlayerObject->Pos.z;
    D_801775EF = 0;
    D_801775F4 = 0;
    D_801775F8 = 0;
    D_801775A8 = 0.0f;
    D_801775B0 = 0.0f;
    D_801775B8 = 0.0f;
    D_801775C0 = D_80177A58;
    D_801775C8 = 0.0f;
    D_801775D0 = 0.0f;
    D_801775D8 = D_80177A5C;
    D_801775E0 = 0.0f;
    D_80177A58 = (s16) gLevelInfo[gCurrentLevel]->unk30;
    D_80177A5C = 950.0f;
    D_8017762C = 250.0f;
    if (D_8016523E == 4) {
        D_80177634 = -100.0f;
    } else {
        D_80177634 = 100.0f;
    }
    func_80072A08(gPlayerObject->Pos.y, gPlayerObject->Pos.z, &gView.at.y, &gView.rot.x, &gView.dist, &sp24);
    D_80177614 = gView.at.y;
    D_8017761C = gView.at.y;
    D_80177624 = 0.0f;
    func_80019B7C();
}

extern f32 D_80105634;
extern f64 D_80105638;
extern f32 D_80105640;

void func_80073784(void) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    UNUSED f32 sp40;
    UNUSED f32 sp3C;
    UNUSED f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    s8 sp1F;
    f32 sp18;

    sp54 = gPlayerObject->Pos.x;
    sp50 = gPlayerObject->Pos.y;
    sp4C = gPlayerObject->Pos.z;

    sp48 = (f32) (D_801777E8 + 0x3C0);
    sp44 = (f32) (D_80177900 - 0x3C0);
    sp40 = (f32) (D_801778F0 + 0x3C0);
    sp3C = (f32) (D_80177908 - 0x3C0);
    sp38 = (f32) (D_801778F8 + 0x3C0);
    sp34 = (f32) (D_8017790C - 0x3C0);
    if (sp44 <= sp48) {
        sp48 = sp44 = (sp44 + sp48) / 2.0f;
    }
    if (sp54 <= sp48) {
        sp2C = sp54 - sp48;
    } else if (sp54 >= sp44) {
        sp2C = sp54 - sp44;
    } else {
        sp2C = 0.0f;
    }
    if (sp2C < 0.0f) {
        sp2C = -sp2C;
    }
    if (sp44 == sp48) {
        sp30 = 0.8f;
    } else {
        sp30 = (f32) ((((f64) sp2C * -0.2) / 960.0) + 1.0);
    }
    sp24 = D_801651C4 - gPlayerObject->Pos.x;
    if (sp54 < sp48) {
        sp1F = 0;
        sp18 = 5.0f;
    } else if (sp54 > sp44) {
        sp1F = 1;
        sp18 = 5.0f;
    } else if ((sp24 <= 1.0f) && (sp24 >= -1.0f)) {
        if (D_8016E09C == 0) {
            sp20 = D_801651CC - gPlayerObject->Pos.z;
            if ((sp20 <= 1.0f) && (sp20 >= -1.0f)) {
                sp1F = 2;
                sp18 = 0.0f;
            } else {
                sp1F = 2;
                sp18 = 0.0f;
            }
        } else {
            sp1F = 2;
            sp18 = 20.0f;
        }
    } else {
        if ((gPlayerObject->Rot.y <= 45.0f) || (315.0f <= gPlayerObject->Rot.y) ||
            ((gPlayerObject->Rot.y >= 135.0f) && (gPlayerObject->Rot.y <= 225.0f))) {
            sp1F = 2;
            sp18 = 2.0f;
        } else if (gPlayerObject->Rot.y <= 180.0f) {
            sp1F = 3;
            sp18 = 5.0f;
        } else {
            sp1F = 3;
            sp18 = -5.0f;
        }
    }
    if (sp1F == 0) {
        if (D_801775E0 >= sp18) {
            D_801775E0 -= sp18;
        } else if (D_801775E0 <= -sp18) {
            D_801775E0 += sp18;
        } else {
            D_801775E0 = 0.0f;
        }
        D_801775A8 = (-sp2C * sp30) + sp48 + D_801775E0;
    } else if (sp1F == 1) {
        if (D_801775E0 >= sp18) {
            D_801775E0 -= sp18;
        } else if (D_801775E0 <= -sp18) {
            D_801775E0 += sp18;
        } else {
            D_801775E0 = 0.0f;
        }
        D_801775A8 = (sp2C * sp30) + sp44 + D_801775E0;
    } else {
        if (sp1F == 2) {
            if (D_801775E0 >= sp18) {
                D_801775E0 -= sp18;
            } else if (D_801775E0 <= -sp18) {
                D_801775E0 += sp18;
            } else {
                D_801775E0 = 0.0f;
            }
            D_801775A8 = sp54 + D_801775E0;
        } else if (sp1F == 3) {
            D_801775E0 += sp18;
            if (D_801775E0 >= 150.0f) {
                D_801775E0 = 150.0f;
            } else if (D_801775E0 <= -150.0f) {
                D_801775E0 = -150.0f;
            }
            D_801775A8 = sp54 + D_801775E0;
        }
    }
    D_801775B8 = sp4C;
    if (gPlayerObject->unk108 != 0) {
        if (sp4C >= sp34) {
            sp28 = sp4C - sp34;
        } else {
            sp28 = 0.0f;
        }
        if (sp28 < 0.0f) {
            sp28 = -sp28;
        }
        if (sp4C > sp34) {
            D_801775B0 = sp50 + 100.0f + ((100.0f * sp28) / 960.0f);
            D_801775C0 = D_80177A58 - ((sp28 / 960.0f) * 5.0f);
            D_801775D8 = D_80177A5C - ((200.0f * sp28) / 960.0f);
        } else {
            D_801775B0 = sp50 + 100.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
        }
    } else {
        if ((gPlayerObject->unkA4 == 0x25) || (gPlayerObject->unkA4 == 0x26D)) {
            func_80071CF4(0);
        } else {
            func_80071CF4(1);
        }
    }
    gView.at.y = func_80071A88(gView.at.y, D_801775B0, &D_801775EF);
    gView.at.x = D_801775A8;
    gView.at.z = D_801775B8;
    gView.dist = D_801775D8;
    gView.rot.x = D_801775C0;
    gView.rot.y = D_801775C8;
    gView.rot.z = D_801775D0;
}

void func_80074194(void) {
    gView.rot.x = 26.0f;
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 800.0f;
    gView.at.x = gPlayerObject->Pos.x;
    gView.at.y = gPlayerObject->Pos.y + 200.0f;
    gView.at.z = gPlayerObject->Pos.z;
    D_801775EF = 0;
    D_801775F4 = 0;
    D_801775F8 = 0;
    D_80177A58 = (f32) gLevelInfo[gCurrentLevel]->unk30;
    D_80177A5C = 800.0f;
    D_801775A8 = 0.0f;
    D_801775B0 = 0.0f;
    D_801775B8 = 0.0f;
    D_801775C0 = D_80177A58;
    D_801775C8 = 0.0f;
    D_801775D0 = 0.0f;
    D_801775D8 = D_80177A5C;
    D_801775E0 = 0.0f;
}

extern f32 D_80105644;
extern f32 D_80105648;

void func_80074318(void) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    s32 sp18;
    s32 sp14;
    f32 sp10;
    f32 spC;
    s32 sp8;
    s32 sp4;

    sp24 = gPlayerObject->Pos.x;
    sp20 = gPlayerObject->Pos.y;
    sp1C = gPlayerObject->Pos.z;
    sp18 = (s32) (D_80177900 + D_801777E8) / 2;
    sp14 = (s32) (D_80177908 + D_801778F0) / 2;
    sp10 = 0.8f;
    spC = 0.9f;
    sp8 = (s32) (sp24 - (f32) sp18);
    sp4 = (s32) (sp20 - (f32) sp14);
    gView.at.x = ((f32) sp8 * sp10) + (f32) sp18;
    gView.at.y = ((f32) sp4 * spC) + (f32) sp14;
    gView.at.z = sp1C;
}

void func_800744D8(void) {
    if (D_8016523E == 2) {
        gView.rot.x = 15.0f;
    } else {
        gView.rot.x = 5.0f;
    }
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 500.0f;
    gView.at.x = gPlayerObject->Pos.x;
    gView.at.y = gPlayerObject->Pos.y + 200.0f;
    gView.at.z = gPlayerObject->Pos.z;
}

void func_800745C0(void) {
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    s64 sp58;
    s64 sp54;
    s64 sp48;
    f32 sp44;
    s32 sp40;
    s32 sp3C;

    sp74 = gPlayerObject->Pos.x;
    sp70 = gPlayerObject->Pos.y;
    sp6C = gPlayerObject->Pos.z;
    D_801775A8 = sp74;
    D_801775B0 = sp70 + 100.0f;
    D_801775B8 = sp6C;

    sp58 = gView.eye.x - D_801775A8;
    sp48 = gView.eye.z - D_801775B8;
    sp54 = sinf((f32) ((f64) D_801775C0 * DEG_TO_RAD)) * D_801775D8;

    sp44 = sqrtf((SQ(sp58) + SQ(sp54) + SQ(sp48))), D_801775D8 = gView.dist;

    if ((D_801775D8 - sp44 >= 1.0f) || (D_801775D8 - sp44 <= -1.0f)) {
        D_801775D8 = sp44;
    }
    if (D_801775D8 > 800.0f) {
        D_801775D8 = 800.0f;
    } else if (D_801775D8 < 500.0f) {
        D_801775D8 = 500.0f;
    }
    sp64 = func_80015538(360.0f - gPlayerObject->unk3C, 180.0f);
    sp68 = func_80015538(gView.rot.y, -sp64);
    if ((sp68 <= 90.0f) || (sp68 >= 270.0f)) {
        if ((gPlayerObject->Vel.x == 0.0f) && (gPlayerObject->Vel.z == 0.0f)) {
            sp40 = 0;
        } else {
            sp40 = 1;
        }
    } else if ((gPlayerObject->Vel.x == 0.0f) && (gPlayerObject->Vel.z == 0.0f)) {
        sp40 = 0;
    } else if (gView.dist == 500.0f) {
        sp40 = 2;
    } else {
        sp40 = 1;
    }
    if (sp40 != 0) {
        sp3C = func_800157EC(gView.rot.y, sp64, (f32) sp40);
        if (sp3C == 0) {
            D_801775C8 = gView.rot.y;
        } else {
            if (sp68 > 180.0f) {
                sp68 = 360.0f - sp68;
            }
            D_801775C8 = func_80015538(gView.rot.y, (f32) (sp40 * sp3C));
        }
    }
    gView.at.y = func_80071A88(gView.at.y, D_801775B0, &D_801775EF);
    gView.at.x = D_801775A8;
    gView.at.z = D_801775B8;
    gView.dist = D_801775D8;
    gView.rot.x = D_801775C0;
    gView.rot.y = D_801775C8;
    gView.rot.z = D_801775D0;
}

void func_80074B04(void) {
    gView.rot.x = 26.0f;
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 800.0f;
    gView.at.x = gPlayerObject->Pos.x;
    gView.at.y = gPlayerObject->Pos.y + 200.0f;
    gView.at.z = gPlayerObject->Pos.z;
    D_801775EF = 0;
    D_801775F4 = 0;
    D_801775F8 = 0;
    D_80177A58 = (f32) gLevelInfo[gCurrentLevel]->unk30;
    D_80177A5C = 800.0f;
    D_801775A8 = 0.0f;
    D_801775B0 = 0.0f;
    D_801775B8 = 0.0f;
    D_801775C0 = 26.0f;
    D_801775C8 = 0.0f;
    D_801775D0 = 0.0f;
    D_801775D8 = 800.0f;
}

f32 func_80074C7C(f32 arg0, f32 arg1, f32 arg2) {
    f32 sp2C;
    UNUSED s32 pad28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    sp24 = func_80015634(arg0, arg1);
    sp24 = func_80015538(sp24, 180.0f);
    sp24 = 360.0f - sp24;
    sp20 = func_80015538(gView.rot.y, -sp24);
    sp1C = func_80015538(sp20, 180.0f);
    if (sp1C <= arg2) {
        sp2C = func_80015538(gView.rot.y, -sp1C);
    } else if (sp1C >= (360.0f - arg2)) {
        sp2C = func_80015538(gView.rot.y, 360.0f - sp1C);
    } else if (sp1C >= 180.0f) {
        sp2C = func_80015538(gView.rot.y, arg2);
    } else {
        sp2C = func_80015538(gView.rot.y, -arg2);
    }
    return sp2C;
}

/* .bss */
extern f32 D_801775FC;
extern f32 D_80177604;
extern f32 D_8017760C;

void func_80074DFC(void) {
    struct ObjectStruct* sp2C;
    UNUSED char pad[0x28];

    switch (gCurrentLevel) {
        case 0x22:
            D_801775FC = 480.0f;
            D_8017760C = -480.0f;
            break;
        case 0x13:
            D_801775FC = 0.0f;
            D_80177604 = 500.0f;
            D_8017760C = 0.0f;
            break;
        case 0x25:
            sp2C = &gObjects[0xE];
            if (sp2C->unkA4 != 0) {
                D_801775FC = sp2C->Pos.x;
                D_80177604 = sp2C->Pos.y + 210.0f;
                D_8017760C = sp2C->Pos.z;
            }
            break;
        case 0x39:
            sp2C = &gObjects[0xE];
            if (sp2C->unkA4 != 0) {
                D_801775FC = sp2C->Pos.x;
                D_8017760C = sp2C->Pos.z;
            }
            break;
        case 0x5A:
            sp2C = &gObjects[0xE];
            if ((sp2C->unkA4 != 0) && (sp2C->unkE4 == 0x1B8)) {
                D_801775FC = gObjects[0xE].Pos.x;
                D_8017760C = gObjects[0xE].Pos.z;
            } else {
                D_801775FC = 0.0f;
                D_8017760C = 0.0f;
            }
            break;
        case 0x4C:
            sp2C = &gObjects[0xE];
            if (sp2C->unkA4 != 0) {
                D_801775FC = sp2C->Pos.x;
                D_8017760C = sp2C->Pos.z;
            }
            break;
        case 0x4D:
            sp2C = &gObjects[0xE];
            if (sp2C->unkA4 != 0) {
                D_801775FC = sp2C->Pos.x;
                D_80177604 = sp2C->Pos.y + 210.0f;
                D_8017760C = sp2C->Pos.z;
            }
            break;
        case 0x4E:
            D_801775FC = 0.0f;
            D_80177604 = 320.0f;
            D_8017760C = -1200.0f;
            break;
        case 0x51:
            D_801775FC = 0.0f;
            D_80177604 = 320.0f;
            D_8017760C = 0.0f;
            break;
        case 0x52:
            D_801775FC = 0.0f;
            D_80177604 = 320.0f;
            D_8017760C = 0.0f;
            break;
        case 0x6C:
            D_801775FC = 0.0f;
            D_80177604 = 320.0f;
            D_8017760C = 0.0f;
            break;
        case 0x53:
            sp2C = &gObjects[0xE];
            if (sp2C->unkA4 != 0) {
                D_801775FC = sp2C->Pos.x;
                D_8017760C = sp2C->Pos.z;
            }
            break;
        case 0x55:
            sp2C = &gObjects[0xE];
            if (sp2C->unkA4 != 0) {
                D_801775FC = sp2C->Pos.x;
                D_8017760C = sp2C->Pos.z;
            }
            break;
        case 0xF:
        case 0x4F:
        case 0x57:
        case 0x58:
        case 0x59:
            sp2C = &gObjects[0xE];
            if (sp2C->unkA4 != 0) {
                D_801775FC = sp2C->Pos.x;
                D_8017760C = sp2C->Pos.z;
            }
            break;
    }
}

void func_80075288(void) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    UNUSED s32 pad48;
    UNUSED s32 pad44;
    UNUSED s32 pad40;
    f32 sp3C;
    UNUSED s32 pad38;
    f32 sp34;
    f32 sp30;
    UNUSED char pad[0x14];

    sp54 = gPlayerObject->Pos.x;
    sp50 = gPlayerObject->Pos.y;
    sp4C = gPlayerObject->Pos.z;
    func_80074DFC();
    switch (gCurrentLevel) { /* switch 1 */
        case 0x13:           /* switch 1 */
        case 0x25:           /* switch 1 */
        case 0x39:           /* switch 1 */
        case 0x4C:           /* switch 1 */
        case 0x4E:           /* switch 1 */
        case 0x53:           /* switch 1 */
            D_801775A8 = sp54;
            D_801775B8 = sp4C;
            func_80071B50(sp50 + 200.0f);
            break;
        case 0x4D: /* switch 1 */
        case 0x55: /* switch 1 */
            D_801775A8 = sp54;
            D_801775B8 = sp4C;
            func_80071B50(sp50 + 250.0f);
            break;
        case 0xF:  /* switch 1 */
        case 0x4F: /* switch 1 */
        case 0x51: /* switch 1 */
        case 0x52: /* switch 1 */
        case 0x57: /* switch 1 */
        case 0x58: /* switch 1 */
        case 0x59: /* switch 1 */
            D_801775A8 = sp54;
            D_801775B8 = sp4C;
            func_80071B50(sp50 + 100.0f);
            break;
        case 0x6C: /* switch 1 */
            D_801775A8 = sp54;
            D_801775B8 = sp4C;
            func_80071B50(sp50 + 200.0f);
            break;
        default: /* switch 1 */
            D_801775A8 = sp54;
            D_801775B8 = sp4C;
            func_80071B50(sp50 + 100.0f);
            break;
    }
    D_801775C0 = D_80177A58;
    switch (gCurrentLevel) { /* switch 2 */
        case 0xF:            /* switch 2 */
        case 0x13:           /* switch 2 */
        case 0x25:           /* switch 2 */
        case 0x39:           /* switch 2 */
        case 0x4C:           /* switch 2 */
        case 0x4D:           /* switch 2 */
        case 0x4E:           /* switch 2 */
        case 0x4F:           /* switch 2 */
        case 0x53:           /* switch 2 */
        case 0x55:           /* switch 2 */
        case 0x57:           /* switch 2 */
        case 0x58:           /* switch 2 */
        case 0x59:           /* switch 2 */
        case 0x5A:           /* switch 2 */
            sp3C = D_801775A8 - D_801775FC;
            sp34 = D_801775B8 - D_8017760C;
            sp30 = func_80074C7C(sp3C, sp34, 2.0f);
            D_801775C8 = sp30;
            break;
        case 0x51: /* switch 2 */
            sp3C = D_801775A8 - D_801775FC;
            sp34 = D_801775B8 - D_8017760C;
            sp30 = func_80074C7C(sp3C, sp34, 1.0f);
            D_801775C8 = sp30;
            break;
        case 0x52: /* switch 2 */
            sp3C = D_801775A8 - D_801775FC;
            sp34 = D_801775B8 - D_8017760C;
            sp30 = func_80074C7C(sp3C, sp34, 2.5f);
            D_801775C8 = sp30;
            break;
        case 0x6C: /* switch 2 */
            sp3C = D_801775A8 - D_801775FC;
            sp34 = D_801775B8 - D_8017760C;
            sp30 = func_80074C7C(sp3C, sp34, 1.5f);
            D_801775C8 = sp30;
            break;
        default: /* switch 2 */
            sp3C = D_801775A8 - D_801775FC;
            sp34 = D_801775B8 - D_8017760C;
            sp30 = 360.0f - func_80015634(sp3C, sp34);
            D_801775C8 = sp30;
            sp30 = func_80015538(gView.rot.y, -D_801775C8);
            if ((sp30 > 90.0f) && (sp30 < 270.0f)) {
                D_801775F8 = 0x3C;
            }
            break;
    }
    if (gPlayerObject->unk108 != 0) {
    } else if (gPlayerObject->unkA4 == 0x25) {
        func_80071CF4(0);
    } else {
        func_80071CF4(1);
    }
    gView.at.y = func_80071A88(gView.at.y, D_801775B0, &D_801775EF);
    gView.at.x = D_801775A8;
    gView.at.z = D_801775B8;
    gView.dist = D_801775D8;
    gView.rot.x = D_801775C0;
    gView.rot.y = func_80071A88(gView.rot.y, D_801775C8, &D_801775F8);
    gView.rot.z = D_801775D0;
}

extern f32 D_80105C3C;
extern f32 D_80105C40;
void func_800757C0(void) {
    gView.rot.x = 26.0f;
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 800.0f;
    gView.at.x = gPlayerObject->Pos.x;
    gView.at.y = gPlayerObject->Pos.y + 200.0f;
    gView.at.z = gPlayerObject->Pos.z;
    D_801775EF = 0;
    D_801775F4 = 0;
    D_801775F8 = 0;
    D_80177A58 = (f32) gLevelInfo[gCurrentLevel]->unk30;
    D_80177A5C = 950.0f;
    D_801775A8 = 0.0f;
    D_801775B0 = 0.0f;
    D_801775B8 = 0.0f;
    D_801775C0 = D_80177A58;
    D_801775C8 = 0.0f;
    D_801775D0 = 0.0f;
    D_801775D8 = D_80177A5C;
    D_801775FC = 0.0f;
    D_80177604 = 0.0f;
    D_8017760C = 0.0f;
    D_80177614 = gView.at.y;
    D_8017761C = gView.at.y;
    D_80177624 = 0.0f;
    switch (gCurrentLevel) {
        case 0x13:
            D_80177A58 = 23.0f;
            D_80177A5C = 800.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0x25:
            D_80177A58 = 45.0f;
            D_80177A5C = 800.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0x39:
            D_80177A58 = 20.0f;
            D_80177A5C = 800.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0x5A:
            D_80177A58 = 26.0f;
            D_80177A5C = 800.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0x4C:
            D_80177A58 = 20.0f;
            D_80177A5C = 800.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0x4D:
            D_80177A58 = 12.0f;
            D_80177A5C = 800.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0x4E:
            D_80177A58 = 18.0f;
            D_80177A5C = 900.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0x51:
            D_80177A58 = 20.0f;
            D_80177A5C = 800.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0x52:
            D_80177A58 = 23.0f;
            D_80177A5C = 850.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0x6C:
            D_80177A58 = 16.0f;
            D_80177A5C = 750.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0x53:
            D_80177A58 = 14.0f;
            D_80177A5C = 800.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0x55:
            D_80177A58 = 12.0f;
            D_80177A5C = 800.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
        case 0xF:
        case 0x4F:
        case 0x57:
        case 0x58:
        case 0x59:
            D_80177A58 = 20.0f;
            D_80177A5C = 800.0f;
            D_801775C0 = D_80177A58;
            D_801775D8 = D_80177A5C;
            break;
    }
}

void func_80075D68(void) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    sp3C = gPlayerObject->Pos.x;
    sp38 = gPlayerObject->Pos.y;
    sp34 = gPlayerObject->Pos.z;
    sp30 = 0.0f;
    sp2C = 0.0f;
    sp28 = 0.0f;
    if (gCurrentLevel == 0x25) {
        if (gObjects[0xE].unkA4 != 0) {
            sp30 = gObjects[0xE].Pos.x;
            sp2C = gObjects[0xE].Pos.y + 210.0f;
            sp28 = gObjects[0xE].Pos.z;
        } else {
            sp30 = 0.0f;
            sp2C = 0.0f;
            sp28 = 0.0f;
        }
    }
    D_801775A8 = sp3C;
    D_801775B0 = sp38 + 60.0f;
    D_801775B8 = sp34;
    sp24 = D_801775A8 - sp30;
    sp20 = D_801775B0 - sp2C;
    sp1C = D_801775B8 - sp28;
    sp18 = 360.0f - func_80015634(sp24, sp1C);
    D_801775C8 = sp18;
    sp18 = func_80015538(gView.rot.y, -D_801775C8);
    if ((sp18 > 90.0f) && (sp18 < 270.0f)) {
        D_801775F8 = 0x3C;
    }
    sp18 = 360.0f - func_800155A8(sp20, sp1C);
    if ((sp18 > 90.0f) && (sp18 <= 180.0f)) {
        sp18 = 180.0f - sp18;
    } else if ((sp18 > 180.0f) && (sp18 <= 270.0f)) {
        sp18 = 540.0f - sp18;
    }
    if ((sp18 >= 60.0f) && (sp18 <= 180.0f)) {
        sp18 = 60.0f;
    } else if ((sp18 > 180.0f) && (sp18 <= 300.0f)) {
        sp18 = 300.0f;
    }
    D_801775C0 = sp18;
    if (gPlayerObject->unk108 != 0) {
    } else if (gPlayerObject->unkA4 == 0x25) {
        func_80071CF4(0);
    } else {
        func_80071CF4(1);
    }
    gView.at.y = func_80071A88(gView.at.y, D_801775B0, &D_801775EF);
    gView.at.x = D_801775A8;
    gView.at.z = D_801775B8;
    gView.dist = D_801775D8;
    gView.rot.x = D_801775C0;
    gView.rot.y = func_80071A88(gView.rot.y, D_801775C8, &D_801775F8);
    gView.rot.z = D_801775D0;
}

void func_800761FC(void) {
    gView.rot.x = 26.0f;
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 800.0f;
    gView.at.x = gPlayerObject->Pos.x;
    gView.at.y = gPlayerObject->Pos.y + 200.0f;
    gView.at.z = gPlayerObject->Pos.z;
    D_801775EF = 0;
    D_801775F4 = 0;
    D_801775F8 = 0;
    D_80177A58 = (f32) gLevelInfo[gCurrentLevel]->unk30;
    D_80177A5C = 800.0f;
    D_801775A8 = 0.0f;
    D_801775B0 = 0.0f;
    D_801775B8 = 0.0f;
    D_801775C0 = 26.0f;
    D_801775C8 = 0.0f;
    D_801775D0 = 0.0f;
    D_801775D8 = 800.0f;
}

void func_80075288(); /* extern */

void func_80076374(void) {
    func_800722FC();
    switch (gCameraType) {
        default:
        case 0:
            func_8008B030();
            break;
        case 1:
            func_80072854();
            break;
        case 2:
            func_80072B08();
            break;
        case 3:
            func_80073784();
            break;
        case 4:
            func_80074318();
            break;
        case 5:
            func_800745C0();
            break;
        case 6:
            func_80075288();
            break;
        case 7:
            func_80075D68();
            break;
    }
    func_800723EC();
}

void func_80076458(void) {
    gView.rot.x = 26.0f;
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 800.0f;
    gView.at.x = gPlayerObject->Pos.x;
    gView.at.y = gPlayerObject->Pos.y + 200.0f;
    gView.at.z = gPlayerObject->Pos.z;
    D_801775EF = 0;
    D_801775F4 = 0;
    D_801775F8 = 0;
    D_80177A58 = (f32) gLevelInfo[gCurrentLevel]->unk30;
    D_80177A5C = 800.0f;
    func_80072160();
    switch (gCameraType) {
        case 0:
        case 1:
            func_80072948();
            break;
        case 2:
            func_80073580();
            break;
        case 3:
            func_80074194();
            break;
        case 4:
            func_800744D8();
            break;
        case 5:
            func_80074B04();
            break;
        case 6:
            func_800757C0();
            break;
        case 7:
            func_800761FC();
            break;
        default:
            break;
    }
    func_800723A4();
}

extern s8 D_8017790A;
extern s8 D_8017790E;
extern s8 D_80177912;
extern s8 D_8017791A;
extern s16* D_80177924;
extern s16 D_8017792A;

void func_80076640(void) {
    D_8017790A = 0;
    D_80177924 = 0;
    D_8017790E = 0;
    D_80177912 = 0;
    D_8017791A = 0;
    D_8017792A = 0;
}

s32 func_80076680(void) {
    if (D_8017790A != 0) {
        return 1;
    }
    return 0;
}

extern s32 D_80106CFC[];
extern s8 D_80177916;

void func_800766B4(s32 arg0) {
    gPlayerObject->unk108 = -1;
    D_80177920 = arg0;
    D_80177924 = (s16*) D_80106CFC[arg0];
    D_8017790E = 0;
    D_80177912 = 0;
    D_80177916 = 0;
    D_8017791A = 0;
    D_8017792A = 2;
}

void func_80076720(void) {
    if (D_8017792A != 0) {
        D_8017792A -= 1;
        if (D_8017792A == 0) {
            D_8017790A = 1;
        }
    }
    if (D_8017790A == 0) {
        return;
    }
    switch (D_8017790E) { /* irregular */
        case 0:
            D_80177916 += 8;
            if (D_80177916 >= 0x28) {
                D_80177916 = 0x28;
                D_8017790E = 1;
            }
            break;
        case 1:
            D_8017791A = (u8) D_8017791A + 1;
            if (gActiveContPressed & 0x8000) {
                gActiveContButton &= 0xFFFF7FFF;
                gActiveContPressed &= 0xFFFF7FFF;
                gPlayerObject->unk108 = 1;
                D_8017790A = 0;
            }
            break;
    }
}

void func_80076890(void) {
    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                   G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetCombineMode(gMasterDisplayList++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(gMasterDisplayList++, 0, 0, 0x0, 0x00, 0x00, 0xB4);
    gDPFillRectangle(gMasterDisplayList++, 24, 0x78 - D_80177916, 298, 0x78 + D_80177916);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gDPSetPrimColor(gMasterDisplayList++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPFillRectangle(gMasterDisplayList++, 24, 0x78 - D_80177916, 298, 0x79 - D_80177916);

    gDPFillRectangle(gMasterDisplayList++, 24, D_80177916 + 0x77, 298, D_80177916 + 0x78);
    gDPFillRectangle(gMasterDisplayList++, 24, 0x78 - D_80177916, 25, D_80177916 + 0x78);
    gDPFillRectangle(gMasterDisplayList++, 297, 0x78 - D_80177916, 298, 0x78 + D_80177916);
}

void func_80076C4C(void) {
    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                   G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetTexturePersp(gMasterDisplayList++, G_TP_NONE);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gDPSetCombineMode(gMasterDisplayList++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetColorDither(gMasterDisplayList++, G_CD_MAGICSQ | 0x40);
    gDPSetTextureFilter(gMasterDisplayList++, G_TF_BILERP);
    gDPSetTextureLUT(gMasterDisplayList++, G_TT_RGBA16);
    gDPSetTextureImage(gMasterDisplayList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, gFileArray[0x1A].ptr + 0x10);
    gDPTileSync(gMasterDisplayList++);
    gDPSetTile(gMasterDisplayList++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMasterDisplayList++);
    gDPLoadTLUTCmd(gMasterDisplayList++, G_TX_LOADTILE, 15);
    gDPPipeSync(gMasterDisplayList++);
}

void func_80076F6C(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    gDPLoadTextureTile_4b(gMasterDisplayList++, (gFileArray[0x1A].ptr + 0x30), G_IM_FMT_CI, 256,
                          0 /* height - unused field */, arg2, arg3, arg2 + 8, arg3 + 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetTileSize(gMasterDisplayList++, G_TX_RENDERTILE, 0, 0, 64, 64);
    gSPTextureRectangle(gMasterDisplayList++, arg0 << 2, arg1 << 2, (arg0 + 8) << 2, (arg1 + 16) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
}

void func_800772B8(void) {
    s16* sp24;
    s16 sp22;
    s16 sp20;
    s16 sp1E;
    s16 sp1C;

    if (D_80177924 == 0) {
        return;
    }
    func_80076890();
    if (D_8017790E != 1) {
        return;
    }
    func_80076C4C();
    if (D_80177920 < 0x14) {
        sp1C = 0x20;
    } else {
        sp1C = 0x64;
    }
    sp20 = sp1C;
    sp1E = 0x58;
    sp22 = D_80177924[4];
    sp24 = D_80177924 + 5;

    while (TRUE) {

        if ((*sp24 == -1)) {
            sp22--;
            if (sp22 == 0) {
                break;
            }
            sp1E += 16;
            sp20 = sp1C;
        } else {
            func_80076F6C(sp20, sp1E, (*sp24 % 32) * 8, (*sp24 / 32) * 0x10);
            sp20 += 8;
        }
        sp24++;
    }
}

void func_80077458(void) {
    UNUSED s32 pad[3];

    if (D_80177924 == NULL) {
        return;
    }
    if ((s32) D_80177920 < 0x14) {
        return;
    }
    if (D_8017790E != 1) {
        return;
    }
    func_8006F570(0x2B, 0x1C, 0x58, 1.0f, 1.0f);
    if ((u8) D_8017791A & 4) {
        func_8006F570(0x2C, 0x2C, 0x7B, 1.0f, 1.0f);
    }
}

void func_80077528(void) {
    if (D_8017790A == 0) {
        return;
    }
    func_800772B8();
    func_80077458();
}
