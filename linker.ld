ENTRY(boot)

SECTIONS
{
    . = 0x80000000;
    
    . = ALIGN(4);
    .text :
    {
        KEEP(*(.text.boot))
        *(.text)
    }
    
    . = ALIGN(4);
    .rodata :
    {
        *(.rodata)
    }
    
    . = ALIGN(4);
    .data :
    {
        *(.data)
    }

    . = ALIGN(4);
    .bss :
    {
        *(.bss)
    }

    /DISCARD/ :
    {
        *(.init)
        *(.fini)
    }

}