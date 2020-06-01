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
 * Abstract interface class protocol_EventBus for protocol EventBus.
 */

#ifndef protocol_EventBus_h_
#define protocol_EventBus_h_

// Includes from the 'includes' section of this protocol
#line 11 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/EventBus.lisa"

        #include "sg/SGComponentTrace.h"
    
#line 25 "./Linux64-Release-GCC-7.3/gen/protocol_EventBus.h"


// Abstract interface for protocol EventBus
class protocol_EventBus
{
public:
        virtual ~protocol_EventBus() {}
        // Abstract protocol members
	virtual void publishEventSource(uint32_t index, sg::EventSourceBase* src) = 0;

};

#endif /* protocol_EventBus_h_ */

