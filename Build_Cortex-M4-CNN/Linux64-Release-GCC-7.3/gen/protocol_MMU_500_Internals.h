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
 * Abstract interface class protocol_MMU_500_Internals for protocol MMU_500_Internals.
 */

#ifndef protocol_MMU_500_Internals_h_
#define protocol_MMU_500_Internals_h_

// Includes from the 'includes' section of this protocol
#line 68 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/SMMU_500_BASE.lisa"

        namespace MMU_500
        {
            class mmu_500_if;
        }
    
#line 28 "./Linux64-Release-GCC-7.3/gen/protocol_MMU_500_Internals.h"


// Abstract interface for protocol MMU_500_Internals
class protocol_MMU_500_Internals
{
public:
        virtual ~protocol_MMU_500_Internals() {}
        // Abstract protocol members
	virtual MMU_500::mmu_500_if* getMMU_500() = 0;

};

#endif /* protocol_MMU_500_Internals_h_ */

