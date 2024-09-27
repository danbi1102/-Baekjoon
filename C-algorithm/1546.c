#include <stdio.h>
int main(void){
    int n;
    double arr[1001];
    double max=0, sum=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%lf",&arr[i]);

        if(arr[i]>max){
            max = arr[i];
        }
    }
    for(int i=0;i<n;i++){
        arr[i] = arr[i]/max*100;
        sum+=arr[i];
    }
    printf("%.2f",sum/(double)n);
    return 0;
}