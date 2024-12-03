#include <stdio.h>

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
    int x=03,y=47;
    printf("%d\n%d\n%d\n%d",operato(x,y,'+'),operato(x,y,'-'),operato(x,y,'*'),operato(x,y,'/'));
    return 0;
}