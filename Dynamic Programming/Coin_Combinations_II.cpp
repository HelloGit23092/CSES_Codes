#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n,x;
    cin>> n>> x;
    int arr[n];
    for(int i = 0; i < n; i++)
    cin>> arr[i];
    long dp[x+1] = {0};
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            if(arr[i] <= j)
            dp[j] = (dp[j] + dp[j - arr[i]])%mod;
        }
    }
 
    cout<<dp[x];
}
