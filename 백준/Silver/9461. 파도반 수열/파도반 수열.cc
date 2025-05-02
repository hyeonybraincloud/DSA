#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);  // 입출력 속도 향상
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<long long> dp(101);
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;

    for (int i = 6; i <= 100; ++i)
        dp[i] = dp[i - 1] + dp[i - 5];

    while (T--) {
        int N;
        cin >> N;
        cout << dp[N] << '\n';  // 반드시 줄바꿈 '\n' 사용
    }

    return 0;
}
