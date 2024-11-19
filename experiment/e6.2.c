#include <stdio.h>
#include <math.h>

double limit=0.0001;

double ABS(double val)
{
    return val>=0?val:-val;
}

double f(double x)
{
    return pow(x,3)-5*pow(x,2)+16*x-80;
}

double xpoint(double x1,double x2)
{
    double f1=f(x1),f2=f(x2);
    return (x1*f2-x2*f1)/(f2-f1);
}

double root(double x1,double x2)
{
    printf("%lf %lf\n",x1,x2);
    if(ABS(f((x1+x2)/2))<=limit)
        return (x1+x2)/2;
    else if(ABS(f(x1))<=limit)
        return x1;
    else if(ABS(f(x2))<=limit)
        return x2;
    if(f(xpoint(x1,x2))*f(x1)>=0&&f(xpoint(x1,x2))*f(x2)<=0)
        root(xpoint(x1,x2),x2);
    else if(f(xpoint(x1,x2))*f(x2)>=0&&f(xpoint(x1,x2))*f(x1)<=0)
        root(x1,xpoint(x1,x2));
    else if(f(xpoint(x1,x2))*f(x1)>=0&&f(xpoint(x1,x2))*f(x2)>=0)
        return 0;
    else if(f(xpoint(x1,x2))*f(x1)<=0&&f(xpoint(x1,x2))*f(x2)<=0)
        return 0;
    else 
        return 0;
}

int main(void)
{
    double x1,x2;
    scanf("%lf %lf",&x1,&x2);
    printf("%lf",root(x1,x2));
    return 0;
}