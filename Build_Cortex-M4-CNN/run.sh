#!/bin/sh
#
# run.sh - Run the EVS_DMA example.
#
# Copyright 2012 ARM Limited.
# All rights reserved.
#

./EVS_DMA_Cortex-M4-CNN.x -a CNN.Core=../Image/dma_v7m.axf $*
