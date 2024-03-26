@echo off

set NO_ERROR=0

set BUILD_DIR=build
set SCRIPT_DIR=scripts
set BUILD_FILE=cmake.ps1
set CLEAN_FILE=clean_build.ps1

set EXEC_FILE_NAME=gtest_algorithms.exe
set EXEC_FILE="%BUILD_DIR%\%EXEC_FILE_NAME%"

set ARG_1=%1


rem Check the input arguments
if "%ARG_1%"=="make" (
  powershell.exe -ExecutionPolicy Bypass -File "%SCRIPT_DIR%\%BUILD_FILE%"
) else if "%ARG_1%"=="clean" (
  powershell.exe -ExecutionPolicy Bypass -File "%SCRIPT_DIR%\%CLEAN_FILE%"
) else if "%ARG_1%"=="exec" (
  if exist %EXEC_FILE% (
    %EXEC_FILE%
  ) else (
    echo "Executable file not found"
  )
) else if "%ARG_1%"=="help" (
  goto :showHelp
) else (
  echo "Usage: cmake.bat [make|clean|exec|help]"
  goto :showHelp
)

goto :no_err_end

:showHelp
echo Usage: cmake.bat [command]
echo Commands:
echo  make  - Build the project
echo  clean - Clean the project
echo  exec  - Execute the project
echo  help  - Show this help message
echo.


:no_err_end
exit /b %NO_ERROR%
