#include <stdio.h>
#include <stdlib.h>

#define n_MAX 100

typedef struct __Radius {
    int r;
    int cnt;
} Radius;

// 선형 탐색 (배열이 크지 않으므로 이 방법이 더 나음)
int find_index(Radius rr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (rr[i].r == target) return i;
    }
    return -1;
}

// 비교 함수 (카운트 기준 내림차순 정렬)
int compare(const void* a, const void* b) {
    return ((Radius*)b)->cnt - ((Radius*)a)->cnt;
}

int heater[n_MAX];
Radius radius[n_MAX];

int main(void) {
    int n;
    int count = 0;  // radius 배열의 실제 사용 크기

    scanf("%d", &n);

    for (int idx = 0; idx < n; idx++)
        scanf("%d", &heater[idx]);

    // 난로의 반지름 길이 분석
    for (int idx = 0; idx < n; idx++) {
        for (int i = 2; i <= heater[idx]; i++) {
            if (heater[idx] % i == 0) {
                int where = find_index(radius, count, i);

                if (where == -1) {  // 새로운 값이면 추가
                    radius[count].r = i;
                    radius[count].cnt = 1;  // 반드시 1로 초기화
                    count++;
                }
                else {
                    radius[where].cnt++;  // 기존 값이면 개수 증가
                }
            }
        }
    }

    // 정렬 (가장 많이 등장한 반지름이 최우선)
    qsort(radius, count, sizeof(Radius), compare);

    // 결과 출력
    printf("%d\n", radius[0].cnt);

    return 0;
}
