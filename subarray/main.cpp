#include <iostream>
#include <array>

int* find(int arr[],int left,int right)
{
    int* index = new int[3]{left,right};
    if(left==right)
    {
        index[2]=arr[left];
        return index;
    } 
    int mid{(left+right)/2};
    int *leftIndex{},*rightIndex{};
    leftIndex = find(arr,left,mid);
    rightIndex = find(arr,mid+1,right);
    int sumLeftMax{arr[mid]},sumRightMax{arr[mid+1]};
    int sumLeft{},sumRight{};
    int midIndex[3]{mid,mid+1};
    for(int i = mid;i>=left;--i)
    {
        sumLeft+=arr[i];
        if(sumLeft>=sumLeftMax)
        {
            sumLeftMax=sumLeft;
            midIndex[0]=i;
        }
    }
    for(int i= mid+1;i<=right;++i)
    {
        sumRight+=arr[i];
        if(sumRight>=sumRightMax)
        {
            sumRightMax=sumRight;
            midIndex[1]=i;
        }
    }
    midIndex[2]=sumLeftMax+sumRightMax;
    if(leftIndex[2]>=rightIndex[2]&&leftIndex[2]>=midIndex[2])
    {
        for(std::size_t i=0;i<3;++i)
            index[i]=leftIndex[i];
    }
    else if(rightIndex[2]>=leftIndex[2]&&rightIndex[2]>=midIndex[2])
    {
        for(std::size_t i=0;i<3;++i)
            index[i]=rightIndex[i];
    }
    else
    {
        for(std::size_t i=0;i<3;++i)
            index[i]=midIndex[i];
    }
    delete[] leftIndex;
    delete[] rightIndex;
    return index;
}

int main()
{
    int arr[]={-12,14,2,-3,-95,99,12,-5,-23,17,75,-84,99};
    int* index = new int[3];
    index=find(arr,0,std::size(arr)-1);
    std::cout<<index[2];
    delete[] index;
    return 0;
}