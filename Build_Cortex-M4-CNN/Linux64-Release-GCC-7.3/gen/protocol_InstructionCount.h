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
 * Abstract interface class protocol_InstructionCount for protocol InstructionCount.
 */

#ifndef protocol_InstructionCount_h_
#define protocol_InstructionCount_h_

// Includes from the 'includes' section of this protocol
#line 8 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/InstructionCountProtocol.lisa"

        #if (defined IEEE_1666_SYSTEMC)
            #include "Protocols/InstructionCount/instruction_count_sockets.h"
        #endif
    
#line 27 "./Linux64-Release-GCC-7.3/gen/protocol_InstructionCount.h"


// Abstract interface for protocol InstructionCount
class protocol_InstructionCount
{
public:
        virtual ~protocol_InstructionCount() {}
        // Abstract protocol members
	virtual uint64_t getValue() = 0;
	virtual uint32_t getRunState() = 0;

};

#endif /* protocol_InstructionCount_h_ */

