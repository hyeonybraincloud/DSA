#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int idx = 0; idx < n; idx++)
		cin >> nums[idx];

	int currentSum = nums[0];
	int maxSum = nums[0];

	for (int idx = 1; idx < n; idx++) {
		currentSum = max(nums[idx], currentSum + nums[idx]);
		maxSum = max(maxSum, currentSum);
	}

	cout << maxSum << endl;

	return 0;
}