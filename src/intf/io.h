#pragma once
#include <stdint.h>

void inline outb(uint16_t port, uint8_t val);
uint8_t inline inb(uint16_t port);
void io_wait(void);