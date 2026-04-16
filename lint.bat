@echo off
set EXTENSIONS=*.cpp *.h *.hpp *.c *.cc *.cxx

echo Formatting files in current directory and subdirectories...

for /R %%f in (%EXTENSIONS%) do (
    echo Formatting "%%f"
    clang-format -i "%%f"
)

echo Done!

