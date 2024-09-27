#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_strings(char** strings, int n);
// 입력받은 문자열을 동적 메모리에 저장하는 함수
// strings: 문자열을 저장할 이중 포인터 배열입
// n: 저장할 문자열의 개수

void print_strings(char** strings, int n);
// 저장된 문자열을 출력하는 함수
// strings: 저장된 문자열을 가리키는 이중 포인터 배열
// n: 저장된 문자열의 개수

int main() {
    int n;
    printf("문자열의 개수: ");
    scanf("%d", &n);

    char* strings = malloc(n * sizeof(char)); // 입력받을 문자열을 저장할 동적 메모리를 할당
    if (strings == NULL) {
        printf("동적 메모리 할당 오류\n");
        return 1;
    }

    get_strings(strings, n);
    print_strings(strings, n);

    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }

    free(strings);

    return 0;
}

void get_strings(char** strings, int n) {
    char input[100];

    for (int i = 0; i < n; i++) {
        printf("문자열을 입력하시오: ");
        scanf("%s", input);

        strings[i] = malloc(100 * sizeof(char)); // 문자열을 저장할 동적 메모리를 할당합니다.
        if (strings[i] == NULL) {
            printf("동적 메모리 할당 오류\n");
            return;
        }

        strcpy(strings[i], input);
    }
}

void print_strings(char** strings, int n) {
    printf("### 입력된 문자열:\n");
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("\"%s\"", strings[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}