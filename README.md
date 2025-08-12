# C Project Template

This is a starter template for small-to-medium C projects using a structured layout.

## Folder Structure

- `src/` – All `.c` source files
- `include/` – All `.h` header files
- `build/` – Compiled object files and final binary

## Available Commands

```sh
make           # Build the development version (with debug symbols)
make prod      # Build the production version (optimized)
make run       # Run the development build
make valgrind  # Run valgrind memory checks
make clean     # Remove build artifacts
