#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define GET_BIT(n,pos) ((n)>>(pos) & 0x01)

void print_bits(int value);

int main(){

    int n,move,bit,after;

    printf("정수값을 입력하시오: ");
    scanf("%d",&n);

    printf("왼쪽 이동은 0, 오른쪽 이동은 1을 입력하시오(-1은 Quit): ");
    scanf("%d", &move);

    if(move==-1)
    break;

    printf("이동시킬 비트 수를 입력하시오: ");
    scanf("%d",&bit);

    printf("이동 전: ");
    
    print_bits(n);

    if(move==0){
        prinf("이동 후: ");
        after = (n<<bit);
        print_bits(after);
    }
    else if(move==1){
        printf("이동 후: ");
        after = (n>>bit);
        print_bits(after);
    }
    
    return 0;
}