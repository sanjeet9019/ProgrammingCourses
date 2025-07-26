"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Demonstrates use of Python assertions for validating ###
###                 inputs and verifying logic with test cases           ###
###                 Includes value range checks and condition tests      ###
###  Created On   : 02-08-2025                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

def validate_temperature(temp_celsius):
    # ❄️ Ensure temperature is within operational range
    assert temp_celsius >= -40 and temp_celsius <= 85, "🌡️ Temperature out of range!"
    print(f"✅ Temperature {temp_celsius}°C is within safe operating limits.")

def test_kpi_accuracy(actual, expected, tolerance=0.05):
    # 📶 Assert KPI result is within acceptable deviation
    delta = abs(actual - expected)
    assert delta <= tolerance, f"📉 KPI variance too high: {delta}"
    print("✅ KPI is within tolerance:", round(delta, 3))

def validate_network_band(band):
    # 🎯 Assert that band is a supported option
    supported_bands = ["LTE", "NR", "WiFi"]
    assert band in supported_bands, f"🚫 Unsupported band: {band}"
    print(f"📡 Band '{band}' is valid and supported.")

def main():
    print("🚀 Running assertion validation demo...")

    # ✅ Input validation examples
    validate_temperature(25)
    validate_temperature(-50)  # ❌ Will raise AssertionError

    # ✅ KPI test example
    test_kpi_accuracy(actual=0.95, expected=0.97)

    # ✅ Band check
    validate_network_band("LTE")
    validate_network_band("GSM")  # ❌ Will raise AssertionError

if __name__ == "__main__":
    main()