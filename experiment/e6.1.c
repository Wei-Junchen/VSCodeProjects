#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,l[18],characters[26];

void print(int length,char *arr,char *_characters)
{
    if(length==n)
    {
        for(int i=0;i<n;++i) printf("%c ",arr[i]);
        printf("\n");
        return ;
    }
    for(int i=0;i<n;++i)
    {
        if(!l[i])
            continue;
        else
        {
            l[i]=0;
            arr[length]=_characters[i];
            ++length;
        }
        print(length,arr,_characters);
        l[i]=1;
        length--;
    }
}

int main()
{
    char name[18]={},arr[18]={};
    scanf("%s",name);
    for(int i=0;i<strlen(name);++i) 
        characters[name[i]-'a']=1;
    for(int i=0;i<26;++i)
        if(characters[i]==1) ++n;
    char* _characters=(char*)malloc(n*sizeof(char));
    int index=-1;
    for(int i=0;i<n;++i)
    {
        do
        {
            ++index;
        }while(characters[index]==0);
        _characters[i]=index+'a';
    }
    for(int i=0;i<18;++i) 
        l[i]=1;
    print(0,arr,_characters);
    return 0;
}