# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\FirstSemFinalProject.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\FirstSemFinalProject.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\FirstSemFinalProject.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\FirstSemFinalProject.dir\flags.make

CMakeFiles\FirstSemFinalProject.dir\main.cpp.obj: CMakeFiles\FirstSemFinalProject.dir\flags.make
CMakeFiles\FirstSemFinalProject.dir\main.cpp.obj: ..\main.cpp
CMakeFiles\FirstSemFinalProject.dir\main.cpp.obj: CMakeFiles\FirstSemFinalProject.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FirstSemFinalProject.dir/main.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\FirstSemFinalProject.dir\main.cpp.obj.d --working-dir="C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Visual Studio\VC\Tools\MSVC\14.30.30705\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\FirstSemFinalProject.dir\main.cpp.obj /FdCMakeFiles\FirstSemFinalProject.dir\ /FS -c "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\main.cpp"
<<

CMakeFiles\FirstSemFinalProject.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstSemFinalProject.dir/main.cpp.i"
	"D:\Visual Studio\VC\Tools\MSVC\14.30.30705\bin\Hostx86\x86\cl.exe" > CMakeFiles\FirstSemFinalProject.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\main.cpp"
<<

CMakeFiles\FirstSemFinalProject.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstSemFinalProject.dir/main.cpp.s"
	"D:\Visual Studio\VC\Tools\MSVC\14.30.30705\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\FirstSemFinalProject.dir\main.cpp.s /c "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\main.cpp"
<<

CMakeFiles\FirstSemFinalProject.dir\StockManagement.cpp.obj: CMakeFiles\FirstSemFinalProject.dir\flags.make
CMakeFiles\FirstSemFinalProject.dir\StockManagement.cpp.obj: ..\StockManagement.cpp
CMakeFiles\FirstSemFinalProject.dir\StockManagement.cpp.obj: CMakeFiles\FirstSemFinalProject.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FirstSemFinalProject.dir/StockManagement.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\FirstSemFinalProject.dir\StockManagement.cpp.obj.d --working-dir="C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Visual Studio\VC\Tools\MSVC\14.30.30705\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\FirstSemFinalProject.dir\StockManagement.cpp.obj /FdCMakeFiles\FirstSemFinalProject.dir\ /FS -c "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\StockManagement.cpp"
<<

CMakeFiles\FirstSemFinalProject.dir\StockManagement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstSemFinalProject.dir/StockManagement.cpp.i"
	"D:\Visual Studio\VC\Tools\MSVC\14.30.30705\bin\Hostx86\x86\cl.exe" > CMakeFiles\FirstSemFinalProject.dir\StockManagement.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\StockManagement.cpp"
<<

CMakeFiles\FirstSemFinalProject.dir\StockManagement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstSemFinalProject.dir/StockManagement.cpp.s"
	"D:\Visual Studio\VC\Tools\MSVC\14.30.30705\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\FirstSemFinalProject.dir\StockManagement.cpp.s /c "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\StockManagement.cpp"
<<

CMakeFiles\FirstSemFinalProject.dir\UserInterface.cpp.obj: CMakeFiles\FirstSemFinalProject.dir\flags.make
CMakeFiles\FirstSemFinalProject.dir\UserInterface.cpp.obj: ..\UserInterface.cpp
CMakeFiles\FirstSemFinalProject.dir\UserInterface.cpp.obj: CMakeFiles\FirstSemFinalProject.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FirstSemFinalProject.dir/UserInterface.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\FirstSemFinalProject.dir\UserInterface.cpp.obj.d --working-dir="C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug" --filter-prefix="Note: including file: " -- "D:\Visual Studio\VC\Tools\MSVC\14.30.30705\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\FirstSemFinalProject.dir\UserInterface.cpp.obj /FdCMakeFiles\FirstSemFinalProject.dir\ /FS -c "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\UserInterface.cpp"
<<

CMakeFiles\FirstSemFinalProject.dir\UserInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstSemFinalProject.dir/UserInterface.cpp.i"
	"D:\Visual Studio\VC\Tools\MSVC\14.30.30705\bin\Hostx86\x86\cl.exe" > CMakeFiles\FirstSemFinalProject.dir\UserInterface.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\UserInterface.cpp"
<<

CMakeFiles\FirstSemFinalProject.dir\UserInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstSemFinalProject.dir/UserInterface.cpp.s"
	"D:\Visual Studio\VC\Tools\MSVC\14.30.30705\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\FirstSemFinalProject.dir\UserInterface.cpp.s /c "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\UserInterface.cpp"
<<

# Object files for target FirstSemFinalProject
FirstSemFinalProject_OBJECTS = \
"CMakeFiles\FirstSemFinalProject.dir\main.cpp.obj" \
"CMakeFiles\FirstSemFinalProject.dir\StockManagement.cpp.obj" \
"CMakeFiles\FirstSemFinalProject.dir\UserInterface.cpp.obj"

# External object files for target FirstSemFinalProject
FirstSemFinalProject_EXTERNAL_OBJECTS =

FirstSemFinalProject.exe: CMakeFiles\FirstSemFinalProject.dir\main.cpp.obj
FirstSemFinalProject.exe: CMakeFiles\FirstSemFinalProject.dir\StockManagement.cpp.obj
FirstSemFinalProject.exe: CMakeFiles\FirstSemFinalProject.dir\UserInterface.cpp.obj
FirstSemFinalProject.exe: CMakeFiles\FirstSemFinalProject.dir\build.make
FirstSemFinalProject.exe: CMakeFiles\FirstSemFinalProject.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable FirstSemFinalProject.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\FirstSemFinalProject.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100203~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100203~1.0\x86\mt.exe --manifests -- "D:\Visual Studio\VC\Tools\MSVC\14.30.30705\bin\Hostx86\x86\link.exe" /nologo @CMakeFiles\FirstSemFinalProject.dir\objects1.rsp @<<
 /out:FirstSemFinalProject.exe /implib:FirstSemFinalProject.lib /pdb:"C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug\FirstSemFinalProject.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\FirstSemFinalProject.dir\build: FirstSemFinalProject.exe
.PHONY : CMakeFiles\FirstSemFinalProject.dir\build

CMakeFiles\FirstSemFinalProject.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FirstSemFinalProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles\FirstSemFinalProject.dir\clean

CMakeFiles\FirstSemFinalProject.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject" "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject" "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug" "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug" "C:\Users\Nadun N. T. Fernando\CLionProjects\FirstSemFinalProject\cmake-build-debug\CMakeFiles\FirstSemFinalProject.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\FirstSemFinalProject.dir\depend

