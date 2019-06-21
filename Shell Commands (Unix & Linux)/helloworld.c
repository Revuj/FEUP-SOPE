#include <stdio.h>
#include <string.h>

#define MAX_VARIABLE_SIZE 256;
#define MAX_NAME_SIZE 256;

int main(int argc, char* argv[], char* envp[]) 
{
    char * variable = malloc(MAX_VARIABLE_SIZE);
    char * name = malloc(MAX_NAME_SIZE);

    for (unsigned int i = 0; envp[i] != NULL; i++) {
        strcpy(variable, envp[i]);

        if (strncmp(variable, "USER=", 5)) {
            strncpy(name, variable+4, strlen(variable) - 5);
            break;
        }
    }

    printf("Hello %s\n", name);
 return 0;
} 