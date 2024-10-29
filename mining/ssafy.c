// ssafy.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

// Global variable to store mineApp PID
pid_t mine_pid;

// Signal handler for alarm (timeout)
void handle_alarm(int sig)
{
    printf("No input received in 5 seconds. Exiting...\n");
    // Send SIGTERM to mineApp to terminate it
    kill(mine_pid, SIGTERM);
    exit(0); // Exit ssafyApp
}

// Function to send a signal to mineApp
void send_signal(int signal)
{
    if (kill(mine_pid, signal) == -1)
    {
        perror("Error sending signal");
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <mineApp PID>\n", argv[0]);
        return 1;
    }

    mine_pid = atoi(argv[1]);
    char command[10];

    printf("ssafyApp started. PID: %d\n", getpid());

    // Set up the alarm signal handler
    struct sigaction sa;
    sa.sa_handler = handle_alarm;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGALRM, &sa, NULL);

    while (1)
    {
        // Start a 5-second alarm
        alarm(5);

        printf("Enter command (SHOW, ADD, STOP, exit): ");
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }

        // Reset the alarm since we received input
        alarm(0);

        // Remove newline character from command
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "SHOW") == 0)
        {
            send_signal(SIGUSR1);
        }
        else if (strcmp(command, "ADD") == 0)
        {
            send_signal(SIGUSR2);
        }
        else if (strcmp(command, "STOP") == 0 || strcmp(command, "exit") == 0)
        {
            send_signal(SIGTERM);
            if (strcmp(command, "exit") == 0)
            {
                break;
            }
        }
        else
        {
            printf("ERROR: Unknown command\n");
        }
    }

    printf("ssafyApp exiting.\n");
    return 0;
}
