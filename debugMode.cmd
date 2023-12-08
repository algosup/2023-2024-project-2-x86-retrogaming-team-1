@REM Launch dosbox 
@REM Add turbo debugger to the DosBox_exe folder manually.

@REM @echo off is used to hide the commands from the user

@echo off

@REM Set the path to the directory where the script is located

set "ROOT_DIR=%~dp0"

@REM Set the path to the directory where the main.com file will be placed
set "BIN_DIR=%ROOT_DIR%\DosBox_exe"

@REM Set the path to the dosbox executable

set "DOSBOX_BIN=%ProgramFiles(x86)%\DOSBox-0.74-3\DOSBox.exe"

@REM Set the path to the dosbox configuration file
set "CONFIG_LOC=%ROOT_DIR%"


@REM Execute the dosbox command to go to the DosBox_exe folder

::"%DOSBOX_BIN%" -conf "%CONFIG_LOC%"

@REM Mount the DosBox_exe folder as the C drive
@REM Go to the C drive
@REM Clear the screen

"%DOSBOX_BIN%" -c "MOUNT c %BIN_DIR%" -c "c:" -c "cls" -c "td main.com"
