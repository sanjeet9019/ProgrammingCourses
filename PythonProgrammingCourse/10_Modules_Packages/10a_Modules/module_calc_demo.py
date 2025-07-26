"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Demonstrates usage of user-defined module, math,     ###
###                 matplotlib, pandas, and XML parsing modules          ###
###  Created On   : 24-09-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import module_calc as calc                 # Custom calculator module (module.py)
import math                                # Built-in math module
import matplotlib.pyplot as plt            # Graph plotting module
import pandas                              # Data manipulation library
import xml.etree.ElementTree as ET         # XML parsing module

def main():
    print("🧮 Calculator Function Calls from module.py")

    # Sum of two numbers
    result = calc.sum(10, 20)
    print("Sum of two numbers:", result)

    # Subtraction
    result = calc.sub(100, 20)
    print("Subtraction of two numbers:", result)

    # Multiplication
    result = calc.multiply(10, 10)
    print("Multiplication of two numbers:", result)

    # Print PI constant from module
    print("Value of PI from module:", calc.PI)

    print("\n🧠 Using math module")

    result = math.pow(2, 3)
    print("math.pow(2, 3):", result)

    result = math.sqrt(16)
    print("math.sqrt(16):", result)

    print("\n📈 Using matplotlib to generate graph")

    x = [1, 2, 3]
    y = [2, 4, 1]

    plt.plot(x, y)
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('Sample Line Graph')
    # plt.show()  # Uncomment this to display the plot in a window

    print("\n📊 Using pandas for tabular data representation")

    mydataset = {
        'cars': ["BMW", "Volvo", "Ford"],
        'passings': [3, 7, 2]
    }
    myvar = pandas.DataFrame(mydataset)
    print(myvar)

    print("\n📜 XML Parsing Example")

    try:
        mytree = ET.parse('sample.xml')  # Make sure this XML file is present
        myroot = mytree.getroot()
        print("Root tag:", myroot.tag)
        print("Root attributes:", myroot.attrib)
        print("First child tag:", myroot[0].tag)

        for x in myroot[0]:
            print("Tag:", x.tag, "Attributes:", x.attrib)

        for x in myroot[0]:
            print("Text content:", x.text)
    except FileNotFoundError:
        print("⚠️ sample.xml not found. Please place it in your working directory.")

if __name__ == "__main__":
    main()

# ----------------------------------------------------------------------
# 📘 Assignment Section (Preserved from Original Instruction)
# ----------------------------------------------------------------------

# 1. Write your own module for string operations (strlen, string concatenation, string compare, string search)
#    ➝ Create: string.py
#    ➝ Use in: userapp.py

# 2. Write your own module for banking software maintaining multiple accounts
#    ➝ Attributes: Account number, Account name, Balance
#    ➝ Module: banking.py
#    ➝ Use in: userapp.py

# 3. Use math module and implement 20 functions across different categories

# 4. Use matplotlib.pyplot with at least 5 plotting functions
#    ➝ Resources:
#       https://www.geeksforgeeks.org/graph-plotting-in-python-set-1/
#       https://matplotlib.org/3.5.3/api/_as_gen/matplotlib.pyplot.html

# 5. Use pandas library to perform Excel-like operations:
#    ➝ Read a CSV file
#    ➝ Update CSV file
#    ➝ Apply 5 different pandas functions

# 6. Use XML parsing module to decode contents of an XML file
#    ➝ Apply 5 parsing functions
#    ➝ Guide: https://www.edureka.co/blog/python-xml-parser-tutorial/