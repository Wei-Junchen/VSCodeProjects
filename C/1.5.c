#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int length;
    char num[50];
}myType;

int max(int a,int b)
{
    return a>b?a:b;
}

myType* init()
{
    myType* obj=(myType*)malloc(sizeof(myType));
    obj->length=1;
    memset(obj->num,'0',sizeof(obj->num));
    return obj;
}

void add(myType* num,const myType* x)
{
    int up=0;
    int maxl=max(num->length,x->length);
    for(int i=0;i<maxl;++i)
    {
        int sum = (num->num[i] - '0') + (x->num[i] - '0') + up;
        if(sum>9)
        {
            num->num[i]= (sum-10) + '0';
            up=1;
        }
        else
        {
            num->num[i]= sum + '0';
            up=0;
        }
    }
    num->length=maxl;
    if(up==1)
    {
        num->num[num->length]='1';
        num->length++;
    }
}

void mul(myType* num,int x)
{
    myType* copy=init();
    memcpy(copy,num,sizeof(*num));
    num->length=1;
    memset(num->num,'0',sizeof(num->num));
    int back=x%10;
    x/=10;
    for(int i=0;i<back;++i)
        add(num,copy);
    for(int i=copy->length;i>=1;--i)
        copy->num[i]=copy->num[i-1];
    copy->num[0]='0';
    ++copy->length;
    for(int i=0;i<x;++i)
        add(num,copy);
    free(copy);
}

void print(const myType* num)
{
    for(int i=num->length-1;i>=0;--i)
        printf("%c",num->num[i]);
    printf("\n");
}

int main()
{
    myType* sum=init();
    myType* num=init();
    num->num[0]='1';
    for(int i=1;i<=20;++i)
    {
        mul(num,i);
        add(sum,num);
    }
    print(sum);
    free(sum);
    free(num);
    return 0;
}