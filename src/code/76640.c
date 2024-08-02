#include <ultra64.h>

//RODATA START unk_FF0F0_rodata

extern f64 D_8010CD50;

extern f64 D_8010CD60;
extern f64 D_8010CD68;
extern f64 D_8010CD70;
extern f64 D_8010CD78;

//RODATA END

s32 func_80084120(f32 arg0, f32 arg1, f32 arg2) {
    f32 sp4;

    sp4 = arg1 - arg0;
    if (sp4 < 0.0f) {
        sp4 += 360.0f;
    }
    if ((sp4 < arg2) || ((360.0f - arg2) < sp4)) {
        return 0;
    }
    if (sp4 >= 180.0f) {
        return -1;
    }
    return 1;
}

void func_800841E8(void) {
    if ((gCurrentLevel == 0x28) || (gCurrentLevel == 0x29)) {
        D_8016E110 = 2;
        D_8016E112 = 0x3C;
    } else {
        D_8016E110 = 0;
        D_8016E112 = 0;
    }
    D_8016E115 = 0;
}

void func_8008424C(void) {
    if ((gCurrentLevel == 0x28) || (gCurrentLevel == 0x29)) {
        if (D_8016E110 == 1) {
            D_8016E112 = 0xB4;
        }
        else if (D_8016E110 == 2) {
            D_8016E112 = 0x3C;
        }
    }
}

void func_800842C0(void) {
    if (D_8016E110 == 1) {
        if (D_8016E112 != 0) {
            D_8016E112 -= 1;
        }
        if ((D_8016E112 == 1) || (D_8016E112 == 0xF) || (D_8016E112 == 0x1E) || (D_8016E112 == 0x2D)) {
            func_800178D4(-1, 0, 0x28, -1, 0);
        }
    } else if (D_8016E110 == 2) {
        if (D_8016E112 == 0) {
            D_8016E110 = 1;
            D_8016E112 = 0xB4;
        } else {
            D_8016E112 -= 1;
        }
    }
}

void func_800843CC(f32 arg0, f32 arg1, f32 arg2) {
    func_80067748(arg0, arg1, arg2);
    func_800670E8();
    func_80068CC4(arg0, arg1, arg2);
    func_80069314();
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80084430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80084BD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80085424.s")

void func_800857B0(void) {
    func_80085424();
    gObjects[D_80165270].unkA6 = 1;
}

void func_80085804(void) {
    func_80085424();
    gObjects[D_80165270].unkA6 = 1;
    gObjects[D_80165270].unkB6 = 1;
}

void func_80085884(void) {
    s32 sp1C;
    s32 sp18;

    if (D_8016E238 == 0) {
        if (D_80165270 != -1) {
            if ((gObjects[D_80165270].unkA4 == 0) || (gObjects[D_80165270].unkE4 != D_80165280)) {
                sp1C = -1;
            } else {
                sp1C = (s32) D_80165270;
            }
        } else {
            if ((gObjects[D_8016E2A8].unkA4 == 0) || (gObjects[D_8016E2A8].unkE4 != D_8016E2B8)) {
                sp1C = -1;
            } else {
                sp1C = (s32) D_8016E2A8;
            }
        }
        if (sp1C != -1) {
            D_80124D90[gObjects[sp1C].unkE4].routine3();
        }
    }
    else
    {
        sp18 = D_8016E240 - 2;
        if(D_801779B0[sp18] != -1)
        {
            if ((gObjects[D_801779B0[sp18]].unkA4 == 0) || gObjects[D_801779B0[sp18]].unkE4 != D_801779C0[sp18]) {
            sp1C = -1;
            } else {
                sp1C = D_801779B0[sp18];
            }
        }
        else {
            sp1C = -1;
        }
        if (sp1C != -1) {
            D_80124D90[gObjects[sp1C].unkE4].routine3();
        }
    }
}

void func_80085B34(f32 arg0, f32 arg1) {
    s32 sp3C;

    func_800843CC(gPlayerObject->Pos.x + arg0, gPlayerObject->Pos.y, gPlayerObject->Pos.z + arg1);
    sp3C = D_801776E0 & 1;
    D_801651A8 = D_801776E0;
    D_801651AC = D_801776F0[sp3C];
    D_801651B0 = D_80177700[sp3C];
    D_801651B4 = D_80177710[sp3C];
    D_801651B8 = D_80177720[sp3C];
    D_801651BC = D_80177730[sp3C];
    D_801651C0 = D_80177760[sp3C];
    D_801651C4 = gPlayerObject->Pos.x + arg0;
    D_801651C8 = gPlayerObject->Pos.y;
    D_801651CC = gPlayerObject->Pos.z + arg1;
    D_801651D0 = gPlayerObject->unk3C;
    D_801651D4 = func_80015634(gActiveContStickX, -gActiveContStickY);
    func_80016A80(D_801651AC, 
        D_801651B0, D_801651B4, D_801651B8, 
       &D_801651D8[0], &D_801651D8[1], &D_801651D8[2], &D_801651D8[3]);
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80085D54.s")

void func_80086AD0(void) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    s32 sp20;
    UNUSED s32 sp30;

    D_8016E080 = 0;
    sp2C = gPlayerObject->Pos.x;
    sp28 = gPlayerObject->Pos.y;
    sp24 = gPlayerObject->Pos.z;
    if (D_8016523E == 4) {
        sp28 = (f32) ((f64) sp28 - D_8010CD50);
    }
    func_800843CC(sp2C, sp28, sp24);
    sp20 = D_801776E0 & 1;
    if (D_80177740[sp20] == 0xFF) {
        return;
    }
    else if (D_80177740[sp20] == 0xF8) {
        if (sp28 <= D_80177760[sp20]) {
            D_8016E080 = 2;
        }
    } else if (D_80177740[sp20] == 0xF7) {
        if (sp28 <= D_80177760[sp20]) {
            D_8016E080 = 1;
        }
    } 
    else if(((D_80177740[sp20] == 0xF5) || (D_80177740[sp20] == 0xD9)) && (sp28 <= D_80177760[sp20]))
    {
        if(D_80177750[sp20] == 0)
        {
            D_8016E080 = 3;
        }
        else if(D_80177750[sp20] == 1)
        {
            D_8016E080 = 4;
        }
        else
        {
            D_8016E080 = 5;
        }
    }
}

void func_80086D50(void) {
    Mtx_t sp120;
    Mtx_t spE0;
    Mtx_t spA0;
    Mtx_t sp60;
    Mtx_t sp20;
    
    guTranslateF((f32 (*)[4]) &sp120[0], gPlayerObject->Pos.x, gPlayerObject->Pos.y, gPlayerObject->Pos.z);
    guScaleF((f32 (*)[4]) &spE0[0], gPlayerObject->Scale.x, gPlayerObject->Scale.y, gPlayerObject->Scale.z);
    guRotateF((f32 (*)[4]) &spA0[0], gPlayerObject->Rot.x, 1.0f, 0.0f, 0.0f);
    guRotateF((f32 (*)[4]) &sp60[0], gPlayerObject->Rot.y, 0.0f, 1.0f, 0.0f);
    guRotateF((f32 (*)[4]) &sp20[0], gPlayerObject->Rot.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF((f32 (*)[4]) &sp20[0], (f32 (*)[4]) &sp60[0], (f32 (*)[4]) &sp20[0]);
    guMtxCatF((f32 (*)[4]) &sp20[0], (f32 (*)[4]) &spA0[0], (f32 (*)[4]) &sp20[0]);
    guMtxCatF((f32 (*)[4]) &sp20[0], (f32 (*)[4]) &spE0[0], (f32 (*)[4]) &sp20[0]);
    guMtxCatF((f32 (*)[4]) &sp20[0], (f32 (*)[4]) &sp120[0], (f32 (*)[4]) D_80177550);
}

void func_80086E70(f32* arg0, f32* arg1, f32* arg2) {
    guMtxXFMF((f32 (*)[4]) D_80177550, *arg0, *arg1, *arg2, arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80086ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80087694.s")

void func_80087994(void) {
    UNUSED s16 sp20;
    
    if ((gPlayerObject->unk108 >= 2) && (gPlayerObject->unk108 < 0x3D)) {
        gPlayerObject->unk108 -= 1;
    }
    if (D_8016E0D0 != 0) {
        return;
    }
    if (D_8016523E == 0) {
        func_8028AA70();
    } else if (D_8016523E == 1) {
        func_802838DC();
    } else if (D_8016523E == 2) {
        func_802823A4();
    } else if (D_8016523E == 3) {
        func_80281314();
    } else if (D_8016523E == 4) {
        func_8028117C_code_extra_4();
    } else if (D_8016523E == 5) {
        func_802860F8();
    } else if (D_8016523E == 6) {
        func_80282F24();
    }
    func_80086D50();
    func_80086ECC();
}

void func_80087B1C(void) {
    func_8001BB34(0, 0);
    func_8001BB34(1, 0);
    if (D_8016523E == 0) {
        func_8028ADB0();
    } else if (D_8016523E == 1) {
        func_80283A40();
    } else if (D_8016523E == 2) {
        func_802824DC();
    } else if (D_8016523E == 3) {
        func_802813E4();
    } else if (D_8016523E == 4) {
        func_802812AC();
    } else if (D_8016523E == 5) {
        func_80286374();
    } else if (D_8016523E == 6) {
        func_802831BC();
    }
    func_80086D50();
    func_80086ECC();
}

void func_80087C58(void) {
    if (D_8016E0D0 == 0) {
        if ((gPlayerObject->unk108 >= 2) && (gPlayerObject->unk108 < 0x3D)) {
            D_8016E250 += 1;
            if (D_8016E250 & 1) {
                return;
            }
        }
    }
    if (func_8001C1A8(0, 0) != 0) {
        func_8001838C();
        func_8001B014(0, 0);
        func_8001C384(0, 0);
    }
    if ((gPlayerArmWindObject->unkA4 != 0) && (func_8001C1A8(1, 0) != 0)) {
        func_8001838C();
        func_8001B014(1, 0);
        func_8001C384(1, 0);
    }
}

void func_80087D70(void) {
    if (func_8001C248(0, 3) != 0) {
        func_8001838C();
        func_8001B014(0, 3);
        func_8001C384(0, 3);
    }
    if ((gPlayerArmWindObject->unkA4 != 0) && (func_8001C248(1, 3) != 0)) {
        func_8001838C();
        func_8001B014(1, 3);
        func_8001C384(1, 3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_80087E14.s")

void func_80088094(void) {
    gLifeCount = 1;
    gMaxHealth = 4;
    gHealthCount = gMaxHealth;
    gBombCount = 0;
    gFireCount = 0;
    gGemCount = 0;
}

void func_800880E4(void) {
    gLifeCount = 3;
    gMaxHealth = 4;
    gHealthCount = gMaxHealth;
    gBombCount = 0;
    gFireCount = 0;
    gGemCount = 0;
}

void func_80088134(void) { //looks like the regular base stats
    gLifeCount = 3;
    gMaxHealth = 4;
    gHealthCount = gMaxHealth;
    gBombCount = 0;
    gFireCount = 0;
    gGemCount = 0;
}

void func_80088184(void) { //looks like the regular base stats
    gLifeCount = 3;
    gMaxHealth = 4;
    gHealthCount = gMaxHealth;
    gBombCount = 0;
    gFireCount = 0;
    gGemCount = 0;
}

void func_800881D4(void) {
    gHealthCount = gMaxHealth;
    if (gFireCount != 0) {
        gFireCount -= 1;
    }
    else if (gBombCount != 0) {
        gBombCount -= 1;
    }
}

void func_80088248(s32 arg0) {
    if (arg0 > 0) {
        gLifeCount += arg0;
        if ((s32) gLifeCount >= 99) {
            gLifeCount = 99;
        }
    }
    else if (gLifeCount != 0) {
        gLifeCount += arg0;
    }
}

void func_800882C8(void) {
    D_80165238 = gLifeCount;
    D_80165239 = gHealthCount;
    D_8016523A = gMaxHealth;
    D_8016523B = gBombCount;
    D_8016523C = gFireCount;
    D_8016523D = gGemCount;
}

void func_80088338(void) {
    gLifeCount = D_80165238;
    gHealthCount = D_80165239;
    gMaxHealth = D_8016523A;
    gBombCount = D_8016523B;
    gFireCount = D_8016523C;
    gGemCount = D_8016523D;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_800883A8.s")

void func_80088694(void) {
    func_8001A928(0);
    func_8001A928(1);
    gPlayerObject->Pos.x = D_8016E438;
    gPlayerObject->Pos.y = D_8016E43C;
    gPlayerObject->Pos.z = D_8016E440;
    gPlayerObject->Rot.y = D_8016E444;
    gPlayerObject->unk3C = gPlayerObject->Rot.y;
    gPlayerObject->unk108 = 1;
    func_80087E14();
    func_8006828C();
    func_80085B34(0, 0);
    if (D_8016523E == 0) {
        func_8028AF38();
    } else if (D_8016523E == 1) {
        func_80283BD4();
    } else if (D_8016523E == 2) {
        func_80282698();
    } else if (D_8016523E == 3) {
        func_802814CC();
    } else if (D_8016523E == 4) {
        func_80281440();
    } else if (D_8016523E == 5) {
        func_80286508();
    } else {
        func_80283344();
    }
}

void func_8008884C(s32 arg0) {
    func_8001A928(0);
    func_8001A928(1);
    func_8001BD44(0, 0, 0x10, gFileArray[0x223].ptr + D_80111880[arg0]);
    func_8001C0EC(0, 0, 0, 0x223, &D_80111888);
    gPlayerObject->unkE4 = 0x266;
    gPlayerObject->unkA4 = 1;
    func_80019448(0, 2, 0, 1);
    if (arg0 == 0) {
        func_8001ABF4(0, 0, 0, &D_80111A74);
        func_8001ABF4(0, 1, 0, &D_80111A74[0x3F]);
        func_8001ABF4(0, 2, 0, &D_80111A74[0x46]);
        func_8001ABF4(0, 3, 0, &D_80111A74[0x4D]);
    } else {
        func_8001ABF4(0, 0, 0, &D_80111A74[0x69]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/76640/func_800889A8.s")

void func_80088A88(s32 arg0) {
    s32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    D_8016523E = (s8) arg0;
    func_8001EC04();
    for(sp24 = 0; sp24 < 1000000; sp24++)
    {
        
    }
    sp20 = gPlayerObject->Pos.x;
    sp1C = gPlayerObject->Pos.y;
    sp18 = gPlayerObject->Pos.z;
    func_800883A8();
    func_80088694();
    gPlayerObject->Pos.x = sp20;
    gPlayerObject->Pos.y = sp1C;
    gPlayerObject->Pos.z = sp18;
    func_8001EBE8();
}
