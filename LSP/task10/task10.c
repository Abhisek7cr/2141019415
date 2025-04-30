#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Create a child process using fork()
    pid = fork();

    if (pid == -1) {
        // Error occurred during fork
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing 'ls' command...\n", getpid());

        // Execute 'ls' command using execvp()
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args); // Replaces child process with 'ls' command

        // If execvp() fails, it returns -1, and we print an error
        perror("execvp failed");
        exit(1);
    }
    else {
        // Parent process
        printf("Parent process (PID: %d) created child process (PID: %d)\n", getpid(), pid);

        // Wait for the child process to complete
        wait(NULL);  // Waits for child process to terminate

        // Print a message after child process terminates
        printf("Child process terminated. Parent process (PID: %d) resumes.\n", getpid());
    }

    return 0;
}
