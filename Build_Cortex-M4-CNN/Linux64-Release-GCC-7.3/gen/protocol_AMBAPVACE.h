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
 * Abstract interface class protocol_AMBAPVACE for protocol AMBAPVACE.
 */

#ifndef protocol_AMBAPVACE_h_
#define protocol_AMBAPVACE_h_

// Includes from the 'includes' section of this protocol
#line 9 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/AMBAPVACEProtocol.lisa"

        #include <amba_pv.h>
    
#line 25 "./Linux64-Release-GCC-7.3/gen/protocol_AMBAPVACE.h"


// Abstract interface for protocol AMBAPVACE
class protocol_AMBAPVACE
{
public:
        virtual ~protocol_AMBAPVACE() {}
        // Abstract protocol members
	virtual void b_transport(int socket_id, amba_pv::amba_pv_transaction& trans, sc_core::sc_time& t) = 0;
	virtual unsigned int transport_dbg(int socket_id, amba_pv::amba_pv_transaction& trans) = 0;
	virtual bool get_direct_mem_ptr(int socket_id, amba_pv::amba_pv_transaction& trans, tlm::tlm_dmi& dmi_data) = 0;
	virtual void b_snoop(int socket_id, amba_pv::amba_pv_transaction& trans, sc_core::sc_time& t) = 0;
	virtual unsigned int snoop_dbg(int socket_id, amba_pv::amba_pv_transaction& trans) = 0;
	virtual void invalidate_direct_mem_ptr(int socket_id, sc_dt::uint64 start_range, sc_dt::uint64 end_range) = 0;

};

#endif /* protocol_AMBAPVACE_h_ */

