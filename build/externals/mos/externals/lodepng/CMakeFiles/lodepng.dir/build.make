# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = "/home/morgan/Projects/Dungeon on the fly"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/morgan/Projects/Dungeon on the fly/build"

# Include any dependencies generated for this target.
include externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/depend.make

# Include the progress variables for this target.
include externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/progress.make

# Include the compile flags for this target's objects.
include externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/flags.make

externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o: externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/flags.make
externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o: ../externals/mos/externals/lodepng/lodepng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/morgan/Projects/Dungeon on the fly/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o"
	cd "/home/morgan/Projects/Dungeon on the fly/build/externals/mos/externals/lodepng" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lodepng.dir/lodepng.cpp.o -c "/home/morgan/Projects/Dungeon on the fly/externals/mos/externals/lodepng/lodepng.cpp"

externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lodepng.dir/lodepng.cpp.i"
	cd "/home/morgan/Projects/Dungeon on the fly/build/externals/mos/externals/lodepng" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/morgan/Projects/Dungeon on the fly/externals/mos/externals/lodepng/lodepng.cpp" > CMakeFiles/lodepng.dir/lodepng.cpp.i

externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lodepng.dir/lodepng.cpp.s"
	cd "/home/morgan/Projects/Dungeon on the fly/build/externals/mos/externals/lodepng" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/morgan/Projects/Dungeon on the fly/externals/mos/externals/lodepng/lodepng.cpp" -o CMakeFiles/lodepng.dir/lodepng.cpp.s

externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o.requires:

.PHONY : externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o.requires

externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o.provides: externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o.requires
	$(MAKE) -f externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/build.make externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o.provides.build
.PHONY : externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o.provides

externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o.provides.build: externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o


# Object files for target lodepng
lodepng_OBJECTS = \
"CMakeFiles/lodepng.dir/lodepng.cpp.o"

# External object files for target lodepng
lodepng_EXTERNAL_OBJECTS =

externals/mos/externals/lodepng/liblodepng.a: externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o
externals/mos/externals/lodepng/liblodepng.a: externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/build.make
externals/mos/externals/lodepng/liblodepng.a: externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/morgan/Projects/Dungeon on the fly/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblodepng.a"
	cd "/home/morgan/Projects/Dungeon on the fly/build/externals/mos/externals/lodepng" && $(CMAKE_COMMAND) -P CMakeFiles/lodepng.dir/cmake_clean_target.cmake
	cd "/home/morgan/Projects/Dungeon on the fly/build/externals/mos/externals/lodepng" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lodepng.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/build: externals/mos/externals/lodepng/liblodepng.a

.PHONY : externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/build

externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/requires: externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/lodepng.cpp.o.requires

.PHONY : externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/requires

externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/clean:
	cd "/home/morgan/Projects/Dungeon on the fly/build/externals/mos/externals/lodepng" && $(CMAKE_COMMAND) -P CMakeFiles/lodepng.dir/cmake_clean.cmake
.PHONY : externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/clean

externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/depend:
	cd "/home/morgan/Projects/Dungeon on the fly/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/morgan/Projects/Dungeon on the fly" "/home/morgan/Projects/Dungeon on the fly/externals/mos/externals/lodepng" "/home/morgan/Projects/Dungeon on the fly/build" "/home/morgan/Projects/Dungeon on the fly/build/externals/mos/externals/lodepng" "/home/morgan/Projects/Dungeon on the fly/build/externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : externals/mos/externals/lodepng/CMakeFiles/lodepng.dir/depend

