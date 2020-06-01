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
 * Class definition for protocol CoprocBusProtocol_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/CoprocBusProtocol.lisa"
 */

#ifndef CoprocBusProtocol_2D_ClassDef_h_
#define CoprocBusProtocol_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_CoprocBusProtocol.h"

namespace DMA_NMS {

class CoprocBusProtocol_2D;

// Abstract interface implementation for port
class protocol_CoprocBusProtocol__Implementation: public protocol_CoprocBusProtocol
{
public:
    protocol_CoprocBusProtocol__Implementation(): thisPort(0) {}

    void SetPort(CoprocBusProtocol_2D *port) { thisPort = port; }

    // Protocol members
	inline void addCoprocessor(Coprocessor* , int num);
	inline void removeCoprocessor(Coprocessor* , int num);
	inline bool accessIsPriv();
	inline bool accessIsNonSecure();


private:
    // Parent port this interface belongs to.
    CoprocBusProtocol_2D *thisPort;
};


// Protocol (port) class definition
class CoprocBusProtocol_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::PeerConnector< void (Coprocessor*,int) > addCoprocessor;
	sg::PeerConnector< void (Coprocessor*,int) > removeCoprocessor;
	sg::PeerConnector< bool (void) > accessIsPriv;
	sg::PeerConnector< bool (void) > accessIsNonSecure;


    CoprocBusProtocol_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(addCoprocessor);
		define_behaviour(removeCoprocessor);
		define_behaviour(accessIsPriv);
		define_behaviour(accessIsNonSecure);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_CoprocBusProtocol__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_CoprocBusProtocol *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline void protocol_CoprocBusProtocol__Implementation::addCoprocessor(Coprocessor* param0__, int num)
{
	return thisPort->addCoprocessor(param0__, num);
}

inline void protocol_CoprocBusProtocol__Implementation::removeCoprocessor(Coprocessor* param0__, int num)
{
	return thisPort->removeCoprocessor(param0__, num);
}

inline bool protocol_CoprocBusProtocol__Implementation::accessIsPriv()
{
	return thisPort->accessIsPriv();
}

inline bool protocol_CoprocBusProtocol__Implementation::accessIsNonSecure()
{
	return thisPort->accessIsNonSecure();
}




// Mapping object
// (these ports are implemented inside CoprocBusProtocol_2D__AddressablePort)
class CoprocBusProtocol_2D__AddressablePort_OutPort: public CoprocBusProtocol_2D
{
public:
    // constructor
    CoprocBusProtocol_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class CoprocBusProtocol_2D__AddressablePort: public CoprocBusProtocol_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    CoprocBusProtocol_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &CoprocBusProtocol_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &CoprocBusProtocol_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &CoprocBusProtocol_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &CoprocBusProtocol_2D__AddressablePort::isMapped__, this);

    }

    ~CoprocBusProtocol_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    CoprocBusProtocol_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        CoprocBusProtocol_2D__AddressablePort_OutPort *masterPort =
            new CoprocBusProtocol_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->addCoprocessor.connectTo(&masterPort->addCoprocessor);
		this->removeCoprocessor.connectTo(&masterPort->removeCoprocessor);
		this->accessIsPriv.connectTo(&masterPort->accessIsPriv);
		this->accessIsNonSecure.connectTo(&masterPort->accessIsNonSecure);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new CoprocBusProtocol_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((CoprocBusProtocol_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<CoprocBusProtocol_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    CoprocBusProtocol_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

