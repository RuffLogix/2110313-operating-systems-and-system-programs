#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Error : cannot fork\n");
        exit(1);
    } else if (pid == 0) {
        char* args[argc];
        for (int i = 1; i < argc; i++) {
            args[i-1] = argv[i];
        }
        args[argc-1] = (char *) 0;

        execvp(args[0], args);
    } else {
        wait(NULL);
        return 0;
    }
}