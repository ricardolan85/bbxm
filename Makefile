PROJECT	= bbxm

SRCS	= boot.c main.c 
OBJS	= boot.o main.o
LDS		= linker.lds

PREFIX	= arm-none-eabi-

CFLAGS	=  -W -Wall
CFLAGS 	+= -g3 -Os -ffunction-sections -fdata-sections
CFLAGS  += -mtune=cortex-a8
CFLAGS  += -I./include/ -I./ 

LDFLAGS	= -T$(LDS) --specs=nano.specs --specs=nosys.specs -Wl,--gc-sections -Wl,-Map=$@.map


all: $(PROJECT).elf

$(PROJECT).elf: $(OBJS)
	$(PREFIX)gcc $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c
	$(PREFIX)gcc -c $(CFLAGS) $< -o $@

bin: $(PROJECT).elf
	$(PREFIX)objcopy -O binary $(PROJECT).elf $(PROJECT).bin

hex: $(PROJECT).elf
	$(PREFIX)objcopy -O ihex $(PROJECT).elf $(PROJECT).hex

size: $(PROJECT).elf
	$(PREFIX)size $(PROJECT).elf

readelf: $(PROJECT).elf
	$(PREFIX)readelf -s $(PROJECT).elf

dump: $(PROJECT).elf
	$(PREFIX)objdump -d $(PROJECT).elf > $(PROJECT).dump

clean:
	del *.elf
	del *.o
	del *.hex
	del *.bin
	del *.dump
	del *.map
