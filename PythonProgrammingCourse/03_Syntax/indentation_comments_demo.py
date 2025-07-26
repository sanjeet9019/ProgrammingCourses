"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Description  : Demonstrates indentation and comment usage in Python ###
###                 (no loops, no conditionals, no class/functions)      ###
###  Created On   : 01-08-2025                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

# ✅ This is a single-line comment
# It describes the line of code directly below

print("🚀 Python indentation and comments demo started")  # Another inline comment

# 🧾 Multi-line comment
"""
Python uses indentation instead of braces to define code blocks.
Every line of code inside a block should be indented consistently.
Comments help explain the purpose of code to other developers or learners.
"""

def main():
    print("🧪 First statement inside main")    # Indented properly under main
    print("✅ Second statement also indented")

    # The two lines above are indented with 4 spaces
    # This follows Python’s recommended indentation style

    print("🛑 Incorrect indentation would raise an error")  # But this block is safe

# Entry point for script execution
if __name__ == "__main__":
    main()