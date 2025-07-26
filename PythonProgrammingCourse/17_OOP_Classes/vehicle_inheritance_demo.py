"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Demonstrates single inheritance in Python            ###
###                 using Vehicle and Car classes                        ###
###                 Includes method override for maintenance behavior    ###
###  Created On   : 02-08-2025                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

# ✅ Base class representing a generic vehicle
class Vehicle:
    def __init__(self, model):
        self.model = model

    def maintenance_check(self):
        print(f"🛠️ Vehicle '{self.model}' passed general inspection.")

# ✅ Derived class: Car inherits from Vehicle and overrides method
class Car(Vehicle):
    def __init__(self, model, fuel_type):
        super().__init__(model)
        self.fuel_type = fuel_type

    def maintenance_check(self):
        print(f"🚗 Car '{self.model}' requires checkup for engine oil and tire pressure.")
        print(f"⚙️ Fuel type used: {self.fuel_type}")

def main():
    print("\n🚘 Vehicle Maintenance Demo: Inheritance with Override\n")

    # 🛻 Create a generic vehicle
    v1 = Vehicle("TransportVan-X")
    print("Calling maintenance_check() for Vehicle:")
    v1.maintenance_check()

    # 🚗 Create a specific car
    c1 = Car("Honda City", "Petrol")
    print("\nCalling maintenance_check() for Car:")
    c1.maintenance_check()

if __name__ == "__main__":
    main()