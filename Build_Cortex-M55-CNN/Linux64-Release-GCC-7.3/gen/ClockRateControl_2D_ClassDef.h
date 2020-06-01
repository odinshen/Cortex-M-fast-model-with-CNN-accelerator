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
 * Class definition for protocol ClockRateControl_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/ClockRateControlProtocol.lisa"
 */

#ifndef ClockRateControl_2D_ClassDef_h_
#define ClockRateControl_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_ClockRateControl.h"

namespace DMA_NMS {

class ClockRateControl_2D;

// Abstract interface implementation for port
class protocol_ClockRateControl__Implementation: public protocol_ClockRateControl
{
public:
    protocol_ClockRateControl__Implementation(): thisPort(0) {}

    void SetPort(ClockRateControl_2D *port) { thisPort = port; }

    // Protocol members
	inline void set(uint32_t mul, uint32_t div);
	inline void set64(uint64_t mul, uint64_t div);


private:
    // Parent port this interface belongs to.
    ClockRateControl_2D *thisPort;
};


// Protocol (port) class definition
class ClockRateControl_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::PeerConnector< void (uint32_t,uint32_t) > set;
	sg::PeerConnector< void (uint64_t,uint64_t) > set64;


    ClockRateControl_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(set);
		define_behaviour(set64);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_ClockRateControl__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_ClockRateControl *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline void protocol_ClockRateControl__Implementation::set(uint32_t mul, uint32_t div)
{
	return thisPort->set(mul, div);
}

inline void protocol_ClockRateControl__Implementation::set64(uint64_t mul, uint64_t div)
{
	return thisPort->set64(mul, div);
}




// Mapping object
// (these ports are implemented inside ClockRateControl_2D__AddressablePort)
class ClockRateControl_2D__AddressablePort_OutPort: public ClockRateControl_2D
{
public:
    // constructor
    ClockRateControl_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class ClockRateControl_2D__AddressablePort: public ClockRateControl_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    ClockRateControl_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &ClockRateControl_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &ClockRateControl_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &ClockRateControl_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &ClockRateControl_2D__AddressablePort::isMapped__, this);

    }

    ~ClockRateControl_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    ClockRateControl_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        ClockRateControl_2D__AddressablePort_OutPort *masterPort =
            new ClockRateControl_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->set.connectTo(&masterPort->set);
		this->set64.connectTo(&masterPort->set64);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new ClockRateControl_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((ClockRateControl_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<ClockRateControl_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    ClockRateControl_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

