/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2011-2014 ARM Limited.
 *
 * All rights reserved.
 */

#ifndef SCX_SIMULATION_CONTROLLER__H
#define SCX_SIMULATION_CONTROLLER__H

/* Includes */
#if defined(SG_TARGET_SYSTEMC)
    #include "GlobalDefs.h"
#endif

#include <systemc>
#include <list>

#include <TxLib/TxEvent.h>
#include <TxLib/TxMutex.h>
#include <scx/scx.h>

#include <sg/Singleton.h>
struct simulation_controller_mutexes
{
    TxMutex callbacks;
    TxMutex status;
};
static sg::Singleton<simulation_controller_mutexes> mutexes;

namespace sc_core
{
    enum sc_stop_mode;
    extern sc_stop_mode stop_mode;
}

/* Forward declarations */
namespace eslapi
{
    class CAInterface;
}
namespace scx
{
    class scheduler_mapping;
}

/* Namespaces */

/*
 * SystemC eXport support namespace.
 */
namespace scx {

/* Datatypes */

/*
 * Default simulation controller.
 */
class scx_simcontroller final : public scx_simcontrol_if {

    /* Construction */
    public:
        scx_simcontroller();
        ~scx_simcontroller();

    /* scx_simcontrol_if interface */
    private:

    /* Scheduler creation */
        eslapi::CAInterface* get_scheduler() override;

    /* Report handler creation */
        scx::scx_report_handler_if* get_report_handler() override;

    /* Simulation requests */
        void run() override;
        void stop() override;
        bool is_running() override;
        void shutdown() override;

    /* Simulation call-backs */
        void add_callback(scx_simcallback_if* callback_obj) override;
        void remove_callback(scx_simcallback_if* callback_obj) override;

    /* Simulation stop implementation */
        void stop_acknowledge(sg::SchedulerRunnable* runnable) override;

    /* Simulation debuggable implementation (when simulation at debuggable point) */
        void process_debuggable() override;

    /* Notifies that a debug activity has been added to the queue */
        virtual void notify_pending_debug();

    /* Simulation idle implementation (when simulation stopped) */
        void process_idle() override;

    /* Implementation */
    private:

        /* Typedefs */
        enum status_t { /* Simulation statuses */
            SCX_SHUTDOWN,
            SCX_RUNNING,
            SCX_RUN_REQUESTED,
            SCX_STOPPED
        };

        /* Member variables */
        TxEvent m_run_event;    /* Signals run simulation requested */
        status_t m_status;      /* Simulation status */
        TxMutex m_status_mutex; /* Mutex for simulation status */
        std::list<scx_simcallback_if *> m_callbacks;
            /* List of registered simulation call-backs */
        TxMutex m_callbacks_mutex;
            /* Mutex for list of registered simulation call-backs */
        eslapi::CAInterface * m_scheduler;
            /* Scheduler interface */
        bool m_clearStopRequest;    /* To not ignore run simulation request */
        unsigned int m_stop_period_ms; /* Period while simulation stopped */
        bool m_disable_idle;        /* Idle processing disabled? */

        /* Call-backs handling */
        void notify_stopped_all();
        void notify_running_all();
        void notify_idle_all();
        void notify_debuggable_all();

        /* Send stop request to scheduler */
        void scheduler_stop_request();
};

}   /* namespace scx */

#endif  /* defined(SCX_SIMULATION_CONTROLLER__H) */
