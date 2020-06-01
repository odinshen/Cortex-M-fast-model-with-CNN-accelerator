/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2011-2012, 2014 ARM Limited.
 * All rights reserved.
 */

/* Includes */
#if defined(SG_TARGET_SYSTEMC)
    #include "GlobalDefs.h"
#endif

#include <systemc>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>

#include <TxLib/TxActiveObject.h>
#include <scx/scx_ids.h>
#include <scx/scx_report.h>

/* Namespaces */

/*
 * SystemC eXport support namespace.
 */
namespace scx {

/* Globals */

/* Pointer to unique instance of report handler. */
static scx_report_handler_if * default_report_handler_ptr = NULL;

/* Datatypes */

/*
 * Default report handler.
 *
 * NOTE:    This class is final, that is not intended to be derived from.
 */
class scx_report_handler: public scx_report_handler_if {

    /* Construction */
    public:
        scx_report_handler();
        ~scx_report_handler();

    /* Reporting */
    private:
        void set_verbosity_level(int);
        int get_verbosity_level() const;
        void report_info(const char *, const char *, int, const char *, ...);
        void report_info_verb(int, const char *, const char *, int, const char *, ...);
        void report_warning(const char *, const char *, int, const char *, ...);
        void report_error(const char *, const char *, int, const char *, ...);
        void report_fatal(const char *, const char *, int, const char *, ...);

    /* Implementation */
    private:

        /* Datatypes */

        /*
         * Report message datatype for asynchronous reporting.
         */
        struct report_t {
            sc_core::sc_report * m_rep;
            sc_core::sc_actions m_actions;
            report_t():
                m_rep(NULL),
                m_actions(sc_core::SC_STOP) {
            };
            report_t(const sc_core::sc_report & rep,
                     const sc_core::sc_actions & actions):
                m_rep(new sc_core::sc_report(rep)),
                m_actions(actions) {
            };
            void operator()() {
                if (m_actions & (sc_core::SC_STOP
                                 | sc_core::SC_ABORT
                                 | sc_core::SC_THROW)) {
                    scx_report_handler::m_active->done();
                }
                m_actions &= (sc_core::SC_DISPLAY | sc_core::SC_LOG);
                if (m_rep != NULL) {
                    sc_core::sc_report_handler::default_handler((* m_rep), m_actions);
                    delete m_rep;
                    m_rep = NULL;
                }
            };
        };

        /* Member variables */
        static TxActiveObject<report_t> * m_active;

        /* Helpers */
        static void vreport(sc_core::sc_severity,
                            const char *,
                            const char *,
                            int,
                            const char *,
                            std::va_list);

        /* Report handler */
        static void handler(const sc_core::sc_report &,
                            const sc_core::sc_actions &);
};

/* Globals */

/* Active object for synchronous reporting */
TxActiveObject<scx_report_handler::report_t> *
scx_report_handler::m_active = NULL;

/* Functions */

/*
 * Constructs a new report handler.
 */
scx_report_handler::scx_report_handler() {

    /* Process environmental settings... */

    /* 1) Environmental override about deprecation warnings */
    const char * deprecation_warn = std::getenv("FM_SCX_DEPRECATION_WARNINGS");

    if ((deprecation_warn != NULL) && (std::atoi(deprecation_warn) <= 0)) {
        sc_core::sc_report_handler::set_actions(SCX_ID_FM_DEPRECATION,
                                                sc_core::SC_DO_NOTHING);
    }

    /* 2) Setup verbosity level */
    const char * verbosity_level = std::getenv("FM_SCX_VERBOSITY_LEVEL");

    if (verbosity_level != NULL) {
        sc_core::sc_report_handler::set_verbosity_level(std::atoi(verbosity_level));
    }

    /* 3) Setup asynchronous report handler procedure */
    if (std::getenv("FM_SCX_ENABLE_ASYNC_REPORT") != NULL) {
        std::size_t queue_size = 4096;
        const char * queue_size_str = std::getenv("FM_SCX_ASYNC_REPORT_MAX_SIZE");

        if (queue_size_str != NULL) {
            queue_size = std::max(1, std::atoi(queue_size_str));
        }
        m_active = TxActiveObject<report_t>::create(queue_size);
        sc_core::sc_report_handler::set_handler(handler);
    }
}

/*
 * Destructs this report handler.
 */
scx_report_handler::~scx_report_handler() {
    default_report_handler_ptr = NULL;

    /* Reset default report handler procedure */
    sc_core::sc_report_handler::set_handler(& sc_core::sc_report_handler::default_handler);
    if (m_active != NULL) {

        /* Stop asynchronous reporting */
        delete m_active;
        m_active = NULL;
    }

    /* If deprecation warnings were issued tell user how to turn them off
     *
     * NOTE:        This does not work when user presses Ctrl-C.  */
    if (sc_core::sc_report_handler::get_count(SCX_ID_FM_DEPRECATION) > 0) {
        SC_REPORT_INFO(SCX_ID_FM_DEPRECATION,
                        "You can turn off warnings about\n"
                        "              Fast Models deprecated features by "
                        "placing this method call\n"
                        "              as the first statement in your "
                        "sc_main() function:\n\n  "
                        "sc_core::sc_report_handler::set_actions("
                        "scx::SCX_ID_FM_DEPRECATION, sc_core::SC_DO_NOTHING);\n");
    }
}

/*!
 * \brief   Sets the verbosity level for information message reports.
 */
void
scx_report_handler::set_verbosity_level(int verbosity) {
    sc_core::sc_report_handler::set_verbosity_level(verbosity);
}

/*!
 * \brief   Returns the verbosity level for information message reports.
 */
int
scx_report_handler::get_verbosity_level() const {
    return (sc_core::sc_report_handler::get_verbosity_level());
}

/*!
 * \brief   Reports an information message with variable arguments.
 */
void
scx_report_handler::report_info(const char * id,
                                const char * file,
                                int line,
                                const char * fmt,
                                ...) {
    std::va_list arg;

    if (SCX_MEDIUM > get_verbosity_level()) {
        return;
    }
    va_start(arg, fmt);
    vreport(sc_core::SC_INFO, id, file, line, fmt, arg);
    va_end(arg);
}

/*!
 * \brief   Reports an information message with variable arguments.
 */
void
scx_report_handler::report_info_verb(int verbosity,
                                     const char * id,
                                     const char * file,
                                     int line,
                                     const char * fmt,
                                     ...) {
    std::va_list arg;

    if (verbosity > get_verbosity_level()) {
        return;
    }
    va_start(arg, fmt);
    vreport(sc_core::SC_INFO, id, file, line, fmt, arg);
    va_end(arg);
}

/*!
 * \brief   Reports a warning message with variable arguments.
 */
void
scx_report_handler::report_warning(const char * id,
                                   const char * file,
                                   int line,
                                   const char * fmt,
                                   ...) {
    std::va_list arg;

    va_start(arg, fmt);
    vreport(sc_core::SC_WARNING, id, file, line, fmt, arg);
    va_end(arg);
}

/*!
 * \brief   Reports an error message with variable arguments.
 */
void
scx_report_handler::report_error(const char * id,
                                 const char * file,
                                 int line,
                                 const char * fmt,
                                 ...) {
    std::va_list arg;

    va_start(arg, fmt);
    vreport(sc_core::SC_ERROR, id, file, line, fmt, arg);
    va_end(arg);
}

/*!
 * \brief   Reports a fatal error message with variable arguments.
 */
void
scx_report_handler::report_fatal(const char * id,
                                 const char * file,
                                 int line,
                                 const char * fmt,
                                 ...) {
    std::va_list arg;

    va_start(arg, fmt);
    vreport(sc_core::SC_FATAL, id, file, line, fmt, arg);
    va_end(arg);
}

/*
 * Reports a message with variable arguments like the printf() function.
 */
void
scx_report_handler::vreport(sc_core::sc_severity severity,
                            const char * id,
                            const char * file,
                            int line,
                            const char * fmt,
                            std::va_list arg) {
    char  default_msg[1024] = "";
    char* msg               = default_msg;

    std::vector<char> big_buffer;

    if ((fmt != NULL) && ((* fmt) != '\0')) {

        va_list copy_of_arg;
        va_copy(copy_of_arg, arg);
        
        // First try and see if it fits in the default buffer.
        ::vsnprintf(default_msg, sizeof(default_msg), fmt, arg);

        // Due to differences in vsnprintf() between Windows and Linux then
        // don't trust the return result.  Instead ensure NUL-termination and
        // explicitly work out if it might have been bigger than the buffer we
        // have.
        default_msg[ sizeof(default_msg) - 1 ] = '\0';

        if (strlen(default_msg) == sizeof(default_msg) - /*exclude NUL*/1)
        {
            // Assume that it overflowed so allocate a huge buffer and assume
            // that is big enough.
            //
            // Allow messages up to 1 MB in size "plus something", which
            // should be enough for all sane use-cases of log messages.
            // This limit is arbitrary, but 16 kB is not enough.
            // Other limits in the log chain also support messages of
            // 1 MB in size as well, arbitrarily.
            big_buffer.resize((1024 + 64) * 1024); // 1 MB + 64 kB
            msg = &big_buffer[0];
            ::vsnprintf(msg, big_buffer.size(), fmt, copy_of_arg);
            big_buffer[big_buffer.size() - 1] = '\0';
        }

        va_end(copy_of_arg);
    }
    sc_core::sc_report_handler::report(severity,
                                       id,
                                       msg,
                                       (file == NULL? "(unknown)": file),
                                       line);
}

/*
 * Handler of message reporting.
 */
void
scx_report_handler::handler(const sc_core::sc_report & rep,
                            const sc_core::sc_actions & actions) {
    const sc_core::sc_actions async_actions = sc_core::SC_DISPLAY | sc_core::SC_LOG;

    /* Handle report asynchronously */
    m_active->push(report_t(rep, actions));
    if (actions & ~async_actions) {

        /* Handle report synchronously */
        sc_core::sc_report_handler::default_handler(rep, actions & ~async_actions);
    }
}

/*!
 * \brief   Returns a pointer to the default implementation of the report
 *          handler provided with Fast Models.
 */
scx_report_handler_if * scx_get_default_report_handler() {
    if (default_report_handler_ptr == NULL) {
        static scx_report_handler default_report_handler;

        default_report_handler_ptr = & default_report_handler;
    }
    return (default_report_handler_ptr);
}

}   /* namespace scx */
