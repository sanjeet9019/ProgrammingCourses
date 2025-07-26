"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python debugger demo using pdb module and calculator ###
###                 module integration with conditional logic and break  ###
###  Created On   : 16-09-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import pdb                      # Python debugger module
import calc_module as calc      # Importing user-defined calculator module

def main():
    print("🚀 Starting Python Debugger Demo\n")

    a = 10
    pdb.set_trace()  # 🔍 Breakpoint 1 – inspect 'a'
    print("Value of a:", a)

    if a > 5:
        print("Condition Met ➝ a > 5")

    num1 = 100
    num2 = 10
    pdb.set_trace()  # 🔍 Breakpoint 2 – inspect before division
    divide = num1 / num2
    print("Result of num1 / num2 =", divide)

    result = calc.sum(10, 20)  # Calling module function
    print("Sum from module:", result)

    # Nested condition with break point
    a = 40
    b = 10
    c = 20
    pdb.set_trace()  # 🔍 Breakpoint 3 – inspect a, b, c
    if a > b:
        if a > c:
            print("✅ a is the largest number")

if __name__ == "__main__":
    main()

"""
🧠 Python Debugger Steps Recap:
1️⃣ import pdb
2️⃣ Add pdb.set_trace() where you suspect the issue
3️⃣ Use commands inside debugger: n (next), c (continue), s (step), l (list), q (quit), p variable
4️⃣ Debug, fix, then remove all pdb.set_trace() lines
"""