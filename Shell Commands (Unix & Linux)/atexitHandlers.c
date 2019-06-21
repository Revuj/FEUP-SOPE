#include <stdlib.h>
#include <stdio.h>

static void handler1(void) {
    printf("Executing exit handler 1\n");
}

static void handler2(void) { //este handler vai ser executado primeiro, porque o atexit trata das funções como se estivessem numa stack
    printf("Executing exit handler 2\n");
    exit(1); //mesmo existindo um exit, o programa prossegue normalmente
}

int main(void) {
    atexit(handler1);
    atexit(handler2);
    atexit(handler1);
    //abort(); com abort sai antes de chamar as funções atexit
    printf("Main done!\n"); //os handlers só são chamados depois deste printf
    return 0;
}

