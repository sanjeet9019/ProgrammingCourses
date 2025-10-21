# 💻 Linux/Unix Shell Scripting Course

Welcome to the comprehensive **Linux/Unix Shell Scripting Course** repository!

This course is meticulously designed for a broad audience, including **beginners**, **intermediate users**, those focused on **DevOps/Automation**, and anyone seeking **customized training**. It focuses on writing robust, production-quality, and highly efficient Bash and shell scripts, following professional best practices.

## Course Content Overview

The course is structured into two main sections: Core Fundamentals and Real-Time Automation Projects.

### 1. Unix_ShellScripts_Examples/ (Core Concepts)

This section contains demonstration scripts that cover every foundational and advanced concept necessary for mastering shell scripting.

| Topic | Key Concepts Covered |
| :--- | :--- |
| **Debugging** | `set -x`, `set -v`, `set -e` for execution tracing, verbosity, and error handling |
| **Variables & Arrays** | Scalar variables, special variables (`$0`, `$#`, `$$`), array definition, and iteration |
| **Operators** | Arithmetic (`$(())`), Conditional (`-eq`, `-gt`, `-lt`), Logical (`&&`, `||`), and File Test operators |
| **Control Flow** | `if/elif/else`, `case` statements, `for` loops (C-style and list-based), `while` loops, `break`, and `continue` |
| **Metacharacters** | Wildcards (`*`), Quotes (`'`, `"`), Command Substitution (`$()`), and I/O Redirection (`>`, `>>`, `<`) |
| **Functions** | Defining and calling functions, handling arguments, and capturing return status (`$?`) |
| **Text Processing** | Advanced usage of utilities like `grep`, `sed` (Stream Editor), and `awk` for complex data manipulation |

---

### 2. UnixShellRealTimeProjects/ (Automation & Utility)

This section contains production-ready scripts designed to solve common real-world problems, focusing on efficiency, robustness, and constraint-based development (e.g., no temporary files).

| Project Folder | Description | Key Features |
| :--- | :--- | :--- |
| **`clean_list_automation`** | A script designed to clean and normalize system path-like strings (e.g., `$PATH` environment variables). | **Deduplication** (preserving original order), handles both **space and colon-separated** elements, and correctly converts special colon patterns (`::`, leading/trailing `:`) to the current directory (`.`). |
| **`disk_usage_warning`** | An essential system monitoring tool to alert administrators when filesystem usage exceeds defined limits. | **Threshold-based alerts**, critical alerts at ≥ 90%, filters for `ext2/ext4` filesystems, and delivers formatted alerts via **email (`mailx`)**. |
| **`executable_file_locator`** | A custom implementation of a command resolver that mimics and extends the functionality of the built-in `which` command. | Locates executables, performs permission checks, supports special `PATH` handling, and includes the `-a` flag to list **all** matching executables. |
| **`fixing_file_dir_names`** | A utility to normalize names across a directory structure, making file names safe and consistent for cross-platform use. | **Recursively replaces spaces with dashes** (`-`) in file and/or directory names. Supports options `-f` (files only) and `-d` (directories only). |

## Getting Started

To explore the shell scripting course materials locally:

1.  **Clone the main repository:**
    ```bash
    git clone [https://github.com/sanjeet9019/ProgrammingCourses.git](https://github.com/sanjeet9019/ProgrammingCourses.git)
    ```
2.  **Navigate to the Shell course directory:**
    ```bash
    cd ProgrammingCourses/UnixShellSciptingCourse
    ```
3.  Scripts can be executed using `bash` or `./script_name.sh` after ensuring execution permissions are set (`chmod +x`).

## Contributions & Custom Training

We welcome issues or pull requests if you have suggestions, corrections, or want to contribute new content.

For **customized training** in Linux/Unix Shell Scripting or other programming topics, please connect via email: **sanjeet8.23@gmail.com**