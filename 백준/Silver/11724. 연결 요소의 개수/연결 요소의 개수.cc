#include <iostream>
#include <vector>

using namespace std;

void dfs(int cur, const vector<vector<int>>& adj, vector<bool>& visited) {
	visited[cur] = true;

	for (int next : adj[cur]) {
		if (!visited[next])
			dfs(next, adj, visited);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n+1);
	vector<bool> visited(n+1, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int connection = 0;

	for (int i = 1; i <=n; i++) {
		if (!visited[i]) {
			dfs(i, adj, visited);
			connection++;
		}
	}

	cout<< connection << endl;

	return 0;
}