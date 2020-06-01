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
 * Class definition for protocol PVCacheDebugRam_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/PVCache_DebugRamProtocol.lisa"
 */

#ifndef PVCacheDebugRam_2D_ClassDef_h_
#define PVCacheDebugRam_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_PVCacheDebugRam.h"

namespace DMA_NMS {

class PVCacheDebugRam_2D;

// Abstract interface implementation for port
class protocol_PVCacheDebugRam__Implementation: public protocol_PVCacheDebugRam
{
public:
    protocol_PVCacheDebugRam__Implementation(): thisPort(0) {}

    void SetPort(PVCacheDebugRam_2D *port) { thisPort = port; }

    // Protocol members
	inline void getConfig(pv::PVCache_DebugConfig& config);
	inline bool peekLine(const pv::PVCache_DebugFilter& filter, pv::PVCache_DebugLine& buffer);
	inline bool pokeLine(const pv::PVCache_DebugFilter& filter, const pv::PVCache_DebugLine& buffer);
	inline sg_deferred_actions::deferred_actions_t* getDeferredActions();
	inline uint64_t getAttribute(pv::PVCache_DebugRamPort::Attribute attribute, unsigned index);


private:
    // Parent port this interface belongs to.
    PVCacheDebugRam_2D *thisPort;
};


// Protocol (port) class definition
class PVCacheDebugRam_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< void (pv::PVCache_DebugConfig&) > getConfig;
	sg::SlaveConnector< bool (const pv::PVCache_DebugFilter&,pv::PVCache_DebugLine&) > peekLine;
	sg::SlaveConnector< bool (const pv::PVCache_DebugFilter&,const pv::PVCache_DebugLine&) > pokeLine;
	sg::SlaveConnector< sg_deferred_actions::deferred_actions_t* (void) > getDeferredActions;
	sg::SlaveConnector< uint64_t (pv::PVCache_DebugRamPort::Attribute,unsigned) > getAttribute;


    PVCacheDebugRam_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(getConfig);
		define_behaviour(peekLine);
		define_behaviour(pokeLine);
		define_behaviour(getDeferredActions);
		define_behaviour(getAttribute);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_PVCacheDebugRam__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_PVCacheDebugRam *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline void protocol_PVCacheDebugRam__Implementation::getConfig(pv::PVCache_DebugConfig& config)
{
	return thisPort->getConfig(config);
}

inline bool protocol_PVCacheDebugRam__Implementation::peekLine(const pv::PVCache_DebugFilter& filter, pv::PVCache_DebugLine& buffer)
{
	return thisPort->peekLine(filter, buffer);
}

inline bool protocol_PVCacheDebugRam__Implementation::pokeLine(const pv::PVCache_DebugFilter& filter, const pv::PVCache_DebugLine& buffer)
{
	return thisPort->pokeLine(filter, buffer);
}

inline sg_deferred_actions::deferred_actions_t* protocol_PVCacheDebugRam__Implementation::getDeferredActions()
{
	return thisPort->getDeferredActions();
}

inline uint64_t protocol_PVCacheDebugRam__Implementation::getAttribute(pv::PVCache_DebugRamPort::Attribute attribute, unsigned index)
{
	return thisPort->getAttribute(attribute, index);
}




// Mapping object
// (these ports are implemented inside PVCacheDebugRam_2D__AddressablePort)
class PVCacheDebugRam_2D__AddressablePort_OutPort: public PVCacheDebugRam_2D
{
public:
    // constructor
    PVCacheDebugRam_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class PVCacheDebugRam_2D__AddressablePort: public PVCacheDebugRam_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    PVCacheDebugRam_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &PVCacheDebugRam_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &PVCacheDebugRam_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &PVCacheDebugRam_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &PVCacheDebugRam_2D__AddressablePort::isMapped__, this);

    }

    ~PVCacheDebugRam_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    PVCacheDebugRam_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        PVCacheDebugRam_2D__AddressablePort_OutPort *masterPort =
            new PVCacheDebugRam_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->getConfig.connectTo(&masterPort->getConfig);
		this->peekLine.connectTo(&masterPort->peekLine);
		this->pokeLine.connectTo(&masterPort->pokeLine);
		this->getDeferredActions.connectTo(&masterPort->getDeferredActions);
		this->getAttribute.connectTo(&masterPort->getAttribute);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new PVCacheDebugRam_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((PVCacheDebugRam_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<PVCacheDebugRam_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    PVCacheDebugRam_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

