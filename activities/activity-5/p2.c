#include <stdio.h>
#include <pthread.h>

void* show_id(void* id) {
    int tid = *(int*) id;
    printf("This is thread %d\n", tid);
    return NULL;
}

int main() {
    pthread_t threads[10];
    int idx[10];

    for (int i = 0; i < 10; i++) {
        idx[i] = i+1;
        pthread_create(&threads[i], NULL, *show_id, &idx[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}