#include <stdint.h>

static inline uint32_t read32(volatile void *addr) {
	uint32_t val;
	asm volatile("ldr %0, %1"
		     : "=r" (val)
		     : "Qo" (*(volatile uint32_t *)addr)
             );
	return val;
}
static inline void write32(volatile void  *addr, uint32_t val) {
	asm volatile("str %0, %1"
		     : 
             : "r" (val), "Qo" (*(volatile uint32_t *)addr)
             );
}