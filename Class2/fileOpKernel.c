#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 512

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    int fd1, fd2;

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        perror(argv[1]);
        return 2;
    }

    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644); //não percebo o uso do O_CREAT junto do O_EXCL. Não percebo o conceito de owner, group e other
    if (fd2 == -1) {
        perror(argv[2]);
        return 3;
    } 

    int nr, nw;
    char buffer[BUFFER_SIZE];

    while((nr = read(fd1, buffer, BUFFER_SIZE)) > 0) {
        if ((nw = write(fd2, buffer, nr)) <= 0 || nw != nr) {
            perror(argv[2]);
            close(fd1);
            close(fd2);
            return 4;
        }
    }
    close(fd1);
    close(fd2);
    return 0;
}