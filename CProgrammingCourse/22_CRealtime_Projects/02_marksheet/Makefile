# Compiler name
CC = gcc

# Compiler flags: enable all warnings
CFLAGS = -Wall

# Object files
OBJ = main.o marksheet.o

# Output executable name
TARGET = MarksheetApp

# Default target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Pattern rule for compiling .c to .o
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

# Clean up build artifacts
.PHONY: clean
clean:
	rm -rf *.o $(TARGET)