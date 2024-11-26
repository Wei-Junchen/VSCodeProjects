#include <iostream>
#include <array>

constexpr size_t SIZE {10};

int main()
{
    std::array<float,SIZE> a1 {};
    a1.fill(114514.0f);
    for(auto& element : a1)
        std::cout<<element<<" ";
    a1.at(1) = 2;
    std::cout<<std::endl<<std::size(a1)<<std::endl;
    std::cout<<a1.front()<<std::endl;
    std::array<float, SIZE>::iterator it=a1.begin();
    std::array<float, SIZE>::reverse_iterator rit=a1.rbegin(); 
    std::cout<<*(++it)<<" "<<*rit<<std::endl;
    return 0;
}