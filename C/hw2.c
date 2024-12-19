#include <stdio.h>

void Inverse(char str[])
{
    int l=0;
    char tmp;
    for(;str[l]!='\0';++l);
    for(int i=0;i<l/2+1;++i)
    {
        tmp = str[i];
        str[i] = str[l-i-1];
        str[l-i-1] = tmp;
    }
}

int main()
{
    char a[100]={};
    scanf("%s",a);
    Inverse(a);
    printf("%s",a);
    return 0;
}