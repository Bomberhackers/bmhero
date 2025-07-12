#include <ultra64.h>
#include "70C40.h"

void func_8007E720(void) {
    s32 sp1C;

    for (sp1C = 6; sp1C < 0xE; sp1C++) {
        func_8001A928(sp1C);
    }
}

void func_8007E76C(f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    s32 sp34;
    struct ObjectStruct* sp30;
    f32 sp2C;

    for (sp34 = 6; sp34 <= 13; sp34++) {
        if (gObjects[sp34].actionState == 0) {
            func_8001A928(sp34);
            sp30 = &gObjects[sp34];
            if (arg3 == 1) {
                sp30->objID = 0x10;
                func_8001BD44(sp34, 0, 2, (s32) gFileArray[0xF].ptr);
                func_8001BD44(sp34, 1, 3, &gFileArray[0xF].ptr[D_80116650[0]]);
                func_8001C0EC(sp34, 0, 0, 0xF, &D_80116654);
                func_8001C0EC(sp34, 1, 0, 0xF, &D_80116658);
            } else if (arg3 == 2) {
                sp30->objID = 0x11;
                func_8001BD44(sp34, 0, 1, (s32) gFileArray[0xE].ptr);
                func_8001BD44(sp34, 1, 3, (s32) &gFileArray[0xE].ptr[D_80116644[0]]);
                func_8001C0EC(sp34, 0, 0, 0xE, &D_80116648);
                func_8001C0EC(sp34, 1, 0, 0xE, &D_8011664C);
            } else {
                func_8001BD44(sp34, 0, 3, (s32) gFileArray[0xD].ptr);
                func_8001BD44(sp34, 1, 4, (s32) &gFileArray[0xD].ptr[D_80116638[0]]);
                func_8001C0EC(sp34, 0, 0, 0xD, &D_8011663C);
                func_8001C0EC(sp34, 1, 0, 0xD, &D_80116640);
                sp30->objID = 0xF;
            }
            sp30->actionState = 1;
            sp30->damageState = 1;
            sp30->Pos.x = arg0;
            sp30->Pos.y = arg1;
            sp30->Pos.z = arg2;
            if (arg3 == 1) {
                func_800177D8(sp34, 0, 0x2B, -1, 0);
            } else if (gFireCount < 2) {
                func_800177D8(sp34, 0, 0x29, -1, 0);
            } else if (gFireCount == 2) {
                func_800177D8(sp34, 0, 0x66, -1, 0);
            } else {
                func_800177D8(sp34, 0, 0x2A, -1, 0);
            }
            if (gFireCount == 0) {
                sp2C = D_8010CB00;
            } else if (gFireCount == 1) {
                sp2C = D_8010CB04;
            } else if (gFireCount == 2) {
                sp2C = D_8010CB08;
            } else {
                sp2C = 1.5f;
            }
            func_8001FB3C(5, 4, 1);
            sp30->Scale.z = sp2C;
            sp30->Scale.x = sp30->Scale.y = sp30->Scale.z;
            func_80019448(sp34, 2, 0, 1);
            break;
        }
    }
}

void func_8007EBEC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    s32 sp34;
    struct ObjectStruct* sp30;

    for (sp34 = 6; sp34 < 0xE; sp34++) {
        if (gObjects[sp34].actionState == 0) {
            sp30 = &gObjects[sp34];
            func_8001A928(sp34);
            func_8001BD44(sp34, 0, 3, (s32) gFileArray[0x10].ptr);
            func_8001BD44(sp34, 1, 4, (s32) &gFileArray[0x10].ptr[D_8011665C[0]]);
            func_8001C0EC(sp34, 0, 0, 0x10, &D_80116660);
            func_8001C0EC(sp34, 1, 0, 0x10, &D_80116664);
            sp30->objID = 0x12;
            sp30->actionState = 1;
            sp30->Pos.x = arg0;
            sp30->Pos.y = arg1;
            sp30->Pos.z = arg2;
            sp30->Scale.z = arg3;
            sp30->Scale.x = sp30->Scale.y = sp30->Scale.z;
            func_80019448(sp34, 2, 0, 1);
            if (arg4 != 0) {
                sp30->damageState = 1;
            } else {
                sp30->damageState = 0;
            }
            break;
        }
    }
}

void func_8007EDF4(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_8007EBEC(arg0, arg1, arg2, arg3, 1);
}

void func_8007EE40(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_8007EBEC(arg0, arg1, arg2, arg3, 0);
}

void func_8007EE88(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 sp34;
    struct ObjectStruct* sp30;

    for (sp34 = 6; sp34 < 14; sp34++) {
        if (gObjects[sp34].actionState == 0) {
            sp30 = &gObjects[sp34];
            func_8001A928(sp34);
            func_8001BD44(sp34, 0, 1, (s32) gFileArray[0xE].ptr);
            func_8001BD44(sp34, 1, 3, (s32) &gFileArray[0xE].ptr[*D_80116644]);
            func_8001C0EC(sp34, 0, 0, 0xE, &D_80116648);
            func_8001C0EC(sp34, 1, 0, 0xE, &D_8011664C);
            sp30->objID = 0x14;
            sp30->actionState = 1;
            sp30->Pos.x = arg0;
            sp30->Pos.y = arg1;
            sp30->Pos.z = arg2;
            sp30->Scale.z = arg3;
            sp30->Scale.x = sp30->Scale.y = sp30->Scale.z;
            func_80019448(sp34, 2, 0, 1);
            sp30->damageState = 1;
            break;
        }
    }
}

void func_8007F070(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 sp34;
    struct ObjectStruct* sp30;

    for (sp34 = 6; sp34 < 14; sp34++) {
        if (gObjects[sp34].actionState == 0) {
            sp30 = &gObjects[sp34];
            func_8001A928(sp34);
            func_8001BD44(sp34, 0, 4, (s32) gFileArray[0x11].ptr);
            func_8001BD44(sp34, 1, 3, (s32) &gFileArray[0x11].ptr[D_80116668[0]]);
            func_8001C0EC(sp34, 0, 0, 0x11, &D_8011666C);
            func_8001C0EC(sp34, 1, 0, 0x11, &D_80116670);
            sp30->objID = 0x13;
            sp30->actionState = 1;
            sp30->Pos.x = arg0;
            sp30->Pos.y = arg1;
            sp30->Pos.z = arg2;
            sp30->Scale.z = arg3;
            sp30->Scale.x = sp30->Scale.y = sp30->Scale.z;
            func_80019448(sp34, 2, 0, 1);
            break;
        }
    }
}

void func_8007F24C(void) {
    struct ObjectStruct* sp24;
    s32 sp20;
    f32 sp1C;

    for (sp20 = 6, sp24 = &gObjects[6]; sp20 < 14; sp20++, sp24++) {
        if (sp24->actionState != 0) {
            if (sp24->objID == 0x13) {
                sp1C = func_8001B62C(sp20, 1);
                if ((sp1C >= 30.0f) && (sp1C <= 80.0f)) {
                    func_80081468(0x2C8, sp24->Pos.x, sp24->Pos.y, sp24->Pos.z);
                }
            }
            sp1C = func_8001B62C(sp20, 1);
            if (sp1C < 36.0f) {
                sp24->unkFE = (s16) ((s32) sp1C / 4);
            } else {
                sp24->damageState = 0;
            }

            if (func_8001B44C(sp20, 0) != 0) {
                func_8001A928(sp20);
                break;
            } else {
                func_8001CD20(sp20);
            }
        }
    }
}

void func_8007F3F0(void) {
    struct ObjectStruct* sp34;
    s32 sp30;
    Vec3f sp24;

    func_8001838C();
    for (sp30 = 6, sp34 = gObjects + 6; sp30 < 0xE; sp30++, sp34++) {
        if (sp34->actionState != 0) {
            if (func_8001C300(sp30, 0) != 0) {
                sp24.z = gView.eye.x - sp34->Pos.x;
                sp24.y = gView.eye.y - sp34->Pos.y;
                sp24.x = gView.eye.z - sp34->Pos.z;
                func_800158B4(sp24.z, sp24.y, sp24.x, &sp34->Rot.x, &sp34->Rot.y);
                sp34->Rot.z = 0.0f;
                func_80019510(sp30, 1, 1);
                func_8001C384(sp30, 0);
            }
            if (func_8001C300(sp30, 1) != 0) {
                sp34->Rot.y = 0.0f;
                sp34->Rot.x = 0.0f;
                sp34->Rot.z = 0.0f;
                func_80019510(sp30, 1, 1);
                func_8001C384(sp30, 1);
            }
        }
    }
}
