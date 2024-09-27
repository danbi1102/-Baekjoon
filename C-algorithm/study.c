#define _CRT_SECURE_NO_WARNINGS // 2진수 형식으로 출력
#include <stdio.h>

void print_binary(int x);

int main(void) {
    print_binary(9); 
}

void print_binary(int x) 
{
if (x > 0) {

    print_binary(x / 2);// 재귀 호출
    printf("%d", x % 2);// 나머지를 출력 }

    }
}