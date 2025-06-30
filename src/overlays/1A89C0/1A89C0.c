#include "common.h"

struct UnkStruct_80027C00 const D_803331B0_unk_bin_20 = { 0, 0x1FA, 0xCA, 1, 1, 1, 1, 0 };
struct UnkStruct_80027C00 const D_803331BC_unk_bin_20 = { 3, 0x1F9, 0x154, 2, -1, 0, 0, 0 };
struct UnkStruct_80027C00 const D_803331C8_unk_bin_20 = { 3, 0x1FB, 0x155, 2, -1, 0, 0, 0 };
struct UnkStruct_80027C00 const D_803331D4_unk_bin_20 = { 0, 0x1F8, 0x153, 2, -1, 1, 1, 0 };
struct UnkStruct_80027C00 const D_803331E0_unk_bin_20 = { 0, 0x1FC, 0x156, 1, -1, 0, 0, 0 };
struct UnkStruct_80027C00 const D_803331EC_unk_bin_20 = { 0, 0x1FD, 0x1A2, 1, -1, 0, 0, 0 };
struct UnkStruct_80027C00 const D_803331F8_unk_bin_20 = { 0, 0x1F7, 0xC8, 0x12, 8, 1, 1, 0 };

const u32 padding[0x2] = { 0 };

void func_80330000_unk_bin_20(void);
void func_803300E8_unk_bin_20(void);
void func_8033020C_unk_bin_20(void);
void func_80330394_unk_bin_20(void);
void func_80330478_unk_bin_20(void);
void func_8033055C_unk_bin_20(void);
void func_80330764_unk_bin_20(void);
void func_803308F0_unk_bin_20(void);
void func_803309F8_unk_bin_20(void);
void func_80330B00_unk_bin_20(void);
void func_80330C08_unk_bin_20(void);
void func_80330D10_unk_bin_20(void);
void func_8033124C_unk_bin_20(void);
void func_80331330_unk_bin_20(void);
void func_80331434_unk_bin_20(void);
void func_80331518_unk_bin_20(void);
void func_803317C4_unk_bin_20(void);
void func_80331A40_unk_bin_20(void);
void func_80331C44_unk_bin_20(void);
void func_80331D28_unk_bin_20(void);
void func_80331E0C_unk_bin_20(void);
void func_80331EF0_unk_bin_20(void);
void func_803321E4_unk_bin_20(void);
void func_80332378_unk_bin_20(void);
void func_803325B4_unk_bin_20(void);
void func_803325E4_unk_bin_20(void);
void func_80332774_unk_bin_20(void);
void func_80332908_unk_bin_20(void);
void func_80332A88_unk_bin_20(void);
void func_80332B48_unk_bin_20(void);
void func_80332C24_unk_bin_20(void);
void func_80332E00_unk_bin_20(void);
void func_80332EDC_unk_bin_20(void);
void func_8033309C_unk_bin_20(void);

void func_80330000_unk_bin_20() {
    s32 idx;

    idx = func_80027464(1, &D_803331F8_unk_bin_20, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6,
                        D_80165100->unk8);

    func_8001ABF4(idx, 0, 0, &D_80119E0C.unk0);
    func_8001ABF4(idx, 1, 0, &D_80119E0C.unk38);
    func_8001ABF4(idx, 2, 0, &D_80119E0C.unk8C);
    func_8001ABF4(idx, 3, 0, &D_80119E0C.unkFC);
}

void func_803300E8_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (D_80177A64 == 0) {
        obj->damageState = 0;

        func_80017B3C(gCurrentParsedObject, 0);
        func_80069E60(0, 1, 0x12C);

        obj->actionState = 0x15;
        obj->unk132 = 0;
        obj->Vel.z = 0.0f;
        obj->Vel.x = obj->Vel.z;
        obj->unk44 = 0.0f;

        func_8001BBDC(gCurrentParsedObject, 1);
    } else if (D_80177A64 == 1) {
        obj->damageState = 0x78;
        obj->actionState = obj->unkB2;
    }
}

void func_8033020C_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;

        func_8001C0EC(gCurrentParsedObject, 0, 1, 0xC8, D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80119E0C.unk1C);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk70);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unk8C);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unkFC);

        if (obj->unkB4 == 0) {
            obj->unkB4 = 0;
        }
    }
    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 2;
        obj->unk132 = 0;
    }
}

void func_80330394_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0xC8, &D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 3;
        obj->unk132 = 0;
    }
}

void func_80330478_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0xC8, &D_80119C80);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 4;
        obj->unk132 = 0;
    }
}

void func_8033055C_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 objIdx;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;

        func_8001C0EC(gCurrentParsedObject, 0, 4, 0xC8, &D_80119C80);

        obj->unkA6 = 1;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        if (obj->unkB4 < 2) {
            if (func_8002A2EC(gCurrentParsedObject, 480.0f)) {
                obj->actionState = 5;
                obj->unk132 = 0;
            } else {
                obj->actionState = 0xE;
                obj->unk132 = 0;
            }
            if (obj->unkBC == 0) {
                obj->unkBC = 1;

                objIdx = func_80027464(1, &D_803331C8_unk_bin_20, obj->Pos.x, obj->Pos.y, obj->Pos.z, obj->Rot.y);

                gObjects[objIdx].unkC2 = gCurrentParsedObject;
            }
            obj->unkB4--;
        } else {
            obj->unkB4--;
            obj->actionState = 1;
            obj->unk132 = 0;
        }
    }
}

void func_80330764_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0xC8, &D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk54);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        if (obj->unkA6 == 0) {
            obj->actionState = 0x10;
            obj->unk132 = 0;

            if (obj->unk100 >= 7) {
                obj->unkA6 = 1;
            } else {
                obj->unkA6 = 1;
            }
        } else {
            obj->actionState = 6;
            obj->unk132 = 0;
            obj->unkA6--;
        }
    }
}

void func_803308F0_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xD, 0xC8, &D_80119C80);
    }

    func_8002A8B4(gCurrentParsedObject, 6.0f);
    obj->Rot.y = obj->unk3C;

    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 7;
        obj->unk132 = 0;
    }
}

void func_803309F8_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xE, 0xC8, &D_80119C80);
    }

    func_8002A8B4(gCurrentParsedObject, 6.0f);
    obj->Rot.y = obj->unk3C;

    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 8;
        obj->unk132 = 0;
    }
}

void func_80330B00_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xF, 0xC8, &D_80119C80);
    }

    func_8002A8B4(gCurrentParsedObject, 6.0f);
    obj->Rot.y = obj->unk3C;

    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 9;
        obj->unk132 = 0;
    }
}

void func_80330C08_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x10, 0xC8, &D_80119C80);
    }

    func_8002A8B4(gCurrentParsedObject, 6.0f);
    obj->Rot.y = obj->unk3C;

    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 10;
        obj->unk132 = 0;
    }
}

void func_80330D10_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    s32 objIdx;
    f32 rotBase;
    f32 addend;
    f32 posX;
    f32 posZ;
    f32 posY;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;

        func_8001C0EC(gCurrentParsedObject, 0, 0x11, 0xC8, &D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unkA8);
    }
    if (func_8001B62C(gCurrentParsedObject, 0) < 18.0f) {
        func_8002A8B4(gCurrentParsedObject, 6.0f);
        obj->Rot.y = obj->unk3C;
    } else if (func_8001B62C(gCurrentParsedObject, 0) == 18.0f) {
        func_800175F0(gCurrentParsedObject, 0, 0x1B, -1, 0);

        rotBase = func_80015538(obj->Rot.y, 16.5f);
        addend = sqrtf(58624.0f);
        posX = (sinf((f32) ((f64) rotBase * DEG_TO_RAD)) * addend) + obj->Pos.x;
        posZ = (cosf((f32) ((f64) rotBase * DEG_TO_RAD)) * addend) + obj->Pos.z;
        objIdx =
            func_80027464(1, &D_803331B0_unk_bin_20, posX, obj->Pos.y + 240.0f, posZ, func_80015538(obj->Rot.y, 20.0f));
        func_8001ABF4(objIdx, 0, 0, &D_80119FA4);
        gObjects[objIdx].unkC2 = gCurrentParsedObject;

        rotBase = func_80015538(obj->Rot.y, -16.5f);
        addend = sqrtf(58624.0f);
        posX = (sinf((f32) ((f64) rotBase * DEG_TO_RAD)) * addend) + obj->Pos.x;
        posZ = (cosf((f32) ((f64) rotBase * DEG_TO_RAD)) * addend) + obj->Pos.z;
        objIdx = func_80027464(1, &D_803331B0_unk_bin_20, posX, obj->Pos.y + 240.0f, posZ,
                               func_80015538(obj->Rot.y, -20.0f));
        func_8001ABF4(objIdx, 0, 0, &D_80119FA4);
        gObjects[objIdx].unkC2 = gCurrentParsedObject;

        posX = (sinf((f32) ((f64) obj->Rot.y * DEG_TO_RAD)) * 60.0f) + obj->Pos.x;
        posZ = (cosf((f32) ((f64) obj->Rot.y * DEG_TO_RAD)) * 60.0f) + obj->Pos.z;
        objIdx = func_80027464(1, &D_803331B0_unk_bin_20, posX, obj->Pos.y + 240.0f, posZ, obj->Rot.y);
        func_8001ABF4(objIdx, 0, 0, &D_80119FA4);
        gObjects[objIdx].unkC2 = gCurrentParsedObject;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 11;
        obj->unk132 = 0;
    }
}

void func_8033124C_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x12, 0xC8, &D_80119C80);
    }

    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 12;
        obj->unk132 = 0;
    }
}

void func_80331330_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x13, 0xC8, &D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unk8C);
    }

    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 13;
        obj->unk132 = 0;
    }
}

void func_80331434_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0x14, 0xC8, &D_80119C80);
    }

    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 14;
        obj->unk132 = 0;
    }
}

void func_80331518_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        obj->unk44 = 4.0f;

        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0xC8, &D_80119C80);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk70);
        func_8001ABF4(gCurrentParsedObject, 2, 0, &D_80119E0C.unk8C);
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unkFC);

        if (obj->unk100 < 7) {
            obj->unkA8 = 1;
        } else {
            obj->unkA8 = 2;
        }
    } else if (obj->unk132 == 2) {
        obj->unk132 = 1;
        obj->unk44 = 4.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0xB, 0xC8, &D_80119C80);
    }

    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->unk3C;
    func_80029C40(gCurrentParsedObject);

    if (func_80029018(gCurrentParsedObject, 0U, 120.0f, 0.0f, 0.0f, 0.0f)) {
        obj->unk44 = 0.0f;
        obj->Vel.z = 0.0f;
        obj->Vel.x = obj->Vel.z;
        obj->actionState = 5;
        obj->unk132 = 0;
        return;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 0xF;
        obj->unk132 = 0;
    }
}

void func_803317C4_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xC, 0xC8, &D_80119C80);
    }
    func_8002A8B4(gCurrentParsedObject, 3.0f);
    obj->Rot.y = obj->unk3C;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 120.0f, 0.0f, 0.0f, 0.0f)) {
        obj->unk44 = 0.0f;
        obj->Vel.z = 0.0f;
        obj->Vel.x = obj->Vel.z;
        obj->actionState = 5;
        obj->unk132 = 0;
        return;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        if (obj->unkA8 == 0) {
            obj->actionState = 5;
            obj->unk132 = 0;
            obj->Vel.z = 0.0f;
            obj->Vel.x = obj->Vel.z;
            obj->unk44 = 0.0f;
        } else if (func_8002A1FC(gCurrentParsedObject, 300.0f)) {
            obj->actionState = 5;
            obj->unk132 = 0;
            obj->Vel.z = 0.0f;
            obj->Vel.x = obj->Vel.z;
            obj->unk44 = 0.0f;
        } else {
            obj->actionState = 0xE;
            obj->unk132 = 2;
            obj->unkA8--;
        }
    }
}

void func_80331A40_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 objIdx;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;

        func_8001C0EC(gCurrentParsedObject, 0, 6, 0xC8, &D_80119C80);
        obj->unkD4 = (180.0f - obj->Rot.y) / 16.0f;
        objIdx = func_80027464(1, &D_803331EC_unk_bin_20, obj->Pos.x, obj->Pos.y, obj->Pos.z, obj->Rot.y);
        gObjects[objIdx].unkC2 = gCurrentParsedObject;
        func_800175F0(gCurrentParsedObject, 0, 0x71, -1, 0);
    }
    obj->Rot.y = func_80015538(obj->Rot.y, obj->unkD4);
    obj->unk3C = obj->Rot.y;
    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 0x11;
        obj->unk132 = 0;
        obj->Rot.y = 180.0f;
        obj->unk3C = 180.0f;
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unk118);
    }
}

void func_80331C44_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 7, 0xC8, &D_80119C80);
    }

    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 18;
        obj->unk132 = 0;
    }
}

void func_80331D28_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 8, 0xC8, &D_80119C80);
    }

    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 19;
        obj->unk132 = 0;
    }
}

void func_80331E0C_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 9, 0xC8, &D_80119C80);
    }

    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 20;
        obj->unk132 = 0;
    }
}

void func_80331EF0_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 objIdx;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0xA, 0xC8, &D_80119C80);
    }

    if (func_8001B62C(gCurrentParsedObject, 0) == 8.0f) {
        objIdx = func_80027464(1, &D_803331BC_unk_bin_20, obj->Pos.x, obj->Pos.y, obj->Pos.z, obj->Rot.y);

        objIdx = func_80027464(1, &D_803331D4_unk_bin_20, 0.0f, 120.0f, 0.0f, 0.0f);
        func_80026F10(gCurrentParsedObject, objIdx);

        objIdx = func_80027464(1, &D_803331D4_unk_bin_20, 0.0f, 120.0f, 0.0f, 90.0f);
        func_80026F10(gCurrentParsedObject, objIdx);

        objIdx = func_80027464(1, &D_803331D4_unk_bin_20, 0.0f, 120.0f, 0.0f, 180.0f);
        func_80026F10(gCurrentParsedObject, objIdx);

        objIdx = func_80027464(1, &D_803331D4_unk_bin_20, 0.0f, 120.0f, 0.0f, 270.0f);
        func_80026F10(gCurrentParsedObject, objIdx);
    } else if (func_8001B62C(gCurrentParsedObject, 0) == 16.0f) {
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80119E0C.unk70);
    } else if (func_8001B62C(gCurrentParsedObject, 0) == 40.0f) {
        func_8001ABF4(gCurrentParsedObject, 3, 0, &D_80119E0C.unkFC);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        obj->actionState = 1;
        obj->unk132 = 0;
    }
}

void func_803321E4_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        obj->unkA6 = 0x3C;

        func_80069E60(0, 1, 0x82);
    }

    if (obj->unkA6 == 0x1E) {
        obj->unkA6--;
        func_8007F070(obj->Pos.x, obj->Pos.y, obj->Pos.z, 5.0f);
    } else if (obj->unkA6 == 0) {
        func_8001BB34(gCurrentParsedObject, 1);

        if (obj->unk132 == 1) {
            func_800175F0(gCurrentParsedObject, 0, 0x67, -1, 0);
            obj->unk132++;
        }
    } else {
        obj->unkA6--;
    }
}

void func_80332378_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->damageState == 0) {
        func_8001BB34(gCurrentParsedObject, 0);

    } else {
        func_8001BB34(gCurrentParsedObject, !(obj->damageState % 2));
    }
    switch (obj->actionState) {
        case 1:
            func_8033020C_unk_bin_20();
            break;
        case 2:
            func_80330394_unk_bin_20();
            break;
        case 3:
            func_80330478_unk_bin_20();
            break;
        case 4:
            func_8033055C_unk_bin_20();
            break;
        case 5:
            func_80330764_unk_bin_20();
            break;
        case 6:
            func_803308F0_unk_bin_20();
            break;
        case 7:
            func_803309F8_unk_bin_20();
            break;
        case 8:
            func_80330B00_unk_bin_20();
            break;
        case 9:
            func_80330C08_unk_bin_20();
            break;
        case 10:
            func_80330D10_unk_bin_20();
            break;
        case 11:
            func_8033124C_unk_bin_20();
            break;
        case 12:
            func_80331330_unk_bin_20();
            break;
        case 13:
            func_80331434_unk_bin_20();
            break;
        case 14:
            func_80331518_unk_bin_20();
            break;
        case 15:
            func_803317C4_unk_bin_20();
            break;
        case 16:
            func_80331A40_unk_bin_20();
            break;
        case 17:
            func_80331C44_unk_bin_20();
            break;
        case 18:
            func_80331D28_unk_bin_20();
            break;
        case 19:
            func_80331E0C_unk_bin_20();
            break;
        case 20:
            func_80331EF0_unk_bin_20();
            break;
        case 21:
            func_803321E4_unk_bin_20();
            break;
        default:
            break;
    }
}

void func_803325B4_unk_bin_20() {
    func_8002B0E4(gCurrentParsedObject);
}

void func_803325E4_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (gObjects[obj->unkC2].actionState == 0xB) {
        if (obj->unk132 == 0) {
            obj->unk132++;
            obj->unk44 = 9.0f;
            obj->unk3C = obj->Rot.y;
            obj->unkA6 = 3;
        }

        if (obj->unkA6 == 0) {
            obj->actionState = 2;
            obj->unk132 = 0;
            obj->unk44 = 0.0f;
            obj->Vel.z = 0.0f;
            obj->Vel.x = obj->Vel.z;
        } else {
            func_80029C40(gCurrentParsedObject);
            obj->unk44 += 9.0f;
            obj->unkA6--;
        }
    }
}

void func_80332774_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unk44 = 30.0f;
        obj->unkA6 = 0xC;
        obj->Vel.y = -8.0f;
    }
    if (obj->unkA6 == 0) {
        obj->actionState = 3;
        obj->unk132 = 0;
        obj->unk44 = 0.0f;
        obj->Vel.x = obj->Vel.y = obj->Vel.z = 0.0f;
    } else {
        func_80029C40(gCurrentParsedObject);
        obj->unkA6--;
    }
    if (func_80029018(gCurrentParsedObject, 3, 30.0f, 0.0f, 0.0f, 0.0f)) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_80332908_unk_bin_20(void) {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unk44 = 30.0f;
        obj->unkA6 = 0xA;
        obj->Vel.y = -8.0f;
    }

    func_80029C40(gCurrentParsedObject);

    obj->unk44 -= 3.0f;
    obj->Vel.y -= 4.0f;

    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f)) {
        func_8002B0E4(gCurrentParsedObject);
    } else if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, -30.0f, 30.0f) == 1) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_80332A88_unk_bin_20(void) {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    switch (obj->actionState) {
        case 1:
            func_803325E4_unk_bin_20();
            break;
        case 2:
            func_80332774_unk_bin_20();
            break;
        case 3:
            func_80332908_unk_bin_20();
            break;
        default:
            break;
    }
}

void func_80332B48_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x154, &D_8011BCD8);
    }
    if (func_8001B4AC(gCurrentParsedObject, 3)) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_80332C24_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 sp20;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;

        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x153, &D_8011BCD0);
        obj->unkA6 = 4;
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        if (obj->unkA6 == 0) {
            sp20 = func_80027464(1, &D_803331E0_unk_bin_20, 0.0f, 120.0f, 0.0f, 0.0f);
            sp20 = func_80027464(1, &D_803331E0_unk_bin_20, 0.0f, 120.0f, 0.0f, 90.0f);
            sp20 = func_80027464(1, &D_803331E0_unk_bin_20, 0.0f, 120.0f, 0.0f, 180.0f);
            sp20 = func_80027464(1, &D_803331E0_unk_bin_20, 0.0f, 120.0f, 0.0f, 270.0f);
            func_8002B114(gCurrentParsedObject);
        } else {
            obj->unkA6 -= 1;
        }
    }
}

void func_80332E00_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;

        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x156, &D_8011BCD4);
    }
    if (func_8001B4AC(gCurrentParsedObject, 0) != 0) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_80332EDC_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 objIdx;

    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 3, 0, 0x155, &D_8011BCDC);
    }
    if (func_8001B62C(gCurrentParsedObject, 3) == 44.0f && gObjects[obj->unkC2].damageState) {
        objIdx = func_80027464(1, &D_803331C8_unk_bin_20, gObjects[obj->unkC2].Pos.x, gObjects[obj->unkC2].Pos.y,
                               gObjects[obj->unkC2].Pos.z, gObjects[obj->unkC2].Rot.y);
        gObjects[objIdx].unkC2 = obj->unkC2;
    }
    if (func_8001B4AC(gCurrentParsedObject, 3)) {
        func_8002B114(gCurrentParsedObject);
    }
}

void func_8033309C_unk_bin_20() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132 += 1;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1A2, &D_8011BCE0);
    }

    obj->Rot.y = gObjects[obj->unkC2].Rot.y;

    if (func_8001B4AC(gCurrentParsedObject, 0)) {
        func_8002B114(gCurrentParsedObject);
    }
}
