/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2011-2012, 2014 ARM Limited.
 * All rights reserved.
 */

/* Includes */
#include "scx_simcontroller.h"
#include "TxLib/TxCriticalSection.h"

#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <chrono>

#include <sg/SGSchedulerInterfaceForComponents.h>

/* Namespaces */

/*
 * SystemC eXport support namespace.
 */
namespace scx {

/* Globals - Simulation controller */

/* Pointer to unique instance of simulation controller. */
static scx_simcontrol_if * default_simcontrol_ptr = NULL;

/* Functions */

/*
 * Constructs a new simulation controller.
 */
scx_simcontroller::scx_simcontroller():
    m_run_event(0, 0),
    m_status(SCX_RUNNING),
    m_scheduler(NULL),
    m_clearStopRequest(false),
    m_stop_period_ms(20),
    m_disable_idle(std::getenv("FM_SCX_DISABLE_IDLE") != NULL) {

    /* Process environmental settings */
    const char * stop_period_str = std::getenv("FM_SCX_STOP_PERIOD");

    if (stop_period_str != NULL) {
        m_stop_period_ms = std::max(1, std::atoi(stop_period_str));
    }
}

/*
 * Destructs this simulation controller.
 */
scx_simcontroller::~scx_simcontroller() {
    delete m_scheduler;
    m_scheduler = NULL;
    default_simcontrol_ptr = NULL;
}

/*
 * Returns a pointer to the current implementation of the simulation scheduler.
 */
inline eslapi::CAInterface *
scx_simcontroller::get_scheduler() {
    if (m_scheduler == NULL) {
        m_scheduler = scx_create_default_scheduler_mapping(this);
    }
    return (m_scheduler);
}

/*
 * Returns a pointer to the current implementation of the report handler.
 *
 * This version of the function returns the default implementation provided with
 * Fast Models.
 */
scx_report_handler_if *
scx_simcontroller::get_report_handler() {
    return (scx_get_default_report_handler());
}

/*
 * Requests to run the simulation.
 */
void
scx_simcontroller::run() {
    SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scx_simcontroller", "run()");

    /* Run simulation requested */
    TxCriticalSection lock(mutexes->status,"status mutex for simcontroller.run");

    if (m_status == SCX_STOPPED) {
        m_status = SCX_RUN_REQUESTED;
        m_run_event.SetEvent();
    } else if (m_status == SCX_RUNNING) {

        /* Clear previous stop request, else run() could be ignored */
        m_clearStopRequest = true;
    }
}

/*
 * Requests to stop the simulation as soon as possible, that is at the next
 * \c wait().
 */
void
scx_simcontroller::stop() {
    SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scx_simcontroller", "stop()");

    /* Stop simulation requested */
    TxCriticalSection lock(mutexes->status,"status mutex for simcontroller.stop");

    if (m_status == SCX_RUNNING) {
        scheduler_stop_request();

        /* Do not clear previous stop request, else stop() could be ignored */
        m_clearStopRequest = false;
    }
}

/*
 * Returns whether the simulation is running.
 */
bool
scx_simcontroller::is_running() {
    status_t status;

    /* Retrieve status */
    {
        TxCriticalSection lock(mutexes->status,"status mutex for simcontroller.status");

        status = m_status;
    }
    return (sc_core::sc_is_running() && (status == SCX_RUNNING));
}

/*
 * Requests to shutdown the simulation.
 */
void
scx_simcontroller::shutdown() {
    SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scx_simcontroller", "shutdown()");

    /* Shutdown simulation requested */
    TxCriticalSection lock(mutexes->status,"status mutex for simcontroller.shutdown");

    /* Stops SystemC simulation if not stopped already */
    if (m_status != SCX_SHUTDOWN) {

        /* Issue a stop request first, otherwise it could be ignored */
        if (m_status == SCX_RUNNING) {
            scheduler_stop_request();
        }

        /* Run next, otherwise it could deadlock */
        if (m_status == SCX_STOPPED) {
            m_run_event.SetEvent();
        }

        /* Shutdown... */
        m_status = SCX_SHUTDOWN;

        /* Disable the warning about sc_stop() being already called.
         * (We do this as we have no means to test whether something else,
         * for instance a slave, has already called sc_stop() and we are thus
         * called as part of the end_of_simulation() call-backs.) */
        sc_core::sc_actions a = sc_core::sc_report_handler::set_actions(
                sc_core::SC_ID_SIMULATION_STOP_CALLED_TWICE_,
                sc_core::SC_DO_NOTHING);
        sc_core::sc_stop();
        sc_core::sc_report_handler::set_actions(
                sc_core::SC_ID_SIMULATION_STOP_CALLED_TWICE_,
                a);
    }
}

/*
 * Registers call-backs with this simulation controller.
 */
void
scx_simcontroller::add_callback(scx_simcallback_if * callback_obj) {
    if (callback_obj != NULL) {
        TxCriticalSection lock(mutexes->callbacks,"callbacks mutex for simcontroller.add_callback");

        m_callbacks.push_back(callback_obj);
    }
}

/*
 * Removes call-backs from this simulation controller.
 */
void
scx_simcontroller::remove_callback(scx_simcallback_if * callback_obj) {
    TxCriticalSection lock(mutexes->callbacks,"callbacks mutex for simcontroller.remove_callback");

    m_callbacks.remove(callback_obj);
}

/*
 * Block simulation while simulation is stopped.
 */
void
scx_simcontroller::stop_acknowledge(sg::SchedulerRunnable * runnable) {
    SCX_REPORT_INFO_VERB(SCX_DEBUG,
                         "scx::scx_simcontroller",
                         "stop_acknowledge(runnable=%p)",
                         runnable);

    mutexes->status.lock();

    /* Simulation running? */
    if (m_status == SCX_RUNNING) {

        /* Update status */
        m_status = SCX_STOPPED;

        /* Notify all clients
         * Unless stop request cleared by a simulation run request */
        if (! m_clearStopRequest) {
            mutexes->status.unlock();
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scx_simcontroller", "stopped");
            notify_stopped_all();
            mutexes->status.lock();
        }
    }

    /* Clear stop request (1) */
    mutexes->status.unlock();
    if (runnable != NULL) {
        runnable->clearStopRequest();
    }
    mutexes->status.lock();

    /* Simulation stopped? */
    if (m_status == SCX_STOPPED) {

        /* Wait for run simulation request
         * Unless stop request cleared by a simulation run request */
        if (! m_clearStopRequest) {
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scx_simcontroller", "debuggable");

            /* Allow processing of potentially pending idle and debug activity.
               Note this loop exits with mutex locked. */
            auto last_process_idle = std::chrono::system_clock::now();
            while (m_status == SCX_STOPPED) {
                mutexes->status.unlock();
                m_run_event.TimedWait(m_stop_period_ms);
                process_debuggable();
                /* Check the time since the last process_idle call to avoid calling process_idle() too
                   often in the case when wait is interrupted by debug requests. */
                if (! m_disable_idle &&
                    std::chrono::duration_cast<std::chrono::milliseconds>
                    (std::chrono::system_clock::now()-last_process_idle).count() > m_stop_period_ms) {
                    process_idle();
                    last_process_idle = std::chrono::system_clock::now();
                }
                mutexes->status.lock();
            }
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scx_simcontroller", "running");
        }

        /* Update status */
        if (m_status == SCX_RUN_REQUESTED || m_status == SCX_STOPPED) {
            m_status = SCX_RUNNING;

            /* Notify all clients */
            mutexes->status.unlock();
            notify_running_all();
            mutexes->status.lock();
        }
    }

    /* Clear stop request (2) */
    m_clearStopRequest = false;

    /* Simulation shutdown? */
    if (m_status == SCX_SHUTDOWN) {
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scx_simcontroller", "shutdown");

        /* Issue a wait(0) so the SystemC scheduler gets a chance to pick up
         * the sc_stop().
         * (If we do not do this the models will just keep on calling
         * stop_ackowledge() in an endless loop if they do not wait() in the
         * meantime by chance.) */
        mutexes->status.unlock();
        sc_core::wait(sc_core::SC_ZERO_TIME);
        return;
    }
    mutexes->status.unlock();
}

/*
 * Process any potentially pending idle activity.
 */
void
scx_simcontroller::process_idle() {
    if (! m_disable_idle) {
        notify_idle_all();
    } else {
        static bool info_idle_disabled = true;

        if (info_idle_disabled) {
            info_idle_disabled = false;
            SCX_REPORT_INFO("scx::scx_simcontroller",
                            "process_idle() disabled as FM_SCX_DISABLE_IDLE "
                            "was defined");
        }
    }
}

/*
 * Process any potentially pending debug activity.
 */
void
scx_simcontroller::process_debuggable() {
    notify_debuggable_all();
}

/*
 * Notifies that a debug activity has been added to the queue.
 */
void
scx_simcontroller::notify_pending_debug() {
    m_run_event.SetEvent();
}

/*
 * Notify all clients simulation has stopped.
 */
void
scx_simcontroller::notify_stopped_all() {
    std::list<scx_simcallback_if *> tmpCallbacks;

    /* 1) Take a copy of call-backs list */
    {
        TxCriticalSection lock(mutexes->callbacks,"callback mutex for simcontroller.notify_stopped_all");

        tmpCallbacks = m_callbacks;
    }

    /* 2) Use copy to notify clients */
    std::list<scx_simcallback_if *>::iterator i;

    for (i = tmpCallbacks.begin(); (i != tmpCallbacks.end()); i ++) {
        (* i)->notify_stopped();
    }
}

/*
 * Notify all clients simulation is running.
 */
void
scx_simcontroller::notify_running_all() {
    std::list<scx_simcallback_if *> tmpCallbacks;

    /* 1) Take a copy of call-backs list */
    {
        TxCriticalSection lock(mutexes->callbacks,"callback mutex for simcontroller.tmpCallbacks");

        tmpCallbacks = m_callbacks;
    }

    /* 2) Use copy to notify clients */
    std::list<scx_simcallback_if *>::iterator i;

    for (i = tmpCallbacks.begin(); (i != tmpCallbacks.end()); i ++) {
        (* i)->notify_running();
    }
}

/*
 * Notify all clients simulation is at debuggable point.
 */
void
scx_simcontroller::notify_debuggable_all() {
    std::list<scx_simcallback_if *> tmpCallbacks;

    /* 1) Take a copy of call-backs list */
    {
        TxCriticalSection lock(mutexes->callbacks,"callback mutex for simcontroller.notify_debuggable_all");

        tmpCallbacks = m_callbacks;
    }

    /* 2) Use copy to notify clients */
    std::list<scx_simcallback_if *>::iterator i;

    for (i = tmpCallbacks.begin(); (i != tmpCallbacks.end()); i ++) {
        (* i)->notify_debuggable();
    }
}

/*
 * Notify all clients simulation is idle.
 */
void
scx_simcontroller::notify_idle_all() {
    std::list<scx_simcallback_if *> tmpCallbacks;

    /* 1) Take a copy of call-backs list */
    {
        TxCriticalSection lock(mutexes->callbacks,"callbacks mutex for simcontroller.notify_idle_all");

        tmpCallbacks = m_callbacks;
    }

    /* 2) Use copy to notify clients */
    std::list<scx_simcallback_if *>::iterator i;

    for (i = tmpCallbacks.begin(); (i != tmpCallbacks.end()); i ++) {
        (* i)->notify_idle();
    }
}

/*
 * Send stopRequest() to scheduler.
 */
void
scx_simcontroller::scheduler_stop_request()
{
    sg::SchedulerInterfaceForComponents * scheduler = scx_get_curr_scheduler_mapping();

    if (scheduler) {
        scheduler->stopRequest();
    }
}

/*
 * Returns a pointer to the default implementation of the simulation controller
 * provided with Fast Models.
 */
scx_simcontrol_if * scx_get_default_simcontrol() {
    if (default_simcontrol_ptr == NULL) {
        static scx_simcontroller default_simcontroller;

        default_simcontrol_ptr = & default_simcontroller;
    }
    return (default_simcontrol_ptr);
}

}   /* namespace scx */
