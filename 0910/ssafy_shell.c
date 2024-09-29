#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isHistoryCmd(char *line)
{
    if (line[0] != '!')
        return 0;

    int n = strlen(line);
    for (int i = 1; i < n; i++)
    {
        if (!(line[i] >= '0' && line[i] <= '9'))
            return 0;
    }

    return 1;
}

int main()
{
    char history[100][100]; // To store the history of commands
    int hn = 0;             // History counter
    int historyFlag = 0;    // Flag to check if running from history
    char line[100];         // To store the current command

    while (1)
    {
        printf("SSAFY > ");

        if (historyFlag == 0)
        {
            scanf("%s", line); // Read the current command
        }
        historyFlag = 0; // Reset history flag after executing the history command

        // Add command to history
        strcpy(history[hn++], line);

        // Check for valid commands and execute
        if (!strcmp(line, "date"))
            system("date");
        else if (!strcmp(line, "uptime"))
            system("uptime");
        else if (!strcmp(line, "ls"))
            system("ls -al");
        else if (!strcmp(line, "log"))
            system("dmesg");
        else if (!strcmp(line, "exit"))
            break; // Exit the shell
        else if (!strcmp(line, "hclear"))
            hn = 0; // Clear the history
        else if (!strcmp(line, "history"))
        {
            for (int i = 0; i < hn; i++)
            {
                printf("%d %s\n", i + 1, history[i]); // Print history with command numbers
            }
        }
        else if (isHistoryCmd(line))
        {
            int num = atoi(&line[1]); // Extract number after '!'
            if (num > 0 && num <= hn)
            {
                strcpy(line, history[num - 1]); // Retrieve command from history
                historyFlag = 1;                // Set flag to indicate command retrieved from history
            }
            else
            {
                printf("ERROR: Invalid history command\n"); // Invalid history number
            }
        }
        else
        {
            printf("ERROR\n"); // Invalid command
        }
    }

    return 0;
}
