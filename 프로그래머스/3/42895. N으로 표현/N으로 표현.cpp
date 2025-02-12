#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;  // N을 1번 사용한 경우
    
    vector<set<int>> dp(9);  // dp[i]: N을 i번 사용해서 만들 수 있는 숫자 집합

    for (int i = 1; i <= 8; i++) {
        // N을 i번 연속해서 쓴 값 추가 (예: 5, 55, 555, 5555, ...)
        int num = 0;
        for (int j = 0; j < i; j++) {
            num = num * 10 + N;
        }
        dp[i].insert(num);

        // i를 두 부분 (j, i-j)로 나눠서 사칙연산 수행
        for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }

        // 목표 값이 있는지 확인
        if (dp[i].count(number)) return i;
    }

    return -1;  // 8번보다 크면 -1 반환
}
