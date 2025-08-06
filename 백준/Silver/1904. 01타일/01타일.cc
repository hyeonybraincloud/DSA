#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (N == 2) {
		cout << 2 << endl;
		return 0;
	}

	vector<int> dp(N+1);
	const int mod = 15746;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i-1] + dp[i-2]) % mod;

	cout << dp[N] << endl;

	return 0;
}