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

#ifndef _NO_CORE_Components_h_
#define _NO_CORE_Components_h_

#include <eslapi/eslapi_stdint.h>

#include <string>
#include <vector>
#include "MaxCoreVersion.h"

// clean way to get the name of the generated class for a component (e.g. for behavior return types for types defined in the resources section)
#define COMPONENT_CLASS_NAME(compName) Component__##compName

// collected defines start
#define MAXCORE_VERSION  "11 + 3.10.22"
#define SYSTEM_GENERATOR_VERSION  "11.10.22"
#define GEN_SBOX  1
#define GEN_SYSTEM_PLATFORM  1
#define linux  1
#define SIMGEN_RELEASE  1
#define NDEBUG  1

// collected defines end

#include "CADIProtocol.h"

#include "MCPagedMemory.h"
#include "MCNonPagedMemory.h"
#include "sg/SGSimulationContext.h"
#include "sg/SGComponentFactory.h"
class ObjectLoader;

#include "SGComponentWithPorts.h"

#include "DMA_DSO.h"

// include protocols
#include "Builtin__AddressablePortProtocol_2D_ClassDef.h"
#include "Builtin__ControlProtocol_2D_ClassDef.h"

// legacy: collected includes from components


// collected includes from components


sg::ComponentFactory *PVBusMaster_GetFactory();
sg::ComponentFactory *PVBusBridge_GetFactory();
sg::ComponentFactory *ClockDivider_GetFactory();
sg::ComponentFactory *MasterClock_GetFactory();
sg::ComponentFactory *ARMCortexM4CT_GetFactory();
sg::ComponentFactory *PVBusDecoder_GetFactory();
sg::ComponentFactory *PVBusSlave_GetFactory();


namespace DMA_NMS {

// declare all components (forward decls)
class Component__DMA;
namespace MT { class Component__DMA; }
class Component__AMBAPV2PVBus;
namespace MT { class Component__AMBAPV2PVBus; }
class Component__PVBus2AMBAPV;
namespace MT { class Component__PVBus2AMBAPV; }
class Component__RAMDevice;
namespace MT { class Component__RAMDevice; }
class Component__SGSignal2AMBAPVSignal;
namespace MT { class Component__SGSignal2AMBAPVSignal; }
class Component__AMBAPVSignal2SGSignal;
namespace MT { class Component__AMBAPVSignal2SGSignal; }


// legacy: component class declarations


// legacy: component class definitions


// component factory prototypes
sg::ComponentFactory *DMA_GetFactory();
sg::ComponentFactory *AMBAPV2PVBus_GetFactory();
sg::ComponentFactory *PVBus2AMBAPV_GetFactory();
SG_DMA_DSO sg::ComponentFactory *RAMDevice_GetFactory();
sg::ComponentFactory *SGSignal2AMBAPVSignal_GetFactory();
sg::ComponentFactory *AMBAPVSignal2SGSignal_GetFactory();


} // namespace DMA_NMS

#endif

