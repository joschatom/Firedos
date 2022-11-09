#pragma once
#include <stdint.h>
#include <stdint.h>

/*
    VGA Header (Precompiled into Kernel)
        VERSION: 1.0
        COPYRIGHT: Joscha Egloff
        LICENSE: GNU Gerneral Public v3.0
*/

#define BIOS_TEXT_BASE_ADRESS               0xb8000
#define BIOS_ALLOW_INTERUPTS                false
#define VGA_VIDEO_MEMORY_BASE_ADRESS        0x000A0000
#define VGA_VIDEO_MEMORY_MAX_ADRESS         0x000BFFFF
#define VGA_REGISTER_PORT                   0x3C0
#define VGA_MODE_CONTROL_INDEX              0x10
#define VGA_OVERSCAN_REGISTER_INDEX         0x11
#define VGA_COLOR_PLANE_INDEX               0x12
#define VGA_HORISONTAL_PANNING_INDEX        0x13
#define VGA_COLOR_SELECT_INDEX              0x14


void vga_set_mode(uint8_t mode);
void vga_clor_select();


void vga_init();
