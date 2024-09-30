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
    char history[100][100];
    int hn = 0;
    int historyFlag = 0;
    char line[100];

    while (1)
    {
        printf("SSAFY > ");

        if (!historyFlag == 0)
        {
            scanf("%s", line);
        }
        historyFlag = 0;

        strcpy(history[hn++], line);

        if (!strcmp(line, "date"))
            system("date");
        else if (!strcmp(line, "uptime"))
            system("uptime");
        else if (!strcmp(line, "ls"))
            system("ls -al");
        else if (!strcmp(line, "log"))
            system("dmesg");
        else if (!strcmp(line, "exit"))
            break;
        else if (!strcmp(line, "hclear"))
            hn = 0;
        else if (!strcmp(line, "history"))
        {
            for (int i = 0; i < hn; i++)
            {
                printf("%d %s\n", i + 1, history[i]);
            }
        }

        else if (isHistoryCmd(line))
        {
            int num = atoi(&line[1]);
            if (num > 0 && num <= hn)
            {
                strcpy(line, history[num - 1]);
                historyFlag = 1;
            }
            else
            {
                printf("ERROR: Invalie history command\n");
            }
        }
        else
        {
            printf("ERROR\n");
        }
    }
}