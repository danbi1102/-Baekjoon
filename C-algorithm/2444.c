#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        for(int z=n-i; z>0; z--){
            printf(" ");
        }

        for(int j =2*i-1; j>0; j--){
            printf("*");
        }

        printf("\n");
    }

    for(int i = n-1; i>0; i--){
        for(int z=n-i; z>0; z--){
            printf(" ");
        }

        for(int j=2*i-1; j>0; j--){
            printf("*");
        }

        printf("\n");
    }
    return 0;
}