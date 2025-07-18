#include "prevent_bss_reordering2.h"
#include <ultra64.h>
#include "2BF00.h"
#include "obj.h"
#include "debug.h"
#include "common.h"

extern s16 sSetModeMenuOption; // Current Set mode menu item

typedef enum { MAIN_MENU, RESET_MODE_MENU, SAVE_MODE_MENU } SET_MODE_MENUS;

typedef enum {
    SET_MODE_OPTION_CHR, // Unused
    SET_MODE_OPTION_1,
    SET_MODE_OPTION_2,
    SET_MODE_OPTION_3,
    SET_MODE_OPTION_ADJUST,
    SET_MODE_OPTION_ANGLE,
    SET_MODE_OPTION_PRM1,
    SET_MODE_OPTION_PRM2,
    SET_MODE_OPTION_PRM3,
    SET_MODE_OPTION_MOVE
} SET_MODE_MENU_OPTIONS;

Vec3f D_8004A660[8] = {
    { 0.0f, 0.0f, -29.0f },  { 29.0f, 0.0f, 0.0f },  { 0.0f, 0.0f, 29.0f },  { -29.0f, 0.0f, 0.0f },
    { 0.0f, 59.0f, -29.0f }, { 29.0f, 59.0f, 0.0f }, { 0.0f, 59.0f, 29.0f }, { -29.0f, 59.0f, 0.0f },
};

u8 D_8004A6C0[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

s32 D_8004A6CC[0x11][2] = {
    { 0, 0 }, { 0, 1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 0 },  { -1, -1 }, { -1, 0 }, { 1, 0 },
    { 1, 1 }, { 0, 0 }, { 0, 1 },  { 1, -1 }, { 1, 0 },  { 0, -1 }, { 0, 0 },   { 0, 0 },
};

//.bss
u8 D_80057660;
s32 D_80057664;
s32 D_80057668;
s32 D_8005766C;
s32 D_80057670;
s32 D_80057674;
f32 D_80057678;
f32 sPlayerObjPosX;
f32 sPlayerObjPosY;
f32 sPlayerObjPosZ;
s8 sDebugSetModeMenu;
s8 D_80057689;
s8 D_8005768A;
s32 D_8005768C;

// Handles
void Handle_ObjView(void) {
    f32 sp4;

    if (gActiveContButton & 0x2000) {
        if (gActiveContButton & 8) {
            gView.dist = gView.dist - 10.0f;
            if (gView.dist < 100.0f) {
                gView.dist = 100.0f;
            }
        }
        if (gActiveContButton & CONT_D) {
            gView.dist = gView.dist + 10.0f;
        }
    } else {
        if (gActiveContButton & CONT_C) {
            sp4 = (f32) ((f64) gView.rot.y + 2.0);
            gView.rot.y = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
        }
        if (gActiveContButton & CONT_F) {
            sp4 = (f32) ((f64) gView.rot.y + 358.0);
            gView.rot.y = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
        }
        if (gActiveContButton & CONT_E) {
            sp4 = (f32) ((f64) gView.rot.x + 2.0);
            gView.rot.x = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
        }
        if (gActiveContButton & CONT_D) {
            sp4 = (f32) ((f64) gView.rot.x + 358.0);
            gView.rot.x = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
        }
    }
}

void Set_ObjView(f32 viewX, f32 viewY, f32 viewZ) {
    gView.at.x = viewX;
    gView.at.y = viewY;
    gView.at.z = viewZ;
}

void func_8002B670(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 0x81; sp4++) {
        D_800576A8[sp4].unk0 = -1;
    }

    for (sp4 = 0; sp4 < 0x80; sp4++) {
        if (D_8017796C[sp4].unk0 == -1) {
            break;
        }
        D_800576A8[sp4].unk0 = D_8017796C[sp4].unk0;
        D_800576A8[sp4].unk2 = D_8017796C[sp4].unk2;
        D_800576A8[sp4].unk4 = D_8017796C[sp4].unk4;
        D_800576A8[sp4].unk6 = D_8017796C[sp4].unk6;
        D_800576A8[sp4].unk8 = D_8017796C[sp4].unk8;
        D_800576A8[sp4].unkA = D_8017796C[sp4].unkA;
        D_800576A8[sp4].unkC = D_8017796C[sp4].unkC;
        D_800576A8[sp4].unkE = D_8017796C[sp4].unkE;
    }
    D_8017796C = D_800576A8;
}

s32 func_8002B830(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 0x80; sp4++) {
        if (D_800576A8[sp4].unk0 == -1) {
            return sp4;
        }
    }
    return -1;
}

s32 func_8002B894(s32 arg0) {
    s32 sp4;

    for (sp4 = 0xE; sp4 < 0x4E; sp4++) {
        if ((gObjects[sp4].actionState) && (gObjects[sp4].objID == D_800576A8[arg0].unk0) &&
            (gObjects[sp4].Pos.x == D_800576A8[arg0].unk2) && (gObjects[sp4].Pos.y == D_800576A8[arg0].unk4) &&
            (gObjects[sp4].Pos.z == D_800576A8[arg0].unk6)) {

            return sp4;
        }
    }

    return -1;
}

void func_8002B9B8(void) {
    s32 sp1C;

    for (sp1C = 0xE; sp1C < 0x4E; sp1C++) {
        if (gObjects[sp1C].actionState != 0) {
            func_8001BB34(sp1C, 0);
        }
    }
}

s32 func_8002BA34(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 0x80; sp4++) {
        if ((D_800576A8[sp4].unk0 != -1) && (D_800576A8[sp4].unk2 != 0x7530) && (D_800576A8[sp4].unk4 != 0x7530) &&
            (D_800576A8[sp4].unk6 != 0x7530)) {
            return 0;
        }
    }
    return 1;
}

void func_8002BAC8(void) {
    u16 pressed_button;

    if (D_800576A2 != 0) {
        D_800576A2 -= 1;
    }
    pressed_button = 0;
    if (D_800576A2 == 0) {
        if (gActiveContPressed & CONT_RIGHT) {
            D_800576A2 = 0xF;
            pressed_button = CONT_RIGHT;
        } else if (gActiveContPressed & CONT_LEFT) {
            D_800576A2 = 0xF;
            pressed_button = CONT_LEFT;
        } else if (gActiveContPressed & CONT_UP) {
            D_800576A2 = 0xF;
            pressed_button = CONT_UP;
        } else if (gActiveContPressed & CONT_DOWN) {
            D_800576A2 = 0xF;
            pressed_button = CONT_DOWN;
        } else if (gActiveContPressed & CONT_A) {
            D_800576A2 = 0xF;
            pressed_button = CONT_A;
        } else if (gActiveContPressed & CONT_B) {
            D_800576A2 = 0xF;
            pressed_button = CONT_B;
        }
    } else if (gActiveContButton & CONT_RIGHT) {
        if (D_800576A2 == 1) {
            pressed_button = CONT_RIGHT;
            D_800576A2 = 2;
        }
    } else if (gActiveContButton & CONT_LEFT) {
        if (D_800576A2 == 1) {
            pressed_button = CONT_LEFT;
            D_800576A2 = 2;
        }
    } else if (gActiveContButton & CONT_UP) {
        if (D_800576A2 == 1) {
            pressed_button = CONT_UP;
            D_800576A2 = 2;
        }
    } else if (gActiveContButton & CONT_DOWN) {
        if (D_800576A2 == 1) {
            pressed_button = CONT_DOWN;
            D_800576A2 = 2;
        }
    } else if (gActiveContButton & CONT_A) {
        if (D_800576A2 == 1) {
            pressed_button = CONT_A;
            D_800576A2 = 2;
        }
    } else if (gActiveContButton & CONT_B) {
        if (D_800576A2 == 1) {
            pressed_button = CONT_B;
            D_800576A2 = 2;
        }
    } else {
        D_800576A2 = 0;
    }
    sContActiveButton = pressed_button;
}

void func_8002BE04(void) {
    s32 sp3C;
    void* sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    void* sp28;
    s32 sp24;

    for (sp3C = 14; sp3C < 0x4E; sp3C++) {
        if (gObjects[sp3C].actionState != 0) {
            if (gObjects[sp3C].unkE6[0] == -1) {
                sp38 = gObjInfo[gObjects[sp3C].objID].animPtr;
                sp34 = gObjInfo[gObjects[sp3C].objID].unk38->unk0;
                sp30 = gObjInfo[gObjects[sp3C].objID].unk38->unk4;
                sp2C = gObjects[sp3C].Unk140[sp34];
                func_8001A488(sp2C);
                if ((D_80165290[sp2C].unk20 == 0) && (sp38 != NULL)) {
                    func_8001C0EC(sp3C, sp34, 0, sp30, sp38);
                }
            }
            if ((gObjects[sp3C].unkE6[0] == -1)) {
                if ((gObjects[sp3C].Unk140[4] == -1)) {

                    sp28 = gObjInfo[gObjects[sp3C].objID].moveSpeed;

                    sp24 = gObjInfo[gObjects[sp3C].objID].unk38->unk0;

                    if (sp28 != NULL) {
                        func_8001ABF4(sp3C, 0, sp24, sp28);
                    }
                }
            }
            func_8001CD20(sp3C);
            func_8001AD6C(sp3C);
        }
    }
}

void func_8002C144(f32 arg0, f32 arg1, f32 arg2) {
    func_80067748(arg0, arg1, arg2);
}

s32 func_8002C184(f32 x, f32 y, f32 z) {
    s32 spAC;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    UNUSED s32 sp98;
    f32 sp94;
    u8 sp93;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    s32 sp6C;
    s32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;

    func_8002C144(x, y, z);
    spAC = D_801776E0 & 1;
    sp93 = D_801776E0;
    spA8 = D_801776F0[spAC];
    spA4 = D_80177700[spAC];
    spA0 = D_80177710[spAC];
    sp9C = D_80177720[spAC];
    sp98 = D_80177730[spAC];
    sp94 = D_80177760[spAC];
    func_80016A80(D_80057664, D_80057668, D_8005766C, D_80057670, &sp8C, &sp88, &sp84, &sp80);
    func_80016A80(spA8, spA4, spA0, sp9C, &sp7C, &sp78, &sp74, &sp70);
    if ((Math_ComparePlanes(D_80057664, D_80057668, D_8005766C, D_80057670, D_801776F0[spAC], D_80177700[spAC],
                            D_80177710[spAC], D_80177720[spAC]) != 0) &&
        (sp80 < 60.0f)) {
        return 0;
    }

    if (sp93 == 0) {
        if ((sp80 < 60.0f) && (sp70 < 60.0f)) {
            if ((D_80057678 - sp94) < 30.0f) {
                return 1;
            }

            if (((sp80 != 0.0f) || (sp70 != 0.0f)) &&
                ((func_80016714(D_80057664, D_80057668, D_8005766C, D_80057670, spA8, spA4, spA0, sp9C, &sp64, &sp60,
                                &sp5C, &sp58),
                  (sp64 != 0.0f)) ||
                 (sp60 != 0.0f) || (sp5C != 0.0f) || (sp58 != 0.0f))) {
                sp6C = func_800162F0(sPlayerObjPosX, sPlayerObjPosZ, sp64, sp60, sp5C, sp58);
                sp68 = func_800162F0(x, z, sp64, sp60, sp5C, sp58);
                if (sp6C != sp68) {
                    return 1;
                }
            }
        }
        return 3;
    } else {
        if ((sp80 < 60.0f) && (sp70 < 60.0f)) {
            if ((sp94 - D_80057678) < 30.0f) {
                return 2;
            }

            if (((sp80 != 0.0f) || (sp70 != 0.0f)) &&
                ((func_80016714(D_80057664, D_80057668, D_8005766C, D_80057670, spA8, spA4, spA0, sp9C, &sp64, &sp60,
                                &sp5C, &sp58),
                  (sp64 != 0.0f)) ||
                 (sp60 != 0.0f) || (sp5C != 0.0f) || (sp58 != 0.0f))) {
                sp6C = func_800162F0(sPlayerObjPosX, sPlayerObjPosZ, sp64, sp60, sp5C, sp58);
                sp68 = func_800162F0(x, z, sp64, sp60, sp5C, sp58);

                if (sp6C != sp68) {
                    return 2;
                }
            }
        }
        return 4;
    }
}

void func_8002C92C(void) {
    s32 sp1C;

    func_8002C144(gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
    sp1C = D_801776E0 & 1;
    D_80057660 = D_801776E0;
    D_80057664 = D_801776F0[sp1C];
    D_80057668 = D_80177700[sp1C];
    D_8005766C = D_80177710[sp1C];
    D_80057670 = D_80177720[sp1C];
    D_80057674 = D_80177730[sp1C];
    D_80057678 = D_80177760[sp1C];
    sPlayerObjPosX = gPlayerObject->Pos.x;
    sPlayerObjPosY = gPlayerObject->Pos.y;
    sPlayerObjPosZ = gPlayerObject->Pos.z;
}

void func_8002CA80(void) {
    f32 player_pos_x;
    f32 player_pos_y;
    f32 player_pos_z;
    f32 player_vel_x;
    f32 player_vel_y;
    f32 player_vel_z;
    s32 sp34;
    s32 sp30;
    u8 sp2F;
    u8 sp2E;
    s32 i;
    s32 sp24;
    s32 sp20;
    f32 sp1C;
    f32 sp18;

    player_pos_x = gPlayerObject->Pos.x;
    player_pos_y = gPlayerObject->Pos.y;
    player_pos_z = gPlayerObject->Pos.z;
    player_vel_x = gPlayerObject->Vel.x;
    player_vel_y = gPlayerObject->Vel.y;
    player_vel_z = gPlayerObject->Vel.z;

    player_pos_y += player_vel_y;
    func_8002C144(player_pos_x, player_pos_y + 59.0f, player_pos_z);
    if (D_801776E0 & 1) {
        player_pos_y = D_80177760[0] - 60.0f;
    }
    func_8002C144(player_pos_x, player_pos_y, player_pos_z);
    if (D_801776E0 & 1) {
        player_pos_y = D_80177760[1];
    }
    if (D_80177760[D_801776E0 & 1] == player_pos_y) {
        sp34 = 1;
    } else {
        sp34 = 0;
    }
    player_pos_x += player_vel_x;
    player_pos_z += player_vel_z;
    sp20 = 8;
    sp2E = 0;

    for (sp30 = 0; sp30 < 30; sp30++) {
        sp2F = 0;

        for (i = 0; i < 8; i++) {
            sp24 = func_8002C184(D_8004A660[i].x + player_pos_x, D_8004A660[i].y + player_pos_y,
                                 D_8004A660[i].z + player_pos_z);
            if (sp24 == 4) {
                sp2F = sp2F | D_8004A6C0[i];
            }
        }

        sp2F = (sp2F & 0xF) | ((s32) sp2F >> 4);

        if ((sp2F == 0) && ((sp30 == 0) || (sp20 == 1))) {
            break;
        }

        if (sp2F == 0) {
            player_pos_x = sp1C;
            player_pos_z = sp18;
            sp20 = sp20 / 2;
            sp2F = sp2E;
        } else if ((sp2E != sp2F) && (sp30 != 0) && ((sp20 / 2) != 0)) {
            sp2F = sp2E;
            sp20 = sp20 / 2;
            player_pos_x = sp1C;
            player_pos_z = sp18;
        }
        sp1C = player_pos_x;
        sp18 = player_pos_z;
        sp2E = sp2F;
        player_pos_x = player_pos_x + D_8004A6CC[sp2F][0] * sp20;
        player_pos_z = player_pos_z + D_8004A6CC[sp2F][1] * sp20;
    }

    sp24 = func_8002C184(player_pos_x, player_pos_y, player_pos_z);
    if ((sp24 < 3) && (sp34 != 0)) {
        func_8002C144(player_pos_x, player_pos_y, player_pos_z);
        if (!(D_801776E0 & 1)) {
            player_pos_y = D_80177760[0];
        }
    }
    gPlayerObject->Pos.x = player_pos_x;
    gPlayerObject->Pos.y = player_pos_y;
    gPlayerObject->Pos.z = player_pos_z;
}

s32 func_8002CF78(void) {
    s32 sp1C;

    sp1C = 0;
    func_8002C144(gPlayerObject->Pos.x, gPlayerObject->Pos.y + 60.0f, gPlayerObject->Pos.z);
    if (D_801776E0 & 1) {
        sp1C |= 1;
    }
    func_8002C144(gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
    if (!(D_801776E0 & 1)) {
        if (*D_80177760 == gPlayerObject->Pos.y) {
            sp1C |= 2;
        }
    } else {
        sp1C |= 2;
    }
    return sp1C;
}

void func_8002D080(void) {
    gPlayerObject->Vel.x = sinf((f32) ((f64) gPlayerObject->moveAngle * DEG_TO_RAD)) * gPlayerObject->moveSpeed;
    gPlayerObject->Vel.z = cosf((f32) ((f64) gPlayerObject->moveAngle * DEG_TO_RAD)) * gPlayerObject->moveSpeed;
}

void Debug_HandleObjMovement(void) {
    f32 sp1C;

    func_8002C92C();
    gPlayerObject->moveAngle = Math_CalcAngleRotated(gActiveContStickX, -gActiveContStickY);
    sp1C = sqrtf((gActiveContStickX * gActiveContStickX) + (gActiveContStickY * gActiveContStickY));
    if (sp1C > 10.0f) {
        sp1C /= 2.0f;
        gPlayerObject->moveSpeed = sp1C;
        if (gPlayerObject->moveSpeed >= 20.0f) {
            gPlayerObject->moveSpeed = 20.0f;
        }
    } else {
        gPlayerObject->moveSpeed = 0.0f;
    }
    if (D_8005768A == 0) {
        if (D_80057689 == 0) {
            if (func_8002CF78() & 2) {
                if (gActiveContPressed & CONT_A) {
                    D_80057689 = 1;
                    gPlayerObject->Vel.y = 33.29999924;
                } else {
                    D_80057689 = 0;
                    gPlayerObject->Vel.y = 0.0f;
                }
            } else {
                D_80057689 = 1;
                gPlayerObject->Vel.y = 0.0f;
            }
        } else {
            if (func_8002CF78() & 1) {
                gPlayerObject->Vel.y = -gPlayerObject->Vel.y;
            }
            if (func_8002CF78() & 2) {
                D_80057689 = 0;
                gPlayerObject->Vel.y = 0.0f;
            }
        }
    } else {
        D_80057689 = 0;
        gPlayerObject->Vel.y = 0.0f;
        if (!(gActiveContButton & CONT_G)) {
            if (sContActiveButton & CONT_A) {
                gPlayerObject->Vel.y = 10.0f;
            } else if (sContActiveButton & CONT_B) {
                gPlayerObject->Vel.y = -10.0f;
            }
        }
    }
    if (D_80057689 == 1) {
        gPlayerObject->Vel.y = (f32) ((f64) gPlayerObject->Vel.y - 2.083333);
        if (gPlayerObject->Vel.y <= -48.0f) {
            gPlayerObject->Vel.y = -48.0f;
        }
    }
    gPlayerObject->Rot.y = (f32) D_80057694;
    func_8002D080();
    if (D_8005768A == 2) {
        gPlayerObject->Pos.x += gPlayerObject->Vel.x;
        gPlayerObject->Pos.y += gPlayerObject->Vel.y;
        gPlayerObject->Pos.z += gPlayerObject->Vel.z;
    } else {
        func_8002CA80();
    }
    func_8001CD20(0);
    func_8001AD6C(0);
}

void func_8002D538(void) {
    struct ObjSpawnInfo* sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    UNUSED s32 pad;
    struct UnkStruct_80026548_SP24* sp30;
    u32 sp2C;
    s32 sp28;
    u32* sp24;
    void* sp20;

    func_8001EC04();

    for (sp28 = 0; sp28 < 0xF4240; sp28++)
        ;

    Set_DecompressHeap((s32*) 0x80280000);
    sp30 = gObjInfo[D_80057690].unk24;

    for (sp2C = 1; (s32) sp2C < 2; sp2C++) {
        DecompressFile(sp2C, sp30->unk4, sp30->unk8);

        if (sp30->unk2 == 0) {
            break;
        }

        sp30++;
    }
    sp44 = gObjInfo[D_80057690].unk38;
    sp24 = gObjInfo[D_80057690].animPtr;
    sp20 = gObjInfo[D_80057690].moveSpeed;
    sp40 = 0;
    func_8001A958(sp40);
    sp3C = (s32) sp44->unk0;
    sp38 = (s32) sp44->unk6;
    func_8001BD44(sp40, sp3C, sp38, (s32) gFileArray[1].ptr);
    gPlayerObject->objID = sp44->unk2;
    gPlayerObject->actionState = 1;
    if (sp24 != NULL) {
        func_8001C0EC(sp40, sp3C, 0, 1, sp24);
    }
    if (sp20 != NULL) {
        func_8001ABF4(sp40, 0, sp3C, sp20);
    }
    func_8001EBE8();
}

void func_8002D768(void) {
    s32 sp1C;

    sp1C = 0;
    if (gActiveContButton & CONT_G) {
        if (gActiveContPressed & CONT_A) {
            sp1C = 1;
        } else if (gActiveContButton & CONT_B) {
            sp1C = -1;
        }
        if (gActiveContButton & CONT_R) {
            sp1C *= 0xA;
        }
    }
    if (sp1C != 0) {
        while (TRUE) {
            D_80057690 += sp1C;

            if (D_80057690 < 0x20) {
                D_80057690 = 0x287;
            } else if (D_80057690 >= 0x288) {
                D_80057690 = 0x20;
            }

            if (gObjInfo[D_80057690].unk38 != 0) {
                break;
            }
        }

        D_80057694 = 0;
        D_80057696 = 0;
        D_80057698 = 0;
        D_8005769A = 0;
        sSetModeMenuOption = 4;
        func_8002D538();
    }
}

void func_8002D8FC(void) {
    if ((sDebugSetModeMenu == MAIN_MENU) && (func_8001C1A8(0, 0) != 0)) {
        func_8001838C();
        func_8001B234(0, 0, 1);
        func_8001C384(0, 0);
    }
}

void func_8002D968(void) {
    if ((sDebugSetModeMenu == 0) && (func_8001C1A8(0, 3) != 0)) {
        func_8001838C();
        func_8001B234(0, 3, 1);
        func_8001C384(0, 3);
    }
}

void func_8002D9D4(void) {
    struct UnkStruct_80026548_SP24* sp24;
    s32 sp20;
    s32 line;
    s32 sp18;

    if (gActiveContPressed & CONT_START) {
        line = func_8002B830();
        if (line != -1) {
            D_800576A8[line].unk0 = D_80057690;
            D_800576A8[line].unk2 = (s16) (s32) gPlayerObject->Pos.x;
            D_800576A8[line].unk4 = (s16) (s32) gPlayerObject->Pos.y;
            D_800576A8[line].unk6 = (s16) (s32) gPlayerObject->Pos.z;
            D_800576A8[line].unk8 = D_80057694;
            D_800576A8[line].unkA = D_80057696;
            D_800576A8[line].unkC = D_80057698;
            D_800576A8[line].unkE = D_8005769A;
            D_80165118[line] = 1;

            DEBUG_PRINTF("<Set> line=%d MemoryAD=%x\n", line, D_8005768C);
            func_8001EC04();
            for (sp18 = 0; sp18 < 0xF4240; sp18++)
                ;

            Set_DecompressHeap((s32*) D_8005768C);
            sp24 = gObjInfo[D_80057690].unk24;

            for (sp20 = 1; sp20 < 10; sp20++) {
                if (gFileArray[sp24->unk0].ptr == NULL) {
                    DecompressFile((u32) sp24->unk0, sp24->unk4, sp24->unk8);
                }

                if (sp24->unk2 == 0) {

                    break;
                }

                sp24++;
            }

            D_8005768C = Get_DecompressHeap();
            func_8001EBE8();
            func_8002E8B4();
        }
    }
}

void Debug_Parse_SetModeMenuOptions(void) {
    if (sContActiveButton & CONT_UP) {
        if ((--sSetModeMenuOption) < 0) {
            sSetModeMenuOption = 9;
        }
    } else if (sContActiveButton & CONT_DOWN) {
        if ((++sSetModeMenuOption) >= 0xA) {
            sSetModeMenuOption = 0;
        }
    }

    switch (sSetModeMenuOption) {
        case SET_MODE_OPTION_1:
            if (sContActiveButton & CONT_RIGHT) {
                gPlayerObject->Pos.x += 1.0f;
            } else if (sContActiveButton & CONT_LEFT) {
                gPlayerObject->Pos.x -= 1.0f;
            }
            break;
        case SET_MODE_OPTION_2:
            if (sContActiveButton & CONT_RIGHT) {
                gPlayerObject->Pos.y += 1.0f;
            } else if (sContActiveButton & CONT_LEFT) {
                gPlayerObject->Pos.y -= 1.0f;
            }
            break;
        case SET_MODE_OPTION_3:
            if (sContActiveButton & CONT_RIGHT) {
                gPlayerObject->Pos.z += 1.0f;
            } else if (sContActiveButton & CONT_LEFT) {
                gPlayerObject->Pos.z -= 1.0f;
            }
            break;
        case SET_MODE_OPTION_ADJUST:
            if ((gActiveContPressed & CONT_RIGHT) || (gActiveContPressed & CONT_LEFT)) {
                gPlayerObject->Pos.x = (f32) (((s32) gPlayerObject->Pos.x / 30) * 0x1E);
                gPlayerObject->Pos.z = (f32) (((s32) gPlayerObject->Pos.z / 30) * 0x1E);
            }
            break;
        case SET_MODE_OPTION_ANGLE:
            if (sContActiveButton & 0x100) {
                D_80057694 += 1;
            } else if (sContActiveButton & 0x200) {
                D_80057694 -= 1;
            }
            break;
        case SET_MODE_OPTION_PRM1:
            if (sContActiveButton & 0x100) {
                D_80057696 += 1;
            } else if (sContActiveButton & 0x200) {
                D_80057696 -= 1;
            }
            break;
        case SET_MODE_OPTION_PRM2:
            if (sContActiveButton & 0x100) {
                D_80057698 += 1;
            } else if (sContActiveButton & 0x200) {
                D_80057698 -= 1;
            }
            break;
        case SET_MODE_OPTION_PRM3:
            if (sContActiveButton & CONT_RIGHT) {
                D_8005769A += 1;
            } else if (sContActiveButton & CONT_LEFT) {
                D_8005769A -= 1;
            }
            break;
        case SET_MODE_OPTION_MOVE:
            func_8002C144(gPlayerObject->Pos.x, gPlayerObject->Pos.y + 60.0f, gPlayerObject->Pos.z);
            if ((D_801776E0 & 1) == 0) {
            if (sContActiveButton & 0x200) {
                if ((--D_8005768A) < 0) {
                    D_8005768A = 2;
                }
            } else if (sContActiveButton & 0x100) {
                if ((++D_8005768A) > 2) {
                    D_8005768A = 0;
                }
            }
        }
            break;
    }
}

void func_8002E23C(void) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    if (func_8002BA34() != 0) {
        return;
    }
    sp24 = (s32) D_80057692;
    if ((D_800576A8[D_80057692].unk0 == -1) ||
        ((D_800576A8[D_80057692].unk2 == 0x7530) && (D_800576A8[D_80057692].unk4 == 0x7530) &&
         (D_800576A8[D_80057692].unk6 == 0x7530))) {
        return;
    }
    if (gActiveContPressed & CONT_START) {
        sp20 = func_8002B894(sp24);
        if (sp20 != -1) {
            for (sp1C = 0; sp1C < 10; sp1C++) {
                if (gObjects[sp20].unkE8[sp1C] != -1) {
                    func_8001A928(gObjects[sp20].unkE8[sp1C]);
                }
            }
            func_8001A928(sp20);
        }
        gPlayerObject->Pos.x = D_800576A8[sp24].unk2;
        gPlayerObject->Pos.y = D_800576A8[sp24].unk4;
        gPlayerObject->Pos.z = D_800576A8[sp24].unk6;
        D_80057690 = D_800576A8[sp24].unk0;
        func_8002D538();
        DEBUG_PRINTF("<Reset> line=%d\n", D_80057692);
        D_800576A8[sp24].unk0 = -1;
        D_800576A8[sp24].unk2 = 0;
        D_800576A8[sp24].unk4 = 0;
        D_800576A8[sp24].unk6 = 0;
        D_800576A8[sp24].unk8 = 0;
        D_800576A8[sp24].unkA = 0;
        D_800576A8[sp24].unkC = 0;
        D_800576A8[sp24].unkE = 0;
        D_80165118[sp24] = 0;
        func_8002E8B4();
    }
}

void func_8002E524(void) {
    s32 sp24;
    UNUSED s32 pad;
    s32 sp1C;

    if (func_8002BA34() != 0) {
        return;
    }
    sp24 = 0;
    if (gActiveContButton & CONT_G) {
        if (gActiveContPressed & CONT_A) {
            sp24 = 1;
        } else if (gActiveContPressed & CONT_B) {
            sp24 = -1;
        }
    }

    if (sp24 != 0) {
        while (TRUE) {

            D_80057692 += sp24;

            if (D_80057692 < 0) {
                D_80057692 = 0x7F;
            } else if (D_80057692 >= 0x80) {
                D_80057692 = 0;
            }

            if ((D_800576A8[D_80057692].unk0 != -1 && D_800576A8[D_80057692].unk2 != 0x7530 &&
                 D_800576A8[D_80057692].unk4 != 0x7530 && D_800576A8[D_80057692].unk6 != 0x7530)) {
                break;
            }
        }
    }

    func_8002B9B8();

    sp1C = func_8002B894((s32) D_80057692);

    if (sp1C != -1) {
        func_8001BB34(sp1C, (u8) D_8005769E & 1);
        D_8005769E = (u8) D_8005769E + 1;
    }
}

void Debug_SaveMode(void) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    if (gActiveContPressed & 0x1000) {
        DEBUG_PRINTF("<SAVE>\n");

        for (sp34 = 0; sp34 < 128; sp34++) {

            sp2C = (s32) D_800576A8[sp34].unk0;

            if ((sp2C != -1) && (D_800576A8[sp34].unk2 != 0x7530)) {

                DEBUG_PRINTF("  ");

                for (sp30 = 0; sp30 < OBJ_NAME_LEN; sp30++) {
                    if (gObjInfo->objName[(sp2C * 0x60) + sp30] == ' ') {
                        break;
                    }
                    DEBUG_PRINTF("%c", gObjInfo->objName[(sp2C * 96) + sp30]);
                }

                DEBUG_PRINTF(",");

                for (; sp30 < OBJ_NAME_LEN; sp30++) {
                    DEBUG_PRINTF(" ");
                }

                DEBUG_PRINTF("%6d,%6d,%6d,0x%04x,0x%04x,0x%04x,0x%04x,\n", D_800576A8[sp34].unk2, D_800576A8[sp34].unk4,
                             D_800576A8[sp34].unk6, (s32) D_800576A8[sp34].unk8, (s32) D_800576A8[sp34].unkA,
                             (s32) D_800576A8[sp34].unkC, (s32) D_800576A8[sp34].unkE);
            }
        }
    }
}

void func_8002E8B4(void) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    DEBUG_PRINTF("<SAVE>\n");
    for (sp34 = 0; sp34 < 0x80; sp34++) {
        sp2C = (s32) D_800576A8[sp34].unk0;
        if ((sp2C != -1) && (D_800576A8[sp34].unk2 != 0x7530)) {
            DEBUG_PRINTF("  ");
            for (sp30 = 0; sp30 < OBJ_NAME_LEN; sp30++) {
                if (gObjInfo->objName[(sp2C * 0x60) + sp30] == 0x20) {
                    break;
                }
                DEBUG_PRINTF("%c", gObjInfo->objName[(sp2C * 0x60) + sp30]);
            }
            DEBUG_PRINTF(",");
            for (; sp30 < OBJ_NAME_LEN; sp30++) {
                DEBUG_PRINTF(" ");
            }
            DEBUG_PRINTF("%6d,%6d,%6d,0x%04x,0x%04x,0x%04x,0x%04x,\n", D_800576A8[sp34].unk2, D_800576A8[sp34].unk4,
                         D_800576A8[sp34].unk6, (s32) D_800576A8[sp34].unk8, (s32) D_800576A8[sp34].unkA,
                         (s32) D_800576A8[sp34].unkC, (s32) D_800576A8[sp34].unkE);
        }
    }
}

void func_8002EA68(void) {
    if (gActiveContPressed & CONT_L) {
        sDebugSetModeMenu += 1;
        if (sDebugSetModeMenu >= 3) {
            sDebugSetModeMenu = 0;
        }
        if (sDebugSetModeMenu == 0) {
            sSetModeMenuOption = 4;
            D_80057694 = 0;
            D_80057696 = 0;
            D_80057698 = 0;
            D_8005769A = 0;
            func_8002B9B8();
        } else if (sDebugSetModeMenu == 1) {
            D_80057692 = 0;
        } else if (sDebugSetModeMenu == 2) {
        }
    }
}

void Debug_SetMode_Menu(void) {
    char sp27;
    s32 sp20;
    f32 sp1C;

    func_8002C144(gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
    sp1C = D_80177760[D_801776E0 & 1];
    sprintf((char*) gDebugTextBuf, "SET MODE");
    Debug_PrintXY(0x20, 0x10);
    sprintf((char*) gDebugTextBuf, "CHR=%d", D_80057690);
    Debug_PrintXY(0x20, 0x20);

    for (sp20 = 0; sp20 < OBJ_NAME_LEN; sp20++) {
        sp27 = gObjInfo[D_80057690].objName[sp20];
        sprintf((char*) gDebugTextBuf, "%c", sp27);
        Debug_PrintXY((sp20 * 8) + 0x60, 0x20);
    }
    sprintf((char*) gDebugTextBuf, "X=%d", (s32) gPlayerObject->Pos.x);
    Debug_PrintXY(0x20, 0x30);
    sprintf((char*) gDebugTextBuf, "Y=%d(%d)", (s32) gPlayerObject->Pos.y, (s32) (gPlayerObject->Pos.y - sp1C));
    Debug_PrintXY(0x20, 0x40);
    sprintf((char*) gDebugTextBuf, "Z=%d", (s32) gPlayerObject->Pos.z);
    Debug_PrintXY(0x20, 0x50);
    sprintf((char*) gDebugTextBuf, "ADJUST");
    Debug_PrintXY(0x20, 0x60);
    sprintf((char*) gDebugTextBuf, "ANGLE=%u(0x%X)", D_80057694, D_80057694);
    Debug_PrintXY(0x20, 0x70);
    sprintf((char*) gDebugTextBuf, "PRM1=%u(0x%X)", D_80057696, D_80057696);
    Debug_PrintXY(0x20, 0x80);
    sprintf((char*) gDebugTextBuf, "PRM2=%u(0x%X)", D_80057698, D_80057698);
    Debug_PrintXY(0x20, 0x90);
    sprintf((char*) gDebugTextBuf, "PRM3=%u(0x%X)", D_8005769A, D_8005769A);
    Debug_PrintXY(0x20, 0xA0);
    sprintf((char*) gDebugTextBuf, "MOVE=%d", D_8005768A);
    Debug_PrintXY(0x20, 0xB0);
    sprintf((char*) gDebugTextBuf, "=");
    Debug_PrintXY(0x18, (sSetModeMenuOption * 0x10) + 0x20);
}

void Debug_ResetMode_Menu(void) {
    sprintf((char*) &gDebugTextBuf, "RESET MODE : LINE=%d", D_80057692);
    Debug_PrintXY(32, 16);
}

void Debug_SaveMode_Menu(void) {
    sprintf((char*) &gDebugTextBuf, "SAVE MODE");
    Debug_PrintXY(32, 16);
    sprintf((char*) &gDebugTextBuf, "PRESS START BUTTON");
    Debug_PrintXY(88, 100);
}

void Debug_ParseSetModeMenu(void) {
    Debug_SetTextColor(255, 255, 255);
    switch (sDebugSetModeMenu) {
        case MAIN_MENU:
            Debug_SetMode_Menu();
            break;
        case RESET_MODE_MENU:
            Debug_ResetMode_Menu();
            break;
        case SAVE_MODE_MENU:
            Debug_SaveMode_Menu();
            break;
    }
    stub_8005FA90();
}

void Debug_SetupSetMode(void) {
    struct UnkStruct80108238* sp1C;
    s32 i;

    sDebugSetModeMenu = 0;
    D_80057689 = 0;
    D_8005768A = 1;
    D_80057690 = 32;
    D_8005769E = 0;
    D_80057692 = 0;
    D_80057694 = 0;
    D_80057696 = 0;
    D_80057698 = 0;
    D_8005769A = 0;
    sSetModeMenuOption = 0;
    D_800576A2 = 0;

    for (i = 0; i < 700; i++) {
        gFileArray[i].ptr = NULL;
    }
    Set_DecompressHeap((s32*) 0x8024C000);
    LoadFile(0, (void*) &unk_bin_0_2_ROM_START, (void*) &unk_bin_0_2_ROM_END);
    gPlayerObject = &PLAYER_OBJ;
    func_80019C84();
    func_80019D2C();
    func_8001A258();
    func_80088B80();
    Set_DecompressHeap((s32*) 0x802D0000);
    sp1C = D_80108238[gCurrentLevel];
    DecompressFile(0x1C, sp1C->unk4, sp1C->unk8);
    func_8001EB68(0x1B, (void*) sp1C->unkC, (void*) sp1C->unk10);
    func_80000FF4(gCurrentLevel);
    func_8006707C();
    func_800695A0();
    func_8006E088();
    func_8002629C();
    gLevelInfo[gCurrentLevel]->unk24();
    gLevelInfo[gCurrentLevel]->unk28();
    func_8002B670();
    D_8005768C = Get_DecompressHeap();
    func_8002D538();
    gPlayerObject->Pos.x = D_80108238[gCurrentLevel]->unk0[0];
    gPlayerObject->Pos.y = D_80108238[gCurrentLevel]->unk0[1];
    gPlayerObject->Pos.z = D_80108238[gCurrentLevel]->unk0[2];
    gPlayerObject->Rot.x = 0.0f;
    gPlayerObject->Rot.y = 0.0f;
    gPlayerObject->Rot.z = 0.0f;
    gCameraType = 1;
    func_80076458();
    Set_BgColor(-1, -1, -1, 0x10);
    func_8001D284();
}

void func_8002F32C(void) {
    f32 sp6C;
    Matrix sp2C;

    UpdateActiveController(FALSE);

    if ((gCameraType == 1) || (gCameraType == 5)) {
        guRotateF(sp2C, gView.rot.y, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(sp2C, gActiveContStickX, 0.0f, gActiveContStickY, &gActiveContStickX, &sp6C, &gActiveContStickY);
    }
    func_8002BAC8(); // Update active cont button?
    func_8002EA68();
    if (sDebugSetModeMenu == MAIN_MENU) {
        func_8002D768();
        Debug_HandleObjMovement();
        Debug_Parse_SetModeMenuOptions();
        func_8002D9D4();
    } else if (sDebugSetModeMenu == RESET_MODE_MENU) {
        func_8002E524();
        func_8002E23C();
    } else if (sDebugSetModeMenu == SAVE_MODE_MENU) {
        Debug_SaveMode();
    }
    func_80026548();
    func_8002BE04();
    func_800663EC();
    func_800654AC();
    Handle_ObjView();
    if (sDebugSetModeMenu == MAIN_MENU) {
        Set_ObjView(gPlayerObject->Pos.x, gPlayerObject->Pos.y + 100.0f, gPlayerObject->Pos.z);
    } else if ((sDebugSetModeMenu == 1) && (D_800576A8[D_80057692].unk0 != -1)) {
        if ((D_800576A8[D_80057692].unk2 != 0x7530) && (D_800576A8[D_80057692].unk4 != 0x7530) &&
            (D_800576A8[D_80057692].unk6 != 0x7530)) {
            Set_ObjView((f32) D_800576A8[D_80057692].unk2, (f32) D_800576A8[D_80057692].unk4,
                        (f32) D_800576A8[D_80057692].unk6);
        }
    }
    func_8001994C();
}

void func_8002F598(void) {
    u16 persp;
    UNUSED u16 pad1;
    UNUSED u16 sp3E;

    func_8001D4D0();
    Debug_SetBg(TRUE, 60, 60, 60);
    guPerspective(D_8016E104->unk00, &persp, 50.0f, 1.3333334f, 100.0f, 20000.0f, 1.0f);
    gSPPerspNormalize(gMasterDisplayList++, persp);
    guLookAt(&D_8016E104->unk00[2], gView.eye.x, gView.eye.y, gView.eye.z, gView.at.x, gView.at.y, gView.at.z,
             gView.up.x, gView.up.y, gView.up.z);
    gSPMatrix(gMasterDisplayList++, D_8016E104, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    D_8016E3A4 = 0;
    func_8002D8FC();
    func_8001C464();
    func_8001C70C();
    func_8002D968();
    func_8001C5B8();
    func_8001C96C();
    Debug_ParseSetModeMenu();
}

void func_8002F738(void) {
    func_8001ECB8();
    gDebugRoutine1 = &func_8002F598;
    gDebugRoutine2 = &func_8002F32C;
    Debug_SetupSetMode();
    func_80000964();
}
