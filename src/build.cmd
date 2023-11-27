@REM This script is used to build the main.com file
@REM  @echo off is used to hide the commands from the user
@echo off

@REM Set the path to the directory where the script is located
set "SCRIPT_DIR=%~dp0"

@REM Set the root directory to the parent directory of the script directory
set "ROOT_DIR=%SCRIPT_DIR%\..\"

@REM Set the path to the nasm executable
set "NASM=%ROOT_DIR%.\nasm\nasm"

@REM Set the path to the directory where the main.com file will be placed
set "BIN_DIR=%ROOT_DIR%\DosBox_exe"

@REM Execute the nasm command to build the main.com file
"%NASM%" main.asm -f bin -o "%BIN_DIR%\main.com"

@REM Pause the script
pause


