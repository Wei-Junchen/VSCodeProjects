#include <stdio.h>

int main()
{
    char ch;
    int cnt[4]={};
    while((ch = getchar()) != '\n')
    {
        if( (ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z'))
            ++cnt[0];
        else if(ch==' ')
            ++cnt[1];
        else if(ch>='0'&&ch<='9')
            ++cnt[2];
        else 
            ++cnt[3];
    }
    printf("characters: %d ,space: %d ,number: %d ,others: %d \n",cnt[0],cnt[1],cnt[2],cnt[3]);
    return 0;
}