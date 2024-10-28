# Makefile for SSAFY and MINE applications

# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra

# Targets
TARGETS = ssafy mine

# Build rules
all: $(TARGETS)

ssafy: ssafy.c
	$(CC) $(CFLAGS) -o ssafy ssafy.c

mine: mine.c
	$(CC) $(CFLAGS) -o mine mine.c

# Run mineApp and ssafyApp
run-mine:
	./mine

run-ssafy: 
	@echo "Usage: make run-ssafy MINE_PID=<mineApp_PID>"
	./ssafy $(MINE_PID)

# Clean up
clean:
	rm -f $(TARGETS)
	rm -f *.o

# Phony targets (these are not actual files)
.PHONY: all clean run-mine run-ssafy
