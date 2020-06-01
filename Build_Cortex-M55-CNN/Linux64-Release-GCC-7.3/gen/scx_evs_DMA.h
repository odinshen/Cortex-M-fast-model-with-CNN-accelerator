/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2011 - 2019 ARM Limited.
 *
 * All rights reserved.
 */

#ifndef scx_evs_DMA__H
#define scx_evs_DMA__H

/* Includes */
#include <sg/IncludeMeFirst.h>

#if defined (SG_TARGET_SCX_CADI) || ! defined(SG_BUILDING_DSO_DMA)
#if ! defined(SC_INCLUDE_DYNAMIC_PROCESSES)
#define SC_INCLUDE_DYNAMIC_PROCESSES
#endif
#include <sg/SystemCInclude.h>
#endif

#include <eslapi/eslapi_stdint.h>

#include <scx/scx.h>

/* Includes from the 'includes' section of the protocols */
#line 9 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/AMBAPVProtocol.lisa"

        #include <amba_pv.h>
    
#line 34 "./Linux64-Release-GCC-7.3/gen/scx_evs_DMA.h"


namespace DMA_NMS {

/* Forward declarations */
class AMBAPV_2D;
class AMBAPVSignal_2D;


/* Slave port classes TLM2 draft1*/
class sc_slave_port_class_irq_in: public amba_pv::signal_slave_base<bool>
{
public:
	sc_slave_port_class_irq_in(const std::string &portname);
	~sc_slave_port_class_irq_in();
	AMBAPVSignal_2D *sg_port;
	void set_state(int export_id, const bool& state);
};


/* Slave port classes TLM2 final */
class sc_slave_port_class_amba_pv_s: public amba_pv::amba_pv_slave_base<64>
{
public:
	sc_slave_port_class_amba_pv_s(const std::string &portname);
	~sc_slave_port_class_amba_pv_s();
	AMBAPV_2D *sg_port;
	amba_pv::amba_pv_resp_t read(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int size, const amba_pv::amba_pv_control* ctrl, sc_core::sc_time& t);
	amba_pv::amba_pv_resp_t write(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int size, const amba_pv::amba_pv_control* ctrl, unsigned char* strb, sc_core::sc_time& t);
	unsigned int debug_read(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int length, const amba_pv::amba_pv_control* ctrl);
	unsigned int debug_write(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int length, const amba_pv::amba_pv_control* ctrl);
	void b_transport(int socket_id, amba_pv::amba_pv_transaction& trans, sc_core::sc_time& t);
	unsigned int transport_dbg(int socket_id, amba_pv::amba_pv_transaction& trans);
	bool get_direct_mem_ptr(int socket_id, amba_pv::amba_pv_transaction& trans, tlm::tlm_dmi& dmi_data);
};


/* Master port clases TLM2 final */
class sc_master_port_class_amba_pv_m: public amba_pv::amba_pv_master_base
{
public:
	sc_master_port_class_amba_pv_m(const std::string &portname);
	~sc_master_port_class_amba_pv_m();
	AMBAPV_2D *sg_port;
	void invalidate_direct_mem_ptr(int socket_id, sc_dt::uint64 start_range, sc_dt::uint64 end_range);
};


/* System C wrapper class */
class scx_evs_DMA:
    public sc_core::sc_module,
    public scx::scx_evs_base {

        /* Ports */
    public:

        /* Slave ports TLM2 final */
	amba_pv::amba_pv_slave_socket<64> amba_pv_s;
	sc_slave_port_class_amba_pv_s sc_slave_port_amba_pv_s;


        /* Slave ports TLM2 draft 1 and TLM 1 (Signal port interfaces) */
	amba_pv::signal_slave_export<bool> irq_in;
	sc_slave_port_class_irq_in sc_slave_port_irq_in;


        /* Master ports TLM2 final */
	amba_pv::amba_pv_master_socket<64> amba_pv_m;
	sc_master_port_class_amba_pv_m sc_master_port_amba_pv_m;


        /* Master ports TLM2 draft 1 and TLM 1 (Signal port interfaces ) */
	amba_pv::signal_master_port<bool> irq_out;
	AMBAPVSignal_2D *sg_master_port_irq_out;


    /* Construction */
        explicit scx_evs_DMA(sc_core::sc_module_name);
        ~scx_evs_DMA() override;

    /* sc_object override-ables */
        const char * kind() const override;

    /* Implementation */
    protected:

        /* sc_module override-ables */
        void before_end_of_elaboration() override;
        void end_of_elaboration() override;
        void start_of_simulation() override;
        void end_of_simulation() override;
};

#if defined(SG_TARGET_SCX_CADI)
void scx_evs_DMA_create_sim_thread();
#endif

}   /* namespace DMA_NMS */

using DMA_NMS::scx_evs_DMA;

#endif  /* defined(scx_evs_DMA__H) */
