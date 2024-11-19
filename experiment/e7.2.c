#include <stdio.h>
#include <stdlib.h>

int find_max(int* p,int n)
{
    int max=p[0];
    for(int i=1;i<n;++i)
        if(p[i]>max)
            max=p[i];
    return max;
}

int find_min(int* p,int n)
{
    int min=p[0];
    for(int i=1;i<n;++i)
        if(p[i]<min)
            min=p[i];
    return min;
}

void sort(int* p,int n)
{
    int* arr=(int*)malloc(sizeof(int)*n);
    arr[0]=p[0];
    int left,right,mid;
    for(int i=1;i<n;++i)
    {
        left=0,right=i-1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(p[i]>arr[mid])
                left=mid+1;
            else
                right=mid-1;
        }
        for(int j=i-1;j>=left;--j)
            arr[j+1]=arr[j];
        arr[left]=p[i];
    }
    for(int i=0;i<n;++i)
        p[i]=arr[i];
    free(arr);
}

int main(void)
{
    int num[10]={9,7,6,12,44,53,32,11,29};
    scanf("%d",num+9);
    sort(num,10);
    printf("Max:%d Min:%d\n",find_max(num,10),find_min(num,10));
    for(int i=0;i<10;++i)
        printf("%d ",num[i]);
    return 0;
}