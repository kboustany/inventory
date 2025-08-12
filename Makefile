# Available make commands:
# 
# make           # Build the development version of the program (with debug symbols and no optimization).
# make all       # Same as 'make'; builds the development version.
# make prod      # Clean and build the production version of the program (with no debug symbols and with optimization).
# make run       # Run the development build executable.
# make valgrind  # Run valgrind memory checker on the development build executable.
# make clean     # Remove all build artifacts (executables, object files, dependencies).


# Directories.
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Compiler and flags.
CC = gcc

# Development flags: include debug symbols, no optimization.
CFLAGS_DEV = -Wall -Wextra -g -O0 -I$(INC_DIR) -MMD -MP

# Production flags: no debug symbols, optimization.
CFLAGS_PROD = -Wall -O2 -I$(INC_DIR) -MMD -MP

# Default (development) build flags.
CFLAGS = $(CFLAGS_DEV)

# Target executable name.
TARGET = $(BUILD_DIR)/main

# Source files (from src/).
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object and dependency files (go in build/).
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

# Build (default) development target.
all: $(TARGET)

# Build (optimized) production target.
prod: CFLAGS = $(CFLAGS_PROD)
prod: clean $(TARGET)

# Link object files into executable.
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile .c files in src/ to .o in build/.
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Include dependency files if present.
-include $(DEPS)

# Run program normally (development build).
run: $(TARGET)
	./$(TARGET)

# Run program with valgrind (development build).
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Clean up build files.
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all prod run valgrind clean
