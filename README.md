# calculator

A python like lightweight calculator extensible for more complex calculations. 
[![CMake](https://github.com/johnwyz88/calculator/actions/workflows/cmake.yml/badge.svg)](https://github.com/johnwyz88/calculator/actions/workflows/cmake.yml)
[![Release](https://img.shields.io/badge/release-v0.2-informational)](https://github.com/johnwyz88/calculator/releases/latest)


## Install 

```console
$ git clone https://github.com/johnwyz88/calculator.git
$ cd calculator && mkdir build && cd build
$ cmake .. && make -j
$ ./runner
```
      
   see example [CMakeLists.txt](https://github.com/johnwyz88/calculator/blob/master/CMakeLists.txt) on how to use.

## Platforms
 * Linux, FreeBSD, OpenBSD, Solaris, AIX
 * Windows (msvc 2013+, cygwin)
 * macOS (clang 3.5+)
 * Android



## Features
* Numeric operator support
* Binary operator support
* Boolean operator support
* Variable declaration
 
## User manual

#### Basic operators

| Operator | Description |
| --------------- | --------------- |
| ( | Open Paren |
| ) | Close Paren |
| * | Multiply |
| / | Divide |
| % | Modulo |
| + | Add |
| - | Subtract |
| \| | Binary Or |
| & | Binary And |
| ^ | Xor |
| ! | Not |
| && | Boolean And |
| \|\| | Boolean Or |
| = | Assignment |
| ** | Exponent |
