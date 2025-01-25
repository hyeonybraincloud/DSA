#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

int map[MAX][MAX];         // 지도 배열
int visited[MAX][MAX];     // 방문 여부 확인 배열
int block_sizes[MAX * MAX]; // 블록별 크기 저장 배열
int dx[] = { -1, 1, 0, 0 };  // 상하좌우 방향 벡터
int dy[] = { 0, 0, -1, 1 };
int N;                     // 지도 크기
int block_count = 0;       // 블록 개수

// BFS 구현
void bfs(int x, int y) {
    int queue[MAX * MAX][2], front = 0, rear = 0;
    queue[rear][0] = x;
    queue[rear++][1] = y;
    visited[x][y] = 1;

    int size = 0;

    while (front < rear) {
        int cx = queue[front][0];
        int cy = queue[front++][1];
        size++;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (!visited[nx][ny] && map[nx][ny] == 1) {
                    visited[nx][ny] = 1;
                    queue[rear][0] = nx;
                    queue[rear++][1] = ny;
                }
            }
        }
    }

    block_sizes[block_count++] = size;
}

// 비교 함수 (오름차순 정렬용)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // 지도 크기 입력 받기
    scanf("%d", &N);

    // 지도 정보 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]); // 각 숫자를 개별적으로 입력
        }
    }

    // BFS로 블록 탐색
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    // 블록 크기 정렬 (qsort 사용)
    qsort(block_sizes, block_count, sizeof(int), compare);

    // 결과 출력
    printf("%d\n", block_count); // 블록 개수
    for (int i = 0; i < block_count; i++) {
        printf("%d\n", block_sizes[i]); // 각 블록의 크기
    }

    return 0;
}