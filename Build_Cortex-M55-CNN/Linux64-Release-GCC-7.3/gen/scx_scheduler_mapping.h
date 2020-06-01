/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2011-2016 ARM Limited.
 * All rights reserved.
 */

#ifndef SCX_SCHEDULER_MAPPING__H
#define SCX_SCHEDULER_MAPPING__H

/* Includes */
#if defined(SG_TARGET_SYSTEMC)
    #include "GlobalDefs.h"
#endif

#include <systemc>
#include <list>
#include <queue>
#include <functional>
#include <thread>
#include <unordered_map>

#include <sg/SGSchedulerInterfaceForComponents.h>
#include <eslapi/CAInterfaceRegistry.h>
#include <TxLib/TxMutex.h>
#include <scx_sc_time_from_value.h>

/* Forwards */
namespace eslapi
{
class CAInterface;
}

namespace scx
{

// Simulation controller interface
class scx_simcontrol_if;

/* Internal classes */
class async_request;
class scheduler_mapping_Timer;
class scheduler_mapping_sc_thread;
class scheduler_mapping_sc_method;
class scheduler_mapping_sc_event;
class scheduler_mapping_Thread;
class scheduler_mapping_ThreadSignal;
class clear_stop_request_proxy_class;

/* common helper functions */

inline sc_core::sc_time simulated_time_from_ticks(sg::ticks_t ticks)
{
    return scx_sc_time_from_value(ticks);
}

/* Datatypes */

/*
 * Scheduler implementation.
 */
class scheduler_mapping final : public sg::SchedulerInterfaceForComponents
{

// Constructor and destructor
public:
    explicit scheduler_mapping(scx_simcontrol_if *);
    virtual ~scheduler_mapping();

// CAInterface Implementation
private:
    virtual eslapi::CAInterface * ObtainInterface(eslapi::if_name_t, eslapi::if_rev_t, eslapi::if_rev_t *);

// sg::SchedulerInterfaceForComponents interface, used by components
private:
    virtual sg::Timer * createTimer(const char *, sg::TimerCallback *);
    virtual sg::SchedulerThread * createThread(const char *, sg::SchedulerRunnable *);
    virtual sg::SchedulerThread * currentThread();
    sg::SchedulerRunnable * currentRunnable();
    virtual sg::ThreadSignal * createThreadSignal(const char *);
    virtual void wait(sg::ticks_t);
    virtual void wait(sg::ThreadSignal *);
    virtual void setGlobalQuantum(sg::ticks_t);
    virtual sg::ticks_t getGlobalQuantum(sg::Tag<sg::ticks_t> *)
    {
        return tlm::tlm_global_quantum::instance().get().value();
    }
    virtual void setMinSyncLatency(sg::ticks_t);
    virtual sg::ticks_t getMinSyncLatency(sg::Tag<sg::ticks_t> *)
    {
        return (m_min_sync_latency.value());
    }
    virtual void addSynchronisationPoint(sg::ticks_t);
    virtual sg::ticks_t getNextSyncPoint(sg::Tag<sg::ticks_t> *);
    virtual void getNextSyncRange(sg::ticks_t & min_sync_latency, sg::ticks_t & next_sync_pt)
    {
        min_sync_latency = scheduler_mapping::getMinSyncLatency(0);
        next_sync_pt = scheduler_mapping::getNextSyncPoint(0);
    }
    virtual void addCallback(sg::SchedulerCallback *);
    virtual void removeCallback(sg::SchedulerCallback *);
    virtual sg::ticks_t getCurrentSimulatedTime(sg::Tag<sg::ticks_t> *)
    {
        return sc_core::sc_time_stamp().value();
    }
    virtual double getSimulatedTimeResolution()
    {
        return sc_core::sc_get_time_resolution().to_seconds();
    }
    virtual void setSimulatedTimeResolution(double resolution)
    {
        sc_core::sc_set_time_resolution(resolution, sc_core::SC_SEC);
    }
    virtual void stopRequest();
    virtual void stopAcknowledge(sg::SchedulerRunnable *);

// Internal interface towards internal timer, thread and thread signal implementations
private:
    friend class async_request;
    friend class scheduler_mapping_Timer;
    friend class scheduler_mapping_sc_thread;
    friend class scheduler_mapping_sc_method;
    friend class scheduler_mapping_sc_event;
    friend class scheduler_mapping_Thread;
    friend class scheduler_mapping_ThreadSignal;
    friend class clear_stop_request_proxy_class;

    // get verbose level
    // verbose variable is set by env var SCX_EVS_VERBOSE
    enum VerboseFlags // these need to be ored together
    {
        V_ALL     = 0x0001,         // all messages
        V_SYSTEMC = 0x0002,         // SystemC function calls
        V_GENERAL = 0x0004,         // general adapter messages
        V_TIMER   = 0x0010,         // timer calls
        V_THREAD  = 0x0020,         // thread calls
        V_THREAD_SIGNAL = 0x0040,   // thread signal calls
        V_ASYNC_CALLBACK = 0x0080,  // addCallback/removeCallback() calls
        V_EXEC    = 0x0100,         // execution control (stopRequest(), stopAcknowledge())
        V_OTHER   = 0x0800,         // addSynchronisationPoint(), getCurrentSimulationTime() calls
        V_SIMCONTROL = 0x1000       // simcontroller messages (see tpl_scx_simcontrol.h/cpp)
    };
    unsigned int get_verbose() const
    {
        return verbose;
    }

    /// called by Timer destructor when timer gets destroyed
    void remove_timer(scheduler_mapping_Timer *);

    /// called by Thread destructor when thread gets destroyed
    void remove_thread(scheduler_mapping_Thread *);

    /// called by ThreadSignal destructor when timer gets destroyed
    void remove_thread_signal(scheduler_mapping_ThreadSignal *);

    /// return current scheduler_mapping_sc_thread object or NULL if not in any threadProc() call
    scheduler_mapping_sc_thread *get_current_sc_thread();

    /// called by scheduler_mapping_sc_thread constructor when sc_threads get created/started
    void add_sc_thread(scheduler_mapping_sc_thread *);

    /// called by scheduler_mapping_sc_thread destructor when sc_threads get destroyed
    void remove_sc_thread(scheduler_mapping_sc_thread *);

    /// called by scheduler_mapping_sc_method constructor when sc_methods get created/started
    void add_sc_method(scheduler_mapping_sc_method *);

    /// called by scheduler_mapping_sc_method destructor when sc_methods get destroyed
    void remove_sc_method(scheduler_mapping_sc_method *);

    /// process any potentially pending async callbacks
    void process_async_callbacks();

    /// call stopAcknowledge() for async stops (block simulation)
    void stop_acknowledge_from_async_stop_thread();

    /// clear stop request flag
    void clear_stop_request();

    /// push async stop request
    void push_stop_request();

    /// get async stop request flag (for async stop requests handling)
    bool stop_requested();

    /// get async stop request event (for async stop requests handling)
    sc_core::sc_event & get_stop_request_event();

    /// return true if there are potentially async callbacks pending
    bool has_pending_async_callbacks();

    /// get new async callback event (for async callbacks handling)
    sc_core::sc_event & get_pending_async_callbacks_event();

    /// clear pending async callbacks flag
    void clear_pending_async_callbacks();

    /// process async requests
    void async_thread_proc();

    bool isTADisabled() const
    {
        return disable_ta;
    }

    bool isTimerLocalTimeEnabled() const
    {
        return enable_timer_local_time;
    }

/* Implementation */
private:

    // member variables

    // verbose level
    unsigned int verbose;

    // list of timers
    std::list<scheduler_mapping_Timer *> timers;

    // list of threads
    std::list<scheduler_mapping_Thread *> threads;

    // list of thread signals
    std::list<scheduler_mapping_ThreadSignal *> thread_signals;

    // map from SystemC process objects onto scheduler_mapping_sc_threads
    typedef std::unordered_map<sc_core::sc_object *, scheduler_mapping_sc_thread *> ThreadMap;
    ThreadMap sc_thread_map;

    // map from SystemC process objects onto scheduler_mapping_sc_methods
    typedef std::unordered_map<sc_core::sc_object *, scheduler_mapping_sc_method *> MethodMap;
    MethodMap sc_method_map;

    // async event queue (addCallback()/removeCallback())
    typedef std::list<sg::SchedulerCallback *> AsyncCallbacksList;
    AsyncCallbacksList async_callbacks;

    // mutex for async event queue
    TxMutex async_callbacks_mutex;

    // simulation controller (for stopAcknowledge)
    scx_simcontrol_if * simcontroller;

    // stop request flag for asynchronous stop requests (set by stopRequest(), cleared by
    // clear_stop_request_proxy/stopAcknowledge())
    async_request * stop_request;

    // forward clearStopRequest() calls from stopAcknowledge to the scheduler adapter itself
    clear_stop_request_proxy_class * clear_stop_request_proxy;

    // new call-back flag for asynchronous call-backs (set by addCallback(), cleared by
    // process_async_callbacks())
    async_request * pending_callbacks;

    // asynchronous requests thread
    sc_core::sc_process_handle async_thread_handle;

    // thread ID of the simulation thread
    std::thread::id simulation_thread_id;

    // scheduler interface registry
    eslapi::CAInterfaceRegistry schedulerInterfaceRegistry;

    /* Future synchronization points priority queue, expressed in absolute simulated time */
    std::priority_queue<sc_core::sc_time, std::vector<sc_core::sc_time>, std::greater<sc_core::sc_time> > m_sync_points;

    // true: Timing Annotation support is disabled
    bool disable_ta;

    // true: use of Local Time on sg:Timer::set/remaining() is enabled
    bool enable_timer_local_time;

    // minimum synchronization latency
    sc_core::sc_time m_min_sync_latency;
};

}   // namespace scx

#endif  /* defined(SCX_SCHEDULER_MAPPING__H) */
