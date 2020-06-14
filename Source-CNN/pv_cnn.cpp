/*
 * pv_cnn.cpp - CNN module implementation.
 *
 * Copyright 2007-2009, 2011 ARM Limited.
 * All rights reserved.
 */

/* Includes */
#include "pv_cnn.h"
#include <scx/scx.h>

/* Constants */

/*
 * Register relative addresses
 */
const addr_t pv_cnn::IN_ADDR    = 0x00;  /* First register */
const addr_t pv_cnn::OUT_ADDR   = IN_ADDR + sizeof(data_t);
const addr_t pv_cnn::WEIGHT_ADDR= OUT_ADDR + sizeof(data_t);
const addr_t pv_cnn::BAISE_ADDR = WEIGHT_ADDR + sizeof(data_t);
const addr_t pv_cnn::CONTROL    = BAISE_ADDR + sizeof(data_t);
const addr_t pv_cnn::MONITOR1   = CONTROL + sizeof(data_t);
const addr_t pv_cnn::MONITOR2   = MONITOR1 + sizeof(data_t);
const addr_t pv_cnn::MONITOR3   = MONITOR2 + sizeof(data_t);
const addr_t pv_cnn::MONITOR4   = MONITOR3 + sizeof(data_t);


/*
 * Control register bit
 */
const unsigned char pv_cnn::START = 0x01;
const unsigned char pv_cnn::IRQ   = 0x10;

/* CNN ACC control parameter */
unsigned int pv_cnn::AccDelay = 0x4;

unsigned long cnn_time_stamp = 0;

/* Functions */

/*
 * Constructor
 */
pv_cnn::pv_cnn(sc_core::sc_module_name module_name):
    sc_core::sc_module(module_name),
    amba_pv::amba_pv_slave_base<BUSWIDTH>(name()),
    amba_pv::amba_pv_master_base(name()),
    amba_pv_s("amba_pv_s"),
    amba_pv_m("amba_pv_m"),
    pv_cnn_irq_out("pv_cnn_irq_out"),
    m_pv_cnn_src_addr(0),
    m_pv_cnn_dst_addr(0),
    m_pv_cnn_weight(0),
    m_pv_cnn_baise(0),
    m_pv_cnn_control(0),
    m_pv_cnn_monitor1(0),
    m_pv_cnn_monitor2(0),
    m_pv_cnn_monitor3(0),
    m_pv_cnn_monitor4(0) {
    amba_pv_s(* this);
    amba_pv_m(* this);
    SC_METHOD(transfer);
    sensitive << m_start_transfer;
    dont_initialize();
    SC_METHOD(irq);
    sensitive << m_irq_to_change;
    dont_initialize();
}

/* amba_pv_if virtual method implementation */

/*
 * CNN read access
 */
amba_pv::amba_pv_resp_t
pv_cnn::read(int id,
             const addr_t & address,
             unsigned char * data,
             unsigned int size,
             const amba_pv::amba_pv_control * ctrl,
             sc_core::sc_time & t) {

    unsigned long time_stamp = sc_core::sc_time_stamp().value();

    switch (address) {
        case IN_ADDR:

            /* Read pv_cnn source address register. This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid read access on source address "
                                  "register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            (* reinterpret_cast<unsigned int *>(data)) = m_pv_cnn_src_addr;
            std::cout << "[  SC DBG  ]\t" << name() << std::showbase << std::hex;
            std::cout << ": read pv_cnn source address register, returns ";
            std::cout << m_pv_cnn_src_addr << std::endl;
            break;
        case OUT_ADDR:

            /* Read pv_cnn destination address register.
             * This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid read access on destination address "
                                  "register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            (* reinterpret_cast<unsigned int *>(data)) = m_pv_cnn_dst_addr;
            std::cout << "[  SC DBG  ]\t" << name() << std::showbase << std::hex;
            std::cout << ": read pv_cnn destination address register, returns ";
            std::cout << m_pv_cnn_dst_addr << std::endl;
            break;  
        case WEIGHT_ADDR:

            /* Read pv_cnn length register. This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid read access on length register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            (* reinterpret_cast<unsigned int *>(data)) = m_pv_cnn_weight;
            std::cout << "[  SC DBG  ]\t" << name() << std::showbase << std::hex;
            std::cout << ": read pv_cnn length register, returns ";
            std::cout << m_pv_cnn_weight << std::endl;
            break;  

        case BAISE_ADDR:
            /* Read pv_cnn baise register. This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid read access on length register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            (* reinterpret_cast<unsigned int *>(data)) = m_pv_cnn_baise;
            std::cout << "[  SC DBG  ]\t" << name() << std::showbase << std::hex;
            std::cout << ": read pv_cnn BAISE_ADDR register, returns ";
            std::cout << m_pv_cnn_baise << std::endl;
            break;  

        case CONTROL: 

            /* Read pv_cnn control register. This register is 8 bits */
            if (size != 1) {
                SC_REPORT_WARNING(name(),
                                  "invalid read access on control register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            (* data) = m_pv_cnn_control;
            std::cout << "[  SC DBG  ]\t" << name() << std::showbase << std::hex;
            std::cout << ": read pv_cnn control register, returns ";
            std::cout << (int) m_pv_cnn_control << std::endl;
            break;

        case MONITOR1: 

            /* Read pv_cnn control register. This register is 8 bits */ /* cycle count */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid read access on monitor1 register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            (* data) = m_pv_cnn_monitor1;
            std::cout << "[  SC DBG Mon1 ]\t" << std::showbase << std::hex;
            std::cout << ": read pv_cnn monitor1 register, returns ";
            std::cout << (int) m_pv_cnn_monitor1 << std::endl;
            std::cout << "\t\t Time: " << time_stamp << std::endl;
            break;

        case MONITOR2: 

            /* Read pv_cnn control register. This register is 8 bits */  /* memory read count */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid read access on monicnn_stamptor2 register");
                return (amba_pv::AMBA_PV_SLVERR);            m_pv_cnn_src_addr = (* reinterpret_cast<unsigned int *>(data));

            }
//            (* data) = m_pv_cnn_monitor2;
            time_stamp = time_stamp - cnn_time_stamp;
            (* reinterpret_cast<unsigned int *>(data)) = time_stamp;

            std::cout << "[  SC DBG Mon2 ]\t" << std::showbase << " size: " << size << std::hex;
            std::cout << ": read pv_cnn monitor2 register, returns ";
            std::cout << (int) time_stamp << std::endl;
            cnn_time_stamp = time_stamp;

            break;

        case MONITOR3: // As CNN dataport, add SC time delay

            /* Read pv_cnn control register. This register is 8 bits */  /* memory write count */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid read access on monitor3 register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            (* data) = m_pv_cnn_monitor3;
            std::cout << "[  SC DBG Mon3 ]\t" << std::showbase << std::hex;
            std::cout << ": read pv_cnn monitor3 register, returns ";
            std::cout << (int) m_pv_cnn_monitor3 << std::endl;
            break;

        case MONITOR4: 

            /* Read pv_cnn control register. This register is 8 bits */  /* other count */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid read access on monitor4 register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            (* data) = m_pv_cnn_monitor4;
            std::cout << "[  SC DBG Mon4 ]\t" << std::showbase << std::hex;
            std::cout << ": read pv_cnn monitor4 register, returns ";
            std::cout << (int) m_pv_cnn_monitor4 << std::endl;

            break;

        default:       
            SCX_REPORT_WARNING(name(),
                               "cnn has received a read request with input "
                               "address out of range: %p", (void *) address);
            return (amba_pv::AMBA_PV_SLVERR);
    }
    return (amba_pv::AMBA_PV_OKAY);
}

/*
 * Write access
 */
amba_pv::amba_pv_resp_t
pv_cnn::write(int id,
              const addr_t & address,
              unsigned char * data,
              unsigned int size,
              const amba_pv::amba_pv_control * ctrl,
              unsigned char * strb, 
              sc_core::sc_time & t) {
    
    unsigned long time_stamp = sc_core::sc_time_stamp().value();

    switch (address) {
        case IN_ADDR:

            /* Write pv_cnn source address register. This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid write access on source address "
                                  "register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            m_pv_cnn_src_addr = (* reinterpret_cast<unsigned int *>(data));
            std::cout << "[  SC DBG  ]\t" << name() << std::showbase << std::hex;
            std::cout << ": write " << m_pv_cnn_src_addr;
            std::cout << " in pv_cnn source address register\n";
            break;
        case OUT_ADDR:

            /* Write pv_cnn destination address register.
             * This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid write access on destination address "
                                  "register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            m_pv_cnn_dst_addr = (* reinterpret_cast<unsigned int *>(data));
            std::cout << "[  SC DBG  ]\t" << name() << std::showbase << std::hex;
            std::cout << ": write " << m_pv_cnn_dst_addr;
            std::cout << " in pv_cnn destination address register\n";
            break;
        case WEIGHT_ADDR:

            /* Write pv_cnn weight register. This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid write access on weight register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            m_pv_cnn_weight = (* reinterpret_cast<unsigned int *>(data));
            std::cout << "[  SC DBG  ]\t" << name() << std::showbase << std::hex;
            std::cout << ": write " << m_pv_cnn_weight;
            std::cout << " in pv_cnn weight register\n";
            break;  

        case BAISE_ADDR:
            /* Write pv_cnn Baise register. This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid write access on baise register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            m_pv_cnn_baise = (* reinterpret_cast<unsigned int *>(data));
            std::cout << "[  SC DBG  ]\t" << name() << std::showbase << std::hex;
            std::cout << ": write " << m_pv_cnn_baise;
            std::cout << " in pv_cnn baise register\n";
            break;  

        case CONTROL:
            /* Write pv_cnn control register. This register is 8 bits */
            std::cout << "\t\t\t Write Control " << sc_core::sc_time_stamp().value() << std::endl;
            if (size != 1) {
                SC_REPORT_WARNING(name(),
                                  "invalid write access on control register");
                return (amba_pv::AMBA_PV_SLVERR);
            std::cout << "[  SC DBG  ]\t" << name() << std::showbase << std::hex;
            std::cout << ": write " << (unsigned int) (* data);
            std::cout << " in pv_cnn control register\n";
            }    
            if (((* data) & START) && (!( m_pv_cnn_control & START))) {
                m_start_transfer.notify(t);
                m_pv_cnn_control |= START;
                std::cout << "[  SC DBG  ]\t" << name() << ": pv_cnn started\n";
            }
            if ((!((* data) & IRQ)) && (m_pv_cnn_control & IRQ)) {
                m_pv_cnn_control &= ~IRQ;
                m_irq_to_change.notify(t);
            }
            break;

        case MONITOR1:
            /* Write pv_cnn length register. This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid write access on monitor1 register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            m_pv_cnn_monitor1 = (* reinterpret_cast<unsigned int *>(data));
            std::cout << "[  SC DBG Mon1 ]\t" << std::showbase << std::hex;
            std::cout << ": write " << m_pv_cnn_monitor1;
            std::cout << " in pv_cnn monitor1 register\n";
            std::cout << "\t\t Time: " << time_stamp << std::endl;
            break;  

        case MONITOR2:
            /* Write pv_cnn length register. This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid write access on monitor2 register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            m_pv_cnn_monitor2 = (* reinterpret_cast<unsigned int *>(data));
            std::cout << "[  SC DBG Mon2 ]\t" << std::showbase << std::hex;
            std::cout << ": write " << m_pv_cnn_monitor2;
            std::cout << " in pv_cnn monitor2 register\n";
            break;  

        case MONITOR3:
            /* Write pv_cnn length register. This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid write access on monitor3 register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            m_pv_cnn_monitor3 = (* reinterpret_cast<unsigned int *>(data));
            std::cout << "[  SC DBG Mon3 ]\t" << std::showbase << std::hex;
            std::cout << ": write " << m_pv_cnn_monitor3;
            std::cout << " in pv_cnn monitor3 register\n";
            break;  

        case MONITOR4:
            /* Write pv_cnn length register. This register is 32 bits */
            if (size != 4) {
                SC_REPORT_WARNING(name(),
                                  "invalid write access on monitor4 register");
                return (amba_pv::AMBA_PV_SLVERR);
            }
            m_pv_cnn_monitor4 = (* reinterpret_cast<unsigned int *>(data));
            std::cout << "[  SC DBG Mon4 ]\t" << std::showbase << std::hex;
            std::cout << ": write " << m_pv_cnn_monitor4;
            std::cout << " in pv_cnn monitor4 register\n";
            break;  

        default: 
            SCX_REPORT_WARNING(name(),
                               "CNN has received a write request with input "
                               "address out of range: %p", (void *) address);
            return (amba_pv::AMBA_PV_SLVERR);
    }
    return (amba_pv::AMBA_PV_OKAY);
}

/*
 * Debug read access
 */
unsigned int
pv_cnn::debug_read(int socket_id,
                   const addr_t & addr,
                   unsigned char * data,
                   unsigned int length,
                   const amba_pv::amba_pv_control * ctrl) {
    switch (addr) {      
        case IN_ADDR:

            /* Read pv_cnn source address register. This register is 32 bits */
            if (length != 4) {
                return 0;
            }
            (* reinterpret_cast<unsigned int *>(data)) = m_pv_cnn_src_addr;
            break;
        case OUT_ADDR:

            /* Read pv_cnn destination address register.
             * This register is 32 bits */
            if (length != 4) {
                return 0;
            }
            (* reinterpret_cast<unsigned int *>(data)) = m_pv_cnn_dst_addr;
            break;  
        case WEIGHT_ADDR:

            /* Read pv_cnn length register. This register is 32 bits */
            if (length != 4) {
                return 0;
            }
            (* reinterpret_cast<unsigned int *>(data)) = m_pv_cnn_weight;
            break;  
        case BAISE_ADDR:
            /* Read pv_cnn baise register. This register is 32 bits */
            if (length != 4) {
                return 0;
            }
            (* reinterpret_cast<unsigned int *>(data)) = m_pv_cnn_baise;
            break;  

        case CONTROL: 

            /* Read pv_cnn control register. This register is 8 bits */
            if (length != 1) {
                return 0;
            }
            (* data) = m_pv_cnn_control;
            break;
        default:       
            return 0;
    }
    return (length);
}

/*
 * Debug write access
 */
unsigned int
pv_cnn::debug_write(int socket_id,
                    const addr_t & addr,
                    unsigned char * data,
                    unsigned int length,
                    const amba_pv::amba_pv_control * ctrl) {
    switch (addr) {
        case IN_ADDR:

            /* Write pv_cnn source address register. This register is 32 bits */
            if (length != 4) {
                return 0;
            }
            m_pv_cnn_src_addr = (* reinterpret_cast<unsigned int *>(data));
            break;
        case OUT_ADDR:

            /* Write pv_cnn destination address register.
             * This register is 32 bits */
            if (length != 4) {
                return 0;
            }
            m_pv_cnn_dst_addr = (* reinterpret_cast<unsigned int *>(data));
            break;
        case WEIGHT_ADDR:

            /* Write CNN weight register */      
            if (length != 4) {
                return 0;
            }
            m_pv_cnn_weight = (* reinterpret_cast<unsigned int *>(data));
            break;  

        case BAISE_ADDR:

            /* Write CNN baise register */      
            if (length != 4) {
                return 0;
            }
            m_pv_cnn_baise = (* reinterpret_cast<unsigned int *>(data));
            break;  

        case CONTROL: 

            /* Write pv_cnn control register. This register is 8 bits */
            if (length != 1) {
                return 0;
            }
            if (((* data) & START) && (!( m_pv_cnn_control & START))) {
                m_pv_cnn_control |= START;
            }
            if ((!((* data) & IRQ)) && (m_pv_cnn_control & IRQ)) {
                m_pv_cnn_control &= ~IRQ;
            }
            break;
            
        default: 
            return 0;
    }
    return (length);
}

/*
 * Transfer end IRQ signal management
 */
void pv_cnn::irq() {
    if (m_pv_cnn_control & IRQ) {
        std::cout << "[  SC DBG  ]\t" << name() << ": rise end transfer IRQ \n";
        std::cout << "\t\t\t Raise Interrupt" << sc_core::sc_time_stamp().value() << std::endl;
        pv_cnn_irq_out.set_state(true);
    } else {
        std::cout << "[  SC DBG  ]\t" << name() << ": clear end transfer IRQ \n";
        pv_cnn_irq_out.set_state(false);  
    }
}

/*
 * CNN transfer management
 */
void pv_cnn::transfer() {
    static const size_t BURST_LENGTH = 16;
    amba_pv::amba_pv_resp_t status;
    sc_core::sc_time t = sc_core::SC_ZERO_TIME;

    std::cout << "[  SC DBG  ] CNN test \n";
    std::cout << "\t\t\t Transfer Time: " << sc_core::sc_time_stamp().value() << std::endl;

    if (m_pv_cnn_control & START) {
        if (m_pv_cnn_baise) {
            std::cout << "[  SC DBG  ] [ CNN ] \t" << name() << std::showbase << std::hex;
            std::cout << ": pv_cnn CNN started. Source address: ";
            std::cout << m_pv_cnn_src_addr << " - destination address: ";
            std::cout << m_pv_cnn_dst_addr << " - length: ";
            std::cout << m_pv_cnn_weight << " - weight: ";
            std::cout << m_pv_cnn_baise << " baise\n";
            /*
            * Starts the memory transfer...
            */

            size_t nb_word = 4 * 4 * 3;  // input size: 32bit x 32bit x RBG

            data_t * input = new data_t[nb_word];
            data_t * output = new data_t[nb_word];
            data_t * weight = new data_t[3 * 3];
            data_t * baise = new data_t[nb_word];

            status = amba_pv_m.burst_read(0,
                                        m_pv_cnn_weight,
                                        reinterpret_cast<unsigned char *>(weight),
                                        3 * 3,
                                        sizeof(data_t),
                                        NULL,
                                        amba_pv::AMBA_PV_INCR,
                                        t);
        /*
            if (status != amba_pv::AMBA_PV_OKAY) {
                SCX_REPORT_WARNING(
                    name(), 
                    "read weight failure at %p",
                    (void *) (m_pv_cnn_src_addr)
                );
                std::cout << std::endl;
            }
        */

            status = amba_pv_m.burst_read(0,
                                        m_pv_cnn_baise,
                                        reinterpret_cast<unsigned char *>(baise),
                                        3 * 3,
                                        sizeof(data_t),
                                        NULL,
                                        amba_pv::AMBA_PV_INCR,
                                        t);
        /*
            if (status != amba_pv::AMBA_PV_OKAY) {
                SCX_REPORT_WARNING(
                    name(), 
                    "read weight failure at %p",
                    (void *) (m_pv_cnn_src_addr)
                );
                std::cout << std::endl;
            }
        */

            for (size_t n = 0; (n < nb_word); n += BURST_LENGTH) {
                status = amba_pv_m.burst_read(0,
                                            m_pv_cnn_src_addr + (n * sizeof(data_t)),
                                            reinterpret_cast<unsigned char *>(input + n),
                                            sc_dt::sc_min(BURST_LENGTH, nb_word - n),
                                            sizeof(data_t),
                                            NULL,
                                            amba_pv::AMBA_PV_INCR,
                                            t);

                if (status != amba_pv::AMBA_PV_OKAY) {
                    SCX_REPORT_WARNING(name(),
                                    "read input failure at %p",
                                    (void *) (m_pv_cnn_src_addr + (n * sizeof(data_t))));
                    std::cout << std::endl;
                    continue;
                }

                //
                // MAC operation
                // input x weight --> output
                //
                output[n] = input[n] * weight[n] + baise[n];
                // Additional delay

                std::cout << "\t\t\t MAC " << AccDelay << ": " << sc_core::sc_time_stamp().value() << std::endl;
                for (unsigned int cycle = 0; (cycle < AccDelay); cycle++) {
                    m_start_transfer.notify(t);
//                    std::cout << "\t\t\t MAC " << sc_core::sc_time_stamp().value() << std::endl;
                }

                /* Write destination block */
                status = amba_pv_m.burst_write(0,
                                            m_pv_cnn_dst_addr + (n * sizeof(data_t)),
                                            reinterpret_cast<unsigned char *>(output + n),
                                            sc_dt::sc_min(BURST_LENGTH, nb_word - n),
                                            sizeof(data_t),
                                            NULL,
                                            amba_pv::AMBA_PV_INCR,
                                            NULL,
                                            0,
                                            t);

                if (status != amba_pv::AMBA_PV_OKAY) {
                    SCX_REPORT_WARNING(name(),
                                    "write memory failure at %p",
                                    (void *) (m_pv_cnn_dst_addr + (n * sizeof(data_t))));
                    continue;
                }

                if (status != amba_pv::AMBA_PV_OKAY) {
                    continue;
                }
            }

            delete [] input;
            delete [] weight;
            delete [] output;
            delete [] baise;

            /* Clear the START bit of the control register */
            m_pv_cnn_control &= ~START;

            /* Interrupt generation */
            if (! (m_pv_cnn_control & IRQ)) {
                m_pv_cnn_control |= IRQ;
                m_irq_to_change.notify(t);
            }
        }
        else {
        #if 1
            std::cout << "[  SC DBG  ] [ DMA]\t" << name() << std::showbase << std::hex;
            std::cout << ": pv_cnn transfer started. Source address: ";
            std::cout << m_pv_cnn_src_addr << " - destination address: ";
            std::cout << m_pv_cnn_dst_addr << " - length: " << std::dec;
            std::cout << m_pv_cnn_weight << " - weight: " << std::dec;
            std::cout << m_pv_cnn_baise << " baise\n";
        
            /*
            * Starts the memory transfer...
            */
            size_t nb_word = (m_pv_cnn_weight + sizeof(data_t) - 1)
                            / sizeof(data_t);
            data_t * tmp = new data_t[nb_word];
        
            for (size_t n = 0; (n < nb_word); n += BURST_LENGTH) {

                std::cout << "\t\t\t Transfer loop " << sc_core::sc_time_stamp().value() << std::endl;
                std::cout << "\t\t\t Transfer loop " << sc_core::sc_time_stamp().value() << std::endl;

                status = amba_pv_m.burst_read(0,
                                            m_pv_cnn_src_addr + (n * sizeof(data_t)),
                                            reinterpret_cast<unsigned char *>(tmp + n),
                                            sc_dt::sc_min(BURST_LENGTH, nb_word - n),
                                            sizeof(data_t),
                                            NULL,
                                            amba_pv::AMBA_PV_INCR,
                                            t);
                std::cout << "\t\t\t Transfer loop after read" << sc_core::sc_time_stamp().value() << std::endl;

                if (status != amba_pv::AMBA_PV_OKAY) {
                    SCX_REPORT_WARNING(name(),
                                    "read memory failure at %p",
                                    (void *) (m_pv_cnn_src_addr + (n * sizeof(data_t))));
                    std::cout << std::endl;
                    continue;
                }
                /* Output source bock using debug transactions.... */
                std::cout << "[  SC DBG  ]\t" << name() << std::dec
                        << ": source block ("
                        << sc_dt::sc_min(BURST_LENGTH, nb_word - n) * 8
                        << " bytes) at " << std::showbase << std::hex
                        << m_pv_cnn_src_addr + (n * sizeof(data_t))
                        << "\n";
                for (size_t i = 0;
                    (i < sc_dt::sc_min(BURST_LENGTH, nb_word - n));
                    i += 1) {
                    data_t tmp = 0xffffffff;

                    if (amba_pv_m.debug_read(m_pv_cnn_src_addr + (n + i) * sizeof(data_t),
                                            reinterpret_cast<unsigned char *>(&tmp),
                                            sizeof(tmp),
                                            NULL) != sizeof(tmp)) {
                        SCX_REPORT_WARNING(name(),
                                        "debug_read() memory failure at %p",
                                        (void *) ((n + i) * sizeof(data_t)));
                    }

                    std::cout << std::hex
                            << resetiosflags(std::ios_base::showbase);
                    if (! (i % 4)) {
                        std::cout << "\t0x"
                                << (m_pv_cnn_src_addr
                                    + ((n + i) * sizeof(data_t)));
                    }
                    std::cout << ": 0x" << std::setfill('0')
                            << std::setw(sizeof(data_t) * 2)
                            << tmp;
                    if (((i % 4) == 3)
                        || (i == (sc_dt::sc_min(BURST_LENGTH, nb_word - n) - 1))) {
                        std::cout << std::endl;
                    }
                }

                /* Write destination block */
                status = amba_pv_m.burst_write(0,
                                            m_pv_cnn_dst_addr + (n * sizeof(data_t)),
                                            reinterpret_cast<unsigned char *>(tmp + n),
                                            sc_dt::sc_min(BURST_LENGTH, nb_word - n),
                                            sizeof(data_t),
                                            NULL,
                                            amba_pv::AMBA_PV_INCR,
                                            NULL,
                                            0,
                                            t);
                std::cout << "\t\t\t Transfer loop after write" << sc_core::sc_time_stamp().value() << std::endl;

                if (status != amba_pv::AMBA_PV_OKAY) {
                    SCX_REPORT_WARNING(name(),
                                    "write memory failure at %p",
                                    (void *) (m_pv_cnn_dst_addr + (n * sizeof(data_t))));
                    continue;
                }

                /* Verify destination block */
                status = amba_pv_m.burst_read(0,
                                            m_pv_cnn_dst_addr + (n * sizeof(data_t)),
                                            reinterpret_cast<unsigned char *>(tmp + n),
                                            sc_dt::sc_min(BURST_LENGTH, nb_word - n),
                                            sizeof(data_t),
                                            NULL,
                                            amba_pv::AMBA_PV_INCR,
                                            t);

                if (status != amba_pv::AMBA_PV_OKAY) {
                    continue;
                }

                /* Output destination bock using debug transactions... */
                std::cout << "[  SC DBG  ]\t" << name() << std::dec
                        << ": destination block ("
                        << sc_dt::sc_min(BURST_LENGTH, nb_word - n) * 8
                        << " bytes) at " << std::showbase << std::hex
                        << m_pv_cnn_dst_addr + (n * sizeof(data_t))
                        << "\n";
                for (size_t i = 0;
                    (i < sc_dt::sc_min(BURST_LENGTH, nb_word - n));
                    i += 1) {
                    data_t tmp = 0xffffffff;

                    if (amba_pv_m.debug_read(m_pv_cnn_dst_addr+ (n + i) * sizeof(data_t),
                                            reinterpret_cast<unsigned char *>(&tmp),
                                            sizeof(tmp),
                                            NULL) != sizeof(tmp)) {
                        SCX_REPORT_WARNING(name(),
                                        "debug_read() memory failure at %p",
                                        (void *) ((n + i) * sizeof(data_t)));
                    }

                    std::cout << std::hex
                            << resetiosflags (std::ios_base::showbase);
                    if (! (i % 4)) {
                        std::cout << "\t0x"
                                << (m_pv_cnn_dst_addr
                                    + ((n + i) * sizeof(data_t)));
                    }
                    std::cout << ": 0x" << std::setfill('0')
                            << std::setw(sizeof(data_t) * 2)
                            << tmp;
                    if (((i % 4) == 3)
                        || (i == (sc_dt::sc_min(BURST_LENGTH, nb_word - n) - 1))) {
                        std::cout << std::endl;
                    }
                }
            }

            delete [] tmp;
    
            /* Clear the START bit of the control register */
            m_pv_cnn_control &= ~START;
        #endif
            /* Interrupt generation */
            if (! (m_pv_cnn_control & IRQ)) {
                m_pv_cnn_control |= IRQ;
                m_irq_to_change.notify(t);
            }
        }
    }
}

