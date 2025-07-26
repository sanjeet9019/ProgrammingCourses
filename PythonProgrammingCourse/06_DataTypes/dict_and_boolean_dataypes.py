"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python program demonstrating dictionary data types,  ###
###                 multiple mapping styles, boolean types, and examples ###
###  Created On   : 03-09-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

def main():
    # Dictionary data types

    # 1st way to define a dictionary (employee name --> employee number)
    dict1 = {"sree": 1000, "venkat": 1022, "ashish": 1022, "amit": 1033}
    print(dict1)  # print whole dictionary
    print(dict1["sree"])  # print corresponding value

    dict1["sree"] = 2000  # update using key
    print(dict1["sree"])

    # Note: +, *, / not applicable to dictionaries

    # 2nd way to define a dictionary
    dict2 = {}
    dict2[1] = 1
    dict2[2] = 4
    dict2[3] = 9
    dict2[4] = 16
    dict2[5] = 25
    dict2[6] = 36
    dict2[7] = 49
    dict2[8] = 64
    dict2[9] = 81
    dict2[10] = 100

    print(dict2)
    print(dict2[3])  # get value using key

    dict2[3] = 90
    print(dict2[3])
    print(dict2.keys())
    print(dict2.values())

    # Numorology ➝ subcarrier spacing  (2^numorlogy × 15)
    dict3 = {}
    dict3[0] = 15
    dict3[1] = 30
    dict3[2] = 60
    dict3[3] = 120
    dict3[4] = 240

    # Boolean & None usage
    boolT = True
    boolF = False
    value = None

    print(boolT)

    if boolT:
        print("boolT is true")

    # Assignment (as per instructor's notes)
    # 1. Create cube dictionary 1–10 → int:int mapping
    # 2. Create employee profile → string:list mapping
    # 3. Create prime number mapping → int:list mapping
    # 4. Use both methods to define dictionaries
    # 5. Create condition using True/False/None to check even numbers

if __name__ == "__main__":
    main()