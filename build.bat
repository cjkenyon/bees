@echo off
if not exist build mkdir build
cl /EHsc /Zi ./src/main.cpp ./src/log.cpp /Fe:./build/main.exe /link /subsystem:windows user32.lib
