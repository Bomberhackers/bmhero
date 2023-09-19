#include <ultra64.h>

/**
 * Seems to parse a string of arguments, possibly treating the game like an executable at one
 * point.
 */
void HS_ParseArg(u8* arg0) {
    s32 argcount = 1;
    u8* buf[0x20];
    u8** bufptr;
    u8* sp4;

    bufptr = &buf;

    if(arg0 == 0 || (*arg0 == 0))
    {
        return;
    }

    sp4 = arg0;

    while(*sp4 != 0) {
        while(*sp4 != 0 && *sp4 == ' ')
        {
            *sp4 = 0;
            sp4 += 1;
        }
    

        if(*sp4 != 0)
        {
            buf[argcount] = sp4;
            argcount++;
        }
    
        while(*sp4 != 0 && *sp4 != ' ')
        {
            sp4 += 1;        
        }        
    }

    while(argcount >= 2 && *bufptr[1] == '-') {
        switch((bufptr[1][1])) {
            // checks for 4 possible args.
            // the only one that has a tangible effect is -d, which does not allow the game to
            // init past the init thread.
            case('d'): // '-d'
                D_8004A384 = 1;
                break;
            case('v'): // '-v'
                D_8004A380 = 1;
                break;
            case('s'): // '-s'
                D_8004A388 = 1;
                break;
            case('l'): // '-l'
                D_8004A38C = 1;
                break;
            default:
                break;
        }
        argcount--;
        bufptr++;            
    }
}
