"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python program demonstrating user-defined functions, ###
###                 built-in string and list functions, including        ###
###                 calculator utilities and length calculator           ###
###  Created On   : 23-09-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import pdb

# ----------------------------- Calculator Functions -----------------------------

def sum(a, b):
    """Return sum of a and b"""
    return a + b

def sub(a, b):
    """Return difference between a and b"""
    return a - b

def multiply(a, b):
    """Return product of a and b"""
    return a * b

def divide(a, b):
    """Return division of a by b"""
    return a / b

def printcalc():
    """Print available calculation functions"""
    print("Available Calculator Functions: sum, sub, multiply, divide")

# ----------------------------- Utility Functions -----------------------------

def numberofelelist(input_list):
    """Calculate and print number of elements in a list (manual count)"""
    length = 0
    for count in input_list:
        length += 1
    print("🔢 Number of elements in the list =", length)

def builtinfunc():
    """Demonstrate Python built-in string and list functions"""

    print("\n🧵 String Functions Demo")
    string1 = "India"
    string2 = "Python Programming"

    print("Original string2:", string2)
    print("Lowercase:", string2.casefold())
    print("Uppercase:", string1.upper())
    print("Length of string2:", len(string2))
    print("Zero-padded string1:", string1.zfill(10))

    print("\n📦 List Functions Demo")
    list1 = [10, 20, 30, 40, 50]
    fruits = ['apple', 'banana', 'cherry']
    print("Original fruit list:", fruits)

    fruits.append("orange")
    print("After appending 'orange':", fruits)

    fruits.clear()
    print("After clearing list:", fruits)

    print("Length of list1:", len(list1))
    copied_list = list1.copy()
    print("Copied list1:", copied_list)

    # Reference for more: https://www.w3schools.com/python/python_ref_string.asp

# ----------------------------- Main Function -----------------------------

def main():
    print("\n🎯 Executing User-Defined Function Examples")

    list1 = [10, 20, 30, 40, 50]
    numberofelelist(list1)

    print("Using built-in len():", len(list1))

    # Uncomment below to run built-in function demo
    # builtinfunc()

    # Uncomment below to test calculator functions
    # print("Sum:", sum(10, 20))
    # print("Subtraction:", sub(200, 20))
    # print("Multiplication:", multiply(10, 10))
    # print("Division:", divide(1000, 5))

if __name__ == "__main__":
    main()