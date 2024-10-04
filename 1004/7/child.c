#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>   // exit() 함수 포함
#include <sys/wait.h> // wait() 함수 포함

int main()
{
    // 부모 프로세스가 자식 프로세스를 생성
    pid_t child_pid = fork();

    if (child_pid > 0)
    { // 부모 프로세스 코드
        printf("I'm Parent! I'm Busy!!\n");
        while (1)
            ; // 부모는 무한 루프에서 바쁜 상태로 유지
    }
    else if (child_pid == 0)
    { // 자식 프로세스 코드
        printf("HI! I'm baby! ByeBye\n");

        // 자식 프로세스가 손자 프로세스를 생성
        pid_t grandchild_pid = fork();

        if (grandchild_pid > 0)
        {
            // 자식 프로세스는 손자를 생성한 후 종료
            printf("Child is saying ByeBye!\n");
            exit(0); // 자식 프로세스는 더 이상 작업할 것이 없으므로 종료
        }
        else if (grandchild_pid == 0)
        {
            // 손자 프로세스 코드
            printf("Grow up! I'm Groot!\n");
            sleep(2); // 손자 프로세스는 2초간 작업을 수행하는 것처럼 기다림
            printf("Grandchild completed its task.\n");
            exit(0); // 손자 프로세스는 작업을 마친 후 종료
        }
    }

    return 0;
}
