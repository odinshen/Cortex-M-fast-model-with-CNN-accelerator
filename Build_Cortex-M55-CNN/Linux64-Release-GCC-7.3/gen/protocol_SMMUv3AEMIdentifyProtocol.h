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
 * Abstract interface class protocol_SMMUv3AEMIdentifyProtocol for protocol SMMUv3AEMIdentifyProtocol.
 */

#ifndef protocol_SMMUv3AEMIdentifyProtocol_h_
#define protocol_SMMUv3AEMIdentifyProtocol_h_

// Includes from the 'includes' section of this protocol
#line 8 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/SMMUv3AEMIdentifyProtocol.lisa"

#include "pv/TransactionAttributes.h"
    
#line 25 "./Linux64-Release-GCC-7.3/gen/protocol_SMMUv3AEMIdentifyProtocol.h"


// Abstract interface for protocol SMMUv3AEMIdentifyProtocol
class protocol_SMMUv3AEMIdentifyProtocol
{
public:
        virtual ~protocol_SMMUv3AEMIdentifyProtocol() {}
        // Abstract protocol members
	virtual void identify(unsigned tbu_number_, const pv::TransactionAttributes* attributes_, bool* out_ssd_ns_, unsigned* out_streamid_, unsigned* out_substreamid_) = 0;

};

#endif /* protocol_SMMUv3AEMIdentifyProtocol_h_ */

