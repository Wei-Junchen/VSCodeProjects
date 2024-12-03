#include <iostream>
#include <array>

constexpr std::size_t SIZE {10};

template<typename T,std::size_t N>
void printArr(const std::array<T,N>& arr)
{
    for(typename std::array<T,N>::const_iterator it=arr.begin();it!=arr.end();++it)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}

template<typename T,std::size_t N>
void printArr1(const std::array<T,N>& arr)
{
    for(const T& element : arr)
        std::cout<<element<<" ";
    std::cout<<std::endl;
}


int main()
{
    std::array<float,SIZE> a1 {};
    a1.fill(114514.0f);
    for(const auto& element : a1)
        std::cout<<element<<" ";
    a1.at(1) = 2;
    std::cout<<std::endl<<std::size(a1)<<std::endl;
    std::cout<<a1.front()<<std::endl;
    std::array<float, SIZE>::iterator it=a1.begin();
    std::array<float, SIZE>::reverse_iterator rit=a1.rbegin(); 
    std::cout<<*(++it)<<" "<<*rit<<std::endl;
    printArr(a1);
    return 0;
}