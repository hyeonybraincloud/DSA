#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 만약 N의 최댓값이 10^9 정도라면 2^31까지도 21억 정도이므로 크게 문제 안될 수 있음.
// N의 최댓값이 10^18 근처라면 K가 60을 넘어가면 2^K가 10^18을 초과할 수 있음.

int main(void)
{
    int T;
    scanf("%d", &T);

    while(T--) {
        long long N, K;
        scanf("%lld %lld", &N, &K);

        // 만약 2^K > N 이면 자동으로 답은 0
        // 1LL << K가 오버플로우날 수 있으므로 K 비교를 먼저 해준다.
        if(K >= 63) {
            // 2^63 = 9223372036854775808 > any 64비트 signed
            // -> 이 경우 N이 최대 10^18이라고 해도 2^K > N 이므로 답은 무조건 0
            printf("0\n");
            continue;
        }
        long long pow2K = 1LL << K; // 2^K

        if(pow2K > N) {
            printf("0\n");
            continue;
        }

        // floor(N / 2^K)
        long long M = N / pow2K;

        // (M+1)//2 : 1..M 중 홀수의 개수
        long long ans = (M + 1) / 2;

        printf("%lld\n", ans);
    }

    return 0;
}
