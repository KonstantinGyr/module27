# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Kot\CLionProjects\hw27\company

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Kot\CLionProjects\hw27\company\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\company.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\company.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\company.dir\flags.make

CMakeFiles\company.dir\main.cpp.obj: CMakeFiles\company.dir\flags.make
CMakeFiles\company.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Kot\CLionProjects\hw27\company\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/company.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\company.dir\main.cpp.obj /FdCMakeFiles\company.dir\ /FS -c C:\Users\Kot\CLionProjects\hw27\company\main.cpp
<<

CMakeFiles\company.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/company.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\company.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Kot\CLionProjects\hw27\company\main.cpp
<<

CMakeFiles\company.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/company.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\company.dir\main.cpp.s /c C:\Users\Kot\CLionProjects\hw27\company\main.cpp
<<

# Object files for target company
company_OBJECTS = \
"CMakeFiles\company.dir\main.cpp.obj"

# External object files for target company
company_EXTERNAL_OBJECTS =

company.exe: CMakeFiles\company.dir\main.cpp.obj
company.exe: CMakeFiles\company.dir\build.make
company.exe: CMakeFiles\company.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Kot\CLionProjects\hw27\company\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable company.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\company.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\company.dir\objects1.rsp @<<
 /out:company.exe /implib:company.lib /pdb:C:\Users\Kot\CLionProjects\hw27\company\cmake-build-debug\company.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\company.dir\build: company.exe
.PHONY : CMakeFiles\company.dir\build

CMakeFiles\company.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\company.dir\cmake_clean.cmake
.PHONY : CMakeFiles\company.dir\clean

CMakeFiles\company.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Kot\CLionProjects\hw27\company C:\Users\Kot\CLionProjects\hw27\company C:\Users\Kot\CLionProjects\hw27\company\cmake-build-debug C:\Users\Kot\CLionProjects\hw27\company\cmake-build-debug C:\Users\Kot\CLionProjects\hw27\company\cmake-build-debug\CMakeFiles\company.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\company.dir\depend

