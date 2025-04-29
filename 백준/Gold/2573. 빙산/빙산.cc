#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visited) {
	visited[x][y] = true;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (!visited[nx][ny] && map[nx][ny] > 0)
				dfs(nx, ny, map, visited);
		}
	}
}

int countIcebergs(vector<vector<int>>& map) {
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && map[i][j] > 0) {
				dfs(i, j, map, visited);
				count++;
			}
		}
	}

	return count;
}

void melt(vector<vector<int>>& map) {
	vector<vector<int>> temp = map;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0) {
				int sea = 0;

				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					
					if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0)
						sea++;
				}

				temp[i][j] = max(0, map[i][j] - sea);
			}
		}
	}

	map = temp;
}

int main() {
	// Step 1: 입력
	cin >> N >> M;

	vector<vector<int>> map(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	// Step 2
	int year = 0;

	while (true) {
		int count = countIcebergs(map);
		
		if (count == 0) {
			cout << 0 << endl;
			break;
		}

		if (count >= 2) {
			cout << year << endl;
			break;
		}

		melt(map);
		year++;
	}

	return 0;
}