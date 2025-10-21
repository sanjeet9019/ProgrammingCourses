#!/bin/bash
##################################################################
# Script Name   : shell_scripting_concepts.sh
# Description   : A comprehensive demonstration script covering
#                 fundamental Shell Scripting concepts...
# Author        : Sanjeet Prasad
# Email         : sanjeet8.23@gmail.com
# Date          : October 21, 2025
##################################################################

# --- Global Settings Variable ---
# Set this variable to 'true' or 'false' to globally control
# 'set -o nounset' and 'set -o pipefail' for the entire script.
# Default: true (for robustness)
ENABLE_ROBUST_OPTS="true"

# Global variables (can be used for script-wide settings)
LOG_FILE="script_execution.log"

##
# Core Conceptual Functions
##

# Function to enable or disable robust execution options based on the global variable
configure_robustness() {
    # set -o nounset (set -u): Treat unset variables as an error
    # set -o pipefail: Exit if any command in a pipeline fails
    
    if [[ "$ENABLE_ROBUST_OPTS" == "true" ]]; then
        echo "Global Robustness: Enabled (nounset, pipefail)."
        set -o nounset
        set -o pipefail
    else
        echo "Global Robustness: Disabled."
        set +o nounset
        set +o pipefail
    fi

    # Note on 'set -e': It's often best to control 'set -e' (errexit) inside main()
    # or specific functions, as enabling/disabling it inside a function can
    # be tricky and may not persist reliably across all shell environments.
    # For simplicity, we'll keep it disabled globally unless needed in 'debugging'.
}

# Debugging Shell script setup
# This function is used for *temporary* debug modes (set -x, set -v)
debugging()
{
    echo "############### DEBUGGING SETUP ###################"
    # Customize debug output format to show line numbers
    PS4='Line ${LINENO}: '
    
    # Enable debugging: print commands and their arguments as they are executed
    set -x
    # Enable verbose mode: print shell input lines as they are read
    set -v
    # Enable immediate exit on error (errexit)
    set -e 

    echo "Debugging modes (set -x, set -v, set -e) are active for this function."
}

# Variable demonstration
Variables()
{
    echo "==================================================="
    echo "############### VARIABLE DEMONSTRATION ###############"
    # Scalar Variables
    NAME="Linux shell scripting "
    VAR1=100
    VAR2=200
    Command="pwd"
    # Command Substitution using $()
    EchCmd=$($Command)
    echo "Variables Name is $NAME ,Var1 is $VAR1 ,Var2 is $VAR2"
    echo "Command running now is $Command "
    echo "Actual Command running result: $EchCmd "

    date1="date"
    # Command Substitution using $()
    datecmd=$($date1)
    echo "Current Date and time: $datecmd "
    # Delete the variable NAME
    unset NAME
    
    # Unix / Linux - Special Variables
    echo "--- Special Variables ---"
    # To fix the 'unbound variable' error when $1 is not passed, use ${1-}
    echo "Current script name: $0, First argument: ${1-} ,Number of arguments supplied: $# ,Process ID: $$"
    # $?: Exit status of the most recently executed foreground pipeline
    echo "Result of last command run = $?" # This will be the status of the last 'echo'

    # Array Demonstration
    echo "--- Array Demonstration ---"
    NAME[0]="First"
    NAME[1]="Second"
    NAME[2]="Third"
    NAME[3]="Fourth"
    NAME[4]="Fifth"
    NUMARR=(1 2 3 4 5 6 7 8 9 10)

    echo "NAME Array - First Index: ${NAME[0]}"
    echo "NAME Array - Second Index: ${NAME[1]}"
    echo "NAME Array - All elements (First Method): ${NAME[*]}"
    echo "NUMARR Array - All elements: ${NUMARR[*]}"

    strArr=("Apple" "Mango" "Orange")
    echo "strArr First element : ${strArr[0]}"
    echo "strArr all elements : ${strArr[*]}"
    # Iterate over array elements
    echo "Iterating over elements:"
    for element in "${strArr[@]}"; do
       echo -e "- $element "
    done

    # Echo and Printf Formatting
    echo "--- Output Formatting ---"
    # -e enables interpretation of backslash escapes like \n (newline)
    echo -e "This is the first line.\nThis is the second line."
    # Printing to stderr (Standard Error) file descriptor (2)
    echo "This is an error message" >&2
    value="Formatted string "
    # printf for formatted output (like C)
    printf "This is printing using printf statement ,formatted output = %s\n" "$value"
}

# Arithmetic and File Operators
operatorsfunc()
{
    echo "==================================================="
    echo "################## OPERATOR DEMONSTRATION #################"
    a=10
    b=10

    # Arithmetic Operations using $(())
    Sum=$((a + b))
    Mul=$((a * b))
    # Note: $((a == b)) evaluates to 1 (true) or 0 (false)
    bool=$((a == b))
    echo "Sum $Sum, Multiplication $Mul, Equality Check (1=true, 0=false) $bool"

    # Conditional (Test) Operators: -eq (numeric equality)
    if [ "$a" -eq "$b" ]; then
        echo "a and b are equal (using -eq)."
    else
        echo "a and b are not equal (using -eq)."
    fi

    # Logical Operators (Short-circuit evaluation)
    file="example.txt"
    # Using || (Logical OR): If touch fails, then echo runs.
    touch "$file" > /dev/null 2>&1 || echo "Attempted to create $file"

    # Using && (Logical AND): Check if file exists (-e) AND print its content (cat)
    if [ -e "$file" ] && cat "$file" > /dev/null 2>&1; then
        echo "$file exists and its content was processed."
    else
        echo "$file still doesn't exist or cat failed."
    fi
    rm -f "$file" # Clean up the example file

    # Advanced Arithmetic Calculation
    # (a+b)^2 = a^2 + b^2 + 2*a*b
    sum1=$((($a*$a)+($b*$b)+(2*$a*$b)))
    # Calculate the square of the sum directly
    result=$((($a + $b) * ($a + $b)))
    echo "Sum of Square (a^2+b^2+2ab) $sum1, Result of (a+b)^2: $result"

    # Basic Arithmetic
    mul1=$(($a*$b))
    div1=$(($a/$b))
    echo "Multiplication $mul1, Integer Division $div1"
}

# Decision Making (if/elif/else and case)
DecisionMaking()
{
    echo "==================================================="
    echo "############# DECISION MAKING STATEMENT FUNCTIONS #############"
    # if-elif-else for Numeric Comparison
    number=100
    echo "Checking number: $number"
    # Check if the number is positive, negative, or zero
    if [ "$number" -gt 0 ]; then
        echo "The number $number is positive (using -gt)."
    elif [ "$number" -lt 0 ]; then
        echo "The number $number is negative (using -lt)."
    else
        echo "The number is zero (using -eq)."
    fi

    # String Comparison
    string1="hello"
    string2="hello"
    # For string comparison, use == or =
    if [ "$string1" == "$string2" ];then
        echo "Strings are equal (using ==)."
    else
        echo "Strings are not equal (using ==)."
    fi

    # Numeric Comparison
    num1=10
    num2=10
    # For number comparison, use -lt, -eq, -gt
    if [ $num1 -eq $num2 ];then
        echo "Numbers are equal (using -eq)."
    else
        echo "Numbers are not equal (using -eq)."
    fi

    # File Test Operators
    touch log.txt # Ensure log.txt exists for the file tests
    # Link creation and removal for demonstration
    ln log.txt hardlink.txt > /dev/null 2>&1
    ln -s log.txt softlink.txt > /dev/null 2>&1
    echo "Created hardlink (hardlink.txt) and softlink (softlink.txt) to log.txt."

    # Remove links after testing
    rm -f hardlink.txt softlink.txt > /dev/null 2>&1

    # Test if 'log.txt' is a regular file (-f)
    if [ -f log.txt ]; then
      echo "log.txt is present and is a regular file (-f)."
    else
      echo "log.txt does not exist or is not a regular file."
    fi
    rm -f log.txt # Clean up

    # Combined Conditional Logic (&& and ||)
    number=100
    # Check if the number is greater than 10 AND even
    if [ $number -gt 10 ] && [ $((number % 2)) -eq 0 ]; then
        echo "The number is greater than 10 AND even (using &&)."
    else
        echo "The number is not greater than 10 or not even."
    fi

    # Check if the number is less than 5 OR odd
    if [ $number -lt 5 ] || [ $((number % 2)) -ne 0 ]; then
        echo "The number is less than 5 OR odd (using ||)."
    else
        echo "The number is neither less than 5 nor odd."
    fi

    # Directory and Executable Test Operators
    if [ -d "dirname" ]; then
      echo "Directory 'dirname' exists (-d)."
    else
      echo "Directory 'dirname' does not exist (-d)."
    fi

    if [ -x "/bin/bash" ]; then # Testing a known executable
       echo "/bin/bash is executable (-x)."
    else
       echo "/bin/bash is not executable."
    fi

    # Case Statement Demonstration
    echo "--- Case Statement ---"
    dayNumber=5
    # Use the case statement to check the day of the week
    case "$dayNumber" in
        1) echo "Sunday" ;;
        2) echo "Monday" ;;
        3) echo "Tuesday" ;;
        4) echo "Wednesday" ;;
        5) echo "Thursday" ;;
        6) echo "Friday" ;;
        7) echo "Saturday" ;;
        *) echo "Invalid input. Please enter a number between 1 and 7." ;;
    esac
}

# Loop function (while and for)
LoopStatement()
{
    echo "==================================================="
    echo "################### LOOPS STATEMENT FUNCTIONS ###############"

    # While Loop with break
    count=10
    echo "--- While Loop (counting down with break) ---"
    while [ "$count" -gt 0 ]; do
        echo "Count: $count"
        count=$((count-1))
        if [ "$count" -eq 5 ];then
            echo "Count is $count: Executing break."
            break # Exit the loop immediately
        fi
    done

    # C-style For Loop with continue
    echo "--- For Loop (C-style with continue) ---"
    for ((i = 1; i <= 10; i++)); do
        if [ "$i" -eq 5 ];then
            echo "For loop counter is $i: Executing continue (skipping echo)."
            continue # Skip the rest of the loop body for this iteration
        fi
        echo "i: $i"
    done
}

# Metacharacters demonstration
MetaCharacters()
{
    echo "==================================================="
    echo "####################### METACHARACTERS FUNCTIONS #########################"

    # 1. Wildcard (*) for file matching
    echo "1. Wildcard (*): List of files in the current directory:"
    ls *

    # 2. Command substitution ($())
    echo "2. Command substitution (\$(\)): Current date and time: $(date)"

    # 3. Single quotes (') to preserve literal value
    echo "3. Single quotes (''): 'This is a single-quoted string with \$variable'"

    # 4. Double quotes (") for variable expansion
    name="John"
    echo "4. Double quotes (\"\"): Hello, $name!"

    # 5. Backslash (\) to escape special characters
    echo "5. Backslash (\\): This is a backslash: \\"

    # 6. Semicolon (;) to separate commands
    echo "6. Semicolon (;): Command 1"; echo "Command 2"

    # 7. Pipe (|) for command chaining (redirecting output of one to input of next)
    echo "7. Pipe (|): 'Hello, world!' | grep 'world' ->"
    echo "Hello, world!" | grep "world"

    # 8. Parentheses () for arithmetic expansion
    echo "8. Parentheses (): Result: $((2 + 2))"

    # 9. Ampersand (&) for running a command in the background
    (sleep 2) & # Run sleep in a subshell in the background
    echo "9. Ampersand (&): Sleep command is running in the background (PID: $!)."
    wait # Wait for the background job to complete

    # 10. Newline for line breaks (using -e)
    echo "10. Newline (\n):"
    echo -e "This is line 1\nThis is line 2"

    # 11. Space and tab for separating words (internal field separator)
    echo "11. Space and tab: Word1 Word2    Word3"

    # Output Redirection
    echo "--- Output/Input Redirection ---"
    # 12. Redirecting output to a file (>) - overwrites
    echo "Redirecting to a file" > output.txt

    # 13. Append output to a file (>>) - appends
    echo "Appending to a file" >> output.txt

    # 14. Input Redirection (<)
    echo "Input redirection file1.txt content (created earlier by ls):"
    ls -l > file1.txt 2>&1
    cat < file1.txt

    # 15. Discard output to /dev/null
    echo "Discarding output to /dev/null"
    cat file1.txt > /dev/null
    cat file1.txt > /dev/null 2>&1 # Discard both stdout (1) and stderr (2)
    rm -f output.txt file1.txt # Clean up
}

# Substitution demonstration
Substition()
{
    echo "==================================================="
    echo "#################### SUBSTITUTION FUNCTIONS ######################"

    # Variable Substitution
    a=10
    echo -e "1. Variable Substitution: Value of a is $a \n"

    # Command Substitution (Backquotes vs. $())
    # Backquotes (`) are legacy; $() is preferred.
    DATE=`date`
    DATE1=$(date)
    echo "2. Command Substitution: Date (using backquotes) is $DATE"
    echo "3. Command Substitution: Date (using \$()) is $DATE1"

    # Parameter Expansion
    var="India"
    # ${var} is explicit parameter expansion, useful when concatenating strings
    string="I love my country, ${var}."
    echo "4. Parameter Expansion: $string"
}

# Standard Function Definition
Hello () {
    echo "==================================================="
    echo "#################### FUNCTION CALL ######################"
    # $1 and $2 are positional parameters passed to the function
    echo "Hello World - Shell Function called, Arguments: arg1: $1, arg2: $2"
    return 0 # Return status of the function (0 means success)
}

# Grep and Sed (Stream Editor) demonstration
grepsed()
{
    echo "==================================================="
    echo "############################ GREP/SED FUNCTIONS #############################"
    # Create a temporary file for sed/grep demonstrations
    echo -e "1 unix is awesome\n2 learn shell scripting\n3 one two three\n4 unix\n5 one\n31-12-2022\nlog.txt contains errors" > file.txt
    echo -e "2025-10-21 INFO Starting process\n2025-10-21 ERROR File not found\n2025-10-21 INFO User logged in" > log.txt

    echo "--- Grep Command Demonstration ---"
    # grep -i: ignore case, -n: line number, -r: recursive, -w: whole word
    echo "Grep command: Finding 'INFO' in log.txt (case-insensitive, line number, recursive search in current dir is not used here):"
    grep -in "INFO" log.txt
    echo "Grep command: Finding all .txt files (find command):"
    find . -iname "*.txt"

    echo "--- Sed Command Demonstration (Stream Editor) ---"
    # Sed command: Replacing or substituting string
    # 1. Replace 'unix' with 'linux' and print to screen (-e)
    echo "1. Replace 'unix' with 'linux' (print to screen):"
    sed -e "s/unix/linux/g" file.txt

    # 2 & 3. Replace in-place (-i)
    echo "2 & 3. In-place substitution (unix->linux, then linux->unix):"
    sed -i "s/unix/linux/g" file.txt
    sed -i "s/linux/unix/g" file.txt
    cat file.txt # Show the result of the in-place change (should be back to 'unix')

    # 4. Replace and print (demonstrates input and output)
    echo "4. Cat original file, then sed replace and print:"
    cat file.txt ; sed -e 's/unix/linux/g' file.txt

    # Print a specific line (3rd line only)
    echo "Print 3rd line only (-n '3p'):"
    sed -n "3p" file.txt

    # Delete the line containing this string
    echo "Delete lines containing 'learn' (-e '/learn/D'):"
    sed -e "/learn/D" file.txt

    # 5. Put one word at the beginning of each line (s/^/word/)
    echo "5. Put 'START:' at the beginning of each line:"
    sed 's/^/START: /' file.txt

    # 6. Put a word at the end of each line (s/$/word/)
    echo "6. Put ' END' at the end of each line:"
    sed 's/$/ END/' file.txt

    # 7. Prints only lines that START with the string 'unix'
    echo "7. Print lines starting with 'unix' (-e '/^unix/p' and -n to suppress normal output):"
    sed -n -e '/^unix/p' file.txt

    # 9. Exchange multiple occurrences (using \| for OR, requires -E for extended regex in some systems)
    echo "9. Exchange 'unix', 'learn', or 'one' with 'NEWWORD':"
    sed -E "s/unix|learn|one/NEWWORD/g" file.txt

    # 10. Print a range of lines (1-2)
    echo "10. Print line range 1-2:"
    sed -n '1,2p' file.txt

    # 11. Replace a date/number using capturing groups and backreferences
    echo "11. Date format reversal (DD-MM-YYYY to YYYY-MM-DD):"
    echo "31-12-2022" | sed -E 's/([0-9]{2})-([0-9]{2})-([0-9]{4})/\3-\2-\1/' # \3-\2-\1 references captured groups

    # Delete Empty Lines
    echo "Delete Empty Lines ('/^$/d'):"
    sed '/^$/d' file.txt

    # Backreference for word swap
    echo "Word swap (John Doe -> Doe, John):"
    echo "John Doe" | sed 's/\(John\) \(Doe\)/\2, \1/'

    rm -f file.txt log.txt # Clean up
}

# Awk command demonstration
awkcommand()
{
    echo "==================================================="
    echo "############################### AWK COMMAND FUNCTIONS #############################################"
    # Create log file for awk demo
    echo -e "1598863888 INFO Start script\n1598863889 ERROR Failed to connect\n1598863890 INFO Connected successfully\n1598863891 ERROR Timeout occurred" > log.txt

    echo "--- Basic Awk Usage ---"
    echo "Grep, Sed, and Awk equivalents for finding 'INFO':"
    grep "INFO" log.txt
    sed -n "/INFO/p" log.txt
    # Awk: /pattern/{action}
    awk "/INFO/{print}" log.txt # Prints lines containing INFO

    echo "--- Awk: Substitution (gsub) ---"
    # Awk: gsub(regex, replacement) substitutes all occurrences
    echo "Substituting all 'ERROR' with 'CRITICAL':"
    awk '{gsub(/ERROR/, "CRITICAL"); print}' log.txt

    echo "--- Awk: BEGIN and END Blocks ---"
    # BEGIN block executes before any lines, END block executes after all lines
    echo "Adding Header and Footer:"
    awk 'BEGIN {print "LOG SUMMARY\n--------------"} {print} END {print "--------------\nEND OF LOG SUMMARY"}' log.txt

    echo "--- Awk: Column Manipulation (Default Field Separator is Whitespace) ---"
    # $1: first column, $2: second column, $0: entire line
    echo "Printing first and second column (timestamp and log level):"
    awk '{print $1, $2}' log.txt
    echo "Printing third column (message):"
    awk '{print $3}' log.txt

    echo "--- Awk: Numeric Calculation and Array Counting ---"
    # Calculates the number of ERROR event occurrences by counting them in an associative array
    echo "Count of 'ERROR' events:"
    awk '{count[$2]++} END {print count["ERROR"]}' log.txt

    echo "--- Awk: Numeric Comparison ---"
    # If the first field ($1 - timestamp) is greater than a value, print the line
    echo "Lines with timestamp > 1598863889:"
    awk '{ if ($1 > 1598863889 ) {print $0} }' log.txt

    rm -f log.txt # Clean up
}

# Function with arguments and return status demonstration
Function_Demo() {
    echo "==================================================="
    # The 'Hello' function is defined globally above
    Hello "Sanjeet" "Prasad" # Invoke the function
    retfun=$? # Capture the return status of the last command (Hello function)
    echo "Functions return value (\$?) of 'Hello' is: $retfun"
}

#---
##
# Main Execution Logic
##
# The main function orchestrates the execution of all conceptual functions.
main() {
    echo "==================================================="
    echo "Starting Shell Scripting Concepts Demonstration"

    # 1. Apply global robustness settings
    configure_robustness

	# A list of functions to be executed
	local functions_to_run=(
	# --- Basic (Core Syntax and Data) ---
    "Variables"          # 1. Fundamental concept: Storing and using data.
    "operatorsfunc"      # 2. Basic arithmetic, comparison, and file tests.
    "DecisionMaking"     # 3. Essential control flow (if/case).

    # -------------------------------------
    # --- Intermediate (Flow and Structure) ---
    "LoopStatement"      # 4. Iteration (for/while), break/continue.
    "Function_Demo"      # 5. Modularization, passing arguments, return codes.
    "MetaCharacters"     # 6. Shell expansion, quotes, I/O redirection, piping.
    "Substition"         # 7. Command and Parameter Expansion (a specific type of metacharacter usage).

    # -------------------------------------
    # --- Advanced (Text Processing Tools) ---
    "grepsed"            # 8. Essential text filtering (grep) and stream editing (sed).
    "awkcommand"         # 9. Advanced column/field processing and reporting.
	)

    # Use a loop to call each conceptual function
    for func in "${functions_to_run[@]}"; do
        echo "" # Blank line for separation
        echo "Executing concept: $func..."
        # The function name is passed as a command to be executed
        "$func"
        echo "Finished concept: $func."
    done

    echo "==================================================="
    echo "All Conceptual Functions Executed Successfully."
}

# Main Execution Entry Point
# Optional: Uncomment 'debugging' to enable extensive debug output for the entire main script.
# debugging
main "$@" # Pass all command-line arguments to the main function

# Optional: Disable debugging if it was enabled in a specific function but needs to be off globally.
# set +x
# set +v