# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy/build-release

# Include any dependencies generated for this target.
include CMakeFiles/intersections.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/intersections.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/intersections.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/intersections.dir/flags.make

CMakeFiles/intersections.dir/intersections.cpp.o: CMakeFiles/intersections.dir/flags.make
CMakeFiles/intersections.dir/intersections.cpp.o: /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy/intersections.cpp
CMakeFiles/intersections.dir/intersections.cpp.o: CMakeFiles/intersections.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/intersections.dir/intersections.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/intersections.dir/intersections.cpp.o -MF CMakeFiles/intersections.dir/intersections.cpp.o.d -o CMakeFiles/intersections.dir/intersections.cpp.o -c /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy/intersections.cpp

CMakeFiles/intersections.dir/intersections.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/intersections.dir/intersections.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy/intersections.cpp > CMakeFiles/intersections.dir/intersections.cpp.i

CMakeFiles/intersections.dir/intersections.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/intersections.dir/intersections.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy/intersections.cpp -o CMakeFiles/intersections.dir/intersections.cpp.s

# Object files for target intersections
intersections_OBJECTS = \
"CMakeFiles/intersections.dir/intersections.cpp.o"

# External object files for target intersections
intersections_EXTERNAL_OBJECTS =

intersections: CMakeFiles/intersections.dir/intersections.cpp.o
intersections: CMakeFiles/intersections.dir/build.make
intersections: libcore.a
intersections: /Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/System/Library/Frameworks/OpenGL.framework
intersections: glad/libglad.a
intersections: glfw/src/libglfw3.a
intersections: CMakeFiles/intersections.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable intersections"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/intersections.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/intersections.dir/build: intersections
.PHONY : CMakeFiles/intersections.dir/build

CMakeFiles/intersections.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/intersections.dir/cmake_clean.cmake
.PHONY : CMakeFiles/intersections.dir/clean

CMakeFiles/intersections.dir/depend:
	cd /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy/build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy/build-release /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy/build-release /Users/yuchunfeng/Documents/CSC317/A4/computer-graphics-bounding-volume-hierarchy/build-release/CMakeFiles/intersections.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/intersections.dir/depend
