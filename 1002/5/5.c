#include <stdio.h>
#include <fcntl.h>   // open() 시스템 호출을 사용하기 위해 필요
#include <unistd.h>  // read(), close()를 사용하기 위해 필요
#include <string.h>  // memset()을 사용하기 위해 필요

int main() {
    int fd;
    ssize_t bytes_read;
    char buffer[11];  // 10바이트 + 널 문자를 위한 공간

    // 1. 파일 열기
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("파일을 열 수 없습니다.");
        return 1;
    }

    // 2. 파일에서 10바이트씩 읽어서 출력
    while ((bytes_read = read(fd, buffer, 10)) > 0) {
        buffer[bytes_read] = '\0';  // 널 문자로 끝을 지정
        printf("%s\n", buffer);     // 읽은 내용 출력
        memset(buffer, 0, sizeof(buffer));  // 버퍼 초기화
    }

    if (bytes_read == -1) {
        perror("파일을 읽는 중 오류 발생");
    }

    // 3. 파일 닫기
    close(fd);

    printf("FINISH\n");

    return 0;
}
