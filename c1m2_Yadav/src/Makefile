#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Makefile for the c1m2 assessment>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <File>.i : Generate the preprocessed output of c-program files.
#      <File>.asm : Generate assembly output of c-program files and
#                   final output executable.
#      <File>.o : Generate the object file for c-source files.
#      compile-all : Compile all object files without linking.
#      Build : Compile all object files and link to final executable.
#      Clean : remove all non-source build files like .o,.asm etc. 
#
# Platform Overrides:
#      PLATFORM : For native or cross compilation (HOST,MSP432)
#
#------------------------------------------------------------------------------
# Platform Overrides
PLATFORM = HOST 

include sources.mk
# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds 
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
PLATFORM_TARGET = -D$(PLATFORM) 

# Compiler Flags and Defines	 
LD = arm-none-eabi-ld
TARGET = c1m2
CPPFLAGS = -Wall -g -std=c99
CC = gcc
LDFLAGS = -Wl,-Map=$(TARGET).map
CFLAGS = $(CPPFLAGS) $(PLATFORM_TARGET)

ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	CFLAGS = $(CPPFLAGS) $(PLATFORM_TARGET) -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m \
          -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
endif

%.i : %.c
	$(CC) $(CFLAGS) -E $< -o $@

%.asm : %.c
	$(CC) $(CFLAGS) -S $< -o $@
	
%.o : %.c                           
	$(CC)  $(CFLAGS) -c $< -o $@

OBJS = $(SOURCES:.c=.o)

.PHONY: compile-all
compile-all: $(OBJS)
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: Build
Build: $(TARGET).out
$(TARGET).out:$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -MD -o $@

.PHONY: Clean
Clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map *.i *.asm  
	


