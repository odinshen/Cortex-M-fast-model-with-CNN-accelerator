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
 * Abstract interface class protocol_MouseStatus for protocol MouseStatus.
 */

#ifndef protocol_MouseStatus_h_
#define protocol_MouseStatus_h_

// Includes from the 'includes' section of this protocol
#line 28 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/MouseStatusProtocol.lisa"

#if (defined IEEE_1666_SYSTEMC)
#include "Protocols/MouseStatus/mouse_status_sockets.h"
#endif
    
#line 27 "./Linux64-Release-GCC-7.3/gen/protocol_MouseStatus.h"


// Abstract interface for protocol MouseStatus
class protocol_MouseStatus
{
public:
        virtual ~protocol_MouseStatus() {}
        // Abstract protocol members
	virtual void mouseMove(int dx, int dy) = 0;
	virtual void mouseButton(uint8_t button, bool down) = 0;

};

#endif /* protocol_MouseStatus_h_ */

