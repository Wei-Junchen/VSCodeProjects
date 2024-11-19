#include <stdio.h>
#include <math.h>

float min(float a,float b)
{
    return a>b?b:a;
}

float max(float a,float b)
{
    return a>b?a:b;
}

int main(void)
{
    float a,b,c;
    do
    {
        scanf("%f%f%f",&a,&b,&c);
    }while(abs(min(a,b)+min(a,c)+min(b,c)-min(a,min(b,c)))<=max(a,max(b,c))||a<=0||b<=0||c<=0);
    float p=(a+b+c)/2;
    printf("%.1f",sqrt(p*(p-a)*(p-b)*(p-c)));
}