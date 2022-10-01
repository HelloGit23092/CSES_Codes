#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(int i = 0; i < x; i++)
#define For(i,x,y) for(int i = x; i <= y; i++)
#define vint(x) vector<int>x
#define vl(x) vector<long>x
#define vll(x) vector<long long>x
#define pb push_back
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
const int mx = 1e6;
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,x;
	cin>>n>>x;
	long long arr[n];
	FOR(i,n)
	cin>>arr[i];
	long long dp[x+1];
	For(i,1,x)
	dp[i] = INT_MAX;
	dp[0] = 0;
	For(i,1,x)
	{
		FOR(j,n)
		{
			if(i >= arr[j])
			dp[i] = min(dp[i],1+dp[i-arr[j]]);
		}
	}
	if(dp[x] == INT_MAX)
	cout<<-1;
	else
	cout<<dp[x];	
}
