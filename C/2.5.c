#include <stdio.h>
#include <stddef.h>

int strcmp(const char* str1,const char* str2)
{
    ptrdiff_t d=0;
    while(*(str1+d)!='\0'&&*(str2+d)!='\0')
    {
        if(*(str1+d)!=*(str2+d))
            return *(str1+d)-*(str2+d);
        ++d;
    }
    return *(str1 + d) - *(str2 + d);
}

int main()
{
    char s1[100]={},s2[100]={};
    gets(s1);
    gets(s2);
    printf("%d",strcmp(s1,s2));
    return 0;
}