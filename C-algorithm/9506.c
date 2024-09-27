#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int n;

    while(1){
        scanf("%d",&n);

        if(n==-1){
            return 0;
        }

        int arr[10000]={0,}; //약수 저장하는 배열
        int cnt= 0; //배열에 저장된 약수의 개수
        int sum =0; //배열에 저장된 약수의 합

        for(int i=1;i<n;i++){
            if(n%i==0){ //i로 나누어지면 약수, 약수 개수만큼의 배열에 i 대입
                arr[cnt]=i; 
                sum +=i; //배열 저장된 약수 합에 i 추가
                cnt ++;
            }
        }

        if(sum==n){
            printf("%d = ",n);
            for(int i=0; i<cnt; i++){ //배열에 저장된 약수 수만큼 for문 돌림
                printf("%d",arr[i]); //arr배열의 i번째 약수 출력
                if(i != cnt-1){ //마지막 약수 뒤에는 + 출력 안 하려고 있는 조건
                    printf(" + ");
                }
            }
            printf("\n");
        }
        else{
            printf("%d is NOT perfect.\n",n);
        }
    }
    return 0;
}