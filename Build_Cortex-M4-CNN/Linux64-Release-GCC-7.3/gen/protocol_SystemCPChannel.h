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
 * Abstract interface class protocol_SystemCPChannel for protocol SystemCPChannel.
 */

#ifndef protocol_SystemCPChannel_h_
#define protocol_SystemCPChannel_h_

// Includes from the 'includes' section of this protocol
#line 14 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Common/Protocols/LISA/SystemCPChannelProtocol.lisa"

#include "sg/SGPChannel.h"
#include "Protocols/pchannel/convenience_pchannel_sockets.h"
#include "Protocols/pchannel/pchannel_simgen.h"

    
#line 28 "./Linux64-Release-GCC-7.3/gen/protocol_SystemCPChannel.h"


// Abstract interface for protocol SystemCPChannel
class protocol_SystemCPChannel
{
public:
        virtual ~protocol_SystemCPChannel() {}
        // Abstract protocol members
	virtual pchannel::presp_t prequest(uint32_t pstate) = 0;
	virtual void pactive(uint32_t pstate) = 0;

};

#endif /* protocol_SystemCPChannel_h_ */

