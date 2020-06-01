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
 * Abstract interface class protocol_AMBAPVValueState64 for protocol AMBAPVValueState64.
 */

#ifndef protocol_AMBAPVValueState64_h_
#define protocol_AMBAPVValueState64_h_

// Includes from the 'includes' section of this protocol
#line 53 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/AMBAPVValue64Protocol.lisa"

        #include <amba_pv.h>
        #include <stdint.h>
    
#line 26 "./Linux64-Release-GCC-7.3/gen/protocol_AMBAPVValueState64.h"


// Abstract interface for protocol AMBAPVValueState64
class protocol_AMBAPVValueState64
{
public:
        virtual ~protocol_AMBAPVValueState64() {}
        // Abstract protocol members
	virtual void set_state(int export_id, const uint64_t& value) = 0;
	virtual uint64_t get_state(int export_id, tlm::tlm_tag<uint64_t> * t) = 0;

};

#endif /* protocol_AMBAPVValueState64_h_ */

