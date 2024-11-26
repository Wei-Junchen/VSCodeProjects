#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

double solve(double left,double right,double (*function)(double))
{
    double mid=(left+right)/2;
    double fleft=function(left),fright=function(right),fmid=function(mid);
    if(fabs(fmid)<=EPSILON)
        return mid;
    if(fleft==0)
        return left;
    else if(fright==0)
        return right;
    else if(fmid==0)
        return mid;
    if(fleft*fright<0)
    {
        if(fleft*fmid<0)
            return solve(left,mid,function);
        else
            return solve(mid,right,function);
    }
    else
        return mid;
}

double f(double x)
{
    return 2*pow(x,3)-4*pow(x,2)+3*x-6;
}

int main()
{
    double root=solve(-10,10,f);
    printf("%lf",root);
    return 0;
}