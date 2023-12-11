@REM Launch dosbox 
@REM Add turbo debugger to the DosBox_exe folder manually.

@REM @echo off is used to hide the commands from the user

@echo off

@REM Set the path to the directory where the script is located

set "ROOT_DIR=%~dp0"

@REM Set the path to the directory where the main.com file will be placed
set "BIN_DIR=%ROOT_DIR%\DosBox_exe"

@REM Set the path to the nasm executable
set "NASM=%ROOT_DIR%.\nasm\nasm"

@REM source code file
set "SRC_FILE=%ROOT_DIR%\src\main.asm"

@REM Library file
set "LIB_FILE=%ROOT_DIR%\src"

@REM Set the path to the dosbox executable

set "DOSBOX_BIN=%ProgramFiles(x86)%\DOSBox-0.74-3\DOSBox.exe"

@REM Set the path to the dosbox configuration file
set "CONFIG_LOC=%ROOT_DIR%"


@REM Execute the dosbox command to go to the DosBox_exe folder

@REM Execute the nasm command to build the main.com file
@REM Commented the command below if you don't want to build the main.com file before debugging
"%NASM%" "%SRC_FILE%" -f bin -o "%BIN_DIR%\main.com" -i "%LIB_FILE%"

::"%DOSBOX_BIN%" -conf "%CONFIG_LOC%"

@REM Mount the DosBox_exe folder as the C drive
@REM Go to the C drive
@REM Clear the screen

"%DOSBOX_BIN%" -c "MOUNT c %BIN_DIR%" -c "c:" -c "cls" -c "td main.com"
