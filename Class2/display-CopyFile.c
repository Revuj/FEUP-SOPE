#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2 || argc != 3) {
        printf("Usage: %s <source> OR %s <source> <destination>\n", argv[0], argv[0]);
        return 1; 
    }

    int fd1;

    fd1 = open(argv[1], O_RDONLY);

    if (fd1 == -1)
    {
        perror(argv[1]);
        return 2;
    }

    if (argc == 3)
    {
        int fd2;

        fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (fd2 == -1)
        {
            perror(argv[2]);
            return 2;
        }

        if (dup2(fd2, STDOUT_FILENO) == -1)
            return 3;
    }

    int nr, nw;
    char buffer[BUFFER_SIZE];

    while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0)
    {
        if ((nw = write(STDOUT_FILENO, buffer, nr)) <= 0 || nr != nw)
        {
            perror(argv[2]);
            return 4;
        }
    }

    return 0;
}