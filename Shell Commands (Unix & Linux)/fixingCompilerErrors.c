#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LENGTH 256
#define MAX 10
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: nome_do_executável file1 file2\n");
        exit(1);
    }
    FILE *src, *dst;

    char infile[BUF_LENGTH];
    strcpy(infile, argv[0]);

    char outfile[BUF_LENGTH];
    strcpy(outfile, argv[1]);

    char buf[BUF_LENGTH];
    char error[BUF_LENGTH];
    if ((src = fopen(infile, "r")) == NULL)
    {
        strcpy(error, strerror(1));
        printf("%s\n", error);
        //perror("Infile does not exist!");
        exit(1);
    }
    if ((dst = fopen(outfile, "w")) == NULL)
    {
        strcpy(error, strerror(2));
        printf("%s\n", error);
        //perror("Outfile does not exist!");
        exit(2);
    }
    while ((fgets(buf, MAX, src)) != NULL)
    {
        fputs(buf, dst);
    }
    fclose(src);
    fclose(dst);
    exit(0); // zero é geralmente indicativo de "sucesso"
}