#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Regex Pattern Extractor from Text File               ###
###                 Finds emails, phone numbers, ages, locations, etc.  ###
###  Date         : 03-05-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################

import re

# Optional data storage (can be extended for CSV/DB export)
salary_data = []

def extract_regex_patterns():
    """
    Reads a text file and applies various regex patterns to extract structured data.
    """
    try:
        with open("test.txt", "r", encoding="utf-8") as file:
            content = file.read()
            print("📄 File loaded successfully.\n")
    except FileNotFoundError:
        print("❌ File 'test.txt' not found.")
        return

    # Define multiple regex patterns
    patterns = {
        "All Numbers": r"\d+",
        "Phone Numbers": r"\+\d+\s\d+\s\d+",
        "Email Addresses": r"\w+\.?\w+@\w+\.\w+",
        "Age Info": r"age is \d+",
        "Location Info": r"lives in \(\w+\)",
        "Salary Format": r"\-?\$\d+\.\d+",
        "Keyword Match": r"Spain",
        "Digit-Followed Dot": r"\d\."
    }

    print("🔍 Regex Extraction Results\n")
    for label, pattern in patterns.items():
        matches = re.findall(pattern, content)
        print(f"🔸 {label}:")
        if matches:
            for match in matches:
                print(f"   ↪ {match}")
        else:
            print("   ❌ No matches found.")
        print("")

    # Optional: add to salary data list for later use
    # salary_data.extend(re.findall(patterns["Salary Format"], content))

if __name__ == "__main__":
    extract_regex_patterns()