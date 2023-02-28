PROJECT	= bbxm

CSRCS	= boot.c main.c 
OBJ		= boot.o main.o
LDS		= linker.ld

PREFIX	= arm-none-eabi-

CFLAGS	=  -W -Wall 
CFLAGS 	+= -g3 -Os -ffunction-sections -fdata-sections
CFLAGS  += -mtune=cortex-a8
CFLAGS  += -I./include/ -I./ 

LDFLAGS	= -T$(LDS) --specs=nano.specs --specs=nosys.specs -Wl,--gc-sections -Wl,-Map=$@.map

OBJS = $(SOURCES:.c=.o)

all: $(PROJECT).elf

# compile
$(PROJECT).elf: $(OBJ)
	$(PREFIX)gcc $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c $(DEPS)
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