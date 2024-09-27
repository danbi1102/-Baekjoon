#include <stdio.h>
int main(void){

    int n,m,a,b,temp;
    int arr[101]={0}; 

    /* n은 바구니개수, m은 공 바꾸는 횟수, 
    a는 바구니1 b는 바구니2, temp는 공 임시저장 변수, arr은 바구니 배열  */

    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        arr[i] = i;} //일단 각 바구니에 처음 적힐 숫자 넣기
        for(int k = 0; k<m; k++){
            scanf("%d %d",&a,&b);
            temp = arr[a];
            arr[a]= arr[b];
            arr[b] = temp;
        } //temp라는 새로운 변수 하나 잡아서 각 바구니 숫자 바꾸기. m번(공바꾸는 횟수만큼)


    for(int i=1; i<=n; i++){
        printf("%d ",arr[i]); //바구니 개수 n번 바구니까지 든 숫자 출력
    }
return 0;
}