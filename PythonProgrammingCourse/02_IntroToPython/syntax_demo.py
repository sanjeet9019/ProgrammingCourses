"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python program demonstrating syntax elements such as ###
###                 line structure, comments, indentation, multiline     ###
###                 statements, and string quotations                    ###
###  Created On   : 26-08-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

def main():
    # ------------------------ Variable Declarations -----------------------
    num1 = 200
    num2 = 200
    string1 = "a"
    string2 = "b"

    # ------------------------ Indentation Example -------------------------
    if num1 < 100:
        print("Num1 is smaller than 100")
        print("This is the 3rd line of if condition ")
        a = 100
        b = 300
        c = 400
    else:
        print("Num1 is greater than 100")
        print("This is inside the else condition")
        d = 500
        e = 700

    # ------------------------ Comments Demo -------------------------------
    print("This is our normal program")  # Single-line comment using #

    # ------------------------ Multiline Statement -------------------------
    total = 10 + 20 + 30 + \
            40
    print("Total (multiline addition):", total)

    # ------------------------ Multiline Comment ---------------------------
    """
    Multiline comments in Python are typically written using triple quotes.
    Backslash (\) continues statements across lines.
    """

    # ------------------------ String Quotation Styles ---------------------
    string1 = 'India'
    string2 = "India"    # Preferred style for most strings
    string3 = """India"""

    print("Single quotes:", string1)
    print("Double quotes:", string2)
    print("Triple quotes:", string3)

    # ------------------------ Multiple Assignment -------------------------
    a, b, c = 10, 20, 30
    print("Multiple assignments:", a, b, c)

    # ------------------------ Placeholder Variable ------------------------
    while1 = 100  # Valid variable name, though not recommended

    # ------------------------ Assignment Ideas for Learners ----------------
    print("\nAssignments:")
    print("1. Write a program to check voting eligibility (if condition, proper indentation)")
    print("2. Create a multiline math statement that performs addition and subtraction")
    print("3. Print 'India is my country' using all three string styles")

if __name__ == "__main__":
    main()