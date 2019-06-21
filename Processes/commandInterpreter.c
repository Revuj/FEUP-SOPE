#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#define COMMAND_SIZE 512
#define MAX_COMMANDS 10

void append(char *s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}

void prompt(char command[COMMAND_SIZE]) {
    write(STDOUT_FILENO, "\nminish > ", 10);
    fgets(command, COMMAND_SIZE, stdin);
    
    for (int i = 0; i < COMMAND_SIZE; i++) {
        if (command[i] == '\n') {
            command[i] = '\0';
            return;
        }
    }
}

void get_tokens(char command[COMMAND_SIZE], char *tokens[MAX_COMMANDS]) {
    const char delim[] = " ";
    char * command_token;
    int token_counter = 0;

    command_token = strtok(command, delim);

    while (command_token != NULL) {
        tokens[token_counter++] = command_token;
        command_token = strtok(NULL, delim);
    }
}

int main() {
    char command[COMMAND_SIZE];
    char* tokens[MAX_COMMANDS];
    int pid;

    prompt(command);

    get_tokens(command, tokens);

    printf("%s", tokens[1]);

    pid = fork();

    if (pid != 0) {
        wait(NULL);
    }
    else {
        execvp(tokens[0], tokens);
    }

    return 0;
}