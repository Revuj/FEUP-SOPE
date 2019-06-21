#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int NUM_THREADS = 5000;

void * thread(void * arg) {
    sleep(1);
    printf("TID = %ld\n", pthread_self());
    return arg;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int args[NUM_THREADS];

    while (NUM_THREADS-- > 0) {
        args[NUM_THREADS] = NUM_THREADS;
        pthread_create(&threads[NUM_THREADS], NULL, thread, &args[NUM_THREADS]);
    }

    while (NUM_THREADS++ < 5000) {
        void * ret;
        pthread_join(threads[NUM_THREADS], &ret);
        printf("Return value = %d\n", *(int *)ret);
    }
    pthread_exit(0);
}
