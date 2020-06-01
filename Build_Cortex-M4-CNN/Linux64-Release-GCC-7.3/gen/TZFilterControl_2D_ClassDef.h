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
 * Class definition for protocol TZFilterControl_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/TZFilterUnit.lisa"
 */

#ifndef TZFilterControl_2D_ClassDef_h_
#define TZFilterControl_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_TZFilterControl.h"

namespace DMA_NMS {

class TZFilterControl_2D;

// Abstract interface implementation for port
class protocol_TZFilterControl__Implementation: public protocol_TZFilterControl
{
public:
    protocol_TZFilterControl__Implementation(): thisPort(0) {}

    void SetPort(TZFilterControl_2D *port) { thisPort = port; }

    // Protocol members
	inline bool checkPermission(const pv::TransactionAttributes* attributes_, pv::bus_addr_t page_base_, bool is_read_, pv::RemapRequest& req_, bool& abort_on_error_);
	inline bool isEnabled();
	inline bool isSecureSlave();
	inline void setConfig(bool rd_spec_enable, bool wr_spec_enable, uint32_t action);


private:
    // Parent port this interface belongs to.
    TZFilterControl_2D *thisPort;
};


// Protocol (port) class definition
class TZFilterControl_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< bool (const pv::TransactionAttributes*,pv::bus_addr_t,bool,pv::RemapRequest&,bool&) > checkPermission;
	sg::SlaveConnector< bool (void) > isEnabled;
	sg::SlaveConnector< bool (void) > isSecureSlave;
	sg::MasterConnector< void (bool,bool,uint32_t) > setConfig;


    TZFilterControl_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(checkPermission);
		define_behaviour(isEnabled);
		define_behaviour(isSecureSlave);
		define_behaviour(setConfig);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_TZFilterControl__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_TZFilterControl *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline bool protocol_TZFilterControl__Implementation::checkPermission(const pv::TransactionAttributes* attributes_, pv::bus_addr_t page_base_, bool is_read_, pv::RemapRequest& req_, bool& abort_on_error_)
{
	return thisPort->checkPermission(attributes_, page_base_, is_read_, req_, abort_on_error_);
}

inline bool protocol_TZFilterControl__Implementation::isEnabled()
{
	return thisPort->isEnabled();
}

inline bool protocol_TZFilterControl__Implementation::isSecureSlave()
{
	return thisPort->isSecureSlave();
}

inline void protocol_TZFilterControl__Implementation::setConfig(bool rd_spec_enable, bool wr_spec_enable, uint32_t action)
{
	return thisPort->setConfig(rd_spec_enable, wr_spec_enable, action);
}




// Mapping object
// (these ports are implemented inside TZFilterControl_2D__AddressablePort)
class TZFilterControl_2D__AddressablePort_OutPort: public TZFilterControl_2D
{
public:
    // constructor
    TZFilterControl_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class TZFilterControl_2D__AddressablePort: public TZFilterControl_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    TZFilterControl_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &TZFilterControl_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &TZFilterControl_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &TZFilterControl_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &TZFilterControl_2D__AddressablePort::isMapped__, this);

    }

    ~TZFilterControl_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    TZFilterControl_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        TZFilterControl_2D__AddressablePort_OutPort *masterPort =
            new TZFilterControl_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->checkPermission.connectTo(&masterPort->checkPermission);
		this->isEnabled.connectTo(&masterPort->isEnabled);
		this->isSecureSlave.connectTo(&masterPort->isSecureSlave);
		this->setConfig.connectTo(&masterPort->setConfig);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new TZFilterControl_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((TZFilterControl_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<TZFilterControl_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    TZFilterControl_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

