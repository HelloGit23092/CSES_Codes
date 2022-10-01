#include <bits/stdc++.h>
using namespace std;
long long int dp[1000001]={0};
long long int s(int n)
{
    if(n<0)
    return 0;
    else
    if(n==0)
    return 1;
    else
    if(dp[n]!=0)
    return dp[n]%1000000007;
    else
    {
        dp[n]=s(n-1)+s(n-2)+s(n-3)+s(n-4)+s(n-5)+s(n-6);
        return dp[n]%1000000007;
    }
    
}
int main() {
    int n;
    cin>>n;
    cout<<s(n);
	return 0;
}
