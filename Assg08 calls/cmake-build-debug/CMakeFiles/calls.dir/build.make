# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /cygdrive/c/Users/aswin/.CLion2018.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/aswin/.CLion2018.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/calls.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/calls.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calls.dir/flags.make

CMakeFiles/calls.dir/calls.c.o: CMakeFiles/calls.dir/flags.make
CMakeFiles/calls.dir/calls.c.o: ../calls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/calls.dir/calls.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/calls.dir/calls.c.o   -c "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls/calls.c"

CMakeFiles/calls.dir/calls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/calls.dir/calls.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls/calls.c" > CMakeFiles/calls.dir/calls.c.i

CMakeFiles/calls.dir/calls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/calls.dir/calls.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls/calls.c" -o CMakeFiles/calls.dir/calls.c.s

# Object files for target calls
calls_OBJECTS = \
"CMakeFiles/calls.dir/calls.c.o"

# External object files for target calls
calls_EXTERNAL_OBJECTS =

calls.exe: CMakeFiles/calls.dir/calls.c.o
calls.exe: CMakeFiles/calls.dir/build.make
calls.exe: CMakeFiles/calls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable calls.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calls.dir/build: calls.exe

.PHONY : CMakeFiles/calls.dir/build

CMakeFiles/calls.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calls.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calls.dir/clean

CMakeFiles/calls.dir/depend:
	cd "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls/cmake-build-debug" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls/cmake-build-debug" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg08 calls/cmake-build-debug/CMakeFiles/calls.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/calls.dir/depend

