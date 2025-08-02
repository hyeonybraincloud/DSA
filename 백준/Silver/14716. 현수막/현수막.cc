#include <iostream>
#include <vector>

using namespace std;

// 8방향 (상, 우상, 우, 우하, 하, 좌하, 좌, 좌상)
int dx[8] = {-1, -1,  0, 1, 1, 1,  0, -1};
int dy[8] = { 0,  1,  1, 1, 0,-1, -1, -1};

void dfs(int x, int y, vector<vector<int>>& board, int M, int N) {
    board[x][y] = 0;  // 방문 처리
    for (int dir = 0; dir < 8; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && board[nx][ny] == 1) {
            dfs(nx, ny, board, M, N);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M, N;
    cin >> M >> N;
    
    vector<vector<int>> board(M, vector<int>(N));
    
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int count = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                count++;
                dfs(i, j, board, M, N);
            }
        }
    }

    cout << count << endl;
    return 0;
}