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
 * Class definition for protocol Builtin__ControlProtocol_2D.
 * GeneratedFrom: "<string-input>"
 */

#ifndef Builtin__ControlProtocol_2D_ClassDef_h_
#define Builtin__ControlProtocol_2D_ClassDef_h_

#include <eslapi/eslapi_stdint.h>

#include <list>
#include "sg/SGPort.h"

#include "protocol_Builtin__ControlProtocol.h"

namespace DMA_NMS {

class Builtin__ControlProtocol_2D;

// Abstract interface implementation for port
class protocol_Builtin__ControlProtocol__Implementation: public protocol_Builtin__ControlProtocol
{
public:
    protocol_Builtin__ControlProtocol__Implementation(): thisPort(0) {}

    void SetPort(Builtin__ControlProtocol_2D *port) { thisPort = port; }

    // Protocol members
	inline void configure(const sg::Params& params);
	inline void init();
	inline void interconnect();
	inline void reset(int level);
	inline void loadApplicationFile(const std::string& filename);
	inline void serializeState(const char* name, cp::SerializationInterface* stream);
	inline void interrupt();
	inline void disconnect();
	inline void terminate();
	inline void populateCADIMap(std::map<std::string,eslapi::CAInterface *> & , const std::string& );
	inline void step();
	inline std::string getProperty(const std::string& );
	inline std::string bypass(const std::string& );
	inline std::string callSimEngine(const std::string& );
	inline void run();
	inline void stop();
	inline void idle();
	inline void quit();
	inline void setSimulationEngine(sg::SimulationEngine* );
	inline void message(const std::string& msg, sg::message::MessageType msgType);


private:
    // Parent port this interface belongs to.
    Builtin__ControlProtocol_2D *thisPort;
};


// Protocol (port) class definition
class Builtin__ControlProtocol_2D: public sg::Port
{
private:
    
public:
    // Resources


    // Connector instances
	sg::SlaveConnector< void (const sg::Params&) > configure;
	sg::SlaveConnector< void (void) > init;
	sg::SlaveConnector< void (void) > interconnect;
	sg::SlaveConnector< void (int) > reset;
	sg::SlaveConnector< void (const std::string&) > loadApplicationFile;
	sg::SlaveConnector< void (const char*,cp::SerializationInterface*) > serializeState;
	sg::SlaveConnector< void (void) > interrupt;
	sg::SlaveConnector< void (void) > disconnect;
	sg::SlaveConnector< void (void) > terminate;
	sg::SlaveConnector< void (std::map<std::string,eslapi::CAInterface *> &,const std::string&) > populateCADIMap;
	sg::SlaveConnector< void (void) > step;
	sg::SlaveConnector< std::string (const std::string&) > getProperty;
	sg::SlaveConnector< std::string (const std::string&) > bypass;
	sg::MasterConnector< std::string (const std::string&) > callSimEngine;
	sg::SlaveConnector< void (void) > run;
	sg::SlaveConnector< void (void) > stop;
	sg::PeerConnector< void (void) > idle;
	sg::MasterConnector< void (void) > quit;
	sg::SlaveConnector< void (sg::SimulationEngine*) > setSimulationEngine;
	sg::MasterConnector< void (const std::string&,sg::message::MessageType) > message;


    Builtin__ControlProtocol_2D()
    {
        abstractInterface__.SetPort(this);
		define_behaviour(configure);
		define_behaviour(init);
		define_behaviour(interconnect);
		define_behaviour(reset);
		define_behaviour(loadApplicationFile);
		define_behaviour(serializeState);
		define_behaviour(interrupt);
		define_behaviour(disconnect);
		define_behaviour(terminate);
		define_behaviour(populateCADIMap);
		define_behaviour(step);
		define_behaviour(getProperty);
		define_behaviour(bypass);
		define_behaviour(callSimEngine);
		define_behaviour(run);
		define_behaviour(stop);
		define_behaviour(idle);
		define_behaviour(quit);
		define_behaviour(setSimulationEngine);
		define_behaviour(message);


        setProtocolID("ARM::Builtin.ControlProtocol");
    }

    // Set name (currently ignored here)
    void SetName__(const char *) {}

    // Abstract port interface for non-LISA C++ components
    protocol_Builtin__ControlProtocol__Implementation abstractInterface__;

    // Get abstract interface for non-LISA C++ components
    protocol_Builtin__ControlProtocol *getAbstractInterface() { return &abstractInterface__; }
};


// Abstract interface implementations
inline void protocol_Builtin__ControlProtocol__Implementation::configure(const sg::Params& params)
{
	return thisPort->configure(params);
}

inline void protocol_Builtin__ControlProtocol__Implementation::init()
{
	return thisPort->init();
}

inline void protocol_Builtin__ControlProtocol__Implementation::interconnect()
{
	return thisPort->interconnect();
}

inline void protocol_Builtin__ControlProtocol__Implementation::reset(int level)
{
	return thisPort->reset(level);
}

inline void protocol_Builtin__ControlProtocol__Implementation::loadApplicationFile(const std::string& filename)
{
	return thisPort->loadApplicationFile(filename);
}

inline void protocol_Builtin__ControlProtocol__Implementation::serializeState(const char* name, cp::SerializationInterface* stream)
{
	return thisPort->serializeState(name, stream);
}

inline void protocol_Builtin__ControlProtocol__Implementation::interrupt()
{
	return thisPort->interrupt();
}

inline void protocol_Builtin__ControlProtocol__Implementation::disconnect()
{
	return thisPort->disconnect();
}

inline void protocol_Builtin__ControlProtocol__Implementation::terminate()
{
	return thisPort->terminate();
}

inline void protocol_Builtin__ControlProtocol__Implementation::populateCADIMap(std::map<std::string,eslapi::CAInterface *> & param0__, const std::string& param1__)
{
	return thisPort->populateCADIMap(param0__, param1__);
}

inline void protocol_Builtin__ControlProtocol__Implementation::step()
{
	return thisPort->step();
}

inline std::string protocol_Builtin__ControlProtocol__Implementation::getProperty(const std::string& param0__)
{
	return thisPort->getProperty(param0__);
}

inline std::string protocol_Builtin__ControlProtocol__Implementation::bypass(const std::string& param0__)
{
	return thisPort->bypass(param0__);
}

inline std::string protocol_Builtin__ControlProtocol__Implementation::callSimEngine(const std::string& param0__)
{
	return thisPort->callSimEngine(param0__);
}

inline void protocol_Builtin__ControlProtocol__Implementation::run()
{
	return thisPort->run();
}

inline void protocol_Builtin__ControlProtocol__Implementation::stop()
{
	return thisPort->stop();
}

inline void protocol_Builtin__ControlProtocol__Implementation::idle()
{
	return thisPort->idle();
}

inline void protocol_Builtin__ControlProtocol__Implementation::quit()
{
	return thisPort->quit();
}

inline void protocol_Builtin__ControlProtocol__Implementation::setSimulationEngine(sg::SimulationEngine* param0__)
{
	return thisPort->setSimulationEngine(param0__);
}

inline void protocol_Builtin__ControlProtocol__Implementation::message(const std::string& msg, sg::message::MessageType msgType)
{
	return thisPort->message(msg, msgType);
}




// Mapping object
// (these ports are implemented inside Builtin__ControlProtocol_2D__AddressablePort)
class Builtin__ControlProtocol_2D__AddressablePort_OutPort: public Builtin__ControlProtocol_2D
{
public:
    // constructor
    Builtin__ControlProtocol_2D__AddressablePort_OutPort(uint32_t inFirst,
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
class Builtin__ControlProtocol_2D__AddressablePort: public Builtin__ControlProtocol_2D
{
public:
    declare_slave_behaviour(mapRange, sg::Port*(uint64_t inFirst, uint64_t inLast, uint64_t outFirst, uint64_t outLast));
    declare_slave_behaviour(mapDefault, sg::Port*());
    declare_slave_behaviour(unmapRange, void(sg::Port*));
    declare_slave_behaviour(isMapped, bool(uint64_t));

    Builtin__ControlProtocol_2D__AddressablePort():
    defaultOutPort__(0),
    portName__("(unknown name)")
    {
        define_behaviour(mapRange);
        define_behaviour(mapDefault);
        define_behaviour(unmapRange);
        define_behaviour(isMapped);
        bind_method(*this, mapRange, &Builtin__ControlProtocol_2D__AddressablePort::mapRange__, this);
        bind_method(*this, mapDefault, &Builtin__ControlProtocol_2D__AddressablePort::mapDefault__, this);
        bind_method(*this, unmapRange, &Builtin__ControlProtocol_2D__AddressablePort::unmapRange__, this);
        bind_method(*this, isMapped, &Builtin__ControlProtocol_2D__AddressablePort::isMapped__, this);

    }

    ~Builtin__ControlProtocol_2D__AddressablePort()
    {
        OutPortList__::iterator it;
        for (it = outPortList__.begin(); it != outPortList__.end(); ++it)
            delete *it;
        delete defaultOutPort__;
    }

    void SetName__(const char *name) { portName__ = name; }

    Builtin__ControlProtocol_2D__AddressablePort_OutPort *locateOutPort__(uint32_t &addr)
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
        Builtin__ControlProtocol_2D__AddressablePort_OutPort *masterPort =
            new Builtin__ControlProtocol_2D__AddressablePort_OutPort(inFirst, inLast, outFirst, outLast);
		this->configure.connectTo(&masterPort->configure);
		this->init.connectTo(&masterPort->init);
		this->interconnect.connectTo(&masterPort->interconnect);
		this->reset.connectTo(&masterPort->reset);
		this->loadApplicationFile.connectTo(&masterPort->loadApplicationFile);
		this->serializeState.connectTo(&masterPort->serializeState);
		this->interrupt.connectTo(&masterPort->interrupt);
		this->disconnect.connectTo(&masterPort->disconnect);
		this->terminate.connectTo(&masterPort->terminate);
		this->populateCADIMap.connectTo(&masterPort->populateCADIMap);
		this->step.connectTo(&masterPort->step);
		this->getProperty.connectTo(&masterPort->getProperty);
		this->bypass.connectTo(&masterPort->bypass);
		this->callSimEngine.connectTo(&masterPort->callSimEngine);
		this->run.connectTo(&masterPort->run);
		this->stop.connectTo(&masterPort->stop);
		this->idle.connectTo(&masterPort->idle);
		this->quit.connectTo(&masterPort->quit);
		this->setSimulationEngine.connectTo(&masterPort->setSimulationEngine);
		this->message.connectTo(&masterPort->message);

        // push_front() because the first statement should have the lowest priority and the last statement should have the
        // highest priority, like PVBusDecoder
        outPortList__.push_front(masterPort);
        return masterPort;
    }

    // map default slave
    sg::Port* mapDefault__()
    {
        delete defaultOutPort__;
        defaultOutPort__ = new Builtin__ControlProtocol_2D__AddressablePort_OutPort(0, uint32_t(0) - 1, 0, uint32_t(0) - 1);
        return defaultOutPort__;
    }

    void unmapRange__(sg::Port* port)
    {
        outPortList__.remove((Builtin__ControlProtocol_2D__AddressablePort_OutPort*)port);
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
    typedef std::list<Builtin__ControlProtocol_2D__AddressablePort_OutPort*> OutPortList__;
    OutPortList__ outPortList__;
    Builtin__ControlProtocol_2D__AddressablePort_OutPort *defaultOutPort__;
    const char *portName__;
};

} // namespace DMA_NMS

#endif

