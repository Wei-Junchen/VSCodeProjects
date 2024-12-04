#include <iostream>
#include <array>
#include <cctype>


template<size_t N>
std::array<std::array<int,N>,N> strassen(const std::array<std::array<int,N>,N>& m1,const std::array<std::array<int,N>,N>& m2)
{
    if(N==1)
    {
        std::array<std::array<int,N>,N> r;
        r[0][0]=m1[0][0]*m2[0][0];
        return r;
    }
    std::array<std::array<std::array<int,N/2>,N/2>,10> S;
    //还是应该O(N^2)构造8个子数组，否则不好通过下标计算(函数重载复杂性增加)
    std::array<std::array<std::array<std::array<int,N/2>,N/2>,2>,2> A,B;
    for(size_t i=0;i<2;++i)
    {
        for(size_t j=0;j<2;++j)
        {
            for(size_t row=0;row<N/2;++row)
            {
                for(size_t line=0;line<N/2;++line)
                {
                    A[i][j][row][line]=m1[row+i*N/2][line+j*N/2];
                    B[i][j][row][line]=m2[row+i*N/2][line+j*N/2];
                }
            }
        }
    }
    for(size_t k=0;k<10;++k)
    {
        for(size_t i=0;i<N/2;++i)
        {
            for(size_t j=0;j<N/2;++j)
            {
                switch(k)
                {
                    case 0:
                        S[k][i][j]=m2[i][j+N/2]-m2[i+N/2][j+N/2];
                        break;
                    case 1:
                        S[k][i][j]=m1[i][j]+m1[i][j+N/2];
                            break;
                    case 2:
                        S[k][i][j]=m1[i+N/2][j]+m1[i+N/2][j+N/2];
                        break;
                    case 3:
                        S[k][i][j]=m2[i+N/2][j]-m2[i][j];
                        break;
                    case 4:
                        S[k][i][j]=m1[i][j]+m1[i+N/2][j+N/2];
                        break;
                    case 5:
                        S[k][i][j]=m2[i][j]+m2[i+N/2][j+N/2];
                        break;
                    case 6:
                        S[k][i][j]=m1[i][j+N/2]-m1[i+N/2][j+N/2];
                        break;
                    case 7:
                        S[k][i][j]=m2[i+N/2][j]+m2[i+N/2][j+N/2];
                        break;
                    case 8:
                        S[k][i][j]=m1[i][j]-m1[i+N/2][j];
                        break;
                    case 9:
                        S[k][i][j]=m2[i][j]+m2[i][j+N/2];
                        break;
                }
            }
        }
    }
    std::array<std::array<std::array<int,N/2>,N/2>,7> P;
    P[0]=strassen(A[0][0],S[0]);
    P[1]=strassen(S[1],B[1][1]);
    P[2]=strassen(S[2],B[0][0]);
    P[3]=strassen(A[1][1],S[3]);
    P[4]=strassen(S[4],S[5]);
    P[5]=strassen(S[6],S[7]);
    P[6]=strassen(S[8],S[9]);
    std::array<std::array<int,N>,N> result{{}};
    //C11=P5+P4-P2+P6   C12=P1+P2
    //C21=P3+P4         C22=P5+P1-P3-P7
    for(size_t i=0;i<N/2;++i)
    {
        for(size_t j=0;j<N/2;++j)
        {
            result[i][j]+=(P[4][i][j]+P[3][i][j]-P[1][i][j]+P[5][i][j]);
            result[i][j+N/2]+=(P[0][i][j]+P[1][i][j]);
            result[i+N/2][j]+=(P[2][i][j]+P[3][i][j]);
            result[i+N/2][j+N/2]+=(P[4][i][j]+P[0][i][j]-P[2][i][j]-P[6][i][j]);
        }
    }
    return result;
}

int main()
{
    std::array<std::array<int,2>,2> a{{{1,2},{3,4}}};
    std::array<std::array<int,2>,2> b{{{5,6},{7,8}}};
    std::array<std::array<int,2>,2> c=strassen(a,b);
    for(size_t i=0;i<2;++i)
    {
        for(size_t j=0;j<2;++j)
            std::cout<<c[i][j]<<" ";
        std::cout<<std::endl;
    }
    return 0;
}