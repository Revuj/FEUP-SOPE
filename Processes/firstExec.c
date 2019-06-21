#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char prog[20];
    sprintf(prog, "%s.c", argv[1]);
    execlp("gcc","gcc",prog,"-Wall","-o",argv[1],NULL); //compiles a program
    printf("This is useless"); //after exec calls, all the code is substituted with the program to be executed
    exit(50); //useless
}