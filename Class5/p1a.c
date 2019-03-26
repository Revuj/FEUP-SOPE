#include<stdio.h> 
#include<stdlib.h>
#include<unistd.h> 
#include<sys/types.h> 

#define READ 0 
#define WRITE 1

int main(void) {
    int fd[2];
    pid_t  pid;

    if (pipe(fd) == -1) {
        perror("Pipe Error");
        exit(1);
    }

    if ((pid = fork()) > 0) {
        int a[2];
        printf("Parent:\n");
        printf(" x y ? ");
        if (scanf("%d %d", &a[0], &a[1]) == EOF) {
            perror("Input Error");
            exit(2);
        }
        close(fd[READ]);
        write(fd[WRITE], a, 2 * sizeof(int));
        close(fd[WRITE]);
    }
    else {
        int b[2];
        close(fd[WRITE]);
        read(fd[READ], b, 2 * sizeof(int));
        printf("Son:\n");
        printf("x + y = %d\n", b[0] + b[1]);
        close(fd[READ]);
    }
    return 0;
}