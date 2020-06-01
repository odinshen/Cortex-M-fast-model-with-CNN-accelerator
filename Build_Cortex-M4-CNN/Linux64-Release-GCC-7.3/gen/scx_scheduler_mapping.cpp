/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2011-2016 ARM Limited.
 * All rights reserved.
 *
 * Concrete implementation of the abstract scheduler interface for SystemC export (EVS).
 */

/* Includes */
#if defined(SG_TARGET_SYSTEMC)
    #include "GlobalDefs.h"
#endif

#include <systemc>
#include <tlm.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <thread>

#include "scx_scheduler_mapping.h"

#include <scx/scx.h>
#include <TxLib/TxCriticalSection.h>
#include <sg/SGSimpleComponentRegistry.h>
#include <sg/MSCFixes.h>
#include <sg/Attributes.h>

// helpers

// strdup which accepts NULL pointers and converts them into empty strings
static inline const char *safe_strdup(const char *str)
{
    return strdup(str ? str : "");
}

// like FrequencySource::getFrequency() plus returns 0.0 for NULL pointers
static inline double safe_getFrequency(sg::FrequencySource *f)
{
    return f ? f->getFrequency() : 0.0;
}

// like SchedulerObject::getName() but handling NULL pointers
static inline const char *safe_getName(sg::SchedulerObject *obj)
{
    if (!obj)
        return "(NULL)";
    const char *name = obj->getName();
    if (!name)
        return "(NULL)";
    return name;
}

// macro for verbose messages (redefined below)
#define if_verbose(message_class) \
    if (owner->get_verbose() & ((scx::scheduler_mapping::message_class) | scx::scheduler_mapping::V_ALL))

namespace scx
{

// asynchronous request primitive channel
// handles stop request and pending call-backs in a thread-safe manner
class async_request: public sc_core::sc_prim_channel
{
public:
    async_request(const char * name_, scheduler_mapping * owner_):
        sc_core::sc_prim_channel(name_),
        request(false),
        owner(owner_) {
    }
    void set() {
        if (! request) {
            request = true;
            if (owner->simulation_thread_id == std::this_thread::get_id()) {

                // Called from simulation thread...
                event.notify(sc_core::SC_ZERO_TIME);
            } else {

#if defined(IEEE_1666_SYSTEMC) && (IEEE_1666_SYSTEMC >= 201101L)
                // Handles asynchronous request in a thread-safe manner
                async_request_update();
#else
                // There are no means before SystemC 2011 to handle asynchronous request in a thread-safe manner
                request_update();
#endif  /* IEEE_1666_SYSTEMC */
            }
        }
    }
    void clear() {
        request = false;

        // Assumes clear() is only called from SystemC thread
        sc_assert(owner->simulation_thread_id == std::this_thread::get_id());
        event.cancel();
    }
    operator bool() const {
        return request;
    }
    sc_core::sc_event & get_event() {
        return event;
    }
private:

    // member variables
    bool request;
    scheduler_mapping * owner;
    sc_core::sc_event event;

    virtual void update() {
        if (request) {
            event.notify(sc_core::SC_ZERO_TIME);
        } else {
            event.cancel();
        }
    }
};

// clear_stop_request_proxy_class:
// This class is used as a pseudo runnable to forward clearStopRequest() calls from the scheduler to the scheduler when
// the scheduler called stopAcknowledge() in contrast to threads calling stopAcknowledge().
// The clearStopRequest() function is the only function of this interface which is used.
class clear_stop_request_proxy_class: public sg::SchedulerRunnable
{
public:

    // constructor and destructor
    clear_stop_request_proxy_class(scheduler_mapping *owner_):
    owner(owner_)
    {
        sc_assert(owner);
    }
    virtual const char *getName() const
    {
        return "scx::clear_stop_request_proxy_class";
    }

    // these functions should never be called
    virtual void threadProc() {}
    virtual void threadProcExitRequest() {}
    virtual void breakQuantum(sg::ticks_t) {}
    virtual bool stopRequest()
    {
        return false;
    }
    virtual bool setThreadProperty(ThreadProperty, uint64_t)
    {
        return false;
    }
    virtual bool getThreadProperty(ThreadProperty, uint64_t &)
    {
        return false;
    }

    /*! Clear stop request flag.
     * Forward to scheduler.
     */
    virtual void clearStopRequest()
    {
        owner->clear_stop_request();
    }

/* Implementation */
private:

    // member variables
    scheduler_mapping *owner;
};

// Abstract 'runnable' interface for scheduler_mapping_sc_thread objects
class scheduler_mapping_sc_thread_runnable
{
public:

    /*! Get name of underlying thread (not of SchedulerRunnable). */
    virtual const char * get_name() const = 0;

    /*! Main thread function. Returning from this terminates the thread. */
    virtual void thread_proc() = 0;

    /*! Set default quantum size. */
    virtual void set_default_quantum_size(double quantum_sec) = 0;

    /*! Break quantum in the underlying SchedulerRunnable. Ignored for timers. */
    virtual void break_quantum(double quantum_sec) = 0;

    /*! Set next quantum size. */
    virtual void set_next_quantum_size(double quantum_sec) = 0;

    /*! Stop simulation request. */
    virtual bool stop_request() = 0;

    /*! Tell runnable that the sc_thread has terminated. */
    virtual void thread_terminated() = 0;

    /*! Get SchedulerRunnable (if available for this runnable). */
    virtual sg::SchedulerRunnable * get_scheduler_runnable()
    {
        return 0;
    }

/* Implementation */
protected:

    // protected destructor: do not allow to destry objects through this interface
    virtual ~scheduler_mapping_sc_thread_runnable() {}
};

// Abstract 'runnable' interface for scheduler_mapping_sc_method objects
class scheduler_mapping_sc_method_runnable
{
public:

    /*! Get name of underlying method (not of SchedulerRunnable). */
    virtual const char * get_name() const = 0;

    /*! Tell runnable that the sc_methodhas terminated. */
    virtual void method_terminated() = 0;

    /*! Main method function. */
    virtual void method_proc() = 0;

/* Implementation */
protected:

    // protected destructor: do not allow to destry objects through this interface
    virtual ~scheduler_mapping_sc_method_runnable() {}
};

// SystemC sc_event abstraction
// This object represents a SystemC sc_event and can be notified any time, also during elaboration
class scheduler_mapping_sc_event
{
public:

    // constructor and destructor
    scheduler_mapping_sc_event(scheduler_mapping *owner_, const char *name_):
    owner(owner_),
    name(safe_strdup(name_)),
    was_notified_(false)
    {
    }
    ~scheduler_mapping_sc_event()
    {
        free((void *) name);
    }

    /*! This is the equivalent of the sc_event::notify() function.
     * In contrast to sc_event::notify() this function may be called _any_ time, also during elaboration.
     * (This is the primary motivation for the existence of this class.)
     */
    void notify()
    {
        was_notified_ = true;
        if (sc_core::sc_is_running())
        {
            if_verbose(V_SYSTEMC)
                SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping_sc_event", "notify('%s'): sc_event::notify()", name);
            event.notify();
        }
    }
    void notify(const double & d)
    {
        was_notified_ = false;
        if_verbose(V_SYSTEMC)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping_sc_event", "notify('%s'): sc_event::notify(%.9fs)", name, d);
        event.notify(sc_core::sc_time(d, sc_core::SC_SEC));
    }

    void notify(sg::ticks_t t)
    {
        was_notified_ = false;
        if_verbose(V_SYSTEMC)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping_sc_event", "notify('%s'): sc_event::notify(%llu)", name, (long long unsigned)t);
        event.notify(simulated_time_from_ticks(t));
    }

    /*! Returns true if this event was notified after the last call to clear_notify() or since event creation. */
    bool was_notified() const
    {
        return was_notified_;
    }

    /*! Clear 'was_notified()' flag after event was notified to be able to detect a new notification. */
    void clear_notified()
    {
        was_notified_ = false;
    }

    /*! This is the equivalent of the sc_event::cancel() function.
     * In contrast to sc_event::cancel() this function may be called _any_ time, also during elaboration.
     * Clear 'was_notified()' flag as well. */
    void cancel()
    {
        clear_notified();
        if_verbose(V_SYSTEMC)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping_sc_event", "notify('%s'): sc_event::cancel()", name);
        event.cancel();
    }

    /*! Get SystemC event object. */
    sc_core::sc_event & get_event()
    {
        return event;
    }

private:

    // private data
    scheduler_mapping * owner; /// parent scheduler API implementation (never NULL)
    const char * name;         /// string owned by this object (never NULL)
    bool was_notified_;        /// true if this event was notified since the last clear_notified() or since object
                               /// creation (this is important when during the elaboration phase where
                               /// sc_event::notify() cannot be used)
    sc_core::sc_event event;   /// SystemC event
};

// --- SystemC thread abstraction ---
// This object represents a SystemC thread (not a Fast Models scheduler API thread).
class scheduler_mapping_sc_thread
{
public:
    enum { DEFAULT_THREAD_STACK_SIZE = 128*1024 };

    /*! constructor and destructor */
    scheduler_mapping_sc_thread(scheduler_mapping *owner_,
                                scheduler_mapping_sc_thread_runnable *runnable_):
    owner(owner_),
    runnable(runnable_),
    initialized(false)
    {
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_sc_thread",
                                 "scheduler_mapping_sc_thread() name=%s",
                                 get_name());
        sc_assert(owner);
        sc_assert(runnable);

        // start thread_proc() thread
        int stack_size = get_stack_size();
        if_verbose(V_SYSTEMC)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_sc_thread",
                                 "scheduler_mapping_sc_thread('%s'): sc_core::sc_spawn(thread_proc, stack_size=%d)",
                                 get_name(),
                                 stack_size);
        sc_core::sc_spawn_options spawn_options;
        spawn_options.set_stack_size(stack_size);
        process_handle = sc_core::sc_spawn(sc_bind(& scheduler_mapping_sc_thread::thread_proc, this),
                                           0,
                                           & spawn_options);
        owner->add_sc_thread(this);
    }

    /* Terminate the thread.
     * This take into account non initialized thread */
    void terminate()
    {
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_sc_thread",
                                 "terminate() name=%s",
                                 get_name());
        if (initialized)
            delete this;
        else
        {
            if (runnable)
                runnable->thread_terminated();
            runnable = 0;
        }
    }

    /*! get stack size for this thread from runnable (or use the default stack size) */
    int get_stack_size()
    {
        // ask runnable
        uint64_t stack_size = DEFAULT_THREAD_STACK_SIZE;
        bool value_ok = false;
        if (runnable && runnable->get_scheduler_runnable())
            value_ok = runnable->get_scheduler_runnable()->getThreadProperty(sg::SchedulerRunnable::TP_STACK_SIZE,
                                                                             stack_size);

        // if:
        // - we do not have a runnable or
        // - the runnable does support TP_STACK_SIZE or
        // - the runnable request a very small stack:
        // -> use default stack size
        if ((!value_ok) || (stack_size < DEFAULT_THREAD_STACK_SIZE))
            stack_size = DEFAULT_THREAD_STACK_SIZE;

        // round up to 4k page and return stack size
        stack_size = (stack_size + 0xfff) & ~0xfffull;
        return int(stack_size);
    }

    /*! get name of thread */
    const char *get_name() const
    {
        return runnable ? runnable->get_name() : "";
    }

    /*! get associated scheduler API thread object (may return NULL) */
    scheduler_mapping_sc_thread_runnable *get_runnable() const
    {
        return runnable;
    }

    /*! Return SystemC process object for the started SystemC thread or NULL if the thread was not yet started. */
    sc_core::sc_object *get_process_object() const
    {
        return process_handle.get_process_object();
    }

    /*! Calculate and set default quantum size */
    void set_default_quantum_size()
    {
        // this is meanigless if we have no runnable attached
        if (!runnable)
            return;
        // get size of default quantum (global quantum)
        double quantum_sec = tlm::tlm_global_quantum::instance().get().to_seconds();
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_sc_thread",
                                 "set_default_quantum_size() name=%s: tlm::tlm_global_quantum::instance().get()=%.9fs",
                                 get_name(),
                                 quantum_sec);
        // push size of default quantum into runnable
        runnable->set_default_quantum_size(quantum_sec);
    }

    /*! Calculate and set next quantum size */
    void set_next_quantum_size()
    {
        // this is meanigless if we have no runnable attached
        if (!runnable)
            return;
        // get size of next quantum (local quantum)
        double quantum_sec = owner->getNextSyncPoint(0) * owner->getSimulatedTimeResolution();
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_sc_thread",
                                 "set_next_quantum_size() name=%s: scheduler_mapping::getNextSyncPoint()=%.9fs",
                                 get_name(),
                                 quantum_sec);
        // push size of next quantum into runnable
        runnable->set_next_quantum_size(quantum_sec);
    }

    /*! Break quantum */
    void break_quantum(double quantum_sec)
    {
        // this is meaningless if we have no runnable attached
        if (!runnable)
            return;
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_sc_thread",
                                 "break_quantum(%.9fs) name=%s",
                                 quantum_sec,
                                 get_name());
        // push size of next quantum into runnable
        runnable->break_quantum(quantum_sec);
    }

private:

    /* Cannot be called directly so as to handle SystemC thread deletion gracefully */
    ~scheduler_mapping_sc_thread()
    {
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_sc_thread",
                                 "~scheduler_mapping_sc_thread() name=%s",
                                 get_name());
        sc_assert(initialized);
        owner->remove_sc_thread(this);
        if (runnable)
            runnable->thread_terminated();
        runnable = 0;
#if defined(IEEE_1666_SYSTEMC) && (IEEE_1666_SYSTEMC >= 201101L)
        process_handle.suspend();
#endif  /* defined(IEEE_1666_SYSTEMC) */
    }

    /* main thread function */
    void thread_proc()
    {
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_sc_thread",
                                 "thread_proc() name=%s: enter",
                                 get_name());
        initialized = true;
        try
        {
            if (owner->isTADisabled())
            {

                // initialize first quantum size in runnable
                set_default_quantum_size();
            }
            // run thread
            if (runnable)
                runnable->thread_proc();
            // when thread_proc() returns the thread terminates
            if_verbose(V_THREAD)
                SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                     "scx::scheduler_mapping_sc_thread",
                                     "thread_proc() name=%s: thread terminated because thread function returned",
                                     get_name());
        }
        catch(...)
        {
            // we catch all exceptions which end up here...
            SCX_REPORT_WARNING(get_name(), "Uncaught exception, thread terminated");
        }

        // ... and terminate the thread
        terminate();
    }

    // private data
    scheduler_mapping *owner;                       // parent scheduler API implementation (never NULL)
    scheduler_mapping_sc_thread_runnable *runnable; // pointer to the associated scheduler API runnable
    sc_core::sc_process_handle process_handle;      // process handle for timer_loop() thread
    bool initialized;
};

// --- SystemC method abstraction ---
// This object represents a SystemC method (not a Fast Models scheduler API thread).
class scheduler_mapping_sc_method
{
public:
    enum { DEFAULT_METHOD_STACK_SIZE = 128*1024 };

    /*! constructor */
    scheduler_mapping_sc_method(scheduler_mapping *owner_,
                                scheduler_mapping_sc_event *event_,
                                scheduler_mapping_sc_method_runnable *runnable_):
    owner(owner_),
    event(event_),
    runnable(runnable_),
    initialized(false)
    {
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_sc_method",
                                 "scheduler_mapping_sc_method() name=%s",
                                 get_name());
        sc_assert(owner);
        sc_assert(event);
        sc_assert(runnable);

        // start method_proc() method
        if_verbose(V_SYSTEMC)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_sc_method",
                                 "scheduler_mapping_sc_method('%s'): sc_core::sc_spawn(method_proc, stack_size=%d)",
                                 get_name(),
                                 DEFAULT_METHOD_STACK_SIZE);
        sc_core::sc_spawn_options spawn_options;
        spawn_options.spawn_method();
        spawn_options.set_sensitivity(& event->get_event());
        spawn_options.set_stack_size(DEFAULT_METHOD_STACK_SIZE);
        spawn_options.dont_initialize();
        process_handle = sc_core::sc_spawn(sc_bind(& scheduler_mapping_sc_method::method_proc, this),
                                           0,
                                           & spawn_options);
        owner->add_sc_method(this);
    }

    /* Terminate the method.
     * This take into account non initialized method */
    void terminate()
    {
        if (initialized)
            delete this;
        else
        {
            if (runnable)
                runnable->method_terminated();
            runnable = 0;
        }
    }

    /*! get name of thread */
    const char *get_name() const
    {
        return runnable ? runnable->get_name() : "";
    }

    /*! get associated scheduler API method object (may return NULL) */
    scheduler_mapping_sc_method_runnable *get_runnable() const
    {
        return runnable;
    }

    /*! Return SystemC process object for the started SystemC method or NULL if the method was not yet started. */
    sc_core::sc_object *get_process_object() const
    {
        return process_handle.get_process_object();
    }

private:

    /* Cannot be called directly so as to handle SystemC method deletion gracefully */
    ~scheduler_mapping_sc_method()
    {
        sc_assert(initialized);
        owner->remove_sc_method(this);
        if (runnable)
            runnable->method_terminated();
        runnable = 0;
#if defined(IEEE_1666_SYSTEMC) && (IEEE_1666_SYSTEMC >= 201101L)
        process_handle.suspend();
#endif  /* defined(IEEE_1666_SYSTEMC) */
    }

    /* main method function */
    void method_proc()
    {
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_sc_method",
                                 "method_proc() name=%s: enter",
                                 get_name());
        initialized = true;
        try
        {
            // run method
            if (runnable)
                runnable->method_proc();
            // method_proc() returns
            if_verbose(V_THREAD)
                SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                     "scx::scheduler_mapping_sc_method",
                                     "method_proc() name=%s: leave",
                                     get_name());
        }
        catch(...)
        {
            // we catch all exceptions which end up here and terminate the method
            SCX_REPORT_WARNING(get_name(), "Uncaught exception, method terminated");
            terminate();
        }
    }

    // private data
    scheduler_mapping *owner;                       // parent scheduler API implementation (never NULL)
    scheduler_mapping_sc_event *event;              // pointer to the associated scheduler API event
    scheduler_mapping_sc_method_runnable *runnable; // pointer to the associated scheduler API runnable
    sc_core::sc_process_handle process_handle;      // process handle for timer_loop() thread
    bool initialized;
};

// --- Timer implementation ---
class scheduler_mapping_Timer:
    public sg::Timer,
    public scheduler_mapping_sc_method_runnable
{
public:
    // constructor and destructor
    scheduler_mapping_Timer(const char *name_, scheduler_mapping *owner_, sg::TimerCallback *callback_):
    name(safe_strdup(name_)),
    owner(owner_),
    callback(callback_),
    timer_interval(0),
    last_timer_callback_time(0),
    timer_loop_event(owner_, "timer_loop_event"),
    sc_method(0),
    is_set_internal(false)
    {
        if_verbose(V_TIMER)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping_Timer", "scheduler_mapping_Timer() name=%s", name_);
        sc_assert(owner);
        sc_assert(callback);

        // start timer_loop() method
        sc_method = new scheduler_mapping_sc_method(owner, & timer_loop_event, this);
    }

    virtual ~scheduler_mapping_Timer()
    {
        if_verbose(V_TIMER)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping_Timer", "~scheduler_mapping_Timer() name=%s", name);
        cancel_internal();
        // notify parent that we got destroyed
        owner->remove_timer(this);
        if (sc_method)
            sc_method->terminate();
        free((void*)name);
    }

    // --- Timer implementation ---

    /*! Get Name. */
    virtual const char *getName() const
    {
        return name;
    }

    /*! Sets the specified frequency source clock for this timer. */
    virtual void setFrequency(sg::FrequencySource*)
    {
        SCX_REPORT_WARNING(SCX_ID_FM_DEPRECATION, "%s: sg::Timer::setFrequency() is not supported", name);
    }

    /*! Unsets the timer; causing it to no longer be set and will no longer fire.
     *  Has no effect if the timer is not currently set.
     */
    virtual void cancel()
    {
        if_verbose(V_TIMER)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping_Timer", "cancel() name=%s", name);
        cancel_internal();
    }

    /*! Set a timer to be signalled after ticks' ticks of the parent clock. When
     *  this happens the user callback function will be called. If the user
     *  callback returns 0 the timer will act as a one-shot, else it will be
     *  reoccur after n ticks; where n is the callback return value.
     *
     *  If the timer was already set and has not yet expired it will be re-set as
     *  if the old set() had never occurred.
     *
     *  \param ticks The number of ticks in the future to set the timer to fire.
     *  \returns false if the timer couldn't be scheduled (ticks too big).
     */
    virtual bool set(sg::ticks_t ticks)
    {
        if_verbose(V_TIMER)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_Timer",
                                 "set(ticks=%llu)=%d name=%s",
                                 (long long unsigned) ticks,
                                 true,
                                 name);
        if (!owner->isTADisabled() && owner->isTimerLocalTimeEnabled())
        {
            sg::ticks_t l = 0;
            sg::SchedulerRunnable * runnable = owner->currentRunnable();

            if (runnable && runnable->getThreadProperty(sg::SchedulerRunnable::TP_LOCAL_TIME, l))
            {
                ticks += l;
            }
        }
        set_internal(ticks);
        return true;
    }

    /*! Return whether a timer is set and queued for callback.
     *
     *  \returns True if the timer is set; else false.
     */
    virtual bool isSet()
    {
        bool is_set = is_set_internal;
        if_verbose(V_TIMER)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_Timer",
                                 "isSet()=%d name=%s (timer_interval=%llu)",
                                 is_set,
                                 name,
                                 (long long unsigned) timer_interval);
        return is_set;
    }

    /*! Get the remaining clock ticks before a timer will be triggered. This
     * may return 0 if the timer is about to be triggered. This will return 0
     * if the timer is not set.
     *
     * \returns The number of remaining ticks before the timer will be triggered.
     */
    virtual sg::ticks_t remaining()
    {
        sg::ticks_t r = remaining_internal();

        if (!owner->isTADisabled() && owner->isTimerLocalTimeEnabled())
        {
            sg::ticks_t l = 0;
            sg::SchedulerRunnable * runnable = owner->currentRunnable();

            if (runnable && runnable->getThreadProperty(sg::SchedulerRunnable::TP_LOCAL_TIME, l))
            {
                r -= std::min(r, l);
            }
        }
        if_verbose(V_TIMER)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_Timer",
                                 "remaining()=%llu name=%s current=%llu",
                                 (long long unsigned)r,
                                 name,
                                 (long long unsigned)sc_core::sc_time_stamp().value());
        return r;
    }

    // --- scheduler_mapping_sc_thread_runnable implementation ---

    /*! Get name of underlying thread (not of SchedulerRunnable). */
    virtual const char *get_name() const {
        return getName();
    }

    /*! Main method function.
     * All timed timer functionality is implemented by this method.
     */
    virtual void method_proc()
    {
        // clear timer_loop_event
        timer_loop_event.clear_notified();

        // call timer callback (only if timer is still set)
        if (is_set_internal)
        {
            // cancel timer before calling callback to ensure remaing() returns 0
            cancel_internal();
            sg::ticks_t ticks = callback->timerCallback();

            // re-set timer if needed
            if (ticks)
                set_internal(ticks);
        }
    }

    /*! Tell runnable that the sc_method has terminated. */
    virtual void method_terminated()
    {
        sc_method = 0;
        cancel_internal();
    }

private:
    // internal implementation

    /*! Get remaining ticks until timer fires next.
     * \return time in ticks relative to simulated time resolution until next timer fires, 0 if timer not set. */
    sg::ticks_t get_remaining()
    {
        if (! is_set_internal)
        {
            return 0;
        }

        return last_timer_callback_time + timer_interval - sc_core::sc_time_stamp().value();
    }

    /*! Set timer. Correctly overrides currently set timer. */
    void set_internal(sg::ticks_t ticks)
    {
        if (is_set_internal)
        {
            timer_loop_event.cancel();
        }
        is_set_internal = true;
        timer_interval = ticks;
        last_timer_callback_time = sc_core::sc_time_stamp().value(); // remember current time for remaining()
        timer_loop_event.notify(timer_interval);
#if ! (defined(IEEE_1666_SYSTEMC) && (IEEE_1666_SYSTEMC >= 201101L))

        /* This is a synchronisation point */
        owner->addSynchronisationPoint(ticks);
#endif  /* IEEE_1666_SYSTEMC */
    }

    /*! Cancel timer. */
    void cancel_internal()
    {
        if (is_set_internal)
        {
            timer_loop_event.cancel();
            is_set_internal = false;
            timer_interval = 0;
        }
    }

    /*! Get the remaining ticks relative to simulated time resolution before timer will be triggered. This
     * may return 0 if timer is about to be triggered. This will return 0 if timer is not set.
     *
     * \returns The number of remaining ticks before the timer will be triggered.
     */
    sg::ticks_t remaining_internal()
    {
        sg::ticks_t r = 0;
        if (is_set_internal)
        {
            r = get_remaining();
        }
        return r;
    }

    // private data
    const char *name;                       // string owned by this object (never NULL)
    scheduler_mapping *owner;               // parent scheduler API implementation (never NULL)
    sg::TimerCallback *callback;

    // timer loop state machine:
    sg::ticks_t timer_interval;             // timer interval for next and current timer interval while timer is set
    sg::ticks_t last_timer_callback_time;   // absolute time (no specific base) when the last timer callback
                                            // was called or when the timer was started with set()
    scheduler_mapping_sc_event timer_loop_event;
        // event which is triggered whenever the timer loop needs to respond to changed circumstances (_not_ when the
        // timer triggers)
    scheduler_mapping_sc_method *sc_method; // associated sc_method (if any), NULL when method does not run
    bool is_set_internal;
};

// --- Thread implementation ---
// This object represents one thread of the Fast Models scheduler API (not an sc_thread).
class scheduler_mapping_Thread:
    public sg::SchedulerThread,
    public sg::FrequencyObserver,
    public scheduler_mapping_sc_thread_runnable
{
public:
    // constructor and destructor
    scheduler_mapping_Thread(const char *name_, scheduler_mapping *owner_, sg::SchedulerRunnable *runnable_):
    name(safe_strdup(name_)),
    owner(owner_),
    frequency_source(0),
    current_frequency(0.0),
    runnable(runnable_),
    sc_thread(0),
    is_terminated(false)
    {
        sc_assert(owner);
        sc_assert(runnable);
    }

    virtual ~scheduler_mapping_Thread()
    {
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping_Thread", "~scheduler_mapping_Thread() name=%s", name);
        // unregister from frequency source
        if (frequency_source)
            frequency_source->unregisterFrequencyObserver(this);
        // notify parent that we got destroyed
        owner->remove_thread(this);
        // terminate thread (if running)
        if (sc_thread)
            sc_thread->terminate();
        free((void*)name);
    }

    // --- sg::SchedulerThread implementation ---

    /*! Get Name. */
    virtual const char *getName() const { return name; }

    /*! Sets/resets the specified frequency source to be the parent clock for this thread. */
    virtual void setFrequency(sg::FrequencySource* new_frequency_source)
    {
        if (!owner->isTADisabled())
        {
            SCX_REPORT_WARNING(SCX_ID_FM_DEPRECATION, "%s: sg::SchedulerThread::setFrequency() is not supported", name);
        }
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_Thread",
                                 "setFrequency(%s:%.1fHz) name=%s",
                                 safe_getName(new_frequency_source),
                                 safe_getFrequency(new_frequency_source),
                                 name);

        // unregister from old frequency source
        if (frequency_source)
            frequency_source->unregisterFrequencyObserver(this);

        // update frequency
        frequency_source = new_frequency_source;
        update_frequency();

        // register for frequency source
        if (frequency_source)
            frequency_source->registerFrequencyObserver(this);
    }

    /*! Start thread. */
    virtual void start()
    {
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping_Thread", "start() name=%s", name);
        if ((sc_thread != 0) || is_terminated)
            return; // ignore start() when: 1) thread was started already and also when 2) thread has terminated

        if (owner->isTADisabled())
        {
            // get size of global quantum
            double quantum_sec = tlm::tlm_global_quantum::instance().get().to_seconds();
            if_verbose(V_THREAD)
                SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                     "scx::scheduler_mapping_Thread",
                                     "set_default_quantum_size() name=%s: tlm::tlm_global_quantum::instance().get()=%.9fs",
                                     get_name(),
                                     quantum_sec);

            // push size of global quantum into runnable
            set_default_quantum_size(quantum_sec);
        }

        // start thread
        sc_thread = new scheduler_mapping_sc_thread(owner, this);
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping_Thread", "start() name=%s returned", name);
    }

    // --- FrequencyObserver implementation ---

    /*! Notify this object that the observed frequency source changed. */
    virtual void notifyFrequencyChanged(sg::FrequencySource *frequency_source_)
    {
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_Thread",
                                 "notifyFrequencyChanged(%s:%.1fHz) name=%s",
                                 safe_getName(frequency_source_),
                                 safe_getFrequency(frequency_source_),
                                 name);
        update_frequency();
    }

    /*! Notify this object that the observed frequency is about to be destroyed. */
    virtual void notifyFrequencySourceDestroyed(sg::FrequencySource *frequency_source_)
    {
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_Thread",
                                 "notifyFrequencySourceDestroyed(%s:%.1fHz) name=%s",
                                 safe_getName(frequency_source_),
                                 safe_getFrequency(frequency_source_),
                                 name);
        frequency_source = 0;
        update_frequency();
    }

    // --- scheduler_mapping_sc_thread_runnable implementation ---

    /*! Get name of underlying thread (not of SchedulerRunnable). */
    virtual const char *get_name() const
    {
        return getName();
    }

    /*! Main thread function. Returning from this terminates the thread. */
    virtual void thread_proc()
    {
        runnable->threadProc();
    }

    /*! Set default quantum size in the underlying SchedulerRunnable. */
    virtual void set_default_quantum_size(double quantum_sec)
    {
        // convert time in seconds into time in ticks
        sg::ticks_t quantum_ticks = 0;
        if (quantum_sec)
        {
            // if current_frequency == 0.0 then quantum_ticks will become 1
            quantum_ticks = (sg::ticks_t)ceil(quantum_sec * current_frequency);
            // make sure we advance time by at least one tick if quantum_sec > 0. to avoid convergence against 0.0
            if (quantum_ticks == 0)
                quantum_ticks = 1;
        }
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_Thread",
                                 "set_default_quantum_size(%.9fs) name=%s: "
                                 "runnable->setThreadProperty(TP_DEFAULT_QUANTUM_SIZE, ticks=%llu)",
                                 quantum_sec,
                                 name,
                                 (long long unsigned)quantum_ticks);
        // push default quantum size into runnable
        runnable->setThreadProperty(sg::SchedulerRunnable::TP_DEFAULT_QUANTUM_SIZE, quantum_ticks);
    }

    /*! Break quantum in the underlying SchedulerRunnable. */
    virtual void break_quantum(double quantum_sec)
    {
        // convert time in seconds into time in ticks
        sg::ticks_t quantum_ticks = 0;
        if (quantum_sec)
        {
            // if current_frequency == 0.0 then quantum_ticks will become 1
            quantum_ticks = (sg::ticks_t)ceil(quantum_sec * current_frequency);
            // make sure we advance time by at least one tick if quantum_sec > 0. to avoid convergence against 0.0
            if (quantum_ticks == 0)
                quantum_ticks = 1;
        }
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_Thread",
                                 "break_quantum(%.9fs) name=%s: runnable->breakQuantum(ticks=%llu)",
                                 quantum_sec,
                                 name,
                                 (long long unsigned) quantum_ticks);
        // push next quantum size into runnable
        runnable->breakQuantum(quantum_ticks);
    }

    /*! Set next quantum size in the underlying SchedulerRunnable. */
    virtual void set_next_quantum_size(double quantum_sec)
    {
        // convert time in seconds into time in ticks
        sg::ticks_t quantum_ticks = 0;
        if (quantum_sec)
        {
            // if current_frequency == 0.0 then quantum_ticks will become 1
            quantum_ticks = (sg::ticks_t)ceil(quantum_sec * current_frequency);
            // make sure we advance time by at least one tick if quantum_sec > 0. to avoid convergence against 0.0
            if (quantum_ticks == 0)
                quantum_ticks = 1;
        }
        if_verbose(V_THREAD)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_Thread",
                                 "set_next_quantum_size(%.9fs) name=%s: "
                                 "runnable->setThreadProperty(TP_BREAK_QUANTUM, ticks=%llu)",
                                 quantum_sec,
                                 name,
                                 (long long unsigned)quantum_ticks);
        // push next quantum size into runnable
        runnable->setThreadProperty(sg::SchedulerRunnable::TP_BREAK_QUANTUM, quantum_ticks);
    }

    /*! Stop simulation request. */
    virtual bool stop_request()
    {
        return runnable->stopRequest();
    }

    /*! Tell runnable that the sc_thread has terminated. */
    virtual void thread_terminated()
    {
        sc_thread = 0;
        is_terminated = true;
    }

    /*! Get SchedulerRunnable (if available for this runnable). */
    virtual sg::SchedulerRunnable *get_scheduler_runnable()
    {
        return runnable;
    }
    
    /*! Get runnable of this thread. */
    virtual sg::SchedulerRunnable *getRunnable() const
    {
        return runnable;
    }

private:
    // private helper

    // freqency changed
    void update_frequency()
    {
        double new_frequency = safe_getFrequency(frequency_source);
        if (new_frequency == current_frequency)
            return; // avoid spurious updates

        // get new frequency
        current_frequency = new_frequency;
    }

    // private data
    const char *name;                   // string owned by this object (never NULL)
    scheduler_mapping *owner;           // parent scheduler API implementation (never NULL)
    sg::FrequencySource *frequency_source;
        // current frequency source of this thread (may be NULL) (for breakQuantum() only)
    double current_frequency;           // current frequency from the current frequency source, may be 0.0
    sg::SchedulerRunnable *runnable;    // pointer to the associated scheduler API runnable
    scheduler_mapping_sc_thread *sc_thread;
        // associated sc_thread (if any), NULL when thread does not run
    bool is_terminated;                 // true: thread was started and also has terminated already
};

// --- ThreadSignal implementation ---
class scheduler_mapping_ThreadSignal: public sg::ThreadSignal
{
public:
    // constructor and destructor
    scheduler_mapping_ThreadSignal(const char *name_, scheduler_mapping *owner_):
    name(safe_strdup(name_)),
    owner(owner_),
    thread_signal(owner_, "thread_signal")
    {
    }

    virtual ~scheduler_mapping_ThreadSignal()
    {
        if_verbose(V_THREAD_SIGNAL)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping_ThreadSignal",
                                 "~scheduler_mapping_ThreadSignal() name=%s",
                                 name);
        // notify parent that we got destroyed
        owner->remove_thread_signal(this);
        free((void*)name);
    }

    /*! Get Name. */
    virtual const char *getName() const
    {
        return name;
    }

    /*! Notify the event, waking up any waiting threads. */
    virtual void notify()
    {
        if_verbose(V_THREAD_SIGNAL)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping_ThreadSignal", "notify() name=%s", name);
        thread_signal.notify();
    }

    // --- private interface towards scheduler_mapping class ---

    /*! Get SystemC event object. */
    scheduler_mapping_sc_event &get_event()
    {
        return thread_signal;
    }

private:

    // private data
    const char *name;                           // string owned by this object (never NULL)
    scheduler_mapping *owner;                   // parent scheduler API implementation (never NULL)
    scheduler_mapping_sc_event thread_signal;   // this event implements the notify()/wait() mechanism
};

// --- class scheduler_mapping implementation ---

// macro for verbose messages (redefinition)
#undef if_verbose
#define if_verbose(message_class) \
    if (verbose & ((scx::scheduler_mapping::message_class) | scx::scheduler_mapping::V_ALL))

// constructor and destructor
scheduler_mapping::scheduler_mapping(scx_simcontrol_if * controller):
verbose(0),
stop_request(0),
clear_stop_request_proxy(0),
simulation_thread_id(),
schedulerInterfaceRegistry("scx::scheduler_mapping::schedulerInterfaceRegistry", false),
disable_ta(false),
enable_timer_local_time(false)
{
    // enable verbose messages
    if (getenv("SCX_EVS_VERBOSE"))
        verbose = strtoul(getenv("SCX_EVS_VERBOSE"), 0, 0);
    if (verbose)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "scheduler_mapping(): enabled verbose messages (flags 0x%04X)",
                             verbose);

    // get access to simulation controller
    simcontroller = controller;
    sc_assert(simcontroller);

#if ! (defined(IEEE_1666_SYSTEMC) && (IEEE_1666_SYSTEMC >= 201101L))
    // There are no means before SystemC 2011 to handle asynchronous stop request or call-backs in a thread-safe manner
    SCX_REPORT_WARNING(SCX_ID_FM_DEPRECATION, "This version of SystemC is not supported, use SystemC 2011 or later");
#endif  /* IEEE_1666_SYSTEMC */

    scx_report_sc_time_has_from_value();

    // set simulation thread id to be able to determine whether calls come from this thread or from other threads
    simulation_thread_id = std::this_thread::get_id();

    // create async_stop_request thread-safe channel
    stop_request = new async_request("scx::async_stop_request", this);

    // create clear_stop_request_proxy
    clear_stop_request_proxy = new clear_stop_request_proxy_class(this);

    // create pending async callbacks thread-safe channel
    pending_callbacks = new async_request("scx::pending_async_callbacks", this);

    // create async thread
    async_thread_handle = sc_core::sc_spawn(sc_bind(& scheduler_mapping::async_thread_proc, this),
                                            "scx::async_thread");
    if_verbose(V_EXEC)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "scheduler_mapping(): created async_thread...");

    // register SchedulerInterfaceForComponents
    schedulerInterfaceRegistry.RegisterInterface(scheduler_mapping::IFNAME(),
                                                 scheduler_mapping::IFREVISION(),
                                                 this);

    /* Is support for Timing Annotation disabled? */
    if (const char* fastsim_disable_ta = getenv("FASTSIM_DISABLE_TA"))
    {
       disable_ta = strcmp(fastsim_disable_ta, "1") == 0;
    }

    /* Is Local Time on sg::Timer::set/remaining() enabled? */
    if (const char* enable_timer_local_time_str = getenv("FM_SCX_ENABLE_TIMER_LOCAL_TIME"))
    {
       enable_timer_local_time = strcmp(enable_timer_local_time_str, "1") == 0;
    }
}

scheduler_mapping::~scheduler_mapping()
{
    // Note: We cannot call SCX_REPORT...() from here since scx_default_report_handler may be already deconstructed
    // when we come here (global destructors)
    //if_verbose(V_GENERAL)
    //   SCX_REPORT_INFO_VERB(SCX_DEBUG, "scheduler_mapping", "~scheduler_mapping()");
    delete clear_stop_request_proxy;
    delete stop_request;
    delete pending_callbacks;
}

// CAInterface related stuff
inline eslapi::CAInterface *scheduler_mapping::ObtainInterface(eslapi::if_name_t ifName,
                                                        eslapi::if_rev_t minRev,
                                                        eslapi::if_rev_t *actualRev)
{
    return schedulerInterfaceRegistry.ObtainInterface(ifName, minRev, actualRev);
}

// main interface, used by components
sg::Timer* scheduler_mapping::createTimer(const char* name, sg::TimerCallback *callback)
{
    if (!name)
        name = "(anonymous timer)";
    if (!callback)
        return 0;
    if_verbose(V_TIMER)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "createTimer(name=%s)", name);
    scheduler_mapping_Timer *timer = new scheduler_mapping_Timer(name, this, callback);
    timers.push_front(timer);
    return timer;
}

sg::SchedulerThread *scheduler_mapping::createThread(const char* name, sg::SchedulerRunnable *runnable)
{
    if (!name)
        name = "(anonymous thread)";
    if (!runnable)
        return 0;
    if_verbose(V_THREAD)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "createThread(name=%s, runnable=%s)",
                             name,
                             safe_getName(runnable));
    scheduler_mapping_Thread *thread = new scheduler_mapping_Thread(name, this, runnable);
    threads.push_front(thread);
    return thread;
}

sg::ThreadSignal* scheduler_mapping::createThreadSignal(const char* name)
{
    if (!name)
        name = "(anonymous thread signal)";
    if_verbose(V_THREAD_SIGNAL)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "createThreadSignal(name=%s)", name);
    scheduler_mapping_ThreadSignal *thread_signal = new scheduler_mapping_ThreadSignal(name, this);
    thread_signals.push_front(thread_signal);
    return thread_signal;
}

void scheduler_mapping::wait(sg::ticks_t ticks)
{
    if_verbose(V_THREAD)
    {
        scheduler_mapping_sc_thread *sc_thread = get_current_sc_thread();

        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "wait(%llu, thread='%s')",
                             (long long unsigned)ticks,
                             (sc_thread? sc_thread->get_name(): "(unkown)"));
    }

    // wait for timeout
    sc_core::sc_time timeout = simulated_time_from_ticks(ticks);

    if_verbose(V_SYSTEMC)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "wait(): sc_core::wait(%llu)", (long long unsigned)timeout.value());
    sc_core::wait(timeout);
    if (isTADisabled())
    {

        // calc and set next quantum size
        scheduler_mapping_sc_thread *sc_thread = get_current_sc_thread();
        if (sc_thread)
        {
            sc_thread->set_next_quantum_size();
        }
        else
        {
            if_verbose(V_THREAD)
                SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                     "scx::scheduler_mapping",
                                     "wait(): not setting next quantum size because not in one of our sc_threads");
        }
    }
}

void scheduler_mapping::wait(sg::ThreadSignal *thread_signal)
{
    if_verbose(V_THREAD_SIGNAL)
    {
        scheduler_mapping_sc_thread *sc_thread = get_current_sc_thread();

        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "wait(threadSignal=%s, thread='%s')",
                             safe_getName(thread_signal),
                             (sc_thread? sc_thread->get_name(): "(unkown)"));
    }

    if (!thread_signal)
        return;

    // wait for notify event
    scheduler_mapping_ThreadSignal *our_thread_signal = static_cast<scheduler_mapping_ThreadSignal*>(thread_signal);

    if_verbose(V_SYSTEMC)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "wait(): sc_core::wait(thread_signal_event)");
    sc_core::wait(our_thread_signal->get_event().get_event());
    our_thread_signal->get_event().clear_notified();
    if (isTADisabled())
    {

        // calc and set next quantum size
        scheduler_mapping_sc_thread *sc_thread = get_current_sc_thread();
        if (sc_thread)
        {
            sc_thread->set_next_quantum_size();
        }
        else
        {
            if_verbose(V_THREAD)
                SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                     "scx::scheduler_mapping",
                                     "wait(): not setting next quantum size because not in one of our sc_threads");
        }
    }
}

/*! Sets the value of the global quantum.
 * The global quantum is the maximum time a thread can run ahead of simulation time.
 * All threads must synchronize on timing points that are multiples of the global quantum.
 */
void scheduler_mapping::setGlobalQuantum(sg::ticks_t ticks)
{
    if_verbose(V_OTHER)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "setGlobalQuantum(ticks=%llu)",
                             (long long unsigned) ticks);
    tlm::tlm_global_quantum::instance().set(simulated_time_from_ticks(ticks));
}

/*! Sets the minimum synchronization latency for this scheduler.
 */
void
scheduler_mapping::setMinSyncLatency(sg::ticks_t ticks) {
    if_verbose(V_OTHER)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "setMinSyncLatency(ticks=%llu)",
                             (long long unsigned) ticks);
    m_min_sync_latency = simulated_time_from_ticks(ticks);
}

void scheduler_mapping::addSynchronisationPoint(SG_MAYBEUNUSED sg::ticks_t ticks)
{
#if ! (defined(IEEE_1666_SYSTEMC) && (IEEE_1666_SYSTEMC >= 201101L))
    sc_core::sc_time next_sync = sc_core::SC_ZERO_TIME;

    if_verbose(V_OTHER)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "addSynchronisationPoint(ticks=%llu)",
                             (long long unsigned)ticks);

    // next sync point
    if (ticks != 0)
    {
        next_sync = simulated_time_from_ticks(ticks);

        /* Add future sync point to priority queue, if sufficient time has passed */
        if (next_sync >= m_min_sync_latency)
        {
            m_sync_points.push(sc_core::sc_time_stamp() + next_sync);
        }
    }
    if (isTADisabled())
    {

        // modify quantum of all non running threads
        scheduler_mapping_sc_thread * sc_current_thread = get_current_sc_thread();
        for (ThreadMap::const_iterator i = sc_thread_map.begin(); (i != sc_thread_map.end()); i ++)
        {
            if (i->second && (i->second != sc_current_thread))
            {
                i->second->set_next_quantum_size();
            }
        }

        // notify running thread so it knows we would like it to stop ASAP
        if (sc_current_thread)
        {
            if (next_sync == sc_core::SC_ZERO_TIME)
            {
                sc_current_thread->break_quantum(0.0);
            }
            else
            {
                sc_current_thread->break_quantum(getNextSyncPoint(0) * getSimulatedTimeResolution());
            }
        }
    }
#endif  /* IEEE_1666_SYSTEMC */
}

/*!
 * \brief   Returns the next synchronization point.
 *
 * This version of the method returns the earliest of the local quantum and the next timed notification or
 * synchronisation point, expressed relatively to the current simulated time.
 */
sg::ticks_t scheduler_mapping::getNextSyncPoint(sg::Tag<sg::ticks_t> *)
{
    /* Compute local quantum */
    sc_core::sc_time q = tlm::tlm_global_quantum::instance().compute_local_quantum();

    if_verbose(V_SYSTEMC)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "getNextSyncPoint(): tlm::tlm_global_quantum::instance().compute_local_quantum()=%llu",
                             (long long unsigned)q.value());
#if defined(IEEE_1666_SYSTEMC) && (IEEE_1666_SYSTEMC >= 201101L)

    /* Compute earliest of next timed notification and local quantum */
    if (((q.value() / 2) >= m_min_sync_latency.value()) && sc_core::sc_pending_activity_at_future_time())
    {
        sc_core::sc_time t = sc_core::sc_time_to_pending_activity();
            /* NOTE:    SystemC does lack an sc_time_to_future_activity() that could be useful here to re-size the
             *          quantum even in the presence of pending acitivity at current time... */

        if ((t > sc_core::SC_ZERO_TIME) && (t >= m_min_sync_latency) && ((t + m_min_sync_latency) <= q))
        {
            q = t;
        }
    }
#else

    /* Compute earliest of next sync point and local quantum */
    if (((q.value() / 2) >= m_min_sync_latency.value()) && ! m_sync_points.empty())
    {
        sc_core::sc_time now = sc_core::sc_time_stamp();

        /* Remove old sync points */
        while ((! m_sync_points.empty()) && (m_sync_points.top() <= now))
        {
            m_sync_points.pop();
        }

        /* Return earliest of next sync point and local quantum */
        if (! m_sync_points.empty())
        {
            sc_core::sc_time next = m_sync_points.top() - now;

            if ((next >= m_min_sync_latency) && ((next + m_min_sync_latency) <= q))
            {
                q = next;
            }
        }
    }
#endif  /* IEEE_1666_SYSTEMC */
    if_verbose(V_OTHER)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "getNextSyncPoint(): %llu", (long long unsigned)q.value());
    return (q.value());
}

void scheduler_mapping::addCallback(sg::SchedulerCallback *callback)
{
    if_verbose(V_ASYNC_CALLBACK)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "addCallback()");

    TxCriticalSection lock(async_callbacks_mutex); // automatically lock/unlock mutext in an exception safe way
    async_callbacks.push_back(callback);

    // raise pending async callbacks event
    if (! has_pending_async_callbacks())
    {
        if_verbose(V_ASYNC_CALLBACK)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "addCallback(): setting pending_callbacks...");
        pending_callbacks->set();
    }
}

void scheduler_mapping::removeCallback(sg::SchedulerCallback *callback)
{
    if_verbose(V_ASYNC_CALLBACK)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "removeCallback()");
    TxCriticalSection lock(async_callbacks_mutex); // automatically lock/unlock mutext in an exception safe way
    async_callbacks.remove(callback);
}

// the models call this function to request a system wide simulation stop
void scheduler_mapping::stopRequest()
{
    if (simulation_thread_id == std::this_thread::get_id())
    {
        // we are in the simulation thread

        // get currently running thread runnable or NULL if no runnable is currently running
        scheduler_mapping_sc_thread_runnable *current_runnable = 0;
        scheduler_mapping_sc_thread *current_sc_thread = get_current_sc_thread();
        if (current_sc_thread)
            current_runnable = current_sc_thread->get_runnable();

        if_verbose(V_EXEC)
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                                 "scx::scheduler_mapping",
                                 "stopRequest() from simulation thread (sending stop request to %s)",
                                 current_runnable ? "current runnable" : "scheduler adapter itself");

        if (current_runnable)
        {
            // if we are in a thread which has a runnable tell that runnable to stop at a useful point
            // (this may be a scheduler thread or a timer)
            if (!current_runnable->stop_request())
                push_stop_request();
                    // if the runnable does not accept our stop request we have to stop the simulation ourselves in the
                    // scheduler
        }
        else
        {
            // if we are not in a thread (e.g. async callback) we will just push an async stop event
            push_stop_request();
        }
    }
    else
    {
        // we are not in the simulation thread
        if_verbose(V_EXEC)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "stopRequest() from non-simulation thread");

        // note that coming here will be a rare case: CADI interfaces will call stopRequest() on the runnable they are
        // attached to directly
        push_stop_request();
    }
}

// the models call this function to acknowledge a stop requested by requestStop():
// the models expect this function to block until the simulation is resumed
void scheduler_mapping::stopAcknowledge(sg::SchedulerRunnable *runnable)
{
    if_verbose(V_EXEC)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "stopAcknowledge(runnable->getName()=%s) enter (pausing (blocking) simulation)",
                             safe_getName(runnable));
    simcontroller->stop_acknowledge(runnable);
    if_verbose(V_EXEC)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "stopAcknowledge(runnable->getName()=%s) leave (resuming simulation)",
                             safe_getName(runnable));
}

// private internal API towards scheduler objects (timer, thread and thread signal)

/// called by Timer destructor when timer gets destroyed
void scheduler_mapping::remove_timer(scheduler_mapping_Timer *timer)
{
    if_verbose(V_TIMER)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "remove_timer()");
    timers.remove(timer);
}

/// called by Thread destructor when thread gets destroyed
void scheduler_mapping::remove_thread(scheduler_mapping_Thread *thread)
{
    if_verbose(V_THREAD)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "remove_thread()");
    threads.remove(thread);
}

/// called by ThreadSignal destructor when thread signal gets destroyed
void scheduler_mapping::remove_thread_signal(scheduler_mapping_ThreadSignal *thread_signal)
{
    if_verbose(V_THREAD_SIGNAL)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scheduler_mapping", "remove_thread_signal()");
    thread_signals.remove(thread_signal);
}

/// return current scheduler_mapping_sc_thread object or NULL if not in any threadProc() call
scheduler_mapping_sc_thread *scheduler_mapping::get_current_sc_thread()
{
    // ensure we are running, else return NULL
    if (simulation_thread_id != std::this_thread::get_id())
    {
        return 0;
    }
    if (! sc_core::sc_is_running())
    {
        return 0;
    }
    // get current SystemC process handle
    sc_core::sc_process_handle proc_h = sc_core::sc_get_current_process_handle();
    // find associated scheduler_mapping_Thread object
    ThreadMap::const_iterator i = sc_thread_map.find(proc_h.get_process_object());
    if (i == sc_thread_map.end())
    {
        return 0; // not found
    }
    return i->second;
}

/// return current SchedulerThread object or NULL if not in any threadProc() call
sg::SchedulerThread *scheduler_mapping::currentThread()
{
    scheduler_mapping_sc_thread *current_sc_thread = get_current_sc_thread();
    scheduler_mapping_sc_thread_runnable *current_runnable = NULL;
    
    if (current_sc_thread)
        current_runnable = current_sc_thread->get_runnable();
    return dynamic_cast<scheduler_mapping_Thread *>(current_runnable);
}

/// return current SchedulerRunnable object or NULL if not in any threadProc() call
sg::SchedulerRunnable *scheduler_mapping::currentRunnable()
{
    scheduler_mapping_sc_thread *current_sc_thread = get_current_sc_thread();
    scheduler_mapping_sc_thread_runnable *current_runnable = NULL;
    sg::SchedulerRunnable *scheduler_runnable = NULL;

    if (current_sc_thread)
        current_runnable = current_sc_thread->get_runnable();
    if (current_runnable)
        scheduler_runnable = current_runnable->get_scheduler_runnable();
    return scheduler_runnable;
}

/// called by scheduler_mapping_sc_thread constructor when sc_threads get created/started
void scheduler_mapping::add_sc_thread(scheduler_mapping_sc_thread *sc_thread)
{
    if_verbose(V_THREAD)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "add_sc_thread(): sc_thread_map[%p] -> %p",
                             sc_thread->get_process_object(),
                             sc_thread);
    // add map entry
    sc_thread_map[sc_thread->get_process_object()] = sc_thread;
}

/// called by scheduler_mapping_sc_thread destructor when sc_threads get destroyed
void scheduler_mapping::remove_sc_thread(scheduler_mapping_sc_thread *sc_thread)
{
    if_verbose(V_THREAD)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "remove_sc_thread(): erasing sc_thread_map[%p] -> %p",
                             sc_thread->get_process_object(),
                             sc_thread);
    // remove map entry
    sc_thread_map.erase(sc_thread->get_process_object());
}

/// called by scheduler_mapping_sc_method constructor when sc_methods get created/started
void scheduler_mapping::add_sc_method(scheduler_mapping_sc_method *sc_method)
{
    if_verbose(V_THREAD)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "add_sc_method(): sc_method_map[%p] -> %p",
                             sc_method->get_process_object(),
                             sc_method);
    // add map entry
    sc_method_map[sc_method->get_process_object()] = sc_method;
}

/// called by scheduler_mapping_sc_method destructor when sc_methods get destroyed
void scheduler_mapping::remove_sc_method(scheduler_mapping_sc_method *sc_method)
{
    if_verbose(V_THREAD)
        SCX_REPORT_INFO_VERB(SCX_DEBUG,
                             "scx::scheduler_mapping",
                             "remove_sc_method(): erasing sc_method_map[%p] -> %p",
                             sc_method->get_process_object(),
                             sc_method);
    // remove map entry
    sc_method_map.erase(sc_method->get_process_object());
}

void scheduler_mapping::async_thread_proc()
{
    // set simulation thread id to be able to determine whether calls come from this thread or from other threads
    simulation_thread_id = std::this_thread::get_id();

    while (true)
    {
        if (stop_requested())
        {
            stop_acknowledge_from_async_stop_thread();
            continue;
        }
        if (has_pending_async_callbacks())
        {
            process_async_callbacks();
            continue;
        }
        if_verbose(V_EXEC)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "async_thread_proc(): waiting for async request...");
        sc_core::wait(get_stop_request_event() | get_pending_async_callbacks_event());
    }
}

/// call stopAcknowledge() for async stops (block simulation)
inline void scheduler_mapping::stop_acknowledge_from_async_stop_thread()
{
    if_verbose(V_EXEC)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "stop_acknowledge_from_async_stop_thread()");
    stopAcknowledge(clear_stop_request_proxy);
}

/// clear stop request flag
inline void scheduler_mapping::clear_stop_request()
{
    if_verbose(V_EXEC)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "clear_stop_request()");
    stop_request->clear();
}

inline bool scheduler_mapping::stop_requested()
{
    return (* stop_request);
}

inline sc_core::sc_event & scheduler_mapping::get_stop_request_event()
{
    return stop_request->get_event();
}

/// Push async stop request.
/// Called by stopRequest() to stop the simulation from async requests or for other fallback cases.
/// Note: This just happens in rare cases and is not the usual stop mechanism.
/// This is just a fallback for asynchronous stops and whenever we have no current runnable we could stop or if the
/// runnable does not accept the stopRequest().
void scheduler_mapping::push_stop_request()
{
    // this will stop us during the current or next async event processing which will be soon enough
    if (!stop_requested())
    {
        if_verbose(V_EXEC)
            SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "push_stop_request(): setting stop_request...");
        stop_request->set();
    }
}

/// process any potentially pending async callbacks
void scheduler_mapping::process_async_callbacks()
{
    TxCriticalSection lock(async_callbacks_mutex);   // automatically lock/unlock mutext in an exception safe way
    if_verbose(V_ASYNC_CALLBACK)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "process_async_callbacks()");
    while(!async_callbacks.empty())
    {
        sg::SchedulerCallback *callback = async_callbacks.front();
        async_callbacks.pop_front();
        // the callback may add other callbacks and remove this and other callbacks
        // therefore we use an iterator free loop here
        async_callbacks_mutex.unlock();
        callback->schedulerCallback();
        async_callbacks_mutex.lock();
    }
    clear_pending_async_callbacks();
}

inline bool scheduler_mapping::has_pending_async_callbacks()
{
    return (* pending_callbacks);
}

/// clear pendign asynchronous callbacks flag
inline void scheduler_mapping::clear_pending_async_callbacks()
{
    if_verbose(V_ASYNC_CALLBACK)
        SCX_REPORT_INFO_VERB(SCX_DEBUG, "scx::scheduler_mapping", "clear_pending_async_callbacks()");
    pending_callbacks->clear();
}

inline sc_core::sc_event & scheduler_mapping::get_pending_async_callbacks_event()
{
    return pending_callbacks->get_event();
}

/*!
 * \brief   Returns a pointer to a new instance of the default implementation of the scheduler mapping provided with
 * Fast Models.
 */
sg::SchedulerInterfaceForComponents *scx_create_default_scheduler_mapping(scx_simcontrol_if *simcontrol)
{
    if (simcontrol)
        return new scheduler_mapping(simcontrol);
    else
        return 0;
}

} // namespace scx

