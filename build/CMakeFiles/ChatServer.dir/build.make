# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maria-fintineanu/MultithreadedWebServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maria-fintineanu/MultithreadedWebServer/build

# Include any dependencies generated for this target.
include CMakeFiles/ChatServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ChatServer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ChatServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ChatServer.dir/flags.make

CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.o: CMakeFiles/ChatServer.dir/flags.make
CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.o: /home/maria-fintineanu/MultithreadedWebServer/src/ClientHandler.cpp
CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.o: CMakeFiles/ChatServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maria-fintineanu/MultithreadedWebServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.o -MF CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.o.d -o CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.o -c /home/maria-fintineanu/MultithreadedWebServer/src/ClientHandler.cpp

CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maria-fintineanu/MultithreadedWebServer/src/ClientHandler.cpp > CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.i

CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maria-fintineanu/MultithreadedWebServer/src/ClientHandler.cpp -o CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.s

CMakeFiles/ChatServer.dir/src/Server.cpp.o: CMakeFiles/ChatServer.dir/flags.make
CMakeFiles/ChatServer.dir/src/Server.cpp.o: /home/maria-fintineanu/MultithreadedWebServer/src/Server.cpp
CMakeFiles/ChatServer.dir/src/Server.cpp.o: CMakeFiles/ChatServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maria-fintineanu/MultithreadedWebServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ChatServer.dir/src/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChatServer.dir/src/Server.cpp.o -MF CMakeFiles/ChatServer.dir/src/Server.cpp.o.d -o CMakeFiles/ChatServer.dir/src/Server.cpp.o -c /home/maria-fintineanu/MultithreadedWebServer/src/Server.cpp

CMakeFiles/ChatServer.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatServer.dir/src/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maria-fintineanu/MultithreadedWebServer/src/Server.cpp > CMakeFiles/ChatServer.dir/src/Server.cpp.i

CMakeFiles/ChatServer.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatServer.dir/src/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maria-fintineanu/MultithreadedWebServer/src/Server.cpp -o CMakeFiles/ChatServer.dir/src/Server.cpp.s

CMakeFiles/ChatServer.dir/src/ServerMain.cpp.o: CMakeFiles/ChatServer.dir/flags.make
CMakeFiles/ChatServer.dir/src/ServerMain.cpp.o: /home/maria-fintineanu/MultithreadedWebServer/src/ServerMain.cpp
CMakeFiles/ChatServer.dir/src/ServerMain.cpp.o: CMakeFiles/ChatServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maria-fintineanu/MultithreadedWebServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ChatServer.dir/src/ServerMain.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChatServer.dir/src/ServerMain.cpp.o -MF CMakeFiles/ChatServer.dir/src/ServerMain.cpp.o.d -o CMakeFiles/ChatServer.dir/src/ServerMain.cpp.o -c /home/maria-fintineanu/MultithreadedWebServer/src/ServerMain.cpp

CMakeFiles/ChatServer.dir/src/ServerMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChatServer.dir/src/ServerMain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maria-fintineanu/MultithreadedWebServer/src/ServerMain.cpp > CMakeFiles/ChatServer.dir/src/ServerMain.cpp.i

CMakeFiles/ChatServer.dir/src/ServerMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChatServer.dir/src/ServerMain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maria-fintineanu/MultithreadedWebServer/src/ServerMain.cpp -o CMakeFiles/ChatServer.dir/src/ServerMain.cpp.s

# Object files for target ChatServer
ChatServer_OBJECTS = \
"CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.o" \
"CMakeFiles/ChatServer.dir/src/Server.cpp.o" \
"CMakeFiles/ChatServer.dir/src/ServerMain.cpp.o"

# External object files for target ChatServer
ChatServer_EXTERNAL_OBJECTS =

ChatServer: CMakeFiles/ChatServer.dir/src/ClientHandler.cpp.o
ChatServer: CMakeFiles/ChatServer.dir/src/Server.cpp.o
ChatServer: CMakeFiles/ChatServer.dir/src/ServerMain.cpp.o
ChatServer: CMakeFiles/ChatServer.dir/build.make
ChatServer: CMakeFiles/ChatServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maria-fintineanu/MultithreadedWebServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ChatServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChatServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ChatServer.dir/build: ChatServer
.PHONY : CMakeFiles/ChatServer.dir/build

CMakeFiles/ChatServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ChatServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ChatServer.dir/clean

CMakeFiles/ChatServer.dir/depend:
	cd /home/maria-fintineanu/MultithreadedWebServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maria-fintineanu/MultithreadedWebServer /home/maria-fintineanu/MultithreadedWebServer /home/maria-fintineanu/MultithreadedWebServer/build /home/maria-fintineanu/MultithreadedWebServer/build /home/maria-fintineanu/MultithreadedWebServer/build/CMakeFiles/ChatServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ChatServer.dir/depend

