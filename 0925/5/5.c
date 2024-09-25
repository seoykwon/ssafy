#include <stdio.h>
#include <stdint.h>

union parser
{
    struct
    {
        uint8_t header[3];
        uint8_t body[2];
        uint8_t tail[2];
    } field;
};

int main()
{
    uint8_t data[7] = {0XAB, 0XCD, 0XEF, 0X12, 0X09, 0XAF, 0XAF};

    union parser *p = (union parser *)data;

    printf(" header: ");
    for (int i = 0; i < 3; i++)
        printf("%02X", p->field.header[i]);

    printf("\n body: ");
    for (int i = 0; i < 2; i++)
        printf("%02X", p->field.body[i]);

    printf("\n tail: ");
    for (int i = 0; i < 2; i++)
        printf("%02X", p->field.tail[i]);

    return 0;
}
