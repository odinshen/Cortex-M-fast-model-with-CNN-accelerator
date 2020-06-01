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
 * Class definition for protocol PVBusCacheDevice_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/PVBusCache.lisa"
 */

#ifndef PVBusCacheDevice_2D_ClassDef_h_
#define PVBusCacheDevice_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_PVBusCacheDevice.h"

namespace DMA_NMS {

class PVBusCacheDevice_2D;

// Abstract interface implementation for port
class protocol_PVBusCacheDevice__Implementation: public protocol_PVBusCacheDevice
{
public:
    protocol_PVBusCacheDevice__Implementation(): thisPort(0) {}

    void SetPort(PVBusCacheDevice_2D *port) { thisPort = port; }

    // Protocol members
	inline pv::Tx_Result cacheRead(unsigned in_port, pv::ReadTransaction tx);
	inline pv::Tx_Result cacheWrite(unsigned in_port, pv::WriteTransaction tx);
	inline pv::CacheRoutingDecision routeTransaction(unsigned in_port, pv::Transaction tx);


private:
    // Parent port this interface belongs to.
    PVBusCacheDevice_2D *thisPort;
};


// Protocol (port) class definition
class PVBusCacheDevice_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< pv::Tx_Result (unsigned,pv::ReadTransaction) > cacheRead;
	sg::SlaveConnector< pv::Tx_Result (unsigned,pv::WriteTransaction) > cacheWrite;
	sg::SlaveConnector< pv::CacheRoutingDecision (unsigned,pv::Transaction) > routeTransaction;


    PVBusCacheDevice_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(cacheRead);
		define_behaviour(cacheWrite);
		define_behaviour(routeTransaction);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_PVBusCacheDevice__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_PVBusCacheDevice *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline pv::Tx_Result protocol_PVBusCacheDevice__Implementation::cacheRead(unsigned in_port, pv::ReadTransaction tx)
{
	return thisPort->cacheRead(in_port, tx);
}

inline pv::Tx_Result protocol_PVBusCacheDevice__Implementation::cacheWrite(unsigned in_port, pv::WriteTransaction tx)
{
	return thisPort->cacheWrite(in_port, tx);
}

inline pv::CacheRoutingDecision protocol_PVBusCacheDevice__Implementation::routeTransaction(unsigned in_port, pv::Transaction tx)
{
	return thisPort->routeTransaction(in_port, tx);
}




// Mapping object
// (these ports are implemented inside PVBusCacheDevice_2D__AddressablePort)
class PVBusCacheDevice_2D__AddressablePort_OutPort: public PVBusCacheDevice_2D
{
public:
    // constructor
    PVBusCacheDevice_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class PVBusCacheDevice_2D__AddressablePort: public PVBusCacheDevice_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    PVBusCacheDevice_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &PVBusCacheDevice_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &PVBusCacheDevice_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &PVBusCacheDevice_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &PVBusCacheDevice_2D__AddressablePort::isMapped__, this);

    }

    ~PVBusCacheDevice_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    PVBusCacheDevice_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        PVBusCacheDevice_2D__AddressablePort_OutPort *masterPort =
            new PVBusCacheDevice_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->cacheRead.connectTo(&masterPort->cacheRead);
		this->cacheWrite.connectTo(&masterPort->cacheWrite);
		this->routeTransaction.connectTo(&masterPort->routeTransaction);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new PVBusCacheDevice_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((PVBusCacheDevice_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<PVBusCacheDevice_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    PVBusCacheDevice_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

