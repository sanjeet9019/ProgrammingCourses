"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Contains basic arithmetic functions for testing      ###
###                 Functions: add, subtract, multiply, divide           ###
###  Created On   : 04-08-2025                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

def add(a, b):
    """Returns the sum of a and b"""
    return a + b

def subtract(a, b):
    """Returns the difference of a and b"""
    return a - b

def multiply(a, b):
    """Returns the product of a and b"""
    return a * b

def divide(a, b):
    """Returns the division result of a by b. Raises error if b is zero."""
    if b == 0:
        raise ValueError("Cannot divide by zero")
    return a / b

def main():
    print("\n🧮 Basic Math Operations Demo\n")
    print("Addition (3 + 2):", add(3, 2))
    print("Subtraction (10 - 4):", subtract(10, 4))
    print("Multiplication (6 * 7):", multiply(6, 7))
    print("Division (20 / 5):", divide(20, 5))

if __name__ == "__main__":
    main()