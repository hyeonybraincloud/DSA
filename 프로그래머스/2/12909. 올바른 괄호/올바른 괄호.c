#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(const char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len);  // 최대 len 만큼의 스택 필요
    int top = -1;  // 스택의 인덱스 초기화

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = '(';  // push
        } else {  // s[i] == ')'
            if (top == -1) {
                free(stack);
                return false;  // 짝 맞는 여는 괄호가 없음
            }
            top--;  // pop
        }
    }

    bool result = (top == -1);  // 스택이 비어 있으면 true
    free(stack);
    return result;
}
