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
 * Class definition for Component PVBus2AMBAPV.
 */

#ifndef Component_Component__PVBus2AMBAPV_ClassDef_h_
#define Component_Component__PVBus2AMBAPV_ClassDef_h_

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

#line 33 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"
 

        /* WARNING! API not intended to be supported and will definitely
         * change in future releases. */
        #include <pv/PVMemoryAttributes.h>
        #include <pv/BusNode.h>
        #include <include/pv_userpayload_extension.h>
        #include "scx_sc_time_from_value.h"
    
#line 49 "./Linux64-Release-GCC-7.3/gen/Component__PVBus2AMBAPV_ClassDef.h"
#include "AMBAPV_2D_ClassDef.h"
#include "Builtin__ControlProtocol_2D_ClassDef.h"
#include "PVBusBridgeControl_2D_ClassDef.h"
#include "PVBus_2D_ClassDef.h"
#include "PVDevice_2D_ClassDef.h"
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

class ParameterFilter_bus_bridge_of_PVBusBridge_to_PVBus2AMBAPV : public ParameterFilter
{
public:
	ParameterFilter_bus_bridge_of_PVBusBridge_to_PVBus2AMBAPV()
	{
		ovrd_params["counters-file-name"] = eslapi::CADIParameterInfo_t(0x10000007 | PARAMETERFILTER_FORWARDED, "counters-file-name",eslapi::CADI_PARAM_STRING, "Prefix of the file name to store counters at the end of simulation",0,INT64_C(0x8000000000000000),INT64_C(0x7fffffffffffffff),INT64_C(0x0), "" ); // forwarded from "counters_file_name"
		ovrd_params["dmi-container-type"] = eslapi::CADIParameterInfo_t(0x10000006 | PARAMETERFILTER_FORWARDED, "dmi-container-type",eslapi::CADI_PARAM_STRING, "Type of the DMI cache. Allowed values: TZAttr and FullAttr",0,INT64_C(0x8000000000000000),INT64_C(0x7fffffffffffffff),INT64_C(0x0), "TZAttr" ); // forwarded from "dmi_container_type"
		ovrd_params["dump-dmi-file-name"] = eslapi::CADIParameterInfo_t(0x10000009 | PARAMETERFILTER_FORWARDED, "dump-dmi-file-name",eslapi::CADI_PARAM_STRING, "Prefix of the file name to dump the content of the DMI when requested",0,INT64_C(0x8000000000000000),INT64_C(0x7fffffffffffffff),INT64_C(0x0), "" ); // forwarded from "dump_dmi_file_name"
		ovrd_params["min-range-to-cache"] = eslapi::CADIParameterInfo_t(0x10000008 | PARAMETERFILTER_FORWARDED, "min-range-to-cache",eslapi::CADI_PARAM_INT, "Min DMI range size to cache in the bridge",0,INT64_C(0x1000),INT64_C(0x7fffffffffffffff),INT64_C(0x10000), "0x10000" ); // forwarded from "min_size_to_cache"
	}
};



class
#ifndef _WINDOWS
SG_DMA_DSO
#endif
Component__PVBus2AMBAPV: public SystemGenComponent
{
    // CADI class can see the resources (for MEMORY sections).
    friend class Component__PVBus2AMBAPV_CADI;
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
    
#line 43 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Bridges/PVBus2AMBAPV.lisa"


        // Limit size of memory region, defaulting to 48-bit
        const uint64_t  max_size   
                      ;

        const bool  force_dmi_size   
                      ;
        
        // Type of the DMI cache container. 
        // TZAttr -   A container which stores separately DMI ranges produced as a result of the NS attribute
        //            This is the default and a faster container
        // FullAttr - A container which stores separately DMI ranges produced as a result of transactions with different attributes
        //            FullAttr is only needed if any component downstream of the bridge would alter DMi ranges so that they differ
        //            based on ANY transaction attribute.
        //            This is the most strict container and as a result is the slowest one
        const std::string  dmi_container_type   
                      ;

        //The prefix provided here is going to be completed with the name of the instance of the bridge 
        //and an instance ID which is generated automatically. The file extension is .log
        const std::string  counters_file_name   
                      ;

        // Min DMI range size to cache. DMI ranges smaller than this will not by cached in the bridge
        // though they are still going to be used by the system
        // The smallest acceptable value here is 0x1000
        const uint32_t  min_size_to_cache   
                       ;

        //The prefix provided here is going to be completed with the name of the instance of the bridge 
        //and an instance ID which is generated automatically. The file extension is .log
        const std::string  dump_dmi_file_name   
                      ;

        // Setting this runtime parameter to anything != 0 makes the bridge dump its DMI cache content into a file
        // The parameter will auto-reset itself to false each time following the serialization 
        bool  dump_dmi_cache   
                        ;

        static pv::bus_addr_t const LOG2_GRANULARITY = 12;
        static pv::bus_addr_t const GRANULARITY = 1 << LOG2_GRANULARITY;
        static pv::bus_addr_t const GRANULARITY_MASK = GRANULARITY - 1;

        inline pv::bus_addr_t getBaseAddress(pv::bus_addr_t address) const
        {
            return force_dmi_size ?
                address & ~GRANULARITY_MASK :
                address;
        }

        inline pv::bus_addr_t getLimitAddress(pv::bus_addr_t address) const
        {
            pv::bus_addr_t limit = force_dmi_size ?
                                    (address | GRANULARITY_MASK):
                                    address;

            // Limit address range to 'max_size'
            if ((max_size > 0) && (limit > max_size))
               limit = max_size;
            return limit;
        }
        
        amba_pv::amba_pv_trans_pool trans_pool;

        amba_pv::amba_pv_trans_ptr transCacheRead;
        amba_pv::amba_pv_trans_ptr transCacheWrite;

        pv::BridgeBusNode  bus_node;

        uint32_t reentryCounter = 0;
    
#line 183 "./Linux64-Release-GCC-7.3/gen/Component__PVBus2AMBAPV_ClassDef.h"

public:

    // constructor and destructor
    Component__PVBus2AMBAPV(const char *instName, sg::SimulationContext* simulationContext, const sg::Params & params);
    ~Component__PVBus2AMBAPV();

    // abstract ports
	PVBus_2D pvbus_s; 
	private: Signal_2D reset_bus_interfaces; public:
	private: Signal_2D dump_dmi; public:
	AMBAPV_2D amba_pv_m; 
	private: PVBusBridgeControl_2D control_bridge; public:
	private: PVDevice_2D device; public:

    
    // Behaviours
	AccessFuncResult write_dump_dmi_cache(uint32_t id, const int64_t* data);
	void build_amba_pv_extension(const pv::Transaction* tx, amba_pv::amba_pv_extension* ex);
	bool send_tlm_dmi_request(pv::Transaction* tx, tlm::tlm_command command);
	pv::Tx_Result handle_transaction_result(pv::Transaction* tx, amba_pv::amba_pv_transaction* trans, amba_pv::amba_pv_extension* extension);
	pv::Tx_Result send_tlm_transaction(pv::Transaction* tx, tlm::tlm_command command, amba_pv::amba_pv_transaction* transCache);
	pv::Tx_Result send_tlm_transaction(pv::Transaction* tx, tlm::tlm_command command, bool debug);
	bool get_direct_mem_ptr(pv::Transaction* tx, amba_pv::amba_pv_transaction& trans);
	void init();
	void terminate();
	void reset(int level_);
	void busDiscovery();
	void interconnect();
	void disconnect();
	void loadApplicationFile(const std::string& filename);
	void step();
	void abstract_port__amba_pv_m__invalidate_direct_mem_ptr(int socket_id, sc_dt::uint64 start_range, sc_dt::uint64 end_range);
	pv::Tx_Result abstract_port__device__read(pv::ReadTransaction tx);
	pv::Tx_Result abstract_port__device__write(pv::WriteTransaction tx);
	pv::Tx_Result abstract_port__device__debugRead(pv::ReadTransaction tx);
	pv::Tx_Result abstract_port__device__debugWrite(pv::WriteTransaction tx);


    // These are explicitly lists in the LISA reference manual as being callable.
    void simHalt();
    void simRun();
    bool simIsRunning();
    void simShutdown();
    void simReset(uint32_t level);

private:
        
    // pointers to subcomponents
	sg::ComponentBase *bus_bridge;


    // control ports of subcomponents
	Builtin__ControlProtocol_2D controlPort_bus_bridge__;


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

    	void wire_connectionmap__0__();



	ParameterFilter_bus_bridge_of_PVBusBridge_to_PVBus2AMBAPV parameterFilter_bus_bridge_of_PVBusBridge_to_PVBus2AMBAPV__;


	CADIParameterProxy *cadiParameterProxy_bus_bridge_of_PVBusBridge_to_PVBus2AMBAPV__;


    // definition of parameter IDs as constants for use in parameter access functions
	enum
	{
		PARAMETER_ID_max_size = 0x10000004,
		PARAMETER_ID_force_dmi_size = 0x10000005,
		PARAMETER_ID_dmi_container_type = 0x10000006,
		PARAMETER_ID_counters_file_name = 0x10000007,
		PARAMETER_ID_min_size_to_cache = 0x10000008,
		PARAMETER_ID_dump_dmi_file_name = 0x10000009,
		PARAMETER_ID_dump_dmi_cache = 0x1000000A,
	};




};

namespace MT {

    //
    // This represents Component__PVBus2AMBAPV wrapped through a proxy so that it can
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
    Component__PVBus2AMBAPV : public sg::ComponentBaseForwarder
    {
        using wrapped_type = DMA_NMS::Component__PVBus2AMBAPV;
    public:
        
        Component__PVBus2AMBAPV(
            sg::ComponentFactory*      factory,
            sg::MTWrapperConfig const& wrapper_config,
            std::string const&         mtdomain_name,
            std::string const&         instName,
            sg::SimulationContext*     simulationContext,
            sg::Params const&          params
            );
        ~Component__PVBus2AMBAPV();


        // Non-internal ports of components are public and the parent component
        // can drive the behaviours directly in LISA or via the abstract C++
        // interface that just forwards them to the connectors in any event.
        //
        // Thus to proxy the components we just list them again and connector
        // their connectors like any other port.
	PVBus_2D pvbus_s; 
	private: Signal_2D reset_bus_interfaces; public:
	private: Signal_2D dump_dmi; public:
	AMBAPV_2D amba_pv_m; 
	private: PVBusBridgeControl_2D control_bridge; public:
	private: PVDevice_2D device; public:


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

    ARM_S( write_dump_dmi_cache )\
    ARM_S( build_amba_pv_extension )\
    ARM_S( send_tlm_dmi_request )\
    ARM_S( handle_transaction_result )\
    ARM_S( send_tlm_transaction )\
    ARM_S( get_direct_mem_ptr )\
    ARM_S( init )\
    ARM_S( terminate )\
    ARM_S( reset )\
    ARM_S( busDiscovery )\
    ARM_S( interconnect )\
    ARM_S( disconnect )\
    ARM_S( loadApplicationFile )\
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

