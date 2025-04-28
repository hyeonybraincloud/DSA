#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
vector<string> maps;
vector<vector<bool>> visited;
int startX, startY, leverX, leverY, endX, endY;
int dx[] = {-1, 1, 0, 0}; // 상하좌우
int dy[] = {0, 0, -1, 1};

int bfs(int sx, int sy, char target) {
    visited.assign(n, vector<bool>(m, false));
    queue<pair<pair<int,int>, int>> q;
    q.push({{sx, sy}, 0});
    visited[sx][sy] = true;
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        if (maps[x][y] == target) return dist;
        
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && maps[nx][ny] != 'X') {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }
    }
    
    return -1; // 못 찾았으면
}

int solution(vector<string> inputMaps) {
    maps = inputMaps;
    n = maps.size();
    m = maps[0].size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] == 'S') {
                startX = i; startY = j;
            } else if (maps[i][j] == 'L') {
                leverX = i; leverY = j;
            } else if (maps[i][j] == 'E') {
                endX = i; endY = j;
            }
        }
    }
    
    int toLever = bfs(startX, startY, 'L');
    if (toLever == -1) return -1;
    
    int toExit = bfs(leverX, leverY, 'E');
    if (toExit == -1) return -1;
    
    return toLever + toExit;
}
