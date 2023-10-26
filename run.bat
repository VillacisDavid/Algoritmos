@echo off
IF NOT EXIST ".\build" (mkdir build)
cd build
cmake ..\source
cmake --build .
.\Debug\main.exe
cd ..