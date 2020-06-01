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
 * Abstract interface class protocol_SystemCoherencyInterface for protocol SystemCoherencyInterface.
 */

#ifndef protocol_SystemCoherencyInterface_h_
#define protocol_SystemCoherencyInterface_h_

// Includes from the 'includes' section of this protocol
#line 24 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/SystemCoherencyInterface.lisa"

        namespace SystemCoherency {
            class DownstreamAction;
            class UpstreamAction;
        }

        #include "Protocols/SystemCoherencyInterface/sci_sockets.h"
        #include "Protocols/SystemCoherencyInterface/sci_base.h"
    
#line 31 "./Linux64-Release-GCC-7.3/gen/protocol_SystemCoherencyInterface.h"


// Abstract interface for protocol SystemCoherencyInterface
class protocol_SystemCoherencyInterface
{
public:
        virtual ~protocol_SystemCoherencyInterface() {}
        // Abstract protocol members
	virtual bool doDownstreamAction(const SystemCoherency::DownstreamAction& ) = 0;
	virtual bool doUpstreamAction(const SystemCoherency::UpstreamAction& ) = 0;

};

#endif /* protocol_SystemCoherencyInterface_h_ */

