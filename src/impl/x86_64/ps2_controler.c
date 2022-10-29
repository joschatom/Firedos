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
    bool result;
    uint8_t count;

    result = ps2_test_controler();

    if (result == true) print_sucess("Self-test Passed!\n", "[TESTING PS/2 CONTROLER]")
    else print_error("Self-test Failed!\n", "[TESTING PS/2 CONTROLER]")
    print_set_color(PRINT_COLOR_LIGHT_GRAY, PRINT_COLOR_BLACK);
    if (result == false) print_error("PS/2 Controler is maybe unstable...!\n", "[WARNING]")

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

        TEST(type, 0x00, print_sucess("Found 'Standard PS/2 mouse' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is not a 'Standard PS/2 mouse' Device!\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
        TEST(type, 0x03, print_sucess("Found 'Mouse with scroll wheel' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is not a 'Mouse with scroll wheel' Device!\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
        TEST(type, 0x04, print_sucess("Found '5-button mouse' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is not a '5-button mouse' Device!\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
        TEST(type, (0xAB, 0x83), print_sucess("Found 'MF2 keyboard' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is not a 'MF2 keyboard' Device!\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
        TEST(type, (0xAB, 0x41), print_sucess("Found 'MF2 keyboard with translation enabled in the PS/Controller' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is not a 'MF2 keyboard with translation enabled in the PS/Controller' Device!\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
        TEST(type, (0xAB, 0xC1), print_sucess("Found 'MF2 keyboard with translation enabled in the PS/Controller' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is not a 'MF2 keyboard with translation enabled in the PS/Controller' Device!\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
        TEST(!IF6(type, 0x00, 0x03, 0x04, (0x0AB, 0x83), (0xAB, 0x41), (0xAB, 0xC1)), true, print_sucess("Found 'Standart PS/2 Keyboard' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is now a 'Standart PS/2 Keyboard' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
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

        TEST(type, 0x00, print_sucess("Found 'Standard PS/2 mouse' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is not a 'Standard PS/2 mouse' Device!\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
        TEST(type, 0x03, print_sucess("Found 'Mouse with scroll wheel' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is not a 'Mouse with scroll wheel' Device!\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
        TEST(type, 0x04, print_sucess("Found '5-button mouse' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is not a '5-button mouse' Device!\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
        TEST(type, (0xAB, 0x83), print_sucess("Found 'MF2 keyboard' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is not a 'MF2 keyboard' Device!\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
        TEST(!IF4(type, 0x00, 0x03, 0x04, (0x0AB, 0x83)), true, print_sucess("Found 'Standart PS/2 Keyboard' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"), print_error("Is now a 'Standart PS/2 Keyboard' Device\n", "[CHECKING FOR DEVICES ON FIRST PORT]"))
        
    }
    
}
