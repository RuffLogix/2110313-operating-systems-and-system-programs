#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("I am the child process. My PID is %d and my parent\'s PID is %d\n", getpid(), getppid());
        pid = fork();

        if (pid == 0) {
            printf("I am the grandchild process. My PID is %d and my parent\'s PID is %d\n", getpid(), getppid()); 
        }
    } else {
        printf("I am the parent process. My PID is %d\n", getpid());
    }
}