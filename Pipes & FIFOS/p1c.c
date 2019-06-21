#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

struct numbers
{
    int no1;
    int no2;
}; 

int main(void)
{
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1)
    {
        perror("Pipe Error");
        exit(1);
    }

    if ((pid = fork()) > 0)
    {
        struct numbers input;
        printf("Parent:\n");
        printf(" x y ? ");
        char * line = malloc(16 * sizeof(char));
        int n = read(STDIN_FILENO, line, 16);
        line[n] = 0;
        if (sscanf(line, "%d %d", &input.no1, &input.no2) != 2) {
            perror("Scan Error");
            exit(2);
        }
        close(fd[READ]);
        write(fd[WRITE], &input, sizeof(struct numbers));
        close(fd[WRITE]);
    }
    else
    {
        struct numbers output;
        close(fd[WRITE]);
        read(fd[READ], &output, sizeof(struct numbers));
        printf("Son:\n");
        printf("x + y = %d\n", output.no1 + output.no2);
        close(fd[READ]);
    }
    return 0;
}