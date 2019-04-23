#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2
#define NUMITER 10000
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

int N = 5000;

void *thrfunc(void *arg)
{
    int i = 0;
    fprintf(stderr, "Starting thread %s\n", (char *)arg);
    while (N > 0) {
        pthread_mutex_lock(&mut);
        i++;
        N--;
        pthread_mutex_unlock(&mut);
    }
    void * ret = malloc(sizeof(int));
    *(int *) ret = i;
    return ret;
}
int main()
{
    pthread_t ta, tb;
    char arg = '1';
    pthread_create(&ta, NULL, thrfunc, &arg);
    char arg2 = '2';
    pthread_create(&tb, NULL, thrfunc, &arg2);
    void * reta;
    void * retb;
    pthread_join(ta, &reta);
    pthread_join(tb, &retb);
    printf("T1 = %d\n", *(int *)reta);
    printf("T2 = %d\n", *(int *)retb);
    printf("RESULT = %d\n", *(int *)reta + *(int *)retb);
    return 0;
}