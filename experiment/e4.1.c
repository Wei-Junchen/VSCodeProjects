#include <stdio.h>

int main(void)
{
    int num[10],count[10][2]={},length=0,max;
    for(int i=0;i<10;++i)
        scanf("%d",num+i);
    max=num[0];
    for(int i=0;i<10;++i) 
    {
        int isInsert=0;
        if(num[i]>max)
            max=num[i];
        if(length==0&&count[length][1]==0)
            count[0][0]=num[0];
        for(int j=0;j<=length;++j)
        {
            if(count[j][0]==num[i])
            {
                count[j][1]+=1;
                isInsert=1;
                break;
            }
        }
        if(isInsert==0)
        {
            ++length;
            count[length][0]=num[i];
            count[length][1]=1;
        }
    }
    printf("Max: %d\n",max);
    for(int i=0;i<=length;++i)
        printf("%d : %d times\n",count[i][0],count[i][1]);
    return 0;
}