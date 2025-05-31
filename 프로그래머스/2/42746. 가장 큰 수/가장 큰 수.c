#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 두 숫자를 문자열로 이어붙인 결과를 비교하여 정렬 순서를 결정하는 함수
int compare(const void *a, const void *b) {
    char ab[9], ba[9];
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    return strcmp(ba, ab);  // 내림차순 정렬
}

char* solution(int numbers[], size_t numbers_len) {
    // 정렬
    qsort(numbers, numbers_len, sizeof(int), compare);

    // 전체 결과 길이 계산 (최대 4자리 숫자 * 개수 + 1)
    char *answer = malloc(numbers_len * 4 + 1);
    answer[0] = '\0';

    for (int i = 0; i < numbers_len; i++) {
        char buffer[5];
        sprintf(buffer, "%d", numbers[i]);
        strcat(answer, buffer);
    }

    // "000..." 같은 경우는 "0"으로 처리
    if (answer[0] == '0') {
        answer[1] = '\0';
    }

    return answer;
}

// 테스트용 메인 함수
int main() {
    int numbers1[] = {6, 10, 2};
    char* result1 = solution(numbers1, 3);
    printf("%s\n", result1);  // 출력: 6210
    free(result1);

    int numbers2[] = {3, 30, 34, 5, 9};
    char* result2 = solution(numbers2, 5);
    printf("%s\n", result2);  // 출력: 9534330
    free(result2);

    return 0;
}
