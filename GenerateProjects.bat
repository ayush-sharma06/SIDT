@echo off
set CMAKE_PATH=vendor\cmake\bin\cmake.exe
set BUILD_DIR=build

if not exist "%CMAKE_PATH%" (
    echo CMake not found! Make sure it's inside vendor\cmake\bin.
    pause
    exit /b
)

echo Generating Visual Studio Project Files...
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

"%CMAKE_PATH%" -G "Visual Studio 17 2022" -S "%CD%" -B "%CD%\%BUILD_DIR%"

echo Building the solution...
"%CMAKE_PATH%" --build "%CD%\%BUILD_DIR%" --config Debug

"%CD%\build\bin\Debug-Windows-AMD64\Simulation\Simulation.exe"

echo Cleaning up CMake-generated files...
"%CMAKE_PATH%" --build "%CD%\%BUILD_DIR%" --target clean

echo Removing CMake cache and generated project files...
del /f /q "%BUILD_DIR%\CMakeCache.txt"
del /f /q "%BUILD_DIR%\cmake_install.cmake"
rmdir /s /q "%BUILD_DIR%\CMakeFiles"
rmdir /s /q "%BUILD_DIR%\x64"
rmdir /s /q "%BUILD_DIR%\build"
del /f /q "%BUILD_DIR%\*.sln"
del /f /q "%BUILD_DIR%\*.vcxproj"
del /f /q "%BUILD_DIR%\*.vcxproj.filters"
del /f /q "%BUILD_DIR%\*.vcxproj.user"


echo Cleanup complete! Only CMake-generated files were removed.

pause

