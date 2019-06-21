#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <inttypes.h>

int main(int argc, char *argv[])
{
    DIR *dirp;
    struct dirent *direntp;
    struct stat stat_buf;
    char *str;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s dir_name\n", argv[0]);
        exit(1);
    }
    if ((dirp = opendir(argv[1])) == NULL)
    {
        perror(argv[1]);
        exit(2);
    }
    while ((direntp = readdir(dirp)) != NULL)
    {
        if (stat(direntp->d_name, &stat_buf) == -1) {
            perror(direntp->d_name);
        }
        if (S_ISREG(stat_buf.st_mode))
            str = "regular";
        else if (S_ISDIR(stat_buf.st_mode))
            str = "directory";
        else
            str = "other";
        printf("%-25s - %s; i-node - %ju;   size - %ju\n", direntp->d_name, str, (uintmax_t)direntp->d_ino, (uintmax_t)stat_buf.st_size);
        //symbolic links (pointer to file name) use less space than original file or hard link: this can only be verified using lstat instead of stat, because the first gives us info about symbolic links
        //file and its hard link have same i-node, the same cant be said for the symbolic link
        //with the symbolic link file, after we erase (or name change) the original file, the symbolic link file cannot be found anymore because its nothing but a pointer to the name of the original file
        //on the other hand, after the original file is deletes, the hard link file keeps its content
    }
    closedir(dirp);
    exit(0);
}