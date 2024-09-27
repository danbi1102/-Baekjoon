#include <stdio.h>

int main(void){

    int n,m;
    int arr[101] = {0,};
    int i,j,k;

    scanf("%d %d",&n,&m);

    for(int a=0; a<m; a++){
        scanf("%d %d %d",&i,&j,&k);
        for(int b = i; b<=j; b++ ){
            arr[b] = k;
        }
    }
    for(int c = 1; c<=n; c++){
        printf("%d ",arr[c]);
    }
return 0;
}