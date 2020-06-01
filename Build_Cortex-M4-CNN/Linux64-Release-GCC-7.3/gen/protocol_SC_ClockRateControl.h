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
 * Abstract interface class protocol_SC_ClockRateControl for protocol SC_ClockRateControl.
 */

#ifndef protocol_SC_ClockRateControl_h_
#define protocol_SC_ClockRateControl_h_

// Includes from the 'includes' section of this protocol
#line 38 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Common/Protocols/LISA/SC_ClockRateControlProtocol.lisa"

        #include "Protocols/ClockRateControl/clock_rate_control_sockets.h"
        #include "Protocols/ClockRateControl/clock_rate_control_base.h"
    
#line 26 "./Linux64-Release-GCC-7.3/gen/protocol_SC_ClockRateControl.h"


// Abstract interface for protocol SC_ClockRateControl
class protocol_SC_ClockRateControl
{
public:
        virtual ~protocol_SC_ClockRateControl() {}
        // Abstract protocol members
	virtual void set_m(uint32_t mul, uint32_t div) = 0;
	virtual void set_s(uint32_t mul, uint32_t div) = 0;
	virtual void set64_m(uint64_t mul, uint64_t div) = 0;
	virtual void set64_s(uint64_t mul, uint64_t div) = 0;

};

#endif /* protocol_SC_ClockRateControl_h_ */

