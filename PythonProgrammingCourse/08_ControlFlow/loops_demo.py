"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python loop examples using while, for, break,        ###
###                 continue, range, nested loops, and assignments       ###
###  Created On   : 16-09-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import pdb

def main():
    print("\n🔁 Print numbers from 1 to 10 using while loop")
    num = 1
    while num <= 10:
        print(num)
        num += 1

    print("\n🔁 Print even numbers from 1 to 100 using step-wise increment")
    num = 2
    while num <= 100:
        print(num)
        num += 2

    print("\n🔁 Print even numbers using modulo check inside while loop")
    num = 1
    while num <= 100:
        if num % 2 == 0:
            print("Even number using %:", num)
        num += 1

    print("\n🔁 Print odd numbers from 1 to 100 using while loop")
    num = 1
    while num <= 100:
        print(num)
        num += 2

    print("\n🔁 Print multiplication table of 10 using while loop (break after 5 rows)")
    num = 1
    multiplication = 10
    while num <= 10:
        result = multiplication * num
        print(multiplication, "*", num, "=", result)
        num += 1
        if num == 5:
            break  # early exit

    print("\n🔁 For loop over list values")
    list1 = [10, 20, 30, 40, 50]
    for count in list1:
        print("List item:", count)

    print("\n🔁 For loop over string characters")
    string = "India is my country"
    for alpha in string:
        print("Character:", alpha)

    print("\n🔁 Use of range() function")
    list2 = list(range(1, 11, 1))
    print("Generated range list:", list2)

    print("\n🔁 Multiplication table of 3 using range")
    multipy = 3
    for num in range(1, 11):
        result = multipy * num
        print(multipy, "*", num, "=", result)

    # Uncomment below block to test infinite loop with exit condition
    # print("\n⏳ Infinite while loop demo (commented)")
    # while True:
    #     name = input("Enter your name: ")
    #     if name == "No":
    #         break
    #     print(name)

    print("\n🔁 Nested for loop - 10x10 multiplication grid")
    for outer in range(1, 11):
        for inner in range(1, 11):
            result = outer * inner
            print(outer, "*", inner, "=", result)

    print("\n🔁 Nested while loop - 10x10 multiplication grid (break after 5 rows)")
    outer = 1
    while outer <= 10:
        inner = 1
        while inner <= 10:
            result = outer * inner
            print(outer, "*", inner, "=", result)
            inner += 1

        outer += 1
        if outer == 6:
            break  # early exit after 5 outer loops

    print("\n🔁 While loop with continue - skip printing when num == 5")
    num = 1
    while num <= 10:
        if num == 5:
            num += 1
            continue  # skip printing 5
        print(num)
        num += 1

    print("\n📘 Assignment Suggestions:")
    print("1️⃣ Explore type mismatches with int and string operations")
    print("2️⃣ Print squares and cubes from 1 to 10 using while loop")
    print("3️⃣ Print prime numbers up to a given input")
    print("4️⃣ Print details of 10 employees using loop")
    print("5️⃣ Calculate sum of first 10 numbers")
    print("6️⃣ Print Fibonacci series up to a limit")
    print("7️⃣ Add elements of a list using loop")
    print("8️⃣ Use for loop to add numbers from 1 to 100")
    print("9️⃣ Use loop to print even and odd numbers separately")
    print("🔟 Use nested loop to list states and vegetables")
    print("🔁 Use nested loop with dictionary to compute average marks")
    print("💡 Create algebra calculator in infinite loop (exit with user input)")
    print("🧠 Use infinite loop to monitor HDD space (optional)")
    print("🚫 Use continue to skip specific loop values (like skipping number 5)")

if __name__ == "__main__":
    main()