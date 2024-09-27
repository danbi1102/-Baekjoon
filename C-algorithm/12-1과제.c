#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

#define INIT_ARRAY(array,size,value) for(int i=0; i<size; i++) array[i] = value;
   
int main(){
    int a[SIZE];
    int value=1;

    printf("배열을 초기화할 정수를 입력하시오: ");
    scanf("%d",&value);

    INIT_ARRAY(a,SIZE,value);

    printf("초기화된 배열 a=[");
    for(int i=0; i<SIZE; i++){
        printf("%d", a[i]);

        if(i != SIZE-1)
            printf(",");
        else
            break;
    }
    printf("]\n");

    return 0;

}