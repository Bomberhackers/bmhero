/*====================================================================
 * synquickstartvoice
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

#include "synthInternals.h"
#include <libaudio.h>
#include <ultraerror.h>
#include <os_internal.h>

#if BUILD_VERSION < VERSION_J
#ident "$Revision: 1.17 $"
#endif

extern u8 D_80052DB7;

void alSynStartVoiceParams(ALSynth* s, ALVoice* v, ALWaveTable* w, f32 pitch, s16 vol, ALPan pan, u8 fxmix,
                           ALMicroTime t) {
    ALStartParamAlt* update;
    ALFilter* f;

    if (v->pvoice) {
        /*
         * get new update struct from the free list
         */
        update = (ALStartParamAlt*) __allocParam();
        ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

        /*
         * set offset and fxmix data
         */
        update->delta = s->paramSamples + v->pvoice->offset;
        update->next = 0;
        update->type = AL_FILTER_START_VOICE_ALT;

        update->unity = v->unityPitch;

        if (D_80052DB7 & 1) {
            update->pan = 64;
        } else {
            update->pan = pan;
        }
        update->volume = vol;
        update->fxMix = fxmix;
        update->pitch = pitch;
        update->samples = _timeToSamples(s, t);
        update->wave = w;

        f = v->pvoice->channelKnob;
        (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);
    }
}
