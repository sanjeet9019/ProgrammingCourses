############################################################
# Author        : Sanjeet Prasad
# Email         : sanjeet8.23@gmail.com
# Description   : Demonstrates modular unit testing in C 
#                 using the Unity framework. Each logical 
#                 assertion is split into a separate test 
#                 function for granular pass/fail analysis.
# Created On    : 14th July 2025
############################################################

# Compiler & Flags
GCC     = gcc
CFLAGS  = -g -Iinclude -Isrc -Iunity

# Source & Object Files
SRC     = src/math_util.c src/memory_util.c src/string_util.c src/control_flags.c src/bit_util.c
OBJS    = test/cunit_demo.o $(SRC:.c=.o) unity/unity.o

# Executable
TARGET  = cunit_demo

# Default Build Target
$(TARGET): $(OBJS)
	@echo "Building $(TARGET)..."
	$(GCC) -o $(TARGET) $(OBJS)

# Compile Test File Separately
test/cunit_demo.o: test/cunit_demo.c
	@echo "Compiling test file..."
	$(GCC) $(CFLAGS) -c $< -o $@

# Compile Unity and All Source Files
%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@

# Run the Test
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)

# Cleanup Artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -f $(OBJS) $(TARGET)