#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VARIABLE_SIZE 256
#define MAX_NAME_SIZE 256

int main(int argc, char* argv[], char* envp[]) 
{
    printf("Hello %s\n", getenv("USER"));
    return 0;
} 