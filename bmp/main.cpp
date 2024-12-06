#include <iostream>
#include <string>
#include <cstdint>
#include <cctype>

int main()
{
    std::size_t row,column;
    std::cin>>row>>column;
    bool** bmp = new bool*[row];
    for(int i=0;i<row;++i)
        bmp[i]=new bool[column];
    std::string input;
    std::getline(std::cin,input,'#');
    uint8_t line;
    std::size_t index=0;
    for(int k=0;k<row/8;++k)
    {
        for(int i=0;i<column;++i)
        {
            if(input.find("0x",index)!=std::string::npos)
            {
                index=input.find("0x",index);
                line=std::stoi(input.substr(index+2,2),nullptr,16);
                ++index;
            }
            else
            {
                std::cerr << "Invalid input format!" << std::endl;
                return 0;
            }
            for(int j=8*k;j<8*k+8;++j)
            {
                bmp[j][i]=line&0x01;
                line>>=1;
            }
        }
    }
    std::cout<<std::endl;
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<column;++j)
        {
            if(bmp[i][j])
                std::cout<<"#";
            else 
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}