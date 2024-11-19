#include <stdio.h>

int main(void)
{
    char input[100]={},output[100]={};
    scanf("%s",input);
    int i;
    for(i=0;input[i]!='\0';++i)
    {
        if(input[i]-'A'>=0&&input[i]-'A'<=25)
        {
            if(input[i]-'A'+4>=26)
                output[i]=input[i]-'A'+4-26+'a';
            else 
                output[i]=input[i]-'A'+4+'a';
        }
        else if(input[i]-'a'>=0&&input[i]-'a'<=25)
        {
            if(input[i]-'a'+4>=26)
                output[i]=input[i]-'a'+4-26+'A';
            else 
                output[i]=input[i]-'a'+4+'A';
        }
        else 
            output[i]='?';
    }
    output[i]='\0';
    printf("%s",output);
    return 0;
}