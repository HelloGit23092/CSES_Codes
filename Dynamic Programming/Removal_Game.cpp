#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(int i = 0; i < x; i++)
#define For(i,x,y) for(int i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define um unordered_map
#define vint(x) vector<int>x
#define vl(x) vector<long>x
#define vll(x) vector<long long>x  
#define pb push_back
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
const int mx = 3*1e5;;
ll power(ll a,ll b)
{
    if(b == 0)
    return 1;
    if(b&1)
    return (a%mod * power((a%mod * a%mod)%mod, (b-1)/2)%mod)%mod;
    return power((a%mod * a%mod)%mod, b/2)%mod;
}
ll fact(ll a)
{
    if(a == 0)
    return 1;
    return (a%mod * fact(a-1)%mod)%mod;
}
bool sortthis(pair<ll,ll> &a, pair<ll,ll> &b)
{
    if(a.second > b.second)
    return true;
    return false;
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
    t=1;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll arr[n];
	    ll s = 0;
	    FOR(i,n)
	    {
	    	cin>>arr[i];
	    	s += arr[i];
		}
	    ll dp[n][n];  // Calculating range from ith index to jth index in dp[i][j]
	    memset(dp,0,sizeof(dp));
	    rep(i,n-1,0)
	    {
	    	For(j,i,n-1)
	    	{
	    		if(i == j)
	    		dp[i][j] = arr[i];
	    		else
	    		dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
			}
		}
		cout<<(s + dp[0][n-1])/2<<"\n";
	}
}
