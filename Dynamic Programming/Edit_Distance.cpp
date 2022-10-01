#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>> a >> b;
    int n = a.length();
    int m = b.length();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0)
            dp[i][j] = j;
            else if(j == 0)
            dp[i][j] = i;
            else 
            {
                if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
                else
                dp[i][j] = min(1+dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
            }
        }
    }
    cout<<dp[n][m];
}
