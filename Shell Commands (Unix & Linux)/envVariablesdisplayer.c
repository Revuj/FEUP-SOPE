#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 256

int main(int argc, char* argv[], char* envp[]) 
{
    for (unsigned int i = 0; envp[i] != NULL; i++) {
        printf("%s\n", envp[i]);
    }
 return 0;
} 
