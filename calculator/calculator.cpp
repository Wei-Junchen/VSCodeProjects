#include <stack>
#include <iostream>
#include <string>
#include <cmath>

bool isOp(const char& ch)
{
    return ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='{'||ch=='}'||ch=='['||ch==']'||ch=='^';
}

bool isNum(const char& ch)
{
    return ch>='0'&&ch<='9';
}

bool isDot(const char& ch)
{
    return ch=='.';
}

int getPr(const char& ch)
{
    switch (ch)
    {
    case '+':
        return 0;
        break;
    case '-':
        return 0;
        break;
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    case '^':
        return 2;
    default:
        return -1;
        break;
    }
}

int compare(const char& a,const char& b)
{
    return getPr(a)-getPr(b);
}

double calculate(double a,double b,const char& op)
{
    switch(op)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '^':
            return std::pow(a,b);
    }
    return 0.0;
}

bool isLeftBr(const char& ch)
{
    return ch=='('||ch=='{'||ch=='[';

}

bool isRightBr(const char& ch)
{
    return ch==')'||ch=='}'||ch==']';
}

bool isPN(const char& ch)
{
    return ch=='+'||ch=='-';
}

int getPN(const char& ch)
{
    if(ch=='+')
        return 1;
    else 
        return -1;
}

int loop()
{
    std::string input;
    std::getline(std::cin,input,'\n');
    std::stack<double> num;
    std::stack<char> op;
    std::size_t head;
    int lastOpIndex=-1;
    int numPN=1;
    int skip=1;
    for(std::size_t i=0;i<input.size();++i)
    {
        if(isOp(input[i]))
        {
            if(isPN(input[i]))//此分支检测数字之前的正负
            {
                if(lastOpIndex==i-skip&&!isRightBr(input[lastOpIndex]))//如果两个符号相邻
                {
                    numPN*=getPN(input[i]);
                    lastOpIndex=i;
                    skip=1;
                    continue;
                }
            }
            lastOpIndex=i;
            skip=1;
            if(!op.empty())
            {
                if(getPr(input[i])!=-1)//无括弧
                {
                    if(compare(input[i],op.top())<=0)
                    {
                        double tmp1=num.top();
                        num.pop();
                        double tmp2=num.top();
                        num.pop();
                        num.push(calculate(tmp2,tmp1,op.top()));
                        op.pop();
                        op.push(input[i]);
                    }
                    else 
                        op.push(input[i]);
                }
                else//有括弧
                {
                    if(isLeftBr(input[i]))
                        op.push(input[i]);
                    else if(isRightBr(input[i]))//反括弧，开始向前计算
                    {
                        while(!isLeftBr(op.top()))//不是左括弧前一直向前计算
                        {
                            double tmp1=num.top();
                            num.pop();
                            double tmp2=num.top();
                            num.pop();
                            num.push(calculate(tmp2,tmp1,op.top()));
                            op.pop();
                        }
                        op.pop();
                    }
                }
            }
            else
                op.push(input[i]);
        }
        //数字的检测插入还待完成(还需要检测是否为负数)
        else if(isNum(input[i])||isDot(input[i]))
        {
            if(i==0)
                head=0;
            else if(!isNum(input[i-1])&&!isDot(input[i-1]))//判断是否为数字开始
                head=i;
            if(i==input.size()-1)//边界条件，防止越界
            {
                std::string numstr = input.substr(head,i-head+1);
                num.push(numPN*std::stod(numstr));
                numPN=1;
            }
            else if(!isNum(input[i+1])&&!isDot(input[i+1]))//说明数字读取完毕
            {
                std::string numstr = input.substr(head,i-head+1);
                num.push(numPN*std::stod(numstr));
                numPN=1;
            }
        }
        else //跳过(如空格)但是之前的符号不变
            ++skip;
    }

    //收尾(前面已经保证没有括弧了)
    while(!op.empty())
    {
        double tmp1=num.top();
        num.pop();
        double tmp2=num.top();
        num.pop();
        num.push(calculate(tmp2,tmp1,op.top()));
        op.pop();
    }
    std::cout<<num.top()<<std::endl;
    return 0;
}

int main()
{
    while(!loop());
    return 0;
}