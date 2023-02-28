#include <cpu.h>
#include <io.h>

#define DELAY 500000

int main (void) {

	volatile unsigned int ra;
	write32(CM_PER_BASE+CM_PER_GPIO1, 1<<18 | 2);
	ra = read32(GPIO1_BASE+GPIO_OE);
	ra &= ~(15<<21);
	write32(GPIO1_BASE+GPIO_OE,ra);
	
    for(;;)
	{
		write32(GPIO1_BASE+GPIO_SETDATAOUT, (15<<21));
		for(ra = 0; ra < DELAY; ra ++);
		write32(GPIO1_BASE+GPIO_CLRDATAOUT, (15<<21));
		for(ra = 0; ra < DELAY; ra ++);
	}
    
    return 0;

}