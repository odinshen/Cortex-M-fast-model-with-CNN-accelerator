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
 * Class definition for protocol MMU_400_Internals_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/SMMU_400_BASE.lisa"
 */

#ifndef MMU_400_Internals_2D_ClassDef_h_
#define MMU_400_Internals_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_MMU_400_Internals.h"

namespace DMA_NMS {

class MMU_400_Internals_2D;

// Abstract interface implementation for port
class protocol_MMU_400_Internals__Implementation: public protocol_MMU_400_Internals
{
public:
    protocol_MMU_400_Internals__Implementation(): thisPort(0) {}

    void SetPort(MMU_400_Internals_2D *port) { thisPort = port; }

    // Protocol members
	inline MMU_400::mmu_400_if* getMMU_400();


private:
    // Parent port this interface belongs to.
    MMU_400_Internals_2D *thisPort;
};


// Protocol (port) class definition
class MMU_400_Internals_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< MMU_400::mmu_400_if* (void) > getMMU_400;


    MMU_400_Internals_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(getMMU_400);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_MMU_400_Internals__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_MMU_400_Internals *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline MMU_400::mmu_400_if* protocol_MMU_400_Internals__Implementation::getMMU_400()
{
	return thisPort->getMMU_400();
}




// Mapping object
// (these ports are implemented inside MMU_400_Internals_2D__AddressablePort)
class MMU_400_Internals_2D__AddressablePort_OutPort: public MMU_400_Internals_2D
{
public:
    // constructor
    MMU_400_Internals_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class MMU_400_Internals_2D__AddressablePort: public MMU_400_Internals_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    MMU_400_Internals_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &MMU_400_Internals_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &MMU_400_Internals_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &MMU_400_Internals_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &MMU_400_Internals_2D__AddressablePort::isMapped__, this);

    }

    ~MMU_400_Internals_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    MMU_400_Internals_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        MMU_400_Internals_2D__AddressablePort_OutPort *masterPort =
            new MMU_400_Internals_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->getMMU_400.connectTo(&masterPort->getMMU_400);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new MMU_400_Internals_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((MMU_400_Internals_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<MMU_400_Internals_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    MMU_400_Internals_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

