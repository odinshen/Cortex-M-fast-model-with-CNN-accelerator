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
 * Class definition for protocol PVBusMapperControl_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/PVBusMapperControlProtocol.lisa"
 */

#ifndef PVBusMapperControl_2D_ClassDef_h_
#define PVBusMapperControl_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_PVBusMapperControl.h"

namespace DMA_NMS {

class PVBusMapperControl_2D;

// Abstract interface implementation for port
class protocol_PVBusMapperControl__Implementation: public protocol_PVBusMapperControl
{
public:
    protocol_PVBusMapperControl__Implementation(): thisPort(0) {}

    void SetPort(PVBusMapperControl_2D *port) { thisPort = port; }

    // Protocol members
	inline unsigned remap(pv::RemapRequest& req_);
	inline void allBusMapChanging();
	inline DVM::error_response_t handleDownstreamDVMMessageFromUpstream(unsigned upstream_port_index_, void* arc_within_port_, DVM::Message* message_);
	inline DVM::error_response_t handleUpstreamDVMMessageFromDownstream(unsigned downstream_port_index_, void* arc_within_port_, DVM::Message* message_);
	inline bool getDVMNodesCanSendTo(std::vector<pv::DVMNodeRecord> & upstream_nodes_, std::vector<pv::DVMNodeRecord> & downstream_nodes_);
	inline void* getMyArcIdentifier();
	inline void printDVMNodes(std::ostream& , const std::string& indent_);
	inline void handleSnoopRequest(ACE::SnoopRequest* req_, bool debug_);
	inline void injectSnoopRequest(ACE::SnoopRequest* req_, bool debug_);
	inline void reset();


private:
    // Parent port this interface belongs to.
    PVBusMapperControl_2D *thisPort;
};


// Protocol (port) class definition
class PVBusMapperControl_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< unsigned (pv::RemapRequest&) > remap;
	sg::MasterConnector< void (void) > allBusMapChanging;
	sg::SlaveConnector< DVM::error_response_t (unsigned,void*,DVM::Message*) > handleDownstreamDVMMessageFromUpstream;
	sg::SlaveConnector< DVM::error_response_t (unsigned,void*,DVM::Message*) > handleUpstreamDVMMessageFromDownstream;
	sg::MasterConnector< bool (std::vector<pv::DVMNodeRecord> &,std::vector<pv::DVMNodeRecord> &) > getDVMNodesCanSendTo;
	sg::MasterConnector< void* (void) > getMyArcIdentifier;
	sg::MasterConnector< void (std::ostream&,const std::string&) > printDVMNodes;
	sg::SlaveConnector< void (ACE::SnoopRequest*,bool) > handleSnoopRequest;
	sg::MasterConnector< void (ACE::SnoopRequest*,bool) > injectSnoopRequest;
	sg::MasterConnector< void (void) > reset;


    PVBusMapperControl_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(remap);
		define_behaviour(allBusMapChanging);
		define_behaviour(handleDownstreamDVMMessageFromUpstream);
		define_behaviour(handleUpstreamDVMMessageFromDownstream);
		define_behaviour(getDVMNodesCanSendTo);
		define_behaviour(getMyArcIdentifier);
		define_behaviour(printDVMNodes);
		define_behaviour(handleSnoopRequest);
		define_behaviour(injectSnoopRequest);
		define_behaviour(reset);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_PVBusMapperControl__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_PVBusMapperControl *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline unsigned protocol_PVBusMapperControl__Implementation::remap(pv::RemapRequest& req_)
{
	return thisPort->remap(req_);
}

inline void protocol_PVBusMapperControl__Implementation::allBusMapChanging()
{
	return thisPort->allBusMapChanging();
}

inline DVM::error_response_t protocol_PVBusMapperControl__Implementation::handleDownstreamDVMMessageFromUpstream(unsigned upstream_port_index_, void* arc_within_port_, DVM::Message* message_)
{
	return thisPort->handleDownstreamDVMMessageFromUpstream(upstream_port_index_, arc_within_port_, message_);
}

inline DVM::error_response_t protocol_PVBusMapperControl__Implementation::handleUpstreamDVMMessageFromDownstream(unsigned downstream_port_index_, void* arc_within_port_, DVM::Message* message_)
{
	return thisPort->handleUpstreamDVMMessageFromDownstream(downstream_port_index_, arc_within_port_, message_);
}

inline bool protocol_PVBusMapperControl__Implementation::getDVMNodesCanSendTo(std::vector<pv::DVMNodeRecord> & upstream_nodes_, std::vector<pv::DVMNodeRecord> & downstream_nodes_)
{
	return thisPort->getDVMNodesCanSendTo(upstream_nodes_, downstream_nodes_);
}

inline void* protocol_PVBusMapperControl__Implementation::getMyArcIdentifier()
{
	return thisPort->getMyArcIdentifier();
}

inline void protocol_PVBusMapperControl__Implementation::printDVMNodes(std::ostream& param0__, const std::string& indent_)
{
	return thisPort->printDVMNodes(param0__, indent_);
}

inline void protocol_PVBusMapperControl__Implementation::handleSnoopRequest(ACE::SnoopRequest* req_, bool debug_)
{
	return thisPort->handleSnoopRequest(req_, debug_);
}

inline void protocol_PVBusMapperControl__Implementation::injectSnoopRequest(ACE::SnoopRequest* req_, bool debug_)
{
	return thisPort->injectSnoopRequest(req_, debug_);
}

inline void protocol_PVBusMapperControl__Implementation::reset()
{
	return thisPort->reset();
}




// Mapping object
// (these ports are implemented inside PVBusMapperControl_2D__AddressablePort)
class PVBusMapperControl_2D__AddressablePort_OutPort: public PVBusMapperControl_2D
{
public:
    // constructor
    PVBusMapperControl_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class PVBusMapperControl_2D__AddressablePort: public PVBusMapperControl_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    PVBusMapperControl_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &PVBusMapperControl_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &PVBusMapperControl_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &PVBusMapperControl_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &PVBusMapperControl_2D__AddressablePort::isMapped__, this);

    }

    ~PVBusMapperControl_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    PVBusMapperControl_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        PVBusMapperControl_2D__AddressablePort_OutPort *masterPort =
            new PVBusMapperControl_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->remap.connectTo(&masterPort->remap);
		this->allBusMapChanging.connectTo(&masterPort->allBusMapChanging);
		this->handleDownstreamDVMMessageFromUpstream.connectTo(&masterPort->handleDownstreamDVMMessageFromUpstream);
		this->handleUpstreamDVMMessageFromDownstream.connectTo(&masterPort->handleUpstreamDVMMessageFromDownstream);
		this->getDVMNodesCanSendTo.connectTo(&masterPort->getDVMNodesCanSendTo);
		this->getMyArcIdentifier.connectTo(&masterPort->getMyArcIdentifier);
		this->printDVMNodes.connectTo(&masterPort->printDVMNodes);
		this->handleSnoopRequest.connectTo(&masterPort->handleSnoopRequest);
		this->injectSnoopRequest.connectTo(&masterPort->injectSnoopRequest);
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
        defaultOutPort__ = new PVBusMapperControl_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((PVBusMapperControl_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<PVBusMapperControl_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    PVBusMapperControl_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

