#include <ultra64.h>

/**************************************************************
	LZSS.C -- A Data Compression Program
	(tab = 4 spaces)
***************************************************************
	4/6/1989 Haruhiko Okumura
---------------------------------------------------------------
    This version is a modification of LZSS.C for Bomberman Hero.
    Original version by Okumura.
---------------------------------------------------------------

***************************************************************/

#define N		 4096	/* size of ring buffer */
#define F		   18	/* upper limit for match_length */
#define THRESHOLD	2   /* encode string into position and length
						   if match_length is greater than this */
#define NIL			N	/* index for root of binary search trees */

#define EOF        -1

/**
 * Retrieve a short from the buffer. (Why are they using shorts and not bytes?
 */
s16 hgetc(u8** buf, s32* arg1) {
    s16 c;

    if (*arg1 == 0) {
        return -1;
    }
    *arg1 -= 1;
    c = (s16) **buf;
    *buf += 1;
    return c;
}

/**
 * Place a character in the buffer.
 */
void hputc(s16 c, u8** buf) {
    **buf = (char) c;
    *buf += 1;
}

/**
 * Decode a given LZSS binary; modified routine from the original 1989 public domain code.
 */
int Decode(u8* buf_in, u8* buf_out) {
    s16 i, j, k, r, c;
    u16 flags;
    s32 sp20;
    s32 size;

    // bits added to original 1989 LZSS routine written by Haruhiko Okumura.
    size = 0;
    sp20 = 0;

    for(i = 3; i >= 0; i--)
        sp20 = buf_in[i] + (sp20 << 8);
    buf_in += 4;

    for (i = 0; i < N - F; i++) text_buf[i] = 0;
    r = N - F;  flags = 0;
    for ( ; ; ) {
        if (((flags >>= 1) & 256) == 0) {
            if((c = hgetc(&buf_in, &sp20)) == EOF) break;
            flags = c | 0xff00;		/* uses higher byte cleverly */
        }							/* to count eight */
        if(flags & 1) {
            if((c = hgetc(&buf_in, &sp20)) == EOF) break;
            hputc(c, &buf_out); size += 1; text_buf[r++] = c; r &= (N - 1);
        } else {
            if((i = hgetc(&buf_in, &sp20)) == EOF) break;
            if((j = hgetc(&buf_in, &sp20)) == EOF) break;
            i |= ((j & 0xf0) << 4);  j = (j & 0x0f) + THRESHOLD;
            for(k = 0; k <= j; k++) {
                c = text_buf[(i + k) & (N - 1)];
                hputc(c, &buf_out); size += 1; text_buf[r++] = c; r &= (N - 1);
            }
        }
    }

    return size;
}
