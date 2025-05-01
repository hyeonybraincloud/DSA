#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> sticker(2, vector<int>(n + 1));
        vector<vector<int>> dp(2, vector<int>(n + 1));

        for (int i = 0; i < 2; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> sticker[i][j];

        // 초기값
        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];

        for (int j = 2; j <= n; ++j) {
            dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + sticker[0][j];
            dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + sticker[1][j];
        }

        cout << max(dp[0][n], dp[1][n]) << '\n';
    }

    return 0;
}
