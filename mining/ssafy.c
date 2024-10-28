// ssafy.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void send_signal(pid_t mine_pid, int signal)
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

    pid_t mine_pid = atoi(argv[1]);
    char command[10];

    printf("ssafyApp started. PID: %d\n", getpid());

    while (1)
    {
        printf("Enter command (SHOW, ADD, STOP, exit): ");
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }

        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        if (strcmp(command, "SHOW") == 0)
        {
            send_signal(mine_pid, SIGUSR1);
        }
        else if (strcmp(command, "ADD") == 0)
        {
            send_signal(mine_pid, SIGUSR2);
        }
        else if (strcmp(command, "STOP") == 0 || strcmp(command, "exit") == 0)
        {
            send_signal(mine_pid, SIGTERM);
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
