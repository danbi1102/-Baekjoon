#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} NODE;

int get_integer(); // 양의 정수를 입력 받는 함수
void print_list(NODE* plist); // 연결 리스트를 출력하는 함수, plist는 연결리스트 받기위한 매개변수
void free_list(NODE* plist); // 연결 리스트의 노드들을 해제하는 함수, plist는 연결리스트 받기위한 매개변수

int main() {
    NODE* plist = NULL; 

    while (1) {
        int num = get_integer(); 

        if (num < 0) 
            break;

        NODE* newNode = (NODE*)malloc(sizeof(NODE));
        newNode->data = num;
        newNode->link = NULL;

        if (plist == NULL) { 
            plist = newNode;
        } else { 
            NODE* current = plist;
            while (current->link != NULL)
                current = current->link;
                current->link = newNode;
        }
    }

    print_list(plist); 
    free_list(plist); 

    return 0;
}

int get_integer() {
    int num;
    printf("양의 정수를 입력하시오 (종료하려면 -1을 입력): ");
    scanf("%d", &num);
    return num;
}

void print_list(NODE* plist) {
    if (plist == NULL) {
        printf("연결 리스트가 비어 있습니다.\n");
        return;
    }

    NODE* current = plist;

    printf("###입력된 연결 리스트: ");

    while (current != NULL) {
        printf("%d", current->data);
        if (current->link != NULL)
            printf("->");
        else
            printf("->NULL");
        current = current->link;
    }

    printf("\n");
}

void free_list(NODE* plist) {
    NODE* current = plist;

    while (current != NULL) {
        NODE* temp = current;
        current = current->link;
        free(temp);
    }
}