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
 * Abstract interface class protocol_FlashLoaderPort for protocol FlashLoaderPort.
 */

#ifndef protocol_FlashLoaderPort_h_
#define protocol_FlashLoaderPort_h_

// Includes from the 'includes' section of this protocol
#line 10 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/FlashLoaderPort.lisa"

        #include "components/FlashLoader.h"
    
#line 25 "./Linux64-Release-GCC-7.3/gen/protocol_FlashLoaderPort.h"


// Abstract interface for protocol FlashLoaderPort
class protocol_FlashLoaderPort
{
public:
        virtual ~protocol_FlashLoaderPort() {}
        // Abstract protocol members
	virtual uint32_t loadFlashFile(FlashLoader* loader) = 0;
	virtual uint32_t saveFlashFile(FlashLoader* loader) = 0;

};

#endif /* protocol_FlashLoaderPort_h_ */

