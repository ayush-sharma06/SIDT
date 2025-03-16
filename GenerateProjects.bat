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

echo Done! Open the .sln file in the src folder.
pause

