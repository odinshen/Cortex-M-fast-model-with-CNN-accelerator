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
 * Abstract interface class protocol_SC_VirtualEthernet for protocol SC_VirtualEthernet.
 */

#ifndef protocol_SC_VirtualEthernet_h_
#define protocol_SC_VirtualEthernet_h_

// Includes from the 'includes' section of this protocol
#line 28 "/home/odishe01/FastModel/FastModelsPortfolio_11.10/examples/SystemCExport/Common/Protocols/LISA/SC_VirtualEthernetProtocol.lisa"

        #include "Protocols/VirtualEthernet/virtual_ethernet_sockets.h"
        #include "Protocols/VirtualEthernet/virtual_ethernet_base.h"
    
#line 26 "./Linux64-Release-GCC-7.3/gen/protocol_SC_VirtualEthernet.h"


// Abstract interface for protocol SC_VirtualEthernet
class protocol_SC_VirtualEthernet
{
public:
        virtual ~protocol_SC_VirtualEthernet() {}
        // Abstract protocol members
	virtual void send_to_slave_s(EthernetFrame* frame) = 0;
	virtual void send_to_master_m(EthernetFrame* frame) = 0;

};

#endif /* protocol_SC_VirtualEthernet_h_ */

