#******************************************************************************
# Copyright (C) 2017 by Abhinand
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Abhinand is not liable for any misuse of this material.
#  
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      <FILE>.asm - Generate assembly output of c-program implementation files and the final output executable 
#					(Use the –S flag and the objdump utility).
#      <FILE>.i - Generate the preprocessed output of all c-program implementation files (use the –E flag).
#	   build - Builds and links all source files
#      all - Same as build
#      clean - Removes all generated files
#       
# Platform Overrides:
#    -HOST       - Builds for host / virtual machine
#    -MSP432     - Builds for arm architechture board
#
# $(TARGET): $(OBJS)
#		$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $(TARGET) $(OBJS)
#------------------------------------------------------------------------------

include sources.mk

#BASENAME = c1m2
TARGET = c1m2

# Architecture Specific Flags
LINKER_FILE = msp432p401r.lds 

CPU = cortex-m4
ARCH = thumb # armv7e-m 
SPECS = nosys.specs
# ABI = hard
FPU =fpv4-sp-d16
#-march=armv7e-m

ifeq ($(PLATFORM),MSP432)
	# Compile Defines
	CC = arm-none-eabi-gcc #Compiler that will perform the build (Native or Cross)
	LD = arm-none-eabi-ld # compiler fot linker 
	CFLAGS =  -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall #C-programming flags for gcc
	CPPFLAGS = -Wall -Werror -g -O0 -std=c99 -march=armv7e-m -mfloat-abi=hard -mfpu=$(FPU) #C-Preprocessor Flags
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE) # $(LINKER_FILE) #Linker Flags
	SIZE = arm-none-eabi-size


else ifeq ($(PLATFORM),HOST)

	CC = gcc
	LD = ld
	CPPFLAGS = -Wall -Werror -g -O0 -std=c99 #C-Preprocessor Flags
	CFLAGS = -DHOST
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJDUMP = objdump 
	SIZE = size

endif


DEPND = $(SRCS:.c=.d)

OBJS = $(SRCS:.c=.o)

%.i:%.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -E $< -o $@

%.asm:%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -S $< -o $@

%.o:%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

%.d:%.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(INCLUDES)  -MM $<  -o $@

$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@
	#$(OBJDUMP)  $< $(TARGET) -d $@
	#$(CC) $^ $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ 

.PHONY: build
build: $(TARGET).out $(TARGET).asm

$(TARGET).out: $(OBJS) $(DEPND)
	$(CC) $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(INCLUDES) -o $@
# 	$(SIZE) -Atd $(TARGET).out
# 	$(SIZE) $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -o $@ 
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out

.PHONY: compile-all
compile-all: $(SRCS) $(OBJS)
	$(CC) -c $^ $(OBJS) $(SRCS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).asm $(TARGET).out $(TARGET).map *.i *.o *.asm *.d

