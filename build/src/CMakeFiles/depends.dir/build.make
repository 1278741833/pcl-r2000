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
CMAKE_SOURCE_DIR = /home/zxy/zxy/cloudPcl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zxy/zxy/cloudPcl/build

# Include any dependencies generated for this target.
include src/CMakeFiles/depends.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/depends.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/depends.dir/flags.make

src/CMakeFiles/depends.dir/_freecplus.cpp.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/_freecplus.cpp.o: ../src/_freecplus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/depends.dir/_freecplus.cpp.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depends.dir/_freecplus.cpp.o -c /home/zxy/zxy/cloudPcl/src/_freecplus.cpp

src/CMakeFiles/depends.dir/_freecplus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depends.dir/_freecplus.cpp.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxy/zxy/cloudPcl/src/_freecplus.cpp > CMakeFiles/depends.dir/_freecplus.cpp.i

src/CMakeFiles/depends.dir/_freecplus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depends.dir/_freecplus.cpp.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxy/zxy/cloudPcl/src/_freecplus.cpp -o CMakeFiles/depends.dir/_freecplus.cpp.s

src/CMakeFiles/depends.dir/_freecplus.cpp.o.requires:

.PHONY : src/CMakeFiles/depends.dir/_freecplus.cpp.o.requires

src/CMakeFiles/depends.dir/_freecplus.cpp.o.provides: src/CMakeFiles/depends.dir/_freecplus.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/_freecplus.cpp.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/_freecplus.cpp.o.provides

src/CMakeFiles/depends.dir/_freecplus.cpp.o.provides.build: src/CMakeFiles/depends.dir/_freecplus.cpp.o


src/CMakeFiles/depends.dir/crc32.cpp.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/crc32.cpp.o: ../src/crc32.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/depends.dir/crc32.cpp.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depends.dir/crc32.cpp.o -c /home/zxy/zxy/cloudPcl/src/crc32.cpp

src/CMakeFiles/depends.dir/crc32.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depends.dir/crc32.cpp.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxy/zxy/cloudPcl/src/crc32.cpp > CMakeFiles/depends.dir/crc32.cpp.i

src/CMakeFiles/depends.dir/crc32.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depends.dir/crc32.cpp.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxy/zxy/cloudPcl/src/crc32.cpp -o CMakeFiles/depends.dir/crc32.cpp.s

src/CMakeFiles/depends.dir/crc32.cpp.o.requires:

.PHONY : src/CMakeFiles/depends.dir/crc32.cpp.o.requires

src/CMakeFiles/depends.dir/crc32.cpp.o.provides: src/CMakeFiles/depends.dir/crc32.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/crc32.cpp.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/crc32.cpp.o.provides

src/CMakeFiles/depends.dir/crc32.cpp.o.provides.build: src/CMakeFiles/depends.dir/crc32.cpp.o


src/CMakeFiles/depends.dir/net.cpp.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/net.cpp.o: ../src/net.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/depends.dir/net.cpp.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depends.dir/net.cpp.o -c /home/zxy/zxy/cloudPcl/src/net.cpp

src/CMakeFiles/depends.dir/net.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depends.dir/net.cpp.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxy/zxy/cloudPcl/src/net.cpp > CMakeFiles/depends.dir/net.cpp.i

src/CMakeFiles/depends.dir/net.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depends.dir/net.cpp.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxy/zxy/cloudPcl/src/net.cpp -o CMakeFiles/depends.dir/net.cpp.s

src/CMakeFiles/depends.dir/net.cpp.o.requires:

.PHONY : src/CMakeFiles/depends.dir/net.cpp.o.requires

src/CMakeFiles/depends.dir/net.cpp.o.provides: src/CMakeFiles/depends.dir/net.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/net.cpp.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/net.cpp.o.provides

src/CMakeFiles/depends.dir/net.cpp.o.provides.build: src/CMakeFiles/depends.dir/net.cpp.o


src/CMakeFiles/depends.dir/r2000.cpp.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/r2000.cpp.o: ../src/r2000.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/depends.dir/r2000.cpp.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depends.dir/r2000.cpp.o -c /home/zxy/zxy/cloudPcl/src/r2000.cpp

src/CMakeFiles/depends.dir/r2000.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depends.dir/r2000.cpp.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxy/zxy/cloudPcl/src/r2000.cpp > CMakeFiles/depends.dir/r2000.cpp.i

src/CMakeFiles/depends.dir/r2000.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depends.dir/r2000.cpp.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxy/zxy/cloudPcl/src/r2000.cpp -o CMakeFiles/depends.dir/r2000.cpp.s

src/CMakeFiles/depends.dir/r2000.cpp.o.requires:

.PHONY : src/CMakeFiles/depends.dir/r2000.cpp.o.requires

src/CMakeFiles/depends.dir/r2000.cpp.o.provides: src/CMakeFiles/depends.dir/r2000.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/r2000.cpp.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/r2000.cpp.o.provides

src/CMakeFiles/depends.dir/r2000.cpp.o.provides.build: src/CMakeFiles/depends.dir/r2000.cpp.o


src/CMakeFiles/depends.dir/util.cpp.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/util.cpp.o: ../src/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/depends.dir/util.cpp.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depends.dir/util.cpp.o -c /home/zxy/zxy/cloudPcl/src/util.cpp

src/CMakeFiles/depends.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depends.dir/util.cpp.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxy/zxy/cloudPcl/src/util.cpp > CMakeFiles/depends.dir/util.cpp.i

src/CMakeFiles/depends.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depends.dir/util.cpp.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxy/zxy/cloudPcl/src/util.cpp -o CMakeFiles/depends.dir/util.cpp.s

src/CMakeFiles/depends.dir/util.cpp.o.requires:

.PHONY : src/CMakeFiles/depends.dir/util.cpp.o.requires

src/CMakeFiles/depends.dir/util.cpp.o.provides: src/CMakeFiles/depends.dir/util.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/util.cpp.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/util.cpp.o.provides

src/CMakeFiles/depends.dir/util.cpp.o.provides.build: src/CMakeFiles/depends.dir/util.cpp.o


src/CMakeFiles/depends.dir/ini.c.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/ini.c.o: ../src/ini.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/depends.dir/ini.c.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/depends.dir/ini.c.o   -c /home/zxy/zxy/cloudPcl/src/ini.c

src/CMakeFiles/depends.dir/ini.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/depends.dir/ini.c.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zxy/zxy/cloudPcl/src/ini.c > CMakeFiles/depends.dir/ini.c.i

src/CMakeFiles/depends.dir/ini.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/depends.dir/ini.c.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zxy/zxy/cloudPcl/src/ini.c -o CMakeFiles/depends.dir/ini.c.s

src/CMakeFiles/depends.dir/ini.c.o.requires:

.PHONY : src/CMakeFiles/depends.dir/ini.c.o.requires

src/CMakeFiles/depends.dir/ini.c.o.provides: src/CMakeFiles/depends.dir/ini.c.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/ini.c.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/ini.c.o.provides

src/CMakeFiles/depends.dir/ini.c.o.provides.build: src/CMakeFiles/depends.dir/ini.c.o


src/CMakeFiles/depends.dir/INIReader.cpp.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/INIReader.cpp.o: ../src/INIReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/depends.dir/INIReader.cpp.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depends.dir/INIReader.cpp.o -c /home/zxy/zxy/cloudPcl/src/INIReader.cpp

src/CMakeFiles/depends.dir/INIReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depends.dir/INIReader.cpp.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxy/zxy/cloudPcl/src/INIReader.cpp > CMakeFiles/depends.dir/INIReader.cpp.i

src/CMakeFiles/depends.dir/INIReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depends.dir/INIReader.cpp.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxy/zxy/cloudPcl/src/INIReader.cpp -o CMakeFiles/depends.dir/INIReader.cpp.s

src/CMakeFiles/depends.dir/INIReader.cpp.o.requires:

.PHONY : src/CMakeFiles/depends.dir/INIReader.cpp.o.requires

src/CMakeFiles/depends.dir/INIReader.cpp.o.provides: src/CMakeFiles/depends.dir/INIReader.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/INIReader.cpp.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/INIReader.cpp.o.provides

src/CMakeFiles/depends.dir/INIReader.cpp.o.provides.build: src/CMakeFiles/depends.dir/INIReader.cpp.o


src/CMakeFiles/depends.dir/dfilter.cpp.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/dfilter.cpp.o: ../src/dfilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/depends.dir/dfilter.cpp.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depends.dir/dfilter.cpp.o -c /home/zxy/zxy/cloudPcl/src/dfilter.cpp

src/CMakeFiles/depends.dir/dfilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depends.dir/dfilter.cpp.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxy/zxy/cloudPcl/src/dfilter.cpp > CMakeFiles/depends.dir/dfilter.cpp.i

src/CMakeFiles/depends.dir/dfilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depends.dir/dfilter.cpp.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxy/zxy/cloudPcl/src/dfilter.cpp -o CMakeFiles/depends.dir/dfilter.cpp.s

src/CMakeFiles/depends.dir/dfilter.cpp.o.requires:

.PHONY : src/CMakeFiles/depends.dir/dfilter.cpp.o.requires

src/CMakeFiles/depends.dir/dfilter.cpp.o.provides: src/CMakeFiles/depends.dir/dfilter.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/dfilter.cpp.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/dfilter.cpp.o.provides

src/CMakeFiles/depends.dir/dfilter.cpp.o.provides.build: src/CMakeFiles/depends.dir/dfilter.cpp.o


src/CMakeFiles/depends.dir/icp.cpp.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/icp.cpp.o: ../src/icp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/depends.dir/icp.cpp.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depends.dir/icp.cpp.o -c /home/zxy/zxy/cloudPcl/src/icp.cpp

src/CMakeFiles/depends.dir/icp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depends.dir/icp.cpp.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxy/zxy/cloudPcl/src/icp.cpp > CMakeFiles/depends.dir/icp.cpp.i

src/CMakeFiles/depends.dir/icp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depends.dir/icp.cpp.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxy/zxy/cloudPcl/src/icp.cpp -o CMakeFiles/depends.dir/icp.cpp.s

src/CMakeFiles/depends.dir/icp.cpp.o.requires:

.PHONY : src/CMakeFiles/depends.dir/icp.cpp.o.requires

src/CMakeFiles/depends.dir/icp.cpp.o.provides: src/CMakeFiles/depends.dir/icp.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/icp.cpp.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/icp.cpp.o.provides

src/CMakeFiles/depends.dir/icp.cpp.o.provides.build: src/CMakeFiles/depends.dir/icp.cpp.o


src/CMakeFiles/depends.dir/commander.cpp.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/commander.cpp.o: ../src/commander.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/depends.dir/commander.cpp.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depends.dir/commander.cpp.o -c /home/zxy/zxy/cloudPcl/src/commander.cpp

src/CMakeFiles/depends.dir/commander.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depends.dir/commander.cpp.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxy/zxy/cloudPcl/src/commander.cpp > CMakeFiles/depends.dir/commander.cpp.i

src/CMakeFiles/depends.dir/commander.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depends.dir/commander.cpp.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxy/zxy/cloudPcl/src/commander.cpp -o CMakeFiles/depends.dir/commander.cpp.s

src/CMakeFiles/depends.dir/commander.cpp.o.requires:

.PHONY : src/CMakeFiles/depends.dir/commander.cpp.o.requires

src/CMakeFiles/depends.dir/commander.cpp.o.provides: src/CMakeFiles/depends.dir/commander.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/commander.cpp.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/commander.cpp.o.provides

src/CMakeFiles/depends.dir/commander.cpp.o.provides.build: src/CMakeFiles/depends.dir/commander.cpp.o


src/CMakeFiles/depends.dir/terminal_cmd.cpp.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/terminal_cmd.cpp.o: ../src/terminal_cmd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/depends.dir/terminal_cmd.cpp.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depends.dir/terminal_cmd.cpp.o -c /home/zxy/zxy/cloudPcl/src/terminal_cmd.cpp

src/CMakeFiles/depends.dir/terminal_cmd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depends.dir/terminal_cmd.cpp.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxy/zxy/cloudPcl/src/terminal_cmd.cpp > CMakeFiles/depends.dir/terminal_cmd.cpp.i

src/CMakeFiles/depends.dir/terminal_cmd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depends.dir/terminal_cmd.cpp.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxy/zxy/cloudPcl/src/terminal_cmd.cpp -o CMakeFiles/depends.dir/terminal_cmd.cpp.s

src/CMakeFiles/depends.dir/terminal_cmd.cpp.o.requires:

.PHONY : src/CMakeFiles/depends.dir/terminal_cmd.cpp.o.requires

src/CMakeFiles/depends.dir/terminal_cmd.cpp.o.provides: src/CMakeFiles/depends.dir/terminal_cmd.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/terminal_cmd.cpp.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/terminal_cmd.cpp.o.provides

src/CMakeFiles/depends.dir/terminal_cmd.cpp.o.provides.build: src/CMakeFiles/depends.dir/terminal_cmd.cpp.o


src/CMakeFiles/depends.dir/network.cpp.o: src/CMakeFiles/depends.dir/flags.make
src/CMakeFiles/depends.dir/network.cpp.o: ../src/network.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/depends.dir/network.cpp.o"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/depends.dir/network.cpp.o -c /home/zxy/zxy/cloudPcl/src/network.cpp

src/CMakeFiles/depends.dir/network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/depends.dir/network.cpp.i"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zxy/zxy/cloudPcl/src/network.cpp > CMakeFiles/depends.dir/network.cpp.i

src/CMakeFiles/depends.dir/network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/depends.dir/network.cpp.s"
	cd /home/zxy/zxy/cloudPcl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zxy/zxy/cloudPcl/src/network.cpp -o CMakeFiles/depends.dir/network.cpp.s

src/CMakeFiles/depends.dir/network.cpp.o.requires:

.PHONY : src/CMakeFiles/depends.dir/network.cpp.o.requires

src/CMakeFiles/depends.dir/network.cpp.o.provides: src/CMakeFiles/depends.dir/network.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/depends.dir/build.make src/CMakeFiles/depends.dir/network.cpp.o.provides.build
.PHONY : src/CMakeFiles/depends.dir/network.cpp.o.provides

src/CMakeFiles/depends.dir/network.cpp.o.provides.build: src/CMakeFiles/depends.dir/network.cpp.o


# Object files for target depends
depends_OBJECTS = \
"CMakeFiles/depends.dir/_freecplus.cpp.o" \
"CMakeFiles/depends.dir/crc32.cpp.o" \
"CMakeFiles/depends.dir/net.cpp.o" \
"CMakeFiles/depends.dir/r2000.cpp.o" \
"CMakeFiles/depends.dir/util.cpp.o" \
"CMakeFiles/depends.dir/ini.c.o" \
"CMakeFiles/depends.dir/INIReader.cpp.o" \
"CMakeFiles/depends.dir/dfilter.cpp.o" \
"CMakeFiles/depends.dir/icp.cpp.o" \
"CMakeFiles/depends.dir/commander.cpp.o" \
"CMakeFiles/depends.dir/terminal_cmd.cpp.o" \
"CMakeFiles/depends.dir/network.cpp.o"

# External object files for target depends
depends_EXTERNAL_OBJECTS =

lib/libdepends.a: src/CMakeFiles/depends.dir/_freecplus.cpp.o
lib/libdepends.a: src/CMakeFiles/depends.dir/crc32.cpp.o
lib/libdepends.a: src/CMakeFiles/depends.dir/net.cpp.o
lib/libdepends.a: src/CMakeFiles/depends.dir/r2000.cpp.o
lib/libdepends.a: src/CMakeFiles/depends.dir/util.cpp.o
lib/libdepends.a: src/CMakeFiles/depends.dir/ini.c.o
lib/libdepends.a: src/CMakeFiles/depends.dir/INIReader.cpp.o
lib/libdepends.a: src/CMakeFiles/depends.dir/dfilter.cpp.o
lib/libdepends.a: src/CMakeFiles/depends.dir/icp.cpp.o
lib/libdepends.a: src/CMakeFiles/depends.dir/commander.cpp.o
lib/libdepends.a: src/CMakeFiles/depends.dir/terminal_cmd.cpp.o
lib/libdepends.a: src/CMakeFiles/depends.dir/network.cpp.o
lib/libdepends.a: src/CMakeFiles/depends.dir/build.make
lib/libdepends.a: src/CMakeFiles/depends.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zxy/zxy/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX static library ../lib/libdepends.a"
	cd /home/zxy/zxy/cloudPcl/build/src && $(CMAKE_COMMAND) -P CMakeFiles/depends.dir/cmake_clean_target.cmake
	cd /home/zxy/zxy/cloudPcl/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/depends.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/depends.dir/build: lib/libdepends.a

.PHONY : src/CMakeFiles/depends.dir/build

src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/_freecplus.cpp.o.requires
src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/crc32.cpp.o.requires
src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/net.cpp.o.requires
src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/r2000.cpp.o.requires
src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/util.cpp.o.requires
src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/ini.c.o.requires
src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/INIReader.cpp.o.requires
src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/dfilter.cpp.o.requires
src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/icp.cpp.o.requires
src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/commander.cpp.o.requires
src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/terminal_cmd.cpp.o.requires
src/CMakeFiles/depends.dir/requires: src/CMakeFiles/depends.dir/network.cpp.o.requires

.PHONY : src/CMakeFiles/depends.dir/requires

src/CMakeFiles/depends.dir/clean:
	cd /home/zxy/zxy/cloudPcl/build/src && $(CMAKE_COMMAND) -P CMakeFiles/depends.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/depends.dir/clean

src/CMakeFiles/depends.dir/depend:
	cd /home/zxy/zxy/cloudPcl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zxy/zxy/cloudPcl /home/zxy/zxy/cloudPcl/src /home/zxy/zxy/cloudPcl/build /home/zxy/zxy/cloudPcl/build/src /home/zxy/zxy/cloudPcl/build/src/CMakeFiles/depends.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/depends.dir/depend

