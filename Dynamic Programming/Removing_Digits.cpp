#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int check(int n)
{
    int ans = 0;
    while(n)
    {
        int p = n%10;
        n = n / 10;
        if(p > ans)
        ans = p;
    }
    return ans;
}
int main()
{
    int n;
    cin>> n;
    long dp[n+1] = {0};
    for(int i = 1; i <= n; i++)
    {
        int y = check(i);
        dp[i] = 1 +  dp[i - y];
    }
    
    cout<<dp[n];
}
