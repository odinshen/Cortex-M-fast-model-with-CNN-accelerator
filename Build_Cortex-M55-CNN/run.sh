#!/bin/sh
#
# run.sh - Run the EVS_DMA example.
#
# Copyright 2020 ARM Limited.
# All rights reserved.
#

./EVS_Cortex-M55-CNN.x -a CNN.Core=../Image/cnn_v7m.axf $*
