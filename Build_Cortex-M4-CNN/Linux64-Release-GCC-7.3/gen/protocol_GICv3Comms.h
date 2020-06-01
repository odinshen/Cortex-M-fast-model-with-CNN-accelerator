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
 * Abstract interface class protocol_GICv3Comms for protocol GICv3Comms.
 */

#ifndef protocol_GICv3Comms_h_
#define protocol_GICv3Comms_h_

// Includes from the 'includes' section of this protocol
#line 12 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/GICv3Comms.lisa"

        #if (defined IEEE_1666_SYSTEMC)
            #include "Protocols/GICv3Comms/gicv3_comms_sockets.h"
            #include "Protocols/GICv3Comms/gicv3_comms_base.h"
        #endif
    
#line 28 "./Linux64-Release-GCC-7.3/gen/protocol_GICv3Comms.h"


// Abstract interface for protocol GICv3Comms
class protocol_GICv3Comms
{
public:
        virtual ~protocol_GICv3Comms() {}
        // Abstract protocol members
	virtual void sendTowardsCPU(uint8_t len, const uint8_t* data) = 0;
	virtual void sendTowardsTopLevel(uint8_t len, const uint8_t* data) = 0;
	virtual void setAXIMasterID(uint32_t master_id) = 0;

};

#endif /* protocol_GICv3Comms_h_ */

