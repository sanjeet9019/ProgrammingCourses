"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python program demonstrating various file operations ###
###                 including open, read (full/line/bytes), close, and  ###
###                 file handling best practices                         ###
###  Created On   : 01-10-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import math  # Example: Imported for potential future logic (not used here)

def main():
    print("\n📁 File Operation Demo Started\n")

    # 🖊️ Input Example (commented out for file-focused demo)
    # name = input("What is your name? ")
    # age = input("What is your age? ")
    # print("My name is", name, "and age is", age)

    # 📘 1st Way: Basic open() and read()
    print("\n🔹 Opening and reading full content using open() and read()\n")
    fileptr = open(r"C:\Users\x\Desktop\Python\batch12\Day12\FileOperation.py", "r")  # Raw path
    readcontent = fileptr.read()  # Reads entire file content
    print("File Content:\n", readcontent)
    fileptr.close()

    # 💡 Tip:
    # 1. Use raw string `r"..."` for Windows paths
    # 2. Always provide full absolute path
    # 3. `read()` reads full content; `read(n)` reads `n` bytes

    # 📘 2nd Way: Using `with open()` and iterating line by line
    print("\n🔹 Reading each line using with open + for loop\n")
    with open(r"C:\Users\x\Desktop\Python\batch12\Day12\PyPython.txt", "r") as fileptr:
        for eachline in fileptr:
            print(eachline.strip())  # Removes trailing newline

    # 📘 3rd Way: Using `readline()` in a loop
    print("\n🔹 Reading each line using with open + readline()\n")
    with open(r"C:\Users\x\Desktop\Python\batch12\Day12\PyPython.txt", "r") as fileptr:
        while True:
            content = fileptr.readline()
            if not content:  # EOF reached
                break
            print("readline():", content.strip())

    # 📘 Bonus: Read, then seek() or tell() usage placeholder
    print("\n🔹 Re-reading content using open() again\n")
    fileptr = open(r"C:\Users\x\Desktop\Python\batch12\Day12\FileOperation.py", "r")
    readcontent = fileptr.read()
    print("File Content:\n", readcontent)
    fileptr.close()

if __name__ == "__main__":
    main()

# ----------------------------------------------------------------------
# 📘 Assignment Section (Preserved from Original Instruction)
# ----------------------------------------------------------------------

# 1️⃣ Write a Python code that demonstrates the following file operations:
# - Using open()
# - Using with open()
# - read() function
# - Reading each line individually
# - Reading specific bytes using read(n)

# 📂 Use input file: FileOperation.py (or any other .py or .txt file for testing)