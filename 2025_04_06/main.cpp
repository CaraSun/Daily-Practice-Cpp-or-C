#include <stdlib.h>
#include <stdio.h>
#include <string.h>

union test{
    int d1;
    float d2;
    int d3;
}d;

int main()
{
    d.d1=10;
    printf("d1:   %d\n",d.d1);
    printf("d2:   %d\n",d.d2);
    printf("d3:   %d\n",d.d3);
    printf("Addr of d: %p\n",&d);
    printf("Addr of d1: %p\n",&d.d1);
    printf("Addr of d2: %p\n",&d.d2);

    return 0;
}