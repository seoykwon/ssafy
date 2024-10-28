// mine.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int total_mined = 0;
volatile int mining_rate = 1;

void handle_sigusr1(int sig)
{
    printf("[total]: %d\n", total_mined);
}

void handle_sigusr2(int sig)
{
    mining_rate *= 2;
    printf("Something on your mind?\n");
}

void handle_sigterm(int sig)
{
    printf("Mining stopped. Final amount mined: %d\n", total_mined);
    exit(0);
}

int main()
{
    struct sigaction sa1, sa2, sa_term;
    sa1.sa_handler = handle_sigusr1;
    sa2.sa_handler = handle_sigusr2;
    sa_term.sa_handler = handle_sigterm;

    sigemptyset(&sa1.sa_mask);
    sigemptyset(&sa2.sa_mask);
    sigemptyset(&sa_term.sa_mask);

    sa1.sa_flags = 0;
    sa2.sa_flags = 0;
    sa_term.sa_flags = 0;

    sigaction(SIGUSR1, &sa1, NULL);
    sigaction(SIGUSR2, &sa2, NULL);
    sigaction(SIGTERM, &sa_term, NULL);

    printf("mineApp PID: %d\n", getpid());

    while (1)
    {
        total_mined += mining_rate;
        sleep(1);
    }

    return 0;
}
