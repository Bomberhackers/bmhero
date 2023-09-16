#include <ultra64.h>

extern s32 D_8004A380;
extern s32 D_8004A384;
extern s32 D_8004A388;
extern s32 D_8004A38C;

//function is pretty much just a stub, only time it gets called is in main with the argument 0
void func_8000E3E0(u8* arg0) {
    s32 sp8C;
    u8* spC[0x20];
    u8** sp8;
    u8* sp4;

    sp8C = 1;
    sp8 = &spC;

    if(arg0 == 0 || (*arg0 == 0))
    {
        return;
    }

    sp4 = arg0;

    while(*sp4 != 0)
    {
        while(*sp4 != 0 && *sp4 == 0x20)
        {
            *sp4 = 0;
            sp4 += 1;
        }
    

        if(*sp4 != 0)
        {
            spC[sp8C] = sp4;
            sp8C++;
        }
    
        while(*sp4 != 0 && *sp4 != 0x20)
        {
            sp4 += 1;        
        }        
    }

    if(sp8C >= 0x2 && *(sp8[1]) == 0x2D)
    {
        do
        {
            switch((sp8[1][1]))
                {
                    case(0x64):
                        {
                            D_8004A384 = 1;
                            break;
                        }
                    case(0x76):
                        {
                            D_8004A380 = 1;
                            break;
                        }
                    case(0x73):
                        {
                            D_8004A388 = 1;
                            break;
                        }
                    case(0x6C):
                        {
                            D_8004A38C = 1;
                            break;
                        }
                    default:
                        {
                            break;
                        }
                }
            sp8C--;
            sp8++;            
        }
        while(sp8C >= 2 && *sp8[1] == 0x2D);
    }
}
