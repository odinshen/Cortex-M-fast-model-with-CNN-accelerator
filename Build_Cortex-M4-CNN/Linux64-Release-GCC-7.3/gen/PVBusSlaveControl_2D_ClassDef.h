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
 * Class definition for protocol PVBusSlaveControl_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/PVBusSlaveControlProtocol.lisa"
 */

#ifndef PVBusSlaveControl_2D_ClassDef_h_
#define PVBusSlaveControl_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_PVBusSlaveControl.h"

namespace DMA_NMS {

class PVBusSlaveControl_2D;

// Abstract interface implementation for port
class protocol_PVBusSlaveControl__Implementation: public protocol_PVBusSlaveControl
{
public:
    protocol_PVBusSlaveControl__Implementation(): thisPort(0) {}

    void SetPort(PVBusSlaveControl_2D *port) { thisPort = port; }

    // Protocol members
	inline void setFillPattern(uint32_t fill1, uint32_t fill2);
	inline void setAccess(pv::bus_addr_t base, pv::bus_addr_t top, pv::accessType type, pv::accessMode mode);
	inline const uint8_t* getReadStorage(pv::bus_addr_t address, pv::bus_addr_t* limit);
	inline uint8_t* getWriteStorage(pv::bus_addr_t address, pv::bus_addr_t* limit);
	inline uint32_t getRegionIterHandle();
	inline bool getNextRegionInfo(uint32_t iter_handle, pv::PVBusSlaveRegionInfo* info);
	inline void closeRegionIterHandle(uint32_t iter_handle);
	inline void provideReadStorage(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, const uint8_t* storage);
	inline void provideReadStorageEx(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, const uint8_t* storage, double read_latency);
	inline void provideWriteStorage(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, uint8_t* storage);
	inline void provideWriteStorageEx(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, uint8_t* storage, double write_latency);
	inline void provideReadWriteStorage(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, uint8_t* storage);
	inline void provideReadWriteStorageEx(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, uint8_t* storage, double read_latency, double write_latency);
	inline void configure(pv::slave_config_t* );
	inline void reset();


private:
    // Parent port this interface belongs to.
    PVBusSlaveControl_2D *thisPort;
};


// Protocol (port) class definition
class PVBusSlaveControl_2D: public sg::Port
{
private:
    void default_provideReadStorage(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, const uint8_t* storage)
{

 provideReadStorageEx(device_base, device_limit, storage, 0.0);
 
}
void default_provideWriteStorage(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, uint8_t* storage)
{

 provideWriteStorageEx(device_base, device_limit, storage, 0.0);
 
}
void default_provideReadWriteStorage(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, uint8_t* storage)
{

 provideReadWriteStorageEx(device_base, device_limit, storage, 0.0, 0.0);
 
}

public:
    // Resources


    // Connector instances
	sg::SlaveConnector< void (uint32_t,uint32_t) > setFillPattern;
	sg::SlaveConnector< void (pv::bus_addr_t,pv::bus_addr_t,pv::accessType,pv::accessMode) > setAccess;
	sg::SlaveConnector< const uint8_t* (pv::bus_addr_t,pv::bus_addr_t*) > getReadStorage;
	sg::SlaveConnector< uint8_t* (pv::bus_addr_t,pv::bus_addr_t*) > getWriteStorage;
	sg::SlaveConnector< uint32_t (void) > getRegionIterHandle;
	sg::SlaveConnector< bool (uint32_t,pv::PVBusSlaveRegionInfo*) > getNextRegionInfo;
	sg::SlaveConnector< void (uint32_t) > closeRegionIterHandle;
	sg::SlaveConnector< void (pv::bus_addr_t,pv::bus_addr_t,const uint8_t*) > provideReadStorage;
	sg::SlaveConnector< void (pv::bus_addr_t,pv::bus_addr_t,const uint8_t*,double) > provideReadStorageEx;
	sg::SlaveConnector< void (pv::bus_addr_t,pv::bus_addr_t,uint8_t*) > provideWriteStorage;
	sg::SlaveConnector< void (pv::bus_addr_t,pv::bus_addr_t,uint8_t*,double) > provideWriteStorageEx;
	sg::SlaveConnector< void (pv::bus_addr_t,pv::bus_addr_t,uint8_t*) > provideReadWriteStorage;
	sg::SlaveConnector< void (pv::bus_addr_t,pv::bus_addr_t,uint8_t*,double,double) > provideReadWriteStorageEx;
	sg::SlaveConnector< void (pv::slave_config_t*) > configure;
	sg::SlaveConnector< void (void) > reset;


    PVBusSlaveControl_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(setFillPattern);
		define_behaviour(setAccess);
		define_behaviour(getReadStorage);
		define_behaviour(getWriteStorage);
		define_behaviour(getRegionIterHandle);
		define_behaviour(getNextRegionInfo);
		define_behaviour(closeRegionIterHandle);
		define_behaviour(provideReadStorage);
		define_behaviour(provideReadStorageEx);
		define_behaviour(provideWriteStorage);
		define_behaviour(provideWriteStorageEx);
		define_behaviour(provideReadWriteStorage);
		define_behaviour(provideReadWriteStorageEx);
		define_behaviour(configure);
		define_behaviour(reset);

provideReadStorage.bind_default_behaviour( this, &PVBusSlaveControl_2D::default_provideReadStorage);provideWriteStorage.bind_default_behaviour( this, &PVBusSlaveControl_2D::default_provideWriteStorage);provideReadWriteStorage.bind_default_behaviour( this, &PVBusSlaveControl_2D::default_provideReadWriteStorage);
        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_PVBusSlaveControl__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_PVBusSlaveControl *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline void protocol_PVBusSlaveControl__Implementation::setFillPattern(uint32_t fill1, uint32_t fill2)
{
	return thisPort->setFillPattern(fill1, fill2);
}

inline void protocol_PVBusSlaveControl__Implementation::setAccess(pv::bus_addr_t base, pv::bus_addr_t top, pv::accessType type, pv::accessMode mode)
{
	return thisPort->setAccess(base, top, type, mode);
}

inline const uint8_t* protocol_PVBusSlaveControl__Implementation::getReadStorage(pv::bus_addr_t address, pv::bus_addr_t* limit)
{
	return thisPort->getReadStorage(address, limit);
}

inline uint8_t* protocol_PVBusSlaveControl__Implementation::getWriteStorage(pv::bus_addr_t address, pv::bus_addr_t* limit)
{
	return thisPort->getWriteStorage(address, limit);
}

inline uint32_t protocol_PVBusSlaveControl__Implementation::getRegionIterHandle()
{
	return thisPort->getRegionIterHandle();
}

inline bool protocol_PVBusSlaveControl__Implementation::getNextRegionInfo(uint32_t iter_handle, pv::PVBusSlaveRegionInfo* info)
{
	return thisPort->getNextRegionInfo(iter_handle, info);
}

inline void protocol_PVBusSlaveControl__Implementation::closeRegionIterHandle(uint32_t iter_handle)
{
	return thisPort->closeRegionIterHandle(iter_handle);
}

inline void protocol_PVBusSlaveControl__Implementation::provideReadStorage(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, const uint8_t* storage)
{
	return thisPort->provideReadStorage(device_base, device_limit, storage);
}

inline void protocol_PVBusSlaveControl__Implementation::provideReadStorageEx(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, const uint8_t* storage, double read_latency)
{
	return thisPort->provideReadStorageEx(device_base, device_limit, storage, read_latency);
}

inline void protocol_PVBusSlaveControl__Implementation::provideWriteStorage(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, uint8_t* storage)
{
	return thisPort->provideWriteStorage(device_base, device_limit, storage);
}

inline void protocol_PVBusSlaveControl__Implementation::provideWriteStorageEx(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, uint8_t* storage, double write_latency)
{
	return thisPort->provideWriteStorageEx(device_base, device_limit, storage, write_latency);
}

inline void protocol_PVBusSlaveControl__Implementation::provideReadWriteStorage(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, uint8_t* storage)
{
	return thisPort->provideReadWriteStorage(device_base, device_limit, storage);
}

inline void protocol_PVBusSlaveControl__Implementation::provideReadWriteStorageEx(pv::bus_addr_t device_base, pv::bus_addr_t device_limit, uint8_t* storage, double read_latency, double write_latency)
{
	return thisPort->provideReadWriteStorageEx(device_base, device_limit, storage, read_latency, write_latency);
}

inline void protocol_PVBusSlaveControl__Implementation::configure(pv::slave_config_t* param0__)
{
	return thisPort->configure(param0__);
}

inline void protocol_PVBusSlaveControl__Implementation::reset()
{
	return thisPort->reset();
}




// Mapping object
// (these ports are implemented inside PVBusSlaveControl_2D__AddressablePort)
class PVBusSlaveControl_2D__AddressablePort_OutPort: public PVBusSlaveControl_2D
{
public:
    // constructor
    PVBusSlaveControl_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class PVBusSlaveControl_2D__AddressablePort: public PVBusSlaveControl_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    PVBusSlaveControl_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &PVBusSlaveControl_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &PVBusSlaveControl_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &PVBusSlaveControl_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &PVBusSlaveControl_2D__AddressablePort::isMapped__, this);

    }

    ~PVBusSlaveControl_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    PVBusSlaveControl_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        PVBusSlaveControl_2D__AddressablePort_OutPort *masterPort =
            new PVBusSlaveControl_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->setFillPattern.connectTo(&masterPort->setFillPattern);
		this->setAccess.connectTo(&masterPort->setAccess);
		this->getReadStorage.connectTo(&masterPort->getReadStorage);
		this->getWriteStorage.connectTo(&masterPort->getWriteStorage);
		this->getRegionIterHandle.connectTo(&masterPort->getRegionIterHandle);
		this->getNextRegionInfo.connectTo(&masterPort->getNextRegionInfo);
		this->closeRegionIterHandle.connectTo(&masterPort->closeRegionIterHandle);
		this->provideReadStorage.connectTo(&masterPort->provideReadStorage);
		this->provideReadStorageEx.connectTo(&masterPort->provideReadStorageEx);
		this->provideWriteStorage.connectTo(&masterPort->provideWriteStorage);
		this->provideWriteStorageEx.connectTo(&masterPort->provideWriteStorageEx);
		this->provideReadWriteStorage.connectTo(&masterPort->provideReadWriteStorage);
		this->provideReadWriteStorageEx.connectTo(&masterPort->provideReadWriteStorageEx);
		this->configure.connectTo(&masterPort->configure);
		this->reset.connectTo(&masterPort->reset);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new PVBusSlaveControl_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((PVBusSlaveControl_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<PVBusSlaveControl_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    PVBusSlaveControl_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

