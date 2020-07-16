#******************************************************************************
# Copyright (C) 2017 by Abhinand
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Abhinand are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for the cortex-M0+ build system
#
# Use: make [TARGET] [OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#
#------------------------------------------------------------------------------
include sources.mk

# PLATFORM = HOST

TARGET = main

# Architecture Specific Flags
# CPU = cortex-m0plus
# ARCH = thumb
# SPECS = nosys.specs

# Platform Specific Flags
LINKER_FILE = msp432p401r.lds

# Compile Defines
CC = gcc
LD = ld
CPPFLAGS = -Wall -Werror -g -O0 -std=c99 #C-Preprocessor Flags
CFLAGS = -DHOST
LDFLAGS = -Wl,-Map=$(TARGET).map
OBJDUMP = objdump 
SIZE = size

OBJS = $(SRCS:.c=.o)


%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -g $< -o $@

%.asm:%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -S $< -o $@


.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
# 	$(SIZE) -Atd $(TARGET).out
# 	$(SIZE) $(TARGET).out

$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

.PHONY: compile-all
compile-all: $(SRCS) $(OBJS)
	$(CC) -c $^ $(OBJS) $(SRCS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).asm $(TARGET).out $(TARGET).map

