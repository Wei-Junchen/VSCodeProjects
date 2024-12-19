#include <iostream>
#include <string>
#include <string_view>

void printStr(std::string_view str)
{
    for(auto i:str)
        std::cout<<i;
    std::cout<<std::endl;
    std::cout<<str<<std::endl;
}

int main()
{
    std::string a="Hello,world";
    std::cout<<a<<std::endl;
    const char *s=a.c_str();//注意，c_str函数只能获得const char*类型
    std::cout<<s<<std::endl;
    char *ss=a.data();//可以返回非const类型char*,意味着可以更改std::string 对象的值
    *ss='A';
    std::cout<<a<<std::endl;
    std::size_t l=a.length();
    std::cout<<l<<std::endl; 
    std::string b{"abcdefg",6};
    std::string c(6,'z');
    //std::string c{6,'z};不可
    std::cout<<b<<" "<<c<<std::endl;
    //拷贝初始化
    std::string copy{b,1,2};//1为起始索引，2为长度
    std::cout<<copy<<std::endl;
    std::string connect{"apple"+a+"ifjwa"};//字符串的连接，注意不能连接两个字符串字面量(必须至少有一个是std::string 对象)
    //但是可以手动更改优先级
    std::string connect1{"apple"+("banana"+a)};
    std::string connect2{std::string("apple")+std::string("banana")};
    {
        using namespace std::string_literals;//可以使用s后缀将字符串转变为std::string对象
        std::string connnect3{"apple"s+"banan"s};
    }
    copy.append(copy).append("goshujin");//另类的+=
    std::string song_title{"Summer of '"};
    //song_title+=69;// 不会报错，注意
    song_title.append(std::to_string(69));//可
    std::cout<<song_title<<std::endl;
    std::string str{".Hello,world"};
    printStr(str);
    std::cout<<str.find_first_not_of(".,")<<std::endl;//返回第一个不在指定字符串中的字符的索引
    return 0;
}