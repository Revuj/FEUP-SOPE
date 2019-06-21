#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 256

int main(void)
{
 printf("Hello !\n");
 printf("What is your name my friend?\n");

 char * name = malloc(MAX_NAME_SIZE);

 fgets(name, MAX_NAME_SIZE, stdin); //fgets is better for user input that is not formatted

 if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n')) //removes trailing newline, if there
    name[strlen (name) - 1] = '\0';

printf("Hello %s\n", name);
printf("Bye\n");

 return 0;
} 