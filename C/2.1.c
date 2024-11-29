#include <stdio.h>

int sgn(int num)
{
    return num>0?1:-1;
}

void insert(int* arr,int num,int size)
{
    int sign=0;
    for(int i=0;i<size-1;++i)
    {
        if(arr[i+1]-arr[i]!=0)
        {
            sign=sgn(arr[i+1]-arr[i]);
            break;
        }
    }
    if(sgn==0)
    {
        if(num>=arr[0])
            arr[size]=num;
        else
        {
            for(int i=0;i<size;++i)
                arr[i+1]=arr[i];
            arr[0]=num;
        }
    }
    else
    {
        int left=0,right=size-1,mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(num==arr[mid]) 
            {
                left=mid;
                break;
            }
            else if(num>arr[mid])
            {
                if(sign==1)
                    left=mid+1;
                else
                    right=mid-1;
            }
            else
            {
                if(sign==1)
                    right=mid-1;
                else
                    left=mid+1;
            }
        }
        for(int i=size;i>left;--i)
            arr[i]=arr[i-1];
        arr[left]=num;
    }
}

int main()
{
    int arr[11]={0,2,4,6,8,10,12,14,16,18};
    int arr_r[11]={18,16,14,12,10,8,6,4,2,0};
    int insertNum;
    scanf("%d",&insertNum);
    insert(arr,insertNum,10);
    insert(arr_r,insertNum,10);
    for(int i=0;i<11;++i)
        printf("%d ",arr[i]);
    printf("\n");
    for(int i=0;i<11;++i)
        printf("%d ",arr_r[i]);
    return 0;
}