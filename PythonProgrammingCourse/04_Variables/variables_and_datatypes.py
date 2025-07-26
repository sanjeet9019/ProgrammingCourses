"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Demonstrates variable declaration, valid naming,     ###
###                 Python data types (int, float, string, list, tuple), ###
###                 string operations, typecasting, and sequence types   ###
###  Created On   : 02-09-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

def main():
    # ------------------------- Variable Declaration --------------------------
    number = 100  # Python auto-allocates memory; approx. 4 bytes here
    number2 = 200
    name = "Python"

    print(number)
    del number  # variable deletion

    a = b = c = d = 100  # multiple assignment

    # ------------------------- Valid and Invalid Variable Names -------------------------
    string = "India"   # valid
    _string = "India"  # valid
    # 5string = "India"  # invalid: starts with number
    num = 100           # valid
    NUM = 200           # valid
    # if = 300           # invalid: 'if' is a reserved keyword
    number123 = 500

    # ------------------------- Integer and Float -------------------------
    num1 = 100
    num2 = 200
    num2 = -100

    float1 = 100.00
    pi = 3.14

    print(num1, float1)
    print(pi)

    # ------------------------- String Operations -------------------------
    string1 = "Python"
    string2 = "Programmer"
    string4 = "100"

    print(string1)
    print(string1[0])  # Indexing starts from 0

    string = string1 + string2        # concatenation
    string3 = 2 * string              # repetition
    string5 = 2 * string4             # repetition of numeric string

    print(string)
    print(string3)
    print(string5)

    # ------------------------- Typecasting -------------------------
    intnum = 150
    print(intnum)

    floatnum = float(intnum)         # int → float
    print(floatnum)

    string = "100"
    string1 = 2 * string             # string multiplication
    print(string1)

    intstr = int(string)             # string → int
    intmul = 2 * intstr
    print(intmul)

    age = 100                        # use of input() would return a string
    intage = int(age)
    print(intage)

    print(type(intage), type(string))  # type display

    # ------------------------- List Operations -------------------------
    list1 = [10, 20, 30, 40, 50, 60]
    list2 = [70, 80, 90, 100, 110]
    list5 = ["Gangadhar", "Hema", "venkat"]
    list3 = list1 + list2           # list concatenation
    list4 = 2 * list1               # repetition

    list5[0] = "Ashish"             # update list by index
    # list5[3] = "Gangadhar"       # assignment — index out of range (commented)

    print(list1)
    print(list1[0])
    print(list3)
    print(list4)
    print(list5)

    list6 = []                      # empty list
    print(list6)

    # ------------------------- Tuple Operations -------------------------
    tuple1 = (10, 20, 30, 40, 50, 60)
    tuple2 = (70, 80, 90, 100, 110)

    print(tuple1)
    print(tuple1[3])

    tuple3 = tuple1 + tuple2        # tuple concatenation
    print(tuple3)

    tuple4 = 2 * tuple1             # tuple repetition
    print(tuple4)

    # tuple1[0] = 100              # tuple is immutable — assignment not allowed

    # ------------------------- Assignment Summary -------------------------
    print("\nAssignments:")
    print("1. Define 10 valid and 10 invalid variable names")
    print("2. Declare 5 int, 5 float, and 5 string variables with type display")
    print("3. Perform string addition, multiplication, and index access")
    print("4. Typecasting: int→float, float→int, string→int, int→string")
    print("5. Perform list operations: print, add, multiply, update")
    print("6. Add element to list without using any function")
    print("7. Add all elements of a list manually")
    print("8. Perform tuple operations: print, add, multiply (update not allowed)")
    print("9. Add element to tuple without function (hint: create new tuple)")
    print("10. Sum all elements in a tuple manually")

if __name__ == "__main__":
    main()