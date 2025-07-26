"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python program demonstrating file read/write modes,  ###
###                 seek and tell operations, and mode behaviors like    ###
###                 r+, w+, a+, plus conditional test case writing       ###
###  Created On   : 07-10-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

from datetime import date

def main():
    print("\n📁 File Pointer and Seek/Tell Demo\n")

    filename = r"otherfile.txt"
    with open(filename, "r") as fileptr:
        filepos = fileptr.tell()
        print("🔹 Initial file position after open:", filepos)

        readcontent = fileptr.read()
        print("🔹 File position after read():", fileptr.tell())
        print("🔸 File content:\n", readcontent)

        fileptr.seek(0, 0)  # Seek to beginning
        print("🔹 Position after seek(0,0):", fileptr.tell())
        print("🔸 Re-read from beginning:\n", fileptr.read())

        fileptr.seek(0, 1)  # Seek to current position
        print("🔹 Position after seek(0,1):", fileptr.tell())
        print("🔸 Attempted read from current:\n", fileptr.read())

        # Notes on seek()
        print("🧠 seek(0,0): Go to beginning")
        print("🧠 seek(0,1): Stay at current pointer")
        print("🧠 seek(0,2): Go to end of file")

    # Writing test case data with current date
    today = date.today()
    name = "rahul"
    string = f"hello world my name is {name}"

    print("\n📝 Creating PassTestCase.txt using write mode")
    with open(r"PassTestCase.txt", "w") as fileptr:
        fileptr.write(f"Test case 1 - 5G Throughput passed [{today}]\n")
        fileptr.write(f"Test case 2 - NR Handover passed [{today}]\n")
        fileptr.write(f"Test case 3 - LTE to NR reselection passed [{today}]\n")

    print("\n📝 Creating FailTestCase.txt using write mode")
    with open(r"FailTestCase.txt", "w") as fileptr:
        fileptr.write("Test case 1 - 4G Throughput failed\n")
        fileptr.write("Test case 2 - LTE Handover failed\n")
        fileptr.write("Test case 3 - NR to LTE reselection failed\n")

    print("\n📝 Writing initial test cases using w mode")
    with open(r"testw.txt", "w") as fileptr:
        print("Initial file position:", fileptr.tell())
        fileptr.write("Test case 1\n")
        fileptr.write("Test case 2\n")
        fileptr.write("Test case 3\n")

    print("\n📎 Appending new test cases using a mode")
    with open(r"testw.txt", "a") as fileptr:
        print("Current position before append:", fileptr.tell())
        fileptr.write("Test case 4\n")
        fileptr.write("Test case 5\n")
        fileptr.write("Test case 6\n")

    print("\n🔁 Reading then writing using r+ mode")
    with open(r"testw.txt", "r+") as fileptr:
        print("Current position before read:", fileptr.tell())
        content = fileptr.read()
        print("Position after read:", fileptr.tell())
        print("r+ content:\n", content)
        fileptr.write("We got the msg\n")

    # Notes:
    # w+ ➝ Writes then reads
    # a+ ➝ Appends then reads
    # r+ ➝ Reads then writes

if __name__ == "__main__":
    main()

# ----------------------------------------------------------------------
# 📘 Assignment Section (Preserved from Original Instruction)
# ----------------------------------------------------------------------

# 1. Write a Python code to do the following operations:
#    - Write the algebra formulae in a text file called algebra.txt
#    - Write student information (name, age, class) in a text file called student.txt
#    - Read both files using w+ and r+ modes

# 2. Write a sample code demonstrating the use of a+ mode in Python

# 3. Write a Python code to demonstrate the use of seek() and tell() functions:
#    - Read the same file (test.txt) twice
#    - Write to the same file twice using different positions