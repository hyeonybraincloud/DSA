# [Lv. 2] GPT 식 숫자 비교 

[문제 링크](https://softeer.ai/practice/11001)

## 1. `getchar()`
기능은 다음과 같이 두 가지가 있다.
### 1.1 여러 문자 입력 처리
```c
#include <stdio.h>

int main() {
    char c;

    printf("Enter a string (press Enter to stop): ");

    while ((c = getchar()) != '\n') { // Enter 입력 전까지 반복
        printf("You entered: %c\n", c);
    }

    return 0;
}
```

### 1.2 버퍼 비우기
`getchar()`은 버퍼의 잔여 문자를 제거할 때 종종 사용된다. 예를 들어, 숫자를 입력받은 후 문자를 입력받을 때 버퍼에 잔여하는 `\n`을 제거해야 하는 상황이 있을 수 있다.
```c
    int N;
    scanf("%d", &N);
    getchar(); // 버퍼에 남은 개행 문자 제거
```

## 2. `fgets()`와 `strcspn()`
### 2.1 본 코드에서 어떻게 사용했는가?
```c
// 입력 받기
fgets(arr[i].original, sizeof(arr[i].original), stdin);

// 개행 문자 제거
arr[i].original[strcspn(arr[i].original, "\n")] = '\0';
```

### 2.2 `fgets()` 사용법
```c
char *fgets(char *str, int size, FILE *stream);
```
그런데 `fgets()`은 개행 문자도 포함하므로, 문자열 끝의 `\n`을 제거하고 싶으면 수동으로 처리해야 한다. 그 방법이 다음과 같다.

### 2.3 `strcspn()` 사용법
`strcspn()` 함수는 문자열에서 특정 문자가 처음 나타나는 위치를 반환한다. 본 코드에서는 `\n`이 처음 나타나는 위치를 반환한다.

## 3. `strchr()`
`strchr()`은 특정 문자 하나를 찾아 위치(포인터)를 반환하는 함수이다. `strcspn()`은 길이(정수)를 반환한다는 점에서 차이가 있다.
```c
char *dot = strchr(arr[i].original, '.');
```

## 4. `atoi()`
```c
int atoi(const char *str)
```
문자열을 정수로 반환하는 함수이다.

## 5. qsort()
`qsort()`은 `<stdlib.h>` 헤더 파일에 정의되어 있는 일반적인 정렬 함수로, 배열을 효율적으로 정렬하기 위해 **퀵 정렬 알고리즘**을 기반으로 구현되었다.
```c
void qsort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
// void *base: 정렬할 배열의 시작 주소
// size_t num: 배열의 요소 개수
// size_t size: 배열 요소 하나의 크기(byte 단위)
// int (*compare)(const void *, const void *): 비교 함수에 대한 포인터. 두 요소의 상대적 순서를 결정하는 함수로, 사용자가 직접 정의해야 함.
```
### 5.1 본 코드에서는 어떻게 쓰였는가? 그리고 비교 함수에 대하여.
```c
// 비교 함수 (qsort용)
int compare(const void *a, const void *b) {
    Number *numA = (Number *)a;
    Number *numB = (Number *)b;

    // 1) 정수 부분 비교
    if (numA->integerPart < numB->integerPart) {
        return -1;
    } else if (numA->integerPart > numB->integerPart) {
        return 1;
    }

    // 2) 정수 부분 같을 때, 소수점 유무 비교
    if (numA->hasDecimal == 0 && numB->hasDecimal == 1) {
        return -1;  // A 쪽이 더 작음
    } else if (numA->hasDecimal == 1 && numB->hasDecimal == 0) {
        return 1;   // B 쪽이 더 작음
    }

    // 3) 둘 다 소수점이 있으면 소수 부분 비교
    if (numA->decimalPart < numB->decimalPart) {
        return -1;
    } else if (numA->decimalPart > numB->decimalPart) {
        return 1;
    }

    // 모두 같으면 동등
    return 0;
}

qsort(arr, N, sizeof(Number), compare);
```

**비교 함수**는 두 요소의 포인터를 받아, 정렬 순서를 결정하는 값을 반환한다.
- 음수: 첫 번째 요소가 두 번째 요소보다 앞에 있어야 함
- 0: 두 요소가 같음
- 양수: 첫 번째 요소가 두 번째 요소보다 뒤에 있어야 함

**※ 보충 설명**
```c
Number *numA = (Number *)a;
Number *numB = (Number *)b;
```
이 부분은 **포인터 캐스팅**을 통해 `void *`로 전달된 데이터를 개발자가 정의한 구조체 `Number`의 포인터로 변환하는 역할을 한다.
