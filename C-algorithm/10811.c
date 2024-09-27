#include <stdio.h>
int main(void){

    int n,m,a,b,temp;
    scanf("%d %d",&n,&m);
    int bas[101]={0,};

    for(int i=0; i<=n; i++){
        bas[i]=i;
    }

    for(int i=0; i<m; i++){
        scanf("%d %d",&a,&b);
        for(int j=a; j<=b; j++){
            temp = bas[a];
            bas[a] = bas[b];
            bas[b] = temp;
            a++; 
            b--; //a는 늘리고 b는 줄여야지 역순으로 출력
        }
    }
    for(int i =1;i<=n;i++){
        printf("%d ",bas[i]);
    }
    return 0;
}