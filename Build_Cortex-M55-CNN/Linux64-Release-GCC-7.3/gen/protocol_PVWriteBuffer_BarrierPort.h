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
 * Abstract interface class protocol_PVWriteBuffer_BarrierPort for protocol PVWriteBuffer_BarrierPort.
 */

#ifndef protocol_PVWriteBuffer_BarrierPort_h_
#define protocol_PVWriteBuffer_BarrierPort_h_

// Includes from the 'includes' section of this protocol
#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/PVWriteBuffer.lisa"

        #include "pv/PVWriteBufferComponent.h"

        using namespace pv;
    
#line 27 "./Linux64-Release-GCC-7.3/gen/protocol_PVWriteBuffer_BarrierPort.h"


// Abstract interface for protocol PVWriteBuffer_BarrierPort
class protocol_PVWriteBuffer_BarrierPort
{
public:
        virtual ~protocol_PVWriteBuffer_BarrierPort() {}
        // Abstract protocol members
	virtual void notify(PVWriteBuffer_BarrierPort::barrier_t type) = 0;
	virtual void CleanByAddr(bus_addr_t addr, bool ns) = 0;

};

#endif /* protocol_PVWriteBuffer_BarrierPort_h_ */

