# object files
#
OBJS = main.o \
#   startup_stm32f0xx.o \
   system_stm32f0xx.o \
#   stm32f30x_it.o \
#   stm32f3_discovery.o \
   stm32f0xx_gpio.o \
#   stm32f30x_rcc.o \
#   stm32f30x_exti.o \
#   stm32f30x_syscfg.o \
#   stm32f30x_misc.o 
#
# library
#
LIB_ROOT = ../
#DEVICE = $(LIB_ROOT)/Libraries/CMSIS/Device/ST/STM32F30x
CORE = $(LIB_ROOT)/Include
PERIPH = $(LIB_ROOT)/Libraries/STM32F0xx_StdPeriph_Driver
BUILD_FILES = $(LIB_ROOT)/build
#DISCOVERY = $(LIB_ROOT)/Utilities/STM32F3_Discovery
#SYSTEM_FILE = $(LIB_ROOT)/Libraries/CMSIS/Device/ST/STM32F30x/Source/Templates
#STARTUP_FILE = $(LIB_ROOT)/Libraries/CMSIS/Device/ST/STM32F30x/Source/Templates/gcc_ride7
#
# search path
#
#vpath %.c $(DEVICE)
vpath %.c $(CORE)
vpath %.c $(PERIPH)/src
#vpath %.c $(DISCOVERY)
#vpath %.c $(SYSTEM_FILE)
#vpath %.s $(STARTUP_FILE)
#
# toolchain
#
TOOL_ROOT = /usr/bin
CC = $(TOOL_ROOT)/arm-none-eabi-gcc
LD = $(TOOL_ROOT)/arm-none-eabi-gcc
AR = $(TOOL_ROOT)/arm-none-eabi-ar
OBJCOPY = $(TOOL_ROOT)/arm-none-eabi-objcopy
#
# programmer
#
STLINK_ROOT = /usr/local/bin
#
# C flags
#
CFLAGS  = -O0 -g -Wall -I.\
   -mcpu=cortex-m0 -mthumb \
   -mfloat-abi=soft \
   -I$(CORE) \
   -I$(PERIPH)/inc \
   -DUSE_STDPERIPH_DRIVER
#
# loader script
#
#LDSCRIPT = stm32_flash.ld
#
# loader flags
#
#LDFLAGS+= -T$(LDSCRIPT) -mthumb -mcpu=cortex-m0 -nostdlib
LDFLAGS+= -mthumb -mcpu=cortex-m0 -nostdlib
#
# .o .c target
#
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	$(CC) -MM $(CFLAGS) $< > $*.d
#
# .o .s target
#
%.o: %.s
	$(CC) -c $(CFLAGS) $< -o $@
#
# .elf target
#
ELF = $(notdir $(CURDIR)).elf                    
$(ELF): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)
#
# .bin target
#
BIN = $(notdir $(CURDIR)).bin
%.bin: %.elf
	$(OBJCOPY) -O binary $< $@
#
# .hex target
#
HEX = $(notdir $(CURDIR)).hex
%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@
#
# make all
#
all: $(ELF) $(BIN) $(HEX)
#
# flash
#
flash: $(BIN)
	$(STLINK_ROOT)/st-flash write $(BIN) 0x8000000
#
# debug
#
debug: $(ELF)
	$(TOOL_ROOT)/arm-none-eabi-gdb  $(ELF)
#
# clean
#
clean:
	rm -f $(OBJS) $(OBJS:.o=.d) $(ELF) $(BIN) $(HEX) startup_stm32f*

