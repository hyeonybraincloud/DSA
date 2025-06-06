#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, max_val = 0;
int board[21][21];

void copy_board(int dest[21][21], int src[21][21]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dest[i][j] = src[i][j];
}

void rotate(int b[21][21]) {
    int tmp[21][21];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            tmp[i][j] = b[N - j - 1][i];
    copy_board(b, tmp);
}

void move(int b[21][21]) {
    for (int i = 0; i < N; ++i) {
        int tmp[21] = {0}, idx = 0, last = 0;
        for (int j = 0; j < N; ++j) {
            if (b[i][j] == 0) continue;
            if (last == b[i][j]) {
                tmp[idx - 1] *= 2;
                last = 0;
            } else {
                tmp[idx++] = b[i][j];
                last = b[i][j];
            }
        }
        for (int j = 0; j < N; ++j)
            b[i][j] = tmp[j];
    }
}

void dfs(int depth, int b[21][21]) {
    if (depth == 5) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (b[i][j] > max_val)
                    max_val = b[i][j];
        return;
    }

    for (int d = 0; d < 4; ++d) {
        int next[21][21];
        copy_board(next, b);
        move(next);
        dfs(depth + 1, next);
        rotate(b);  // 원본 회전 (다음 방향 시도)
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &board[i][j]);

    dfs(0, board);
    printf("%d\n", max_val);
    return 0;
}
