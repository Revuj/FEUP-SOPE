#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VARIABLE_SIZE 256
#define MAX_NAME_SIZE 256

int main(int argc, char* argv[], char* envp[]) 
{
    char * variable = malloc(MAX_VARIABLE_SIZE);
    char * name = malloc(MAX_NAME_SIZE);
    name[0] = '\0';

    for (unsigned int i = 0; envp[i] != NULL; i++) {
        strcpy(variable, envp[i]);

        if (strncmp(variable, "USER=", 5) == 0) {
            if (strlen(variable) < MAX_VARIABLE_SIZE) {
                strncpy(name, variable+5, strlen(variable) - 4);
                break;
            }
        }
    }
    printf("Hello %s\n", name);
 return 0;
} 