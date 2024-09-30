# Makefile for SSAFY Shell

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable
TARGET = ssafy_shell

# Source files
SRC = ssafy_shell.c

# Default rule to build the executable
all: $(TARGET)

# Rule to compile the source file into an executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean rule to remove compiled files
clean:
	rm -f $(TARGET)
	rm -f *.o
