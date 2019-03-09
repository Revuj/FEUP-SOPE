#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    //write(STDOUT_FILENO,"1",1);
    printf("1\n"); //if there is not new-line, buffer is not cleared and, since fork copies the memory for child processes from it's parent, the "1" will be printed 2 times
    if (fork() > 0)
    {
        printf("2");
        printf("3");
        //write(STDOUT_FILENO,"2",1);
        //write(STDOUT_FILENO,"3",1);
    }
    else
    {
        printf("4");
        printf("5");
        //write(STDOUT_FILENO,"4",1);
        //write(STDOUT_FILENO,"5",1);
    }
    printf("6");
    //write(STDOUT_FILENO,"\n",1);
    return 0;
}