#include <stdio.h>

int main()
{
    int line1[11]={1},line2[11]={1};
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(i%2==0)
            {
                line2[j+1]=line1[j]+line1[j+1];
                printf("%d ",line1[j]);
            }
            else
            {
                line1[j+1]=line2[j]+line2[j+1];
                printf("%d ",line2[j]);
            }
        }
        printf("\n");
    }
    return 0;
}