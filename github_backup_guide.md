# 🔐 Backup Your Code to GitHub (Daily Workflow)

This guide helps you back up your DSA and Web Development code to GitHub every day to avoid accidental loss.

---

## ✅ Step 1: Organize Your Code Locally

Organize your code files in a proper directory:

```
/Code
  ├── /DSA
  │     ├── day1.cpp
  │     ├── day2.cpp
  ├── /WebDev
        ├── index.html
        ├── app.js
```

Place this folder somewhere safe like `Documents`, not `Downloads`.

---

## ✅ Step 2: Create a GitHub Repository

1. Go to [https://github.com](https://github.com)
2. Click on **New Repository**
3. Name it something like `my-learning-code`
4. Choose **Public** or **Private**
5. Click **Create Repository**

---

## ✅ Step 3: Initialize Git Locally (One-Time Setup)

Open Terminal and run:

```bash
cd ~/Documents/Code  # Adjust the path if needed
git init
git remote add origin https://github.com/YOUR_USERNAME/my-learning-code.git
```

---

## ✅ Step 4: Daily Commit & Push
---

### 🔁 Step 4 Detailed Explanation: Daily Commit & Push

Every day, after finishing your coding tasks, follow these steps to safely update your code to GitHub:

#### ✅ 1. Change Directory
```bash
cd ~/Documents/Code
```
This moves you into the folder where your code is stored. Adjust the path if your folder is located elsewhere.

#### ✅ 2. Track All Files
```bash
git add .
```
This tells Git to track **all new and changed files** in the current folder and subfolders. The `.` means “everything here”.

#### ✅ 3. Commit Your Changes
```bash
git commit -m "Daily backup - $(Date)"
```
This takes a **snapshot** of your current code and saves it with a message so you can understand what was changed later.

#### ✅ 4. Push to GitHub
```bash
git push origin master
```
This sends all the committed changes to your GitHub repository. If your default branch is `main`, use:
```bash
git push origin main
```

Once you run this, your code will be safely stored in your GitHub repository.

---


Every day after coding, run the following:

```bash
cd ~/Documents/Code  # Go to your code folder
git add .            # Track all changes
git commit -m "Daily backup - $(Date)"  # Save a snapshot
git push origin master  # Push to GitHub (use 'main' if that's your branch)
```

---

## ✅ Optional: Use .gitignore

To ignore unnecessary files, create a `.gitignore` file with:

```
.DS_Store
node_modules/
```

---

## ✅ Optional: Automation Script

You can create a simple shell script `backup.sh`:

```bash
#!/bin/bash
cd ~/Documents/Code
git add .
git commit -m "Auto backup on $(date '+%Y-%m-%d')"
git push origin master
```

Make it executable:

```bash
chmod +x backup.sh
```

Now just run `./backup.sh` daily.

---

Happy coding! 🚀
