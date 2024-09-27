#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[101];
    scanf("%s", word);

    char eng[26];
    int num[26];

    for (int i = 0; i < 26;)
    {
        num[i] = -1;
    }

    for (int i = 0; i < 26; i++)
    {
        eng[i] = i + 97;
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (word[i] == eng[i])
            {
                num[i] = j;
            }
            if (word[j] == 0)
                break;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%d ", num[i]);
    }

    return 0;
}