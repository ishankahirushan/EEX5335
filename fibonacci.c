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