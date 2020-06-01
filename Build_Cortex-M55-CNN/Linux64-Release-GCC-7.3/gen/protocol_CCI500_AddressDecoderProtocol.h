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
 * Abstract interface class protocol_CCI500_AddressDecoderProtocol for protocol CCI500_AddressDecoderProtocol.
 */

#ifndef protocol_CCI500_AddressDecoderProtocol_h_
#define protocol_CCI500_AddressDecoderProtocol_h_

// Includes from the 'includes' section of this protocol
#line 61 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/CCI500_AddressDecoderProtocol.lisa"

#include "pv/CCI5x0_AddressDecoderConfiguration.h"
    
#line 25 "./Linux64-Release-GCC-7.3/gen/protocol_CCI500_AddressDecoderProtocol.h"


// Abstract interface for protocol CCI500_AddressDecoderProtocol
class protocol_CCI500_AddressDecoderProtocol
{
public:
        virtual ~protocol_CCI500_AddressDecoderProtocol() {}
        // Abstract protocol members
	virtual void configuration(const CCI5x0_AddressDecoderConfiguration& ) = 0;
	virtual unsigned decode_by_4KiB_addr(unsigned upstream_port_index_, bool is_read_or_cmo_, uint64_t address_, bool ns_) = 0;
	virtual void reset() = 0;
	virtual void get_squash_record(unsigned downstream_port_index_, unsigned* out_lsb_bitpos_, unsigned* out_number_of_bits_to_squash_) = 0;

};

#endif /* protocol_CCI500_AddressDecoderProtocol_h_ */

