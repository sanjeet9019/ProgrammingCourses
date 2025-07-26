#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : 5G NR Band Support & Combination Analyzer (OOP Based) ###
###                 Parses UE Capability logs for supported bands & combos ###
###  Date         : 03-05-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################

import re

class NRLogAnalyzer:
    """
    Analyzes UE NR capability logs for supported bands and band combinations.
    """

    def __init__(self, logfile_path="UECapabilityInfo.txt"):
        self.logfile_path = logfile_path
        self.supported_band_list = []
        self.band_combinations = []

    def extract_supported_bands(self):
        """Extracts NR band identifiers from UE Capability log"""
        band_pattern = r"bandNR: \d+"

        try:
            with open(self.logfile_path, "r") as file:
                for line in file:
                    bands = re.findall(band_pattern, line)
                    if bands:
                        self.supported_band_list.append(bands[0])
                    if "supportedBandCombinationList" in line:
                        break
        except FileNotFoundError:
            print(f"❌ Log file '{self.logfile_path}' not found.")
            return

        print("\n📶 NR UE Capability – Supported Band List:")
        print(self.supported_band_list)

    def extract_band_combinations(self):
        """Extracts NR band combinations (CA pairs/groups) from UE logs"""
        band_pattern = r"bandNR: \d+"
        current_combo = []

        try:
            with open(self.logfile_path, "r") as file:
                for line in file:
                    if "supportedBandCombinationList" in line:
                        for line in file:
                            bands = re.findall(band_pattern, line)
                            if bands:
                                current_combo.append(bands[0])

                            if "featureSetCombination" in line:
                                if current_combo:
                                    self.band_combinations.append(current_combo)
                                    current_combo = []

                            if "appliedFreqBandListFilter" in line:
                                break
                        break
        except FileNotFoundError:
            print(f"❌ Log file '{self.logfile_path}' not found.")
            return

        print("\n🔗 NR UE Capability – Band Combinations:")
        for combo in self.band_combinations:
            print(combo)

    def run_analysis(self):
        """Runs the complete 5G NR band support analysis"""
        print("\n🚀 Starting 5G NR Capability Analysis...\n")
        self.extract_supported_bands()
        self.extract_band_combinations()
        print("\n✅ NR Log Analysis Complete.\n")

# -------------------- Program Entry Point --------------------

def main():
    """
    Main function for executing 5G NR band analysis.
    """
    analyzer = NRLogAnalyzer()
    analyzer.run_analysis()

if __name__ == "__main__":
    main()