#include <stdio.h>

#define SIZE 10

int main()
{
    int list[SIZE] = {3, 2, 9, 7, 1, 4, 8, 0, 6, 5};
    int temp, least;

    for (int i = 0; i < SIZE - 1; i++)
    {
        least = i;

        for (int j = i + 1; j < SIZE; j++)
        {
            if (list[j] < list[least])
                least = j;
        }

        temp = list[i];
        list[i] = list[least];
        list[least] = temp;

        for (int k = 0; k < SIZE; k++)
            printf("%d ", list[k]);
    }
    printf("\n");

    return 0;
}

typedef struct listNode *listpointer
{
    int data;
    listpointer link;
};