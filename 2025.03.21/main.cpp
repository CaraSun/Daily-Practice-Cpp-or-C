

void fun(int array[3]) {
    printf("fun:sizeof(array) = %d\n", sizeof(array));
}
#include <stdio.h>
int main() {
    int array[3] = {1, 2, 3};
    long int a = 6789012345L;
    printf("main:sizeof(array) = %d\n", sizeof(array));
    printf("sizeof(long int) = %d\n", sizeof(a));
    fun(array);
    return 0;
}