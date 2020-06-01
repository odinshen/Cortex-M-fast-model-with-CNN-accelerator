/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2006 ARM Limited.
 * Copyright 2011 ARM LImited.
 *
 * All rights reserved.
 */

/** \file
 * Class definition for Component SGSignal2AMBAPVSignal.
 */

#ifndef Component_Component__SGSignal2AMBAPVSignal_ClassDef_h_
#define Component_Component__SGSignal2AMBAPVSignal_ClassDef_h_

#include <eslapi/eslapi_stdint.h>
#include <Int2String.h>
#include <limits.h>
#include <map>
#include <fstream>
#include <utility>
#include "SystemGenComponent.h"
#include "CADIBase.h"
#include "ComponentRegister.h"
#include "ResourceAccessFuncTypes.h"
#include "CADIParameterProxy.h"
#include "ParameterFilter.h"
#include "sg/SGTargetInfo.h"
#include "sg/MTDomainGate.h"
#include "sg/SGComponentBaseForwarder.h"
#include "DMA_DSO.h"

using namespace std;

#include "AMBAPVSignal_2D_ClassDef.h"
#include "Signal_2D_ClassDef.h"



namespace sg
{
    class SimulationEngine;
}

class ObjectLoader;

using namespace sg::accessfunc;

namespace eslapi
{
    class CADI;
}

namespace DMA_NMS {



class
#ifndef _WINDOWS
SG_DMA_DSO
#endif
Component__SGSignal2AMBAPVSignal: public SystemGenComponent
{
    // CADI class can see the resources (for MEMORY sections).
    friend class Component__SGSignal2AMBAPVSignal_CADI;
private:
    // resources
    //
    // This might include type definitions used by the behaviour declarations
    // and so must be before the behaviour section.
    //
    // NOTE that the property "resources_are_public" controls if the resources
    // can be accessed by their parents.  If this property is missing or 0 then
    // the resources are private.  If it is 1 then they are public.
    //
    // This option is only intended as a work-around for customers who have
    // inadvertently broken the encapsulation of the sub-component.
    
public:

    // constructor and destructor
    Component__SGSignal2AMBAPVSignal(const char *instName, sg::SimulationContext* simulationContext, const sg::Params & params);
    ~Component__SGSignal2AMBAPVSignal();

    // abstract ports
	AMBAPVSignal_2D amba_pv_signal_m; 
	Signal_2D sg_signal_s; 

    
    // Behaviours
	void interconnect();
	void disconnect();
	void loadApplicationFile(const std::string& filename);
	void init();
	void terminate();
	void reset(int level);
	void reset(int level, int /*argc*/, char** /*argv*/);
	void step();
	void abstract_port__sg_signal_s__setValue(sg::Signal::State value);


    // These are explicitly lists in the LISA reference manual as being callable.
    void simHalt();
    void simRun();
    bool simIsRunning();
    void simShutdown();
    void simReset(uint32_t level);

private:
        
    // pointers to subcomponents


    // control ports of subcomponents


    std::string application_pathname;

    // find parameter name for a specific CADIFactory parameter ID
    std::map<uint32_t,std::string> parameterId2parameterName__;

    // interface functions
    sg::SimulationContext* getSimulationContext() const { return simulationContext__; }

    // control port implementation
    void control_port__configure(const sg::Params& params);
    void control_port__init();
    void control_port__loadApplicationFile(const std::string& filename);
    void control_port__serializeState(const char *name, cp::SerializationInterface* stream);
    std::string control_port__getProperty(const std::string& propname);
    std::string control_port__bypass(const std::string&);
    void control_port__run();
    void control_port__stop();
    void control_port__idle();
    void control_port__quit();
    void control_port__getMxDI(std::map<std::string,eslapi::CADI*>*);
    void control_port__setSimulationEngine(sg::SimulationEngine*);
    void control_port__populateCADIMap(std::map< std::string, eslapi::CAInterface* > &, std::string const &);
    void control_port__message(const std::string &msg, sg::message::MessageType msgType);
    std::string control_port__callSimEngine(const std::string&);
    void control_port__reset(int level);
    void control_port__terminate();

    // CADI Port implementations
    eslapi::CADIReturn_t cadiPort__GetParameterValues (uint32_t parameterCount, uint32_t *actualNumOfParamsRead, eslapi::CADIParameterValue_t *paramValuesOut);
    eslapi::CADIReturn_t cadiPort__SetParameters(uint32_t count, eslapi::CADIParameterValue_t *params, eslapi::CADIFactoryErrorMessage_t *error);
    eslapi::CADIReturn_t cadiPort__GetProperty(const std::string& propertyName, std::string &value);
    void cadiPort__LoadApplicationFile(const std::string& filename);
    void cadiPort__GetApplicationsAndCommandLineParams(std::map<std::string, std::string>&applications2params_);

    // helper functions
    void insertCADIMap__(std::string prefix, std::map< std::string, eslapi::CAInterface*>&componentName2CADI);

    sg::accessfunc::AccessFuncResult parameter_read_func(uint32_t id, int64_t *data);
    sg::accessfunc::AccessFuncResult parameter_read_string_func(uint32_t id, std::string &data);
    sg::accessfunc::AccessFuncResult parameter_write_func(uint32_t id, const int64_t *data);
    sg::accessfunc::AccessFuncResult parameter_write_string_func(uint32_t id, const std::string &data);

    sg::accessfunc::AccessFuncResult GetExtendedTargetFeatures__(uint32_t /*id*/, std::string &data, bool /*se*/);

    // dummy functions, mostly required by IsimMain (formerly InterpreterMain), will go away soon

    // May be required by TraceGen however that itself is obsolete
    uint64_t getInstructionCount() const { return 0; }
    // May be required by SystemGen however that itself is obsolete
    uint64_t getCycleCount() const { return 0; }
    

    // methods
    eslapi::CADI* obtainCADI__(const std::string &subcomp, const std::map< std::string, eslapi::CAInterface* > &componentName2CADI) const;
    static bool ForwardParameterValueToSubcomponent(CADIParameterProxy *proxy,
                                                    const char *param_name,
                                                    int64_t intVal,
                                                    const char *strVal);
    uint32_t paramNameToParamAccessFuncID(const std::string &name);
    void buildDebugInfoWithMetaData__();

    void reset_resources__();
    void freeCADIResources__();
    void connect_controlports__();
    void add_abstractports__();
    void wire_connectionmap__();

    	void add_abstractports__0__();

    






    // definition of parameter IDs as constants for use in parameter access functions




};

namespace MT {

    //
    // This represents Component__SGSignal2AMBAPVSignal wrapped through a proxy so that it can
    // be hosted in a separate MTDomain.
    //
    // It only implements the bare minimum that is allowed to be called by a
    // parent component on a child that it contains.
    //
    // NOTE that there are two parts to this:
    //     - the base class is used for all users that manipulate the object
    //       through sg::ComponentBase or via any of its public ports.
    //     - the 'raw_component' that is _only_ used if the parent call
    //       behaviours in the sub-component.  The calls are forwarded
    //       by taking an MTDomainGate and perfectly forwarding the behaviours.
    //
    class
#ifndef _WINDOWS
    SG_DMA_DSO
#endif
    Component__SGSignal2AMBAPVSignal : public sg::ComponentBaseForwarder
    {
        using wrapped_type = DMA_NMS::Component__SGSignal2AMBAPVSignal;
    public:
        
        Component__SGSignal2AMBAPVSignal(
            sg::ComponentFactory*      factory,
            sg::MTWrapperConfig const& wrapper_config,
            std::string const&         mtdomain_name,
            std::string const&         instName,
            sg::SimulationContext*     simulationContext,
            sg::Params const&          params
            );
        ~Component__SGSignal2AMBAPVSignal();


        // Non-internal ports of components are public and the parent component
        // can drive the behaviours directly in LISA or via the abstract C++
        // interface that just forwards them to the connectors in any event.
        //
        // Thus to proxy the components we just list them again and connector
        // their connectors like any other port.
	AMBAPVSignal_2D amba_pv_signal_m; 
	Signal_2D sg_signal_s; 


        // A parent component is allowed to call behaviours in this class, we
        // have to proxy them to the actual component.  We can do this by
        // perfect forwarding.
#define ARM_S(BEHAVIOUR_NAME)                                            \
    template<typename... U>                                              \
    auto BEHAVIOUR_NAME(U&&... args_)                                    \
        -> decltype(std::declval<wrapped_type>()                         \
                    .BEHAVIOUR_NAME(std::forward<U>(args_)...))          \
    {                                                                    \
        if (mtdomain_id.isUnknown())                                    \
            return raw_component->BEHAVIOUR_NAME(std::forward<U>(args_)...); \
        sg::MTDomainGate gate(mtdomain_id);                              \
        return raw_component->BEHAVIOUR_NAME(std::forward<U>(args_)...); \
    }

    ARM_S( interconnect )\
    ARM_S( disconnect )\
    ARM_S( loadApplicationFile )\
    ARM_S( init )\
    ARM_S( terminate )\
    ARM_S( reset )\
    ARM_S( step )\


    // Standard behaviours are automatically generated
//    ARM_S ( interconnect        );
//    ARM_S ( disconnect          );
//    ARM_S ( loadApplicationFile );
//    ARM_S ( init                );
//    ARM_S ( terminate           );
//    ARM_S ( reset               );
//    ARM_S ( step                );

    // These are explicitly lists in the LISA reference manual as being callable.
    ARM_S ( simHalt             );
    ARM_S ( simRun              );
    ARM_S ( simIsRunning        );
    ARM_S ( simShutdown         );
    ARM_S ( simReset            );
    
#undef ARM_S
    private:
        wrapped_type*       raw_component;
        sg::MTDomainID      mtdomain_id;
    };
}
    
} // namespace DMA_NMS

#endif

