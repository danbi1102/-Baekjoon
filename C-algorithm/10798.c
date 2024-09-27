#define NO_SECURE_WARNINGS
#include <stdio.h>

int main(){
    char arr[5][15]={0,};

    for(int i=0; i<5; i++)
        scanf("%s",arr[i]);

    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            if (arr[j][i]!='\0'){
                printf("%c",arr[j][i]);
            }
                
        }
    }
return 0;
}