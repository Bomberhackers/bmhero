#include "common.h"
#include "BE560.h"

//.rodata
const s16 D_80114FE0[4] = { -0x1E, -0x1E, 0x1E, 0x1E }; /* const */
const s16 D_80114FE8[4] = { 0x1E, -0x1E, 0x1E, -0x1E }; /* const */

void func_800CC040(void) {
    s32 sp24;
    s32 sp20;

    if (func_80026260(D_8016519C) != 1) {
        sp24 =
            func_80027464(3, &D_8011400C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, 0.0f);
        if (sp24 != -1) {
            sp20 = gObjects[sp24].unkE8[1];
            gObjects[sp20].Pos.x = 3630.0f;
            gObjects[sp20].Pos.y = 0.0f;
            gObjects[sp20].Pos.z = 30.0f;
        }
    } else {
        sp24 =
            func_80027464(1, &D_80114030, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, 0.0f);
        if (sp24 != -1) {
            gObjects[sp24].actionState = 3;
        }
    }
}

void func_800CC220(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp4->unk132 = 0;
        sp4->actionState = 2;
    }
    if ((D_80177A64 == 1) && (sp4->actionState == 1) && (sp4->unkA8 == 0)) {
        sp4->unkA8 = 0xA;
        sp4->damageState = 0x32;
    }
}

void func_800CC2E0(void) {
    struct ObjectStruct* sp44;
    s32 sp40;
    s32 sp3C;
    UNUSED char pad[0x4];

    sp44 = &gObjects[gCurrentParsedObject];
    sp40 = gObjects[gCurrentParsedObject].unkE8[0];
    sp3C = gObjects[gCurrentParsedObject].unkE8[1];
    if (sp44->unk132 == 0) {
        sp44->unk132 += 1;
        sp44->unkA6 = 0x14;
        sp44->unkA8 = 0;
        sp44->Vel.x = sp44->Vel.y = sp44->Vel.z = 0.0f;
        gObjects[sp40].Vel.x = gObjects[sp40].Vel.y = gObjects[sp40].Vel.z = 0.0f;
        gObjects[sp3C].Vel.x = gObjects[sp3C].Vel.y = gObjects[sp3C].Vel.z = 0.0f;
        gObjects[sp3C].Rot.y = 90.0f;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x7B, &D_80118258);
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_80118284);
        func_8001C0EC(sp40, 0, 0, 0x7C, &D_801182BC);
        func_8001C0EC(sp3C, 3, 0, 0x7D, &D_801182C0);
        func_800176F4(gCurrentParsedObject, 0, 0x62, -1, 0);
    }
    if (sp44->damageState >= 2) {
        func_8001BB34(gCurrentParsedObject, !(sp44->damageState & 1));
    } else {
        func_8001BB34(gCurrentParsedObject, 0);
    }
    if (sp44->unkA8 != 0) {
        sp44->unkA8 -= 1;
        sp44->unkA6 -= 1;
    }
    gObjects[sp40].Rot.y = Math_WrapAngle(gObjects[sp40].Rot.y, (f32) sp44->unkA6);
}

void func_800CC6D8(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    s32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    sp30 = gObjects[gCurrentParsedObject].unkE8[0];
    sp2C = gObjects[gCurrentParsedObject].unkE8[1];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->damageState = 0x1E;
        func_800281A4(gCurrentParsedObject, 0);
        func_8002B0E4(sp30);
        func_80017B3C(gCurrentParsedObject, 0);
        func_800175F0(gCurrentParsedObject, 0, 0x63, -1, 0);
    }
    if (sp34->damageState >= 2) {
        func_8001BB34(gCurrentParsedObject, !(sp34->damageState & 1));
        if (gObjects[gCurrentParsedObject].unkE8[1] != -1) {
            gObjects[sp2C].Scale.x = (f32) ((f64) gObjects[sp2C].Scale.x - 0.04);
            gObjects[sp2C].Scale.y = (f32) ((f64) gObjects[sp2C].Scale.y - 0.04);
            gObjects[sp2C].Scale.z = (f32) ((f64) gObjects[sp2C].Scale.z - 0.04);
            if (gObjects[sp2C].Scale.x <= 0.0f) {
                func_800281A4(gCurrentParsedObject, 1);
                func_8002B0E4(sp2C);
            }
        }
    } else {
        func_8001BB34(gCurrentParsedObject, 0);
        if (gObjects[gCurrentParsedObject].unkE8[1] != -1) {
            func_800281A4(gCurrentParsedObject, 1);
            func_8002B0E4(sp2C);
        }
        sp34->unk132 = 0;
        sp34->actionState = 3;
    }
}

void func_800CCA28(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        sp1C->damageState = 0;
        func_8001ABF4(gCurrentParsedObject, 0, 3, &D_80118284 + 7);
        func_800261E8(gCurrentParsedObject, 1);
    }
}

void func_800CCAE0(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_800CC2E0();
            break;
        case 2:
            func_800CC6D8();
            break;
        case 3:
            func_800CCA28();
            break;

        default:
            break;
    }
}

void func_800CCB90(void) {
    s32 sp24;
    s32 sp20;

    sp24 = func_80027464(4, &D_8011406C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        sp20 = gObjects[sp24].unkE8[1];
        gObjects[sp20].Pos.y += 40.0f;
        gObjects[sp24].unkB6 = D_80165100->unkA;
        gObjects[sp24].unkB8 = D_80165100->unkC;
    }
}

void func_800CCCE4(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 9;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800CCD5C(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    sp3C = &gObjects[gCurrentParsedObject];
    sp38 = gObjects[gCurrentParsedObject].unkE8[0];
    sp34 = gObjects[gCurrentParsedObject].unkE8[1];
    sp30 = gObjects[gCurrentParsedObject].unkE8[2];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unkC0 = 0;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z = 0.0f;
        gObjects[sp38].Vel.x = gObjects[sp38].Vel.y = gObjects[sp38].Vel.z = 0.0f;
        gObjects[sp34].Vel.x = gObjects[sp34].Vel.y = gObjects[sp34].Vel.z = 0.0f;
        gObjects[sp30].Vel.x = gObjects[sp30].Vel.y = gObjects[sp30].Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x8C, &D_801182D4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011830C);
        func_8001BBDC(gCurrentParsedObject, 1);
        sp3C->damageState = -1;
        func_8001C0EC(sp38, 0, 0, 0x8D, &D_80118344);
        func_8001C0EC(sp34, 3, 1, 0x8E, &D_80118348);
        func_8001ABF4(sp34, 0, 3, &D_80118378 + 7);
        func_8001C0EC(sp30, 3, 0, 0x90, &D_80118418);
        func_8001ABF4(sp30, 0, 3, &D_801184A4);
        func_8001ABF4(sp30, 1, 3, &D_801184A4 + 7);
        func_8001ABF4(sp30, 2, 3, &D_801184A4 + 14);
        func_8001ABF4(sp30, 3, 3, &D_801184A4 + 21);
        func_8001BBDC(sp30, 1);
        func_8001BB34(sp30, 1);
        gObjects[sp30].damageState = 0;
    }
    if (func_8002A1FC(gCurrentParsedObject, 1000.0f) != 0) {
        sp3C->actionState = 3;
        sp3C->unk132 = 0;
    }
}

void func_800CD1D4(void) {
}

void func_800CD1E4(void) {
    struct ObjectStruct* sp1C;
    s32 sp18;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011830C);
        sp1C->damageState = -1;
    }
    if (sp1C->unkC0 == 0) {
        sp18 = 0xE;

        while (TRUE) {
            sp18 = Get_ObjIdx_ByPos(0x10E, sp18);
            if (sp18 == -1) {
                break;
            } else if (gObjects[sp18].unkB6 == sp1C->unkB6) {
                gObjects[sp18].unk132 = 0;
                gObjects[sp18].actionState = 2;
                break;
            } else {
                sp18 += 1;
            }
        }
        sp1C->unk132 = 0;
        sp1C->actionState = 4;
    } else if (sp1C->unkC0 == 1) {
        sp18 = 0xE;

        while (TRUE) {
            sp18 = Get_ObjIdx_ByPos(0x10E, sp18);
            if (sp18 == -1) {
                break;
            } else if (gObjects[sp18].unkB6 == sp1C->unkB8) {
                gObjects[sp18].unk132 = 0;
                gObjects[sp18].actionState = 2;
                break;
            } else {
                sp18 += 1;
            }
        }
        sp1C->unk132 = 0;
        sp1C->actionState = 4;
    } else {
        sp1C->unk132 = 0;
        sp1C->actionState = 5;
        sp1C->unkBA = 0;
    }
    sp1C->unkC0 += 1;
    if (sp1C->unkC0 == 3) {
        sp1C->unkC0 = 0;
    }
}

void func_800CD528(void) {
    struct ObjectStruct* sp4;
    s32 sp0;

    sp4 = &gObjects[gCurrentParsedObject];
    sp0 = gObjects[gCurrentParsedObject].unkE8[0];
    if (sp4->unk132 == 0) {
        sp4->unk132 += 1;
        sp4->unkBC = 0x32;
        sp4->unkBE = 4;
    }
    if ((sp4->unkBC != 0) && (sp4->unkC0 == 1)) {
        gObjects[sp0].Pos.y += 2.0f;
        if (sp4->unkBC == 0x28) {
            sp4->damageState = 1;
        }
    }
    if ((sp4->unkBC != 0x32) && (sp4->unkC0 == 2)) {
        gObjects[sp0].Pos.y -= 2.0f;
        if (sp4->unkBC == 0xA) {
            sp4->damageState = -1;
        }
    }
    if (sp4->unkBC == 0) {
        sp4->actionState = 0xA;
        sp4->unk132 = 0;
    } else {
        sp4->unkBC -= 1;
    }
}

void func_800CD738(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 += 1;
        sp4->unkA6 = 0x1E;
        sp4->unkBE = 0xA;
    }
    if (sp4->unkA6 == 0) {
        sp4->actionState = 3;
        sp4->unk132 = 0;
    } else {
        sp4->unkA6 -= 1;
    }
}

void func_800CD808(void) {
    struct ObjectStruct* sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    f32 sp4C;
    f32 sp48;

    sp5C = &gObjects[gCurrentParsedObject];
    sp58 = (s32) gObjects[gCurrentParsedObject].unkE8[0];
    sp54 = (s32) gObjects[gCurrentParsedObject].unkE8[1];
    sp50 = (s32) gObjects[gCurrentParsedObject].unkE8[2];
    if (sp5C->unk132 == 0) {
        sp5C->unk132 += 1;
        sp5C->unkA6 = 0x14;
        sp5C->unk44 = 5.0f;
        sp5C->moveAngle = 0.0f;
        gObjects[sp58].unkA6 = (s16) (s32) (gObjects[sp58].Pos.y - sp5C->Pos.y);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x8C, &D_801182D4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011830C);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    sp5C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_800295C0(gCurrentParsedObject, &sp4C, &sp48, 0.0f, 0.0f, 0.0f) != 0) {
        sp5C->Pos.y = sp48;
    } else {
        sp5C->Pos.y = sp4C;
    }

    gObjects[sp58].Pos.x = gObjects[sp54].Pos.x = gObjects[sp50].Pos.x = sp5C->Pos.x;

    gObjects[sp58].Pos.y = (f32) gObjects[sp58].unkA6 + sp5C->Pos.y;
    gObjects[sp54].Pos.y = sp5C->Pos.y + 40.0f;
    gObjects[sp50].Pos.y = sp5C->Pos.y;

    gObjects[sp58].Pos.z = gObjects[sp54].Pos.z = gObjects[sp50].Pos.z = sp5C->Pos.z;

    gObjects[sp58].Rot.y = gObjects[sp54].Rot.y = gObjects[sp50].Rot.y = sp5C->Rot.y;

    gObjects[sp58].moveAngle = gObjects[sp54].moveAngle = gObjects[sp50].moveAngle = sp5C->moveAngle;
    if ((sp5C->unkA6 - sp5C->unkBA) == 0) {
        sp5C->unk44 = 0.0f;

        sp5C->Vel.x = sp5C->Vel.y = sp5C->Vel.z = 0.0f;

        gObjects[sp58].Vel.x = gObjects[sp58].Vel.y = gObjects[sp58].Vel.z = 0.0f;

        gObjects[sp54].Vel.x = gObjects[sp54].Vel.y = gObjects[sp54].Vel.z = 0.0f;

        gObjects[sp50].Vel.x = gObjects[sp50].Vel.y = gObjects[sp50].Vel.z = 0.0f;
        sp5C->unkBA = 0;
        sp5C->actionState = 6;
        sp5C->unk132 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x8C, &D_801182D4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011830C + 7);
        func_800175F0(gCurrentParsedObject, 0, 1, -1, 0);
    } else {
        sp5C->unkBA += 1;
    }
}

void func_800CDFD4(void) {
    struct ObjectStruct* sp2C;
    s32 sp28;
    s32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    sp28 = gObjects[gCurrentParsedObject].unkE8[0];
    sp24 = gObjects[gCurrentParsedObject].unkE8[2];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkAA = 0;
        sp2C->unkA6 = sp2C->unkA8 = sp2C->unkAA;
    }
    if (sp2C->unkAA != 0) {
        if (sp2C->unkA8 == 0) {
            if (sp2C->moveAngle == 30.0f) {
                sp2C->unkA8 += 1;
            } else {
                sp2C->moveAngle += 1.0f;
                sp2C->Rot.y = sp2C->moveAngle;
            }
        } else if (sp2C->unkA8 == 1) {
            if (sp2C->moveAngle == 0.0f) {
                sp2C->unkA8 += 1;
                sp2C->Rot.y = 359.0f;
                sp2C->moveAngle = sp2C->Rot.y;
            } else {
                sp2C->moveAngle -= 1.0f;
                sp2C->Rot.y = sp2C->moveAngle;
            }
        } else if (sp2C->unkA8 == 2) {
            if (sp2C->moveAngle == 330.0f) {
                sp2C->unkA8 += 1;
            } else {
                sp2C->moveAngle -= 1.0f;
                sp2C->Rot.y = sp2C->moveAngle;
            }
        } else if (sp2C->unkA8 == 3) {
            if (sp2C->moveAngle == 359.0f) {
                sp2C->unkA8 += 1;
                sp2C->Rot.y = 0.0f;
                sp2C->moveAngle = sp2C->Rot.y;
            } else {
                sp2C->moveAngle += 1.0f;
                sp2C->Rot.y = sp2C->moveAngle;
            }
        }
        gObjects[sp28].moveAngle = sp2C->moveAngle;
        gObjects[sp28].Rot.y = sp2C->Rot.y;
        gObjects[sp24].moveAngle = sp2C->moveAngle;
        gObjects[sp24].Rot.y = sp2C->Rot.y;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp2C->unkA8 == 4) {
            sp2C->actionState = 7;
            sp2C->unk132 = 0;
            func_8001BBDC(gCurrentParsedObject, 1);
            func_8001BBDC(sp24, 1);
            func_8001BB34(sp24, 1);
            gObjects[sp24].damageState = 0;
        } else if (sp2C->unkA8 == 0) {
            func_8001BBDC(sp24, 0);
            func_8001BB34(sp24, 0);
            gObjects[sp24].damageState = -1;
            sp2C->unkAA = 1;
        }
    }
}

void func_800CE51C(void) {
    struct ObjectStruct* sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    f32 sp4C;
    f32 sp48;

    sp5C = &gObjects[gCurrentParsedObject];
    sp58 = (s32) gObjects[gCurrentParsedObject].unkE8[0];
    sp54 = (s32) gObjects[gCurrentParsedObject].unkE8[1];
    sp50 = (s32) gObjects[gCurrentParsedObject].unkE8[2];
    if (sp5C->unk132 == 0) {
        sp5C->unk132 += 1;
        sp5C->unkA6 = 0x14;
        sp5C->unk44 = 5.0f;
        sp5C->moveAngle = 180.0f;
        gObjects[sp58].unkA6 = (s16) (s32) (gObjects[sp58].Pos.y - sp5C->Pos.y);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x8C, &D_801182D4);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_8011830C);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    sp5C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_800295C0(gCurrentParsedObject, &sp4C, &sp48, 0.0f, 0.0f, 0.0f) != 0) {
        sp5C->Pos.y = sp48;
    } else {
        sp5C->Pos.y = sp4C;
    }

    gObjects[sp58].Pos.x = gObjects[sp54].Pos.x = gObjects[sp50].Pos.x = sp5C->Pos.x;

    gObjects[sp58].Pos.y = (f32) gObjects[sp58].unkA6 + sp5C->Pos.y;
    gObjects[sp54].Pos.y = sp5C->Pos.y + 40.0f;
    gObjects[sp50].Pos.y = sp5C->Pos.y;

    gObjects[sp58].Pos.z = gObjects[sp54].Pos.z = gObjects[sp50].Pos.z = sp5C->Pos.z;

    gObjects[sp58].Rot.y = gObjects[sp54].Rot.y = gObjects[sp50].Rot.y = sp5C->Rot.y;

    gObjects[sp58].moveAngle = gObjects[sp54].moveAngle = gObjects[sp50].moveAngle = sp5C->moveAngle;
    if ((sp5C->unkA6 - sp5C->unkBA) == 0) {
        sp5C->unk44 = 0.0f;

        sp5C->Vel.x = sp5C->Vel.y = sp5C->Vel.z = 0.0f;

        gObjects[sp58].Vel.x = gObjects[sp58].Vel.y = gObjects[sp58].Vel.z = 0.0f;

        gObjects[sp54].Vel.x = gObjects[sp54].Vel.y = gObjects[sp54].Vel.z = 0.0f;

        gObjects[sp50].Vel.x = gObjects[sp50].Vel.y = gObjects[sp50].Vel.z = 0.0f;
        sp5C->actionState = 3;
        sp5C->unk132 = 0;
        sp5C->unkBA = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x8C, &D_801182D4);
    } else {
        sp5C->unkBA += 1;
    }
}

void func_800CECB0(void) {
}

void func_800CECC0(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    sp38 = (s32) gObjects[gCurrentParsedObject].unkE8[0];
    sp34 = (s32) gObjects[gCurrentParsedObject].unkE8[1];
    sp30 = (s32) gObjects[gCurrentParsedObject].unkE8[2];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->damageState = 0x14;

        if (sp38 != -1) {
            gObjects[sp38].damageState = 0x14;
        }
        if (sp34 != -1) {
            gObjects[sp34].damageState = 0x14;
            ;
        }
        if (sp30 != -1) {
            gObjects[sp30].damageState = 0x14;
        }

        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z = 0.0f;
        if (sp38 != -1) {
            gObjects[sp38].Vel.x = gObjects[sp38].Vel.y = gObjects[sp38].Vel.z = 0.0f;
        }
        if (sp34 != -1) {
            gObjects[sp34].Vel.x = gObjects[sp34].Vel.y = gObjects[sp34].Vel.z = 0.0f;
        }
        if (sp30 != -1) {
            gObjects[sp30].Vel.x = gObjects[sp30].Vel.y = gObjects[sp30].Vel.z = 0.0f;
        }
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x8C, &D_801182D4);
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001BBDC(sp30, 1);
        func_8001BB34(sp30, 1);
        gObjects[sp30].damageState = 0;
    }
    if (sp3C->damageState == 1) {
        func_800281A4(gCurrentParsedObject, 0);
        func_800281A4(gCurrentParsedObject, 1);
        func_8002B0E4(sp34);
        func_800281A4(gCurrentParsedObject, 2);
        func_8002B0E4(sp30);
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800CF140(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800CCD5C();
            break;
        case 2:
            func_800CD1D4();
            break;
        case 3:
            func_800CD1E4();
            break;
        case 4:
            func_800CD528();
            break;
        case 5:
            func_800CD808();
            break;
        case 6:
            func_800CDFD4();
            break;
        case 7:
            func_800CE51C();
            break;
        case 8:
            func_800CECB0();
            break;
        case 9:
            func_800CECC0();
            break;
        case 10:
            func_800CD738();
            break;
        default:
            break;
    }
}

void func_800CF260(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkA6 = 3;
        sp34->unkA8 = 0xA;
        sp34->Vel.z = 0.0f;
        sp34->Vel.y = sp34->Vel.x = sp34->Vel.z;
    }
    if (sp34->unkA8 == 0) {
        if (sp34->unkA6 < -9) {
            sp34->unkA6 = -0xA;
        }
        sp34->Vel.y = (f32) sp34->unkA6;
        sp34->unkA6 -= 1;
        if (func_800295C0(gCurrentParsedObject, &sp30, &sp2C, 0.0f, 100.0f, 0.0f) != 0) {
            func_8002B0E4(gCurrentParsedObject);
        }
    } else {
        sp34->unkA8 -= 1;
    }
}
void func_800CF40C(void) {
    if (gObjects[gCurrentParsedObject].unkE6[0] == -1) {
        if (gObjects[gCurrentParsedObject].actionState == 1) {
            if (FALSE) {}
            func_800CF260();
        } else {
            if (FALSE) {}
        }
    }
}

void func_800CF4B4(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011409C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkB6 = D_80165100->unkA;
    }
}

void func_800CF570(void) {
}

void func_800CF580(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        func_8001BB34(gCurrentParsedObject, 1);
    }
}

void func_800CF60C(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 = 1;
    }
    if (sp24->unkE8[0] == -1) {
        sp20 = func_80027464(1, &D_801140A8, sp24->Pos.x, sp24->Pos.y, sp24->Pos.z, sp24->Rot.y);
        if (sp20 != -1) {
            func_80019448(sp20, 2, 0, 1);
        }
    }
    sp24->actionState = 1;
}

void func_800CF6F4(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_800CF580();
            break;
        case 2:
            func_800CF60C();
            break;
        default:
            break;
    }
}

void func_800CF788(void) {
    if (D_80177A64 == 2) {
        gObjects[gCurrentParsedObject].actionState = 3;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800CF800(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkA6 = 0x2D;
        func_80019448(gCurrentParsedObject, 2, 0, 1);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x8F, &D_801183B0);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_801183E0 + 7);
    }
    if (sp24->unkA6 == 0) {
        sp24->unk132 = 0;
        sp24->actionState = 2;
    } else {
        sp24->unkA6 -= 1;
        sp24->Pos.y += 5.0f;
        sp24->Rot.x += 2.0f;
    }
}

void func_800CF968(void) {
    struct ObjectStruct* sp2C;
    UNUSED s32 pad[2];
    s32 sp20;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkA6 = 0xA;
        sp2C->unk44 = 14.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        sp2C->actionState = 3;
        sp2C->unk132 = 0;
    }
    if (sp2C->unkA6 == 0) {
        sp20 = func_8002A640(gCurrentParsedObject, 10.0f);
        sp2C->Rot.y = Math_WrapAngle(sp2C->Rot.y, (f32) (sp20 * 0xA));
        sp2C->moveAngle = sp2C->Rot.y;
        sp2C->unkA6 = 0xA;
    } else {
        sp2C->unkA6 -= 1;
    }
    sp2C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->actionState = 3;
        sp2C->unk132 = 0;
    }
}

void func_800CFB34(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800CFB64(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_800CF800();
            break;
        case 2:
            func_800CF968();
            break;
        case 3:
            func_800CFB34();
            break;
        default:
            break;
    }
}

void func_800CFC14(void) {
    func_80027464(1, &D_801140B4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800CFC8C(void) {
    if ((D_80177A64 == 0) && (gObjects[gCurrentParsedObject].actionState != 6)) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 6;
    }
}

void func_800CFD38(void) {
    struct ObjectStruct* sp34;
    UNUSED s32 pad[2];

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z = 0.0f;
        sp34->Scale.x = sp34->Scale.y = sp34->Scale.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x92, &D_80118514);
        func_8001BB34(gCurrentParsedObject, 1);
        func_8001BB04(gCurrentParsedObject, 1);
    }
    if ((gObjects->Pos.y < (sp34->Pos.y - 90.0f)) && (func_8002A2EC(gCurrentParsedObject, 600.0f) != 0)) {
        sp34->actionState = 2;
        sp34->unk132 = 0;
    }
}

void func_800CFEC4(void) {
    struct ObjectStruct* sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkA8 = 0x14;
        sp24->unk44 = 8.0f;
        sp24->moveAngle = Get_AngleToPlayer(gCurrentParsedObject);
        func_80029EF8(gCurrentParsedObject, 0.0f, 1.5f);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x92, &D_80118514);
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BB04(gCurrentParsedObject, 0);
        func_800175F0(gCurrentParsedObject, 0, 0x54, -1, 0);
    }
    if (sp24->unkA8 != 0) {
        sp24->Scale.x = (f32) ((f64) sp24->Scale.x + 0.05);
        sp24->Scale.y = (f32) ((f64) sp24->Scale.y + 0.05);
        sp24->Scale.z = (f32) ((f64) sp24->Scale.z + 0.05);
        sp24->unkA8 -= 1;
    } else {
        sp20 = sp24->Vel.y;
        sp24->Vel.y = 0.0f;
        func_80029C40(gCurrentParsedObject);
        if (func_80029018(gCurrentParsedObject, 2U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
            sp24->Vel.z = 0.0f;
            sp24->Vel.x = sp24->Vel.z;
        }
        sp24->Vel.y = sp20;
        if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
            sp24->Vel.z = 0.0f;
            sp24->Vel.x = sp24->Vel.z;
            sp24->actionState = 3;
            sp24->unk132 = 0;
        }
    }
}

void func_800D0194(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 0.0f;
        sp24->damageState = 1;
        func_80029EF8(gCurrentParsedObject, 10.0f, 1.0f);
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x92, &D_80118514);
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        sp24->actionState = 4;
        sp24->unk132 = 0;
    }
}

void func_800D02AC(void) {
    struct ObjectStruct* sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkA6 = 0x14;
        sp2C->Vel.x = sp2C->Vel.y = sp2C->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x92, &D_80118514);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    if (sp2C->unkA6 == 0) {
        sp2C->actionState = 5;
        sp2C->unk132 = 0;
    } else {
        sp2C->unkA6 -= 1;
    }
}

void func_800D03EC(void) {
    struct ObjectStruct* sp34;
    f32 sp30;
    s32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB0 = 0;
        sp34->unk44 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x92, &D_80118514);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp34->unkB0 = 0xA;
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 8.0f) {
        sp34->unk44 = 4.0f;
        func_80029EF8(gCurrentParsedObject, 6.666667f, 0.350877f);
    }
    if (sp34->unkB0 == 0) {
        sp2C = func_8002A640(gCurrentParsedObject, 10.0f);
        sp34->Rot.y = Math_WrapAngle(sp34->Rot.y, (f32) (sp2C * 0xA));
        sp34->moveAngle = sp34->Rot.y;
    } else {
        sp34->unkB0 -= 1;
    }
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 90.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if ((func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) && (sp34->unk44 != 0.0f)) {
        sp34->actionState = 4;
        sp34->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
}

void func_800D06CC(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;
    s16 sp36;
    f32 sp30;
    f32 sp2C;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z = 0.0f;
        sp3C->unkA6 = 0x20;
        sp3C->unkA8 = 0;
        sp3C->unkAA = 1;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x92, &D_80118514);
        func_8001BBDC(gCurrentParsedObject, 0);
        gObjects[gCurrentParsedObject].damageState = 0;
        func_800175F0(gCurrentParsedObject, 0, 0x54, -1, 0);
    }
    if (sp3C->unkA6 != 0) {
        sp36 = sp3C->unkA6 & 0xF;
        if ((sp36 == 0) || (sp36 == 5)) {
            sp38 = func_80027464(1, &D_801140C0, sp3C->Pos.x, sp3C->Pos.y, sp3C->Pos.z, 0.0f);
            if (sp38 != -1) {
                gObjects[sp38].Pos.x += (f32) D_80114FE0[sp3C->unkA8];
                gObjects[sp38].Pos.z += (f32) D_80114FE8[sp3C->unkA8];
                if (func_800295C0(sp38, &sp30, &sp2C, 0.0f, 0.0f, 0.0f) != 0) {
                    gObjects[sp38].Pos.y = sp2C;
                } else {
                    gObjects[sp38].Pos.y = sp30;
                }
                gObjects[sp38].Pos.y += 60.0f;
                gObjects[sp38].Scale.x = gObjects[sp38].Scale.y = gObjects[sp38].Scale.z = 0.2f;
            }
            sp3C->unkA8 += 1;
        }
        sp3C->unkA6 -= 1;
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        func_8001BBDC(gCurrentParsedObject, 1);
        sp3C->unkAA = 0;
    }
    if ((sp3C->unkA6 == 0) && (sp3C->unkAA == 0)) {
        func_800175F0(gCurrentParsedObject, 0, 0x55, -1, 0);
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800D0B48(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_800CFD38();
            break;
        case 2:
            func_800CFEC4();
            break;
        case 3:
            func_800D0194();
            break;
        case 4:
            func_800D02AC();
            break;
        case 5:
            func_800D03EC();
            break;
        case 6:
            func_800D06CC();
            break;
        default:
            break;
    }
}

void func_800D0C28(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 3;
    }
}

void func_800D0CA0(void) {
    struct ObjectStruct* sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z = 0.0f;
        sp34->unkA6 = 0x32;
        sp34->damageState = -1;
        func_80029EF8(gCurrentParsedObject, 10.0f, 2.0f);
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x93, &D_80118528);
    }
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 2U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.z;
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z = 0.0f;
    }
    if (sp34->unkA6 != 0) {
        sp34->unkA6 -= 1;
        sp34->Scale.x = (f32) ((f64) sp34->Scale.x + 0.025);
        sp34->Scale.y = (f32) ((f64) sp34->Scale.y + 0.025);
        sp34->Scale.z = (f32) ((f64) sp34->Scale.z + 0.025);
        sp34->Rot.y = Math_WrapAngle(sp34->Rot.y, 15.0f);
        sp34->moveAngle = sp34->Rot.y;
    } else {
        sp34->damageState = 1;
        sp34->actionState = 2;
        sp34->unk132 = 0;
    }
}

void func_800D0F98(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unk44 = 5.0f;
        sp3C->unkA6 = 1;
        sp3C->unkA8 = 0;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x93, &D_80118528);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp3C->Rot.y = sp3C->moveAngle;
    }
    if (sp3C->unkA6 != 0) {
        sp3C->unkA6 = 0;
        func_80029EF8(gCurrentParsedObject, 6.0f, 0.545455f);
        if (sp3C->unkA8 == 0) {
            sp3C->moveAngle = (f32) Math_Random(0x168);
            sp3C->Rot.y = sp3C->moveAngle;
            sp3C->unkA8 = 2;
        }
    }
    sp38 = sp3C->Vel.y;
    sp3C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp3C->Rot.y = sp3C->moveAngle;
    }
    sp3C->Vel.y = sp38;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 30.0f) == 1) {
        sp3C->unkA6 = 1;
        sp3C->unkA8 -= 1;
    }
}

void func_800D1268(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_800D1268(); /* extern */

void func_800D1298(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_800D0CA0();
            break;
        case 2:
            func_800D0F98();
            break;
        case 3:
            func_800D1268();
            break;
        default:
            break;
    }
}

void func_800D1348(void) {
    func_80027464(1, &D_801140CC, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void stub_BE560() {
}

void func_800D13D0(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        func_8001BB34(gCurrentParsedObject, 1);
        func_8001BB04(gCurrentParsedObject, 1);
        sp1C->unkA6 = 0;
    }
    if (sp1C->unkA6 != 0) {
        sp1C->actionState = 2;
        sp1C->unk132 = 0;
    }
}

void func_800D14A8(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;
    f32 sp34;
    f32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unkA6 = 0x1E;
        sp3C->unkA8 = 0;
        sp3C->unkAA = 0;
    }
    if (sp3C->unkA6 == 0) {
        if (sp3C->unkA8 < 0xA) {
            sp38 = func_80027464(1, &D_801140D8, sp3C->Pos.x, sp3C->Pos.y, sp3C->Pos.z, 0.0f);
            if (sp38 != -1) {
                if (func_800295C0(sp38, &sp34, &sp30, 0.0f, 0.0f, 0.0f) != 0) {
                    gObjects[sp38].Pos.y = sp30;
                } else {
                    gObjects[sp38].Pos.y = sp34;
                }
                gObjects[sp38].moveAngle = gObjects[sp38].Rot.y = 0.0f;
                gObjects[sp38].Scale.x = gObjects[sp38].Scale.y = gObjects[sp38].Scale.z = 1.5f;
            }
            sp3C->unkA6 = 0x1E;
            sp3C->unkA8 += 1;
        }
    } else {
        sp3C->unkA6 -= 1;
    }
}

void func_800D1764(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_800D13D0();
            break;
        case 2:
            func_800D14A8();
            break;
        default:
            break;
    }
}

void func_800D17F8(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 2;
    }
}

void func_800D1870(void) {
    struct ObjectStruct* sp3C;
    f32 sp38;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unk44 = 5.0f;
        sp3C->unkA6 = 1;
        sp3C->unkA8 = 2;
        sp3C->unkB6 = 0x1E;
        sp3C->Vel.x = sp3C->Vel.y = sp3C->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x93, &D_80118528);
    }
    if (sp3C->unkB6 != 0) {
        sp3C->unkB6 -= 1;
    }
    if ((func_80028FA0(gCurrentParsedObject) != 0) && (sp3C->unkB6 == 0)) {
        func_80029B60(gCurrentParsedObject);
        sp3C->Rot.y = sp3C->moveAngle;
    }
    if (sp3C->unkA6 != 0) {
        sp3C->unkA6 = 0;
        func_80029EF8(gCurrentParsedObject, 6.0f, 0.545455f);
        if (sp3C->unkA8 == 0) {
            sp3C->moveAngle = (f32) Math_Random(0x168);
            sp3C->Rot.y = sp3C->moveAngle;
            sp3C->unkA8 = 2;
        }
    }
    sp38 = sp3C->Vel.y;
    sp3C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp3C->Rot.y = sp3C->moveAngle;
    }
    sp3C->Vel.y = sp38;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 30.0f) == 1) {
        sp3C->unkA6 = 1;
        sp3C->unkA8 -= 1;
    }
}

void func_800D1B94(void) {
    UNUSED struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    func_8002B0E4(gCurrentParsedObject);
}

void func_800D1BF0(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_800D1870();
            break;
        case 2:
            func_800D1B94();
            break;
        default:
            break;
    }
}

void func_800D1C84(void) {
    func_80027464(1, &D_801140E4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                  (f32) D_80165100->unk8);
}

void func_800D1CFC(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].actionState = 2;
    }
}

void func_800D1D74(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 += 1;
    }
}

void func_800D1DE4(void) {
    UNUSED struct ObjectStruct* sp1C;
    s32 sp18;

    sp1C = &gObjects[gCurrentParsedObject];
    sp18 = 0xE;

    while (TRUE) {
        sp18 = Get_ObjIdx_ByPos(0xC7, sp18);
        if (sp18 == -1) {
            break;
        } else {
            gObjects[sp18].unkA6 = 1;
            break;
        }
    }

    func_8002B0E4(gCurrentParsedObject);
}

void func_800D1EB0(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_800D1D74();
            break;
        case 2:
            func_800D1DE4();
            break;
        default:
            break;
    }
}
