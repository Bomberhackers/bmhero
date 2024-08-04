#include <ultra64.h>
#include "1050.h"

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80016D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80016D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80016DB4.s")

s32 func_80016DD4(void) {
    s32 i;

    for(i = 0; i < 1000000; i++) {
        
    }
    func_80003FE0(_38A1F0_ROM_START, 0, 0, 0, 0);
    func_8000ABEC(_229650_ROM_START, _229A60_ROM_START, _229A60_ROM_END, _230D50_ROM_START);
    func_80002E1C(0xC, 2, (void*)&D_8004D748, (void*)&D_80177A70, 0x493E0);
    func_80016D74(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80016E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80016EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/PlayTrack_WithVolLoop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80016FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80016FF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_800171E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_800175F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_800176F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_800177D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_800178D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_800179B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017B04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017CFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017DFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80017FD8.s")

s32 func_80017FF8(void) {
    Lights2 *sp4 = gLevelInfo[gCurrentLevel]->unk20;

    if (sp4) {
        gLightingSettings = *sp4;

        if ((gCurrentLevel == MAP_FREEZE_LAKE) || (gCurrentLevel == MAP_SNOWLAND)) {
            return 2;
        } else {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_800180C4.s")

void func_8001819C(void) {
    gLightingSettings = D_8004A590;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_800181F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001838C.s")

void func_800183E8(s32 r, s32 g, s32 b, s32 a, s32 arg4, s32 arg5) {
    gDPPipeSync(gMasterDisplayList++);
    gDPSetCycleType(gMasterDisplayList++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetCombineLERP(gMasterDisplayList++, TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, TEXEL0, 0, SHADE, 0, 0, 0, 0, 1);
    gDPSetRenderMode(gMasterDisplayList++, AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | G_RM_FOG_SHADE_A, AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
    gDPSetFogColor(gMasterDisplayList++, r, g, b, a);
    gSPFogFactor(gMasterDisplayList++, (0x1F400 / (arg5 - arg4)), ((-1 * arg4) + 0x1F4) * 0x100 / (arg5 - arg4));
    gDPSetTextureFilter(gMasterDisplayList++, G_TF_BILERP); 
    gDPSetTexturePersp(gMasterDisplayList++, G_TP_PERSP);
    gSPNumLights(gMasterDisplayList++, 2);
    gSPLight(gMasterDisplayList++, &gLightingSettings.l[0], 1);
    gSPLight(gMasterDisplayList++, &gLightingSettings.l[1], 2);
    gSPLight(gMasterDisplayList++, &gLightingSettings.a, 3);
}

void func_80018794(s32 r, s32 g, s32 b, s32 a, s32 arg4, s32 arg5) {
    gDPPipeSync(gMasterDisplayList++);
    gDPSetCycleType(gMasterDisplayList++, G_CYC_2CYCLE);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetCombineLERP(gMasterDisplayList++, TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
    gDPSetFogColor(gMasterDisplayList++, r, g, b, a);
    gSPFogFactor(gMasterDisplayList++, (0x1F400 / (arg5 - arg4)), ((-1 * arg4) + 0x1F4) * 0x100 / (arg5 - arg4));
    gDPSetAlphaCompare(gMasterDisplayList++, G_AC_NONE);
    gDPSetAlphaDither(gMasterDisplayList++, G_AD_DISABLE);
    gDPSetColorDither(gMasterDisplayList++, G_CD_DISABLE);
    gDPSetBlendColor(gMasterDisplayList++, 0x00, 0x00, 0x00, 0x01);
    gDPSetTextureFilter(gMasterDisplayList++, G_TF_BILERP); 
    gDPSetTexturePersp(gMasterDisplayList++, G_TP_PERSP);
    gSPNumLights(gMasterDisplayList++, 2);
    gSPLight(gMasterDisplayList++, &gLightingSettings.l[0], 1);
    gSPLight(gMasterDisplayList++, &gLightingSettings.l[1], 2);
    gSPLight(gMasterDisplayList++, &gLightingSettings.a, 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80018C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80018CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80018EEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80019050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_800193CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80019448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_800194C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80019510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001994C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80019B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80019BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80019C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80019CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80019D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_80019D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001A258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001A2A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001A300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001A488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001A5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001A738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001A7E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001A88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001A928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001A958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001A988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001AA60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001AB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001AB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001ABC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001ABF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001AD6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B44C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B4AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B62C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B6AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B6BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B7E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B8D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001B9F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001BA7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001BB04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001BB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001BBDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001BC84.s")

void func_8001BD44(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp1C;

    if (gObjects[arg0].Unk140[arg1] != -1) {
        return;
    }
    sp1C = func_8001A988();
    gObjects[arg0].Unk140[arg1] = sp1C;
    D_80165290[sp1C].unk0 = arg3;
    func_8001A2A0();
    D_8016E3AC = func_800122F0(arg3);
    D_80165290[sp1C].unk1C = func_80010408(arg3, arg2);
    func_8001A300(sp1C);
}

void func_8001BE6C(s32 objID, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp1C;

    gObjects[objID].unkFE = arg2;
    sp1C = gObjects[objID].Unk140[arg1];
    func_8001A488(sp1C);
    if (D_80165290[sp1C].unk20 != 0) {
        func_80011DD0(D_80165290[sp1C].unk20);
        D_80165290[sp1C].unk20 = 0;
    }
    if (arg3 != 0) {
        if (D_8016E3AC != NULL) {
            func_80013A00(D_8016E3AC);
            D_8016E3AC = NULL;
        }
        D_8016E3AC = func_800122F0(arg3);
        D_80165290[sp1C].unk20 = func_8001191C(D_80165290[sp1C].unk1C, 0);
        D_80165290[sp1C].unk15 = 0;
    } else {
        D_80165290[sp1C].unk20 = func_8001191C(D_80165290[sp1C].unk1C, arg2);
        D_80165290[sp1C].unk15 = arg2;
    }
    D_80165290[sp1C].unk14 = arg2;
    D_80165290[sp1C].unk24 = 0.0f;
    D_80165290[sp1C].unk16 = 0;
    func_8001A300(sp1C);
}

void func_8001C0EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u32* arg4) {
    func_8001BE6C(arg0, arg1, arg2, (void*)&gFileArray[arg3].ptr[arg4[arg2]]);
}

void func_8001C158(s32 arg0, s32 arg1, s32 arg2) {
    func_8001BE6C(arg0, arg1, 0, (void*)gFileArray[arg2].ptr);
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001C1A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001C248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001C300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001C374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001C384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001C464.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001C5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001C70C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001C96C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001CAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001CD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001CD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001CD88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001CDF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001CEF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001D000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001D1D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001D1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001D244.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001D284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001D2C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001D2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001D3CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001D440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001D4D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001D638.s")

void func_8001D814(void) {
    struct UnkStruct8016E10C* sp1C;
    struct UnkStruct8016E10C* sp18 = D_8016E10C;
    sp1C = sp18;

    sp1C->task.t.data_ptr = (s32) ((u32)D_8016E104 + 0x80E0);
    sp1C->task.t.data_size = (s32) (((s32) (((u32)gMasterDisplayList - (u32)D_8016E104 - 0x80E0)) >> 3) << 3);
    sp1C->task.t.type = 1;
    sp1C->task.t.flags = 0;
    sp1C->task.t.ucode_boot = (u64*)rspbootTextStart;
    sp1C->task.t.ucode_boot_size = (u32)rspbootTextEnd - (u32)rspbootTextStart;
    sp1C->task.t.ucode = (u64*)rspbootTextEnd; // this is probably F3DEX Data start. TODO: Rename
    sp1C->task.t.ucode_size = 0x1000;
    sp1C->task.t.ucode_data = (u64*)gspF3DEX_fifoTextStart_bin;
    sp1C->task.t.ucode_data_size = 0x800;
    sp1C->task.t.dram_stack = D_801D04B0;
    sp1C->task.t.dram_stack_size = 0x400;
    sp1C->task.t.output_buff = (void*)&D_801C1A50;
    sp1C->task.t.output_buff_size = (void*)((u32)&D_801C1A50 + 0xEA60);
    sp1C->task.t.yield_data_ptr = &D_801C0E50;
    sp1C->task.t.yield_data_size = 0xC00;
    sp1C->unk0 = 0;
    sp1C->unk8 = 0x63;
    sp1C->unk50 = &D_8016E0B8;
    sp1C->unk54 = &sp18->unk18148;
    sp1C->unkC = sp18->unk18168;
    osSendMesg(D_8004D9D0, sp1C, 1);
}

void func_8001D9E4(void* arg0) {
    func_8005F0F4();
    D_8016E10C = arg0;
    D_8016E104 = (void*)((u32)D_8016E10C + 0x68);
    gMasterDisplayList = (void*)((u32)D_8016E10C + 0x8148);
    gSPSegment(gMasterDisplayList++, 0x00, 0x00000000);
    gSPSegment(gMasterDisplayList++, 0x01, osVirtualToPhysical(gFileArray[0].ptr));
    gSPDisplayList(gMasterDisplayList++, D_1000C68);

    if(D_80165254 == 1) {
        gSPDisplayList(gMasterDisplayList++, D_1000B78);
    }

    gSPDisplayList(gMasterDisplayList++, D_1000C50);
    if (D_80165254 == 0) {
        if ((D_8016E0A8 != 0) && (D_8016526C != NULL)) {
            D_8016526C();
        }
    } else if (D_80165254 == 2) {
        D_80165254 = 0;
    } else {
        D_80165254 += 1;
    }
    func_8001D3CC();
    gDPFullSync(gMasterDisplayList++);
    gSPEndDisplayList(gMasterDisplayList++);

    osWritebackDCacheAll();
    func_8001D814();
}

void func_8001DC78(void) {
    D_801776F8 = 0;
    D_80177708 = 0;
    D_80177718 = 0;
    D_80177728 = 0;
    D_80177738 = 0;
    D_80177748[0] = 0;
    D_80177758[0] = 0;
    D_80177768[0] = 0;
}

void func_8001DCD4(int arg0) {
    D_80177708 = arg0;
}

void func_8001DCEC(void) {
    s32 port;
    OSContPad* pad;

    if (D_80177708 == 0) {
        return;
    }
    // whats the point of setting this var? was there a for loop here?
    port = 0;
    if ((gControllerBits >> port) & 1) {
        pad = &gContPads[port];
        if (pad->errno != 0) {
            return;
        }
        D_80177748[port] = D_80177758[port];
        D_80177758[port] = pad->button;
        D_80177768[port] = (D_80177758[port] ^ D_80177748[port]) & D_80177758[port];
    }
    if (D_80177768[port] & 0x1000) {
        D_80177718 += 1;
        D_80177728 = 0;
    } else {
        D_80177728 += 1;
    }
    if (D_80177728 >= 7) {
        D_80177718 = 0;
        D_80177738 = 0;
    }
    if (D_80177738 == 0x3C) {
        if ((D_80177718 >= 0xA) && (D_80177718 < 0xF)) {
            D_801776F8 = 1;
        }
        D_80177718 = 0;
        D_80177738 = 0;
    } else {
        D_80177738 += 1;
    }
}

/**
 * Update the active controller masks.
 */
void UpdateActiveController(u16 port) {
    gActiveContPort = port;
    gActiveContButton = gContCurrButton[gActiveContPort];
    gActiveContPressed = gContButtonPressed[gActiveContPort];
    gActiveContStickX = gContStickX[gActiveContPort];
    gActiveContStickY = gContStickY[gActiveContPort];
    gActiveContCurrDir = gContCurrDir[gActiveContPort];
    gActiveContDirPressed = gContDirPressed[gActiveContPort];
}

/**
 * Setup the mesg queue for the controllers and init them.
 */
void InitControllers(void) {
    s32 status;
    u16 i;

    gControllerBits = 0;
    osCreateMesgQueue(&gContMesgQueue, &D_801776CC, 1);
    osSetEventMesg(5U, &gContMesgQueue, (void* )1);
    status = osContInit(&gContMesgQueue, &gControllerBits, &D_80177650);
    if (status != 0) {
        // presumedly for handling if the controller had an error, but there's nothing here.
        // missing assert?
    }
    for(i = 0; i < 4; i++) {
        gContRawPlugged[i] = 0;
        gContRawLastButton[i] = 0;
        gContRawCurrButton[i] = 0;
        gContRawButtonPressed[i] = 0;
        gContRawStickX[i] = 0;
        gContRawStickY[i] = 0;
        gContRawCurrDir[i] = 0;
        gContRawLastDir[i] = 0;
        gContRawDirPressed[i] = 0;
        gContLastButton[i] = 0;
        gContCurrButton[i] = 0;
        gContButtonPressed[i] = 0;
        gContStickX[i] = 0;
        gContStickY[i] = 0;
        gContCurrDir[i] = 0;
        gContLastDir[i] = 0;
        gContDirPressed[i] = 0;
    }
    UpdateActiveController(0);
    func_8001DC78();
}

/**
 * Reset the active controller masks.
 */
void ResetActiveController(void) {
    gActiveContButton = 0;
    gActiveContPressed = 0;
    gActiveContStickX = 0.0f;
    gActiveContStickY = 0.0f;
    gActiveContCurrDir = 0;
    gActiveContDirPressed = 0;
}

/**
 * Perform the reading of the raw arrays front the OSContPad data itself. This will be later read
 * into the buffers to be used during gameplay.
 */
void UpdateRawControllers(void) {
    OSContPad* pad;
    u16 dir;
    u16 i;
    s32 status;

    status = 1;
    if (gControllerBits & 1) {
        status = osContStartReadData(&gContMesgQueue);
        if (status == 0) {
            osRecvMesg(&gContMesgQueue, NULL, 1);
            osContGetReadData(gContPads);
        }
    }
    for(i = 0; i < 4; i++) {
        if ((gControllerBits >> i) & 1) {
            pad = &gContPads[i];
            // if any errors occurred or if no controllers are plugged in, treat the controller as if its not plugged in.
            if ((pad->errno != 0) || (status != 0)) {
                gContRawPlugged[i] = 0;;
            } else {
                gContRawPlugged[i] = 1;
                dir = 0;
                gContRawStickX[i] = pad->stick_x;
                gContRawStickY[i] = pad->stick_y;
                if (gContRawStickX[i] >= 0x32) {
                    dir |= CONT_RIGHT;
                } else if (gContRawStickX[i] < -0x31) {
                    dir |= CONT_LEFT;
                }
                if (gContRawStickY[i] >= 0x32) {
                    dir |= CONT_UP;
                } else if (gContRawStickY[i] < -0x31) {
                    dir |= CONT_DOWN;
                }
                if (D_8016525C != 0) {
                    gContRawCurrButton[i] = 0;
                    gContRawCurrDir[i] = 0;
                } else if (D_80165284 == 1) {
                    gContRawLastButton[i] = gContRawCurrButton[i];
                    gContRawCurrButton[i] = pad->button;
                    gContRawLastDir[i] = gContRawCurrDir[i];
                    gContRawCurrDir[i] = dir;
                } else {
                    gContRawCurrButton[i] |= pad->button;
                    gContRawCurrDir[i] |= dir;
                }
            }
        }
    }
}

/**
 * Set the pressed arrays and copy them to their live buffers later.
 */
void UpdateControllers(void) {
    u16 i;

    for(i = 0; i < 4; i++) {
        // Only update if plugged in and initialized.
        if (gContRawPlugged[i] != 0) {
            gContRawButtonPressed[i] = (gContRawCurrButton[i] ^ gContRawLastButton[i]) & gContRawCurrButton[i];
            gContRawDirPressed[i] = (gContRawCurrDir[i] ^ gContRawLastDir[i]) & gContRawCurrDir[i];
            gContPlugged[i] = gContRawPlugged[i];
            gContLastButton[i] = gContRawLastButton[i];
            gContCurrButton[i] = gContRawCurrButton[i];
            gContButtonPressed[i] = gContRawButtonPressed[i];
            gContStickX[i] = gContRawStickX[i];
            gContStickY[i] = gContRawStickY[i];
            gContLastDir[i] = gContRawLastDir[i];
            gContCurrDir[i] = gContRawCurrDir[i];
            gContDirPressed[i] = gContRawDirPressed[i];
        } else {
            // We dont want lingering inputs, so clear the raw arrays.
            gContRawButtonPressed[i] = 0;
            gContRawDirPressed[i] = 0;
            gContPlugged[i] = 0;
            gContLastButton[i] = 0;
            gContCurrButton[i] = 0;
            gContButtonPressed[i] = 0;
            gContStickX[i] = 0;
            gContStickY[i] = 0;
            gContLastDir[i] = 0;
            gContCurrDir[i] = 0;
            gContDirPressed[i] = 0;
        }
    }
}

void func_8001E80C(void) {
    UpdateRawControllers();
    func_8001DCEC();
    if (D_80165284 == 0) {
        func_8005F088();
        UpdateControllers();
        if (D_8016E0B0 != 0) {
            if (D_80165274 != NULL) {
                D_80165274();
            }
            func_8001D2FC();
            func_80016EE4();
            func_8001FBAC();
        }
        func_8005F0B8();
    }
    if (D_8016525C != 0) {
        if (D_8016525C == 8) {
            D_8016525C = 0;
        } else {
            D_8016525C += 1;
        }
    }
    D_80165284 += 1;
    if (D_80165284 >= D_8016527C) {
        D_80165284 = 0;
    }
    D_8016E244 += 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001E954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001E96C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001E98C.s")

#define ALIGN16(val) (((val) + 0xF) & ~0xF)

/**
 * Decompress a given area and add it to the file array's ID pointer.
 */
void DecompressFile(u32 id, u32 rom_start, u32 rom_end) {
    u32 heap;
    u32 allocSize;
    u32 size;
    void* buf;

    // align the heap pointer's size.
    heap = gDecompressHeap;
    if (heap & 0xF) {
        // add 1 so the heap will point to the new blank area in the heap.
        heap = ALIGN16(heap+1);
        gDecompressHeap = heap;
    }
    allocSize = rom_end - rom_start;
    buf = malloc(allocSize);
    // first load the compressed bin to the buffer.
    load_from_rom_to_addr(rom_start, buf, allocSize);
    // decompress the bin to the heap.
    size = Decode(buf, gDecompressHeap);
    free(buf);
    gFileArray[id].ptr = gDecompressHeap; // add the decompressed file to the file array.
    gDecompressHeap += size;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001EB68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001EBE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001EC04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001EC1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001EC38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001EC50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001EC6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001EC84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001ECA0.s")

void func_8001ECB8(void) {
    func_8001F9DC();
    D_8016E244 = 0;
    D_8016E084 = 0;
    D_8016E08C = 0;
    D_801765F4 = 0;
    D_80176602 = 0;
    func_8001EBE8();
    func_8001EC1C();
    func_8001EC50();
    func_8001EC84();
    // Set the View struct.
    gView.at.x = 0.0f;
    gView.at.y = 0.0f;
    gView.at.z = 0.0f;
    gView.eye.x = 0.0f;
    gView.eye.y = 0.0f;
    gView.eye.z = 1000.0f;
    gView.rot.x = 0.0f;
    gView.rot.y = 0.0f;
    gView.rot.z = 0.0f;
    gView.up.x = 0.0f;
    gView.up.y = 1.0f;
    gView.up.z = 0.0f;
    gView.dist = 1000.0f;
    gLightingSettings = D_8004A590;
    D_801775BC = 0;
    D_801775C4 = 0;
    D_801775CC = 0;
    D_801775D4 = 0;
    D_801775DC = 0;
    D_801775E4 = 0;
    D_801775EC = 0;
    D_8016E26C = 0x20;
    D_8016E274 = 0x20;
}

#pragma GLOBAL_ASM("asm/nonmatchings/boot/17930/func_8001EE64.s")
