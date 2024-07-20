#include "common.h"
#include "variables.h"

void func_8001A928(s32); 
void func_8007EBEC(f32, f32, s32, s32, s32);
void func_800158B4(f32, f32, f32, f32*, f32*);         /* extern */
void func_8001838C();                                  /* extern */
void func_80019510(s32, s32, s32);                         /* extern */
s32 func_8001C300(s32, s32);                          /* extern */
void func_8001C384(s32, s32);                            /* extern */

void func_8007E720(void) {
    s32 sp1C;
    
    for(sp1C = 6; sp1C < 0xE; sp1C++)
    {
        func_8001A928(sp1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/70C40/func_8007E76C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/70C40/func_8007EBEC.s")

void func_8007EDF4(f32 arg0, f32 arg1, s32 arg2, s32 arg3) {
    func_8007EBEC(arg0, arg1, arg2, arg3, 1);
}

void func_8007EE40(f32 arg0, f32 arg1, s32 arg2, s32 arg3) {
    func_8007EBEC(arg0, arg1, arg2, arg3, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/70C40/func_8007EE88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/70C40/func_8007F070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/70C40/func_8007F24C.s")

void func_8007F3F0(void) {
    struct PlayerStruct* sp34;
    s32 sp30;
    struct Vec3f sp24;

    func_8001838C();
    for(sp30 = 6, sp34 = gObjects + 6; sp30 < 0xE; sp30++, sp34++)
    {
        if (sp34->unkA4 != 0) 
        {
            if (func_8001C300(sp30, 0) != 0) 
            {
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
