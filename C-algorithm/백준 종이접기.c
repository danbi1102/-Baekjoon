#include <stdio.h>

int main() {
    int Drawing_paper[100][100] = {{0,}}; //도화지 그리기. 모든 값을 0으로 설정한 후, 놓을 때마다 1씩 더하기
    int count; //색종이 개수 
    int x, y; // 모서리 좌표

    scanf("%d", &count); // 개수 받기

    int sum = count*100; //색종이 기본 넓이, 나중에 겹치는 부분은 아래에서 빠짐. 
    
    //printf("%d\n", sum); //확인하고 싶을 때 주석 때기.

    //도화지를 좌표처럼 생각하고, 좌표 기준으로 가로 10, 세로 10씩 추가하기. 

    for(int i=0; i<count; i++) { //색종이 개수만큼 반복하기.
        scanf("%d %d",&x, &y); //x,y 좌표를 받고 
        for (int j=0; j<10; j++) { //가로 10
            for (int k=0; k<10; k++) { //세로 10
                Drawing_paper[x+j][y+k] += 1; //10x10 씩 1추가. 겹칠 경우에는 1->2가 된다. 
            }
        }
    }
    

    for(int i=0; i<100; i++) { 
        for(int j=0; j<100; j++) {
            if (Drawing_paper[i][j]!=1&&Drawing_paper[i][j]!=0) { //0은 기본 도화지, 1은 겹치지 않기에, 처음 구한 넓이에 포함됨. 
                sum = sum-(Drawing_paper[i][j]-1); // 2가 겹치는 부분 -> 넓이는 1을 빼줘야됨. 
            }
        }
    }



    //도화지 확인하고 싶을 때, 주석 때기. 

    /*
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            printf("%d ", Drawing_paper[i][j]);
        }
        printf("\n");
    }
    */


    printf("%d", sum);


    return 0;
}