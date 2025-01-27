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

    int found = 0; // ��� �޴��� �߰ߵǾ����� ���θ� üũ

    for (int i = 0; i <= N - M; i++) { // N_arr���� ���ӵ� �κ� �迭 Ž��
        int match = 1; // ���� �κ� �迭�� M_arr�� ��ġ�ϴ��� Ȯ��
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
