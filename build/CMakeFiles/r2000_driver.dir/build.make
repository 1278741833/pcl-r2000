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
CMAKE_SOURCE_DIR = /mnt/hgfs/share/pcl_proj/cloudPcl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/share/pcl_proj/cloudPcl/build

# Include any dependencies generated for this target.
include CMakeFiles/r2000_driver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/r2000_driver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/r2000_driver.dir/flags.make

CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o: CMakeFiles/r2000_driver.dir/flags.make
CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o: ../src/driver/r2000_driver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/share/pcl_proj/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o -c /mnt/hgfs/share/pcl_proj/cloudPcl/src/driver/r2000_driver.cpp

CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/share/pcl_proj/cloudPcl/src/driver/r2000_driver.cpp > CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.i

CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/share/pcl_proj/cloudPcl/src/driver/r2000_driver.cpp -o CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.s

CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o.requires:

.PHONY : CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o.requires

CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o.provides: CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o.requires
	$(MAKE) -f CMakeFiles/r2000_driver.dir/build.make CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o.provides.build
.PHONY : CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o.provides

CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o.provides.build: CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o


CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o: CMakeFiles/r2000_driver.dir/flags.make
CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o: ../src/driver/http_command_interface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/share/pcl_proj/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o -c /mnt/hgfs/share/pcl_proj/cloudPcl/src/driver/http_command_interface.cpp

CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/share/pcl_proj/cloudPcl/src/driver/http_command_interface.cpp > CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.i

CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/share/pcl_proj/cloudPcl/src/driver/http_command_interface.cpp -o CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.s

CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o.requires:

.PHONY : CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o.requires

CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o.provides: CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o.requires
	$(MAKE) -f CMakeFiles/r2000_driver.dir/build.make CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o.provides.build
.PHONY : CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o.provides

CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o.provides.build: CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o


CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o: CMakeFiles/r2000_driver.dir/flags.make
CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o: ../src/driver/scan_data_receiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/share/pcl_proj/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o -c /mnt/hgfs/share/pcl_proj/cloudPcl/src/driver/scan_data_receiver.cpp

CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/share/pcl_proj/cloudPcl/src/driver/scan_data_receiver.cpp > CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.i

CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/share/pcl_proj/cloudPcl/src/driver/scan_data_receiver.cpp -o CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.s

CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o.requires:

.PHONY : CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o.requires

CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o.provides: CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o.requires
	$(MAKE) -f CMakeFiles/r2000_driver.dir/build.make CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o.provides.build
.PHONY : CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o.provides

CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o.provides.build: CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o


# Object files for target r2000_driver
r2000_driver_OBJECTS = \
"CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o" \
"CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o" \
"CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o"

# External object files for target r2000_driver
r2000_driver_EXTERNAL_OBJECTS =

lib/libr2000_driver.a: CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o
lib/libr2000_driver.a: CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o
lib/libr2000_driver.a: CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o
lib/libr2000_driver.a: CMakeFiles/r2000_driver.dir/build.make
lib/libr2000_driver.a: CMakeFiles/r2000_driver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/share/pcl_proj/cloudPcl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library lib/libr2000_driver.a"
	$(CMAKE_COMMAND) -P CMakeFiles/r2000_driver.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/r2000_driver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/r2000_driver.dir/build: lib/libr2000_driver.a

.PHONY : CMakeFiles/r2000_driver.dir/build

CMakeFiles/r2000_driver.dir/requires: CMakeFiles/r2000_driver.dir/src/driver/r2000_driver.cpp.o.requires
CMakeFiles/r2000_driver.dir/requires: CMakeFiles/r2000_driver.dir/src/driver/http_command_interface.cpp.o.requires
CMakeFiles/r2000_driver.dir/requires: CMakeFiles/r2000_driver.dir/src/driver/scan_data_receiver.cpp.o.requires

.PHONY : CMakeFiles/r2000_driver.dir/requires

CMakeFiles/r2000_driver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/r2000_driver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/r2000_driver.dir/clean

CMakeFiles/r2000_driver.dir/depend:
	cd /mnt/hgfs/share/pcl_proj/cloudPcl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/share/pcl_proj/cloudPcl /mnt/hgfs/share/pcl_proj/cloudPcl /mnt/hgfs/share/pcl_proj/cloudPcl/build /mnt/hgfs/share/pcl_proj/cloudPcl/build /mnt/hgfs/share/pcl_proj/cloudPcl/build/CMakeFiles/r2000_driver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/r2000_driver.dir/depend
