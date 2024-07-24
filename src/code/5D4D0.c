#include <ultra64.h>
#include "7B0A0.h"

void func_8006AFB0(void) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    sp24 = (f32) func_80014E80(-0x3C0) + gView.at.x;
    sp20 = (f32) func_80014E80(0xF0) + (gView.at.y + 540.0f);
    sp1C = (f32) func_80014E80(-0x3C0) + gView.at.z;
    func_80067748(sp24, sp20, sp1C);
    if (!(D_801776E0 & 1)) {
        func_80081468(0x2C1, sp24, sp20, sp1C);
    }
}

void func_8006B084(void) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    if (D_801775EE == 0) {
        D_801775EE = 1;
        D_80177933 = 0;
    }
    if (D_80177933 == 0) {
        D_80177933 = 5;
        sp24 = (f32) func_80014E80(-960) + gView.at.x;
        sp20 = (f32) func_80014E80(240) + (gView.at.y + 540.0f);
        sp1C = (f32) func_80014E80(-960) + gView.at.z;
        func_80067748(sp24, sp20, sp1C);
        if (!(D_801776E0 & 1)) {
            func_80081468(706, sp24, sp20, sp1C);
        }
    }
    D_80177933 -= 1;
}

void func_8006B1B4(void) {
    s32 sp04;
    return; //stubbed?
    if(D_801775EE == 0)
    {
        D_801775EE = 1;
        D_80177936 = 0;
        D_80177939 = 0;
    }

    if(D_80177939 == 0)
    {
        if(gPlayerObject->Pos.x >= 3600.0f)
        {
            D_80177939 = 1; 
        }

        if(D_80177936 == 0)
        {
            sp04 = (s32) (3000.0f - gPlayerObject->Pos.x);
            if(sp04 < 0)
            {
                sp04 = 0;
            }            
            else if(sp04 > 4000)
            {
                sp04 = 4000;
            }
            
            sp04 = (sp04 / 30) + 10;
            
            D_80177936 = sp04;
            D_801775BC = 3;
            D_801775C4 = 200;
            D_801775CC = 0;
            D_801775D4 = 0;
            D_801775DC = 200;
            D_801775E4 = 50;
            D_801775EC = 50;
        }
        else
        {
            D_80177936--;
        }
    }

    if(D_801775C4 != 0)
    {
        D_801775C4 -= 10;
        D_801775DC = D_801775C4;
        if(D_801775DC < 50)
        {
            D_801775DC = 50;
        }
    }
}

void func_8006B3BC(void) {
    f32 sp34; //unused
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp24;


    if (D_801775EE == 0) {
        D_801775EE = 1;
        D_8017793C = 0;
    }

    if(gPlayerObject->Pos.y < 480.0f)
    {
        if (D_8017793C == 0)
        {
            D_8017793C = func_80014E80(0xA) + 15;
            if(gPlayerObject->Vel.x == 0.0f && gPlayerObject->Vel.z == 0.0f)
            {
                sp30 = (f32)func_80014E80(-480) + gPlayerObject->Pos.x;
            }
            else
            {
                sp30 = (f32)func_80014E80(-960) + gPlayerObject->Pos.x;
            }

            sp2C = gPlayerObject->Pos.y + 540.0f;
            sp28 = (f32)func_80014E80(-240) + gPlayerObject->Pos.z;
            func_80067748(sp30, sp2C, sp28);
            if(D_801776E0 % 2 == 0)
            {
                sp24 = func_80027464(1, &D_8011472C, sp30, sp2C, sp28, 0.0f);
            }
        }
        else
        {
            D_8017793C -= 1;
        }
    }
}

void func_8006B5A4(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
        func_80017BEC(0, 0x35, -1, 0);
    }
}

void func_8006B5F8(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
        func_80017BEC(0, 0x35, -1, 0);
    }
}

void func_8006B64C(void) {
    s32 sp24;
    s32 sp28;

    if (D_801775EE == 0) {
        D_801775EE = 1;
        D_8017793F = 0;
    }
    if ((D_8017793F == 0) && (D_80165242 >= 0xA)) 
    {
        sp24 = 0xE;
        while(1)
        {
            sp24 = func_80026E58(0x54, sp24);
            if(sp24 == -1)
            {
                break;
            }
            else
            {
                gObjects[sp24].unkA8 = 1;
                func_800178D4(-1, 0, 0x61, -1, 0);
                D_8017793F = 1;
                break;
            }            
        }
    }
}

void func_8006B754(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
    }
    func_80017BEC(0, 0x38, -1, 1);
    func_80017CFC(0, 0x38, -1, 0);
}

void func_8006B7BC(void) {
    s32 sp24;

    if (D_801775EE == 0) {
        D_801775EE = 1;
        D_8017792D = 0;
    }

    if ((D_8017792D == 0) && (D_80165242 >= 9))
    {
        func_800178D4(-1, 0, 0x61, -1, 0);
        sp24 = 0xE;
        while(1)
        {
            sp24 = func_80026E58(0x164, sp24);
            if(sp24 == -1)
            {
                break;
            }
            else
            {
                gObjects[sp24].unkA4 = 2;
                D_8017792D = 1;
                sp24 += 1;
            }
        }
    }
}

void func_8006B8CC(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
        func_80017BEC(0, 0x35, -1, 0);
    }
}

void func_8006B920(void) {
    if (D_80134C22 != 0) {
        if (D_80177950 == 0) {
            func_80017BEC(0, 0x78, -1, 2);
            D_80177950 = 8;
        } else {
            D_80177950 -= 1;
        }
    }
}

void func_8006B9A0(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
        func_80017BEC(0, 0x35, -1, 0);
    }
}

void func_8006B9F4(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
    }
    func_80017BEC(0, 0x3C, -1, 1);
    func_80017CFC(0, 0x3C, -1, 0);
}

void func_8006BA5C(void) {
    if (D_801775EE == 0) {
        D_801775EE = 1;
    }
    func_80017BEC(0, 0x3C, -1, 1);
    func_80017CFC(0, 0x3C, -1, 0);
}

void func_8006BAC4(void) {
    s32 sp1C;

    if (D_801775EE == 0) {
        D_801775EE = 1;
        D_80177942 = 0x32;
        D_80177946 = 0xFF;
    }
    
    sp1C = 0xE;
    
    while(1)
    {
        sp1C = func_80026E58(0x267, sp1C);
        
        if (sp1C == -1) 
        {
            break;
        }
        else 
        {
            if(D_80177942 == 0)
            {
                if (D_80177946 % 2 == 0)
                {
                    func_80081468(0x2C7, gObjects[sp1C].Pos.x, gObjects[sp1C].Pos.y, gObjects[sp1C].Pos.z);
                }         
                D_80177946 -= 1;
            }
            else D_80177942 -= 1;
            
            break;
        }
    }
}

void func_8006BBF4(void) {
    s32 sp34;

    if (func_80014E80(0x1E) == 0) {
        func_80017BEC(0, 0x36, -1, 2);
    }

    sp34 = 0xE;
    while(1)
    {
        sp34 = func_80026E58(0x26A, sp34);
        if (sp34 == -1) {
            break;
        }
        else
        {
            if (func_80014E80(3) == 0) 
            {
                func_80081468(0x2BC, gObjects[sp34].Pos.x + (f32)func_80014E80(-0x14), 
                    gObjects[sp34].Pos.y + (f32)func_80014E80(-0xA) , 
                    gObjects[sp34].Pos.z +(f32)func_80014E80(-0x14));
            }
            if (D_80134C22 != 0)
            {
                if (func_80014E80(0xF) == 0)
                {
                    func_80081468(0x2CD, gObjects[sp34].Pos.x + (f32)func_80014E80(-0x190), 
                        gObjects[sp34].Pos.y + (f32)func_80014E80(-0x12C) , 
                        gObjects[sp34].Pos.z +(f32)func_80014E80(-0x12C));
                    break;
                }
            }
            else if(func_80014E80(0x23) == 0)
            {
                func_80081468(0x2CD, gObjects[sp34].Pos.x + (f32)func_80014E80(-0x320), 
                    gObjects[sp34].Pos.y + (f32)(func_80014E80(-0x12C) + 0xC8), 
                    gObjects[sp34].Pos.z + (f32)(func_80014E80(-0x12C)));
                break;
            }
        }
    }
}

void func_8006BE9C(void) {
    if (D_801775EE == 0) {
        D_801775EE += 1;
        D_80177958 = 0;
    }
    if (D_80134C22 != 0) {
        if (D_80177958 == 0) {
            gMegaStruct.D_80134F28.x += 2.0f;
            D_80177958 += 1;
        }
        else
        {
            gMegaStruct.D_80134F28.x -= 2.0f;
            D_80177958 = 0;
        }
    }
}

void func_8006BF5C(void) {
    s32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    if (D_801775EE == 0) {
        D_8017794A = 0;
    }

    if(D_80134C22 != 0)
    {
        sp24 = 0xE;
        while(1)
        {
            sp24 = func_80026E58(0x281, sp24);
            if (sp24 == -1) 
            {
                break;
            }
            else
            {
                if (D_8017794A == 0)
                {
                    sp1C = sinf((f32) (((f64)gObjects[sp24].unk3C) * 0.017453292519943295)) * -90.0f;
                    sp18 = cosf((f32) (((f64)gObjects[sp24].unk3C) * 0.017453292519943295)) * -90.0f;

                    func_80067748(gObjects[sp24].Pos.x + sp1C, gObjects[sp24].Pos.y, gObjects[sp24].Pos.z + sp18);
                    sp20 = D_80177760[D_801776E0 & 1];
                    func_80081468(0x2BD, gObjects[sp24].Pos.x + sp1C, sp20, gObjects[sp24].Pos.z + sp18);
                    D_8017794A = 2;
                }
                D_8017794A -= 1;
                break;
            }
        }        
    }
}

void func_8006C18C(void) {
    if ((D_80134C22 != 0) && (D_801775EE == 0)) {
        D_801775EE = 1;
        D_801348B2 = 1;
    }
}

void func_8006C1DC(void) {
    switch (gCurrentLevel) {
    case 0x4:
        func_8006B1B4();
        break;
    case 0xE:
        func_8006B3BC();
        break;
    case 0x18:
        func_8006B5A4();
        break;
    case 0x19:
        func_8006B5F8();
        break;
    case 0x21:
        func_8006B64C();
        break;
    case 0x28:
        func_8006B754();
        break;
    case 0x3C:
        func_8006B084();
        break;
    case 0x41:
        func_8006AFB0();
        func_8006B7BC();
        break;
    case 0x55:
        func_8006B084();
        break;
    case 0x85:
        func_8006B8CC();
        break;
    case 0x90:
        func_8006B920();
        break;
    case 0x91:
        func_8006B920();
        break;
    case 0x99:
        func_8006B9A0();
        break;
    case 0x9F:
        func_8006B9F4();
        break;
    case 0xA0:
        func_8006BA5C();
        break;
    case 0xA8:
        func_8006BAC4();
        break;
    case 0xA4:
        func_8006B920();
        break;
    case 0xA9:
        func_8006BBF4();
        break;
    case 0xAA:
        func_8006BE9C();
        break;
    case 0xAC:
        func_8006BF5C();
        break;
    case 0xBB:
        func_8006C18C();
        break;
    }
}