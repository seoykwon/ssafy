#include <stdio.h>
#include <fcntl.h>  // open(), O_RDONLY 등
#include <unistd.h> // read(), lseek()
#include <string.h> // strcmp(), memset()

int main()
{
    int fd;
    char buffer[6];  // 5글자 + 널 문자
    char buffer3[4]; // 3글자 + 널 문자

    // 1. 파일 열기
    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("파일을 열 수 없습니다.");
        return 1;
    }

    // 2. 첫 다섯 글자 읽기
    if (read(fd, buffer, 5) == -1)
    {
        perror("파일 읽기 오류");
        close(fd);
        return 1;
    }
    buffer[5] = '\0';                     // 널 문자 추가
    printf("첫 다섯 글자: %s\n", buffer); // 출력: ABCDE

    // 3. 문자열 맨 뒤 다섯 글자 읽기
    lseek(fd, -5, SEEK_END); // 파일 끝에서 5칸 뒤로 이동
    if (read(fd, buffer, 5) == -1)
    {
        perror("파일 읽기 오류");
        close(fd);
        return 1;
    }
    buffer[5] = '\0';                        // 널 문자 추가
    printf("맨 뒤 다섯 글자: %s\n", buffer); // 출력: VWXYZ

    // 4. 처음부터 세 글자씩 읽기
    lseek(fd, 0, SEEK_SET); // 파일 처음으로 이동
    while (read(fd, buffer3, 3) > 0)
    {
        buffer3[3] = '\0';                     // 널 문자 추가
        printf("읽은 세 글자: %s\n", buffer3); // 세 글자 출력

        // "GHI"를 발견하면 처리
        if (strcmp(buffer3, "GHI") == 0)
        {
            printf("GHI 발견!\n");
            lseek(fd, 5, SEEK_CUR); // 오프셋 5칸 이동
            if (read(fd, buffer3, 3) == -1)
            {
                perror("파일 읽기 오류");
                close(fd);
                return 1;
            }
            buffer3[3] = '\0';
            printf("오프셋 이동 후 읽은 세 글자: %s\n", buffer3); // 출력: OPQ
            break;                                                // GHI를 찾은 후 종료
        }
    }

    // 5. 파일 닫기
    close(fd);

    return 0;
}
