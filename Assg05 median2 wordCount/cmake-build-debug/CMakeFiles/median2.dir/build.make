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
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/median2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/median2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/median2.dir/flags.make

CMakeFiles/median2.dir/median2.c.o: CMakeFiles/median2.dir/flags.make
CMakeFiles/median2.dir/median2.c.o: ../median2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/median2.dir/median2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/median2.dir/median2.c.o   -c "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount/median2.c"

CMakeFiles/median2.dir/median2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/median2.dir/median2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount/median2.c" > CMakeFiles/median2.dir/median2.c.i

CMakeFiles/median2.dir/median2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/median2.dir/median2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount/median2.c" -o CMakeFiles/median2.dir/median2.c.s

# Object files for target median2
median2_OBJECTS = \
"CMakeFiles/median2.dir/median2.c.o"

# External object files for target median2
median2_EXTERNAL_OBJECTS =

median2.exe: CMakeFiles/median2.dir/median2.c.o
median2.exe: CMakeFiles/median2.dir/build.make
median2.exe: CMakeFiles/median2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable median2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/median2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/median2.dir/build: median2.exe

.PHONY : CMakeFiles/median2.dir/build

CMakeFiles/median2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/median2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/median2.dir/clean

CMakeFiles/median2.dir/depend:
	cd "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount/cmake-build-debug" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount/cmake-build-debug" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg05 median2 wordCount/cmake-build-debug/CMakeFiles/median2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/median2.dir/depend
