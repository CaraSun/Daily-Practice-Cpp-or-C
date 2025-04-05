#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char p1[15] = "abcd";
    char *p2 = "ABCD";
    char str[50] = "xyz";
    char *result = strcat(p1+1,p2+1);

    printf("%s\n",p1);
    printf("%s\n",result);
    
    return 0;
}