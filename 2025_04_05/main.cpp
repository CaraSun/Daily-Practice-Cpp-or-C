#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char p1[15] = "abcd";
    char *p2 = "ABCD";
    char str[50] = "xyz";
    char *result = strcat(p1+1,p2+1);

    char *p;
    for (p = str; p < str + 4; p++)
        printf("%s\n", p);


    printf("%s\n",p1);
    printf("%s\n",result);

    char str1[6] = "China";
    char str2[6] = {"China"};// 等价

    



    return 0;
}