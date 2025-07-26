#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : WirelessAP Decoder and Socket Broadcaster (AppA)     ###
###                 Monitors WirelessAP JSON updates and broadcasts changes ###
###  Date         : 06-10-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################

import json
import os
import time
import datetime
import shutil
import socket

class WirelessAPMonitor:
    """
    Class to monitor changes in Wireless Access Point JSON configurations
    and broadcast detected updates to another application via socket.
    """

    def __init__(self, original_file="WirelessAP_Org.json", live_file="WirelessAP.json"):
        self.original_file = original_file
        self.live_file = live_file
        self.last_modified = 0
        self.broadcast_host = "127.0.0.1"
        self.broadcast_port = 12345

    def load_json_file(self, file_path):
        """
        Loads and parses a JSON file.
        Returns parsed data or None if error occurs.
        """
        try:
            with open(file_path, "r", encoding="utf-8") as f:
                return json.load(f)
        except FileNotFoundError:
            print(f"❌ File not found: {file_path}")
        except json.JSONDecodeError as e:
            print(f"⚠️ Invalid JSON format in {file_path}: {e}")
        return None

    def backup_json_file(self):
        """
        Creates a backup snapshot of the live JSON as the reference file.
        """
        shutil.copy(self.live_file, self.original_file)
        print(f"✅ Backup created: {self.original_file}")

    def show_current_ap_details(self):
        """
        Displays the current Wireless AP details from the reference file.
        """
        print("\n📡 Current WirelessAP Details:\n")
        data = self.load_json_file(self.original_file)
        if data and "access_points" in data:
            for ap in data["access_points"]:
                print(f"SSID   : {ap['ssid']}")
                print(f"SNR    : {ap['snr']}")
                print(f"Channel: {ap['channel']}\n")

    def broadcast_message(self, message):
        """
        Sends a message via UDP socket to designated receiver.
        """
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
                print(f"\n📤 Broadcasting update:\n{message}\n")
                sock.sendto(message.encode(), (self.broadcast_host, self.broadcast_port))
                time.sleep(2)
        except Exception as e:
            print(f"⚠️ Failed to send socket message: {e}")

    def compare_and_report(self, data1, data2):
        """
        Compares two AP JSON configurations and reports any differences.
        """
        ap_list1 = data1.get("access_points", [])
        ap_list2 = data2.get("access_points", [])
        count = 1

        for ap1, ap2 in zip(ap_list1, ap_list2):
            for key in ap1:
                if key in ap2 and ap1[key] == ap2[key]:
                    print(f"✅ '{key}' unchanged for SSID '{ap1['ssid']}': {ap1[key]}")
                elif ap1["ssid"] != ap2["ssid"]:
                    message = (
                        f"{ap1['ssid']} removed from list.\n"
                        f"{ap2['ssid']} added with SNR {ap2['snr']} and channel {ap2['channel']}"
                    )
                    if count == 1:
                        self.broadcast_message(message)
                        count = 0
                else:
                    print(f"\n🔁 '{key}' changed for SSID '{ap1['ssid']}':")
                    print(f"  From: {ap1[key]}")
                    print(f"  To  : {ap2.get(key, 'Missing')}")
                    message = (
                        f"{ap1['ssid']}'s {key.upper() if key == 'snr' else key} changed "
                        f"from {ap1[key]} to {ap2.get(key)}"
                    )
                    self.broadcast_message(message)

    def monitor_changes(self):
        """
        Monitors JSON for updates and triggers comparison + broadcasting.
        """
        self.backup_json_file()

        while True:
            try:
                current_mod_time = os.path.getmtime(self.live_file)
                if current_mod_time != self.last_modified:
                    self.last_modified = current_mod_time
                    mod_datetime = datetime.datetime.fromtimestamp(current_mod_time)
                    print(f"\n🕒 JSON file updated at: {mod_datetime}")

                    data1 = self.load_json_file(self.original_file)
                    data2 = self.load_json_file(self.live_file)

                    if data1 and data2:
                        if data1 == data2:
                            print("✅ JSON files are identical.")
                        else:
                            print("⚠️ JSON files differ — processing updates.")
                            self.compare_and_report(data1, data2)
                else:
                    self.show_current_ap_details()

                time.sleep(5)

            except KeyboardInterrupt:
                choice = input("\n🔁 Ctrl+C detected. Continue monitoring? (y/n): ").lower()
                if choice == "n":
                    print("🛑 Monitoring terminated. Cleaning up...")
                    os.remove(self.original_file)
                    break
                elif choice != "y":
                    print("⚠️ Invalid input. Enter 'y' or 'n'.")

# -------------------------- Program Entry ----------------------------

def main():
    """
    Initializes and runs the WirelessAP JSON monitoring tool.
    """
    monitor = WirelessAPMonitor()
    monitor.monitor_changes()

if __name__ == "__main__":
    main()