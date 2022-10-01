#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 10000000000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define vint vector<int>
#define vl vector<long>
#define vll vector<long long>
#define um unordered_map
#define pb push_back
#define pll pair<ll,ll>
#define mone cout<<-1<<"\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define nl cout<<"\n"
#define all(x) x.begin(),x.end()
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
#define INF 1000000000000000000
const ll mx = 2*1e5;
/*ll numinv[mx+1];
void InverseofNumber(ll p)
{
    numinv[0] = numinv[1] = 1;
    for (ll i = 2; i <= mx; i++)
        numinv[i] = numinv[mod % i] * (mod - mod / i) % mod;
}
ll fac[mx+1] = {0}, infac[mx+1] = {0};
ll comb(ll n, ll r)
{
	if(r > n)
	return 0;
	return (fac[n]%mod * infac[r]%mod * infac[n-r]%mod)%mod;
}*/
ll power(ll a,ll b, ll m)
{
    if(b == 0)
    return 1;
    if(b&1)
    return (a%m * power((a%m * a%m)%m, (b-1)/2, m)%m)%m;
    return power((a%m * a%m)%m, b/2, m)%m;
}
ll fact(ll a, ll b)
{
    if(a == b)
    return 1;
    return (a%mod * fact(a-1,b)%mod)%mod;
}
ll block;
bool sortthis(pll &a, pll &b)
{
	if(a.first == b.first)
	return a.second < b.second;
	return (a.first > b.first);
}
bool prime(ll n)
{
	if(n == 2)
	return true;
	if(n%2 == 0 || n == 1)
	return false;
	for(ll i = 3; (i*i) <= n; i += 2)
	{
		if(n%i == 0)
		return false;
	}
	return true;
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
		ll n,x;
		cin>>n>>x;
		ll arr[n];
		FOR(i,n)
		cin>>arr[i];
		vector<pll> dp(1<<n, {n+1,INT_MAX});
		dp[0] = {1,0};
		For(i,1,(1<<n)-1)
		{
			FOR(j,n)
			{
				if((i>>j)&1)
				{
					pll op = dp[i^(1<<j)];
					if(op.second+arr[j] <= x)
					op.second += arr[j];
					else
					{
						op.first += 1;
						op.second = arr[j];
					}
					dp[i] = min(dp[i], op);
				}
			}
		}
		cout<<dp[(1<<n)-1].first;
	}
}
