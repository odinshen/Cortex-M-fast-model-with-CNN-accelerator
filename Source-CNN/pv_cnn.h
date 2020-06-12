/*
 * pv_cnn.h - PV CNN module definition.
 *
 * Copyright 2007-2012 ARM Limited.
 * All rights reserved.
 */

#ifndef _PV_CNN_H_
#define _PV_CNN_H_

/* Includes */ 
#include <amba_pv.h>
#include "types.h"

/* Datatypes */

class pv_cnn:
    public sc_core::sc_module,
    public amba_pv::amba_pv_slave_base<BUSWIDTH>,
    public amba_pv::amba_pv_master_base {
      
    /* Registers relative addresses */
    public:
        static const addr_t IN_ADDR;
        static const addr_t OUT_ADDR;
        static const addr_t WEIGHT_ADDR;
        static const addr_t BAISE_ADDR;
        static const addr_t CONTROL;
        static const addr_t MONITOR1;
        static const addr_t MONITOR2;
        static const addr_t MONITOR3;
        static const addr_t MONITOR4;

    /* Control register bits */
        static const unsigned char START;
        static const unsigned char IRQ;

    /* Module ports */
        amba_pv::amba_pv_slave_socket<BUSWIDTH> amba_pv_s;
        amba_pv::amba_pv_master_socket<BUSWIDTH> amba_pv_m;
        amba_pv::signal_master_port<signal_t> pv_cnn_irq_out;

    /* Constructor */
        SC_HAS_PROCESS(pv_cnn);
        explicit pv_cnn(sc_core::sc_module_name);

    /* amba_pv_if methods implementation (overrides amba_pv_slave_base default
     * implementation) */
        virtual amba_pv::amba_pv_resp_t
        read(int,
             const addr_t &,
             unsigned char *,
             unsigned int,
             const amba_pv::amba_pv_control *,
             sc_core::sc_time &);
        virtual amba_pv::amba_pv_resp_t
        write(int,
              const addr_t &,
              unsigned char *,
              unsigned int,
              const amba_pv::amba_pv_control *,
              unsigned char *,
              sc_core::sc_time &);
        virtual unsigned int
        debug_read(int,
                   const addr_t &,
                   unsigned char *,
                   unsigned int,
                   const amba_pv::amba_pv_control *);
        virtual unsigned int
        debug_write(int,
                    const addr_t &,
                    unsigned char *,
                    unsigned int,
                    const amba_pv::amba_pv_control *);

    /* Implementation */
    private:
      
        /* Member variables */
        sc_core::sc_event m_start_transfer;
            /* CNN process related event (start) */
        sc_core::sc_event m_irq_to_change;
            /* Rise/clear interrupt signal related event */
        unsigned int m_pv_cnn_src_addr; /* Source address register */
        unsigned int m_pv_cnn_dst_addr; /* Destination address register */
        unsigned int m_pv_cnn_weight;   /* Weight register (in byte) */
        unsigned int m_pv_cnn_baise;    /* Baise register (in byte) */
        unsigned char m_pv_cnn_control; /* Control register (8 bits register) */
        unsigned int m_pv_cnn_monitor1; /* Monitor register */
        unsigned int m_pv_cnn_monitor2; /* Monitor register */
        unsigned int m_pv_cnn_monitor3; /* Monitor register */
        unsigned int m_pv_cnn_monitor4; /* Monitor register */

        /* Helpers */
        void transfer();                /* CNN transfer management process */
        void irq();
            /* CNN transfer end IRQ signal management process */
};

#endif /* _PV_CNN_H_ */
