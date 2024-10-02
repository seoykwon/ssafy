#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  // open, O_RDONLY, O_WRONLY, O_CREAT
#include <unistd.h> // read, write, close, lseek
#include <string.h>

int main()
{
    int file, temp;
    char buffer[256];
    int line_to_delete, current_line = 1;
    ssize_t bytes_read;
    int offset = 0;

    // 1. 삭제할 줄 번호 입력받기
    printf("삭제할 줄 번호를 입력하세요: ");
    scanf("%d", &line_to_delete);

    // 2. 파일 열기
    file = open("test.txt", O_RDONLY);
    if (file == -1)
    {
        perror("파일을 열 수 없습니다.");
        return 1;
    }

    // 임시 파일 열기 (삭제된 내용을 임시로 저장)
    temp = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (temp == -1)
    {
        perror("임시 파일을 생성할 수 없습니다.");
        close(file);
        return 1;
    }

    // 3. 파일을 한 줄씩 읽어서 처리
    while ((bytes_read = read(file, &buffer[offset], 1)) > 0)
    {
        // 줄 읽기 (한 글자씩 읽어 \n이 나올 때까지 줄을 구분)
        if (buffer[offset] == '\n' || offset == sizeof(buffer) - 1)
        {
            buffer[offset + 1] = '\0'; // null-terminate the string
            if (current_line != line_to_delete)
            {
                // 삭제할 줄이 아닌 경우 임시 파일에 줄 쓰기
                write(temp, buffer, offset + 1);
            }
            current_line++;
            offset = 0; // 다음 줄을 위한 초기화
        }
        else
        {
            offset++;
        }
    }

    close(file);
    close(temp);

    // 4. 임시 파일을 원본 파일로 대체
    unlink("test.txt");             // 원본 파일 삭제
    rename("temp.txt", "test.txt"); // 임시 파일을 원본 파일로 이름 변경

    printf("줄 삭제가 완료되었습니다.\n");

    return 0;
}
