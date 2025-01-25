#include <stdio.h>


int main(void)
{
    int arr[8];
    int satisfied_ascending = 0;
    int satisfied_descending = 0;

    for (int idx = 0; idx < sizeof(arr) / sizeof(int); idx++) {
        scanf("%d", &arr[idx]);
    }

    for (int idx = 1; idx < sizeof(arr) / sizeof(int); idx++) {
        if (arr[idx] - arr[idx - 1] == 1)
            satisfied_ascending++;
        else if (arr[idx] - arr[idx - 1] == -1)
            satisfied_descending++;
    }

    if (satisfied_ascending == 7)
        printf("ascending\n");
    else if (satisfied_descending == 7)
        printf("descending\n");
    else
        printf("mixed\n");

    return 0;
}