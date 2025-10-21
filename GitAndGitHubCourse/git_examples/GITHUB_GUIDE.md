# 🚀 Git & GitHub Setup Guide: Creating Your First Repository

This guide walks you through the essential first steps of using Git: **creating a remote repository on GitHub** and **linking it to your local project files** (`add.c`, `multiply.c`, `sub.c`).

---

## Part 1: Creating the Remote Repository on GitHub 🌐

This process establishes the online storage (the *remote*) for your project's version history.

### Step 1: Start a New Repository

1.  Log into your **GitHub** account.
2.  Click the **'+' icon** in the top right corner and select **"New repository."**

### Step 2: Configure Details

Fill in the necessary details, ensuring you create a truly empty repository:

* **Repository name:** Use a descriptive name (e.g., `Git-Calculator-Demo`).
* **Visibility:** Choose **Public** (or Private if preferred).
* **Initializers:** **DO NOT** check any boxes for adding a README, .gitignore, or license.

### Step 3: Copy the Remote URL

After clicking **"Create repository,"** you will see a setup page.

* Locate the section titled **"or push an existing repository from the command line."**
* Copy the **HTTPS URL** provided (e.g., `https://github.com/sanjeet9019/Git-Calculator-Demo.git`).

---

## Part 2: Local System Setup and Initial Push 💻

These steps initialize Git locally, commit your files, and link your local history to the remote repository on GitHub.

### Setup (Initialize Git)

1.  **Navigate to the Project Folder:** Open your **Git Bash** terminal and move into the directory containing your C files (`add.c`, `multiply.c`, etc.).

    ```bash
    cd GitAndGitHubCourse/git_examples/
    ```

2.  **Initialize Local Repository:** This command creates the hidden `.git` directory, turning the folder into a Git repository.

    ```bash
    git init
    ```

### Stage and Commit (Create Local History)

3.  **Stage All Files:** The `git add .` command moves all files from your Working Directory to the Staging Area.

    ```bash
    git add .
    ```

4.  **Create the Initial Commit:** This permanently records the staged snapshot into your local Git history.

    ```bash
    git commit -m "Initial commit: Add calculator files (add.c, multiply.c, sub.c)"
    ```

### Connect and Push (Link to GitHub)

5.  **Connect Local to Remote:** Use the URL copied in Part 1 to establish a link to GitHub, naming the remote connection `origin`.

    ```bash
    git remote add origin <PASTE_YOUR_HTTPS_URL_HERE>
    ```

6.  **Push the Code:** Push your local `master` (or `main`) branch up to the remote repository (`origin`). The `-u` flag sets up tracking for future pushes.

    ```bash
    # Use 'master' or 'main' depending on your default branch name
    git push -u origin master
    # OR
    # git push -u origin main
    ```

After entering your GitHub credentials (username and Personal Access Token), your files will appear on GitHub, and your setup is complete!