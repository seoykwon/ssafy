#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char history[100][100];
    char line[100];
    int hn = 0;
    int historyFlag = 0;
    int cnt = 1;
    int n1 = 0;
    int n2 = 0;
    char line2[100];
    char var[1001][100];
    int used[1001] = { 0 ,};

    while (1) {
        printf("seoyoung.kwon(%d) >> ", cnt);

        scanf("%s", &line);

        strcpy(history[hn++], line);

        //if (!strcmp(line, "exit")) break;
        if (!strcmp(line, "loop")) {
            
            scanf("%d %d", &n1, &n2);


            for (int i = n1; i <= n2; i++) {
                printf("%d ", i);
            }
            printf("\n");
            for (int i = n1; i <= n2; i++) {
                printf("%d ", i + 10);
            }
            printf("\n");
        }
        else if (!strcmp(line, "add")) {

            scanf("%d %s", &n1, &line2);

            strcpy(var[n1], line2);

            used[n1] = 1;
            //printf("%s\n", var[n1]);
        }
        else if (!strcmp(line, "print") || !strcmp(line, "show")) {

            scanf("%d", &n1);

            if (!used[n1]) {
                printf("%s", "[ERROR] Wrong variable\n");
            }
            else {
                printf("%s\n", var[n1]);
            }
        }
        else if (!strcmp(line, "repeat")) {

            scanf("%d %d", &n1, &n2);

            for (int i = 0; i < n2; i++) {
                printf("%s\n", var[n1]);
            }
        }
        else if (!strcmp(line, "alpha")) {

            scanf("%s", &line2);

            int n = strlen(line2);

            for (int i = 0; i < n; i++) {
                if (line2[i] >= 'a' && line2[i] <= 'z') {
                    printf("%c", line2[i] - 32);
                }
                else {
                    printf("%c", line2[i] + 32);
                }
            }
            printf("\n");
        }
          
        cnt++;
    }
}

/*
use scanf("%[^\n]s", input);

char *tok = strtok(input, " ");

or

fgets with stdin;
*/