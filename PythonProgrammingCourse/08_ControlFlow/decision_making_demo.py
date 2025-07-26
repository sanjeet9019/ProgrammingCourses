"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Demonstrates Python decision-making constructs:      ###
###                 if, if-else, if-elif-else, nested conditions with    ###
###                 real-world examples and learner assignments          ###
###  Created On   : 10-09-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

def main():
    print("\n🔸 Example: if-elif-else to check number sign\n")

    number = 0
    if number > 0:
        print("✔ The number is positive")
    elif number < 0:
        print("✔ The number is negative")
    else:
        print("✔ The number is zero")

    print("\n🔸 Example: Multi-branch elif condition with logical AND\n")

    priceoftomatoes = 10
    if 80 < priceoftomatoes < 100:
        print("Tomato price range matched: Australia")
    elif 25 <= priceoftomatoes <= 35:
        print("Tomato price range matched: Maharashtra")
    elif 10 <= priceoftomatoes <= 20:
        print("Tomato price range matched: Andhra")
    else:
        print("No price match found → Else condition")

    print("\n🔸 Example: Nested if condition to validate vehicle type\n")

    vehicle = "Car"
    tyres = 4
    if vehicle == "Car":
        if tyres == 4:
            print("✔ Vehicle is a Car and it has 4 tyres")
    else:
        print("❌ Not identified as a Car")

    print("\n🔸 Example: Nested if to validate voter eligibility\n")

    age = 20
    nationality = "Indian"
    if age >= 18:
        if nationality == "Indian":
            print("✔ You are eligible for voting")

    print("\n🔸 Example: Deep nested if condition with thresholds\n")

    number = 10
    if number > 10:
        if number > 50:
            if number > 100:
                print("✔ Number is greater than 100")

    print("\n📝 Assignments for Students\n")
    print("1️⃣ Use in / not in operator with list, string, and tuple")
    print("2️⃣ Use elif to assign grades: 1st class, 2nd class, 3rd class")
    print("3️⃣ Write a program to check if a number is Prime")
    print("4️⃣ Write a program to check if a number is Even")
    print("5️⃣ Use nested if to design a multi-condition logic (your own example)")

if __name__ == "__main__":
    main()