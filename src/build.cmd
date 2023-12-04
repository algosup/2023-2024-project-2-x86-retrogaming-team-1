@REM This script is used to build the main.com file
@REM  @echo off is used to hide the commands from the user
@echo off

@REM Change the current directory to the directory where the script is located
CD /D "%~dp0"

@REM Set the path to the directory where the script is located
set "SCRIPT_DIR=%~dp0"

@REM Set the root directory to the parent directory of the script directory
set "ROOT_DIR=%SCRIPT_DIR%\..\"

@REM Set the path to the nasm executable
set "NASM=%ROOT_DIR%.\nasm\nasm"

@REM Set the path to the directory where the main.com file will be placed
set "BIN_DIR=%ROOT_DIR%\DosBox_exe"

@REM Set the path to the dosbox configuration file
set "CONFIG_LOC=%ROOT_DIR%"

@REM Execute the nasm command to build the main.com file
"%NASM%" main.asm -f bin -o "%BIN_DIR%\main.com"

set "DOSBOX_BIN=%ProgramFiles(x86)%\DOSBox-0.74-3\DOSBox.exe"

@REM Execute the dosbox command to go to the DosBox_exe folder

::"%DOSBOX_BIN%" -conf "%CONFIG_LOC%"

@REM Mount the DosBox_exe folder as the C drive
@REM Go to the C drive
@REM Clear the screen

"%DOSBOX_BIN%" -c "MOUNT c %BIN_DIR%" -c "c:" -c "cls" -c main

@REM Pause the script
pause


