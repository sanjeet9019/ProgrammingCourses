"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Demonstrates arithmetic, comparison, logical,        ###
###                 membership, and bitwise operators in Python using    ###
###                 examples and algebraic expressions for clarity       ###
###  Created On   : 09-09-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

def main():
    # --------------------- Arithmetic Operators ---------------------
    print("\n🧮 Arithmetic Operators\n")

    # Addition
    number1 = 100
    number2 = 200
    Sum = number1 + number2
    print("Addition =", Sum)

    # Subtraction
    number1 = 200
    number2 = 100
    Subtraction = number1 - number2
    print("Subtraction =", Subtraction)

    # Multiplication
    number1 = 10
    number2 = 20
    Multiply = number1 * number2
    print("Multiply =", Multiply)

    # Division
    number1 = 200
    number2 = 10
    Division = number1 / number2
    print("Division =", Division)

    # Modulus
    number1 = 10
    number2 = 3
    Modulus = number1 % number2
    print("Modulus (remainder) =", Modulus)

    # Exponentiation
    number1 = 5
    number2 = 4
    Exponent = number1 ** number2
    print("Exponent =", Exponent)

    # ---------------- Algebraic Expressions Using Operators ----------------
    print("\n🔢 Algebraic Formula Implementation\n")

    a = 5
    b = 3

    # a² – b² = (a – b)(a + b)
    result = (a - b) * (a + b)
    print("a² – b² =", result)

    # (a + b)² = a² + 2ab + b²
    result = (a * a) + (2 * a * b) + (b * b)
    print("(a + b)² =", result)

    result1 = (a ** 2) + (2 * a * b) + (b ** 2)
    print("(a + b)² using exponent =", result1)

    # (a + b)³ = (a + b)(a + b)(a + b)
    cube_result = (a + b) ** 3
    print("(a + b)³ =", cube_result)

    # --------------------- Comparison Operators ---------------------
    print("\n📏 Comparison Operators\n")

    a, b, c = 10, 20, 10

    print("a == b:", a == b)
    print("a == c:", a == c)

    print("a != b:", a != b)
    print("a != c:", a != c)

    print("b > a:", b > a)
    print("a < c:", a < c)

    amit = 25
    govtage = 18
    if amit > govtage:
        print("✅ Amit is eligible for voting")

    print("b >= a:", b >= a)
    print("a <= c:", a <= c)

    # --------------------- Logical Operators ---------------------
    print("\n🔗 Logical Operators\n")

    a, b, c, d, e = 10, 20, 0, 50, -100

    # AND Operator
    result = a and b and c
    result1 = a and c
    print("a and b and c →", result)
    print("a and c →", result1)

    if result:
        print("✔ All values are non-zero: True condition")
    if result1:
        print("❌ One operand is zero: False condition")

    # OR Operator
    d = 0
    result = a or b
    result1 = d or c
    print("a or b →", result)
    print("d or c →", result1)

    if result:
        print("✔ At least one non-zero value: True condition")
    if result1:
        print("❌ All operands are zero: False condition")

    # NOT Operator
    a = 22
    result = not a
    print("not a (where a = 22) →", result)

    # --------------------- Membership Operators ---------------------
    print("\n🧮 Membership Operators\n")

    list1 = [10, 20, 30, 40, 50]
    number = 16
    result = number not in list1
    if result:
        print(f"{number} is not in list1 ➝", result)

    string = "India is my country"
    substring = "is"
    if substring in string:
        print(f"'{substring}' found in string ➝ True")

    tuple1 = (10, 30, 40)
    number = 30
    if number in tuple1:
        print(f"{number} found in tuple ➝ True")

    # --------------------- Expression with Operator Precedence ---------------------
    print("\n🧠 Operator Precedence Example\n")

    expression_result = 10 - 4 * 2  # = 10 - 8 = 2
    print("10 - 4 * 2 =", expression_result)

    # --------------------- Bitwise Operator Concept ---------------------
    print("\n📊 Bitwise AND Truth Table (Conceptual)\n")

    print("1 & 1 = 1")
    print("0 & 0 = 0")
    print("1 & 0 = 0")
    print("0 & 1 = 0")

    # --------------------- Assignment Summary ---------------------
    print("\n📝 Assignments for Practice\n")

    print("1. Implement algebra formulas: a³ ± b³, a⁴ ± b⁴, a⁵ ± b⁵")
    print("2. Check student pass/fail across 5 subjects using comparison and logical operators")
    print("3. Use 'or' operator with 3+ conditions to model a winner selection")
    print("4. Demonstrate 'not' operator in a logical toggle example")
    print("5. Use 'in' / 'not in' with string, list, and tuple")

if __name__ == "__main__":
    main()