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
 * Class definition for protocol PVDevice_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/PVDeviceProtocol.lisa"
 */

#ifndef PVDevice_2D_ClassDef_h_
#define PVDevice_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_PVDevice.h"

namespace DMA_NMS {

class PVDevice_2D;

// Abstract interface implementation for port
class protocol_PVDevice__Implementation: public protocol_PVDevice
{
public:
    protocol_PVDevice__Implementation(): thisPort(0) {}

    void SetPort(PVDevice_2D *port) { thisPort = port; }

    // Protocol members
	inline pv::Tx_Result read(pv::ReadTransaction tx);
	inline pv::Tx_Result write(pv::WriteTransaction tx);
	inline pv::Tx_Result debugRead(pv::ReadTransaction tx);
	inline pv::Tx_Result debugWrite(pv::WriteTransaction tx);


private:
    // Parent port this interface belongs to.
    PVDevice_2D *thisPort;
};


// Protocol (port) class definition
class PVDevice_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< pv::Tx_Result (pv::ReadTransaction) > read;
	sg::SlaveConnector< pv::Tx_Result (pv::WriteTransaction) > write;
	sg::SlaveConnector< pv::Tx_Result (pv::ReadTransaction) > debugRead;
	sg::SlaveConnector< pv::Tx_Result (pv::WriteTransaction) > debugWrite;


    PVDevice_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(read);
		define_behaviour(write);
		define_behaviour(debugRead);
		define_behaviour(debugWrite);


        setProtocolID("ARM::pv.PVDevice");
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_PVDevice__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_PVDevice *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline pv::Tx_Result protocol_PVDevice__Implementation::read(pv::ReadTransaction tx)
{
	return thisPort->read(tx);
}

inline pv::Tx_Result protocol_PVDevice__Implementation::write(pv::WriteTransaction tx)
{
	return thisPort->write(tx);
}

inline pv::Tx_Result protocol_PVDevice__Implementation::debugRead(pv::ReadTransaction tx)
{
	return thisPort->debugRead(tx);
}

inline pv::Tx_Result protocol_PVDevice__Implementation::debugWrite(pv::WriteTransaction tx)
{
	return thisPort->debugWrite(tx);
}




// Mapping object
// (these ports are implemented inside PVDevice_2D__AddressablePort)
class PVDevice_2D__AddressablePort_OutPort: public PVDevice_2D
{
public:
    // constructor
    PVDevice_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class PVDevice_2D__AddressablePort: public PVDevice_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    PVDevice_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &PVDevice_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &PVDevice_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &PVDevice_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &PVDevice_2D__AddressablePort::isMapped__, this);

    }

    ~PVDevice_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    PVDevice_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        PVDevice_2D__AddressablePort_OutPort *masterPort =
            new PVDevice_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->read.connectTo(&masterPort->read);
		this->write.connectTo(&masterPort->write);
		this->debugRead.connectTo(&masterPort->debugRead);
		this->debugWrite.connectTo(&masterPort->debugWrite);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new PVDevice_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((PVDevice_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<PVDevice_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    PVDevice_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

