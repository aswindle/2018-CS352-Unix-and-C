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
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/assg1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/assg1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assg1.dir/flags.make

CMakeFiles/assg1.dir/main.c.o: CMakeFiles/assg1.dir/flags.make
CMakeFiles/assg1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/assg1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/assg1.dir/main.c.o   -c "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1/main.c"

CMakeFiles/assg1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assg1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1/main.c" > CMakeFiles/assg1.dir/main.c.i

CMakeFiles/assg1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assg1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1/main.c" -o CMakeFiles/assg1.dir/main.c.s

# Object files for target assg1
assg1_OBJECTS = \
"CMakeFiles/assg1.dir/main.c.o"

# External object files for target assg1
assg1_EXTERNAL_OBJECTS =

assg1.exe: CMakeFiles/assg1.dir/main.c.o
assg1.exe: CMakeFiles/assg1.dir/build.make
assg1.exe: CMakeFiles/assg1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable assg1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assg1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assg1.dir/build: assg1.exe

.PHONY : CMakeFiles/assg1.dir/build

CMakeFiles/assg1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assg1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assg1.dir/clean

CMakeFiles/assg1.dir/depend:
	cd "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1/cmake-build-debug" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1/cmake-build-debug" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assignment 1/assg1/cmake-build-debug/CMakeFiles/assg1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/assg1.dir/depend

