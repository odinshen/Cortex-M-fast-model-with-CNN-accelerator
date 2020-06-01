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
 * Abstract interface class protocol_SC_ClockSignal for protocol SC_ClockSignal.
 */

#ifndef protocol_SC_ClockSignal_h_
#define protocol_SC_ClockSignal_h_

// Includes from the 'includes' section of this protocol
#line 69 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Common/Protocols/LISA/SC_ClockSignalProtocol.lisa"

        #include "Protocols/ClockSignal/clock_signal_sockets.h"
        #include "Protocols/ClockSignal/clock_signal_base.h"
    
#line 26 "./Linux64-Release-GCC-7.3/gen/protocol_SC_ClockSignal.h"


// Abstract interface for protocol SC_ClockSignal
class protocol_SC_ClockSignal
{
public:
        virtual ~protocol_SC_ClockSignal() {}
        // Abstract protocol members
	virtual void set_clock_m(sg::FrequencySource* _sg_frequencysource_0) = 0;
	virtual void set_clock_s(sg::FrequencySource* _sg_frequencysource_0) = 0;
	virtual sg::FrequencySource* get_clock_m() = 0;
	virtual sg::FrequencySource* get_clock_s() = 0;
	virtual double rate_in_hz_m() = 0;
	virtual double rate_in_hz_s() = 0;
	virtual uint64_t current_ticks_m() = 0;
	virtual uint64_t current_ticks_s() = 0;

};

#endif /* protocol_SC_ClockSignal_h_ */

