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
CMAKE_BINARY_DIR = /home/sofi/deleteMe/demod

# Utility rule file for distclean.

# Include any custom commands dependencies for this target.
include CMakeFiles/distclean.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/distclean.dir/progress.make

CMakeFiles/distclean:
	find . -name *_automoc.cpp -type f -delete
	find . -name moc_*cpp -type f -delete
	find . -name *_t -type f -delete
	rm -rf ./binnaries/lib/*
	rm -rf ./binnaries/plugins/*
	rm -rf ./binnaries/tasks/*

distclean: CMakeFiles/distclean
distclean: CMakeFiles/distclean.dir/build.make
.PHONY : distclean

# Rule to build all files generated by this target.
CMakeFiles/distclean.dir/build: distclean
.PHONY : CMakeFiles/distclean.dir/build

CMakeFiles/distclean.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/distclean.dir/cmake_clean.cmake
.PHONY : CMakeFiles/distclean.dir/clean

CMakeFiles/distclean.dir/depend:
	cd /home/sofi/deleteMe/demod && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sofi/deleteMe/demod /home/sofi/deleteMe/demod /home/sofi/deleteMe/demod /home/sofi/deleteMe/demod /home/sofi/deleteMe/demod/CMakeFiles/distclean.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/distclean.dir/depend
