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
include CMakeFiles/Assg04_sumLine_median_shuffle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assg04_sumLine_median_shuffle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assg04_sumLine_median_shuffle.dir/flags.make

CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.o: CMakeFiles/Assg04_sumLine_median_shuffle.dir/flags.make
CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.o   -c "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/main.c"

CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/main.c" > CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.i

CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/main.c" -o CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.s

# Object files for target Assg04_sumLine_median_shuffle
Assg04_sumLine_median_shuffle_OBJECTS = \
"CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.o"

# External object files for target Assg04_sumLine_median_shuffle
Assg04_sumLine_median_shuffle_EXTERNAL_OBJECTS =

Assg04_sumLine_median_shuffle.exe: CMakeFiles/Assg04_sumLine_median_shuffle.dir/main.c.o
Assg04_sumLine_median_shuffle.exe: CMakeFiles/Assg04_sumLine_median_shuffle.dir/build.make
Assg04_sumLine_median_shuffle.exe: CMakeFiles/Assg04_sumLine_median_shuffle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Assg04_sumLine_median_shuffle.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assg04_sumLine_median_shuffle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assg04_sumLine_median_shuffle.dir/build: Assg04_sumLine_median_shuffle.exe

.PHONY : CMakeFiles/Assg04_sumLine_median_shuffle.dir/build

CMakeFiles/Assg04_sumLine_median_shuffle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assg04_sumLine_median_shuffle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assg04_sumLine_median_shuffle.dir/clean

CMakeFiles/Assg04_sumLine_median_shuffle.dir/depend:
	cd "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug" "/cygdrive/c/Users/aswin/Google Drive/Coding/C/CSC 352 C/Assg04 sumLine median shuffle/cmake-build-debug/CMakeFiles/Assg04_sumLine_median_shuffle.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Assg04_sumLine_median_shuffle.dir/depend

