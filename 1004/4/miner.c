#include <stdio.h>
#include <pthread.h>
#include <unistd.h>   // usleep() 사용
#include <stdlib.h>   // malloc(), free() 사용
#include <string.h>   // strcmp() 사용

#define MAX_MINERS 100 // 최대 채굴기 개수 설정

pthread_t miners[MAX_MINERS];  // 스레드 배열, 최대 100개의 채굴기
int coin_count[MAX_MINERS];    // 각 스레드에서 채굴한 코인의 수
int active_miners = 0;         // 현재 활성화된 채굴기 개수
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // 동기화를 위한 뮤텍스

// 채굴기 스레드 함수
void* mine_coin(void* arg) {
    int id = *(int*)arg;  // 스레드 ID
    while (1) {
        usleep(100000);  // 0.1초 대기
        pthread_mutex_lock(&mutex);  // 임계 구역 진입
        coin_count[id]++;  // 해당 스레드의 코인 수 증가
        pthread_mutex_unlock(&mutex);  // 임계 구역 해제
    }
    return NULL;
}

// 현재 코인 개수 출력
void show_coins() {
    pthread_mutex_lock(&mutex);  // 동기화
    int total_coins = 0;
    for (int i = 0; i < active_miners; i++) {
        total_coins += coin_count[i];
    }
    printf("Total mined coins: %d\n", total_coins);
    pthread_mutex_unlock(&mutex);  // 동기화 해제
}

// 새로운 채굴기 추가
void add_miner() {
    if (active_miners >= MAX_MINERS) {
        printf("Cannot add more miners!\n");
        return;
    }
    int* id = malloc(sizeof(int));  // 스레드 ID 저장
    *id = active_miners;
    pthread_create(&miners[active_miners], NULL, mine_coin, id);  // 새로운 스레드 생성
    active_miners++;  // 활성화된 채굴기 수 증가
    printf("Added a new miner! Total miners: %d\n", active_miners);
}

// 가장 오래된 채굴기 삭제
void delete_miner() {
    if (active_miners <= 0) {
        printf("No miners to delete!\n");
        return;
    }
    pthread_cancel(miners[0]);  // 첫 번째(가장 오래된) 채굴기 스레드 종료
    pthread_mutex_lock(&mutex);  // 동기화
    for (int i = 1; i < active_miners; i++) {
        miners[i - 1] = miners[i];      // 스레드 목록에서 한 칸씩 당기기
        coin_count[i - 1] = coin_count[i];  // 채굴 코인 수 한 칸씩 당기기
    }
    active_miners--;  // 활성화된 채굴기 수 감소
    pthread_mutex_unlock(&mutex);  // 동기화 해제
    printf("Deleted the oldest miner! Total miners: %d\n", active_miners);
}

int main() {
    // 기본적으로 첫 번째 채굴기 자동 생성
    add_miner();

    char command[100];
    while (1) {
        printf("ssafy>> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // 개행 문자 제거

        if (strcmp(command, "show") == 0) {
            show_coins();
        }
        else if (strcmp(command, "add") == 0) {
            add_miner();
        }
        else if (strcmp(command, "del") == 0) {
            delete_miner();
        }
        else {
            printf("Unknown command. Use 'show', 'add', or 'del'.\n");
        }
    }

    return 0;
}
