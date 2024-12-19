#include <stdio.h>
#define STUDENT 30
#define COURSE 3
int Input(long num[],int score[][COURSE]);
void Total(int score[][COURSE],int sum[],float aver[],int n);
void Print(long num[],int score[][COURSE],int sum[],float aver[],int n);  
int main() 
{
    int n,score[STUDENT][COURSE],sum[STUDENT];
    long num[STUDENT];
    float aver[STUDENT];
    n=Input(num,score);
    Total(score,sum,aver,n);
    Print(num,score,sum,aver,n);
    return 0;
}

//输入学生人数和学生学号以及三门课程的成绩，返回学生人数
int Input(long num[],int score[][COURSE])
{
    int i,j,n;
    printf("Please input the number of students:");
    scanf("%d",&n);
    printf("Please input the student id and the score of three courses(MT,EN,PH):\n");
    for(i=0;i<n;i++)
    {
        scanf("%ld",&num[i]);
        for(j=0;j<COURSE;j++)
            scanf("%d",&score[i][j]);
    }
    return n;
}

//统计每个学生的总分和平均分
void Total(int score[][COURSE],int sum[],float aver[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        sum[i]=0;
        for(j=0;j<COURSE;j++)
            sum[i]+=score[i][j];
        aver[i]=sum[i]/COURSE;
    }
}

//输出学生学号，三门课程的成绩，总分和平均分以及能否获得奖学金（均分大于等于90），用Y/N表示
void Print(long num[],int score[][COURSE],int sum[],float aver[],int n)
{
    int i;
    printf("Student number\tMT\tEN\tPH\tTotal\tAverage\tScholarship\n");
    for(i=0;i<n;i++)
    {
        printf("%7ld\t\t%d\t%d\t%d\t%d\t%.2f\t",num[i],score[i][0],score[i][1],score[i][2],sum[i],aver[i]);
        if(aver[i]>=90)
            printf("\tY\n");
        else
            printf("\tN\n");
    }
}