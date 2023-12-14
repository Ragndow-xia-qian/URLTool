@REM Change 'cmake' to the path of your CMake
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - MinGW Makefiles" -S . -B ./cmake-build-debug

@REM Compile the project
cmake --build ./cmake-build-debug --config Debug
