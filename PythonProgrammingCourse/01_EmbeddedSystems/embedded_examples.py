"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : System-level embedded diagnostics using Python       ###
###                 Includes battery status, folder size, network ping,  ###
###                 and serial port listing                              ###
###  Created On   : 02-08-2025                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import os

# ✅ Battery Status Monitor
def check_battery():
    try:
        import psutil
        battery = psutil.sensors_battery()
        print("\n🔋 Battery Status")
        print("Charge:", battery.percent, "%")
        print("Plugged In:", battery.power_plugged)
    except Exception:
        print("\n⚠️ Battery information not available on this system.")

# ✅ Directory Size Analyzer
def check_directory_size(path="."):
    total_bytes = 0
    for root, _, files in os.walk(path):
        for file in files:
            try:
                fp = os.path.join(root, file)
                total_bytes += os.path.getsize(fp)
            except FileNotFoundError:
                continue
    print(f"\n📁 Folder Size → '{path}': {round(total_bytes / 1024, 2)} KB")

# ✅ Ping a Device/IP
def ping_device(ip="8.8.8.8"):
    print(f"\n🌐 Pinging {ip}...")
    cmd = f"ping -n 1 {ip}" if os.name == "nt" else f"ping -c 1 {ip}"
    result = os.system(cmd)
    print("✅ Reachable" if result == 0 else "❌ Unreachable")

# ✅ Serial Port Availability
def list_serial_ports():
    try:
        import serial.tools.list_ports
        ports = serial.tools.list_ports.comports()
        print("\n📟 Available Serial Ports:")
        if not ports:
            print("No ports detected.")
        for port in ports:
            print(f"- {port.device}: {port.description}")
    except Exception:
        print("\n⚠️ pyserial not installed or unavailable.")

# 🚀 Main Execution
def main():
    print("\n📡 SYSTEM CHECKS (Python Embedded Tools)")
    check_battery()
    check_directory_size()
    ping_device()
    list_serial_ports()

if __name__ == "__main__":
    main()