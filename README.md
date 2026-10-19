# CppFundamental

A collection of C++ practice programs written while learning the language. Each program is a small exercise on one topic, so the repo grows as I move along.

## What's in here

Standalone `.cpp` files, one concept per file. Topics covered so far include:

- Basics: variables, input/output, operators, control flow
- Functions
- Arrays and strings
- File handling with `fstream` (opening files with `open()` and with the constructor, reading and writing text files)

I'll keep adding to this list as I practice more.

## Running a program

You need a C++ compiler such as g++. I use g++ from MSYS2 (UCRT64) on Windows, with VS Code and the Code Runner extension.

Compile and run from a terminal:

```
g++ filename.cpp -o filename
./filename
```

On Windows, run `filename.exe` instead of `./filename`.

## Project structure

```
CppFundamental/
├── README.md
└── *.cpp
```

## Notes

- These are practice programs, so some are rough or unfinished.
- Some file handling programs create text files (like `abc.txt`) in the folder where they run.
