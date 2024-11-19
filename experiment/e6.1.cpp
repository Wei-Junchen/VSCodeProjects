#include <iostream>
#include <iomanip>
using namespace std;

int n;
bool l[100];

void print(int length,int *arr)
{
    if(length==n)
    {
        for(int i=0;i<n;++i) cout<<setw(5)<<arr[i]<<" ";
        cout<<endl;
        return ;
    }
    for(int i=0;i<n;++i)
    {
        if(!l[i])
            continue;
        else
        {
            l[i]=false;
            arr[length]=i+1;
            ++length;
        }
        print(length,arr);
        l[i]=true;
        length--;
    }
}

int main()
{
    int arr[100]={};
    cin>>n;
    for(int i=0;i<100;++i) 
        l[i]=true;
    print(0,arr);
    return 0;
}