#define _CRT_SECURE_NO_WARNIGNS
#include <stdio.h>

#define GET_BIT(n,pos) ((n)>> (pos) & 0x01)
#define SET_BIT(n,pos) ((n) |= (0x01 <<(pos)))
#define CLR_BIT(n,pos) ((n) &= ~(0x01 << (pos)))

int main(){

    int n = 0x000000f8, pos = 0;
    printf("n = %#08x\n",n);

    pos = 3;
    printf("GET_BIT(n,3)의 결과: %x\n", GET_BIT(n,pos));

    pos = 1;
    SET_BIT(n,pos);
    printf("SET_BIT(n,%d)의 결과: n=%#08x\n", pos, n);

    pos = 4;
    CLR_BIT(n,pos);
    printf("CLR_BIT(n,%d)의 결과: n=%#08x\n",pos,n);

    return 0;
}