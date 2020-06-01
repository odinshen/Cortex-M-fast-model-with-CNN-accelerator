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

#include "Component__SGSignal2AMBAPVSignal_ClassDef.h"


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


// non inline behaviors
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

#line 132 "./Linux64-Release-GCC-7.3/gen/Comp_NonDSO_4.cpp"

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

#line 786 "./Linux64-Release-GCC-7.3/gen/Comp_NonDSO_4.cpp"

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
