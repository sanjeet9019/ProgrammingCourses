"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Safely demonstrates binary file read/write in Python ###
###                 Creates binary file, writes bytes, then reads them   ###
###                 Shows use of 'rb' and 'wb' modes + error handling    ###
###  Created On   : 02-08-2025                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

def write_binary_file(filename="sample_binary.dat"):
    # 📦 Create some raw binary content
    data = bytes([120, 3, 255, 0, 100])  # Binary values (0–255)

    try:
        with open(filename, "wb") as f:
            f.write(data)
        print(f"✅ Binary data written to {filename}")
    except Exception as e:
        print(f"❌ Error writing binary file: {e}")

def read_binary_file(filename="sample_binary.dat"):
    try:
        with open(filename, "rb") as f:
            content = f.read()
        print(f"\n🔍 Reading from {filename}")
        print("📂 Raw Bytes:", content)
        print("🔢 Integers:", list(content))  # Converted for clarity
    except FileNotFoundError:
        print(f"⚠️ File '{filename}' not found.")
    except Exception as e:
        print(f"❌ Error reading binary file: {e}")

def main():
    print("🚀 Starting binary file demo")
    write_binary_file()
    read_binary_file()

if __name__ == "__main__":
    main()