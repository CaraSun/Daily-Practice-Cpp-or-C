#include <stdio.h>

int main() {
    char str[31];
    int i;

    printf("enter your name :");
    scanf("%30s",str);
    printf("enter your age :");
    scanf("%d",&i);
    printf("Hello %s, you are %d years old. \n",str,i);
    printf("Enter a hex number :");
    scanf("%x",&i);
    printf("you have entered %#x(%d)\n",i,i);


    char c[5] = {'a','b','\0','c','\0'};
    printf("c: %s",c);

    return 0;
}