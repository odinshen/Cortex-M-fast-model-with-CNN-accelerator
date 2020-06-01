/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2009 ARM Limited.
 * Copyright 2011 ARM Limited.
 *
 * All rights reserved.
 */
/** \file
 * System components.
 */

#include "GlobalDefs.h"
#include "Components.h"

#include "Component__AMBAPV2PVBus_ClassDef.h"
#include "Component__AMBAPVSignal2SGSignal_ClassDef.h"
#include "Component__PVBus2AMBAPV_ClassDef.h"
#include "Component__RAMDevice_ClassDef.h"
#include "Component__SGSignal2AMBAPVSignal_ClassDef.h"
#include "Component__DMA_ClassDef.h"
#include "Component__AMBAPV2PVBus_ClassDef.h"
#include "Component__PVBus2AMBAPV_ClassDef.h"
#include "Component__SGSignal2AMBAPVSignal_ClassDef.h"
#include "Component__AMBAPVSignal2SGSignal_ClassDef.h"


#include "eslapi/CADITypes.h"

#include "cp/SerializationInterface.h"


#include "sg/SGBasicComponentFactory.h"
#include "sg/FastDelegate.h"

#include "TerminateScheduler.h"
#include "ParameterFilter.h"

#include <sg/MSCFixes.h>

// make the MSG_<...> symbols available in the global namespace
using namespace sg::message;
using namespace fastdelegate;

// component CADI interfaces
// ------------------------------------------------------------------------------
// CADI Interface for component Component__DMA
// ------------------------------------------------------------------------------

namespace DMA_NMS {

class Component__DMA_CADI : public sg::CADIBase
{
public:
        Component__DMA_CADI(Component__DMA* parentComponent, sg::ComponentBase* simulationEngine);

    eslapi::CADIReturn_t CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response);

private:
    Component__DMA *component;
};

} // DMA_NMS
// ------------------------------------------------------------------------------
// CADI Interface for component Component__AMBAPV2PVBus
// ------------------------------------------------------------------------------

namespace DMA_NMS {

class Component__AMBAPV2PVBus_CADI : public sg::CADIBase
{
public:
        Component__AMBAPV2PVBus_CADI(Component__AMBAPV2PVBus* parentComponent, sg::ComponentBase* simulationEngine);

    eslapi::CADIReturn_t CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response);

private:
    Component__AMBAPV2PVBus *component;
};

} // DMA_NMS
// ------------------------------------------------------------------------------
// CADI Interface for component Component__PVBus2AMBAPV
// ------------------------------------------------------------------------------

namespace DMA_NMS {

class Component__PVBus2AMBAPV_CADI : public sg::CADIBase
{
public:
        Component__PVBus2AMBAPV_CADI(Component__PVBus2AMBAPV* parentComponent, sg::ComponentBase* simulationEngine);

    eslapi::CADIReturn_t CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response);

private:
    Component__PVBus2AMBAPV *component;
};

} // DMA_NMS
// ------------------------------------------------------------------------------
// CADI Interface for component Component__SGSignal2AMBAPVSignal
// ------------------------------------------------------------------------------

namespace DMA_NMS {

class Component__SGSignal2AMBAPVSignal_CADI : public sg::CADIBase
{
public:
        Component__SGSignal2AMBAPVSignal_CADI(Component__SGSignal2AMBAPVSignal* parentComponent, sg::ComponentBase* simulationEngine);

    eslapi::CADIReturn_t CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response);

private:
    Component__SGSignal2AMBAPVSignal *component;
};

} // DMA_NMS
// ------------------------------------------------------------------------------
// CADI Interface for component Component__AMBAPVSignal2SGSignal
// ------------------------------------------------------------------------------

namespace DMA_NMS {

class Component__AMBAPVSignal2SGSignal_CADI : public sg::CADIBase
{
public:
        Component__AMBAPVSignal2SGSignal_CADI(Component__AMBAPVSignal2SGSignal* parentComponent, sg::ComponentBase* simulationEngine);

    eslapi::CADIReturn_t CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response);

private:
    Component__AMBAPVSignal2SGSignal *component;
};

} // DMA_NMS


// non inline behaviors
#line 4 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/EVS_Platforms/EVS_DMA/LISA/DMA_Cortex-M55.lisa"
namespace DMA_NMS { void 
Component__DMA::interconnect()
{{if(!controlPort_Core__.interconnect.empty()) controlPort_Core__.interconnect();if(!controlPort_ProgMem__.interconnect.empty()) controlPort_ProgMem__.interconnect();if(!controlPort_SrcMem__.interconnect.empty()) controlPort_SrcMem__.interconnect();if(!controlPort_PVBus__.interconnect.empty()) controlPort_PVBus__.interconnect();if(!controlPort_Clock100MHz__.interconnect.empty()) controlPort_Clock100MHz__.interconnect();if(!controlPort_AMBAPVBus__.interconnect.empty()) controlPort_AMBAPVBus__.interconnect();if(!controlPort_AMBAPVBridge__.interconnect.empty()) controlPort_AMBAPVBridge__.interconnect();if(!controlPort_SignalBridge__.interconnect.empty()) controlPort_SignalBridge__.interconnect();if(!controlPort_ReverseBridge__.interconnect.empty()) controlPort_ReverseBridge__.interconnect();if(!controlPort_Clock1Hz__.interconnect.empty()) controlPort_Clock1Hz__.interconnect();};
}
}

#line 4 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/EVS_Platforms/EVS_DMA/LISA/DMA_Cortex-M55.lisa"
namespace DMA_NMS { void 
Component__DMA::disconnect()
{{if(!controlPort_Core__.disconnect.empty()) controlPort_Core__.disconnect();if(!controlPort_ProgMem__.disconnect.empty()) controlPort_ProgMem__.disconnect();if(!controlPort_SrcMem__.disconnect.empty()) controlPort_SrcMem__.disconnect();if(!controlPort_PVBus__.disconnect.empty()) controlPort_PVBus__.disconnect();if(!controlPort_Clock100MHz__.disconnect.empty()) controlPort_Clock100MHz__.disconnect();if(!controlPort_AMBAPVBus__.disconnect.empty()) controlPort_AMBAPVBus__.disconnect();if(!controlPort_AMBAPVBridge__.disconnect.empty()) controlPort_AMBAPVBridge__.disconnect();if(!controlPort_SignalBridge__.disconnect.empty()) controlPort_SignalBridge__.disconnect();if(!controlPort_ReverseBridge__.disconnect.empty()) controlPort_ReverseBridge__.disconnect();if(!controlPort_Clock1Hz__.disconnect.empty()) controlPort_Clock1Hz__.disconnect();};
}
}

#line 4 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/EVS_Platforms/EVS_DMA/LISA/DMA_Cortex-M55.lisa"
namespace DMA_NMS { void 
Component__DMA::loadApplicationFile(const std::string& filename)
{{if(!controlPort_Core__.loadApplicationFile.empty()) controlPort_Core__.loadApplicationFile(filename);if(!controlPort_ProgMem__.loadApplicationFile.empty()) controlPort_ProgMem__.loadApplicationFile(filename);if(!controlPort_SrcMem__.loadApplicationFile.empty()) controlPort_SrcMem__.loadApplicationFile(filename);if(!controlPort_PVBus__.loadApplicationFile.empty()) controlPort_PVBus__.loadApplicationFile(filename);if(!controlPort_Clock100MHz__.loadApplicationFile.empty()) controlPort_Clock100MHz__.loadApplicationFile(filename);if(!controlPort_AMBAPVBus__.loadApplicationFile.empty()) controlPort_AMBAPVBus__.loadApplicationFile(filename);if(!controlPort_AMBAPVBridge__.loadApplicationFile.empty()) controlPort_AMBAPVBridge__.loadApplicationFile(filename);if(!controlPort_SignalBridge__.loadApplicationFile.empty()) controlPort_SignalBridge__.loadApplicationFile(filename);if(!controlPort_ReverseBridge__.loadApplicationFile.empty()) controlPort_ReverseBridge__.loadApplicationFile(filename);if(!controlPort_Clock1Hz__.loadApplicationFile.empty()) controlPort_Clock1Hz__.loadApplicationFile(filename);};(void)filename;
}
}

#line 4 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/EVS_Platforms/EVS_DMA/LISA/DMA_Cortex-M55.lisa"
namespace DMA_NMS { void 
Component__DMA::init()
{{if(!controlPort_Core__.init.empty()) controlPort_Core__.init();if(!controlPort_ProgMem__.init.empty()) controlPort_ProgMem__.init();if(!controlPort_SrcMem__.init.empty()) controlPort_SrcMem__.init();if(!controlPort_PVBus__.init.empty()) controlPort_PVBus__.init();if(!controlPort_Clock100MHz__.init.empty()) controlPort_Clock100MHz__.init();if(!controlPort_AMBAPVBus__.init.empty()) controlPort_AMBAPVBus__.init();if(!controlPort_AMBAPVBridge__.init.empty()) controlPort_AMBAPVBridge__.init();if(!controlPort_SignalBridge__.init.empty()) controlPort_SignalBridge__.init();if(!controlPort_ReverseBridge__.init.empty()) controlPort_ReverseBridge__.init();if(!controlPort_Clock1Hz__.init.empty()) controlPort_Clock1Hz__.init();};
}
}

#line 4 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/EVS_Platforms/EVS_DMA/LISA/DMA_Cortex-M55.lisa"
namespace DMA_NMS { void 
Component__DMA::terminate()
{{if(!controlPort_Core__.terminate.empty()) controlPort_Core__.terminate();if(!controlPort_ProgMem__.terminate.empty()) controlPort_ProgMem__.terminate();if(!controlPort_SrcMem__.terminate.empty()) controlPort_SrcMem__.terminate();if(!controlPort_PVBus__.terminate.empty()) controlPort_PVBus__.terminate();if(!controlPort_Clock100MHz__.terminate.empty()) controlPort_Clock100MHz__.terminate();if(!controlPort_AMBAPVBus__.terminate.empty()) controlPort_AMBAPVBus__.terminate();if(!controlPort_AMBAPVBridge__.terminate.empty()) controlPort_AMBAPVBridge__.terminate();if(!controlPort_SignalBridge__.terminate.empty()) controlPort_SignalBridge__.terminate();if(!controlPort_ReverseBridge__.terminate.empty()) controlPort_ReverseBridge__.terminate();if(!controlPort_Clock1Hz__.terminate.empty()) controlPort_Clock1Hz__.terminate();};
}
}

#line 4 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/EVS_Platforms/EVS_DMA/LISA/DMA_Cortex-M55.lisa"
namespace DMA_NMS { void 
Component__DMA::reset(int level)
{{if(!controlPort_Core__.reset.empty()) controlPort_Core__.reset(level);if(!controlPort_ProgMem__.reset.empty()) controlPort_ProgMem__.reset(level);if(!controlPort_SrcMem__.reset.empty()) controlPort_SrcMem__.reset(level);if(!controlPort_PVBus__.reset.empty()) controlPort_PVBus__.reset(level);if(!controlPort_Clock100MHz__.reset.empty()) controlPort_Clock100MHz__.reset(level);if(!controlPort_AMBAPVBus__.reset.empty()) controlPort_AMBAPVBus__.reset(level);if(!controlPort_AMBAPVBridge__.reset.empty()) controlPort_AMBAPVBridge__.reset(level);if(!controlPort_SignalBridge__.reset.empty()) controlPort_SignalBridge__.reset(level);if(!controlPort_ReverseBridge__.reset.empty()) controlPort_ReverseBridge__.reset(level);if(!controlPort_Clock1Hz__.reset.empty()) controlPort_Clock1Hz__.reset(level);};(void)level;
}
}

#line 4 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/EVS_Platforms/EVS_DMA/LISA/DMA_Cortex-M55.lisa"
namespace DMA_NMS { void 
Component__DMA::reset(int level, int /*argc*/, char** /*argv*/)
{
	reset(level);

}
}

#line 4 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/EVS_Platforms/EVS_DMA/LISA/DMA_Cortex-M55.lisa"
namespace DMA_NMS { void 
Component__DMA::step()
{{if(!controlPort_Core__.step.empty()) controlPort_Core__.step();if(!controlPort_ProgMem__.step.empty()) controlPort_ProgMem__.step();if(!controlPort_SrcMem__.step.empty()) controlPort_SrcMem__.step();if(!controlPort_PVBus__.step.empty()) controlPort_PVBus__.step();if(!controlPort_Clock100MHz__.step.empty()) controlPort_Clock100MHz__.step();if(!controlPort_AMBAPVBus__.step.empty()) controlPort_AMBAPVBus__.step();if(!controlPort_AMBAPVBridge__.step.empty()) controlPort_AMBAPVBridge__.step();if(!controlPort_SignalBridge__.step.empty()) controlPort_SignalBridge__.step();if(!controlPort_ReverseBridge__.step.empty()) controlPort_ReverseBridge__.step();if(!controlPort_Clock1Hz__.step.empty()) controlPort_Clock1Hz__.step();};
}
}

#line 200 "./Linux64-Release-GCC-7.3/gen/Comp_NonDSO_1.cpp"

// ------------------------------------------------------------------------------
// implementation of class Component__DMA
// ------------------------------------------------------------------------------

namespace DMA_NMS {


    namespace MT
    {
        Component__DMA::Component__DMA(
            sg::ComponentFactory*      factory,
            sg::MTWrapperConfig const& wrapper_config,
            std::string const&         mtdomain_name,
            std::string const&         instName,
            sg::SimulationContext*     simulationContext,
            sg::Params const&          params
            )
        {
        
            // what this creates is a component where 
            auto result = MTComponentWrapper(
                factory, wrapper_config, mtdomain_name, instName, simulationContext, params
                );
            mtdomain_id   = result.mtdomain_id;
            raw_component = dynamic_cast<wrapped_type*>(result.raw_component);
            setComponentBase(result.wrapper_component);

            // Forward the ports in the publicly visible part of the class to the
            // versions that have been created by the wrapper.
            connectPort(KIND_IN_WRAPPED_COMPONENT_Master, "amba_pv_m", amba_pv_m);
            connectPort(KIND_IN_WRAPPED_COMPONENT_Slave, "amba_pv_s", amba_pv_s);
            connectPort(KIND_IN_WRAPPED_COMPONENT_Slave, "irq_in", irq_in);
            connectPort(KIND_IN_WRAPPED_COMPONENT_Master, "irq_out", irq_out);


            ; // fixup indentation in template file.
        }

        Component__DMA::~Component__DMA()
        {
            ; // do nothing
        }
    }
    
    // This is a list of the properties of the component of the form:
    //    { "propertyA", "valueA" }, {"propertyB", "valueB"}, ... , {nullptr, nullptr}
    static SystemGenComponent::property_value_pair_t const Component__DMA_properties_201705121426_[] = {
	{ "component_name", "DMA", 0 },
	{ "component_type", "System", 0 },
	{ "debugger_name", "", 0 },
	{ "debugger_start_command", "", 0 },
	{ "default_view", "auto", 0 },
	{ "deprecated", "0", 0 },
	{ "description", "", 0 },
	{ "documentation_file", "", 0 },
	{ "dso_safe", "0", 0 },
	{ "executes_software", "0", 0 },
	{ "expose_extern_sub_component_cadi", "1", 0 },
	{ "factory_namespace", "", 0 },
	{ "has_cadi", "1", 0 },
	{ "has_implicit_clk_in", "1", 0 },
	{ "hidden", "0", 0 },
	{ "hwversion", "", 0 },
	{ "icon_file", "", 0 },
	{ "ip_provider", "", 0 },
	{ "is_single_stepped", "0", 0 },
	{ "license_feature", "", 0 },
	{ "loadfile_extension", "", 0 },
	{ "mtdomains", "", 0 },
	{ "mtdomains_tool_config", "", 0 },
	{ "package", "", 0 },
	{ "resources_are_public", "0", 0 },
	{ "small_icon_file", "", 0 },
	{ "variant", "", 0 },
	{ "version", "1.0", 0 },

        { nullptr, nullptr, 0 }
    };

Component__DMA::Component__DMA(const char * instName, sg::SimulationContext* simulationContext, const sg::Params & params):
    SystemGenComponent(instName, simulationContext, params, Component__DMA_properties_201705121426_)



	,cadiParameterProxy_ProgMem_of_RAMDevice_to_DMA__(0)
	,cadiParameterProxy_SrcMem_of_RAMDevice_to_DMA__(0)
	,cadiParameterProxy_Clock100MHz_of_ClockDivider_to_DMA__(0)
	,cadiParameterProxy_AMBAPVBridge_of_AMBAPV2PVBus_to_DMA__(0)

{
    // initialize parameter info
    {
        sg::ComponentFactory *factory = DMA_GetFactory();

        sg::TargetInfo *targetInfo = factory->getTargetInfo(""); // empty string means 'this' component

        if(targetInfo) // if we have no target info we also have no parameters towards CADI interfaces
        {
            // get parameter infos
            for(unsigned int i = 0; i < targetInfo->parameter_count; i++)
            {
                parameterId2parameterName__[targetInfo->parameter_info[i].id] = targetInfo->parameter_info[i].name;
                parameterInfos__.push_back((targetInfo->parameter_info)[i]);
            }
        }

        factory->dereference();
    }

    // bad_params is used by any components for which it needs to do:
    //           params.interpolate("$mtdomain_name", bad_params)
    // for the mtdomain parameter passed to the proxying component.
    //
    // However, we don't actually ever do anything with the result as
    // fillOutMTWrapperConfig__() will report any interpolation errors.
    std::vector< std::pair<std::string, std::string::size_type> > bad_params;
    sg::MTWrapperConfig mtwrapper_config__;
    fillOutMTWrapperConfig__(mtwrapper_config__);
    
    // create subcomponents
    
	{
		sg::ComponentFactory *ClockDivider_factory = ClockDivider_GetFactory();
		sg::ComponentFactory *MasterClock_factory = MasterClock_GetFactory();
		sg::ComponentFactory *ARMCortexM55CT_factory = ARMCortexM55CT_GetFactory();
		sg::ComponentFactory *RAMDevice_factory = RAMDevice_GetFactory();
		sg::ComponentFactory *PVBusDecoder_factory = PVBusDecoder_GetFactory();
		sg::ComponentFactory *AMBAPVSignal2SGSignal_factory = AMBAPVSignal2SGSignal_GetFactory();
		sg::ComponentFactory *SGSignal2AMBAPVSignal_factory = SGSignal2AMBAPVSignal_GetFactory();
		sg::ComponentFactory *PVBus2AMBAPV_factory = PVBus2AMBAPV_GetFactory();
		sg::ComponentFactory *AMBAPV2PVBus_factory = AMBAPV2PVBus_GetFactory();
		{
			sg::Params params_Core__ = params.getParamsFor("Core");
			Core = ARMCortexM55CT_factory->instantiate(subcompHierName("Core"), simulationContext, params_Core__);
			Core->setParent(this);
			assert(Core);
			add(Core);
		}
		{
			sg::Params params_ProgMem__ = params.getParamsFor("ProgMem");
			params_ProgMem__["size"] = UINT64_C(0x0000000034000000);
			ProgMem = dynamic_cast<Component__RAMDevice*>(RAMDevice_factory->instantiate(subcompHierName("ProgMem"), simulationContext, params_ProgMem__));
			assert(ProgMem);
			add(ProgMem);
		}
		{
			sg::Params params_SrcMem__ = params.getParamsFor("SrcMem");
			params_SrcMem__["size"] = UINT64_C(0x0000000000002000);
			SrcMem = dynamic_cast<Component__RAMDevice*>(RAMDevice_factory->instantiate(subcompHierName("SrcMem"), simulationContext, params_SrcMem__));
			assert(SrcMem);
			add(SrcMem);
		}
		{
			sg::Params params_PVBus__ = params.getParamsFor("PVBus");
			PVBus = PVBusDecoder_factory->instantiate(subcompHierName("PVBus"), simulationContext, params_PVBus__);
			PVBus->setParent(this);
			assert(PVBus);
			add(PVBus);
		}
		{
			sg::Params params_Clock100MHz__ = params.getParamsFor("Clock100MHz");
			params_Clock100MHz__["mul"] = UINT64_C(0x0000000005F5E100);
			Clock100MHz = ClockDivider_factory->instantiate(subcompHierName("Clock100MHz"), simulationContext, params_Clock100MHz__);
			Clock100MHz->setParent(this);
			assert(Clock100MHz);
			add(Clock100MHz);
		}
		{
			sg::Params params_AMBAPVBus__ = params.getParamsFor("AMBAPVBus");
			AMBAPVBus = dynamic_cast<Component__PVBus2AMBAPV*>(PVBus2AMBAPV_factory->instantiate(subcompHierName("AMBAPVBus"), simulationContext, params_AMBAPVBus__));
			assert(AMBAPVBus);
			add(AMBAPVBus);
		}
		{
			sg::Params params_AMBAPVBridge__ = params.getParamsFor("AMBAPVBridge");
			params_AMBAPVBridge__["base_addr"] = UINT64_C(0x0000000035000000);
			AMBAPVBridge = dynamic_cast<Component__AMBAPV2PVBus*>(AMBAPV2PVBus_factory->instantiate(subcompHierName("AMBAPVBridge"), simulationContext, params_AMBAPVBridge__));
			assert(AMBAPVBridge);
			add(AMBAPVBridge);
		}
		{
			sg::Params params_SignalBridge__ = params.getParamsFor("SignalBridge");
			SignalBridge = dynamic_cast<Component__AMBAPVSignal2SGSignal*>(AMBAPVSignal2SGSignal_factory->instantiate(subcompHierName("SignalBridge"), simulationContext, params_SignalBridge__));
			assert(SignalBridge);
			add(SignalBridge);
		}
		{
			sg::Params params_ReverseBridge__ = params.getParamsFor("ReverseBridge");
			ReverseBridge = dynamic_cast<Component__SGSignal2AMBAPVSignal*>(SGSignal2AMBAPVSignal_factory->instantiate(subcompHierName("ReverseBridge"), simulationContext, params_ReverseBridge__));
			assert(ReverseBridge);
			add(ReverseBridge);
		}
		{
			sg::Params params_Clock1Hz__ = params.getParamsFor("Clock1Hz");
			Clock1Hz = MasterClock_factory->instantiate(subcompHierName("Clock1Hz"), simulationContext, params_Clock1Hz__);
			Clock1Hz->setParent(this);
			assert(Clock1Hz);
			add(Clock1Hz);
		}
		ClockDivider_factory->dereference();
		MasterClock_factory->dereference();
		ARMCortexM55CT_factory->dereference();
		RAMDevice_factory->dereference();
		PVBusDecoder_factory->dereference();
		AMBAPVSignal2SGSignal_factory->dereference();
		SGSignal2AMBAPVSignal_factory->dereference();
		PVBus2AMBAPV_factory->dereference();
		AMBAPV2PVBus_factory->dereference();
	}


    // bind local behaviors to this->control_port
    bind_method(control_port, configure, &Component__DMA::control_port__configure, this);
    bind_method(control_port, init, &Component__DMA::control_port__init, this);
    bind_method(control_port, interconnect, &Component__DMA::interconnect, this);
    bind_method(control_port, reset, &Component__DMA::control_port__reset, this);
    bind_method(control_port, loadApplicationFile, &Component__DMA::loadApplicationFile, this);
    bind_method(control_port, serializeState, &Component__DMA::control_port__serializeState, this);
    bind_method(control_port, disconnect, &Component__DMA::disconnect, this);
    bind_method(control_port, terminate, &Component__DMA::control_port__terminate, this);
    bind_method(control_port, populateCADIMap, &Component__DMA::control_port__populateCADIMap, this);
    bind_method(control_port, step, &Component__DMA::step, this);
    bind_method(control_port, getProperty, &Component__DMA::control_port__getProperty, this);
    bind_method(control_port, bypass, &Component__DMA::control_port__bypass, this);
    bind_method(control_port, run, &Component__DMA::control_port__run, this);
    bind_method(control_port, stop, &Component__DMA::control_port__stop, this);
    bind_method(control_port, idle, &Component__DMA::control_port__idle, this);
    bind_method(control_port, quit, &Component__DMA::control_port__quit, this);
    bind_method(control_port, setSimulationEngine, &Component__DMA::control_port__setSimulationEngine, this);
    bind_method(control_port, message, &Component__DMA::control_port__message, this);
    bind_method(control_port, callSimEngine, &Component__DMA::control_port__callSimEngine, this);

    // Avoid the propagation of calls to subcomponents through the framework:
    // if setLocalOnly(true) is not called, any call to an element (connector)
    // of the control port, causes the corresponding behaviours of all
    // subcomponents to be automatically called, too. Whenever we want the
    // LISA programmer to control the propagation of special-purpose behaviours,
    // we need to prevent this to happen.
    control_port.configure.setLocalOnly(true);
    control_port.init.setLocalOnly(true);
    control_port.interconnect.setLocalOnly(true);
    control_port.reset.setLocalOnly(true);
    control_port.loadApplicationFile.setLocalOnly(true);
    control_port.serializeState.setLocalOnly(true);
    control_port.disconnect.setLocalOnly(true);
    control_port.terminate.setLocalOnly(true);
    control_port.populateCADIMap.setLocalOnly(true);
    control_port.step.setLocalOnly(true);
    control_port.getProperty.setLocalOnly(true);
//  control_port.bypass.setLocalOnly(true);
//  control_port.run.setLocalOnly(true);
//  control_port.stop.setLocalOnly(true);
//  control_port.idle.setLocalOnly(true); // broadcast ports don't have setLocalOnly
//  control_port.quit.setLocalOnly(true);
//  control_port.setSimulationEngine.setLocalOnly(true);

    // bind cadiPort behaviors
    bind_method(cadiPort__, GetProperty, &Component__DMA::cadiPort__GetProperty, this);
    bind_method(cadiPort__, LoadApplicationFile, &Component__DMA::cadiPort__LoadApplicationFile, this);
    bind_method(cadiPort__, GetApplicationsAndCommandLineParams, &Component__DMA::cadiPort__GetApplicationsAndCommandLineParams, this);

    // connect control ports for subcomponents to subcomponents
    connect_controlports__();

    // resource initialization code
    reset_resources__();

    // bind behaviors to abstract ports


    // add abstract ports
    add_abstractports__();

    // wire up static connection map
    wire_connectionmap__();

    // init profiling

    // init resources


    // run the parameter write access functions for all of the component's parameters
    for (size_t i = 0; i < parameterInfos__.size(); ++i)
    {
        std::string paramName = parameterInfos__[i].name;

        switch (parameterInfos__[i].dataType)
        {
        case eslapi::CADI_PARAM_STRING:
            {
                std::string data = GetParameterValue(params, paramName, parameterInfos__[i].defaultString);
                parameter_write_string_func(paramNameToParamAccessFuncID(paramName), data);
            }
            break;
        case eslapi::CADI_PARAM_BOOL:
            {
                bool default_val = string2bool(parameterInfos__[i].defaultString);
                int64_t data = static_cast<int64_t>(GetParameterValue(params, paramName, default_val));
                parameter_write_func(paramNameToParamAccessFuncID(paramName), &data);
            }
            break;
        case eslapi::CADI_PARAM_INT:
            {
                int64_t data = GetParameterValue(params, paramName, parameterInfos__[i].defaultValue, parameterInfos__[i].minValue, parameterInfos__[i].maxValue);
                parameter_write_func(paramNameToParamAccessFuncID(paramName), &data);
            }
            break;
        default:
            break;
        }
    }
}


Component__DMA::~Component__DMA()
{
}

void Component__DMA::control_port__serializeState(const char *name, cp::SerializationInterface* stream)
{
    serializeState(name, stream);
}

void Component__DMA::control_port__configure(const sg::Params& params)
{
    (void)params;

	if(controlPort_Core__.configure.implemented()) controlPort_Core__.configure(params.getParamsFor("Core"));
	if(controlPort_ProgMem__.configure.implemented()) controlPort_ProgMem__.configure(params.getParamsFor("ProgMem"));
	if(controlPort_SrcMem__.configure.implemented()) controlPort_SrcMem__.configure(params.getParamsFor("SrcMem"));
	if(controlPort_PVBus__.configure.implemented()) controlPort_PVBus__.configure(params.getParamsFor("PVBus"));
	if(controlPort_Clock100MHz__.configure.implemented()) controlPort_Clock100MHz__.configure(params.getParamsFor("Clock100MHz"));
	if(controlPort_AMBAPVBus__.configure.implemented()) controlPort_AMBAPVBus__.configure(params.getParamsFor("AMBAPVBus"));
	if(controlPort_AMBAPVBridge__.configure.implemented()) controlPort_AMBAPVBridge__.configure(params.getParamsFor("AMBAPVBridge"));
	if(controlPort_SignalBridge__.configure.implemented()) controlPort_SignalBridge__.configure(params.getParamsFor("SignalBridge"));
	if(controlPort_ReverseBridge__.configure.implemented()) controlPort_ReverseBridge__.configure(params.getParamsFor("ReverseBridge"));
	if(controlPort_Clock1Hz__.configure.implemented()) controlPort_Clock1Hz__.configure(params.getParamsFor("Clock1Hz"));


    assert(simulationContext__->getSimulationEngine());
    cadi__ = new Component__DMA_CADI(this, simulationContext__->getSimulationEngine());
    buildDebugInfoWithMetaData__();

    // forward certain calls from CADI interface to this component
    cadi__->GetCADIPort().connectTo(cadiPort__);

    

    std::map< std::string, eslapi::CAInterface* > tempMap;
    control_port__populateCADIMap(tempMap, ""); // precompute mxdi map

	cadi__->EnableSubComponentCADIImport();


}

void Component__DMA::control_port__init()
{
    // We assume that the message() part of the control port is now bound
    // correctly.  Thus anything that we have buffered from prior to now can be
    // dumped.
    dontBufferMessages__();
    
    // Call the behavior init()
    init();
}

void Component__DMA::control_port__populateCADIMap(std::map< std::string, eslapi::CAInterface* >&output_map, std::string const & base_prefix)
{
    if (componentName2CADI__.empty())
    {
        componentName2CADI__[getName()] = static_cast<eslapi::CADI*>(cadi__);
        std::string prefix = cadiNamePrefix;

		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_Core__.populateCADIMap.implemented())
			{
				controlPort_Core__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
		}
		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_ProgMem__.populateCADIMap.implemented())
			{
				controlPort_ProgMem__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
			eslapi::CADI *cadi = obtainCADI__("ProgMem", compMap);
			if (cadi != NULL)
			{
				cadiParameterProxy_ProgMem_of_RAMDevice_to_DMA__ = new CADIParameterProxy(cadi, &parameterFilter_ProgMem_of_RAMDevice_to_DMA__);
			}
		}
		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_SrcMem__.populateCADIMap.implemented())
			{
				controlPort_SrcMem__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
			eslapi::CADI *cadi = obtainCADI__("SrcMem", compMap);
			if (cadi != NULL)
			{
				cadiParameterProxy_SrcMem_of_RAMDevice_to_DMA__ = new CADIParameterProxy(cadi, &parameterFilter_SrcMem_of_RAMDevice_to_DMA__);
			}
		}
		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_PVBus__.populateCADIMap.implemented())
			{
				controlPort_PVBus__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
		}
		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_Clock100MHz__.populateCADIMap.implemented())
			{
				controlPort_Clock100MHz__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
			eslapi::CADI *cadi = obtainCADI__("Clock100MHz", compMap);
			if (cadi != NULL)
			{
				cadiParameterProxy_Clock100MHz_of_ClockDivider_to_DMA__ = new CADIParameterProxy(cadi, &parameterFilter_Clock100MHz_of_ClockDivider_to_DMA__);
			}
		}
		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_AMBAPVBus__.populateCADIMap.implemented())
			{
				controlPort_AMBAPVBus__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
		}
		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_AMBAPVBridge__.populateCADIMap.implemented())
			{
				controlPort_AMBAPVBridge__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
			eslapi::CADI *cadi = obtainCADI__("AMBAPVBridge", compMap);
			if (cadi != NULL)
			{
				cadiParameterProxy_AMBAPVBridge_of_AMBAPV2PVBus_to_DMA__ = new CADIParameterProxy(cadi, &parameterFilter_AMBAPVBridge_of_AMBAPV2PVBus_to_DMA__);
			}
		}
		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_SignalBridge__.populateCADIMap.implemented())
			{
				controlPort_SignalBridge__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
		}
		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_ReverseBridge__.populateCADIMap.implemented())
			{
				controlPort_ReverseBridge__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
		}
		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_Clock1Hz__.populateCADIMap.implemented())
			{
				controlPort_Clock1Hz__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
		}

    }
    // Copy the local map into the given map with the requested prefix.
    for (std::map<std::string,eslapi::CAInterface*>::iterator it = componentName2CADI__.begin(); it != componentName2CADI__.end(); ++it)
    {
        output_map.insert(std::make_pair(base_prefix + it->first, it->second));
    }
}

// Turn off optimizations for this function; it is not performance critical as it is only
// generally run once per simulation on startup. Keeping track of the large number of
// variables in some cases causes the comiler to take a lot of time and memory attempting
// to optimize, so we explicitly turn this off.
#ifdef WIN32
# pragma optimize("", off)
#else
# pragma GCC push_options
# pragma GCC optimize ("O0")
#endif
void Component__DMA::buildDebugInfoWithMetaData__()
{


    sg::CADIBase::RegInfo regData[] =
    {

        {"ETFR", "ExtendedTargetFeatureRegisterGroup", 0, 0, eslapi::CADI_REGTYPE_STRING, "Extended Target Features", eslapi::CADI_REG_READ_ONLY, 0, 0, 0, true, 0, false, 0, 0, 0, true/*pseudo*/, true, 0xFFFFFFFF, 0, 0, 0, 0, 0xffffffff, 0, 0, false, false, false},
        {0, "", 0, 0, eslapi::CADI_REGTYPE_HEX, 0, eslapi::CADI_REG_READ_WRITE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    // the instance specific data has to be non-static, this is currently only access_data
    // this array is compressed: only registers which have hasInstanceSpecificPointers=true in regData are present here
    sg::CADIBase::RegInfoInstanceSpecific regDataInstanceSpecific[] = {

        {0, 0, 0, 0, MakeDelegate(this, &Component__DMA::GetExtendedTargetFeatures__), 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    sg::CADIBase::ParamInfo paramData[] =
    {

        { 0, 0, 0, 0, 0 }
    };

    buildDebugInfo__(regData, (sizeof(regData) / sizeof( regData[0])) - 1,
                     regDataInstanceSpecific, sizeof(regDataInstanceSpecific) / sizeof( regDataInstanceSpecific[0]),
                     paramData, sizeof(paramData) / sizeof(paramData[0]));
}
// Restore optimization.
#ifdef WIN32
# pragma optimize("", on)
#else
# pragma GCC pop_options
#endif

sg::accessfunc::AccessFuncResult
Component__DMA::GetExtendedTargetFeatures__(uint32_t /*id*/, std::string &data, bool /*se*/)
{
    data = getExtendedTargetFeatures();
    return sg::accessfunc::ACCESS_FUNC_OK;
}

eslapi::CADI* Component__DMA::obtainCADI__(const std::string &subcomp, const std::map< std::string, eslapi::CAInterface* > &componentName2CADI) const
{
    std::map< std::string, eslapi::CAInterface* >::const_iterator it = componentName2CADI.find(subcomp);
    if (it != componentName2CADI.end())
    {
        eslapi::CAInterface *cai = it->second;
        if (cai != NULL)
        {
            cai = cai->ObtainInterface(eslapi::CADI::IFNAME(), 0, 0);
            if (cai != NULL)
            {
                return static_cast<eslapi::CADI*>(cai);
            }
        }
    }
    return NULL;
}

void Component__DMA::insertCADIMap__(std::string prefix, std::map< std::string, eslapi::CAInterface* > &componentName2CADI)
{
    for (std::map<std::string, eslapi::CAInterface*>::iterator it = componentName2CADI.begin(); it != componentName2CADI.end(); it++)
    {
        // put prefix in front of all entries
        componentName2CADI__[prefix + it->first] = it->second;
    }
}


std::string Component__DMA::control_port__getProperty(const std::string& propname)
{
    if(properties__.find(propname) != properties__.end())
    {
        return properties__[propname];
    }
    else
        return ""; // unknown property
}

std::string Component__DMA::control_port__bypass(const std::string&)
{
    return "";
}

void Component__DMA::control_port__run()
{
}


void Component__DMA::control_port__stop()
{
}


void Component__DMA::control_port__idle()
{
}


void Component__DMA::control_port__quit()
{
}


void Component__DMA::control_port__setSimulationEngine(sg::SimulationEngine*)
{
}


void Component__DMA::control_port__message(const std::string &/*msg*/, sg::message::MessageType /*msgType*/)
{
}


std::string Component__DMA::control_port__callSimEngine(const std::string &)
{
    return "";
}


void Component__DMA::control_port__reset(int level)
{
    drainBufferedMessages__();
    if (isShutdownAtReset__())
        message("Shutting down due to prior errors.", MSG_FATAL_ERROR);
    
    (void)level;
    // restore the resources' reset values before executing 'reset'
    reset_resources__();
    reset(level);
}


void Component__DMA::control_port__terminate()
{
    // the CADI was created before 'init', therefore we free it after 'terminate'
    terminate();
    freeCADIResources__();
}


void Component__DMA::freeCADIResources__()
{
    // free CADI parameter proxies
	delete cadiParameterProxy_ProgMem_of_RAMDevice_to_DMA__;
	cadiParameterProxy_ProgMem_of_RAMDevice_to_DMA__ = 0;
	delete cadiParameterProxy_SrcMem_of_RAMDevice_to_DMA__;
	cadiParameterProxy_SrcMem_of_RAMDevice_to_DMA__ = 0;
	delete cadiParameterProxy_Clock100MHz_of_ClockDivider_to_DMA__;
	cadiParameterProxy_Clock100MHz_of_ClockDivider_to_DMA__ = 0;
	delete cadiParameterProxy_AMBAPVBridge_of_AMBAPV2PVBus_to_DMA__;
	cadiParameterProxy_AMBAPVBridge_of_AMBAPV2PVBus_to_DMA__ = 0;


    // free CADI interface
    delete cadi__;
    cadi__ = 0;
}

bool Component__DMA::ForwardParameterValueToSubcomponent(CADIParameterProxy *proxy, const char *param_name, int64_t intVal, const char *strVal)
{
    if (!proxy)
        return false;

    // we need the parameter's CADI id in order to create an eslapi::CADIParameterValue_t structure
    // therefore, we first retrieve its eslapi::CADIParameterInfo_t meta-data
    eslapi::CADIParameterInfo_t paramInfo;
    if (proxy->CADIGetParameterInfo(param_name, &paramInfo) != eslapi::CADI_STATUS_OK)
        return false;

    eslapi::CADIParameterValue_t paramVal(paramInfo.id, paramInfo.dataType, intVal, strVal);
    eslapi::CADIFactoryErrorMessage_t error;
    if (proxy->CADISetParameters(1, &paramVal, &error) != eslapi::CADI_STATUS_OK)
        return false;

    return true;
}


sg::accessfunc::AccessFuncResult Component__DMA::parameter_read_func(uint32_t id, int64_t *data)
{
    if (data == 0)
        return eslapi::CADI_STATUS_IllegalArgument;

    switch (id)
    {

        default:
            printf("error: Component__DMA::parameter_read_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__DMA::parameter_read_string_func(uint32_t id, std::string &data)
{
    (void)data;
    switch (id)
    {

        default:
            printf("error: Component__DMA::parameter_read_string_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__DMA::parameter_write_func(uint32_t id, const int64_t *data)
{
    if (data == 0)
        return eslapi::CADI_STATUS_IllegalArgument;

    switch (id)
    {

        default:
            printf("error: Component__DMA::parameter_write_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__DMA::parameter_write_string_func(uint32_t id, const std::string &data)
{
    (void)data;
    switch (id)
    {

        default:
            printf("error: Component__DMA::parameter_write_string_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

void Component__DMA::cadiPort__LoadApplicationFile(const std::string& filename)
{
    loadApplicationFile(filename);
    applications2params[filename] = "";
}

void Component__DMA::cadiPort__GetApplicationsAndCommandLineParams(std::map<std::string, std::string>&applications2params_)
{
    applications2params_ = applications2params;
}

eslapi::CADIReturn_t Component__DMA::cadiPort__GetProperty(const std::string& propertyName, std::string &value)
{
    if(properties__.find(propertyName) != properties__.end())
    {
        value = properties__[propertyName];
        return eslapi::CADI_STATUS_OK;
    }
    else
    {
        value = "";
        return eslapi::CADI_STATUS_GeneralError;
    }
}

// functions to stop and lock the simulator
// we only expose the simHalt() function in the documentation for the moment

void Component__DMA::simHalt()
{
    cadi__->StopSimulation();
}


// start simulation from the inside
// (useful from visualisation components which can execute code while the
// simulation is stopped, like key events)
void Component__DMA::simRun()
{
    cadi__->CADIExecContinue();
}


// return true if simulation is running
// (useful from visualisation components which can execute code while the
// simulation is stopped, like key events)
bool Component__DMA::simIsRunning()
{
    uint32_t mode = eslapi::CADI_EXECMODE_Stop;
    cadi__->CADIExecGetMode(&mode);
    return mode != eslapi::CADI_EXECMODE_Stop;
}


void Component__DMA::simShutdown()
{
    cadiPort__.simShutdown();
}

void Component__DMA::simReset(uint32_t level)
{
    cadi__->CADIExecReset(level);
}

uint32_t Component__DMA::paramNameToParamAccessFuncID(const std::string &name)
{
    uint32_t id = 0;
    if (name == "") id = 0xffffffff;

    return id;
}

void Component__DMA::reset_resources__()
{
    // resource initialization code

}

void Component__DMA::connect_controlports__()
{
    typedef struct {
        sg::Port * local_cport_name;
        sg::ComponentBase * local_instance_name;
        const char * cport_name;
    } connection_map_t;


    connection_map_t cmap[] = {
    {&controlPort_Core__,Core,"$control"},
    {&controlPort_ProgMem__,ProgMem,"$control"},
    {&controlPort_SrcMem__,SrcMem,"$control"},
    {&controlPort_PVBus__,PVBus,"$control"},
    {&controlPort_Clock100MHz__,Clock100MHz,"$control"},
    {&controlPort_AMBAPVBus__,AMBAPVBus,"$control"},
    {&controlPort_AMBAPVBridge__,AMBAPVBridge,"$control"},
    {&controlPort_SignalBridge__,SignalBridge,"$control"},
    {&controlPort_ReverseBridge__,ReverseBridge,"$control"},
    {&controlPort_Clock1Hz__,Clock1Hz,"$control"},
    { 0, 0, 0 },
    };


    for(unsigned int i=0; cmap[i].local_cport_name != 0; i++) {
        connection_map_t c = cmap[i];
        c.local_cport_name->connectTo(c.local_instance_name->findPort(c.cport_name));
    }


    // #CONNECT_CONTROLPORTS_TO_SUBCOMPONENTS#
}

void Component__DMA::add_abstractports__0__()
{
	publishMasterPort("amba_pv_m", amba_pv_m);
	amba_pv_m.SetName__("amba_pv_m");
	publishSlavePort("amba_pv_s", amba_pv_s);
	amba_pv_s.SetName__("amba_pv_s");
	publishSlavePort("irq_in", irq_in);
	irq_in.SetName__("irq_in");
	publishMasterPort("irq_out", irq_out);
	irq_out.SetName__("irq_out");
}



void Component__DMA::add_abstractports__()
{
	add_abstractports__0__();

}

void Component__DMA::wire_connectionmap__0__()
{
	AMBAPVBus->findPort("amba_pv_m").connectTo(amba_pv_m);
	irq_in.connectTo(SignalBridge->findPort("amba_pv_signal_s"));
	amba_pv_s.connectTo(AMBAPVBridge->findPort("amba_pv_s"));
	Clock1Hz->findPort("clk_out").connectTo(Clock100MHz->findPort("clk_in"));
	AMBAPVBridge->findPort("pvbus_m").connectTo(PVBus->findPort("pvbus_s"));
	tmp__.setName("tmp_addressmap_control");
	tmp__.setParent(this);	tmp__.connectTo(PVBus->findPort("pvbus_m_range"));
#line 30 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/EVS_Platforms/EVS_DMA/LISA/DMA_Cortex-M55.lisa"
	tmp__.mapRange(UINT64_C(0x00000000), UINT64_C(0x33FFFFFF), UINT64_C(0x00000000), UINT64_C(0x33FFFFFF))->connectTo(ProgMem->findPort("pvbus"));
#line 1078 "./Linux64-Release-GCC-7.3/gen/Comp_NonDSO_1.cpp"
	tmp__.disconnectFrom(PVBus->findPort("pvbus_m_range"));
	tmp__.connectTo(PVBus->findPort("pvbus_m_range"));
#line 31 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/EVS_Platforms/EVS_DMA/LISA/DMA_Cortex-M55.lisa"
	tmp__.mapRange(UINT64_C(0x34000000), UINT64_C(0x34004FFF), UINT64_C(0x34000000), UINT64_C(0x34004FFF))->connectTo(AMBAPVBus->findPort("pvbus_s"));
#line 1083 "./Linux64-Release-GCC-7.3/gen/Comp_NonDSO_1.cpp"
	tmp__.disconnectFrom(PVBus->findPort("pvbus_m_range"));
	tmp__.connectTo(PVBus->findPort("pvbus_m_range"));
#line 32 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/EVS_Platforms/EVS_DMA/LISA/DMA_Cortex-M55.lisa"
	tmp__.mapRange(UINT64_C(0x35000000), UINT64_C(0x35001FFF), UINT64_C(0x00000000), UINT64_C(0x00001FFF))->connectTo(SrcMem->findPort("pvbus"));
#line 1088 "./Linux64-Release-GCC-7.3/gen/Comp_NonDSO_1.cpp"
	tmp__.disconnectFrom(PVBus->findPort("pvbus_m_range"));
	SignalBridge->findPort("sg_signal_m").connectTo(ReverseBridge->findPort("sg_signal_s"));
	ReverseBridge->findPort("amba_pv_signal_m").connectTo(irq_out);
	Core->findPort("pvbus_m").connectTo(PVBus->findPort("pvbus_s"));
}

void Component__DMA::wire_connectionmap__1__()
{
	Clock100MHz->findPort("clk_out").connectTo(Core->findPort("clk_in"));
	SignalBridge->findPort("sg_signal_m").connectTo(Core->findPort("nmi"));
}



void Component__DMA::wire_connectionmap__()
{
	wire_connectionmap__0__();
	wire_connectionmap__1__();

}


} // DMA_NMS
#line 134 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { void 
Component__AMBAPV2PVBus::init()
{
 {if(!controlPort_bus_master__.init.empty()) controlPort_bus_master__.init();};

 ambapv2pvbus = new AMBAPV2PVBus(this, __AMBAPV2PVBus_internal_1.createRandomContextTransactionGenerator());
 
}
}

#line 142 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { void 
Component__AMBAPV2PVBus::terminate()
{
 {if(!controlPort_bus_master__.terminate.empty()) controlPort_bus_master__.terminate();};

 delete ambapv2pvbus;
 
}
}

#line 246 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { void 
Component__AMBAPV2PVBus::invalidateDirectMemPtr(pv::bus_addr_range_t range)
{
 amba_pv_s.invalidate_direct_mem_ptr(0, (sc_dt::uint64)range.begin, (sc_dt::uint64)range.end_incl);
 
}
}

#line 251 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { void 
Component__AMBAPV2PVBus::reset(int level_)
{
 {if(!controlPort_bus_master__.reset.empty()) controlPort_bus_master__.reset(level_);};

 busDiscovery();
 
}
}

#line 259 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { void 
Component__AMBAPV2PVBus::busDiscovery()
{
 bus_node.discoverDownstream((pv::Bus&)pvbus_m);
 bus_node.declareBridge(getHierarchicalName().c_str(), "AMBAPV", "PVBus");
 
}
}

#line 19 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { void 
Component__AMBAPV2PVBus::interconnect()
{{if(!controlPort_bus_master__.interconnect.empty()) controlPort_bus_master__.interconnect();};
}
}

#line 19 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { void 
Component__AMBAPV2PVBus::disconnect()
{{if(!controlPort_bus_master__.disconnect.empty()) controlPort_bus_master__.disconnect();};
}
}

#line 19 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { void 
Component__AMBAPV2PVBus::loadApplicationFile(const std::string& filename)
{{if(!controlPort_bus_master__.loadApplicationFile.empty()) controlPort_bus_master__.loadApplicationFile(filename);};(void)filename;
}
}

#line 19 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { void 
Component__AMBAPV2PVBus::step()
{{if(!controlPort_bus_master__.step.empty()) controlPort_bus_master__.step();};
}
}

#line 157 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { unsigned int 
Component__AMBAPV2PVBus::abstract_port__amba_pv_s__transport_dbg(int socket_id, amba_pv::amba_pv_transaction& trans)
{
 if (bus_node.discoveryFilter())
 {
 busDiscovery();
 return 0;
 }

 
 amba_pv::amba_pv_extension * ex = 0;

 trans.get_extension(ex);
 if (ex == 0)
 return 0;

 unsigned num_bytes = 0;

 if (trans.is_read() || trans.is_write())
 {
 
 if (trans.get_byte_enable_ptr() != 0)
 return 0;

 num_bytes = ambapv2pvbus->translateDebugTransaction(trans, ex);
 }

 return num_bytes;
 
}
}

#line 189 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { void 
Component__AMBAPV2PVBus::abstract_port__amba_pv_s__b_transport(int socket_id, amba_pv::amba_pv_transaction& trans, sc_core::sc_time& t)
{
 
 trans.set_dmi_allowed(false);

 
 amba_pv::amba_pv_extension* ex = 0;

 trans.get_extension(ex);
 if (ex == 0)
 {
 trans.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
 return;
 }

 if (trans.is_read() || trans.is_write())
 {
 
 if (trans.get_byte_enable_ptr() != 0)
 {
 ex->set_slverr();
 trans.set_response_status(tlm::TLM_BYTE_ENABLE_ERROR_RESPONSE);
 return;
 }

 
 if (trans.get_data_length() < (ex->get_size() * ex->get_length()))
 {
 ex->set_slverr();
 trans.set_response_status(tlm::TLM_BURST_ERROR_RESPONSE);
 return;
 }

 ambapv2pvbus->translateTransaction(trans, ex, t);
 }
 else
 {
 
 ex->set_okay();
 }

 
 trans.set_response_status(amba_pv::amba_pv_resp_to_tlm(ex->get_resp(), ex->is_exclusive()));
 
}
}

#line 237 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPV2PVBus.lisa"
namespace DMA_NMS { bool 
Component__AMBAPV2PVBus::abstract_port__amba_pv_s__get_direct_mem_ptr(int socket_id, amba_pv::amba_pv_transaction& trans, tlm::tlm_dmi& dmi_data)
{
 return ambapv2pvbus->getDirectMemPtr(socket_id, trans, dmi_data);
 
}
}

#line 1283 "./Linux64-Release-GCC-7.3/gen/Comp_NonDSO_1.cpp"

// ------------------------------------------------------------------------------
// implementation of class Component__AMBAPV2PVBus
// ------------------------------------------------------------------------------

namespace DMA_NMS {


    namespace MT
    {
        Component__AMBAPV2PVBus::Component__AMBAPV2PVBus(
            sg::ComponentFactory*      factory,
            sg::MTWrapperConfig const& wrapper_config,
            std::string const&         mtdomain_name,
            std::string const&         instName,
            sg::SimulationContext*     simulationContext,
            sg::Params const&          params
            )
        {
        
            // what this creates is a component where 
            auto result = MTComponentWrapper(
                factory, wrapper_config, mtdomain_name, instName, simulationContext, params
                );
            mtdomain_id   = result.mtdomain_id;
            raw_component = dynamic_cast<wrapped_type*>(result.raw_component);
            setComponentBase(result.wrapper_component);

            // Forward the ports in the publicly visible part of the class to the
            // versions that have been created by the wrapper.
            connectPort(KIND_IN_WRAPPED_COMPONENT_Master, "pvbus_m", pvbus_m);
            connectPort(KIND_IN_WRAPPED_COMPONENT_Slave, "amba_pv_s", amba_pv_s);


            ; // fixup indentation in template file.
        }

        Component__AMBAPV2PVBus::~Component__AMBAPV2PVBus()
        {
            ; // do nothing
        }
    }
    
    // This is a list of the properties of the component of the form:
    //    { "propertyA", "valueA" }, {"propertyB", "valueB"}, ... , {nullptr, nullptr}
    static SystemGenComponent::property_value_pair_t const Component__AMBAPV2PVBus_properties_201705121426_[] = {
	{ "component_name", "AMBAPV2PVBus", 0 },
	{ "component_type", "Bridge", 0 },
	{ "debugger_name", "", 0 },
	{ "debugger_start_command", "", 0 },
	{ "default_view", "auto", 0 },
	{ "deprecated", "0", 0 },
	{ "description", "AMBA-PV to PVBus protocol converter.", 0 },
	{ "documentation_file", "../#100964#", 0 },
	{ "dso_safe", "0", 0 },
	{ "executes_software", "0", 0 },
	{ "expose_extern_sub_component_cadi", "1", 0 },
	{ "factory_namespace", "", 0 },
	{ "has_cadi", "1", 0 },
	{ "has_implicit_clk_in", "1", 0 },
	{ "hidden", "0", 0 },
	{ "hwversion", "", 0 },
	{ "icon_file", "", 0 },
	{ "ip_provider", "", 0 },
	{ "is_single_stepped", "0", 0 },
	{ "license_feature", "", 0 },
	{ "loadfile_extension", "", 0 },
	{ "mtdomains", "", 0 },
	{ "mtdomains_tool_config", "", 0 },
	{ "package", "", 0 },
	{ "resources_are_public", "0", 0 },
	{ "small_icon_file", "", 0 },
	{ "variant", "", 0 },
	{ "version", "11.10.22", 0 },

        { nullptr, nullptr, 0 }
    };

Component__AMBAPV2PVBus::Component__AMBAPV2PVBus(const char * instName, sg::SimulationContext* simulationContext, const sg::Params & params):
    SystemGenComponent(instName, simulationContext, params, Component__AMBAPV2PVBus_properties_201705121426_)

	,base_addr(GetParameterValue(params, "base_addr", INT64_C(0x0), INT64_C(0x8000000000000000), INT64_C(0x7fffffffffffffff)))
	,shareable(GetParameterValue(params, "shareable", static_cast<bool>(0x1) ))



{
    // initialize parameter info
    {
        sg::ComponentFactory *factory = AMBAPV2PVBus_GetFactory();

        sg::TargetInfo *targetInfo = factory->getTargetInfo(""); // empty string means 'this' component

        if(targetInfo) // if we have no target info we also have no parameters towards CADI interfaces
        {
            // get parameter infos
            for(unsigned int i = 0; i < targetInfo->parameter_count; i++)
            {
                parameterId2parameterName__[targetInfo->parameter_info[i].id] = targetInfo->parameter_info[i].name;
                parameterInfos__.push_back((targetInfo->parameter_info)[i]);
            }
        }

        factory->dereference();
    }

    // bad_params is used by any components for which it needs to do:
    //           params.interpolate("$mtdomain_name", bad_params)
    // for the mtdomain parameter passed to the proxying component.
    //
    // However, we don't actually ever do anything with the result as
    // fillOutMTWrapperConfig__() will report any interpolation errors.
    std::vector< std::pair<std::string, std::string::size_type> > bad_params;
    sg::MTWrapperConfig mtwrapper_config__;
    fillOutMTWrapperConfig__(mtwrapper_config__);
    
    // create subcomponents
    
	{
		sg::ComponentFactory *PVBusMaster_factory = PVBusMaster_GetFactory();
		{
			sg::Params params_bus_master__ = params.getParamsFor("bus_master");
			bus_master = PVBusMaster_factory->instantiate(subcompHierName("bus_master"), simulationContext, params_bus_master__);
			bus_master->setParent(this);
			assert(bus_master);
			add(bus_master);
		}
		PVBusMaster_factory->dereference();
	}


    // bind local behaviors to this->control_port
    bind_method(control_port, configure, &Component__AMBAPV2PVBus::control_port__configure, this);
    bind_method(control_port, init, &Component__AMBAPV2PVBus::control_port__init, this);
    bind_method(control_port, interconnect, &Component__AMBAPV2PVBus::interconnect, this);
    bind_method(control_port, reset, &Component__AMBAPV2PVBus::control_port__reset, this);
    bind_method(control_port, loadApplicationFile, &Component__AMBAPV2PVBus::loadApplicationFile, this);
    bind_method(control_port, serializeState, &Component__AMBAPV2PVBus::control_port__serializeState, this);
    bind_method(control_port, disconnect, &Component__AMBAPV2PVBus::disconnect, this);
    bind_method(control_port, terminate, &Component__AMBAPV2PVBus::control_port__terminate, this);
    bind_method(control_port, populateCADIMap, &Component__AMBAPV2PVBus::control_port__populateCADIMap, this);
    bind_method(control_port, step, &Component__AMBAPV2PVBus::step, this);
    bind_method(control_port, getProperty, &Component__AMBAPV2PVBus::control_port__getProperty, this);
    bind_method(control_port, bypass, &Component__AMBAPV2PVBus::control_port__bypass, this);
    bind_method(control_port, run, &Component__AMBAPV2PVBus::control_port__run, this);
    bind_method(control_port, stop, &Component__AMBAPV2PVBus::control_port__stop, this);
    bind_method(control_port, idle, &Component__AMBAPV2PVBus::control_port__idle, this);
    bind_method(control_port, quit, &Component__AMBAPV2PVBus::control_port__quit, this);
    bind_method(control_port, setSimulationEngine, &Component__AMBAPV2PVBus::control_port__setSimulationEngine, this);
    bind_method(control_port, message, &Component__AMBAPV2PVBus::control_port__message, this);
    bind_method(control_port, callSimEngine, &Component__AMBAPV2PVBus::control_port__callSimEngine, this);

    // Avoid the propagation of calls to subcomponents through the framework:
    // if setLocalOnly(true) is not called, any call to an element (connector)
    // of the control port, causes the corresponding behaviours of all
    // subcomponents to be automatically called, too. Whenever we want the
    // LISA programmer to control the propagation of special-purpose behaviours,
    // we need to prevent this to happen.
    control_port.configure.setLocalOnly(true);
    control_port.init.setLocalOnly(true);
    control_port.interconnect.setLocalOnly(true);
    control_port.reset.setLocalOnly(true);
    control_port.loadApplicationFile.setLocalOnly(true);
    control_port.serializeState.setLocalOnly(true);
    control_port.disconnect.setLocalOnly(true);
    control_port.terminate.setLocalOnly(true);
    control_port.populateCADIMap.setLocalOnly(true);
    control_port.step.setLocalOnly(true);
    control_port.getProperty.setLocalOnly(true);
//  control_port.bypass.setLocalOnly(true);
//  control_port.run.setLocalOnly(true);
//  control_port.stop.setLocalOnly(true);
//  control_port.idle.setLocalOnly(true); // broadcast ports don't have setLocalOnly
//  control_port.quit.setLocalOnly(true);
//  control_port.setSimulationEngine.setLocalOnly(true);

    // bind cadiPort behaviors
    bind_method(cadiPort__, GetProperty, &Component__AMBAPV2PVBus::cadiPort__GetProperty, this);
    bind_method(cadiPort__, LoadApplicationFile, &Component__AMBAPV2PVBus::cadiPort__LoadApplicationFile, this);
    bind_method(cadiPort__, GetApplicationsAndCommandLineParams, &Component__AMBAPV2PVBus::cadiPort__GetApplicationsAndCommandLineParams, this);

    // connect control ports for subcomponents to subcomponents
    connect_controlports__();

    // resource initialization code
    reset_resources__();

    // bind behaviors to abstract ports
	bind_method(amba_pv_s, transport_dbg, &Component__AMBAPV2PVBus::abstract_port__amba_pv_s__transport_dbg, this);
	bind_method(amba_pv_s, b_transport, &Component__AMBAPV2PVBus::abstract_port__amba_pv_s__b_transport, this);
	bind_method(amba_pv_s, get_direct_mem_ptr, &Component__AMBAPV2PVBus::abstract_port__amba_pv_s__get_direct_mem_ptr, this);


    // add abstract ports
    add_abstractports__();

    // wire up static connection map
    wire_connectionmap__();

    // init profiling

    // init resources


    // run the parameter write access functions for all of the component's parameters
    for (size_t i = 0; i < parameterInfos__.size(); ++i)
    {
        std::string paramName = parameterInfos__[i].name;

        switch (parameterInfos__[i].dataType)
        {
        case eslapi::CADI_PARAM_STRING:
            {
                std::string data = GetParameterValue(params, paramName, parameterInfos__[i].defaultString);
                parameter_write_string_func(paramNameToParamAccessFuncID(paramName), data);
            }
            break;
        case eslapi::CADI_PARAM_BOOL:
            {
                bool default_val = string2bool(parameterInfos__[i].defaultString);
                int64_t data = static_cast<int64_t>(GetParameterValue(params, paramName, default_val));
                parameter_write_func(paramNameToParamAccessFuncID(paramName), &data);
            }
            break;
        case eslapi::CADI_PARAM_INT:
            {
                int64_t data = GetParameterValue(params, paramName, parameterInfos__[i].defaultValue, parameterInfos__[i].minValue, parameterInfos__[i].maxValue);
                parameter_write_func(paramNameToParamAccessFuncID(paramName), &data);
            }
            break;
        default:
            break;
        }
    }
}


Component__AMBAPV2PVBus::~Component__AMBAPV2PVBus()
{
}

void Component__AMBAPV2PVBus::control_port__serializeState(const char *name, cp::SerializationInterface* stream)
{
    serializeState(name, stream);
}

void Component__AMBAPV2PVBus::control_port__configure(const sg::Params& params)
{
    (void)params;

	if(controlPort_bus_master__.configure.implemented()) controlPort_bus_master__.configure(params.getParamsFor("bus_master"));


    assert(simulationContext__->getSimulationEngine());
    cadi__ = new Component__AMBAPV2PVBus_CADI(this, simulationContext__->getSimulationEngine());
    buildDebugInfoWithMetaData__();

    // forward certain calls from CADI interface to this component
    cadi__->GetCADIPort().connectTo(cadiPort__);

    

    std::map< std::string, eslapi::CAInterface* > tempMap;
    control_port__populateCADIMap(tempMap, ""); // precompute mxdi map

	cadi__->EnableSubComponentCADIImport();


}

void Component__AMBAPV2PVBus::control_port__init()
{
    // We assume that the message() part of the control port is now bound
    // correctly.  Thus anything that we have buffered from prior to now can be
    // dumped.
    dontBufferMessages__();
    
    // Call the behavior init()
    init();
}

void Component__AMBAPV2PVBus::control_port__populateCADIMap(std::map< std::string, eslapi::CAInterface* >&output_map, std::string const & base_prefix)
{
    if (componentName2CADI__.empty())
    {
        componentName2CADI__[getName()] = static_cast<eslapi::CADI*>(cadi__);
        std::string prefix = cadiNamePrefix;

		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_bus_master__.populateCADIMap.implemented())
			{
				controlPort_bus_master__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
		}

    }
    // Copy the local map into the given map with the requested prefix.
    for (std::map<std::string,eslapi::CAInterface*>::iterator it = componentName2CADI__.begin(); it != componentName2CADI__.end(); ++it)
    {
        output_map.insert(std::make_pair(base_prefix + it->first, it->second));
    }
}

// Turn off optimizations for this function; it is not performance critical as it is only
// generally run once per simulation on startup. Keeping track of the large number of
// variables in some cases causes the comiler to take a lot of time and memory attempting
// to optimize, so we explicitly turn this off.
#ifdef WIN32
# pragma optimize("", off)
#else
# pragma GCC push_options
# pragma GCC optimize ("O0")
#endif
void Component__AMBAPV2PVBus::buildDebugInfoWithMetaData__()
{


    sg::CADIBase::RegInfo regData[] =
    {

        {"ETFR", "ExtendedTargetFeatureRegisterGroup", 0, 0, eslapi::CADI_REGTYPE_STRING, "Extended Target Features", eslapi::CADI_REG_READ_ONLY, 0, 0, 0, true, 0, false, 0, 0, 0, true/*pseudo*/, true, 0xFFFFFFFF, 0, 0, 0, 0, 0xffffffff, 0, 0, false, false, false},
        {0, "", 0, 0, eslapi::CADI_REGTYPE_HEX, 0, eslapi::CADI_REG_READ_WRITE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    // the instance specific data has to be non-static, this is currently only access_data
    // this array is compressed: only registers which have hasInstanceSpecificPointers=true in regData are present here
    sg::CADIBase::RegInfoInstanceSpecific regDataInstanceSpecific[] = {

        {0, 0, 0, 0, MakeDelegate(this, &Component__AMBAPV2PVBus::GetExtendedTargetFeatures__), 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    sg::CADIBase::ParamInfo paramData[] =
    {
		{ 0x10000002, MakeDelegate(this, &Component__AMBAPV2PVBus::parameter_read_func), 0, MakeDelegate(this, &Component__AMBAPV2PVBus::parameter_write_func), 0 },
		{ 0x10000003, MakeDelegate(this, &Component__AMBAPV2PVBus::parameter_read_func), 0, MakeDelegate(this, &Component__AMBAPV2PVBus::parameter_write_func), 0 },

        { 0, 0, 0, 0, 0 }
    };

    buildDebugInfo__(regData, (sizeof(regData) / sizeof( regData[0])) - 1,
                     regDataInstanceSpecific, sizeof(regDataInstanceSpecific) / sizeof( regDataInstanceSpecific[0]),
                     paramData, sizeof(paramData) / sizeof(paramData[0]));
}
// Restore optimization.
#ifdef WIN32
# pragma optimize("", on)
#else
# pragma GCC pop_options
#endif

sg::accessfunc::AccessFuncResult
Component__AMBAPV2PVBus::GetExtendedTargetFeatures__(uint32_t /*id*/, std::string &data, bool /*se*/)
{
    data = getExtendedTargetFeatures();
    return sg::accessfunc::ACCESS_FUNC_OK;
}

eslapi::CADI* Component__AMBAPV2PVBus::obtainCADI__(const std::string &subcomp, const std::map< std::string, eslapi::CAInterface* > &componentName2CADI) const
{
    std::map< std::string, eslapi::CAInterface* >::const_iterator it = componentName2CADI.find(subcomp);
    if (it != componentName2CADI.end())
    {
        eslapi::CAInterface *cai = it->second;
        if (cai != NULL)
        {
            cai = cai->ObtainInterface(eslapi::CADI::IFNAME(), 0, 0);
            if (cai != NULL)
            {
                return static_cast<eslapi::CADI*>(cai);
            }
        }
    }
    return NULL;
}

void Component__AMBAPV2PVBus::insertCADIMap__(std::string prefix, std::map< std::string, eslapi::CAInterface* > &componentName2CADI)
{
    for (std::map<std::string, eslapi::CAInterface*>::iterator it = componentName2CADI.begin(); it != componentName2CADI.end(); it++)
    {
        // put prefix in front of all entries
        componentName2CADI__[prefix + it->first] = it->second;
    }
}


std::string Component__AMBAPV2PVBus::control_port__getProperty(const std::string& propname)
{
    if(properties__.find(propname) != properties__.end())
    {
        return properties__[propname];
    }
    else
        return ""; // unknown property
}

std::string Component__AMBAPV2PVBus::control_port__bypass(const std::string&)
{
    return "";
}

void Component__AMBAPV2PVBus::control_port__run()
{
}


void Component__AMBAPV2PVBus::control_port__stop()
{
}


void Component__AMBAPV2PVBus::control_port__idle()
{
}


void Component__AMBAPV2PVBus::control_port__quit()
{
}


void Component__AMBAPV2PVBus::control_port__setSimulationEngine(sg::SimulationEngine*)
{
}


void Component__AMBAPV2PVBus::control_port__message(const std::string &/*msg*/, sg::message::MessageType /*msgType*/)
{
}


std::string Component__AMBAPV2PVBus::control_port__callSimEngine(const std::string &)
{
    return "";
}


void Component__AMBAPV2PVBus::control_port__reset(int level)
{
    drainBufferedMessages__();
    if (isShutdownAtReset__())
        message("Shutting down due to prior errors.", MSG_FATAL_ERROR);
    
    (void)level;
    // restore the resources' reset values before executing 'reset'
    reset_resources__();
    reset(level);
}


void Component__AMBAPV2PVBus::control_port__terminate()
{
    // the CADI was created before 'init', therefore we free it after 'terminate'
    terminate();
    freeCADIResources__();
}


void Component__AMBAPV2PVBus::freeCADIResources__()
{
    // free CADI parameter proxies


    // free CADI interface
    delete cadi__;
    cadi__ = 0;
}

bool Component__AMBAPV2PVBus::ForwardParameterValueToSubcomponent(CADIParameterProxy *proxy, const char *param_name, int64_t intVal, const char *strVal)
{
    if (!proxy)
        return false;

    // we need the parameter's CADI id in order to create an eslapi::CADIParameterValue_t structure
    // therefore, we first retrieve its eslapi::CADIParameterInfo_t meta-data
    eslapi::CADIParameterInfo_t paramInfo;
    if (proxy->CADIGetParameterInfo(param_name, &paramInfo) != eslapi::CADI_STATUS_OK)
        return false;

    eslapi::CADIParameterValue_t paramVal(paramInfo.id, paramInfo.dataType, intVal, strVal);
    eslapi::CADIFactoryErrorMessage_t error;
    if (proxy->CADISetParameters(1, &paramVal, &error) != eslapi::CADI_STATUS_OK)
        return false;

    return true;
}


sg::accessfunc::AccessFuncResult Component__AMBAPV2PVBus::parameter_read_func(uint32_t id, int64_t *data)
{
    if (data == 0)
        return eslapi::CADI_STATUS_IllegalArgument;

    switch (id)
    {
	case PARAMETER_ID_base_addr: *data = base_addr; break;
	case PARAMETER_ID_shareable: *data = shareable; break;

        default:
            printf("error: Component__AMBAPV2PVBus::parameter_read_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__AMBAPV2PVBus::parameter_read_string_func(uint32_t id, std::string &data)
{
    (void)data;
    switch (id)
    {

        default:
            printf("error: Component__AMBAPV2PVBus::parameter_read_string_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__AMBAPV2PVBus::parameter_write_func(uint32_t id, const int64_t *data)
{
    if (data == 0)
        return eslapi::CADI_STATUS_IllegalArgument;

    switch (id)
    {
	case PARAMETER_ID_base_addr:
		{
			*(const_cast<uint64_t*>(&base_addr)) = *data;
		}
		break;
	case PARAMETER_ID_shareable:
		{
			*(const_cast<bool*>(&shareable)) = !!*data;
		}
		break;

        default:
            printf("error: Component__AMBAPV2PVBus::parameter_write_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__AMBAPV2PVBus::parameter_write_string_func(uint32_t id, const std::string &data)
{
    (void)data;
    switch (id)
    {

        default:
            printf("error: Component__AMBAPV2PVBus::parameter_write_string_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

void Component__AMBAPV2PVBus::cadiPort__LoadApplicationFile(const std::string& filename)
{
    loadApplicationFile(filename);
    applications2params[filename] = "";
}

void Component__AMBAPV2PVBus::cadiPort__GetApplicationsAndCommandLineParams(std::map<std::string, std::string>&applications2params_)
{
    applications2params_ = applications2params;
}

eslapi::CADIReturn_t Component__AMBAPV2PVBus::cadiPort__GetProperty(const std::string& propertyName, std::string &value)
{
    if(properties__.find(propertyName) != properties__.end())
    {
        value = properties__[propertyName];
        return eslapi::CADI_STATUS_OK;
    }
    else
    {
        value = "";
        return eslapi::CADI_STATUS_GeneralError;
    }
}

// functions to stop and lock the simulator
// we only expose the simHalt() function in the documentation for the moment

void Component__AMBAPV2PVBus::simHalt()
{
    cadi__->StopSimulation();
}


// start simulation from the inside
// (useful from visualisation components which can execute code while the
// simulation is stopped, like key events)
void Component__AMBAPV2PVBus::simRun()
{
    cadi__->CADIExecContinue();
}


// return true if simulation is running
// (useful from visualisation components which can execute code while the
// simulation is stopped, like key events)
bool Component__AMBAPV2PVBus::simIsRunning()
{
    uint32_t mode = eslapi::CADI_EXECMODE_Stop;
    cadi__->CADIExecGetMode(&mode);
    return mode != eslapi::CADI_EXECMODE_Stop;
}


void Component__AMBAPV2PVBus::simShutdown()
{
    cadiPort__.simShutdown();
}

void Component__AMBAPV2PVBus::simReset(uint32_t level)
{
    cadi__->CADIExecReset(level);
}

uint32_t Component__AMBAPV2PVBus::paramNameToParamAccessFuncID(const std::string &name)
{
    uint32_t id = 0;
    if (name == "") id = 0xffffffff;
    if (name == "base_addr") id = PARAMETER_ID_base_addr;
    if (name == "shareable") id = PARAMETER_ID_shareable;

    return id;
}

void Component__AMBAPV2PVBus::reset_resources__()
{
    // resource initialization code

}

void Component__AMBAPV2PVBus::connect_controlports__()
{
    typedef struct {
        sg::Port * local_cport_name;
        sg::ComponentBase * local_instance_name;
        const char * cport_name;
    } connection_map_t;


    connection_map_t cmap[] = {
    {&controlPort_bus_master__,bus_master,"$control"},
    { 0, 0, 0 },
    };


    for(unsigned int i=0; cmap[i].local_cport_name != 0; i++) {
        connection_map_t c = cmap[i];
        c.local_cport_name->connectTo(c.local_instance_name->findPort(c.cport_name));
    }


    // #CONNECT_CONTROLPORTS_TO_SUBCOMPONENTS#
}

void Component__AMBAPV2PVBus::add_abstractports__0__()
{
	publishMasterPort("pvbus_m", pvbus_m);
	pvbus_m.SetName__("pvbus_m");
	publishSlavePort("amba_pv_s", amba_pv_s);
	amba_pv_s.SetName__("amba_pv_s");
	reset_bus_interfaces.SetName__("reset_bus_interfaces");
	__AMBAPV2PVBus_internal_1.SetName__("__AMBAPV2PVBus_internal_1");
}



void Component__AMBAPV2PVBus::add_abstractports__()
{
	add_abstractports__0__();

}

void Component__AMBAPV2PVBus::wire_connectionmap__0__()
{
	bus_master->findPort("pvbus_m").connectTo(pvbus_m);
	reset_bus_interfaces.connectTo(bus_master->findPort("reset"));
	__AMBAPV2PVBus_internal_1.connectTo(bus_master->findPort("control"));
}



void Component__AMBAPV2PVBus::wire_connectionmap__()
{
	wire_connectionmap__0__();

}


} // DMA_NMS
#line 226 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { AccessFuncResult 
Component__PVBus2AMBAPV::write_dump_dmi_cache(uint32_t id, const int64_t* data)
{
 if (*data)
 {
 dump_dmi.setValue(sg::Signal::Set);
 }
 return ACCESS_FUNC_OK;
 
}
}

#line 237 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { void 
Component__PVBus2AMBAPV::build_amba_pv_extension(const pv::Transaction* tx, amba_pv::amba_pv_extension* ex)
{
 const pv::TransactionAttributes* attr = tx->getAttributes();
 if (attr != 0)
 {
 ex->set_id(attr->getMasterID());
 ex->set_extended_id(attr->getExtendedID());

 
 
 
 
 
 
 

 
 ex->set_bufferable(attr->isOuterBufferable());
 ex->set_modifiable(attr->isOuterCacheable());
 ex->set_read_allocate(attr->isOuterReadAllocatable());
 ex->set_write_allocate(attr->isOuterWriteAllocatable());

 
 ex->set_privileged(attr->isPrivileged());
 ex->set_non_secure(attr->isNormalWorld());
 ex->set_instruction(attr->isInstruction());

 
 ex->set_exclusive(attr->isExclusive());
 ex->set_locked(attr->isLocked()); 

 
 ex->set_translated_access(attr->isTranslatedAccess());

 
 ex->set_user(attr->getUserFlags());

 
 
 ex->set_service_req_number(amba_pv::amba_pv_service_req_t(attr->getServiceRequestNumber()));

 
 ex->set_address_based_routed(attr->isAddressBasedRouted());
 }
 
}
}

#line 286 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { bool 
Component__PVBus2AMBAPV::send_tlm_dmi_request(pv::Transaction* tx, tlm::tlm_command command)
{
 amba_pv::amba_pv_trans_ptr trans(trans_pool.allocate(1, NULL));
 amba_pv::amba_pv_extension * ex = NULL;

 
 trans->set_command(command);
 trans->set_address(tx->getAddress());

 
 trans->get_extension(ex);
 build_amba_pv_extension(tx, ex);

 pv_userpayload_extension user_ex(tx->getPayload()->getUserPayload(), trans.get());

 
 return get_direct_mem_ptr(tx, *trans);
 
}
}

#line 307 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { pv::Tx_Result 
Component__PVBus2AMBAPV::handle_transaction_result(pv::Transaction* tx, amba_pv::amba_pv_transaction* trans, amba_pv::amba_pv_extension* extension)
{
 bool dmi_allowed = false;
 amba_pv::amba_pv_resp_t amba_resp;
 bool amba_exclusive = false;

 dmi_allowed = trans->is_dmi_allowed();
 amba_resp = extension->get_resp();
 amba_exclusive = extension->is_exclusive();

 if (dmi_allowed)
 {
 if (tx->getPayload()->getWantPrefetch())
 {
 assert(amba_exclusive == false); 
 trans->set_address(tx->getAddress());
 extension->set_id(tx->getMasterID());
 get_direct_mem_ptr(tx, *trans);
 }
 else
 {
 if (trans->is_read())
 tx->getPayload()->setPrefetchReadHint(); 
 else
 tx->getPayload()->setPrefetchWriteHint(); 
 }
 }

 
 switch(amba_resp)
 {
 case amba_pv::AMBA_PV_INCOMPLETE: return tx->generateAbort();
 case amba_pv::AMBA_PV_SLVERR: return tx->generateSlaveAbort();
 case amba_pv::AMBA_PV_DECERR: return tx->generateDecodeAbort();
 case amba_pv::AMBA_PV_OKAY:
 if (amba_exclusive)
 return tx->generateExclusiveAbort();
 break;
 case amba_pv::AMBA_PV_EXOKAY:
 break;
 }

 return pv::Tx_Result();
 
}
}

#line 356 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { pv::Tx_Result 
Component__PVBus2AMBAPV::send_tlm_transaction(pv::Transaction* tx, tlm::tlm_command command, amba_pv::amba_pv_transaction* transCache)
{
 pv::Tx_Result res;

 if (reentryCounter > 0)
 return send_tlm_transaction(tx, command, false);

 {
 ++reentryCounter;

 
 transCache->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
 transCache->set_dmi_allowed(false);
 transCache->set_address(tx->getAddress());
 transCache->set_data_ptr((unsigned char*)tx->referenceDataValue());
 transCache->set_data_length(tx->getTransactionByteSize());
 transCache->set_streaming_width(transCache->get_data_length()); 

 
 amba_pv::amba_pv_extension *extensionCache;
 transCache->get_extension(extensionCache);
 extensionCache->set_incomplete();
 build_amba_pv_extension(tx, extensionCache);

 
 pv_userpayload_extension user_ex(tx->getPayload()->getUserPayload(), transCache);

 
 extensionCache->set_size(tx->getAccessByteWidth());
 if (extensionCache->get_size() < 1)
 {
 
 res = tx->generateAbort();
 return res;
 }
 extensionCache->set_length(tx->getBurstLength());

 
 sc_core::sc_time t = scx::scx_sc_time_from_value(tx->getLocalTimeInTicks());
 amba_pv_m.b_transport(0, *transCache, t);
 tx->setLocalTimeInTicks(t.value());

 res = handle_transaction_result(tx, transCache, extensionCache);

 transCache->reset();
 
 --reentryCounter;
 }

 return res;
 
}
}

#line 411 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { pv::Tx_Result 
Component__PVBus2AMBAPV::send_tlm_transaction(pv::Transaction* tx, tlm::tlm_command command, bool debug)
{
 amba_pv::amba_pv_trans_ptr trans(trans_pool.allocate(tx->getBurstLength(),
 tx->getAccessByteWidth(),
 NULL,
 amba_pv::AMBA_PV_INCR));
 amba_pv::amba_pv_extension * ex = NULL;
 pv::Tx_Result result;

 
 trans->set_command(command);
 trans->set_address(tx->getAddress());
 trans->set_data_ptr((unsigned char*)tx->referenceDataValue());
 trans->set_data_length(tx->getTransactionByteSize());
 trans->set_streaming_width(trans->get_data_length()); 

 
 trans->get_extension(ex);
 if (ex->get_size() < 1)
 {
 
 result = tx->generateAbort();
 return result;
 }
 build_amba_pv_extension(tx, ex);

 
 pv_userpayload_extension user_ex(tx->getPayload()->getUserPayload(), trans.get());

 if (debug)
 {
 if (amba_pv_m.transport_dbg(0, *trans) != trans->get_data_length())
 {
 result = tx->generateAbort();
 }
 }
 else
 {
 sc_core::sc_time t = scx::scx_sc_time_from_value(tx->getLocalTimeInTicks());

 amba_pv_m.b_transport(0, *trans, t);
 tx->setLocalTimeInTicks(t.value());
 }

 
 if (debug)
 return result;

 result = handle_transaction_result(tx, trans.get(), ex);

 return result;
 
}
}

#line 465 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { bool 
Component__PVBus2AMBAPV::get_direct_mem_ptr(pv::Transaction* tx, amba_pv::amba_pv_transaction& trans)
{
 tlm::tlm_dmi dmi_data;
 bool dmi_ok = amba_pv_m.get_direct_mem_ptr(0, trans, dmi_data);
 sg::ticks_t dmi_read_latency = 0, dmi_write_latency = 0;

 pv::bus_range_t effective_range = pv::range_begin_end_incl(dmi_data.get_start_address(), dmi_data.get_end_address());
 if (force_dmi_size)
 {
 pv::bus_range_t inner_range = effective_range;
 
 
 
 
 
 inner_range.reduce_to_contained_power_of_two_granule(GRANULARITY);
 if (inner_range.contains(tx->getAddress()))
 {
 
 
 effective_range = inner_range;
 }
 else
 {
 
 
 dmi_ok = false;
 effective_range = pv::range_begin_end_incl(tx->getAddress(), tx->getAddress());
 effective_range.expand_to_cover_power_of_two_granule(GRANULARITY);
 dmi_data.allow_read_write();
 }
 }

 unsigned char *dmi_ptr = dmi_ok ? dmi_data.get_dmi_ptr() : 0;

 
 if (effective_range.full() || ((max_size > 0) && (effective_range.size() > max_size)))
 effective_range = pv::range_begin_end(effective_range.begin, max_size - 1);

 
 if ((effective_range.begin > dmi_data.get_start_address()) && (dmi_ptr != 0))
 dmi_ptr += (effective_range.begin - dmi_data.get_start_address());
 
 
 if (dmi_data.is_read_allowed())
 {
 pv::PrefetchRange<pv::AccessRead> range (dmi_ptr, effective_range);

 tx->getPayload()->setPrefetchRange(range);
 if (dmi_ok)
 {
 dmi_read_latency = dmi_data.get_read_latency().value();
 tx->getPayload()->setReadPrefetchLatency(dmi_read_latency);
 }
 }
 if (dmi_data.is_write_allowed())
 {
 pv::PrefetchRange<pv::AccessWrite> range(dmi_ptr, effective_range);

 tx->getPayload()->setPrefetchRange(range);
 if (dmi_ok)
 {
 dmi_write_latency = dmi_data.get_write_latency().value();
 tx->getPayload()->setWritePrefetchLatency(dmi_write_latency);
 }
 }
 if (!dmi_ok)
 {
 
 
 if ((trans.is_read() && dmi_data.is_write_allowed()) ||
 (trans.is_write() && dmi_data.is_read_allowed()))
 tx->getPayload()->setPrefetchIsDeniedForOtherAccessHint();
 }
 return dmi_ok;
 
}
}

#line 543 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { void 
Component__PVBus2AMBAPV::init()
{
 {if(!controlPort_bus_bridge__.init.empty()) controlPort_bus_bridge__.init();};

 trans_pool.reserve(4);

 transCacheRead.reset(trans_pool.allocate(1, NULL));
 transCacheRead->set_command(tlm::TLM_READ_COMMAND);

 transCacheWrite.reset(trans_pool.allocate(1, NULL));
 transCacheWrite->set_command(tlm::TLM_WRITE_COMMAND);
 
}
}

#line 557 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { void 
Component__PVBus2AMBAPV::terminate()
{
 dump_dmi.setValue(sg::Signal::Set);
 {if(!controlPort_bus_bridge__.terminate.empty()) controlPort_bus_bridge__.terminate();};
 
}
}

#line 563 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { void 
Component__PVBus2AMBAPV::reset(int level_)
{
 {if(!controlPort_bus_bridge__.reset.empty()) controlPort_bus_bridge__.reset(level_);};

 busDiscovery();
 
}
}

#line 571 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { void 
Component__PVBus2AMBAPV::busDiscovery()
{
 if (bus_node.startDiscovery(true, false))
 {
 amba_pv::amba_pv_trans_ptr trans(trans_pool.allocate(0, NULL));

 trans->set_command(tlm::TLM_IGNORE_COMMAND);
 trans->set_address(0);
 trans->set_data_ptr(NULL);
 trans->set_data_length(0);
 trans->set_streaming_width(0);

 amba_pv_m.transport_dbg(0, *trans);
 }
 bus_node.endDiscovery();
 bus_node.declareBridge(getHierarchicalName().c_str(), "PVBus", "AMBAPV");
 
}
}

#line 17 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { void 
Component__PVBus2AMBAPV::interconnect()
{{if(!controlPort_bus_bridge__.interconnect.empty()) controlPort_bus_bridge__.interconnect();};
}
}

#line 17 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { void 
Component__PVBus2AMBAPV::disconnect()
{{if(!controlPort_bus_bridge__.disconnect.empty()) controlPort_bus_bridge__.disconnect();};
}
}

#line 17 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { void 
Component__PVBus2AMBAPV::loadApplicationFile(const std::string& filename)
{{if(!controlPort_bus_bridge__.loadApplicationFile.empty()) controlPort_bus_bridge__.loadApplicationFile(filename);};(void)filename;
}
}

#line 17 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { void 
Component__PVBus2AMBAPV::step()
{{if(!controlPort_bus_bridge__.step.empty()) controlPort_bus_bridge__.step();};
}
}

#line 126 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { void 
Component__PVBus2AMBAPV::abstract_port__amba_pv_m__invalidate_direct_mem_ptr(int socket_id, sc_dt::uint64 start_range, sc_dt::uint64 end_range)
{
 pv::bus_addr_t base = getBaseAddress(pv::bus_addr_t(start_range));
 pv::bus_addr_t limit = getLimitAddress(pv::bus_addr_t(end_range));

 assert(limit >= base);

 control_bridge.revokePrefetch(base, limit);
 
}
}

#line 142 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { pv::Tx_Result 
Component__PVBus2AMBAPV::abstract_port__device__read(pv::ReadTransaction tx)
{
 
 if (tx.getPayload() && tx.getPayload()->isPrefetchOnly())
 return send_tlm_dmi_request(&tx, tlm::TLM_READ_COMMAND) ? tx.readComplete() : tx.wontPrefetch();
 
 pv::Tx_Result result = send_tlm_transaction(&tx, tlm::TLM_READ_COMMAND, transCacheRead.get());

 
 if (result.isUndefined())
 {
 result = tx.readComplete();
 }
 
 if (tx.getBurstLength()>1)
 tx.allBeatsCompletedInOneOperation(result);

 return result;
 
}
}

#line 163 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { pv::Tx_Result 
Component__PVBus2AMBAPV::abstract_port__device__write(pv::WriteTransaction tx)
{
 
 if (tx.getPayload() && tx.getPayload()->isPrefetchOnly())
 return send_tlm_dmi_request(&tx, tlm::TLM_WRITE_COMMAND) ? tx.writeComplete() : tx.wontPrefetch();
 
 pv::Tx_Result result = send_tlm_transaction(&tx, tlm::TLM_WRITE_COMMAND, transCacheWrite.get());

 
 if (result.isUndefined())
 {
 result = tx.writeComplete();
 }
 
 if (tx.getBurstLength()>1)
 tx.allBeatsCompletedInOneOperation(result);

 return result;
 
}
}

#line 184 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { pv::Tx_Result 
Component__PVBus2AMBAPV::abstract_port__device__debugRead(pv::ReadTransaction tx)
{
 
 if (tx.getPayload() && tx.getPayload()->isPrefetchOnly())
 return send_tlm_dmi_request(&tx, tlm::TLM_READ_COMMAND) ? tx.readComplete() : tx.wontPrefetch();

 pv::Tx_Result result = send_tlm_transaction(&tx, tlm::TLM_READ_COMMAND, true);

 
 if (result.isUndefined())
 {
 result = tx.readComplete();
 }
 
 if (tx.getBurstLength()>1)
 tx.allBeatsCompletedInOneOperation(result);

 return result;
 
}
}

#line 205 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
namespace DMA_NMS { pv::Tx_Result 
Component__PVBus2AMBAPV::abstract_port__device__debugWrite(pv::WriteTransaction tx)
{
 
 if (tx.getPayload() && tx.getPayload()->isPrefetchOnly())
 return send_tlm_dmi_request(&tx, tlm::TLM_WRITE_COMMAND) ? tx.writeComplete() : tx.wontPrefetch();

 pv::Tx_Result result = send_tlm_transaction(&tx, tlm::TLM_WRITE_COMMAND, true);

 
 if (result.isUndefined())
 {
 result = tx.writeComplete();
 }
 
 if (tx.getBurstLength()>1)
 tx.allBeatsCompletedInOneOperation(result);

 return result;
 
}
}

#line 2512 "./Linux64-Release-GCC-7.3/gen/Comp_NonDSO_1.cpp"

// ------------------------------------------------------------------------------
// implementation of class Component__PVBus2AMBAPV
// ------------------------------------------------------------------------------

namespace DMA_NMS {


    namespace MT
    {
        Component__PVBus2AMBAPV::Component__PVBus2AMBAPV(
            sg::ComponentFactory*      factory,
            sg::MTWrapperConfig const& wrapper_config,
            std::string const&         mtdomain_name,
            std::string const&         instName,
            sg::SimulationContext*     simulationContext,
            sg::Params const&          params
            )
        {
        
            // what this creates is a component where 
            auto result = MTComponentWrapper(
                factory, wrapper_config, mtdomain_name, instName, simulationContext, params
                );
            mtdomain_id   = result.mtdomain_id;
            raw_component = dynamic_cast<wrapped_type*>(result.raw_component);
            setComponentBase(result.wrapper_component);

            // Forward the ports in the publicly visible part of the class to the
            // versions that have been created by the wrapper.
            connectPort(KIND_IN_WRAPPED_COMPONENT_Slave, "pvbus_s", pvbus_s);
            connectPort(KIND_IN_WRAPPED_COMPONENT_Master, "amba_pv_m", amba_pv_m);


            ; // fixup indentation in template file.
        }

        Component__PVBus2AMBAPV::~Component__PVBus2AMBAPV()
        {
            ; // do nothing
        }
    }
    
    // This is a list of the properties of the component of the form:
    //    { "propertyA", "valueA" }, {"propertyB", "valueB"}, ... , {nullptr, nullptr}
    static SystemGenComponent::property_value_pair_t const Component__PVBus2AMBAPV_properties_201705121426_[] = {
	{ "component_name", "PVBus2AMBAPV", 0 },
	{ "component_type", "Bridge", 0 },
	{ "debugger_name", "", 0 },
	{ "debugger_start_command", "", 0 },
	{ "default_view", "auto", 0 },
	{ "deprecated", "0", 0 },
	{ "description", "PVBus to AMBA-PV protocol converter", 0 },
	{ "documentation_file", "../#100964#", 0 },
	{ "dso_safe", "0", 0 },
	{ "executes_software", "0", 0 },
	{ "expose_extern_sub_component_cadi", "1", 0 },
	{ "factory_namespace", "", 0 },
	{ "has_cadi", "1", 0 },
	{ "has_implicit_clk_in", "1", 0 },
	{ "hidden", "0", 0 },
	{ "hwversion", "", 0 },
	{ "icon_file", "", 0 },
	{ "ip_provider", "", 0 },
	{ "is_single_stepped", "0", 0 },
	{ "license_feature", "", 0 },
	{ "loadfile_extension", "", 0 },
	{ "mtdomains", "", 0 },
	{ "mtdomains_tool_config", "", 0 },
	{ "package", "", 0 },
	{ "resources_are_public", "0", 0 },
	{ "small_icon_file", "", 0 },
	{ "variant", "", 0 },
	{ "version", "11.10.22", 0 },

        { nullptr, nullptr, 0 }
    };

Component__PVBus2AMBAPV::Component__PVBus2AMBAPV(const char * instName, sg::SimulationContext* simulationContext, const sg::Params & params):
    SystemGenComponent(instName, simulationContext, params, Component__PVBus2AMBAPV_properties_201705121426_)

	,max_size(GetParameterValue(params, "size", INT64_C(0x1000000000000), INT64_C(0x8000000000000000), INT64_C(0x7fffffffffffffff)))
	,force_dmi_size(GetParameterValue(params, "force-dmi-size", static_cast<bool>(0x1) ))
	,dmi_container_type(GetParameterValue(params, "dmi-container-type", "TZAttr"))
	,counters_file_name(GetParameterValue(params, "counters-file-name", ""))
	,min_size_to_cache(GetParameterValue(params, "min-range-to-cache", INT64_C(0x10000), INT64_C(0x1000), INT64_C(0x7fffffffffffffff)))
	,dump_dmi_file_name(GetParameterValue(params, "dump-dmi-file-name", ""))
	,dump_dmi_cache(GetParameterValue(params, "dump-dmi-cache", static_cast<bool>(0x0) ))


	,cadiParameterProxy_bus_bridge_of_PVBusBridge_to_PVBus2AMBAPV__(0)

{
    // initialize parameter info
    {
        sg::ComponentFactory *factory = PVBus2AMBAPV_GetFactory();

        sg::TargetInfo *targetInfo = factory->getTargetInfo(""); // empty string means 'this' component

        if(targetInfo) // if we have no target info we also have no parameters towards CADI interfaces
        {
            // get parameter infos
            for(unsigned int i = 0; i < targetInfo->parameter_count; i++)
            {
                parameterId2parameterName__[targetInfo->parameter_info[i].id] = targetInfo->parameter_info[i].name;
                parameterInfos__.push_back((targetInfo->parameter_info)[i]);
            }
        }

        factory->dereference();
    }

    // bad_params is used by any components for which it needs to do:
    //           params.interpolate("$mtdomain_name", bad_params)
    // for the mtdomain parameter passed to the proxying component.
    //
    // However, we don't actually ever do anything with the result as
    // fillOutMTWrapperConfig__() will report any interpolation errors.
    std::vector< std::pair<std::string, std::string::size_type> > bad_params;
    sg::MTWrapperConfig mtwrapper_config__;
    fillOutMTWrapperConfig__(mtwrapper_config__);
    
    // create subcomponents
    
	{
		sg::ComponentFactory *PVBusBridge_factory = PVBusBridge_GetFactory();
		{
			sg::Params params_bus_bridge__ = params.getParamsFor("bus_bridge");
			params_bus_bridge__["min-range-to-cache"] = min_size_to_cache;
			params_bus_bridge__["dmi-container-type"] = dmi_container_type;
			params_bus_bridge__["counters-file-name"] = counters_file_name;
			params_bus_bridge__["dump-dmi-file-name"] = dump_dmi_file_name;
			bus_bridge = PVBusBridge_factory->instantiate(subcompHierName("bus_bridge"), simulationContext, params_bus_bridge__);
			bus_bridge->setParent(this);
			assert(bus_bridge);
			add(bus_bridge);
		}
		PVBusBridge_factory->dereference();
	}


    // bind local behaviors to this->control_port
    bind_method(control_port, configure, &Component__PVBus2AMBAPV::control_port__configure, this);
    bind_method(control_port, init, &Component__PVBus2AMBAPV::control_port__init, this);
    bind_method(control_port, interconnect, &Component__PVBus2AMBAPV::interconnect, this);
    bind_method(control_port, reset, &Component__PVBus2AMBAPV::control_port__reset, this);
    bind_method(control_port, loadApplicationFile, &Component__PVBus2AMBAPV::loadApplicationFile, this);
    bind_method(control_port, serializeState, &Component__PVBus2AMBAPV::control_port__serializeState, this);
    bind_method(control_port, disconnect, &Component__PVBus2AMBAPV::disconnect, this);
    bind_method(control_port, terminate, &Component__PVBus2AMBAPV::control_port__terminate, this);
    bind_method(control_port, populateCADIMap, &Component__PVBus2AMBAPV::control_port__populateCADIMap, this);
    bind_method(control_port, step, &Component__PVBus2AMBAPV::step, this);
    bind_method(control_port, getProperty, &Component__PVBus2AMBAPV::control_port__getProperty, this);
    bind_method(control_port, bypass, &Component__PVBus2AMBAPV::control_port__bypass, this);
    bind_method(control_port, run, &Component__PVBus2AMBAPV::control_port__run, this);
    bind_method(control_port, stop, &Component__PVBus2AMBAPV::control_port__stop, this);
    bind_method(control_port, idle, &Component__PVBus2AMBAPV::control_port__idle, this);
    bind_method(control_port, quit, &Component__PVBus2AMBAPV::control_port__quit, this);
    bind_method(control_port, setSimulationEngine, &Component__PVBus2AMBAPV::control_port__setSimulationEngine, this);
    bind_method(control_port, message, &Component__PVBus2AMBAPV::control_port__message, this);
    bind_method(control_port, callSimEngine, &Component__PVBus2AMBAPV::control_port__callSimEngine, this);

    // Avoid the propagation of calls to subcomponents through the framework:
    // if setLocalOnly(true) is not called, any call to an element (connector)
    // of the control port, causes the corresponding behaviours of all
    // subcomponents to be automatically called, too. Whenever we want the
    // LISA programmer to control the propagation of special-purpose behaviours,
    // we need to prevent this to happen.
    control_port.configure.setLocalOnly(true);
    control_port.init.setLocalOnly(true);
    control_port.interconnect.setLocalOnly(true);
    control_port.reset.setLocalOnly(true);
    control_port.loadApplicationFile.setLocalOnly(true);
    control_port.serializeState.setLocalOnly(true);
    control_port.disconnect.setLocalOnly(true);
    control_port.terminate.setLocalOnly(true);
    control_port.populateCADIMap.setLocalOnly(true);
    control_port.step.setLocalOnly(true);
    control_port.getProperty.setLocalOnly(true);
//  control_port.bypass.setLocalOnly(true);
//  control_port.run.setLocalOnly(true);
//  control_port.stop.setLocalOnly(true);
//  control_port.idle.setLocalOnly(true); // broadcast ports don't have setLocalOnly
//  control_port.quit.setLocalOnly(true);
//  control_port.setSimulationEngine.setLocalOnly(true);

    // bind cadiPort behaviors
    bind_method(cadiPort__, GetProperty, &Component__PVBus2AMBAPV::cadiPort__GetProperty, this);
    bind_method(cadiPort__, LoadApplicationFile, &Component__PVBus2AMBAPV::cadiPort__LoadApplicationFile, this);
    bind_method(cadiPort__, GetApplicationsAndCommandLineParams, &Component__PVBus2AMBAPV::cadiPort__GetApplicationsAndCommandLineParams, this);

    // connect control ports for subcomponents to subcomponents
    connect_controlports__();

    // resource initialization code
    reset_resources__();

    // bind behaviors to abstract ports
	bind_method(amba_pv_m, invalidate_direct_mem_ptr, &Component__PVBus2AMBAPV::abstract_port__amba_pv_m__invalidate_direct_mem_ptr, this);
	bind_method(device, read, &Component__PVBus2AMBAPV::abstract_port__device__read, this);
	bind_method(device, write, &Component__PVBus2AMBAPV::abstract_port__device__write, this);
	bind_method(device, debugRead, &Component__PVBus2AMBAPV::abstract_port__device__debugRead, this);
	bind_method(device, debugWrite, &Component__PVBus2AMBAPV::abstract_port__device__debugWrite, this);


    // add abstract ports
    add_abstractports__();

    // wire up static connection map
    wire_connectionmap__();

    // init profiling

    // init resources


    // run the parameter write access functions for all of the component's parameters
    for (size_t i = 0; i < parameterInfos__.size(); ++i)
    {
        std::string paramName = parameterInfos__[i].name;

        switch (parameterInfos__[i].dataType)
        {
        case eslapi::CADI_PARAM_STRING:
            {
                std::string data = GetParameterValue(params, paramName, parameterInfos__[i].defaultString);
                parameter_write_string_func(paramNameToParamAccessFuncID(paramName), data);
            }
            break;
        case eslapi::CADI_PARAM_BOOL:
            {
                bool default_val = string2bool(parameterInfos__[i].defaultString);
                int64_t data = static_cast<int64_t>(GetParameterValue(params, paramName, default_val));
                parameter_write_func(paramNameToParamAccessFuncID(paramName), &data);
            }
            break;
        case eslapi::CADI_PARAM_INT:
            {
                int64_t data = GetParameterValue(params, paramName, parameterInfos__[i].defaultValue, parameterInfos__[i].minValue, parameterInfos__[i].maxValue);
                parameter_write_func(paramNameToParamAccessFuncID(paramName), &data);
            }
            break;
        default:
            break;
        }
    }
}


Component__PVBus2AMBAPV::~Component__PVBus2AMBAPV()
{
}

void Component__PVBus2AMBAPV::control_port__serializeState(const char *name, cp::SerializationInterface* stream)
{
    serializeState(name, stream);
}

void Component__PVBus2AMBAPV::control_port__configure(const sg::Params& params)
{
    (void)params;

	if(controlPort_bus_bridge__.configure.implemented()) controlPort_bus_bridge__.configure(params.getParamsFor("bus_bridge"));


    assert(simulationContext__->getSimulationEngine());
    cadi__ = new Component__PVBus2AMBAPV_CADI(this, simulationContext__->getSimulationEngine());
    buildDebugInfoWithMetaData__();

    // forward certain calls from CADI interface to this component
    cadi__->GetCADIPort().connectTo(cadiPort__);

    

    std::map< std::string, eslapi::CAInterface* > tempMap;
    control_port__populateCADIMap(tempMap, ""); // precompute mxdi map

	cadi__->EnableSubComponentCADIImport();


}

void Component__PVBus2AMBAPV::control_port__init()
{
    // We assume that the message() part of the control port is now bound
    // correctly.  Thus anything that we have buffered from prior to now can be
    // dumped.
    dontBufferMessages__();
    
    // Call the behavior init()
    init();
}

void Component__PVBus2AMBAPV::control_port__populateCADIMap(std::map< std::string, eslapi::CAInterface* >&output_map, std::string const & base_prefix)
{
    if (componentName2CADI__.empty())
    {
        componentName2CADI__[getName()] = static_cast<eslapi::CADI*>(cadi__);
        std::string prefix = cadiNamePrefix;

		{
			std::map< std::string, eslapi::CAInterface* > compMap;
			if (controlPort_bus_bridge__.populateCADIMap.implemented())
			{
				controlPort_bus_bridge__.populateCADIMap(compMap, "");
			}
			insertCADIMap__(prefix, compMap);
			eslapi::CADI *cadi = obtainCADI__("bus_bridge", compMap);
			if (cadi != NULL)
			{
				cadiParameterProxy_bus_bridge_of_PVBusBridge_to_PVBus2AMBAPV__ = new CADIParameterProxy(cadi, &parameterFilter_bus_bridge_of_PVBusBridge_to_PVBus2AMBAPV__);
			}
		}

    }
    // Copy the local map into the given map with the requested prefix.
    for (std::map<std::string,eslapi::CAInterface*>::iterator it = componentName2CADI__.begin(); it != componentName2CADI__.end(); ++it)
    {
        output_map.insert(std::make_pair(base_prefix + it->first, it->second));
    }
}

// Turn off optimizations for this function; it is not performance critical as it is only
// generally run once per simulation on startup. Keeping track of the large number of
// variables in some cases causes the comiler to take a lot of time and memory attempting
// to optimize, so we explicitly turn this off.
#ifdef WIN32
# pragma optimize("", off)
#else
# pragma GCC push_options
# pragma GCC optimize ("O0")
#endif
void Component__PVBus2AMBAPV::buildDebugInfoWithMetaData__()
{


    sg::CADIBase::RegInfo regData[] =
    {

        {"ETFR", "ExtendedTargetFeatureRegisterGroup", 0, 0, eslapi::CADI_REGTYPE_STRING, "Extended Target Features", eslapi::CADI_REG_READ_ONLY, 0, 0, 0, true, 0, false, 0, 0, 0, true/*pseudo*/, true, 0xFFFFFFFF, 0, 0, 0, 0, 0xffffffff, 0, 0, false, false, false},
        {0, "", 0, 0, eslapi::CADI_REGTYPE_HEX, 0, eslapi::CADI_REG_READ_WRITE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    // the instance specific data has to be non-static, this is currently only access_data
    // this array is compressed: only registers which have hasInstanceSpecificPointers=true in regData are present here
    sg::CADIBase::RegInfoInstanceSpecific regDataInstanceSpecific[] = {

        {0, 0, 0, 0, MakeDelegate(this, &Component__PVBus2AMBAPV::GetExtendedTargetFeatures__), 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    sg::CADIBase::ParamInfo paramData[] =
    {
		{ 0x10000004, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_read_func), 0, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_write_func), 0 },
		{ 0x10000005, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_read_func), 0, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_write_func), 0 },
		{ 0x10000006, 0, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_read_string_func), 0, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_write_string_func) },
		{ 0x10000007, 0, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_read_string_func), 0, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_write_string_func) },
		{ 0x10000008, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_read_func), 0, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_write_func), 0 },
		{ 0x10000009, 0, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_read_string_func), 0, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_write_string_func) },
		{ 0x1000000A, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_read_func), 0, MakeDelegate(this, &Component__PVBus2AMBAPV::parameter_write_func), 0 },

        { 0, 0, 0, 0, 0 }
    };

    buildDebugInfo__(regData, (sizeof(regData) / sizeof( regData[0])) - 1,
                     regDataInstanceSpecific, sizeof(regDataInstanceSpecific) / sizeof( regDataInstanceSpecific[0]),
                     paramData, sizeof(paramData) / sizeof(paramData[0]));
}
// Restore optimization.
#ifdef WIN32
# pragma optimize("", on)
#else
# pragma GCC pop_options
#endif

sg::accessfunc::AccessFuncResult
Component__PVBus2AMBAPV::GetExtendedTargetFeatures__(uint32_t /*id*/, std::string &data, bool /*se*/)
{
    data = getExtendedTargetFeatures();
    return sg::accessfunc::ACCESS_FUNC_OK;
}

eslapi::CADI* Component__PVBus2AMBAPV::obtainCADI__(const std::string &subcomp, const std::map< std::string, eslapi::CAInterface* > &componentName2CADI) const
{
    std::map< std::string, eslapi::CAInterface* >::const_iterator it = componentName2CADI.find(subcomp);
    if (it != componentName2CADI.end())
    {
        eslapi::CAInterface *cai = it->second;
        if (cai != NULL)
        {
            cai = cai->ObtainInterface(eslapi::CADI::IFNAME(), 0, 0);
            if (cai != NULL)
            {
                return static_cast<eslapi::CADI*>(cai);
            }
        }
    }
    return NULL;
}

void Component__PVBus2AMBAPV::insertCADIMap__(std::string prefix, std::map< std::string, eslapi::CAInterface* > &componentName2CADI)
{
    for (std::map<std::string, eslapi::CAInterface*>::iterator it = componentName2CADI.begin(); it != componentName2CADI.end(); it++)
    {
        // put prefix in front of all entries
        componentName2CADI__[prefix + it->first] = it->second;
    }
}


std::string Component__PVBus2AMBAPV::control_port__getProperty(const std::string& propname)
{
    if(properties__.find(propname) != properties__.end())
    {
        return properties__[propname];
    }
    else
        return ""; // unknown property
}

std::string Component__PVBus2AMBAPV::control_port__bypass(const std::string&)
{
    return "";
}

void Component__PVBus2AMBAPV::control_port__run()
{
}


void Component__PVBus2AMBAPV::control_port__stop()
{
}


void Component__PVBus2AMBAPV::control_port__idle()
{
}


void Component__PVBus2AMBAPV::control_port__quit()
{
}


void Component__PVBus2AMBAPV::control_port__setSimulationEngine(sg::SimulationEngine*)
{
}


void Component__PVBus2AMBAPV::control_port__message(const std::string &/*msg*/, sg::message::MessageType /*msgType*/)
{
}


std::string Component__PVBus2AMBAPV::control_port__callSimEngine(const std::string &)
{
    return "";
}


void Component__PVBus2AMBAPV::control_port__reset(int level)
{
    drainBufferedMessages__();
    if (isShutdownAtReset__())
        message("Shutting down due to prior errors.", MSG_FATAL_ERROR);
    
    (void)level;
    // restore the resources' reset values before executing 'reset'
    reset_resources__();
    reset(level);
}


void Component__PVBus2AMBAPV::control_port__terminate()
{
    // the CADI was created before 'init', therefore we free it after 'terminate'
    terminate();
    freeCADIResources__();
}


void Component__PVBus2AMBAPV::freeCADIResources__()
{
    // free CADI parameter proxies
	delete cadiParameterProxy_bus_bridge_of_PVBusBridge_to_PVBus2AMBAPV__;
	cadiParameterProxy_bus_bridge_of_PVBusBridge_to_PVBus2AMBAPV__ = 0;


    // free CADI interface
    delete cadi__;
    cadi__ = 0;
}

bool Component__PVBus2AMBAPV::ForwardParameterValueToSubcomponent(CADIParameterProxy *proxy, const char *param_name, int64_t intVal, const char *strVal)
{
    if (!proxy)
        return false;

    // we need the parameter's CADI id in order to create an eslapi::CADIParameterValue_t structure
    // therefore, we first retrieve its eslapi::CADIParameterInfo_t meta-data
    eslapi::CADIParameterInfo_t paramInfo;
    if (proxy->CADIGetParameterInfo(param_name, &paramInfo) != eslapi::CADI_STATUS_OK)
        return false;

    eslapi::CADIParameterValue_t paramVal(paramInfo.id, paramInfo.dataType, intVal, strVal);
    eslapi::CADIFactoryErrorMessage_t error;
    if (proxy->CADISetParameters(1, &paramVal, &error) != eslapi::CADI_STATUS_OK)
        return false;

    return true;
}


sg::accessfunc::AccessFuncResult Component__PVBus2AMBAPV::parameter_read_func(uint32_t id, int64_t *data)
{
    if (data == 0)
        return eslapi::CADI_STATUS_IllegalArgument;

    switch (id)
    {
	case PARAMETER_ID_max_size: *data = max_size; break;
	case PARAMETER_ID_force_dmi_size: *data = force_dmi_size; break;
	case PARAMETER_ID_min_size_to_cache: *data = min_size_to_cache; break;
	case PARAMETER_ID_dump_dmi_cache: *data = dump_dmi_cache; break;

        default:
            printf("error: Component__PVBus2AMBAPV::parameter_read_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__PVBus2AMBAPV::parameter_read_string_func(uint32_t id, std::string &data)
{
    (void)data;
    switch (id)
    {
	case PARAMETER_ID_dmi_container_type:  data = dmi_container_type; break;
	case PARAMETER_ID_counters_file_name:  data = counters_file_name; break;
	case PARAMETER_ID_dump_dmi_file_name:  data = dump_dmi_file_name; break;

        default:
            printf("error: Component__PVBus2AMBAPV::parameter_read_string_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__PVBus2AMBAPV::parameter_write_func(uint32_t id, const int64_t *data)
{
    if (data == 0)
        return eslapi::CADI_STATUS_IllegalArgument;

    switch (id)
    {
	case PARAMETER_ID_max_size:
		{
			*(const_cast<uint64_t*>(&max_size)) = *data;
		}
		break;
	case PARAMETER_ID_force_dmi_size:
		{
			*(const_cast<bool*>(&force_dmi_size)) = !!*data;
		}
		break;
	case PARAMETER_ID_min_size_to_cache:
		{
			*(const_cast<uint32_t*>(&min_size_to_cache)) = *data;
		}
		break;
	case PARAMETER_ID_dump_dmi_cache:
		{
			write_dump_dmi_cache(id, data);
		}
		break;

        default:
            printf("error: Component__PVBus2AMBAPV::parameter_write_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__PVBus2AMBAPV::parameter_write_string_func(uint32_t id, const std::string &data)
{
    (void)data;
    switch (id)
    {
	case PARAMETER_ID_dmi_container_type:
		{
			*(const_cast<std::string*>(&dmi_container_type)) = data;
		}
		break;
	case PARAMETER_ID_counters_file_name:
		{
			*(const_cast<std::string*>(&counters_file_name)) = data;
		}
		break;
	case PARAMETER_ID_dump_dmi_file_name:
		{
			*(const_cast<std::string*>(&dump_dmi_file_name)) = data;
		}
		break;

        default:
            printf("error: Component__PVBus2AMBAPV::parameter_write_string_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

void Component__PVBus2AMBAPV::cadiPort__LoadApplicationFile(const std::string& filename)
{
    loadApplicationFile(filename);
    applications2params[filename] = "";
}

void Component__PVBus2AMBAPV::cadiPort__GetApplicationsAndCommandLineParams(std::map<std::string, std::string>&applications2params_)
{
    applications2params_ = applications2params;
}

eslapi::CADIReturn_t Component__PVBus2AMBAPV::cadiPort__GetProperty(const std::string& propertyName, std::string &value)
{
    if(properties__.find(propertyName) != properties__.end())
    {
        value = properties__[propertyName];
        return eslapi::CADI_STATUS_OK;
    }
    else
    {
        value = "";
        return eslapi::CADI_STATUS_GeneralError;
    }
}

// functions to stop and lock the simulator
// we only expose the simHalt() function in the documentation for the moment

void Component__PVBus2AMBAPV::simHalt()
{
    cadi__->StopSimulation();
}


// start simulation from the inside
// (useful from visualisation components which can execute code while the
// simulation is stopped, like key events)
void Component__PVBus2AMBAPV::simRun()
{
    cadi__->CADIExecContinue();
}


// return true if simulation is running
// (useful from visualisation components which can execute code while the
// simulation is stopped, like key events)
bool Component__PVBus2AMBAPV::simIsRunning()
{
    uint32_t mode = eslapi::CADI_EXECMODE_Stop;
    cadi__->CADIExecGetMode(&mode);
    return mode != eslapi::CADI_EXECMODE_Stop;
}


void Component__PVBus2AMBAPV::simShutdown()
{
    cadiPort__.simShutdown();
}

void Component__PVBus2AMBAPV::simReset(uint32_t level)
{
    cadi__->CADIExecReset(level);
}

uint32_t Component__PVBus2AMBAPV::paramNameToParamAccessFuncID(const std::string &name)
{
    uint32_t id = 0;
    if (name == "") id = 0xffffffff;
    if (name == "size") id = PARAMETER_ID_max_size;
    if (name == "force-dmi-size") id = PARAMETER_ID_force_dmi_size;
    if (name == "dmi-container-type") id = PARAMETER_ID_dmi_container_type;
    if (name == "counters-file-name") id = PARAMETER_ID_counters_file_name;
    if (name == "min-range-to-cache") id = PARAMETER_ID_min_size_to_cache;
    if (name == "dump-dmi-file-name") id = PARAMETER_ID_dump_dmi_file_name;
    if (name == "dump-dmi-cache") id = PARAMETER_ID_dump_dmi_cache;

    return id;
}

void Component__PVBus2AMBAPV::reset_resources__()
{
    // resource initialization code

}

void Component__PVBus2AMBAPV::connect_controlports__()
{
    typedef struct {
        sg::Port * local_cport_name;
        sg::ComponentBase * local_instance_name;
        const char * cport_name;
    } connection_map_t;


    connection_map_t cmap[] = {
    {&controlPort_bus_bridge__,bus_bridge,"$control"},
    { 0, 0, 0 },
    };


    for(unsigned int i=0; cmap[i].local_cport_name != 0; i++) {
        connection_map_t c = cmap[i];
        c.local_cport_name->connectTo(c.local_instance_name->findPort(c.cport_name));
    }


    // #CONNECT_CONTROLPORTS_TO_SUBCOMPONENTS#
}

void Component__PVBus2AMBAPV::add_abstractports__0__()
{
	publishSlavePort("pvbus_s", pvbus_s);
	pvbus_s.SetName__("pvbus_s");
	reset_bus_interfaces.SetName__("reset_bus_interfaces");
	dump_dmi.SetName__("dump_dmi");
	publishMasterPort("amba_pv_m", amba_pv_m);
	amba_pv_m.SetName__("amba_pv_m");
	control_bridge.SetName__("control_bridge");
	device.SetName__("device");
}



void Component__PVBus2AMBAPV::add_abstractports__()
{
	add_abstractports__0__();

}

void Component__PVBus2AMBAPV::wire_connectionmap__0__()
{
	pvbus_s.connectTo(bus_bridge->findPort("pvbus_s"));
	bus_bridge->findPort("device").connectTo(device);
	reset_bus_interfaces.connectTo(bus_bridge->findPort("reset"));
	dump_dmi.connectTo(bus_bridge->findPort("dump_dmi"));
	control_bridge.connectTo(bus_bridge->findPort("control"));
}



void Component__PVBus2AMBAPV::wire_connectionmap__()
{
	wire_connectionmap__0__();

}


} // DMA_NMS
#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/SGSignal2AMBAPVSignal.lisa"
namespace DMA_NMS { void 
Component__SGSignal2AMBAPVSignal::interconnect()
{;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/SGSignal2AMBAPVSignal.lisa"
namespace DMA_NMS { void 
Component__SGSignal2AMBAPVSignal::disconnect()
{;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/SGSignal2AMBAPVSignal.lisa"
namespace DMA_NMS { void 
Component__SGSignal2AMBAPVSignal::loadApplicationFile(const std::string& filename)
{;(void)filename;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/SGSignal2AMBAPVSignal.lisa"
namespace DMA_NMS { void 
Component__SGSignal2AMBAPVSignal::init()
{;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/SGSignal2AMBAPVSignal.lisa"
namespace DMA_NMS { void 
Component__SGSignal2AMBAPVSignal::terminate()
{;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/SGSignal2AMBAPVSignal.lisa"
namespace DMA_NMS { void 
Component__SGSignal2AMBAPVSignal::reset(int level)
{;(void)level;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/SGSignal2AMBAPVSignal.lisa"
namespace DMA_NMS { void 
Component__SGSignal2AMBAPVSignal::reset(int level, int /*argc*/, char** /*argv*/)
{
	reset(level);

}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/SGSignal2AMBAPVSignal.lisa"
namespace DMA_NMS { void 
Component__SGSignal2AMBAPVSignal::step()
{;
}
}

#line 39 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/SGSignal2AMBAPVSignal.lisa"
namespace DMA_NMS { void 
Component__SGSignal2AMBAPVSignal::abstract_port__sg_signal_s__setValue(sg::Signal::State value)
{
 if (value == sg::Signal::Set) {
 amba_pv_signal_m.set_state(0, true);
 } else {
 amba_pv_signal_m.set_state(0, false);
 }
 
}
}

#line 3348 "./Linux64-Release-GCC-7.3/gen/Comp_NonDSO_1.cpp"

// ------------------------------------------------------------------------------
// implementation of class Component__SGSignal2AMBAPVSignal
// ------------------------------------------------------------------------------

namespace DMA_NMS {


    namespace MT
    {
        Component__SGSignal2AMBAPVSignal::Component__SGSignal2AMBAPVSignal(
            sg::ComponentFactory*      factory,
            sg::MTWrapperConfig const& wrapper_config,
            std::string const&         mtdomain_name,
            std::string const&         instName,
            sg::SimulationContext*     simulationContext,
            sg::Params const&          params
            )
        {
        
            // what this creates is a component where 
            auto result = MTComponentWrapper(
                factory, wrapper_config, mtdomain_name, instName, simulationContext, params
                );
            mtdomain_id   = result.mtdomain_id;
            raw_component = dynamic_cast<wrapped_type*>(result.raw_component);
            setComponentBase(result.wrapper_component);

            // Forward the ports in the publicly visible part of the class to the
            // versions that have been created by the wrapper.
            connectPort(KIND_IN_WRAPPED_COMPONENT_Master, "amba_pv_signal_m", amba_pv_signal_m);
            connectPort(KIND_IN_WRAPPED_COMPONENT_Slave, "sg_signal_s", sg_signal_s);


            ; // fixup indentation in template file.
        }

        Component__SGSignal2AMBAPVSignal::~Component__SGSignal2AMBAPVSignal()
        {
            ; // do nothing
        }
    }
    
    // This is a list of the properties of the component of the form:
    //    { "propertyA", "valueA" }, {"propertyB", "valueB"}, ... , {nullptr, nullptr}
    static SystemGenComponent::property_value_pair_t const Component__SGSignal2AMBAPVSignal_properties_201705121426_[] = {
	{ "component_name", "SGSignal2AMBAPVSignal", 0 },
	{ "component_type", "Bridge", 0 },
	{ "debugger_name", "", 0 },
	{ "debugger_start_command", "", 0 },
	{ "default_view", "auto", 0 },
	{ "deprecated", "0", 0 },
	{ "description", "SystemGenerator Signal to AMBA-PV Signal protocol converter.", 0 },
	{ "documentation_file", "../#DUI0834#", 0 },
	{ "dso_safe", "0", 0 },
	{ "executes_software", "0", 0 },
	{ "expose_extern_sub_component_cadi", "1", 0 },
	{ "factory_namespace", "", 0 },
	{ "has_cadi", "0", 0 },
	{ "has_implicit_clk_in", "1", 0 },
	{ "hidden", "0", 0 },
	{ "hwversion", "", 0 },
	{ "icon_file", "", 0 },
	{ "ip_provider", "", 0 },
	{ "is_single_stepped", "0", 0 },
	{ "license_feature", "", 0 },
	{ "loadfile_extension", "", 0 },
	{ "mtdomains", "", 0 },
	{ "mtdomains_tool_config", "", 0 },
	{ "package", "", 0 },
	{ "resources_are_public", "0", 0 },
	{ "small_icon_file", "", 0 },
	{ "variant", "", 0 },
	{ "version", "11.10.22", 0 },

        { nullptr, nullptr, 0 }
    };

Component__SGSignal2AMBAPVSignal::Component__SGSignal2AMBAPVSignal(const char * instName, sg::SimulationContext* simulationContext, const sg::Params & params):
    SystemGenComponent(instName, simulationContext, params, Component__SGSignal2AMBAPVSignal_properties_201705121426_)




{
    // initialize parameter info
    {
        sg::ComponentFactory *factory = SGSignal2AMBAPVSignal_GetFactory();

        sg::TargetInfo *targetInfo = factory->getTargetInfo(""); // empty string means 'this' component

        if(targetInfo) // if we have no target info we also have no parameters towards CADI interfaces
        {
            // get parameter infos
            for(unsigned int i = 0; i < targetInfo->parameter_count; i++)
            {
                parameterId2parameterName__[targetInfo->parameter_info[i].id] = targetInfo->parameter_info[i].name;
                parameterInfos__.push_back((targetInfo->parameter_info)[i]);
            }
        }

        factory->dereference();
    }

    // bad_params is used by any components for which it needs to do:
    //           params.interpolate("$mtdomain_name", bad_params)
    // for the mtdomain parameter passed to the proxying component.
    //
    // However, we don't actually ever do anything with the result as
    // fillOutMTWrapperConfig__() will report any interpolation errors.
    std::vector< std::pair<std::string, std::string::size_type> > bad_params;
    sg::MTWrapperConfig mtwrapper_config__;
    fillOutMTWrapperConfig__(mtwrapper_config__);
    
    // create subcomponents
    
	{
	}


    // bind local behaviors to this->control_port
    bind_method(control_port, configure, &Component__SGSignal2AMBAPVSignal::control_port__configure, this);
    bind_method(control_port, init, &Component__SGSignal2AMBAPVSignal::control_port__init, this);
    bind_method(control_port, interconnect, &Component__SGSignal2AMBAPVSignal::interconnect, this);
    bind_method(control_port, reset, &Component__SGSignal2AMBAPVSignal::control_port__reset, this);
    bind_method(control_port, loadApplicationFile, &Component__SGSignal2AMBAPVSignal::loadApplicationFile, this);
    bind_method(control_port, serializeState, &Component__SGSignal2AMBAPVSignal::control_port__serializeState, this);
    bind_method(control_port, disconnect, &Component__SGSignal2AMBAPVSignal::disconnect, this);
    bind_method(control_port, terminate, &Component__SGSignal2AMBAPVSignal::control_port__terminate, this);
    bind_method(control_port, populateCADIMap, &Component__SGSignal2AMBAPVSignal::control_port__populateCADIMap, this);
    bind_method(control_port, step, &Component__SGSignal2AMBAPVSignal::step, this);
    bind_method(control_port, getProperty, &Component__SGSignal2AMBAPVSignal::control_port__getProperty, this);
    bind_method(control_port, bypass, &Component__SGSignal2AMBAPVSignal::control_port__bypass, this);
    bind_method(control_port, run, &Component__SGSignal2AMBAPVSignal::control_port__run, this);
    bind_method(control_port, stop, &Component__SGSignal2AMBAPVSignal::control_port__stop, this);
    bind_method(control_port, idle, &Component__SGSignal2AMBAPVSignal::control_port__idle, this);
    bind_method(control_port, quit, &Component__SGSignal2AMBAPVSignal::control_port__quit, this);
    bind_method(control_port, setSimulationEngine, &Component__SGSignal2AMBAPVSignal::control_port__setSimulationEngine, this);
    bind_method(control_port, message, &Component__SGSignal2AMBAPVSignal::control_port__message, this);
    bind_method(control_port, callSimEngine, &Component__SGSignal2AMBAPVSignal::control_port__callSimEngine, this);

    // Avoid the propagation of calls to subcomponents through the framework:
    // if setLocalOnly(true) is not called, any call to an element (connector)
    // of the control port, causes the corresponding behaviours of all
    // subcomponents to be automatically called, too. Whenever we want the
    // LISA programmer to control the propagation of special-purpose behaviours,
    // we need to prevent this to happen.
    control_port.configure.setLocalOnly(true);
    control_port.init.setLocalOnly(true);
    control_port.interconnect.setLocalOnly(true);
    control_port.reset.setLocalOnly(true);
    control_port.loadApplicationFile.setLocalOnly(true);
    control_port.serializeState.setLocalOnly(true);
    control_port.disconnect.setLocalOnly(true);
    control_port.terminate.setLocalOnly(true);
    control_port.populateCADIMap.setLocalOnly(true);
    control_port.step.setLocalOnly(true);
    control_port.getProperty.setLocalOnly(true);
//  control_port.bypass.setLocalOnly(true);
//  control_port.run.setLocalOnly(true);
//  control_port.stop.setLocalOnly(true);
//  control_port.idle.setLocalOnly(true); // broadcast ports don't have setLocalOnly
//  control_port.quit.setLocalOnly(true);
//  control_port.setSimulationEngine.setLocalOnly(true);

    // bind cadiPort behaviors
    bind_method(cadiPort__, GetProperty, &Component__SGSignal2AMBAPVSignal::cadiPort__GetProperty, this);
    bind_method(cadiPort__, LoadApplicationFile, &Component__SGSignal2AMBAPVSignal::cadiPort__LoadApplicationFile, this);
    bind_method(cadiPort__, GetApplicationsAndCommandLineParams, &Component__SGSignal2AMBAPVSignal::cadiPort__GetApplicationsAndCommandLineParams, this);

    // connect control ports for subcomponents to subcomponents
    connect_controlports__();

    // resource initialization code
    reset_resources__();

    // bind behaviors to abstract ports
	bind_method(sg_signal_s, setValue, &Component__SGSignal2AMBAPVSignal::abstract_port__sg_signal_s__setValue, this);


    // add abstract ports
    add_abstractports__();

    // wire up static connection map
    wire_connectionmap__();

    // init profiling

    // init resources


    // run the parameter write access functions for all of the component's parameters
    for (size_t i = 0; i < parameterInfos__.size(); ++i)
    {
        std::string paramName = parameterInfos__[i].name;

        switch (parameterInfos__[i].dataType)
        {
        case eslapi::CADI_PARAM_STRING:
            {
                std::string data = GetParameterValue(params, paramName, parameterInfos__[i].defaultString);
                parameter_write_string_func(paramNameToParamAccessFuncID(paramName), data);
            }
            break;
        case eslapi::CADI_PARAM_BOOL:
            {
                bool default_val = string2bool(parameterInfos__[i].defaultString);
                int64_t data = static_cast<int64_t>(GetParameterValue(params, paramName, default_val));
                parameter_write_func(paramNameToParamAccessFuncID(paramName), &data);
            }
            break;
        case eslapi::CADI_PARAM_INT:
            {
                int64_t data = GetParameterValue(params, paramName, parameterInfos__[i].defaultValue, parameterInfos__[i].minValue, parameterInfos__[i].maxValue);
                parameter_write_func(paramNameToParamAccessFuncID(paramName), &data);
            }
            break;
        default:
            break;
        }
    }
}


Component__SGSignal2AMBAPVSignal::~Component__SGSignal2AMBAPVSignal()
{
}

void Component__SGSignal2AMBAPVSignal::control_port__serializeState(const char *name, cp::SerializationInterface* stream)
{
    serializeState(name, stream);
}

void Component__SGSignal2AMBAPVSignal::control_port__configure(const sg::Params& params)
{
    (void)params;



    assert(simulationContext__->getSimulationEngine());
    cadi__ = new Component__SGSignal2AMBAPVSignal_CADI(this, simulationContext__->getSimulationEngine());
    buildDebugInfoWithMetaData__();

    // forward certain calls from CADI interface to this component
    cadi__->GetCADIPort().connectTo(cadiPort__);

    

    std::map< std::string, eslapi::CAInterface* > tempMap;
    control_port__populateCADIMap(tempMap, ""); // precompute mxdi map

	cadi__->EnableSubComponentCADIImport();


}

void Component__SGSignal2AMBAPVSignal::control_port__init()
{
    // We assume that the message() part of the control port is now bound
    // correctly.  Thus anything that we have buffered from prior to now can be
    // dumped.
    dontBufferMessages__();
    
    // Call the behavior init()
    init();
}

void Component__SGSignal2AMBAPVSignal::control_port__populateCADIMap(std::map< std::string, eslapi::CAInterface* >&output_map, std::string const & base_prefix)
{
    if (componentName2CADI__.empty())
    {
        componentName2CADI__[getName()] = static_cast<eslapi::CADI*>(cadi__);
        std::string prefix = cadiNamePrefix;


    }
    // Copy the local map into the given map with the requested prefix.
    for (std::map<std::string,eslapi::CAInterface*>::iterator it = componentName2CADI__.begin(); it != componentName2CADI__.end(); ++it)
    {
        output_map.insert(std::make_pair(base_prefix + it->first, it->second));
    }
}

// Turn off optimizations for this function; it is not performance critical as it is only
// generally run once per simulation on startup. Keeping track of the large number of
// variables in some cases causes the comiler to take a lot of time and memory attempting
// to optimize, so we explicitly turn this off.
#ifdef WIN32
# pragma optimize("", off)
#else
# pragma GCC push_options
# pragma GCC optimize ("O0")
#endif
void Component__SGSignal2AMBAPVSignal::buildDebugInfoWithMetaData__()
{


    sg::CADIBase::RegInfo regData[] =
    {

        {"ETFR", "ExtendedTargetFeatureRegisterGroup", 0, 0, eslapi::CADI_REGTYPE_STRING, "Extended Target Features", eslapi::CADI_REG_READ_ONLY, 0, 0, 0, true, 0, false, 0, 0, 0, true/*pseudo*/, true, 0xFFFFFFFF, 0, 0, 0, 0, 0xffffffff, 0, 0, false, false, false},
        {0, "", 0, 0, eslapi::CADI_REGTYPE_HEX, 0, eslapi::CADI_REG_READ_WRITE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    // the instance specific data has to be non-static, this is currently only access_data
    // this array is compressed: only registers which have hasInstanceSpecificPointers=true in regData are present here
    sg::CADIBase::RegInfoInstanceSpecific regDataInstanceSpecific[] = {

        {0, 0, 0, 0, MakeDelegate(this, &Component__SGSignal2AMBAPVSignal::GetExtendedTargetFeatures__), 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    sg::CADIBase::ParamInfo paramData[] =
    {

        { 0, 0, 0, 0, 0 }
    };

    buildDebugInfo__(regData, (sizeof(regData) / sizeof( regData[0])) - 1,
                     regDataInstanceSpecific, sizeof(regDataInstanceSpecific) / sizeof( regDataInstanceSpecific[0]),
                     paramData, sizeof(paramData) / sizeof(paramData[0]));
}
// Restore optimization.
#ifdef WIN32
# pragma optimize("", on)
#else
# pragma GCC pop_options
#endif

sg::accessfunc::AccessFuncResult
Component__SGSignal2AMBAPVSignal::GetExtendedTargetFeatures__(uint32_t /*id*/, std::string &data, bool /*se*/)
{
    data = getExtendedTargetFeatures();
    return sg::accessfunc::ACCESS_FUNC_OK;
}

eslapi::CADI* Component__SGSignal2AMBAPVSignal::obtainCADI__(const std::string &subcomp, const std::map< std::string, eslapi::CAInterface* > &componentName2CADI) const
{
    std::map< std::string, eslapi::CAInterface* >::const_iterator it = componentName2CADI.find(subcomp);
    if (it != componentName2CADI.end())
    {
        eslapi::CAInterface *cai = it->second;
        if (cai != NULL)
        {
            cai = cai->ObtainInterface(eslapi::CADI::IFNAME(), 0, 0);
            if (cai != NULL)
            {
                return static_cast<eslapi::CADI*>(cai);
            }
        }
    }
    return NULL;
}

void Component__SGSignal2AMBAPVSignal::insertCADIMap__(std::string prefix, std::map< std::string, eslapi::CAInterface* > &componentName2CADI)
{
    for (std::map<std::string, eslapi::CAInterface*>::iterator it = componentName2CADI.begin(); it != componentName2CADI.end(); it++)
    {
        // put prefix in front of all entries
        componentName2CADI__[prefix + it->first] = it->second;
    }
}


std::string Component__SGSignal2AMBAPVSignal::control_port__getProperty(const std::string& propname)
{
    if(properties__.find(propname) != properties__.end())
    {
        return properties__[propname];
    }
    else
        return ""; // unknown property
}

std::string Component__SGSignal2AMBAPVSignal::control_port__bypass(const std::string&)
{
    return "";
}

void Component__SGSignal2AMBAPVSignal::control_port__run()
{
}


void Component__SGSignal2AMBAPVSignal::control_port__stop()
{
}


void Component__SGSignal2AMBAPVSignal::control_port__idle()
{
}


void Component__SGSignal2AMBAPVSignal::control_port__quit()
{
}


void Component__SGSignal2AMBAPVSignal::control_port__setSimulationEngine(sg::SimulationEngine*)
{
}


void Component__SGSignal2AMBAPVSignal::control_port__message(const std::string &/*msg*/, sg::message::MessageType /*msgType*/)
{
}


std::string Component__SGSignal2AMBAPVSignal::control_port__callSimEngine(const std::string &)
{
    return "";
}


void Component__SGSignal2AMBAPVSignal::control_port__reset(int level)
{
    drainBufferedMessages__();
    if (isShutdownAtReset__())
        message("Shutting down due to prior errors.", MSG_FATAL_ERROR);
    
    (void)level;
    // restore the resources' reset values before executing 'reset'
    reset_resources__();
    reset(level);
}


void Component__SGSignal2AMBAPVSignal::control_port__terminate()
{
    // the CADI was created before 'init', therefore we free it after 'terminate'
    terminate();
    freeCADIResources__();
}


void Component__SGSignal2AMBAPVSignal::freeCADIResources__()
{
    // free CADI parameter proxies


    // free CADI interface
    delete cadi__;
    cadi__ = 0;
}

bool Component__SGSignal2AMBAPVSignal::ForwardParameterValueToSubcomponent(CADIParameterProxy *proxy, const char *param_name, int64_t intVal, const char *strVal)
{
    if (!proxy)
        return false;

    // we need the parameter's CADI id in order to create an eslapi::CADIParameterValue_t structure
    // therefore, we first retrieve its eslapi::CADIParameterInfo_t meta-data
    eslapi::CADIParameterInfo_t paramInfo;
    if (proxy->CADIGetParameterInfo(param_name, &paramInfo) != eslapi::CADI_STATUS_OK)
        return false;

    eslapi::CADIParameterValue_t paramVal(paramInfo.id, paramInfo.dataType, intVal, strVal);
    eslapi::CADIFactoryErrorMessage_t error;
    if (proxy->CADISetParameters(1, &paramVal, &error) != eslapi::CADI_STATUS_OK)
        return false;

    return true;
}


sg::accessfunc::AccessFuncResult Component__SGSignal2AMBAPVSignal::parameter_read_func(uint32_t id, int64_t *data)
{
    if (data == 0)
        return eslapi::CADI_STATUS_IllegalArgument;

    switch (id)
    {

        default:
            printf("error: Component__SGSignal2AMBAPVSignal::parameter_read_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__SGSignal2AMBAPVSignal::parameter_read_string_func(uint32_t id, std::string &data)
{
    (void)data;
    switch (id)
    {

        default:
            printf("error: Component__SGSignal2AMBAPVSignal::parameter_read_string_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__SGSignal2AMBAPVSignal::parameter_write_func(uint32_t id, const int64_t *data)
{
    if (data == 0)
        return eslapi::CADI_STATUS_IllegalArgument;

    switch (id)
    {

        default:
            printf("error: Component__SGSignal2AMBAPVSignal::parameter_write_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__SGSignal2AMBAPVSignal::parameter_write_string_func(uint32_t id, const std::string &data)
{
    (void)data;
    switch (id)
    {

        default:
            printf("error: Component__SGSignal2AMBAPVSignal::parameter_write_string_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

void Component__SGSignal2AMBAPVSignal::cadiPort__LoadApplicationFile(const std::string& filename)
{
    loadApplicationFile(filename);
    applications2params[filename] = "";
}

void Component__SGSignal2AMBAPVSignal::cadiPort__GetApplicationsAndCommandLineParams(std::map<std::string, std::string>&applications2params_)
{
    applications2params_ = applications2params;
}

eslapi::CADIReturn_t Component__SGSignal2AMBAPVSignal::cadiPort__GetProperty(const std::string& propertyName, std::string &value)
{
    if(properties__.find(propertyName) != properties__.end())
    {
        value = properties__[propertyName];
        return eslapi::CADI_STATUS_OK;
    }
    else
    {
        value = "";
        return eslapi::CADI_STATUS_GeneralError;
    }
}

// functions to stop and lock the simulator
// we only expose the simHalt() function in the documentation for the moment

void Component__SGSignal2AMBAPVSignal::simHalt()
{
    cadi__->StopSimulation();
}


// start simulation from the inside
// (useful from visualisation components which can execute code while the
// simulation is stopped, like key events)
void Component__SGSignal2AMBAPVSignal::simRun()
{
    cadi__->CADIExecContinue();
}


// return true if simulation is running
// (useful from visualisation components which can execute code while the
// simulation is stopped, like key events)
bool Component__SGSignal2AMBAPVSignal::simIsRunning()
{
    uint32_t mode = eslapi::CADI_EXECMODE_Stop;
    cadi__->CADIExecGetMode(&mode);
    return mode != eslapi::CADI_EXECMODE_Stop;
}


void Component__SGSignal2AMBAPVSignal::simShutdown()
{
    cadiPort__.simShutdown();
}

void Component__SGSignal2AMBAPVSignal::simReset(uint32_t level)
{
    cadi__->CADIExecReset(level);
}

uint32_t Component__SGSignal2AMBAPVSignal::paramNameToParamAccessFuncID(const std::string &name)
{
    uint32_t id = 0;
    if (name == "") id = 0xffffffff;

    return id;
}

void Component__SGSignal2AMBAPVSignal::reset_resources__()
{
    // resource initialization code

}

void Component__SGSignal2AMBAPVSignal::connect_controlports__()
{
    typedef struct {
        sg::Port * local_cport_name;
        sg::ComponentBase * local_instance_name;
        const char * cport_name;
    } connection_map_t;


    connection_map_t cmap[] = {
    { 0, 0, 0 },
    };


    for(unsigned int i=0; cmap[i].local_cport_name != 0; i++) {
        connection_map_t c = cmap[i];
        c.local_cport_name->connectTo(c.local_instance_name->findPort(c.cport_name));
    }


    // #CONNECT_CONTROLPORTS_TO_SUBCOMPONENTS#
}

void Component__SGSignal2AMBAPVSignal::add_abstractports__0__()
{
	publishMasterPort("amba_pv_signal_m", amba_pv_signal_m);
	amba_pv_signal_m.SetName__("amba_pv_signal_m");
	publishSlavePort("sg_signal_s", sg_signal_s);
	sg_signal_s.SetName__("sg_signal_s");
}



void Component__SGSignal2AMBAPVSignal::add_abstractports__()
{
	add_abstractports__0__();

}



void Component__SGSignal2AMBAPVSignal::wire_connectionmap__()
{

}


} // DMA_NMS
#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPVSignal2SGSignal.lisa"
namespace DMA_NMS { void 
Component__AMBAPVSignal2SGSignal::interconnect()
{;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPVSignal2SGSignal.lisa"
namespace DMA_NMS { void 
Component__AMBAPVSignal2SGSignal::disconnect()
{;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPVSignal2SGSignal.lisa"
namespace DMA_NMS { void 
Component__AMBAPVSignal2SGSignal::loadApplicationFile(const std::string& filename)
{;(void)filename;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPVSignal2SGSignal.lisa"
namespace DMA_NMS { void 
Component__AMBAPVSignal2SGSignal::init()
{;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPVSignal2SGSignal.lisa"
namespace DMA_NMS { void 
Component__AMBAPVSignal2SGSignal::terminate()
{;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPVSignal2SGSignal.lisa"
namespace DMA_NMS { void 
Component__AMBAPVSignal2SGSignal::reset(int level)
{;(void)level;
}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPVSignal2SGSignal.lisa"
namespace DMA_NMS { void 
Component__AMBAPVSignal2SGSignal::reset(int level, int /*argc*/, char** /*argv*/)
{
	reset(level);

}
}

#line 16 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPVSignal2SGSignal.lisa"
namespace DMA_NMS { void 
Component__AMBAPVSignal2SGSignal::step()
{;
}
}

#line 40 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/AMBAPVSignal2SGSignal.lisa"
namespace DMA_NMS { void 
Component__AMBAPVSignal2SGSignal::abstract_port__amba_pv_signal_s__set_state(int export_id, const bool& state)
{
 if (state) {
 sg_signal_m.setValue(sg::Signal::Set);
 } else {
 sg_signal_m.setValue(sg::Signal::Clear);
 }
 
}
}

#line 4072 "./Linux64-Release-GCC-7.3/gen/Comp_NonDSO_1.cpp"

// ------------------------------------------------------------------------------
// implementation of class Component__AMBAPVSignal2SGSignal
// ------------------------------------------------------------------------------

namespace DMA_NMS {


    namespace MT
    {
        Component__AMBAPVSignal2SGSignal::Component__AMBAPVSignal2SGSignal(
            sg::ComponentFactory*      factory,
            sg::MTWrapperConfig const& wrapper_config,
            std::string const&         mtdomain_name,
            std::string const&         instName,
            sg::SimulationContext*     simulationContext,
            sg::Params const&          params
            )
        {
        
            // what this creates is a component where 
            auto result = MTComponentWrapper(
                factory, wrapper_config, mtdomain_name, instName, simulationContext, params
                );
            mtdomain_id   = result.mtdomain_id;
            raw_component = dynamic_cast<wrapped_type*>(result.raw_component);
            setComponentBase(result.wrapper_component);

            // Forward the ports in the publicly visible part of the class to the
            // versions that have been created by the wrapper.
            connectPort(KIND_IN_WRAPPED_COMPONENT_Master, "sg_signal_m", sg_signal_m);
            connectPort(KIND_IN_WRAPPED_COMPONENT_Slave, "amba_pv_signal_s", amba_pv_signal_s);


            ; // fixup indentation in template file.
        }

        Component__AMBAPVSignal2SGSignal::~Component__AMBAPVSignal2SGSignal()
        {
            ; // do nothing
        }
    }
    
    // This is a list of the properties of the component of the form:
    //    { "propertyA", "valueA" }, {"propertyB", "valueB"}, ... , {nullptr, nullptr}
    static SystemGenComponent::property_value_pair_t const Component__AMBAPVSignal2SGSignal_properties_201705121426_[] = {
	{ "component_name", "AMBAPVSignal2SGSignal", 0 },
	{ "component_type", "Bridge", 0 },
	{ "debugger_name", "", 0 },
	{ "debugger_start_command", "", 0 },
	{ "default_view", "auto", 0 },
	{ "deprecated", "0", 0 },
	{ "description", "AMBA-PV Signal to SystemGenerator Signal protocol converter.", 0 },
	{ "documentation_file", "../#DUI0834#", 0 },
	{ "dso_safe", "0", 0 },
	{ "executes_software", "0", 0 },
	{ "expose_extern_sub_component_cadi", "1", 0 },
	{ "factory_namespace", "", 0 },
	{ "has_cadi", "0", 0 },
	{ "has_implicit_clk_in", "1", 0 },
	{ "hidden", "0", 0 },
	{ "hwversion", "", 0 },
	{ "icon_file", "", 0 },
	{ "ip_provider", "", 0 },
	{ "is_single_stepped", "0", 0 },
	{ "license_feature", "", 0 },
	{ "loadfile_extension", "", 0 },
	{ "mtdomains", "", 0 },
	{ "mtdomains_tool_config", "", 0 },
	{ "package", "", 0 },
	{ "resources_are_public", "0", 0 },
	{ "small_icon_file", "", 0 },
	{ "variant", "", 0 },
	{ "version", "11.10.22", 0 },

        { nullptr, nullptr, 0 }
    };

Component__AMBAPVSignal2SGSignal::Component__AMBAPVSignal2SGSignal(const char * instName, sg::SimulationContext* simulationContext, const sg::Params & params):
    SystemGenComponent(instName, simulationContext, params, Component__AMBAPVSignal2SGSignal_properties_201705121426_)




{
    // initialize parameter info
    {
        sg::ComponentFactory *factory = AMBAPVSignal2SGSignal_GetFactory();

        sg::TargetInfo *targetInfo = factory->getTargetInfo(""); // empty string means 'this' component

        if(targetInfo) // if we have no target info we also have no parameters towards CADI interfaces
        {
            // get parameter infos
            for(unsigned int i = 0; i < targetInfo->parameter_count; i++)
            {
                parameterId2parameterName__[targetInfo->parameter_info[i].id] = targetInfo->parameter_info[i].name;
                parameterInfos__.push_back((targetInfo->parameter_info)[i]);
            }
        }

        factory->dereference();
    }

    // bad_params is used by any components for which it needs to do:
    //           params.interpolate("$mtdomain_name", bad_params)
    // for the mtdomain parameter passed to the proxying component.
    //
    // However, we don't actually ever do anything with the result as
    // fillOutMTWrapperConfig__() will report any interpolation errors.
    std::vector< std::pair<std::string, std::string::size_type> > bad_params;
    sg::MTWrapperConfig mtwrapper_config__;
    fillOutMTWrapperConfig__(mtwrapper_config__);
    
    // create subcomponents
    
	{
	}


    // bind local behaviors to this->control_port
    bind_method(control_port, configure, &Component__AMBAPVSignal2SGSignal::control_port__configure, this);
    bind_method(control_port, init, &Component__AMBAPVSignal2SGSignal::control_port__init, this);
    bind_method(control_port, interconnect, &Component__AMBAPVSignal2SGSignal::interconnect, this);
    bind_method(control_port, reset, &Component__AMBAPVSignal2SGSignal::control_port__reset, this);
    bind_method(control_port, loadApplicationFile, &Component__AMBAPVSignal2SGSignal::loadApplicationFile, this);
    bind_method(control_port, serializeState, &Component__AMBAPVSignal2SGSignal::control_port__serializeState, this);
    bind_method(control_port, disconnect, &Component__AMBAPVSignal2SGSignal::disconnect, this);
    bind_method(control_port, terminate, &Component__AMBAPVSignal2SGSignal::control_port__terminate, this);
    bind_method(control_port, populateCADIMap, &Component__AMBAPVSignal2SGSignal::control_port__populateCADIMap, this);
    bind_method(control_port, step, &Component__AMBAPVSignal2SGSignal::step, this);
    bind_method(control_port, getProperty, &Component__AMBAPVSignal2SGSignal::control_port__getProperty, this);
    bind_method(control_port, bypass, &Component__AMBAPVSignal2SGSignal::control_port__bypass, this);
    bind_method(control_port, run, &Component__AMBAPVSignal2SGSignal::control_port__run, this);
    bind_method(control_port, stop, &Component__AMBAPVSignal2SGSignal::control_port__stop, this);
    bind_method(control_port, idle, &Component__AMBAPVSignal2SGSignal::control_port__idle, this);
    bind_method(control_port, quit, &Component__AMBAPVSignal2SGSignal::control_port__quit, this);
    bind_method(control_port, setSimulationEngine, &Component__AMBAPVSignal2SGSignal::control_port__setSimulationEngine, this);
    bind_method(control_port, message, &Component__AMBAPVSignal2SGSignal::control_port__message, this);
    bind_method(control_port, callSimEngine, &Component__AMBAPVSignal2SGSignal::control_port__callSimEngine, this);

    // Avoid the propagation of calls to subcomponents through the framework:
    // if setLocalOnly(true) is not called, any call to an element (connector)
    // of the control port, causes the corresponding behaviours of all
    // subcomponents to be automatically called, too. Whenever we want the
    // LISA programmer to control the propagation of special-purpose behaviours,
    // we need to prevent this to happen.
    control_port.configure.setLocalOnly(true);
    control_port.init.setLocalOnly(true);
    control_port.interconnect.setLocalOnly(true);
    control_port.reset.setLocalOnly(true);
    control_port.loadApplicationFile.setLocalOnly(true);
    control_port.serializeState.setLocalOnly(true);
    control_port.disconnect.setLocalOnly(true);
    control_port.terminate.setLocalOnly(true);
    control_port.populateCADIMap.setLocalOnly(true);
    control_port.step.setLocalOnly(true);
    control_port.getProperty.setLocalOnly(true);
//  control_port.bypass.setLocalOnly(true);
//  control_port.run.setLocalOnly(true);
//  control_port.stop.setLocalOnly(true);
//  control_port.idle.setLocalOnly(true); // broadcast ports don't have setLocalOnly
//  control_port.quit.setLocalOnly(true);
//  control_port.setSimulationEngine.setLocalOnly(true);

    // bind cadiPort behaviors
    bind_method(cadiPort__, GetProperty, &Component__AMBAPVSignal2SGSignal::cadiPort__GetProperty, this);
    bind_method(cadiPort__, LoadApplicationFile, &Component__AMBAPVSignal2SGSignal::cadiPort__LoadApplicationFile, this);
    bind_method(cadiPort__, GetApplicationsAndCommandLineParams, &Component__AMBAPVSignal2SGSignal::cadiPort__GetApplicationsAndCommandLineParams, this);

    // connect control ports for subcomponents to subcomponents
    connect_controlports__();

    // resource initialization code
    reset_resources__();

    // bind behaviors to abstract ports
	bind_method(amba_pv_signal_s, set_state, &Component__AMBAPVSignal2SGSignal::abstract_port__amba_pv_signal_s__set_state, this);


    // add abstract ports
    add_abstractports__();

    // wire up static connection map
    wire_connectionmap__();

    // init profiling

    // init resources


    // run the parameter write access functions for all of the component's parameters
    for (size_t i = 0; i < parameterInfos__.size(); ++i)
    {
        std::string paramName = parameterInfos__[i].name;

        switch (parameterInfos__[i].dataType)
        {
        case eslapi::CADI_PARAM_STRING:
            {
                std::string data = GetParameterValue(params, paramName, parameterInfos__[i].defaultString);
                parameter_write_string_func(paramNameToParamAccessFuncID(paramName), data);
            }
            break;
        case eslapi::CADI_PARAM_BOOL:
            {
                bool default_val = string2bool(parameterInfos__[i].defaultString);
                int64_t data = static_cast<int64_t>(GetParameterValue(params, paramName, default_val));
                parameter_write_func(paramNameToParamAccessFuncID(paramName), &data);
            }
            break;
        case eslapi::CADI_PARAM_INT:
            {
                int64_t data = GetParameterValue(params, paramName, parameterInfos__[i].defaultValue, parameterInfos__[i].minValue, parameterInfos__[i].maxValue);
                parameter_write_func(paramNameToParamAccessFuncID(paramName), &data);
            }
            break;
        default:
            break;
        }
    }
}


Component__AMBAPVSignal2SGSignal::~Component__AMBAPVSignal2SGSignal()
{
}

void Component__AMBAPVSignal2SGSignal::control_port__serializeState(const char *name, cp::SerializationInterface* stream)
{
    serializeState(name, stream);
}

void Component__AMBAPVSignal2SGSignal::control_port__configure(const sg::Params& params)
{
    (void)params;



    assert(simulationContext__->getSimulationEngine());
    cadi__ = new Component__AMBAPVSignal2SGSignal_CADI(this, simulationContext__->getSimulationEngine());
    buildDebugInfoWithMetaData__();

    // forward certain calls from CADI interface to this component
    cadi__->GetCADIPort().connectTo(cadiPort__);

    

    std::map< std::string, eslapi::CAInterface* > tempMap;
    control_port__populateCADIMap(tempMap, ""); // precompute mxdi map

	cadi__->EnableSubComponentCADIImport();


}

void Component__AMBAPVSignal2SGSignal::control_port__init()
{
    // We assume that the message() part of the control port is now bound
    // correctly.  Thus anything that we have buffered from prior to now can be
    // dumped.
    dontBufferMessages__();
    
    // Call the behavior init()
    init();
}

void Component__AMBAPVSignal2SGSignal::control_port__populateCADIMap(std::map< std::string, eslapi::CAInterface* >&output_map, std::string const & base_prefix)
{
    if (componentName2CADI__.empty())
    {
        componentName2CADI__[getName()] = static_cast<eslapi::CADI*>(cadi__);
        std::string prefix = cadiNamePrefix;


    }
    // Copy the local map into the given map with the requested prefix.
    for (std::map<std::string,eslapi::CAInterface*>::iterator it = componentName2CADI__.begin(); it != componentName2CADI__.end(); ++it)
    {
        output_map.insert(std::make_pair(base_prefix + it->first, it->second));
    }
}

// Turn off optimizations for this function; it is not performance critical as it is only
// generally run once per simulation on startup. Keeping track of the large number of
// variables in some cases causes the comiler to take a lot of time and memory attempting
// to optimize, so we explicitly turn this off.
#ifdef WIN32
# pragma optimize("", off)
#else
# pragma GCC push_options
# pragma GCC optimize ("O0")
#endif
void Component__AMBAPVSignal2SGSignal::buildDebugInfoWithMetaData__()
{


    sg::CADIBase::RegInfo regData[] =
    {

        {"ETFR", "ExtendedTargetFeatureRegisterGroup", 0, 0, eslapi::CADI_REGTYPE_STRING, "Extended Target Features", eslapi::CADI_REG_READ_ONLY, 0, 0, 0, true, 0, false, 0, 0, 0, true/*pseudo*/, true, 0xFFFFFFFF, 0, 0, 0, 0, 0xffffffff, 0, 0, false, false, false},
        {0, "", 0, 0, eslapi::CADI_REGTYPE_HEX, 0, eslapi::CADI_REG_READ_WRITE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    // the instance specific data has to be non-static, this is currently only access_data
    // this array is compressed: only registers which have hasInstanceSpecificPointers=true in regData are present here
    sg::CADIBase::RegInfoInstanceSpecific regDataInstanceSpecific[] = {

        {0, 0, 0, 0, MakeDelegate(this, &Component__AMBAPVSignal2SGSignal::GetExtendedTargetFeatures__), 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    sg::CADIBase::ParamInfo paramData[] =
    {

        { 0, 0, 0, 0, 0 }
    };

    buildDebugInfo__(regData, (sizeof(regData) / sizeof( regData[0])) - 1,
                     regDataInstanceSpecific, sizeof(regDataInstanceSpecific) / sizeof( regDataInstanceSpecific[0]),
                     paramData, sizeof(paramData) / sizeof(paramData[0]));
}
// Restore optimization.
#ifdef WIN32
# pragma optimize("", on)
#else
# pragma GCC pop_options
#endif

sg::accessfunc::AccessFuncResult
Component__AMBAPVSignal2SGSignal::GetExtendedTargetFeatures__(uint32_t /*id*/, std::string &data, bool /*se*/)
{
    data = getExtendedTargetFeatures();
    return sg::accessfunc::ACCESS_FUNC_OK;
}

eslapi::CADI* Component__AMBAPVSignal2SGSignal::obtainCADI__(const std::string &subcomp, const std::map< std::string, eslapi::CAInterface* > &componentName2CADI) const
{
    std::map< std::string, eslapi::CAInterface* >::const_iterator it = componentName2CADI.find(subcomp);
    if (it != componentName2CADI.end())
    {
        eslapi::CAInterface *cai = it->second;
        if (cai != NULL)
        {
            cai = cai->ObtainInterface(eslapi::CADI::IFNAME(), 0, 0);
            if (cai != NULL)
            {
                return static_cast<eslapi::CADI*>(cai);
            }
        }
    }
    return NULL;
}

void Component__AMBAPVSignal2SGSignal::insertCADIMap__(std::string prefix, std::map< std::string, eslapi::CAInterface* > &componentName2CADI)
{
    for (std::map<std::string, eslapi::CAInterface*>::iterator it = componentName2CADI.begin(); it != componentName2CADI.end(); it++)
    {
        // put prefix in front of all entries
        componentName2CADI__[prefix + it->first] = it->second;
    }
}


std::string Component__AMBAPVSignal2SGSignal::control_port__getProperty(const std::string& propname)
{
    if(properties__.find(propname) != properties__.end())
    {
        return properties__[propname];
    }
    else
        return ""; // unknown property
}

std::string Component__AMBAPVSignal2SGSignal::control_port__bypass(const std::string&)
{
    return "";
}

void Component__AMBAPVSignal2SGSignal::control_port__run()
{
}


void Component__AMBAPVSignal2SGSignal::control_port__stop()
{
}


void Component__AMBAPVSignal2SGSignal::control_port__idle()
{
}


void Component__AMBAPVSignal2SGSignal::control_port__quit()
{
}


void Component__AMBAPVSignal2SGSignal::control_port__setSimulationEngine(sg::SimulationEngine*)
{
}


void Component__AMBAPVSignal2SGSignal::control_port__message(const std::string &/*msg*/, sg::message::MessageType /*msgType*/)
{
}


std::string Component__AMBAPVSignal2SGSignal::control_port__callSimEngine(const std::string &)
{
    return "";
}


void Component__AMBAPVSignal2SGSignal::control_port__reset(int level)
{
    drainBufferedMessages__();
    if (isShutdownAtReset__())
        message("Shutting down due to prior errors.", MSG_FATAL_ERROR);
    
    (void)level;
    // restore the resources' reset values before executing 'reset'
    reset_resources__();
    reset(level);
}


void Component__AMBAPVSignal2SGSignal::control_port__terminate()
{
    // the CADI was created before 'init', therefore we free it after 'terminate'
    terminate();
    freeCADIResources__();
}


void Component__AMBAPVSignal2SGSignal::freeCADIResources__()
{
    // free CADI parameter proxies


    // free CADI interface
    delete cadi__;
    cadi__ = 0;
}

bool Component__AMBAPVSignal2SGSignal::ForwardParameterValueToSubcomponent(CADIParameterProxy *proxy, const char *param_name, int64_t intVal, const char *strVal)
{
    if (!proxy)
        return false;

    // we need the parameter's CADI id in order to create an eslapi::CADIParameterValue_t structure
    // therefore, we first retrieve its eslapi::CADIParameterInfo_t meta-data
    eslapi::CADIParameterInfo_t paramInfo;
    if (proxy->CADIGetParameterInfo(param_name, &paramInfo) != eslapi::CADI_STATUS_OK)
        return false;

    eslapi::CADIParameterValue_t paramVal(paramInfo.id, paramInfo.dataType, intVal, strVal);
    eslapi::CADIFactoryErrorMessage_t error;
    if (proxy->CADISetParameters(1, &paramVal, &error) != eslapi::CADI_STATUS_OK)
        return false;

    return true;
}


sg::accessfunc::AccessFuncResult Component__AMBAPVSignal2SGSignal::parameter_read_func(uint32_t id, int64_t *data)
{
    if (data == 0)
        return eslapi::CADI_STATUS_IllegalArgument;

    switch (id)
    {

        default:
            printf("error: Component__AMBAPVSignal2SGSignal::parameter_read_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__AMBAPVSignal2SGSignal::parameter_read_string_func(uint32_t id, std::string &data)
{
    (void)data;
    switch (id)
    {

        default:
            printf("error: Component__AMBAPVSignal2SGSignal::parameter_read_string_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__AMBAPVSignal2SGSignal::parameter_write_func(uint32_t id, const int64_t *data)
{
    if (data == 0)
        return eslapi::CADI_STATUS_IllegalArgument;

    switch (id)
    {

        default:
            printf("error: Component__AMBAPVSignal2SGSignal::parameter_write_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

sg::accessfunc::AccessFuncResult Component__AMBAPVSignal2SGSignal::parameter_write_string_func(uint32_t id, const std::string &data)
{
    (void)data;
    switch (id)
    {

        default:
            printf("error: Component__AMBAPVSignal2SGSignal::parameter_write_string_func: undefined parameter id '0x%08x'\n", id);
            return sg::accessfunc::ACCESS_FUNC_GeneralError;
    }

    return sg::accessfunc::ACCESS_FUNC_OK;
}

void Component__AMBAPVSignal2SGSignal::cadiPort__LoadApplicationFile(const std::string& filename)
{
    loadApplicationFile(filename);
    applications2params[filename] = "";
}

void Component__AMBAPVSignal2SGSignal::cadiPort__GetApplicationsAndCommandLineParams(std::map<std::string, std::string>&applications2params_)
{
    applications2params_ = applications2params;
}

eslapi::CADIReturn_t Component__AMBAPVSignal2SGSignal::cadiPort__GetProperty(const std::string& propertyName, std::string &value)
{
    if(properties__.find(propertyName) != properties__.end())
    {
        value = properties__[propertyName];
        return eslapi::CADI_STATUS_OK;
    }
    else
    {
        value = "";
        return eslapi::CADI_STATUS_GeneralError;
    }
}

// functions to stop and lock the simulator
// we only expose the simHalt() function in the documentation for the moment

void Component__AMBAPVSignal2SGSignal::simHalt()
{
    cadi__->StopSimulation();
}


// start simulation from the inside
// (useful from visualisation components which can execute code while the
// simulation is stopped, like key events)
void Component__AMBAPVSignal2SGSignal::simRun()
{
    cadi__->CADIExecContinue();
}


// return true if simulation is running
// (useful from visualisation components which can execute code while the
// simulation is stopped, like key events)
bool Component__AMBAPVSignal2SGSignal::simIsRunning()
{
    uint32_t mode = eslapi::CADI_EXECMODE_Stop;
    cadi__->CADIExecGetMode(&mode);
    return mode != eslapi::CADI_EXECMODE_Stop;
}


void Component__AMBAPVSignal2SGSignal::simShutdown()
{
    cadiPort__.simShutdown();
}

void Component__AMBAPVSignal2SGSignal::simReset(uint32_t level)
{
    cadi__->CADIExecReset(level);
}

uint32_t Component__AMBAPVSignal2SGSignal::paramNameToParamAccessFuncID(const std::string &name)
{
    uint32_t id = 0;
    if (name == "") id = 0xffffffff;

    return id;
}

void Component__AMBAPVSignal2SGSignal::reset_resources__()
{
    // resource initialization code

}

void Component__AMBAPVSignal2SGSignal::connect_controlports__()
{
    typedef struct {
        sg::Port * local_cport_name;
        sg::ComponentBase * local_instance_name;
        const char * cport_name;
    } connection_map_t;


    connection_map_t cmap[] = {
    { 0, 0, 0 },
    };


    for(unsigned int i=0; cmap[i].local_cport_name != 0; i++) {
        connection_map_t c = cmap[i];
        c.local_cport_name->connectTo(c.local_instance_name->findPort(c.cport_name));
    }


    // #CONNECT_CONTROLPORTS_TO_SUBCOMPONENTS#
}

void Component__AMBAPVSignal2SGSignal::add_abstractports__0__()
{
	publishMasterPort("sg_signal_m", sg_signal_m);
	sg_signal_m.SetName__("sg_signal_m");
	publishSlavePort("amba_pv_signal_s", amba_pv_signal_s);
	amba_pv_signal_s.SetName__("amba_pv_signal_s");
}



void Component__AMBAPVSignal2SGSignal::add_abstractports__()
{
	add_abstractports__0__();

}



void Component__AMBAPVSignal2SGSignal::wire_connectionmap__()
{

}


} // DMA_NMS

#line 4726 "./Linux64-Release-GCC-7.3/gen/Comp_NonDSO_1.cpp"

// This is an anonymous namespace, it effectively declares everything inside it as 'static', e.g. only visible within the .o file it is compiled into
//     without this we get link errors when linking together LISA generated components
namespace
{

class ComponentFactoryBase :
    public sg::BasicComponentFactory
{
protected:
    void publishSubComponent(sg::ComponentFactory *factory,
                             const std::string &prefix,
                             bool publish_all,
                             const ParameterFilter &param_filter);
};

void
ComponentFactoryBase::publishSubComponent(sg::ComponentFactory *factory,
                                          const std::string &prefix,
                                          bool publish_all,
                                          const ParameterFilter &param_filter)
{
    using namespace sg;

    if (param_filter.isEmpty())
    {
        BasicComponentFactory::publishComponent(factory, prefix, publish_all);
    }
    else
    {
        for (unsigned int t = 0; t < factory->getTargetCount(); ++t)
        {
            TargetInfo *info = factory->getTargetInfo(t);

            std::vector<eslapi::CADIParameterInfo_t> my_param_infos;

            param_filter.filter(info->parameter_info, info->parameter_count, info->instance_path, my_param_infos);

            TargetInfo *my_target_info = new TargetInfo;

                        eslapi::CADITargetInfo_t *my_cadi_target_info = new eslapi::CADITargetInfo_t;
                        *my_cadi_target_info = *(info->cadi_target_info); // copy CADI target info
            my_cadi_target_info->numberOfParameters = (uint32_t)my_param_infos.size();
            my_target_info->cadi_target_info = my_cadi_target_info;

            my_target_info->parameter_count = (unsigned)my_param_infos.size();

            // only copy parameters, if there are ones
                        if (my_target_info->parameter_count)
                        {
                                my_target_info->parameter_info = new eslapi::CADIParameterInfo_t[my_target_info->parameter_count];
                                memcpy(const_cast<eslapi::CADIParameterInfo_t *>(my_target_info->parameter_info),
                                           &my_param_infos.front(),
                                           sizeof(eslapi::CADIParameterInfo_t) * my_target_info->parameter_count);
                        }

            my_target_info->instance_path = info->instance_path;

            // Skip any targets that have an instance_path of "".
            if (my_target_info->instance_path.length() > 0)
            {
                // Add the prefix at the start of the instance path.
                std::string new_path = prefix + "." + my_target_info->instance_path;
                publishTarget(*my_target_info, new_path);
            }
            else if (publish_all)
            {
                std::string new_path = prefix;
                publishTarget(*my_target_info, new_path);
            }
            delete my_target_info;
        }
    }
}

}

using namespace DMA_NMS;

// component factory implementation
// ------------------------------------------------------------------------------
// component factory of class DMA
// ------------------------------------------------------------------------------
//


namespace
{

// component factory class
// (this concrete class is never exposed to the outside world)
class DMA_ComponentFactoryClass: public ComponentFactoryBase
{
    bool componentsPublished;
    void lazyPublish(void)
    {

        static eslapi::CADIParameterInfo_t const parameters[] =
        {
            
            eslapi::CADIParameterInfo_t( 0, "", eslapi::CADI_PARAM_BOOL, "", 1, INT64_C(0), INT64_C(-1), 0, "0" )
        };
        
        static eslapi::CADITargetInfo_t const info
        (
            0, /* uint32_t id; (overridden in CADIFactory) */                                                              // used for identification
            "DMA", /* char  targetName[CADI_NAME_SIZE];     */      // name of the target, i.e. the "type", not the instance name
            "", /* char instanceName[CADI_NAME_SIZE]; (overridden in CADIFactory) */    // name of the CADI target instance
            "1.0", /* char        version[CADI_DESCRIPTION]; */           // version string
            "", /* char    description[CADI_DESCRIPTION]; */       // target description
            "System", /* char componentType[CADI_NAME_SIZE]; */       // classification of the target into a user-defined group
            uint32_t((sizeof(parameters) / sizeof(parameters[0])) - 1),         // number of parameters supported
            0, /* bool        executesSoftware; */                            // false = does not execute programs, true = executes software
            false, /* uint32_t     isHardwareModel; */                             // 0 = is software model, 1 = is hardware model
            "", /* char systemName[CADI_NAME_SIZE];  (overridden in CADIFactory) */             // name of the system the target belongs to.
            // Is empty for single-core standalone models.
            0, /* uint32_t systemID; (overridden in CADIFactory) */                                                // system id
            "" /* char  systemDescription[CADI_DESCRIPTION]; (overridden in CADIFactory) */ // description of the system
        );

        // build TargetInfo
        sg::TargetInfo targetInfo;
        targetInfo.cadi_target_info = &info;
        targetInfo.parameter_count = targetInfo.cadi_target_info->numberOfParameters;
        targetInfo.parameter_info = parameters;

        // publish this component's TargetInfo
        publishTarget(targetInfo, "");

        // publish subcomponent TargetInfos
        {
            sg::ComponentFactory *componentFactory = ARMCortexM55CT_GetFactory();
            ComponentFactoryBase::publishComponent(componentFactory, "Core", true);
            componentFactory->dereference();
        }
        {
            sg::ComponentFactory *componentFactory = RAMDevice_GetFactory();
            ComponentFactoryBase::publishSubComponent(componentFactory, "ProgMem", true, ParameterFilter_ProgMem_of_RAMDevice_to_DMA());
            componentFactory->dereference();
        }
        {
            sg::ComponentFactory *componentFactory = RAMDevice_GetFactory();
            ComponentFactoryBase::publishSubComponent(componentFactory, "SrcMem", true, ParameterFilter_SrcMem_of_RAMDevice_to_DMA());
            componentFactory->dereference();
        }
        {
            sg::ComponentFactory *componentFactory = PVBusDecoder_GetFactory();
            ComponentFactoryBase::publishComponent(componentFactory, "PVBus", true);
            componentFactory->dereference();
        }
        {
            sg::ComponentFactory *componentFactory = ClockDivider_GetFactory();
            ComponentFactoryBase::publishSubComponent(componentFactory, "Clock100MHz", true, ParameterFilter_Clock100MHz_of_ClockDivider_to_DMA());
            componentFactory->dereference();
        }
        {
            sg::ComponentFactory *componentFactory = PVBus2AMBAPV_GetFactory();
            ComponentFactoryBase::publishComponent(componentFactory, "AMBAPVBus", true);
            componentFactory->dereference();
        }
        {
            sg::ComponentFactory *componentFactory = AMBAPV2PVBus_GetFactory();
            ComponentFactoryBase::publishSubComponent(componentFactory, "AMBAPVBridge", true, ParameterFilter_AMBAPVBridge_of_AMBAPV2PVBus_to_DMA());
            componentFactory->dereference();
        }
        {
            sg::ComponentFactory *componentFactory = AMBAPVSignal2SGSignal_GetFactory();
            ComponentFactoryBase::publishComponent(componentFactory, "SignalBridge", true);
            componentFactory->dereference();
        }
        {
            sg::ComponentFactory *componentFactory = SGSignal2AMBAPVSignal_GetFactory();
            ComponentFactoryBase::publishComponent(componentFactory, "ReverseBridge", true);
            componentFactory->dereference();
        }
        {
            sg::ComponentFactory *componentFactory = MasterClock_GetFactory();
            ComponentFactoryBase::publishComponent(componentFactory, "Clock1Hz", true);
            componentFactory->dereference();
        }

        componentsPublished = true;
    }
    ~DMA_ComponentFactoryClass()
    {
    }

public:
    DMA_ComponentFactoryClass() {
        componentsPublished = false;
    }

    virtual void dereference() { delete this; }

    virtual sg::ComponentBase *instantiate(std::string const & instance_name,
                                                sg::SimulationContext *simulationContext,
                                                sg::Params const & params)
    {
        return new DMA_NMS::Component__DMA(instance_name.c_str(), simulationContext, params);
    }

    virtual unsigned int getTargetCount()
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetCount();
    }

    virtual sg::TargetInfo * getTargetInfo(unsigned int index)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetInfo(index);
    }

    virtual sg::TargetInfo * getTargetInfo(std::string const & instance_path)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetInfo(instance_path);
    }

    virtual void publishSubComponent(sg::ComponentFactory *factory, const std::string &prefix,
                          bool publish_all, const ParameterFilter &param_filter)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::publishSubComponent(factory, prefix, publish_all, param_filter);
    }

    virtual void publishComponent(sg::ComponentFactory *factory, const std::string &prefix,
                          bool publish_all)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::publishComponent(factory, prefix, publish_all);
    }

};

}

namespace DMA_NMS {

// factory function
// (this is the function which is exposed to the outside world)
sg::ComponentFactory *DMA_GetFactory()
{
        return new DMA_ComponentFactoryClass();
}

} // DMA_NMS
// ------------------------------------------------------------------------------
// component factory of class AMBAPV2PVBus
// ------------------------------------------------------------------------------
//


namespace
{

// component factory class
// (this concrete class is never exposed to the outside world)
class AMBAPV2PVBus_ComponentFactoryClass: public ComponentFactoryBase
{
    bool componentsPublished;
    void lazyPublish(void)
    {

        static eslapi::CADIParameterInfo_t const parameters[] =
        {
                    eslapi::CADIParameterInfo_t(0x10000002, "base_addr",eslapi::CADI_PARAM_INT, "Base address",0,INT64_C(0x8000000000000000),INT64_C(0x7fffffffffffffff),INT64_C(0x0), "0x0" ),
        eslapi::CADIParameterInfo_t(0x10000003, "shareable",eslapi::CADI_PARAM_BOOL, "Shareable default",0,INT64_C(0x8000000000000000),INT64_C(0x7fffffffffffffff),INT64_C(0x1), "true" ),

            eslapi::CADIParameterInfo_t( 0, "", eslapi::CADI_PARAM_BOOL, "", 1, INT64_C(0), INT64_C(-1), 0, "0" )
        };
        
        static eslapi::CADITargetInfo_t const info
        (
            0, /* uint32_t id; (overridden in CADIFactory) */                                                              // used for identification
            "AMBAPV2PVBus", /* char  targetName[CADI_NAME_SIZE];     */      // name of the target, i.e. the "type", not the instance name
            "", /* char instanceName[CADI_NAME_SIZE]; (overridden in CADIFactory) */    // name of the CADI target instance
            "11.10.22", /* char        version[CADI_DESCRIPTION]; */           // version string
            "AMBA-PV to PVBus protocol converter.", /* char    description[CADI_DESCRIPTION]; */       // target description
            "Bridge", /* char componentType[CADI_NAME_SIZE]; */       // classification of the target into a user-defined group
            uint32_t((sizeof(parameters) / sizeof(parameters[0])) - 1),         // number of parameters supported
            0, /* bool        executesSoftware; */                            // false = does not execute programs, true = executes software
            false, /* uint32_t     isHardwareModel; */                             // 0 = is software model, 1 = is hardware model
            "", /* char systemName[CADI_NAME_SIZE];  (overridden in CADIFactory) */             // name of the system the target belongs to.
            // Is empty for single-core standalone models.
            0, /* uint32_t systemID; (overridden in CADIFactory) */                                                // system id
            "" /* char  systemDescription[CADI_DESCRIPTION]; (overridden in CADIFactory) */ // description of the system
        );

        // build TargetInfo
        sg::TargetInfo targetInfo;
        targetInfo.cadi_target_info = &info;
        targetInfo.parameter_count = targetInfo.cadi_target_info->numberOfParameters;
        targetInfo.parameter_info = parameters;

        // publish this component's TargetInfo
        publishTarget(targetInfo, "");

        // publish subcomponent TargetInfos
        {
            sg::ComponentFactory *componentFactory = PVBusMaster_GetFactory();
            ComponentFactoryBase::publishComponent(componentFactory, "bus_master", true);
            componentFactory->dereference();
        }

        componentsPublished = true;
    }
    ~AMBAPV2PVBus_ComponentFactoryClass()
    {
    }

public:
    AMBAPV2PVBus_ComponentFactoryClass() {
        componentsPublished = false;
    }

    virtual void dereference() { delete this; }

    virtual sg::ComponentBase *instantiate(std::string const & instance_name,
                                                sg::SimulationContext *simulationContext,
                                                sg::Params const & params)
    {
        return new DMA_NMS::Component__AMBAPV2PVBus(instance_name.c_str(), simulationContext, params);
    }

    virtual unsigned int getTargetCount()
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetCount();
    }

    virtual sg::TargetInfo * getTargetInfo(unsigned int index)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetInfo(index);
    }

    virtual sg::TargetInfo * getTargetInfo(std::string const & instance_path)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetInfo(instance_path);
    }

    virtual void publishSubComponent(sg::ComponentFactory *factory, const std::string &prefix,
                          bool publish_all, const ParameterFilter &param_filter)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::publishSubComponent(factory, prefix, publish_all, param_filter);
    }

    virtual void publishComponent(sg::ComponentFactory *factory, const std::string &prefix,
                          bool publish_all)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::publishComponent(factory, prefix, publish_all);
    }

};

}

namespace DMA_NMS {

// factory function
// (this is the function which is exposed to the outside world)
sg::ComponentFactory *AMBAPV2PVBus_GetFactory()
{
        return new AMBAPV2PVBus_ComponentFactoryClass();
}

} // DMA_NMS
// ------------------------------------------------------------------------------
// component factory of class PVBus2AMBAPV
// ------------------------------------------------------------------------------
//


namespace
{

// component factory class
// (this concrete class is never exposed to the outside world)
class PVBus2AMBAPV_ComponentFactoryClass: public ComponentFactoryBase
{
    bool componentsPublished;
    void lazyPublish(void)
    {

        static eslapi::CADIParameterInfo_t const parameters[] =
        {
                    eslapi::CADIParameterInfo_t(0x10000004, "size",eslapi::CADI_PARAM_INT, "Maximum size of memory region",0,INT64_C(0x8000000000000000),INT64_C(0x7fffffffffffffff),INT64_C(0x1000000000000), "0x1000000000000" ),
        eslapi::CADIParameterInfo_t(0x10000005, "force-dmi-size",eslapi::CADI_PARAM_BOOL, "Force DMI start and end address to be 4kB-aligned",0,INT64_C(0x8000000000000000),INT64_C(0x7fffffffffffffff),INT64_C(0x1), "true" ),
        eslapi::CADIParameterInfo_t(0x10000006, "dmi-container-type",eslapi::CADI_PARAM_STRING, "Type of the DMI cache. Allowed values: TZAttr and FullAttr",0,INT64_C(0x8000000000000000),INT64_C(0x7fffffffffffffff),INT64_C(0x0), "TZAttr" ),
        eslapi::CADIParameterInfo_t(0x10000007, "counters-file-name",eslapi::CADI_PARAM_STRING, "Prefix of the file name to store counters at the end of simulation",0,INT64_C(0x8000000000000000),INT64_C(0x7fffffffffffffff),INT64_C(0x0), "" ),
        eslapi::CADIParameterInfo_t(0x10000008, "min-range-to-cache",eslapi::CADI_PARAM_INT, "Min DMI range size to cache in the bridge",0,INT64_C(0x1000),INT64_C(0x7fffffffffffffff),INT64_C(0x10000), "0x10000" ),
        eslapi::CADIParameterInfo_t(0x10000009, "dump-dmi-file-name",eslapi::CADI_PARAM_STRING, "Prefix of the file name to dump the content of the DMI when requested",0,INT64_C(0x8000000000000000),INT64_C(0x7fffffffffffffff),INT64_C(0x0), "" ),
        eslapi::CADIParameterInfo_t(0x1000000A, "dump-dmi-cache",eslapi::CADI_PARAM_BOOL, "Dumps the content of the DMI cache into a file",1,INT64_C(0x8000000000000000),INT64_C(0x7fffffffffffffff),INT64_C(0x0), "false" ),

            eslapi::CADIParameterInfo_t( 0, "", eslapi::CADI_PARAM_BOOL, "", 1, INT64_C(0), INT64_C(-1), 0, "0" )
        };
        
        static eslapi::CADITargetInfo_t const info
        (
            0, /* uint32_t id; (overridden in CADIFactory) */                                                              // used for identification
            "PVBus2AMBAPV", /* char  targetName[CADI_NAME_SIZE];     */      // name of the target, i.e. the "type", not the instance name
            "", /* char instanceName[CADI_NAME_SIZE]; (overridden in CADIFactory) */    // name of the CADI target instance
            "11.10.22", /* char        version[CADI_DESCRIPTION]; */           // version string
            "PVBus to AMBA-PV protocol converter", /* char    description[CADI_DESCRIPTION]; */       // target description
            "Bridge", /* char componentType[CADI_NAME_SIZE]; */       // classification of the target into a user-defined group
            uint32_t((sizeof(parameters) / sizeof(parameters[0])) - 1),         // number of parameters supported
            0, /* bool        executesSoftware; */                            // false = does not execute programs, true = executes software
            false, /* uint32_t     isHardwareModel; */                             // 0 = is software model, 1 = is hardware model
            "", /* char systemName[CADI_NAME_SIZE];  (overridden in CADIFactory) */             // name of the system the target belongs to.
            // Is empty for single-core standalone models.
            0, /* uint32_t systemID; (overridden in CADIFactory) */                                                // system id
            "" /* char  systemDescription[CADI_DESCRIPTION]; (overridden in CADIFactory) */ // description of the system
        );

        // build TargetInfo
        sg::TargetInfo targetInfo;
        targetInfo.cadi_target_info = &info;
        targetInfo.parameter_count = targetInfo.cadi_target_info->numberOfParameters;
        targetInfo.parameter_info = parameters;

        // publish this component's TargetInfo
        publishTarget(targetInfo, "");

        // publish subcomponent TargetInfos
        {
            sg::ComponentFactory *componentFactory = PVBusBridge_GetFactory();
            ComponentFactoryBase::publishSubComponent(componentFactory, "bus_bridge", true, ParameterFilter_bus_bridge_of_PVBusBridge_to_PVBus2AMBAPV());
            componentFactory->dereference();
        }

        componentsPublished = true;
    }
    ~PVBus2AMBAPV_ComponentFactoryClass()
    {
    }

public:
    PVBus2AMBAPV_ComponentFactoryClass() {
        componentsPublished = false;
    }

    virtual void dereference() { delete this; }

    virtual sg::ComponentBase *instantiate(std::string const & instance_name,
                                                sg::SimulationContext *simulationContext,
                                                sg::Params const & params)
    {
        return new DMA_NMS::Component__PVBus2AMBAPV(instance_name.c_str(), simulationContext, params);
    }

    virtual unsigned int getTargetCount()
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetCount();
    }

    virtual sg::TargetInfo * getTargetInfo(unsigned int index)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetInfo(index);
    }

    virtual sg::TargetInfo * getTargetInfo(std::string const & instance_path)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetInfo(instance_path);
    }

    virtual void publishSubComponent(sg::ComponentFactory *factory, const std::string &prefix,
                          bool publish_all, const ParameterFilter &param_filter)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::publishSubComponent(factory, prefix, publish_all, param_filter);
    }

    virtual void publishComponent(sg::ComponentFactory *factory, const std::string &prefix,
                          bool publish_all)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::publishComponent(factory, prefix, publish_all);
    }

};

}

namespace DMA_NMS {

// factory function
// (this is the function which is exposed to the outside world)
sg::ComponentFactory *PVBus2AMBAPV_GetFactory()
{
        return new PVBus2AMBAPV_ComponentFactoryClass();
}

} // DMA_NMS
// ------------------------------------------------------------------------------
// component factory of class SGSignal2AMBAPVSignal
// ------------------------------------------------------------------------------
//


namespace
{

// component factory class
// (this concrete class is never exposed to the outside world)
class SGSignal2AMBAPVSignal_ComponentFactoryClass: public ComponentFactoryBase
{
    bool componentsPublished;
    void lazyPublish(void)
    {
        // publish subcomponent TargetInfos

        componentsPublished = true;
    }
    ~SGSignal2AMBAPVSignal_ComponentFactoryClass()
    {
    }

public:
    SGSignal2AMBAPVSignal_ComponentFactoryClass() {
        componentsPublished = false;
    }

    virtual void dereference() { delete this; }

    virtual sg::ComponentBase *instantiate(std::string const & instance_name,
                                                sg::SimulationContext *simulationContext,
                                                sg::Params const & params)
    {
        return new DMA_NMS::Component__SGSignal2AMBAPVSignal(instance_name.c_str(), simulationContext, params);
    }

    virtual unsigned int getTargetCount()
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetCount();
    }

    virtual sg::TargetInfo * getTargetInfo(unsigned int index)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetInfo(index);
    }

    virtual sg::TargetInfo * getTargetInfo(std::string const & instance_path)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetInfo(instance_path);
    }

    virtual void publishSubComponent(sg::ComponentFactory *factory, const std::string &prefix,
                          bool publish_all, const ParameterFilter &param_filter)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::publishSubComponent(factory, prefix, publish_all, param_filter);
    }

    virtual void publishComponent(sg::ComponentFactory *factory, const std::string &prefix,
                          bool publish_all)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::publishComponent(factory, prefix, publish_all);
    }

};

}

namespace DMA_NMS {

// factory function
// (this is the function which is exposed to the outside world)
sg::ComponentFactory *SGSignal2AMBAPVSignal_GetFactory()
{
        return new SGSignal2AMBAPVSignal_ComponentFactoryClass();
}

} // DMA_NMS
// ------------------------------------------------------------------------------
// component factory of class AMBAPVSignal2SGSignal
// ------------------------------------------------------------------------------
//


namespace
{

// component factory class
// (this concrete class is never exposed to the outside world)
class AMBAPVSignal2SGSignal_ComponentFactoryClass: public ComponentFactoryBase
{
    bool componentsPublished;
    void lazyPublish(void)
    {
        // publish subcomponent TargetInfos

        componentsPublished = true;
    }
    ~AMBAPVSignal2SGSignal_ComponentFactoryClass()
    {
    }

public:
    AMBAPVSignal2SGSignal_ComponentFactoryClass() {
        componentsPublished = false;
    }

    virtual void dereference() { delete this; }

    virtual sg::ComponentBase *instantiate(std::string const & instance_name,
                                                sg::SimulationContext *simulationContext,
                                                sg::Params const & params)
    {
        return new DMA_NMS::Component__AMBAPVSignal2SGSignal(instance_name.c_str(), simulationContext, params);
    }

    virtual unsigned int getTargetCount()
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetCount();
    }

    virtual sg::TargetInfo * getTargetInfo(unsigned int index)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetInfo(index);
    }

    virtual sg::TargetInfo * getTargetInfo(std::string const & instance_path)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::getTargetInfo(instance_path);
    }

    virtual void publishSubComponent(sg::ComponentFactory *factory, const std::string &prefix,
                          bool publish_all, const ParameterFilter &param_filter)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::publishSubComponent(factory, prefix, publish_all, param_filter);
    }

    virtual void publishComponent(sg::ComponentFactory *factory, const std::string &prefix,
                          bool publish_all)
    {
        if (!componentsPublished) lazyPublish();
        return ComponentFactoryBase::publishComponent(factory, prefix, publish_all);
    }

};

}

namespace DMA_NMS {

// factory function
// (this is the function which is exposed to the outside world)
sg::ComponentFactory *AMBAPVSignal2SGSignal_GetFactory()
{
        return new AMBAPVSignal2SGSignal_ComponentFactoryClass();
}

} // DMA_NMS

