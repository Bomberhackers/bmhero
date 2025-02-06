#include "common.h"

extern struct UnkStruct_80027C00 D_8011457C;
extern struct UnkStruct_80027C00 D_80114588;
extern struct UnkStruct_80027C00 D_80114594;

u8 func_80330000_unk_bin_36(f32 arg0, f32 arg1, f32 arg2);
void func_80330090_unk_bin_36(void);
void func_80330130_unk_bin_36(void);
void func_803301C4_unk_bin_36(void);
void func_803302E4_unk_bin_36(void);
void func_8033069C_unk_bin_36(void);
void func_80330800_unk_bin_36(void);
void func_803308C0_unk_bin_36(void);
void func_80330960_unk_bin_36(void);
void func_803309D0_unk_bin_36(void);
void func_80330AF0_unk_bin_36(void);
void func_80330E10_unk_bin_36(void);
void func_80330F74_unk_bin_36(void);
void func_80331034_unk_bin_36(void);
void func_803310AC_unk_bin_36(void);
void func_80331124_unk_bin_36(void);
void func_80331470_unk_bin_36(void);
void func_803314A0_unk_bin_36(void);

u8 func_80330000_unk_bin_36(f32 arg0, f32 arg1, f32 arg2) {
    UNUSED struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    func_80067748(arg0, arg1, arg2);

    return D_80177740[D_801776E0 & 1];
}

void func_80330090_unk_bin_36() {
    s32 objIdx;

    objIdx = func_80027464(1, &D_8011457C, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);

    if (objIdx != -1) {
        func_80019448(objIdx, 2, 0, 1);
    }
} 

void func_80330130_unk_bin_36() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    func_800175F0(obj->unkE8[1], 0, 0x29, -1, 0);
    func_8007EDF4(obj->Pos.x, obj->Pos.y, obj->Pos.z, 1.0f);
    func_8002B114(gCurrentParsedObject);
}

void func_803301C4_unk_bin_36() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    f32 y1, y2;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->unkA4;
    }

    if (func_800295C0(gCurrentParsedObject, &y1, &y2, 0, 0.0f, 0.0f)) {
        obj->Pos.y = y2;
    } else {
        obj->Pos.y = y1;
    }
    if (gPlayerObject->Pos.z < obj->Pos.z) {
        obj->unkA4 = 2;
        obj->unk132 = 0;
    }
}

void func_803302E4_unk_bin_36() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    f32 ySave;
    f32 y1, y2;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->unkA4;
        func_80029EF8(gCurrentParsedObject, 0, 1.0f);
        obj->unk44 = 8.0f;
        obj->unkA6 = 0x96;
    }

    if (func_80028FA0(gCurrentParsedObject)) {
        func_80029B60(gCurrentParsedObject);
    }

    if (gPlayerObject->Pos.z > (obj->Pos.z + 300.0f)) {
        func_800175F0(obj->unkE8[1], 0, 0x29, -1, 0);
        func_8007EDF4(obj->Pos.x, obj->Pos.y, obj->Pos.z, 1.0f);
        func_8002B114(gCurrentParsedObject);

        return;
    } else {
        func_8002A8B4(gCurrentParsedObject, 1.0f);
        obj->Rot.y = obj->unk3C;
    }

    if (obj->unk44 > 26.0f) {
        obj->unk44 = 26.0f;
    } else {
        obj->unk44 += 1.0f;
    }

    ySave = obj->Vel.y;
    func_80029C40(gCurrentParsedObject);
    func_80029018(gCurrentParsedObject, 3, 60.0f, 0, 0.0f, 0.0f);
    obj->Vel.y = ySave;

    if (func_8002A0D0(gCurrentParsedObject, 0, 0, 0) == 1) {
        if (D_80177740[D_801776E0 & 1] == 0xF5) {
            obj->Vel.y = ySave;
            obj->unkA4 = 3;
            obj->unk132 = 0;
            return;
        } else {
            if (func_800295C0(gCurrentParsedObject, &y1, &y2, 0, 0.0f, 0.0f)) {
                obj->Pos.y = y2;
            } else {
                obj->Pos.y = y1;
            }
            func_80029EF8(gCurrentParsedObject, 0, 1.0f);
        }
    }

    if (obj->unkA6 == 0) {
        func_800175F0(obj->unkE8[1], 0, 0x29, -1, 0);
        func_8007EDF4(obj->Pos.x, obj->Pos.y, obj->Pos.z, 1.0f);
        func_8002B114(gCurrentParsedObject);

        return;
    } else {
        obj->unkA6--;
    }
}

void func_8033069C_unk_bin_36() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    UNUSED s32 pad[2];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->unkA4;
        obj->unkB0 = 0x3C;
    }

    func_80029C40(gCurrentParsedObject);

    obj->Vel.y -= 1.0f;
    func_80067748(obj->Pos.x, obj->Pos.y, obj->Pos.z);

    if (D_80177740[D_801776E0 & 1] == 0xF5) {
        func_8001BB04(gCurrentParsedObject, 1);
    }

    if (obj->unkB0 == 0) {
        func_8002B114(gCurrentParsedObject);
    } else {
        obj->unkB0--;
    }
}

void func_80330800_unk_bin_36() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    UNUSED s32 pad;

    switch (obj->unkA4) {
        case 1:
            func_803301C4_unk_bin_36();
            break;
        case 2:
            func_803302E4_unk_bin_36();
            break;
        case 3:
            func_8033069C_unk_bin_36();
            break;
        default:
            break;
    }
}

void func_803308C0_unk_bin_36() {
    s32 objIdx;

    objIdx = func_80027464(1, &D_80114588, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);

    if (objIdx != -1) {
        func_80019448(objIdx, 2, 0, 1);
    }
}

void func_80330960_unk_bin_36() {
    UNUSED struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (D_80177A64 == 0) {
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_803309D0_unk_bin_36() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    f32 y1, y2;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->unkA4;
    }

    if (func_800295C0(gCurrentParsedObject, &y1, &y2, 0, 0.0f, 0.0f)) {
        obj->Pos.y = y2;
    } else {
        obj->Pos.y = y1;
    }
    if (gPlayerObject->Pos.z < obj->Pos.z) {
        obj->unkA4 = 2;
        obj->unk132 = 0;
    }
}

void func_80330AF0_unk_bin_36() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    f32 ySave;
    f32 y1, y2;

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->unkA4;
        func_80029EF8(gCurrentParsedObject, 0, 1.0f);
        obj->unk44 = 8.0f;
    }

    if (func_80028FA0(gCurrentParsedObject)) {
        func_80029B60(gCurrentParsedObject);
    }

    if (obj->Pos.z - gPlayerObject->Pos.z > 600.0f) {
        obj->Vel.z = 0.0f;
        obj->Vel.x = obj->Vel.y = obj->Vel.z;
        obj->unk44 = 0.0f;

        return;
    }

    func_8002A8B4(gCurrentParsedObject, 1.0f);
    obj->Rot.y = obj->unk3C;

    if (obj->unk44 > 26.0f) {
        obj->unk44 = 26.0f;
    } else {
        obj->unk44 += 1.0f;
    }

    ySave = obj->Vel.y;
    func_80029C40(gCurrentParsedObject);
    func_80029018(gCurrentParsedObject, 3, 60.0f, 0, 0.0f, 0.0f);
    obj->Vel.y = ySave;

    if (func_8002A0D0(gCurrentParsedObject, 0, 0, 0) == 1) {
        if (D_80177740[D_801776E0 & 1] == 0xF5) {
            obj->Vel.y = ySave;
            obj->unkA4 = 3;
            obj->unk132 = 0;

            return;
        } else {
            if (func_800295C0(gCurrentParsedObject, &y1, &y2, 0, 0.0f, 0.0f)) {
                obj->Pos.y = y2;
            } else {
                obj->Pos.y = y1;
            }
            func_80029EF8(gCurrentParsedObject, 0, 1.0f);
        }
    }
}

void func_80330E10_unk_bin_36() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    UNUSED s32 pad[2];

    if (obj->unk132 == 0) {
        obj->unk132++;
        obj->unkB2 = obj->unkA4;
        obj->unkB0 = 0x3C;
    }

    func_80029C40(gCurrentParsedObject);

    obj->Vel.y -= 1.0f;
    func_80067748(obj->Pos.x, obj->Pos.y, obj->Pos.z);

    if (D_80177740[D_801776E0 & 1] == 0xF5) {
        func_8001BB04(gCurrentParsedObject, 1);
    }

    if (obj->unkB0 == 0) {
        func_8002B114(gCurrentParsedObject);
    } else {
        obj->unkB0--;
    }
}

void func_80330F74_unk_bin_36() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    switch (obj->unkA4) {
        case 1:
            func_803309D0_unk_bin_36();
            break;
        case 2:
            func_80330AF0_unk_bin_36();
            break;
        case 3:
            func_80330E10_unk_bin_36();
            break;
        default:
            break;
    }
}

void func_80331034_unk_bin_36() {
    func_80027464(1, &D_80114594, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);
}

void func_803310AC_unk_bin_36() {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_80331124_unk_bin_36(void) {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    f32 y1, y2;

    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = 0;
        obj->unkA8 *= 0x64;
        obj->unkB6 = obj->Pos.y;
        obj->unk3C = (func_80014E80(0xA) & 1) * 0xB4 + 0x5A;
        obj->unk44 = 4.0f;
        obj->unk40 = 90.0f;
        obj->unk48 = 30.0f;
        func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118BA4.unk0);
        func_8001ABF4(gCurrentParsedObject, 1, 0, &D_80118BA4.unk1C);
    }
    func_80029C40(gCurrentParsedObject);

    obj->unkA6 = func_80015538(obj->unkA6, 10.0f);
    func_800294F0(gCurrentParsedObject, &y1, &y2, 0, 0.0f, 0.0f);

    obj->unk48 = (sinf(obj->unkA6 * 0.0174532925199432955) * 30.0f) + obj->unkB6 - obj->Pos.y;

    func_80029D04(gCurrentParsedObject);

    if (func_80029018(gCurrentParsedObject, 1, 300.0f, 0, 0.0f, 0.0f) != 0) {
        obj->unkA8 = 0;
    }
    if (obj->unkA8 == 0) {
        if (obj->unk3C == 90.0f) {
            obj->unk3C = 270.0f;
        } else {
            obj->unk3C = 90.0f;
        }

        obj->unkA8 = (func_80014E80(0xA) & 1) + 1;
        obj->unkA8 = obj->unkA8 * 0x64;
    }
}

void func_80331470_unk_bin_36() {
    func_8002B0E4(gCurrentParsedObject);
}

void func_803314A0_unk_bin_36() {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1:
            func_80331124_unk_bin_36();
            break;
        case 2:
            func_80331470_unk_bin_36();
            break;
        default:
            break;
    }
}
