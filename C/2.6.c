#include <stdio.h>
#include <stddef.h>

void strcpy(char* s1,const char* s2)
{
    ptrdiff_t d=0;
    while(*(s2+d)!='\0')
    {
        *(s1+d)=*(s2+d);
        ++d;
    }
    *(s1+d)='\0';
}

int main()
{
    char a[100]="Hello, World!",b[100]={};
    strcpy(b,a);
    printf("%s",b);
    return 0;
}