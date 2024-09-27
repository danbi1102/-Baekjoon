#include <stdio.h>
int main()
{
    int arr[7] = {1, 1, 2, 2, 2, 8};
    int a;
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &a);
        printf("%d ", arr[i] - a);
    }
    return 0;
}