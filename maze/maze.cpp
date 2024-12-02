#include <iostream>
#include <random>
#include <windows.h>
#include <chrono>
#include <stack>
#include <array>

#define DEBUG 0

constexpr std::size_t width{35},height{80};
std::stack<std::array<int,2>> line;
int p[1000][3][2]{}; // p[i] -> {{x1,y1},{x2,y2},{x3,y3}}
int pp[1000]{};
int table[width][height]{};
int table_t[width][height]{};
int setX{},setY{};

void checkAdd(int x,int y,int num,int& index)
{
    if(num)
    {
        bool isNotCheck[4]{};
        if(x<0||x>width-1||y<0||y>height-1)
            return;
        if(x==0)
            isNotCheck[1]=true;
        else if(x==width-1)
            isNotCheck[0]=true;
        if(y==0)
            isNotCheck[3]=true;
        else if(y==height-1)
            isNotCheck[2]=true;
        if((!isNotCheck[0]))
            if(table_t[x+1][y]==1)
                return ;
        if((!isNotCheck[1]))
            if(table_t[x-1][y]==1)
                return ;
        if((!isNotCheck[2]))
            if(table_t[x][y+1]==1)
                return ;
        if((!isNotCheck[3]))
            if(table_t[x][y-1]==1)
                return ;
    }
    p[num][index][0]=x;
    p[num][index][1]=y;
    index++;
}

int getRand(int range) 
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);  // 初始化 Mersenne Twister 引擎
    std::uniform_int_distribution<> distrib(0, range-1);  // 设置随机数范围

    return distrib(gen);
}

void f(int x,int y,int num)
{
#if !DEBUG
    system("cls");
#endif
    for(int i=0;i<width;++i)
    {
        for(int j=0;j<height;++j)
            std::cout<<table[i][j]<<" ";
        std::cout<<std::endl;
    }
#if DEBUG
    std::cout<<"now:"<<x<<","<<y<<std::endl;
#endif
    if(x==setX&&y==setY)//找到目标点跳出
        return;
    if(line.size()==num+1)//说明返回到了上一个点,num!=0确保不会是起始点
    {
#if DEBUG
        std::cout<<"back:("<<std::endl;
        for(int i=0;i<pp[num];++i)
            std::cout<<p[num][i][0]<<","<<p[num][i][1]<<std::endl;
#endif
        for(int i=0;i<pp[num];++i)
        {
            if(p[num][i][0]==x&&p[num][i][1]==y)//这里目前存在问题？
            {
                --pp[num];
                p[num][i][0]=0;
                p[num][i][1]=0;
                //保证p[num]能够全部密排 !{{0,0},{x1,y1},{x2,y2}};
                for(int j=i;j<pp[num];++j)
                {
                    p[num][j][0]=p[num][j+1][0];
                    p[num][j][1]=p[num][j+1][1];
                }
                break;
            }
        }
#if DEBUG
        std::cout<<"after delete:"<<std::endl;
        for(int i=0;i<pp[num];++i)
            std::cout<<p[num][i][0]<<","<<p[num][i][1]<<std::endl;
        system("pause");
#endif
        //在剩余可能的点中尝试
        if(pp[num]==0)//如果该点pp(可能延伸点)为零
        {
            table[line.top()[0]][line.top()[1]]=0;//table清零
            int xCopy{line.top()[0]},yCopy{line.top()[1]};
            line.pop();
            f(xCopy,yCopy,num-1);
        }
        else//在剩余的点中尝试延伸
        {
            int chosen=getRand(pp[num]);
            f(p[num][chosen][0],p[num][chosen][1],num+1);
        }
    }
    else
    {
        int index{};
        if(num==0)
        {
            checkAdd(1,0,0,index);
            checkAdd(0,1,0,index);
        }
        else
        {
            int dx{line.top()[0]-x};
            int dy{line.top()[1]-y};
            if(dy)//dx==0
            {
                checkAdd(x+1,y,num,index); 
                checkAdd(x-1,y,num,index);
                checkAdd(x,y-dy,num,index);
            }
            else//dy==0
            {
                checkAdd(x,y+1,num,index);
                checkAdd(x,y-1,num,index);
                checkAdd(x-dx,y,num,index);
            }
        }
        if(index==0)
        {
#if DEBUG
            std::cout<<"None"<<std::endl;
            system("pause");
#endif
            f(x,y,num-1);
        }
        else
        {
            pp[num]=index;
            line.push({x,y});
            int chosen=getRand(pp[num]);
            table[x][y]=1;
            table_t[x][y]=1;
#if DEBUG
            for(int i=0;i<pp[num];++i)
                std::cout<<p[num][i][0]<<","<<p[num][i][1]<<std::endl;
            system("pause");
#endif
            f(p[num][chosen][0],p[num][chosen][1],num+1);
        }
    }
}

void buildPath(int x,int y)
{
    setX=x;
    setY=y;
    f(0,0,0);
}

int main()
{
    buildPath(width-1,height-1);
    std::stack<std::array<int,2>> reverse;
    std::cout<<"Origin Maze:"<<std::endl;
    for(int i=0;i<width;++i)
    {
        for(int j=0;j<height;++j)
            std::cout<<table_t[i][j]<<" ";
        std::cout<<std::endl;
    }
    /*std::size_t lineLength=line.size();
    for(std::size_t i=0;i<lineLength;++i)
    {
        reverse.push(line.top());
        line.pop();
    }
    for(std::size_t i=0;i<lineLength;++i)
    {
        std::cout<<"("<<reverse.top()[0]<<","<<reverse.top()[1]<<")->";
        line.push(reverse.top());
        reverse.pop();
    }*/
}

