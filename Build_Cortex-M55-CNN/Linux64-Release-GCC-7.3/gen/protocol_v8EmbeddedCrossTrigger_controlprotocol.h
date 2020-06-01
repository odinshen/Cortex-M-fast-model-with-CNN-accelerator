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
 * Abstract interface class protocol_v8EmbeddedCrossTrigger_controlprotocol for protocol v8EmbeddedCrossTrigger_controlprotocol.
 */

#ifndef protocol_v8EmbeddedCrossTrigger_controlprotocol_h_
#define protocol_v8EmbeddedCrossTrigger_controlprotocol_h_

// Includes from the 'includes' section of this protocol
#line 8 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/v8EmbeddedCrossTrigger.lisa"

    #include "sg/SGSignal.h"
        class SystemRegUpdateTraceProbe;
        class SynchronizeSysRegHelper;
    
#line 27 "./Linux64-Release-GCC-7.3/gen/protocol_v8EmbeddedCrossTrigger_controlprotocol.h"


// Abstract interface for protocol v8EmbeddedCrossTrigger_controlprotocol
class protocol_v8EmbeddedCrossTrigger_controlprotocol
{
public:
        virtual ~protocol_v8EmbeddedCrossTrigger_controlprotocol() {}
        // Abstract protocol members
	virtual void init(unsigned number_of_triggers, unsigned intack_mask, unsigned number_of_claim_bits, bool has_software_lock, bool has_CTIDEVCTL) = 0;
	virtual uint32_t reg_read(bool is_memory_mapped, uint32_t addr, bool is_non_secure) = 0;
	virtual void reg_write(bool is_memory_mapped, uint32_t addr, bool is_non_secure, uint32_t data) = 0;
	virtual void setValue_inputTrigger(unsigned index, sg::Signal::State state) = 0;
	virtual void setValue_outputTrigger(unsigned index, sg::Signal::State state) = 0;
	virtual uint8_t getPeripheralIdByte(unsigned pidn) = 0;
	virtual uint8_t getComponentIdByte(unsigned pidn) = 0;
	virtual void reset() = 0;
	virtual void initTrace(SystemRegUpdateTraceProbe* , bool* ) = 0;
	virtual void initDelayedSysReg(SynchronizeSysRegHelper* , bool , bool ) = 0;
	virtual bool isResetCatchEnabled() = 0;
	virtual bool isOSUnlockCatchEnabled() = 0;

};

#endif /* protocol_v8EmbeddedCrossTrigger_controlprotocol_h_ */

