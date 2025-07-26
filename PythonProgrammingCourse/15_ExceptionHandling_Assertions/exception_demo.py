"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Demonstrates handling of common Python exceptions    ###
###                 Includes ZeroDivisionError, ValueError, IndexError   ###
###                 and fallback to generic Exception                    ###
###  Created On   : 02-08-2025                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

def demo_zero_division():
    print("\n🚫 ZeroDivisionError Example")
    try:
        result = 10 / 0
    except ZeroDivisionError as e:
        print("Caught ZeroDivisionError:", e)

def demo_value_error():
    print("\n🚫 ValueError Example")
    try:
        number = int("abc")  # invalid string to int conversion
    except ValueError as e:
        print("Caught ValueError:", e)

def demo_index_error():
    print("\n🚫 IndexError Example")
    try:
        items = [1, 2, 3]
        print("Accessing index 5:", items[5])
    except IndexError as e:
        print("Caught IndexError:", e)

def demo_generic_exception():
    print("\n🚫 Generic Exception Example")
    try:
        x = undefined_variable + 5  # variable is not declared
    except Exception as e:
        print("Caught generic Exception:", e)

def main():
    print("🧪 Running exception handling demos:")
    demo_zero_division()
    demo_value_error()
    demo_index_error()
    demo_generic_exception()

if __name__ == "__main__":
    main()