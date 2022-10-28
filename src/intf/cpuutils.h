#pragma once
#include <stdint.h>

#define UNSECURE_CPU_FUNCTIONS // Tells the kernel thta this are  unsecure cpu functions!

static inline void cpuid(int code, uint32_t* a, uint32_t* d);
uint64_t rdtsc(void);
static inline unsigned long read_cr0(void);
static inline void invlpg(void* m);
static inline void wrmsr(uint64_t msr, uint64_t value);
static inline uint64_t rdmsr(uint64_t msr);
