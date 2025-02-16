#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 1. 정렬 (Greedy 알고리즘 특성상 정렬이 필요)
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 2. 여벌 체육복이 있지만 도난당한 경우 제거
    vector<int> real_lost, real_reserve;
    for (int l : lost) {
        if (find(reserve.begin(), reserve.end(), l) != reserve.end()) {
            reserve.erase(find(reserve.begin(), reserve.end(), l));
        } else {
            real_lost.push_back(l);
        }
    }

    // 3. 체육복을 빌려주기
    int count = n - real_lost.size();  // 체육복이 있는 학생 수
    for (int l : real_lost) {
        auto it = find_if(reserve.begin(), reserve.end(), [&](int r) {
            return r == l - 1 || r == l + 1;
        });
        if (it != reserve.end()) {
            count++;  // 체육복을 빌려줄 수 있는 경우 증가
            reserve.erase(it);
        }
    }

    return count;
}
