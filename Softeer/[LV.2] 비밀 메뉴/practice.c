#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int M, N, K;

    scanf("%d %d %d", &M, &N, &K);

    int* M_arr = (int*)malloc(M * sizeof(int));
    int* N_arr = (int*)malloc(N * sizeof(int));

    for (int idx = 0; idx < M; idx++)
        scanf("%d", &M_arr[idx]);

    for (int idx = 0; idx < N; idx++)
        scanf("%d", &N_arr[idx]);

    int found = 0; // 비밀 메뉴가 발견되었는지 여부를 체크

    for (int i = 0; i <= N - M; i++) { // N_arr에서 연속된 부분 배열 탐색
        int match = 1; // 현재 부분 배열이 M_arr와 일치하는지 확인
        for (int j = 0; j < M; j++) {
            if (N_arr[i + j] != M_arr[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("secret\n");
    else
        printf("normal\n");

    free(M_arr);
    free(N_arr);
    return 0;
}
