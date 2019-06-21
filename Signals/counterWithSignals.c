#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int increasing = 1;

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
    while (1)
    {
        if (increasing)
        {
            counter++;
        }
        else
        {
            counter--;
        }

        sleep(1);
        printf("%d\n", counter);
    }
}