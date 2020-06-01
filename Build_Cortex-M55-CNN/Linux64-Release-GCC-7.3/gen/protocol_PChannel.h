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
 * Abstract interface class protocol_PChannel for protocol PChannel.
 */

#ifndef protocol_PChannel_h_
#define protocol_PChannel_h_

// Includes from the 'includes' section of this protocol
#line 14 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/PChannelProtocol.lisa"

#include "sg/SGPChannel.h"
    
#line 25 "./Linux64-Release-GCC-7.3/gen/protocol_PChannel.h"


// Abstract interface for protocol PChannel
class protocol_PChannel
{
public:
        virtual ~protocol_PChannel() {}
        // Abstract protocol members
	virtual sg::PChannel::presp_t prequest(uint32_t pstate) = 0;
	virtual void pactive(uint32_t pstate) = 0;

};

#endif /* protocol_PChannel_h_ */

