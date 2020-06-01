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
 * Class definition for protocol ValueState_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/ValueProtocol.lisa"
 */

#ifndef ValueState_2D_ClassDef_h_
#define ValueState_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_ValueState.h"

namespace DMA_NMS {

class ValueState_2D;

// Abstract interface implementation for port
class protocol_ValueState__Implementation: public protocol_ValueState
{
public:
    protocol_ValueState__Implementation(): thisPort(0) {}

    void SetPort(ValueState_2D *port) { thisPort = port; }

    // Protocol members
	inline void setValue(uint32_t value);
	inline uint32_t getValue();


private:
    // Parent port this interface belongs to.
    ValueState_2D *thisPort;
};


// Protocol (port) class definition
class ValueState_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::PeerConnector< void (uint32_t) > setValue;
	sg::PeerConnector< uint32_t (void) > getValue;


    ValueState_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(setValue);
		define_behaviour(getValue);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_ValueState__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_ValueState *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline void protocol_ValueState__Implementation::setValue(uint32_t value)
{
	return thisPort->setValue(value);
}

inline uint32_t protocol_ValueState__Implementation::getValue()
{
	return thisPort->getValue();
}




// Mapping object
// (these ports are implemented inside ValueState_2D__AddressablePort)
class ValueState_2D__AddressablePort_OutPort: public ValueState_2D
{
public:
    // constructor
    ValueState_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class ValueState_2D__AddressablePort: public ValueState_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    ValueState_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &ValueState_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &ValueState_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &ValueState_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &ValueState_2D__AddressablePort::isMapped__, this);

    }

    ~ValueState_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    ValueState_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        ValueState_2D__AddressablePort_OutPort *masterPort =
            new ValueState_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->setValue.connectTo(&masterPort->setValue);
		this->getValue.connectTo(&masterPort->getValue);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new ValueState_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((ValueState_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<ValueState_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    ValueState_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

