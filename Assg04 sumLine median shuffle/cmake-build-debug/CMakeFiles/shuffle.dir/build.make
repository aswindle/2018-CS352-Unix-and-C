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
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/shuffle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/shuffle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shuffle.dir/flags.make

CMakeFiles/shuffle.dir/shuffle.c.o: CMakeFiles/shuffle.dir/flags.make
CMakeFiles/shuffle.dir/shuffle.c.o: ../shuffle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/shuffle.dir/shuffle.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/shuffle.dir/shuffle.c.o   -c "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/shuffle.c"

CMakeFiles/shuffle.dir/shuffle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/shuffle.dir/shuffle.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/shuffle.c" > CMakeFiles/shuffle.dir/shuffle.c.i

CMakeFiles/shuffle.dir/shuffle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/shuffle.dir/shuffle.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/shuffle.c" -o CMakeFiles/shuffle.dir/shuffle.c.s

# Object files for target shuffle
shuffle_OBJECTS = \
"CMakeFiles/shuffle.dir/shuffle.c.o"

# External object files for target shuffle
shuffle_EXTERNAL_OBJECTS =

shuffle.exe: CMakeFiles/shuffle.dir/shuffle.c.o
shuffle.exe: CMakeFiles/shuffle.dir/build.make
shuffle.exe: CMakeFiles/shuffle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable shuffle.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shuffle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shuffle.dir/build: shuffle.exe

.PHONY : CMakeFiles/shuffle.dir/build

CMakeFiles/shuffle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shuffle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shuffle.dir/clean

CMakeFiles/shuffle.dir/depend:
	cd "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug/CMakeFiles/shuffle.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/shuffle.dir/depend
