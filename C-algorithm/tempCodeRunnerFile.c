#include <stdio.h>

int combination(int n, int r)
{
    return (factorial(n)/(factorial(n-r)*factorial(r)));
}

int get_int(void){
    int n;
    printf("정수를 입력하시오: ");
    scanf("%d",&n);

    return n;
}

int factorial(int n){

    long result =1;

    for(int i=1;i<=n;i++)
        result *= i;
    
    return result;
}

int main(void){

    int a,b;

    a=get_int();
    b=get_int();

    printf("C(%d,%d) = %d\n",a,b,combination(a,b));

    return 0;
}