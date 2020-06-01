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
 * Class definition for protocol PVCacheMaintenance_2D.
 * GeneratedFrom: "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/PVCacheMaintenance.lisa"
 */

#ifndef PVCacheMaintenance_2D_ClassDef_h_
#define PVCacheMaintenance_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_PVCacheMaintenance.h"

namespace DMA_NMS {

class PVCacheMaintenance_2D;

// Abstract interface implementation for port
class protocol_PVCacheMaintenance__Implementation: public protocol_PVCacheMaintenance
{
public:
    protocol_PVCacheMaintenance__Implementation(): thisPort(0) {}

    void SetPort(PVCacheMaintenance_2D *port) { thisPort = port; }

    // Protocol members
	inline void clean_all();
	inline void clean_by_addr(pv::bus_addr_t addr, bool is_non_secure);
	inline void clean_by_set_way(uint32_t set, uint32_t way, bool is_non_secure);
	inline void invalidate_all();
	inline void clean_and_invalidate_all();
	inline void invalidate_by_addr(pv::bus_addr_t addr, bool is_non_secure);
	inline void clean_and_invalidate_by_addr(pv::bus_addr_t addr, bool is_non_secure);
	inline void invalidate_by_set_way(uint32_t set, uint32_t way, bool is_non_secure);
	inline void clean_and_invalidate_by_set_way(uint32_t set, uint32_t way, bool is_non_secure);
	inline pv::Tx_Result preload(const pv::MemoryAttributes& memory_attributes_, pv::bus_addr_t address_, bool make_unique_, sg::ticks_t& local_time_);
	inline bool find_in_cache(const pv::MemoryAttributes& memory_attributes_, pv::bus_addr_t address_);
	inline void setLockDown(uint32_t lock);
	inline uint32_t getLockDown();
	inline void setIsInner(bool is_inner);
	inline bool getEnabled(bool is_non_secure);
	inline void setEnabled(bool enabled, bool is_non_secure);
	inline void setCacheStateModelled(bool modelled);
	inline bool getCacheStateModelled();
	inline void enableUpstreamAcceptsSnoopRequests(unsigned upstream_port_, bool on_);
	inline void enableUpstreamAcceptsDVM(unsigned upstream_port_, bool on_);
	inline void enableLocalDVMMessageProcessing(bool on_);
	inline void cacheSizeOverride(unsigned cache_line_size_in_bytes_, unsigned number_of_sets_, unsigned number_of_ways_);
	inline void setBitmapOfUpstreamPortsThatTreatNonSharedAsShared(uint64_t bitmap_of_upstream_ports_that_treat_nsh_as_sh);
	inline void setBitmapOfDownstreamPortsThatIsDomainBoundaryForReallyNonShared(uint64_t );


private:
    // Parent port this interface belongs to.
    PVCacheMaintenance_2D *thisPort;
};


// Protocol (port) class definition
class PVCacheMaintenance_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< void (void) > clean_all;
	sg::SlaveConnector< void (pv::bus_addr_t,bool) > clean_by_addr;
	sg::SlaveConnector< void (uint32_t,uint32_t,bool) > clean_by_set_way;
	sg::SlaveConnector< void (void) > invalidate_all;
	sg::SlaveConnector< void (void) > clean_and_invalidate_all;
	sg::SlaveConnector< void (pv::bus_addr_t,bool) > invalidate_by_addr;
	sg::SlaveConnector< void (pv::bus_addr_t,bool) > clean_and_invalidate_by_addr;
	sg::SlaveConnector< void (uint32_t,uint32_t,bool) > invalidate_by_set_way;
	sg::SlaveConnector< void (uint32_t,uint32_t,bool) > clean_and_invalidate_by_set_way;
	sg::SlaveConnector< pv::Tx_Result (const pv::MemoryAttributes&,pv::bus_addr_t,bool,sg::ticks_t&) > preload;
	sg::SlaveConnector< bool (const pv::MemoryAttributes&,pv::bus_addr_t) > find_in_cache;
	sg::SlaveConnector< void (uint32_t) > setLockDown;
	sg::SlaveConnector< uint32_t (void) > getLockDown;
	sg::SlaveConnector< void (bool) > setIsInner;
	sg::SlaveConnector< bool (bool) > getEnabled;
	sg::SlaveConnector< void (bool,bool) > setEnabled;
	sg::SlaveConnector< void (bool) > setCacheStateModelled;
	sg::SlaveConnector< bool (void) > getCacheStateModelled;
	sg::SlaveConnector< void (unsigned,bool) > enableUpstreamAcceptsSnoopRequests;
	sg::SlaveConnector< void (unsigned,bool) > enableUpstreamAcceptsDVM;
	sg::SlaveConnector< void (bool) > enableLocalDVMMessageProcessing;
	sg::SlaveConnector< void (unsigned,unsigned,unsigned) > cacheSizeOverride;
	sg::SlaveConnector< void (uint64_t) > setBitmapOfUpstreamPortsThatTreatNonSharedAsShared;
	sg::SlaveConnector< void (uint64_t) > setBitmapOfDownstreamPortsThatIsDomainBoundaryForReallyNonShared;


    PVCacheMaintenance_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(clean_all);
		define_behaviour(clean_by_addr);
		define_behaviour(clean_by_set_way);
		define_behaviour(invalidate_all);
		define_behaviour(clean_and_invalidate_all);
		define_behaviour(invalidate_by_addr);
		define_behaviour(clean_and_invalidate_by_addr);
		define_behaviour(invalidate_by_set_way);
		define_behaviour(clean_and_invalidate_by_set_way);
		define_behaviour(preload);
		define_behaviour(find_in_cache);
		define_behaviour(setLockDown);
		define_behaviour(getLockDown);
		define_behaviour(setIsInner);
		define_behaviour(getEnabled);
		define_behaviour(setEnabled);
		define_behaviour(setCacheStateModelled);
		define_behaviour(getCacheStateModelled);
		define_behaviour(enableUpstreamAcceptsSnoopRequests);
		define_behaviour(enableUpstreamAcceptsDVM);
		define_behaviour(enableLocalDVMMessageProcessing);
		define_behaviour(cacheSizeOverride);
		define_behaviour(setBitmapOfUpstreamPortsThatTreatNonSharedAsShared);
		define_behaviour(setBitmapOfDownstreamPortsThatIsDomainBoundaryForReallyNonShared);


        /* no setProtocolID() */
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_PVCacheMaintenance__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_PVCacheMaintenance *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline void protocol_PVCacheMaintenance__Implementation::clean_all()
{
	return thisPort->clean_all();
}

inline void protocol_PVCacheMaintenance__Implementation::clean_by_addr(pv::bus_addr_t addr, bool is_non_secure)
{
	return thisPort->clean_by_addr(addr, is_non_secure);
}

inline void protocol_PVCacheMaintenance__Implementation::clean_by_set_way(uint32_t set, uint32_t way, bool is_non_secure)
{
	return thisPort->clean_by_set_way(set, way, is_non_secure);
}

inline void protocol_PVCacheMaintenance__Implementation::invalidate_all()
{
	return thisPort->invalidate_all();
}

inline void protocol_PVCacheMaintenance__Implementation::clean_and_invalidate_all()
{
	return thisPort->clean_and_invalidate_all();
}

inline void protocol_PVCacheMaintenance__Implementation::invalidate_by_addr(pv::bus_addr_t addr, bool is_non_secure)
{
	return thisPort->invalidate_by_addr(addr, is_non_secure);
}

inline void protocol_PVCacheMaintenance__Implementation::clean_and_invalidate_by_addr(pv::bus_addr_t addr, bool is_non_secure)
{
	return thisPort->clean_and_invalidate_by_addr(addr, is_non_secure);
}

inline void protocol_PVCacheMaintenance__Implementation::invalidate_by_set_way(uint32_t set, uint32_t way, bool is_non_secure)
{
	return thisPort->invalidate_by_set_way(set, way, is_non_secure);
}

inline void protocol_PVCacheMaintenance__Implementation::clean_and_invalidate_by_set_way(uint32_t set, uint32_t way, bool is_non_secure)
{
	return thisPort->clean_and_invalidate_by_set_way(set, way, is_non_secure);
}

inline pv::Tx_Result protocol_PVCacheMaintenance__Implementation::preload(const pv::MemoryAttributes& memory_attributes_, pv::bus_addr_t address_, bool make_unique_, sg::ticks_t& local_time_)
{
	return thisPort->preload(memory_attributes_, address_, make_unique_, local_time_);
}

inline bool protocol_PVCacheMaintenance__Implementation::find_in_cache(const pv::MemoryAttributes& memory_attributes_, pv::bus_addr_t address_)
{
	return thisPort->find_in_cache(memory_attributes_, address_);
}

inline void protocol_PVCacheMaintenance__Implementation::setLockDown(uint32_t lock)
{
	return thisPort->setLockDown(lock);
}

inline uint32_t protocol_PVCacheMaintenance__Implementation::getLockDown()
{
	return thisPort->getLockDown();
}

inline void protocol_PVCacheMaintenance__Implementation::setIsInner(bool is_inner)
{
	return thisPort->setIsInner(is_inner);
}

inline bool protocol_PVCacheMaintenance__Implementation::getEnabled(bool is_non_secure)
{
	return thisPort->getEnabled(is_non_secure);
}

inline void protocol_PVCacheMaintenance__Implementation::setEnabled(bool enabled, bool is_non_secure)
{
	return thisPort->setEnabled(enabled, is_non_secure);
}

inline void protocol_PVCacheMaintenance__Implementation::setCacheStateModelled(bool modelled)
{
	return thisPort->setCacheStateModelled(modelled);
}

inline bool protocol_PVCacheMaintenance__Implementation::getCacheStateModelled()
{
	return thisPort->getCacheStateModelled();
}

inline void protocol_PVCacheMaintenance__Implementation::enableUpstreamAcceptsSnoopRequests(unsigned upstream_port_, bool on_)
{
	return thisPort->enableUpstreamAcceptsSnoopRequests(upstream_port_, on_);
}

inline void protocol_PVCacheMaintenance__Implementation::enableUpstreamAcceptsDVM(unsigned upstream_port_, bool on_)
{
	return thisPort->enableUpstreamAcceptsDVM(upstream_port_, on_);
}

inline void protocol_PVCacheMaintenance__Implementation::enableLocalDVMMessageProcessing(bool on_)
{
	return thisPort->enableLocalDVMMessageProcessing(on_);
}

inline void protocol_PVCacheMaintenance__Implementation::cacheSizeOverride(unsigned cache_line_size_in_bytes_, unsigned number_of_sets_, unsigned number_of_ways_)
{
	return thisPort->cacheSizeOverride(cache_line_size_in_bytes_, number_of_sets_, number_of_ways_);
}

inline void protocol_PVCacheMaintenance__Implementation::setBitmapOfUpstreamPortsThatTreatNonSharedAsShared(uint64_t bitmap_of_upstream_ports_that_treat_nsh_as_sh)
{
	return thisPort->setBitmapOfUpstreamPortsThatTreatNonSharedAsShared(bitmap_of_upstream_ports_that_treat_nsh_as_sh);
}

inline void protocol_PVCacheMaintenance__Implementation::setBitmapOfDownstreamPortsThatIsDomainBoundaryForReallyNonShared(uint64_t param0__)
{
	return thisPort->setBitmapOfDownstreamPortsThatIsDomainBoundaryForReallyNonShared(param0__);
}




// Mapping object
// (these ports are implemented inside PVCacheMaintenance_2D__AddressablePort)
class PVCacheMaintenance_2D__AddressablePort_OutPort: public PVCacheMaintenance_2D
{
public:
    // constructor
    PVCacheMaintenance_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class PVCacheMaintenance_2D__AddressablePort: public PVCacheMaintenance_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    PVCacheMaintenance_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &PVCacheMaintenance_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &PVCacheMaintenance_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &PVCacheMaintenance_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &PVCacheMaintenance_2D__AddressablePort::isMapped__, this);

    }

    ~PVCacheMaintenance_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    PVCacheMaintenance_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        PVCacheMaintenance_2D__AddressablePort_OutPort *masterPort =
            new PVCacheMaintenance_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->clean_all.connectTo(&masterPort->clean_all);
		this->clean_by_addr.connectTo(&masterPort->clean_by_addr);
		this->clean_by_set_way.connectTo(&masterPort->clean_by_set_way);
		this->invalidate_all.connectTo(&masterPort->invalidate_all);
		this->clean_and_invalidate_all.connectTo(&masterPort->clean_and_invalidate_all);
		this->invalidate_by_addr.connectTo(&masterPort->invalidate_by_addr);
		this->clean_and_invalidate_by_addr.connectTo(&masterPort->clean_and_invalidate_by_addr);
		this->invalidate_by_set_way.connectTo(&masterPort->invalidate_by_set_way);
		this->clean_and_invalidate_by_set_way.connectTo(&masterPort->clean_and_invalidate_by_set_way);
		this->preload.connectTo(&masterPort->preload);
		this->find_in_cache.connectTo(&masterPort->find_in_cache);
		this->setLockDown.connectTo(&masterPort->setLockDown);
		this->getLockDown.connectTo(&masterPort->getLockDown);
		this->setIsInner.connectTo(&masterPort->setIsInner);
		this->getEnabled.connectTo(&masterPort->getEnabled);
		this->setEnabled.connectTo(&masterPort->setEnabled);
		this->setCacheStateModelled.connectTo(&masterPort->setCacheStateModelled);
		this->getCacheStateModelled.connectTo(&masterPort->getCacheStateModelled);
		this->enableUpstreamAcceptsSnoopRequests.connectTo(&masterPort->enableUpstreamAcceptsSnoopRequests);
		this->enableUpstreamAcceptsDVM.connectTo(&masterPort->enableUpstreamAcceptsDVM);
		this->enableLocalDVMMessageProcessing.connectTo(&masterPort->enableLocalDVMMessageProcessing);
		this->cacheSizeOverride.connectTo(&masterPort->cacheSizeOverride);
		this->setBitmapOfUpstreamPortsThatTreatNonSharedAsShared.connectTo(&masterPort->setBitmapOfUpstreamPortsThatTreatNonSharedAsShared);
		this->setBitmapOfDownstreamPortsThatIsDomainBoundaryForReallyNonShared.connectTo(&masterPort->setBitmapOfDownstreamPortsThatIsDomainBoundaryForReallyNonShared);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new PVCacheMaintenance_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((PVCacheMaintenance_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<PVCacheMaintenance_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    PVCacheMaintenance_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

