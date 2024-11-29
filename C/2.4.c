#include <stdio.h>

int main()
{
    int arr[15]={16,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int search;
    scanf("%d",&search);
    int left=0,right=14,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(search==arr[mid])
        {
            printf("%d",mid);
            return 0;
        }
        else if(search>arr[mid])
            right=mid-1;
        else 
            left=mid+1;
    }
    printf("Out");
    return 0;
}