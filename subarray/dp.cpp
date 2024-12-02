#include <iostream>
#include <array>
#include <cmath>

int main()
{
    int arr[]={-12,14,2,-3,-95,99,12,-5,-23,17,75,-84,99};
    int dp[3]={{arr[0],0,0}};
    for(std::size_t i=1;i<std::size(arr);++i)
    {
        int sum{};
        for(std::size_t j=dp[2]+1;j<=i;++j)
            sum+=arr[j];
        if(sum>=0)
        {
            dp[0]+=sum;
            dp[i][1]=dp[i-1][1];
            dp[i][2]=i;
        }
        else 
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
        }
    }
    std::cout<<dp[std::size(dp)-1];
    return 0;
}