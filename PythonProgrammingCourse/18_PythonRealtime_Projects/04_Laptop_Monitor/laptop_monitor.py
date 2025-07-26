#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Laptop Monitoring Tool – HDD, CPU, Network, Files     ###
###                 Real-time system insights using psutil, ping, speedtest ###
###  Date         : 21-10-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################

import socket
import psutil
import os
import time
from ping3 import ping
import speedtest
import platform

class LaptopMonitor:
    """
    A monitoring utility to track disk, CPU, network, and file status on a local PC.
    """

    def __init__(self):
        self.folder_path = r"C:\Users\sanprasa\Desktop\python\PyProject"
        self.ping_host = "google.com"

    def monitor_disk_space(self):
        """Monitor and display HDD usage stats"""
        print("\n🖴 Monitoring HDD Space\n")
        disk_usage = psutil.disk_usage('/')
        bytestoGB = 1024 ** 3
        print(f"Total Disk Space   : {disk_usage.total / bytestoGB:.2f} GB")
        print(f"Used Disk Space    : {disk_usage.used / bytestoGB:.2f} GB")
        print(f"Free Disk Space    : {disk_usage.free / bytestoGB:.2f} GB")
        print(f"Usage Percentage   : {disk_usage.percent}%")

    def monitor_files(self):
        """List all files in given folder path with size"""
        print("\n📁 Monitoring Files\n")
        if not os.path.exists(self.folder_path):
            print(f"❌ Folder not found: {self.folder_path}")
            return
        for root, _, files in os.walk(self.folder_path):
            for file in files:
                file_path = os.path.join(root, file)
                try:
                    size = os.path.getsize(file_path)
                    print(f"File: {file_path}, Size: {size} bytes")
                except Exception as e:
                    print(f"⚠️ Error accessing {file}: {e}")

    def monitor_network_usage(self):
        """Display NIC network IO stats"""
        print("\n🌐 Monitoring Network Activity\n")
        stats = psutil.net_io_counters()
        print(f"Bytes Sent        : {stats.bytes_sent}")
        print(f"Bytes Received    : {stats.bytes_recv}")
        print(f"Packets Sent      : {stats.packets_sent}")
        print(f"Packets Received  : {stats.packets_recv}")

    def monitor_active_interfaces(self):
        """Check active NIC interfaces and their attributes"""
        print("\n🧭 Monitoring Active Network Interfaces\n")
        stats = psutil.net_if_stats()
        active = [name for name, s in stats.items() if s.isup]
        for name in active:
            iface = stats[name]
            print(f"Interface: {name}, Speed: {iface.speed} Mbps, MTU: {iface.mtu}")
        print(f"Active Interfaces: {active}")

    def monitor_network_latency(self):
        """Ping a host and measure latency"""
        print("\n📶 Monitoring Network Latency\n")
        try:
            latency = ping(self.ping_host)
            print(f"Ping to {self.ping_host}: {latency:.2f} ms")
        except Exception as e:
            print(f"⚠️ Ping failed: {e}")

    def monitor_cpu_usage(self):
        """Display CPU model and usage stats"""
        print("\n🧠 Monitoring CPU Usage\n")
        model = platform.processor()
        usage = psutil.cpu_percent(interval=1)
        print(f"CPU Model : {model}")
        print(f"CPU Usage : {usage}%")

    def monitor_processes(self):
        """List user-level processes excluding system services"""
        print("\n⚙️ Monitoring Processes\n")
        excluded = {
            "svchost.exe", "services.exe", "lsass.exe", "csrss.exe", "smss.exe",
            "wininit.exe", "fontdrvhost.exe", "conhost.exe", "WUDFHost.exe",
            "msedge.exe", "IntelCpHDCPSvc.exe"
        }
        for proc in psutil.process_iter(['name']):
            try:
                name = proc.info['name']
                if name not in excluded:
                    print(f"Process: {name}")
            except (psutil.NoSuchProcess, psutil.AccessDenied):
                continue

    def monitor_speed_test(self):
        """Check internet upload and download speed"""
        print("\n⏱️ Monitoring Download & Upload Speed\n")
        print("Running speed test… please wait.\n")
        try:
            st = speedtest.Speedtest()
            st.get_best_server()
            down = st.download() / 1_000_000
            up = st.upload() / 1_000_000
            print(f"Download Speed : {down:.2f} Mbps")
            print(f"Upload Speed   : {up:.2f} Mbps")
        except Exception as e:
            print(f"⚠️ Speed test failed: {e}")

    def run_all(self):
        """Execute all monitoring functions in loop"""
        print("\n🖥️ Laptop Monitoring Tool — Real-time Stats\n")
        while True:
            self.monitor_disk_space()
            self.monitor_files()
            self.monitor_network_usage()
            self.monitor_network_latency()
            self.monitor_speed_test()
            self.monitor_cpu_usage()
            self.monitor_processes()
            self.monitor_active_interfaces()
            try:
                time.sleep(10)
            except KeyboardInterrupt:
                choice = input("\n🔁 Ctrl+C detected. Continue monitoring? (y/n): ").lower()
                if choice == 'n':
                    print("🚫 Monitoring stopped.")
                    break
                elif choice != 'y':
                    print("⚠️ Invalid input. Type 'y' to continue or 'n' to exit.")

# ----------------------- Main Entry -----------------------
def main():
    monitor = LaptopMonitor()
    monitor.run_all()

if __name__ == "__main__":
    main()