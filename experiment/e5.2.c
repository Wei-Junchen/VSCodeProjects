#include <stdio.h>

int operator(int x,int y,char op)
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
    int x=12,y=34;
    printf("%d",operator(x,y,'+'));
    return 0;
}