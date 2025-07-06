#include "common.h"
#include "debug.h"

// Unused overlay..

extern u32 D_80119FE0;
extern u32 D_8011A09C;
extern u32 D_8011A178;

struct ObjSpawnInfo D_80332FB0_unk_bin_21 = { 0, OBJ_BAL_LZ2, 0xCF, 2, -1, -1, 1, 0 };
struct ObjSpawnInfo D_80332FBC_unk_bin_21 = { 0, OBJ_BAL_BD2, 0xCD, 16, 8, 1, 1, 0 };

void func_80330000_unk_bin_21(void) {
    s32 obj_idx;

    obj_idx = func_80027464(1, &D_80332FBC_unk_bin_21, (f32) D_80165100->unk2, (f32) D_80165100->unk4,
                            (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    func_80019448(obj_idx, 2, 0, 1);
    func_8001ABF4(obj_idx, 0, 0, &D_8011A09C);
    gObjects[obj_idx].unkA8 = 2;
}

void func_803300D0_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        obj->damageState = 0;
        func_80069E60(0, 1, 0x12C);
        obj->actionState = 0x1A;
        obj->unk132 = 0;
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
        obj->unk44 = 0.0f;
        func_8001BBDC(gCurrentParsedObject, 1);
    } else if (D_80177A64 == 1) {
        obj->damageState = 0x78;
        switch (obj->unkB2) {
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
                obj->actionState = 0xD;
                obj->unk132 = 0;
                obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
                obj->unk44 = 0.0f;
                break;
            default:
                obj->actionState = obj->unkB2;
                break;
        }
    }
}

void func_803302A0_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xCD, &D_80119FE0);
        obj->unkA6 = 0;
    } else if (obj->unk132 == 2) {
        obj->unk132 = 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
    }
}

void func_80330410_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xCD, &D_80119FE0);
        func_800175F0(gCurrentParsedObject, 0, 0x78, -1, 0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (obj->unkA6 == 0) {
            obj->actionState = 3;
            obj->unk132 = 0;
        } else {
            obj->unkA6 -= 1;
            obj->actionState = 1;
            obj->unk132 = 2;
        }
    }
}

void func_8033057C_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xCD, &D_80119FE0);
        obj->Vel.y = 12.0f;
        obj->unkA6 = 4;
    } else if (obj->unk132 == 2) {
        obj->unk132 = 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if ((obj->Pos.y + obj->Vel.y) > 600.0f) {
        obj->Pos.y = 600.0f;
        obj->Vel.y = 0.0f;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 4;
        obj->unk132 = 0;
    }
}

void func_80330750_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xCD, &D_80119FE0);
        func_800175F0(gCurrentParsedObject, 0, 0x78, -1, 0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if ((obj->Pos.y + obj->Vel.y) > 600.0f) {
        obj->Pos.y = 600.0f;
        obj->Vel.y = 0.0f;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (obj->unkA6 == 0) {
            obj->actionState = 5;
            obj->unk132 = 0;
        } else {
            obj->unkA6 -= 1;
            obj->actionState = 3;
            obj->unk132 = 2;
        }
    }
}

void func_80330908_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 6;
        obj->unk132 = 0;
    }
}

void func_80330A10_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 7;
        obj->unk132 = 0;
    }
}

void func_80330B18_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 6, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 8;
        obj->unk132 = 0;
    }
}

void func_80330C20_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 9;
        obj->unk132 = 0;
    }
}

void func_80330D28_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 8, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0xA;
        obj->unk132 = 0;
    }
}

void func_80330E30_unk_bin_21(void) {
    struct ObjectStruct* obj;
    UNUSED char pad[0xC];

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        obj->unk40 = 340.0f;
        obj->unk44 = 42.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 9, 0xCD, &D_80119FE0);
        func_800175F0(gCurrentParsedObject, 0, 0x79, -1, 0);
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0xB;
        obj->unk132 = 0;
    }
}

void func_80330F68_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xA, 0xCD, &D_80119FE0);
    }
    func_80029D8C(gCurrentParsedObject);
    if ((obj->Pos.y + obj->Vel.y) < 330.0f) {
        obj->actionState = 0xC;
        obj->unk132 = 0;
        obj->Vel.y = 0.0f;
        obj->unk40 = 0.0f;
    }
}

void func_8033108C_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        obj->unkA6 = 0x10;
    }
    func_80029C40(gCurrentParsedObject);
    if (obj->unkA6 == 0) {
        obj->actionState = 0xD;
        obj->unk132 = 0;
        obj->Vel.y = 0.0f;
        obj->Vel.z = 0.0f;
        obj->Vel.x = obj->Vel.z;
        obj->unk44 = 0.0f;
        obj->unk40 = 0.0f;
    } else {
        obj->unkA6 -= 1;
    }
}

void func_803311D4_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0xCD, &D_80119FE0);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (obj->unkA8 == 0) {
            obj->actionState = 0xE;
            obj->unk132 = 0;
            obj->Vel.y = 0.0f;
            if (obj->unk100 >= 7) {
                obj->unkA8 = 2;
            } else {
                obj->unkA8 = 1;
            }
        } else {
            obj->actionState = 1;
            obj->unk132 = 0;
            obj->Vel.y = 0.0f;
            obj->unkA8 -= 1;
        }
    }
}

void func_80331360_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xC, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0xF;
        obj->unk132 = 0;
    }
}

void func_80331468_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xD, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0x10;
        obj->unk132 = 0;
    }
}

void func_80331570_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xE, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0x11;
        obj->unk132 = 0;
    }
}

void func_80331678_unk_bin_21(void) {
    struct ObjectStruct* obj;
    UNUSED char pad[0x14];

    obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x11, 0xCD, &D_80119FE0);
        obj->unk40 = 0.0f;
        obj->Rot.x = 0.0f;
    }
    func_8002A8B4(gCurrentParsedObject, 9.0f);
    obj->Rot.y = obj->moveAngle;
    obj->unk40 = Math_WrapAngle(obj->unk40, -1.5f);
    obj->Rot.x = 360.0f - obj->unk40;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0x12;
        obj->unk132 = 0;
    }
}

void func_803317E0_unk_bin_21(void) {
    struct ObjectStruct* obj;
    UNUSED char pad[8];
    s32 sp20;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x12, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 9.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B62C(gCurrentParsedObject, 0) == 16.0f) {
        sp20 = func_80027464(1, &D_80332FB0_unk_bin_21, obj->Pos.x, obj->Pos.y, obj->Pos.z, obj->Rot.y);
        func_8001C0EC(sp20, 0, 0, 0xCF, &D_8011A178);
        func_80026F10(gCurrentParsedObject, sp20);
        func_80019448(sp20, 2, 0, 1);
        gObjects[sp20].unkC2 = (s16) gCurrentParsedObject;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0x13;
        obj->unk132 = 0;
    }
}

void func_803319B8_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x13, 0xCD, &D_80119FE0);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0x14;
        obj->unk132 = 0;
    }
}

void func_80331A9C_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x14, 0xCD, &D_80119FE0);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0x15;
        obj->unk132 = 0;
    }
}

void func_80331B80_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xF, 0xCD, &D_80119FE0);
        obj->moveAngle = obj->Rot.y;
        if (obj->Rot.x != 0.0f) {
            if (obj->Rot.x > 180.0f) {
                obj->unkD4 = 360.0f - (obj->Rot.x / 8.0f);
            } else {
                obj->unkD4 = (obj->Rot.x * -1.0f) / 8.0f;
            }
        }
    }
    obj->Rot.x = Math_WrapAngle(obj->Rot.x, obj->unkD4);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->Rot.x = 0.0f;
        obj->actionState = 0x16;
        obj->unk132 = 0;
    }
}

void func_80331D44_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x10, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0x17;
        obj->unk132 = 0;
    }
}

void func_80331E4C_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x18, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0x18;
        obj->unk132 = 0;
    }
}

void func_80331F54_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x19, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 0x19;
        obj->unk132 = 0;
    }
}

void func_8033205C_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x1A, 0xCD, &D_80119FE0);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 1;
        obj->unk132 = 0;
    }
}

void func_80332164_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        obj->unkA6 = 0x3C;
        func_80069E60(0, 1, 0x82);
    }
    if (obj->unkA6 == 0x1E) {
        obj->unkA6 -= 1;
        func_800175F0(gCurrentParsedObject, 0, 0x1C, -1, 0);
        func_8007F070(obj->Pos.x, obj->Pos.y + 210.0f, obj->Pos.z, 7.0f);
    } else if (obj->unkA6 == 0) {
        func_8001BB34(gCurrentParsedObject, 1);
        if (obj->unk132 == 1) {
            func_800175F0(gCurrentParsedObject, 0, 0x67, -1, 0);
            obj->unk132 += 1;
        }
    } else {
        obj->unkA6 -= 1;
    }
}

void func_8033231C_unk_bin_21(void) {
    struct ObjectStruct* obj;
    UNUSED s16 pad;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->damageState == OBJ_DEATH) {
        func_8001BB34(gCurrentParsedObject, 0);
    } else {
        func_8001BB34(gCurrentParsedObject, !(obj->damageState & 1));
    }
    switch (obj->actionState) {
        case 1:
            func_803302A0_unk_bin_21();
            break;
        case 2:
            func_80330410_unk_bin_21();
            break;
        case 3:
            func_8033057C_unk_bin_21();
            break;
        case 4:
            func_80330750_unk_bin_21();
            break;
        case 5:
            func_80330908_unk_bin_21();
            break;
        case 6:
            func_80330A10_unk_bin_21();
            break;
        case 7:
            func_80330B18_unk_bin_21();
            break;
        case 8:
            func_80330C20_unk_bin_21();
            break;
        case 9:
            func_80330D28_unk_bin_21();
            break;
        case 10:
            func_80330E30_unk_bin_21();
            break;
        case 11:
            func_80330F68_unk_bin_21();
            break;
        case 12:
            func_8033108C_unk_bin_21();
            break;
        case 13:
            func_803311D4_unk_bin_21();
            break;
        case 14:
            func_80331360_unk_bin_21();
            break;
        case 15:
            func_80331468_unk_bin_21();
            break;
        case 16:
            func_80331570_unk_bin_21();
            break;
        case 17:
            func_80331678_unk_bin_21();
            break;
        case 18:
            func_803317E0_unk_bin_21();
            break;
        case 19:
            func_803319B8_unk_bin_21();
            break;
        case 20:
            func_80331A9C_unk_bin_21();
            break;
        case 21:
            func_80331B80_unk_bin_21();
            break;
        case 22:
            func_80331D44_unk_bin_21();
            break;
        case 23:
            func_80331E4C_unk_bin_21();
            break;
        case 24:
            func_80331F54_unk_bin_21();
            break;
        case 25:
            func_8033205C_unk_bin_21();
            break;
        case 26:
            func_80332164_unk_bin_21();
            break;
        default:
            break;
    }
}

void func_803325A8_unk_bin_21(void) {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        obj->damageState = 0;
    }
    obj->Rot.x = gObjects[obj->unkC2].Rot.x;
    obj->unk40 = gObjects[obj->unkC2].unk40;
    obj->Rot.y = gObjects[obj->unkC2].Rot.y;
    obj->moveAngle = gObjects[obj->unkC2].moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
    }
}

void func_80332744_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xCF, &D_8011A178);
        obj->damageState = -1;
    }
    obj->Rot.x = gObjects[obj->unkC2].Rot.x;
    obj->unk40 = gObjects[obj->unkC2].unk40;
    obj->Rot.y = gObjects[obj->unkC2].Rot.y;
    obj->moveAngle = gObjects[obj->unkC2].moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 3;
        obj->unk132 = 0;
    }
}

void func_80332904_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xCF, &D_8011A178);
        func_800175F0(gCurrentParsedObject, 0, 0x22, -1, 0);
    }
    obj->Rot.x = gObjects[obj->unkC2].Rot.x;
    obj->unk40 = gObjects[obj->unkC2].unk40;
    obj->Rot.y = gObjects[obj->unkC2].Rot.y;
    obj->moveAngle = gObjects[obj->unkC2].moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 4;
        obj->unk132 = 0;
    }
}

void func_80332AD4_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xCF, &D_8011A178);
    }
    obj->Rot.x = gObjects[obj->unkC2].Rot.x;
    obj->unk40 = gObjects[obj->unkC2].unk40;
    obj->Rot.y = gObjects[obj->unkC2].Rot.y;
    obj->moveAngle = gObjects[obj->unkC2].moveAngle;
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 5;
        obj->unk132 = 0;
    }
}

void func_80332C88_unk_bin_21(void) {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        obj->unk44 = 30.0f;
        obj->unkA6 = 2;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0xCF, &D_8011A178);
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (obj->unkA6 == 0) {
            obj->actionState = 6;
            obj->unk132 = 0;
        } else {
            obj->unkA6 -= 1;
        }
    }
}

void func_80332DCC_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0xCF, &D_8011A178);
    }
    func_80029D8C(gCurrentParsedObject);
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_80332EB8_unk_bin_21(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    switch (obj->actionState) {
        case 1:
            func_803325A8_unk_bin_21();
            break;
        case 2:
            func_80332744_unk_bin_21();
            break;
        case 3:
            func_80332904_unk_bin_21();
            break;
        case 4:
            func_80332AD4_unk_bin_21();
            break;
        case 5:
            func_80332C88_unk_bin_21();
            break;
        case 6:
            func_80332DCC_unk_bin_21();
            break;
        default:
            break;
    }
}
