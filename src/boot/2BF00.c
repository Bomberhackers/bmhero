#include <ultra64.h>

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002B300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002B640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002B670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002B830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002B894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002B9B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002BA34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002BAC8.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002EF00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002EF60.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002F32C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002F598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/boot/2BF00/func_8002F738.s")
