#include <stdio.h>

int factorial(int n) {
    if (n == 1) {  // n이 1일 경우, 1을 반환
        return 1;
    }
    else {  // n이 1이 아닐 경우, n * (n-1)!를 반환
        return n * factorial(n-1);
    }
}

int main() {
    int n;
    printf("정수를 입력하세요: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, factorial(n));
    return 0;
}