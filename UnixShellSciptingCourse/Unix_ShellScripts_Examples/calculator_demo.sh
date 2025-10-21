#!/bin/bash

##################################################################
# Script Name : calculator.sh
# Description : A simple command-line calculator using Bash's
#               built-in arithmetic for integer operations.
# Author      : Sanjeet Prasad
# Email       : sanjeet8.23@gmail.com
# Date        : October 21, 2025
##################################################################

# Function: Display usage instructions
show_usage() {
    echo "Usage: $0"
    echo "This script prompts for two integers and performs basic arithmetic."
    exit 1
}

# Function: Perform calculation based on user choice
calculate() {
    local num1="$1"
    local num2="$2"
    local choice="$3"
    local result
    local op

    case "$choice" in
        1)
            result=$((num1 + num2))
            op="Addition"
            ;;
        2)
            result=$((num1 - num2))
            op="Subtraction"
            ;;
        3)
            result=$((num1 * num2))
            op="Multiplication"
            ;;
        4)
            if [ "$num2" -eq 0 ]; then
                echo "Error: Division by zero is not allowed."
                exit 1
            fi
            result=$((num1 / num2))
            op="Division"
            ;;
        *)
            echo "Invalid choice. Please select 1–4."
            show_usage
            ;;
    esac

    echo "$op result: $result"
}

# Main logic
main() {
    echo "Enter two integers:"
    read num1 num2

    # Validate input
    if ! [[ "$num1" =~ ^-?[0-9]+$ && "$num2" =~ ^-?[0-9]+$ ]]; then
        echo "Error: Please enter valid integers."
        exit 1
    fi

    echo "Select an operation:"
    echo "  1. Addition"
    echo "  2. Subtraction"
    echo "  3. Multiplication"
    echo "  4. Division"
    read choice

    calculate "$num1" "$num2" "$choice"
}

main "$@"
exit 0
