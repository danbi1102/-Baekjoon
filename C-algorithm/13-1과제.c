#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void get_numbers(int *numbers,int n);
/* 사용자로부터 정수 입력받아 numbers 배열에 저장하는 함수
numbers : 정수들 저장하는 배열
n : 입력받는 정수의 개수
*/
void print_numbers(int *numbers, int n);
/* 입력받은 정수들과 그 합계들을 출력하는 함수
numbers : 입력받은 정수들이 저장된 배열
n : 입력받은 정수의 개수
*/

int main(void) 
{
    int count;
    printf("정수의 개수: ");
    scanf("%d",&count);

    int *numbers = (int *)malloc(count *sizeof(int));
    //count 만큼 크기로 동적메모리 할당 받음
    //numbers: 정수들 저장하는 배열의 포인터
    if(count<1){
        printf("동적 메모리 할당 오류\n");
        return 1;
    }

    get_numbers(numbers, count); //정수 입력받아 numbers 배열에 저장
    print_numbers(numbers, count); //입력받은 정수, 그 합계 출력

    free(numbers); // 동적할당된 메모리 해제

    return 0;
}

void get_numbers(int *numbers, int n){
    
    for(int i=0;i<n;i++){
        printf("양의 정수를 입력하시오: ");
        scanf("%d",&numbers[i]);
    }

}

void print_numbers(int *numbers, int n){
    int sum = 0;
    printf("###입력된 정수: ");
    
    for(int i=0; i<n; i++){
        printf(" %d",numbers[i]);
        sum +=numbers[i];

    }
    printf("\n### 입력된 정수들의 합: %d\n",sum);
    
}

