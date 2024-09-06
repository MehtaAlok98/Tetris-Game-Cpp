# Tetris-Raylib-Cpp
### a Simple Tetris Game made with Raylib C++<br/>


KEY LEFT, KEY DOWN, KEY RIGHT -> For block control.<br/>
KEY UP -> For rotate block.<br/>
KEY R -> For restart.<br/>
KEY P -> For Pause.<br/>

![tetris](https://github.com/ilyascant/Tetris-Raylib-Cpp/assets/79863003/6da2e33e-be05-4213-a94d-60e2c2451881)

Each row combo earns 250 Points.<br/>
Each block placement earns 25 Points.<br/>
Moving block at top speed earns 1 Points for each 1/10 seconds.<br/>

![Game itself](https://github.com/ilyascant/Tetris-Raylib-Cpp/assets/79863003/a3c23833-3e91-4daa-83e8-0ec0665e0008)
![Pause Screen](https://github.com/ilyascant/Tetris-Raylib-Cpp/assets/79863003/4d0314d6-51f7-4e4e-9841-78442f380e8c)
![End Screen](https://github.com/ilyascant/Tetris-Raylib-Cpp/assets/79863003/be408cb9-073b-4a43-a18e-3d250cdb4157)

<img src="https://t.bkit.co/w_6688c8a91c175.gif" />

## Installation and Dependencies
### Prerequisites:
- Python 3.x: Required for Conan package management.
   ```bash
   pip install conan
   ```
- g++ Compiler: Ensure you have a C++ compiler installed (e.g., GCC on Linux, MinGW on Windows).
- Conan: A package manager for C++ dependencies.
- CMake: Used for configuring and generating build systems.
Ninja (Optional): For faster builds if you prefer it over Make.

### Conan Profile and Installation:
1. Detect and create a Conan profile named custompr based on your system:

   ```bash
   conan profile detect --name custompr
   ```
   sample profile settings
   ```text
    [settings]
    os=Windows
    compiler=gcc
    compiler.version=12
    compiler.libcxx=libstdc++11
    compiler.threads=posix
    compiler.exception=sjlj
    arch=x86_64
    build_type=Debug

    [conf]
    tools.cmake.cmaketoolchain:generator=Ninja
    ```
2. Install dependencies using the conan install command:
   ```bash
   conan install . --build=missing -s build_type=Release -pr=custompr
   ```
## Build Instructions
### Steps to Build:
Configure CMake with the conan-release preset:

```bash
cmake --preset conan-release
```
Build the project using CMake:

```bash
cmake --build build/Release
```
Run the Game:

```bash
./build/Release/bin/TetrisGame.exe
```

Run Tests:

```bash
cd build/Release
ctest --verbose
```
