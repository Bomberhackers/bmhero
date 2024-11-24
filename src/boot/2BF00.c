#include "common.h"
#include "2BF00.h"


void func_8002B300(void) {
    f32 sp4;

    if (gActiveContButton & 0x2000) {
        if (gActiveContButton & 8) {
            gView.dist = gView.dist - 10.0f;
            if (gView.dist < 100.0f) {
                gView.dist = 100.0f;
            }
        }
        if (gActiveContButton & 4) {
            gView.dist = gView.dist + 10.0f;
        }
    } else {
        if (gActiveContButton & 2) {
            sp4 = (f32) ((f64) gView.rot.y + 2.0);
            gView.rot.y = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
        }
        if (gActiveContButton & 1) {
            sp4 = (f32) ((f64) gView.rot.y + D_8004BFB8);
            gView.rot.y = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
        }
        if (gActiveContButton & 8) {
            sp4 = (f32) ((f64) gView.rot.x + 2.0);
            gView.rot.x = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
        }
        if (gActiveContButton & 4) {
            sp4 = (f32) ((f64) gView.rot.x + D_8004BFC0);
            gView.rot.x = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
        }
    }
}

void func_8002B640(f32 arg0, f32 arg1, f32 arg2) {
    gView.at.x = arg0;
    gView.at.y = arg1;
    gView.at.z = arg2;
}

void func_8002B670(void) {
    s32 sp4;

    
    for (sp4 = 0; sp4 < 0x81; sp4++) {
        D_800576A8[sp4].unk0 = -1;
    } 
    
    for (sp4 = 0; sp4 < 0x80; sp4++) {
        if (D_8017796C[sp4].unk0 == -1) {
            break;
        }
        D_800576A8[sp4].unk0 = D_8017796C[sp4].unk0;
        D_800576AA[sp4].unk0 = D_8017796C[sp4].unk2;
        D_800576AC[sp4].unk0 = D_8017796C[sp4].unk4;
        D_800576AE[sp4].unk0 = D_8017796C[sp4].unk6;
        D_800576B0[sp4].unk0 = D_8017796C[sp4].unk8;
        D_800576B2[sp4].unk0 = D_8017796C[sp4].unkA;
        D_800576B4[sp4].unk0 = D_8017796C[sp4].unkC;
        D_800576B6[sp4].unk0 = D_8017796C[sp4].unkE;
    }
    D_8017796C = &D_800576A8;
}


s32 func_8002B830(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 0x80; sp4++){
        if (D_800576A8[sp4].unk0 == -1) {
            return sp4;
        }
    }
    return -1;
}

s32 func_8002B894(s32 arg0) {
    s32 sp4;

    for(sp4 = 0xE; sp4 < 0x4E; sp4++) {
        if ((gObjects[sp4].unkA4) && 
            (gObjects[sp4].unkE4 == D_800576A8[arg0].unk0) && 
            (gObjects[sp4].Pos.x == D_800576A8[arg0].unk2) && 
            (gObjects[sp4].Pos.y == D_800576A8[arg0].unk4) && 
            (gObjects[sp4].Pos.z == D_800576A8[arg0].unk6)) {
            
            return sp4;
        }
    }

    return -1;
}


void func_8002B9B8(void) {
    s32 sp1C;

    for (sp1C = 0xE; sp1C < 0x4E; sp1C++) {
        if (gObjects[sp1C].unkA4 != 0) {
            func_8001BB34(sp1C, 0);
        }
    } 
}

s32 func_8002BA34(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 0x80; sp4++) {
        if ((D_800576A8[sp4].unk0 != -1) && (D_800576A8[sp4].unk2 != 0x7530) && (D_800576A8[sp4].unk4 != 0x7530) && (D_800576A8[sp4].unk6 != 0x7530)) {
            return 0;
        }
    }
    return 1;
}



void func_8002BAC8(void) {
    u16 sp6;
 
    if (D_800576A2 != 0) {
        D_800576A2 -= 1;
    }
    sp6 = 0;
    if (D_800576A2 == 0) {
        if (gActiveContPressed & 0x100) {
            D_800576A2 = 0xF;
            sp6 = 0x100;
        } else if (gActiveContPressed & 0x200) {
            D_800576A2 = 0xF;
            sp6 = 0x200;
        } else if (gActiveContPressed & 0x800) {
            D_800576A2 = 0xF;
            sp6 = 0x800;
        } else if (gActiveContPressed & 0x400) {
            D_800576A2 = 0xF;
            sp6 = 0x400;
        } else if (gActiveContPressed & 0x8000) {
            D_800576A2 = 0xF;
            sp6 = 0x8000;
        } else if (gActiveContPressed & 0x4000) {
            D_800576A2 = 0xF;
            sp6 = 0x4000;
        }
    } else if (gActiveContButton & 0x100) {
        if (D_800576A2 == 1) {
            sp6 = 0x100;
            D_800576A2 = 2;
        }
    } else if (gActiveContButton & 0x200) {
        if (D_800576A2 == 1) {
            sp6 = 0x200;
            D_800576A2 = 2;
        }
    } else if (gActiveContButton & 0x800) {
        if (D_800576A2 == 1) {
            sp6 = 0x800;
            D_800576A2 = 2;
        }
    } else if (gActiveContButton & 0x400) {
        if (D_800576A2 == 1) {
            sp6 = 0x400;
            D_800576A2 = 2;
        }
    } else if (gActiveContButton & 0x8000) {
        if (D_800576A2 == 1) {
            sp6 = 0x8000;
            D_800576A2 = 2;
        }
    } else if (gActiveContButton & 0x4000) {
        if (D_800576A2 == 1) {
            sp6 = 0x4000;
            D_800576A2 = 2;
        }
    } else {
        D_800576A2 = 0;
    }
    D_800576A0 = sp6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002BE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002C144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002C184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002C92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002CA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002CF78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002D080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002D128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002D538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002D768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002D8FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002D968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002D9D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002DCA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002E23C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002E524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002E6E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002E8B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002EA68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002EB58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002EEB8.s")

void func_8002EF00(void) {
    sprintf(&gDebugTextBuf, &D_8004BF98);
    debug_print_xy(0x20, 0x10);
    sprintf(&gDebugTextBuf, &D_8004BFA4);
    debug_print_xy(0x58, 0x64);
}


void func_8002EF60(void) {
    func_8005F96C(0xFFU, 0xFFU, 0xFFU);
    switch (D_80057688) {                           /* irregular */
    case 0:
        func_8002EB58();
        break;
    case 1:
        func_8002EEB8();
        break;
    case 2:
        func_8002EF00();
        break;
    }
    func_8005FA90();
}


void func_8002F000(void) {
    struct UnkStruct80108238* sp1C;
    s32 i;

    D_80057688 = 0;
    D_80057689 = 0;
    D_8005768A = 1;
    D_80057690 = 0x20;
    D_8005769E = 0;
    D_80057692 = 0;
    D_80057694 = 0;
    D_80057696 = 0;
    D_80057698 = 0;
    D_8005769A = 0;
    D_8005769C = 0;
    D_800576A2 = 0;

    for(i = 0; i < 0x2BC; i++) {
        gFileArray[i].ptr = NULL;
    }
    func_8001E954((s32* )0x8024C000);
    func_8001E98C(0, (u32)&unk_bin_0_2_ROM_START, (u32)&unk_bin_0_2_ROM_END);
    gPlayerObject = gObjects;
    func_80019C84();
    func_80019D2C();
    func_8001A258();
    func_80088B80();
    func_8001E954((s32* )0x802D0000);
    sp1C = D_80108238[gCurrentLevel];
    DecompressFile(0x1C, sp1C->unk4, sp1C->unk8);
    func_8001EB68(0x1B, (void* ) sp1C->unkC, (void* ) sp1C->unk10);
    func_80000FF4(gCurrentLevel);
    func_8006707C();
    func_800695A0();
    func_8006E088();
    func_8002629C();
    gLevelInfo[gCurrentLevel]->unk24();
    gLevelInfo[gCurrentLevel]->unk28();
    func_8002B670();
    D_8005768C = func_8001E96C();
    func_8002D538();
    gPlayerObject->Pos.x = D_80108238[gCurrentLevel]->unk0[0];
    gPlayerObject->Pos.y = D_80108238[gCurrentLevel]->unk0[1];
    gPlayerObject->Pos.z = D_80108238[gCurrentLevel]->unk0[2];
    gPlayerObject->Rot.x = 0.0f;
    gPlayerObject->Rot.y = 0.0f;
    gPlayerObject->Rot.z = 0.0f;
    gCameraType = 1;
    func_80076458();
    func_8001D244(-1, -1, -1, 0x10);
    func_8001D284();
}


void func_8002F32C(void) {
    f32 sp6C;
    Matrix sp2C;


    UpdateActiveController(0U);
    if ((gCameraType == 1) || (gCameraType == 5)) {
        guRotateF(sp2C, gView.rot.y, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(sp2C, gActiveContStickX, 0.0f, gActiveContStickY, &gActiveContStickX, &sp6C, &gActiveContStickY);
    }
    func_8002BAC8();
    func_8002EA68();
    if (D_80057688 == 0) {
        func_8002D768();
        func_8002D128();
        func_8002DCA8();
        func_8002D9D4();
    } else if (D_80057688 == 1) {
        func_8002E524();
        func_8002E23C();
    } else if (D_80057688 == 2) {
        func_8002E6E8();
    }
    func_80026548();
    func_8002BE04();
    func_800663EC();
    func_800654AC();
    func_8002B300();
    if (D_80057688 == 0) {
        func_8002B640(gPlayerObject->Pos.x, gPlayerObject->Pos.y + 100.0f, gPlayerObject->Pos.z);
    } else if ((D_80057688 == 1) && (D_800576A8[D_80057692].unk0 != -1)) {
        if ((D_800576A8[D_80057692].unk2 != 0x7530) && (D_800576A8[D_80057692].unk4 != 0x7530) && (D_800576A8[D_80057692].unk6 != 0x7530)) {
            func_8002B640((f32) D_800576A8[D_80057692].unk2, (f32) D_800576A8[D_80057692].unk4, (f32) D_800576A8[D_80057692].unk6);
        }
    }
    func_8001994C();
}

void func_8002F598(void) {
    UNUSED u16 pad;
    UNUSED u16 pad1;
    UNUSED u16 sp3E;

    func_8001D4D0();
    func_8001D638(1, 0x3C, 0x3C, 0x3C);
    guPerspective(D_8016E104->unk00, &pad, 50.0f, 1.3333334f, 100.0f, D_8004C00C, 1.0f);
    gSPPerspNormalize(gMasterDisplayList++, pad);
    guLookAt(&D_8016E104->unk00[2], gView.eye.x, gView.eye.y, gView.eye.z, gView.at.x, gView.at.y, gView.at.z, gView.up.x, gView.up.y, gView.up.z);
    gSPMatrix(gMasterDisplayList++, D_8016E104, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    
    D_8016E3A4 = 0;
    func_8002D8FC();
    func_8001C464();
    func_8001C70C();
    func_8002D968();
    func_8001C5B8();
    func_8001C96C();
    func_8002EF60();
}

void func_8002F738(void) {
    func_8001ECB8();
    D_8016526C = &func_8002F598;
    D_80165274 = &func_8002F32C;
    func_8002F000();
    func_80000964();
}
