#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define LINE_SIZE 8

struct Numbers
{
    int a;
    int b;
};

void * sumThread(void * arg) {
    struct Numbers * pair = (struct Numbers *) arg;
    void * sum = malloc(sizeof(int));
    *(int *) sum = pair->a + pair->b;
    return sum;
}

void * subThread(void * arg) {
    struct Numbers * pair = (struct Numbers *) arg;
    void * sum = malloc(sizeof(int));
    *(int *) sum = pair->a - pair->b;
    return sum;
}

void * multThread(void * arg) {
    struct Numbers * pair = (struct Numbers *) arg;
    void * sum = malloc(sizeof(int));
    *(int *) sum = pair->a * pair->b;
    return sum;
}

void * divThread(void * arg) {
    struct Numbers * pair = (struct Numbers *) arg;
    void * sum = malloc(sizeof(int));
    *(int *) sum = pair->a / pair->b;
    return sum;
}

int main()
{
    struct Numbers numbers;
    scanf("%d %d", &numbers.a, &numbers.b);
    pthread_t sumTid, subTid, multTid, divTid;

    pthread_create(&sumTid, NULL, sumThread, (void *)&numbers);
    pthread_create(&subTid, NULL, subThread, (void *)&numbers);
    pthread_create(&multTid, NULL, multThread, (void *)&numbers);
    pthread_create(&divTid, NULL, divThread, (void *)&numbers);

    void * sum;
    void * sub;
    void * mult;
    void * div;
    pthread_join(sumTid, &sum);
    pthread_join(subTid, &sub);
    pthread_join(multTid, &mult);
    pthread_join(divTid, &div);

    printf("sum = %d\n", *(int *)sum);
    printf("sum = %d\n", *(int *)sub);
    printf("sum = %d\n", *(int *)mult);
    printf("sum = %d\n", *(int *)div);

    return 0;
}