"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python program demonstrating regular expressions     ###
###                 including findall, search, split, and sub, applied   ###
###                 to email, mobile, salary patterns and file text      ###
###  Created On   : 14-10-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import re

def regex():
    # Sample multiline string with names, phone numbers, emails, salaries
    text = r"""
        India is my country. I love my country.
        We are doing Python class today.
        We have Amit, Ashish, Hema, Venkat, Madhu in the class.
        Amit mobile is +91 995821763, Ashish number +44 123234445, Hema number is +1 342345556, Madhu +92-56754556.
        Amit's email id is amit.python@gmail.com, Venkat has email id as venkat_python12@gmail.com.
        Hema has email id as hema_python12@yahoo.co.uk.
        Amit salary is $1200, Hema salary is $1400.55, Venkat salary is $5500.453.
    """

    # REGEX Patterns
    string = "email id as"
    pattern1 = rf"{string}"                            # Search for static text
    pattern2 = r"\+\d+\D?\s?\d+"                       # Mobile numbers
    pattern3 = r"\w+\.?\w+@\w+\.\w+\.?\w*"             # Email addresses
    pattern4 = r"\$\d+\.?\d*"                          # Salary amounts
    pattern5 = rf"{string} {pattern3}"                 # "email id as" followed by actual email

    # 🔍 Find email entries with context
    print("\n🔹 Extracting email IDs from string...")
    email_matches = re.findall(pattern5, text)
    for data in email_matches:
        print("Matched:", data)

    # 📄 Read and extract mobile numbers from external file
    filepath = r"text.txt"
    try:
        with open(filepath, "r") as fileptr:
            content = fileptr.read()
            mobile_matches = re.findall(pattern2, content)
            print("\n🔹 Extracted mobile numbers from file:")
            for number in mobile_matches:
                print("Found:", number)
    except FileNotFoundError:
        print("❌ FileNotFoundError: text.txt was not found.")

    # 🔍 re.search demo
    print("\n🔍 Using re.search() for keyword...")
    match = re.search(pattern1, text)
    if match:
        print("Match found:", match.group())
    else:
        print("No match found")

    # 📐 re.split demo
    print("\n📐 Using re.split() to tokenize salary sentence...")
    text2 = "amit salary is $1200, hema salary is $1400.55, venkat salary is $5500.453"
    split_pattern = r"\s"
    tokens = re.split(split_pattern, text2)
    for token in tokens:
        print("Token:", token)

    # ✂️ re.sub demo
    print("\n✂️ Using re.sub() to mask salary values...")
    salary_pattern = r"\$\d+\.?\d*"
    replace = "****"
    masked_text = re.sub(salary_pattern, replace, text2)
    print("Masked Salary Sentence:", masked_text)

def main():
    regex()

if __name__ == "__main__":
    main()

# ----------------------------------------------------------------------
# 📘 Assignment Section (Preserved from Original Instruction)
# ----------------------------------------------------------------------

# 1. Write a Python code using regex to find:
#    - At least 5 different email IDs
#    - At least 5 different types of mobile numbers

# 2. Demonstrate real-time use of:
#    - re.sub() for masking or sanitizing
#    - re.search() for lookup
#    - re.split() for token extraction