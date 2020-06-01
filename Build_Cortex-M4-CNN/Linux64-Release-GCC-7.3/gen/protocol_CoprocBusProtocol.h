/*
 * 
 *
 * This is an automatically generated file. Do not edit.
 *
 * Copyright 2007 ARM Limited.
 * Copyright 2011 ARM Limited.
 *
 * All rights reserved.
 */

/** \file
 * Abstract interface class protocol_CoprocBusProtocol for protocol CoprocBusProtocol.
 */

#ifndef protocol_CoprocBusProtocol_h_
#define protocol_CoprocBusProtocol_h_

// Includes from the 'includes' section of this protocol
#line 9 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/LISA/CoprocBusProtocol.lisa"

        // this should come from a generic header
        enum CoprocState_t
        {
            CoprocOk,             //! <- Complete/Ok
            CoprocUndef,          //! <- undefined operation
            CoprocAbort,          //! -- data abort
            CoprocFirst = 4,      //!< -> First transfer in a sequence of data transfers (LDC and STC only)
            CoprocNext,           //!< -> Subsequent transfers (LDC and STC only)
            CoprocNop = 12        //!< <- Treat as a NOP
        };

        typedef CoprocState_t CoprocState;

        #ifndef CDECL
            #ifdef _MSC_VER
                #define CDECL _cdecl
            #else
                #define CDECL
            #endif
        #endif

    /*! Perform a coprocessor data processing op
     *  \param context context registered with coprocessor interface
     *  \param inst the coprocessor instruction being executed
     *  \return new coprocessor transaction state
     */
    typedef CoprocState (CDECL *CoprocCDPHandler)(void* context, uint32_t inst);
    typedef CoprocState (CDECL *CoprocCDPTestWillUndef)(void* context, uint32_t inst);

    /*! Perform a move register to coprocessor register op
     *  \param context context registered with coprocessor interface
     *  \param inst the coprocessor instruction being executed
     *  \param register contents
     *  \return new coprocessor transaction state
     */
    typedef CoprocState (CDECL *CoprocMCRHandler)(void* context, uint32_t inst, uint32_t data);
    typedef CoprocState (CDECL *CoprocMCRTestWillUndef)(void* context, uint32_t inst);

    /*! Perform a move coprocessor register to register op
     *  \param context context registered with coprocessor interface
     *  \param inst the coprocessor instruction being executed
     *  \param data pointer to word to fill in with coprocessor register contents
     *  \return new coprocessor transaction state
     */
    typedef CoprocState (CDECL *CoprocMRCHandler)(void* context, uint32_t inst, uint32_t* data);
    typedef CoprocState (CDECL *CoprocMRCTestWillUndef)(void* context, uint32_t inst);

    /*! Perform a coprocessor load from memory operation
     *  \param context context registered with coprocessor interface
     *  \param inst the coprocessor instruction being executed
     *  \param data contents of current memory location to load into register
     *  \param state current state in multistate transaction
     *  \return new coprocessor transaction state
     */
    typedef CoprocState (CDECL *CoprocLDCHandler)(void* context, uint32_t inst, uint32_t data, CoprocState state);
    typedef CoprocState (CDECL *CoprocLDCTestWillUndef)(void* context, uint32_t inst, CoprocState state);

    /*! Perform a coprocessor store to memory operation
     *  \param context context registered with coprocessor interface
     *  \param inst the coprocessor instruction being executed
     *  \param data pointer to word to fill in with coprocessor register contents to transfer to memory
     *  \return new coprocessor transaction state
     */
    typedef CoprocState (CDECL *CoprocSTCHandler)(void* context, uint32_t inst, uint32_t* data, CoprocState state);
    typedef CoprocState (CDECL *CoprocSTCTestWillUndef)(void* context, uint32_t inst, CoprocState state);

    /*! Perform a coprocessor double move register to coprocessor register op
     *  \param context context registered with coprocessor interface
     *  \param inst the coprocessor instruction being executed
     *  \param data1 first data word to load to a coprocessor register
     *  \param data2 second data word to load to a coprocessor register
     *  \return new coprocessor transaction state
     */
    typedef CoprocState (CDECL *CoprocMCRRHandler)(void* context, uint32_t inst, uint32_t data1, uint32_t data2);
    typedef CoprocState (CDECL *CoprocMCRRTestWillUndef)(void* context, uint32_t inst);

    /*! Perform a coprocessor double move coprocessor register to register op
     *  \param context context registered with coprocessor interface
     *  \param inst the coprocessor instruction being executed
     *  \param data1 pointer to first word to fill in with coprocessor register contents
     *  \param data2 pointer to second word to fill in with coprocessor register contents
     *  \return new coprocessor transaction state
     */
    typedef CoprocState (CDECL *CoprocMRRCHandler)(void* context, uint32_t inst, uint32_t* data1, uint32_t* data2);
    typedef CoprocState (CDECL *CoprocMRRCTestWillUndef)(void* context, uint32_t inst);

    /*! Coprocessor callback interface used to register coprocessor
     *  implementations with Cores.
     */
    struct Coprocessor
    {
        void *context;  //!< coprocessor private context pointer, passed as first argument to all calls

        CoprocCDPHandler CoprocCDP;   //!< Coprocessor Data Processing op handler
        CoprocCDPTestWillUndef CoprocWillUndefCDP;   //!< Coprocessor Data Processing op undef test
        CoprocMCRHandler CoprocMCR;   //!< Coprocessor move to coprocessor register handler
        CoprocMCRTestWillUndef CoprocWillUndefMCR;   //!< Coprocessor move to coprocessor register undef test
        CoprocMRCHandler CoprocMRC;   //!< Coprocessor move from coprocessor register handler
        CoprocMRCTestWillUndef CoprocWillUndefMRC;   //!< Coprocessor move from coprocessor register undef test
        CoprocLDCHandler CoprocLDC;   //!< Coprocessor load coprocessor register from memory handler
        CoprocLDCTestWillUndef CoprocWillUndefLDC;   //!< Coprocessor load coprocessor register from memory undef test
        CoprocSTCHandler CoprocSTC;   //!< Coprocessor store coprocessor register to memory handler
        CoprocSTCTestWillUndef CoprocWillUndefSTC;   //!< Coprocessor store coprocessor register to memory undef test
        CoprocMCRRHandler CoprocMCRR; //!< Coprocessor move to two coprocessor registers handler
        CoprocMCRRTestWillUndef CoprocWillUndefMCRR; //!< Coprocessor move to two coprocessor registers undef test
        CoprocMRRCHandler CoprocMRRC; //!< Coprocessor move from two coprocessor registers handler
        CoprocMRRCTestWillUndef CoprocWillUndefMRRC; //!< Coprocessor move from two coprocessor registers undef test

        Coprocessor()
        : context(nullptr)
        , CoprocCDP(nullptr)
        , CoprocWillUndefCDP(nullptr)
        , CoprocMCR(nullptr)
        , CoprocWillUndefMCR(nullptr)
        , CoprocMRC(nullptr)
        , CoprocWillUndefMRC(nullptr)
        , CoprocLDC(nullptr)
        , CoprocWillUndefLDC(nullptr)
        , CoprocSTC(nullptr)
        , CoprocWillUndefSTC(nullptr)
        , CoprocMCRR(nullptr)
        , CoprocWillUndefMCRR(nullptr)
        , CoprocMRRC(nullptr)
        , CoprocWillUndefMRRC(nullptr)
        {
        }

        Coprocessor(
        void*                    context_,  //!< coprocessor private context pointer, passed as first argument to all calls
        CoprocCDPHandler         CoprocCDP_,   //!< Coprocessor Data Processing op handler
        CoprocCDPTestWillUndef   CoprocWillUndefCDP_,   //!< Coprocessor Data Processing op undef test
        CoprocMCRHandler         CoprocMCR_,   //!< Coprocessor move to coprocessor register handler
        CoprocMCRTestWillUndef   CoprocWillUndefMCR_,   //!< Coprocessor move to coprocessor register undef test
        CoprocMRCHandler         CoprocMRC_,   //!< Coprocessor move from coprocessor register handler
        CoprocMRCTestWillUndef   CoprocWillUndefMRC_,   //!< Coprocessor move from coprocessor register undef test
        CoprocLDCHandler         CoprocLDC_,   //!< Coprocessor load coprocessor register from memory handler
        CoprocLDCTestWillUndef   CoprocWillUndefLDC_,   //!< Coprocessor load coprocessor register from memory undef test
        CoprocSTCHandler         CoprocSTC_,   //!< Coprocessor store coprocessor register to memory handler
        CoprocSTCTestWillUndef   CoprocWillUndefSTC_,   //!< Coprocessor store coprocessor register to memory undef test
        CoprocMCRRHandler        CoprocMCRR_, //!< Coprocessor move to two coprocessor registers handler
        CoprocMCRRTestWillUndef  CoprocWillUndefMCRR_, //!< Coprocessor move to two coprocessor registers undef test
        CoprocMRRCHandler        CoprocMRRC_, //!< Coprocessor move from two coprocessor registers handler
        CoprocMRRCTestWillUndef  CoprocWillUndefMRRC_ //!< Coprocessor move from two coprocessor registers undef test
        )
        : context             ( context_             ),
          CoprocCDP           ( CoprocCDP_           ),
          CoprocWillUndefCDP  ( CoprocWillUndefCDP_  ),
          CoprocMCR           ( CoprocMCR_           ),
          CoprocWillUndefMCR  ( CoprocWillUndefMCR_  ),
          CoprocMRC           ( CoprocMRC_           ),
          CoprocWillUndefMRC  ( CoprocWillUndefMRC_  ),
          CoprocLDC           ( CoprocLDC_           ),
          CoprocWillUndefLDC  ( CoprocWillUndefLDC_  ),
          CoprocSTC           ( CoprocSTC_           ),
          CoprocWillUndefSTC  ( CoprocWillUndefSTC_  ),
          CoprocMCRR          ( CoprocMCRR_          ),
          CoprocWillUndefMCRR ( CoprocWillUndefMCRR_ ),
          CoprocMRRC          ( CoprocMRRC_          ),
          CoprocWillUndefMRRC ( CoprocWillUndefMRRC_ )
        {
        }

        };

    
#line 188 "./Linux64-Release-GCC-7.3/gen/protocol_CoprocBusProtocol.h"


// Abstract interface for protocol CoprocBusProtocol
class protocol_CoprocBusProtocol
{
public:
        virtual ~protocol_CoprocBusProtocol() {}
        // Abstract protocol members
	virtual void addCoprocessor(Coprocessor* , int num) = 0;
	virtual void removeCoprocessor(Coprocessor* , int num) = 0;
	virtual bool accessIsPriv() = 0;
	virtual bool accessIsNonSecure() = 0;

};

#endif /* protocol_CoprocBusProtocol_h_ */

