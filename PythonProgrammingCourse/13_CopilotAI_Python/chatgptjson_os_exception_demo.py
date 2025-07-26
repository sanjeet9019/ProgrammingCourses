"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python module demonstrating ChatGPT-style handling of###
###                 JSON/XML parsing, OS file functions, and exception   ###
###                 handling with user-friendly formatting               ###
###  Created On   : 08-10-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import json
import xml.etree.ElementTree as ET
import os

# ----------------------------------------------------------------------
# 🔢 Function to print even numbers from 1 to 100
# ----------------------------------------------------------------------
def printevennumber():
    print("Even numbers from 1 to 100:")
    for number in range(1, 101):
        if number % 2 == 0:
            print(number)

# ----------------------------------------------------------------------
# 📄 Function to read JSON file and display content
# ----------------------------------------------------------------------
def readjsonfile():
    json_file_path = "sample1.json"
    try:
        with open(json_file_path, "r") as json_file:
            data = json.load(json_file)
    except FileNotFoundError:
        print("❌ FileNotFoundError: JSON file not found")
        return
    else:
        print("✅ JSON file successfully read")

    print("🧾 Parsed JSON content:")
    print("Name:", data.get("name"))
    print("Age:", data.get("age"))
    print("City:", data.get("city"))

# ----------------------------------------------------------------------
# 📜 Function to parse XML and display data elements
# ----------------------------------------------------------------------
def xmlparsing():
    xml_file_path = "samplexml.xml"
    try:
        tree = ET.parse(xml_file_path)
        root = tree.getroot()
    except FileNotFoundError:
        print("❌ FileNotFoundError: XML file not found")
        return
    print("✅ XML file parsed successfully")

    for item in root.findall('item'):
        name = item.find('name').text
        price = item.find('price').text
        print("Item Name:", name)
        print("Item Price:", price)

# ----------------------------------------------------------------------
# 📁 File handling using os module: rename, delete, mkdir, rmdir
# ----------------------------------------------------------------------
def filehandling():
    current_filename = "sample2.json"
    new_filename = "sample2.json"

    foldername = "PythonCode"

    # Uncomment below to test safely
    # os.rename(current_filename, new_filename)
    # os.remove(new_filename)
    # os.mkdir(foldername)
    os.rmdir(foldername)
    print(f"✅ Folder '{foldername}' deleted successfully")

# ----------------------------------------------------------------------
# ⚠️ Function to handle common exceptions using try/except blocks
# ----------------------------------------------------------------------
def tryandexception():
    try:
        with open("abc.txt", "r") as file:
            content = file.read()
            print("File Content:\n", content)
    except FileNotFoundError:
        print("❌ FileNotFoundError: abc.txt is missing")
    else:
        print("✅ File read without error")

    try:
        a = 10
        b = 0
        divide = a / b  # Will raise ZeroDivisionError
        print("Divide Result:", divide)
    except ZeroDivisionError:
        print("❌ ZeroDivisionError: Cannot divide by zero")
    else:
        print("✅ Division executed without error")

    print("✔️ End of try-except demonstration")

# ----------------------------------------------------------------------
# 🔧 Main execution block
# ----------------------------------------------------------------------
def main():
    # printevennumber()
    readjsonfile()
    # xmlparsing()
    # filehandling()
    # tryandexception()

if __name__ == "__main__":
    main()

# ----------------------------------------------------------------------
# 📘 Assignment Section (Preserved from Original Instruction)
# ----------------------------------------------------------------------

# 1. Read a sample PDF file and print content using ChatGPT logic
# 2. Read an HTML file and print structured content using ChatGPT
# 3. Write Python code using ChatGPT to read a file and write to Excel
# 4. Use pandas to create a report for 10 employees with ID, salary, and department
# 5. Use os module to demonstrate 10 file handling operations
# 6. Write Python code to handle exceptions for 5 real-world scenarios:
#    ➝ Divide by zero
#    ➝ File not found
#    ➝ Permission denied
#    ➝ Type mismatch
#    ➝ Invalid input format