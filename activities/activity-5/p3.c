#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

struct Params {
    int index;
    char is_parent;
};

void* print_message(void* params) {
    struct Params p = *(struct Params*) params;
    
    char* process_level;
    if (p.is_parent) {
        process_level = "parent";
    } else {
        process_level = "child";
    }

    char* n_thread;
    if (p.index == 1) {
        n_thread = "First";
    } else {
        n_thread = "Second";
    }

    printf("%s thread from %s process\n", n_thread, process_level);
    return NULL;
}

int main() {
    pid_t pid = fork();
    struct Params params[2];
    pthread_t threads[2];
    
    if (pid == 0) {    
        params[0].is_parent = 0;
        params[1].is_parent = 0;
    } else {
        params[0].is_parent = 1;
        params[1].is_parent = 1;
    }

    for (int i = 0; i < 2; i++) {
        params[i].index = i+1;
        pthread_create(&threads[i], NULL, *print_message, &params[i]);
    }
    
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    wait(0);
    
    return 0;
}