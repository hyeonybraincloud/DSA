#include <iostream>
#include <vector>

using namespace std;

// 4방향 (상, 하, 좌, 우)
const int dx[4] = { -1,  1,  0,  0 };
const int dy[4] = {  0,  0, -1,  1 };

void dfs(int x, int y,
         int N, int M,
         const vector<vector<int>>& grid,
         vector<vector<bool>>& visited)
{
    visited[x][y] = true;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // 배열 범위 내이고, 아직 방문하지 않았으며, 배추가 있을 때만 탐색
        if (nx >= 0 && nx < N && ny >= 0 && ny < M
            && !visited[nx][ny]
            && grid[nx][ny] == 1)
        {
            dfs(nx, ny, N, M, grid, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        // N: 행, M: 열
        vector<vector<int>> grid(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        for (int i = 0; i < K; ++i) {
            int x, y;
            cin >> x >> y;
            grid[y][x] = 1;
        }

        int worms = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ++worms;
                    dfs(i, j, N, M, grid, visited);
                }
            }
        }

        cout << worms << endl;
    }

    return 0;
}