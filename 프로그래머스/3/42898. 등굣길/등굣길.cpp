#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // 웅덩이 위치를 표시할 배열 생성
    vector<vector<bool>> isPuddle(n, vector<bool>(m, false));
    for (const auto& p : puddles) {
        isPuddle[p[1] - 1][p[0] - 1] = true; // (x, y) 좌표를 (행, 열)로 변환
    }

    // 시작점 설정
    dp[0][0] = 1;

    // DP 수행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPuddle[i][j]) {
                dp[i][j] = 0; // 웅덩이는 경로를 만들 수 없음
            } else {
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD; // 위쪽에서 오는 경우
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD; // 왼쪽에서 오는 경우
            }
        }
    }

    return dp[n - 1][m - 1];
}
