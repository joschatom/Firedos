#pragma once

#include <stdint.h>
#include <stdbool.h>

static bool are_interrupts_enabled();
static unsigned long save_irqdisable(void);
static void irqrestore(unsigned long flags);
static void intended_usage(void);
