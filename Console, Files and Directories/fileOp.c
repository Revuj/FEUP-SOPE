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

    FILE* f1;
    FILE* f2;

    if ((f1 = fopen(argv[1], "r")) == NULL) {
        perror(argv[1]);
        return 2;
    }

    if ((f2 = fopen(argv[2], "w+")) == NULL) {
        perror(argv[2]);
        return 3;
    }

    size_t nr;
    char line[BUFFER_SIZE];

    while ((nr = fread(line, 1, 512, f1)) > 0 ) {
        if (fwrite(line, 1, nr, f2) <= 0) {
            perror(argv[2]);
            fclose(f1);
            fclose(f2);
            return 4;
        }
    }

    fclose(f1);
    fclose(f2);
    return 0;
}