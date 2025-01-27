#include <stdio.h>
#include <string.h>

#define MAXN 4       // �ִ� ���� ũ��
#define MAXM 16      // �ִ� üũ����Ʈ ����
#define INF 1e9

int n, m;
int grid[MAXN][MAXN];               // ����: 0(�� ĭ), 1(��)
int checkpoints[MAXM][2];           // üũ����Ʈ ��ǥ
long long dp[MAXN][MAXN][1 << 16][MAXM + 1]; // �޸������̼� �迭

int dx[4] = { -1, 1, 0, 0 };          // �����¿� �̵�
int dy[4] = { 0, 0, -1, 1 };

// ��Ʈ����ũ���� (x, y) ��ġ�� ǥ��
int bitIndex(int x, int y) {
    return x * n + y;
}

// DFS �Լ�
long long dfs(int x, int y, int visitedMask, int cIdx) {
    // ��� üũ����Ʈ�� �湮 �Ϸ��ߴٸ� ��� 1��
    if (cIdx == m) return 1;

    // �̹� ���� ���¶�� ��� ��ȯ
    if (dp[x][y][visitedMask][cIdx] != -1) {
        return dp[x][y][visitedMask][cIdx];
    }

    long long paths = 0;

    // 4�������� �̵�
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // ���� ������ ����ų� ���̰ų� �̹� �湮�� ĭ�̸� ��ŵ
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (grid[nx][ny] == 1) continue;
        if (visitedMask & (1 << bitIndex(nx, ny))) continue;

        // ���ο� �湮 ���� ����
        int nextMask = visitedMask | (1 << bitIndex(nx, ny));

        // üũ����Ʈ�� �湮�� ���
        if (nx == checkpoints[cIdx][0] && ny == checkpoints[cIdx][1]) {
            paths += dfs(nx, ny, nextMask, cIdx + 1);
        }
        else {
            paths += dfs(nx, ny, nextMask, cIdx);
        }
    }

    // ��� ����
    dp[x][y][visitedMask][cIdx] = paths;
    return paths;
}

int main() {
    // �Է� �ޱ�
    scanf("%d %d", &n, &m);

    // ���� ���� �Է�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // üũ����Ʈ �Է� (1-based�� 0-based�� ��ȯ)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &checkpoints[i][0], &checkpoints[i][1]);
        checkpoints[i][0]--; // 1-based �� 0-based
        checkpoints[i][1]--;
    }

    // dp �迭 �ʱ�ȭ (-1�� ����)
    memset(dp, -1, sizeof(dp));

    // ����� ����
    int startX = checkpoints[0][0];
    int startY = checkpoints[0][1];
    int startMask = 1 << bitIndex(startX, startY); // ����� �湮 ó��

    // DFS Ž�� ����
    long long result = dfs(startX, startY, startMask, 1);

    // ��� ���
    printf("%lld\n", result);

    return 0;
}
