/*
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2019 Arm Limited.
 * All rights reserved.
 */

#ifndef SCX_THREAD_CONTROL_H
#define SCX_THREAD_CONTROL_H

#include <condition_variable>
#include <mutex>
#include <thread>
#include <cassert>

// states that simulation thread transitions through
enum class scx_thread_state
{
    init,                 // initial state
    evs_instantiated,     // when scx_initialise and platform instantiation are complete
    resumed,              // when thread resumes to call sc_start due to cadi clinet request
    sysc_start_completed, // when systemc thread finished start_of_simulation
    sysc_ended            // when systemc thread finished end_of_simulation
};

// structure to control simulation thread synchronization
struct scx_thread_control_t
{
private:
    std::mutex              mx;
    std::condition_variable cv;
    scx_thread_state        state = scx_thread_state::init;

    void wait_for_thread_state(scx_thread_state expected_state)
    {
        std::unique_lock<std::mutex> ul(mx);
        cv.wait(ul, [&]() {
            return state == expected_state;
        });
    }

    void transform_thread_state(scx_thread_state expected_state,
                                scx_thread_state new_state)
    {
        std::lock_guard<std::mutex> lg(mx);
        assert(state == expected_state);
        state = new_state;
    }

public:
    std::thread sim_thread;

    void notify_evs_instantiated()
    {
        transform_thread_state(scx_thread_state::init,
                               scx_thread_state::evs_instantiated);
        cv.notify_all();
    }

    void notify_resumed()
    {
        transform_thread_state(scx_thread_state::evs_instantiated,
                               scx_thread_state::resumed);
        cv.notify_all();
    }

    void notify_simulation_started()
    {
        transform_thread_state(scx_thread_state::resumed,
                               scx_thread_state::sysc_start_completed);
        cv.notify_all();
    }

    void notify_simulation_ended()
    {
        transform_thread_state(scx_thread_state::sysc_start_completed,
                               scx_thread_state::sysc_ended);

        // The application thread does not wait on the condition variable
        // when the simulation ends. So, a notify here does effectively nothing.
        // But it doesn't hurt to have it.
        cv.notify_all();
    }

    void wait_for_evs_instantiated()
    {
        wait_for_thread_state(scx_thread_state::evs_instantiated);
    }

    void wait_for_simulation_resumed()
    {
        wait_for_thread_state(scx_thread_state::resumed);
    }

    void wait_for_simulation_started()
    {
        wait_for_thread_state(scx_thread_state::sysc_start_completed);
    }

    bool in_initial_state()
    {
        std::lock_guard<std::mutex> lg(mx);
        return state == scx_thread_state::init;
    }

    void reset()
    {
        transform_thread_state(scx_thread_state::sysc_ended,
                               scx_thread_state::init);
    }
};

#endif /* defined(SCX_THREAD_CONTROL_H) */
