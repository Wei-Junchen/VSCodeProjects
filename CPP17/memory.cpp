#include <memory>
#include <iostream>

int main() 
{                                                                                                                      
    auto a{std::make_unique<int>(666)};
    //std::unique_ptr<int> b{a}; 不能复制 
    std::unique_ptr<int> b{std::make_unique<int>(18)};//nullptr
    *b=19;
    std::cout<<*b<<" "<<std::hex<<std::showbase<<b.get()<<std::endl;
    int *p=b.release();                              //------
    std::cout<<std::dec<<*a<<" "<<*p<<std::endl;     //      |  @attention 转换后记得释放
    delete p;                                        //<-----
    std::unique_ptr<std::unique_ptr<int[]>[]> matrix{std::make_unique<std::unique_ptr<int[]>[]>(10)};
    for(std::size_t i=0;i<10;++i)
        matrix[i] = std::make_unique<int[]>(10);

    for(std::size_t i=0;i<10;++i)//注意：smart pointer不支持iterator
    {
        for(std::size_t j=0;j<10;++j)
            std::cout<<matrix[i][j]<<" ";
        std::cout<<std::endl;
    }

    std::shared_ptr<int> sa{std::make_shared<int>(6)};
    std::shared_ptr<int> sb=sa;
    //int s=sb.release();
    std::cout<<*sa<<std::endl;

    int arr[10]{};
    for(auto& t : arr) //基于范围的for循环可以通过引用修改值
        t=1;
    for(auto x : arr)
    {
        //x=2; 不可改变arr其值(x仅为拷贝)
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    return 0;
} 