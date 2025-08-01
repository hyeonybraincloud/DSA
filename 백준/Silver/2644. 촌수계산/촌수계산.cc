#include <iostream>
#include <vector>

using namespace std;

// DFS로 촌수 계산 (함수 파라미터로 모든 상태 전달)
void dfs(int current,
         int depth,
         int end_person,
         const vector<vector<int>>& adj,
         vector<bool>& visited,
         int& result) {
    if (current == end_person) {
        result = depth;
        return;
    }
    visited[current] = true;
    for (int next : adj[current]) {
        if (!visited[next]) {
            dfs(next, depth + 1, end_person, adj, visited, result);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int start_person, end_person;
    cin >> start_person >> end_person;
    int m;
    cin >> m;

    // 지역 변수로 선언 및 정의
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    int result = -1;  // 결과 촌수 (초기값 -1: 미연결)

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS 호출: 필요한 모든 변수를 인자로 전달
    dfs(start_person, 0, end_person, adj, visited, result);

    cout << result << '\n';
    return 0;
}