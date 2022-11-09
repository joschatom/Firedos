#include "print.h"
#include "gdt.h"
#include "idt.h"
#include "io.h"
#include "ps2_controler.h"

void kernel_main(){

	// ==== GDT Descriptors (gdt.c*4) ==== //
    create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL0));
    create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL0));
    create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL3));
    create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL3));
    print_clear();

    print_set_color(PRINT_COLOR_LIGHT_GRAY, PRINT_COLOR_BLACK);

    idt_init();
    ps2_controler_init();



    print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_BLACK);

    print_str(("Scancode %d", inb(0x71)));

    

    

    //exception_handler();

	print_str("\nThis os was created using the os64 template!\n");

    asm volatile ("hlt");
}

__attribute__((noreturn))
void exception_handler(void);
void exception_handler() {
    /*print_set_color(PRINT_COLOR_WHITE,PRINT_COLOR_RED);
    print_clear();
    print_str("\n-------Firedos has Paniced-------\n      STOP: IRQ_GENERAL_EXEPTION.\n");
    print_str("\n     Please know that firedos is a os that I programmed for fun...!\n");
    print_str("\n-------End Panic-------\n");
    print_set_color(PRINT_COLOR_LIGHT_GRAY, PRINT_COLOR_RED);
    print_str("Halting the CPU...!\n");*/
}