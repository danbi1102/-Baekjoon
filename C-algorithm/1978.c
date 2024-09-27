#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>

int main(){

    int n; //n은 첫줄에 입력받는 총 수의 개수
    int num, count = 0; //num은 판별할 소수 후보들, count는 소수 개수 세기 위함

    scanf("%d", &n); //n은 총 수의 개수

    for(int i=0; i<n; i++){ //반복문은 첫줄 입력받은 총 수의 갯수만큼만 돌아가게
        scanf("%d", &num); //num의 숫자 중 소수 판별
        for(int j=2; j<=num; j++){ //소수는 1제외하고 판별하니까 ~ 2부터
            if(num==j){ //소수는 약수가 자기 자신 수와 1뿐임. 
                count++; //count에 소수 개수 하나 추가해줌
            }
            if(num%j==0){ //입력받은 수가 어떠한 수 j로 나누어진다면 소수가 아님. 
                break;
            }
        }
    }
    printf("%d",count); //count는 for문 내에서 소수인 갯수 늘려왔으니 그 수만큼 출력
    return 0;
}
