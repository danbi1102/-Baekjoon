#include <stdio.h>
int main()
{

    int testcase, charge, quarter, dime, nickel, penny = 0;
    scanf("%d", &testcase);
    for (int i = 0; i < testcase; i++)
    {
        scanf("%d", &charge);
        quarter = charge / 25, charge -= quarter * 25;
        dime = charge / 10, charge -= dime * 10;
        nickel = charge / 5, charge -= nickel * 5;
        penny = charge;

        printf("%d %d %d %d", quarter, dime, nickel, penny);
    }
    return 0;
}