# Makefile for the C Converter Program

# Define the C compiler to use
CC = gcc

# Define compiler flags
# -Wall: Enable all common warnings
# -Wextra: Enable extra warnings
# -std=c11: Use C11 standard
# -g: Include debugging information
CFLAGS = -Wall -Wextra -std=c11 -g

# Define the executable name
TARGET = converter_app

# Define source files
SRCS = converter.c main.c

# Automatically generate object file names from source files
OBJS = $(SRCS:.c=.o)

# Default target: builds the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule to compile each C source file into an object file
# $<: The first prerequisite (e.g., converter.c)
# $@: The target of the rule (e.g., converter.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Phony targets: these are not actual files
.PHONY: all clean

# Clean rule: removes object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)