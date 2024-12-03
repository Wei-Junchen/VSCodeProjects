#include <stdio.h>

int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int day_of_year(int year,int month,int day)
{
    int add=0,rday=0;
    if((year%4==0&&year%100!=0)||year%400==0) 
        add=1;
    for(int i=0;i<month-1;++i)
        rday+=days[i];
    rday+=day;
    if(month>=3) rday+=add;
    return rday;
}

int main(void)
{
    printf("%d\n%d",day_of_year(2024,6,13),day_of_year(2024,10,1));
    return 0;
}