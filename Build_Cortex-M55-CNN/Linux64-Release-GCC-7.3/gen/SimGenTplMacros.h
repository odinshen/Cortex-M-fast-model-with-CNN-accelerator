/*
 * Copyright 2011-2012 ARM Limited.
 *
 * All Rights Reserved.
 *
 * SimGen generation macros.
 *
 * This header file is not used by other generated sources, since they can use
 * the generation @macros@ directly. But handwritten code (for example a
 * handwritten IsimMain.cpp) can make use of these macros.
 */

#ifndef SimGenTplMacros_h
#define SimGenTplMacros_h

#include "pv/PVVersion.h"

#define SIMGEN_TOP_COMPONENT "DMA"
#define PVLIB_VERSION_STRING SYSGEN_PVMODELLIB_MAJOR_STR "." SYSGEN_PVMODELLIB_MINOR_STR "." SYSGEN_PVMODELLIB_BUILD_STR

#define SCX_EVS_SUPPORTED 1

#endif // #ifndef SimGenTplMacros_h
// end of file #ifndef SimGenTplMacros.h
