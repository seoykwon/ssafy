#include <stdio.h>
#include <pthread.h> // Pthread 라이브러리 포함
#include <string.h>
#include <unistd.h> // sleep() 함수 포함

// 스레드에서 실행할 함수
void *abc(void *arg)
{
    char *message = (char *)arg; // 전달된 인자를 문자열로 캐스팅
    while (1)
    {
        printf("%s\n", message); // 전달된 문자열을 출력
        sleep(1);                // CPU 과부하 방지를 위해 1초 대기
    }
    return NULL;
}

int main()
{
    pthread_t threads[4];                                          // 4개의 스레드를 저장할 배열
    const char *messages[4] = {"ABC", "MINMIN", "COCO", "KFCKFC"}; // 스레드마다 출력할 메시지

    // 4개의 스레드를 생성하고, 각 스레드가 abc() 함수를 호출하게 함
    for (int i = 0; i < 4; i++)
    {
        if (pthread_create(&threads[i], NULL, abc, (void *)messages[i]))
        {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // 스레드가 무한 루프이므로, 메인 스레드는 종료되지 않도록 무한 대기
    for (int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL); // 스레드가 종료될 때까지 대기
    }

    return 0;
}
