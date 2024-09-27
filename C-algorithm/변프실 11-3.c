#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

struct product {
char pid[20];
double price;
double number;
};

void find_total(FILE* fp, int n); //파일에서 데이터를 읽고 출력하는 함수, fp는 파일의 포인터변수, n은 사이즈를 받기 위한 변수
int main() {
 
char fname[100];
 
FILE* fp;
 
printf("파일명을 입력하시오: ");
scanf("%s", fname);
 
fp = fopen(fname, "r");
 
if (fp == NULL) {
 
printf("파일<%s>을 열 수 없습니다.", fname);
 
return 1;
 
}
 
printf("### 제품 판매 데이터 ###");
 
find_total(fp, SIZE);
 
fclose(fp);
 
return 0;
}
void find_total(FILE* fp, int n) {
 
struct product p;
 
double total = 0.0;
 
for (int z = 0; z < n; z++)
 
{
 
fread(&p, sizeof(struct product), 1, fp);
 
printf("pid = %s, price = %.2f, number = %.0f\n", p.pid, p.price, p.number);
 
total += p.price * p.number;
 
}
 
printf("###판매총액 : %.2lf", total);
}