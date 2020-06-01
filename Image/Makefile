#
# Makefile - DMA example application makefile.
#
# Copyright 2012 ARM Limited.
# All rights reserved.
#


#RVCT_LIB = $(shell which armcc | sed -e "s/Programs/Data/" | sed -e "s;linux-pentium/armcc;lib;")
#RVCT_INC = $(shell which armcc | sed -e "s/Programs/Data/" | sed -e "s;linux-pentium/armcc;include/unix;")
CC = /usr/local/DS-5_v5.29.2/sw/ARMCompiler5.06u6/bin/armcc
LD = /usr/local/DS-5_v5.29.2/sw/ARMCompiler5.06u6/bin/armlink
#CFLAGS = -W -g -O2 -Otime -I $(RVCT_INC)
CFLAGS = -W -g -O2 -Otime
#LDFLAGS = --info totals --info unused --libpath $(RVCT_LIB)
LDFLAGS = --info totals --info unused
V6CFLAGS = --arm --cpu=6
V7MCFLAGS = --thumb --cpu=Cortex-M3
V6MCFLAGS = --thumb --cpu=Cortex-M0
WFICFLAGS = --arm --cpu=7-R -D USE_WFI
V6LDFLAGS = 
V7MLDFLAGS =
V6MLDFLAGS =
WFILDFLAGS = 

all: v6 v7m v6m wfi

v6:
	mkdir v6

v7m:
	mkdir v7m

v6m:
	mkdir v6m

wfi:
	mkdir wfi

v6/%.o: %.c
	$(CC) $(CFLAGS) $(V6CFLAGS) -c -o $@ $<

v7m/%.o: %.c
	$(CC) $(CFLAGS) $(V7MCFLAGS) -c -o $@ $<

v6m/%.o: %.c
	$(CC) $(CFLAGS) $(V6MCFLAGS) -c -o $@ $<

wfi/%.o: %.c
	$(CC) $(CFLAGS) $(WFICFLAGS) -c -o $@ $<

all: dma.axf dma_v7m.axf dma_v6m.axf dma_wfi.axf

dma.axf: v6 v6/dma.o
	$(LD) $(LDFLAGS) $(V6LDFLAGS) -o $@ v6/dma.o

dma_v7m.axf: v7m v7m/dma.o
	$(LD) $(LDFLAGS) $(V7MLDFLAGS) -o $@ v7m/dma.o

dma_v6m.axf: v6m v6m/dma.o
	$(LD) $(LDFLAGS) $(V6MLDFLAGS) -o $@ v6m/dma.o

dma_wfi.axf: wfi wfi/dma.o
	$(LD) $(LDFLAGS) $(WFILDFLAGS) -o $@ wfi/dma.o

clean:
	-rm -f *.axf *.list *.map
	-rm -f v6/*.o v7m/*.o v6m/*.o wfi/*.o

