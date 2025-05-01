#include <iostream>
#include <vector>

using namespace std;

int dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    int count = 0;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            count += 1 + dfs(neighbor, graph, visited);
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);      // 1번부터 n번까지 사용
    vector<bool> visited(n + 1, false);    // 방문 체크

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b); // 양방향 연결
        graph[b].push_back(a);
    }

    int result = dfs(1, graph, visited);  // 1번 컴퓨터에서 감염 시작
    cout << result << endl;

    return 0;
}
