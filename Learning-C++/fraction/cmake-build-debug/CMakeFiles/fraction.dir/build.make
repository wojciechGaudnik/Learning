# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/bq666/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5233.144/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/bq666/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5233.144/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bq666/Workspace/C_C++/fraction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bq666/Workspace/C_C++/fraction/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fraction.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fraction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fraction.dir/flags.make

CMakeFiles/fraction.dir/main.c.o: CMakeFiles/fraction.dir/flags.make
CMakeFiles/fraction.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bq666/Workspace/C_C++/fraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fraction.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fraction.dir/main.c.o   -c /home/bq666/Workspace/C_C++/fraction/main.c

CMakeFiles/fraction.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fraction.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bq666/Workspace/C_C++/fraction/main.c > CMakeFiles/fraction.dir/main.c.i

CMakeFiles/fraction.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fraction.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bq666/Workspace/C_C++/fraction/main.c -o CMakeFiles/fraction.dir/main.c.s

# Object files for target fraction
fraction_OBJECTS = \
"CMakeFiles/fraction.dir/main.c.o"

# External object files for target fraction
fraction_EXTERNAL_OBJECTS =

fraction: CMakeFiles/fraction.dir/main.c.o
fraction: CMakeFiles/fraction.dir/build.make
fraction: CMakeFiles/fraction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bq666/Workspace/C_C++/fraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fraction"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fraction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fraction.dir/build: fraction

.PHONY : CMakeFiles/fraction.dir/build

CMakeFiles/fraction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fraction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fraction.dir/clean

CMakeFiles/fraction.dir/depend:
	cd /home/bq666/Workspace/C_C++/fraction/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bq666/Workspace/C_C++/fraction /home/bq666/Workspace/C_C++/fraction /home/bq666/Workspace/C_C++/fraction/cmake-build-debug /home/bq666/Workspace/C_C++/fraction/cmake-build-debug /home/bq666/Workspace/C_C++/fraction/cmake-build-debug/CMakeFiles/fraction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fraction.dir/depend

