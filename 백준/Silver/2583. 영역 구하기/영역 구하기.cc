#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
vector<vector<int>> grid;
vector<vector<bool>> visited;
const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = {  0, 0, 1,-1 };

// (y, x) 에서 시작해 연결된 빈 칸의 개수를 세어 반환
int dfs(int y, int x) {
    visited[y][x] = true;
    int area = 1;
    for (int d = 0; d < 4; ++d) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny >= 0 && ny < M && nx >= 0 && nx < N
            && !visited[ny][nx] && grid[ny][nx] == 0) {
            area += dfs(ny, nx);
        }
    }
    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> K;
    grid.assign(M, vector<int>(N, 0));
    visited.assign(M, vector<bool>(N, false));

    // 1) 직사각형 내부 채우기
    for (int i = 0; i < K; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; ++y)
            for (int x = x1; x < x2; ++x)
                grid[y][x] = 1;
    }

    // 2) DFS로 분리 영역 넓이 계산
    vector<int> areas;
    for (int y = 0; y < M; ++y) {
        for (int x = 0; x < N; ++x) {
            if (grid[y][x] == 0 && !visited[y][x]) {
                areas.push_back(dfs(y, x));
            }
        }
    }

    // 3) 결과 출력
    sort(areas.begin(), areas.end());
    cout << areas.size() << "\n";
    for (int a : areas) cout << a << " ";
    cout << "\n";
    return 0;
}
