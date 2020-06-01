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
 * Class definition for protocol PMUEvent_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/CCIRegisters.lisa"
 */

#ifndef PMUEvent_2D_ClassDef_h_
#define PMUEvent_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_PMUEvent.h"

namespace DMA_NMS {

class PMUEvent_2D;

// Abstract interface implementation for port
class protocol_PMUEvent__Implementation: public protocol_PMUEvent
{
public:
    protocol_PMUEvent__Implementation(): thisPort(0) {}

    void SetPort(PMUEvent_2D *port) { thisPort = port; }

    // Protocol members
	inline void fire();


private:
    // Parent port this interface belongs to.
    PMUEvent_2D *thisPort;
};


// Protocol (port) class definition
class PMUEvent_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::PeerConnector< void (void) > fire;


    PMUEvent_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(fire);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_PMUEvent__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_PMUEvent *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline void protocol_PMUEvent__Implementation::fire()
{
	return thisPort->fire();
}




// Mapping object
// (these ports are implemented inside PMUEvent_2D__AddressablePort)
class PMUEvent_2D__AddressablePort_OutPort: public PMUEvent_2D
{
public:
    // constructor
    PMUEvent_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class PMUEvent_2D__AddressablePort: public PMUEvent_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    PMUEvent_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &PMUEvent_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &PMUEvent_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &PMUEvent_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &PMUEvent_2D__AddressablePort::isMapped__, this);

    }

    ~PMUEvent_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    PMUEvent_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        PMUEvent_2D__AddressablePort_OutPort *masterPort =
            new PMUEvent_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->fire.connectTo(&masterPort->fire);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new PMUEvent_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((PMUEvent_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<PMUEvent_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    PMUEvent_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

