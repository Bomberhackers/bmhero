#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"
#include "prevent_bss_reordering.h"

extern OSMesgQueue D_801776B0;
extern OSMesg D_801776CC;
extern u8 D_8016E27C;
extern OSContStatus D_80177650;

struct UnkStruct8016E280 {
    u16 unk00[4];
    char filler8[0x8];
    u16 unk10[4];
    char filler18[0x8];
    u16 unk20[4];
    char filler28[0x8];
    u16 unk30[4];
    char filler38[0x4];
    u8 unk3C[4];
    char filler40[0x4];
    u8 unk44[4];
    char filler48[0x8];
    u16 unk50[4];
    char filler58[0x8];
    u16 unk60[4];
    char filler68[0x8];
    u16 unk70[4];
    char filler78[0x8];
};

extern struct UnkStruct8016E280 D_8016E280;
extern struct UnkStruct8016E280 D_8016E300;

#endif // _VARIABLES_H_
