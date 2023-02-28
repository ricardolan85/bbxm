ENTRY(_start)

MEMORY
{
    ram : ORIGIN = 0x80000000, LENGTH = 0x10000000
}

SECTIONS
{
    __start = .;
    .text :
    {
        KEEP(*(.text.boot))
        *(.text)
    } > ram
    
    .rodata :
    {
        *(.rodata)
    } > ram
    
    .data :
    {
        *(.data)
    } > ram

    __bss_start__ = .;
    .bss :
    {
        bss = .;
        *(.bss)
    } > ram
    __bss_end__ = .;

}