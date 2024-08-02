# Simple Calculator Ex

1. main.cpp - Contains the main function
2. add.cpp - Contains the addition function
3. subtract.cpp - Contains the subtraction function
4. calculator.h - Header file with function declarations

Without make, you'd have to compile this program manually:

```cmd
g++ -c main.cpp
g++ -c add.cpp
g++ -c subtract.cpp
g++ main.o add.o subtract.o -o calculator
```

This process is tedious and error-prone, especially for larger projects. Now, let's see why make is useful:

1. Create makefile
2. Now, you can simply run:

```cmd
make
```

## How to run

```cmd
make
./calculator

// to clean up
make clean
```

## make will

- Automatically determine which files need to be recompiled based on modification times
- Compile only the necessary files
- Link the object files to create the final executable

If you change only add.cpp, running make again will recompile only add.cpp and relink the executable, saving time.
This example demonstrates why make is useful:

1. It automates the build process
2. It manages dependencies between files
3. It only recompiles what's necessary, saving time
4. It standardizes the build process, making it easier for others to compile your project
