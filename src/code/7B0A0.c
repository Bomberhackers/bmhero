#include <ultra64.h>
#include "common.h"
#include "variables.h"

extern void func_80019B7C();
extern void func_8006AA60(s32*, s32*, s32*);
void func_8008A870(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
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
void func_80088D84();
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
extern f32 func_80015538(f32, f32); 


extern s8 D_8016E134;
extern s16 D_80177600;
extern f32 D_80134F40;

extern s32 D_801765EC;

extern s16 D_8010CD80[2];
extern s16 D_80110B78[];
extern s16* D_80110D4C[];

extern Gfx* gMasterDisplayList;

// .bss
s8 D_80134BF0;
s16 D_80134BF2;
s16 D_80134BF4;
s16 D_80134BF6_unused;
s16 D_80134BF8;
s16 D_80134BFA;
s16 D_80134BFC;
s16 *D_80134C00;
s16 *D_80134C04_unused;
s16* D_80134C08;
s16 D_80134C0C;
s16 D_80134C0E;
s16 D_80134C10;
s16 D_80134C12;
s16 D_80134C14;
s16 D_80134C16;
s16 D_80134C18;
s16 D_80134C1A;
s16 D_80134C1C;
s16 D_80134C1E;
s16 D_80134C20;
s16 D_80134C22;
s8 D_80134C24;
s8 D_80134C25;
s8 D_80134C26;
s16 D_80134C28[0x18];
s16 D_80134C58[0x18];
s16 D_80134C88[0x18];
s16 D_80134CB8[0x18];
s16 D_80134CE8[0x18];
s16 D_80134D18[0x18];

struct UnkStruct80134D48 D_80134D48[0x18];
struct MegaStruct gMegaStruct; // 80134F28

void func_80088B80(void) {
    s16 sp1E;
    D_80134BF2 = -1;
    D_80134BF8 = -1;
    D_80134BF0 = 0;
    D_80134C26 = 0;
    D_80134C24 = 0;
    D_80134C25 = 0;
    D_80134C22 = 0;
    D_80134C0C = 0;
    D_80134C1E = -1,
    D_80134C1C = -1,
    D_80134C1A = -1;
    D_80134C20 = -1;
    func_80088D84();
    for(sp1E = 0; sp1E < 0x18; sp1E++)
    {
        D_80134D48[sp1E].unk0 = -1;
        D_80134D48[sp1E].unk4 = 0.0f;
        D_80134D48[sp1E].unk8 = 0.0f;
        D_80134D48[sp1E].unkC = 0;
        D_80134D48[sp1E].unkE = 0;
        D_80134D48[sp1E].unk10 = 0;
        D_80134C28[sp1E] = -1;
        D_80134C58[sp1E] = -1;
        D_80134C88[sp1E] = -1;
        D_80134CB8[sp1E] = -1;
        D_80134CE8[sp1E] = -1;
        D_80134D18[sp1E] = 0;
    }
}

void func_80088D84(void) {
    gMegaStruct.D_80134F28.x =    gMegaStruct.D_80134F28.y =    gMegaStruct.D_80134F28.z = 0.0f;
    gMegaStruct.D_80134F44.x =    gMegaStruct.D_80134F44.y =    gMegaStruct.D_80134F44.z = 0.0f;
    gMegaStruct.D_80134F34.x =    gMegaStruct.D_80134F34.y =    gMegaStruct.D_80134F34.z = gMegaStruct.D_80134F40 = 0.0f;
    gMegaStruct.D_80134F50.x =    gMegaStruct.D_80134F50.y =    gMegaStruct.D_80134F50.z = 0.0f;
    gMegaStruct.D_80134F68.x =    gMegaStruct.D_80134F68.y =    gMegaStruct.D_80134F68.z = 0.0f;
    gMegaStruct.D_80134F5C.x =    gMegaStruct.D_80134F5C.y =    gMegaStruct.D_80134F5C.z = gMegaStruct.D_80134F74 = 0.0f;
    gMegaStruct.D_80134F78.x =    gMegaStruct.D_80134F78.y =    gMegaStruct.D_80134F78.z = 0.0f;
    gMegaStruct.D_80134F90.x =    gMegaStruct.D_80134F90.y =    gMegaStruct.D_80134F90.z = 0.0f;
    gMegaStruct.D_80134F84.x =    gMegaStruct.D_80134F84.y =    gMegaStruct.D_80134F84.z = gMegaStruct.D_80134F9C = 0.0f;
    gMegaStruct.D_80134FA0.unk0 = 1;
    gMegaStruct.D_80134FA0.unk2 = 0;
    gMegaStruct.D_80134FA4.unk0 = gMegaStruct.D_80134FA4.unk2 = 0;
    gMegaStruct.D_80134FA8 = 0;
}

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
            gMegaStruct.D_80134F74 = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0xA:
            gMegaStruct.D_80134F50.x = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0xB:
            gMegaStruct.D_80134F50.y = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0xC:
            gMegaStruct.D_80134F50.z = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0xD:
            gMegaStruct.D_80134F5C.x = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0xE:
            gMegaStruct.D_80134F5C.y = (f32)D_80134C00[1] / 10.0f;
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
            gMegaStruct.D_80134F68.x = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0x29:
            gMegaStruct.D_80134F68.y = (f32)D_80134C00[1] / 10.0f;
            D_80134C00 += 1;
            break;
          case 0x2A:
            gMegaStruct.D_80134F68.z = (f32)D_80134C00[1] / 10.0f;
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

void func_8008A384(void) {
    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetTexturePersp(gMasterDisplayList++, G_TP_NONE);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gDPSetCombineMode(gMasterDisplayList++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetColorDither(gMasterDisplayList++, G_CD_BAYER);
    gDPSetTextureFilter(gMasterDisplayList++, G_TF_BILERP);
    gDPSetTextureLUT(gMasterDisplayList++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gMasterDisplayList++, 0, D_8016CAA0[26].unk0 + 0x10);
}

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

void func_8008A870(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    gDPLoadMultiTile_4b(gMasterDisplayList++,
        D_8016CAA0[arg4].unk0 + 0x30, 0, 0,
        G_IM_FMT_CI,
        256, 256,
        arg2, arg3, (arg2 + 0x08), (arg3 + 0x10),
        0, 0, 0, 0, 0, 0, 0
    );
    gDPSetTileSize(gMasterDisplayList++,  0, 0, 0, 0x40, 0x40);
    gSPTextureRectangle(gMasterDisplayList++,
        (arg0 << 2), (arg1 << 2), ((arg0 + 0x08) << 2), ((arg1 + 0x10) << 2),
        0, 0, 0, 0x400, 0x400);
}

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
                gMegaStruct.D_80134FA4.unk0 = 0;
                break;
            }
        case 2:
            {
                D_8016E134 = 1;
                gMegaStruct.D_80134FA4.unk0 = 1;
                func_8008B030();
                break;
            }
        case 3:
            {
                D_8016E134 = 0;
                gMegaStruct.D_80134FA4.unk0 = 1;
                break;
            }
        case 4:
            {
                D_8016E134 = 1;
                gMegaStruct.D_80134FA4.unk0 = 0;
                func_8008B030();
                break;
            }
        default:
            {
                D_8016E134 = 0;
                gMegaStruct.D_80134FA4.unk0 = 0;
                break;
            }
    }

    func_80019B7C();
    if (D_8016E134 == 1) {
        gMegaStruct.D_80134F44.x = gView.eye.x;
        gMegaStruct.D_80134F44.y = gView.eye.y;
        gMegaStruct.D_80134F44.z = gView.eye.z;
    }
}

void func_8008AD58(s16* arg0) {
    gMegaStruct.D_80134F28.x = (f32) arg0[0];
    gMegaStruct.D_80134F28.y = (f32) arg0[1];
    gMegaStruct.D_80134F28.z = (f32) arg0[2];
    gMegaStruct.D_80134F34.x = (f32) arg0[3];
    gMegaStruct.D_80134F34.y = (f32) arg0[4];
    gMegaStruct.D_80134F34.z = (f32) arg0[5];
    gMegaStruct.D_80134F40 = (f32) arg0[6];
    gMegaStruct.D_80134F50.x = 0.0f;
    gMegaStruct.D_80134F50.y = 0.0f;
    gMegaStruct.D_80134F50.z = 0.0f;
    gMegaStruct.D_80134F5C.x = 0.0f;
    gMegaStruct.D_80134F5C.y = 0.0f;
    gMegaStruct.D_80134F5C.z = 0.0f;
    gMegaStruct.D_80134F74 = 0.0f;
}

void func_8008AE64(s16* arg0) {
    s32 sp4;

    sp4 = D_80134D48[arg0[0]].unk0;
    gMegaStruct.D_80134F28.x = gPlayerData[sp4].Pos.x;
    gMegaStruct.D_80134F28.y = gPlayerData[sp4].Pos.y + arg0[1];
    gMegaStruct.D_80134F28.z = gPlayerData[sp4].Pos.z;
    gMegaStruct.D_80134F34.x = arg0[2];
    gMegaStruct.D_80134F34.y = arg0[3];
    gMegaStruct.D_80134F34.z = arg0[4];
    gMegaStruct.D_80134F40 = arg0[5];
    gMegaStruct.D_80134FA4.unk2 = (s16) (s32) (f32) arg0[1]; //what the fuck
    gMegaStruct.D_80134FA8 = arg0[0];
    gMegaStruct.D_80134F50.x = 0.0f;
    gMegaStruct.D_80134F50.y = 0.0f;
    gMegaStruct.D_80134F50.z = 0.0f;
    gMegaStruct.D_80134F5C.x = 0.0f;
    gMegaStruct.D_80134F5C.y = 0.0f;
    gMegaStruct.D_80134F5C.z = 0.0f;
    gMegaStruct.D_80134F74 = 0.0f;
}

void func_8008B030(void) {
    gView.at.x = gMegaStruct.D_80134F28.x;
    gView.at.y = gMegaStruct.D_80134F28.y;
    gView.at.z = gMegaStruct.D_80134F28.z;
    gView.rot.x = gMegaStruct.D_80134F34.x;
    gView.rot.y = gMegaStruct.D_80134F34.y;
    gView.rot.z = gMegaStruct.D_80134F34.z;
    gView.dist = gMegaStruct.D_80134F40;
    if (D_8016E134 == 1) {
        gView.eye.x = gMegaStruct.D_80134F44.x;
        gView.eye.y = gMegaStruct.D_80134F44.y;
        gView.eye.z = gMegaStruct.D_80134F44.z;
    }
}

void func_8008B0F4(void) {
    s32 sp1C;
    f32 var_f18;

    if (D_80134C1A == 0) {
        gMegaStruct.D_80134F74 = 0.0f;
        D_80134C1A = -1;
    } else if (D_80134C1A != -1) {
        D_80134C1A -= 1;
    }
    if (D_80134C1C == 0) {
        gMegaStruct.D_80134F50.x = 0.0f;
        gMegaStruct.D_80134F50.y = 0.0f;
        gMegaStruct.D_80134F50.z = 0.0f;
        D_80134C1C = -1;
    } else if (D_80134C1C != -1) {
        D_80134C1C -= 1;
    }
    if (D_80134C1E == 0) {
        gMegaStruct.D_80134F5C.x = 0.0f;
        gMegaStruct.D_80134F5C.y = 0.0f;
        D_80134C1E = -1;
    } else if (D_80134C1E != -1) {
        D_80134C1E -= 1;
    }
    if (D_8016E134 == 0) {
        gMegaStruct.D_80134F34.x = func_80015538(gMegaStruct.D_80134F34.x, gMegaStruct.D_80134F5C.x);
        gMegaStruct.D_80134F34.y = func_80015538(gMegaStruct.D_80134F34.y, gMegaStruct.D_80134F5C.y);
        gMegaStruct.D_80134F40 = gMegaStruct.D_80134F40 + gMegaStruct.D_80134F74;
        if (gMegaStruct.D_80134FA4.unk0 == 0) {
            gMegaStruct.D_80134F28.x += gMegaStruct.D_80134F50.x;
            gMegaStruct.D_80134F28.y = gMegaStruct.D_80134F28.y + gMegaStruct.D_80134F50.y;
            gMegaStruct.D_80134F28.z = gMegaStruct.D_80134F28.z + gMegaStruct.D_80134F50.z;
        } else {
            sp1C = D_80134D48[gMegaStruct.D_80134FA8].unk0;
            gMegaStruct.D_80134F28.x = gPlayerData[sp1C].Pos.x;
            gMegaStruct.D_80134F28.y = gPlayerData[sp1C].Pos.y + (f32) gMegaStruct.D_80134FA4.unk2;
            gMegaStruct.D_80134F28.z = gPlayerData[sp1C].Pos.z;
        }
    } else {
        if (D_80134C20 == 0) {
            gMegaStruct.D_80134F68.x = 0.0f;
            gMegaStruct.D_80134F68.y = 0.0f;
            gMegaStruct.D_80134F68.z = 0.0f;
            D_80134C20 = -1;
        } else if (D_80134C20 != -1) {
            D_80134C20 -= 1;
        }
        gMegaStruct.D_80134F44.x = gMegaStruct.D_80134F44.x + gMegaStruct.D_80134F68.x;
        gMegaStruct.D_80134F44.y = gMegaStruct.D_80134F44.y + gMegaStruct.D_80134F68.y;
        gMegaStruct.D_80134F44.z = gMegaStruct.D_80134F44.z + gMegaStruct.D_80134F68.z;
        if (gMegaStruct.D_80134FA4.unk0 == 1) {
            sp1C = D_80134D48[gMegaStruct.D_80134FA8].unk0;
            gMegaStruct.D_80134F28.x = gPlayerData[sp1C].Pos.x;
            gMegaStruct.D_80134F28.y = gPlayerData[sp1C].Pos.y + (f32) gMegaStruct.D_80134FA4.unk2;
            gMegaStruct.D_80134F28.z = gPlayerData[sp1C].Pos.z;
        } else {
            gMegaStruct.D_80134F28.x += gMegaStruct.D_80134F50.x;
            gMegaStruct.D_80134F28.y = gMegaStruct.D_80134F28.y + gMegaStruct.D_80134F50.y;
            gMegaStruct.D_80134F28.z = gMegaStruct.D_80134F28.z + gMegaStruct.D_80134F50.z;
        }
    }
}

void func_8008B5D4(s16* arg0) {
    gMegaStruct.D_80134F74 = ((f32) arg0[0] - gMegaStruct.D_80134F40) / (f32) arg0[1];
    D_80134C1A = arg0[1];
}

void func_8008B624(s16* arg0) {
    gMegaStruct.D_80134F50.x = ((f32) arg0[0] - gMegaStruct.D_80134F28.x) / (f32) arg0[3];
    gMegaStruct.D_80134F50.y = ((f32) arg0[1] - gMegaStruct.D_80134F28.y) / (f32) arg0[3];
    gMegaStruct.D_80134F50.z = ((f32) arg0[2] - gMegaStruct.D_80134F28.z) / (f32) arg0[3];
    D_80134C1C = arg0[3] - 1;
}

void func_8008B6E0(s16* arg0) {
    if (arg0[3] == 0)
    {
        if((f32)(arg0[0]) / 10 < gMegaStruct.D_80134F34.x)
        {
            gMegaStruct.D_80134F5C.x = ((((f32)(arg0[0]) / 10) - gMegaStruct.D_80134F34.x) + 360) / arg0[2];
        }
        else
        {
            gMegaStruct.D_80134F5C.x = ((((f32)(arg0[0]) / 10) - gMegaStruct.D_80134F34.x)) / arg0[2];
        }
    }
    else if ((f32)(arg0[0]) / 10 <= gMegaStruct.D_80134F34.x)
    {
        gMegaStruct.D_80134F5C.x = ((((f32)(arg0[0]) / 10) - gMegaStruct.D_80134F34.x)) / arg0[2];
    }
    else
    {
        gMegaStruct.D_80134F5C.x = ((gMegaStruct.D_80134F34.x - ((f32)(arg0[0]) / 10) + 360) / arg0[2]) * -1;
    }

    if (arg0[4] == 0)
    {
        if((f32)(arg0[1]) / 10 < gMegaStruct.D_80134F34.y)
        {
            gMegaStruct.D_80134F5C.y = ((((f32)(arg0[1]) / 10) - gMegaStruct.D_80134F34.y) + 360) / arg0[2];
        }
        else
        {
            gMegaStruct.D_80134F5C.y = ((((f32)(arg0[1]) / 10) - gMegaStruct.D_80134F34.y)) / arg0[2];
        }
    }
    else if  ((f32)(arg0[1]) / 10 <= gMegaStruct.D_80134F34.y)
    {
        gMegaStruct.D_80134F5C.y = ((((f32)(arg0[1]) / 10) - gMegaStruct.D_80134F34.y)) / arg0[2];
    }
        else
    {
        gMegaStruct.D_80134F5C.y = ((gMegaStruct.D_80134F34.y - ((f32)(arg0[1]) / 10) + 360) / arg0[2]) * -1;
    }

    D_80134C1E = arg0[2];
}

void func_8008BA3C(void) {
    gMegaStruct.D_80134FA0.unk0 = (s16) D_801765EC;
    gMegaStruct.D_80134FA0.unk2 = (s16) D_8016E134;
    gMegaStruct.D_80134F78.x = gView.at.x;
    gMegaStruct.D_80134F78.y = gView.at.y;
    gMegaStruct.D_80134F78.z = gView.at.z;
    gMegaStruct.D_80134F84.x = gView.rot.x;
    gMegaStruct.D_80134F84.y = gView.rot.y;
    gMegaStruct.D_80134F84.z = gView.rot.z;
    gMegaStruct.D_80134F9C = gView.dist;
    gMegaStruct.D_80134F90.x = gView.eye.x;
    gMegaStruct.D_80134F90.y = gView.eye.y;
    gMegaStruct.D_80134F90.z = gView.eye.z;
}

void func_8008BB0C(void) {
    D_801765EC = (s32) gMegaStruct.D_80134FA0.unk0;
    D_8016E134 = (s8) gMegaStruct.D_80134FA0.unk2;
    gView.at.x = gMegaStruct.D_80134F78.x;
    gView.at.y = gMegaStruct.D_80134F78.y;
    gView.at.z = gMegaStruct.D_80134F78.z;
    gView.rot.x = gMegaStruct.D_80134F84.x;
    gView.rot.y = gMegaStruct.D_80134F84.y;
    gView.rot.z = gMegaStruct.D_80134F84.z;
    gView.eye.x = gMegaStruct.D_80134F90.x;
    gView.eye.y = gMegaStruct.D_80134F90.y;
    gView.eye.z = gMegaStruct.D_80134F90.z;
    gView.dist = gMegaStruct.D_80134F9C;
    gMegaStruct.D_80134FA4.unk0 = 0;
    gMegaStruct.D_80134FA4.unk2 = 0;
    func_80019B7C();
}

void func_8008BC04(s16* arg0) {
    gMegaStruct.D_80134F68.x = ((f32) arg0[0] - gMegaStruct.D_80134F44.x) / (f32) arg0[3];
    gMegaStruct.D_80134F68.y = ((f32) arg0[1] - gMegaStruct.D_80134F44.y) / (f32) arg0[3];
    gMegaStruct.D_80134F68.z = ((f32) arg0[2] - gMegaStruct.D_80134F44.z) / (f32) arg0[3];
    D_80134C20 = arg0[3];
}
