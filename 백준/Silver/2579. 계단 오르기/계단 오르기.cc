#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> score(n + 1);

	for (int idx = 1; idx <= n; idx++)
		cin >> score[idx];

	vector<int> dp(n + 1, 0);

	// 초기값 설정
	dp[1] = score[1];
	if (n >= 2)
		dp[2] = score[1] + score[2];
	if (n >= 3)
		dp[3] = max(score[1] + score[3], score[2] + score[3]);

	for (int idx = 4; idx <= n; idx++)
		dp[idx] = max(dp[idx- 2], dp[idx - 3] + score[idx - 1]) + score[idx];

	cout << dp[n] << endl;

	return 0;
}