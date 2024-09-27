#include <stdio.h>
int main(void){
    
    int arr[10];

    printf("Input : ");
    for ( int i = 1; i<=10; i++){
        scanf("%d", &arr[i]);
    }

    printf("Output1 : ");
    for (int i = 10; i>0; i--){
        printf("%d ",arr[i]);
    }
    printf("\n");

    arr[2]=999;

    printf("Output2 : ");
    for(int i = 10; i > 0; i--){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}