#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
    int fd;
    char *text1 = "AAAAA";
    char *text2 = "BBBBB";
    if ((fd = open("f1.txt", O_CREAT | O_EXCL | O_TRUNC | O_WRONLY | O_SYNC, 0600)) == -1)
    {
        perror("f1.txt");
        return 1;
    }

    if (write(fd, text1, 5) == -1)
    {
        perror(text1);
    }

    if (write(fd, text2, 5) == -1)
    {
        perror(text1);
    }
    
    close(fd);
    return 0;
}