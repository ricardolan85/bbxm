#include <stdint.h>

/* PRCM Registers */

/* PRCM - CM */
typedef struct {
    volatile uint32_t FCLKEN;           //0x00
    uint32_t RESERVED0[3];
    volatile uint32_t ICLKEN;           //0x10
    uint32_t RESERVED1[3];
    volatile uint32_t IDLEST;           //0x20
    uint32_t RESERVED2[3];
    volatile uint32_t AUTOIDLE;         //0x30
    uint32_t RESERVED3[3];
    volatile uint32_t CLKSEL;           //0x40
} PRCM_CM_WKUP_def;

#define PRCM_CM_WKUP_ADDR 0x48004C00UL

#define PRCM_CM_WKUP           ((PRCM_CM_WKUP_def *) PRCM_CM_WKUP_ADDR)


/* GPIO Registers */
typedef struct {
    volatile uint32_t REVISION;         //0x00
    uint32_t RESERVED0[3];
    volatile uint32_t SYSCONFIG;        //0x10
    volatile uint32_t SYSSTATUS;        //0x14
    volatile uint32_t IRQSTATUS1;       //0x18
    volatile uint32_t IRQENABLE1;       //0x1C
    volatile uint32_t WAKEUPENABLE;     //0x20
    uint32_t RESERVED1[1];
    volatile uint32_t IRQSTATUS2;       //0x28
    volatile uint32_t IRQENABLE2;       //0x2C
    volatile uint32_t CTRL;             //0x30
    volatile uint32_t OE;               //0x34
    volatile uint32_t DATAIN;           //0x38
    volatile uint32_t DATAOUT;          //0x3C
    volatile uint32_t LEVELDETECT0;     //0x40
    volatile uint32_t LEVELDETECT1;     //0x44
    volatile uint32_t RISINGDETECT;     //0x48
    volatile uint32_t FALLINGDETECT;    //0x4C
    volatile uint32_t DEBOUNCENABLE;    //0x50
    volatile uint32_t DEBOUNCINGTIME;   //0x54
    uint32_t RESERVED2[2];
    volatile uint32_t CLEARIRQENABLE1;  //0x60
    volatile uint32_t SETIRQENABLE1;    //0x64
    uint32_t RESERVED3[2];
    volatile uint32_t CLEARIRQENABLE2;  //0x70
    volatile uint32_t SETIRQENABLE2;    //0x74
    uint32_t RESERVED4[2];
    volatile uint32_t CLEARWKUENA;      //0x80
    volatile uint32_t SETWKUENA;        //0x84
    uint32_t RESERVED5[2];
    volatile uint32_t CLEARDATAOUT;     //0x90
    volatile uint32_t SETDATAOUT;       //0x94
} GPIO_def;

#define GPIO1_ADDR		0x48310000UL
#define GPIO2_ADDR		0x49050000UL
#define GPIO3_ADDR		0x49052000UL
#define GPIO4_ADDR		0x49054000UL
#define GPIO5_ADDR		0x49056000UL
#define GPIO6_ADDR		0x49058000UL

#define GPIO1           ((GPIO_def *) GPIO1_ADDR)
#define GPIO2           ((GPIO_def *) GPIO2_ADDR)
#define GPIO3           ((GPIO_def *) GPIO3_ADDR)
#define GPIO4           ((GPIO_def *) GPIO4_ADDR)
#define GPIO5           ((GPIO_def *) GPIO5_ADDR)
#define GPIO6           ((GPIO_def *) GPIO6_ADDR)
