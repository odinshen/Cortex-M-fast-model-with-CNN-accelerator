/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2020 ARM Limited.
 * All rights reserved.
 */

#ifndef SCX_SC_TIME_FROM_VALUE_H
#define SCX_SC_TIME_FROM_VALUE_H

#include <utility>
#include <type_traits>

#include "scx/scx_report.h"
#include "scx/scx_ids.h"

namespace scx
{
    namespace details
    {
        // A convenience struct whose member "value" is true
        // if sc_time::from_value exists
        template <typename T, typename = void>
        struct scx_sc_time_has_from_value : std::false_type {};

        template <typename T>
        struct scx_sc_time_has_from_value<T,
            decltype(T::from_value(std::declval<sc_dt::uint64>()), void())>
            : std::true_type {};

        // SFINAE based selection of function to get sc_core::sc_time object.
        // use sc_time::from_value if it exists
        template<typename T>
        sc_core::sc_time scx_sc_time_from_value(sc_dt::uint64 ticks, std::true_type)
        {
            static_assert(std::is_same<T, sc_core::sc_time>::value,
                          "T should be sc_core::sc_time");
            return sc_core::sc_time::from_value(ticks);
        }

        template<typename T>
        sc_core::sc_time scx_sc_time_from_value(sc_dt::uint64 ticks, std::false_type)
        {
            static_assert(std::is_same<T, sc_core::sc_time>::value,
                          "T should be sc_core::sc_time");
            return sc_core::sc_time(
                       double(ticks) * sc_core::sc_get_time_resolution().to_seconds(),
                       sc_core::SC_SEC);
        }

        // SFINAE based selection of function to report diagnostic.
        // use sc_time::from_value version of report, if sc_time::from_value exists
        template<typename T>
        void scx_report_sc_time_has_from_value(std::true_type)
        {
            static_assert(std::is_same<T, sc_core::sc_time>::value,
                          "T should be sc_core::sc_time");
            SCX_REPORT_INFO_VERB(SCX_DEBUG,
                "scx::scx_report_sc_time_has_from_value()",
                "SystemC implementation has sc_core::sc_time::from_value(sc_dt::uint64)");
        }

        template<typename T>
        void scx_report_sc_time_has_from_value(std::false_type)
        {
            static_assert(std::is_same<T, sc_core::sc_time>::value,
                          "T should be sc_core::sc_time");
            SCX_REPORT_WARNING(SCX_ID_FM_DEPRECATION,
                "This implementation of SystemC does not support constructing sc_core::sc_time from sc_dt::uint64, simulation speed might be impacted");
        }

    }

    // convenience wrapper around scx_sc_time_from_value<T>
    inline sc_core::sc_time scx_sc_time_from_value(sg::ticks_t ticks)
    {
        return details::scx_sc_time_from_value<sc_core::sc_time>(ticks,
                        details::scx_sc_time_has_from_value<sc_core::sc_time>{});
    }

    // convenience wrapper around scx_report_sc_time_has_from_value<T>
    inline void scx_report_sc_time_has_from_value()
    {
        details::scx_report_sc_time_has_from_value<sc_core::sc_time>(
                     details::scx_sc_time_has_from_value<sc_core::sc_time>{});
    }

}

#endif  /* defined(SCX_SC_TIME_FROM_VALUE_H) */
