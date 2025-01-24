#include <stdio.h>
#include <stdlib.h>

// 구조체 정의
typedef struct Bid{
    int A; // MOLOCO 입찰가
    int B; // 다른 회사의 최고 입찰가
} Bid;

// 낙찰 가능한 지면 수 계산
int countWins(Bid* bids, int N, int X) {
    int wins = 0;

    for (int i = 0; i < N; i++) {
        if (bids[i].A + X >= bids[i].B)
            wins++;
    }

    return wins;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Bid* bids = (Bid*)malloc(sizeof(Bid) * N);

    // 입력 받기
    for (int i = 0; i < N; i++)
        scanf("%d %d", &bids[i].A, &bids[i].B);

    // 이진 탐색
    int left = 0, right = 1000000000, X = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (countWins(bids, N, mid) >= K) {
            X = mid; // 가능한 X 저장
            right = mid - 1; // 더 작은 X를 찾기 위해 탐색 범위 축소
        }
        else
            left = mid + 1; // 더 큰 X를 찾기 위해 탐색 범위 확대
    }

    // 결과 출력
    printf("%d\n", X);

    // 메모리 해제
    free(bids);

    return 0;
}
