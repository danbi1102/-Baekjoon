#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_file(FILE *fp); // 파일에서 읽은 내용 화면에 출력하는 함수, fp는 읽을 파일의 파일 포인터

void convert_to_lower(FILE *fp1, FILE *fp2); /*파일에서 읽은 알파벳을 소문자로 변환해서 다른 파일에 저장하는 함수
fp1 : 변환할 원본 파일의 파일 포인터
fp2: 변환된 내용을 저장할 파일의 파일 포인터
*/

int main(void)
{

    FILE *fp1, *fp2;

    char fname1[100], fname2[100];

    printf("첫번째 파일: ");
    scanf("%s", fname1);

    printf("두번째 파일: ");
    scanf("%s", fname2);

    fp1 = fopen(fname1, "r");
    fp2 = fopen(fname2, "w+");

    if (fp1 == NULL)
    {

        printf("파일 <%s> 을 열 수 없습니다.\n ", fname1);

        exit(1);
    }

    if (fp2 == NULL)
    {

        printf("파일 <%s> 을 열 수 없습니다.\n ", fname2);

        exit(1);
    }

    printf("### 원본 파일 ###\n");
    print_file(fp1);
    rewind(fp1);

    convert_to_lower(fp1, fp2);

    printf("### 변환된 파일 ###\n");
    rewind(fp2);
    print_file(fp2);

    fclose(fp1);
    fclose(fp2);

    return 0;
}

void print_file(FILE *fp)
{

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), fp))
    {
        printf("%s", buffer);
    }
}

void convert_to_lower(FILE *fp1, FILE *fp2)
{

    int c;

    while (
        (c = fgetc(fp1)) != EOF)
    {

        c = tolower(c);

        fputc(c, fp2);
    }
}
