/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2007 ARM Limited.
 * Copyright 2011 ARM Limited.
 *
 * All rights reserved.
 */

/** \file
 * Abstract interface class protocol_AudioControl for protocol AudioControl.
 */

#ifndef protocol_AudioControl_h_
#define protocol_AudioControl_h_

// Includes from the 'includes' section of this protocol
#line 28 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/AudioControlProtocol.lisa"

#include "components/PVAudioBuffer.h"

#if (defined IEEE_1666_SYSTEMC)
#include "Protocols/AudioControl/audio_control_sockets.h"
#endif
    
#line 29 "./Linux64-Release-GCC-7.3/gen/protocol_AudioControl.h"


// Abstract interface for protocol AudioControl
class protocol_AudioControl
{
public:
        virtual ~protocol_AudioControl() {}
        // Abstract protocol members
	virtual PVAudioBuffer* getPVAudioBuffer(uint32_t depth) = 0;
	virtual void releasePVAudioBuffer(PVAudioBuffer* buf) = 0;

};

#endif /* protocol_AudioControl_h_ */

