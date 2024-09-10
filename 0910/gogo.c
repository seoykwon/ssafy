#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];

    while (1)
    {
        printf("SSAFY_ECHOBOT >> ");

        // Get user input
        fgets(input, sizeof(input), stdin);

        // Remove newline character from fgets
        input[strcspn(input, "\n")] = 0;

        // Check if input is "exit" or "bye"
        if (strcmp(input, "EXIT") == 0 || strcmp(input, "BYE") == 0 || strcmp(input, "exit") == 0 || strcmp(input, "bye") == 0)
        {
            break;
        }

        // Print user input
        printf("%s\n", input);
    }

    return 0;
}
