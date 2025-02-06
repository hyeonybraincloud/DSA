#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    // 이동 방향 (상, 하, 좌, 우)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    // BFS를 위한 큐
    queue<pair<int, int>> q;
    q.push({0, 0}); // 시작점 (1,1) → 배열 인덱스 기준 (0,0)
    
    // 방문한 위치에 최단 거리 기록
    vector<vector<int>> distance(n, vector<int>(m, -1));
    distance[0][0] = 1; // 시작점은 첫 이동을 포함하여 1칸

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 네 방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 유효한 범위 내에 있고, 벽이 아니며, 아직 방문하지 않은 경우
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    // 상대 팀 진영까지의 최소 거리 반환
    return distance[n-1][m-1];
}
