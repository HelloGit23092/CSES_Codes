#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6;
int main()
{
    int n,x;
    cin >> n >> x;
    int wt[n+1] = {0}, val[n+1] = {0};
    for(int i = 1; i <= n; i++)
    cin>> wt[i];
    for(int i = 1; i <= n; i++)
    cin>> val[i];
    int dp[n+1][x+1];
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            if(j < wt[i])
            dp[i][j] = dp[i-1][j];
            else
            dp[i][j] = max(dp[i-1][j], val[i] + dp[i-1][j - wt[i]]);
        }
    }
    cout<<dp[n][x];
}
