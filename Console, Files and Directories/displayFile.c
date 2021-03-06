#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define BUFFER_SIZE 512

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd1;

    fd1 = open(argv[1], O_RDONLY);

    if (fd1 == -1) {
        perror(argv[1]);
        return 2;
    }

    char buffer[BUFFER_SIZE];

    int nr, nw;

    while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0) {
        if ((nw = write(STDOUT_FILENO, buffer, nr)) <= 0 || nr != nw) {
            perror(argv[2]);
            return 3;
        }
    }

    
    return 0;
}