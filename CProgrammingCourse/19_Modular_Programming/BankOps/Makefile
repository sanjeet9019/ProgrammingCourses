##################################################
# Author       : Sanjeet Prasad                  #
# Email        : sanjeet8.23@gmail.com           #
# Description  : Makefile for C Bank Project     #
#               Compiles bank_main.c and         #
#               bank_module.c using bank_module.h#
# Date         : 28th June 2025                  #
##################################################

# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -g
TARGET  = BankApp

# Object files
OBJS    = bank_main.o bank_module.o

# Build the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile bank_main.c
bank_main.o: bank_main.c bank_module.h
	$(CC) $(CFLAGS) -c bank_main.c

# Compile bank_module.c
bank_module.o: bank_module.c bank_module.h
	$(CC) $(CFLAGS) -c bank_module.c

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf *.o *.gch $(TARGET)
