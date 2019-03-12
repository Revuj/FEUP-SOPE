#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h> 

int main(void)
{
    sigset_t sigset;
    sigfillset(sigset);

    if (sigprocmask(SIG_BLOCK, &sigset, NULL))
        perror("sigprocmask");

    printf("Sleeping for 30 seconds ...\n");
    sleep(30);
    printf("Waking up ...\n");
    exit(0);
}