#include <iostream>
#include <vector>

template<typename T>
void print(const T& volumn)
{
    for(const auto& element : volumn)
        std::cout<<element<<" ";
    std::cout<<std::endl;
}

int main()
{
    std::vector<float> a(2,99);
    a.push_back(114);
    for(auto it=a.begin();it!=a.end();++it)
        std::cout<<*it<<" ";
    print(a);
    return 0;
    
}