#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_HISTORY 100

char history[MAX_HISTORY][256];
int history_count = 0;

void add_to_history(const char *command)
{
    if (history_count < MAX_HISTORY)
    {
        strncpy(history[history_count], command, 255);
        history[history_count][255] = '\0';
        history_count++;
    }
}

void show_history()
{
    for (int i = 0; i < history_count; i++)
    {
        printf("%d %s\n", i + 1, history[i]);
    }
}

void clear_history()
{
    history_count = 0;
}

int main()
{
    char command[256];
    while (1)
    {
        printf("SSAFY > ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0'; // Remove newline character

        // Add command to history
        add_to_history(command);

        // Built-in commands
        if (strcmp(command, "date") == 0)
        {
            system("date");
        }
        else if (strcmp(command, "uptime") == 0)
        {
            system("uptime");
        }
        else if (strcmp(command, "ls") == 0)
        {
            system("ls -al");
        }
        else if (strcmp(command, "log") == 0)
        {
            system("dmesg");
        }
        else if (strcmp(command, "exit") == 0)
        {
            break; // Exit the shell
        }
        else if (strcmp(command, "history") == 0)
        {
            show_history();
        }
        else if (strncmp(command, "!", 1) == 0)
        {
            int cmd_num = atoi(command + 1);
            if (cmd_num > 0 && cmd_num <= history_count)
            {
                printf("Re-executing command: %s\n", history[cmd_num - 1]);
                system(history[cmd_num - 1]);
            }
            else
            {
                printf("Invalid history number\n");
            }
        }
        else if (strcmp(command, "hclear") == 0)
        {
            clear_history();
        }
        else
        {
            printf("ERROR\n");
        }
    }

    return 0;
}
