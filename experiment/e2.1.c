#include <stdio.h>

int main(void)
{
    float x,y;
    scanf("%f",&x);
    if(x<=10) 
        y=2*x;
    else if(x>10&&x<50)
        y=2*x+1;
    else 
        y=0.5*x+0.1;
    printf("%.1f",y);
}