/*
 * main.cpp - DMA platform model wrapper.
 *
 * Copyright 2011-2012 ARM Limited.
 * All rights reserved.
 */

/* Includes */
#include <scx_evs_DMA.h>
#include "pv_dma.h"
#include "master.h"

/* Functions */

/*
 * User's entry point.
 */
int sc_main(int argc , char * argv[]) {

    /*
     * Initialize simulation 
     */
    scx::scx_initialize("DMA");

    /*
     * Components
     */
    amba_pv::amba_pv_simple_memory<BUSWIDTH> dst_mem("dst_mem", 0x2000, 0xFF);
    pv_dma pv_dma("pv_dma");
    amba_pv::amba_pv_decoder<BUSWIDTH, 2, 3> router("router");
    scx_evs_DMA dma("DMA");
    master master("master");

    /*
     * Simulation configuration
     */
   
    /* From command-line options */
    scx::scx_parse_and_configure(argc, argv);

    /* Semi-hosting configuration */
    bool v;

    if (scx::scx_get_parameter("DMA.Core.cpu0.semihosting-enable", v)) {

        /* MP core */
        scx::scx_set_parameter("*.Core.cpu0.semihosting-enable", true);
        scx::scx_set_parameter("*.Core.cpu0.semihosting-ARM_SVC", 0x123456);
        scx::scx_set_parameter("*.Core.cpu0.semihosting-Thumb_SVC", 0xAB);
        scx::scx_set_parameter("*.Core.cpu0.semihosting-heap_base", 0x32000000);
        scx::scx_set_parameter("*.Core.cpu0.semihosting-heap_limit", 0x1000000);
        scx::scx_set_parameter("*.Core.cpu0.semihosting-stack_base", 0x33000000);
        scx::scx_set_parameter("*.Core.cpu0.semihosting-stack_limit", 0x1000000);
    } else {

        /* UP core */
        scx::scx_set_parameter("*.Core.semihosting-enable", true);
        if (scx::scx_get_parameter("DMA.Core.semihosting-ARM_SVC", v))
        {
            // M-class cores only support Thumb and do not have a semihosting-ARM_SVC parameter.
            scx::scx_set_parameter("*.Core.semihosting-ARM_SVC", 0x123456);
        }
        scx::scx_set_parameter("*.Core.semihosting-Thumb_SVC", 0xAB);
        scx::scx_set_parameter("*.Core.semihosting-heap_base", 0x32000000);
        scx::scx_set_parameter("*.Core.semihosting-heap_limit", 0x1000000);
        scx::scx_set_parameter("*.Core.semihosting-stack_base", 0x33000000);
        scx::scx_set_parameter("*.Core.semihosting-stack_limit", 0x1000000);
    }

    /* Simulation quantum, i.e. seconds to run per quantum */
    tlm::tlm_global_quantum::instance().set(sc_core::sc_time(100.0
                                                             / 100000000,
                                                             sc_core::SC_SEC));

    /* Simulation minimum synchronization latency */
    scx::scx_set_min_sync_latency(100.0 / 100000000);

    /*
     * Bindings
     */
    pv_dma.amba_pv_m(router.amba_pv_s[0]);
    pv_dma.pv_dma_irq_out(dma.irq_in);
    dma.amba_pv_m(router.amba_pv_s[1]);
    router.bind(0, dma.amba_pv_s, 0x0, 0x1FFF);
    router.bind(1, pv_dma.amba_pv_s, 0x34004000, 0x34004FFF);
    router.bind(2, dst_mem.amba_pv_s, 0x34002000, 0x34003FFF);
    dma.irq_out(master.pv_dma_irq_in);

    /*
     * Start of simulation
     */
    sc_core::sc_start();
    return EXIT_SUCCESS;
}
