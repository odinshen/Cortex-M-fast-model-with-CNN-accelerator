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
 * Abstract interface class protocol_PVCacheDebugRam for protocol PVCacheDebugRam.
 */

#ifndef protocol_PVCacheDebugRam_h_
#define protocol_PVCacheDebugRam_h_

// Includes from the 'includes' section of this protocol
#line 15 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/PVCache_DebugRamProtocol.lisa"

       #include  "pv/PVCache_DebugRamPort.h"

        namespace sg_deferred_actions {
            class deferred_actions_t;
        }
    
#line 29 "./Linux64-Release-GCC-7.3/gen/protocol_PVCacheDebugRam.h"


// Abstract interface for protocol PVCacheDebugRam
class protocol_PVCacheDebugRam
{
public:
        virtual ~protocol_PVCacheDebugRam() {}
        // Abstract protocol members
	virtual void getConfig(pv::PVCache_DebugConfig& config) = 0;
	virtual bool peekLine(const pv::PVCache_DebugFilter& filter, pv::PVCache_DebugLine& buffer) = 0;
	virtual bool pokeLine(const pv::PVCache_DebugFilter& filter, const pv::PVCache_DebugLine& buffer) = 0;
	virtual sg_deferred_actions::deferred_actions_t* getDeferredActions() = 0;
	virtual uint64_t getAttribute(pv::PVCache_DebugRamPort::Attribute attribute, unsigned index) = 0;

};

#endif /* protocol_PVCacheDebugRam_h_ */

