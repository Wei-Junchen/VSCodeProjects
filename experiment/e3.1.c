#include <stdio.h>

int main(void)
{
    int a,b,sum1=0,sum2=0;
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;++i)
    {
        if(i%2==0) 
            sum2+=i;
        else 
            sum1+=i;
    }
    printf("%d %d",sum1,sum2);
    return 0;
}