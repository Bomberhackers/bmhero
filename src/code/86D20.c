#include <ultra64.h>
#include "common.h"

struct struct_801765D9 {
    char unk[2];
};

// Ram addresses used in this file
#define UNK_TYPE int

extern struct UnkStruct_80027C00 D_80113400;
extern struct UnkStruct_80027C00 D_8011340C;
extern struct UnkStruct_80027C00 D_80113418;
extern struct UnkStruct_80027C00 D_80113424;
extern struct UnkStruct_80027C00 D_8011343C;
extern struct UnkStruct_80027C00 D_80113448;
extern struct UnkStruct_80027C00 D_80113454;
extern struct UnkStruct_80027C00 D_80113460;
extern struct UnkStruct_80027C00 D_8011346C;
extern struct UnkStruct_80027C00 D_801134A8;
extern struct UnkStruct_80027C00 D_801134E4;
extern struct UnkStruct_80027C00 D_80113508;
extern struct UnkStruct_80027C00 D_80113514;
extern struct UnkStruct_80027C00 D_80113520;
extern struct UnkStruct_80027C00 D_8011352C;
extern struct UnkStruct_80027C00 D_80113538;
extern struct UnkStruct_80027C00 D_80113544;
extern struct UnkStruct_80027C00 D_80113550;
extern struct UnkStruct_80027C00 D_8011355C;
extern struct UnkStruct_80027C00 D_80113568;
extern struct UnkStruct_80027C00 D_80113574;
extern struct UnkStruct_80027C00 D_8011358C;
extern struct UnkStruct_80027C00 D_801135A4;
extern struct UnkStruct_80027C00 D_801135B0;
extern struct UnkStruct_80027C00 D_801135BC;
extern struct UnkStruct_80027C00 D_801135D4;
extern struct UnkStruct_80027C00 D_801135E0;
extern struct UnkStruct_80027C00 D_80113604;
extern struct UnkStruct_80027C00 D_80113610;
extern struct UnkStruct_80027C00 D_8011361C;
extern struct UnkStruct_80027C00 D_80113628;
extern struct UnkStruct_80027C00 D_80113634;
extern struct UnkStruct_80027C00 D_80113640;
extern struct UnkStruct_80027C00 D_8011364C;
extern struct UnkStruct_80027C00 D_80113658;
extern struct UnkStruct_80027C00 D_80113664;
extern struct UnkStruct_80027C00 D_80113670;
extern struct UnkStruct_80027C00 D_8011367C;
extern struct UnkStruct_80027C00 D_80113688;
extern struct UnkStruct_80027C00 D_801136A0;
extern struct UnkStruct_80027C00 D_801136AC;
extern struct UnkStruct_80027C00 D_801136B8;
extern struct UnkStruct_80027C00 D_801136E8;
extern struct UnkStruct_80027C00 D_801136F4;
extern struct UnkStruct_80027C00 D_8011382C;
extern struct UnkStruct_80027C00 D_80113844;
extern struct UnkStruct_80027C00 D_80113874;
extern struct UnkStruct_80027C00 D_801138A4;
extern struct UnkStruct_80027C00 D_801138B0;
extern struct UnkStruct_80027C00 D_801138BC;
extern struct UnkStruct_80027C00 D_801138C8;
extern struct UnkStruct_80027C00 D_801138F8;
extern struct UnkStruct_80027C00 D_80113910;
extern struct UnkStruct_80027C00 D_801147F0;
extern short D_80114820[4];
extern UNK_TYPE D_8011482C;
extern struct UnkStruct_80027B34 D_8011485C;
extern UNK_TYPE D_8011486C;
extern UNK_TYPE D_8011486E;
extern UNK_TYPE D_80114874;
extern UNK_TYPE D_80114890;
extern UNK_TYPE D_80114892;
extern UNK_TYPE D_801148A4;
extern UNK_TYPE D_801148B4;
extern UNK_TYPE D_801148C0;
extern f64 D_801148D8;
extern f32 D_801148E0;
extern f32 D_801148E4;
extern f32 D_801148E8;
extern f64 D_801148F0;
extern f32 D_801148F8;
extern f32 D_80114950;
extern f64 D_80114958;
extern f64 D_80114960;
extern f32 D_80114968;
extern f64 D_80114970;
extern f64 D_80114978;
extern f32 D_80114980;
extern f32 D_80114988;
extern f32 D_80114990;
extern f32 D_80114998;
extern f32 D_8011499C;
extern f32 D_801149A0;
extern f64 D_801149F0;
extern f64 D_801149F8;
extern f64 D_80114A00;
extern f64 D_80114A08;
extern f64 D_80114A10;
extern f32 D_80114A18;
extern u32 D_80116938;
extern u32 D_8011693C;
extern u32 D_80116940;
extern u32 D_80116944;
extern u32 D_80116950;
extern UNK_TYPE D_8011698C;
extern u32 D_801169FC;
extern UNK_TYPE D_80116A18;
extern UNK_TYPE D_80116A50;
extern u32 D_80116A88;
extern UNK_TYPE D_80116AB8;
extern u32 D_80116AF0;
extern u32 D_80116AF4;
extern UNK_TYPE D_80116B60;
extern UNK_TYPE D_80116D78;
extern UNK_TYPE D_80116E50;
extern u32 D_80116ECC;
extern u32 D_80116ED4;
extern u32 D_80116EE4;
extern UNK_TYPE D_80116F20;
extern u32 D_80117020;
extern u32 D_80117028;
extern u32 D_80117088;
extern UNK_TYPE D_80117108;
extern UNK_TYPE D_80117124;
extern UNK_TYPE D_80117140;
extern UNK_TYPE D_8011715C;
extern UNK_TYPE D_80117178;
extern UNK_TYPE D_80117194;
extern u32 D_801171B0;
extern UNK_TYPE D_80117230;
extern UNK_TYPE D_8011724C;
extern UNK_TYPE D_80117268;
extern UNK_TYPE D_80117284;
extern u32 D_801172A0;
extern UNK_TYPE D_801172D0;
extern UNK_TYPE D_801172EC;
extern u32 D_8011B8E0;
extern UNK_TYPE D_8011B92C;
extern s8 D_8016E328;
extern struct struct_801765D9 D_801765D9[0x4];


// In this file
extern f64 D_801148D0; // RODATA literal

// Unsorted
extern struct UnkStruct_80027C00  D_801147F0;
extern f32 D_801147F8[0x4]; // Rodata constantUNK_TYPE
extern struct struct_801765D9 D_80116934;
extern struct struct_801765D9 D_801765D8[0x4]; // Random arr size


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

// TODO: has rodata
void func_80094F94(void) {
    struct ObjectStruct *sp34;
    f32 sp30;
    f32 sp2C;

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 = 1;
        sp34->unkA8 = 0;
        sp34->unk3C = (f32) func_80014E80(0x168);
        sp34->unk44 = 5.0f;
        sp34->unk40 = 90.0f;
        sp34->unk48 = 30.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    sp34->unkA6 = (s16) (s32) func_80015538((f32) sp34->unkA6, 10.0f);
    func_800294F0(gCurrentParsedObject, &sp30, &sp2C, 0.0f, 0.0f, 0.0f);
    sp34->unk48 = ((sinf((f32) ((f64) sp34->unkA6 *  D_801148D0)) * 30.0f) + (sp30 + 100.0f)) - sp34->Pos.y;
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        sp34->unkA6 = (s16) (s32) func_80015538((f32) sp34->unkA6, -10.0f);
    }
    sp34->Rot.y = func_8002A46C(gCurrentParsedObject);
}

void func_80095228(void) {
    struct ObjectStruct* sp2C;
    UNUSED s32 pad[2];
    s32 sp20;

    sp20 = 0;
    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unkA6 = 0;
        sp2C->unk48 = 0.0f;
        sp2C->unk40 = sp2C->unk48;
        sp20 = 1;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp2C->unkA6 = 1;
    }
    if (sp2C->unkA6 != 0) {
        if ((--sp2C->unk44) < 5.0f) {
            sp2C->unkA6 = 0;
            sp20 = 1;
        }
    }
    if (sp20 != 0) {
        sp2C->unk3C = func_8002A46C(gCurrentParsedObject);
        sp2C->unk44 = 20.0f;
        sp2C->Rot.y = sp2C->unk3C;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        sp2C->unk3C = func_80015538(sp2C->unk3C, 180.0f);
        sp2C->unkA6 = 1;
    }
}

void func_80095448(void) {
    struct ObjectStruct *sp34;
    UNUSED s32 pad[2];

    sp34 = &gObjects[gCurrentParsedObject];
    if (sp34->unk132 == 0) {
        sp34->unk132 += 1;
        sp34->unk3C = (f32) func_80014E80(0x168);
        sp34->unk44 = 5.0f;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    sp34->Vel.y = 0.0f;
    func_80029C40(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 5U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
}

// TODO: has rodata
void func_80095588(void) {
    UNUSED s32 sp2C;
    UNUSED s32 pad[2];

    sp2C = func_80027464(1, &D_801147F0, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
}

void func_80095604(void) {
    if (D_80177A64 == 0) {
        gObjects[gCurrentParsedObject].unkA4 = 4;
    } else if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].unkA4 = 5;
    } else {
        gObjects[gCurrentParsedObject].unkA4 = 6;
    }
    gObjects[gCurrentParsedObject].unk132 = 0;
}

void func_800956F0(void) {
    UNUSED s32 pad[2];

    if (gObjects[gCurrentParsedObject].unk132 == 0) {
        gObjects[gCurrentParsedObject].unk132 = 1;
        gObjects[gCurrentParsedObject].unkA8 = 0;
        gObjects[gCurrentParsedObject].unk3C = (f32) func_80014E80(0x168);
        gObjects[gCurrentParsedObject].unk44 = 0.0f;
        gObjects[gCurrentParsedObject].unk40 = 0.0f;
        gObjects[gCurrentParsedObject].unk48 = 0.0f;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x47, &D_8011B8E0);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 0U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        gObjects[gCurrentParsedObject].unkA6 = (s16) (s32) func_80015538((f32) gObjects[gCurrentParsedObject].unkA6, -10.0f);
    }
    gObjects[gCurrentParsedObject].Rot.y = func_80015538(gObjects[gCurrentParsedObject].Rot.y, 4.0f);
}

void func_800959F0(void) {
    func_8002B0E4(gCurrentParsedObject);
}

void func_80095A20(void) {
    if (gObjects[gCurrentParsedObject].unk132  == 0) {
        gObjects[gCurrentParsedObject].unk132  = 1;
        gObjects[gCurrentParsedObject].unk108  = 0x50;
    }

    gObjects[gCurrentParsedObject].Vel.x =
    gObjects[gCurrentParsedObject].Vel.y =
    gObjects[gCurrentParsedObject].Vel.z = 0.0f;

    func_8001BB34(gCurrentParsedObject, !(gObjects[gCurrentParsedObject].unk108  & 1));
    if (gObjects[gCurrentParsedObject].unk108  == 1) {
        gObjects[gCurrentParsedObject].unk132  = 0;
        gObjects[gCurrentParsedObject].unkA4  = 1;
    }
}


void func_80095C30(void) {
    if (gObjects[gCurrentParsedObject].unk132  == 0) {
        gObjects[gCurrentParsedObject].unk132  = 1;
        gObjects[gCurrentParsedObject].unkA6  = 0x1E;
        gObjects[gCurrentParsedObject].unk44  = 0.0f;
        gObjects[gCurrentParsedObject].unk48 = 0.0f;
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);

    gObjects[gCurrentParsedObject].unkA6 -= 1;
    if (gObjects[gCurrentParsedObject].unkA6  == 0) {
        gObjects[gCurrentParsedObject].unk132 = 0;
        gObjects[gCurrentParsedObject].unkA4 = 1;
    }
}

void func_80095E14(void) {
    gObjects[gCurrentParsedObject].Rot.y = func_80015538(gObjects[gCurrentParsedObject].Rot.y, 4.0f);
}

void func_80095E94(void) {
    UNUSED s32 sp24;

    sp24 = func_80027464(1, &D_80113400, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, 0.0f);
}

void func_80095F08(void) {
    struct ObjectStruct *sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    if (sp4->unkA6 != 0) {
        sp4->unkA6 -= 1;
    }
    if (sp4->unkA8 != 0) {
        sp4->Pos.y = sp4->Pos.y + D_801147F8[sp4->unkA8];
        sp4->unkA8 += 1;
        if (sp4->unkA8 >= 0xA) {
            sp4->unkA8 = 0;
        }
    }
}

void func_80095FF8(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011340C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA;
    }
}

void func_800960B4(void) {
    if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_8009612C(struct ObjectStruct *arg0) {
    if (D_801765D9[arg0->unkA6].unk[0] == 0) {
        func_8001B6BC(gCurrentParsedObject, 0, 0.0f);
    } else {
        func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
    }
}

void func_800961A8(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AB, &D_80116934);
    }
    func_8009612C(sp24);
}


void func_80096254(void) {
    struct ObjectStruct* sp24;


    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk108 = 0x20;
        func_800175F0(gCurrentParsedObject, 0, 0x61, -1, 0);
    }
    if (sp24->unk108 == 1) {
        D_801765D8[sp24->unkA6].unk[1] ^= 1;
        func_8009612C(sp24);
        sp24->unkA4 = 1;
    }
}

void func_80096350(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {
        case 1:
            func_800961A8();
            break;
        case 2:
            func_80096254();
            break;
    }
}

void func_800963DC(void) {
    func_80027464(1, &D_80113418, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
}

void func_80096454(void) {
    if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_800964CC(struct ObjectStruct *arg0) {
    if (D_8016E328 == 0) {
        func_8001B6BC(gCurrentParsedObject, 0, 0.0f);
        func_8001BBDC(gCurrentParsedObject, 1);
    } else {
        func_8001BBDC(gCurrentParsedObject, 0);
    }
}

void func_80096540(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AD, &D_8011693C);
        func_800964CC(sp24);
    }
}

void func_800965EC(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk108 = 0x20;
        D_8016E328 ^= 1;
        func_800964CC(sp24);
        func_800175F0(gCurrentParsedObject, 0, 0x61, -1, 0);
    }
    if (sp24->unk108 == 1) {
        sp24->unkA4 = 1;
    }
}

void func_800966D4(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {                              /* irregular */
        case 1:
            func_80096540();
            break;
        case 2:
            func_800965EC();
            break;
    }
}

void func_80096760(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113424, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkAE = D_80165100->unkE;
    }
}

void func_8009681C(void) {
    if (D_80177A64 == 1) {
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_80096894(struct ObjectStruct *arg0) {
    if (arg0->unkA6 == 0) {
        func_8001B6BC(gCurrentParsedObject, 0, 0.0f);
    } else {
        func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
    }
}

void func_80096900(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AC, &D_80116938);
    }
    func_80096894(sp24);
}


void func_800969AC(void) {
    struct ObjectStruct* sp24;
    s32 sp20;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk108 = 0x20;
        func_800175F0(gCurrentParsedObject, 0, 0x61, -1, 0);
    }
    if (sp24->unk108 == 1) {
        sp24->unkA6 ^= 1;
        func_80096894(sp24);
        sp24->unkA4 = 1;
        sp20 = 0xE;

        while (TRUE) {
            sp20 = func_80026E58(0x5A, sp20);

            if (sp20 == -1) {
                break;
            }

            if (gObjects[sp20].unkAE == sp24->unkAE) {
                if (gObjects[sp20].unkA4 == 1) {
                    gObjects[sp20].unkA4 = 2;
                } else {
                    gObjects[sp20].unkA4 = 1;
                }
                gObjects[sp20].unk132 = 0;
                break;
            }
            sp20 += 1;
        }
    }
}

void func_80096BC8(void) {

    switch (gObjects[gCurrentParsedObject].unkA4) {                              /* irregular */
        case 1:
            func_80096900();
            break;
        case 2:
            func_800969AC();
            break;
    }
}

void func_80096C54(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_8011361C, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, 0.0f);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA * 0x3C;
        if (D_80165100->unkC < 4) {
            gObjects[sp24].unk3C = D_80114820[D_80165100->unkC];
            gObjects[sp24].unkAC = 0;
        } else if (D_80165100->unkC < 6) {
            gObjects[sp24].unk40 = D_80114820[D_80165100->unkC];
            gObjects[sp24].unkAC = 1;
        } else {
            gObjects[sp24].unkAC = 2;
        }

        gObjects[sp24].unkA8 = gObjects[sp24].unkA6;
        gObjects[sp24].unk3C = func_80015538(gObjects[sp24].unk3C, 180.0f);
        gObjects[sp24].unk40 = func_80015538(gObjects[sp24].unk40, 180.0f);
        gObjects[sp24].unkAE = D_80165100->unkE;
        func_8001ABF4(sp24, 0, 0, &D_8011B92C);
    }
}

void func_80096F88(void) {
    struct ObjectStruct *sp4;

    sp4 = &gObjects[gCurrentParsedObject];
    sp4->Vel.x = sp4->Vel.y = sp4->Vel.z = 0.0f;
}

void func_80096FF8(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];
    if (sp24->unk132 == 0) {
        sp24->unk132 += 1;
        sp24->unk44 = 4.0f;
    }
    if (sp24->unkAC == 0) {
        sp24->unk40 = 0.0f;
        func_80029D8C(gCurrentParsedObject);
        sp24->Vel.y = 0.0f;
    } else if (sp24->unkAC == 1) {
        sp24->unk3C = 0.0f;
        func_80029D8C(gCurrentParsedObject);
        sp24->Vel.z = 0.0f;
        sp24->Vel.x = sp24->Vel.z;
    } else {
        sp24->Vel.x = sp24->Vel.y = sp24->Vel.z = 0.0f;
    }
    if (sp24->unkAC < 2) {
        sp24->unkA8 = (s16) (s32) ((f32) sp24->unkA8 - sp24->unk44);
        if (sp24->unkA8 <= 0) {
            sp24->unkA8 = sp24->unkA6;
            sp24->unk3C = func_80015538(sp24->unk3C, 180.0f);
            sp24->unk40 = func_80015538(sp24->unk40, 180.0f);
        }
    }
}

void func_80097244(void) {
    switch (gObjects[gCurrentParsedObject].unkA4) {                              /* irregular */
        case 1:
            func_80096F88();
            break;
        case 2:
            func_80096FF8();
            break;
    }
}

void func_800972D0(void) {
    s32 sp24;

    sp24 = func_80027464(1, &D_80113640, (f32) D_80165100->unk2, (f32) D_80165100->unk4, (f32) D_80165100->unk6, (f32) D_80165100->unk8);
    if (sp24 != -1) {
        gObjects[sp24].unkA6 = D_80165100->unkA;
    }
}

void func_8009738C(void) {
    if ((D_80177A64 == 1) && (gObjects[gCurrentParsedObject].unkA4 == 1)) {
        gObjects[gCurrentParsedObject].unkA4 = 2;
        gObjects[gCurrentParsedObject].unk132 = 0;
    }
}

void func_80097438(struct ObjectStruct *arg0) {
    if (arg0->unk132 == 0) {
        arg0->unk132 += 1;
        func_8001C0EC(gCurrentParsedObject, 0, 0, 0x1AC, &D_80116938);
        func_8001BBDC(gCurrentParsedObject, 1);
    }
}

void func_800974C0(struct ObjectStruct *arg0) {
    s32 sp24;

    if (arg0->unk132 == 0) {
        arg0->unk132 += 1;
        arg0->unk108 = 0x20;
        func_8001BBDC(gCurrentParsedObject, 0);
        func_800175F0(gCurrentParsedObject, 0, 0x61, -1, 0);
    }

    if (arg0->unk108 == 1) {
        func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
        arg0->unkA4 = 3;
        sp24 = 0xE;
        while (TRUE) {
            sp24 = func_80026E58(0x54, sp24);

            if (sp24 == -1) {
                break;
            }

            if (gObjects[sp24].unkA6 == arg0->unkA6) {

                gObjects[sp24].unkA8 = 1;
                break;

            }

            sp24++;
        }
    }
}

void func_80097634(struct ObjectStruct *arg0) {
    func_8001B6BC(gCurrentParsedObject, 0, 14.0f);
}

void func_8009766C(void) {
    struct ObjectStruct *sp24;

    sp24 = &gObjects[gCurrentParsedObject];

    switch (sp24->unkA4) {
        case 1:
            func_80097438(sp24);
            break;
        case 2:
            func_800974C0(sp24);
            break;
        case 3:
            func_80097634(sp24);
            break;
    }
}

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


void func_800A8500(void) {
    if ((D_80177A64 == 0) || (D_80177A64 == 1)) {
        gObjects[gCurrentParsedObject].unk108 = 0;
        func_8002B0E4(gCurrentParsedObject);
    }
}

void func_800A8580(void) {
    union {
        float x;
        float y;
        float z;
        float w;
    } cords;

    struct ObjectStruct *sp44;
    sp44 = &gObjects[gCurrentParsedObject];
    if (sp44->unk132 == 0) {
        sp44->unk132 = 1;
        sp44->unk44 = 0.0f;
        sp44->unk3C = func_80015538((f32) (func_80014E80(0x165) + 1), 1.0f);
        sp44->unk40 = 270.0f;
        sp44->unk48 = 0.0f;
        func_80029EF8(gCurrentParsedObject, 0.0f, 4.0f);
        func_800272E8(gCurrentParsedObject);
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
        sp44->unk44 = 20.0f;
    }
    func_80029C40(gCurrentParsedObject);
    sp44->Rot.y = func_80015538(sp44->Rot.y, 20.0f);
    if (func_80029018(gCurrentParsedObject, 3U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
        if (D_801651A0 & 0x80) {
            func_8002B0E4(gCurrentParsedObject);
            return;
        }
    }
    if (func_80029F58(gCurrentParsedObject, 0.0f, 8.0f, 0.0f, 60.0f) == 1) {
        sp44->unkA4 = 2;
        sp44->unk132 = 0;
        if (D_80177740[D_801776E0 & 1] == 0xF5) {
            func_8002B0E4(gCurrentParsedObject);
            return;
        }
        func_80016C54(sp44->Pos.x, sp44->Pos.y, sp44->Pos.z, &cords.x, &cords.y, &cords.z, &cords.w);
        if (cords.w > 45.0f) {
            func_8002B0E4(gCurrentParsedObject);
        }
    }
}

void func_800A8858(void) {
    struct ObjectStruct *sp2C;

    sp2C = &gObjects[gCurrentParsedObject];
    if (sp2C->unk132 == 0) {
        sp2C->unk132 = 1;
        sp2C->unk44 = 3.0f;
        sp2C->unk48 = 0.0f;
        sp2C->unk40 = 0.0f;
        sp2C->unk108 = 1;
        sp2C->unkA6 = 0;
    }
    if (func_80028FA0(gCurrentParsedObject) != 0) {
        func_80029B60(gCurrentParsedObject);
    } else if (!(sp2C->unkA6 & 0x1F)) {
        sp2C->unk3C = func_80015538(sp2C->unk3C, (f32) func_80014E80(-0x14));
        sp2C->unk3C = func_80015538(sp2C->unk3C, 180.0f);
    }
    func_80029C40(gCurrentParsedObject);
    func_80029D04(gCurrentParsedObject);
    if (func_80029018(gCurrentParsedObject, 1U, 30.0f, 0.0f, 0.0f, 0.0f) != 0) {
        func_80029824(gCurrentParsedObject, func_800297DC());
    }
    func_800C00F4(sp2C, 8.0f);
    sp2C->Rot.y = sp2C->unk3C;
    sp2C->unkA6 += 1;
}

void func_800A8A58(void) {
    struct ObjectStruct *sp2C;
    struct ObjectStruct *sp28;

    sp28 = &gObjects[gCurrentParsedObject];
    if (sp28->unkE6[0] != -1) {
        sp2C = &gObjects[sp28->unkE6[0]];
        sp28->Pos.x = sp2C->Pos.x;
        sp28->Pos.y = sp2C->Pos.y;
        sp28->Pos.z = sp2C->Pos.z;
        sp28->unk3C = sp2C->unk3C;
        sp28->unk40 = sp2C->unk40;
        sp28->Rot.y = sp2C->Rot.y;
        func_80029C40(gCurrentParsedObject);
        func_80029D04(gCurrentParsedObject);
    } else {
        switch (sp28->unkA4) {                          /* irregular */
            case 1:
                func_800A8580();
                break;
            case 2:
                func_800A8858();
                break;
            default:
                func_800A8858();
                break;
        }
    }
}
