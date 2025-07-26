"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Python debugger demo using pdb module to inspect     ###
###                 variables at runtime inside conditional logic        ###
###  Created On   : 10-09-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import pdb  # Python Debugger module

def main():
    a = 10
    print("🚀 Starting the debugger demo...")

    # Conditional check to trigger debugger breakpoint
    if a == 10:
        print("🔍 Condition met: a == 10 → Invoking debugger...")
        pdb.set_trace()  # Starts the interactive debugger shell
        b = 100  # Variable b will be visible in pdb session
        c = 200  # Variable c also available during step-through

        # You can inspect variables using:
        # - p a
        # - p b
        # - p c
        # And exit with: continue or quit

        print(f"✅ Debugging complete. b = {b}, c = {c}")

if __name__ == "__main__":
    main()