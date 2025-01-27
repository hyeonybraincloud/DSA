#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int n, q;

    // ют╥б
    scanf("%d %d", &n, &q);

    int* fuel_arr = (int*)malloc(sizeof(int) * n);
    int* m_arr = (int*)malloc(sizeof(int) * q);

    for (int idx = 0; idx < n; idx++)
        scanf("%d", &fuel_arr[idx]);

    for (int idx = 0; idx < q; idx++)
        scanf("%d", &m_arr[idx]);

    // quick sorting
    qsort(fuel_arr, n, sizeof(int), compare);

    for (int idx = 0; idx < q; idx++) {
        int where = binary_search(fuel_arr, n, m_arr[idx]);

        if (where == -1)
            printf("0\n");
        else {
            printf("%d\n", where * (n - (where + 1)));
        }
    }

    free(fuel_arr);
    free(m_arr);

    return 0;
}