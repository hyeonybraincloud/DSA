#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Number{
    char original[20];   // 원본 문자열 저장용 (최대 "100.999" 정도 가정, 여유 있게 20)
    int integerPart;     // 정수 부분
    int decimalPart;     // 소수 부분 (최대 세 자리)
    int hasDecimal;      // 소수점 존재 여부 (1: 있음, 0: 없음)
} Number;

// 비교 함수 (qsort용)
int compare(void* a, void* b) {
    Number* numA = (Number*)a;
    Number* numB = (Number*)b;

    // 1) 정수 부분 비교
    if (numA->integerPart < numB->integerPart) {
        return -1;
    }
    else if (numA->integerPart > numB->integerPart) {
        return 1;
    }

    // 2) 정수 부분 같을 때, 소수점 유무 비교
    if (numA->hasDecimal == 0 && numB->hasDecimal == 1) {
        return -1;  // A 쪽이 더 작음
    }
    else if (numA->hasDecimal == 1 && numB->hasDecimal == 0) {
        return 1;   // B 쪽이 더 작음
    }

    // 3) 둘 다 소수점이 있으면 소수 부분 비교
    if (numA->decimalPart < numB->decimalPart) {
        return -1;
    }
    else if (numA->decimalPart > numB->decimalPart) {
        return 1;
    }

    // 모두 같으면 동등
    return 0;
}

int main(void) {
    int N;
    scanf("%d", &N);
    getchar(); // 버퍼에 남은 개행 문자 제거

    Number* arr = (Number*)malloc(sizeof(Number) * N);

    for (int i = 0; i < N; i++) {
        // 입력 받기
        fgets(arr[i].original, sizeof(arr[i].original), stdin);
        // 개행 문자 제거
        arr[i].original[strcspn(arr[i].original, "\n")] = '\0';

        // 파싱
        char* dot = strchr(arr[i].original, '.');
        if (dot == NULL) {
            // 소수점이 없는 경우
            arr[i].integerPart = atoi(arr[i].original);
            arr[i].decimalPart = 0;
            arr[i].hasDecimal = 0;
        }
        else {
            // 소수점이 있는 경우
            // 정수 부분
            *dot = '\0'; // 소수점을 구분자처럼 쓰기 위해 일시적으로 '\0' 처리
            arr[i].integerPart = atoi(arr[i].original);

            // 소수 부분
            char* decimalStr = dot + 1;
            arr[i].decimalPart = atoi(decimalStr);
            arr[i].hasDecimal = 1;

            // 소수점을 원상 복구할 필요는 없음(이미 구조체에 필요한 정보는 모두 담았음)
            *dot = '.';
        }
    }

    // 정렬
    qsort(arr, N, sizeof(Number), compare);

    // 출력
    for (int i = 0; i < N; i++) {
        printf("%s\n", arr[i].original);
    }

    free(arr);
    return 0;
}