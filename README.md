# Description

This is a toy program that I created when I was teaching myself C, meant to model a simple inventory database management system. The real meat of the code is the implementation of an ArrayList object, which is my approximation of a Python list (or as close as you can get to one in a non-object-oriented language). The database structure is then built on top of an ArrayList.

Also included is a file called ```reader.c```, containg a collection of utilities for receiving input from the buffer stream, but implemented in such a way so as to avoid the typical C quirks of dangling newline characters and the like. The user can also enter and store strings of arbitrary length, similarly to what one might do using the ```input()``` function in Python. Both this file and the ```arrayList.c``` file can be used in other code independently of the current project.

# Available Commands

```sh
make           # Build the development version (with debug symbols)
make prod      # Build the production version (optimized)
make run       # Run the development build
make valgrind  # Run valgrind memory checks
make clean     # Remove build artifacts
```
