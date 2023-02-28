#include <cpu.h>

#define DELAY 500000

int main (void) {

	uint32_t i;
	uint32_t aux;
	
	PRCM_CM_WKUP->ICLKEN = (1 << 3);//set GPIO1 clock

	aux = GPIO1->OE;
	aux &= ~( 1 << 21 ); //set 21 to output
	GPIO1->OE = aux;
	
    for(;;)
	{
		GPIO1->SETDATAOUT = ( 1 << 21 );
		for(i = 0; i < DELAY; i++);
		GPIO1->CLEARDATAOUT = ( 1 << 21 );
		for(i = 0; i < DELAY; i++);
	}
    
    return 0;

}