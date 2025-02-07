#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> pii;

vector<pii> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// 주어진 좌표에서 연결된 블록을 탐색하여 조각을 추출하는 함수
vector<pii> extractShape(vector<vector<int>> &board, int x, int y, int value) {
    int n = board.size();
    queue<pii> q;
    vector<pii> shape;
    board[x][y] = -1; // 방문 처리
    q.push({x, y});

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        shape.push_back(cur);
        
        for (auto d : directions) {
            int nx = cur.first + d.first;
            int ny = cur.second + d.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == value) {
                board[nx][ny] = -1; // 방문 처리
                q.push({nx, ny});
            }
        }
    }
    
    // 좌표 정규화 (맨 왼쪽 위 기준으로 이동)
    int minX = n, minY = n;
    for (auto &[px, py] : shape) {
        minX = min(minX, px);
        minY = min(minY, py);
    }
    
    for (auto &[px, py] : shape) {
        px -= minX;
        py -= minY;
    }
    
    return shape;
}

// 퍼즐 조각을 90도 회전하는 함수
vector<pii> rotateShape(vector<pii> shape) {
    vector<pii> rotated;
    int maxX = 0, maxY = 0;
    
    for (auto &[x, y] : shape) {
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }
    
    for (auto &[x, y] : shape) {
        rotated.push_back({y, maxX - x});
    }
    
    sort(rotated.begin(), rotated.end());
    return rotated;
}

// 두 퍼즐 조각이 같은 모양인지 확인하는 함수
bool matchShapes(vector<pii> &a, vector<pii> &b) {
    if (a.size() != b.size()) return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int n = game_board.size();
    
    vector<vector<pii>> boardSpaces, tableShapes;
    
    // 빈 공간(퍼즐 조각이 들어갈 자리) 추출
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (game_board[i][j] == 0) {
                boardSpaces.push_back(extractShape(game_board, i, j, 0));
            }
        }
    }
    
    // 퍼즐 조각 추출
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == 1) {
                tableShapes.push_back(extractShape(table, i, j, 1));
            }
        }
    }
    
    int answer = 0;
    
    vector<bool> used(tableShapes.size(), false);
    
    // 빈 공간과 퍼즐 조각 매칭
    for (auto &space : boardSpaces) {
        for (int j = 0; j < tableShapes.size(); j++) {
            if (used[j]) continue;
            vector<pii> shape = tableShapes[j];
            
            // 4방향 회전하여 매칭 확인
            for (int r = 0; r < 4; r++) {
                if (matchShapes(space, shape)) {
                    answer += space.size();
                    used[j] = true;
                    break;
                }
                shape = rotateShape(shape);
            }
            
            if (used[j]) break;
        }
    }
    
    return answer;
}
