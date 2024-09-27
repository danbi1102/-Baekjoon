#include <stdio.h>

long factorial(int num){
    long result;
    for(int i=1;i<=num;i++){
        result *= i;
        return result;
    }
}

int main(void){
    int num =0;;
    printf("정수를 입력하시오: ");
    scanf("%d",&num);
    printf("%d!은 %d입니다. \n",num,factorial(num));

    return 0;
}