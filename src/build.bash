#!/usr/bin/env bash

# Set options for strict error handling (-e), preventing clobbering existing files (-C), and echoing commands (-u)
set -Cue

# Set the THIS_DIR variable to the absolute path of the directory containing the script
THIS_DIR="$(cd "$(dirname "$0")" && pwd)"

# Set the ROOT_DIR variable to the absolute path of the project's root directory
ROOT_DIR="$(cd "${THIS_DIR}/.." && pwd)"

# Set the BIN_DIR variable to the absolute path of the 'bin' directory within the project
BIN_DIR="${ROOT_DIR}/DosBox_exe"

# Print the absolute path of the project's root directory
echo "${ROOT_DIR}"

# Change the current directory to THIS_DIR and assemble the keyboard.asm file to a binary file in BIN_DIR
cd "${THIS_DIR}" && \
    nasm main.asm -f bin -o "${BIN_DIR}/main.com"

# chmod +x build.bash