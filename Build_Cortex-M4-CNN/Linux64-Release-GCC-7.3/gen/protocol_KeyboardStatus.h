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
 * Abstract interface class protocol_KeyboardStatus for protocol KeyboardStatus.
 */

#ifndef protocol_KeyboardStatus_h_
#define protocol_KeyboardStatus_h_

// Includes from the 'includes' section of this protocol
#line 28 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/KeyboardStatusProtocol.lisa"

#include "components/KeyCode.h"

#if (defined IEEE_1666_SYSTEMC)
#include "Protocols/KeyboardStatus/keyboard_status_sockets.h"
#endif
    
#line 29 "./Linux64-Release-GCC-7.3/gen/protocol_KeyboardStatus.h"


// Abstract interface for protocol KeyboardStatus
class protocol_KeyboardStatus
{
public:
        virtual ~protocol_KeyboardStatus() {}
        // Abstract protocol members
	virtual void keyDown(ATKeyCode code) = 0;
	virtual void keyUp(ATKeyCode code) = 0;

};

#endif /* protocol_KeyboardStatus_h_ */

