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

## 2. `fgets()`와 `strcspn`
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
