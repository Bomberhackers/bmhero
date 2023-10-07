#include "common.h"

extern void func_80019B7C();
extern void func_8006AA60(s32*, s32*, s32*);
extern void func_8008A870(u8, u8, s32, s32, s32);
extern void func_80069E00(s32, s32);
void func_8008B030(void);
void func_8008A6A4(void);
void func_8008A384(void);
void func_8008A824(s16 arg0, s16 arg1, s16 arg2);
extern void func_8001FB3C (s16, s16, s16);
void func_8008884C (s32);
void func_8008ABC4 (s16 *);
void func_8008ABF4 (s16 *);
void func_8008AC08 (s16 *);
void func_8008AD58 (s16 *);
void func_8008AE64 (s16 *);
void func_8008B5D4 (s16*);
void func_8008B624 (s16*);
void func_8008B6E0 (s16*);
void func_8008BA3C(void);
void func_8008BB0C(void);
void func_8008BC04(s16*);
extern void func_8008C61C();
extern void func_8008C638();
extern void func_8008C650();
extern void func_8008C66C();
extern void func_8008C684(s16*);
extern void func_8008C778(s16*);
extern void func_8008C9B4(s16*);
extern void func_8008CADC(s16*);
extern void func_8008CC04(s16*);
extern void func_8008CD2C(s16*);
extern void func_8008CE8C(s16*);
extern void func_8008D074(s16*);
extern void func_8008D114(s16*);
extern void func_8008D530(s16*);
extern void func_8008DC8C(s16*);
extern void func_8008E328(s16*);
extern void func_8008E3B0(s16*);
extern void func_8008E418(s16*);
extern void func_8008E81C(s16*);
extern void func_8008E8A4(s16*);
extern void func_8008E918(s16*);
extern void func_8008EAE4(s16*);
extern void func_8008EB10(s16*);
extern void func_8008EB40(s16*);
extern void func_8008EB6C(s16*);
extern void func_8008EB9C(s16*);
extern void func_8008EBEC(s16*);
extern void func_8008EC3C(s16*);
extern void func_8008ECD0(s16*);
extern void func_8008ED64(s16*);
extern void func_8008EF8C(s16*);
extern void func_8008F078(s16*);
extern void func_8008F3D4(s16*);
extern void func_8008F63C(s16*);
extern void func_8008F6AC(s16*);


extern f32 D_80134F44;
extern f32 D_80134F48;
extern f32 D_80134F4C;
extern s16 D_80134FA4;
extern s8 D_8016E134;
extern f32 D_8016E14C;
extern f32 D_8016E150;
extern f32 D_8016E154;
extern s16 D_80177600;
extern s8 D_80134BF0;
extern f32 D_80134F28;
extern f32 D_80134F2C;
extern f32 D_80134F30;
extern f32 D_80134F34;
extern f32 D_80134F38;
extern f32 D_80134F3C;
extern f32 D_80134F40;
extern f32 D_80134F50;
extern f32 D_80134F54;
extern f32 D_80134F58;
extern f32 D_80134F5C;
extern f32 D_80134F60;
extern f32 D_80134F64;
extern f32 D_80134F74;
extern s16 D_80134C1A;
extern f32 D_8016E140;
extern f32 D_8016E144;
extern f32 D_8016E148;
extern f32 D_8016E158;
extern f32 D_8016E15C;
extern f32 D_8016E160;
extern f32 D_8016E170;
extern s16 D_80134C1C;
extern f32 D_80134F78;
extern f32 D_80134F7C;
extern f32 D_80134F80;
extern f32 D_80134F84;
extern f32 D_80134F88;
extern f32 D_80134F8C;
extern f32 D_80134F90;
extern f32 D_80134F94;
extern f32 D_80134F98;
extern f32 D_80134F9C;
extern s16 D_80134FA0;
extern s16 D_80134FA2;
extern s32 D_801765EC;
extern s16 D_80134FA6;
extern s16 D_80134C20;
extern f32 D_80134F68;
extern f32 D_80134F6C;
extern f32 D_80134F70;

extern s16 D_80134C1E;

extern s16 D_8010CD80[2];
extern s16 D_80110B78[];
extern s16* D_80110D4C[];
extern s16 D_80134BF8;
extern s16* D_80134C08;
extern s16 D_80134C0E;
extern s16 D_80134C16;
extern s16 D_80134C18;

extern s16 D_80134BF2;
extern s16 D_80134C0C;
extern s16 D_80134BFA;
extern s16 D_80134BFC;

extern s16 D_80134BF4;
extern s16 *D_80134C00;
extern s16 D_80134C10;
extern s16 D_80134C12;
extern s16 D_80134C14;
extern s16 D_80134C22;
extern s8 D_80134C24;
extern s8 D_80134C25;
extern s8 D_80134C26;

extern Gfx* gMasterDisplayList;

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_80088B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_80088D84.s")

void func_80088EAC(s32 arg0) {
    D_80134BF2 = arg0;
    D_80134C0C = 0;
}

void func_80088ECC (void)
{
  s16 sp1E;


  if (D_80134BF2 == -1)
    {
      return;
    }
  if ((D_80134C0C == 0) && (D_80134BF8 == -1))
    {
      D_80134C0C += 1;
      D_80134C12 = 0;
      D_80134C10 = 0;
      D_80134C0E = 0;
      D_80134C16 = 0;
      D_80134C14 = 0;
      D_80134BF8 = -1, D_80134BF4 = -1;
      D_80134C00 = (s16 *)0x8033A000;
    }
  if (D_80134C14 != 0)
    {
      D_80134C14 -= 1;
      return;
    }
  sp1E = 0;
  while (sp1E == 0)
      {

    switch (D_80134C00[0])
      {
          case 0x0:
            D_80134BF2 = -1;
            D_80134C0C = 0;
            sp1E = 1;
            break;
          case 0x1:
            sp1E = 1;
            break;
          case 0x2:
            D_80134BF8 = D_80134C00[1];
            D_80134BFA = D_80134C00[2];
            D_80134BFC = D_80134C00[3];
            D_80134C00 += 3;
            break;
          case 0x5:
            D_80134C14 = D_80134C00[1] - 1;
            D_80134C00 += 1;
            sp1E = 1;
            break;
          case 0x6:
            func_8008ABC4 (D_80134C00 + 1);
            D_80134C00 += 4;
            break;
          case 0x3C:
            func_8008ABF4 (D_80134C00 + 1);
            D_80134C00 += 4;
            break;
          case 0x7:
            func_8008AC08 (D_80134C00 + 1);
            D_80134C00 += 1;
            break;
          case 0x8:
            D_801765EC = 0;
            break;
          case 0x27:
            func_8008BB0C ();
            break;
          case 0x25:
            func_8008AD58 (D_80134C00 + 1);
            D_80134C00 += 7;
            break;
          case 0x26:
            func_8008AE64 (D_80134C00 + 1);
            D_80134C00 += 6;
            break;
          case 0x9:
            D_80134F74 = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0xA:
            D_80134F50 = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0xB:
            D_80134F54 = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0xC:
            D_80134F58 = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0xD:
            D_80134F5C = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0xE:
            D_80134F60 = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0xF:
            func_8008B5D4 (D_80134C00 + 1);
            D_80134C00 += 2;
            break;
          case 0x10:
            func_8008B624 (D_80134C00 + 1);
            D_80134C00 += 4;
            break;
          case 0x11:
            func_8008B6E0 (D_80134C00 + 1);
            D_80134C00 += 5;
            break;
          case 0x12:
            func_8008BA3C ();
            break;
          case 0x13:
            func_8008C61C ();
            break;
          case 0x14:
            func_8008C638 ();
            break;
          case 0x15:
            func_8008C650 ();
            break;
          case 0x16:
            func_8008C66C ();
            break;
          case 0x17:
            func_8008C684 (D_80134C00 + 1);
            D_80134C00 += 4;
            break;
          case 0x18:
            func_8008C778 (D_80134C00 + 1);
            D_80134C00 += 5;
            break;
          case 0x19:
            func_8008C9B4 (D_80134C00 + 1);
            D_80134C00 += 2;
            break;
          case 0x1A:
            func_8008CADC (D_80134C00 + 1);
            D_80134C00 += 2;
            break;
          case 0x1B:
            func_8008CC04 (D_80134C00 + 1);
            D_80134C00 += 2;
            break;
          case 0x1F:
            func_8008CD2C (D_80134C00 + 1);
            D_80134C00 += 4;
            break;
          case 0x20:
            func_8008CE8C (D_80134C00 + 1);
            D_80134C00 += 5;
            break;
          case 0x32:
            func_8008D074 (D_80134C00 + 1);
            D_80134C00 += 3;
            break;
          case 0x33:
            func_8008D114 (D_80134C00 + 1);
            D_80134C00 += 2;
            break;
          case 0x21:
            func_8008D530 (D_80134C00 + 1);
            D_80134C00 += 6;
            break;
          case 0x22:
            func_8008DC8C (D_80134C00 + 1);
            D_80134C00 += 3;
            break;
          case 0x23:
            func_8008E328 (D_80134C00 + 1);
            D_80134C00 += 2;
            break;
          case 0x34:
            func_8008E3B0 (D_80134C00 + 1);
            D_80134C00 += 3;
            break;
          case 0x39:
            func_8008E418 (D_80134C00 + 1);
            D_80134C00 += 3;
            break;
          case 0x24:
            func_8008E81C (D_80134C00 + 1);
            D_80134C00 += 3;
            break;
          case 0x28:
            D_80134F68 = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0x29:
            D_80134F6C = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0x2A:
            D_80134F70 = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0x2B:
            func_8008BC04 (D_80134C00 + 1);
            D_80134C00 += 4;
            break;
          case 0x2C:
            func_8008E8A4 (D_80134C00 + 1);
            D_80134C00 += 2;
            break;
          case 0x2D:
            func_8008E918 (D_80134C00 + 1);
            D_80134C00 += 3;
            break;
          case 0x2E:
            func_8008EAE4 (D_80134C00 + 1);
            D_80134C00 += 1;
            break;
          case 0x2F:
            func_8008EB10 (D_80134C00 + 1);
            D_80134C00 += 1;
            break;
          case 0x30:
            func_8008EB40 (D_80134C00 + 1);
            D_80134C00 += 1;
            break;
          case 0x31:
            func_8008EB6C (D_80134C00 + 1);
            D_80134C00 += 1;
            break;
          case 0x36:
            func_8008EB9C (D_80134C00 + 1);
            D_80134C00 += 1;
            break;
          case 0x35:
            func_8008EBEC (D_80134C00 + 1);
            D_80134C00 += 1;
            break;
          case 0x37:
            func_8008EC3C (D_80134C00 + 1);
            D_80134C00 += 1;
            break;
          case 0x38:
            func_8008ECD0 (D_80134C00 + 1);
            D_80134C00 += 1;
            break;
          case 0x3A:
            func_8008ED64 (D_80134C00 + 1);
            D_80134C00 += 2;
            break;
          case 0x3B:
            func_8008EF8C (D_80134C00 + 1);
            D_80134C00 += 4;
            break;
          case 0x3D:
            func_8008F078 (D_80134C00 + 1);
            D_80134C00 += 5;
            break;
          case 0x3E:
            func_8008F3D4 (D_80134C00 + 1);
            D_80134C00 += 1;
            break;
          case 0x3F:
            func_8008F63C (D_80134C00 + 1);
            D_80134C00 += 5;
            break;
          case 0x4C:
            func_8008F6AC (D_80134C00 + 1);
            D_80134C00 += 2;
            break;
          case 0x40:
            D_80134C22 = 1;
            break;
          case 0x41:
            D_80134C22 = 0;
            break;
          case 0x42:
            D_80134C24 = 1;
            D_80134C25 = 0;
            break;
          case 0x44:
            D_80134C24 = 2;
            D_80134C25 = 0;
            break;
          case 0x43:
          case 0x45:
            D_80134C24 = 0;
            break;
          case 0x46:
            func_8001FB3C (D_80134C00[1], D_80134C00[2], D_80134C00[3]);
            D_80134C00 += 3;
            break;
          case 0x47:
            D_80134C26 = 1;
            break;
          case 0x48:
            D_80134C26 = 0;
            break;
          case 0x49:
            func_8008884C (1);
            break;
          case 0x4A:
            func_8008884C (0);
            break;
          case 0x4B:
            D_80134BF0 = (s8)D_80134C00[1];
            D_80134C00 += 1;
            break;
          default:
            sp1E = 1;
            break;
          }
          D_80134C00 += 1;
      }
}

void func_80089C18(void) {
    if (D_80134BF8 == -1) {
        return;
    }
    if (D_80134C0E == 0) {
        D_80134C0E += 1;
        D_80134C08 = D_80110D4C[D_80134BF8];
        D_80134C16 = D_80110B78[D_80134BF8];
        D_80134C18 = 0xA;
    }
    if (D_80134C16 == 0) {
        if (D_80134C18 == 0) {
            D_80134BF8 = -1;
            D_80134BF0 = 0;
            D_80134C0E = 0;
        } else
        {
            D_80134C18 -= 1;
        }
    }
    else
    {
        D_80134C16 -= 1;
    }
}

void func_80089D30(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp2C;
    s32 sp28;
    s32 i;

    for(i = 0; i < arg3; i++) {
        sp28 = arg0 % 10;

        if(arg0 == 0) {
            sp2C = 0;
        }
        else {
            sp2C = sp28;
        }
        arg0 /= 10;
        sp2C++;
        func_8008A870(arg1, arg2, (sp2C % 32) * 8, (sp2C / 32) * 0x10, 0x1A);
        arg1 -= 8;
    }
}

void func_80089E48(void) {
    s16 sp2E;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    if (D_80134BF0 == 1) {
        sp2E = 0x45;
        func_8006AA60(&sp28, &sp24, &sp20);
        func_80089D30(sp28, 0xC0, 0xB8, 2);
        func_8008A870(0xC8, 0xB8, (sp2E % 32) * 8, (sp2E / 32) * 0x10, 0x1A);
        func_80089D30(sp24, 0xD8, 0xB8, 2);
        func_8008A870(0xE0, 0xB8, (sp2E % 32) * 8, (sp2E / 32) * 0x10, 0x1A);
        func_80089D30(sp20, 0xF0, 0xB8, 2);
        sp2E = 0x3F;
        func_8008A870(0xF8, 0xB8, (sp2E % 32) * 8, (sp2E / 32) * 0x10, 0x1A);
    } else if (D_80134BF0 == 2) {
        func_80089D30(D_80177600 * 0xA, 0xB4, 0xC8, 5);
    }
}

void func_8008A000(void) {
    s16 sp3E;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s16 sp2E;

     if (D_80134BF8 == -1)
     {
         return;
     }

    func_8008A6A4();
    func_8008A384();
    func_8008A824(D_80134C08[0], D_80134C08[1], D_80134C08[2]);

    sp36 = 0;
    sp38 = 0;
    sp3A = 0;
    sp3C = 0;
    sp3E = 0;

    while(sp3A == 0)
    {
        if(D_80134C08[sp3E + 5] == -1)
        {
            if (D_80134C08[4] == (sp38 + 1))
            {
                sp3A = 1;
            } else {
                sp38 += 1;
                sp3E += 1;
                sp3C += 1;
                sp36 = 0;
            }
        }
        else
        {
            sp34 = D_80134C08[sp3E+5];
            sp32 = 0x1A;

            switch (D_80134BFA)
            {
                case 0:
                    {
                        sp30 = ((s32) (0x140 - (D_80134C08[3] * 8)) / 2) + (sp36 * 8);
                        break;
                    }
                case 1:
                    {
                        sp30 = sp36 * 8;
                        break;
                    }
                case 2:
                    {
                        sp30 = ((sp36 * 8) - (D_80134C08[3] * 8)) + 0x140;
                        break;
                    }
                default:
                    {
                        sp30 = ((s32) (0x140 - (D_80134C08[3] * 8)) / 2) + (sp36 * 8);
                        break;
                    }
            }

            switch (D_80134BFC)
            {
                case 0:
                    {
                        sp2E = ((s32) (0xF0 - (D_80134C08[4] * 0x10)) / 2) + (sp3C * 0x10);
                        break;
                    }
                case 3:
                    {
                        sp2E = sp3C * 0x10;
                        break;
                    }
                case 4:
                    {
                        sp2E = (sp3C * 0x10) + 0xB8;
                        break;
                    }
                default:
                    {
                        sp2E = (sp3C * 0x10) + 0xB8;
                        break;
                    }
            }

            func_8008A870(sp30, sp2E, (sp34 % 32) * 8, (sp34 / 32) * 0x10, (s32) sp32);
            sp3E++;
            sp36++;
        }
    }

    func_80089E48();
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008A384.s")

void func_8008A6A4(void) {
    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BACK  | G_SHADING_SMOOTH);
    gDPSetCombineMode(gMasterDisplayList++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(gMasterDisplayList++, 0, 0, 0x00, 0x00, 0x00, 0x50);
    gDPFillRectangle(gMasterDisplayList++, 24, 180, 298, 220);
}

void func_8008A824(s16 arg0, s16 arg1, s16 arg2) {
    D_8010CD80[1] = ((arg0 << 0xB) + (arg1 << 6) + (arg2 * 2) + 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008A870.s")

void func_8008ABC4(s16* arg0) {
    func_80069E00(0, 0);
}

void func_8008ABF4(s16* arg0) {

}

void func_8008AC08(s16* arg0) {

    switch(*arg0)
    {
        case 1:
            {
                D_8016E134 = 0;
                D_80134FA4 = 0;
                break;
            }
        case 2:
            {
                D_8016E134 = 1;
                D_80134FA4 = 1;
                func_8008B030();
                break;
            }
        case 3:
            {
                D_8016E134 = 0;
                D_80134FA4 = 1;
                break;
            }
        case 4:
            {
                D_8016E134 = 1;
                D_80134FA4 = 0;
                func_8008B030();
                break;
            }
        default:
            {
                D_8016E134 = 0;
                D_80134FA4 = 0;
                break;
            }
    }

    func_80019B7C();
    if (D_8016E134 == 1) {
        D_80134F44 = D_8016E14C;
        D_80134F48 = D_8016E150;
        D_80134F4C = D_8016E154;
    }
}

void func_8008AD58(s16* arg0) {
    D_80134F28 = (f32) arg0[0];
    D_80134F2C = (f32) arg0[1];
    D_80134F30 = (f32) arg0[2];
    D_80134F34 = (f32) arg0[3];
    D_80134F38 = (f32) arg0[4];
    D_80134F3C = (f32) arg0[5];
    D_80134F40 = (f32) arg0[6];
    D_80134F50 = 0.0f;
    D_80134F54 = 0.0f;
    D_80134F58 = 0.0f;
    D_80134F5C = 0.0f;
    D_80134F60 = 0.0f;
    D_80134F64 = 0.0f;
    D_80134F74 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008AE64.s")

void func_8008B030(void) {
    D_8016E140 = D_80134F28;
    D_8016E144 = D_80134F2C;
    D_8016E148 = D_80134F30;
    D_8016E158 = D_80134F34;
    D_8016E15C = D_80134F38;
    D_8016E160 = D_80134F3C;
    D_8016E170 = D_80134F40;
    if (D_8016E134 == 1) {
        D_8016E14C = D_80134F44;
        D_8016E150 = D_80134F48;
        D_8016E154 = D_80134F4C;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/7B0A0/func_8008B0F4.s")

void func_8008B5D4(s16* arg0) {
    D_80134F74 = ((f32) arg0[0] - D_80134F40) / (f32) arg0[1];
    D_80134C1A = arg0[1];
}

void func_8008B624(s16* arg0) {
    D_80134F50 = ((f32) arg0[0] - D_80134F28) / (f32) arg0[3];
    D_80134F54 = ((f32) arg0[1] - D_80134F2C) / (f32) arg0[3];
    D_80134F58 = ((f32) arg0[2] - D_80134F30) / (f32) arg0[3];
    D_80134C1C = arg0[3] - 1;
}

void func_8008B6E0(s16* arg0) {
    if (arg0[3] == 0)
    {
        if((f32)(arg0[0]) / 10 < D_80134F34)
        {
            D_80134F5C = ((((f32)(arg0[0]) / 10) - D_80134F34) + 360) / arg0[2];
        }
        else
        {
            D_80134F5C = ((((f32)(arg0[0]) / 10) - D_80134F34)) / arg0[2];
        }
    }
    else if ((f32)(arg0[0]) / 10 <= D_80134F34)
    {
        D_80134F5C = ((((f32)(arg0[0]) / 10) - D_80134F34)) / arg0[2];
    }
    else
    {
        D_80134F5C = ((D_80134F34 - ((f32)(arg0[0]) / 10) + 360) / arg0[2]) * -1;
    }

    if (arg0[4] == 0)
    {
        if((f32)(arg0[1]) / 10 < D_80134F38)
        {
            D_80134F60 = ((((f32)(arg0[1]) / 10) - D_80134F38) + 360) / arg0[2];
        }
        else
        {
            D_80134F60 = ((((f32)(arg0[1]) / 10) - D_80134F38)) / arg0[2];
        }
    }
    else if  ((f32)(arg0[1]) / 10 <= D_80134F38)
    {
        D_80134F60 = ((((f32)(arg0[1]) / 10) - D_80134F38)) / arg0[2];
    }
        else
    {
        D_80134F60 = ((D_80134F38 - ((f32)(arg0[1]) / 10) + 360) / arg0[2]) * -1;
    }

    D_80134C1E = arg0[2];
}

void func_8008BA3C(void) {
    D_80134FA0 = (s16) D_801765EC;
    D_80134FA2 = (s16) D_8016E134;
    D_80134F78 = D_8016E140;
    D_80134F7C = D_8016E144;
    D_80134F80 = D_8016E148;
    D_80134F84 = D_8016E158;
    D_80134F88 = D_8016E15C;
    D_80134F8C = D_8016E160;
    D_80134F9C = D_8016E170;
    D_80134F90 = D_8016E14C;
    D_80134F94 = D_8016E150;
    D_80134F98 = D_8016E154;
}

void func_8008BB0C(void) {
    D_801765EC = (s32) D_80134FA0;
    D_8016E134 = (s8) D_80134FA2;
    D_8016E140 = D_80134F78;
    D_8016E144 = D_80134F7C;
    D_8016E148 = D_80134F80;
    D_8016E158 = D_80134F84;
    D_8016E15C = D_80134F88;
    D_8016E160 = D_80134F8C;
    D_8016E14C = D_80134F90;
    D_8016E150 = D_80134F94;
    D_8016E154 = D_80134F98;
    D_8016E170 = D_80134F9C;
    D_80134FA4 = 0;
    D_80134FA6 = 0;
    func_80019B7C();
}

void func_8008BC04(s16* arg0) {
    D_80134F68 = ((f32) arg0[0] - D_80134F44) / (f32) arg0[3];
    D_80134F6C = ((f32) arg0[1] - D_80134F48) / (f32) arg0[3];
    D_80134F70 = ((f32) arg0[2] - D_80134F4C) / (f32) arg0[3];
    D_80134C20 = arg0[3];
}
