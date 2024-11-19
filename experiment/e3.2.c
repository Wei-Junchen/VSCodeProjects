#include <stdio.h>

int main(void)
{
    int f[30]={1,1};
    double sum=0;
    for(int i=2;i<30;++i)
        f[i]=f[i-1]+f[i-2];
    for(int i=0;i<20;++i)
        sum+=f[i+2]/(double)f[i+1];
    printf("%lf",sum);
    return 0;
}