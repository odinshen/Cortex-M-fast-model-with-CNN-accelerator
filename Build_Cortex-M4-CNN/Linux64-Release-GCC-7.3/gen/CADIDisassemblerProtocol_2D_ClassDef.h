/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2005 ARM Limited.
 * Copyright 2011 ARM Limited.
 *
 * All rights reserved.
 */

/** \file
 * Class definition for protocol CADIDisassemblerProtocol_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/CADIDisassemblerProtocol.lisa"
 */

#ifndef CADIDisassemblerProtocol_2D_ClassDef_h_
#define CADIDisassemblerProtocol_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_CADIDisassemblerProtocol.h"

namespace DMA_NMS {

class CADIDisassemblerProtocol_2D;

// Abstract interface implementation for port
class protocol_CADIDisassemblerProtocol__Implementation: public protocol_CADIDisassemblerProtocol
{
public:
    protocol_CADIDisassemblerProtocol__Implementation(): thisPort(0) {}

    void SetPort(CADIDisassemblerProtocol_2D *port) { thisPort = port; }

    // Protocol members
	inline eslapi::CADIDisassemblerType GetType();
	inline uint32_t GetModeCount();
	inline void GetModeNames(eslapi::CADIDisassemblerCB* callback_);
	inline uint32_t GetCurrentMode();
	inline eslapi::CADIDisassemblerStatus GetSourceReferenceForAddress(eslapi::CADIDisassemblerCB* callback_, const eslapi::CADIAddr_t& address);
	inline eslapi::CADIDisassemblerStatus GetAddressForSourceReference(const char* sourceFile, uint32_t sourceLine, eslapi::CADIAddr_t& address);
	inline eslapi::CADIDisassemblerStatus GetDisassembly(eslapi::CADIDisassemblerCB* callback_, const eslapi::CADIAddr_t& address, eslapi::CADIAddr_t& nextAddr, const uint32_t mode, uint32_t desiredCount);
	inline eslapi::CADIDisassemblerStatus GetInstructionType(const eslapi::CADIAddr_t& address, eslapi::CADIDisassemblerInstructionType& insn_type);


private:
    // Parent port this interface belongs to.
    CADIDisassemblerProtocol_2D *thisPort;
};


// Protocol (port) class definition
class CADIDisassemblerProtocol_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< eslapi::CADIDisassemblerType (void) > GetType;
	sg::SlaveConnector< uint32_t (void) > GetModeCount;
	sg::SlaveConnector< void (eslapi::CADIDisassemblerCB*) > GetModeNames;
	sg::SlaveConnector< uint32_t (void) > GetCurrentMode;
	sg::SlaveConnector< eslapi::CADIDisassemblerStatus (eslapi::CADIDisassemblerCB*,const eslapi::CADIAddr_t&) > GetSourceReferenceForAddress;
	sg::SlaveConnector< eslapi::CADIDisassemblerStatus (const char*,uint32_t,eslapi::CADIAddr_t&) > GetAddressForSourceReference;
	sg::SlaveConnector< eslapi::CADIDisassemblerStatus (eslapi::CADIDisassemblerCB*,const eslapi::CADIAddr_t&,eslapi::CADIAddr_t&,const uint32_t,uint32_t) > GetDisassembly;
	sg::SlaveConnector< eslapi::CADIDisassemblerStatus (const eslapi::CADIAddr_t&,eslapi::CADIDisassemblerInstructionType&) > GetInstructionType;


    CADIDisassemblerProtocol_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(GetType);
		define_behaviour(GetModeCount);
		define_behaviour(GetModeNames);
		define_behaviour(GetCurrentMode);
		define_behaviour(GetSourceReferenceForAddress);
		define_behaviour(GetAddressForSourceReference);
		define_behaviour(GetDisassembly);
		define_behaviour(GetInstructionType);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_CADIDisassemblerProtocol__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_CADIDisassemblerProtocol *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline eslapi::CADIDisassemblerType protocol_CADIDisassemblerProtocol__Implementation::GetType()
{
	return thisPort->GetType();
}

inline uint32_t protocol_CADIDisassemblerProtocol__Implementation::GetModeCount()
{
	return thisPort->GetModeCount();
}

inline void protocol_CADIDisassemblerProtocol__Implementation::GetModeNames(eslapi::CADIDisassemblerCB* callback_)
{
	return thisPort->GetModeNames(callback_);
}

inline uint32_t protocol_CADIDisassemblerProtocol__Implementation::GetCurrentMode()
{
	return thisPort->GetCurrentMode();
}

inline eslapi::CADIDisassemblerStatus protocol_CADIDisassemblerProtocol__Implementation::GetSourceReferenceForAddress(eslapi::CADIDisassemblerCB* callback_, const eslapi::CADIAddr_t& address)
{
	return thisPort->GetSourceReferenceForAddress(callback_, address);
}

inline eslapi::CADIDisassemblerStatus protocol_CADIDisassemblerProtocol__Implementation::GetAddressForSourceReference(const char* sourceFile, uint32_t sourceLine, eslapi::CADIAddr_t& address)
{
	return thisPort->GetAddressForSourceReference(sourceFile, sourceLine, address);
}

inline eslapi::CADIDisassemblerStatus protocol_CADIDisassemblerProtocol__Implementation::GetDisassembly(eslapi::CADIDisassemblerCB* callback_, const eslapi::CADIAddr_t& address, eslapi::CADIAddr_t& nextAddr, const uint32_t mode, uint32_t desiredCount)
{
	return thisPort->GetDisassembly(callback_, address, nextAddr, mode, desiredCount);
}

inline eslapi::CADIDisassemblerStatus protocol_CADIDisassemblerProtocol__Implementation::GetInstructionType(const eslapi::CADIAddr_t& address, eslapi::CADIDisassemblerInstructionType& insn_type)
{
	return thisPort->GetInstructionType(address, insn_type);
}




// Mapping object
// (these ports are implemented inside CADIDisassemblerProtocol_2D__AddressablePort)
class CADIDisassemblerProtocol_2D__AddressablePort_OutPort: public CADIDisassemblerProtocol_2D
{
public:
    // constructor
    CADIDisassemblerProtocol_2D__AddressablePort_OutPort(uint32_t inFirst,
                                                 uint32_t inLast,
                                                 uint32_t outFirst,
                                                 uint32_t outLast):
    inFirst__(inFirst),
    inLast__(inLast),
    outFirst__(outFirst),
    outSize__(outLast - outFirst + 1)
    {
    }

    bool isCovered__(uint32_t address) const
    {
        return (address >= inFirst__) && (address <= inLast__);
    }

    void remapAddress__(uint32_t &address) const
    {
        if(outSize__)
            address = ((address - inFirst__) % outSize__) + outFirst__;
    }

private:
    uint32_t inFirst__;
    uint32_t inLast__;
    uint32_t outFirst__;
    uint32_t outSize__;
};


// Addressable protocol class definition
class CADIDisassemblerProtocol_2D__AddressablePort: public CADIDisassemblerProtocol_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    CADIDisassemblerProtocol_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &CADIDisassemblerProtocol_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &CADIDisassemblerProtocol_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &CADIDisassemblerProtocol_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &CADIDisassemblerProtocol_2D__AddressablePort::isMapped__, this);

    }

    ~CADIDisassemblerProtocol_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    CADIDisassemblerProtocol_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
        {
            if ((*it)->isCovered__(addr)) {
                (*it)->remapAddress__(addr);
                return *it;
            }
        }
        return defaultOutPort__;
    }

    sg::Port* mapRange__(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast)
    {
        CADIDisassemblerProtocol_2D__AddressablePort_OutPort *masterPort =
            new CADIDisassemblerProtocol_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->GetType.connectTo(&masterPort->GetType);
		this->GetModeCount.connectTo(&masterPort->GetModeCount);
		this->GetModeNames.connectTo(&masterPort->GetModeNames);
		this->GetCurrentMode.connectTo(&masterPort->GetCurrentMode);
		this->GetSourceReferenceForAddress.connectTo(&masterPort->GetSourceReferenceForAddress);
		this->GetAddressForSourceReference.connectTo(&masterPort->GetAddressForSourceReference);
		this->GetDisassembly.connectTo(&masterPort->GetDisassembly);
		this->GetInstructionType.connectTo(&masterPort->GetInstructionType);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new CADIDisassemblerProtocol_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((CADIDisassemblerProtocol_2D__AddressablePort_OutPort*)port);
        if(defaultOutPort__ == port)
        {
            delete defaultOutPort__;
            defaultOutPort__ = 0;
        }
    }

    bool isMapped__(uint64_t addr)
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
        {
            if ((*it)->isCovered__(static_cast<uint32_t>(addr)))
                return true;
        }
        return false;
    }

    // Wrapper functions for protocol behaviors


private:
    typedef std::list<CADIDisassemblerProtocol_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    CADIDisassemblerProtocol_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

