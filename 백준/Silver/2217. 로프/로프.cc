#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> ropes(N);
    for (int i = 0; i < N; i++) {
        cin >> ropes[i];
    }

    // 1) 내림차순 정렬: 긴 로프가 앞에
    sort(ropes.begin(), ropes.end(), greater<long long>());

    // 2) i+1개의 로프를 사용할 때의 최대 하중 계산
    long long answer = 0;
    for (int i = 0; i < N; i++) {
        long long weight = ropes[i] * (i + 1LL);
        answer = max(answer, weight);
    }

    cout << answer << endl;
    return 0;
}
