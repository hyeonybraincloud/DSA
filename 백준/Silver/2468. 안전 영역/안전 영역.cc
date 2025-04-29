#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, int N, int waterLevel, vector<vector<bool>>& visited, vector<vector<int>>& heightMap) {
	visited[x][y] = true;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (!visited[nx][ny] && heightMap[nx][ny] > waterLevel)
				dfs(nx, ny, N, waterLevel, visited, heightMap);
		}
	}
}

int main() {
	// Step 1: 맵 구성 및 최고 높이 파악
	int N;
	cin >> N;

	vector<vector<int>> heightMap(N, vector<int>(N));
	int maxHeight = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> heightMap[i][j];
			maxHeight = max(maxHeight, heightMap[i][j]);
		}
	}

	// Step 2: 안전 지역 파악
	int maxSafetyArea = 0;

	for (int h = 0; h <= maxHeight; h++) {
		vector<vector<bool>> visited(N, vector<bool>(N, false));
		int SafetyAreaCount = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && heightMap[i][j] > h) {
					dfs(i, j, N, h, visited, heightMap);
					SafetyAreaCount++;
				}
			}
		}

		maxSafetyArea = max(maxSafetyArea, SafetyAreaCount);
	}

	cout << maxSafetyArea << endl;

	return 0;
}