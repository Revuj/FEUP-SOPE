#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror(NULL);
    }
    else if (pid == 0) { //child
        write(STDOUT_FILENO, "Hello ", 6);
    }
    else {
        sleep(1);
        write(STDOUT_FILENO, "World!\n", 7);
    }
    return 0;
}
