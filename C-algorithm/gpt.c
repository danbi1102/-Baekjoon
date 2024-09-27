#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void write_files(FILE *fp1, FILE *fp2, int n);
void print_files(FILE *fp1, FILE *fp2, int n);

int main() {
    FILE *fp1, *fp2;
    char fname1[100], fname2[100];

    printf("첫번째 파일명을 입력하세요: ");
    scanf("%s", fname1);

    printf("두번째 파일명을 입력하세요: ");
    scanf("%s", fname2);

    fp1 = fopen(fname1, "w");
    fp2 = fopen(fname2, "wb");

    if (fp1 == NULL) {
        printf("파일 %s을 열 수 없습니다.\n", fname1);
        return 1;
    }

    if (fp2 == NULL) {
        printf("파일 %s을 열 수 없습니다.\n", fname2);
        return 1;
    }

    printf("### 파일 크기 비교 ###\n");

    write_files(fp1, fp2, SIZE);

    fseek(fp1, 0, SEEK_END);
    fseek(fp2, 0, SEEK_END);
    int file1_size = ftell(fp1);
    int file2_size = ftell(fp2);

    printf("텍스트 파일 크기: %d\n", file1_size);
    printf("이진 파일 크기: %d\n", file2_size);

    rewind(fp1);
    rewind(fp2);

    printf("### 텍스트 파일 출력 ###\n");
    print_files(fp1, NULL, SIZE);

    printf("### 이진 파일 출력 ###\n");
    print_files(NULL, fp2, SIZE);

    fclose(fp1);
    fclose(fp2);

    return 0;
}

void write_files(FILE *fp1, FILE *fp2, int n) {
    srand(time(0));

    if (fp1 != NULL)
        fprintf(fp1, "### 텍스트 파일 출력 ###\n");

    if (fp2 != NULL)
        fwrite("### 이진 파일 출력 ###\n", sizeof(char), 21, fp2);

    for (int i = 0; i < n; i++) {
        int num = rand() % 100;
        if (fp1 != NULL)
            fprintf(fp1, "%d\n", num);
        if (fp2 != NULL)
            fwrite(&num, sizeof(int), 1, fp2);
    }
}

void print_files(FILE *fp1, FILE *fp2, int n) {
    int value;
    FILE *file = (fp1 != NULL) ? fp1 : fp2;

    while (fscanf(file, "%d", &value) != EOF) {
        printf("%d\n", value);
    }
}
