# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/emerson/github/compilers/calculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emerson/github/compilers/calculator/build

# Include any dependencies generated for this target.
include CMakeFiles/calc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/calc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calc.dir/flags.make

CMakeFiles/calc.dir/parsemain.cpp.o: CMakeFiles/calc.dir/flags.make
CMakeFiles/calc.dir/parsemain.cpp.o: ../parsemain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emerson/github/compilers/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calc.dir/parsemain.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/calc.dir/parsemain.cpp.o -c /home/emerson/github/compilers/calculator/parsemain.cpp

CMakeFiles/calc.dir/parsemain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calc.dir/parsemain.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emerson/github/compilers/calculator/parsemain.cpp > CMakeFiles/calc.dir/parsemain.cpp.i

CMakeFiles/calc.dir/parsemain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calc.dir/parsemain.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emerson/github/compilers/calculator/parsemain.cpp -o CMakeFiles/calc.dir/parsemain.cpp.s

CMakeFiles/calc.dir/parsemain.cpp.o.requires:

.PHONY : CMakeFiles/calc.dir/parsemain.cpp.o.requires

CMakeFiles/calc.dir/parsemain.cpp.o.provides: CMakeFiles/calc.dir/parsemain.cpp.o.requires
	$(MAKE) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/parsemain.cpp.o.provides.build
.PHONY : CMakeFiles/calc.dir/parsemain.cpp.o.provides

CMakeFiles/calc.dir/parsemain.cpp.o.provides.build: CMakeFiles/calc.dir/parsemain.cpp.o


# Object files for target calc
calc_OBJECTS = \
"CMakeFiles/calc.dir/parsemain.cpp.o"

# External object files for target calc
calc_EXTERNAL_OBJECTS =

calc: CMakeFiles/calc.dir/parsemain.cpp.o
calc: CMakeFiles/calc.dir/build.make
calc: CMakeFiles/calc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emerson/github/compilers/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable calc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calc.dir/build: calc

.PHONY : CMakeFiles/calc.dir/build

CMakeFiles/calc.dir/requires: CMakeFiles/calc.dir/parsemain.cpp.o.requires

.PHONY : CMakeFiles/calc.dir/requires

CMakeFiles/calc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calc.dir/clean

CMakeFiles/calc.dir/depend:
	cd /home/emerson/github/compilers/calculator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emerson/github/compilers/calculator /home/emerson/github/compilers/calculator /home/emerson/github/compilers/calculator/build /home/emerson/github/compilers/calculator/build /home/emerson/github/compilers/calculator/build/CMakeFiles/calc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calc.dir/depend

