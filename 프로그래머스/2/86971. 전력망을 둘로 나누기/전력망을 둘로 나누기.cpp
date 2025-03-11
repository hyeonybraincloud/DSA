#include <vector>
#include <algorithm>

using namespace std;

// DFS를 이용하여 한 네트워크의 노드 개수 구하기
int dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    int count = 1;  // 현재 노드 포함
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            count += dfs(neighbor, graph, visited);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int minDiff = n;  // 초기값을 가장 큰 값으로 설정

    for (int i = 0; i < wires.size(); i++) {
        // 그래프를 인접 리스트로 만들기
        vector<vector<int>> graph(n + 1);
        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue;  // i 번째 간선을 제거
            int v1 = wires[j][0], v2 = wires[j][1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        // 한쪽 네트워크의 노드 개수를 구하기 위해 DFS 수행
        vector<bool> visited(n + 1, false);
        int count = dfs(1, graph, visited);

        // 두 네트워크의 차이 계산
        int diff = abs((n - count) - count);
        minDiff = min(minDiff, diff);
    }

    return minDiff;
}
