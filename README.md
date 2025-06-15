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
   #include <stdio.h>      // For printf and scanf
#include <stdlib.h>     // For exit()
#include <unistd.h>     // For fork()
#include <sys/types.h>  // For pid_t
#include <sys/wait.h>   // For wait()

int fib[50]; // Global array to store Fibonacci sequence

int main() {
    pid_t pid;
    int n;

    // Prompt user for input
    printf("Enter the number of Fibonacci terms: ");
    scanf("%d", &n);

    if (n <= 0 || n > 50) {
        printf("Please enter a number between 1 and 50.\n");
        exit(1);
    }

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // If fork fails
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        fib[0] = 0;
        if (n > 1) fib[1] = 1;

        for (int i = 2; i < n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        // Print result
        printf("\n[Child Process] PID: %d\n", getpid());
        printf("Fibonacci Sequence: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", fib[i]);
        }
        printf("\n[Child Process] Computation complete. Exiting...\n");
        exit(0); // Exit child process
    }
    else {
        // Parent process
        wait(NULL); // Wait for child to finish
        printf("\n[Parent Process] PID: %d\n", getpid());
        printf("Child process has completed execution.\n");
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


