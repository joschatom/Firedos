#include "print.h"
#include "gdt.h"

void kernel_main(){

	// ==== GDT Descriptors (gdt.c*4) ==== //
    create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL0));
    create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL0));
    create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL3));
    create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL3));


 

	print_str("This os was created using the os64 template!");
}