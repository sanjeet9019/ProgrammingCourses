#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : LTE Log Analysis using Regular Expressions            ###
###                 Extracts RSRP/CQI values and decodes LTE message flow ###
###                 with a structured OOP approach for better readability ###
###  Date         : 03-05-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################

import re

class LTELogAnalyzer:
    """
    A class to analyze LTE log files.
    Extracts RSRP and CQI signal values, and captures LTE message flow using regex.
    """

    def __init__(self, logfile_path="LTENetworkLogs.txt"):
        self.logfile_path = logfile_path
        self.rsrp_values = []
        self.cqi_values = []
        self.msg_start = "MSG2"
        self.msg_stop = "MSG3"

    def extract_signal_values(self):
        """Extract RSRP and CQI measurements from the log file"""
        rsrp_pattern = r"RSRP = -?\d+"
        cqi_pattern = r"CQI = -?\d+"

        try:
            with open(self.logfile_path, "r") as logfile:
                for line in logfile:
                    rsrp_match = re.findall(rsrp_pattern, line)
                    cqi_match = re.findall(cqi_pattern, line)
                    if rsrp_match and cqi_match:
                        self.rsrp_values.append(rsrp_match[0])
                        self.cqi_values.append(cqi_match[0])
        except FileNotFoundError:
            print(f"❌ Log file '{self.logfile_path}' not found.")
            return

        print("\n📶 RSRP Signal Strengths:")
        print(self.rsrp_values)
        print("\n📶 CQI Values:")
        print(self.cqi_values)

    def search_lte_messages(self):
        """
        Search and print LTE messages starting from self.msg_start (e.g., 'MSG2')
        and stopping at self.msg_stop (e.g., 'MSG3')
        """
        found = False

        try:
            with open(self.logfile_path, "r") as logfile:
                for line in logfile:
                    if re.search(rf"\b{self.msg_start}\b", line):
                        found = True
                        print(f"\n🔍 Message '{self.msg_start}' found:\n")
                        print(line.strip())

                        # Continue printing lines until stop message appears
                        for next_line in logfile:
                            if self.msg_stop in next_line:
                                print("\n🛑 End of message block.\n")
                                break
                            print(next_line.strip())
                        break  # Stop after first block
        except FileNotFoundError:
            print(f"❌ Log file '{self.logfile_path}' not found.")
            return

        if not found:
            print(f"⚠️ Message '{self.msg_start}' not found in the log.")

    def run_analysis(self):
        """Run the full LTE log analysis pipeline"""
        print("\n🔧 Starting LTE Log Analysis...\n")
        self.extract_signal_values()
        self.search_lte_messages()
        print("\n✅ LTE Log Analysis Completed.\n")

# -------------------- Program Entry Point --------------------

def main():
    """
    Main entry point for LTE log analysis.
    Instantiates LTELogAnalyzer and executes analysis steps.
    """
    analyzer = LTELogAnalyzer("LTENetworkLogs.txt")
    analyzer.run_analysis()

if __name__ == "__main__":
    main()