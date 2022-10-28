#include "sys/core/io.h"

void inline outb(uint16_t port, int8_t val){
     asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

uint8_t inline inb(uint16_t port){
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

void inline io_wait(void){
    outb(0x80, 0);
}