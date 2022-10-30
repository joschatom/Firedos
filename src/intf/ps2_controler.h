#pragma once // A Header that for the PS/2 Controler.

#include <stdint.h>
#include <stdbool.h>
#include "io.h"
#include "print.h"

#define PS2_CONTROLER_SELFTEST                  0xAA
#define PS2_CONTROLER_CFG_BYTE                  0x20
#define PS2_DEVCIE_STDMOUSE                     0x00
#define PS2_DEVICE_MOUSE_WITH_SCROOLWHEEL       0x03
#define PS2_DEVICE_5BUTTONMOUSE                 0x04
#define PS2_DEVICE_MF2_KEYBOARD_TRANSLATION     ((0xAB, 0x41) || 0xAB, 0xC1)
#define PS2_DEVICE_MF2_KEYBOARD_TRANSLATION_0   (0xAB, 0x41)
#define PS2_DEVICE_MF2_KEYBOARD_TRANSLATION_1   (0xAB, 0xC1)
#define PS2_DEVICE_MF2_KEYBOARD                 (0xAB, 0x83)
#define CHECK_FIRST_PORT_OPNAME                 "[CHECKING FIRST PORT]"
#define CHECK_SECOND_PORT_OPNAME                "[CHECKING SECOND PORT] "
#define TEST(a,b,c,d) if (a==b) c else d
#define IF4(t, v1, v2, v3 , v4) (t == v1 || t==v2 || t==v3 || t==v4)
#define IF6(t, v1, v2, v3 , v4, v5, v6) (t == v1 || t==v2 || t==v3 || t==v4 || t==v5 || t==v6)

void ps2_enable_first_port(void);           // To Enable the First PS/2 Port.
void ps2_disable_first_port(void);          // To Disable the First PS/2 Port.
void ps2_enable_second_port(void);          // To Enable the Second PS/2 Port (if supported).
void ps2_disable_second_port(void);         // To Disable te Second PS/2 Port (if supported).
bool ps2_test_first_port(void);             // Start's a Selftest for the First PS/2 Port.
bool ps2_test_second_port(void);            // Start's a Selftest for the Second PS/2 Port (if supported).
bool ps2_test_controler(void);              // Start's a Selftest for the PS/2 Controler.
void* ps2_dump_memory(void);                // Dumps the internal RAM.
void ps2_controler_init(void);              // Used to Init the PS/2 Controler.
