#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


void execLs(char * argv[]) {
    pid_t pid = fork();
    
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
}

void execAndWriteLs(char * argv[]) {
    pid_t pid = fork();
    
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
        int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (fd == -1) {
            perror(argv[2]);
            exit(1);
        }

        if (dup2(fd, STDOUT_FILENO) == -1) {
            exit(1);
        }

        execlp("ls", "ls", "-laR", argv[1], NULL);
        printf("Command not executed !\n");
        exit(1);
    }
}





int main(int argc, char *argv[], char *envp[])
{
    if (argc == 2)
        execLs(argv);
    else if (argc == 3)
        execAndWriteLs(argv);
    else {
       printf("usage: %s dirname\n", argv[0]);
        exit(1); 
    }

    exit(0);
}