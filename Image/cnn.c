/*
 * cnn.c - CNN example's application.
 *
 * Copyright 2007, 2011-2012 ARM Limited.
 * All rights reserved.
 */

/* Includes */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Typedefs */

typedef void (* handler_t)(void);

/* Globals */

#if defined(__TARGET_CPU_CORTEX_M3) || defined(__TARGET_CPU_CORTEX_M0)
    #define ___MCLASS___
#endif

#define JUMP_TABLE_BASE      0x00000000
#define HANDLER_TABLE_OFFSET 0x40

#define DMA_BASE_ADDRESS ((uint32_t *) 0x34004000)
static volatile uint32_t * SRC_ADDR = DMA_BASE_ADDRESS + 0;
static volatile uint32_t * DST_ADDR = DMA_BASE_ADDRESS + 2;
static volatile uint32_t * LENGTH = DMA_BASE_ADDRESS + 4;
static volatile uint8_t * CONTROL = (uint8_t *) (DMA_BASE_ADDRESS + 6);

static volatile uint32_t * MON1_ADDR = DMA_BASE_ADDRESS + 8;
static volatile uint32_t * MON2_ADDR = DMA_BASE_ADDRESS + 10;
static volatile uint32_t * MON3_ADDR = DMA_BASE_ADDRESS + 12;
static volatile uint32_t * MON4_ADDR = DMA_BASE_ADDRESS + 14;


static const uint8_t START = 0x01;
static const uint8_t IRQ = 0x10;
static volatile int end_transfer = 0;

/* Functions */

/* Compiler intrinsics */
extern void __enable_irq(void);
extern void __wfi(void);

#if defined(___MCLASS___)
/*
 * Updates contents of 'vector' to contain address of 'handler'.
 */
static void install_handler(handler_t handler, uint32_t * vector) {
  (* (vector + (JUMP_TABLE_BASE / sizeof(uint32_t)))) = (uint32_t) handler;
}
#else   /* Assumes --cpu=6 or equivalent */
/*
 * Updates contents of 'vector' to contain LDR pc, [pc, #offset]
 * instruction to cause long branch to 'handler'.
 */
static void install_handler(handler_t handler, uint32_t * vector) {

    /* Updates contents of 'vector' to contain
     * LDR pc, [pc, #offset] instruction */
    (* (vector + (JUMP_TABLE_BASE / sizeof(uint32_t)))) =
        0xe59ff000 | (HANDLER_TABLE_OFFSET - 0x8);

    (* (vector + (HANDLER_TABLE_OFFSET / sizeof(uint32_t)))) =
        (uint32_t) handler;
}

/*
 * Setup a "small" stack for IRQ (and SVC).
 */
__asm void setup_irq_stack(void) {
    cps #0x12       ; Switch to IRQ mode
    mov r13, #0x800
    cps #0x13       ; Back to SVC mode
    bx r14
}
#endif  /* defined(___MCLASS___) */

/*
 * IRQ handler.
 */
__irq void irq_handler(void) {
    if (! end_transfer) {
        uint8_t value = 0;

        /* Transfer done */
        printf("[  CPU  ] cnn.c: irq_handler(): end of DMA transfer received\n");
        end_transfer = 1;

        /* Clears DMA interrupt */
        printf("[  CPU  ] cnn.c: irq_handler(): clears DMA interrupt...\n");

        /* Read DMA control register */
        value = (* CONTROL);

        /* Clears the IRQ bit of the DMA control register */
        value &= ~IRQ;      
        (* CONTROL) = value;
    }
}

static void sc_time_stamp(void) {
    uint32_t value = 0;
    value = 0x11;
    (* MON1_ADDR) = value;
    value = (* MON1_ADDR);
}


static void mon_read(void) {

    uint32_t value = 0;

    value = 0x11;
    (* MON1_ADDR) = value;

    value = 0x22;
    (* MON2_ADDR) = value;

    value = 0x33;
    (* MON3_ADDR) = value;

     value = 0x44;
    (* MON4_ADDR) = value;

}

/*
 * Testbench process.
 */
static void run1(void) {
    uint32_t value = 0;

    /*
     * Programs DMA transfer...
     */
    printf("[  CPU  ] cnn.c: run(): programs DMA transfer...\n");

    /* Write DMA source address register */
    value = 0x20;
    (* SRC_ADDR) = value;

    /* Write DMA destination address register */
    value = 0x34002000;
    (* DST_ADDR) = value;

    /* Write DMA length register */
    value = 1024 /* bytes */;
    (* LENGTH) = value;

    mon_read();
    
    /*
     * Starts DMA transfer...
     */
    printf("cnn.c: run(): starts DMA transfer...\n");

    /* Start the DMA transfer (control register witdh is 8 bits, the write value
     * must be aligned before write) */
    end_transfer = 0;
    (* CONTROL) = START;

    /* Verification: read DMA control register (8 bits value) */
    value = (* CONTROL);

    /*
     * Waiting for end of DMA transfer
     */
    while (1) {
        if (end_transfer) {
            break;
        }
    }
    printf("cnn.c: run(): end of DMA transfer\n");

    mon_read();

/*
    if ( (* MON1_ADDR) == 0x11 )
        printf("cnn.c: run(): OK 1\n");
    if ( (* MON2_ADDR) == 0x22 )
        printf("cnn.c: run(): OK 2\n");
    if ( (* MON3_ADDR) == 0x33 )
        printf("cnn.c: run(): OK 3\n");
    if ( (* MON4_ADDR) == 0x44 )
        printf("cnn.c: run(): OK 4\n");
*/

}


static void run2(void) {
    uint32_t value = 0;

    /*
     * Programs DMA transfer...
     */
    printf("[  CPU  ] cnn.c: run(): programs DMA transfer...\n");

    /* Write DMA source address register */
    value = 0x20;
    (* DST_ADDR) = value;

    /* Write DMA destination address register */
    value = 0x34002000;
    (* SRC_ADDR) = value;

    /* Write DMA length register */
    value = 1024 /* bytes */;
    (* LENGTH) = value;

    mon_read();

    /*
     * Starts DMA transfer...
     */
    printf("cnn.c: run(): starts DMA transfer...\n");

    /* 
     * Start the DMA transfer (control register witdh is 8 bits, the write value
     * must be aligned before write) 
     */
    end_transfer = 0;
    (* CONTROL) = START;

    /* Verification: read DMA control register (8 bits value) */
    value = (* CONTROL);

    /*
     * Waiting for end of DMA transfer
     */
    while (1) {
        if (end_transfer) {
            break;
        }
    }
    printf("cnn.c: run(): end of DMA transfer\n");

    mon_read();

}


/* CNN */

static void convolution(
    uint32_t *inputs,
    uint32_t *outputs,
    uint32_t *weights,
    uint32_t *biases
) {
    uint32_t lay_input_columns  = 32;
    uint32_t lay_input_row      = 32;
    uint32_t lay_input_channel  = 3;
    uint32_t lay_output_columns = 28;
    uint32_t lay_output_row     = 28;
    uint32_t lay_output_channel = 3;
    uint32_t lay_relu_activation = 1;
    uint32_t lay_filter_columns  = 3;
    uint32_t lay_filter_row      = 3;


    unsigned int stride_row;
    unsigned int stride_col;
    unsigned int filter_row;
    unsigned int filter_col;
    unsigned int out_ch;
    unsigned int in_ch;

    uint32_t current_weight;
    uint32_t current_biase;
    uint32_t current_input;
    uint32_t current_result;
    uint32_t kernel_result;

    for (stride_row = 0; stride_row < lay_output_row; stride_row++) {
        for (stride_col = 0; stride_col < lay_output_columns; stride_col++) {
            for (filter_row = 0; filter_row < lay_filter_row; filter_row++) {
                for (filter_col = 0; filter_col < lay_filter_columns; filter_col++) {
                    for (in_ch = 0; in_ch < lay_input_channel; in_ch++) {
                        current_input = ((float*)inputs)[  ((stride_row + filter_row) * lay_input_columns * lay_input_channel)
                                                        + ((stride_col + filter_col)                      * lay_input_channel)
                                                        + in_ch];
                        for (out_ch = 0; out_ch < lay_output_channel; out_ch++) {
                            current_weight = ((float*)biases)[out_ch];
                            current_weight = ((float*)weights)[  (filter_row * lay_filter_columns * lay_input_channel * lay_output_channel)
                                                               + (filter_col                       * lay_input_channel * lay_output_channel)
                                                               + (in_ch                                                 * lay_output_channel)
                                                               + out_ch];
                            current_result = current_input * current_weight;
                            ((float*)outputs)[  (stride_row * lay_output_columns * lay_output_channel)
                                              + (stride_col                       * lay_output_channel)
                                              + out_ch]
                                        += current_result;
                        }
                    }
                }
            }
        }
    }
}



/*
 * User's entry point.
 */
int main(void) {

    uint32_t value = 0;

    /* Initialisations  */
    printf("[  CPU  ] cnn.c: main()\n");

    /* Installs IRQ handler */
#if defined(___MCLASS___)
    install_handler((handler_t) irq_handler, (uint32_t *) 0x8);
#else   /* Assumes --cpu=6 or equivalent */
    setup_irq_stack();
    install_handler((handler_t) irq_handler, (uint32_t *) 0x18);
#endif

    /* Enables IRQ */
    __enable_irq();

    /* Initialize globals */
    end_transfer = 0;

#if 0
    /* Single transfer */
    printf("[  CPU  ] run-1: main()\n");
    run1();

    /* Single transfer */
    printf("[  CPU  ] run-2: main()\n");
    run2();
#endif 

    /* Single transfer */
    sc_time_stamp();
    printf("\n\n[  CPU  ] convolution() Start\n\n");
    sc_time_stamp();

    convolution(
        (uint32_t *) 0x1000, 
        (uint32_t *) 0x2000, 
        (uint32_t *) 0x3000, 
        (uint32_t *) 0x4000
    );

    printf("\n\n[  CPU  ] convolution() End\n\n");
    sc_time_stamp();

#if defined(USE_WFI)
    /* Wait for interrupts */
    __wfi();
#endif


    exit(EXIT_SUCCESS);
    return EXIT_SUCCESS;
}
