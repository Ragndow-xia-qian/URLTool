# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = D:\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Code\cpp\Qt5 Projects\OpenURLTool"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Code\cpp\Qt5 Projects\OpenURLTool\cmake-build-debug"

# Utility rule file for OpenURLTool_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/OpenURLTool_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenURLTool_autogen.dir/progress.make

CMakeFiles/OpenURLTool_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="D:\Code\cpp\Qt5 Projects\OpenURLTool\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target OpenURLTool"
	D:\CLion\bin\cmake\win\x64\bin\cmake.exe -E cmake_autogen "D:/Code/cpp/Qt5 Projects/OpenURLTool/cmake-build-debug/CMakeFiles/OpenURLTool_autogen.dir/AutogenInfo.json" Debug

OpenURLTool_autogen: CMakeFiles/OpenURLTool_autogen
OpenURLTool_autogen: CMakeFiles/OpenURLTool_autogen.dir/build.make
.PHONY : OpenURLTool_autogen

# Rule to build all files generated by this target.
CMakeFiles/OpenURLTool_autogen.dir/build: OpenURLTool_autogen
.PHONY : CMakeFiles/OpenURLTool_autogen.dir/build

CMakeFiles/OpenURLTool_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OpenURLTool_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OpenURLTool_autogen.dir/clean

CMakeFiles/OpenURLTool_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Code\cpp\Qt5 Projects\OpenURLTool" "D:\Code\cpp\Qt5 Projects\OpenURLTool" "D:\Code\cpp\Qt5 Projects\OpenURLTool\cmake-build-debug" "D:\Code\cpp\Qt5 Projects\OpenURLTool\cmake-build-debug" "D:\Code\cpp\Qt5 Projects\OpenURLTool\cmake-build-debug\CMakeFiles\OpenURLTool_autogen.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/OpenURLTool_autogen.dir/depend
