#include <stdio.h>

int main(void)
{
    int matrix[3][4],out[4][3];
    for(int i=0;i<3;++i)
        for(int j=0;j<4;++j)
            scanf("%d",&matrix[i][j]);
    for(int i=0;i<3;++i)
        for(int j=0;j<4;++j)
            out[j][i]=matrix[i][j];
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<3;++j)
            printf("%d ",out[i][j]);
        printf("\n");
    }
    return 0;
}