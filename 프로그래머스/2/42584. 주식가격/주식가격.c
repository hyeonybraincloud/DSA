#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    int* answer = (int*)malloc(sizeof(int) * prices_len);
    int* stack = (int*)malloc(sizeof(int) * prices_len);  // 스택용 배열
    int top = -1;  // 스택의 top 인덱스

    for (int i = 0; i < prices_len; i++) {
        while (top >= 0 && prices[i] < prices[stack[top]]) {
            int idx = stack[top--];
            answer[idx] = i - idx;
        }
        stack[++top] = i;
    }

    while (top >= 0) {
        int idx = stack[top--];
        answer[idx] = prices_len - 1 - idx;
    }

    free(stack);
    return answer;
}
