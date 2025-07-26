"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python sample program demonstrating syntax errors,   ###
###                 runtime errors, variable declaration, input/output   ###
###  Created On   : 26-08-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

def main():
    """
    Demonstrates:
    - Syntax and runtime error examples (commented and explained)
    - Variable declaration and printing
    - Input handling from user
    - Use of reserved keyword 'del'
    """

    # Define numbers
    num1 = 100
    num2 = 200

    # Define strings
    name1 = "Ankur"
    name2 = "Hemlatha"

    # Display numbers
    print("num1:", num1)
    print("num2:", num2)

    # Display names
    print("Name 1:", name1)
    print("Name 2:", name2)

    # Demonstrate runtime fix
    num3 = num2 / 10
    print("Result of num2 / 10:", num3)

    # User input
    user_input = input("Enter something: ")
    print("You entered:", user_input)

    # Demonstrate 'del' keyword
    del user_input
    try:
        print(user_input)  # Runtime error: variable deleted
    except NameError:
        print("Error: 'user_input' was deleted and no longer exists.")

    del num1
    try:
        print(num1)  # Runtime error: variable deleted
    except NameError:
        print("Error: 'num1' was deleted and no longer exists.")

if __name__ == "__main__":
    main()