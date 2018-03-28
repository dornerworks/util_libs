/*
 * Copyright 2017, DornerWorks
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_DORNERWORKS_BSD)
 */

#pragma once

#include <platsupport/timer.h>

#include <stdint.h>




/* LPIT Offsets */
#define LPIT_VERID      0x00
#define LPIT_PARAM      0x04
#define LPIT_MCR        0x08
#define LPIT_MSR        0x0C
#define LPIT_MIER       0x10
#define LPIT_SETTEN     0x14
#define LPIT_CLRTEN     0x18
#define LPIT_TVAL0      0x20
#define LPIT_CVAL0      0x24
#define LPIT_TCTRL0     0x28
#define LPIT_TVAL1      0x30
#define LPIT_CVAL1      0x34
#define LPIT_TCTRL1     0x38
#define LPIT_TVAL2      0x40
#define LPIT_CVAL2      0x44
#define LPIT_TCTRL2     0x48
#define LPIT_TVAL3      0x50
#define LPIT_CVAL3      0x54
#define LPIT_TCTRL3     0x58

#define LPIT_VERID_FEATURE_MASK  (0xFFFF * BIT(0))
#define LPIT_VERID_MINOR_MASK    (0xFF   * BIT(16))
#define LPIT_VERID_MAJOR_MASK    (0xFF   * BIT(24))

#define LPIT_PARAM_CHANNEL_MASK (0xFF * BIT(0))
#define LPIT_PARAM_EXT_TRIG_MASK (0xFF * BIT(8))

#define LPIT_MCR_M_CEN BIT(0)
#define LPIT_MCR_SW_RST BIT(1)
#define LPIT_MCR_DOZE_EN BIT(2)
#define LPIT_MCR_DGB_EN BIT(3)

#define LPIT_MSR_TIF0 BIT(0)
#define LPIT_MSR_TIF1 BIT(1)
#define LPIT_MSR_TIF2 BIT(2)
#define LPIT_MSR_TIF3 BIT(3)

#define LPIT_MIER_TIE0 BIT(0)
#define LPIT_MIER_TIE1 BIT(1)
#define LPIT_MIER_TIE2 BIT(2)
#define LPIT_MIER_TIE3 BIT(3)

#define LPIT_SETTEN_SET_T_EN_0 BIT(0)
#define LPIT_SETTEN_SET_T_EN_1 BIT(1)
#define LPIT_SETTEN_SET_T_EN_2 BIT(2)
#define LPIT_SETTEN_SET_T_EN_3 BIT(3)

#define LPIT_CLRTEN_CLR_T_EN_0 BIT(0)
#define LPIT_CLRTEN_CLR_T_EN_1 BIT(1)
#define LPIT_CLRTEN_CLR_T_EN_2 BIT(2)
#define LPIT_CLRTEN_CLR_T_EN_3 BIT(3)

#define LPIT_TVAL0_OFFSET 0x20
#define LPIT_TVAL1_OFFSET 0x30
#define LPIT_TVAL2_OFFSET 0x40
#define LPIT_TVAL3_OFFSET 0x50

#define LPIT_CVAL0_OFFSET 0x24
#define LPIT_CVAL1_OFFSET 0x34
#define LPIT_CVAL2_OFFSET 0x44
#define LPIT_CVAL3_OFFSET 0x54

#define LPIT_TCTRL0_OFFSET 0x28
#define LPIT_TCTRL1_OFFSET 0x38
#define LPIT_TCTRL2_OFFSET 0x48
#define LPIT_TCTRL3_OFFSET 0x58

#define LPIT_TCTRLa_T_EN                BIT(0)
#define LPIT_TCTRLa_CHAIN               BIT(1)
#define LPIT_TCTRLa_MODE_MASK           (0x3 * BIT(2))
#define LPIT_TCTRLa_TSOT                BIT(16)
#define LPIT_TCTRLa_TSOI                BIT(17)
#define LPIT_TCTRLa_TROT                BIT(18)
#define LPIT_TCTRLa_TRG_SRC             BIT(23)
#define LPIT_TCTRLa_TRG_SEL_MASK        (0xF * BIT(24))

typedef struct {
    /* vaddr lpit is mapped to */
    void *vaddr;
    /* irq for this lpit (should be LPIT_INTERRUPT1 or LPIT_INTERRUPT2 depending on the lpit */
    uint32_t irq;
    /* prescaler to scale time by. 0 = divide by 1. 1 = divide by 2. ...*/
    uint32_t prescaler;
} lpit_config_t;

struct lpit_map;
typedef struct lpit {
    volatile struct lpit_map *lpit_map;
    uint32_t prescaler;
} lpit_t;

static inline timer_properties_t
lpit_timer_properties(void)
{
   return (timer_properties_t) {
     .upcounter = false,
     .timeouts = true,
     .relative_timeouts = true,
     .absolute_timeouts = false,
     .periodic_timeouts = true,
     .bit_width = 32,
     .irqs = 1,
   };
}

/* initialise an lpit struct */
int lpit_init(lpit_t *lpit, lpit_config_t config);
/* turn off any pending irqs */
int lpit_stop(lpit_t *lpit);
/* set a relative timeout */
int lpit_set_timeout(lpit_t *lpit, uint64_t ns, bool periodic, int timernum);
/* handle an irq */
int lpit_handle_irq(lpit_t *lpit);
