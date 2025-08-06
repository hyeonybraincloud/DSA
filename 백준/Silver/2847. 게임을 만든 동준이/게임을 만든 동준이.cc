#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> scores(N);
	for (int i = 0; i < N; i++)
		cin >> scores[i];

	int total_down = 0;
	for (int i = N-1; i > 0; i--) {
		if(scores[i-1] >= scores[i]) {
			int down = scores[i-1] - scores[i] + 1;
			scores[i-1] -= down;
			total_down += down;
		}
	}

	cout << total_down << endl;

	return 0;
}