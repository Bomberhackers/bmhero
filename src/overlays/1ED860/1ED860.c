#include "common.h"

void func_80330000_unk_bin_41(void);
s8 func_80330244_unk_bin_41(s8 idx);
void func_8033050C_unk_bin_41(void);
void func_803305D4_unk_bin_41(void);
void func_803309CC_unk_bin_41(void);
s8 func_8033193C_unk_bin_41(void);
void func_803310A0_unk_bin_41(void);
void func_80331248_unk_bin_41(void);
void func_80331474_unk_bin_41(void);
void func_8033168C_unk_bin_41(void);
s8 func_8033193C_unk_bin_41(void);
s16 func_803319F4_unk_bin_41(s16 idx);
void func_80331D50_unk_bin_41(void);
void func_80331E4C_unk_bin_41(void);
void func_80331E5C_unk_bin_41(void);
void func_80331E6C_unk_bin_41(void);
void func_80331E9C_unk_bin_41(void);

void func_80330000_unk_bin_41() {
    s16 objIdx;

    objIdx = func_80027464(9, &D_80113C7C, D_80165100->unk2, D_80165100->unk4, D_80165100->unk6, D_80165100->unk8);

    if (objIdx != -1) {
        gObjects[objIdx].unkA4 = 8;
        gObjects[objIdx].unkB0 = 8;
        gObjects[objIdx].unk132 = 0;
        gObjects[objIdx].Scale.x = 0.5f;
        gObjects[objIdx].Scale.y = 0.5f;
        gObjects[objIdx].Scale.z = 0.5f;
        gObjects[objIdx].unk44 = 10.0f;
        gObjects[objIdx].unk48 = 6.0f;
        gObjects[objIdx].unkAA = 1;
        func_80019448(objIdx, 2, 0, 1);
        func_80330244_unk_bin_41(objIdx);
        func_8001C0EC(objIdx, 0, 0, 0x118, &D_80117490);
    }
}

s8 func_80330244_unk_bin_41(s8 idx) {
    s16 objIdx;
    s16 i;

    for (i = 0; i < gObjects[idx].unkB0; i++) {
        objIdx = gObjects[idx].unkE8[i];

        gObjects[objIdx].unkA4 = 1;
        gObjects[objIdx].unk132 = 0;
        gObjects[objIdx].unkA8 = gObjects[idx].unkE6[i];
        gObjects[objIdx].unkAA = 1;
        gObjects[objIdx].unkD4 = 0.0f;
        gObjects[objIdx].unkD8 = 0.0f;
        func_80019448(objIdx, 2, 0, 1);

        gObjects[objIdx].Scale.y = gObjects[objIdx].Scale.z = gObjects[objIdx].Scale.x = 0.9f;

        if (i == 0) {
            gObjects[objIdx].unkA8 = idx;
        }
    }

    return i;
}

void func_8033050C_unk_bin_41() {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 3;
    } else if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].unkA4 = 4;
    } else {
        return;
    }

    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_803305D4_unk_bin_41() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    f32 sp18;

    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = obj->unk40;
        obj->unkA6 = 0;
        obj->unkA8 = 0;
        obj->unkE0 = func_80014E80(0x168);

        if (obj->unkAA == 1) {
            obj->unk44 = 10.0f;
            obj->unk48 = 6.0f;
            obj->unkAA = 0;
        }
    }
    obj->unkD4 = obj->unk3C;
    obj->unkD8 = obj->unk40;

    obj->unkA6 = func_80015538(obj->unkA6, obj->unkA8);
    sp18 = sinf(obj->unkA6 * DEG_TO_RAD) * 40.0f;
    obj->unk40 = func_80015538(sp18, 0.0f);

    if (obj->unk44 > 10.0f) {
        obj->unk44 -= 1.0f;
    }
    if (obj->unk48 > 6.0f) {
        obj->unk48 -= 1.0f;
    }
    if (obj->unkA8 < 0xC) {
        obj->unkA8 += 1;
    }
    if (obj->unkA6 >= 0x10E) {
        obj->unk132 = 2;
    }
    if (func_800BFFCC(obj, 0, obj->unkE0, 2.0f) == 0) {
        obj->unkE0 = func_80014E80(0x168);
        obj->unk132 = 2;
    }

    sp18 = func_80015744(obj->unk40);
    obj->Rot.x = func_80015538(360.0f, -sp18);
    obj->Rot.y = obj->unk3C;

    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    func_8033193C_unk_bin_41();

    if (obj->unk132 == 2 && !func_8002A1FC(gCurrentParsedObject, 1200.0f)) {
        obj->unkA4 = 6;
        obj->unk132 = 0;
    }
    if (func_8002A1FC(gCurrentParsedObject, 720.0f)) {
        obj->unkA4 = 7;
        obj->unk132 = 0;
    }
}

void func_803309CC_unk_bin_41() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    struct ObjectStruct* firstObj = &PLAYER;
    f32 sp1C;

    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk44 = 14.0f;
        obj->unk48 = 14.0f;
        obj->unkE0 = 90.0f;
        obj->unkA6 = 0;
    }
    obj->unkD4 = obj->unk3C;
    obj->unkD8 = obj->unk40;

    if (obj->unk132 == 1) {
        if (!func_800BFFCC(obj, 1, obj->unkE0, 12.0f)) {
            obj->unk132 = 2;
        }
    }

    obj->unk3C = func_80015538(obj->unk3C, 12.0f);

    sp1C = func_80015744(obj->unk40);
    obj->Rot.x = func_80015538(360.0f, -sp1C);
    obj->Rot.y = obj->unk3C;

    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    func_8033193C_unk_bin_41();

    obj->unkA6++;

    if (obj->unkA6 >= 0xA) {
        if (firstObj->Pos.y + 480.0f <= obj->Pos.y) {
            obj->unkA4 = 6;
            obj->unk132 = 0;
            if (func_8002A1FC(gCurrentParsedObject, 720.0f) == 0) {
                obj->unkA4 = 8;
                obj->unk132 = 0;
            }
        }
    }
}

s8 func_80330C3C_unk_bin_41() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    struct ObjectStruct* firstObj = &PLAYER;
    f32 x;
    f32 xDiff;
    f32 zDiff;
    s16 distCalc;

    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unkA6 = 0x14;
        obj->unkE0 = 270.0f;

        if (obj->unkAA == 1) {
            obj->unk44 = 10.0f;
            obj->unk48 = 6.0f;
            obj->unkAA = 0;
        }

        obj->unkB2 = 0;
    }

    obj->unkD4 = obj->unk3C;
    obj->unkD8 = obj->unk40;

    if (obj->unk132 == 1) {
        if (obj->unk44 > 0.0f) {
            obj->unk44 -= 1.0f;
        }
        if (obj->unk48 > 0.0f) {
            obj->unk48 -= 1.0f;
        }
    }
    if (obj->unk132 == 1) {
        if (!func_800BFFCC(obj, 1, obj->unkE0, 12.0f)) {
            obj->unk132 = 2;
        }
    }
    if (obj->unk132 == 2) {
        func_8002A8B4(gCurrentParsedObject, 12.0f);

        if (func_8002A560(gCurrentParsedObject, 5.0f) == 0) {
            xDiff = gObjects->Pos.x - obj->Pos.x;
            zDiff = gObjects->Pos.z - obj->Pos.z;
            distCalc = (s16) (sqrtf((xDiff * xDiff) + (zDiff * zDiff)) / 60.0f);

            if (distCalc >= 9) {
                distCalc = 8;
            }

            obj->unk44 = (f32) (distCalc + 14);
            obj->unk48 = 8.0f;
            obj->unk132 = 3;
        }
    }
    if (obj->unk132 == 3) {
        if (obj->unk48 <= 16.0f) {
            obj->unk48 += 1.0f;
        }

        obj->Rot.y = func_80015538(obj->Rot.y, 12.0f);
    }
    x = func_80015744(obj->unk40);

    obj->Rot.x = func_80015538(360.0f, -x);

    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    func_8033193C_unk_bin_41();

    obj->unkB2++;

    if (firstObj->Pos.y - 480.0f >= obj->Pos.y) {
        obj->unkA4 = 7;
        obj->unkA4 = 5;
        obj->unk132 = 0;
    }
}

void func_803310A0_unk_bin_41() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    f32 x;
    UNUSED s32 pad[4];

    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk44 = 14.0f;
        obj->unk48 = 14.0f;
        obj->unkA6 = 0;
    }

    obj->unkD4 = obj->unk3C;
    obj->unkD8 = obj->unk40;

    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    func_8002A8B4(gCurrentParsedObject, 12.0f);
    func_8002A9A4(gCurrentParsedObject, 2.0f);

    x = func_80015744(obj->unk40);
    obj->Rot.x = func_80015538(360.0f, -x);
    obj->Rot.y = obj->unk3C;

    func_8033193C_unk_bin_41();

    obj->unkA6++;

    if (!func_8002A1FC(gCurrentParsedObject, 720.0f)) {
        obj->unkA4 = 8;
        obj->unk132 = 0;
    }
}

void func_80331248_unk_bin_41() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    f32 x;

    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk44 = 0.0f;
        obj->unk48 = 0.0f;
        obj->unkDC = func_80015538(obj->unk3C, 180.0f);
        obj->unkDC = func_80015538(obj->unkDC, func_80014E80(0x5A));
        obj->unkE0 = 90.0f;
    }
    if (obj->unk132 == 1) {
        if (!func_800BFFCC(obj, 1, obj->unkE0, 12.0f)) {
            obj->unk48 = 4.0f;
            obj->unk132 = 2;
        }
    }
    obj->unkD4 = obj->unk3C;
    obj->unkD8 = obj->unk40;

    x = func_80015744(obj->unk40);
    obj->Rot.x = func_80015538(360.0f, -x);
    obj->Rot.y = obj->unk3C;

    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    func_8033193C_unk_bin_41();

    if (!func_800BFF20(obj, obj->unkDC, 12.0f)) {
        obj->unkA4 = 2;
        obj->unkA4 = 7;
        obj->unk132 = 0;
    }
}

void func_80331474_unk_bin_41() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s16 objIdx;
    s16 i;

    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk44 = 0.0f;
        obj->unk48 = 0.0f;
        obj->unkB2 = 0xC8;
        obj->unk108 = 0;

        for (i = 0; i < obj->unkB0; i++) {
            if ((objIdx = obj->unkE8[i]) != -1) {
                gObjects[objIdx].unk108 = 0;
            }
        }
    }

    func_8033193C_unk_bin_41();

    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    obj->unkB2--;

    if (!(obj->unkB2 & 7)) {
        if (obj->unkB0 >= 0) {
            if ((objIdx = obj->unkE8[obj->unkB0]) != -1) {
                func_800281A4(gCurrentParsedObject, obj->unkB0);
                func_8002B0E4(objIdx);
            }
            obj->unkB0--;
        } else {
            func_8002B0E4(gCurrentParsedObject);
        }
    }
}

void func_8033168C_unk_bin_41() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s16 objIdx;

    s16 comp;
    s16 i;

    if (obj->unk132 == 0) {
        obj->unk132 = 1;
        obj->unk108 = 0x28;

        for (i = 0; i < obj->unkB0; i++) {
            if ((objIdx = obj->unkE8[i]) != -1) {
                gObjects[objIdx].unk108 = 0;
            }
        }
    }
    func_8033193C_unk_bin_41();

    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    comp = !(obj->unk108 % 2);

    for (i = 0; i < obj->unkB0; i++) {
        if ((objIdx = obj->unkE8[i]) != -1) {
            func_8001BB34(objIdx, comp);
        }
    }

    func_8001BB34(gCurrentParsedObject, comp);

    if (obj->unk108 == 1) {
        obj->unk108 = 1;
        obj->unkA4 = 7;
        obj->unk132 = 0;

        for (i = 0; i < obj->unkB0; i++) {
            if ((objIdx = obj->unkE8[i]) != -1) {
                func_8001BB34(objIdx, 0);
                gObjects[objIdx].unk108 = 0;
            }
        }
        func_8001BB34(gCurrentParsedObject, 0);
    }
}

s8 func_8033193C_unk_bin_41() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];
    s16 i;
    s8 ret = 0;

    for (i = obj->unkB0; i > 0; i--) {
        ret += func_803319F4_unk_bin_41(i - 1);
    }

    return ret;
}

s16 func_803319F4_unk_bin_41(s16 idx) {
    struct ObjectStruct* parsedObj = &gObjects[gCurrentParsedObject];
    struct ObjectStruct* sp40;
    struct ObjectStruct* obj;
    f32 factor;
    f32 addend;
    s16 objIdx;
    UNUSED s32 pad[2];

    objIdx = parsedObj->unkE8[idx];

    if (objIdx != -1) {
        obj = &gObjects[objIdx];
        sp40 = &gObjects[obj->unkA8];

        factor = func_80015744(sp40->unk40);

        addend = cosf(factor * 0.017453292519943295) * 48.0f;
        obj->Vel.y = sinf(factor * 0.017453292519943295) * 48.0f;
        addend = 48.0f;

        if (parsedObj->unkA4 == 5) {
            addend = 14.0f;
            obj->Vel.y = 0.0f;
        }

        factor = func_80015538(sp40->unkD4, 180.0f);

        obj->Vel.x = sinf(factor * 0.017453292519943295) * addend;
        obj->Vel.z = cosf(factor * 0.017453292519943295) * addend;
        obj->Vel.y *= -1.0f;

        obj->Pos.x = sp40->Pos.x + obj->Vel.x;
        obj->Pos.z = sp40->Pos.z + obj->Vel.z;
        obj->Pos.y = sp40->Pos.y + obj->Vel.y;

        obj->Rot.y = sp40->Rot.y;
        obj->Rot.x = sp40->Rot.x;

        obj->unk3C = sp40->unk3C;
        obj->unk40 = sp40->unk40;
        obj->unk44 = sp40->unk44;

        obj->unk48 = sp40->unk48;
        obj->unkD4 = sp40->unkD4;
        obj->unkD8 = sp40->unkD8;
    }

    return ~(objIdx > 0U) ? 0 : 1;
}

void func_80331D50_unk_bin_41() {
    s32 sp1C;

    sp1C = gObjects[gCurrentParsedObject].unkA4;

    switch (sp1C) {
        case 8:
            func_803305D4_unk_bin_41();
            break;
        case 6:
            func_80330C3C_unk_bin_41();
            break;
        case 7:
            func_803309CC_unk_bin_41();
            break;
        case 2:
            func_803310A0_unk_bin_41();
            break;
        case 5:
            func_80331248_unk_bin_41();
            break;
        case 3:
            func_80331474_unk_bin_41();
            break;
        case 4:
            func_8033168C_unk_bin_41();
            break;
        default:
            break;
    }
}

void func_80331E4C_unk_bin_41() {
}

void func_80331E5C_unk_bin_41() {
}

void func_80331E6C_unk_bin_41() {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80331E9C_unk_bin_41() {
    struct ObjectStruct* obj = &gObjects[gCurrentParsedObject];

    if (obj->unkE6[0] != -1) {
        if (obj->unkAA == 1) {
            func_80029C40(gCurrentParsedObject);
            func_80029D04(gCurrentParsedObject);
        }
    }
}
