#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* str_delete(char* s,int v,int w)
{
    char* ns=(char*)malloc((strlen(s)-w)*sizeof(char));
    for(int i=0;i<v;++i)
        ns[i]=s[i];
    for(int i=v;i<strlen(s)-w;++i)
        ns[i]=s[i+w];
    return ns;
}

int main(void)
{
    char s[20]={};
    scanf("%s",s);
    printf("%s",str_delete(s,3,4));
    return 0;
}