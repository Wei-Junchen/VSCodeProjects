#include <iostream>

void mergesort(int* arr,int from,int to)
{
    if(from==to) return ;
    int tmp[to-from+1];
    mergesort(arr,from,(from+to)/2);
    mergesort(arr,(from+to)/2+1,to);
    int index1=from,index2=(from+to)/2+1;
    for(int i=from;i<=to;++i)
    {
        if(index1 <= (from+to)/2 && (index2 > to || arr[index1] <= arr[index2]))//index <= (from+to)/2 :保证左半边没有分完
        {
            tmp[i-from]=arr[index1];
            ++index1;
        }
        else//左半边分完，剩下全为右半边
        {
            tmp[i-from]=arr[index2];
            ++index2;
        }
    }
    for(int i=from;i<=to;++i)
        arr[i]=tmp[i-from];
}

int main()
{
    int arr[11]{9,8,2,1,10,2,3,2,1,23,5};
    mergesort(arr,0,10);
    for(int i=0;i<11;++i)
        std::cout<<arr[i]<<" ";
    return 0;
}