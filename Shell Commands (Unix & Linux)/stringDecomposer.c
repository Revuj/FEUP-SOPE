#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_SIZE 256

int main(void) {
    char * command = malloc(MAX_COMMAND_SIZE);
    char input[2][10];

    fgets(command, MAX_COMMAND_SIZE, stdin);

    char * line = malloc(MAX_COMMAND_SIZE);
    strcpy(line, command);

    command = strtok(command, " "); //command guarda a primeira palavra da string

    int i = 0;

    while(command != NULL) {
        printf("%s\n", command);
        strcpy(input[i], command);
        command = strtok(NULL, " "); //command guarda as sucessivas palavras delimitadas por " " (NULL porque command já apontar para o char correto)
        i++;
    }

    for (unsigned int i = 0; i < 2; i++) {
        printf("%s\n", input[i]);
    }

    system(line);
}