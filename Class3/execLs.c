#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    if (argc != 2)
    {
        printf("usage: %s dirname\n", argv[0]);
        exit(1);
    }
    pid = fork();
    if (pid > 0) {
        int status;
        int childpid;
        printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);
        childpid = wait(&status);
        childpid = wait(&status); /* wait for the child to terminate */
        printf("A child w/pid %d terminated w/EXIT CODE %d\n", childpid, WEXITSTATUS(status));

        if (WIFEXITED(status))
            printf("Child terminated normally\n");
        else if (WIFSIGNALED(status))
            printf("Child terminated abnormally\n");
    }
    else if (pid == 0)
    {
        execlp("ls", "ls", "-laR", argv[1], NULL);
        printf("Command not executed !\n");
        exit(1);
    }
    exit(0);
}