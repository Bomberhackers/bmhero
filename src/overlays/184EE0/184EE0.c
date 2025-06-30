#include "common.h"

void func_80330000_unk_bin_15(void);
void func_80330918_unk_bin_15(void);
void func_80330ABC_unk_bin_15(void);
void func_80330BD0_unk_bin_15(void);
void func_80330E40_unk_bin_15(void);
void func_80331260_unk_bin_15(void);
void func_80331708_unk_bin_15(void);
void func_80331E70_unk_bin_15(void);
void func_80332058_unk_bin_15(void);
void func_8033226C_unk_bin_15(void);
void func_803325F8_unk_bin_15(void);
void func_80332C94_unk_bin_15(void);
void func_803330D8_unk_bin_15(void);
void func_80333308_unk_bin_15(void);
void func_803339E8_unk_bin_15(s32 idx, s32 arg1, f32 arg2);
s32 func_80333AE4_unk_bin_15(s32 idx, s32 arg1, f32 arg2);
f32 func_80333BCC_unk_bin_15(s32 idx1, s32 idx2);
void func_80333C58_unk_bin_15(s32 idx, s32 arg1, f32 arg2);
s32 func_80333D54_unk_bin_15(s32 idx, s32 arg1, f32 arg2);
f32 func_80333E3C_unk_bin_15(s32 idx1, s32 idx2);
void func_80333ED4_unk_bin_15(void);
void func_80333FD8_unk_bin_15(void);
void func_80334054_unk_bin_15(void);
void func_80334430_unk_bin_15(void);
void func_80334510_unk_bin_15(void);
void func_80334540_unk_bin_15(void);

struct UnkStruct_80027C00 const D_80334930_unk_bin_15 = { 0, 0x145, 0x130, 2, 1, 1, 1, 0 };

struct UnkStruct_80027C00 const D_8033493C_unk_bin_15 = { 0, 0x146, 0x132, 1, 1, 1, 1, 0 };

struct UnkStruct_80027C00 const D_80334948_unk_bin_15[] = {
    { 0, 0x130, 0x111, 6, 5, 1, 1, 0 },    { 0, 0x131, 0x110, 2, -1, -1, -1, 1 }, { 0, 0x131, 0x110, 2, -1, -1, -1, 1 },
    { 0, 0x131, 0x110, 2, -1, -1, -1, 1 }, { 0, 0x131, 0x110, 2, -1, -1, -1, 1 }, { 0, 0x131, 0x110, 2, -1, -1, -1, 1 },
    { 0, 0x131, 0x110, 2, -1, -1, -1, 1 }, { 0, 0x131, 0x110, 2, -1, -1, -1, 1 }, { 0, 0x131, 0x110, 2, -1, -1, -1, 1 },
    { 0, 0x132, 0x112, 1, -1, -1, -1, 1 },
};

extern u32 D_8011AD44[];

void func_80330000_unk_bin_15() {
    s32 objIdx = func_80027464(10, D_80334948_unk_bin_15, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6,
                               D_80165100->unk8);
    s32 i;
    UNUSED s32 pad;

    func_80019448(objIdx, 1, 2, 0);

    for (i = 0; i < 9; i++) {
        func_80019448(gObjects[objIdx].unkE8[i], 1, 2, 0);
    }

    gObjects[gObjects[objIdx].unkE8[0]].Pos.x = 1320.0f;
    gObjects[gObjects[objIdx].unkE8[0]].Pos.y = 1320.0f;
    gObjects[gObjects[objIdx].unkE8[0]].Pos.z -= 80.0f;

    gObjects[gObjects[objIdx].unkE8[1]].Pos.x = 600.0f;
    gObjects[gObjects[objIdx].unkE8[1]].Pos.y = 720.0f;
    gObjects[gObjects[objIdx].unkE8[1]].Pos.z -= 250.0f;

    gObjects[gObjects[objIdx].unkE8[2]].Pos.x = 960.0f;
    gObjects[gObjects[objIdx].unkE8[2]].Pos.y = 720.0f;
    gObjects[gObjects[objIdx].unkE8[2]].Pos.z -= 420.0f;

    gObjects[gObjects[objIdx].unkE8[3]].Pos.x = 630.0f;
    gObjects[gObjects[objIdx].unkE8[3]].Pos.y = 1320.0f;
    gObjects[gObjects[objIdx].unkE8[3]].Pos.z -= 590.0f;

    gObjects[gObjects[objIdx].unkE8[4]].Pos.x = 1320.0f;
    gObjects[gObjects[objIdx].unkE8[4]].Pos.y = 600.0f;
    gObjects[gObjects[objIdx].unkE8[4]].Pos.z -= 760.0f;

    gObjects[gObjects[objIdx].unkE8[5]].Pos.x = 990.0f;
    gObjects[gObjects[objIdx].unkE8[5]].Pos.y = 1200.0f;
    gObjects[gObjects[objIdx].unkE8[5]].Pos.z -= 930.0f;

    gObjects[gObjects[objIdx].unkE8[6]].Pos.x = 600.0f;
    gObjects[gObjects[objIdx].unkE8[6]].Pos.y = 600.0f;
    gObjects[gObjects[objIdx].unkE8[6]].Pos.z -= 1100.0f;

    gObjects[gObjects[objIdx].unkE8[7]].Pos.x = 1200.0f;
    gObjects[gObjects[objIdx].unkE8[7]].Pos.y = 960.0f;
    gObjects[gObjects[objIdx].unkE8[7]].Pos.z -= 1270.0f;

    gObjects[gObjects[objIdx].unkE8[8]].Pos.z -= 1360.0f;

    gObjects[objIdx].damageState = -1;
    gObjects[objIdx].unkD4 = 1.0f;
}

void func_80330918_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;

    if (obj->objID == 0x130) {
        if (D_80177A64 == 0) {
            obj->damageState = 0;

            for (i = 0; i < 9; i++) {
                gObjects[obj->unkE8[i]].damageState = 0;
            }

            obj->actionState = 10;
            obj->unk132 = 0;
        } else if (D_80177A64 == 1) {
            obj->damageState = 60;

            for (i = 0; i < 9; i++) {
                gObjects[obj->unkE8[i]].damageState = 60;
            }

        } else if ((obj->Pos.z - gPlayerObject->Pos.z) <= -120.0f) {
            func_80069D04(1, 0);
        }
    }
}

void func_80330ABC_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
    }
    if (func_8002A2EC(gCurrentParsedObject, 2400.0f) != 0) {
        obj->actionState = 2;
        obj->unk132 = 0;
    } else if ((obj->Pos.z - gPlayerObject->Pos.z) > 5000.0f) {
        obj->damageState = 1;
        obj->actionState = 9;
        obj->unk132 = 0;
    }
}

void func_80330BD0_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x111, D_8011AD44);

        for (i = 0; i < 9; i++) {
            gObjects[obj->unkE8[i]].Vel.x = (960.0f - gObjects[obj->unkE8[i]].Pos.x) / 15.0f;
            gObjects[obj->unkE8[i]].Vel.y = (960.0f - gObjects[obj->unkE8[i]].Pos.y) / 15.0f;
        }

        obj->unkA6 = 15;
    }
    if (obj->unkA6 == 0) {
        for (i = 0; i < 9; i++) {
            gObjects[obj->unkE8[i]].Vel.x = 0.0f;
            gObjects[obj->unkE8[i]].Vel.y = 0.0f;
        }
        obj->actionState = 3;
        obj->unk132 = 0;
        obj->damageState = 1;
    } else {
        obj->unkA6--;
    }
}

void func_80330E40_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;
    f32 x;
    f32 y;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        obj->unk44 = 10.0f;

        for (i = 0; i < 9; i++) {
            gObjects[obj->unkE8[i]].unk44 = 10.0f;
        }

        obj->unk3C = 0.0f;
    }

    if (obj->unkA6 == 0) {
        if (func_8002A2EC(gCurrentParsedObject, 1200.0f)) {
            obj->unkA6++;
            func_8001C0EC(gCurrentParsedObject, 0, 1, 0x111, D_8011AD44);
        }
    } else if (obj->unkA6 == 1 && func_8001B4AC(gCurrentParsedObject, 0)) {
        func_8001BBDC(gCurrentParsedObject, 1);
    }

    if (obj->unk132 == 1) {
        if (func_8002A2EC(gCurrentParsedObject, 480.0f) != 0) {
            obj->unk132++;
        } else {
            func_800158B4(obj->Pos.x - gPlayerObject->Pos.x, obj->Pos.y - gPlayerObject->Pos.y - 50.0f,
                          obj->Pos.z - gPlayerObject->Pos.z, &x, &y);
            obj->unk40 = x;

            if ((obj->unk40 > 90.0f) && (obj->unk40 <= 180.0f)) {
                obj->unk40 = 180.0f - obj->unk40;
            } else {
                if ((obj->unk40 > 180.0f) && (obj->unk40 < 270.0f)) {
                    obj->unk40 = 540.0f - obj->unk40;
                }
            }

            obj->Rot.x = 360.0f - obj->unk40;

            if (obj->Rot.x >= 360.0f) {
                obj->Rot.x -= 360.0f;
            }

            func_8002A8B4(gCurrentParsedObject, obj->unkD4);
            obj->Rot.y = obj->unk3C;
        }
    } else {
        obj->actionState = 4;
        obj->unk132 = 0;
    }

    func_80333308_unk_bin_15();
    func_80029D8C(gCurrentParsedObject);

    for (i = 0; i < 9; i++) {
        func_80029D8C(obj->unkE8[i]);
    }
}

void func_80331260_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;
    f32 x;
    f32 y;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
    }

    if (obj->Pos.z - gPlayerObject->Pos.z > 1800.0f) {
        obj->unk44 = 10.0f;

        for (i = 0; i < 9; i++) {
            gObjects[obj->unkE8[i]].unk44 = 10.0f;
        }

        obj->unkA6 = 0;
        obj->actionState = 5;
        obj->unk132 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
    } else if (obj->Pos.z - gPlayerObject->Pos.z > 0.0f) {
        obj->unk3C = 0.0f;
        obj->unk40 = 0.0f;
        obj->Rot.y = 0.0f;
        obj->Rot.x = 0.0f;
        obj->unk44 = 20.0f;

        for (i = 0; i < 9; i++) {
            gObjects[obj->unkE8[i]].unk44 = 20.0f;
        }
    } else {
        func_800158B4(obj->Pos.x - gPlayerObject->Pos.x, obj->Pos.y - gPlayerObject->Pos.y - 50.0f,
                      obj->Pos.z - gPlayerObject->Pos.z, &x, &y);
        obj->unk40 = x;

        if ((obj->unk40 > 90.0f) && (obj->unk40 <= 180.0f)) {
            obj->unk40 = 180.0f - obj->unk40;
        } else {
            if ((obj->unk40 > 180.0f) && (obj->unk40 < 270.0f)) {
                obj->unk40 = 540.0f - obj->unk40;
            }
        }

        obj->Rot.x = 360.0f - obj->unk40;

        if (obj->Rot.x >= 360.0f) {
            obj->Rot.x -= 360.0f;
        }

        func_8002A8B4(gCurrentParsedObject, obj->unkD4);
        obj->Rot.y = obj->unk3C;
        obj->unk44 = 10.0f;

        for (i = 0; i < 9; i++) {
            gObjects[obj->unkE8[i]].unk44 = 10.0f;
        }
    }

    func_80333308_unk_bin_15();
    func_80029D8C(gCurrentParsedObject);

    for (i = 0; i < 9; i++) {
        func_80029D8C(obj->unkE8[i]);
    }
}

void func_80331708_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;
    UNUSED s32 pad[2];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x111, D_8011AD44);

        obj->Pos.x = 960.0f;
        obj->Pos.y = 420.0f;
        obj->Pos.z = gPlayerObject->Pos.z + 2000.0f;
        obj->Rot.y = 0.0f;
        obj->unk3C = obj->Rot.y;
        obj->unk40 = obj->Rot.x = obj->Rot.z = 0.0f;
        obj->unk44 = 40.0f;
        obj->unkB6 = 0;

        for (i = 0; i < 9; i++) {
            gObjects[obj->unkE8[i]].Pos.x = obj->Pos.x;
            gObjects[obj->unkE8[i]].Pos.y = obj->Pos.y;
            gObjects[obj->unkE8[i]].Pos.z = obj->Pos.z;

            gObjects[obj->unkE8[i]].Rot.x = obj->Rot.x;
            gObjects[obj->unkE8[i]].Rot.y = obj->Rot.y;
            gObjects[obj->unkE8[i]].Rot.z = obj->Rot.z;

            gObjects[obj->unkE8[i]].unk3C = obj->unk3C;
            gObjects[obj->unkE8[i]].unk44 = obj->unk44;
            gObjects[obj->unkE8[i]].unk40 = obj->unk40;
        }

        gObjects[obj->unkE8[0]].Pos.z -= 80.0f;
        gObjects[obj->unkE8[1]].Pos.z -= 250.0f;
        gObjects[obj->unkE8[2]].Pos.z -= 420.0f;
        gObjects[obj->unkE8[3]].Pos.z -= 590.0f;
        gObjects[obj->unkE8[4]].Pos.z -= 760.0f;
        gObjects[obj->unkE8[5]].Pos.z -= 930.0f;
        gObjects[obj->unkE8[6]].Pos.z -= 1100.0f;
        gObjects[obj->unkE8[7]].Pos.z -= 1270.0f;
        gObjects[obj->unkE8[8]].Pos.z -= 1360.0f;
    }

    obj->unk40 = func_80015538(obj->unk40, 4.0f);

    if (obj->unk40 >= 180.0f) {
        obj->unk40 = 180.0f;
    }
    obj->Rot.x = 360.0f - obj->unk40;

    if (obj->Rot.x >= 360.0f) {
        obj->Rot.x -= 360.0f;
    }
    obj->Rot.z = obj->unk40;

    func_80333308_unk_bin_15();
    func_80029D8C(gCurrentParsedObject);

    for (i = 0; i < 9; i++) {
        func_80029D8C(obj->unkE8[i]);
    }

    if (obj->unk40 == 180.0f) {
        obj->actionState = 6;
        obj->unk132 = 0;
    }
    if (gPlayerObject->Pos.z < -7000.0f) {
        obj->actionState = 9;
        obj->unk132 = 0;
    }
}

void func_80331E70_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;
    UNUSED s32 pad;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        obj->unk44 = 40.0f;

        for (i = 0; i < 9; i++) {
            gObjects[obj->unkE8[i]].unk44 = obj->unk44;
        }
    }
    func_80333308_unk_bin_15();
    func_80029D8C(gCurrentParsedObject);

    for (i = 0; i < 9; i++) {
        func_80029D8C(obj->unkE8[i]);
    }

    gObjects[obj->unkE8[8]].Rot.x = func_80015538(gObjects[obj->unkE8[8]].Rot.x, 180.0f);

    if (func_8002A2EC(gCurrentParsedObject, 3600.0f)) {

    } else {
        obj->actionState = 7;
        obj->unk132 = 0;
    }
}

void func_80332058_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;
    UNUSED s32 pad;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
    }

    obj->unk40 = func_80015538(obj->unk40, 4.0f);
    obj->Rot.x = 360.0f - obj->unk40;

    if (obj->Rot.x >= 360.0f) {
        obj->Rot.x -= 360.0f;
    }
    obj->Rot.z = obj->unk40;

    func_80333308_unk_bin_15();
    func_80029D8C(gCurrentParsedObject);

    for (i = 0; i < 9; i++) {
        func_80029D8C(obj->unkE8[i]);
    }

    gObjects[obj->unkE8[8]].Rot.x = func_80015538(gObjects[obj->unkE8[8]].Rot.x, 180.0f);

    if (obj->unk40 == 0.0f) {
        obj->actionState = 8;
        obj->unk132 = 0;
    }
}

void func_8033226C_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;
    UNUSED s32 pad;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        obj->unk44 = 40.0f;

        for (i = 0; i < 9; i++) {
            gObjects[obj->unkE8[i]].unk44 = obj->unk44;
        }
    }
    func_80333308_unk_bin_15();
    func_80029D8C(gCurrentParsedObject);

    for (i = 0; i < 9; i++) {
        func_80029D8C(obj->unkE8[i]);
    }

    if (func_8002A2EC(gCurrentParsedObject, 1200.0f)) {
        obj->actionState = 3;
        obj->unk132 = 0;
        obj->unkD4 += 1.0f;

        gObjects[obj->unkE8[0]].Pos.z = obj->Pos.z - 80.0f;
        gObjects[obj->unkE8[1]].Pos.z = obj->Pos.z - 250.0f;
        gObjects[obj->unkE8[2]].Pos.z = obj->Pos.z - 420.0f;
        gObjects[obj->unkE8[3]].Pos.z = obj->Pos.z - 590.0f;
        gObjects[obj->unkE8[4]].Pos.z = obj->Pos.z - 760.0f;
        gObjects[obj->unkE8[5]].Pos.z = obj->Pos.z - 930.0f;
        gObjects[obj->unkE8[6]].Pos.z = obj->Pos.z - 1100.0f;
        gObjects[obj->unkE8[7]].Pos.z = obj->Pos.z - 1270.0f;
        gObjects[obj->unkE8[8]].Pos.z = obj->Pos.z - 1360.0f;
    }
}

void func_803325F8_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;
    UNUSED s32 pad[2];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;
        func_8001C0EC(gCurrentParsedObject, 0, 2, 0x111, D_8011AD44);
    }

    func_8001BB34(gCurrentParsedObject, 1);

    for (i = 0; i < 9; i++) {
        func_8001BB34(obj->unkE8[i], 1);
    }

    obj->Pos.x = 960.0f;
    obj->Pos.y = 420.0f;
    obj->Pos.z = gPlayerObject->Pos.z + 2000.0f;
    obj->Rot.y = 0.0f;
    obj->unk3C = obj->Rot.y;
    obj->unk40 = obj->Rot.x = obj->Rot.z = 0.0f;
    obj->unk44 = 0.0f;
    obj->unkB6 = 0;

    for (i = 0; i < 9; i++) {
        gObjects[obj->unkE8[i]].Pos.x = obj->Pos.x;
        gObjects[obj->unkE8[i]].Pos.y = obj->Pos.y;
        gObjects[obj->unkE8[i]].Pos.z = obj->Pos.z;

        gObjects[obj->unkE8[i]].Rot.x = obj->Rot.x;
        gObjects[obj->unkE8[i]].Rot.y = obj->Rot.y;
        gObjects[obj->unkE8[i]].Rot.z = obj->Rot.z;

        gObjects[obj->unkE8[i]].unk3C = obj->unk3C;
        gObjects[obj->unkE8[i]].unk44 = obj->unk44;
        gObjects[obj->unkE8[i]].unk40 = obj->unk40;
    }

    gObjects[obj->unkE8[0]].Pos.z -= 80.0f;
    gObjects[obj->unkE8[1]].Pos.z -= 250.0f;
    gObjects[obj->unkE8[2]].Pos.z -= 420.0f;
    gObjects[obj->unkE8[3]].Pos.z -= 590.0f;
    gObjects[obj->unkE8[4]].Pos.z -= 760.0f;
    gObjects[obj->unkE8[5]].Pos.z -= 930.0f;
    gObjects[obj->unkE8[6]].Pos.z -= 1100.0f;
    gObjects[obj->unkE8[7]].Pos.z -= 1270.0f;
    gObjects[obj->unkE8[8]].Pos.z -= 1360.0f;

    if (gPlayerObject->Pos.z > -7000.0f) {
        func_8001BB34(gCurrentParsedObject, 0);

        for (i = 0; i < 9; i++) {
            func_8001BB34(obj->unkE8[i], 0);
        }

        obj->actionState = 5;
        obj->unk132 = 0;
    }
}
void func_80332C94_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;
    s32 sp24;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->actionState;

        obj->unkC2 = 0x3C;
        obj->unk44 = 0.0f;
        obj->unk3C = 0.0f;
        obj->unk40 = 0.0f;

        for (i = 0; i < 9; i++) {
            gObjects[obj->unkE8[i]].unk30.x = Math_Random(0x12);
            gObjects[obj->unkE8[i]].unk30.y = Math_Random(0x12);

            gObjects[obj->unkE8[i]].unk3C = Math_Random(0x167);
            gObjects[obj->unkE8[i]].unk44 = Math_Random(0x1E);
            gObjects[obj->unkE8[i]].unk40 = Math_Random(0x167);
        }

        func_80029D8C(gCurrentParsedObject);

        for (i = 0; i < 9; i++) {
            func_80029D8C(obj->unkE8[i]);
        }
    }

    for (i = 0; i < 9; i++) {
        if (obj->unkE8[i] != -1) {
            if (func_80028FA0(obj->unkE8[i])) {
                func_80029B60(obj->unkE8[i]);
            }
        }
    }

    for (i = 0; i < 9; i++) {
        if (obj->unkE8[i] != -1) {
            if (func_80029018(obj->unkE8[i], 3, 60.0f, 0.0f, 0.0f, 0.0f)) {
                sp24 = func_800281A4(gCurrentParsedObject, i);
                func_8002B0E4(sp24);
            }
        }
    }

    if (obj->unkC2 == 0) {
        for (i = 0; i < 9; i++) {
            if (obj->unkE8[i] != -1) {
                sp24 = func_800281A4(gCurrentParsedObject, i);
                func_8002B0E4(sp24);
            }
        }

        func_8002B0E4(gCurrentParsedObject);
    } else {
        obj->unkC2--;
    }
}

void func_803330D8_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;

    if (obj->damageState == 0) {
        func_8001BB34(gCurrentParsedObject, 0);
        for (i = 0; i < 9; i++) {
            func_8001BB34(obj->unkE8[i], 0);
        }
    } else if (obj->damageState == -1) {

    } else {
        func_8001BB34(gCurrentParsedObject, !(obj->damageState % 2));

        for (i = 0; i < 9; i++) {
            func_8001BB34(obj->unkE8[i], !(obj->damageState % 2));
        }
    }
    switch (obj->actionState) {
        case 1:
            func_80330ABC_unk_bin_15();
            break;
        case 2:
            func_80330BD0_unk_bin_15();
            break;
        case 3:
            func_80330E40_unk_bin_15();
            break;
        case 4:
            func_80331260_unk_bin_15();
            break;
        case 5:
            func_80331708_unk_bin_15();
            break;
        case 6:
            func_80331E70_unk_bin_15();
            break;
        case 7:
            func_80332058_unk_bin_15();
            break;
        case 8:
            func_8033226C_unk_bin_15();
            break;
        case 9:
            func_803325F8_unk_bin_15();
            break;
        case 10:
            func_80332C94_unk_bin_15();
            break;
        default:
            break;
    }
}

void func_80333308_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 i;
    f32 x;
    f32 y;

    func_800158B4(gObjects[obj->unkE8[0]].Pos.x - obj->Pos.x, gObjects[obj->unkE8[0]].Pos.y - obj->Pos.y,
                  gObjects[obj->unkE8[0]].Pos.z - obj->Pos.z, &x, &y);
    gObjects[obj->unkE8[0]].unk40 = x;

    if (gObjects[obj->unkE8[0]].unk40 > 90.0f && gObjects[obj->unkE8[0]].unk40 <= 180.0f) {
        gObjects[obj->unkE8[0]].unk40 = 180.0f - gObjects[obj->unkE8[0]].unk40;
    } else {
        if ((gObjects[obj->unkE8[0]].unk40 > 180.0f) && (gObjects[obj->unkE8[0]].unk40 < 270.0f)) {
            gObjects[obj->unkE8[0]].unk40 = 540.0f - gObjects[obj->unkE8[0]].unk40;
        }
    }

    gObjects[obj->unkE8[0]].Rot.x = 360.0f - gObjects[obj->unkE8[0]].unk40;

    if (gObjects[obj->unkE8[0]].Rot.x >= 360.0f) {
        gObjects[obj->unkE8[0]].Rot.x -= 360.0f;
    }

    for (i = 1; i < 9; i++) {
        func_800158B4(gObjects[obj->unkE8[i]].Pos.x - gObjects[obj->unkE6[i]].Pos.x,
                      gObjects[obj->unkE8[i]].Pos.y - gObjects[obj->unkE6[i]].Pos.y,
                      gObjects[obj->unkE8[i]].Pos.z - gObjects[obj->unkE6[i]].Pos.z, &x, &y);

        gObjects[obj->unkE8[i]].unk40 = x;

        if (gObjects[obj->unkE8[i]].unk40 > 90.0f && gObjects[obj->unkE8[i]].unk40 <= 180.0f) {
            gObjects[obj->unkE8[i]].unk40 = 180.0f - gObjects[obj->unkE8[i]].unk40;
        } else {
            if (gObjects[obj->unkE8[i]].unk40 > 180.0f && gObjects[obj->unkE8[i]].unk40 < 270.0f) {
                gObjects[obj->unkE8[i]].unk40 = 540.0f - gObjects[obj->unkE8[i]].unk40;
            }
        }

        gObjects[obj->unkE8[i]].Rot.x = 360.0f - gObjects[obj->unkE8[i]].unk40;

        if (gObjects[obj->unkE8[i]].Rot.x >= 360.0f) {
            gObjects[obj->unkE8[i]].Rot.x -= 360.0f;
        }
    }

    gObjects[obj->unkE8[0]].unk3C = func_80333BCC_unk_bin_15(obj->unkE8[0], gCurrentParsedObject);

    for (i = 1; i < 9; i++) {
        gObjects[obj->unkE8[i]].unk3C = func_80333BCC_unk_bin_15(obj->unkE8[i], obj->unkE6[i]);
    }
}

void func_803339E8_unk_bin_15(s32 idx, s32 arg1, f32 arg2) {
    f32 unk3C;
    s32 sp18;

    unk3C = gObjects[idx].unk3C;
    sp18 = func_80333AE4_unk_bin_15(idx, arg1, arg2);

    if (sp18 < 0) {
        unk3C = func_80015538(unk3C, -arg2);
    } else if (sp18 > 0) {
        unk3C = func_80015538(unk3C, arg2);
    } else {
        unk3C = func_80333BCC_unk_bin_15(idx, arg1);
    }

    gObjects[idx].unk3C = unk3C;
}

s32 func_80333AE4_unk_bin_15(s32 idx, s32 arg1, f32 arg2) {
    f32 sp1C;
    f32 sp18;

    sp1C = func_80333BCC_unk_bin_15(idx, arg1);
    sp18 = func_80015538(sp1C, -gObjects[idx].unk3C);

    if (sp18 < arg2 || 360.0f - arg2 < sp18) {
        return 0;
    }

    if (sp18 >= 180.0f) {
        return -1;
    }
    return 1;
}

f32 func_80333BCC_unk_bin_15(s32 idx1, s32 idx2) {
    return func_80015634(gObjects[idx2].Pos.x - gObjects[idx1].Pos.x, gObjects[idx2].Pos.z - gObjects[idx1].Pos.z);
}

void func_80333C58_unk_bin_15(s32 idx, s32 arg1, f32 arg2) {
    f32 unk40;
    s32 sp18;

    unk40 = gObjects[idx].unk40;
    sp18 = func_80333D54_unk_bin_15(idx, arg1, arg2);

    if (sp18 < 0) {
        unk40 = func_80015538(unk40, -arg2);
    } else if (sp18 > 0) {
        unk40 = func_80015538(unk40, arg2);
    } else {
        unk40 = func_80333E3C_unk_bin_15(idx, arg1);
    }

    gObjects[idx].unk40 = unk40;
}

s32 func_80333D54_unk_bin_15(s32 idx, s32 arg1, f32 arg2) {
    f32 sp1C;
    f32 sp18;

    sp1C = func_80333E3C_unk_bin_15(idx, arg1);
    sp18 = func_80015538(sp1C, -gObjects[idx].unk40);

    if (sp18 < arg2 || 360.0f - arg2 < sp18) {
        return 0;
    }

    if (sp18 >= 180.0f) {
        return -1;
    }
    return 1;
}

f32 func_80333E3C_unk_bin_15(s32 idx1, s32 idx2) {
    return Math_CalcAngleSimple(gObjects[idx2].Pos.x - gObjects[idx1].Pos.x,
                         gObjects[idx2].Pos.y + 60.0f - gObjects[idx1].Pos.y);
}

void func_80333ED4_unk_bin_15() {
    s32 objIdx = func_80027464(1, &D_80334930_unk_bin_15, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6,
                               D_80165100->unk8);
    UNUSED s32 pad[2];

    if (objIdx != -1) {
        if (D_80165100->unkA == 1) {
            gObjects[objIdx].Rot.z = 180.0f;
        }
        gObjects[objIdx].unkC2 = D_80165100->unkA;
    }
}

void func_80333FD8_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (D_80177A64 == 0) {
        obj->damageState = 0;
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_80334054_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s32 objIdx;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 rotBase;

    if (obj->Pos.z - gPlayerObject->Pos.z < 100.0f) {
        if (obj->unk132 == 0) {
            if (gPlayerObject->Pos.z - obj->Pos.z < 1500.0f) {
                if (obj->unkC2 == 0) {
                    posY = obj->Pos.y + 100.0f;
                } else {
                    posY = obj->Pos.y - 100.0f;
                }

                rotBase = func_80015538(obj->Rot.y, 20.0f);

                posX = sinf((f32) ((f64) rotBase * DEG_TO_RAD)) * 200.0f + obj->Pos.x;
                posZ = cosf((f32) ((f64) rotBase * DEG_TO_RAD)) * 200.0f + obj->Pos.z;

                objIdx = func_80027464(1, &D_8033493C_unk_bin_15, posX, posY, posZ, 0.0f);

                if (objIdx != -1) {
                    func_80019448(objIdx, 2, 0, 1);
                    gObjects[objIdx].unkC2 = gCurrentParsedObject;
                    func_80026F10(gCurrentParsedObject, objIdx);
                }

                rotBase = func_80015538(obj->Rot.y, -20.0f);

                posX = sinf((f32) ((f64) rotBase * DEG_TO_RAD)) * 200.0f + obj->Pos.x;
                posZ = cosf((f32) ((f64) rotBase * DEG_TO_RAD)) * 200.0f + obj->Pos.z;

                objIdx = func_80027464(1, &D_8033493C_unk_bin_15, posX, posY, posZ, 0.0f);

                if (objIdx != -1) {
                    func_80019448(objIdx, 2, 0, 1);
                    gObjects[objIdx].unkC2 = gCurrentParsedObject;
                    func_80026F10(gCurrentParsedObject, objIdx);
                }

                func_800175F0(gCurrentParsedObject, 0, 0x42, -1, 0);
                obj->unk132 = 0x5A;
            }
        } else {
            func_8002A8B4(gCurrentParsedObject, 3.0f);
            obj->Rot.y = obj->unk3C;
            obj->unk132--;
        }
    }
}

void func_80334430_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->damageState == 0) {
        func_8001BB34(gCurrentParsedObject, 0);
    } else {
        func_8001BB34(gCurrentParsedObject, !(obj->damageState % 2));
    }
    if (obj->actionState == 1) {
        if (0) {}
        func_80334054_unk_bin_15();

    } else if (1) {

    } else {
    }
}

void func_80334510_unk_bin_15() {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80334540_unk_bin_15() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unk44 = 20.0f;
        obj->Rot.y = gObjects[obj->unkC2].Rot.y;
        obj->unk3C = obj->Rot.y;
        obj->unkA6 = 0x14;
        obj->unkA8 = 0x3C;
    }
    if (obj->unkA6 >= 0xB) {
        sp30 = Math_CalcAngleSimple(gPlayerObject->Pos.x - obj->Pos.x, gPlayerObject->Pos.y - obj->Pos.y);
        sp30 = Math_NormalizeAngle(sp30);

        sp2C = func_8002A800(obj->unk40, sp30, 2.0f);
        if (sp2C != 0.0f) {
            obj->unk40 = func_80015538(obj->unk40, 2.0f * sp2C);
        }

        obj->Rot.y = obj->unk3C;
        obj->Rot.x = 360.0f - obj->unk40;

        if (obj->Rot.x >= 360.0f) {
            obj->Rot.x -= 360.0f;
        }

        func_8002A8B4(gCurrentParsedObject, 3.0f);

        obj->Rot.y = obj->unk3C;
        obj->unkA6--;
    } else {
        obj->unkA6--;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, -30.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (func_800295C0(gCurrentParsedObject, &sp24, &sp28, 0.0f, 30.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }

    func_80029D8C(gCurrentParsedObject);

    if (func_80029018(gCurrentParsedObject, 1, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    }
    if (obj->unkA8 == 0) {
        func_8002B0E4(gCurrentParsedObject);
        return;
    } else if (1) {
        obj->unkA8--;
    }
}
