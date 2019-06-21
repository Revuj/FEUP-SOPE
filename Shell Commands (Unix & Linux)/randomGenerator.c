#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct tms t;

    clock_t initTime = times(&t);

    srand(time(0));

    int random = 0;
    int i = 0;
    while (random != atoi(argv[2])) {
        random = rand() % atoi(argv[1]);
        printf("%d - %d\n", i, random);
        i++;
    }

    clock_t finalTime = times(&t);

    double ticks_seg = sysconf(_SC_CLK_TCK);

    double real_time = (double)(finalTime - initTime)/ticks_seg;

    double user_time = t.tms_utime/ticks_seg;

    double system_time = t.tms_stime/ticks_seg;

    printf("Real time: %lf\n", real_time);
    printf("User time: %lf\n", user_time);
    printf("System time: %lf\n", system_time);

    return 0;
}