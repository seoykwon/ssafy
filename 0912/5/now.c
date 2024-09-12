#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 1. 현재 사용자명 출력
    printf("현재 사용자명:\n");
    system("users");

    // 2. 현재 Host명 출력
    printf("\n현재 Host명:\n");
    system("hostname");

    // 3. 부팅 후 시간 출력하기
    printf("\n부팅 후 경과 시간:\n");
    system("uptime -p");

    // 4. 로그인 가능한 user 목록들 출력
    printf("\n로그인 가능한 사용자 목록:\n");
    system("cat /etc/passwd | grep bash");

    return 0;
}
