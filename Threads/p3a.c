#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 10

void *PrintHello(void *threadnum)
{
    printf("Hello from thread no. %d!\n", *(int *)threadnum);
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[NUM_THREADS];
    int args[NUM_THREADS];
    int t;
    for (t = 0; t < NUM_THREADS; t++)
    {
        args[t] = t;
        printf("Creating thread %d\n", t);
        pthread_create(&threads[t], NULL, PrintHello, &args[t]);
    }
    pthread_exit(0); //exit não garante que a outra thread acabe
}