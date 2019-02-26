#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define MAX_NAME_LEN 20
#define MAX_GRADE_LEN 2

void writeToFile(int fd, char * student, char * grade) {
    char endl = '\n';
    write(fd, student, strlen(student));
    write(fd, &endl, 1);
    write(fd, grade, strlen(grade));
    write(fd, &endl, 1);
}

int readStudent(int fd) {
    char student[MAX_NAME_LEN + 1];
    char grade[MAX_GRADE_LEN + 1];

    write(STDOUT_FILENO, "Name: ", 6);
    char ch;
    int i = 0;
    read(STDIN_FILENO, &ch, 1);
    if (ch == '\n') {
        return 1;
    }
    while( ch != '\n') {
        student[i++] = ch;
        read(STDIN_FILENO, &ch, 1);
    }
    student[i] = '\0';

    write(STDOUT_FILENO, "Grade: ", 7);
    i = 0;
    read(STDIN_FILENO, &ch, 1);
    while( ch != '\n') {
        grade[i++] = ch;
        read(STDIN_FILENO, &ch, 1);
    }
    grade[i] = '\0';

    writeToFile(fd, student, grade);
    return 0;
}

int main(int argc, char** argv) {
    
    if (argc != 2) {
        printf("Usage: %s <destination>\n", argv[0]);
        perror(argv[0]);
        return 1;
    }

    int fd;
    
    if ((fd = open(argv[1], O_CREAT | O_APPEND | O_WRONLY, 0644)) == -1) {
        perror(argv[1]);
        return 2;
    }

    write(STDOUT_FILENO, "Press ENTER to stop!\n", 21);
    do {
    } while (readStudent(fd) == 0);

    return 0;
}