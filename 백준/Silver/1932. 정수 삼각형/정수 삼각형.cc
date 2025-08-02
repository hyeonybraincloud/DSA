#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> a(N);
    // 각 행의 크기를 i+1로 미리 지정
    for (int i = 0; i < N; ++i) {
        a[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            cin >> a[i][j];
        }
    }

    // 1행부터 in-place로 최대 합 누적
    for (int i = 1; i < N; ++i) {
        // 맨 왼쪽
        a[i][0] += a[i-1][0];

        // 중간: 위(a[i-1][j])와 위대각선좌(a[i-1][j-1]) 중 큰 쪽을 더함
        for (int j = 1; j < i; ++j) {
            int temp = max(a[i-1][j-1], a[i-1][j]);
            a[i][j] += temp;
        }

        // 맨 오른쪽
        a[i][i] += a[i-1][i-1];
    }

    // 마지막 행에서 최대값 찾기
    int answer = *max_element(a[N-1].begin(), a[N-1].end());
    cout << answer << "\n";

    return 0;
}
