"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Description  : Display Python's reserved words using keyword module ###
###                 and explain how they're used in code syntax          ###
###  Created On   : 01-08-2025                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import keyword

def show_reserved_words():
    # List of all Python keywords
    keywords = keyword.kwlist
    print(f"🧠 Total Reserved Keywords in Python: {len(keywords)}\n")

    print("📦 Python Reserved Words:\n")
    for kw in keywords:
        print("-", kw)

    print("\n📌 Notes:")
    print("- Reserved words are special and cannot be used as variable names.")
    print("- They define the structure of Python's syntax.")
    print("- Examples include control flow (if, else), OOP (class, def), logical ops (and, or), and async (async, await)")

def test_reserved_usage():
    print("\n🧪 Code Snippets Using Reserved Words:")

    # Decision control
    age = 18
    if age >= 18:
        print("Access granted ✅")
    else:
        print("Access denied ❌")

    # Loop control
    for i in range(3):
        print("Loop iteration:", i)

    # Define a function
    def greet(name):
        print("Hello,", name)

    greet("Sanjeet")

if __name__ == "__main__":
    show_reserved_words()
    test_reserved_usage()