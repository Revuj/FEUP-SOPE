#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int increasing = 1;
int number = 0;

static void sig_usr(int signo) {
    if (signo == SIGUSR1)
        increasing = 1;
    else
        increasing = 0;
    
}
int main()
{
    int counter = 0;

    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
        fprintf(stderr, "can't catch SIGUSR1\n");
        exit(1);
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
    {
        fprintf(stderr, "can't catch SIGUSR2\n");
        exit(1);
    }

    pid_t pid;

    while(counter <= 50) {
        pid = fork();
        if (pid < 0)
        {
            fprintf(stderr, "can't fork\n");
            exit(2);
        }
        if (pid == 0)
        {
            printf("%d\n", number);
            exit(0);
        }
        else
        {
            sleep(1);
            if (increasing)
            {
                number++;
            }
            else
            {
                number--;
            }
            counter++;
            wait(NULL);
        }
    }

    exit(0);
}