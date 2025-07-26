"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Demonstrates encapsulation via BankAccount class     ###
###                 Shows public balance access and private pin handling ###
###  Created On   : 02-08-2025                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

class BankAccount:
    def __init__(self, owner, balance, pin):
        self.owner = owner            # Public
        self.balance = balance        # Public
        self.__pin = pin              # Private

    def show_balance(self):
        print(f"💰 Account holder: {self.owner}")
        print(f"🔢 Current balance: ₹{self.balance}")

    def withdraw(self, amount, input_pin):
        # Validate pin before allowing withdrawal
        if input_pin == self.__pin:
            if amount <= self.balance:
                self.balance -= amount
                print(f"✅ Withdrawal of ₹{amount} successful.")
            else:
                print("❌ Insufficient balance.")
        else:
            print("🚫 Incorrect PIN. Access denied.")

def main():
    print("\n🏦 Encapsulation Demo: BankAccount\n")

    # Create account instance
    account = BankAccount("Ravi Kumar", 5000, "1234")

    # Public method access
    account.show_balance()

    # Attempt withdrawal with correct PIN
    account.withdraw(1200, "1234")
    account.show_balance()

    # Attempt withdrawal with wrong PIN
    account.withdraw(500, "0000")

    # ❌ Direct access to private attribute (fails)
    try:
        print("🔐 Accessing private __pin directly:", account.__pin)
    except AttributeError as e:
        print("❌ Cannot access __pin:", e)

    # 🔓 Access using name mangling (not recommended)
    print("⚠️ Access via name mangling:", account._BankAccount__pin)

if __name__ == "__main__":
    main()