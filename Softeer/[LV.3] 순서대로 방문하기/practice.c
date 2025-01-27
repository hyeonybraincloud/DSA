#include <stdio.h>
#include <string.h>

#define MAXN 4       // 최대 격자 크기
#define MAXM 16      // 최대 체크포인트 개수
#define INF 1e9

int n, m;
int grid[MAXN][MAXN];               // 격자: 0(빈 칸), 1(벽)
int checkpoints[MAXM][2];           // 체크포인트 좌표
long long dp[MAXN][MAXN][1 << 16][MAXM + 1]; // 메모이제이션 배열

int dx[4] = { -1, 1, 0, 0 };          // 상하좌우 이동
int dy[4] = { 0, 0, -1, 1 };

// 비트마스크에서 (x, y) 위치를 표현
int bitIndex(int x, int y) {
    return x * n + y;
}

// DFS 함수
long long dfs(int x, int y, int visitedMask, int cIdx) {
    // 모든 체크포인트를 방문 완료했다면 경로 1개
    if (cIdx == m) return 1;

    // 이미 계산된 상태라면 결과 반환
    if (dp[x][y][visitedMask][cIdx] != -1) {
        return dp[x][y][visitedMask][cIdx];
    }

    long long paths = 0;

    // 4방향으로 이동
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 격자 범위를 벗어나거나 벽이거나 이미 방문한 칸이면 스킵
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (grid[nx][ny] == 1) continue;
        if (visitedMask & (1 << bitIndex(nx, ny))) continue;

        // 새로운 방문 상태 갱신
        int nextMask = visitedMask | (1 << bitIndex(nx, ny));

        // 체크포인트를 방문한 경우
        if (nx == checkpoints[cIdx][0] && ny == checkpoints[cIdx][1]) {
            paths += dfs(nx, ny, nextMask, cIdx + 1);
        }
        else {
            paths += dfs(nx, ny, nextMask, cIdx);
        }
    }

    // 결과 저장
    dp[x][y][visitedMask][cIdx] = paths;
    return paths;
}

int main() {
    // 입력 받기
    scanf("%d %d", &n, &m);

    // 격자 정보 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // 체크포인트 입력 (1-based를 0-based로 변환)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &checkpoints[i][0], &checkpoints[i][1]);
        checkpoints[i][0]--; // 1-based → 0-based
        checkpoints[i][1]--;
    }

    // dp 배열 초기화 (-1로 설정)
    memset(dp, -1, sizeof(dp));

    // 출발점 설정
    int startX = checkpoints[0][0];
    int startY = checkpoints[0][1];
    int startMask = 1 << bitIndex(startX, startY); // 출발점 방문 처리

    // DFS 탐색 시작
    long long result = dfs(startX, startY, startMask, 1);

    // 결과 출력
    printf("%lld\n", result);

    return 0;
}
