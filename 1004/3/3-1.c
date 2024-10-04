#include <stdio.h>
#include <pthread.h>

void *abc()
{
    printf("1 ABC\n");
}

void *min()
{
    printf("2 MINMIN\n");
}

void *co()
{
    printf("3 COCO\n");
}

void *kfc()
{
    printf("4 KFCKFC\n");
}

int main()
{
    pthread_t t1, t2, t3, t4;

    pthread_create(&t1, NULL, abc, NULL);
    pthread_create(&t2, NULL, min, NULL);
    pthread_create(&t3, NULL, co, NULL);
    pthread_create(&t4, NULL, kfc, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    return 0;
}
