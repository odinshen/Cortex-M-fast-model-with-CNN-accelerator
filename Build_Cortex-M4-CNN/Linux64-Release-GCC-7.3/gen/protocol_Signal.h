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
 * Abstract interface class protocol_Signal for protocol Signal.
 */

#ifndef protocol_Signal_h_
#define protocol_Signal_h_

// Includes from the 'includes' section of this protocol
#line 17 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/SignalProtocol.lisa"

        #include "sg/SGSignal.h"
    
#line 25 "./Linux64-Release-GCC-7.3/gen/protocol_Signal.h"


// Abstract interface for protocol Signal
class protocol_Signal
{
public:
        virtual ~protocol_Signal() {}
        // Abstract protocol members
	virtual void setValue(sg::Signal::State ) = 0;

};

#endif /* protocol_Signal_h_ */

