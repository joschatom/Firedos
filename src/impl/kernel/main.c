#include "print.h"
#include "gdt.h"
#include "idt.h"

static bool are_interrupts_enabled()
{
    unsigned long flags;
    asm volatile ( "pushf\n\t"
                   "pop %0"
                   : "=g"(flags) );
    return flags & (1 << 9);
}

void kernel_main(){

	// ==== GDT Descriptors (gdt.c*4) ==== //
    create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL0));
    create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL0));
    create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL3));
    create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL3));

    idt_init();

    print_clear();
    print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_BLACK);

    if (are_interrupts_enabled() == true){
        print_str("Interupts: Sucesss!");
    }


    exception_handler();

	print_str("This os was created using the os64 template!");
}

__attribute__((noreturn))
void exception_handler(void);
void exception_handler() {
    print_set_color(PRINT_COLOR_WHITE,PRINT_COLOR_RED);
    print_clear();
    print_str("-------Firedos has Paniced-------\n      STOP: IRQ_GENERAL_EXEPTION.\n");
    print_str("     Please know that firedos is a os that I programmed for fun...!\n");
    print_str("\n-------End Panic-------\n");
    print_set_color(PRINT_COLOR_LIGHT_GRAY, PRINT_COLOR_RED);
    print_str("Halting the CPU...!\n");
    __asm__ volatile ("hlt");
}