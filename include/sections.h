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

extern u8 unk_bin_27_ROM_START[];     // 0x1C8320
extern u8 unk_bin_27_ROM_END[];       // 0x1C90D0

extern u8 unk_bin_28_ROM_START[];     // 0x1C90D0
extern u8 unk_bin_28_ROM_END[];       // 0x1C9940

extern u8 unk_bin_29_ROM_START[];     // 0x1C9940
extern u8 unk_bin_29_ROM_END[];       // 0x1CA830

extern u8 unk_bin_30_ROM_START[];     // 0x1CA830
extern u8 unk_bin_30_ROM_END[];       // 0x1CA9B0

extern u8 unk_bin_31_ROM_START[];     // 0x1CA9B0
extern u8 unk_bin_31_ROM_END[];       // 0x1CAA50

extern u8 unk_bin_32_ROM_START[];     // 0x1CAA50
extern u8 unk_bin_32_ROM_END[];       // 0x1CAB90

extern u8 unk_bin_33_ROM_START[];     // 0x1CAB90
extern u8 unk_bin_33_ROM_END[];       // 0x1CBF80

extern u8 unk_bin_34_ROM_START[];     // 0x1CBF80
extern u8 unk_bin_34_ROM_END[];       // 0x1CCCE0

extern u8 unk_bin_35_ROM_START[];     // 0x1CCCE0
extern u8 unk_bin_35_ROM_END[];       // 0x1D01D0

extern u8 unk_bin_36_ROM_START[];     // 0x1D01D0
extern u8 unk_bin_36_ROM_END[];       // 0x1D1720

extern u8 unk_bin_37_ROM_START[];     // 0x1D1720
extern u8 unk_bin_37_ROM_END[];       // 0x1D9110

extern u8 unk_bin_38_ROM_START[];     // 0x1D9110
extern u8 unk_bin_38_ROM_END[];       // 0x1E3FF0

extern u8 unk_bin_39_ROM_START[];     // 0x1E3FF0
extern u8 unk_bin_39_ROM_END[];       // 0x1E7490

extern u8 unk_bin_40_ROM_START[];     // 0x1E7490
extern u8 unk_bin_40_ROM_END[];       // 0x1ED860

extern u8 unk_bin_41_ROM_START[];     // 0x1ED860
extern u8 unk_bin_41_ROM_END[];       // 0x1EF7F0

extern u8 unk_bin_42_ROM_START[];     // 0x1EF7F0
extern u8 unk_bin_42_ROM_END[];       // 0x1F0900

extern u8 unk_bin_43_ROM_START[];     // 0x1F0900
extern u8 unk_bin_43_ROM_END[];       // 0x1F6790

extern u8 unk_bin_44_ROM_START[];     // 0x1F6790
extern u8 unk_bin_44_ROM_END[];       // 0x1F7E80

extern u8 unk_bin_45_ROM_START[];     // 0x1F7E80
extern u8 unk_bin_45_ROM_END[];       // 0x1F8D70

extern u8 unk_bin_46_ROM_START[];     // 0x1F8D70
extern u8 unk_bin_46_ROM_END[];       // 0x1FACD0

extern u8 unk_bin_47_ROM_START[];     // 0x1FACD0
extern u8 unk_bin_47_ROM_END[];       // 0x1FE7A0

extern u8 unk_bin_48_ROM_START[];     // 0x1FE7A0
extern u8 unk_bin_48_ROM_END[];       // 0x201C00

extern u8 unk_bin_49_ROM_START[];     // 0x201C00
extern u8 unk_bin_49_ROM_END[];       // 0x205F30

extern u8 unk_bin_50_ROM_START[];     // 0x205F30
extern u8 unk_bin_50_ROM_END[];       // 0x20DA60

extern u8 unk_bin_51_ROM_START[];     // 0x20DA60
extern u8 unk_bin_51_ROM_END[];       // 0x20F5B0

// other unrelated segments
extern u8 unk_bin_52_ROM_START[];                 // 0x20F5B0
extern u8 unk_bin_52_ROM_END[];

extern u8 unk_bin_53_ROM_START[];                 // 0x2193A0
extern u8 unk_bin_53_ROM_END[];

#endif // _SECTIONS_H_
