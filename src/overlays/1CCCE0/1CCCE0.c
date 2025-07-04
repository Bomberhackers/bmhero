#include <ultra64.h>

/*
 *  These symbols seem to be used between code and the overlays..
 */

extern struct UnkStruct_80027C00 D_80114528;
extern struct UnkStruct_80027C00 D_80114534;
extern struct UnkStruct_80027C00 D_80114540;
extern struct UnkStruct_80027C00 D_8011454C;
extern struct UnkStruct_80027C00 D_80114558;
extern struct UnkStruct_80027C00 D_80114570;
extern u32 D_8011730C;
extern UNK_TYPE D_80117C94;
extern u32 D_80118ACC;
extern u32 D_80118AD0;
extern u32 D_80118AE4;

void func_80330000_unk_bin_35(void) {
    s32 objIdx;

    objIdx = func_80027464(1, &D_80114528, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                           (f32) D_80165100->unk8);
    if (objIdx != -1) {
        gObjects[objIdx].Scale.x = gObjects[objIdx].Scale.y = gObjects[objIdx].Scale.z = 1.5f;
    }
}

void func_80330118_unk_bin_35(struct ObjectStruct* obj, s32 arg1) {
    if (arg1 == 0) {
        obj->unkAC += 1;
        if (obj->unkAC >= 0xF) {
            obj->unkAC = 0xF;
        }
    } else {
        obj->unkAC -= 1;
        if (obj->unkAC <= 0) {
            obj->unkAC = 0;
        }
    }
    obj->Rot.y = Math_WrapAngle(obj->Rot.y, (f32) obj->unkAC);
}

void func_803301FC_unk_bin_35(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (D_80177A64 == 0) {
        obj->actionState = 6;
        obj->unk132 = 0;
    } else if ((D_80177A64 == 1) && (obj->actionState < 6)) {
        obj->actionState = 5;
        obj->unk132 = 0;
        obj->damageState = 0x14;
    }
}

void func_803302BC_unk_bin_35(struct ObjectStruct* obj) {
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x6F, &D_80118ACC);
        func_8001BB04(gCurrentParsedObject, 1.0f);
    }
    if (func_8002A1FC(gCurrentParsedObject, 540.0f) != 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
    }
}

void func_803303A4_unk_bin_35(struct ObjectStruct* obj) {
    f32 sp24;
    f32 sp20;

    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkAC = 0;
        obj->unk44 = 0.0f;
        obj->unk40 = 90.0f;
        obj->unk48 = 50.0f;
        func_8001BB04(gCurrentParsedObject, 0);
        func_800175F0(gCurrentParsedObject, 0, 0x31, -1, 0);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_80330118_unk_bin_35(obj, 0);
    func_800295C0(gCurrentParsedObject, &sp24, &sp20, 0.0f, 0.0f, 0.0f);
    if (obj->Pos.y >= (sp24 + 150.0f)) {
        obj->Vel.y = 0.0f;
        obj->actionState = 3;
        obj->unk132 = 0;
    }
}

void func_8033050C_unk_bin_35(struct ObjectStruct* obj) {
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = 0xA;
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
    }
    func_80330118_unk_bin_35(obj, 0.0f);
    obj->unkA6 -= 1;
    if (obj->unkA6 == 0) {
        obj->actionState = 4;
        obj->unk132 = 0;
    }
}

void func_803305F0_unk_bin_35(struct ObjectStruct* obj) {
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk44 = 0.0f;
        obj->unk3C = func_8002A46C(gCurrentParsedObject);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80330118_unk_bin_35(obj, 0);
    if (obj->unk44 < 10.0f) {
        obj->unk44 = (f32) ((f64) obj->unk44 + 0.5);
    }
    obj->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 4U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        obj->unk3C = func_8002A46C(gCurrentParsedObject);
    }
}

void func_8033074C_unk_bin_35(struct ObjectStruct* obj) {
    f32 sp34;
    f32 sp30;

    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = 0x5A;
        obj->unkA8 = 0;
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
    }
    if (obj->unkA8 == 0) {
        obj->unk40 = 270.0f;
        obj->unk48 = 50.0f;
        obj->unkA8 = 1;
    } else {
        obj->unk40 = 0.0f;
        obj->unk48 = 0.0f;
    }
    func_80029D04(gCurrentParsedObject);
    func_800294F0(gCurrentParsedObject, &sp34, &sp30, 0.0f, 0.0f, 0.0f);
    if (obj->Pos.y <= (sp34 + 50.0f)) {
        obj->unk100 = 1;
    }
    if (obj->unkA6 == 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
        obj->unk100 = -1;
        return;
    } else {
        obj->unkA6 -= 1;
    }
}

void func_80330928_unk_bin_35(UNUSED struct ObjectStruct* obj) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_8033095C_unk_bin_35(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    switch (obj->actionState) {
        case 1:
            func_803302BC_unk_bin_35(obj);
            break;
        case 2:
            func_803303A4_unk_bin_35(obj);
            break;
        case 3:
            func_8033050C_unk_bin_35(obj);
            break;
        case 4:
            func_803305F0_unk_bin_35(obj);
            break;
        case 5:
            func_8033074C_unk_bin_35(obj);
            break;
        case 6:
            func_80330928_unk_bin_35(obj);
            break;
        default:
            break;
    }
}

void func_80330A64_unk_bin_35(void) {
    struct ObjectStruct* obj;
    s32 sp20;

    obj = &gObjects[gCurrentParsedObject];
    sp20 = FALSE;
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unk3C = obj->Rot.y;
        obj->unk40 = 0.0f;
        obj->unk44 = 15.0f;
        obj->unkA6 = 0x28;
    }
    obj->Rot.z = Math_WrapAngle(obj->Rot.z, 2.0f);
    obj->Scale.x = (f32) ((f64) obj->Scale.x + 0.03);
    obj->Scale.y = (f32) ((f64) obj->Scale.y + 0.03);
    obj->Scale.z = (f32) ((f64) obj->Scale.z + 0.06);
    func_80029D8C(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp20 = TRUE;
    }
    if (obj->unkA6 == 0) {
        sp20 = TRUE;
    } else {
        obj->unkA6 -= 1;
    }
    if (sp20) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
}

void func_80330C64_unk_bin_35(void) {
    if (gObjects[gCurrentParsedObject].actionState == 1) {
        if (FALSE) {}
        func_80330A64_unk_bin_35();
    } else {
        if (FALSE) {}
    }
}

void func_80330CD8_unk_bin_35(void) {
    s32 objIdx;

    objIdx = func_80027464(1, &D_80114534, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                           (f32) D_80165100->unk8);
    if (objIdx != -1) {
        gObjects[objIdx].Scale.x = gObjects[objIdx].Scale.y = gObjects[objIdx].Scale.z = 0.5f;
    }
}

void func_80330DF0_unk_bin_35(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 5;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

s32 func_80330E68_unk_bin_35(struct ObjectStruct* obj, s32 arg1) {
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    Matrix sp74;
    Matrix sp34;

    guRotateF(sp74, obj->Rot.y, 0.0f, 1.0f, 0.0f);
    guTranslateF(sp34, obj->Pos.x, obj->Pos.y, obj->Pos.z);
    guMtxCatF(sp74, sp34, sp74);
    guMtxXFMF(sp74, -240.0f, 0.0f, -60.0f, &spD4, &spB4, &spD0);
    guMtxXFMF(sp74, -240.0f, 0.0f, (f32) arg1, &spCC, &spB4, &spC8);
    guMtxXFMF(sp74, 240.0f, 0.0f, (f32) arg1, &spC4, &spB4, &spC0);
    guMtxXFMF(sp74, 240.0f, 0.0f, -60.0f, &spBC, &spB4, &spB8);
    if ((gPlayerObject->Pos.y >= (obj->Pos.y - 240.0f)) && (gPlayerObject->Pos.y <= (obj->Pos.y + 480.0f)) &&
        (func_800163AC(gPlayerObject->Pos.x, gPlayerObject->Pos.z, spD4, spD0, spCC, spC8, spC4, spC0, spBC, spB8))) {

        return 1;
    }
    return 0;
}

void func_80331054_unk_bin_35(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x8B, &D_80118AD0);
    }
    if (func_80330E68_unk_bin_35(obj, 0x258) != 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
    }
}

void func_8033115C_unk_bin_35(void) {
    struct ObjectStruct* obj;
    UNUSED f32 pad;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x8B, &D_80118AD0);
        func_8001B754(gCurrentParsedObject, 0);
    }
    obj->Scale.x = (f32) ((f64) obj->Scale.x + 0.05);
    if (obj->Scale.x >= 1.0f) {
        obj->Scale.x = 1.0f;
    }
    obj->Scale.y = obj->Scale.z = obj->Scale.x;
    if ((func_8001B44C(gCurrentParsedObject, 0) != 0) && (obj->Scale.x == 1.0f)) {
        obj->actionState = 3;
        obj->unk132 = 0;
    }
}

void func_803312E8_unk_bin_35(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x8B, &D_80118AD0);
        obj->unkA6 = 0;
        func_8001FB3C(0x1E, 5, 1);
    }
    if (obj->unkA6 == 0) {
        func_80027464(1, &D_80114540, obj->Pos.x, obj->Pos.y + 240.0f, obj->Pos.z, obj->Rot.y);
        func_800175F0(gCurrentParsedObject, 0, 0x37, -1, 0);
        obj->unkA6 = 0x10;
    } else {
        obj->unkA6 -= 1;
    }
    if (func_80330E68_unk_bin_35(obj, 0x3C0) != 0) {
        if (D_8016E120 == 0) {
            D_8016E120 = 0xC1;
            D_8016E128 = gCurrentParsedObject;
            D_8016E130 = sinf((f32) ((f64) obj->Rot.y * DEG_TO_RAD)) * 20.0f;
            D_8016E138 = 0.0f;
            D_8016E1B4 = cosf((f32) ((f64) obj->Rot.y * DEG_TO_RAD)) * 20.0f;
        }
    } else {
        D_8016E120 = 0;
        obj->actionState = 4;
        obj->unk132 = 0;
    }
}

void func_80331524_unk_bin_35(void) {
    struct ObjectStruct* obj;
    UNUSED f32 pad;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x8B, &D_80118AD0);
        func_8001B754(gCurrentParsedObject, 0);
    }
    obj->Scale.x = (f32) ((f64) obj->Scale.x - 0.05);
    if ((f64) obj->Scale.x <= 0.5) {
        obj->Scale.x = 0.5f;
    }
    obj->Scale.y = obj->Scale.z = obj->Scale.x;
    if ((func_8001B44C(gCurrentParsedObject, 0) != 0) && ((f64) obj->Scale.x == 0.5)) {
        obj->actionState = 1;
        obj->unk132 = 0;
    }
}

void func_803316B8_unk_bin_35(void) {
    func_8002B0E4(gCurrentParsedObject);
    D_8016E120 = 0;
}

void func_803316F0_unk_bin_35(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_80331054_unk_bin_35();
            break;
        case 2:
            func_8033115C_unk_bin_35();
            break;
        case 3:
            func_803312E8_unk_bin_35();
            break;
        case 4:
            func_80331524_unk_bin_35();
            break;
        case 5:
            func_803316B8_unk_bin_35();
            break;
        default:
            break;
    }
}

void func_803317C0_unk_bin_35(void) {
    s32 objIdx;

    objIdx = func_80027464(1, &D_8011454C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                           (f32) D_80165100->unk8);
    if (objIdx != -1) {
        gObjects[objIdx].Scale.x = gObjects[objIdx].Scale.y = gObjects[objIdx].Scale.z = 1.5f;
    }
}

void func_803318D8_unk_bin_35(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 5;
    }
}

void func_80331928_unk_bin_35(void) {
    struct ObjectStruct* obj;
    f32 sp40;
    f32 sp3C;
    s32 sp38;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unk44 = 5.0f;
        obj->unkB0 = 0;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x5A, &D_80118AE4);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        obj->unkB0 = 0xA;
    }
    if (obj->unkB0 == 0) {
        sp38 = func_8002A640(gCurrentParsedObject, 10.0f);
        obj->Rot.y = Math_WrapAngle(obj->Rot.y, (f32) (sp38 * 0xA));
        obj->unk3C = obj->Rot.y;
    } else {
        obj->unkB0 -= 1;
    }
    obj->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
        obj->unkB0 = 0xA;
    }
    if (func_800295C0(gCurrentParsedObject, &sp40, &sp3C, 0.0f, 0.0f, 0.0f) != 0) {
        obj->Pos.y = sp3C;
    } else {
        obj->Pos.y = sp40;
    }
    if (func_8002A1FC(gCurrentParsedObject, 480.0f) != 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
    }
}

void func_80331BE0_unk_bin_35(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x5A, &D_80118AE4);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 3;
        obj->unk132 = 0;
    }
}

void func_80331CEC_unk_bin_35(void) {
    struct ObjectStruct* obj;
    f32 sp38;
    f32 sp34;
    s32 sp30;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unk44 = 25.0f;
        sp30 = (s32) func_8002A46C(gCurrentParsedObject);
        obj->unk3C = (f32) sp30;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x5A, &D_80118AE4);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    obj->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 80.0f, 0.0f, 0.0f, 0.0f) != 0) {
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
        obj->Rot.y = obj->unk3C;
        obj->actionState = 4;
        obj->unk132 = 0;
    }
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) {
        obj->Pos.y = sp34;
    } else {
        obj->Pos.y = sp38;
    }
}

void func_80331F24_unk_bin_35(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x5A, &D_80118AE4);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        obj->actionState = 1;
        obj->unk132 = 0;
    }
}

void func_80331FF4_unk_bin_35(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80332024_unk_bin_35(void) {
    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_80331928_unk_bin_35();
            break;
        case 2:
            func_80331BE0_unk_bin_35();
            break;
        case 3:
            func_80331CEC_unk_bin_35();
            break;
        case 4:
            func_80331F24_unk_bin_35();
            break;
        case 5:
            func_80331FF4_unk_bin_35();
            break;
        default:
            break;
    }
}

void func_803320F4_unk_bin_35(void) {
    s32 objIdx;
    s32 objIdx1;

    objIdx = func_80027464(2, &D_80114558, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                           (f32) D_80165100->unk8);
    if (objIdx != -1) {
        gObjects[objIdx].Scale.x = gObjects[objIdx].Scale.y = gObjects[objIdx].Scale.z = 2.0f;
        objIdx1 = gObjects[objIdx].unkE8[0];
        gObjects[objIdx1].Scale.x = gObjects[objIdx1].Scale.y = gObjects[objIdx1].Scale.z = 2.0f;
    }
}

void func_803322B8_unk_bin_35(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].actionState = 5;
    }
}

void func_80332308_unk_bin_35(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
        func_8001BBDC(gCurrentParsedObject, 1);
    }
    if (func_8002A1FC(gCurrentParsedObject, 720.0f) != 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
    }
}

void func_803323F4_unk_bin_35(void) {
    struct ObjectStruct* parent;
    UNUSED struct ObjectStruct* child;
    s32 objIdx;

    parent = &gObjects[gCurrentParsedObject];
    objIdx = (s32) parent->unkE8[0];
    child = &gObjects[objIdx];
    if (parent->unk132 == 0) {
        parent->unk132 = 1;
        parent->unkA6 = 0;
        parent->unk44 = 30.0f;
        parent->unk3C = parent->Rot.y;
        parent->Vel.y = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x49, &D_8011730C);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    func_80029C40(gCurrentParsedObject);
    if (parent->unkA6 >= 8) {
        parent->actionState = 3;
        parent->unk132 = 0;
    } else {
        parent->unkA6 += 1;
    }
}

void func_80332574_unk_bin_35(void) {
    struct ObjectStruct* parent;
    struct ObjectStruct* child;
    s32 objIdx;
    f32 sp30;

    parent = &gObjects[gCurrentParsedObject];
    objIdx = (s32) parent->unkE8[0];
    child = &gObjects[objIdx];
    if (parent->unk132 == 0) {
        parent->unk132 = 1;
        parent->unkA6 = 0;
        parent->Vel.x = parent->Vel.y = parent->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x49, &D_8011730C);
    }
    if (parent->unkA6 == 0) {
        sp30 = func_8001B62C(gCurrentParsedObject, 0);
        if (sp30 >= 32.0f) {
            func_8001BBDC(gCurrentParsedObject, 1);
            parent->unkA6 = 1;
            func_800175F0(gCurrentParsedObject, 0, 0x15, -1, 0);
        }
    } else if (parent->unkA6 == 1) {
        if (child->Scale.z < 10.0f) {
            child->Scale.z += 1.0f;
        } else {
            child->Scale.z = 10.0f;
            parent->unkA6 = 2;
        }
    } else if (parent->unkA6 == 2) {
        if (child->Scale.z > 2.0f) {
            child->Scale.z -= 1.0f;
        } else {
            child->Scale.z = 2.0f;
            func_8001BBDC(gCurrentParsedObject, 0);
            parent->unkA6 = 3;
        }
    } else if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        parent->actionState = 4;
        parent->unk132 = 0;
    }
}

void func_80332860_unk_bin_35(void) {
    struct ObjectStruct* parent;
    UNUSED struct ObjectStruct* child;
    s32 objIdx;

    parent = &gObjects[gCurrentParsedObject];
    objIdx = (s32) parent->unkE8[0];
    child = &gObjects[objIdx];
    if (parent->unk132 == 0) {
        parent->unk132 = 1;
        parent->unkA6 = 0;
        parent->unk44 = 30.0f;
        parent->unk3C = Math_WrapAngle(parent->Rot.y, 180.0f);
        parent->Vel.y = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x49, &D_8011730C);
    }
    func_80029C40(gCurrentParsedObject);
    if (parent->unkA6 >= 8) {
        parent->actionState = 1;
        parent->unk132 = 0;
    } else {
        parent->unkA6 += 1;
    }
}

void func_803329E0_unk_bin_35(void) {
    s32 objIdx;

    objIdx = gObjects[gCurrentParsedObject].unkE8[0];
    func_800281A4(gCurrentParsedObject, 0);
    func_8002B0E4(objIdx);
    func_8002B0E4(gCurrentParsedObject);
}

void func_80332A5C_unk_bin_35(void) {
    struct ObjectStruct* parent;
    struct ObjectStruct* child;
    s32 objIdx;

    parent = &gObjects[gCurrentParsedObject];
    objIdx = (s32) parent->unkE8[0];
    child = &gObjects[objIdx];

    switch (gObjects[gCurrentParsedObject].actionState) {
        case 1:
            func_80332308_unk_bin_35();
            break;
        case 2:
            func_803323F4_unk_bin_35();
            break;
        case 3:
            func_80332574_unk_bin_35();
            break;
        case 4:
            func_80332860_unk_bin_35();
            break;
        case 5:
            func_803329E0_unk_bin_35();
            break;
        default:
            break;
    }
    child->Pos.y = parent->Pos.y + parent->Vel.y + (75.0f * parent->Scale.x);
    child->Pos.z = parent->Pos.z + parent->Vel.z + (30.0f * parent->Scale.x);
}

void func_80332BEC_unk_bin_35(void) {
    s16 objIdx;

    objIdx = func_80027464(1, &D_80114570, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6,
                           (f32) D_80165100->unk8);
    if (objIdx != -1) {
        gObjects[objIdx].actionState = 1;
        gObjects[objIdx].unkA6 = 0;
        gObjects[objIdx].unk132 = 0;
        gObjects[objIdx].unk102 = 0;
        gObjects[objIdx].damageState = 0;
        gObjects[objIdx].Scale.x = 1.0f;
        gObjects[objIdx].Scale.y = gObjects[objIdx].Scale.z = gObjects[objIdx].Scale.x;
        func_80019448((s32) objIdx, 2, 0, 1);
        func_8001ABF4((s32) objIdx, 0, 0, &D_80117C94);
    }
}

void func_80332DE8_unk_bin_35(struct ObjectStruct* arg0) {
    s16 objIdx;

    objIdx = func_80027464(1, &D_80114570, arg0->Pos.x, arg0->Pos.y, arg0->Pos.z, arg0->unk3C);
    if (objIdx != -1) {
        gObjects[objIdx].actionState = 2;
        gObjects[objIdx].unkA6 = 0x50;
        gObjects[objIdx].unk132 = 0;
        gObjects[objIdx].unk102 = 0;
        gObjects[objIdx].damageState = 0;
        gObjects[objIdx].Scale.x = 0.01f;
        gObjects[objIdx].Scale.y = gObjects[objIdx].Scale.z = gObjects[objIdx].Scale.x;
        func_80019448((s32) objIdx, 2, 0, 1);
        func_8001ABF4((s32) objIdx, 0, 0, &D_80117C94);
    }
}

void func_80332FC0_unk_bin_35(void) {
    if ((D_80177A64 != 0) && (D_80177A64 != 1)) {
        return;
    }
    gObjects[gCurrentParsedObject].actionState = 3;
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_8033304C_unk_bin_35(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk44 = 0.0f;
        obj->unk48 = 0.0f;
        func_8001BB34(gCurrentParsedObject, 1);
        func_8001BB04(gCurrentParsedObject, 1);
        gObjInfo[obj->objID].unk0 = 0;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
}

void func_80333140_unk_bin_35(void) {
    struct ObjectStruct* obj;

    obj = &gObjects[gCurrentParsedObject];
    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk44 = 0.0f;
        obj->unk48 = 0.0f;
        func_8001BB34(gCurrentParsedObject, 0);
        func_8001BB04(gCurrentParsedObject, 0);
        gObjInfo[obj->objID].unk0 = 0xE;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (obj->unkA6 <= 0) {
        if (obj->unk132 == 1) {
            obj->unk132 = 2;
            obj->damageState = 1;
            func_8001BB34(gCurrentParsedObject, 0);
        }
        if (obj->Scale.x <= 1.0f) {
            obj->Scale.x += 0.025f;
            obj->Scale.z = obj->Scale.y = obj->Scale.x;
        }
    } else {
        obj->unkA6 -= 1;
    }
}

void func_80333318_unk_bin_35(void) {
    gObjects[gCurrentParsedObject].damageState = 0;
    func_80332DE8_unk_bin_35(&gObjects[gCurrentParsedObject]);
    func_8002B0E4(gCurrentParsedObject);
}

void func_8033339C_unk_bin_35(void) {
    switch (gObjects[gCurrentParsedObject].actionState) { /* irregular */
        case 1:
            func_8033304C_unk_bin_35();
            break;
        case 2:
            func_80333140_unk_bin_35();
            break;
        case 3:
            func_80333318_unk_bin_35();
            break;
    }
}
/* Warning: struct UnkStruct_80134B54 is not defined (only forward-declared) */
