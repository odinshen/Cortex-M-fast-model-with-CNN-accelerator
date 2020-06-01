#
# Makefile - DMA platform makefile.
#
# Copyright 2012 ARM Limited.
# All rights reserved.
#

PROJECT_PATH ?= .

# Common rules
include $(PROJECT_PATH)/../../../Common/Makefile.common

# Specify objects and target(s) to build
SRCS = $(wildcard $(PROJECT_PATH)/../Source-CNN/*.cpp)
TARGET = EVS_DMA_Cortex-M4-CNN.x

# Determine others...
GENDIR = ./$(CONFIG)/gen
BUILDDIR = ./$(CONFIG)
WRAPPERLIB = scx-DMA-$(CONFIG)
EVSLIB = DMA-$(CONFIG)
CXXFLAGS += -I$(GENDIR)
LDFLAGS += -L$(BUILDDIR) -l$(WRAPPERLIB) -lcomponents -lpvbus \
		 $(PVLIB_HOME)/lib/Linux$(BITNESS_IN_NAME)_GCC-$(GCC_VER)/libarmctmodel.a \
		 -lscx -lfmruntime -lIrisSupport -lsystemc -l$(EVSLIB) -ldl -lrt \
		 -Wl,-rpath,'$$ORIGIN'

# Determine commands
SIMGEN_CMD = $(MAXCORE_HOME)/bin/simgen -p $(PROJECT_PATH)/EVS_DMA_Cortex-M4.sgproj \
			 --num-build-cpus $(J) --configuration $(CONFIG) \
			 $(SIMGENFLAGS)
CXX_CMD = $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS) $(SYSTEMLIBS)

.SUFFIXES:




.PHONY: dbg_gcc49_64 rel_gcc49_64
.PHONY: dbg_gcc64_64 rel_gcc64_64
.PHONY: dbg_gcc73_64 rel_gcc73_64


.PHONY: dbg_gcc49_64_clean rel_gcc49_64_clean
.PHONY: dbg_gcc64_64_clean rel_gcc64_64_clean
.PHONY: dbg_gcc73_64_clean rel_gcc73_64_clean

 dbg_gcc49_64 rel_gcc49_64 dbg_gcc64_64 rel_gcc64_64 dbg_gcc73_64 rel_gcc73_64:
	$(SIMGEN_CMD) -b
	cp $(BUILDDIR)/lib$(EVSLIB).so ./
	$(CXX_CMD)

 dbg_gcc49_64_clean rel_gcc49_64_clean dbg_gcc64_64_clean rel_gcc64_64_clean dbg_gcc73_64_clean rel_gcc73_64_clean:
	-$(SIMGEN_CMD) --clean
	-rm -f $(TARGET)
	-rm -f ./lib$(EVSLIB).so


