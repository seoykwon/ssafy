#include <stdio.h>
#include <stdint.h>

int main()
{
    typedef struct KFC
    {
        int m1;
        char m2;
        int m3[5];
    } chicken;

    chicken tmp;
    tmp.m1 = 1;
    tmp.m2 = 'A';

    for (int i = 0; i < 5; i++)
    {
        tmp.m3[i] = i + 1;
    }
    printf("%d ", tmp.m1);
}
