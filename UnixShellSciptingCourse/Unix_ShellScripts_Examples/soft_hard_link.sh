#!/bin/bash

##################################################################
# Script Name : link_demo.sh
# Description : Demonstrates creation of hard and symbolic links,
#               with debug tracing and file existence check.
# Author      : Programmer
# Date        : December 4, 2023
##################################################################

# Customize debug output to show line numbers
PS4='Line ${LINENO}: '

# Enable debug mode (prints each command before executing)
set -x

# Create a sample file
echo "Sample log content" > log.txt

# Create a hard link named hardlink.txt pointing to log.txt
ln log.txt hardlink.txt

# Create a symbolic link named softlink.txt pointing to log.txt
ln -s log.txt softlink.txt

# Check if the original file exists
if [ -f log.txt ]; then
    echo "File present"
else
    echo "File does not exist"
fi
