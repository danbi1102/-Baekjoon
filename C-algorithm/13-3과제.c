#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct cont{
    char name[100];
    char phone[100];
} CONTACT;

void get_contacts(CONTACT *conts, int n);
// 사용자로부터 주소록 정보를 입력받는 함수
// conts: CONTACT 구조체를 가리키는 포인터 
//  n: 주소록의 개수
void print_contacts(CONTACT *conts, int n);
// 주소록 정보를 출력하는 함수
// conts: CONTACT 구조체를 가리키는 포인터 
// n: 주소록의 개수


int main() {
    int n;
    printf("주소의 개수: ");
    scanf("%d", &n);

    CONTACT *conts = (CONTACT*) malloc(n * sizeof(CONTACT));
    if (conts == NULL) {
        printf("동적 메모리 할당 오류\n");
        return 1;
    }

    get_contacts(conts, n);
    printf("==============================\n");
    printf("이름\t\t휴대폰 번호\n");
    printf("==============================\n");
    print_contacts(conts, n);
    printf("==============================\n");

    free(conts);

    return 0;
}

void get_contacts(CONTACT *conts, int n) {
    for (int i = 0; i < n; i++) {
        printf("이름을 입력하시오: ");
        scanf("%s", conts[i].name);
        printf("휴대폰 번호를 입력하시오: ");
        scanf("%s", conts[i].phone);
    }
}

void print_contacts(CONTACT *conts, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%s\n", conts[i].name, conts[i].phone);
    }
}