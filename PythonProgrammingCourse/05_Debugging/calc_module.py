"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python calculator module with arithmetic operations   ###
###                 and utility functions like list length calculator     ###
###  Created On   : 23-09-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

# ➕ Sum function
def sum(a, b):
    return a + b

# ➖ Subtract function
def sub(a, b):
    return a - b

# ✖ Multiply function
def multiply(a, b):
    return a * b

# ➗ Divide function
def divide(a, b):
    return a / b

# 🔎 Print available functions
def printcalc():
    print("🛠️ Calculator functions: sum, sub, multiply, divide")

# 📏 Count elements in a list
def numberofelelist(data_list):
    length = 0
    for count in data_list:
        length += 1
    print("Length of the list:", length)

# Constant value
PI = 3.14