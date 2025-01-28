#include <stdio.h>

int main(void) {
    int N, K;

    scanf("%d %d", &N, &K);

    int* S_arr = (int*)malloc(sizeof(int) * N);
    int* A_arr = (int*)malloc(sizeof(int) * K);
    int* B_arr = (int*)malloc(sizeof(int) * K);

    for (int idx = 0; idx < N; idx++)
        scanf("%d", &S_arr[idx]);

    for (int idx = 0; idx < K; idx++)
        scanf("%d %d", &A_arr[idx], &B_arr[idx]);

    for (int i = 0; i < K; i++) {
        double avg = 0.0;
        for (int j = A_arr[i] - 1; j < B_arr[i]; j++)
            avg += (double)S_arr[j];

        avg /= (double)(B_arr[i] - A_arr[i] + 1);
        printf("%.2f\n", avg);
    }

    free(S_arr);
    free(A_arr);
    free(B_arr);

    return 0;
}