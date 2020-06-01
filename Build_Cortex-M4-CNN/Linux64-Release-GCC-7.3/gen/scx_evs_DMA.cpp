/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2011, 2014 - 2019 ARM Limited.
 *
 * All rights reserved.
 */

/* Includes */
#if defined (SG_TARGET_SCX_CADI)
#include "scx_thread_control.h"
#include <sg/FmEnvironmentVariables.h>
#endif // #if defined (SG_TARGET_SCX_CADI)

#include "scx_evs_DMA.h"

#if defined(SG_TARGET_SCX_CADI)
// the thread control structure is static and scoped to this file
// all thread synchronization must happen only in this file
static scx_thread_control_t scx_thread_control;
#endif // #if defined(SG_TARGET_SCX_CADI)



#include "AMBAPV_2D_ClassDef.h"
#include "AMBAPVSignal_2D_ClassDef.h"


namespace DMA_NMS {

/* Externs */
extern sg::ComponentFactory * DMA_GetFactory();

/* Functions */

/*
 * Slave port class constructors TLM2 draft 1 and Signal Protocols (TLM1).
 */
sc_slave_port_class_irq_in::sc_slave_port_class_irq_in(const std::string &portname): amba_pv::signal_slave_base<bool>(portname.c_str())
{
	sg_port = new AMBAPVSignal_2D;
}


/*
 * Slave port class constructors TLM2 final.
 */
sc_slave_port_class_amba_pv_s::sc_slave_port_class_amba_pv_s(const std::string &portname): amba_pv::amba_pv_slave_base<64>(portname.c_str())
{
	sg_port = new AMBAPV_2D;
}


/*
 * Slave port class destructors. TLM2 draft 1 and Signal Protocols (TLM1).
 */
sc_slave_port_class_irq_in::~sc_slave_port_class_irq_in()
{
	delete sg_port;
}


/*
 * Slave port class destructors TLM2 final.
 */
sc_slave_port_class_amba_pv_s::~sc_slave_port_class_amba_pv_s()
{
	delete sg_port;
}


/*
 * Master port class constructors TLM2 final.
 */
sc_master_port_class_amba_pv_m::sc_master_port_class_amba_pv_m(const std::string &portname): amba_pv::amba_pv_master_base(portname.c_str())
{
	sg_port = new AMBAPV_2D;
}


/*
 * Master port class destructors TLM2 final.
 */
sc_master_port_class_amba_pv_m::~sc_master_port_class_amba_pv_m()
{
	delete sg_port;
}


/*
 * Constructor.
 */
scx_evs_DMA::scx_evs_DMA(sc_core::sc_module_name name_):
    sc_core::sc_module(name_),
    scx::scx_evs_base(sc_core::sc_module::name(), DMA_GetFactory())
,amba_pv_s("amba_pv_s")
,sc_slave_port_amba_pv_s("amba_pv_s_sc")

,irq_in("irq_in_sc")
,sc_slave_port_irq_in("irq_in")

,amba_pv_m("amba_pv_m")
,sc_master_port_amba_pv_m("amba_pv_m_sc")

,irq_out("irq_out_sc")
 {

    

    /* Allocate Master ports  */
    	publish_master_port("sg_master_port_amba_pv_m", * sc_master_port_amba_pv_m.sg_port);
	sg_master_port_irq_out = new AMBAPVSignal_2D;
	publish_master_port("sg_master_port_irq_out", * sg_master_port_irq_out);


    /* Bind slave exports to slave_base implementations TLM2 draft1*/
    	irq_in(sc_slave_port_irq_in);
	publish_slave_port("irq_in", *(sc_slave_port_irq_in.sg_port));


    /* Bind slave exports to slave_base implementations TLM2 final*/
    	amba_pv_s(sc_slave_port_amba_pv_s);
	publish_slave_port("amba_pv_s", *(sc_slave_port_amba_pv_s.sg_port));


    /* Bind master sockets to master base implementation (TLM2 final) */
    	amba_pv_m(sc_master_port_amba_pv_m);
	publish_master_port("amba_pv_m", *(sc_master_port_amba_pv_m.sg_port));

}

/*
 * Destructor.
 */
scx_evs_DMA::~scx_evs_DMA() {
    /* free master port pointers (TLM2 draft1) */
    	delete sg_master_port_irq_out;

}

/*
 * sc_module override-able.
 * Returns the kind string of this SystemGenerator sub-system SystemC
 * wrapper.
 */
const char * scx_evs_DMA::kind() const {
    return "scx_evs_DMA";
}

/*
 * sc_module override-able.
 * Triggered before end of elaboration.
 */
void scx_evs_DMA::before_end_of_elaboration() {
    scx::scx_evs_base::before_end_of_elaboration();

    /* Bind master ports (must be done after the exported subsystem has been
     * created) and slave ports TLM2 draft 1  */
    	sc_slave_port_irq_in.sg_port->connectTo(find_sg_port("irq_in"));
	find_sg_port("irq_out").connectTo(*(sg_master_port_irq_out));
	bind_method(*(sg_master_port_irq_out), set_state, (&amba_pv::signal_master_port<bool>::set_state), &irq_out);


    /* TLM2 final (bind slave ports) */
    	sc_slave_port_amba_pv_s.sg_port->connectTo(find_sg_port("amba_pv_s"));
	bind_method(*(sc_slave_port_amba_pv_s.sg_port), invalidate_direct_mem_ptr, (&amba_pv::amba_pv_slave_socket<64>::invalidate_direct_mem_ptr), &amba_pv_s);


    /* TLM2 final (bind master ports) */
    	find_sg_port("amba_pv_m").connectTo(*(sc_master_port_amba_pv_m.sg_port));
	bind_method(*(sc_master_port_amba_pv_m.sg_port), read, (&amba_pv::amba_pv_master_socket<64>::read), &amba_pv_m);
	bind_method(*(sc_master_port_amba_pv_m.sg_port), write, (&amba_pv::amba_pv_master_socket<64>::write), &amba_pv_m);
	bind_method(*(sc_master_port_amba_pv_m.sg_port), debug_read, (&amba_pv::amba_pv_master_socket<64>::debug_read), &amba_pv_m);
	bind_method(*(sc_master_port_amba_pv_m.sg_port), debug_write, (&amba_pv::amba_pv_master_socket<64>::debug_write), &amba_pv_m);
	bind_method(*(sc_master_port_amba_pv_m.sg_port), b_transport, (&amba_pv::amba_pv_master_socket<64>::b_transport), &amba_pv_m);
	bind_method(*(sc_master_port_amba_pv_m.sg_port), transport_dbg, (&amba_pv::amba_pv_master_socket<64>::transport_dbg), &amba_pv_m);
	bind_method(*(sc_master_port_amba_pv_m.sg_port), get_direct_mem_ptr, (&amba_pv::amba_pv_master_socket<64>::get_direct_mem_ptr), &amba_pv_m);

}

/*
 * sc_module override-able.
 * Triggered after elaboration.
 */
void scx_evs_DMA::end_of_elaboration() {
    scx::scx_evs_base::end_of_elaboration();
}

/*
 * sc_module override-able.
 * Triggered before simulation.
 */
void scx_evs_DMA::start_of_simulation() {
    scx::scx_evs_base::start_of_simulation();

#if defined(SG_TARGET_SCX_CADI)
    // Notify the application thread that
    // systemc start of simulation is complete
    scx_thread_control.notify_simulation_started();
#endif // #if defined (SG_TARGET_SCX_CADI)
}

/*
 * sc_module override-able.
 * Triggered after simulation.
 */
void scx_evs_DMA::end_of_simulation()
{
    scx::scx_evs_base::end_of_simulation();
#if defined(SG_TARGET_SCX_CADI)
    scx_thread_control.notify_simulation_ended();
#endif // #if defined (SG_TARGET_SCX_CADI)
}

/*
 * Slave port wrapper functions.
 *
 * TLM2 draft 1 and for signals
 */
void sc_slave_port_class_irq_in::set_state(int export_id, const bool& state)
{
	return sg_port->set_state(export_id, state);
}



/*
 * Slave port wrapper functions.
 *
 * TLM2 final and for signals.
 */
amba_pv::amba_pv_resp_t sc_slave_port_class_amba_pv_s::read(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int size, const amba_pv::amba_pv_control* ctrl, sc_core::sc_time& t)
{
	return sg_port->read(socket_id, addr, data, size, ctrl, t);
}

amba_pv::amba_pv_resp_t sc_slave_port_class_amba_pv_s::write(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int size, const amba_pv::amba_pv_control* ctrl, unsigned char* strb, sc_core::sc_time& t)
{
	return sg_port->write(socket_id, addr, data, size, ctrl, strb, t);
}

unsigned int sc_slave_port_class_amba_pv_s::debug_read(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int length, const amba_pv::amba_pv_control* ctrl)
{
	return sg_port->debug_read(socket_id, addr, data, length, ctrl);
}

unsigned int sc_slave_port_class_amba_pv_s::debug_write(int socket_id, const sc_dt::uint64& addr, unsigned char* data, unsigned int length, const amba_pv::amba_pv_control* ctrl)
{
	return sg_port->debug_write(socket_id, addr, data, length, ctrl);
}

void sc_slave_port_class_amba_pv_s::b_transport(int socket_id, amba_pv::amba_pv_transaction& trans, sc_core::sc_time& t)
{
	return sg_port->b_transport(socket_id, trans, t);
}

unsigned int sc_slave_port_class_amba_pv_s::transport_dbg(int socket_id, amba_pv::amba_pv_transaction& trans)
{
	return sg_port->transport_dbg(socket_id, trans);
}

bool sc_slave_port_class_amba_pv_s::get_direct_mem_ptr(int socket_id, amba_pv::amba_pv_transaction& trans, tlm::tlm_dmi& dmi_data)
{
	return sg_port->get_direct_mem_ptr(socket_id, trans, dmi_data);
}



/*
 * Master port wrapper functions.
 *
 * TLM2 final.
 */
void sc_master_port_class_amba_pv_m::invalidate_direct_mem_ptr(int socket_id, sc_dt::uint64 start_range, sc_dt::uint64 end_range)
{
	return sg_port->invalidate_direct_mem_ptr(socket_id, start_range, end_range);
}



#if defined(SG_TARGET_SCX_CADI)
static void DMA_scx_entry_point()
{
    // No arguments (parameters) are passed at this point as the parameters
    // will be passed by the CADI Simulation Factory interface "instantiate"
    int    argc = 0;
    char** argv = nullptr;
    auto   rc   = sc_core::sc_elab_and_sim(argc, argv);
    if (rc != 0)
    {
        std::cerr << "ERROR: Simulation was not successful\n";
    }
}

void scx_evs_DMA_create_sim_thread()
{
    // If a systemc simulation is released and then reinstantiated,
    // we want to make sure that the reinstantiation happens after
    // the previous systemc instance is properly released (via cadibroker->Release)
    // if the previous cadi session was properly ended or if this is going
    // to be the first cadi session (first request for cadi broker),
    // scx_thread_control's thread state should be in "init".
    assert(scx_thread_control.in_initial_state());

    scx_thread_control.sim_thread = std::thread { &DMA_NMS::DMA_scx_entry_point };

    // wait until the simulation thread is created
    // and scx_initialise and platform instantiation are done
    scx_thread_control.wait_for_evs_instantiated();

    // now scx_initialize and platform instantiation are complete
    // which also means, by now, scxsimulationengine has built the parameter
    // and target info list. Now it's ok to return to the cadi user
    // with handle to CADIBroker (so that user can query param info)
}
#endif // #if defined(SG_TARGET_SCX_CADI)

}   /* namespace DMA_NMS */

#if defined(SG_TARGET_SCX_CADI)
static void disable_sysc_actions(sc_core::sc_severity severity_, sc_core::sc_actions actions_)
{
    auto actions = sc_core::sc_report_handler::set_actions(severity_);
    actions &= ~actions_;
    sc_core::sc_report_handler::set_actions(severity_, actions);
}

static void disable_terminating_sysc_actions()
{
    if (!sg::is_env_present("FM_SCX_DISABLE_NON_DEFAULT_SYSC_ACTIONS"))
    {
        // disable SystemC from calling abort() or throwing an exception on errors
        // and fatal errors -> Simulation Engine has its own handler
        disable_sysc_actions(::sc_core::SC_FATAL, ::sc_core::SC_ABORT | ::sc_core::SC_THROW);
        disable_sysc_actions(::sc_core::SC_ERROR, ::sc_core::SC_ABORT | ::sc_core::SC_THROW);
    }
}

int sc_main(int, char**)
{
    const double quantum     = 1.0;
    const double latency     = 100.0;
    const double per_period  = 100000000.0;
    int          return_code = 1;

    sg::set_env_non_empty_value("FM_SCX_DISABLE_BANNER", "1");
    sc_core::sc_report_handler::force(sc_core::SC_DISPLAY);

    if (!sg::is_env_present("FASTSIM_DISABLE_TA"))
    {
        sg::set_env_non_empty_value("FASTSIM_DISABLE_TA", "1");
    }

    scx::scx_initialize("DMA", scx::scx_get_default_simcontrol());
    scx::scx_set_single_evs();

    disable_terminating_sysc_actions();

    /*
     * Exported platform
     */
    scx_evs_DMA platform("DMA");

    /* Simulation quantum, i.e. seconds to run per quantum */
    tlm::tlm_global_quantum::instance().set(sc_core::sc_time(quantum / per_period,
                                                             sc_core::SC_SEC));

    /* Simulation minimum synchronization latency */
    scx::scx_set_min_sync_latency(latency / per_period);

    scx::scx_start_cadi_server(false /* cadiServer */, false /* runSimulation */, true /* debugOnly */);

    // Notify the application thread that scx_initialize and
    // platform instantiate are complete and the cadi interface can
    // now return the cadibroker handle back to the dll user
    scx_thread_control.notify_evs_instantiated();

    // Wait until CADISimulation is instantiated in the application thread, so that
    // sc_start can be invoked to instantiate the systemc simulation
    scx_thread_control.wait_for_simulation_resumed();

    try
    {
        sc_core::sc_start();
        return_code = 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "ERROR: uncaught exception occured. Exception message follows:" << std::endl;
        std::cerr << e.what() << std::endl << std::flush;
    }
    catch (...)
    {
        std::cerr << "ERROR: uncaught exception occured. Terminating program!" << std::endl << std::flush;
    }

    return return_code;
}

namespace scx
{
    // called from SCXCADISimulation constructor (from application thread)
    // to allow simulation thread to resume and invoke sc_start
    void scx_sim_thread_resume()
    {
        // Let the simulation thread to resume and invoke sc_start()
        scx_thread_control.notify_resumed();

        // wait for start_of_simulation of sc_thread is called and completed.
        scx_thread_control.wait_for_simulation_started();

        // systemc start of simulation phase is complete. It's now ok
        // to give the cadisimulation handle to the user.
    }

    // Typically called after sc_stop has been triggered from the simulation engine
    // in order to let the application thread know that the simulation thread has ended.
    void scx_sim_thread_join()
    {
        scx_thread_control.sim_thread.join();
        scx_thread_control.reset();
    }
} /* namespace scx */
#endif // #if defined(SG_TARGET_SCX_CADI)

/* End of file */
