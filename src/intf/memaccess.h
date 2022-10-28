#pragma once
#include <stdint.h>

static inline uint32_t farpeekl(uint16_t sel, void* off);
static inline void farpokeb(uint16_t sel, void* off, uint8_t v);
