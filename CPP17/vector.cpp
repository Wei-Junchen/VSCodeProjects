#include <iostream>
#include <vector>

int main()
{
    std::vector<float> a(2,99);
    a.push_back(114);
    for(auto it=a.begin();it!=a.end();++it)
        std::cout<<*it<<" ";
    return 0;
}