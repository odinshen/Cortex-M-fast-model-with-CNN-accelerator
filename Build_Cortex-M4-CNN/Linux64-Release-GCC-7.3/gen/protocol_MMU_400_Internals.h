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
 * Abstract interface class protocol_MMU_400_Internals for protocol MMU_400_Internals.
 */

#ifndef protocol_MMU_400_Internals_h_
#define protocol_MMU_400_Internals_h_

// Includes from the 'includes' section of this protocol
#line 42 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/SMMU_400_BASE.lisa"

        namespace MMU_400
        {
            class mmu_400_if;
        }
    
#line 28 "./Linux64-Release-GCC-7.3/gen/protocol_MMU_400_Internals.h"


// Abstract interface for protocol MMU_400_Internals
class protocol_MMU_400_Internals
{
public:
        virtual ~protocol_MMU_400_Internals() {}
        // Abstract protocol members
	virtual MMU_400::mmu_400_if* getMMU_400() = 0;

};

#endif /* protocol_MMU_400_Internals_h_ */

