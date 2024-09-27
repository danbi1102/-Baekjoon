#include <stdio.h>
int main(void){
    int a,b = 0; //a는 입력받는거 b는 서로 다른 값 세는 거
    int arr[43] ={0,};
    int res=0;
    for ( int i=0;i<10;i++){
        scanf("%d ",&a);
        int mod = a%42; //mod는 나머지
        if(arr[mod]==0){ //바로바로 배열에서 한번 나왔는지 확인하고 안나왔다면 숫자 늘리기
            res++;
            arr[mod]++;
        }
    }
    printf("%d\n",res);
}