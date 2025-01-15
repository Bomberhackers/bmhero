#include <ultra64.h>
#include "functions.h"
#include "types.h"

extern struct UnkStruct_80027C00 D_80113ED4;

void func_800C1380(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113ED4, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].Scale.x = 1.5f;
        gObjects[sp24].Scale.y = 1.5f;
        gObjects[sp24].Scale.z = 1.5f;
    }
}

void func_800C1490(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 6;
    } else if (D_80177A64 == 2) {
        if ((gObjects[gCurrentParsedObject].unkB2 == 0) && (gObjects[gCurrentParsedObject].unkA4 == 3)) {
            gObjects[gCurrentParsedObject].unkB2 = 0x1E;
        }
    }
}

extern u32 D_80117FF0;
extern UNK_TYPE D_80118044;

void func_800C156C(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->Vel.x = 0.0f;
        sp24->Vel.y = 0.0f;
        sp24->Vel.z = 0.0f;
        sp24->unkB2 = 0;
        func_8001BBDC(gCurrentParsedObject, 1);
        func_8001C0EC(gCurrentParsedObject, 0, 1, 0x48, &D_80117FF0);
        if (sp24->unkB6 == 0) {
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118044);
        }
    }
    if (func_8002A1FC(gCurrentParsedObject, 420.0f) != 0) {
        sp24->unkA4 = 2;
        sp24->unk132 = 0;
    }
}

void func_800C16BC(void) {
    struct ObjectStruct *sp24;
    f32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 12.0f, 0.75f);
        func_8001BBDC(gCurrentParsedObject, 0);
    }
    sp20 = sp24->Vel.y;
    sp24->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 60.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp24->Vel.x = 0.0f;
        sp24->Vel.z = 0.0f;
    }
    sp24->Vel.y = sp20;
    if ((func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) && (func_8001B44C(gCurrentParsedObject, 0) != 0)) {
        sp24->unk108 = 1;
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->unkA4 = 3;
        sp24->unk132 = 0;
    }
}

void func_800C187C(void) {
    struct ObjectStruct *sp3C;
    f32 sp38;
    f32 sp34;
    s32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unkA6 = 0x64;
        sp3C->unkB0 = 0;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_8001C0EC(gCurrentParsedObject, 0, 3, 0x48, &D_80117FF0);
    }
    if (sp3C->unkB2 == 0) {
        sp3C->unk44 = 5.0f;
    } else {
        sp3C->unkB2 -= 1;
        sp3C->unk44 = 0.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp3C->unkB0 = 0xA;
    }
    if (sp3C->unkB0 == 0) {
        sp30 = func_8002A640(gCurrentParsedObject, 10.0f);
        sp3C->Rot.y = func_80015538(sp3C->Rot.y, (f32) (sp30 * 0xA));
        sp3C->unk3C = sp3C->Rot.y;
    } else {
        sp3C->unkB0 -= 1;
    }
    sp3C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 40.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) {
        sp3C->Pos.y = sp34;
    } else {
        sp3C->Pos.y = sp38;
    }
    sp3C->unkA6 -= 1;
    if (sp3C->unkA6 == 0) {
        sp3C->unkA4 = 4;
        sp3C->unk132 = 0;
    }
}

extern struct UnkStruct_80027C00 D_80113EE0;

void func_800C1B5C(void) {
    struct ObjectStruct *sp34;
    s32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->Vel.z = 0.0f;
        sp34->Vel.x = sp34->Vel.y = sp34->Vel.z;
        sp34->unkA6 = 0x14;
        func_8001C0EC(gCurrentParsedObject, 0, 4, 0x48, &D_80117FF0);
        if (sp34->unkB6 == 0) {
            sp34->unkB6 = 1;
            func_8001ABF4(gCurrentParsedObject, 0, 0, &D_80118044 + 7);
        }
    }
    if (sp34->unkA6 == 0) {
        sp30 = func_80027464(1, &D_80113EE0, sp34->Pos.x, sp34->Pos.y + 90.0f, sp34->Pos.z, sp34->Rot.y);
        sp34->unkA6 = 0x14;
    } else {
        sp34->unkA6 -= 1;
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp34->unkA4 = 5;
        sp34->unk132 = 0;
    }
}

void func_800C1D38(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->Vel.x = 0.0f;
        sp24->Vel.y = 0.0f;
        sp24->Vel.z = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 5, 0x48, &D_80117FF0);
    }
    if (func_8001B44C(gCurrentParsedObject, 0) != 0) {
        sp24->unk108 = -1;
        func_8001BBDC(gCurrentParsedObject, 1);
        sp24->unkA4 = 1;
        sp24->unk132 = 0;
    }
}

void func_800C1E54(void) {
    func_8002B0E4(gCurrentParsedObject);
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C1E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C1F64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C2004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C2230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C22C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C238C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C249C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C24EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C2624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C27B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C29F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C2B04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C2C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C2C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C2D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C2E50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C2EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C304C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C31D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C3454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C3670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C38A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C3978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C39F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C3A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C3C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C3E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C3F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C4040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C410C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C4348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C4358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C4584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C4C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C4F64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C5148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C5888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C5BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C5DC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C5EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C5F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C5F80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C60F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C639C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C66B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C689C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C6B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C6DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C7130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C7160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C7260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C77D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C785C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C7BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C7FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C8764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C8858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C8924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C899C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C8A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C8B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C8CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C8F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C8FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C907C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C90F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C9160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C92BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C9420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C980C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C9970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C99CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C9A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C9B14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C9DF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C9E28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C9EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C9F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800C9FF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA2D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA4FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA52C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA55C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA63C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA6DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CA9F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CAA94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CAB00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CAC6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CAE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB0DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB24C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB28C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB36C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB3D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB7A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CB9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CBA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CBB58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CBF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/B38A0/func_800CBF8C.s")
