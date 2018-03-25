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
include sources.mk

# Platform Overrides
PLATFORM = HOST 

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds 
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
Platform_Target = -D$(PLATFORM) 

# Compiler Flags and Defines
CC = 
LD = arm-none-eabi-ld
TARGET = c1m2
LDFLAGS = 
CFLAGS = 
CPPFLAGs = 
GFLAGS = -Wall -g -O0 -std=c99


