#include <stdio.h>
#include <string.h> 

int operato(int x,int y,char op)
{
    switch (op)
    {
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            return x/y;
        default:
            return 0;
    }
}

int main(void)
{
    char str[100];
    scanf("%s",str);
    int x=0,y=0;
    char op=' ';
    for(int i=0;i<strlen(str);++i)
    {
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
            x/=10;
            op=str[i];
            continue;
        }
        else if(op==' ')
        {
            x+=str[i] - '0';
            x*=10;
        }
        else if(op!=' ')
        {
            y+=str[i] - '0';
            y*=10;
        }
        else
        {
            printf("Error\n");
            return 0;
        }
    }
    y/=10;
    if(y==0&&op=='/')
    {
        printf("Error\n");
        return 0;
    }
    printf("%d\n",operato(x,y,op));
    return 0;
}