"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : 5G NR (New Radio) Calculator                         ###
###                 Main CLI interface using menu-driven logic           ###
###                 Imports parameter functions from nr5gmodule.py       ###
###  Date         : 03-08-2025                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

from nr5gmodule import NR5GMenu
import nr5gmodule as nrmod

# ---------------------- Case Functions ----------------------

def case_one():
    arfcn = int(input("Enter NR ARFCN: "))
    freq = nrmod.get_nr_Freq_from_nr_Arfcn(arfcn)
    print(f"NR ARFCN = {arfcn} ➡ NR Frequency = {freq} MHz\n")

def case_two():
    freq = int(input("Enter NR Frequency (MHz): "))
    arfcn = nrmod.get_nr_Arfcn_from_nr_Freq(freq)
    print(f"NR Frequency = {freq} MHz ➡ NR ARFCN = {arfcn}\n")

def case_three():
    freq = int(input("Enter NR Frequency (MHz): "))
    bandlist = nrmod.get_nr_Bands_from_nr_Freq(freq)
    print(f"NR Frequency = {freq} MHz ➡ Band List = {bandlist}\n")

def case_four():
    arfcn = int(input("Enter NR ARFCN: "))
    bandlist = nrmod.get_nr_Bands_from_nr_Arfcn(arfcn)
    print(f"NR ARFCN = {arfcn} ➡ Band List = {bandlist}\n")

def case_five():
    band = input("Enter NR Band (e.g., n78): ")
    duplex = nrmod.get_duplex_mode_from_nr_Band(band)
    print(f"NR Band = {band} ➡ Duplex Type = {duplex}\n")

def case_six():
    band = input("Enter NR Band: ")
    direction = input("Enter Direction (ul/dl): ").lower()
    arfcn_range = nrmod.get_nr_ArfcnRange_from_nr_Band(band, direction)
    print(f"NR Band = {band} ➡ ARFCN Range = {arfcn_range}\n")

def case_seven():
    band = input("Enter NR Band: ")
    direction = input("Enter Direction (ul/dl): ").lower()
    freq_range = nrmod.get_nr_Freqrange_from_nr_Band(band, direction)
    print(f"NR Band = {band} ➡ Frequency Range = {freq_range} MHz\n")

def case_eight():
    gscn = int(input("Enter NR GSCN (0–26639): "))
    freq = nrmod.get_nr_Freq_from_nr_GSCN(gscn)
    print(f"GSCN = {gscn} ➡ NR Frequency = {freq} MHz\n")

def case_nine():
    freq = int(input("Enter NR Frequency (MHz): "))
    gscn = nrmod.get_nr_GSCN_from_nr_Freq(freq)
    print(f"NR Frequency = {freq} MHz ➡ GSCN = {gscn}\n")

def case_ten():
    band = input("Enter NR Band: ")
    gscn_range = nrmod.get_nr_GSCNRange_from_nr_Band(band)
    print(f"NR Band = {band} ➡ GSCN Range = {gscn_range}\n")

def case_eleven():
    numerology = int(input("Enter Numerology (0–3): "))
    spacing = nrmod.get_NRsubcarrier_spacing_from_numerology(numerology)
    print(f"Numerology = {numerology} ➡ Subcarrier Spacing = {spacing} KHz\n")

def case_twelve():
    numerology = int(input("Enter Numerology (0–4): "))
    spacing = nrmod.get_NRsubcarrier_spacing_from_numerology(numerology)
    bandwidth = int(input("Enter Channel Bandwidth (MHz): "))
    prbs = nrmod.get_nr_NumberOfPRBs(bandwidth, spacing)
    print(f"Bandwidth = {bandwidth} MHz ➡ Number of PRBs = {prbs}\n")

def case_default():
    print("❌ Invalid choice. Please enter a number between 1 and 12.\n")

# ---------------------- Menu Dispatcher ----------------------

switcher = {
    NR5GMenu.ARFCN_TO_FREQ: case_one,
    NR5GMenu.FREQ_TO_ARFCN: case_two,
    NR5GMenu.FREQ_TO_BANDLIST: case_three,
    NR5GMenu.ARFCN_TO_BANDLIST: case_four,
    NR5GMenu.BAND_TO_DUPLEX: case_five,
    NR5GMenu.BAND_TO_ARFCN_RANGE: case_six,
    NR5GMenu.BAND_TO_FREQ_RANGE: case_seven,
    NR5GMenu.GSCN_TO_FREQ: case_eight,
    NR5GMenu.FREQ_TO_GSCN: case_nine,
    NR5GMenu.BAND_TO_GSCN_RANGE: case_ten,
    NR5GMenu.NUMEROLOGY_TO_SCS: case_eleven,
    NR5GMenu.PRB_CALCULATION: case_twelve
}

# ---------------------- Main Calculator Loop ----------------------

def nr5GCalculator():
    menu = '''
==============================================================
                  📡 5G NR CALCULATOR MENU
==============================================================
 1. ARFCN ➡ Frequency
 2. Frequency ➡ ARFCN
 3. Frequency ➡ Band List
 4. ARFCN ➡ Band List
 5. Band ➡ Duplex Type
 6. Band ➡ ARFCN Range
 7. Band ➡ Frequency Range
 8. GSCN ➡ Frequency
 9. Frequency ➡ GSCN
10. Band ➡ GSCN Range
11. Numerology ➡ Subcarrier Spacing
12. PRB Calculation (Numerology + Bandwidth)
==============================================================
    '''
    while True:
        print(menu)
        try:
            choice = int(input("Select an option (1–12): "))
            func = switcher.get(NR5GMenu(choice), case_default)
            func()
        except (ValueError, KeyError):
            case_default()

        again = input("🔄 Do you want to continue? (y/n): ").lower()
        if again != "y":
            print("✅ Exiting 5G NR Calculator. Goodbye!\n")
            break

# ---------------------- Program Entry Point ----------------------

def main():
    print("\n🧮 Welcome to the 5G NR Calculator\n")
    nr5GCalculator()

if __name__ == "__main__":
    main()