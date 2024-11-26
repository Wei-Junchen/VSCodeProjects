#include <stdio.h>
#include <math.h>

double dx=1e-10;
double precision=1e-20;

double f(double x)
{
    double equal=2*pow(x,3)-4*pow(x,2)+3*x-6;
    return equal;
}

/*double df(double x)
{
    double equal=6*pow(x,2)-8*x+3;
    return equal;
}*/

double df(double x)
{
    return (f(x+dx)-f(x))/dx;
}

double getCross(double x)
{
    return x-f(x)/df(x);
}

double solve(double x)
{
    if(fabs(f(x))<=precision)
        return x;
    return solve(getCross(x));
}

int main()
{
    printf("%lf",solve(1.5));
    return 0;
}