"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : 5G NR Data Throughput Calculator (OOP Version)       ###
###                 Interactive CLI using NRThroughputCalculator class   ###
###  Date         : 03-05-2023                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import nrarfcn as NR_5G
from PIL import Image

nrthrougput = '''##################### 5G Throughput Calculation Formula ##########################
INPUT PARAMETERS =
J - NUMBER OF CC 
V - MIMO LAYERS
Qm - MODULATION ORDER
f - SCALING FACTOR 
FDD = 1 , TDD = 0.76
Rmax - CODING RATE (0.93) 
Nprb - Number of PRBs 
Ts - OFDM SYMBOL DURATION
Ts = 0.001 / (14 * SubcarrierSpacing)
OH - OVERHEAD
[0.14] FR1 DL, [0.08] FR1 UL, [0.18] FR2 DL, [0.10] FR2 UL

Total PRBs = (BW(MHz) * 1000) / SubcarrierSpacing / 12
ActualNumPRBs = Total PRBs - 4

THROUGHPUT = CCs × [MIMO × Q × f × R × ((N × 12) / Ts) × (1 - OH)] / 1,000,000
##################################################################################'''

class NRThroughputCalculator:
    def __init__(self):
        """Initialize input parameters for throughput calculation"""
        self.num_cc = 0
        self.num_mimo = 0
        self.mod_order = 0
        self.band_type = ''
        self.scaling_factor = 0.0
        self.coding_rate = 0.93
        self.numerology = 0
        self.channel_bw = 0
        self.subcarrier_spacing = 0
        self.num_prbs = 0
        self.symbol_duration = 0
        self.overhead = 0.14
        self.throughput = 0.0

    def get_subcarrier_spacing(self, numerology):
        """Return subcarrier spacing (KHz) for given numerology"""
        return 15 * (2 ** numerology)

    def get_num_prbs(self, bandwidth_mhz, subcarrier_spacing):
        """Calculate number of PRBs given bandwidth and subcarrier spacing"""
        total_prbs = (bandwidth_mhz * 1000) / subcarrier_spacing / 12
        return int(total_prbs) - 4

    def calculate_symbol_duration(self, subcarrier_spacing):
        """Calculate OFDM symbol duration based on spacing"""
        return 0.001 / (14 * subcarrier_spacing)

    def calculate_throughput(self):
        """Perform final throughput computation"""
        numerator = self.num_cc * (
            self.num_mimo * self.mod_order * self.scaling_factor * self.coding_rate *
            ((self.num_prbs * 12) / self.symbol_duration) * (1 - self.overhead)
        )
        self.throughput = numerator / 1_000_000
        return self.throughput

    def display_formula_image(self):
        """Display annotated formula image (if available)"""
        try:
            image = Image.open("NR_Throughput.jpg")
            image.show()
        except Exception as e:
            print(f"⚠️ Unable to display image: {e}")

    def display_parameters(self):
        """Print all parameters for user reference"""
        print("\n********** Input Parameters **********\n")
        print(f"NUMBER OF CC         : {self.num_cc}")
        print(f"MIMO LAYERS          : {self.num_mimo}")
        print(f"MODULATION ORDER     : {self.mod_order}")
        print(f"SCALING FACTOR       : {self.scaling_factor}")
        print(f"CODING RATE          : {self.coding_rate}")
        print(f"SUBCARRIER SPACING   : {self.subcarrier_spacing} KHz")
        print(f"CHANNEL BANDWIDTH    : {self.channel_bw} MHz")
        print(f"NUMBER OF PRBs       : {self.num_prbs}")
        print(f"SYMBOL DURATION      : {self.symbol_duration:.8f} sec")
        print(f"OVERHEAD             : {self.overhead}")
        print("\n**************************************\n")

# -------------------- Program Entry Point --------------------

def main():
    calc = NRThroughputCalculator()

    print("📡 5G NR Data Throughput Calculation\n")
    calc.display_formula_image()
    print(nrthrougput)

    calc.num_cc = int(input("ENTER NUMBER OF CC: "))
    calc.num_mimo = int(input("ENTER NUMBER OF MIMO LAYERS: "))
    calc.mod_order = int(input("ENTER MODULATION ORDER: "))
    band_type = input("ENTER BAND TYPE (FDD/TDD): ").strip().upper()
    calc.band_type = band_type
    calc.scaling_factor = 1.0 if band_type == "FDD" else 0.76

    print("\n🧮 Calculate Number of PRBs")
    calc.numerology = int(input("ENTER NR NUMEROLOGY (0–3): "))
    calc.subcarrier_spacing = calc.get_subcarrier_spacing(calc.numerology)
    calc.channel_bw = int(input("ENTER CHANNEL BANDWIDTH (MHz): "))
    calc.num_prbs = calc.get_num_prbs(calc.channel_bw, calc.subcarrier_spacing)
    calc.symbol_duration = calc.calculate_symbol_duration(calc.subcarrier_spacing)

    # Optional: choose overhead by DL/UL and FR1/FR2 dynamically (hardcoded here for simplicity)
    calc.overhead = 0.14  # Default for FR1 DL

    calc.display_parameters()

    result = calc.calculate_throughput()
    print(f"📶 Estimated 5G NR Throughput = {result:.4f} Mbps")

if __name__ == "__main__":
    main()