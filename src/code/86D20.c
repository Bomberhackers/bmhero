#include "common.h"

void func_80094800(void) {
    struct ObjectStruct *sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk3C = (f32) func_80014E80(0x168);
        sp34->unk44 = 20.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (func_800295C0(gCurrentParsedObject, &sp30, &sp2C, 0.0f, 0.0f, 0.0f) != 0) {
        sp34->Pos.y = sp2C;
    } else {
        sp34->Pos.y = sp30;
    }
}

void func_80094990(void) {
    struct ObjectStruct *sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;

    sp3C = &gObjects[gCurrentParsedObject];
    if (sp3C->unk132 == 0) {
        sp3C->unk132 += 1;
        sp3C->unkA6 = 0;
        sp3C->unk3C = (f32) func_80014E80(0x168);
        sp3C->unk44 = 20.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (sp3C->unkA6 == 1) {
        sp3C->unkA6 = 2;
        func_80029EF8(gCurrentParsedObject, 0.0f, 2.0f);
    }
    sp30 = sp3C->Vel.y;
    sp3C->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    if (D_801651A0 & 0x40) {
        sp3C->unkA6 = 1;
    }
    if (sp3C->unkA6 == 0) {
        if (func_800295C0(gCurrentParsedObject, &sp38, &sp34, 0.0f, 0.0f, 0.0f) != 0) {
            sp3C->Pos.y = sp34;
        } else {
            sp3C->Pos.y = sp38;
        }
    } else if (sp3C->unkA6 == 2) {
        sp3C->Vel.y = sp30;
        if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
            sp3C->unkA6 = 0;
        }
    }
}

void func_80094C20(void) {
    struct ObjectStruct *sp34;
    f32 sp30;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unkA6 = 1;
        sp34->unk3C = (f32) func_80014E80(0x168);
        sp34->unk44 = 10.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    if (sp34->unkA6 != 0) {
        sp34->unkA6 = 0;
        func_80029EF8(gCurrentParsedObject, 30.0f, 2.0f);
    }
    sp30 = sp34->Vel.y;
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    sp34->Vel.y = sp30;
    if (func_80029F58(gCurrentParsedObject, 0.0f, 0.0f, 0.0f, 60.0f) == 1) {
        sp34->unkA6 = 1;
    }
}

void func_80094E04(void) {
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk3C = 0.0f;
        sp2C->Rot.y = sp2C->unk3C;
        sp2C->unk44 = 5.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk40 = sp2C->unk48;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    } else {
        func_8002A8B4(gCurrentParsedObject, 6.0f);
        sp2C->Rot.y = sp2C->unk3C;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80094F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80095228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80095448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80095588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80095604.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800956F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800959F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80095A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80095C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80095E14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80095E94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80095F08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80095FF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800960B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009612C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800961A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80096254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80096350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800963DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80096454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800964CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80096540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800965EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800966D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80096760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009681C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80096894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80096900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800969AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80096BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80096C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80096F88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80096FF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80097244.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800972D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009738C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80097438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800974C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80097634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009766C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80097730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800977EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80097888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800979EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80097A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80097B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80097C68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80097DC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80097E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80097EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80098000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80098164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80098208.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800982C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80098370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800983F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80098590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800985C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009868C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009878C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80098864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800989E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80098AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80098E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80098E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80099084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800991D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80099454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80099C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80099EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_80099F80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009A1F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009A2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009A320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009A390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009A4DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009A674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009A994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009AA10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009AC94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009AD74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009ADE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009AE7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009AF18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009B4C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009B538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009B548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009B5F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009B600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009B884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009B8F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009B904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009B97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009B9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009BBC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009BCBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009BD58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009BDF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009BF7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009C044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009C18C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009C224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009C2E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009C50C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009C598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009C74C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009C7C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009C85C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009C96C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009C9F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009CA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009CB58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009CBE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009CC78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009CC88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009D4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009D558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009D618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009D75C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009D7B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009D9BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009DA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009DFF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E10C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E40C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E4F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E5F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E66C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E67C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E7E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E7F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009E954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009EA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009EAEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009EC44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009ECE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009ED88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009EE54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009EF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F0B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F13C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F4D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F5BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F5EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F66C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F71C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009F890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009FB08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009FC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009FCBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009FD34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_8009FE10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A0034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A0298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A038C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A0418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A04D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A0580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A05EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A0698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A08B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A0960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A0A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A0D3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A0DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A0FA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A10C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A169C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A17E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1C40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1FAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A1FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A2058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A25F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A28AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A2AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A2BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A2C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A3034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A30E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A32E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A3498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A3520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A391C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A39D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A3BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A3D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A3E28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A4178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A4434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A44E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A46E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A488C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A4964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A4AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A4C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A4F08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A528C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A54B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A5760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A5A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A5B74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A5D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A5DB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A605C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A62A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A6574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A6770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A6A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A6D0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A6D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A6DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A7194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A72B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A72C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A7644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A7894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A7A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A7ABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A7C18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A7DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A8144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A843C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A8500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A8580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A8858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/86D20/func_800A8A58.s")
