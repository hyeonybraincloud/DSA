#include <stdio.h>
#include <math.h>

int main(void)
{
    int N;

    scanf("%d", &N);

    int result = 2;

    for (int i = 1; i <= N; i++)
        result += pow(2, i - 1);

    result *= result;

    printf("%d\n", result);

    return 0;
}