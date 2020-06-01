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
 * Class definition for protocol CounterInterface_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/CounterInterface.lisa"
 */

#ifndef CounterInterface_2D_ClassDef_h_
#define CounterInterface_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_CounterInterface.h"

namespace DMA_NMS {

class CounterInterface_2D;

// Abstract interface implementation for port
class protocol_CounterInterface__Implementation: public protocol_CounterInterface
{
public:
    protocol_CounterInterface__Implementation(): thisPort(0) {}

    void SetPort(CounterInterface_2D *port) { thisPort = port; }

    // Protocol members
	inline uint64_t getCounterValue();
	inline void requestSignalUpdate(uint64_t at);
	inline void signalUpdate();
	inline void setEnabled(bool _bool_0);
	inline void requestEventUpdate(uint64_t at);
	inline void eventUpdate();


private:
    // Parent port this interface belongs to.
    CounterInterface_2D *thisPort;
};


// Protocol (port) class definition
class CounterInterface_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::MasterConnector< uint64_t (void) > getCounterValue;
	sg::MasterConnector< void (uint64_t) > requestSignalUpdate;
	sg::SlaveConnector< void (void) > signalUpdate;
	sg::SlaveConnector< void (bool) > setEnabled;
	sg::MasterConnector< void (uint64_t) > requestEventUpdate;
	sg::SlaveConnector< void (void) > eventUpdate;


    CounterInterface_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(getCounterValue);
		define_behaviour(requestSignalUpdate);
		define_behaviour(signalUpdate);
		define_behaviour(setEnabled);
		define_behaviour(requestEventUpdate);
		define_behaviour(eventUpdate);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_CounterInterface__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_CounterInterface *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline uint64_t protocol_CounterInterface__Implementation::getCounterValue()
{
	return thisPort->getCounterValue();
}

inline void protocol_CounterInterface__Implementation::requestSignalUpdate(uint64_t at)
{
	return thisPort->requestSignalUpdate(at);
}

inline void protocol_CounterInterface__Implementation::signalUpdate()
{
	return thisPort->signalUpdate();
}

inline void protocol_CounterInterface__Implementation::setEnabled(bool _bool_0)
{
	return thisPort->setEnabled(_bool_0);
}

inline void protocol_CounterInterface__Implementation::requestEventUpdate(uint64_t at)
{
	return thisPort->requestEventUpdate(at);
}

inline void protocol_CounterInterface__Implementation::eventUpdate()
{
	return thisPort->eventUpdate();
}




// Mapping object
// (these ports are implemented inside CounterInterface_2D__AddressablePort)
class CounterInterface_2D__AddressablePort_OutPort: public CounterInterface_2D
{
public:
    // constructor
    CounterInterface_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class CounterInterface_2D__AddressablePort: public CounterInterface_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    CounterInterface_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &CounterInterface_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &CounterInterface_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &CounterInterface_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &CounterInterface_2D__AddressablePort::isMapped__, this);

    }

    ~CounterInterface_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    CounterInterface_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        CounterInterface_2D__AddressablePort_OutPort *masterPort =
            new CounterInterface_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->getCounterValue.connectTo(&masterPort->getCounterValue);
		this->requestSignalUpdate.connectTo(&masterPort->requestSignalUpdate);
		this->signalUpdate.connectTo(&masterPort->signalUpdate);
		this->setEnabled.connectTo(&masterPort->setEnabled);
		this->requestEventUpdate.connectTo(&masterPort->requestEventUpdate);
		this->eventUpdate.connectTo(&masterPort->eventUpdate);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new CounterInterface_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((CounterInterface_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<CounterInterface_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    CounterInterface_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

