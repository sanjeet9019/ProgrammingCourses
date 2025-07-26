"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Utility module containing Person and Math classes,   ###
###                 basic functions like add(), and reusable constants   ###
###  Created On   : 15-10-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

PI = 3.14
import math

# ➕ Standalone addition function
def add(a, b):
    return a + b

# 👤 Person class: models individual attributes and behavior
class Person:
    def __init__(self, name, age, gender):
        self.name = name
        self.age = age
        self.gender = gender

    def persondetails(self):
        print("Person name:", self.name, "| Age:", self.age, "| Gender:", self.gender)

    def sleeping(self):
        print(self.name, "is sleeping")

# 📐 Math class: encapsulates arithmetic operations
class Math:
    def __init__(self, num1, num2):
        self.num1 = num1
        self.num2 = num2

    def add(self):
        result = self.num1 + self.num2
        print("Sum of two numbers:", result)

    def sub(self):
        result = self.num1 - self.num2
        print("Subtraction of two numbers:", result)

    def mul(self, num1, num2, num3):
        return num1 * num2 * num3

    def divide(self):
        return self.num1 / self.num2