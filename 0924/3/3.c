#include <stdio.h>

int main()
{
    const char *p[3] = {
        "[000053.163123] MIN CO MIN CO MIN CO",
        "[004351.231231] EMBEDDED EM EM EM",
        "[123456.654321] HO HO HO KKK"};

    for (int i = 0; i < 3; i++)
    {
        int time_sec;
        char message[256];
        char output[256];

        // Use sscanf to parse the time and message
        sscanf(p[i], "[%d.%*f] %[^\n]", &time_sec, message);

        // Format the output using sprintf
        sprintf(output, "%d sec : %s", time_sec, message);

        // Print the formatted output
        printf("%s\n", output);
    }

    return 0;
}