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
 * Class definition for protocol Builtin__AddressablePortProtocol_2D.
 * GeneratedFrom: "<string-input>"
 */

#ifndef Builtin__AddressablePortProtocol_2D_ClassDef_h_
#define Builtin__AddressablePortProtocol_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_Builtin__AddressablePortProtocol.h"

namespace DMA_NMS {

class Builtin__AddressablePortProtocol_2D;

// Abstract interface implementation for port
class protocol_Builtin__AddressablePortProtocol__Implementation: public protocol_Builtin__AddressablePortProtocol
{
public:
    protocol_Builtin__AddressablePortProtocol__Implementation(): thisPort(0) {}

    void SetPort(Builtin__AddressablePortProtocol_2D *port) { thisPort = port; }

    // Protocol members
	inline sg::Port* mapRange(MxU64 , MxU64 , MxU64 , MxU64 );
	inline sg::Port* mapDefault();
	inline void unmapRange(sg::Port* );


private:
    // Parent port this interface belongs to.
    Builtin__AddressablePortProtocol_2D *thisPort;
};


// Protocol (port) class definition
class Builtin__AddressablePortProtocol_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< sg::Port* (MxU64,MxU64,MxU64,MxU64) > mapRange;
	sg::SlaveConnector< sg::Port* (void) > mapDefault;
	sg::SlaveConnector< void (sg::Port*) > unmapRange;


    Builtin__AddressablePortProtocol_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(mapRange);
		define_behaviour(mapDefault);
		define_behaviour(unmapRange);


        setProtocolID("ARM::Builtin.AddressablePortProtocol");
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_Builtin__AddressablePortProtocol__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_Builtin__AddressablePortProtocol *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline sg::Port* protocol_Builtin__AddressablePortProtocol__Implementation::mapRange(MxU64 param0__, MxU64 param1__, MxU64 param2__, MxU64 param3__)
{
	return thisPort->mapRange(param0__, param1__, param2__, param3__);
}

inline sg::Port* protocol_Builtin__AddressablePortProtocol__Implementation::mapDefault()
{
	return thisPort->mapDefault();
}

inline void protocol_Builtin__AddressablePortProtocol__Implementation::unmapRange(sg::Port* param0__)
{
	return thisPort->unmapRange(param0__);
}




// Mapping object
// (these ports are implemented inside Builtin__AddressablePortProtocol_2D__AddressablePort)
class Builtin__AddressablePortProtocol_2D__AddressablePort_OutPort: public Builtin__AddressablePortProtocol_2D
{
public:
    // constructor
    Builtin__AddressablePortProtocol_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class Builtin__AddressablePortProtocol_2D__AddressablePort: public Builtin__AddressablePortProtocol_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    Builtin__AddressablePortProtocol_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &Builtin__AddressablePortProtocol_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &Builtin__AddressablePortProtocol_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &Builtin__AddressablePortProtocol_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &Builtin__AddressablePortProtocol_2D__AddressablePort::isMapped__, this);

    }

    ~Builtin__AddressablePortProtocol_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    Builtin__AddressablePortProtocol_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        Builtin__AddressablePortProtocol_2D__AddressablePort_OutPort *masterPort =
            new Builtin__AddressablePortProtocol_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->mapRange.connectTo(&masterPort->mapRange);
		this->mapDefault.connectTo(&masterPort->mapDefault);
		this->unmapRange.connectTo(&masterPort->unmapRange);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new Builtin__AddressablePortProtocol_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((Builtin__AddressablePortProtocol_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<Builtin__AddressablePortProtocol_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    Builtin__AddressablePortProtocol_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

