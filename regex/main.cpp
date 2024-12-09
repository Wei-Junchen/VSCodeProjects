#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string patternRule{R"(\d+)"};
    std::regex pattern(patternRule);
    std::string origin{"uhduawhd252nccdsaca32q123fas"};
    std::smatch match;
    std::cout<<origin<<std::endl;
    if(std::regex_match(origin,pattern))//检测字符串是否 符合 正则表达式的模式
    {
        std::cout<<"Match"<<std::endl;
    }
    else
    {
        std::cout<<"Not match"<<std::endl;
    }

    if(std::regex_search(origin,match,pattern))//检测字符串是否 包含 正则表达式的模式(仅支持第一个)
    {
        std::cout<<"Match"<<" "<<match.str(0)<<std::endl;
    }
    else
    {
        std::cout<<"Not match"<<std::endl;
    }
    for(std::sregex_iterator it(origin.begin(),origin.end(),pattern),end ; it!=end ; ++it) //检测字符串是否 包含 正则表达式的模式(支持多个)
    {
        std::cout<<it->str()<<std::endl;
    }
    // 使用替换字符串
    std::string result = std::regex_replace(origin, pattern, "number");
    return 0;
}