#include <iostream>
#include <random>
#include <windows.h>
#include <chrono>

#define width 10
#define height 10 

int p[1000][3][2]{}; // p[i] -> {{x1,y1},{x2,y2},{x3,y3}}
int pp[1000]{};
int line[1000][2]{};
int table[width][height]{};
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
            if(table[x+1][y]==1)
                return ;
        if((!isNotCheck[1]))
            if(table[x-1][y]==1)
                return ;
        if((!isNotCheck[2]))
            if(table[x][y+1]==1)
                return ;
        if((!isNotCheck[3]))
            if(table[x][y-1]==1)
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
    system("cls");
    for(int i=0;i<width;++i)
    {
        for(int j=0;j<height;++j)
            std::cout<<table[i][j]<<" ";
        std::cout<<std::endl;
    }
    if(x==setX&&y==setY)//找到目标点跳出
        return;
    if(line[num][0]!=0&&line[num][1]!=0&&num!=0)//说明返回到了上一个点,num!=0确保不会是起始点
    {
        for(int i=0;i<pp[num];++i)
        {
            if(p[num][i][0]==x&&p[num][i][1]==y)
            {
                --pp[num];
                p[num][i][0]=0;
                p[num][i][1]=0;
                //保证p[num]能够全部密排 !{{0,0},{x1,y1},{x2,y2}};
                for(int j=i;j<pp[num]-1;++j)
                {
                    p[num][j][0]=p[num][j+1][0];
                    p[num][j][1]=p[num][j+1][0];
                }
                break;
            }
        }
        //在剩余可能的点中尝试
        if(pp[num]==0)//如果该点pp(可能延伸点)为零
        {
            table[line[num][0]][line[num][1]]=0;//table清零
            int xCopy{line[num][0]},yCopy{line[num][1]};
            line[num][0]=0;
            line[num][1]=0;
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
            int dx{line[num-1][0]-x};
            int dy{line[num-1][1]-y};
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
            f(x,y,num-1);
        else
        {
            pp[num]=index;
            line[num][0]=x;
            line[num][1]=y;
            int chosen=getRand(pp[num]);
            table[x][y]=1;
            /*for(int i=0;i<pp[num];++i)
            {
               std::cout<<p[num][i][0]<<" "<<p[num][i][1]<<"----pp"<<std::endl;
            }
            std::cout<<"r:"<<chosen<<std::endl;*/
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
    buildPath(9,9);
}

