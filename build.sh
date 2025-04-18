#!/bin/bash

## Create build directories if they don't already exist
mkdir build-windows
mkdir build

## Create Windows toolchain file
TOOLCHAIN_FILE="mingw-toolchain.cmake"

cat > build-windows/$TOOLCHAIN_FILE <<EOL
# Built from build.sh
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
EOL


## Build for Mac/Linux
cd build &&
cmake .. &&
cmake --build . &&
cd ..

## Build for Windows
cd build-windows &&
cmake .. -DCMAKE_TOOLCHAIN_FILE=./$TOOLCHAIN_FILE &&
cmake --build . &&
cd ..

## Copy the built files to the root directory
cp build/OS-Ready ../OS-Ready
cp build-windows/OS-Ready.exe ./OS-Ready.exe