#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int n, int m, int id, vector<vector<int>>& land, vector<vector<int>>& oil_map, int& size) {
    oil_map[x][y] = id;
    size++;
    
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (land[nx][ny] == 1 && oil_map[nx][ny] == -1) {
                dfs(nx, ny, n, m, id, land, oil_map, size);
            }
        }
    }
}

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    
    vector<vector<int>> oil_map(n, vector<int>(m, -1));
    vector<int> oil_sizes;
    
    int id = 0;
    
    // Step 1: 석유 덩어리 구분 (DFS)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (land[i][j] == 1 && oil_map[i][j] == -1) {
                int size = 0;
                dfs(i, j, n, m, id, land, oil_map, size);
                oil_sizes.push_back(size);
                id++;
            }
        }
    }

    // Step 2: 열마다 시추관 위치 고려
    int max_oil = 0;
    for (int col = 0; col < m; ++col) {
        set<int> seen_ids;
        int total = 0;

        for (int row = 0; row < n; ++row) {
            int oil_id = oil_map[row][col];
            if (oil_id != -1 && seen_ids.find(oil_id) == seen_ids.end()) {
                total += oil_sizes[oil_id];
                seen_ids.insert(oil_id);
            }
        }
        max_oil = max(max_oil, total);
    }

    return max_oil;
}
