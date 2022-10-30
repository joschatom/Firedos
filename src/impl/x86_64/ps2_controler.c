#include "ps2_controler.h" // The Impl of the ps2_controler.h Header.

void ps2_enable_first_port(void){
    outb(0x64, 0xAE);
    io_wait();
}

void ps2_disable_first_port(void){
    outb(0x64, 0xAD);
    io_wait();
}

void ps2_enable_second_port(void){
    outb(0x64, 0xA8);
    io_wait();
}

void ps2_disable_second_port(void){
    outb(0x64, 0xA7);
    io_wait();
}

bool ps2_test_first_port(void){
    uint8_t respons;
    outb(0x64, 0xAB);
    io_wait();
    respons = inb(0x60);
    io_wait();
    if (respons == 0x00)return true;

    return false;
}

bool ps2_test_second_port(void){
    uint8_t respons;
    outb(0x64, 0xA9);
    io_wait();
    respons = inb(0x60);
    io_wait();
    if (respons == 0x00)return true;
    
    return false;
}

bool ps2_test_controler(void){
    uint8_t respons;
    outb(0x64, 0xAA);
    io_wait();
    respons = inb(0x60);
    io_wait();
    if (respons == 0x00)return true;
    
    return false;
}

void* ps2_dump_memory(void){
    void* data;
    outb(0x64, 0xAC);
    io_wait();
    data = inb(0x60);
    io_wait();
    return data;
}

void ps2_controler_init(void){

    print_warning("System is initializing imported Hardware...!\n\n", "[~]")

    bool result;
    uint8_t count;

    result = ps2_test_controler();

    if (result == true) print_sucess("Self-test Passed!\n", "[TESTING PS/2 CONTROLER]")
    else print_error("Self-test Failed!\n", "[TESTING PS/2 CONTROLER]")
    print_set_color(PRINT_COLOR_LIGHT_GRAY, PRINT_COLOR_BLACK);
    if (result == false) print_warning("PS/2 Controler is maybe unstable...!\n", "[WARNING]")

    ps2_enable_first_port();

    result = ps2_test_first_port();

    if (result == true) print_sucess("Self-test Passed!\n", "[PS/2 CONTROLER TESTING FIRST PORT]")
    else print_error("Self-test Failed!\n", "[TESTING PS/2 FIRST PORT]")

    if(result){
        outb(0x60, 0xF5);
        io_wait();
        while (inb(0x60) != 0xFA)
        {
            
        }
        
        outb(0x60, 0xF2);
        io_wait();
        
        while (inb(0x60) != 0xFA)
        {
            
        }

        uint8_t type = inb(0x60);

        TEST(type, PS2_DEVCIE_STDMOUSE, print_sucess("Found 'Standard PS/2 mouse' Device\n", CHECK_FIRST_PORT_OPNAME), print_error("Is not a 'Standard PS/2 mouse' Device!\n", CHECK_FIRST_PORT_OPNAME))
        TEST(type, PS2_DEVICE_MOUSE_WITH_SCROOLWHEEL, print_sucess("Found 'Mouse with scroll wheel' Device\n", CHECK_FIRST_PORT_OPNAME), print_error("Is not a 'Mouse with scroll wheel' Device!\n", CHECK_FIRST_PORT_OPNAME))
        TEST(type, PS2_DEVICE_5BUTTONMOUSE, print_sucess("Found '5-button mouse' Device\n", CHECK_FIRST_PORT_OPNAME), print_error("Is not a '5-button mouse' Device!\n", CHECK_FIRST_PORT_OPNAME))
        TEST(type, PS2_DEVICE_MF2_KEYBOARD, print_sucess("Found 'MF2 keyboard' Device\n", CHECK_FIRST_PORT_OPNAME), print_error("Is not a 'MF2 keyboard' Device!\n", CHECK_FIRST_PORT_OPNAME))
        TEST(type, PS2_DEVICE_MF2_KEYBOARD_TRANSLATION_0, print_sucess("Found 'MF2 Keyboard +Translation (0x0)' Device\n", CHECK_FIRST_PORT_OPNAME), print_error("Is not a 'MF2 Keyboard +Translation (0x0)' Device!\n", CHECK_FIRST_PORT_OPNAME))
        TEST(type, PS2_DEVICE_MF2_KEYBOARD_TRANSLATION_1, print_sucess("Found 'MF2 Keyboard +Translation (0x1)' Device\n", CHECK_FIRST_PORT_OPNAME), print_error("Is not a 'MF2 Keyboard +Translation (0x1)' Device!\n", CHECK_FIRST_PORT_OPNAME))
        TEST(!IF6(type,  PS2_DEVCIE_STDMOUSE, PS2_DEVICE_MOUSE_WITH_SCROOLWHEEL, PS2_DEVICE_5BUTTONMOUSE, PS2_DEVICE_MF2_KEYBOARD, PS2_DEVICE_MF2_KEYBOARD_TRANSLATION_0, PS2_DEVICE_MF2_KEYBOARD_TRANSLATION_1), true, print_sucess("Found 'Standart PS/2 Keyboard' Device\n", CHECK_FIRST_PORT_OPNAME), print_error("Is now a 'Standart PS/2 Keyboard' Device\n", CHECK_FIRST_PORT_OPNAME))
    }

    ps2_enable_second_port();
    if (ps2_test_second_port() == true) print_sucess("Self-test Passed!\n", "[PS/2 CONTROLER TESTING SECOND PORT]")
    else print_error("Self-test Failed!\n", "[TESTING PS/2 SECOND PORT]")

    
    if(result){
        outb(0x60, 0xF5);
        io_wait();
        outb(0x64, 0xD4);
        io_wait();
        outb(0x60, 0xF2);
        io_wait();
        outb(0x64, 0xD4);
        io_wait();
        io_wait();

        uint8_t type = inb(0x60);

        TEST(type, PS2_DEVCIE_STDMOUSE, print_sucess("Found 'Standard PS/2 mouse' Device\n", CHECK_SECOND_PORT_OPNAME), print_error("Is not a 'Standard PS/2 mouse' Device!\n", CHECK_SECOND_PORT_OPNAME))
        TEST(type, PS2_DEVICE_MOUSE_WITH_SCROOLWHEEL, print_sucess("Found 'Mouse with scroll wheel' Device\n", CHECK_SECOND_PORT_OPNAME), print_error("Is not a 'Mouse with scroll wheel' Device!\n", CHECK_SECOND_PORT_OPNAME))
        TEST(type, PS2_DEVICE_5BUTTONMOUSE, print_sucess("Found '5-button mouse' Device\n", CHECK_SECOND_PORT_OPNAME), print_error("Is not a '5-button mouse' Device!\n", CHECK_SECOND_PORT_OPNAME))
        TEST(type, PS2_DEVICE_MF2_KEYBOARD, print_sucess("Found 'MF2 keyboard' Device\n", CHECK_SECOND_PORT_OPNAME), print_error("Is not a 'MF2 keyboard' Device!\n", CHECK_SECOND_PORT_OPNAME))
        TEST(!IF4(type, PS2_DEVCIE_STDMOUSE, PS2_DEVICE_MOUSE_WITH_SCROOLWHEEL, PS2_DEVICE_5BUTTONMOUSE, PS2_DEVICE_MF2_KEYBOARD), true, print_sucess("Found 'Standart PS/2 Keyboard' Device\n", CHECK_SECOND_PORT_OPNAME), print_error("Is now a 'Standart PS/2 Keyboard' Device\n", CHECK_SECOND_PORT_OPNAME))
        
    }
    
}
