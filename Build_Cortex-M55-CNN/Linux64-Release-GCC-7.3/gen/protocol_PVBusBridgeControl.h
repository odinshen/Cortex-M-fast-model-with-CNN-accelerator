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
 * Abstract interface class protocol_PVBusBridgeControl for protocol PVBusBridgeControl.
 */

#ifndef protocol_PVBusBridgeControl_h_
#define protocol_PVBusBridgeControl_h_

// Includes from the 'includes' section of this protocol
#line 10 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/PVBusBridgeControlProtocol.lisa"

        #include <pv/slave_config_t.h>
    
#line 25 "./Linux64-Release-GCC-7.3/gen/protocol_PVBusBridgeControl.h"


// Abstract interface for protocol PVBusBridgeControl
class protocol_PVBusBridgeControl
{
public:
        virtual ~protocol_PVBusBridgeControl() {}
        // Abstract protocol members
	virtual void revokePrefetch(pv::bus_addr_t base, pv::bus_addr_t top) = 0;
	virtual void configure(pv::slave_config_t* ) = 0;

};

#endif /* protocol_PVBusBridgeControl_h_ */

