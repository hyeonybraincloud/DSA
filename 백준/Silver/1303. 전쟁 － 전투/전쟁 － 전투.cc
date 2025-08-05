#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, const char color, const vector<vector<char>>& board, vector<vector<bool>>& visited, int M, int N, int& cnt) {
	visited[x][y] = true;
	cnt++;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && board[nx][ny] == color) {
			dfs(nx, ny, color, board, visited, M, N, cnt);
		}
	}
}
	
int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<char>> board(M, vector<char>(N));
	vector<vector<bool>> visited(M, vector<bool>(N, false));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	int white_army = 0, blue_army = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				char color = board[i][j];
				int cnt = 0;
				
				dfs(i, j, color, board, visited, M, N, cnt);
				
				if (color == 'W')
					white_army += cnt * cnt;
				else
					blue_army += cnt*cnt;
			}
		}
	}

	cout << white_army << " " << blue_army << endl;

	return 0;
}