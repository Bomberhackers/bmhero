#ifndef _SECTIONS_H_
#define _SECTIONS_H_

extern u8 game_ROM_START[];  // 0x4DFF0
extern u8 game_ROM_END[];    // 0x126CB0
extern u32 game_TEXT_START;  // 0x8005BAD0

#define code_extra_VRAM 0x80280000

extern u8 code_extra_0_ROM_START[];   // 0x128D20
extern u8 code_extra_0_ROM_END[];     // 0x134440

extern u8 code_extra_1_ROM_START[];   // 0x134440
extern u8 code_extra_1_ROM_END[];     // 0x138360

extern u8 code_extra_2_ROM_START[];   // 0x138360
extern u8 code_extra_2_ROM_END[];     // 0x13AC20

extern u8 code_extra_3_ROM_START[];   // 0x13AC20
extern u8 code_extra_3_ROM_END[];     // 0x13C4C0

extern u8 code_extra_4_ROM_START[];   // 0x13C4C0
extern u8 code_extra_4_ROM_END[];     // 0x13DAD0

extern u8 code_extra_5_ROM_START[];   // 0x13DAD0
extern u8 code_extra_5_ROM_END[];     // 0x144420

extern u8 code_extra_6_ROM_START[];   // 0x144420
extern u8 code_extra_6_ROM_END[];     // 0x147BB0

// extern ROM labels
extern u8 unk_bin_1_ROM_START[];      // 0x147BB0
extern u8 unk_bin_1_ROM_END[];        // 0x14C540

extern u8 unk_bin_2_ROM_START[];      // 0x14C540
extern u8 unk_bin_2_ROM_END[];        // 0x1528A0

extern u8 unk_bin_3_ROM_START[];      // 0x1528A0
extern u8 unk_bin_3_ROM_END[];        // 0x153B70

extern u8 unk_bin_4_ROM_START[];      // 0x153B70
extern u8 unk_bin_4_ROM_END[];        // 0x156F90

extern u8 unk_bin_5_ROM_START[];      // 0x156F90
extern u8 unk_bin_5_ROM_END[];        // 0x157520

extern u8 unk_bin_6_ROM_START[];      // 0x157520
extern u8 unk_bin_6_ROM_END[];        // 0x157A00

extern u8 unk_bin_7_ROM_START[];      // 0x157A00
extern u8 unk_bin_7_ROM_END[];        // 0x15A0F0

extern u8 unk_bin_8_ROM_START[];      // 0x15A0F0
extern u8 unk_bin_8_ROM_END[];        // 0x15A7D0

extern u8 unk_bin_9_ROM_START[];      // 0x15A7D0
extern u8 unk_bin_9_ROM_END[];        // 0x15C0D0

extern u8 unk_bin_10_ROM_START[];     // 0x15C0D0
extern u8 unk_bin_10_ROM_END[];       // 0x160560

extern u8 unk_bin_11_ROM_START[];     // 0x160560
extern u8 unk_bin_11_ROM_END[];       // 0x167950

extern u8 unk_bin_12_ROM_START[];     // 0x167950
extern u8 unk_bin_12_ROM_END[];       // 0x16D650

extern u8 unk_bin_13_ROM_START[];     // 0x16D650
extern u8 unk_bin_13_ROM_END[];       // 0x175420

extern u8 unk_bin_14_ROM_START[];     // 0x175420
extern u8 unk_bin_14_ROM_END[];       // 0x184EE0

extern u8 unk_bin_15_ROM_START[];     // 0x184EE0
extern u8 unk_bin_15_ROM_END[];       // 0x189940

extern u8 unk_bin_16_ROM_START[];     // 0x189940
extern u8 unk_bin_16_ROM_END[];       // 0x194F10

extern u8 unk_bin_17_ROM_START[];     // 0x194F10
extern u8 unk_bin_17_ROM_END[];       // 0x198140

extern u8 unk_bin_18_ROM_START[];     // 0x198140
extern u8 unk_bin_18_ROM_END[];       // 0x19C610

extern u8 unk_bin_19_ROM_START[];     // 0x19C610
extern u8 unk_bin_19_ROM_END[];       // 0x1A89C0

extern u8 unk_bin_20_ROM_START[];     // 0x1A89C0
extern u8 unk_bin_20_ROM_END[];       // 0x1ABC60

extern u8 unk_bin_21_ROM_START[];     // 0x1ABC60
extern u8 unk_bin_21_ROM_END[];       // 0x1AECD0

extern u8 unk_bin_22_ROM_START[];     // 0x1AECD0
extern u8 unk_bin_22_ROM_END[];       // 0x1B3930

extern u8 unk_bin_23_ROM_START[];     // 0x1B3930
extern u8 unk_bin_23_ROM_END[];       // 0x1B6C30

extern u8 unk_bin_24_ROM_START[];     // 0x1B6C30
extern u8 unk_bin_24_ROM_END[];       // 0x1BC4E0

extern u8 unk_bin_25_ROM_START[];     // 0x1BC4E0
extern u8 unk_bin_25_ROM_END[];       // 0x1C73D0

extern u8 unk_bin_26_ROM_START[];     // 0x1C73D0
extern u8 unk_bin_26_ROM_END[];       // 0x1C8320

extern u8 D_1C8320[];                 // 0x1C8320
extern u8 D_1C90D0[];                 // 0x1C90D0

extern u8 D_1C90D0[];                 // 0x
extern u8 D_1C9940[];                 // 0x

extern u8 D_1C9940[];                 // 0x
extern u8 D_1CA830[];                 // 0x

extern u8 D_1CA830[];                 // 0x
extern u8 D_1CA9B0[];                 // 0x

extern u8 D_1CA9B0[];                 // 0x
extern u8 D_1CAA50[];                 // 0x

extern u8 D_1CAA50[];                 // 0x
extern u8 D_1CAB90[];                 // 0x

extern u8 D_1CAB90[];                 // 0x
extern u8 D_1CBF80[];                 // 0x

extern u8 D_1CBF80[];                 // 0x
extern u8 D_1CCCE0[];                 // 0x

extern u8 D_1CCCE0[];                 // 0x
extern u8 D_1D01D0[];                 // 0x

extern u8 D_1D01D0[];                 // 0x
extern u8 D_1D1720[];                 // 0x

extern u8 D_1D1720[];                 // 0x
extern u8 D_1D9110[];                 // 0x

extern u8 D_1D9110[];                 // 0x
extern u8 D_1E3FF0[];                 // 0x

extern u8 D_1E3FF0[];                 // 0x
extern u8 D_1E7490[];                 // 0x

extern u8 D_1E7490[];                 // 0x
extern u8 D_1ED860[];                 // 0x

extern u8 D_1ED860[];                 // 0x
extern u8 D_1EF7F0[];                 // 0x

extern u8 D_1EF7F0[];                 // 0x
extern u8 D_1F0900[];                 // 0x

extern u8 D_1F0900[];                 // 0x
extern u8 D_1F6790[];                 // 0x

extern u8 D_1F6790[];                 // 0x
extern u8 D_1F7E80[];                 // 0x

extern u8 D_1F7E80[];                 // 0x
extern u8 D_1F8D70[];                 // 0x

extern u8 D_1F8D70[];                 // 0x
extern u8 D_1FACD0[];                 // 0x

extern u8 D_1FACD0[];                 // 0x
extern u8 D_1FE7A0[];                 // 0x

extern u8 D_1FE7A0[];                 // 0x
extern u8 D_201C00[];                 // 0x

extern u8 D_201C00[];                 // 0x
extern u8 D_205F30[];                 // 0x

extern u8 D_205F30[];                 // 0x
extern u8 D_20DA60[];                 // 0x

extern u8 D_20DA60[];                 // 0x
extern u8 D_20F5B0[];                 // 0x

extern u8 D_2193A0[];                 // 0x

#endif // _SECTIONS_H_
