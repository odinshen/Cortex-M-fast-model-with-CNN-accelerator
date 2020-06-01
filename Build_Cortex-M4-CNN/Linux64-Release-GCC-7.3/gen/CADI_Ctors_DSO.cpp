/*
 * 
 *
 * Copyright 2009 ARM Limited.
 * Copyright 2011 ARM Limited.
 *
 * All rights reserved.
 */
/** \file
 * Constructors for CADI wrapper classes. Put in a separate compilation unit
 * so we can compile it without optimisation which is very slow with some
 * versions of some compilers.
 */



#include "GlobalDefs.h"
#include "Components.h"
// includes for components in this file
#include "Component__RAMDevice_ClassDef.h"


#include "sg/FastDelegate.h"

using namespace fastdelegate;
using namespace DMA_NMS;

// ------------------------------------------------------------------------------
// CADI Interface for component Component__RAMDevice
// ------------------------------------------------------------------------------

namespace DMA_NMS {

class Component__RAMDevice_CADI : public sg::CADIBase
{
public:
        Component__RAMDevice_CADI(Component__RAMDevice* parentComponent, sg::ComponentBase* simulationEngine);

    eslapi::CADIReturn_t CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response);

private:
    Component__RAMDevice *component;
};

} // DMA_NMS


// ------------------------------------------------------------------------------
// CADI Interface for component Component__RAMDevice
// ------------------------------------------------------------------------------

#include "Component__RAMDevice_ClassDef.h"

namespace DMA_NMS {

// constructor
Component__RAMDevice_CADI::Component__RAMDevice_CADI(Component__RAMDevice* parentComponent, sg::ComponentBase* simulationEngine) :
    sg::CADIBase(parentComponent ? parentComponent->getName() : "", simulationEngine),
    component(parentComponent)
{

	AddMemorySpace("ram_contents", "ram_contents", 0, 8, (parentComponent->get_ram_contents_length() - 1), 0, 1, 0);
 

	{
		uint32_t supported_multiples_of_mau[32] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		CADIBase::MemoryBlock *mb = AddMemoryBlock(0, "ram_contents", "ram_contents", uint16_t(eslapi::CADI_MEMBLOCK_ROOT), 0, (parentComponent->get_ram_contents_length()), 0, eslapi::CADI_MEM_ReadWrite, supported_multiples_of_mau, 0, 0, 0);
		mb->access_write_func = MakeDelegate(parentComponent, &Component__RAMDevice::debug_write);
		mb->access_read_func = MakeDelegate(parentComponent, &Component__RAMDevice::debug_read);
	}




    strcpy( features.targetName, "RAMDevice" );
    strcpy( features.targetVersion, "11.10.22" );
    features.fProfilingAvailable = false;
    features.nExtendedTargetFeaturesRegNumValid = true;
    features.nExtendedTargetFeaturesRegNum = 0;
    features.nPCRegNum = eslapi::CADI_INVALID_REGISTER_ID;
}


eslapi::CADIReturn_t
Component__RAMDevice_CADI::CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response)
{
    if (!command || (commandLength == 0))
        return eslapi::CADI_STATUS_IllegalArgument;

    const char *param = 0;

    if (IsBypassCommand(commandLength, command, "GetFeatures", &param))
    {
        if ((maxResponseLength > 0) && (response != 0))
        {
            // Feel free to add more features here using the syntax :feature:otherfeature:morefeatures:...:
            strncpy(response,
                    "::MAXVIEWGEN:",
                    maxResponseLength);
            response[maxResponseLength - 1] = 0;
            return eslapi::CADI_STATUS_OK;
        }
        else
            return eslapi::CADI_STATUS_IllegalArgument;
    }
    else
        return CADIBase::CADIXfaceBypass(commandLength, command, maxResponseLength, response);
}

} // DMA_NMS

