#!/bin/sh
#
# run.sh - Run the EVS_DMA example.
#
# Copyright 2012 ARM Limited.
# All rights reserved.
#

./EVS_Cortex-M4-CNN.x -a CNN.Core=../Image/cnn_v2_v7m.axf $*
