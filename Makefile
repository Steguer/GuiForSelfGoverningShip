# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/steven/Documents/programming/SelfGoverningShipDev/Gui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/steven/Documents/programming/SelfGoverningShipDev/Gui

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/steven/Documents/programming/SelfGoverningShipDev/Gui/CMakeFiles /home/steven/Documents/programming/SelfGoverningShipDev/Gui/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/steven/Documents/programming/SelfGoverningShipDev/Gui/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named gui

# Build rule for target.
gui: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gui
.PHONY : gui

# fast build rule for target.
gui/fast:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/build
.PHONY : gui/fast

#=============================================================================
# Target rules for targets named gui_automoc

# Build rule for target.
gui_automoc: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gui_automoc
.PHONY : gui_automoc

# fast build rule for target.
gui_automoc/fast:
	$(MAKE) -f CMakeFiles/gui_automoc.dir/build.make CMakeFiles/gui_automoc.dir/build
.PHONY : gui_automoc/fast

gui_automoc.o: gui_automoc.cpp.o
.PHONY : gui_automoc.o

# target to build an object file
gui_automoc.cpp.o:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/gui_automoc.cpp.o
.PHONY : gui_automoc.cpp.o

gui_automoc.i: gui_automoc.cpp.i
.PHONY : gui_automoc.i

# target to preprocess a source file
gui_automoc.cpp.i:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/gui_automoc.cpp.i
.PHONY : gui_automoc.cpp.i

gui_automoc.s: gui_automoc.cpp.s
.PHONY : gui_automoc.s

# target to generate assembly for a file
gui_automoc.cpp.s:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/gui_automoc.cpp.s
.PHONY : gui_automoc.cpp.s

src/HandlerConfLeaf.o: src/HandlerConfLeaf.cpp.o
.PHONY : src/HandlerConfLeaf.o

# target to build an object file
src/HandlerConfLeaf.cpp.o:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/HandlerConfLeaf.cpp.o
.PHONY : src/HandlerConfLeaf.cpp.o

src/HandlerConfLeaf.i: src/HandlerConfLeaf.cpp.i
.PHONY : src/HandlerConfLeaf.i

# target to preprocess a source file
src/HandlerConfLeaf.cpp.i:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/HandlerConfLeaf.cpp.i
.PHONY : src/HandlerConfLeaf.cpp.i

src/HandlerConfLeaf.s: src/HandlerConfLeaf.cpp.s
.PHONY : src/HandlerConfLeaf.s

# target to generate assembly for a file
src/HandlerConfLeaf.cpp.s:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/HandlerConfLeaf.cpp.s
.PHONY : src/HandlerConfLeaf.cpp.s

src/Parsser.o: src/Parsser.cpp.o
.PHONY : src/Parsser.o

# target to build an object file
src/Parsser.cpp.o:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/Parsser.cpp.o
.PHONY : src/Parsser.cpp.o

src/Parsser.i: src/Parsser.cpp.i
.PHONY : src/Parsser.i

# target to preprocess a source file
src/Parsser.cpp.i:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/Parsser.cpp.i
.PHONY : src/Parsser.cpp.i

src/Parsser.s: src/Parsser.cpp.s
.PHONY : src/Parsser.s

# target to generate assembly for a file
src/Parsser.cpp.s:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/Parsser.cpp.s
.PHONY : src/Parsser.cpp.s

src/PathConfigLeaf.o: src/PathConfigLeaf.cpp.o
.PHONY : src/PathConfigLeaf.o

# target to build an object file
src/PathConfigLeaf.cpp.o:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/PathConfigLeaf.cpp.o
.PHONY : src/PathConfigLeaf.cpp.o

src/PathConfigLeaf.i: src/PathConfigLeaf.cpp.i
.PHONY : src/PathConfigLeaf.i

# target to preprocess a source file
src/PathConfigLeaf.cpp.i:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/PathConfigLeaf.cpp.i
.PHONY : src/PathConfigLeaf.cpp.i

src/PathConfigLeaf.s: src/PathConfigLeaf.cpp.s
.PHONY : src/PathConfigLeaf.s

# target to generate assembly for a file
src/PathConfigLeaf.cpp.s:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/PathConfigLeaf.cpp.s
.PHONY : src/PathConfigLeaf.cpp.s

src/PyScriptConfigurationWindow.o: src/PyScriptConfigurationWindow.cpp.o
.PHONY : src/PyScriptConfigurationWindow.o

# target to build an object file
src/PyScriptConfigurationWindow.cpp.o:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/PyScriptConfigurationWindow.cpp.o
.PHONY : src/PyScriptConfigurationWindow.cpp.o

src/PyScriptConfigurationWindow.i: src/PyScriptConfigurationWindow.cpp.i
.PHONY : src/PyScriptConfigurationWindow.i

# target to preprocess a source file
src/PyScriptConfigurationWindow.cpp.i:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/PyScriptConfigurationWindow.cpp.i
.PHONY : src/PyScriptConfigurationWindow.cpp.i

src/PyScriptConfigurationWindow.s: src/PyScriptConfigurationWindow.cpp.s
.PHONY : src/PyScriptConfigurationWindow.s

# target to generate assembly for a file
src/PyScriptConfigurationWindow.cpp.s:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/PyScriptConfigurationWindow.cpp.s
.PHONY : src/PyScriptConfigurationWindow.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... gui"
	@echo "... gui_automoc"
	@echo "... rebuild_cache"
	@echo "... gui_automoc.o"
	@echo "... gui_automoc.i"
	@echo "... gui_automoc.s"
	@echo "... src/HandlerConfLeaf.o"
	@echo "... src/HandlerConfLeaf.i"
	@echo "... src/HandlerConfLeaf.s"
	@echo "... src/Parsser.o"
	@echo "... src/Parsser.i"
	@echo "... src/Parsser.s"
	@echo "... src/PathConfigLeaf.o"
	@echo "... src/PathConfigLeaf.i"
	@echo "... src/PathConfigLeaf.s"
	@echo "... src/PyScriptConfigurationWindow.o"
	@echo "... src/PyScriptConfigurationWindow.i"
	@echo "... src/PyScriptConfigurationWindow.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

