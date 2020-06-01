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
 * Abstract interface class protocol_CounterInterface for protocol CounterInterface.
 */

#ifndef protocol_CounterInterface_h_
#define protocol_CounterInterface_h_

// Includes from the 'includes' section of this protocol
#line 30 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/CounterInterface.lisa"

#if (defined IEEE_1666_SYSTEMC)
#include "Protocols/CounterInterface/counter_interface_sockets.h"
#endif
    
#line 27 "./Linux64-Release-GCC-7.3/gen/protocol_CounterInterface.h"


// Abstract interface for protocol CounterInterface
class protocol_CounterInterface
{
public:
        virtual ~protocol_CounterInterface() {}
        // Abstract protocol members
	virtual uint64_t getCounterValue() = 0;
	virtual void requestSignalUpdate(uint64_t at) = 0;
	virtual void signalUpdate() = 0;
	virtual void setEnabled(bool _bool_0) = 0;
	virtual void requestEventUpdate(uint64_t at) = 0;
	virtual void eventUpdate() = 0;

};

#endif /* protocol_CounterInterface_h_ */

