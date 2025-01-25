#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

int map[MAX][MAX];         // ���� �迭
int visited[MAX][MAX];     // �湮 ���� Ȯ�� �迭
int block_sizes[MAX * MAX]; // ��Ϻ� ũ�� ���� �迭
int dx[] = { -1, 1, 0, 0 };  // �����¿� ���� ����
int dy[] = { 0, 0, -1, 1 };
int N;                     // ���� ũ��
int block_count = 0;       // ��� ����

// BFS ����
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

// �� �Լ� (�������� ���Ŀ�)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // ���� ũ�� �Է� �ޱ�
    scanf("%d", &N);

    // ���� ���� �Է� �ޱ�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]); // �� ���ڸ� ���������� �Է�
        }
    }

    // BFS�� ��� Ž��
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    // ��� ũ�� ���� (qsort ���)
    qsort(block_sizes, block_count, sizeof(int), compare);

    // ��� ���
    printf("%d\n", block_count); // ��� ����
    for (int i = 0; i < block_count; i++) {
        printf("%d\n", block_sizes[i]); // �� ����� ũ��
    }

    return 0;
}