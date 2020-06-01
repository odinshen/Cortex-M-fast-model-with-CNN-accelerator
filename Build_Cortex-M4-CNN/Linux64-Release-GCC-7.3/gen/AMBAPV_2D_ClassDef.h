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
 * Class definition for protocol AMBAPV_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/AMBAPVProtocol.lisa"
 */

#ifndef AMBAPV_2D_ClassDef_h_
#define AMBAPV_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_AMBAPV.h"

namespace DMA_NMS {

class AMBAPV_2D;

// Abstract interface implementation for port
class protocol_AMBAPV__Implementation: public protocol_AMBAPV
{
public:
    protocol_AMBAPV__Implementation(): thisPort(0) {}

    void SetPort(AMBAPV_2D *port) { thisPort = port; }

    // Protocol members
	inline amba_pv::amba_pv_resp_t read(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int size, const amba_pv::amba_pv_control* ctrl, sc_core::sc_time& t);
	inline amba_pv::amba_pv_resp_t write(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int size, const amba_pv::amba_pv_control* ctrl, unsigned char* strb, sc_core::sc_time& t);
	inline unsigned int debug_read(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int length, const amba_pv::amba_pv_control* ctrl);
	inline unsigned int debug_write(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int length, const amba_pv::amba_pv_control* ctrl);
	inline void b_transport(int socket_id, amba_pv::amba_pv_transaction& trans, sc_core::sc_time& t);
	inline unsigned int transport_dbg(int socket_id, amba_pv::amba_pv_transaction& trans);
	inline bool get_direct_mem_ptr(int socket_id, amba_pv::amba_pv_transaction& trans, tlm::tlm_dmi& dmi_data);
	inline void invalidate_direct_mem_ptr(int socket_id, sc_dt::uint64 start_range, sc_dt::uint64 end_range);


private:
    // Parent port this interface belongs to.
    AMBAPV_2D *thisPort;
};


// Protocol (port) class definition
class AMBAPV_2D: public sg::Port
{
private:
    amba_pv::amba_pv_resp_t default_read(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int size, const amba_pv::amba_pv_control* ctrl, sc_core::sc_time& t)
{

 return amba_pv::AMBA_PV_SLVERR;
 
}
amba_pv::amba_pv_resp_t default_write(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int size, const amba_pv::amba_pv_control* ctrl, unsigned char* strb, sc_core::sc_time& t)
{

 return amba_pv::AMBA_PV_SLVERR;
 
}
unsigned int default_debug_read(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int length, const amba_pv::amba_pv_control* ctrl)
{

 return 0;
 
}
unsigned int default_debug_write(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int length, const amba_pv::amba_pv_control* ctrl)
{

 return 0;
 
}
void default_b_transport(int socket_id, amba_pv::amba_pv_transaction& trans, sc_core::sc_time& t)
{

 
}
unsigned int default_transport_dbg(int socket_id, amba_pv::amba_pv_transaction& trans)
{

 return 0;
 
}
bool default_get_direct_mem_ptr(int socket_id, amba_pv::amba_pv_transaction& trans, tlm::tlm_dmi& dmi_data)
{

 dmi_data.allow_read_write();
 dmi_data.set_start_address(0x0);
 dmi_data.set_end_address(sc_dt::uint64(-1));
 return false;
 
}
void default_invalidate_direct_mem_ptr(int socket_id, sc_dt::uint64 start_range, sc_dt::uint64 end_range)
{

 
}

public:
    // Resources


    // Connector instances
	sg::SlaveConnector< amba_pv::amba_pv_resp_t (int,const sc_dt::uint64&,unsigned char*,unsigned int,const amba_pv::amba_pv_control*,sc_core::sc_time&) > read;
	sg::SlaveConnector< amba_pv::amba_pv_resp_t (int,const sc_dt::uint64&,unsigned char*,unsigned int,const amba_pv::amba_pv_control*,unsigned char*,sc_core::sc_time&) > write;
	sg::SlaveConnector< unsigned int (int,const sc_dt::uint64&,unsigned char*,unsigned int,const amba_pv::amba_pv_control*) > debug_read;
	sg::SlaveConnector< unsigned int (int,const sc_dt::uint64&,unsigned char*,unsigned int,const amba_pv::amba_pv_control*) > debug_write;
	sg::SlaveConnector< void (int,amba_pv::amba_pv_transaction&,sc_core::sc_time&) > b_transport;
	sg::SlaveConnector< unsigned int (int,amba_pv::amba_pv_transaction&) > transport_dbg;
	sg::SlaveConnector< bool (int,amba_pv::amba_pv_transaction&,tlm::tlm_dmi&) > get_direct_mem_ptr;
	sg::MasterConnector< void (int,sc_dt::uint64,sc_dt::uint64) > invalidate_direct_mem_ptr;


    AMBAPV_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(read);
		define_behaviour(write);
		define_behaviour(debug_read);
		define_behaviour(debug_write);
		define_behaviour(b_transport);
		define_behaviour(transport_dbg);
		define_behaviour(get_direct_mem_ptr);
		define_behaviour(invalidate_direct_mem_ptr);

read.bind_default_behaviour( this, &AMBAPV_2D::default_read);write.bind_default_behaviour( this, &AMBAPV_2D::default_write);debug_read.bind_default_behaviour( this, &AMBAPV_2D::default_debug_read);debug_write.bind_default_behaviour( this, &AMBAPV_2D::default_debug_write);b_transport.bind_default_behaviour( this, &AMBAPV_2D::default_b_transport);transport_dbg.bind_default_behaviour( this, &AMBAPV_2D::default_transport_dbg);get_direct_mem_ptr.bind_default_behaviour( this, &AMBAPV_2D::default_get_direct_mem_ptr);invalidate_direct_mem_ptr.bind_default_behaviour( this, &AMBAPV_2D::default_invalidate_direct_mem_ptr);
        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_AMBAPV__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_AMBAPV *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline amba_pv::amba_pv_resp_t protocol_AMBAPV__Implementation::read(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int size, const amba_pv::amba_pv_control* ctrl, sc_core::sc_time& t)
{
	return thisPort->read(socket_id, addr, data, size, ctrl, t);
}

inline amba_pv::amba_pv_resp_t protocol_AMBAPV__Implementation::write(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int size, const amba_pv::amba_pv_control* ctrl, unsigned char* strb, sc_core::sc_time& t)
{
	return thisPort->write(socket_id, addr, data, size, ctrl, strb, t);
}

inline unsigned int protocol_AMBAPV__Implementation::debug_read(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int length, const amba_pv::amba_pv_control* ctrl)
{
	return thisPort->debug_read(socket_id, addr, data, length, ctrl);
}

inline unsigned int protocol_AMBAPV__Implementation::debug_write(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int length, const amba_pv::amba_pv_control* ctrl)
{
	return thisPort->debug_write(socket_id, addr, data, length, ctrl);
}

inline void protocol_AMBAPV__Implementation::b_transport(int socket_id, amba_pv::amba_pv_transaction& trans, sc_core::sc_time& t)
{
	return thisPort->b_transport(socket_id, trans, t);
}

inline unsigned int protocol_AMBAPV__Implementation::transport_dbg(int socket_id, amba_pv::amba_pv_transaction& trans)
{
	return thisPort->transport_dbg(socket_id, trans);
}

inline bool protocol_AMBAPV__Implementation::get_direct_mem_ptr(int socket_id, amba_pv::amba_pv_transaction& trans, tlm::tlm_dmi& dmi_data)
{
	return thisPort->get_direct_mem_ptr(socket_id, trans, dmi_data);
}

inline void protocol_AMBAPV__Implementation::invalidate_direct_mem_ptr(int socket_id, sc_dt::uint64 start_range, sc_dt::uint64 end_range)
{
	return thisPort->invalidate_direct_mem_ptr(socket_id, start_range, end_range);
}




// Mapping object
// (these ports are implemented inside AMBAPV_2D__AddressablePort)
class AMBAPV_2D__AddressablePort_OutPort: public AMBAPV_2D
{
public:
    // constructor
    AMBAPV_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class AMBAPV_2D__AddressablePort: public AMBAPV_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    AMBAPV_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &AMBAPV_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &AMBAPV_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &AMBAPV_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &AMBAPV_2D__AddressablePort::isMapped__, this);

    }

    ~AMBAPV_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    AMBAPV_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        AMBAPV_2D__AddressablePort_OutPort *masterPort =
            new AMBAPV_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->read.connectTo(&masterPort->read);
		this->write.connectTo(&masterPort->write);
		this->debug_read.connectTo(&masterPort->debug_read);
		this->debug_write.connectTo(&masterPort->debug_write);
		this->b_transport.connectTo(&masterPort->b_transport);
		this->transport_dbg.connectTo(&masterPort->transport_dbg);
		this->get_direct_mem_ptr.connectTo(&masterPort->get_direct_mem_ptr);
		this->invalidate_direct_mem_ptr.connectTo(&masterPort->invalidate_direct_mem_ptr);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new AMBAPV_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((AMBAPV_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<AMBAPV_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    AMBAPV_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

