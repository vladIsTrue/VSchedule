# VSchedule
A program with a graphical user interface with visualization of employee vacation schedules 
and color indication of calendar months for which the specified limit on the number of employees 
per month (standard) has been exceeded.

## Requirements
-CMake 3.11 or better; 3.14+ highly recommended
-A C++17 compatible compiler
-Qt6 library
-Git
-Doxygen (optional)

## Build
-To configure:
```
cmake -S . -B build
```
-To build:
```
cmake --build build
```
-To build docs (requires Doxygen, output in build/docs/html):
```
cmake --build build --target docs
```