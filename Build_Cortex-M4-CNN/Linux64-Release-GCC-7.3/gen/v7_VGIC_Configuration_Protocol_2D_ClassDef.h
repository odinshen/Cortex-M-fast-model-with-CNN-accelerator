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
 * Class definition for protocol v7_VGIC_Configuration_Protocol_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/v7_VGIC_Configuration_Protocol.lisa"
 */

#ifndef v7_VGIC_Configuration_Protocol_2D_ClassDef_h_
#define v7_VGIC_Configuration_Protocol_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_v7_VGIC_Configuration_Protocol.h"

namespace DMA_NMS {

class v7_VGIC_Configuration_Protocol_2D;

// Abstract interface implementation for port
class protocol_v7_VGIC_Configuration_Protocol__Implementation: public protocol_v7_VGIC_Configuration_Protocol
{
public:
    protocol_v7_VGIC_Configuration_Protocol__Implementation(): thisPort(0) {}

    void SetPort(v7_VGIC_Configuration_Protocol_2D *port) { thisPort = port; }

    // Protocol members
	inline unsigned getNumberOfCores();
	inline bool setMasterIdToCoreNumberMapping(uint32_t master_id_, uint32_t master_id_mask_, unsigned cpu_interface_number_, unsigned inout_cluster_number_, unsigned inout_cpu_number_in_cluster_);


private:
    // Parent port this interface belongs to.
    v7_VGIC_Configuration_Protocol_2D *thisPort;
};


// Protocol (port) class definition
class v7_VGIC_Configuration_Protocol_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< unsigned (void) > getNumberOfCores;
	sg::SlaveConnector< bool (uint32_t,uint32_t,unsigned,unsigned,unsigned) > setMasterIdToCoreNumberMapping;


    v7_VGIC_Configuration_Protocol_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(getNumberOfCores);
		define_behaviour(setMasterIdToCoreNumberMapping);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_v7_VGIC_Configuration_Protocol__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_v7_VGIC_Configuration_Protocol *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline unsigned protocol_v7_VGIC_Configuration_Protocol__Implementation::getNumberOfCores()
{
	return thisPort->getNumberOfCores();
}

inline bool protocol_v7_VGIC_Configuration_Protocol__Implementation::setMasterIdToCoreNumberMapping(uint32_t master_id_, uint32_t master_id_mask_, unsigned cpu_interface_number_, unsigned inout_cluster_number_, unsigned inout_cpu_number_in_cluster_)
{
	return thisPort->setMasterIdToCoreNumberMapping(master_id_, master_id_mask_, cpu_interface_number_, inout_cluster_number_, inout_cpu_number_in_cluster_);
}




// Mapping object
// (these ports are implemented inside v7_VGIC_Configuration_Protocol_2D__AddressablePort)
class v7_VGIC_Configuration_Protocol_2D__AddressablePort_OutPort: public v7_VGIC_Configuration_Protocol_2D
{
public:
    // constructor
    v7_VGIC_Configuration_Protocol_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class v7_VGIC_Configuration_Protocol_2D__AddressablePort: public v7_VGIC_Configuration_Protocol_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    v7_VGIC_Configuration_Protocol_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &v7_VGIC_Configuration_Protocol_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &v7_VGIC_Configuration_Protocol_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &v7_VGIC_Configuration_Protocol_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &v7_VGIC_Configuration_Protocol_2D__AddressablePort::isMapped__, this);

    }

    ~v7_VGIC_Configuration_Protocol_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    v7_VGIC_Configuration_Protocol_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        v7_VGIC_Configuration_Protocol_2D__AddressablePort_OutPort *masterPort =
            new v7_VGIC_Configuration_Protocol_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->getNumberOfCores.connectTo(&masterPort->getNumberOfCores);
		this->setMasterIdToCoreNumberMapping.connectTo(&masterPort->setMasterIdToCoreNumberMapping);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new v7_VGIC_Configuration_Protocol_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((v7_VGIC_Configuration_Protocol_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<v7_VGIC_Configuration_Protocol_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    v7_VGIC_Configuration_Protocol_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

