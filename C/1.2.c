#include <stdio.h>

int main()
{
    float height=100,sum=0;
    for(int i=0;i<10;++i)
    {
        sum+=height;
        height/=2;
        sum+=height;
    }
    sum-=height;
    printf("S=%f,height=%f\n",sum,height);
    return 0;
}