#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX_PW_LEN 20

int main(void) {
    write(STDOUT_FILENO, "\nPassword? ", 11);

    struct termios oldTerm, newTerm;
    tcgetattr(STDOUT_FILENO, &oldTerm);
    newTerm = oldTerm;
    newTerm.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &newTerm);

    char password[MAX_PW_LEN + 1];
    char echo = '*';
    char ch;
    int i = 0;

    while (i < MAX_PW_LEN && ch != '\n' && read(STDIN_FILENO, &ch, 1)) {
        password[i++] = ch;
        write(STDOUT_FILENO, &echo, 1);
    }
    password[i] = '\0';

    tcsetattr(STDOUT_FILENO, TCSANOW, &oldTerm);

    write(STDOUT_FILENO, "\n\nPassword: ", 12);
    write(STDOUT_FILENO, password, strlen(password));
    write(STDOUT_FILENO, "\n", 1);

    return 0;
}