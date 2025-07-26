"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Email        : sanjeet8.23@gmail.com                                ###
###  Description  : Demonstrates OS module operations in Python          ###
###                 Includes: current path, environment variables,       ###
###                 directory creation, file checks, renaming, deletion ###
###  Created On   : 02-08-2025                                           ###
###  Interpreter  : Python 3.11.0                                        ###
#############################################################################
"""

import os

def main():
    print("\n📌 Starting OS Module Demo")

    # ✅ Get Current Working Directory
    cwd = os.getcwd()
    print("📁 Current Working Directory:", cwd)

    # ✅ List all files and folders in current directory
    items = os.listdir()
    print("📂 Items in Directory:", items)

    # ✅ Create a new directory named 'log_output'
    try:
        os.mkdir("log_output")
        print("🆕 Created folder: log_output")
    except FileExistsError:
        print("ℹ️ Folder 'log_output' already exists")

    # ✅ Rename a file if it exists
    old_file = "sample_log.txt"
    new_file = "renamed_log.txt"
    if os.path.exists(old_file):
        os.rename(old_file, new_file)
        print(f"✏️ Renamed '{old_file}' to '{new_file}'")
    else:
        print(f"🚫 File '{old_file}' not found. Skipping rename.")

    # ✅ Show system environment variable (cross-platform user name)
    user = os.getenv("USERNAME") or os.getenv("USER")
    print("🙋 Logged-in User:", user)

    # ✅ Delete a file named 'junk.txt' if it exists
    junk_file = "junk.txt"
    if os.path.exists(junk_file):
        os.remove(junk_file)
        print("🗑️ Deleted file:", junk_file)
    else:
        print("🚫 'junk.txt' not found. Nothing to delete.")

    # ✅ Delete a folder named 'old_logs' if it exists and is empty
    folder_to_delete = "old_logs"
    if os.path.exists(folder_to_delete) and os.path.isdir(folder_to_delete):
        try:
            os.rmdir(folder_to_delete)
            print("🧹 Deleted folder:", folder_to_delete)
        except OSError:
            print(f"⚠️ Folder '{folder_to_delete}' is not empty. Skipping deletion.")
    else:
        print(f"🚫 Folder '{folder_to_delete}' not found.")

if __name__ == "__main__":
    main()