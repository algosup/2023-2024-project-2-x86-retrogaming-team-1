#!/bin/bash

# This script is used to build the main.com file

# Change the current directory to the directory where the script is located
cd "$(dirname "$0")"

# Set the path to the directory where the script is located
SCRIPT_DIR="$(pwd)"

# Set the root directory to the parent directory of the script directory
ROOT_DIR="$(dirname "$SCRIPT_DIR")"

# Set the path to the nasm executable
NASM="$ROOT_DIR/nasm/nasm"

# Set the path to the directory where the main.com file will be placed
BIN_DIR="$ROOT_DIR/DosBox_exe"

# Set the path to the dosbox configuration file
CONFIG_LOC="$ROOT_DIR"

# Execute the nasm command to build the main.com file
"$NASM" main.asm -f bin -o "$BIN_DIR/main.com"

# Set the path to the dosbox executable
DOSBOX_BIN="/Applications/DOSBox.app/Contents/MacOS/DOSBox"

# Execute the dosbox command to go to the DosBox_exe folder
# Mount the DosBox_exe folder as the C drive
# Go to the C drive
# Clear the screen

"$DOSBOX_BIN" -c "MOUNT c $BIN_DIR" -c "c:" -c "cls" -c main

# Pause the script
read -p "Press any key to continue . . . " -n1 -s