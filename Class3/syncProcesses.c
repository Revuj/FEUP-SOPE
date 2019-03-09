#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    pid_t pid, pid2;

    if ((pid = fork()) < 0) {
        perror(NULL);
    }
    else if (pid > 0) {
        wait(NULL);
        write(STDOUT_FILENO, "friends!\n", 9);
    }
    else {
        if ((pid2 = fork()) < 0) {
            perror(NULL);
        }
        else if (pid2 > 0) {
            wait(NULL);
            write(STDOUT_FILENO, "my ", 3);
        }
        else {
            write(STDOUT_FILENO, "Hello ", 6);
        }
    }
    return 0;
}