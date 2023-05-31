# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sofi/deleteMe/demod

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sofi/deleteMe/demod/build

# Include any dependencies generated for this target.
include TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/compiler_depend.make

# Include the progress variables for this target.
include TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/progress.make

# Include the compile flags for this target's objects.
include TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/flags.make

TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/source/Demodulator.cpp.o: TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/flags.make
TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/source/Demodulator.cpp.o: ../TestTask/libs/Demodulator/source/Demodulator.cpp
TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/source/Demodulator.cpp.o: TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sofi/deleteMe/demod/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/source/Demodulator.cpp.o"
	cd /home/sofi/deleteMe/demod/build/TestTask/libs/Demodulator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/source/Demodulator.cpp.o -MF CMakeFiles/Demodulator.dir/source/Demodulator.cpp.o.d -o CMakeFiles/Demodulator.dir/source/Demodulator.cpp.o -c /home/sofi/deleteMe/demod/TestTask/libs/Demodulator/source/Demodulator.cpp

TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/source/Demodulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Demodulator.dir/source/Demodulator.cpp.i"
	cd /home/sofi/deleteMe/demod/build/TestTask/libs/Demodulator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sofi/deleteMe/demod/TestTask/libs/Demodulator/source/Demodulator.cpp > CMakeFiles/Demodulator.dir/source/Demodulator.cpp.i

TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/source/Demodulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Demodulator.dir/source/Demodulator.cpp.s"
	cd /home/sofi/deleteMe/demod/build/TestTask/libs/Demodulator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sofi/deleteMe/demod/TestTask/libs/Demodulator/source/Demodulator.cpp -o CMakeFiles/Demodulator.dir/source/Demodulator.cpp.s

# Object files for target Demodulator
Demodulator_OBJECTS = \
"CMakeFiles/Demodulator.dir/source/Demodulator.cpp.o"

# External object files for target Demodulator
Demodulator_EXTERNAL_OBJECTS =

tddProject/binaries/lib/libDemodulator.so: TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/source/Demodulator.cpp.o
tddProject/binaries/lib/libDemodulator.so: TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/build.make
tddProject/binaries/lib/libDemodulator.so: TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sofi/deleteMe/demod/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../../tddProject/binaries/lib/libDemodulator.so"
	cd /home/sofi/deleteMe/demod/build/TestTask/libs/Demodulator && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Demodulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/build: tddProject/binaries/lib/libDemodulator.so
.PHONY : TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/build

TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/clean:
	cd /home/sofi/deleteMe/demod/build/TestTask/libs/Demodulator && $(CMAKE_COMMAND) -P CMakeFiles/Demodulator.dir/cmake_clean.cmake
.PHONY : TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/clean

TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/depend:
	cd /home/sofi/deleteMe/demod/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sofi/deleteMe/demod /home/sofi/deleteMe/demod/TestTask/libs/Demodulator /home/sofi/deleteMe/demod/build /home/sofi/deleteMe/demod/build/TestTask/libs/Demodulator /home/sofi/deleteMe/demod/build/TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TestTask/libs/Demodulator/CMakeFiles/Demodulator.dir/depend

