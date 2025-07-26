"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Demonstrates object usage and function interaction    ###
###                 from utility_class.py including Person and Math use  ###
###  Created On   : 15-10-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import utility_class  # Importing renamed module

def classexample():
    # 🧍 Create Person objects
    Person1 = utility_class.Person("Amit", 25, "male")
    Person2 = utility_class.Person("Sree", 30, "male")
    Person3 = utility_class.Person("Hema", 16, "female")

    # 📋 Display person details
    Person1.persondetails()
    Person2.persondetails()
    Person3.persondetails()

    # 💤 Simulate sleeping action
    Person3.sleeping()
    Person1.sleeping()
    Person2.sleeping()

    # ➕ Use utility_class function
    result = utility_class.add(10, 20)
    print("Sum of two numbers:", result)

    # ⚙️ Create Math object and perform operations
    math1 = utility_class.Math(200, 100)
    math1.add()
    math1.sub()

    result1 = math1.mul(10, 10, 10)
    print("Multiplication of three numbers:", result1)

    result2 = math1.divide()
    print("Division of two numbers:", result2)

    result3 = math1.mul(10, 20, 30)
    print("Multiplication of three numbers:", result3)

def main():
    classexample()

if __name__ == "__main__":
    main()