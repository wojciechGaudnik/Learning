# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bq666/Workspace/C_C++/CriterionSample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug

# Include any dependencies generated for this target.
include test_abnormal/CMakeFiles/test_abnormal.dir/depend.make

# Include the progress variables for this target.
include test_abnormal/CMakeFiles/test_abnormal.dir/progress.make

# Include the compile flags for this target's objects.
include test_abnormal/CMakeFiles/test_abnormal.dir/flags.make

test_abnormal/CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.o: test_abnormal/CMakeFiles/test_abnormal.dir/flags.make
test_abnormal/CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.o: ../source/dangerous_add.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test_abnormal/CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.o"
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.o   -c /home/bq666/Workspace/C_C++/CriterionSample/source/dangerous_add.c

test_abnormal/CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.i"
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bq666/Workspace/C_C++/CriterionSample/source/dangerous_add.c > CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.i

test_abnormal/CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.s"
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bq666/Workspace/C_C++/CriterionSample/source/dangerous_add.c -o CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.s

test_abnormal/CMakeFiles/test_abnormal.dir/test_exit.c.o: test_abnormal/CMakeFiles/test_abnormal.dir/flags.make
test_abnormal/CMakeFiles/test_abnormal.dir/test_exit.c.o: ../test_abnormal/test_exit.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object test_abnormal/CMakeFiles/test_abnormal.dir/test_exit.c.o"
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_abnormal.dir/test_exit.c.o   -c /home/bq666/Workspace/C_C++/CriterionSample/test_abnormal/test_exit.c

test_abnormal/CMakeFiles/test_abnormal.dir/test_exit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_abnormal.dir/test_exit.c.i"
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bq666/Workspace/C_C++/CriterionSample/test_abnormal/test_exit.c > CMakeFiles/test_abnormal.dir/test_exit.c.i

test_abnormal/CMakeFiles/test_abnormal.dir/test_exit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_abnormal.dir/test_exit.c.s"
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bq666/Workspace/C_C++/CriterionSample/test_abnormal/test_exit.c -o CMakeFiles/test_abnormal.dir/test_exit.c.s

test_abnormal/CMakeFiles/test_abnormal.dir/test_signal.c.o: test_abnormal/CMakeFiles/test_abnormal.dir/flags.make
test_abnormal/CMakeFiles/test_abnormal.dir/test_signal.c.o: ../test_abnormal/test_signal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object test_abnormal/CMakeFiles/test_abnormal.dir/test_signal.c.o"
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_abnormal.dir/test_signal.c.o   -c /home/bq666/Workspace/C_C++/CriterionSample/test_abnormal/test_signal.c

test_abnormal/CMakeFiles/test_abnormal.dir/test_signal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_abnormal.dir/test_signal.c.i"
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bq666/Workspace/C_C++/CriterionSample/test_abnormal/test_signal.c > CMakeFiles/test_abnormal.dir/test_signal.c.i

test_abnormal/CMakeFiles/test_abnormal.dir/test_signal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_abnormal.dir/test_signal.c.s"
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bq666/Workspace/C_C++/CriterionSample/test_abnormal/test_signal.c -o CMakeFiles/test_abnormal.dir/test_signal.c.s

# Object files for target test_abnormal
test_abnormal_OBJECTS = \
"CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.o" \
"CMakeFiles/test_abnormal.dir/test_exit.c.o" \
"CMakeFiles/test_abnormal.dir/test_signal.c.o"

# External object files for target test_abnormal
test_abnormal_EXTERNAL_OBJECTS =

test_abnormal/test_abnormal: test_abnormal/CMakeFiles/test_abnormal.dir/__/source/dangerous_add.c.o
test_abnormal/test_abnormal: test_abnormal/CMakeFiles/test_abnormal.dir/test_exit.c.o
test_abnormal/test_abnormal: test_abnormal/CMakeFiles/test_abnormal.dir/test_signal.c.o
test_abnormal/test_abnormal: test_abnormal/CMakeFiles/test_abnormal.dir/build.make
test_abnormal/test_abnormal: test_abnormal/CMakeFiles/test_abnormal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable test_abnormal"
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_abnormal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test_abnormal/CMakeFiles/test_abnormal.dir/build: test_abnormal/test_abnormal

.PHONY : test_abnormal/CMakeFiles/test_abnormal.dir/build

test_abnormal/CMakeFiles/test_abnormal.dir/clean:
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal && $(CMAKE_COMMAND) -P CMakeFiles/test_abnormal.dir/cmake_clean.cmake
.PHONY : test_abnormal/CMakeFiles/test_abnormal.dir/clean

test_abnormal/CMakeFiles/test_abnormal.dir/depend:
	cd /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bq666/Workspace/C_C++/CriterionSample /home/bq666/Workspace/C_C++/CriterionSample/test_abnormal /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal /home/bq666/Workspace/C_C++/CriterionSample/cmake-build-debug/test_abnormal/CMakeFiles/test_abnormal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test_abnormal/CMakeFiles/test_abnormal.dir/depend

