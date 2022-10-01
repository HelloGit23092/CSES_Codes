#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n;
    cin>> n;
    long dp[n][n];
    char arr[n][n];
    for(int i = 0;i < n; i++)
    {
        for(int j = 0; j < n; j++)
        cin>>arr[i][j];
    }
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    if(arr[0][0] == '*' || arr[n-1][n-1] == '*')
    {
        cout<<0;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i)
            dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
            if(j)
            dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            if(arr[i][j] == '*')
            dp[i][j] = 0;
        }
    }
    cout<<dp[n-1][n-1];
}
