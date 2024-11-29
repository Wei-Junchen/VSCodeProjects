#include <stdio.h>

#define m 3
#define n 3

int main()
{
    int arr[m][n]={{7,8,9},{5,6,4},{3,2,1}};
    int max_index[m]={},min_index[n]={};
    for(int i=0;i<m;++i)
    {
        for(int j=1;j<n;++j)
            if(arr[i][j]>arr[i][max_index[i]])
                max_index[i]=j;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<m;++j)
            if(arr[j][i]<arr[min_index[i]][i])
                min_index[i]=j;
    }
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i==min_index[j]&&j==max_index[i])
            {
                printf("(%d,%d) : %d\n",i,j,arr[i][j]);
                break;
            }
        }   
    }
    return 0;
}