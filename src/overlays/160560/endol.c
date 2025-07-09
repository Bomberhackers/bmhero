#include <ultra64.h>
#include "obj.h"
#include "functions.h"

// Endol routines
void func_endol_80330000(void);
void func_endol_80330090(void);
void func_endol_803305CC(void);
void func_endol_80330B5C(void);
void func_endol_80330CC0(void);
void func_endol_80330DA4(void);
void func_endol_80330E88(void);
void func_endol_80331130(void);
void func_endol_80331288(void);
void func_endol_803313D4(void);
void func_endol_803314D4(void);
void func_endol_803315B8(void);
void func_endol_80331708(void);
void func_endol_803317EC(void);
void func_endol_803318D0(void);
void func_endol_80331C58(void);
void func_endol_80331D6C(void);
void func_endol_80331E50(void);
void func_endol_80331FD8(void);
void func_endol_803320E0(void);
void func_endol_80332294(void);
void func_endol_8033244C(void);
void func_endol_80332584(void);
void func_endol_803326BC(void);
void func_endol_803327F4(void);
void func_endol_803329C4(void);
void func_endol_80332B2C(void);
void func_endol_80332CD0(void);
void func_endol_80332F7C(void);
void func_endol_803331F8(void);
void func_endol_803333F4(void);
void func_endol_803335F0(void);
void func_endol_8033381C(void);
void func_endol_803339AC(void);
void func_endol_80333BA0(void);
void func_endol_80333CD4(void);
void func_endol_80333EC4(void);
void func_endol_80334090(void);
void func_endol_80334174(void);
void func_endol_80334258(void);
void func_endol_803343F8(void);
void func_endol_8033461C(void);
void func_endol_80334738(void);
void func_endol_80334880(void);
void func_endol_80334964(void);
void func_endol_80334BD4(void);
void func_endol_80334CB8(void);
void func_endol_80334DE8(void);
void func_endol_80334EEC(void);
void func_endol_8033509C(void);
void func_endol_803351B0(void);
void func_endol_80335300(void);
void func_endol_80335808(void);
void func_endol_80335C1C(void);
void func_endol_80335D2C(void);
void func_endol_80335D6C(void);
void func_endol_80335E88(void);
void func_endol_80336010(void);
void func_endol_8033617C(void);
void func_endol_80336258(void);
void func_endol_80336368(void);
void func_endol_803363A8(void);
void func_endol_8033651C(void);
void func_endol_80336600(void);
void func_endol_803366B4(void);
void func_endol_803367D0(void);
void func_endol_80336928(void);
void func_endol_80336A18(void);
void func_endol_80336B8C(void);
void func_endol_80336D14(void);
void func_endol_80336E94(void);
void func_endol_80336EC4(void);
void func_endol_80336F84(void);
void func_endol_803370C0(void);

extern u32 D_80119FC0;
extern u32 D_80119FD0;
extern u32 D_80119FD4;
extern u32 D_80119FD8;

const struct ObjSpawnInfo D_endol_80337190 = { 0, OBJ_ENDL_DD, 0xC9, 1, -1, 1, 1, 0 };
const struct ObjSpawnInfo D_endol_8033719C = { 0, OBJ_ENDL_HD, 0xCB, 6, -1, 1, 1, 0 };
const struct ObjSpawnInfo D_endol_803371A8 = { 0, OBJ_ENDL_FB, 0xCA, 1, 1, 1, 1, 0 };
const struct ObjSpawnInfo D_endol_803371B4 = { 3, OBJ_ENDL_JO, 0xCC, 7, -1, 0, 0, 0 };
const struct ObjSpawnInfo D_endol_803371C0 = { 0, OBJ_ENDL_ST, 0xFE, 1, -1, 0, 0, 0 };
const struct ObjSpawnInfo D_endol_unused = { 3, OBJ_ENDL_TG, 0x197, 3, -1, 0, 0, 0 };
const struct ObjSpawnInfo D_endol_803371D8 = { 0, OBJ_ENDL_BD, 0xC8, 0x12, 0xA, 1, 1, 0 };
const struct ObjSpawnInfo D_endol_unused_1 = { 0 };

void func_endol_80330000(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unkD4 == 0.0f) {
        sp4->unkD4 = 2.0f;
    } else {
        sp4->unkD4 *= -1.0f;
    }
}

void func_endol_80330090(void) {
    s32 sp24;
    s32 sp20;

    sp24 = func_80027464(1, &D_endol_803371D8, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                         (f32) D_80165100->unk8);
    func_8001ABF4(sp24, 0, 0, &D_80119E0C);
    func_8001ABF4(sp24, 1, 0, &D_80119E0C.unk38);
    func_8001ABF4(sp24, 2, 0, &D_80119E0C.unk8C);
    func_8001ABF4(sp24, 3, 0, &D_80119E0C.unkFC);
    gObjects[sp24].unkA8 = 1;
    gObjects[sp24].damageState = -1;
    sp20 = func_80027464(1, &D_endol_80337190, gObjects[sp24].Pos.x, gObjects[sp24].Pos.y - 180.0f,
                         gObjects[sp24].Pos.z, 0.0f);
    gObjects[sp24].unkBA = (s16) sp20;
    gObjects[sp20].unkC2 = (s16) sp24;
    func_80026F10(sp24, sp20);
    sp20 = func_80027464(1, &D_endol_8033719C, gObjects[sp24].Pos.x, gObjects[sp24].Pos.y - 180.0f,
                         gObjects[sp24].Pos.z - 200.0f, 0.0f);
    gObjects[sp24].unkBC = (s16) sp20;
    gObjects[sp20].unkC2 = (s16) sp24;
    func_80026F10(sp24, sp20);
    sp20 = func_80027464(1, &D_endol_8033719C, gObjects[sp24].Pos.x - 200.0f, gObjects[sp24].Pos.y - 180.0f,
                         gObjects[sp24].Pos.z, 90.0f);
    gObjects[sp24].unkBE = (s16) sp20;
    gObjects[sp20].unkC2 = (s16) sp24;
    func_80026F10(sp24, sp20);
    sp20 = func_80027464(1, &D_endol_8033719C, gObjects[sp24].Pos.x, gObjects[sp24].Pos.y - 180.0f,
                         gObjects[sp24].Pos.z + 200.0f, 180.0f);
    gObjects[sp24].unkC0 = (s16) sp20;
    gObjects[sp20].unkC2 = (s16) sp24;
    func_80026F10(sp24, sp20);
    sp20 = func_80027464(1, &D_endol_8033719C, gObjects[sp24].Pos.x + 200.0f, gObjects[sp24].Pos.y - 180.0f,
                         gObjects[sp24].Pos.z, 270.0f);
    gObjects[sp24].unkC2 = (s16) sp20;
    gObjects[sp20].unkC2 = (s16) sp24;
    func_80026F10(sp24, sp20);
}

void func_endol_803305CC(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        sp1C->damageState = 0;
        sp1C->actionState = 0x31;
        sp1C->unk132 = 0;
        func_80069E60(0, 1, 0x89);
    } else if (D_80177A64 == 1) {
        sp1C->damageState = 0x5A;
        if (sp1C->unk100 == 5) {
            sp1C->damageState += 0x1E;
            sp1C->actionState = 0x19;
            sp1C->unk132 = 0;
            gObjects[sp1C->unkBA].damageState = 0;
            gObjects[sp1C->unkBA].unkB2 = 3;
            gObjects[sp1C->unkBA].actionState = 3;
            gObjects[sp1C->unkBA].unk132 = 0;
            gObjects[sp1C->unkBC].damageState = 0;
            gObjects[sp1C->unkBC].unkB2 = 6;
            gObjects[sp1C->unkBC].actionState = 6;
            gObjects[sp1C->unkBC].unk132 = 0;
            gObjects[sp1C->unkBE].damageState = 0;
            gObjects[sp1C->unkBE].unkB2 = 6;
            gObjects[sp1C->unkBE].actionState = 6;
            gObjects[sp1C->unkBE].unk132 = 0;
            gObjects[sp1C->unkC0].damageState = 0;
            gObjects[sp1C->unkC0].unkB2 = 6;
            gObjects[sp1C->unkC0].actionState = 6;
            gObjects[sp1C->unkC0].unk132 = 0;
            gObjects[sp1C->unkC2].damageState = 0;
            gObjects[sp1C->unkC2].unkB2 = 6;
            gObjects[sp1C->unkC2].actionState = 6;
            gObjects[sp1C->unkC2].unk132 = 0;
        } else {
            switch (sp1C->unkB2) { /* switch 1 */
                case 13:           /* switch 1 */
                case 14:           /* switch 1 */
                case 15:           /* switch 1 */
                case 16:           /* switch 1 */
                    sp1C->actionState = 0x11;
                    sp1C->unk132 = 0;
                    break;
                case 30: /* switch 1 */
                case 31: /* switch 1 */
                    sp1C->actionState = 0x19;
                    sp1C->unk132 = 0;
                    break;
            }
        }
    } else if (sp1C->unkAA == 0) {
        switch (sp1C->unkB2) { /* switch 2 */
            case 13:           /* switch 2 */
            case 14:           /* switch 2 */
            case 15:           /* switch 2 */
            case 16:           /* switch 2 */
                sp1C->actionState = 0x16;
                sp1C->unk132 = 0;
                break;
            case 30: /* switch 2 */
            case 31: /* switch 2 */
            case 32: /* switch 2 */
            case 38: /* switch 2 */
            case 39: /* switch 2 */
            case 40: /* switch 2 */
            case 41: /* switch 2 */
            case 42: /* switch 2 */
            case 43: /* switch 2 */
            case 44: /* switch 2 */
            case 45: /* switch 2 */
                sp1C->actionState = 0x2E;
                sp1C->unk132 = 0;
                break;
        }
    }
}

void func_endol_80330B5C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119E0C.unk1C);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk70);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unk8C);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unkFC);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 2;
        sp24->unk132 = 0;
    }
}

void func_endol_80330CC0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 3;
        sp24->unk132 = 0;
    }
}

void func_endol_80330DA4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 4;
        sp24->unk132 = 0;
    }
}

void func_endol_80330E88(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp24->unkA6 == 0) {
            sp24->unkA6 += 1;
            sp24->actionState = 1;
            sp24->unk132 = 0;
            gObjects[sp24->unkBC].actionState = 2;
            gObjects[sp24->unkBC].unk132 = 0;
            gObjects[sp24->unkBE].actionState = 2;
            gObjects[sp24->unkBE].unk132 = 0;
            gObjects[sp24->unkC0].actionState = 2;
            gObjects[sp24->unkC0].unk132 = 0;
            gObjects[sp24->unkC2].actionState = 2;
            gObjects[sp24->unkC2].unk132 = 0;
        } else if (sp24->unkA6 == 1) {
            sp24->actionState = 5;
            sp24->unk132 = 0;
        }
    }
}

void func_endol_80331130(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0xC8, D_80119C80);
        sp24->unkA6 = 0x1E;
    }
    if (sp24->unkA6 != 0) {
        sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, 3.0f);
        sp24->moveAngle = sp24->Rot.y;
        sp24->unkA6 -= 1;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 6;
        sp24->unk132 = 0;
    }
}

void func_endol_80331288(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xC, 0xC8, D_80119C80);
    }
    if (sp24->unkA6 != 0) {
        sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, 3.0f);
        sp24->moveAngle = sp24->Rot.y;
        sp24->unkA6 -= 1;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 7;
        sp24->unk132 = 0;
    }
}

void func_endol_803313D4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0xC8, D_80119C80);
        func_800175F0(gCurrentParsedObject, 0, 2, -1, 0);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 8;
        sp24->unk132 = 0;
    }
}

void func_endol_803314D4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 6, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 9;
        sp24->unk132 = 0;
    }
}

void func_endol_803315B8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unk118);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 12.0f) {
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk54);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0xA;
        sp24->unk132 = 0;
    }
}

void func_endol_80331708(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 8, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0xB;
        sp24->unk132 = 0;
    }
}

void func_endol_803317EC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 9, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0xC;
        sp24->unk132 = 0;
    }
}

void func_endol_803318D0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xA, 0xC8, D_80119C80);
        func_800175F0(gCurrentParsedObject, 0, 0x3D, -1, 0);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 8.0f) {
        gObjects[sp24->unkBA].actionState = 2;
        gObjects[sp24->unkBA].unk132 = 0;
        gObjects[sp24->unkBC].actionState = 5;
        gObjects[sp24->unkBC].unk132 = 0;
        gObjects[sp24->unkBE].actionState = 5;
        gObjects[sp24->unkBE].unk132 = 0;
        gObjects[sp24->unkC0].actionState = 5;
        gObjects[sp24->unkC0].unk132 = 0;
        gObjects[sp24->unkC2].actionState = 5;
        gObjects[sp24->unkC2].unk132 = 0;
    } else if (func_8001B62C(gCurrentParsedObject, 0) == 16.0f) {
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk70);
    } else if (func_8001B62C(gCurrentParsedObject, 0) == 40.0f) {
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unkFC);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0xD;
        sp24->unk132 = 0;
    }
}

void func_endol_80331C58(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0xC8, D_80119C80);
        sp24->damageState = -1;
        if (sp24->damageState != 0) {
            sp24->damageState = 1;
        }
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0xE;
        sp24->unk132 = 0;
    }
}

void func_endol_80331D6C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xC, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0xF;
        sp24->unk132 = 0;
    }
}

void func_endol_80331E50(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119E0C.unk1C);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk70);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unk8C);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unkFC);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    sp24->Rot.y = sp24->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x10;
        sp24->unk132 = 0;
    }
}

void func_endol_80331FD8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xC, 0xC8, D_80119C80);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    sp24->Rot.y = sp24->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0xF;
        sp24->unk132 = 0;
    }
}

void func_endol_803320E0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x18, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119E0C);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk38);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unkAC[0x18]);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unk134);
    }
    sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, gObjects[sp24->unkBA].unkD4);
    sp24->moveAngle = sp24->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x12;
        sp24->unk132 = 0;
    }
}

void func_endol_80332294(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119E0C.unk1C);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk70);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unk8C);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unkFC);
    }
    sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, gObjects[sp24->unkBA].unkD4);
    sp24->moveAngle = sp24->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x13;
        sp24->unk132 = 0;
    }
}

void func_endol_8033244C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xC8, D_80119C80);
    }
    sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, gObjects[sp24->unkBA].unkD4);
    sp24->moveAngle = sp24->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x14;
        sp24->unk132 = 0;
    }
}

void func_endol_80332584(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xC8, D_80119C80);
    }
    sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, gObjects[sp24->unkBA].unkD4);
    sp24->moveAngle = sp24->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x15;
        sp24->unk132 = 0;
    }
}

void func_endol_803326BC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0xC8, D_80119C80);
    }
    sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, gObjects[sp24->unkBA].unkD4);
    sp24->moveAngle = sp24->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0xF;
        sp24->unk132 = 0;
    }
}

void func_endol_803327F4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x15, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk54);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unkAC[0x34]);
        sp24->unkAA = 1;
        func_800175F0(gCurrentParsedObject, 0, 0x1A, -1, 0);
    }
    sp24->damageState = 1;
    if (sp24->damageState != 0) {
        sp24->damageState = -1;
    }
    sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, gObjects[sp24->unkBA].unkD4);
    sp24->moveAngle = sp24->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x17;
        sp24->unk132 = 0;
    }
}

void func_endol_803329C4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x16, 0xC8, D_80119C80);
    }
    sp24->damageState = 1;
    if (sp24->damageState != 0) {
        sp24->damageState = -1;
    }
    sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, gObjects[sp24->unkBA].unkD4);
    sp24->moveAngle = sp24->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x18;
        sp24->unk132 = 0;
    }
}

void func_endol_80332B2C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x17, 0xC8, D_80119C80);
    }
    sp24->damageState = 1;
    if (sp24->damageState != 0) {
        sp24->damageState = -1;
    }
    sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, gObjects[sp24->unkBA].unkD4);
    sp24->moveAngle = sp24->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->damageState = -1;
        if (sp24->damageState != 0) {
            sp24->damageState = 1;
        }
        sp24->unkAA = 0;
        sp24->actionState = 0xF;
        sp24->unk132 = 0;
    }
}

void func_endol_80332CD0(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x18, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119E0C);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk38);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unkAC[0x18]);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unk134);
        sp2C->Vel.z = 0.0f;
        sp2C->Vel.x = sp2C->Vel.z;
        sp2C->moveSpeed = 0.0f;
    }
    sp2C->Rot.y = Math_WrapAngle(sp2C->Rot.y, gObjects[sp2C->unkBA].unkD4);
    sp2C->moveAngle = sp2C->Rot.y;
    if (sp2C->unkBA != 0) {
        if (gObjects[sp2C->unkBA].actionState == 4) {
            sp2C->Pos.y -= 3.0f;
        }
    } else if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp24;
    } else {
        sp2C->Pos.y = sp28;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->actionState = 0x1A;
        sp2C->unk132 = 0;
    }
}

void func_endol_80332F7C(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119E0C.unk1C);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk70);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unk8C);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unkFC);
    }
    sp2C->Rot.y = Math_WrapAngle(sp2C->Rot.y, gObjects[sp2C->unkBA].unkD4);
    sp2C->moveAngle = sp2C->Rot.y;
    if (sp2C->unkBA != 0) {
        if (gObjects[sp2C->unkBA].actionState == 4) {
            sp2C->Pos.y -= 3.0f;
        }
    } else if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp24;
    } else {
        sp2C->Pos.y = sp28;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->actionState = 0x1B;
        sp2C->unk132 = 0;
    }
}

void func_endol_803331F8(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xC8, D_80119C80);
    }
    sp2C->Rot.y = Math_WrapAngle(sp2C->Rot.y, gObjects[sp2C->unkBA].unkD4);
    sp2C->moveAngle = sp2C->Rot.y;
    if (sp2C->unkBA != 0) {
        if (gObjects[sp2C->unkBA].actionState == 4) {
            sp2C->Pos.y -= 3.0f;
        }
    } else if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp24;
    } else {
        sp2C->Pos.y = sp28;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->actionState = 0x1C;
        sp2C->unk132 = 0;
    }
}

void func_endol_803333F4(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xC8, D_80119C80);
    }
    sp2C->Rot.y = Math_WrapAngle(sp2C->Rot.y, gObjects[sp2C->unkBA].unkD4);
    sp2C->moveAngle = sp2C->Rot.y;
    if (sp2C->unkBA != 0) {
        if (gObjects[sp2C->unkBA].actionState == 4) {
            sp2C->Pos.y -= 3.0f;
        }
    } else if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp24;
    } else {
        sp2C->Pos.y = sp28;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp2C->actionState = 0x1D;
        sp2C->unk132 = 0;
    }
}

void func_endol_803335F0(void) {
    struct ObjectStruct* sp2C;
    f32 sp28;
    f32 sp24;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 += 1;
        sp2C->unkB2 = sp2C->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0xC8, D_80119C80);
    }
    sp2C->Rot.y = Math_WrapAngle(sp2C->Rot.y, gObjects[sp2C->unkBA].unkD4);
    sp2C->moveAngle = sp2C->Rot.y;
    if (sp2C->unkBA != 0) {
        if (gObjects[sp2C->unkBA].actionState == 4) {
            sp2C->Pos.y -= 3.0f;
        }
    } else if (func_800295C0(gCurrentParsedObject, &sp28, &sp24, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->Pos.y = sp24;
    } else {
        sp2C->Pos.y = sp28;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (sp2C->unkBA == 0) {
            sp2C->actionState = 0x1E;
            sp2C->unk132 = 0;
        } else {
            sp2C->actionState = 0x1A;
            sp2C->unk132 = 0;
        }
    }
}

void func_endol_8033381C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0xC8, D_80119C80);
    }
    sp24->moveSpeed = 6.0f;
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    sp24->Rot.y = sp24->moveAngle;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->moveSpeed = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x1F;
        sp24->unk132 = 0;
    }
}

void func_endol_803339AC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xC, 0xC8, D_80119C80);
    }
    sp24->moveSpeed = 6.0f;
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    sp24->Rot.y = sp24->moveAngle;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 120.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->moveSpeed = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (func_8002A1FC(gCurrentParsedObject, 540.0f) != 0) {
            sp24->moveSpeed = 0.0f;
            sp24->Vel.z = 0.0f;
            sp24->Vel.x = sp24->Vel.z;
            sp24->actionState = 0x20;
            sp24->unk132 = 0;
        } else {
            sp24->actionState = 0x1E;
            sp24->unk132 = 0;
        }
    }
}

void func_endol_80333BA0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk54);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (func_8002A1FC(gCurrentParsedObject, 360.0f) != 0) {
            sp24->actionState = 0x21;
            sp24->unk132 = 0;
        } else {
            sp24->actionState = 0x26;
            sp24->unk132 = 0;
        }
    }
}

void func_endol_80333CD4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 6, 0xC8, D_80119C80);
        sp24->unkD4 = 0.0f;
    }
    if (func_8001B62C(gCurrentParsedObject, 0) > 4.0f) {
        sp24->unkDC = Get_AngleToPlayer(gCurrentParsedObject);
        sp24->unkDC = (sp24->unkDC - sp24->Rot.y) - 180.0f;
        if (sp24->unkDC < -360.0f) {
            sp24->unkDC += 360.0f;
        }
        sp24->unkDC /= 6.0f;
        sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, sp24->unkDC);
        sp24->moveAngle = sp24->Rot.y;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x22;
        sp24->unk132 = 0;
    }
}

void func_endol_80333EC4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unk118);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 12.0f) {
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk54);
    } else if (func_8001B62C(gCurrentParsedObject, 0) < 4.0f) {
        sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, sp24->unkDC);
        sp24->moveAngle = sp24->Rot.y;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->unkD4 = 0.0f;
        sp24->actionState = 0x23;
        sp24->unk132 = 0;
    }
}

void func_endol_80334090(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 8, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x24;
        sp24->unk132 = 0;
    }
}

void func_endol_80334174(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 9, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x25;
        sp24->unk132 = 0;
    }
}

void func_endol_80334258(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xA, 0xC8, D_80119C80);
        func_800175F0(gCurrentParsedObject, 0, 0x3D, -1, 0);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 16.0f) {
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk70);
    } else if (func_8001B62C(gCurrentParsedObject, 0) == 40.0f) {
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unkFC);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x1E;
        sp24->unk132 = 0;
    }
}

void func_endol_803343F8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xD, 0xC8, D_80119C80);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) > 4.0f) {
        sp24->unkDC = Get_AngleToPlayer(gCurrentParsedObject);
        sp24->unkDC -= sp24->Rot.y;
        if (sp24->unkDC < 0.0f) {
            sp24->unkDC += 360.0f;
        }
        sp24->unkDC /= 14.0f;
        sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, sp24->unkDC);
        sp24->moveAngle = sp24->Rot.y;
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 12.0f) {
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk54);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x27;
        sp24->unk132 = 0;
    }
}

void func_endol_8033461C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xE, 0xC8, D_80119C80);
    }
    sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, sp24->unkDC);
    sp24->moveAngle = sp24->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x28;
        sp24->unk132 = 0;
    }
}

void func_endol_80334738(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xF, 0xC8, D_80119C80);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 2.0f) {
        sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, sp24->unkDC);
        sp24->moveAngle = sp24->Rot.y;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x29;
        sp24->unk132 = 0;
    }
}

void func_endol_80334880(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x10, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x2A;
        sp24->unk132 = 0;
    }
}

void func_endol_80334964(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkB2 = sp34->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x11, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unkA8);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 18.0f) {
        func_800175F0(gCurrentParsedObject, 0, 0x1B, -1, 0);
        sp2C = (sinf((f32) ((f64) sp34->Rot.y * DEG_TO_RAD)) * 14.0f) + sp34->Pos.x;
        sp24 = (cosf((f32) ((f64) sp34->Rot.y * DEG_TO_RAD)) * 14.0f) + sp34->Pos.z;
        sp28 = sp34->Pos.y + 240.0f;
        sp30 = func_80027464(1, &D_endol_803371A8, sp2C, sp28, sp24, sp34->Rot.y);
        gObjects[sp30].unkC2 = (s16) gCurrentParsedObject;
        func_8001ABF4(sp30, 0, 0, D_80119FA4);
        func_80026F10(sp30, 0xE);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp34->actionState = 0x2B;
        sp34->unk132 = 0;
    }
}

void func_endol_80334BD4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x12, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x2C;
        sp24->unk132 = 0;
    }
}

void func_endol_80334CB8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x13, 0xC8, D_80119C80);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) == 2.0f) {
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unk8C);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x2D;
        sp24->unk132 = 0;
    }
}

void func_endol_80334DE8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x14, 0xC8, D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk70);
        sp24->actionState = 0x1E;
        sp24->unk132 = 0;
    }
}

void func_endol_80334EEC(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x15, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk54);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unkAC[0x34]);
        sp24->unkAA = 1;
        func_800175F0(gCurrentParsedObject, 0, 0x1A, -1, 0);
        sp24->moveSpeed = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    }
    sp24->damageState = 1;
    if (sp24->damageState != 0) {
        sp24->damageState = -1;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x2F;
        sp24->unk132 = 0;
    }
}

void func_endol_8033509C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x16, 0xC8, D_80119C80);
    }
    sp24->damageState = 1;
    if (sp24->damageState != 0) {
        sp24->damageState = -1;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 0x30;
        sp24->unk132 = 0;
    }
}

void func_endol_803351B0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x17, 0xC8, D_80119C80);
    }
    sp24->damageState = 1;
    if (sp24->damageState != 0) {
        sp24->damageState = -1;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->damageState = -1;
        if (sp24->damageState != 0) {
            sp24->damageState = 1;
        }
        sp24->unkAA = 0;
        sp24->actionState = 0x1A;
        sp24->unk132 = 0;
    }
}

void func_endol_80335300(void) {
    struct ObjectStruct* sp3C;
    s32 sp38;
    s32 pad[2];

    s16 sp2E;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->Vel.z = 0.0f;
        sp3C->Vel.x = sp3C->Vel.z;
        sp3C->moveSpeed = 0.0f;
        sp3C->unkB2 = sp3C->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x18, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119E0C);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk38);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unk8C);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unkFC);
        sp3C->unkC0 = 0x2D;
        sp3C->unkB4 = 0;
    }
    if ((sp3C->unkB6 == 0) && (func_8001B62C(gCurrentParsedObject, 0) == 12.0f)) {
        sp3C->unkB6 = 1;
        sp38 = func_80027464(1, &D_endol_803371B4, sp3C->Pos.x, sp3C->Pos.y, sp3C->Pos.z, sp3C->Rot.y);
        func_80026F10(sp38, 0xE);
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001C0EC(sp38, 3, 0, 0xCC, &D_80119FD0);
        sp3C->unkB8 = (s16) sp38;
    }
    if ((sp3C->unk132 == 1) && (sp3C->unkB6 == 1)) {
        sp3C->Rot.x = (f32) Math_Random(-2);
        sp3C->Rot.z = (f32) Math_Random(-2);
        gObjects[sp3C->unkB8].Rot.x = sp3C->Rot.x;
        gObjects[sp3C->unkB8].Rot.z = sp3C->Rot.z;
    }
    if (sp3C->unkC0 == 0x1E) {
        sp3C->unkC0 -= 1;
        func_8007F070(sp3C->Pos.x, sp3C->Pos.y, sp3C->Pos.z, 5.0f);
    } else if (sp3C->unkC0 == 0) {
        if (sp3C->unk132 == 1) {
            sp3C->unk132 += 1;
            func_8002B114((s32) sp3C->unkB8);
            func_8001BB34(gCurrentParsedObject, 1);
            sp3C->unkB4 = 1;
            func_800175F0(gCurrentParsedObject, 0, 0x67, -1, 0);
            for (sp2E = 0; sp2E < 10; sp2E++) {
                sp28 = Math_Random(-0x3C0);
                sp24 = Math_Random(0xF0);
                sp20 = Math_Random(-0x3C0);
                sp38 = func_80027464(1, &D_endol_803371C0, (f32) sp28, (f32) (0x4B0 - sp24), (f32) sp20, 0.0f);
            }
            sp3C->unkC2 = 0x5C;
        }
    } else {
        sp3C->unkC0 -= 1;
    }
    if (sp3C->unk132 == 2) {
        if (sp3C->unkC2 == 2) {
            func_8002B114(gCurrentParsedObject);
        } else {
            sp3C->unkC2 -= 1;
        }
    }
}

void func_endol_80335808(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->damageState == OBJ_DEATH) {
        if (sp24->unkB4 == 0) {
            func_8001BB34(gCurrentParsedObject, 0);
        }
    } else {
        func_8001BB34(gCurrentParsedObject, !(sp24->damageState & 1));
    }
    switch (sp24->actionState) {
        case 1:
            func_endol_80330B5C();
            break;
        case 2:
            func_endol_80330CC0();
            break;
        case 3:
            func_endol_80330DA4();
            break;
        case 4:
            func_endol_80330E88();
            break;
        case 5:
            func_endol_80331130();
            break;
        case 6:
            func_endol_80331288();
            break;
        case 7:
            func_endol_803313D4();
            break;
        case 8:
            func_endol_803314D4();
            break;
        case 9:
            func_endol_803315B8();
            break;
        case 10:
            func_endol_80331708();
            break;
        case 11:
            func_endol_803317EC();
            break;
        case 12:
            func_endol_803318D0();
            break;
        case 13:
            func_endol_80331C58();
            break;
        case 14:
            func_endol_80331D6C();
            break;
        case 15:
            func_endol_80331E50();
            break;
        case 16:
            func_endol_80331FD8();
            break;
        case 17:
            func_endol_803320E0();
            break;
        case 18:
            func_endol_80332294();
            break;
        case 19:
            func_endol_8033244C();
            break;
        case 20:
            func_endol_80332584();
            break;
        case 21:
            func_endol_803326BC();
            break;
        case 22:
            func_endol_803327F4();
            break;
        case 23:
            func_endol_803329C4();
            break;
        case 24:
            func_endol_80332B2C();
            break;
        case 25:
            func_endol_80332CD0();
            break;
        case 26:
            func_endol_80332F7C();
            break;
        case 27:
            func_endol_803331F8();
            break;
        case 28:
            func_endol_803333F4();
            break;
        case 29:
            func_endol_803335F0();
            break;
        case 30:
            func_endol_8033381C();
            break;
        case 31:
            func_endol_803339AC();
            break;
        case 32:
            func_endol_80333BA0();
            break;
        case 33:
            func_endol_80333CD4();
            break;
        case 34:
            func_endol_80333EC4();
            break;
        case 35:
            func_endol_80334090();
            break;
        case 36:
            func_endol_80334174();
            break;
        case 37:
            func_endol_80334258();
            break;
        case 38:
            func_endol_803343F8();
            break;
        case 39:
            func_endol_8033461C();
            break;
        case 40:
            func_endol_80334738();
            break;
        case 41:
            func_endol_80334880();
            break;
        case 42:
            func_endol_80334964();
            break;
        case 43:
            func_endol_80334BD4();
            break;
        case 44:
            func_endol_80334CB8();
            break;
        case 45:
            func_endol_80334DE8();
            break;
        case 46:
            func_endol_80334EEC();
            break;
        case 47:
            func_endol_8033509C();
            break;
        case 48:
            func_endol_803351B0();
            break;
        case 49:
            func_endol_80335300();
            break;
        default:
            break;
    }
}

void func_endol_80335C1C(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if ((D_80177A64 == 0) || (D_80177A64 == 1)) {
    } else if ((sp4->unkB2 == 2)) {
        if (gObjects[sp4->unkC2].unkAA == 0) {
            gObjects[sp4->unkC2].actionState = 0x16;
            gObjects[sp4->unkC2].unk132 = 0;
        }
    }
}

void func_endol_80335D2C(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
}

void func_endol_80335D6C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        sp1C->unkB2 = sp1C->actionState;
        sp1C->unkD4 = 2.0f;
        sp1C->unkA6 = 0xB3;
    }
    sp1C->Rot.y = Math_WrapAngle(sp1C->Rot.y, sp1C->unkD4);
    if (sp1C->unkA6 == 0) {
        func_endol_80330000();
        sp1C->unkA6 = 0xB4;
    } else {
        sp1C->unkA6 -= 1;
    }
}

void func_endol_80335E88(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unk132 == 0) {
        sp4->unk132 += 1;
        sp4->unkB2 = sp4->actionState;
        sp4->unkA8 = 0x14;
    }
    if (sp4->unkA8 == 0) {
        gObjects[sp4->unkC2].unkBC = 0;
        gObjects[sp4->unkC2].unkBE = 0;
        gObjects[sp4->unkC2].unkC0 = 0;
        gObjects[sp4->unkC2].unkC2 = 0;
        sp4->actionState = 4;
        sp4->unk132 = 0;
    } else {
        sp4->unkA8 -= 1;
    }
}

void func_endol_80336010(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkA8 = 0x3C;
    }
    func_800175F0(gCurrentParsedObject, 0, 0x3E, -1, 0);
    if (sp24->unkA8 == 0) {
        gObjects[sp24->unkC2].unkBA = 0;
        func_8002B114(gCurrentParsedObject);
        return;
    } else {
        sp24->Vel.y = -3.0f;
        sp24->unkD4 = 4.0f;
        sp24->Rot.y = Math_WrapAngle(sp24->Rot.y, sp24->unkD4);
        sp24->unkA8 -= 1;
    }
}

void func_endol_8033617C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->actionState) { /* irregular */
        case 1:
            func_endol_80335D2C();
            break;
        case 2:
            func_endol_80335D6C();
            break;
        case 3:
            func_endol_80335E88();
            break;
        case 4:
            func_endol_80336010();
            break;
        default:
            break;
    }
}

void func_endol_80336258(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if ((D_80177A64 == 0) || (D_80177A64 == 1)) {

    } else if ((sp4->unkB2 == 5)) {
        if ((gObjects[sp4->unkC2].unkAA == 0)) {
            gObjects[sp4->unkC2].actionState = 0x16;
            gObjects[sp4->unkC2].unk132 = 0;
        }
    }
}

void func_endol_80336368(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
}

void func_endol_803363A8(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xCB, &D_80119FC0);
        sp24->moveSpeed = 10.0f;
        sp24->moveAngle = sp24->Rot.y;
        sp24->unkA6 = 0x14;
    }
    if (sp24->unkA6 == 0) {
        sp24->moveSpeed = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
        sp24->actionState = 3;
        sp24->unk132 = 0;
    } else {
        sp24->unkA6 -= 1;
        func_80029C40(gCurrentParsedObject);
    }
}

void func_endol_8033651C(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xCB, &D_80119FC0);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->actionState = 4;
        sp24->unk132 = 0;
    }
}

void func_endol_80336600(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xCB, &D_80119FC0);
    }
}

void func_endol_803366B4(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (sp1C->unk132 == 0) {
        sp1C->unk132 += 1;
        sp1C->unkB2 = sp1C->actionState;
        sp1C->unkD4 = 2.0f;
        sp1C->unkA6 = 0xB3;
    }
    sp1C->Rot.y = Math_WrapAngle(sp1C->Rot.y, sp1C->unkD4);
    if (sp1C->unkA6 == 0) {
        func_endol_80330000();
        sp1C->unkA6 = 0xB4;
    } else {
        sp1C->unkA6 -= 1;
    }
}

void func_endol_803367D0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unkB2 = sp24->actionState;
        sp24->unkA8 = 0x14;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xCB, &D_80119FC0);
        sp24->moveSpeed = 10.0f;
        sp24->moveAngle = Math_WrapAngle(sp24->Rot.y, 180.0f);
    }

    if (sp24->unkA8 == 0) {
        func_8002B114(gCurrentParsedObject);
        return;
    } else {
        func_80029C40(gCurrentParsedObject);
        sp24->unkA8 -= 1;
    }
}

void func_endol_80336928(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    switch (sp1C->actionState) {
        case 1:
            func_endol_80336368();
            break;
        case 2:
            func_endol_803363A8();
            break;
        case 3:
            func_endol_8033651C();
            break;
        case 4:
            func_endol_80336600();
            break;
        case 5:
            func_endol_803366B4();
            break;
        case 6:
            func_endol_803367D0();
            break;
        default:
            break;
    }
}

void func_endol_80336A18(void) {
    struct ObjectStruct* sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if ((D_80177A64 == 0) || (D_80177A64 == 1)) {

    } else {
        switch (gObjects[sp4->unkC2].actionState) {
            case 30:
            case 31:
            case 32:
            case 38:
            case 39:
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
                if (gObjects[sp4->unkC2].damageState != 0) {
                    gObjects[sp4->unkC2].actionState = 0x2E;
                    gObjects[sp4->unkC2].unk132 = 0;
                }
                break;
        }
    }
    sp4->actionState = 4;
    sp4->unk132 = 0;
}

void func_endol_80336B8C(void) {
    struct ObjectStruct* sp1C;

    sp1C = &gObjects[gCurrentParsedObject];
    if (gObjects[0xE].actionState == 0x2B) {
        if (sp1C->unk132 == 0) {
            sp1C->unk132 += 1;
            sp1C->moveSpeed = 9.0f;
            sp1C->moveAngle = gObjects[0xE].moveAngle;
            sp1C->Rot.y = sp1C->moveAngle;
            sp1C->unkA6 = 3;
        }
        if (sp1C->unkA6 == 0) {
            sp1C->actionState = 2;
            sp1C->unk132 = 0;
            sp1C->moveSpeed = 0.0f;
            sp1C->Vel.z = 0.0f;
            sp1C->Vel.x = sp1C->Vel.z;
        } else {
            func_80029C40(gCurrentParsedObject);
            sp1C->moveSpeed += 9.0f;
            sp1C->unkA6 -= 1;
        }
    }
}

void func_endol_80336D14(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->moveSpeed = 42.0f;
        sp24->unkA6 = 0xA;
        sp24->Vel.y = -12.0f;
    }
    func_8002A8B4(gCurrentParsedObject, 9.0f);
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 45.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->actionState = 4;
    } else if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -45.0f, 45.0f) == 1) {
        sp24->actionState = 4;
    } else if (sp24->Pos.y <= 300.0f) {
        sp24->actionState = 4;
    }
}

void func_endol_80336E94(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_endol_80336EC4(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    switch (sp24->actionState) { /* irregular */
        case 1:
            func_endol_80336B8C();
            break;
        case 2:
            func_endol_80336D14();
            break;
        case 4:
            func_endol_80336E94();
            break;
        default:
            break;
    }
}

void func_endol_80336F84(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xFE, &D_80119FD4);
        sp20 = Math_Random(0x14);
        func_8001B6BC(gCurrentParsedObject, 0, (f32) (sp20 * 2));
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        sp24->Pos.y -= 380.0f;
        if (sp24->Pos.y < 300.0f) {
            func_8002B114(gCurrentParsedObject);
        }
    }
}

void func_endol_803370C0(void) {
    struct ObjectStruct* sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x197, &D_80119FD8);
    }
    if (func_8001B4AC(gCurrentParsedObject, 3) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
}
