#include <stdio.h>
#include <stdint.h>

int main()
{

    union VAR
    {
        uint64_t g;
        uint8_t buf[8];
    };

    union VAR x = {.g = 0xABCD12345678CD01};

    for (int i = 0; i < 8; i++)
    {
        printf("%02X", x.buf[i]);
    }
}
