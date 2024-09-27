#include <stdio.h>

long factorial(int);
int main(void){
    int num;
    printf("정수를 입력하시오: ");
    scanf("%d",&num);
    printf("%d!은 %d입니다. \n",num,factorial(num));

    return 0;
}


long factorial(int num){
    long result = 1;
    for(int i=1;i<=num;i++){
        result *= i;
    }
        return result;
}