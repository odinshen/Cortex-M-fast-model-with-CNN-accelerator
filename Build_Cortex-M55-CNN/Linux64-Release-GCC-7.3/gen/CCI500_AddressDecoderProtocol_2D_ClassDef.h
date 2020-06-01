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
 * Class definition for protocol CCI500_AddressDecoderProtocol_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/CCI500_AddressDecoderProtocol.lisa"
 */

#ifndef CCI500_AddressDecoderProtocol_2D_ClassDef_h_
#define CCI500_AddressDecoderProtocol_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_CCI500_AddressDecoderProtocol.h"

namespace DMA_NMS {

class CCI500_AddressDecoderProtocol_2D;

// Abstract interface implementation for port
class protocol_CCI500_AddressDecoderProtocol__Implementation: public protocol_CCI500_AddressDecoderProtocol
{
public:
    protocol_CCI500_AddressDecoderProtocol__Implementation(): thisPort(0) {}

    void SetPort(CCI500_AddressDecoderProtocol_2D *port) { thisPort = port; }

    // Protocol members
	inline void configuration(const CCI5x0_AddressDecoderConfiguration& );
	inline unsigned decode_by_4KiB_addr(unsigned upstream_port_index_, bool is_read_or_cmo_, uint64_t address_, bool ns_);
	inline void reset();
	inline void get_squash_record(unsigned downstream_port_index_, unsigned* out_lsb_bitpos_, unsigned* out_number_of_bits_to_squash_);


private:
    // Parent port this interface belongs to.
    CCI500_AddressDecoderProtocol_2D *thisPort;
};


// Protocol (port) class definition
class CCI500_AddressDecoderProtocol_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< void (const CCI5x0_AddressDecoderConfiguration&) > configuration;
	sg::SlaveConnector< unsigned (unsigned,bool,uint64_t,bool) > decode_by_4KiB_addr;
	sg::SlaveConnector< void (void) > reset;
	sg::SlaveConnector< void (unsigned,unsigned*,unsigned*) > get_squash_record;


    CCI500_AddressDecoderProtocol_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(configuration);
		define_behaviour(decode_by_4KiB_addr);
		define_behaviour(reset);
		define_behaviour(get_squash_record);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_CCI500_AddressDecoderProtocol__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_CCI500_AddressDecoderProtocol *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline void protocol_CCI500_AddressDecoderProtocol__Implementation::configuration(const CCI5x0_AddressDecoderConfiguration& param0__)
{
	return thisPort->configuration(param0__);
}

inline unsigned protocol_CCI500_AddressDecoderProtocol__Implementation::decode_by_4KiB_addr(unsigned upstream_port_index_, bool is_read_or_cmo_, uint64_t address_, bool ns_)
{
	return thisPort->decode_by_4KiB_addr(upstream_port_index_, is_read_or_cmo_, address_, ns_);
}

inline void protocol_CCI500_AddressDecoderProtocol__Implementation::reset()
{
	return thisPort->reset();
}

inline void protocol_CCI500_AddressDecoderProtocol__Implementation::get_squash_record(unsigned downstream_port_index_, unsigned* out_lsb_bitpos_, unsigned* out_number_of_bits_to_squash_)
{
	return thisPort->get_squash_record(downstream_port_index_, out_lsb_bitpos_, out_number_of_bits_to_squash_);
}




// Mapping object
// (these ports are implemented inside CCI500_AddressDecoderProtocol_2D__AddressablePort)
class CCI500_AddressDecoderProtocol_2D__AddressablePort_OutPort: public CCI500_AddressDecoderProtocol_2D
{
public:
    // constructor
    CCI500_AddressDecoderProtocol_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class CCI500_AddressDecoderProtocol_2D__AddressablePort: public CCI500_AddressDecoderProtocol_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    CCI500_AddressDecoderProtocol_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &CCI500_AddressDecoderProtocol_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &CCI500_AddressDecoderProtocol_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &CCI500_AddressDecoderProtocol_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &CCI500_AddressDecoderProtocol_2D__AddressablePort::isMapped__, this);

    }

    ~CCI500_AddressDecoderProtocol_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    CCI500_AddressDecoderProtocol_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        CCI500_AddressDecoderProtocol_2D__AddressablePort_OutPort *masterPort =
            new CCI500_AddressDecoderProtocol_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->configuration.connectTo(&masterPort->configuration);
		this->decode_by_4KiB_addr.connectTo(&masterPort->decode_by_4KiB_addr);
		this->reset.connectTo(&masterPort->reset);
		this->get_squash_record.connectTo(&masterPort->get_squash_record);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new CCI500_AddressDecoderProtocol_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((CCI500_AddressDecoderProtocol_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<CCI500_AddressDecoderProtocol_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    CCI500_AddressDecoderProtocol_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

