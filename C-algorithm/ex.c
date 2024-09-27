#include <stdio.h>
int main(void){

    int arr[30];
    int sum = 0;
    int count = 0;

    while(1){
        scanf("%d",&arr[count]);
        if(arr[count]== -1){
            break;
        }
        sum += arr[count];
    }
    printf("count: %d, sum: %d\n", count, sum);
    return 0;

    }
    
