#include <iostream>
#include <vector>

using namespace std;

int dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
	visited[node] = true;
	int count = 0;

	for (int idx = 1; idx <= graph.size(); idx++) {
		if (!visited[idx] && graph[node][idx] == 1)
			count += (1 + dfs(idx, graph, visited));
	}

	return count;
}

int main() {
	int n, m;

	cin >> n >> m;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
	vector<bool> visited(n, false);

	for (int idx = 0; idx < m; idx++) {
		int a, b;
		
		cin >> a >> b;

		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	int result = dfs(1, graph, visited);

	cout << result << endl;

	return 0;
}