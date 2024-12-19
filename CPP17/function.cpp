#include <iostream>

void functionA(int,int);//函数原型
void functionB(int a,int b); //两种都可以
void quoteArray(const int (&arr)[10])
{
    for(auto x : arr)
        std::cout<<x<<" ";
    std::cout<<std::endl;
}

int main()
{
    int arr[10] {1,2,3,4,5,6,7,8,9,10};
    functionA(6,7);
    quoteArray(arr);
    return 0;
}

void functionA(int a,int b)
{
    std::cout<<a+b<<std::endl;
}