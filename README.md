# Fibonacci Series Generator in C using WSL2

This guide helps you set up a Linux environment on a Windows computer using **WSL2 (Windows Subsystem for Linux)** and compile a simple C program that generates the Fibonacci sequence.

---

## 🖥️ System Requirements

- **Operating System**: Windows 11 Pro (Version 24H2)
- **Linux Distribution**: Ubuntu 24.04.2 LTS via WSL2
- **Compiler**: GCC 13.4
- **Text Editor**: `nano` inside Ubuntu
- **Code Editor**: Visual Studio Code (v1.101)

---

## ⚙️ Step 1: Install WSL2 and Ubuntu

1. **Enable Required Features**
   - Open **Start Menu** → Search `Windows Features` → Open **"Turn Windows Features on or off"**.
   - Enable:
     - ✅ Windows Subsystem for Linux  
     - ✅ Virtual Machine Platform
   - Click **OK** and **Restart** your computer.

2. **Install WSL and Ubuntu**
   - Open **Windows PowerShell** and run:
     ```bash
     wsl --install
     ```
   - This command installs WSL2 and sets **Ubuntu** as the default Linux distribution.

3. **Create a Linux User**
   - Once installation completes, a terminal window will prompt you to:
     - Enter a **username**
     - Set a **password**

4. **Launch Ubuntu Terminal**
   - Open the Ubuntu terminal from the **Start Menu**. A dedicated Ubuntu terminal with a maroon interface will open.

---

## 🔧 Step 2: Initial Setup in Ubuntu

1. **Update Package Lists**
   ```bash
   sudo apt update && sudo apt upgrade
   ```

2. **Install Required Tools**
   ```bash
   sudo apt install build-essential gcc
   ```

---

## 🧾 Step 3: Write the C Program

1. **Open Terminal and Create a File**
   ```bash
   nano fibonacci.c
   ```

2. **Paste the C Code**  
   Example:
   ```c
   #include <stdio.h>

   int main() {
       int n, first = 0, second = 1, next;

       printf("Enter the number of terms: ");
       scanf("%d", &n);

       printf("Fibonacci Series: ");

       for (int i = 0; i < n; i++) {
           printf("%d ", first);
           next = first + second;
           first = second;
           second = next;
       }

       return 0;
   }
   ```

3. **Save and Exit**
   - Press `Ctrl + O` → `Enter` to save  
   - Press `Ctrl + X` to exit the editor

---

## 🛠️ Step 4: Compile the Code

```bash
gcc fibonacci.c -o fibonacci
```

If successful, an executable named `fibonacci` will be created in the same directory.

---

## ▶️ Step 5: Run the Program

```bash
./fibonacci
```

The program will prompt for the number of terms and print the corresponding Fibonacci sequence.

---

## 📁 Repository Structure

```
.
├── fibonacci.c
└── README.md
```

---

## 📌 Notes

- The Ubuntu terminal runs inside WSL2 and is fully integrated with Windows.
- You can also access your Linux files from Windows at:
  ```
  \\wsl$\Ubuntu\home\<your-username>\
  ```

---

## 📷 Sample Screenshot

> You can add screenshots of your terminal here to make it more illustrative!

---

## 📜 License

This project is licensed under the MIT License.
