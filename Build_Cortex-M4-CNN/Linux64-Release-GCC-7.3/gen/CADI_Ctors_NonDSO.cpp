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
#include "Component__DMA_ClassDef.h"
#include "Component__AMBAPV2PVBus_ClassDef.h"
#include "Component__PVBus2AMBAPV_ClassDef.h"
#include "Component__SGSignal2AMBAPVSignal_ClassDef.h"
#include "Component__AMBAPVSignal2SGSignal_ClassDef.h"


#include "sg/FastDelegate.h"

using namespace fastdelegate;
using namespace DMA_NMS;

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


// ------------------------------------------------------------------------------
// CADI Interface for component Component__DMA
// ------------------------------------------------------------------------------

#include "Component__DMA_ClassDef.h"

namespace DMA_NMS {

// constructor
Component__DMA_CADI::Component__DMA_CADI(Component__DMA* parentComponent, sg::ComponentBase* simulationEngine) :
    sg::CADIBase(parentComponent ? parentComponent->getName() : "", simulationEngine),
    component(parentComponent)
{







    strcpy( features.targetName, "DMA" );
    strcpy( features.targetVersion, "" );
    features.fProfilingAvailable = false;
    features.nExtendedTargetFeaturesRegNumValid = true;
    features.nExtendedTargetFeaturesRegNum = 0;
    features.nPCRegNum = eslapi::CADI_INVALID_REGISTER_ID;
}


eslapi::CADIReturn_t
Component__DMA_CADI::CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response)
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
// ------------------------------------------------------------------------------
// CADI Interface for component Component__AMBAPV2PVBus
// ------------------------------------------------------------------------------

#include "Component__AMBAPV2PVBus_ClassDef.h"

namespace DMA_NMS {

// constructor
Component__AMBAPV2PVBus_CADI::Component__AMBAPV2PVBus_CADI(Component__AMBAPV2PVBus* parentComponent, sg::ComponentBase* simulationEngine) :
    sg::CADIBase(parentComponent ? parentComponent->getName() : "", simulationEngine),
    component(parentComponent)
{







    strcpy( features.targetName, "AMBAPV2PVBus" );
    strcpy( features.targetVersion, "1.0" );
    features.fProfilingAvailable = false;
    features.nExtendedTargetFeaturesRegNumValid = true;
    features.nExtendedTargetFeaturesRegNum = 0;
    features.nPCRegNum = eslapi::CADI_INVALID_REGISTER_ID;
}


eslapi::CADIReturn_t
Component__AMBAPV2PVBus_CADI::CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response)
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
// ------------------------------------------------------------------------------
// CADI Interface for component Component__PVBus2AMBAPV
// ------------------------------------------------------------------------------

#include "Component__PVBus2AMBAPV_ClassDef.h"

namespace DMA_NMS {

// constructor
Component__PVBus2AMBAPV_CADI::Component__PVBus2AMBAPV_CADI(Component__PVBus2AMBAPV* parentComponent, sg::ComponentBase* simulationEngine) :
    sg::CADIBase(parentComponent ? parentComponent->getName() : "", simulationEngine),
    component(parentComponent)
{







    strcpy( features.targetName, "PVBus2AMBAPV" );
    strcpy( features.targetVersion, "11.10.22" );
    features.fProfilingAvailable = false;
    features.nExtendedTargetFeaturesRegNumValid = true;
    features.nExtendedTargetFeaturesRegNum = 0;
    features.nPCRegNum = eslapi::CADI_INVALID_REGISTER_ID;
}


eslapi::CADIReturn_t
Component__PVBus2AMBAPV_CADI::CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response)
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
// ------------------------------------------------------------------------------
// CADI Interface for component Component__SGSignal2AMBAPVSignal
// ------------------------------------------------------------------------------

#include "Component__SGSignal2AMBAPVSignal_ClassDef.h"

namespace DMA_NMS {

// constructor
Component__SGSignal2AMBAPVSignal_CADI::Component__SGSignal2AMBAPVSignal_CADI(Component__SGSignal2AMBAPVSignal* parentComponent, sg::ComponentBase* simulationEngine) :
    sg::CADIBase(parentComponent ? parentComponent->getName() : "", simulationEngine),
    component(parentComponent)
{







    strcpy( features.targetName, "SGSignal2AMBAPVSignal" );
    strcpy( features.targetVersion, "11.10.22" );
    features.fProfilingAvailable = false;
    features.nExtendedTargetFeaturesRegNumValid = true;
    features.nExtendedTargetFeaturesRegNum = 0;
    features.nPCRegNum = eslapi::CADI_INVALID_REGISTER_ID;
}


eslapi::CADIReturn_t
Component__SGSignal2AMBAPVSignal_CADI::CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response)
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
// ------------------------------------------------------------------------------
// CADI Interface for component Component__AMBAPVSignal2SGSignal
// ------------------------------------------------------------------------------

#include "Component__AMBAPVSignal2SGSignal_ClassDef.h"

namespace DMA_NMS {

// constructor
Component__AMBAPVSignal2SGSignal_CADI::Component__AMBAPVSignal2SGSignal_CADI(Component__AMBAPVSignal2SGSignal* parentComponent, sg::ComponentBase* simulationEngine) :
    sg::CADIBase(parentComponent ? parentComponent->getName() : "", simulationEngine),
    component(parentComponent)
{







    strcpy( features.targetName, "AMBAPVSignal2SGSignal" );
    strcpy( features.targetVersion, "11.10.22" );
    features.fProfilingAvailable = false;
    features.nExtendedTargetFeaturesRegNumValid = true;
    features.nExtendedTargetFeaturesRegNum = 0;
    features.nPCRegNum = eslapi::CADI_INVALID_REGISTER_ID;
}


eslapi::CADIReturn_t
Component__AMBAPVSignal2SGSignal_CADI::CADIXfaceBypass(uint32_t commandLength, const char *command, uint32_t maxResponseLength, char *response)
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

